/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   MMI: non-radio mode
   FILE: mode_other.c
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#include "compiler_defs.h"
#include "typedefs.h"

#include <platform_options.h>

#ifdef PLATFORM_F380_MODULE
	#include "C8051F380_defs.h"
#endif
#ifdef PLATFORM_F340_DEMOBOARD
	#include "C8051F340_defs.h"
#endif

#include "usb_main.h"
#include "Firmware_API_Manager.h"
#include "si46xx_firmware_api.h"
#include "mode_other.h"
#include "main.h"
#include "mode_common.h"
#include "key.h"
#include "LCD.h"
#include "sys.h"
#include "mode_dab.h"
#include "delay.h"
#include "si46xx_firmware_api_constants.h"

#include "usb_descriptor.h"
#include "usb_register.h"

/****************************************************************************************
01 00 17 28 00 f8 24 01 21 10 00 00 00 18 00 00
silabs
******************************************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
RETURN_CODE clock_initialize(void)
{
	RETURN_CODE ret = SUCCESS;
	time_count = 0;
	time_refresh_item = 0x7F;
	time_sec_flag = 1;
	time_dot_flag = 1;
	time.sec = 1;
	time.min = 30;
	time.hour = 12 ;
	time.day = 1;
	time.week= 4;
	time.month=9;
	time.year = 112;//1900+112=2012
	
	select_item = 0;

	return ret;
}
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI	
/****************************************************************************************

******************************************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
code u8 MONTH_DAY1[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
code u8 WEEK_STR[8][4]={"Err\n","Mon\n","Tue\n","Wed\n","Thu\n","Fri\n","Sat\n","Sun\n"};
code u8 SELECT_ITEM_BIT[7]={0,TIME_YEAR_ITEM,TIME_MON_ITEM,TIME_DAY_ITEM,TIME_WEEK_ITEM,TIME_HOUR_ITEM,TIME_MIN_ITEM};
#define TIME_VALUE_MODIFY_TIME   5000
RETURN_CODE clock_work_mode(void)
{
	RETURN_CODE ret = SUCCESS;
	/*
	if(display_refresh_flag == 1)
	{
		display_refresh_flag = 0;
		LCD_Clear(LCD_CLEAR_ALL);
	}
	*/
	time_value_update(&time,CLOCK_MODE);
	return ret;
}
#endif // OPTION__OPERATE_AS_SLAVE_NO_MMI
/****************************************************************************************

******************************************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
#ifndef NO_ALARM_HARDWARE_REMOVE_ALARM_CODE
RETURN_CODE alarm_work_mode(void)
{
	RETURN_CODE ret = SUCCESS;
	if(display_refresh_flag)
	{
		display_refresh_flag = 0;
		if(alarm_flag == 0 && alarm_time_up ==0 )
		{
			LCD_Clear(LCD_CLEAR_ALL);
			LCD_DisplayStr("No alarm set\n",0,0);
			time_refresh_item = 0;
			display_delay_4ms  = 2000;
		}
		else if(alarm_time_up == 1)
		{
			alarm_flag = 0;
			alarm_time_up = 0;	
			Timer3_Init_lowpower();
			display_delay_4ms  = 2000;
			time_refresh_item = 0;
			LCD_Clear(LCD_CLEAR_ALL);
			LCD_DisplayStr("alarm Cancel\n",2,0);
		}
		else
		{
			LCD_Clear(LCD_CLEAR_LINE1);
			time_refresh_item = 0x7f;
		}
	}
//	alarm_time.min = 38;
	time_value_update(&alarm_time,ALARM_MODE);
	return ret;
}
#endif //NO_ALARM_HARDWARE_REMOVE_ALARM_CODE
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
/***************************************************************************************************************

*****************************************************************************************************************/
void time_value_update(time_struct *time_temp,u8 work_mode)
{
#ifdef OPTION__TIME_SETTING
	if(key_flag)
	{
		key_flag = 0;
		switch(key_value)
		{
			case UP_KEY:
						if(select_item > 0)
						{
							*pselect_item_value +=1;
							if(*pselect_item_value >select_item_max_scale)
							{
								*pselect_item_value = select_item_min_scale;
							}
							select_item_flash_delay = 700;
							time_refresh_item |= SELECT_ITEM_BIT[select_item];
						}
						display_delay_4ms  = TIME_VALUE_MODIFY_TIME;
				break;
			case DOWN_KEY:
						if(select_item >0)
						{
							if(*pselect_item_value == select_item_min_scale)
							{
								*pselect_item_value = select_item_max_scale;
							}
							else
							{
								*pselect_item_value -=1;
							}
							select_item_flash_delay = 700;
							time_refresh_item |= SELECT_ITEM_BIT[select_item];
						}
						display_delay_4ms  = TIME_VALUE_MODIFY_TIME;
				break;
			case SELECT_KEY://comfirm and move to next item
						if(work_mode == ALARM_MODE)
						{
							alarm_flag = 1;
						}
						display_delay_4ms  = TIME_VALUE_MODIFY_TIME;
						select_item_flash_delay = 0;
						select_item++;
						display_refresh_flag = 1;
						time_refresh_item = 0x7F;
						switch(select_item)
						{
							case SELECT_WEEK_ITEM:
									pselect_item_value = &((*time_temp).week);
									select_item_min_scale = 1;
									select_item_max_scale = 6;
								break;
							case SELECT_MIN_ITEM:
									pselect_item_value = &((*time_temp).min);
									select_item_min_scale = 1;
									select_item_max_scale = 59;
								break;
							case SELECT_HOUR_ITEM:
									pselect_item_value = &((*time_temp).hour);
									select_item_min_scale = 0;
									select_item_max_scale = 24;
								break;																
							case SELECT_MON_ITEM:
									pselect_item_value = &((*time_temp).month);
									select_item_min_scale = 1;
									select_item_max_scale = 12;
								break;
							case SELECT_DAY_ITEM:
									pselect_item_value = &((*time_temp).day);
									select_item_min_scale = 1;
									select_item_max_scale = MONTH_DAY1[(*time_temp).month];
								break;
							case SELECT_YEAR_ITEM:
									pselect_item_value = &((*time_temp).year);
									select_item_min_scale = 0;
									select_item_max_scale = 255;
								break;
							default:select_item = 0;(*time_temp).sec = 0;display_delay_4ms  = 1000;break;
						}
				break;
			default:key_flag = 1;break;
		}
	}

	if(select_item >0&&select_item_flash_delay ==0)
	{
		if(time_dot_flag)
		{
			switch(select_item)
			{
				case SELECT_MIN_ITEM:
						LCD_DisplayStr("  \n",TIME_MIN_X,TIME_MIN_Y);
					break;
				case SELECT_HOUR_ITEM:
						LCD_DisplayStr("  \n",TIME_HOUR_X,TIME_HOUR_Y);
					break;																
				case SELECT_MON_ITEM:
						LCD_DisplayStr("  \n",TIME_MON_X,TIME_MON_Y);
					break;
				case SELECT_DAY_ITEM:
						LCD_DisplayStr("  \n",TIME_DAY_X,TIME_DAY_Y);
					break;
				case SELECT_WEEK_ITEM:
						LCD_DisplayStr("   \n",TIME_WEEK_X,TIME_WEEK_Y);
					break;
				case SELECT_YEAR_ITEM:
						LCD_DisplayStr("    \n",TIME_YEAR_X,TIME_YEAR_Y);
					break;
				default:select_item = 0;break;
			}			
		}
		else
		{
			switch(select_item)
			{
				case SELECT_MIN_ITEM:
					if((*time_temp).min<10){
						LCD_DisplayNum(0,TIME_MIN_X,TIME_MIN_Y);
						LCD_DisplayNum((*time_temp).min,TIME_MIN_X+1,TIME_MIN_Y);
					}else{
						LCD_DisplayNum((*time_temp).min,TIME_MIN_X,TIME_MIN_Y);
					}	
					break;
				case SELECT_HOUR_ITEM:
					if((*time_temp).hour<10){
						LCD_DisplayNum(0,TIME_HOUR_X,TIME_HOUR_Y);
						LCD_DisplayNum((*time_temp).hour,TIME_HOUR_X+1,TIME_HOUR_Y);
					}else{
						LCD_DisplayNum((*time_temp).hour,TIME_HOUR_X,TIME_HOUR_Y);
					}
					break;																
				case SELECT_MON_ITEM:
					if((*time_temp).month<10){
						LCD_DisplayNum(0,TIME_MON_X,TIME_MON_Y);
						LCD_DisplayNum((*time_temp).month,TIME_MON_X+1,TIME_MON_Y);
					}else{
						LCD_DisplayNum((*time_temp).month,TIME_MON_X,TIME_MON_Y);
					}
					break;
				case SELECT_DAY_ITEM:
					if((*time_temp).day<10){
						LCD_DisplayNum(0,TIME_DAY_X,TIME_DAY_Y);
						LCD_DisplayNum((*time_temp).day,TIME_DAY_X+1,TIME_DAY_Y);
					}else{
						LCD_DisplayNum((*time_temp).day,TIME_DAY_X,TIME_DAY_Y);
					}
					break;
				case SELECT_WEEK_ITEM:
					LCD_DisplayStr(WEEK_STR[(*time_temp).week],TIME_WEEK_X,TIME_WEEK_Y);
					break;
				case SELECT_YEAR_ITEM:
					LCD_DisplayNum((*time_temp).year+1900,TIME_YEAR_X,TIME_YEAR_Y);
					break;
				default:select_item = 0;break;
			}
			if(display_delay_4ms == 0)
			{
				select_item = 0;//time changing is time up, go back to exsit adjusting state
			}
		}

	}
#endif
	if(time_refresh_item !=0)
	{
		if(time_refresh_item == 0x7f)
		{
			LCD_DisplayStr("-\n",TIME_YEAR_X+4,TIME_YEAR_Y);
			LCD_DisplayStr("-\n",TIME_MON_X+2,TIME_MON_Y);
		}			
		if(time_refresh_item & TIME_DOT_ITEM )
		{
			time_refresh_item &=~TIME_DOT_ITEM;
			if(work_mode == CLOCK_MODE)
			{
				//if(time_dot_flag || display_delay_4ms >0){ // under adjusting state ,the dot is not flash 
				if(time_dot_flag || select_item!=0){ 
					LCD_DisplayStr(":\n",TIME_DOT_X,TIME_DOT_Y);
				}else{
					LCD_DisplayStr(" \n",TIME_DOT_X,TIME_DOT_Y);
				}
			}
			else
			{
				if(alarm_flag||alarm_time_up)LCD_DisplayStr(":\n",TIME_DOT_X,TIME_DOT_Y);//alway display the do
			}
		}
		if(time_refresh_item & TIME_MIN_ITEM )
		{
			time_refresh_item &=~TIME_MIN_ITEM;
			if((*time_temp).min<10){
				LCD_DisplayNum(0,TIME_MIN_X,TIME_MIN_Y);
				LCD_DisplayNum((*time_temp).min,TIME_MIN_X+1,TIME_MIN_Y);
			}else{
				LCD_DisplayNum((*time_temp).min,TIME_MIN_X,TIME_MIN_Y);
			}			
		}
		if(time_refresh_item & TIME_HOUR_ITEM )
		{
			time_refresh_item &=~TIME_HOUR_ITEM;
			if((*time_temp).hour<10){
				LCD_DisplayNum(0,TIME_HOUR_X,TIME_HOUR_Y);
				LCD_DisplayNum((*time_temp).hour,TIME_HOUR_X+1,TIME_HOUR_Y);
			}else{
				LCD_DisplayNum((*time_temp).hour,TIME_HOUR_X,TIME_HOUR_Y);
			}			
		}
		if(time_refresh_item & TIME_DAY_ITEM )
		{
			time_refresh_item &=~TIME_DAY_ITEM;
			if((*time_temp).day<10){
				LCD_DisplayNum(0,TIME_DAY_X,TIME_DAY_Y);
				LCD_DisplayNum((*time_temp).day,TIME_DAY_X+1,TIME_DAY_Y);
			}else{
				LCD_DisplayNum((*time_temp).day,TIME_DAY_X,TIME_DAY_Y);
			}
		}
		if(time_refresh_item&TIME_WEEK_ITEM)
		{
			time_refresh_item &=~TIME_WEEK_ITEM;
        #ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
			LCD_DisplayStr(WEEK_STR[(*time_temp).week],TIME_WEEK_X,TIME_WEEK_Y);					
        #endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
		}
		if(time_refresh_item & TIME_MON_ITEM )
		{
			time_refresh_item &=~TIME_MON_ITEM;
			if((*time_temp).month<10){
				LCD_DisplayNum(0,TIME_MON_X,TIME_MON_Y);
				LCD_DisplayNum((*time_temp).month,TIME_MON_X+1,TIME_MON_Y);
			}else{
				LCD_DisplayNum((*time_temp).month,TIME_MON_X,TIME_MON_Y);
			}			
		}
		if(time_refresh_item & TIME_YEAR_ITEM )
		{
			time_refresh_item &=~TIME_YEAR_ITEM;

			LCD_DisplayNum((*time_temp).year+1900,TIME_YEAR_X,TIME_YEAR_Y);
		}
		time_refresh_item = 0;
	}
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
	detece_key();
#endif // OPTION__OPERATE_AS_SLAVE_NO_MMI
}

