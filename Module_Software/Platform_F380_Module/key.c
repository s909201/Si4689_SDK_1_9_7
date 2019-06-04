/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   keypad driver for C8051F380 based module
   FILE: key.c
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
	#include "usb_main.h"
#endif

#include "sys.h"
#include "key.h"
#include "main.h"
#include "delay.h"
#include "mode_common.h"
/************************************************************************/
//timer2 interrupt as key scan clock 4ms
/************************************************************************/
void Timer2_init(void)
{
	TMR2CN = 0;
	TMR2H = T2HIGH;
	TMR2L = T2LOW;
	TMR2RLH = T2HIGH;
	TMR2RLL = T2LOW;
	TR2 = 1;
	ET2 = 1;
}

void Timer2_Int() interrupt INTERRUPT_TIMER2
{
	TF2H = 0;
	TF2L = 0;
	TR2 = 0;
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
	switch(tuning_status)
	{
		case 0:
			if(TUNING_A!=TUNING_B) //10 /01
			{
				TA_old = TUNING_A;
				TB_old = TUNING_B;
				tuning_status++;
			}
			break;
		case 1:
			if(TUNING_A == 0&&TUNING_B == 0)//11
			{
				tuning_status++;
			}
			break;
		case 2:
			if(TUNING_A== 1&& TUNING_B ==1) //00
			{
				if(TA_old == 1)
				{
					//tuning_value ++;
					key_value = TUNE_INC_KNOBS;
					key_flag = 1;
				}
				else if(TB_old ==1)
				{
					//tuning_value --;
					key_value = TUNE_DEC_KNOBS;
					key_flag = 1;
				}
#ifdef ATS_EMBED_CODE
				if(key_flag ==1)
				{
					ats_key = key_value;
					ats_key_flag = 2;//1:keypad mode 2:encode mode
				}
#endif
				tuning_status = 0;
				knobs_flag = 1;
			}
			break;
		default:tuning_status = 0;
			break;
	}	
	switch(volume_status)
	{
		case 0:
			if(VOLUME_A!=VOLUME_B) //10 /01
			{
				VA_old = VOLUME_A;
				VB_old = VOLUME_B;
				volume_status++;
			}
			break;
		case 1:
			if(VOLUME_A == 0&&VOLUME_B == 0)//11
			{
				volume_status++;
			}
			break;
		case 2:
			if(VOLUME_A == 1&& VOLUME_B == 1) //00
			{
				if(VA_old == 1)
				{
					//volume_value ++;
					key_value = VOLUME_DEC_KNOBS;
					key_flag = 1;
				}
				else if(VB_old ==1)
				{
					//volume_value --;
					key_value = VOLUME_INC_KNOBS;
					key_flag = 1;
				}
#ifdef ATS_EMBED_CODE
				if(key_flag ==1)
				{
					ats_key = key_value;
					ats_key_flag = 2;//1:keypad mode 2:encode mode
				}
#endif
				volume_status = 0;
				knobs_flag = 1;
			}
			break;
		default:volume_status = 0;
			break;
	}
	if(select_item_flash_delay >0)
	{
		select_item_flash_delay --;
	}
	
	if(temp_knobs==1)
	{
		knobs_count++;
		if(knobs_count==KNOBS_JUDGE_COUNT)
		{
			knobs_press_flag =1;
		}
	}
	if(key_mode == KEY_WAIT_MODE ||key_mode == KEY_WAIT_UP_MODE)
	{
		key_down_count ++;
	}

#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI

	if(display_delay_4ms>0)
	{
		display_delay_4ms --;
	}	
	if(display_item_str_4ms>0)
	{
		display_item_str_4ms --;
	}

#ifdef PLATFORM_F340_DEMOBOARD
	if(time_count>250)
	{
		time_count = 0;
		time_sec_flag = 1;
	}
	else
	{
		time_count ++;
	}
#endif 
	TR2 = 1;
}
/*******************************************************************

********************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI

void key_init(void)
{
#ifdef  PLATFORM_F380_MODULE
	u8  i;
	ADC0CN = 0x00;                      // ADC0 disabled, normal tracking, 
	                               // conversion triggered on write 1 to ADC0BUSY
	// REF0CN = 0x03;                      // Enable on-chip VREF and buffer

	REF0CN  = 0X08;

	AMX0P = 0x13;                       // ADC0 positive input = P1.1
	AMX0N = 0x1F;                       // ADC0 negative input = GND
	                               // i.e., single ended mode

	ADC0CF = ((SYSCLK/3000000)-1)<<3;   // set SAR clock to 3MHz

	ADC0CF &=~0x04;                     // right-justify results 

	//  EIE1 |= 0x08;                       // enable ADC0 conversion complete int.
	// AD0EN = 1;                          // enable ADC0

	for(i=0;i<4;i++)
	{
		key_vlaue_array[i] = 0x03ff;
	}
#endif
	key_down_flag = 0;
	key_up_flag = 0;
	key_value = 0xff;

	key_up_count = 0;
	key_down_count = 0;
	key_flag = 0;

	knobs_count = 0;
	knobs_press_flag = 0;
	temp_knobs = 0;

}
#endif //#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI



#ifdef  PLATFORM_F380_MODULE
/*******************************************************************

********************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
/*
#define ON_OFF_PIN 0x0D
void ADC_compare_init()
{
	EIE1 &=~0x04;//EWADC0;
	AD0TM = 1;
	ADC0CF &=~0x08;
	ADC0CF &=~0x04;                     // right-justify results 
	AMX0P = ON_OFF_PIN;
	//-------->0x0100
	//ADC0WIN =1
	//-------->0x0010
	ADC0LT = 0x0300;//avoid noise
	ADC0GT = 0x0200;//avoid noise

	AD0EN = 1;
	ADC0CN |=0x05;//Triggered ADC conversion by T3 overflow
	AD0WINT = 0;
	EIE1 |= 0X04;
}
void ADC_CMP_int() interrupt INTERRUPT_ADC0_WINDOW
{
	EIE1 &=~0x04;//DWADC0;
	AD0INT = 0;
//	AD0WINT= 0;
//	ADC0CN = 0x00;
//	wake_up_time = NO_KEY_WAKUP_TIME;
}
*/

