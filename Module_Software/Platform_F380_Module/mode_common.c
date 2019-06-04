/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   MMI: for general radio functions
   FILE: mode_common.c
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#include "compiler_defs.h"
#include "typedefs.h"
#include <platform_options.h>
#include "common_types.h"

#ifdef PLATFORM_F380_MODULE
	#include "C8051F380_defs.h"
#endif

#ifdef PLATFORM_F340_DEMOBOARD
	#include "C8051F340_defs.h"
	#include "usb_main.h"
#endif


#include "main.h"
#include "Firmware_API_Manager.h"
#include "si46xx_firmware_api.h"
#include "DAB_Service_List_Handler.h"
#include "LCD.h"
#include "sys.h"
#include "key.h"
#include "delay.h"
#include "mode_fmhd_amhd.h"
#include "mode_fm_am.h"
#include "mode_dab.h"
#include "mode_other.h"
#include "mode_common.h"
#include "SDK_Callbacks.h"
#include "in_chip_eeprom.h"
//#include <character.h>

#include "si468x_bus.h"
/******************************************************************************

*******************************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI

	#ifdef OPTION__INCLUDE_MODE__FM
	code u8 RDS_Pty_List[32][9] = {
		"None    \n",
		"News    \n",
		"Affairs \n",
		"Info    \n",
		"Sport   \n",
		"Educate \n",
		"Drama   \n",
		"Culture \n",
		"Science \n",
		"Varied  \n",
		"Pop M   \n",
		"Rock M  \n",
		"Easy M  \n",
		"Light M \n",
		"Classic \n",
		"Other M \n",
		"Weather \n",
		"Finance \n",
		"Children\n",
		"Social  \n",
		"Religion\n",
		"Phone In\n",
		"Travel  \n",
		"Leisure \n",
		"Jazz    \n",
		"Country \n",
		"Nation M\n",
		"Oldies  \n",
		"Folk M  \n",
		"Document\n",
		"TEST    \n",
		"Alarm!  \n"
	};
	#endif //OPTION__INCLUDE_MODE__FM

#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
/**************************************************************************
power up or power dnow function
****************************************************************************/
RETURN_CODE power_process(void)
{
	RETURN_CODE ret = SUCCESS;
	if(power_flag)
	{
		power_flag = 0;
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
		LCD_Clear(LCD_CLEAR_ALL);

		display_mode = CLOCK_MODE;
		time_refresh_item = 0x7F;
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI

		ret = eeprom_save_parameter();//save the currenct parameter 

		ret = AudioMute(MUTE_LEFT_RIGHT);
		
#ifdef PLATFORM_F380_MODULE
		if(BAT_DISP ==0 )//plus into the wall,so just mute the audio ,
		{
			power_save_flag = 0;
		}
		else//unplugged, then idle the radio chip and put the MCU into idle mode
		{
			power_save_flag = 1;
			//display_mode = IDLE_MODE;//mcu go into save power mode
			//there is one issue need to be solve...the key deal process....
			ret = Finalize();//Put the radio into reset status
		}
#else
		power_save_flag = 0;	
#endif
		LCD_BL_flag = 0;
		DISP_BKLIGHT = LCD_BL_OFF;
	}
	else
	{
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI		
		LCD_Clear(LCD_CLEAR_ALL);
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
		power_flag = 1;
		display_delay_4ms= 0;
		display_delay_en = 1;
		display_item_str_4ms = 0;
		display_refresh_flag = 1;


		if(power_save_flag)//if radio chip fall into reset state, so that radio chip need to re-initial
		{
            
			pfunc = BANDSWITCH;
			state_update();
			power_save_flag = 0;
		}
		display_mode_update();//come back the work mode before turn off
		ret = AudioMute(NOT_MUTED);	
		pfunc = IDLE;
		item_loop = ITEM_AUTO_ROLL;

		LCD_BL_flag = 1;
		DISP_BKLIGHT = LCD_BL_ON;
		
	}
	return ret;
}
/******************************************************************************
band switch function
*******************************************************************************/
code u8 band_str_num[]={
#ifdef OPTION__INCLUDE_MODE__FM
		2,
#endif
#ifdef OPTION__INCLUDE_MODE__FMHD
		4,
#endif
#ifdef OPTION__INCLUDE_MODE__DAB
		3,
#endif
#ifdef OPTION__INCLUDE_MODE__AM
		2,
#endif
#ifdef OPTION__INCLUDE_MODE__AMHD
		4,
#endif

};
code u8 band_string[][5]={
#ifdef OPTION__INCLUDE_MODE__FM
	"FM\n",
#endif
#ifdef OPTION__INCLUDE_MODE__FMHD
	"FMHD\n",
#endif
#ifdef OPTION__INCLUDE_MODE__DAB
	"DAB\n",
#endif
#ifdef OPTION__INCLUDE_MODE__AM
	"AM\n",
#endif
#ifdef OPTION__INCLUDE_MODE__AMHD
	"AMHD\n",
#endif
};

#ifdef OPTION__INCLUDE_MODE__ANY
code u8 SI4682_BAND[]={
#ifdef OPTION__INCLUDE_MODE__FM
    fmonly,
#endif
#ifdef OPTION__INCLUDE_MODE__FMHD
    fmhd,
#endif
};
#endif

#ifdef OPTION__INCLUDE_MODE__ANY
code u8 SI4684_BAND[]={
#ifdef OPTION__INCLUDE_MODE__FM
    fmonly,
#endif
#ifdef OPTION__INCLUDE_MODE__DAB
    dab,
#endif
};
#endif

#ifdef OPTION__INCLUDE_MODE__ANY
code u8 SI4688_BAND[]={
#ifdef OPTION__INCLUDE_MODE__FM
    fmonly,
#endif
#ifdef OPTION__INCLUDE_MODE__FMHD
    fmhd,
#endif
#ifdef OPTION__INCLUDE_MODE__DAB
	dab,
#endif
};
#endif


#ifdef OPTION__INCLUDE_MODE__ANY
code u8 SI4689_BAND[]={
#ifdef OPTION__INCLUDE_MODE__FM
    fmonly,
#endif
#ifdef OPTION__INCLUDE_MODE__FMHD
    fmhd,
#endif
#ifdef OPTION__INCLUDE_MODE__DAB
    dab,
#endif
#ifdef OPTION__INCLUDE_MODE__AM
	am,
#endif
#ifdef OPTION__INCLUDE_MODE__AMHD
	amhd,
#endif
};
#endif


/*************************************************************************************/

/*************************************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
RETURN_CODE band_switch_mode(void)
{
	u8 lcd_line[32];
	u8 index;
	u8 i;
	u8 select_position =0;
	RETURN_CODE ret = SUCCESS;

	if(display_refresh_flag ==1)
	{
		display_refresh_flag = 0;

		LCD_Clear(LCD_CLEAR_ALL);
		LCD_DisplayStr("Mode:\n",0,0);

		for(i=0;i<sizeof(lcd_line);i++)
        {
            lcd_line[i] = ' ';
        }

		index = 0;

		for(i=0;i<band_size;i++)
		{
			if(pband[i]==work_mode)
			{
				index +=1;
				lcd_line[index]='>';
				select_position = index;
			}

			CpyMemory(lcd_line+index+1,band_string[i],band_str_num[i]);

			index += band_str_num[i];
			if(i+1>=band_size)
			{
				*(lcd_line+index+1) ='\n';
			}
			else
			{
				index +=1;
			}	
		}
	/*	
		if(index+1>16)
		{
			CpyMemory(lcd_line,band_string[i],band_str_num[pband[i]]);
		}	
	*/	
		if(select_position+4>15)
		{
			LCD_DisplayStr(lcd_line+index-15,0,1);
		}
		else
		{
			LCD_DisplayStr(lcd_line,0,1);
		}
	}
	return ret;
}
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
/*************************************************************************************/

/*************************************************************************************/
void Init_variable(void)
{
	RETURN_CODE ret = SUCCESS;
	work_mode = fmonly;
	current_work_mode = fmonly;
	work_mode_index = 0;
	band_size = 2;

	power_flag = 0;
	power_save_flag = 1;//need to re-initial at first power up
	firmware_download_flag = 0;

	pfunc = IDLE;
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
	clock_initialize();
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
	display_mode = MAIN_MODE;
	display_refresh_flag = 1;
	display_delay_4ms = 1000;
	display_delay_en = 1;
    display_entered_volume_work_mode = 0; // We use this valiable to flag when we have entered volume screen to know if we should save a change

	auto_time_correct_flag=AUTO_TIME_CORRECT_ENABLE;

	ALARM_BUZZER_PIN =0;



#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
	wake_up_time = NO_KEY_WAKUP_TIME;//

	alarm_time.sec = 5;
	alarm_time.min = 30;
	alarm_time.hour = 12 ;
	alarm_time.day = 1;
	alarm_time.week= 4;
	alarm_time.month=9;
	alarm_time.year = 112;//1900+112=2012

	alarm_flag = 0;
	alarm_time_up = 0;

	ClearMemory(LCD_buf,8);

	auto_time_correct_flag = AUTO_TIME_CORRECT_ENABLE;

	menu_index = 0;
	menu_select_flag = 0;
	current_menu_item = 0;
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI


	ship_ats_inter_flag  = 0;
	mute_flag = 0;
	mono_stereo_flag = 0;

	dab_manual_freq_index = 0;

//-------------------for get the properly part value--------------------
//---------------------first boot up default mode fmonly----------------
	power_flag = 1;//set up this flag for avoid initialize the device system clock again,if not, it will cause F340 work out
	ret |= Get_part(&chip_part);
	power_flag = 0;
	if(ret !=SUCCESS || chip_part == 0)
	{
		chip_part = 4689;//support FM,HD,DAB by default 
	}
    #ifdef OPTION__INCLUDE_MODE__ANY
	switch(chip_part)
	{
		case 4632:
        case 4682:
				pband =SI4682_BAND;
				band_size = sizeof(SI4682_BAND)/sizeof(SI4682_BAND[0]);
				break;
        case 4634:
		case 4684:
				pband =SI4684_BAND;
				band_size = sizeof(SI4684_BAND)/sizeof(SI4684_BAND[0]);
				break;
        case 4638:
		case 4688:
				pband = SI4688_BAND;
				band_size = sizeof(SI4688_BAND)/sizeof(SI4688_BAND[0]);
				break;
		case 4683:
				break;
		case 4689:
				pband = SI4689_BAND;
				band_size = sizeof(SI4689_BAND)/sizeof(SI4689_BAND[0]);
				break;
		default:pband = SI4688_BAND;
				band_size = sizeof(SI4688_BAND)/sizeof(SI4688_BAND[0]);
				break;
	}
    #endif

    
	eeprom_get_work_mode();//read from flash 
}	