/**************************************************************************************

******************************************************************************************/
#ifdef OPTION__INCLUDE_POWER_SAVING_MODE
void wake_up_init(void)
{
	OSCICN    |= 0x83;//enable internal high frequency/2 as system clock 
	while(!(OSCICN&0x40));
	CLKSEL    = 0x02;//select IHF as system clock

	TR2 = 1;//for knos key 
	TR1 = 1;// UART communication
	TMR3CN &= ~0x04;//disable ADC window detect exciter		

	SYS_ON = 1;
	DISP_BKLIGHT = LCD_BL_ON;
	key_init(); 
	EIE1 |= 0x02;//Enable USB 	
}
#endif
/**************************************************************************************
into idle mode:
the timer5 will wake up the MCU in every 1 sec
   EIE1 |= 0x02;                    // Enable USB0 Interrupts
******************************************************************************************/
void idle_mode(void)
{ 
#ifdef OPTION__INCLUDE_POWER_SAVING_MODE
	u8 clock_init_flag ;
	u8 time_auto_correct_temp;

	clock_init_flag = 0;
	if(power_flag == 0)//under power down mode, if there are no key action 
	{	// then MCU will go into save power mode
		//no key action
		time_auto_correct_temp = auto_time_correct_flag;
		auto_time_correct_flag = 0;
		while(wake_up_time == 0)
		{
			if(clock_init_flag ==0)
			{
				Port_IO_lowpower_Init();

				clock_init_flag = 1;
				//Timer3_Init_lowpower();	
				//ADC_compare_init();

				key_comparator_init();

				DISP_BKLIGHT = LCD_BL_OFF;


				VDM0CN &= ~0x80; 

				SPI0CN &=~0x01;//disable spi communication with SI468X

				TR2 = 0;
				TR1 = 0;//disable UART

				TMR3CN &=~0x04;
				TMR5CN |=0x04;//for RTC timer  count
				TMR4CN &= ~0x04;//disable ADC window detect exciter	

				REG01CN = 0x92;

				ADC0CN &=~0x80;
				//TMR3CN |= 0x04;//enable ADC window detect exciter	

				#ifdef OPTION__USB_DRIVER
					EIE1 &=~0x02;//disable USB 
  					 POLL_WRITE_BYTE(POWER,  0x08);   // Force Asynchronous USB Reset
					 POLL_WRITE_BYTE(POWER,  0x10); 
					 //CLKSEL |= 0x20;//USB clock select external OSC
				#endif

				SYS_ON = 0;
				//IE  = 0;
				CLKSEL    = 0x01;//select external 32.768Khz for system clock 
				OSCICN    &=~0x80;//disable internal high frequency
			}
			
			//go into idle mode;
			PCON |= 0x01; // set IDLE bit
			PCON = PCON; // ... followed by a 3-cycle dummy instruction
			//CPT0CN = 0x9f;
			if(key_flag)
			{
				CPT0CN = 0;
				//CPT0CN &= ~0x30;
				//CPT0CN &= ~0x60;
				//AD0WINT = 0;
				//AD0INT = 0;
				key_flag = 0;
				//key_scan();
				//if(key_value ==ON_OFF_KEY)
				{
					wake_up_time = NO_KEY_WAKUP_TIME;
				}
				if(clock_init_flag)
				{
					clock_init_flag = 0;
					OSCICN    |= 0x83;//enable internal high frequency/2 as system clock 
					while(!(OSCICN&0x40));
					CLKSEL    = 0x02;//select IHF as system clock

					Port_IO_Init();

					TR2 = 1;//for knos key 
					TR1 = 1;// UART communication
					TMR3CN &= ~0x04;//disable ADC window detect exciter		

					SYS_ON = 1;
					DISP_BKLIGHT = LCD_BL_ON;
					key_init(); 
					EIE1 |= 0x02;//Enable USB 	

					#ifdef OPTION__MCU_HARDWARE_SPI
						spi0_init();
					#endif

					#ifdef OPTION__USB_DRIVER
						Usb0_Init();
					#endif //OPTION__USB_DRIVER


				}
				
			}
			time_update();
//			detect_alarm();
		}
		auto_time_correct_flag	=time_auto_correct_temp;	
	}
#endif
}

