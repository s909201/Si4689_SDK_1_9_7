/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   MMI: for fmhd/amhd functions
   FILE: mode_fmhd_amhd.c
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#include "compiler_defs.h"
#include "typedefs.h"
#include <platform_options.h>

#if (defined OPTION__INCLUDE_MODE__FMHD) ||(defined OPTION__INCLUDE_MODE__AMHD)

#ifdef PLATFORM_F380_MODULE
	#include "C8051F380_defs.h"
#endif
#ifdef PLATFORM_F340_DEMOBOARD
	#include "C8051F340_defs.h"
	#include "usb_main.h"
#endif
#include "Firmware_API_Manager.h"
#include "main.h"
#include "mode_fmhd_amhd.h"
#include "mode_common.h"
#include "key.h"
#include "LCD.h"
#include "in_chip_eeprom.h"
/********************************************************************************

********************************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
code u8 AMHD_ITEM_STR[][15]= {
	"Info auto roll\n",
	"Metric\n",
	"SIS SLogan\n",					
 	"SIS USName\n",	
	"SIS SMessage\n",		
 	"SIS SNLong\n",		
 	"SIS SNShort\n",		
 	"SIS SID\n",				
	"SIS LOC LAT\n",				
	"SIS LOC LON\n",				

 	"PSD TITLE\n",		
	"PSD ARTIST\n",		
	"PSD ALBUM\n",		
	"PSD GENRE\n",	
	"HD ALERT\n",
};
code u8 FMHD_ITEM_STR[][15] = {
	"Info auto roll\n",
	"Metric\n",
	"RDS RT\n",
	"RDS PST\n",
	"SIS SLogan\n",					
 	"SIS USName\n",	
	"SIS SMessage\n",		
 	"SIS SNLong\n",		
 	"SIS SNShort\n",		
 	"SIS SID\n",				
	"SIS LOC LAT\n",				
	"SIS LOC LON\n",				

 	"PSD TITLE\n",		
	"PSD ARTIST\n",		
	"PSD ALBUM\n",		
	"PSD GENRE\n",	
	"HD ALERT\n",
    #ifdef OPTION__RADIODNS
        "RadioDNS Str\n",
    #endif
};

code u8 FMHD_DISPLAY_ITEM[]={
 		ITEM_AUTO_ROLL,		
 		ITEM_METRIC,				
 		ITEM_RDS_RT,			
 		ITEM_RDS_PST,
				
	  	ITEM_SIS_SLOGAN,					
 		ITEM_SIS_UNIVERSAL_SHORT_NAME,	
		ITEM_SIS_STATION_MESSAGE,		
 		ITEM_SIS_STATION_NAME_LONG,		
 		ITEM_SIS_STATION_NAME_SHORT,		
 		ITEM_SIS_STATION_ID,				
	 	ITEM_SIS_LOC_LAT,				
	 	ITEM_SIS_LOC_LON,				

 		ITEM_PSD_TITLE,		
	 	ITEM_PSD_ARTIST,		
	 	ITEM_PSD_ALBUM,		
	 	ITEM_PSD_GENRE,	
		ITEM_ALERT_HD,
        #ifdef OPTION__RADIODNS
            ITEM_RADIODNS_STRING,
        #endif
};
code u8 AMHD_DISPLAY_ITEM[]={
 		ITEM_AUTO_ROLL,		
 		ITEM_METRIC,				
			
	  	ITEM_SIS_SLOGAN,					
 		ITEM_SIS_UNIVERSAL_SHORT_NAME,	
		ITEM_SIS_STATION_MESSAGE,		
 		ITEM_SIS_STATION_NAME_LONG,		
 		ITEM_SIS_STATION_NAME_SHORT,		
 		ITEM_SIS_STATION_ID,				
	 	ITEM_SIS_LOC_LAT,				
	 	ITEM_SIS_LOC_LON,				

 		ITEM_PSD_TITLE,		
	 	ITEM_PSD_ARTIST,		
	 	ITEM_PSD_ALBUM,		
	 	ITEM_PSD_GENRE,	
		ITEM_ALERT_HD,	
};
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
/***********************************************************************************
set the parameter to default value
************************************************************************************/
RETURN_CODE fmhd_amhd_set_parameter_default()
{
	RETURN_CODE ret = SUCCESS;
	if(work_mode == fmhd)
	{
		fmhd_freq = 8810;
		fmhd_freq_step_size = 200;

	    fmhd_ber_mode = HD_P1;
	    fmhd_split_mode_setting = 0;

		ClearMemory((u8*)fmhd_pset_table,sizeof(fmhd_pset_table));
		pset_table_index =0;

	    fmhd_seekonly = 0;
	}

	#ifdef OPTION__INCLUDE_MODE__AMHD
	if(work_mode == amhd)
	{
		amhd_freq = 1000;
		amhd_freq_step_size = 10;
	}
	#endif



    volume = 63;
    
	return ret;
}	
/***********************************************************************************

************************************************************************************/
RETURN_CODE fmhd_amhd_initialize(void)
{
	RETURN_CODE ret = SUCCESS;

    fmhd_amhd_set_parameter_default();

//	work_mode = fmhd;
	ret |= Initialize(work_mode);
    ret |= eeprom_get_parameter();//read from flash

	if(work_mode == fmhd)
	{
	    if(ret != SUCCESS || fmhd_freq >10800 || fmhd_freq < 6400)
	    {
			fmhd_amhd_set_parameter_default();//if it is incorrect .then load default parameter
		}
		ret |= Tune(fmhd_freq);
	}
	if(work_mode == amhd)
	{
	    if(ret != SUCCESS || amhd_freq >1710 || amhd_freq < 520)
	    {
			fmhd_amhd_set_parameter_default();//if it is incorrect .then load default parameter
		}
		ret |= Tune(amhd_freq);
	}		

    ret |= AudioLevel(volume);

    ret |= set_freq_spacing();

	rds_update_ready_item =0;
	sis_update_ready_item =0;
	psd_update_ready_item =0;
    alert_update_ready_item = 0;
    ber_running_flag = 0;

	seek_state = SEEK_NULL;


	item_loop = ITEM_AUTO_ROLL;
	display_item_str_4ms = 200;

	#ifdef ATS_EMBED_CODE
		ATS_RDS_valid_flag = 1;
	#endif
	return ret;
}	
/***********************************************************************************

************************************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
RETURN_CODE display_hd_ui(void)
{
	RETURN_CODE ret = SUCCESS;

	LCD_Clear(LCD_CLEAR_LINE2);
	show_freq(0,0);

    eeprom_save_parameter();

	return ret;
}
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
/****************************************************************************************


******************************************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
#ifdef OPTION__INCLUDE_FRONT_END_TEST_FUNCTIONS
void fmhd_BER_update_display()
{
    uint32_t err,tot;

    LCD_Clear(LCD_CLEAR_ALL);
    Test_GetFreeRunningBER_FMHD(fmhd_ber_mode, &err, &tot);

    LCD_DisplayStr("P    Err:\n",0,0);
    LCD_DisplayStr("Tot:\n",0,1);
    if(fmhd_ber_mode < HD_PIDS_BIT)
    {
        LCD_DisplayNum32(fmhd_ber_mode,1,0);
    }
    else
    {
        if(fmhd_ber_mode == HD_PIDS_BIT)
        {
            LCD_DisplayStr("BIT\n",1,0);
        }
        else
        {
            LCD_DisplayStr("BLK\n",1,0);
        }
    }

    LCD_DisplayNum32(err,9,0);
    
    LCD_DisplayNum32(tot,4,1);

    display_item_str_4ms = 500;
}
#endif //OPTION__INCLUDE_FRONT_END_TEST_FUNCTIONS
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
/****************************************************************************************

******************************************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
void fmhd_key_update_display()
{
    show_freq(0,0);
    display_item_str_4ms = 500;
}
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
/****************************************************************************************

******************************************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
RETURN_CODE fmhd_amhd_key_process(void)
{
	RETURN_CODE ret = SUCCESS;
	if(key_flag==1)
	{
		key_flag = 0;
		display_refresh_flag = 1;
		switch(key_value)
		{
			case TUNE_PRESS_KNOBS:
				item_loop ++;
				if(item_loop>(sizeof(FMHD_ITEM_STR)/sizeof(FMHD_ITEM_STR[0]))-1)
				{
					item_loop = 0;
				}
				show_freq(0,0);
				LCD_Clear(LCD_CLEAR_LINE2);
				LCD_DisplayStr(FMHD_ITEM_STR[item_loop],0,1);	
				display_item_str_4ms = 500;
                loop_display_times = 0;
				break;
			case DOWN_KEY:
			case TUNE_DEC_KNOBS:
                #ifdef OPTION__INCLUDE_FRONT_END_TEST_FUNCTIONS
                    if(ber_running_flag == 1)
                    {
                        fmhd_ber_mode --;
                        if(fmhd_ber_mode < HD_P1)
                        {
                            fmhd_ber_mode = HD_PIDS_BLOCK;
                        }
                    }
                    else
                    {
                #endif //OPTION__INCLUDE_FRONT_END_TEST_FUNCTIONS

				ret |= tune_up_down(0);
                if(ret == SUCCESS)
                {
                    fmhd_key_update_display();
                }

                #ifdef OPTION__INCLUDE_FRONT_END_TEST_FUNCTIONS
                    }
                #endif //OPTION__INCLUDE_FRONT_END_TEST_FUNCTIONS

				break;
			case UP_KEY:
			case TUNE_INC_KNOBS:
                #ifdef OPTION__INCLUDE_FRONT_END_TEST_FUNCTIONS
                    if(ber_running_flag == 1)
                    {
                        fmhd_ber_mode ++;
                        if(fmhd_ber_mode > HD_PIDS_BLOCK)
                        {
                            fmhd_ber_mode = HD_P1;
                        }
                    }
                    else
                    {
                #endif //OPTION__INCLUDE_FRONT_END_TEST_FUNCTIONS

				ret |= tune_up_down(1);
                if(ret == SUCCESS)
                {
                    fmhd_key_update_display();
                }

                #ifdef OPTION__INCLUDE_FRONT_END_TEST_FUNCTIONS
                    }
                #endif //OPTION__INCLUDE_FRONT_END_TEST_FUNCTIONS

				break;
			case HDSEEK_KEY:
			#ifdef OPTION__INCLUDE_MODE__AMHD
				if(work_mode == amhd)
				{
					return SUCCESS;//amhd mode will not support HD station only seeking
				}
			#endif
				if(seek_state == SEEK_NULL)
				{
					fmhd_seekonly ^= 1;
                    LCD_Clear(LCD_CLEAR_ALL);
    		        LCD_DisplayStr("HD-Only Seek\n",0,0);
                    if(fmhd_seekonly)
                    {
                        LCD_DisplayStr("Enabled\n",0,1);
                    }
                    else
                    {
                        LCD_DisplayStr("Disabled\n",0,1);
                    }
                    display_item_str_4ms = 500;
				}
				break;
			case SEEK_UP_KEY:
				if(seek_state == SEEK_NULL)
				{
                    seek_state = SEEK_PROCESS;
					ret|=SeekStart(1,1,fmhd_seekonly);
                    fmhd_key_update_display();
				}
				break;
			case SEEK_DOWN_KEY:
				if(seek_state == SEEK_NULL)
				{
                    seek_state = SEEK_PROCESS;
					ret|=SeekStart(0,1,fmhd_seekonly);
                    fmhd_key_update_display();						
				}
				break;
			case PRESET_INC_KEY:
            case PRESET_DEC_KEY:
				ret |=pset_operate(key_value);
				display_item_str_4ms = 2000;
				break;
			case PRESET_INC_HOLD_KEY:
            case PRESET_DEC_HOLD_KEY:
				ret |=pset_operate(key_value);
				display_item_str_4ms = 1000;
				break;
#ifdef OPTION__INCLUDE_FRONT_END_TEST_FUNCTIONS
            case DAB_RESCAN_KEY:
                //iBiquity has requested the push botton be used to start a free-running BER test.  The previous 1,000,000 bit sample test is still included in the ATS commands
                if(ber_running_flag == 1)
                {
                    display_item_str_4ms = 3000;
                }
                else
                {
                    Test_StartFreeRunningBER_FMHD();
                }

                ber_running_flag ^= 1;

		
				break;
            case DAB_RESCAN_HOLD_KEY:
                fmhd_split_mode_setting ++;
                if(fmhd_split_mode_setting > 2)
                {
                    fmhd_split_mode_setting = 0;
                }
                ret |= SetProperty(0xE801, fmhd_split_mode_setting); // Test mode for HD split mode rotates through splits
                ret |= Tune(MetricsGetFMHDPtr()->FREQUENCY_10KHZ); //Retune to make the property change take effect
                LCD_Clear(LCD_CLEAR_ALL);
                LCD_DisplayStr("HD-SplitMode\n",0,0);
                LCD_DisplayNum(fmhd_split_mode_setting,0,1);
                display_item_str_4ms = 3000;
                break;
#endif //OPTION__INCLUDE_FRONT_END_TEST_FUNCTIONS
			default:
                key_flag = 1;display_refresh_flag = 0;
                break;
		}
	}
	return ret;
}
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
/****************************************************************************************
fmhd main process
******************************************************************************************/
RETURN_CODE fmhd_amhd_work_mode(void)
{
	RETURN_CODE ret = SUCCESS;

	//u8 temp_str[16];
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
	static bit hd_flag = 0;
	static u8 display_item_state = 0;
#endif

	if( power_flag ==0)
	{
		power_flag =1;
		fmhd_amhd_initialize();
	}

#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
	ret |=fmhd_amhd_key_process();
	
	if(display_item_str_4ms >0)
	{
		//display_refresh_flag = 1;
		return 0;// wait for time up
	}

    if(ber_running_flag == 1)
    {
        fmhd_BER_update_display();
        return 0; // We do not want to leave this screen until we have stopped running the BER test
    }

	 if(display_refresh_flag==1)
	{
		display_refresh_flag=0;
		ret |= display_hd_ui();
	}
	else //if(display_item_str_4ms == 0)
	{
	
		display_item_str_4ms = STATUS_UPDATE_INTERVAL;
		if(item_loop == ITEM_AUTO_ROLL) // display will auto change next next 
		{
			if(work_mode == fmhd)
			{
				if(display_item_state > sizeof(FMHD_DISPLAY_ITEM)/sizeof(FMHD_DISPLAY_ITEM[0])-1)
				{
					display_item_state = 1;
				}
			}
        #ifdef OPTION__INCLUDE_MODE__AMHD
			else if(work_mode == amhd)
			{
				if(display_item_state > sizeof(AMHD_DISPLAY_ITEM)/sizeof(AMHD_DISPLAY_ITEM[0])-1)
				{
					display_item_state = 1;
				}
			}
        #endif // OPTION__INCLUDE_MODE__AMHD		
		}
		else
		{
			display_item_state = item_loop;// fix display special item switched by hold tune knobs
		}

		if(work_mode == fmhd)
		{
			if (display_data_item(FMHD_DISPLAY_ITEM[display_item_state]) == ITEM_NEXT)
			{
				display_item_state ++;
			}   
			ret = UpdateMetrics();
			if(MetricsGetFMHDPtr()->AUDIO_SOURCE != hd_flag)
			{
				hd_flag= MetricsGetFMHDPtr()->AUDIO_SOURCE;
				show_freq(0,0);
			}			 
		}
    #ifdef OPTION__INCLUDE_MODE__AMHD
		else
		{
			if (display_data_item(AMHD_DISPLAY_ITEM[display_item_state]) == ITEM_NEXT)
			{
				display_item_state ++;
			}  
			ret = UpdateMetrics();
			if(MetricsGetAMHDPtr()->AUDIO_SOURCE != hd_flag)
			{
				hd_flag= MetricsGetAMHDPtr()->AUDIO_SOURCE;
				show_freq(0,0);
			}			  
		}
    #endif //OPTION__INCLUDE_MODE__AMHD		
	}
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI

#ifdef OPTION__OPERATE_AS_SLAVE_NO_MMI
	ret |= UpdateMetrics();
	ret |= UpdateDataServiceData();
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI

    ret |= UpdateServiceList(); // Need to periodically check for updates to the service list - reconfiguration
	return ret;
}

#endif //OPTION__INCLUDE_MODE__FMHD