/***********************************************************************************
display the meteric item on LCD line 2
************************************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
#ifdef OPTION__INCLUDE_MODE__ANY
RETURN_CODE display_metric(void)
{
#ifdef OPTION__INCLUDE_MODE__FM
    fm_metrics* fmMet;
#endif //OPTION__INCLUDE_MODE__FM

#ifdef OPTION__INCLUDE_MODE__FMHD
    fmhd_metrics* fmhdMet;
#endif //OPTION__INCLUDE_MODE__FMHD

#ifdef OPTION__INCLUDE_MODE__AM
    am_metrics* amMet;
#endif //OPTION__INCLUDE_MODE__FM

#ifdef OPTION__INCLUDE_MODE__AMHD
    amhd_metrics* amhdMet;
#endif //OPTION__INCLUDE_MODE__FMHD


#ifdef OPTION__INCLUDE_MODE__DAB
    dab_metrics* dabMet;
    #ifdef OPTION__ADVANCED_METRICS
        char display_FFT_offset;
    #endif
#endif //OPTION__INCLUDE_MODE__DAB

	char display_snr,display_rssi;
	RETURN_CODE ret = SUCCESS;	
	ret = UpdateMetrics();
	if(ret == SUCCESS)
	{
        LCD_Clear(LCD_CLEAR_LINE2);

		if(work_mode == fmonly)
		{
#ifdef OPTION__INCLUDE_MODE__FM
			fmMet=MetricsGetFMPtr();
			display_rssi = fmMet->RSSI;
			display_snr = fmMet->SNR;
#endif //OPTION__INCLUDE_MODE__FM
		}
		else if(work_mode == fmhd)
		{
#ifdef OPTION__INCLUDE_MODE__FMHD
			fmhdMet=MetricsGetFMHDPtr();
			display_rssi = fmhdMet->RSSI;
			display_snr = fmhdMet->SNR;
#endif //OPTION__INCLUDE_MODE__FMHD
		}
#ifdef OPTION__INCLUDE_MODE__AM
		else if(work_mode == am)
		{
			amMet = MetricsGetAMPtr();
			display_rssi = amMet->RSSI;
			display_snr = amMet->SNR;
		}
#endif

#ifdef OPTION__INCLUDE_MODE__AMHD
		else if(work_mode == amhd)
		{
			amhdMet = MetricsGetAMHDPtr();
			display_rssi = amhdMet->RSSI;
			display_snr = amhdMet->SNR;
		}
#endif
		else
		{
#ifdef OPTION__INCLUDE_MODE__DAB
			dabMet = MetricsGetDABPtr();
			display_rssi = dabMet->RSSI;
			display_snr = dabMet->SNR;
            
            display_refresh_flag = 1;//refresh the service name

            #ifdef OPTION__ADVANCED_METRICS
                //LCD_DisplayStr("F\n",6,1);
        	    LCD_DisplayNum((u16)dabMet->FIC_QUALITY,7,1);

                display_FFT_offset = dabMet->FFT_OFFSET;
                //LCD_DisplayStr("O\n",10,1);
                if((u8)display_FFT_offset>127)
		        {
        			LCD_DisplayStr("-\n",11,1);
        			LCD_DisplayNum((u16)((~display_FFT_offset)+1),12,1);
        		}
        		else
        		{
        			LCD_DisplayNum((u16)display_FFT_offset,12,1);
        		}
            #endif
#endif //OPTION__INCLUDE_MODE__DAB
		}

        #ifdef OPTION__ADVANCED_METRICS
    		//LCD_DisplayStr("R\n",0,1);
    		if((u8)display_rssi>127)
    		{
    			display_rssi = 0;
    			LCD_DisplayNum((u16)((~display_rssi)+1),1,1);
    		}
    		else
    		{
    			LCD_DisplayNum((u16)display_rssi,1,1);
    		}

    		//LCD_DisplayStr("S\n",3,1);
    	    LCD_DisplayNum((u16)display_snr,4,1);

        #else
            LCD_DisplayStr("R:\n",0,1);
    		if((u8)display_rssi>127)
    		{
    			LCD_DisplayStr("-\n",3,1);
    			LCD_DisplayNum((u16)((~display_rssi)+1),4,1);
    		}
    		else
    		{
    			LCD_DisplayNum((u16)display_rssi,3,1);
    		}

    		LCD_DisplayStr("S:\n",8,1);
    		if((u8)display_snr>127)
    		{
    			LCD_DisplayStr("-\n",11,1);
    			LCD_DisplayNum((u16)(~(display_snr)+1),12,1);
    		}
    		else
    		{
    			LCD_DisplayNum((u16)display_snr,11,1);
    		}
        #endif
		
		//LCD_DisplayNum(dabMet->CURRENT_AUDIO_INFO__BIT_RATE,10,1);	
		//LCD_DisplayNum(dabMet->CURRENT_AUDIO_INFO__MODE,13,1);
	}
	return ret;	
}
#endif //OPTION__INCLUDE_MODE__ANY
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
/***********************************************************************************

************************************************************************************/
#ifdef OPTION__INCLUDE_MODE__FM
RETURN_CODE tune_up_down(u8 up_downb)
{
	RETURN_CODE ret = SUCCESS;

#ifdef OPTION__INCLUDE_MODE__FMHD
    u16 tempFreqFMHD;
#endif //OPTION__INCLUDE_MODE__FMHD

#ifdef OPTION__INCLUDE_MODE__AMHD
    u16 tempFreqAMHD;
#endif //OPTION__INCLUDE_MODE__AMHD

	switch(work_mode)
	{
		case fmonly:
              ret = TuneStep(up_downb);
              if(ret == SUCCESS)
              {
                fm_freq = MetricsGetFMPtr()->FREQUENCY_10KHZ;
              }
			  display_refresh_flag = 1;//exectue the display now,not wait the seek complete any more
			  rds_update_ready_item =0;

			  break;
#ifdef OPTION__INCLUDE_MODE__AM
		case am:
              ret = TuneStep(up_downb);
              if(ret == SUCCESS)
              {
                am_freq = MetricsGetAMPtr()->FREQUENCY_1KHZ;
              }
			  display_refresh_flag = 1;//exectue the display now,not wait the seek complete any more
			  rds_update_ready_item =0;
			  break;				
#endif
#ifdef OPTION__INCLUDE_MODE__FMHD
		case fmhd:
             tempFreqFMHD = fmhd_freq;
			 ret = TuneStep(up_downb);
             if(ret == SUCCESS)
             {
               fmhd_freq = MetricsGetFMHDPtr()->FREQUENCY_10KHZ;
             }
			 display_refresh_flag = 1;//exectue the display now,not wait the seek complete any more

             if(fmhd_freq != tempFreqFMHD)
             {
    			 rds_update_ready_item = 0;
    			 sis_update_ready_item = 0;
             }
             psd_update_ready_item = 0;
             alert_update_ready_item = 0;
             break;
#endif //OPTION__INCLUDE_MODE__FMHD
#ifdef OPTION__INCLUDE_MODE__AMHD
		case amhd:
             tempFreqAMHD = amhd_freq;
			 ret = TuneStep(up_downb);
             if(ret == SUCCESS)
             {
               amhd_freq = MetricsGetAMHDPtr()->FREQUENCY_1KHZ;
             }
			 display_refresh_flag = 1;//exectue the display now,not wait the seek complete any more

             if(amhd_freq != tempFreqAMHD)
             {
    			 sis_update_ready_item = 0;
             }
             psd_update_ready_item = 0;
             alert_update_ready_item = 0;

			  break;
#endif //OPTION__INCLUDE_MODE__AMHD
		default:break;
	}
	return ret;
}
#endif //OPTION__INCLUDE_MODE__FM


#ifdef OPTION__INCLUDE_MODE__FM
RETURN_CODE set_freq_spacing(void)
{
    RETURN_CODE ret = SUCCESS;
    
    switch(work_mode)
    {
        case fmonly:
            ret |= SetStepSize(fm_freq_step_size);
            if(ret == SUCCESS)
            {
                fm_freq = MetricsGetFMPtr()->FREQUENCY_10KHZ;
            }
            break;
#ifdef OPTION__INCLUDE_MODE__FMHD
        case fmhd:
            ret |= SetStepSize(fmhd_freq_step_size);
            if(ret == SUCCESS)
            {
                fmhd_freq = MetricsGetFMHDPtr()->FREQUENCY_10KHZ;
            }
            break;
#endif // OPTION__INCLUDE_MODE__FMHD
#ifdef OPTION__INCLUDE_MODE__AM
		case am:
			ret |= SetStepSize(am_freq_step_size);
            if(ret == SUCCESS)
            {
                am_freq = MetricsGetAMPtr()->FREQUENCY_1KHZ;
            }
            break;
#endif //OPTION__INCLUDE_MODE__AM
        default:
            break;
    }

    return ret;
}
#endif // OPTION__INCLUDE_MODE__FM
/***********************************************************************************

************************************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
RETURN_CODE volume_inc(void)
{
	RETURN_CODE ret = SUCCESS;

	volume += VOLUME_STEP;
	if(volume>MAX_VOLUME)
	{
		volume =MAX_VOLUME;
	}
	return ret;
}
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
/***********************************************************************************

************************************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
RETURN_CODE volume_dec(void)
{
	RETURN_CODE ret = SUCCESS;

	if(volume>VOLUME_STEP)
	{
		volume -=VOLUME_STEP;
	}
	else
	{
		volume = 0;
	}
	return ret;
}
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
/***********************************************************************************
/-----------------------below is covertion the frequency to string--------------------
************************************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
#ifdef OPTION__INCLUDE_MODE__ANY
u8 freq_to_str(u16 freq,u8* buffer)
{
	u8 j,index,temp[8];
	u8 step_temp,display_number;
	char i;
	u16 freq_temp;
	freq_temp = freq;
	index =0;
	for(i=7;i>=0;i--) 
	{ 
		temp[i]='0'+freq_temp%10; 
		freq_temp/=10; 
	} 
	for(i=0;i<7;i++) 
	{ 
		if(temp[i]!='0')break; 
	}
	j = 0;
#ifdef OPTION__INCLUDE_MODE__FM
	if(work_mode == fmonly)
	{
		step_temp = fm_freq_step_size;
	}
#endif

#ifdef OPTION__INCLUDE_MODE__FMHD
	if(work_mode == fmhd)
	{
		step_temp = fmhd_freq_step_size;
	}
#endif

#ifdef OPTION__INCLUDE_MODE__AMHD
	if(work_mode == fmhd)
	{
		step_temp = amhd_freq_step_size;
	}
#endif

#ifdef OPTION__INCLUDE_MODE__AM
	if(work_mode == am)
	{
		step_temp = am_freq_step_size;
	}
#endif

	display_number =  7;
	if(step_temp <100)
	{
		display_number = 8;
	}
			
	for(;i<display_number;i++)
	{	
		buffer[index++]=temp[i];//97.1 103.5 103.500
		if(work_mode==fmonly||work_mode == fmhd)
		{
			j++;	
			if(freq <10000)
			{
				if(j==2)
				{
					buffer[index++]='.';
				}
				else if(j>3)
				{
					if(buffer[index] =='0')
					{
						buffer[index] = '\n';
						break;
					}
				}
			}
			else
			{
				if(j ==3)
				{
					buffer[index++] = '.';
				}
				else if(j>4)
				{
					if(buffer[index] =='0')
					{
						buffer[index] = '\n';
						break;
					}
				}
			}
		}
		else
		{
			buffer[index] = '\n';
		}
	}
	return index;
}
#endif //OPTION__INCLUDE_MODE__ANY	
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
/***********************************************************************************
show the fm frequency on LCD
************************************************************************************/
#ifdef OPTION__INCLUDE_MODE__FMHD
#ifdef OPTION__OPERATE_AS_SLAVE_NO_MMI
u8 get_HD_service_count(void)
{
	u8 i;
	u8 service_count_bitmask;
	u8 service_count;
	if(FMHDServiceListFastPtr()->MAIN_LIST_COMPLETE==0x00)
	{
		service_count_bitmask = FMHDServiceListFastPtr()->AUDIO_SERVICE_PRESENT_BITMASK;
		i = 0;
		service_count = 0;
		while(i++<8)
		{
			if(service_count_bitmask&0x01)
			{
				service_count +=1;
			}
			service_count_bitmask >>=1;
		}
	}
	else
	{
		service_count = FMHDServiceListAudioPtr()->SERVICE_COUNT;	
	}
	return service_count;
}
#endif//OPTION__OPERATE_AS_SLAVE_NO_MMI
/**************************************************************************************

***************************************************************************************/
u8 get_HD_service_name(u8* buffer)
{
	u8 index;
	u8 service_name_len;
	index = 0;
	buffer[index++] = '-';

    service_name_len = FMHDServiceListAudioPtr()->SERVICE[MetricsGetFMHDPtr()->CURRENT_AUDIO_SERVICE__LIST_INDEX].SERVICE_NAME_LENGTH;
    if(service_name_len > 7)
    {
        service_name_len = 7;
    }

	if((FMHDServiceListFastPtr()->MAIN_LIST_COMPLETE ==1)
		&&(service_name_len>0)
		&&(MetricsGetFMHDPtr()->CURRENT_AUDIO_SERVICE__LIST_INDEX !=0xFF))
	{
		CpyMemory(&buffer[index],FMHDServiceListAudioPtr()->SERVICE[MetricsGetFMHDPtr()->CURRENT_AUDIO_SERVICE__LIST_INDEX].SERVICE_NAME,service_name_len);

        index += service_name_len;
	}
	else //(FMHDServiceListFastPtr()->MAIN_LIST_COMPLETE ==0)
	{
		if(MetricsGetFMHDPtr()->CURRENT_AUDIO_SERVICE==0)
		{
			buffer[index++]='M';
			buffer[index++]='P';
			buffer[index++]='S';
		}
		else
		{
			buffer[index++]='S';
			buffer[index++]='P';
			buffer[index++]='S';
			buffer[index++]=MetricsGetFMHDPtr()->CURRENT_AUDIO_SERVICE+'0';
		}
	}

    buffer[index]='\n';
	return index;
}
#endif//OPTION__INCLUDE_MODE__FMHD	