/**************************************************************************************

******************************************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
#ifndef NO_ALARM_HARDWARE_REMOVE_ALARM_CODE
void alarm_time_up_mode(void)
{
	if(alarm_time_up)
	{
		display_delay_4ms = 100;
		display_delay_en = 1;
		if(time_dot_flag == 1)
		{
			LCD_DisplayStr("Time Up\n",4,1);
		}
		else
		{
			LCD_DisplayStr("       \n",4,1);				
		}
#ifdef OPTION__INCLUDE_POWER_SAVING_MODE
		wake_up_time = NO_KEY_WAKUP_TIME;
#endif
	}
}
#endif //NO_ALARM_HARDWARE_REMOVE_ALARM_CODE
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
/**************************************************************************************

******************************************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
#ifndef NO_ALARM_HARDWARE_REMOVE_ALARM_CODE
void detect_alarm(void)
{
	if(alarm_flag == 1)
	{
		if(alarm_time.sec ==time.sec&&alarm_time.min ==time.min&&alarm_time.hour ==time.hour&&alarm_time.day ==time.day&&alarm_time.month ==time.month&&alarm_time.year ==time.year)
		{
			alarm_time.sec = alarm_time.sec+1;//avoid loop fresh within 1 sec
			LCD_Clear(LCD_CLEAR_ALL);
			LCD_DisplayStr("Alarm\n",5,0);
			display_mode = ALARM_TIMEUP_MODE;
			alarm_time_up = 1;

#ifdef OPTION__INCLUDE_POWER_SAVING_MODE
		wake_up_time = NO_KEY_WAKUP_TIME;
		wake_up_init();
#endif

			Timer3_Init_buzzer();// startup the alarm voice


		}
	}
}
#endif //NO_ALARM_HARDWARE_REMOVE_ALARM_CODE


void display_software_version()
{
	#ifdef OPTION__IMAGETYPE__FMHD_AMHD
			LCD_DisplayStr("FMHD AMHD v1.9.7\n",0,1);
	#endif

	#ifdef OPTION__IMAGETYPE__DAB_FM_AM
			LCD_DisplayStr("DAB FM AM v1.9.7\n",0,1);
	#endif
	#ifdef OPTION__IMAGETYPE__DAB_FM
			LCD_DisplayStr("DAB FM v1.9.7\n",0,1);
	#endif
    	#ifdef OPTION__IMAGETYPE__FMHD
			LCD_DisplayStr("FMHD v1.9.7\n",0,1);
	#endif
    	#ifdef OPTION__IMAGETYPE__ALL
			LCD_DisplayStr("DAB FMHD v1.9.7\n",0,1);
	#endif
}
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI				
/****************************************************************************************
#define BACK_LIGHT		0
#define HD_SEEK			1
#define DAB_RESCAN		2
#define MONO_STEREO		3
#define SNOOZE			4
#define VERSION			5
******************************************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
#ifdef OPTION__MENU_SETTING
code u8 menu_item_string[][16]={
	".Back Light\n",
	".HD Seek\n",
	".DAB Rescan\n",
	".Force M/Steo\n",
	".Snooze\n",
	".Version\n",
	".DAB Manu Tune\n",
	".DAB Get Time\n",
	".Battery\n",
	".Freq Step\n",//FM
	".Freq Step\n",//FMHD
	".Auto Time Corr\n",
	".UK Freq List\n",
	".Emphasis\n",
	".Signal Error\n",
	".Audio Info\n",
};
#endif //OPTION__MENU_SETTING
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI


#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
#ifdef OPTION__INCLUDE_MODE__AM
#ifdef OPTION__MENU_SETTING
code AM_MENU_ITEM[]={
	BACK_LIGHT,
	SNOOZE,
	BATTERY,
	VERSION,
};
#endif //OPTION__MENU_SETTING
#endif //OPTION__INCLUDE_MODE__FM
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI




#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
#ifdef OPTION__INCLUDE_MODE__FM
#ifdef OPTION__MENU_SETTING
code FM_MENU_ITEM[]={
	BACK_LIGHT,
	FM_FREQ_STEP_SIZE,
	MONO_STEREO,
	AUTO_TIME_CORRECT,
	FMHD_EMPHASIS,
	SNOOZE,
	BATTERY,
	VERSION,
};
#endif //OPTION__MENU_SETTING
#endif //OPTION__INCLUDE_MODE__FM
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI

#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
#ifdef OPTION__INCLUDE_MODE__FMHD
#ifdef OPTION__MENU_SETTING
code FMHD_MENU_ITEM[]={
	BACK_LIGHT,
	FMHD_FREQ_STEP_SIZE,
	HD_SEEK,
	FMHD_EMPHASIS,
	SNOOZE,
	BATTERY,
	VERSION,

};
#endif// OPTION__MENU_SETTING
#endif //OPTION__INCLUDE_MODE__FMHD
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI

#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
#ifdef OPTION__INCLUDE_MODE__DAB
#ifdef OPTION__MENU_SETTING
code DAB_MENU_ITEM[]={
	BACK_LIGHT,
	DAB_ERROR_BIT,
	DAB_AUDIO_INFO,
	DAB_RESCAN,
	DAB_MANUAL_TUNE,
	DAB_GET_TIME,
	DAB_UK_FREQ_LIST,
	AUTO_TIME_CORRECT,	
	SNOOZE,
	BATTERY,
	VERSION,
};
#endif //OPTION__MENU_SETTING
#endif //OPTION__INCLUDE_MODE__DAB
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
/********************************************************************************************************
full DAB ensemble name and frequency
********************************************************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
#ifdef OPTION__INCLUDE_MODE__DAB
#ifdef OPTION__MENU_SETTING
code u8 DAB_ensemble_name[][12]={ 
	"5A 174.928\n",// 0
	"5B 176.640\n",// 1
	"5C 178.352\n",// 2
	"5D 180.064\n",// 3
	"6A 181.936\n",// 4
	"6B 183.648\n",// 5
	"6C 185.360\n",// 6
	"6D 187.072\n",// 7
	"7A 188.928\n",// 8
	"7B 190.640\n",// 9
	"7C 192.352\n",// 10
	"7D 194.064\n",// 11
	"8A 195.936\n",// 12
	"8B 197.648\n",// 13
	"8C 199.360\n",// 14
	"8D 201.072\n",//  15
	"9A 202.928\n",//  16
	"9B 204.640\n",//  17
	"9C 206.352\n",//  18
	"9D 208.064\n",//  19
	"10A 209.936\n",//  20
	"10N 210.096\n",//  21
	"10B 211.648\n",//  22
	"10C 213.360\n",//  23
	"10D 215.072\n",//  24
	"11A 216.928\n",//  25
	"11N 217.088\n",//  26
	"11B 218.640\n",//  27
	"11C 220.352\n",//  28
	"11D 222.064\n",//  29
	"12A 223.936\n",//  30
	"12N 224.096\n",//  31
	"12B 225.648\n",//  32
	"12C 227.360\n",//  33
	"12D 229.072\n",//  34
	"13A 230.784\n",//  35
	"13B 232.496\n",//  36
	"13C 234.208\n",//  37
	"13D 235.776\n",//  38
	"13E 237.488\n",//  39
	"13F 239.200\n",//  40
};
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI

#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
//                                {218640, 220352, 222064, 223936, 225648, 227360, 229072};
//{211648, 213360, 215072, 216928, 218640, 220352, 222064, 223936, 225648, 227360, 229072};
code u8 DAB_ensemble_name_indexUKonly[]={
    22,
    23,
    24,
    25,
    27,
    28,
    29,
    30,
    32,
    33,
    34,
};
#endif// OPTION__MENU_SETTING
#endif //OPTION__INCLUDE_MODE__DAB
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
/********************************************************************************************************

********************************************************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
#define MENU_ITEM_DISPLAY_TIME	3000
RETURN_CODE menu_work_mode(void)
{
	RETURN_CODE ret = SUCCESS;

#ifndef OPTION__MENU_SETTING

		//display_delay_4ms  = MENU_ITEM_DISPLAY_TIME;
		LCD_DisplayStr("Not menu support\n",0,0);
		display_software_version();	
		return ret;
#endif

		

#ifdef OPTION__MENU_SETTING

#ifdef OPTION__INCLUDE_MODE__DAB
    dab_time TimeDab;
#endif //OPTION__INCLUDE_MODE__DAB
	u16 battery_ad;
	u32 i;
	u16 temp_emphasis;
	if(key_flag)
	{
		key_flag = 0;
		display_refresh_flag = 1;
		switch(key_value)
		{
			case UP_KEY:
			case TUNE_INC_KNOBS:
				display_delay_4ms  = MENU_ITEM_DISPLAY_TIME;
				if(menu_select_flag ==0)//browse the menu item
				{
					menu_index ++;//move the cusor to next 
#ifdef OPTION__INCLUDE_MODE__FM
					if(work_mode == fmonly)
					{
						if(menu_index >sizeof(FM_MENU_ITEM)/sizeof(FM_MENU_ITEM[0]) -1)//if the cusor over range
						{
							menu_index = 0;
						}
						current_menu_item  = FM_MENU_ITEM[menu_index];//
					}
#endif
#ifdef OPTION__INCLUDE_MODE__FMHD
					else if(work_mode == fmhd)
					{

						if(menu_index >sizeof(FMHD_MENU_ITEM)/sizeof(FMHD_MENU_ITEM[0]) -1)
						{
							menu_index = 0;
						}
						current_menu_item  = FMHD_MENU_ITEM[menu_index];
					}
#endif //OPTION__INCLUDE_MODE__FMHD
#ifdef OPTION__INCLUDE_MODE__DAB
					else if(work_mode == dab)
					{
						if(menu_index >sizeof(DAB_MENU_ITEM)/sizeof(DAB_MENU_ITEM[0]) -1)
						{
							menu_index = 0;
						}
						current_menu_item  = DAB_MENU_ITEM[menu_index];
					}
#endif //OPTION__INCLUDE_MODE__DAB
#ifdef OPTION__INCLUDE_MODE__AM
					else if(work_mode == am)
					{
						if(menu_index >sizeof(AM_MENU_ITEM)/sizeof(AM_MENU_ITEM[0]) -1)//if the cusor over range
						{
							menu_index = 0;
						}
						current_menu_item  = AM_MENU_ITEM[menu_index];//
					}
#endif//OPTION__INCLUDE_MODE__AM
																	
				}
				else
				{
					switch(current_menu_item)//change the value 
					{
#ifdef OPTION__INCLUDE_MODE__FM
                        case MONO_STEREO:
							mono_stereo_flag ^= 1;
							ret = ForceMono_FM(mono_stereo_flag);
							break;
                        case FM_FREQ_STEP_SIZE:
							if(fm_freq_step_size ==50){
								fm_freq_step_size =100;
							}else if(fm_freq_step_size==100){
								fm_freq_step_size =200;
							}else if(fmhd_freq_step_size ==200){
								fm_freq_step_size = 50;
							}else{
								fm_freq_step_size = 100;
							}
						    set_freq_spacing();
							break;
                        case FMHD_EMPHASIS:
							temp_emphasis = 0x0000;
							GetProperty(PROP_FM_AUDIO_DE_EMPHASIS_GROUP<<8|PROP_FM_AUDIO_DE_EMPHASIS_INDEX,&temp_emphasis);
							if(temp_emphasis==PROP_FM_AUDIO_DE_EMPHASIS_DE_EMPH_ENUM_OFF)
							{
								 SetProperty(PROP_FM_AUDIO_DE_EMPHASIS_GROUP<<8|PROP_FM_AUDIO_DE_EMPHASIS_INDEX, PROP_FM_AUDIO_DE_EMPHASIS_DE_EMPH_ENUM_50US);
							}
							else if(temp_emphasis==PROP_FM_AUDIO_DE_EMPHASIS_DE_EMPH_ENUM_50US)
							{
								SetProperty(PROP_FM_AUDIO_DE_EMPHASIS_GROUP<<8|PROP_FM_AUDIO_DE_EMPHASIS_INDEX, PROP_FM_AUDIO_DE_EMPHASIS_DE_EMPH_ENUM_75US);	
							}
							else
							{
								SetProperty(PROP_FM_AUDIO_DE_EMPHASIS_GROUP<<8|PROP_FM_AUDIO_DE_EMPHASIS_INDEX, PROP_FM_AUDIO_DE_EMPHASIS_DE_EMPH_ENUM_OFF);
							}
							break;
#endif //OPTION__INCLUDE_MODE__FM

#ifdef OPTION__INCLUDE_MODE__FMHD
						//case HD_SEEK:
						//	if(work_mode == fmhd)
						//	{
						//		seek_state = SEEK_START_UP;
						//		display_delay_4ms = 10;
						//	}
						//	break;
						case FMHD_FREQ_STEP_SIZE:
							if(fmhd_freq_step_size ==50){
								fmhd_freq_step_size =100;
							}else if(fmhd_freq_step_size==100){
								fmhd_freq_step_size =200;
							}else if(fmhd_freq_step_size ==200){
								fmhd_freq_step_size =50;
							}else{
								fmhd_freq_step_size =200;
							}
                            set_freq_spacing();
							break;
#endif //OPTION__INCLUDE_MODE__FMHD

#ifdef OPTION__INCLUDE_MODE__DAB
						case DAB_RESCAN:
							DAB_scan();
							break;
						case DAB_MANUAL_TUNE:
							pfunc = DAB_MANUAL_TUNE;
                            if(dab_reduced_list_flag)
                            {
                                if(dab_manual_freq_index<(sizeof(DAB_ensemble_name_indexUKonly) - 1))
    							{
    								dab_manual_freq_index++;
    							}
                            }else
                            {
    							if(dab_manual_freq_index<(sizeof(DAB_ensemble_name)/sizeof(DAB_ensemble_name[0])-1))
    							{
    								dab_manual_freq_index++;
    							}
                            }
							break;
						case DAB_UK_FREQ_LIST:
							dab_uk_freq_list_flag^=1;
							pfunc = DAB_UK_FREQ_LIST;
							break;
#endif //OPTION__INCLUDE_MODE__DAB

						case BACK_LIGHT:
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
						case SNOOZE:
							if(alarm_time_up)
							{
								alarm_flag = 1;
								alarm_time_up = 0;
								alarm_time.min = time.min+10;
							}
							break;
						case AUTO_TIME_CORRECT:
							 if(auto_time_correct_flag==AUTO_TIME_CORRECT_ENABLE)
							 {
							 	auto_time_correct_flag = 0x00;
							}else{
							 	auto_time_correct_flag = AUTO_TIME_CORRECT_ENABLE;
							 }
							auto_time_correct_func();
							 break;
						case VERSION:
							break;
						default:break;    
					}	
				}	
				break;
			case DOWN_KEY:
			case TUNE_DEC_KNOBS:
				display_delay_4ms  = MENU_ITEM_DISPLAY_TIME;//if the time out then back to main display 
				if(menu_select_flag ==0)
				{
					if(work_mode == fmonly)
					{
#ifdef OPTION__INCLUDE_MODE__FM
						if(menu_index>0)
						{
							menu_index -=1;
						}
						else
						{
							menu_index = sizeof(FM_MENU_ITEM)/sizeof(FM_MENU_ITEM[0]) -1;
						}
						current_menu_item  = FM_MENU_ITEM[menu_index];
#endif //OPTION__INCLUDE_MODE__FM
					}
#ifdef OPTION__INCLUDE_MODE__FMHD
					else if(work_mode == fmhd)
					{
						if(menu_index>0)
						{
							menu_index -=1;
						}
						else
						{
							menu_index = sizeof(FMHD_MENU_ITEM)/sizeof(FMHD_MENU_ITEM[0]) -1;
						}
						current_menu_item  = FMHD_MENU_ITEM[menu_index];
					}
#endif //OPTION__INCLUDE_MODE__FMHD
#ifdef OPTION__INCLUDE_MODE__DAB
					else if(work_mode == dab)
					{
						if(menu_index>0)
						{
							menu_index -=1;
						}
						else
						{
							menu_index = sizeof(DAB_MENU_ITEM)/sizeof(DAB_MENU_ITEM[0]) -1;
						}
						current_menu_item  = DAB_MENU_ITEM[menu_index];
					}	
#endif //OPTION__INCLUDE_MODE__DAB
#ifdef OPTION__INCLUDE_MODE__AM
					else if(work_mode == am)
					{
						if(menu_index>0)
						{
							menu_index -=1;
						}
						else
						{
							menu_index = sizeof(AM_MENU_ITEM)/sizeof(AM_MENU_ITEM[0]) -1;
						}
						current_menu_item  = AM_MENU_ITEM[menu_index];
					}
#endif //OPTION__INCLUDE_MODE__AM																
				}
				else
				{
					switch(current_menu_item)
					{
#ifdef OPTION__INCLUDE_MODE__FM
                        case MONO_STEREO:
							mono_stereo_flag ^= 1;
							ret = ForceMono_FM(mono_stereo_flag);
							break;
                        case FM_FREQ_STEP_SIZE:
							if(fm_freq_step_size ==200){
								fm_freq_step_size =100;
							}else if(fm_freq_step_size==100){
								fm_freq_step_size =50;
							}else if(fm_freq_step_size==50){
								fm_freq_step_size = 200;
							}else{
								fm_freq_step_size = 100;
							}
                            set_freq_spacing();
							break;
                        case FMHD_EMPHASIS:
							temp_emphasis = 0x0000;
							GetProperty(PROP_FM_AUDIO_DE_EMPHASIS_GROUP<<8|PROP_FM_AUDIO_DE_EMPHASIS_INDEX,&temp_emphasis);
							if(temp_emphasis==PROP_FM_AUDIO_DE_EMPHASIS_DE_EMPH_ENUM_OFF)
							{
								 SetProperty(PROP_FM_AUDIO_DE_EMPHASIS_GROUP<<8|PROP_FM_AUDIO_DE_EMPHASIS_INDEX, PROP_FM_AUDIO_DE_EMPHASIS_DE_EMPH_ENUM_75US);
							}
							else if(temp_emphasis==PROP_FM_AUDIO_DE_EMPHASIS_DE_EMPH_ENUM_75US)
							{
								SetProperty(PROP_FM_AUDIO_DE_EMPHASIS_GROUP<<8|PROP_FM_AUDIO_DE_EMPHASIS_INDEX, PROP_FM_AUDIO_DE_EMPHASIS_DE_EMPH_ENUM_50US);	
							}
							else
							{
								SetProperty(PROP_FM_AUDIO_DE_EMPHASIS_GROUP<<8|PROP_FM_AUDIO_DE_EMPHASIS_INDEX, PROP_FM_AUDIO_DE_EMPHASIS_DE_EMPH_ENUM_OFF);
							}
							break;	
#endif //OPTION__INCLUDE_MODE__FM

#ifdef OPTION__INCLUDE_MODE__FMHD
						//case HD_SEEK:
						//	if(work_mode == fmhd)
						//	{
						//		seek_state = SEEK_START_UP;
						//		display_delay_4ms = 10;
						//	}
						//	break;
                        case FMHD_FREQ_STEP_SIZE:
							if(fmhd_freq_step_size ==200){
								fmhd_freq_step_size =100;
							}else if(fmhd_freq_step_size==100){
								fmhd_freq_step_size =50;
							}else if(fmhd_freq_step_size ==50){
								fmhd_freq_step_size =200;
							}else{
								fmhd_freq_step_size =200;
							}
                            set_freq_spacing();
							break;
#endif //OPTION__INCLUDE_MODE__FMHD
													
#ifdef OPTION__INCLUDE_MODE__DAB
						case DAB_RESCAN:
							DAB_scan();
							break;
						case DAB_MANUAL_TUNE:
							pfunc = DAB_MANUAL_TUNE;
							if(dab_manual_freq_index>0)
							{
								dab_manual_freq_index--;
							}
							break;
						case DAB_UK_FREQ_LIST:
							dab_uk_freq_list_flag^=1;
							pfunc = DAB_UK_FREQ_LIST;
							break;
#endif //OPTION__INCLUDE_MODE__DAB

						case BACK_LIGHT:
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
                        case AUTO_TIME_CORRECT:
							 if(auto_time_correct_flag==AUTO_TIME_CORRECT_ENABLE)
							 {
							 	auto_time_correct_flag = 0x00;
							 }else{
							 	auto_time_correct_flag = AUTO_TIME_CORRECT_ENABLE;
							 }

							 auto_time_correct_func();
							 break;
						case SNOOZE:
							if(alarm_time_up)
							{
								alarm_flag = 1;
								alarm_time_up = 0;
								alarm_time.min = time.min+10;
							}
							break;
						case VERSION:
							break;
						default:break;
					}	
				}				
				break;
			case SELECT_KEY:
				display_delay_4ms  = MENU_ITEM_DISPLAY_TIME;
				menu_select_flag ^=1;
				break;
			default:display_refresh_flag = 0; break;
		}
	}
	if(display_refresh_flag)
	{
		display_refresh_flag = 0;
		LCD_Clear(LCD_CLEAR_ALL);
		LCD_DisplayNum(menu_index+1,1,0);
		if(menu_index+1>=10)
		{
			LCD_DisplayStr(menu_item_string[current_menu_item],3,0);
		}
		else
		{
			LCD_DisplayStr(menu_item_string[current_menu_item],2,0);		
		}
		LCD_DisplayStr(">\n",0,0);
		if(menu_select_flag ==0) // in browse item mode , display two items on LCD
		{

			if(work_mode == fmonly)
			{
#ifdef OPTION__INCLUDE_MODE__FM
				if(menu_index <sizeof(FM_MENU_ITEM)/sizeof(FM_MENU_ITEM[0]) -1)//if the cusor over range
				{
					LCD_DisplayNum(menu_index+2,1,1);
					if(menu_index+2 >=10)
					{
						LCD_DisplayStr(menu_item_string[FM_MENU_ITEM[menu_index+1]],3,1);//display the next item;;
					}
					else
					{
						LCD_DisplayStr(menu_item_string[FM_MENU_ITEM[menu_index+1]],2,1);//display the next item;
					}
				}
				else
				{
					LCD_DisplayNum(1,1,1);
					LCD_DisplayStr(menu_item_string[0],2,1);//else display first the item
				}
#endif //OPTION__INCLUDE_MODE__FM				
			}
			else if(work_mode == fmhd)
			{
#ifdef OPTION__INCLUDE_MODE__FMHD
				if(menu_index <sizeof(FMHD_MENU_ITEM)/sizeof(FMHD_MENU_ITEM[0]) -1)//if the cusor over range
				{
					LCD_DisplayNum(menu_index+2,1,1);
					if(menu_index+2>=10)
					{
						LCD_DisplayStr(menu_item_string[FMHD_MENU_ITEM[menu_index+1]],3,1);
					}
					else
					{
						LCD_DisplayStr(menu_item_string[FMHD_MENU_ITEM[menu_index+1]],2,1);
					}						
				}
				else
				{
					LCD_DisplayNum(1,1,1);
					LCD_DisplayStr(menu_item_string[0],2,1);
				}
#endif //OPTION__INCLUDE_MODE__FMHD
			}
			else if(work_mode == dab)
			{
#ifdef OPTION__INCLUDE_MODE__DAB
				if(menu_index <sizeof(DAB_MENU_ITEM)/sizeof(DAB_MENU_ITEM[0]) -1)//if the cusor over range
				{
					LCD_DisplayNum(menu_index+2,1,1);
					if(menu_index+2>=10)
					{
						LCD_DisplayStr(menu_item_string[DAB_MENU_ITEM[menu_index+1]],3,1);;
					}
					else
					{
						LCD_DisplayStr(menu_item_string[DAB_MENU_ITEM[menu_index+1]],2,1);
					}
				}
				else
				{
					LCD_DisplayNum(1,1,1);
					LCD_DisplayStr(menu_item_string[0],2,1);
				}
#endif //OPTION__INCLUDE_MODE__DAB
			}
			else if(work_mode == am)
			{
#ifdef OPTION__INCLUDE_MODE__AM
				if(menu_index <sizeof(AM_MENU_ITEM)/sizeof(AM_MENU_ITEM[0]) -1)//if the cusor over range
				{
					LCD_DisplayNum(menu_index+2,1,1);
					if(menu_index+2>=10)
					{
						LCD_DisplayStr(menu_item_string[AM_MENU_ITEM[menu_index+1]],3,1);;
					}
					else
					{
						LCD_DisplayStr(menu_item_string[AM_MENU_ITEM[menu_index+1]],2,1);
					}
				}
				else
				{
					LCD_DisplayNum(1,1,1);
					LCD_DisplayStr(menu_item_string[0],2,1);
				}
#endif //OPTION__INCLUDE_MODE__AM
			}				
						
		}
		else
		{
			switch(current_menu_item)
			{
#ifdef OPTION__INCLUDE_MODE__FM
                    case MONO_STEREO:
						if(mono_stereo_flag == 0)
						{
							LCD_DisplayStr("Stereo\n",5,1);							
						}
						else
						{
							LCD_DisplayStr("Mono\n",5,1);	
						}	
						break;
                    case FM_FREQ_STEP_SIZE:
						if(work_mode == fmonly)
						{
							LCD_DisplayNum(fm_freq_step_size,5,1);
						}
						else
						{
							current_menu_item =	BACK_LIGHT;	
						}
						break;
                    case FMHD_EMPHASIS:
    					temp_emphasis = 0x0000;
    					GetProperty(PROP_FM_AUDIO_DE_EMPHASIS_GROUP<<8|PROP_FM_AUDIO_DE_EMPHASIS_INDEX,&temp_emphasis);
    					if(temp_emphasis==PROP_FM_AUDIO_DE_EMPHASIS_DE_EMPH_ENUM_OFF)
    					{
    						 LCD_DisplayStr("OFF\n",5,1);
    					}
    					else if(temp_emphasis==PROP_FM_AUDIO_DE_EMPHASIS_DE_EMPH_ENUM_75US)
    					{
    						LCD_DisplayStr("75us\n",5,1);
    					}
    					else
    					{
    						LCD_DisplayStr("50us\n",5,1);
    					}
    					break;
#endif //OPTION__INCLUDE_MODE__FM

#ifdef OPTION__INCLUDE_MODE__FMHD
				case HD_SEEK:
						if(work_mode == fmhd)
						{
							LCD_DisplayStr("Seek now?\n",5,1);	
						}
						else
						{
							current_menu_item =	BACK_LIGHT;		
						}
						break;
                case FMHD_FREQ_STEP_SIZE:
						if(work_mode == fmhd)
						{
							LCD_DisplayNum(fmhd_freq_step_size,5,1);
						}
						else
						{
							current_menu_item =	BACK_LIGHT;	
						}
						break;
#endif //OPTION__INCLUDE_MODE__FMHD


#ifdef OPTION__INCLUDE_MODE__DAB
				case DAB_RESCAN:
						if(work_mode == dab)
						{
							LCD_DisplayStr("Scan now?\n",5,1);
						}
						else
						{
							current_menu_item =	BACK_LIGHT;		
						}					
						break;
				case DAB_MANUAL_TUNE:
						if(work_mode == dab)
						{
                            if(dab_reduced_list_flag)
                            {
                                LCD_DisplayStr(DAB_ensemble_name[DAB_ensemble_name_indexUKonly[dab_manual_freq_index]],2,1);
                            }else
                            {
    							LCD_DisplayStr(DAB_ensemble_name[dab_manual_freq_index],2,1);
                            }
							LCD_DisplayStr("MHz\n",13,1);
							//LCD_DisplayNum(dab_manual_freq_index,0,1);
						}
						else
						{
							current_menu_item =	BACK_LIGHT;					
						}					
						break;
				case DAB_GET_TIME:
						if(work_mode == dab)
						{
                            ret = GetCurrentTime_DAB(LOCAL,&TimeDab);
                            LCD_DisplayNum(TimeDab.YEAR,2,1);
                            LCD_DisplayNum(TimeDab.MONTH, 6,1);
                            LCD_DisplayNum(TimeDab.DAYS, 8,1);
                            LCD_DisplayNum(TimeDab.HOURS, 10,1);
                            LCD_DisplayNum(TimeDab.MINUTES, 12,1);
                            LCD_DisplayNum(TimeDab.SECONDS, 14,1);
						}
						else
						{
							current_menu_item =	BACK_LIGHT;				
						}
						break;
				case DAB_UK_FREQ_LIST:
						if(work_mode == dab)
						{
							//ChangeFreqListToLimitedUK();
							if(dab_uk_freq_list_flag)
							{
								LCD_DisplayStr("Enable\n",5,1);
							}
							else
							{
								LCD_DisplayStr("Disable\n",5,1);
							}
						}
						else
						{
								current_menu_item =	BACK_LIGHT;	
						}
						break;
				case DAB_ERROR_BIT://this item need to be update in time, 
						break;
				case DAB_AUDIO_INFO://DAB_BIT_RATE:
						ret = UpdateMetrics();
						LCD_DisplayStr("kbps\n",4,1);
						LCD_DisplayNum(MetricsGetDABPtr()->CURRENT_AUDIO_INFO__BIT_RATE,0,1);
						if(MetricsGetDABPtr()->CURRENT_AUDIO_INFO__MODE == DUAL)
						{
							LCD_DisplayStr("Dual\n",10,1);
						}
						else if(MetricsGetDABPtr()->CURRENT_AUDIO_INFO__MODE == MONO)
						{
							LCD_DisplayStr("Mono\n",10,1);	
						}
						else if(MetricsGetDABPtr()->CURRENT_AUDIO_INFO__MODE == STEREO)
						{
							LCD_DisplayStr("Stereo\n",10,1);	
						}
						else if(MetricsGetDABPtr()->CURRENT_AUDIO_INFO__MODE == JOINT_STEREO)
						{
							LCD_DisplayStr("Joint\n",10,1);	
						}
						else
						{
							LCD_DisplayStr("None\n",10,1);																		
						}
						break;
#endif //OPTION__INCLUDE_MODE__DABs

				case BACK_LIGHT:
						 if(LCD_BL_flag == 1)
						 {
							LCD_DisplayStr("BL ON\n",5,1);	
						 }
						 else
						 {
							LCD_DisplayStr("BL OFF\n",5,1);	
						 }					
					break;			
				case SNOOZE:
						if(alarm_time_up ==1)
						{
							LCD_DisplayStr("Intend 10 min?\n",2,1);
						}
						else
						{
							LCD_DisplayStr("No alarm\n",3,1);
						}
					break;
				case BATTERY:

#ifdef PLATFORM_F340_DEMOBOARD
						LCD_DisplayStr("No Support\n",0,5);
#endif
						break;
				
				case AUTO_TIME_CORRECT:
						if(auto_time_correct_flag==AUTO_TIME_CORRECT_ENABLE)
						{
							LCD_DisplayStr("Enable\n",5,1);
						}
						else
						{
							LCD_DisplayStr("Disable\n",5,1);
						};
						break;							
				case VERSION:
						display_software_version();
					break;	
				default:current_menu_item =	BACK_LIGHT;	break;
			}
		}
	}
#ifdef PLATFORM_F380_MODULE
/* 
						battery_ad=ad_convertion(0x11);
						//wait_ms(100);
						battery_ad=ad_convertion(0x11);
						LCD_DisplayNum(battery_ad,0,1);
*/
	//display_refresh_flag = 1;////the charging status need to update in time
	if(current_menu_item == BATTERY && menu_select_flag ==1&&display_delay_4ms%100==0)
	{
		if(BAT_DISP ==0)
		{
			LCD_DisplayStr("Cha\n",13,0);
		}
		else
		{
			LCD_DisplayStr("    \n",13,0);//erase the prompt
		}
		//display_delay_4ms  = 1000;//debuge
		battery_ad=ad_convertion(0x11);//P0.3
		wait_ms(100);
		battery_ad=ad_convertion(0x11);
		//LCD_DisplayNum(battery_ad,0,1);

		LCD_Clear(LCD_CLEAR_LINE2);

		LCD_DisplayStr("lev:\n",2,1);

		if(battery_ad <205)
		{
			battery_ad = 205;
		}
		for(i=0;i<10;i++)
		{
			if((((battery_ad+1-205)*10)/30)>i)
			{
				LCD_DisplayCBD(DEF_SFRECTANGLE,i+6,1);
			}
			else
			{
				LCD_DisplayCBD(DEF_SERECTANLG,i+6,1);	
			}
		}			
	}