#ifdef OPTION__INCLUDE_POWER_SAVING_MODE
void key_comparator_init()
{
	u8 i = 0;
	/*
    CPT0CN    = 0x8F;
    for (i = 0; i < 35; i++);  // Wait 10us for initialization
    CPT0CN    &= ~0x30;
    CPT0MX    = 0x33;
    CPT0MD    = 0x30;
*/
	XBR0 |= 0x10;

    CPT0CN    = 0x8F;
    for (i = 0; i < 35; i++);  // Wait 10us for initialization
    CPT0CN    &= ~0x30;
    CPT0MX    = 0x33;
    CPT0MD    = 0x22;
    EIE1      |= 0x20;
}
#endif //OPTION__INCLUDE_POWER_SAVING_MODE

void comparator0_int()  interrupt INTERRUPT_COMPARATOR0
{
	EIE1   &=~0x20;
	key_flag = 1;

    //CPT0CN    = 0x0F;
	//CPT0CN    = 0x8F;
//	CPT0CN = 0xef;
}
	
#endif
/**************************************************************************************************

**************************************************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
u16 ad_convertion(u8 pin_value)
{
	AD0EN = 1;
	ADC0CN &=~0x20;//clr ADC0INT
	ADC0CN &=~0x10;//CLR ADC0BUSY
	AMX0P = pin_value;
	ADC0CN |=0x10;//Triggered ADC conversion
	while(!(ADC0CN&0x20));//WAIT FOR conversion complete			
	AD0EN = 0;		
	return ADC0;
}
#endif//#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI	
/*******************************************************************

********************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
#define NO_KEY_VALUE_TH		0x0380
code u8 KEY_PIN_ADDR[4]={0x20,0x21,0x0C,0x0D};
code u8 KEY_TABLE[16] = {	DOWN_KEY,		SELECT_KEY,	UP_KEY,		BACK_LIGHT_KEY,
							SEEK_DOWN_KEY,	CLOCK_KEY,	SEEK_UP_KEY,	HDSEEK_KEY,
							PRESET_DEC_KEY ,ALARM_KEY,PRESET_INC_KEY,	DAB_RESCAN_KEY,
							MODE_KEY,		MENU_KEY,	ON_OFF_KEY,		SNOOZE_KEY};

void key_scan(void)
{
	u8 i;
	u16 ADC_Result_temp[4];
		switch(key_mode)
		{
			case KEY_UP_MODE:
				for(i=0;i<4;i++)
				{
					ADC_Result_temp[i] = ad_convertion(KEY_PIN_ADDR[i]); // no sense convertion
					wait_us(5);
					ADC_Result_temp[i] = ad_convertion(KEY_PIN_ADDR[i]);

					if(ADC_Result_temp[i] < NO_KEY_VALUE_TH)
					{
						key_mode = KEY_DOWN_MODE;
						key_up_count = 0;
					}
				}
				key_down_count = 0;
				key_up_count ++;
				if(key_up_count >KEY_STABLE_VALID_TIME)
				{
					key_up_count = 0;
					key_up_flag = 1;
				}
				break;
			case KEY_DOWN_MODE:
				key_mode = KEY_UP_MODE;
				for(i=0;i<4;i++)
				{
					ADC_Result_temp[i] = ad_convertion(KEY_PIN_ADDR[i]); // no sense convertion
					wait_us(5);
					ADC_Result_temp[i] = ad_convertion(KEY_PIN_ADDR[i]);

					if(ADC_Result_temp[i] <NO_KEY_VALUE_TH)
					{
						key_mode = KEY_DOWN_MODE;
						key_down_count ++;
						if(key_down_count >KEY_STABLE_VALID_TIME)
						{
							key_down_flag = 1;
							key_mode ++;
							key_vlaue_array[i] = ADC_Result_temp[i];
						}
					}
				}
				break;
			case KEY_WAIT_MODE://wait for down up or reach to the hold condition
				key_mode = KEY_UP_MODE;
				for(i=0;i<4;i++)
				{
					ADC_Result_temp[i] = ad_convertion(KEY_PIN_ADDR[i]); // no sense convertion
					wait_us(5);
					ADC_Result_temp[i] = ad_convertion(KEY_PIN_ADDR[i]);

					if(ADC_Result_temp[i] < NO_KEY_VALUE_TH)
					{
						if(key_down_count >KEY_HOLD_VALID_TIME)
						{
							key_down_count = 0;
							key_hold_flag = 1;
							key_mode = KEY_WAIT_UP_MODE;
						}
						else
						{
							key_mode = KEY_WAIT_MODE;
						}
					}
				}
				key_up_count=0;
				break;
			case KEY_WAIT_UP_MODE:
				for(i=0;i<4;i++)
				{
					ADC_Result_temp[i] = ad_convertion(KEY_PIN_ADDR[i]); // no sense convertion
					wait_us(5);
					ADC_Result_temp[i] = ad_convertion(KEY_PIN_ADDR[i]);

					if(ADC_Result_temp[i] < NO_KEY_VALUE_TH)
					{
						key_mode = KEY_WAIT_UP_MODE;
						key_up_count = 0;
					}
					else
					{
						key_up_count ++;
						if(key_up_count >50)
						{
							key_up_count = 0;
							key_mode = KEY_UP_MODE;
						}
					}
				}
				break;
			default:key_mode = KEY_UP_MODE;break;
		}				
	if(key_mode ==KEY_UP_MODE || key_mode == KEY_WAIT_UP_MODE)
	{					
		if(key_down_flag && (key_up_flag||key_hold_flag))
		{
			key_down_flag = 0;
			key_up_flag= 0;
			key_flag = 1;
			
			wake_up_time = NO_KEY_WAKUP_TIME;


			for(i=0;i<4;i++)
			{
				if(key_vlaue_array[i]>NO_KEY_VALUE_TH)
				{
					;
				}
				else if(key_vlaue_array[i]>0x300)
				{
					key_value = KEY_TABLE[i*4+3];
					i = 4;//exit the for loop
				}
				else if(key_vlaue_array[i]>0x200)
				{
					key_value = KEY_TABLE[i*4+2];
					i = 4;//exit the for loop
				}	
				else if(key_vlaue_array[i]>0x100)
				{
					key_value = KEY_TABLE[i*4+1];
					i = 4;//exit the for loop
				}	
				else
				{
					key_value = KEY_TABLE[i*4+0];
					i = 4;//exit the for loop
				}
			}
#ifdef ATS_EMBED_CODE
			if(key_flag ==1)
			{
				ats_key = key_value;
				ats_key_flag = 1;
			}
#endif//ATS_EMBED_CODE
			if(key_hold_flag)//handing the hold the key action
			{
				key_hold_flag=0;

				switch(key_value)
				{
					case ON_OFF_KEY://hold these buttons ,the effect as same as press
					case MODE_KEY:
                            break;
					case DAB_RESCAN_KEY:
                            key_value = DAB_RESCAN_HOLD_KEY;
                            break;
                    case HDSEEK_KEY:
                            key_value = HDSEEK_HOLD_KEY;
                            break;
					case BACK_LIGHT_KEY: //hold these buttons ,the effect as same as press
							break;
					case CLOCK_KEY:
							key_value = CLOCK_HOLD_KEY;	
							break;
					case ALARM_KEY:
							key_value = ALARM_HOLD_KEY;
							break;
					case PRESET_INC_KEY:
							key_value = PRESET_INC_HOLD_KEY;
							break;
					case PRESET_DEC_KEY:
							key_value = PRESET_DEC_HOLD_KEY;
							break;
					case SEEK_UP_KEY:
							key_value = SEEK_UP_HOLD_KEY;
							break;
					case SEEK_DOWN_KEY:
							key_value = SEEK_DOWN_HOLD_KEY;
							break;
					default:key_flag = 0;break;
				}
			}
			for(i=0;i<4;i++)
			{
				key_vlaue_array[i] = 0x03ff;
			}
		}
	}
	temp_knobs = VOLUME_CONFIRM^TUNING_CONFIRM;
	if(temp_knobs == 1)
	{
		if(knobs_press_flag ==1)
		{
			knobs_press_flag =0;
			if(VOLUME_CONFIRM == 0)
			{
				key_value = VOLUME_PRESS_KNOBS;
				key_flag = 1;
			}
			if(TUNING_CONFIRM == 0)
			{
				key_value = TUNE_PRESS_KNOBS;
				key_flag = 1;
			}
#ifdef ATS_EMBED_CODE
			if(key_flag ==1)
			{
				ats_key = key_value;
				ats_key_flag = 2;//1:keypad mode 2:encode mode
			}
#endif//ATS_EMBED_CODE
		}
	}
	else
	{
		knobs_count = 0;
	}	
}
#endif //#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
#endif //PLATFORM_F380_MODULE


#ifdef PLATFORM_F340_DEMOBOARD
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
/************************************************************************
timer1 interrupt as key scan clock 4ms
***********************************************************************/
code u8 key_table[3][4]={	{DOWN_KEY,SEEK_DOWN_KEY,PRESET_DEC_KEY,MODE_KEY},
							{SELECT_KEY,CLOCK_KEY,ALARM_KEY,MENU_KEY},
							{UP_KEY,SEEK_UP_KEY,PRESET_INC_KEY,ON_OFF_KEY},
						  };