/***********************************************************************************
show the fm frequency on LCD
************************************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
#ifdef OPTION__INCLUDE_MODE__ANY
#define MHZ_STRING_LENGTH 4
#define MHZ_STRING_LENGTH_LONG 6
RETURN_CODE show_freq(u8 x,u8 y)
{
	RETURN_CODE ret = SUCCESS;	
//    fmhd_service_list_fast* fmhdListFast = FMHDServiceListFastPtr();
//    fmhd_service_list* fmhdListAudio = FMHDServiceListAudioPtr();
	u8 lcd_line1[20];
	u8 index;
	if(pfunc!=IDLE)//
	{
		return ret;//there are some action need to be execute, pending refresh the LCD
	}
	index = 0;
	LCD_Clear(LCD_CLEAR_LINE1);
	ClearMemory(lcd_line1,sizeof(lcd_line1));
#ifdef OPTION__INCLUDE_MODE__FM
	if(work_mode == fmonly)
	{
		lcd_line1[index++] ='F';
		lcd_line1[index++] ='M';
		lcd_line1[index++] =' ';
		index+=freq_to_str(fm_freq,lcd_line1+index);
		CpyMemory(lcd_line1+index, "MHz\n", 3);
	}
#endif //OPTION__INCLUDE_MODE__FM

#ifdef OPTION__INCLUDE_MODE__AM
	else if(work_mode == am)
	{
		lcd_line1[index++] ='A';
		lcd_line1[index++] ='M';
		lcd_line1[index++] =' ';
		index+=freq_to_str(am_freq,lcd_line1+index);
		CpyMemory(lcd_line1+index, "kHz\n", 3);		
	}
#endif

#ifdef OPTION__INCLUDE_MODE__FMHD
	else if(work_mode == fmhd)
	{

		if(MetricsGetFMHDPtr()->HDLOGO == 1)
		{
			lcd_line1[index++] ='H';
			lcd_line1[index++] ='D';
			lcd_line1[index++] =' ';
		}
		else
		{
			lcd_line1[index++] ='F';
			lcd_line1[index++] ='M';
			lcd_line1[index++] =' ';			
		}
		index+=freq_to_str(fmhd_freq,lcd_line1+index);
		if(MetricsGetFMHDPtr()->AUDIO_SOURCE ==1)// audio blend to digital signal
		{
			index = get_HD_service_name(lcd_line1+index);
//			if((FMHDServiceListFastPtr()->AUDIO_SERVICE_PRESENT_BITMASK)>>(MetricsGetFMHDPtr()->CURRENT_AUDIO_SERVICE+1)>0)
//			{
//				lcd_line1[index++] = '+';
//			}	
//			lcd_line1[index] = '\n';
		}
		else
		{
			CpyMemory(lcd_line1+index, "MHz\n", 3);
		}
	}
#endif //OPTION__INCLUDE_MODE__FMHD
#ifdef OPTION__INCLUDE_MODE__AMHD
	else if(work_mode == amhd)
	{

		if(MetricsGetAMHDPtr()->HDLOGO == 1)
		{
			lcd_line1[index++] ='H';
			lcd_line1[index++] ='D';
			lcd_line1[index++] =' ';
		}
		else
		{
			lcd_line1[index++] ='A';
			lcd_line1[index++] ='M';
			lcd_line1[index++] =' ';			
		}
		index+=freq_to_str(amhd_freq,lcd_line1+index);
		if(MetricsGetAMHDPtr()->AUDIO_SOURCE ==1)// audio blend to digital signal
		{
			index = get_HD_service_name(lcd_line1+index);
		}
		else
		{
			CpyMemory(lcd_line1+index, "kHz\n", 3);
		}
	}
#endif //OPTION__INCLUDE_MODE__AMHD
	LCD_DisplayStr(lcd_line1,x,y);	

	if(mute_flag)
	{
		LCD_DisplayCBD(0,14,0);	
		LCD_DisplayCBD(1,15,0);		
	}		
	return ret;	
}
#endif //OPTION__INCLUDE_MODE__ANY
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
/***********************************************************************************

************************************************************************************/
RETURN_CODE idle(void)
{
	RETURN_CODE ret = SUCCESS;

	return ret;
}
/****************************************************************************************
Preset the action for fm HD dab
******************************************************************************************/	
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
#ifdef OPTION__INCLUDE_MODE__ANY
#define PSET_DISPLAY_POSITION	3
RETURN_CODE pset_operate(u8 operate)
{
	u8 flag,i;
	RETURN_CODE ret = SUCCESS;
	u8 str_temp[15];
    u8 str_num = 0;
#ifdef OPTION__INCLUDE_MODE__DAB
    #ifndef OPTION__DAB_PRESETS_AS_FAVORITES
	    u8 ptyCurrent;
	    u8 encodeingCurrent;
    #endif //OPTION__DAB_PRESETS_AS_FAVORITES
	//u32 temp_service_id;
	//u16 temp_component_id;
#endif
#ifdef OPTION__INCLUDE_MODE__FM
    u8 mhzString[MHZ_STRING_LENGTH] = {'M','H','z','\n'};
	#ifdef OPTION__FM_SHOW_STATION_NAME_PST
		u8 xdata temp_str[16];
	#endif
#endif
#ifdef OPTION__INCLUDE_MODE__FMHD
    u8 mhzStringLong[MHZ_STRING_LENGTH_LONG] = {'M','H','z',' ',' ','\n'};
#endif

#ifdef OPTION__DAB_PRESETS_AS_FAVORITES
    if(work_mode != dab) {
#endif //OPTION__DAB_PRESETS_AS_FAVORITES

	switch(operate)
	{
		case ADD_PRESET:
				flag = 0;

				for(i=0;i<MAX_PRESET_NUM;i++)
				{
#ifdef OPTION__INCLUDE_MODE__FM
					if(work_mode == fmonly)
					{
						if(fm_pset_table[i] ==0) // the valid station is valid bit equal 1
						{
							flag = 1;
							fm_pset_table[i] = fm_freq;

							#ifdef OPTION__FM_SHOW_STATION_NAME_PST
								if(rds_update_ready_item&UPDATED_RDS_PST_ITEM)
								{
									str_to_lcd_buf(temp_str,12,RDSGetProgramServiceTextPtr(),loop_display_times,RDS_PROGRAM_SERVICE_BUFFER_SIZE,0);
									CpyMemory(fm_pty_pset_table[i],temp_str,12);
								}
							#endif

							//i = MAX_PRESET_NUM;
							break;
						}
					}
#endif
#ifdef OPTION__INCLUDE_MODE__FMHD
					if(work_mode == fmhd)
					{
						if(fmhd_pset_table[i].valid != 1) 
						{
							flag = 1;
							fmhd_pset_table[i].valid = 1;
							fmhd_pset_table[i].frequency = fmhd_freq;
							if(MetricsGetFMHDPtr()->AUDIO_SOURCE ==1)// audio blend to digital signal
							{
								fmhd_pset_table[i].component_id = MetricsGetFMHDPtr()->CURRENT_AUDIO_SERVICE; 
								get_HD_service_name(fmhd_pset_table[i].service_name);
							}
							else
							{			
								fmhd_pset_table[i].component_id = 0xFF;			
								CpyMemory(fmhd_pset_table[i].service_name,mhzStringLong,MHZ_STRING_LENGTH_LONG);
							}
								
							//i = MAX_PRESET_NUM;
							break;
						}
					}
#endif//OPTION__INCLUDE_MODE__FMHD
#ifdef OPTION__INCLUDE_MODE__AM
					if(work_mode == am)
					{
						if(am_pset_table[i] ==0) // the valid station is valid bit equal 1
						{
							flag = 1;
							am_pset_table[i] = am_freq;
							//i = MAX_PRESET_NUM;
							break;
						}
					}
#endif
#ifdef OPTION__INCLUDE_MODE__AMHD
					if(work_mode == amhd)
					{
						if(amhd_pset_table[i].valid != 1) 
						{
							flag = 1;
							amhd_pset_table[i].valid = 1;
							amhd_pset_table[i].frequency = amhd_freq;
							if(MetricsGetAMHDPtr()->AUDIO_SOURCE ==1)// audio blend to digital signal
							{
								amhd_pset_table[i].component_id = MetricsGetAMHDPtr()->CURRENT_AUDIO_SERVICE; 
								get_HD_service_name(amhd_pset_table[i].service_name);
							}
							else
							{			
								amhd_pset_table[i].component_id = 0xFF;			
								CpyMemory(amhd_pset_table[i].service_name,"kHz/n",3);
							}
								
							//i = MAX_PRESET_NUM;
							break;
						}
					}
#endif//OPTION__INCLUDE_MODE__AMHD
#ifdef OPTION__INCLUDE_MODE__DAB
    #ifndef OPTION__DAB_PRESETS_AS_FAVORITES
					if(work_mode == dab) 
					{
						if(dab_pset_table[i].valid != 1)
						{
							if(MetricsGetDABPtr()->VALID&&MetricsGetDABPtr()->ACQ>0)
							{
								flag = 1;
								dab_pset_table[i].valid = 1;
								dab_pset_table[i].freq_index = MetricsGetDABPtr()->FREQUENCY_INDEX;
								GetCurrentServiceIdentification_DAB(&dab_pset_table[i].service_id,&dab_pset_table[i].component_id);
								GetCurrentServiceString_DAB(&dab_pset_table[i].label_str,&ptyCurrent,&encodeingCurrent);
								dab_pset_table[i].label_str[DAB_SERVICE_LIST_SERVICE_LABEL__SIZE] = '\n';
								//i = MAX_PRESET_NUM;
							}
							else
							{
								flag = 2;//current DAB is not a valid station;
							}
							break;
						}
					}
    #endif //OPTION__DAB_PRESETS_AS_FAVORITES	
#endif						
				}

				LCD_Clear(LCD_CLEAR_LINE2);
				if(flag==0)
				{
					LCD_DisplayStr("Preset is full\n",0,1);
				}
				else if(flag ==1)
				{
					LCD_Clear(LCD_CLEAR_ALL);
					LCD_DisplayStr("Preset\n",3,0);
					LCD_DisplayNum(i+1,10,0);
					LCD_DisplayStr("Stored\n",4,1);
                    eeprom_save_parameter();
				}
				else
				{
					LCD_Clear(LCD_CLEAR_ALL);
					LCD_DisplayStr("Not a valid stat\n",0,0);
					LCD_DisplayNum(i+1,10,0);
					LCD_DisplayStr("No Stored\n",3,1);
				}			
				break;
		case  DEL_PRESET:
				flag = 0;
				pfunc = IDLE;//cancel the dec_preset action.
				for(i=0;i<MAX_PRESET_NUM;i++)
				{
					if(flag ==1)
					{
#ifdef OPTION__INCLUDE_MODE__FM
						if(work_mode == fmonly)
						{
							if(fm_pset_table[i] !=0)//move the behind freq to cover the former one
							{
								fm_pset_table[i-1] = fm_pset_table[i];
								fm_pset_table[i] = 0;
								#ifdef OPTION__FM_SHOW_STATION_NAME_PST
									CpyMemory(fm_pty_pset_table[i-1],fm_pty_pset_table[i],12);
									ClearMemory(fm_pty_pset_table[i],12);
								#endif
							}
						}
#endif
#ifdef OPTION__INCLUDE_MODE__FMHD
						if(work_mode == fmhd)
						{
							if(fmhd_pset_table[i].valid == 1)//move the behind freq to cover the former one
							{
								CpyMemory((u8*)&fmhd_pset_table[i-1],&fmhd_pset_table[i],sizeof(fmhd_pset_table[i]));
								fmhd_pset_table[i].valid = 0;
							}
						}
#endif
#ifdef OPTION__INCLUDE_MODE__AM
						if(work_mode == am)
						{
							if(am_pset_table[i] !=0)//move the behind freq to cover the former one
							{
								am_pset_table[i-1] = am_pset_table[i];
								am_pset_table[i] = 0;
							}
						}
#endif//#option_include_mode_am
#ifdef OPTION__INCLUDE_MODE__AMHD
						if(work_mode == amhd)
						{
							if(amhd_pset_table[i].valid == 1)//move the behind freq to cover the former one
							{
								CpyMemory((u8*)&amhd_pset_table[i-1],&amhd_pset_table[i],sizeof(amhd_pset_table[i]));
								amhd_pset_table[i].valid = 0;
							}
						}
#endif

#ifdef OPTION__INCLUDE_MODE__DAB
    #ifndef OPTION__DAB_PRESETS_AS_FAVORITES
						if(work_mode == dab)
						{
							if(dab_pset_table[i].valid ==1)
							{
								CpyMemory((u8*)&dab_pset_table[i-1],(u8*)&dab_pset_table[i],sizeof(dab_pset_table[i]));
								dab_pset_table[i].valid = 0;
							}
						}
    #endif //OPTION__DAB_PRESETS_AS_FAVORITES
#endif
					}
					else
					{
					
#ifdef OPTION__INCLUDE_MODE__FM
						if(work_mode == fmonly)
						{
							//if(fm_pset_table[i]== fm_freq)
							if(i == pset_table_index)
							{
								fm_pset_table[i] = 0;//wipe the pset value
								flag = 1;
								#ifdef OPTION__FM_SHOW_STATION_NAME_PST
									ClearMemory(fm_pty_pset_table[i],12);
								#endif


							}
						}
#endif
#ifdef OPTION__INCLUDE_MODE__FMHD
						if(work_mode == fmhd)
						{
							//if(fmhd_pset_table[i]== fmhd_freq)
							if(i == pset_table_index)
							{
								if(fmhd_pset_table[i].valid == 1)
								{
									fmhd_pset_table[i].valid = 0;//wipe the pset value
									flag = 1;
								}
								//fmhd_pset_table[i] = 0;//wipe the pset value
								//flag = 1;
							}
						}
#endif

#ifdef OPTION__INCLUDE_MODE__AM
						if(work_mode == am)
						{
							//if(fm_pset_table[i]== fm_freq)
							if(i == pset_table_index)
							{
								am_pset_table[i] = 0;//wipe the pset value
								flag = 1;
							}
						}
#endif
#ifdef OPTION__INCLUDE_MODE__AMHD
						if(work_mode == amhd)
						{
							//if(fmhd_pset_table[i]== fmhd_freq)
							if(i == pset_table_index)
							{
								if(amhd_pset_table[i].valid == 1)
								{
									amhd_pset_table[i].valid = 0;//wipe the pset value
									flag = 1;
								}
								//fmhd_pset_table[i] = 0;//wipe the pset value
								//flag = 1;
							}
						}
#endif
#ifdef OPTION__INCLUDE_MODE__DAB
    #ifndef OPTION__DAB_PRESETS_AS_FAVORITES
						if(work_mode == dab)
						{
							//GetCurrentServiceIdentification_DAB(&temp_service_id,&temp_component_id);
							//if(dab_pset_table[i].freq_index ==MetricsGetDABPtr()->FREQUENCY_INDEX 
							//	&&dab_pset_table[i].service_id ==temp_service_id
							//	&&dab_pset_table[i].component_id == temp_component_id
							//	)
							if(i == pset_table_index)
							{
								if(dab_pset_table[i].valid == 1)
								{
									dab_pset_table[i].valid = 0;//wipe the pset value
									flag = 1;
								}
							}
						}
    #endif //OPTION__DAB_PRESETS_AS_FAVORITES
#endif
					}
				}

                if(flag == 1)
				{					
				    //LCD  delete the pset value
					LCD_Clear(LCD_CLEAR_ALL);
					LCD_DisplayStr("Preset\n",3,0);
					LCD_DisplayNum(pset_table_index+1,10,0);
					LCD_DisplayStr("delete\n",4,1);
                    eeprom_save_parameter();
				}
				break;
		case INC_PRESET:
				if(pset_table_index<MAX_PRESET_NUM-1)
				{
					pset_table_index +=1;
						
				}
				else
				{
					pset_table_index  = 0;
				}
				break;
		case DEC_PRESET:
				if(pset_table_index>0)
				{
					pset_table_index --;
				}
				else
				{
					pset_table_index = MAX_PRESET_NUM-1;
				}
				break;
		default:break;
		}

		if(operate == DEC_PRESET ||operate ==INC_PRESET)
		{
			flag = 0;
#ifdef OPTION__INCLUDE_MODE__FM
			if(work_mode == fmonly)
			{
				if(fm_pset_table[pset_table_index] ==0)
				{
					flag = 1;
				}
				else
				{
					LCD_Clear(LCD_CLEAR_LINE1);
					//show_freq(fm_pset_table[pset_table_index],0,0);
					str_num+=freq_to_str(fm_pset_table[pset_table_index],str_temp);
					LCD_DisplayStr("FM\n",0,0);
					CpyMemory(str_temp+str_num,mhzString,MHZ_STRING_LENGTH);

					#ifdef OPTION__FM_SHOW_STATION_NAME_PST

						if(fm_pty_pset_table[pset_table_index][0] !=0)
						{
							LCD_Clear(LCD_CLEAR_LINE1);
							LCD_DisplayStr(fm_pty_pset_table[pset_table_index],0,0);
						}
					#endif



					LCD_DisplayStr(str_temp,3,0);
					LCD_DisplayStr("Ps\n",14,0);
                    fm_freq = fm_pset_table[pset_table_index];
					pfunc = FM_START_PSET;
					display_delay_4ms  = 1500;
				}					
			}
#endif
#ifdef OPTION__INCLUDE_MODE__AM
			if(work_mode == am)
			{
				if(am_pset_table[pset_table_index] ==0)
				{
					flag = 1;
				}
				else
				{
					LCD_Clear(LCD_CLEAR_LINE1);
					//show_freq(fm_pset_table[pset_table_index],0,0);
					str_num+=freq_to_str(am_pset_table[pset_table_index],str_temp);
					LCD_DisplayStr("AM\n",0,0);
					CpyMemory(str_temp+str_num,"KHz\n",MHZ_STRING_LENGTH);

					LCD_DisplayStr(str_temp,3,0);
					LCD_DisplayStr("Ps\n",14,0);
                    am_freq = am_pset_table[pset_table_index];
					pfunc = AM_START_PSET;
					display_delay_4ms  = 1500;
				}
			}	
#endif

#ifdef OPTION__INCLUDE_MODE__FMHD
			if(work_mode == fmhd)
			{
				if(fmhd_pset_table[pset_table_index].valid !=1)
				{
					flag = 1;
				}
				else
				{
					LCD_Clear(LCD_CLEAR_LINE1);
					str_num+=freq_to_str(fmhd_pset_table[pset_table_index].frequency,str_temp);
					str_temp[str_num]='\n';
					LCD_DisplayStr(str_temp,3,0);
					LCD_DisplayStr(fmhd_pset_table[pset_table_index].service_name,(str_num+3),0);


					if(fmhd_pset_table[pset_table_index].component_id!=0xFF)
					{
						LCD_DisplayStr("HD\n",0,0);
					}
					else
					{
						LCD_DisplayStr("FM\n",0,0);
					}
					LCD_DisplayStr("Ps\n",14,0);
					pfunc = FMHD_START_PSET_CHANNEL;
					display_delay_4ms  = 2000;
				}					
			}
#endif
#ifdef OPTION__INCLUDE_MODE__AMHD
			if(work_mode == amhd)
			{
				if(amhd_pset_table[pset_table_index].valid !=1)
				{
					flag = 1;
				}
				else
				{
					LCD_Clear(LCD_CLEAR_LINE1);
					str_num+=freq_to_str(amhd_pset_table[pset_table_index].frequency,str_temp);
					str_temp[str_num]='\n';
					LCD_DisplayStr(str_temp,3,0);
					LCD_DisplayStr(amhd_pset_table[pset_table_index].service_name,(str_num+3),0);


					if(amhd_pset_table[pset_table_index].component_id!=0xFF)
					{
						LCD_DisplayStr("HD\n",0,0);
					}
					else
					{
						LCD_DisplayStr("AM\n",0,0);
					}
					LCD_DisplayStr("Ps\n",14,0);
					pfunc = AMHD_START_PSET_CHANNEL;
					display_delay_4ms  = 2000;
				}					
			}
#endif
#ifdef OPTION__INCLUDE_MODE__DAB
    #ifndef OPTION__DAB_PRESETS_AS_FAVORITES
			if(work_mode == dab)
			{
				if(dab_pset_table[pset_table_index].valid !=1)
				{
					flag = 1;
				}
				else if(dab_pset_table[pset_table_index].valid ==1)
				{
					LCD_Clear(LCD_CLEAR_LINE1);
					LCD_DisplayStr(dab_pset_table[pset_table_index].label_str,0,0);
					pfunc = DAB_START_PSET_CHANNEL;//as dab manuel tune need a long time,so it need to execute after user exit browse pset mode
					if(dls_update_ready_item&UPDATED_DLS_STRING_ITEM)
					{
						dls_update_ready_item =0;
						ClearMemory(DLSGetPtr()->DATA,DLSGetPtr()->LENGTH+1);
						DLSGetPtr()->LENGTH = 0;
					}
					display_delay_4ms  = 2000;
				}
				else
				{
					dab_pset_table[pset_table_index].valid =0;
					flag =1;
				}
			}
    #endif //OPTION__DAB_PRESETS_AS_FAVORITES
#endif
			if(flag)
			{
				LCD_Clear(LCD_CLEAR_LINE1);
				LCD_DisplayStr("Preset\n",1,0);
				LCD_DisplayNum(pset_table_index+1,7,0);
				LCD_DisplayStr("Empty\n",10,0);
				pfunc = IDLE;
			}
			LCD_Clear(LCD_CLEAR_LINE2);

			LCD_DisplayStr("----------------\n",0,1);

			for(i=0;i<MAX_PRESET_NUM;i++)
			{	
				flag = 0;
#ifdef OPTION__INCLUDE_MODE__FM
				if(work_mode == fmonly)
				{
					if(fm_pset_table[i] != 0)
						LCD_DisplayCBD(DEF_SFRECTANGLE,i+PSET_DISPLAY_POSITION,1);
					else
						LCD_DisplayCBD(DEF_SERECTANLG,i+PSET_DISPLAY_POSITION,1);	
					if(i == pset_table_index)
					{
						if(fm_pset_table[i] == 0){
							LCD_DisplayCBD(DEF_SSERECTANGLE,i+PSET_DISPLAY_POSITION,1);	
						}else{
							LCD_DisplayCBD(DEF_SSFRECTANGLE,i+PSET_DISPLAY_POSITION,1);	
						}
					}
				}
#endif
#ifdef OPTION__INCLUDE_MODE__AM
				if(work_mode == am)
				{
					if(am_pset_table[i] != 0)
						LCD_DisplayCBD(DEF_SFRECTANGLE,i+PSET_DISPLAY_POSITION,1);
					else
						LCD_DisplayCBD(DEF_SERECTANLG,i+PSET_DISPLAY_POSITION,1);	
					if(i == pset_table_index)
					{
						if(am_pset_table[i] == 0){
							LCD_DisplayCBD(DEF_SSERECTANGLE,i+PSET_DISPLAY_POSITION,1);	
						}else{
							LCD_DisplayCBD(DEF_SSFRECTANGLE,i+PSET_DISPLAY_POSITION,1);	
						}
					}
				}
#endif
#ifdef OPTION__INCLUDE_MODE__FMHD
				if(work_mode == fmhd)
				{
					if(fmhd_pset_table[i].valid == 1)
						LCD_DisplayCBD(DEF_SFRECTANGLE,i+PSET_DISPLAY_POSITION,1);
					else
						LCD_DisplayCBD(DEF_SERECTANLG,i+PSET_DISPLAY_POSITION,1);	
					if(i == pset_table_index)
					{
						if(fmhd_pset_table[i].valid != 1){
							LCD_DisplayCBD(DEF_SSERECTANGLE,i+PSET_DISPLAY_POSITION,1);	
						}else{
							LCD_DisplayCBD(DEF_SSFRECTANGLE,i+PSET_DISPLAY_POSITION,1);	
						}
					}
				}
#endif
#ifdef OPTION__INCLUDE_MODE__AMHD
				if(work_mode == amhd)
				{
					if(amhd_pset_table[i].valid == 1)
						LCD_DisplayCBD(DEF_SFRECTANGLE,i+PSET_DISPLAY_POSITION,1);
					else
						LCD_DisplayCBD(DEF_SERECTANLG,i+PSET_DISPLAY_POSITION,1);	
					if(i == pset_table_index)
					{
						if(amhd_pset_table[i].valid != 1){
							LCD_DisplayCBD(DEF_SSERECTANGLE,i+PSET_DISPLAY_POSITION,1);	
						}else{
							LCD_DisplayCBD(DEF_SSFRECTANGLE,i+PSET_DISPLAY_POSITION,1);	
						}
					}
				}
#endif
#ifdef OPTION__INCLUDE_MODE__DAB
    #ifndef OPTION__DAB_PRESETS_AS_FAVORITES
				if(work_mode == dab)
				{
					if(dab_pset_table[i].valid == 1)
						LCD_DisplayCBD(DEF_SFRECTANGLE,i+PSET_DISPLAY_POSITION,1);
					else
						LCD_DisplayCBD(DEF_SERECTANLG,i+PSET_DISPLAY_POSITION,1);	
					if(i == pset_table_index)
					{
						if(dab_pset_table[i].valid != 1){
							LCD_DisplayCBD(DEF_SSERECTANGLE,i+PSET_DISPLAY_POSITION,1);	
						}else{
							LCD_DisplayCBD(DEF_SSFRECTANGLE,i+PSET_DISPLAY_POSITION,1);	
						}
					}
				}
    #endif //OPTION__DAB_PRESETS_AS_FAVORITES
#endif							
			}//end for(i=0;i<MAX_PRESET_NUM;i++)

		}//	end if(operate == DEC_PRESET ||operate ==INC_PRESET)
#ifdef OPTION__DAB_PRESETS_AS_FAVORITES
    }
#endif //OPTION__DAB_PRESETS_AS_FAVORITES			
	return ret;
}
#endif //OPTION__INCLUDE_MODE__ANY
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
/***********************************************************************************
now just for RDS PI,PSD,SIS 
************************************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
#ifdef OPTION__INCLUDE_MODE__ANY
code u8 hex_str[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
RETURN_CODE dec_to_hex_str(u32 num,u8* str,bit isHex)
{
	RETURN_CODE ret = SUCCESS;
	u8 temp[11];
    u8 divisor;
	char i;
	u8 j;

    if(isHex)
    {
        divisor = 16;
    }
    else
    {
        divisor = 10;
    }
	for(i=10;i>=0;i--) 
	{
		temp[i]=hex_str[num % divisor]; 
		num /= divisor; 
	} 
	for(i=0;i<10;i++) 
	{ 
		if(temp[i]!='0')break; 
	}
	j =0;
	for(;i<11;i++)
	{
		str[j++]=temp[i];
	}
	str[j] ='\n';

	return ret;	
}
#endif //OPTION__INCLUDE_MODE__ANY
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
/****************************************************************************************
str :output str
str_len:output str length
in_str: input str
void UCS2_To_ASCII(u8 len,u16* pIn,u8* pOut)

u8 UCS2_To_ASCII(u8 len,u8* usc2_str,u8* ascii_str);
u8 UTF8_To_ASCII(u8 len,u8* utf8_str,u8* ascii_str);
*******************************************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
#ifdef OPTION__INCLUDE_MODE__ANY
void decode_str(u8* out_str,u8* out_str_len,u8* in_str,u8 in_str_len,DAB_DLS_ENCODING_TYPE encode)
{
#ifdef OPTION__INCLUDE_MODE__DAB
	if(work_mode == dab)
	{
		if(encode == DLS_EBU)
		{
			CpyMemory(out_str,in_str,in_str_len);
			*out_str_len = in_str_len;
		}
		else if(encode == DLS_UCS2||encode == 0x04)
		{
			*out_str_len = UCS2_To_EBU(in_str_len,in_str,out_str);
		}
		else if(encode == DLS_UTF8)
		{
			*out_str_len = UTF8_To_EBU(in_str_len,in_str,out_str);
		}
		else//unidentifiable code decoded by ascii
		{
			CpyMemory(out_str,in_str,in_str_len);
			*out_str_len = in_str_len;
		}
	}
#endif //OPTION__INCLUDE_MODE__DAB

#ifdef OPTION__INCLUDE_MODE__FM
	if(work_mode == fmonly ||work_mode == fmhd)
	{
		if(encode == IEC_8859_1)
		{
			CpyMemory(out_str,in_str,in_str_len);
			*out_str_len = in_str_len;
		}
		else if(encode == UCS2_LITTLEENDIAN)
		{
			*out_str_len = UCS2_To_EBU(in_str_len,in_str,out_str);
		}
		else //unidentifiable code,decoded by ascii
		{
			CpyMemory(out_str,in_str,in_str_len);
			*out_str_len = in_str_len;
		}
	}
#endif//OPTION__INCLUDE_MODE__FM			
}
#endif //OPTION__INCLUDE_MODE__ANY
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
/****************************************************************************************
lcd_buf:		display on lcd buffer
lcd_dip_len: 	the num of string display on lcd
input_str:		which should be display on LCD
input_offset: 	the start character of string should be display on LCD
str_max_len: 	the max length of string for end of display
end_character:	for stop the display avoid LCD display overflow
*******************************************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
#ifdef OPTION__INCLUDE_MODE__ANY
#define REACH_TO_END_STRING 1
#define SCROLL_DISPLAY_STRING 0
u8 str_to_lcd_buf(u8 *lcd_buf,u8 lcd_disp_len,u8 *input_str,u8 input_offset,u8 str_max_len,u8 end_character)
{
	u8 i;//j;
	if(str_max_len <lcd_disp_len)
	{
		CpyMemory(lcd_buf,input_str,str_max_len); // Note must be sure we allocate enough space in temp_str for FMHD_SIS_STATION_NAME_SHORT_BUFFER_SIZE + 1
		lcd_buf[str_max_len] ='\n';		
		return REACH_TO_END_STRING;
	}
	else
	{
		for(i=0;i<lcd_disp_len;i++)
		{
			lcd_buf[i]=input_str[input_offset+i];
			if(((input_offset+i) > (str_max_len-1)) || (lcd_buf[i] == end_character))
			{
 				lcd_buf[i]='\n';
				return REACH_TO_END_STRING;
			}
		}
	}
	return SCROLL_DISPLAY_STRING;
}
#endif //OPTION__INCLUDE_MODE__ANY
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
/****************************************************************************************
include FM HD all display info like Mertric RDS SIS PSD DLS
******************************************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
#ifdef OPTION__INCLUDE_MODE__ANY
#define TEMP_STR_LENGTH 15
#define CHAR_HOLD_TIME	500
#define CHAR_ROLL_SPEED	200
#define dabRadioDNSEndLength 18
#define fmRadioDNSEndLength 17
u8 display_data_item(u8 state)
{
	//static u8 loop_display_times = 0;
	u8 xdata temp_str[TEMP_STR_LENGTH];
    u8 xdata str[128];
	u8 xdata str_len;
#ifdef OPTION__INCLUDE_MODE__FM
	rds_time temp_rds_time;
#endif //OPTION__INCLUDE_MODE__FM

#ifdef OPTION__RADIODNS
    u8 xdata radio_dns_str[37];
    u8 dnsStringOffset = 0;
    #ifdef OPTION__INCLUDE_MODE__DAB
        radioDNS_dab dns_dab;
        u8 dabStringEnd[dabRadioDNSEndLength] = {'.','d','a','b','.','r','a','d','i','o','d','n','s','.','o','r','g','\n'};
    #endif
    #ifdef OPTION__INCLUDE_MODE__FM
        radioDNS_fm dns_fm;
        u8 fmStringEnd[fmRadioDNSEndLength] = {'.','f','m','.','r','a','d','i','o','d','n','s','.','o','r','g','\n'};
    #endif
#endif

	char convertedHour;
	u8 ret_action;
	RETURN_CODE ret = SUCCESS;	


	ret_action = ITEM_STAND;


//	ret_action = ITEM_NEXT;
//	ret = UpdateDataServiceData();
//	return ret_action;

	switch(state)
	{
		case ITEM_AUTO_ROLL:
			ret_action = ITEM_NEXT;
			loop_display_times = 0;
			break;
		case ITEM_METRIC:
			ret = display_metric();
			loop_display_times ++;
			if(loop_display_times>ITEM_METRIC_LOOP_TIMES)
			{
				loop_display_times = 0;
				ret_action = ITEM_NEXT;
			}
			break;
#ifdef OPTION__INCLUDE_MODE__FM
		case ITEM_RDS_PI:
				ret = UpdateDataServiceData();
				if(ret == SUCCESS)
				{
					LCD_Clear(LCD_CLEAR_LINE2);
					LCD_DisplayStr("PI:\n",0,1);
					if(rds_update_ready_item&UPDATED_RDS_PI_ITEM)
					{
						#ifdef ATS_EMBED_CODE
							ATS_RDS_valid_flag = 1;
						#endif
						dec_to_hex_str((u32)RDSGetProgramIdentifier(),temp_str+2,1);
						temp_str[0] ='0';
						temp_str[1] ='x';
						LCD_DisplayStr(temp_str,4,1);
						loop_display_times++;
						if(loop_display_times>ITEM_RDS_PI_LOOP_TIMES)
						{
							loop_display_times = 0;
							ret_action = ITEM_NEXT;;
						}
					}
					else
					{
						ret_action = ITEM_NEXT;// the item is no ready for display ,then goto next item
					}	
				}
				else
				{
					//error();
					ret_action = ITEM_NEXT;
				}
				break;
		case ITEM_RDS_PTY:
				ret = UpdateDataServiceData();
				if(ret == SUCCESS)
				{
					LCD_Clear(LCD_CLEAR_LINE2);
					LCD_DisplayStr("PTY:\n",0,1);
					if(rds_update_ready_item&UPDATED_RDS_PTY_ITEM)
					{
						#ifdef ATS_EMBED_CODE
							ATS_RDS_valid_flag = 1;
						#endif
						LCD_DisplayStr(RDS_Pty_List[RDSGetProgramType()],4,1);
						loop_display_times ++;
						if(loop_display_times>ITEM_RDS_PTY_LOOP_TIMES)
						{
							loop_display_times = 0;
							ret_action = ITEM_NEXT;
						}
					}
					else
					{
						ret_action = ITEM_NEXT;// the item is no ready for display ,then goto next item
					}		
				}
				else
				{
					//error();
					ret_action = ITEM_NEXT;
				}
			break;
		case ITEM_RDS_RT:
				ret = UpdateDataServiceData();
				if(ret == SUCCESS)
				{
					LCD_Clear(LCD_CLEAR_LINE2);
					LCD_DisplayStr("RT:\n",0,1);
					if(rds_update_ready_item&UPDATED_RDS_RT_ITEM)//check the item whether it is ready for display
					{
						#ifdef ATS_EMBED_CODE
							ATS_RDS_valid_flag = 1;
						#endif
						display_item_str_4ms = CHAR_ROLL_SPEED;
						if(str_to_lcd_buf(temp_str,13,RDSGetRadioTextPtr(),loop_display_times,RDS_RADIO_TEXT_BUFFER_SIZE,0x0d))
						{
							display_item_str_4ms = CHAR_HOLD_TIME;
							loop_display_times = 0;
							ret_action = ITEM_NEXT;
                            //return ret_action;
						}
						else
						{
							loop_display_times++;
						}
						LCD_DisplayStr(temp_str,4,1);

					}
					else
					{
						ret_action = ITEM_NEXT;// the item is no ready for display ,then goto next item
					}						
				}
				else
				{
					//error();
					ret_action = ITEM_NEXT;
				}
			break;
		case ITEM_RDS_PST:
				ret = UpdateDataServiceData();
				if(ret == SUCCESS)
				{
					LCD_Clear(LCD_CLEAR_LINE2);
					LCD_DisplayStr("PST:\n",0,1);
					if(rds_update_ready_item&UPDATED_RDS_PST_ITEM)//check the item whether it is ready for display
					{
						#ifdef ATS_EMBED_CODE
							ATS_RDS_valid_flag = 1;
						#endif
						display_item_str_4ms = CHAR_ROLL_SPEED;
						if(str_to_lcd_buf(temp_str,12,RDSGetProgramServiceTextPtr(),loop_display_times,RDS_PROGRAM_SERVICE_BUFFER_SIZE,0))
						{
							display_item_str_4ms = CHAR_HOLD_TIME;
							loop_display_times = 0;
							ret_action = ITEM_NEXT;
                            //return ret_action;

							#ifdef OPTION__FM_SHOW_STATION_NAME_PST
									LCD_Clear(LCD_CLEAR_LINE1);
									LCD_DisplayStr(temp_str,0,0);
							#endif
						}
						else
						{
							loop_display_times++;
						}
						LCD_DisplayStr(temp_str,4,1);
					}
					else
					{
						ret_action = ITEM_NEXT;// the item is no ready for display ,then goto next item
					}	
				}
				else
				{
					//error();
					ret_action = ITEM_NEXT;
				}				
			break;
		case ITEM_RDS_TIME:
				ret = UpdateDataServiceData();
				if(ret == SUCCESS)
				{
					LCD_Clear(LCD_CLEAR_LINE2);
					LCD_DisplayStr("CT:\n",0,1);
					if(rds_update_ready_item&UPDATED_RDS_TIME_ITEM)//check the item whether it is ready for display
					{
						temp_rds_time = RDSGetCurrentTime();
                        if(temp_rds_time.ctDayLow != 0)
                        {
                            convertedHour = temp_rds_time.ctHour + (temp_rds_time.ctOffset / 2);
                            if (convertedHour < 0)
                            {
                                convertedHour = 24 + convertedHour;
                            }
							LCD_DisplayNum(convertedHour,4,1);
							LCD_DisplayStr(":\n",7,1);
							LCD_DisplayNum(temp_rds_time.ctMinute,6,1);
                        }						
						loop_display_times ++;
						if(loop_display_times>ITEM_RDS_TIME_LOOP_TIMES)
						{
							loop_display_times = 0;
							ret_action = ITEM_NEXT;
						}
					}
					else
					{
						ret_action = ITEM_NEXT;// the item is no ready for display ,then goto next item
					}	
				}
				else
				{
					//error();
					ret_action = ITEM_NEXT;
				}				
			break;
		case ITEM_RDS_ALT_FREQ:
				ret = UpdateDataServiceData();
				if(ret == SUCCESS)
				{
					LCD_Clear(LCD_CLEAR_LINE2);
					LCD_DisplayStr("AF:\n",0,1);
					if(rds_update_ready_item&UPDATED_RDS_ALT_FREQ_ITEM)//check the item whether it is ready for display
					{					
						loop_display_times ++;
						if(loop_display_times>ITEM_RDS_ALT_FREQ_LOOP_TIMES)
						{
							loop_display_times = 0;
							ret_action = ITEM_NEXT;
						}
					}
					else
					{
						ret_action = ITEM_NEXT;// the item is no ready for display ,then goto next item
					}	
				}
				else
				{
					//error();
					ret_action = ITEM_NEXT;
				}		
			break;
#endif //OPTION__INCLUDE_MODE__FM

#ifdef OPTION__INCLUDE_MODE__FMHD
		case ITEM_SIS_SLOGAN:
				ret = UpdateDataServiceData();
				if(ret ==  SUCCESS)
				{
					LCD_Clear(LCD_CLEAR_LINE2);
					LCD_DisplayStr("SL:\n",0,1);
					if(sis_update_ready_item&UPDATED_SIS_SLOGAN_ITEM)//check the item whether it is ready for display
					{
						display_item_str_4ms = CHAR_ROLL_SPEED;
						if(str_to_lcd_buf(temp_str,13,SISGetSloganPtr()->SLGN_TEXT,loop_display_times,FMHD_SIS_SLOGAN_BUFFER_SIZE,0))
						{
							display_item_str_4ms = CHAR_HOLD_TIME;
							loop_display_times = 0;
							ret_action = ITEM_NEXT;
                            //return ret_action;
						}
						else
						{
							loop_display_times++;
						}
						LCD_DisplayStr(temp_str,3,1);
					}
					else
					{
						ret_action = ITEM_NEXT;// the item is no ready for display ,then goto next item
					}
				}
				else
				{
					//error();
					ret_action = ITEM_NEXT;
				}			
			break;
		case ITEM_SIS_UNIVERSAL_SHORT_NAME:
				ret = UpdateDataServiceData();
				if(ret ==  SUCCESS)
				{
					LCD_Clear(LCD_CLEAR_LINE2);
					LCD_DisplayStr("USN:\n",0,1);
					if(sis_update_ready_item&UPDATED_SIS_UNIVERSAL_SHORT_NAME_ITEM)//check the item whether it is ready for display
					{
						display_item_str_4ms = CHAR_ROLL_SPEED;
						if(str_to_lcd_buf(temp_str,12,SISGetUSNPtr()->USN_TEXT,loop_display_times,FMHD_SIS_UNIVERSAL_SHORT_NAME_BUFFER_SIZE,0))
						{
							display_item_str_4ms = CHAR_HOLD_TIME;
							loop_display_times = 0;
							ret_action = ITEM_NEXT;
                           // return ret_action;
						}
						else
						{
							loop_display_times++;
						}
						LCD_DisplayStr(temp_str,4,1);
					}
					else
					{
						loop_display_times = 0;
						ret_action = ITEM_NEXT;// the item is no ready for display ,then goto next item
					}
				}
				else
				{
					//error();
					ret_action = ITEM_NEXT;
				}									
			break;
		case ITEM_SIS_STATION_MESSAGE:
				ret = UpdateDataServiceData();
				if(ret ==  SUCCESS)
				{
					LCD_Clear(LCD_CLEAR_LINE2);
					LCD_DisplayStr("SM:\n",0,1);
					if(sis_update_ready_item&UPDATED_SIS_STATION_MESSAGE_ITEM)//check the item whether it is ready for display
					{
						display_item_str_4ms = CHAR_ROLL_SPEED;
						if(str_to_lcd_buf(temp_str,13,SISGetSMPtr()->SM_TEXT,loop_display_times,FMHD_SIS_STATION_MESSAGE_BUFFER_SIZE,0))
						{
							display_item_str_4ms = CHAR_HOLD_TIME;
							loop_display_times = 0;
							ret_action = ITEM_NEXT;
                            //return ret_action;
						}
						else
						{
							loop_display_times++;
						}
						LCD_DisplayStr(temp_str,3,1);
					}
					else
					{
						loop_display_times = 0;
						ret_action = ITEM_NEXT;// the item is no ready for display ,then goto next item
					}
				}
				else
				{
					//error();
					ret_action = ITEM_NEXT;
				}		
			break;
		case ITEM_SIS_STATION_NAME_LONG:
				ret = UpdateDataServiceData();
				if(ret ==  SUCCESS)
				{
					LCD_Clear(LCD_CLEAR_LINE2);
					LCD_DisplayStr("SNL:\n",0,1);
					if(sis_update_ready_item&UPDATED_SIS_STATION_NAME_LONG_ITEM)//check the item whether it is ready for display
					{
						display_item_str_4ms = CHAR_ROLL_SPEED;
						if(str_to_lcd_buf(temp_str,12,SISGetSNLPtr(),loop_display_times,FMHD_SIS_STATION_NAME_LONG_BUFFER_SIZE,0))
						{
							display_item_str_4ms = CHAR_HOLD_TIME;
							loop_display_times = 0;
							ret_action = ITEM_NEXT;
                            //return ret_action;
						}
						else
						{
							loop_display_times++;
						}
						LCD_DisplayStr(temp_str,4,1);

					}
					else
					{
						ret_action = ITEM_NEXT;// the item is no ready for display ,then goto next item
					}
				}
				else
				{
					//error();
					ret_action = ITEM_NEXT;
				}
			break;
		case ITEM_SIS_STATION_NAME_SHORT:
				ret = UpdateDataServiceData();
				if(ret ==  SUCCESS)
				{
					LCD_Clear(LCD_CLEAR_LINE2);
					LCD_DisplayStr("SNS:\n",0,1);
					if(sis_update_ready_item&UPDATED_SIS_STATION_NAME_SHORT_ITEM)//check the item whether it is ready for display
					{
						display_item_str_4ms = CHAR_ROLL_SPEED;
						if(str_to_lcd_buf(temp_str,12,SISGetSNSPtr(),loop_display_times,FMHD_SIS_STATION_NAME_SHORT_BUFFER_SIZE,0))
						{
							display_item_str_4ms = CHAR_HOLD_TIME;
							loop_display_times = 0;
							ret_action = ITEM_NEXT;
						}
						else
						{
							loop_display_times++;
						}
						LCD_DisplayStr(temp_str,4,1);
					}
					else
					{
						ret_action = ITEM_NEXT;// the item is no ready for display ,then goto next item
					}
				}
				else
				{
					//error();
					ret_action = ITEM_NEXT;
				}
			break;
		case ITEM_SIS_STATION_ID:
				ret = UpdateDataServiceData();
				if(ret ==  SUCCESS)
				{
					LCD_Clear(LCD_CLEAR_LINE2);
					LCD_DisplayStr("ID:\n",0,1);
					if(sis_update_ready_item&UPDATED_SIS_STATION_ID_ITEM)//check the item whether it is ready for display
					{
						dec_to_hex_str((u32)SISGetStationIDPtr(),temp_str+2,1);
						temp_str[0] ='0';
						temp_str[1] ='x';
						LCD_DisplayStr(temp_str,4,1);
						loop_display_times++;
						if(loop_display_times>ITEM_SIS_STATION_ID_TIMES)
						{
							loop_display_times = 0;
							ret_action = ITEM_NEXT;;
						}
					}
					else
					{
						ret_action = ITEM_NEXT;// the item is no ready for display ,then goto next item
					}
				}
				else
				{
					//error();
					ret_action = ITEM_NEXT;
				}
			break;
		case ITEM_SIS_LOC_LAT:
				ret = UpdateDataServiceData();
				if(ret ==  SUCCESS)
				{
					LCD_Clear(LCD_CLEAR_LINE2);
					LCD_DisplayStr("LLAT:\n",0,1);
					if(sis_update_ready_item&UPDATED_SIS_LOC_LAT_ITEM)//check the item whether it is ready for display
					{

						dec_to_hex_str((u32)SISGetStationLocLatPtr(),temp_str+2,1);
						temp_str[0] ='0';
						temp_str[1] ='x';
						LCD_DisplayStr(temp_str,6,1);
						loop_display_times++;
						if(loop_display_times>ITEM_SIS_LOC_LAT_TIMES)
						{
							loop_display_times = 0;
							ret_action = ITEM_NEXT;;
						}
					}
					else
					{
						ret_action = ITEM_NEXT;// the item is no ready for display ,then goto next item
					}
				}
				else
				{
					//error();
					ret_action = ITEM_NEXT;
				}
			break;
		case ITEM_SIS_LOC_LON:
				ret = UpdateDataServiceData();
				if(ret ==  SUCCESS)
				{
					LCD_Clear(LCD_CLEAR_LINE2);
					LCD_DisplayStr("LLON:\n",0,1);
					if(sis_update_ready_item&UPDATED_SIS_LOC_LON_ITEM)//check the item whether it is ready for display
					{
						dec_to_hex_str((u32)SISGetStationLocLongPtr(),temp_str+2,1);
						temp_str[0] ='0';
						temp_str[1] ='x';
						LCD_DisplayStr(temp_str,6,1);
						loop_display_times++;
						if(loop_display_times>ITEM_SIS_LOC_LON_TIMES)
						{
							loop_display_times = 0;
							ret_action = ITEM_NEXT;;
						}
					}
					else
					{
						ret_action = ITEM_NEXT;// the item is no ready for display ,then goto next item
					}
				}
				else
				{
					//error();
					ret_action = ITEM_NEXT;
				}
			break;

		case ITEM_PSD_TITLE:
				ret = UpdateDataServiceData();
				if(ret ==  SUCCESS)
				{
					LCD_Clear(LCD_CLEAR_LINE2);
					LCD_DisplayStr("Ttl:\n",0,1);
					if(psd_update_ready_item&UPDATED_PSD_TITLE_ITEM)//check the item whether it is ready for display
					{
						display_item_str_4ms = CHAR_ROLL_SPEED;
						if(str_to_lcd_buf(temp_str,12,PSDGetTitlePtr()->DATA,loop_display_times,PSDGetTitlePtr()->LENGTH,0))
						{
							display_item_str_4ms = CHAR_HOLD_TIME;
							loop_display_times = 0;
							ret_action = ITEM_NEXT;
                            //return ret_action;
						}
						else
						{
							loop_display_times++;
						}
						LCD_DisplayStr(temp_str,4,1);
					}
					else
					{
						ret_action = ITEM_NEXT;// the item is no ready for display ,then goto next item
					}
				}
				else
				{
					//error();
					ret_action = ITEM_NEXT;
				}
			break;
		case ITEM_PSD_ARTIST:
				ret = UpdateDataServiceData();
				if(ret ==  SUCCESS)
				{
					LCD_Clear(LCD_CLEAR_LINE2);
					LCD_DisplayStr("Art:\n",0,1);
					if(psd_update_ready_item&UPDATED_PSD_ARTIST_ITEM)//check the item whether it is ready for display
					{
						display_item_str_4ms = CHAR_ROLL_SPEED;
						if(str_to_lcd_buf(temp_str,12,PSDGetArtistPtr()->DATA,loop_display_times,PSDGetArtistPtr()->LENGTH,0))
						{
							display_item_str_4ms = CHAR_HOLD_TIME;
							loop_display_times = 0;
							ret_action = ITEM_NEXT;
                            //return ret_action;
						}
						else
						{
							loop_display_times++;
						}
						LCD_DisplayStr(temp_str,4,1);
					}
					else
					{
						ret_action = ITEM_NEXT;// the item is no ready for display ,then goto next item
					}
				}
				else
				{
					//error();
					ret_action = ITEM_NEXT;
				}
			break;
		case ITEM_PSD_ALBUM:
				ret = UpdateDataServiceData();
				if(ret ==  SUCCESS)
				{
					LCD_Clear(LCD_CLEAR_LINE2);
					LCD_DisplayStr("Alb:\n",0,1);
					if(psd_update_ready_item&UPDATED_PSD_ALBUM_ITEM)//check the item whether it is ready for display
					{
						display_item_str_4ms = CHAR_ROLL_SPEED;
						if(str_to_lcd_buf(temp_str,12,PSDGetAlbumPtr()->DATA,loop_display_times,PSDGetAlbumPtr()->LENGTH,0))
						{
							display_item_str_4ms = CHAR_HOLD_TIME;
							loop_display_times = 0;
							ret_action = ITEM_NEXT;
                            //return ret_action;
						}
						else
						{
							loop_display_times++;
						}
						LCD_DisplayStr(temp_str,4,1);
					}
					else
					{
						ret_action = ITEM_NEXT;// the item is no ready for display ,then goto next item
					}
				}
				else
				{
					//error();
					ret_action = ITEM_NEXT;
				}
			break;
		case ITEM_PSD_GENRE:
				ret = UpdateDataServiceData();
				if(ret ==  SUCCESS)
				{
					LCD_Clear(LCD_CLEAR_LINE2);
					LCD_DisplayStr("Gen:\n",0,1);
					if(psd_update_ready_item&UPDATED_PSD_GENRE_ITEM)//check the item whether it is ready for display
					{
						display_item_str_4ms = CHAR_ROLL_SPEED;
						if(str_to_lcd_buf(temp_str,12,PSDGetGenrePtr()->DATA,loop_display_times,PSDGetGenrePtr()->LENGTH,0))
						{
							display_item_str_4ms = CHAR_HOLD_TIME;
							loop_display_times = 0;
							ret_action = ITEM_NEXT;
                            //return ret_action;
						}
						else
						{
							loop_display_times++;
						}
						LCD_DisplayStr(temp_str,4,1);
					}
					else
					{
						ret_action = ITEM_NEXT;// the item is no ready for display ,then goto next item
					}
				}
				else
				{
					//error();
					ret_action = ITEM_NEXT;
				}
				break;
		case ITEM_ALERT_HD:
			ret = UpdateDataServiceData();
			if(ret == SUCCESS)
			{
				LCD_Clear(LCD_CLEAR_LINE2);
				LCD_DisplayStr("Alt:\n",0,1);
				if(alert_update_ready_item&UPDATED_ALERT_ITEM)//check the item whether it is ready for display
				{
						display_item_str_4ms = CHAR_ROLL_SPEED;
						decode_str(str,&str_len,HDAlertGetPtr()->DATA,HDAlertGetPtr()->LENGTH,HDAlertGetPtr()->ENCODING);
						if(str_to_lcd_buf(temp_str,12,str,loop_display_times,str_len,'\n'))
						{
							display_item_str_4ms = CHAR_HOLD_TIME;
							loop_display_times = 0;
							ret_action = ITEM_NEXT;
						}
						else
						{
							loop_display_times++;
						}
						LCD_DisplayStr(temp_str,4,1);
				}
				else
				{
					ret_action = ITEM_NEXT;// the item is no ready for display ,then goto next item
				}
			}
			else
			{
				//error();
				ret_action = ITEM_NEXT;
			}
			break;
#endif //OPTION__INCLUDE_MODE__FMHD

#ifdef OPTION__INCLUDE_MODE__DAB
    #ifdef OPTION__DECODE_DLS
		case ITEM_DLS_STRING:
               ret = UpdateMetrics();
               display_refresh_flag = 1;
				ret =UpdateDataServiceData();
				if(ret == SUCCESS)
				{
					LCD_Clear(LCD_CLEAR_LINE2);
					LCD_DisplayStr("Dls:\n",0,1);
					if(dls_update_ready_item&UPDATED_DLS_STRING_ITEM)
					{
						display_item_str_4ms = CHAR_ROLL_SPEED;

						//LCD_DisplayNum(DLSGetPtr()->ENCODING,12,0);
						decode_str(str,&str_len,DLSGetPtr()->DATA,DLSGetPtr()->LENGTH,DLSGetPtr()->ENCODING);
						//if(str_to_lcd_buf(temp_str,12,str,loop_display_times,str_len,'\n'))
						if(str_to_lcd_buf(temp_str,12,str,loop_display_times,str_len,'\n'))
						{
							display_item_str_4ms = CHAR_HOLD_TIME;
							loop_display_times = 0;
							ret_action = ITEM_NEXT;
                            //return ret_action;
						}
						else
						{
							loop_display_times++;
						}
						LCD_DisplayStr(temp_str,4,1);
					}
					else
					{
						ret_action = ITEM_NEXT;// the item is no ready for display ,then goto next item
					}
				}
				else
				{
					ret_action = ITEM_NEXT;
				}						
			break;
    #endif //OPTION__DECODE_DLS
#endif //OPTION__INCLUDE_MODE__DAB


#ifdef OPTION__RADIODNS
	    case ITEM_RADIODNS_STRING:
            #ifdef OPTION__INCLUDE_MODE__DAB
            if(work_mode == dab)
            {
                dnsStringOffset = 0;
                ret = UpdateRadioDNS_DAB(&dns_dab);
                if(ret == SUCCESS)
                {
                    dec_to_hex_str((u32)dns_dab.SCIDS,&radio_dns_str[dnsStringOffset++],1);
                    radio_dns_str[dnsStringOffset++] = '.';

                    dec_to_hex_str((u32)dns_dab.SID,&radio_dns_str[dnsStringOffset],1);
                    if((dns_dab.SID & 0xFFFF0000) == 0)
                    {
                        dnsStringOffset += 4;
                        radio_dns_str[dnsStringOffset++] = '.';
                    }
                    else
                    {
                        dnsStringOffset += 8;
                        radio_dns_str[dnsStringOffset++] = '.';
                    }
                    
                    dec_to_hex_str((u32)dns_dab.EID,&radio_dns_str[dnsStringOffset],1);
                    dnsStringOffset += 4;
                    radio_dns_str[dnsStringOffset++] = '.';

                    dec_to_hex_str((u32)dns_dab.GCC,&radio_dns_str[dnsStringOffset],1);
                    dnsStringOffset += 3;
                    
                    CpyMemory(&radio_dns_str[dnsStringOffset], dabStringEnd,dabRadioDNSEndLength);
                    dnsStringOffset += dabRadioDNSEndLength;
                }
            }
            #endif

            #ifdef OPTION__INCLUDE_MODE__FM
            if(work_mode == fmonly || work_mode == fmhd)
            {
                dnsStringOffset = 0;
                ret = UpdateRadioDNS_FMRDS(&dns_fm);

                if(ret == SUCCESS)
                {
                    if(dns_fm.FREQUENCY_10KHZ < 10000)
                    {
                        dec_to_hex_str((u32)0,&radio_dns_str[dnsStringOffset++],0);
                        dec_to_hex_str((u32)dns_fm.FREQUENCY_10KHZ,&radio_dns_str[dnsStringOffset],0);
                        dnsStringOffset += 4;
                    }
                    else
                    {
                        dec_to_hex_str((u32)dns_fm.FREQUENCY_10KHZ,&radio_dns_str[dnsStringOffset],0);
                        dnsStringOffset += 5;
                    }
                    radio_dns_str[dnsStringOffset++] = '.';

                    dec_to_hex_str((u32)dns_fm.PI,&radio_dns_str[dnsStringOffset],1);
                    dnsStringOffset += 4;
                    radio_dns_str[dnsStringOffset++] = '.';

                    dec_to_hex_str((u32)dns_fm.GCC,&radio_dns_str[dnsStringOffset],1);
                    dnsStringOffset += 3;

                    CpyMemory(&radio_dns_str[dnsStringOffset], fmStringEnd,fmRadioDNSEndLength);
                    dnsStringOffset += fmRadioDNSEndLength;
                }
            }
            #endif

			if(ret == SUCCESS)
			{
				LCD_Clear(LCD_CLEAR_LINE2);
				LCD_DisplayStr("DNS:\n",0,1);

				display_item_str_4ms = CHAR_ROLL_SPEED;

				if(str_to_lcd_buf(temp_str,12,radio_dns_str,loop_display_times,dnsStringOffset,'\n'))
				{
					display_item_str_4ms = CHAR_HOLD_TIME;
					loop_display_times = 0;
					ret_action = ITEM_NEXT;
				}
				else
				{
					loop_display_times++;
				}
				LCD_DisplayStr(temp_str,4,1);

			}
			else
			{
				ret_action = ITEM_NEXT;
			}						
		break;
#endif //OPTION__DECODE_DLS

		default:ret_action = ITEM_NEXT;//*state = ITEM_AUTO_ROLL;
			break;
	}
	return ret_action;	
}
#endif //OPTION__INCLUDE_MODE__ANY
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
/******************************************************************************************
auto time correct acorrding to the auto_time_correct_flag which is set in menu option
*******************************************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
const u8 code T_MonthDay[13] = {00,31,28,31,30,31,30,31,31,30,31,30,31};
RETURN_CODE auto_time_correct_func(void)
{
	RETURN_CODE ret = SUCCESS;
#ifdef OPTION__INCLUDE_MODE__FM
    rds_time temp_rds_time;
    u32 mdjConvertTemp; //modifiedJulianDay;
    //u16 n;
	//u8 leap;
	//u8 date;
#endif //OPTION__INCLUDE_MODE__FM
#ifdef OPTION__INCLUDE_MODE__DAB
    dab_time TimeDab;
	u16 temp_y;
	u8 temp_m;
	u8 temp_d;
#endif //OPTION__INCLUDE_MODE__DAB


	char convertedHour;
	if( power_flag ==0) //
	{
		return 0;
	}
	if(auto_time_correct_flag==AUTO_TIME_CORRECT_ENABLE)
	{
		if(work_mode ==fmonly||work_mode == fmhd)
		{
#ifdef OPTION__INCLUDE_MODE__FM
			temp_rds_time = RDSGetCurrentTime();
            if(temp_rds_time.ctDayLow != 0)
            {
                convertedHour = temp_rds_time.ctHour + (temp_rds_time.ctOffset / 2);
                if (convertedHour < 0)
                {
                    convertedHour = 24 + convertedHour;
                }

				time.hour = convertedHour;
				time.min =  temp_rds_time.ctMinute;
				
				//RDS time MJD convertion to Gregorian
				
                mdjConvertTemp = (temp_rds_time.ctDayHigh << 16);
                mdjConvertTemp += temp_rds_time.ctDayLow;



/*
                mdjConvertTemp = mdjConvertTemp + 68569 + 2400000;
                n = (4 * mdjConvertTemp / 146097);
   
                mdjConvertTemp = mdjConvertTemp - ((146097 * n + 3) / 4);
                temp_y = (4000 * (mdjConvertTemp + 1) / 1461001);
    
                mdjConvertTemp = mdjConvertTemp - (1461 * temp_y / 4) + 31;
                temp_m = (80 * mdjConvertTemp / 2447);
    
                temp_d = mdjConvertTemp - (2447 * temp_m / 80);
    
                mdjConvertTemp = (temp_m / 11);
    
                temp_m = (temp_m + 2 - 12 * mdjConvertTemp);
                temp_y = (100 * (n - 49) + temp_y + mdjConvertTemp);


				time.year = temp_y - 1900;
				time.month = temp_m;
				time.day = temp_d;

				time.week = (temp_rds_time.ctDayLow+2)%7+1;
				time.hour = convertedHour;
				time.min =  temp_rds_time.ctMinute;

				*/