#endif
#ifdef OPTION__INCLUDE_MODE__DAB
	if(current_menu_item == DAB_ERROR_BIT && menu_select_flag ==1 &&display_delay_4ms%100==0)
	{
		ret = UpdateMetrics();
		LCD_Clear(LCD_CLEAR_LINE2);
		LCD_DisplayStr("Err:\n",2,1);
        if((MetricsGetDABPtr()->CNR < 16) && (MetricsGetDABPtr()->CNR > 6)) // "close to error range"
        {
            LCD_DisplayNum((10 - ((MetricsGetDABPtr()->CNR - 6))),8,1); // convert to 0-10 within this range, where 0 is best
        }
		else if(MetricsGetDABPtr()->CNR <= 6)
        {
            LCD_DisplayNum(10,8,1); // convert to 10 for in error
        }
		else
        {
            LCD_DisplayNum(0,8,1); // convert to 0 for well above error threshold
        }
	}
#endif


	#endif //OPTION__MENU_SETTING

#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
	detece_key();
#endif // OPTION__OPERATE_AS_SLAVE_NO_MMI
	return ret;


}
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
/****************************************************************************************

******************************************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
RETURN_CODE volume_work_mode(void)
{
	u8 i;
	RETURN_CODE ret = SUCCESS;
	if(display_refresh_flag)
	{
		display_refresh_flag = 0;
		LCD_Clear(LCD_CLEAR_ALL);
		LCD_DisplayStr("Volume:\n",0,0);
		LCD_DisplayNum(((volume+1)/VOLUME_STEP),13,0);

		for(i=0;i<16;i++)
		{	
			if(((volume+1)/VOLUME_STEP)>i)
			{
				LCD_DisplayCBD(DEF_SFRECTANGLE,i,1);
			}
			else
			{
				LCD_DisplayCBD(DEF_SERECTANLG,i,1);	
			}			
		}
		ret = AudioLevel(volume);
	}
    //Removing this call as it causes inadvertant exits while in the volume menu
	//detece_key();
	return ret;
}
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
/*****************************************************************************************

******************************************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
RETURN_CODE audio_mute(void)
{
	RETURN_CODE ret = SUCCESS;
	if(display_refresh_flag)
	{
		display_refresh_flag = 0;
		LCD_Clear(LCD_CLEAR_ALL);
		if(mute_flag == 0)
		{
			LCD_DisplayStr("Mute OFF\n",0,0);
		}
		else
		{
			LCD_DisplayStr("Mute ON\n",0,0);
		}
	}
	detece_key();			
	return ret;
}	
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
/******************************************************************************************

*******************************************************************************************/
