/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   MMI: for fm/am functions
   FILE: mode_fm_am.c
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#include "compiler_defs.h"
#include "typedefs.h"
#include <platform_options.h>

#if (defined OPTION__INCLUDE_MODE__FM)||(defined OPTION__INCLUDE_MODE__AM)

#ifdef PLATFORM_F380_MODULE
	#include "C8051F380_defs.h"
#endif
#ifdef PLATFORM_F340_DEMOBOARD
	#include "C8051F340_defs.h"
	#include "usb_main.h"
#endif
#include "Firmware_API_Manager.h"
#include "feature_types.h"
#include "main.h"

#include "mode_common.h"
#include "mode_fm_am.h"
#include "key.h"
#include "LCD.h"
#include "SDK_Callbacks.h"
#include "in_chip_eeprom.h"

#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI

#ifdef OPTION__INCLUDE_MODE__AM
code u8 AM_ITEM_STR[][15] = {
	"Info auto roll\n",
	"Metric\n",
};

code u8 AM_DISPLAY_ITEM[]={
 		ITEM_AUTO_ROLL,		
 		ITEM_METRIC,			
};
#endif

#ifdef OPTION__INCLUDE_MODE__FM
code u8 FM_ITEM_STR[][15] = {
	"Info auto roll\n",
	"Metric\n",
	"RDS PI\n",
	"RDS PTY\n",
	"RDS RT\n",
	"RDS PST\n",
	"RDS CT\n",
	"RDS AF\n",
    #ifdef OPTION__RADIODNS
        "RadioDNS Str\n",
    #endif
};
code u8 FM_DISPLAY_ITEM[]={
 		ITEM_AUTO_ROLL,		
 		ITEM_METRIC,			
 		ITEM_RDS_PI,			
 		ITEM_RDS_PTY,		
 		ITEM_RDS_RT,			
 		ITEM_RDS_PST,		
 		ITEM_RDS_TIME,				
 		ITEM_RDS_ALT_FREQ,
        #ifdef OPTION__RADIODNS
            ITEM_RADIODNS_STRING,
        #endif
};
#endif
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
/***********************************************************************************
set the parameter to default value
************************************************************************************/
RETURN_CODE fm_am_set_parameter_default()
{
	#ifdef OPTION__FM_SHOW_STATION_NAME_PST
		u8  i;
	#endif

	RETURN_CODE ret = SUCCESS;


	if(work_mode == fmonly)
	{
		fm_freq = 8810;
		fm_freq_step_size = 100;
	}
	#ifdef OPTION__INCLUDE_MODE__AM
	else if(work_mode == am)
	{
		am_freq = 1000;
		am_freq_step_size = 10;
	}
//	ClearMemory((u8*)am_pset_table,sizeof(am_pset_table));
	#endif
	ClearMemory((u8*)fm_pset_table,sizeof(fm_pset_table));

	#ifdef OPTION__INCLUDE_MODE__AM
		ClearMemory((u8*)am_pset_table,sizeof(am_pset_table));
	#endif


	#ifdef OPTION__FM_SHOW_STATION_NAME_PST
		for(i=0;i<MAX_PRESET_NUM;i++)
		{
			ClearMemory(fm_pty_pset_table[i],12);
		}
	#endif

	pset_table_index =0;
	return ret;
}	
/***********************************************************************************
initialize the fm include patch loading and variable inital
************************************************************************************/
RETURN_CODE fm_am_initialize(void)
{
	RETURN_CODE ret = SUCCESS;
	
    fm_am_set_parameter_default();

	ret |= Initialize(work_mode);
    ret |= eeprom_get_parameter();//read from flash

	if((work_mode == fmonly)&&(ret != SUCCESS || fm_freq >10800 || fm_freq < 6400))//check whether the para get from flash is correct
	{
		fm_am_set_parameter_default();//if it is incorrect .then load default parameter
	}

#ifdef OPTION__INCLUDE_MODE__AM
	if((work_mode == am)&&(ret != SUCCESS || am_freq >1720 || am_freq < 520))//check whether the para get from flash is correct
	{
		fm_am_set_parameter_default();//if it is incorrect .then load default parameter
	}
#endif
    ret |= AudioLevel(volume);

	if(work_mode == fmonly)
	{
		ret |= Tune(fm_freq);
		rds_update_ready_item =0;
		sis_update_ready_item =0;
		psd_update_ready_item =0;
	    alert_update_ready_item = 0;
	}
	else if(work_mode == am)
	{
		ret |=Tune(am_freq);
	}
	ret |= set_freq_spacing();
    seek_state = SEEK_NULL;

    item_loop = ITEM_AUTO_ROLL;
	display_item_str_4ms = 200;

	#ifdef ATS_EMBED_CODE
		ATS_RDS_valid_flag = 0;
	#endif

	display_refresh_flag = 1;

	return ret;
}
/***********************************************************************************
refresh the frequency after tune next or down
************************************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
RETURN_CODE refresh_fm_ui(void)
{
	RETURN_CODE ret = SUCCESS;
	LCD_Clear(LCD_CLEAR_LINE2);
	ret |= UpdateMetrics();
	show_freq(0,0);

    eeprom_save_parameter();

	return ret;	
}
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
/****************************************************************************************
key deal with progarm
******************************************************************************************/		
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
RETURN_CODE fm_am_key_process(void)
{
	RETURN_CODE ret = SUCCESS;
	if(key_flag)
	{
		key_flag = 0;
		display_refresh_flag = 1;
		switch(key_value)
		{
			case TUNE_PRESS_KNOBS:
				item_loop ++;
				LCD_Clear(LCD_CLEAR_LINE2);
				if(work_mode == fmonly)
				{
					if(item_loop>(sizeof(FM_ITEM_STR)/sizeof(FM_ITEM_STR[0]))-1)
					{
						item_loop = 0;
					}
					LCD_DisplayStr(FM_ITEM_STR[item_loop],0,1);	
				}
				#ifdef OPTION__INCLUDE_MODE__AM
				else if(work_mode == am)
				{
					if(item_loop>(sizeof(AM_ITEM_STR)/sizeof(AM_ITEM_STR[0]))-1)
					{
						item_loop = 0;
					}
					LCD_DisplayStr(AM_ITEM_STR[item_loop],0,1);	
				}	
				#endif				
				show_freq(0,0);
				display_item_str_4ms = 500;
                loop_display_times = 0;
				break;
			case DOWN_KEY:
			case TUNE_DEC_KNOBS:
				ret |= tune_up_down(0);
				show_freq(0,0);
				display_item_str_4ms = 500;
				break;
			case UP_KEY:
			case TUNE_INC_KNOBS:
				ret |= tune_up_down(1);
				show_freq(0,0);
				display_item_str_4ms = 500;
				break;
			case SEEK_UP_KEY:
				if(seek_state == SEEK_NULL)
				{
                    seek_state = SEEK_PROCESS;
					ret|=SeekStart(1,1,0);
				}
				break;
			case SEEK_DOWN_KEY:
				if(seek_state == SEEK_NULL)
				{
                    seek_state = SEEK_PROCESS;
					ret|=SeekStart(0,1,0);
				}
				break;
				
			case PRESET_INC_KEY:
            case PRESET_DEC_KEY:
            	ret |=pset_operate(key_value);
				display_item_str_4ms = 1500;
				break;
			case PRESET_INC_HOLD_KEY:
            case PRESET_DEC_HOLD_KEY:
				ret |=pset_operate(key_value);
				display_item_str_4ms = 1000;
				break;
			default:display_refresh_flag = 0;
				key_flag = 1;
				break;
		}
	}
	return ret;		
}
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
/****************************************************************************************
fm main process .include deal with key and some status update and LCD refresh 
******************************************************************************************/
RETURN_CODE fm_am_work_mode(void)
{
	RETURN_CODE ret = SUCCESS;
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
	static u8 display_item_state = 0;
#endif
	
	if( power_flag ==0)
	{
		power_flag =1;
		fm_am_initialize();
	}
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
	ret |= fm_am_key_process();

	if(display_item_str_4ms >0)
	{
		//display_refresh_flag = 1;//refresh_gui interval
		return 0;// wait for time up
	}

	if(display_refresh_flag == 1)
	{  
		display_refresh_flag = 0;
		ret |= refresh_fm_ui();
	}
	else// if(display_item_str_4ms == 0)
	{
		display_item_str_4ms = STATUS_UPDATE_INTERVAL;
		if(item_loop == ITEM_AUTO_ROLL) // display will auto change next next 
		{
			if(work_mode == fmonly)
			{
				if(display_item_state >  sizeof(FM_DISPLAY_ITEM)/sizeof(FM_DISPLAY_ITEM[0])-1)
				{
					display_item_state = 1;
				}
			}
			#ifdef OPTION__INCLUDE_MODE__AM
			else
			{
				if(display_item_state >  sizeof(AM_DISPLAY_ITEM)/sizeof(AM_DISPLAY_ITEM[0])-1)
				{
					display_item_state = 1;
				}
			}
			#endif				
		}
		else
		{
			display_item_state = item_loop;// fix display special item switched by hold tune knobs
		}

		if(work_mode == fmonly)
		{
			if (display_data_item(FM_DISPLAY_ITEM[display_item_state]) == ITEM_NEXT)
			{
				display_item_state ++;
			}
		}
		#ifdef OPTION__INCLUDE_MODE__AM
		
		else
		{
			if (display_data_item(AM_DISPLAY_ITEM[display_item_state]) == ITEM_NEXT)
			{
				display_item_state ++;
			}
		}
		
		#endif			
		//show_freq(0,0);//refresh the frequency display
	}
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI

#ifdef OPTION__OPERATE_AS_SLAVE_NO_MMI
	ret |= UpdateMetrics();
	ret |= UpdateDataServiceData();
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI

	return ret;
}

#endif //OPTION__INCLUDE_MODE__FM