/*
	
	if(!(mdjConvertTemp&0x8000))//behind 2008 year
	{
		time.year = 2008;
		time.week = (mdjConvertTemp+2)%7;
		if(!(time.week))
			time.week = 7;
		//caculate the year	
		leap = 1;
		while( mdjConvertTemp >= leap+365)
		{	
			mdjConvertTemp -= (leap+365);
			time.year++;
			if(!(time.year%4)&&(time.year%100)||!(time.year%400))
				leap = 1;
			else
				leap = 0;
		}
	}
	else //before 2008 year
	{
		mdjConvertTemp = (~mdjConvertTemp) + 1;
		
		time.week = (9-mdjConvertTemp%7)%7;
		if(!(time.week))
			time.week = 7;
		leap = 0;
		time.year = 2007;
		while( mdjConvertTemp >= leap+365)
		{	
			mdjConvertTemp -= (leap+365);
			time.year--;
			if(!(time.year%4)&&(time.year%100)||!(time.year%400))
				leap = 1;
			else
				leap = 0;
		}
		mdjConvertTemp = leap+365-mdjConvertTemp;
	}
	//caculate the month
	for(time.month = 1;time.month < 12;time.month++)
	{
		if(time.month == 2)
			date = T_MonthDay[time.month]+leap;
		else
			date = T_MonthDay[time.month];
		if(mdjConvertTemp < date)
			break;
		mdjConvertTemp -= date;
	}
	time.day = mdjConvertTemp+1;

*/

            }