void key_scan(void)
{
	u8 i,j;
	u8 temp_key;
		
	switch(key_mode)
	{
		case KEY_UP_MODE:
				KEY_R &= 0xF8;
				temp_key = KEY_C&0xF0;
				if(temp_key == 0xF0)
				{
					key_up_count++;
					if(key_up_count>KEY_STABLE_VALID_TIME)
					{
						key_up_count = 0;
						key_up_flag = 1;
					}
				}
				else
				{
					key_mode = KEY_DOWN_MODE;
					key_down_count = 0;
				}
			break;
		case KEY_DOWN_MODE:
				KEY_R &= 0xF8;
				temp_key = KEY_C&0xF0;
				if(temp_key != 0xF0)
				{
					key_down_count++;
					if(key_down_count>KEY_STABLE_VALID_TIME)
					{
						key_down_flag = 1;
						for(i=0;i<3;i++)
						{
							KEY_R &= 0xF8;
							KEY_R |=(~(1<<i))&0x0F;
							KEY_C |=0xF0;
							for(j=0;j<4;j++)
							{
								temp_key = (1<<j+4);
								if(!(KEY_C &temp_key))
								{
									key_value = key_table[i][j];
								}
							}
						}
						key_mode = KEY_WAIT_MODE;
					}
				}
				else
				{
					key_mode = KEY_UP_MODE;
					key_up_count = 0;
				}
			break;
		case KEY_WAIT_MODE:
				KEY_R &= 0xF8;
				temp_key = KEY_C&0xF0;
				if(temp_key != 0xF0)
				{
					//key_down_count++;
					if(key_down_count>KEY_HOLD_VALID_TIME)
					{
						key_hold_flag = 1;
						key_mode = KEY_WAIT_UP_MODE;
					}
				}
				else
				{
					key_mode = KEY_UP_MODE;
					key_up_count = 0;
				}
			break;
		case KEY_WAIT_UP_MODE:
			//	key_mode = KEY_UP_MODE;
				KEY_R &= 0xF8;
				temp_key = KEY_C&0xF0;
				if(temp_key != 0xF0)
				{
					key_mode = KEY_WAIT_UP_MODE;
					key_up_count = 0;
				}
				else
				{
					key_up_count ++;
					if(key_up_count >KEY_STABLE_VALID_TIME)
					{
						key_up_count = 0;
						key_mode = KEY_UP_MODE;
					}
				}

			break;
		default:key_mode = KEY_UP_MODE;break;
	}

	if(key_mode ==KEY_UP_MODE || key_mode == KEY_WAIT_UP_MODE)
	{					
		if(key_down_flag && (key_up_flag||key_hold_flag))
		{
			key_down_flag = 0;
			key_up_flag= 0;
			key_flag = 1;
		}
		if(key_hold_flag)
		{
			key_hold_flag=0;
			switch(key_value)
			{
				case ON_OFF_KEY://hold these buttons ,it still have affected.
				case MODE_KEY:
                        break;
				case DAB_RESCAN_KEY:
                        key_value = DAB_RESCAN_HOLD_KEY;
                        break;
                case HDSEEK_KEY:
                        key_value = HDSEEK_HOLD_KEY;
                        break;
				case CLOCK_KEY:
						key_value = CLOCK_HOLD_KEY;	
						break;
				case ALARM_KEY:
						key_value = ALARM_HOLD_KEY;
						break;
				case PRESET_INC_KEY:
						key_value = PRESET_INC_HOLD_KEY;
						break;
				case PRESET_DEC_KEY:
						key_value = PRESET_DEC_HOLD_KEY;
						break;
				case SEEK_UP_KEY:
						key_value = SEEK_UP_HOLD_KEY;
						break;
				case SEEK_DOWN_KEY:
						key_value = SEEK_DOWN_HOLD_KEY;
						break;
				default:key_flag = 0;break;
			}
		}
	}
	temp_knobs = VOLUME_CONFIRM^TUNING_CONFIRM;
	if(temp_knobs == 1)
	{
		if(knobs_press_flag ==1)
		{
			knobs_press_flag =0;
			if(VOLUME_CONFIRM == 0)
			{
				key_value = VOLUME_PRESS_KNOBS;
				key_flag = 1;
			}
			if(TUNING_CONFIRM == 0)
			{
				key_value = TUNE_PRESS_KNOBS;
				key_flag = 1;
			}
		}
	}
	else
	{
		knobs_count = 0;
	}
}
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
#endif //PLATFORM_F340_DEMOBOARD