#endif //OPTION__INCLUDE_MODE__FM
		}
		else if(work_mode ==dab)
		{
#ifdef OPTION__INCLUDE_MODE__DAB
            ret = GetCurrentTime_DAB(LOCAL,&TimeDab);
			if(ret==SUCCESS)
			{
				time.year = TimeDab.YEAR-1900;
				time.month = TimeDab.MONTH;
				time.day = TimeDab.DAYS;
				time.hour = TimeDab.HOURS;
				time.min = TimeDab.MINUTES;
				time.sec = TimeDab.SECONDS;
				//get the week day formula
				temp_m = time.month;
				temp_y = time.year;
				temp_d = time.day;
			    if( temp_m == 1 || temp_m == 2 )  
			    {
			        temp_m += 12;
			        if( temp_y> 0 )
			            temp_y--;
			        else
			            temp_y = 4;
			    }
    			time.week = 1+(( temp_d + 2*temp_m + 3*(temp_m+1)/5 + temp_y + temp_y/4 ) %7)+1;//+1 mean the day is 1 to 7
			}
#endif //OPTION__INCLUDE_MODE__DAB
		}
	}
	return ret;
}
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
/******************************************************************************************

*******************************************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
code u8 MONTH_DAY[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
RETURN_CODE time_update(void)
{
	RETURN_CODE ret = SUCCESS;

auto_time_correct_flag=AUTO_TIME_CORRECT_ENABLE;
			auto_time_correct_func();//correct the time and data per minus 


	if(time_sec_flag ==1)
	{
		time_sec_flag = 0;
		time_dot_flag ^=1;

		time_refresh_item |=TIME_DOT_ITEM;
		time.sec++;
		if(time.sec>59)
		{
			auto_time_correct_func();//correct the time and data per minus 
			time.sec = 0;
			time.min++;
			time_refresh_item |=TIME_MIN_ITEM;
			if(time.min>59)
			{
				time.min  = 0;
				time.hour ++;
				time_refresh_item |=TIME_HOUR_ITEM;
				if(time.hour>24)
				{
					time.hour = 0;
					time.day++;
					time.week ++;
					time.week &= 0x07;
					time_refresh_item |=TIME_DAY_ITEM;
					if((time.year%4 ==0 ||(time.year%400 == 0&&time.year %100 ==0))&&time.month == 2)//judge whether the year is leap or not
					{
						if(time.day>MONTH_DAY[time.month]+1)
						{
							time.day = 1;  
							time.month ++;
							time_refresh_item |=TIME_MON_ITEM;
							if(time.month>12)
							{
								time.month = 1;
								time.year ++;
								time_refresh_item |=TIME_YEAR_ITEM;
							}
						}
					}
					else
					{
						if(time.day>MONTH_DAY[time.month])
						{
							time.day = 1;  
							time.month ++;
							time_refresh_item |=TIME_MON_ITEM;
							if(time.month>12)
							{
								time.month = 1;
								time.year ++;
								time_refresh_item |=TIME_YEAR_ITEM;
							}
						}
					}						
				}
			}
		}
		if(wake_up_time>0) wake_up_time--;
	}
	return ret;
}
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
/***********************************************************************************

************************************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
RETURN_CODE key_process(void)
{
	RETURN_CODE ret = SUCCESS;
	if(key_flag)
	{
		key_flag = 0;
		display_refresh_flag = 1;
		switch(key_value)
		{
			case ON_OFF_KEY:
				display_delay_4ms = 0;
				display_delay_en = 0;
				ret |= power_process();
				break;
			case MODE_KEY:
                if(power_flag != 0)
                {
    				display_delay_4ms = 1000;
    				display_delay_en = 1;

    				work_mode_index++;
    				if(work_mode_index > band_size-1)
    				{
    					work_mode_index=0;
    				}
    				work_mode = pband[work_mode_index];
    				if(work_mode != current_work_mode)
    				// if the selected mode equal current mode 
    				//then not need to execute band switch function
    				//power_flag :avoid switch mode before power on the tuner, at this time,need reboot the system
    				{

    					display_mode = BAND_SWITCH_MODE;
    					pfunc = BANDSWITCH;//Initialize;
    				}
    				else
    				{
    					display_mode = BAND_SWITCH_MODE;
    					pfunc = IDLE;
    				}
                }
				break;

			case ALARM_KEY:
                #ifndef OPTION__NO_ALARM_HARDWARE_REMOVE_ALARM_CODE
    				display_delay_4ms = 1000;//4*1000ms = 4s it mean that when user don't press key any more during the 4s
    				display_delay_en = 1;		// then the LCD will go back to display FM/HD.. work mode gui
    				display_mode =ALARM_MODE;
    				LCD_Clear(LCD_CLEAR_ALL);
                #endif //OPTION__NO_ALARM_HARDWARE_REMOVE_ALARM_CODE
				break;
			case CLOCK_KEY:
				display_delay_4ms = 1000;//4*1000ms = 4s it mean that when user don't press key any more during the 4s
				display_delay_en = 1;		// then the LCD will go back to display FM/HD.. work mode gui
				display_mode =CLOCK_MODE;
				time_refresh_item = 0x7F;
				LCD_Clear(LCD_CLEAR_ALL);
				break;
			case MENU_KEY:

				if(!power_flag) return ret;//if on power down mode , MMI will not response to the button

				if(display_mode == MENU_MODE)
				{
					display_delay_4ms = 0;//update the display immediately
					display_delay_en = 1;
					display_mode_update();//EXIT the setting mode
				}
				else
				{
					display_delay_4ms = 1000;//4*1000ms = 4s it mean that when user don't press key any more during the 4s
					display_delay_en = 1;		// then the LCD will go back to display FM/HD.. work mode gui
					display_mode = MENU_MODE;
				}
				break;	
			case VOLUME_PRESS_KNOBS:

				if(!power_flag) return ret;//if on power down mode , MMI will not response to the button

				mute_flag ^=1;
				if(mute_flag)
				{
					ret = AudioMute(MUTE_LEFT_RIGHT);
					//#ifdef PLATFORM_F380_MODULE_V2_0
					//	MUTE = 1;
					//#endif
				}
				else
				{
					ret = AudioMute(NOT_MUTED);	
					//#ifdef PLATFORM_F380_MODULE_V2_0									
					//	MUTE = 0;
					//#endif
				}
				display_delay_4ms = 1000;//4*1000ms = 4s it mean that when user don't press key any more during the 4s
				display_delay_en = 1;		// then the LCD will go back to display FM/HD.. work mode gui	
				display_mode  =MUTE_MODE;	
				break;
			case VOLUME_INC_KNOBS:

				if(!power_flag) return ret;//if on power down mode , MMI will not response to the button

				display_delay_4ms = 1000;
				display_delay_en = 1;
				display_mode  = VOLUME_MODE;
				volume_inc();	
				break;
			case VOLUME_DEC_KNOBS:

				if(!power_flag) return ret;//if on power down mode , MMI will not response to the button

				display_delay_4ms = 1000;
				display_delay_en = 1;
				display_mode  = VOLUME_MODE;
				volume_dec();	
				break;	

			case BACK_LIGHT_KEY:

				 LCD_BL_flag ^=1;

				 if(LCD_BL_flag == 1)
				 {
					 DISP_BKLIGHT = LCD_BL_ON;
				 }
				 else
				 {
				 	DISP_BKLIGHT = LCD_BL_OFF;
				 }			 	
				 break;
            case SNOOZE_KEY:
                
               break;
		default:key_flag = 1;display_refresh_flag = 0;//the key has not been dealed with,set up the flag again
			break;
		}
	}
	return ret;
}
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
/****************************************************************************************

******************************************************************************************/
RETURN_CODE state_update(void)
{
	RETURN_CODE ret = SUCCESS;
//	static work_mode_temp = 0xFF;//if the selected work_mode is same as the pervious, then not need reboot
#ifdef OPTION__INCLUDE_MODE__DAB
    #ifndef OPTION__DAB_PRESETS_AS_FAVORITES
 	    dab_preset_struct xdata dab_pset_temp;
    #endif //#OPTION__DAB_PRESETS_AS_FAVORITES
#endif
	if(display_delay_4ms == TIME_UP)
	{
		switch(pfunc)
		{
			case BANDSWITCH:
					//if((work_mode_temp != work_mode)&&(power_save_flag==0))
					{
                        if(power_save_flag == 0)
                        {   
                            //We are currently switching from one active mode to another - save current state
                            ret = eeprom_save_parameter();
                        }
                        #ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
						current_menu_item = 0;//reset the menu display cursor
						menu_index = 0;
						menu_select_flag = 0;
						#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI

						current_work_mode = work_mode;
						power_flag =1;

						#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
						LCD_Clear(LCD_CLEAR_LINE1);
						LCD_DisplayStr("Booting...\n",0,0);
						#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI   
                     
						ret |= Finalize();	
						switch(work_mode)
						{
							#ifdef OPTION__INCLUDE_MODE__FM
							case fmonly:
									ret |= fm_am_initialize();
									display_mode = FM_MODE;
									display_delay_4ms = 1;
									break;
							#endif //OPTION__INCLUDE_MODE__FM
							#ifdef OPTION__INCLUDE_MODE__AM
							case am:
									ret |= fm_am_initialize();
									display_mode = AM_MODE;
									display_delay_4ms = 1;
									break;
							#endif //OPTION__INCLUDE_MODE__AM
							#ifdef OPTION__INCLUDE_MODE__FMHD
							case fmhd:
									ret |= fmhd_amhd_initialize();
									display_mode = FMHD_MODE;
									display_delay_4ms = 1;
									break;
							#endif //OPTION__INCLUDE_MODE__FMHD

							#ifdef OPTION__INCLUDE_MODE__AMHD
							case amhd:
									ret |= fmhd_amhd_initialize();
									display_mode = AMHD_MODE;
									display_delay_4ms = 1;
									break;
							#endif //OPTION__INCLUDE_MODE__AMHD

							#ifdef OPTION__INCLUDE_MODE__DAB
							case dab:
									ret |= dab_initialize();
									display_mode = DAB_MODE;
									break;
							#endif //OPTION__INCLUDE_MODE__DAB
							//default:work_mode = fmonly;
                            //    break;
						}
					}
					display_refresh_flag = 1;
					display_delay_en =1;
					pfunc =IDLE;
					break;
			#ifdef OPTION__INCLUDE_MODE__FM
			case FM_TUNE:
			 		ret |=Tune(fm_freq);
					display_refresh_flag = 1;
					pfunc =IDLE;
					break;
			#endif //OPTION__INCLUDE_MODE__FM
			#ifdef OPTION__INCLUDE_MODE__FMHD
			case FMHD_TUNE:
					if(SeekTuneCompleteCheck())
					{
						//ret =UpdateMetrics();  // No longer need to update metrics - the frequency is set when tune/tunestep is called.
						if(ret == SUCCESS)
						{
							fmhd_freq = MetricsGetFMHDPtr()->FREQUENCY_10KHZ;
							display_refresh_flag = 1;
							pfunc =IDLE;
						}
					}
					else
					{
						pfunc = FMHD_TUNE;
						display_delay_4ms = 10;
					}
					break;
			#endif //OPTION__INCLUDE_MODE__FMHD
			#ifdef OPTION__INCLUDE_MODE__DAB
			case DAB_MANUAL_TUNE:
			#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
					LCD_Clear(LCD_CLEAR_LINE1);
					LCD_DisplayStr("Tuning...\n",0,0);
			#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
					//initDAB_ServiceList(); // Clear the service list
    				ret = ManualTune_DAB(dab_manual_freq_index); // izt on 2
    				//BrowseServicesStartCurrentSelection_DAB();
				 	pfunc = IDLE;
					break;
			case DAB_UK_FREQ_LIST:
                    if(dab_uk_freq_list_flag != dab_reduced_list_flag)
                    {
    			        #ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
        					LCD_Clear(LCD_CLEAR_LINE1);
        					LCD_DisplayStr("Change freqlist.\n",0,0);
    			        #endif //OPTION__OPERATE_AS_SLAVE_NO_MMI

    					if(dab_uk_freq_list_flag)
    					{
    						ChangeFreqListToLimitedUK();
    					}
    					else
    					{
                            dab_reduced_list_flag = 0;
    						ret |= Initialize(dab);			 	
    					}
                        //We need to dump the current service list and force a rescan because the indexes are now incorrect.
                        DAB_scan();
                    }
					pfunc = IDLE;
					break;
		#ifndef OPTION__DAB_PRESETS_AS_FAVORITES
			case DAB_START_PSET_CHANNEL:
                
					//get current channel info
					dab_pset_temp.freq_index = MetricsGetDABPtr()->FREQUENCY_INDEX;
					GetCurrentServiceIdentification_DAB(&dab_pset_temp.service_id,&dab_pset_temp.component_id);
					//jude current channel is equal to preset channel, if so, then no need tuning again
					if(((dab_pset_temp.freq_index != dab_pset_table[pset_table_index].freq_index)
						||(dab_pset_temp.service_id != dab_pset_table[pset_table_index].service_id)
						||(dab_pset_temp.component_id != dab_pset_table[pset_table_index].component_id))
						&& dab_pset_table[pset_table_index].valid ==1)
					{

                        #ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
    						LCD_Clear(LCD_CLEAR_ALL);
    						LCD_DisplayStr(dab_pset_table[pset_table_index].label_str,0,0);
    						LCD_DisplayStr("Tuning....\n",0,1);
                        #endif // OPTION__OPERATE_AS_SLAVE_NO_MMI

						ManualTune_DAB(dab_pset_table[pset_table_index].freq_index); // izt on 2
						/*
						start_digital_service__command(0,dab_pset_table[pset_table_index].service_id,
														 dab_pset_table[pset_table_index].component_id);
						*/
	                	StartProcessingChannel(SERVICE_TYPE_DAB_AUDIO,
						 						dab_pset_table[pset_table_index].service_id,
												dab_pset_table[pset_table_index].component_id, 0);
					}
					pfunc = IDLE;
					break;
        #endif //OPTION__DAB_PRESETS_AS_FAVORITES
#endif //OPTION__INCLUDE_MODE__DAB

#ifdef OPTION__INCLUDE_MODE__FMHD
			case FMHD_START_PSET_CHANNEL:
					fmhd_freq = fmhd_pset_table[pset_table_index].frequency;
					if(fmhd_freq != MetricsGetFMHDPtr()->FREQUENCY_10KHZ)
					{
						ret |= Tune(fmhd_freq);
					}
					if(fmhd_pset_table[pset_table_index].component_id !=0xFF)
					{
						AudioMute(MUTE_LEFT_RIGHT);	
						//display_item_str_4ms = 1000;//avoid tuner to refresh the LCD
						if(MetricsGetFMHDPtr()->AUDIO_SOURCE == 1)
						{
			                ret |=StartProcessingChannel(SERVICE_TYPE_HD_AUDIO,
								 					0,
													fmhd_pset_table[pset_table_index].component_id, 0);
							if(ret == SUCCESS)
							{
								MetricsGetFMHDPtr()->CURRENT_AUDIO_SERVICE = fmhd_pset_table[pset_table_index].component_id;
							}
							AudioMute(NOT_MUTED);
							//display_refresh_flag = 1;
							pfunc = IDLE;
						}
					}
					else
					{
						pfunc = IDLE;
					}
		 			rds_update_ready_item = 0;
		 			sis_update_ready_item = 0;
		 			psd_update_ready_item = 0;
                    alert_update_ready_item = 0;
					break;
#endif//OPTION__INCLUDE_MODE__FMHD

#ifdef OPTION__INCLUDE_MODE__AMHD
			case AMHD_START_PSET_CHANNEL:
					amhd_freq = amhd_pset_table[pset_table_index].frequency;
					if(amhd_freq != MetricsGetAMHDPtr()->FREQUENCY_1KHZ)
					{
						ret |= Tune(amhd_freq);
					}
					if(amhd_pset_table[pset_table_index].component_id !=0xFF)
					{
						AudioMute(MUTE_LEFT_RIGHT);	
						//display_item_str_4ms = 1000;//avoid tuner to refresh the LCD
						if(MetricsGetAMHDPtr()->AUDIO_SOURCE == 1)
						{
			                ret |=StartProcessingChannel(SERVICE_TYPE_HD_AUDIO,
								 					0,
													amhd_pset_table[pset_table_index].component_id, 0);
							if(ret == SUCCESS)
							{
								MetricsGetAMHDPtr()->CURRENT_AUDIO_SERVICE = amhd_pset_table[pset_table_index].component_id;
							}
							AudioMute(NOT_MUTED);
							//display_refresh_flag = 1;
							pfunc = IDLE;
						}
					}
					else
					{
						pfunc = IDLE;
					}
		 			sis_update_ready_item = 0;
		 			psd_update_ready_item = 0;
                    alert_update_ready_item = 0;
					break;
#endif//OPTION__INCLUDE_MODE__FMHD

#ifdef OPTION__INCLUDE_MODE__FM
			case FM_START_PSET:
					ret |= Tune(fm_freq);
					rds_update_ready_item =0;
					display_refresh_flag = 1;
					pfunc = IDLE;
					break;
			case AM_START_PSET:
					ret |= Tune(am_freq);
					pfunc = IDLE;
					break;
#endif//OPTION__INCLUDE_MODE__FM
			case IDLE:
			default:
					idle();
					break;
		}
	}
	return ret;
}
/****************************************************************************************


******************************************************************************************/

#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
void welcome_gui(void)
{
	if(display_refresh_flag == 1)
	{
		display_refresh_flag = 0;
		LCD_Clear(LCD_CLEAR_ALL);
		LCD_DisplayStr("Welcome To\n",3,0);
		LCD_DisplayStr("Digital Radio\n",1,1);
	}
}
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
/****************************************************************************************

******************************************************************************************/
RETURN_CODE work_mode_process(void)
{
	switch(display_mode)
	{

	#if (defined OPTION__INCLUDE_MODE__FM)||(defined OPTION__INCLUDE_MODE__AM)
		case FM_MODE:
		case AM_MODE:
			fm_am_work_mode();
			break;
	#endif //OPTION__INCLUDE_MODE__FM


	#if (defined OPTION__INCLUDE_MODE__FMHD)||(defined OPTION__INCLUDE_MODE__AMHD)
		case FMHD_MODE:
		case AMHD_MODE:
			fmhd_amhd_work_mode();
			break;
	#endif //OPTION__INCLUDE_MODE__FMHD
	#ifdef OPTION__INCLUDE_MODE__DAB
		case DAB_MODE:
			dab_work_mode();
			break;
	#endif //OPTION__INCLUDE_MODE__DAB

	#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
			case BAND_SWITCH_MODE:
				band_switch_mode();
				break;
			case CLOCK_MODE:
				clock_work_mode();
				break;
			#ifndef NO_ALARM_HARDWARE_REMOVE_ALARM_CODE
			case ALARM_MODE:
				alarm_work_mode();
				break;
			case ALARM_TIMEUP_MODE:
				alarm_time_up_mode();
				break;
			#endif //NO_ALARM_HARDWARE_REMOVE_ALARM_CODE
			case MENU_MODE:
				menu_work_mode();
				break;
			case VOLUME_MODE:
				volume_work_mode();
                display_entered_volume_work_mode = 1;
				break;
			case MUTE_MODE:
				audio_mute();
				break;
			case MAIN_MODE:
				welcome_gui();
				break;
	#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
			case IDLE_MODE:
				idle_mode();
				break;


		default:
            return SUCCESS;
            break;
	}

    if((display_entered_volume_work_mode == 1) && (display_mode != VOLUME_MODE))
    {
        display_entered_volume_work_mode = 0;
        eeprom_save_parameter();
    }

	return SUCCESS;
}
/*********************************************************************************************
detect key action ,if there are key action need to be deal with, then change mode immediate
just for volume control ,mute menu alarm clock function
***********************************************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
RETURN_CODE detece_key(void)
{
	RETURN_CODE ret = SUCCESS;
	if(key_flag && power_flag)//if there are a key process need to deal, then change the mode immediately
	{
		LCD_Clear(LCD_CLEAR_ALL);
		display_delay_4ms = 0;
		display_delay_en  = 1;
		display_mode_update();
	}
	return ret;
}
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
/****************************************************************************************
return to main interface
******************************************************************************************/
RETURN_CODE display_mode_update(void)
{
	RETURN_CODE ret = SUCCESS;
	if(display_delay_4ms==TIME_UP && display_delay_en == 1)
	{
		display_delay_en = 0;
		display_refresh_flag = 1;
		if(power_flag)
		{
			switch(work_mode)
			{
					case fmonly:
						display_mode = FM_MODE;
						break;
					case fmhd:
						display_mode = FMHD_MODE;
						break;
					case am:
						display_mode = AM_MODE;
						break;
					case amhd:
						display_mode = AMHD_MODE;
						break;
					case dab:
						display_mode = DAB_MODE;
						break;
				default:display_refresh_flag = 0;
					break;
			}
		}
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
		else
		{
			LCD_Clear(LCD_CLEAR_ALL);
			display_mode = CLOCK_MODE;
			time_refresh_item = 0x7F;
		}
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
	}	
	return ret;
}

//FMHD = 27824
//SDK == 55986-27824 == 28162
//SDK == 59652 - 26591 = 33K