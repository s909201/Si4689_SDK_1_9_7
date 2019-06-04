/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   uart driver for C8051F380 based module
   FILE: uart.c
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

#include "Firmware_API_Manager.h"
#include "si46xx_firmware_api.h"
#include "DAB_Service_List_Handler.h"
#include "sys.h"
#include "key.h"
#include "main.h"
#include "delay.h"
#include "mode_common.h"
#include "uart.h"
#include "LCD.h"
#include "mode_fmhd_amhd.h"
#include "mode_fm_am.h"
/******************************************************************
the communication between the PC software and module
9600 rate 8,N,1
*********************************************************************/
#ifdef OPTION__UART_DRIVER
void uart0_init(void)
{
	S0MODE = 0;//8bit with variable Baud Rate
	REN0 = 1;//enable receive interrupt
	ES0 = 1;                            // Enable UART0 interrupt
}
#endif
#ifdef OPTION__UART_DRIVER
void Timer1_init(void)
{
    TCON      |= 0x40;
    TMOD      |= 0x20;
    TH1       = 0x98;
	TL1 = TH1;
	TR1 = 1;
}
#endif
/**********************************************************
clock = sysclk/12 = 2Mhz
Timer  = 65535 - 6000 = 3ms interval
***********************************************************/
#ifdef OPTION__UART_DRIVER
#define TIMER4_LOW_INIT_VALUE	0x8F
#define TIMER4_HIGH_INIT_VALUE	0xE8
void timer4_init(void)
{
    SFRPAGE   = CONFIG_PAGE;
    TMR4CN    = 0x04;
    TMR4RLL   = TIMER4_LOW_INIT_VALUE;
    TMR4RLH   = TIMER4_HIGH_INIT_VALUE;
    TMR4L     = TIMER4_LOW_INIT_VALUE;
    TMR4H     = TIMER4_HIGH_INIT_VALUE;
    SFRPAGE   = LEGACY_PAGE;
    EIE2  |= 0x10;
}
#endif
/**********************************************************

***********************************************************/
#ifdef OPTION__UART_DRIVER
u8 check_sum(u8* buf,u8 len)
{
	u8 sum;
	u8 i;
	sum = 0;
	for(i=0;i<len;i++)
	{
		sum +=(u8)buf[i];
	}
	return sum;
}
#endif
/**********************************************************

***********************************************************/	
#ifdef OPTION__UART_DRIVER
void uart0_send(u8* buf,u8 len)
{
	u8 i=0;
	while(len--)
	{
		while (uart0_tx_flag);         // wait until uart0 is ready to transmit
		uart0_tx_flag = 1;
		SBUF0 = buf[i++];              // output <c> using UART 

	}		
}
#endif
/**********************************************************

***********************************************************/
#ifdef OPTION__UART_DRIVER
void ats_send_cmd(u8* buf,u8 len)
{
	u8 cmd[32];
	u8 index;
	u8 i;

	index= 0;
	cmd[index++] = 'S';
	cmd[index++] = 'L';
	cmd[index++] = 'B';
	cmd[index++] = len+1;//cm+arg0+arg1...+checksume

	for(i=0;i<len;i++)
	{
		cmd[index++]=buf[i];
	}

	cmd[index++]=check_sum(cmd+3,index-3);

	uart0_send(cmd,index);
}
#endif
/**********************************************************

***********************************************************/
#ifdef OPTION__UART_DRIVER
#define TF4H 	0x80
void timer4_int(void) interrupt INTERRUPT_TIMER4
{
    SFRPAGE   = CONFIG_PAGE;
	TMR4CN &= ~TF4H;//clear the Timer4 overflow flag;
	TMR4CN    &= ~0x04;//TR4 = 0;//one receive action is compelet
    SFRPAGE   = LEGACY_PAGE;
	if(uart0_rx_start_flag)
	{
		uart0_rx_start_flag = 0;
		uart0_rx_flag = 1;//the delay is timeup ,setup the receive flag
	}

}
#endif
/**********************************************************

***********************************************************/
#ifdef OPTION__UART_DRIVER
void uart0_int(void) interrupt INTERRUPT_UART0
{
	if(RI0)//
	{
		RI0 = 0;
		if(uart0_rx_start_flag==0)
		{
			uart0_rx_start_flag =1;
			uart0_rx_num = 0;
			uart0_rx_flag = 0;//the delay is timeup ,setup the receive flag
    		SFRPAGE   = CONFIG_PAGE;
			TMR4CN    = 0x04;//start to wait for receiving finish
    		SFRPAGE   = LEGACY_PAGE;

		}
		else
		{
    		SFRPAGE   = CONFIG_PAGE;
			TMR4CN    &= ~0x04;;
		    TMR4L     = TIMER4_LOW_INIT_VALUE;
		    TMR4H     = TIMER4_HIGH_INIT_VALUE;
			TMR4CN    = 0x04;
    		SFRPAGE   = LEGACY_PAGE;
		}			
		uart0_rx_buf[uart0_rx_num++] = SBUF0;
	}
	if(TI0)
	{
		TI0 =0;
		uart0_tx_flag = 0;
	}
}
#endif
/**********************************************************

***********************************************************/
#ifdef ATS_EMBED_CODE
code u32 DAB_FREQ_TABLE[] ={
				0x2AB50,// 0
				0x2B200,// 1
				0x2B8B0,// 2
				0x2BF60,// 3
				0x2C6B0,// 4
				0x2CD60,// 5
				0x2D410,// 6
				0x2DAC0,// 7
				0x2E200,// 8
				0x2E8B0,// 9
				0x2EF60,//10
				0x2F610,//11
				0x2FD60,//12
				0x30410,//13
				0x30AC0,//14
				0x31170,//15
				0x318B0,//16
				0x31F60,//17
				0x32610,//18
				0x32CC0,//19
				0x33410,//20
				0x334B0,//21
				0x33AC0,//22
				0x34170,//23
				0x34820,//24
				0x34F60,//25
				0x35000,//26
				0x35610,//27
				0x35CC0,//28
				0x36370,//29
				0x36AC0,//30
				0x36B60,//31
				0x37170,//32
				0x37820,//33
				0x37ED0,//34
				0x38580,//35
				0x38C30,//36
				0x392E0,//37
				0x39900,//38
				0x39FB0,//39
				0x3A660,//40
};
/**********************************************************
for ATS DAB manual tune frequency 
***********************************************************/
#ifdef OPTION__INCLUDE_MODE__DAB
u8 freq_to_dab_index(u32 freq)
{
	u8 i;
	for(i=0;i<41;i++)
	{
		if(freq == DAB_FREQ_TABLE[i])
		{
			return i;
		}
	}
	return 0xFF;
}  
#endif
/**********************************************************

***********************************************************/
#ifdef OPTION__UART_DRIVER
#define uart0_RX_CMD 	uart0_rx_buf[4]
void ats_cmd_process(void)
{
	u8 xdata uart0_tx_num;
	u32 xdata freq_temp;
    u32 xdata  err,tot;
    u8 xdata berPass;
#ifdef OPTION__INCLUDE_MODE__DAB
    dab_service_list_element tempListElement;
	u32 xdata dab_ber;
	u8 xdata freq_index;			
#endif //OPTION_INCLUDE_MODE_DAB
#ifdef OPTION__INCLUDE_MODE__FMHD
	uint32_t hd_ber;
#endif //OPTION__INCLUDE_MODE__FMHD
	uart0_tx_num = 0;
	if(uart0_rx_flag)
	{
		if((uart0_rx_buf[uart0_rx_num-1]==check_sum(uart0_rx_buf+3,uart0_rx_num-3-1))
			&&(uart0_rx_buf[0]=='A'
			&&uart0_rx_buf[1]=='T'
			&&uart0_rx_buf[2]=='S'))//1:remove the checksum byte 
		{
			uart0_rx_flag = 0;
			ats_keypad_test_flag = 0;
			ats_encode_test_flag = 0;
			if(ats_test_enable_flag==0 && uart0_RX_CMD !=CMD_START_ATS_TEST)
			{
				return;//ATS is in exit mode and will not response all ATS command, except start ats command
			}
			//LCD_Clear(LCD_CLEAR_LINE1);//Clear LCD for displaying the ATS test command

			switch(uart0_RX_CMD)
			{
				case CMD_SET_IO_LEVEL://4154530400010005
					if(uart0_rx_buf[5]==0x00)
					{
						SYS_ON = uart0_rx_buf[6];
					}
					else if(uart0_rx_buf[5]==0x01)
					{
						MUTE = uart0_rx_buf[6];
					}
					else
					{
						DISP_BKLIGHT = uart0_rx_buf[6];
					}
					uart0_tx_buf[0] = RSP_SET_IO_LEVEL;
					uart0_tx_buf[1] = 00;//ACKNOWLEDGE
					uart0_tx_num = 2;
					break;
				case CMD_GET_IO_STATUS://41545303010105
					uart0_tx_buf[0] = RSP_GET_IO_STATUS;
					uart0_tx_buf[1] = uart0_rx_buf[5];
					if(uart0_rx_buf[5]==0x00)
					{
						P0MDIN |=0x08;//make P0.3(BAT_IN)to input mode
						uart0_tx_buf[2] = BAT_IN;//AD pin
						P0MDIN &=~0x08;//make P0.3(BAT_IN)to input mode
					}
					else
					{
						uart0_tx_buf[2] = BAT_DISP;
					}
					uart0_tx_num = 3;
					break;
				case CMD_ENTER_ENCODE_TEST_MODE://41545303020005
					ats_encode_test_flag = 1;
					uart0_tx_buf[0] = RSP_ENTER_ENCODE_TEST_MODE;
					uart0_tx_buf[1] = CMD_ACK;
					uart0_tx_buf[2] = ATS_NO_KEY;
					uart0_tx_num = 3;
					break;
				case CMD_ENTER_KEYPAD_TEST_MODE:
					ats_keypad_test_flag = 1;
					uart0_tx_buf[0] = RSP_ENTER_KEYPAD_TEST_MODE;
					uart0_tx_buf[1] = CMD_ACK;
					uart0_tx_buf[2] = ATS_NO_KEY;
					uart0_tx_num = 3;
					break;

				case CMD_GET_RDS_VALID://415453030E0011
					uart0_tx_buf[0] = RSP_GET_RDS_VALID;
					uart0_tx_buf[1] = ~ATS_RDS_valid_flag;//valid = 0; invalid = 1
					uart0_tx_num = 2;	
					break;				
				case CMD_MODE_SWITCH://41545303040007
					uart0_tx_buf[0] = RSP_MODE_SWITCH;
					if(ats_mode_switch_flag==0)
					{
						ats_mode_switch_flag = 1;
						work_mode = fmonly;
						uart0_tx_buf[1] = 0x00;
					}
					else
					{
						ats_mode_switch_flag  = 0;
#ifdef OPTION__INCLUDE_MODE__FMHD
						work_mode =fmhd;
						uart0_tx_buf[1] = 0x01;
#endif //OPTION__INCLUDE_MODE__FMHD
#ifdef OPTION__INCLUDE_MODE__DAB
						work_mode = dab;
						uart0_tx_buf[1] = 0x02;
#endif//OPTION__INCLUDE_MODE__DAB
					}
					uart0_tx_num = 2;
					pfunc = BANDSWITCH;
					display_delay_4ms = 1;

					break;
				case CMD_TUNE_FREQ://41 54 53 07 05 34 7f 01 00 c0(test command 98100)
//#ifdef OPTION__INCLUDE_MODE__FM    17F34
					if(power_flag == 0 )
					{
#ifdef OPTION__INCLUDE_MODE__FM
						if(work_mode == fmonly)
						{
							power_flag = 1;
							fm_am_initialize();

						}
#ifdef OPTION__INCLUDE_MODE__FMHD
						else if(work_mode == fmhd)
						{
							power_flag = 1;
							fmhd_amhd_initialize();
						}
#endif//OPTION__INCLUDE_MODE__FMHD
						else
						{
							break;
						}
#endif
							
					}
					freq_temp = (u32)uart0_rx_buf[8]<<24
									|(u32)uart0_rx_buf[7]<<16
									|(u32)uart0_rx_buf[6]<<8
									|(u32)uart0_rx_buf[5];
#ifdef OPTION__INCLUDE_MODE__FM
					if(work_mode == fmonly)
					{
						fm_freq=freq_temp/10;//the data is using 1khz as unit /10khz
						Tune(fm_freq);

					}
#endif //OPTION__INCLUDE_MODE__FM
#ifdef OPTION__INCLUDE_MODE__FMHD
					if(work_mode == fmhd)
					{
						fmhd_freq=freq_temp/10;//10khz
						Tune(fmhd_freq);
					}
#endif //OPTION__INCLUDE_MODE__FMHD
					uart0_tx_buf[0]=RSP_TUNE_FREQ;
					uart0_tx_buf[1] = 00;
					uart0_tx_num = 2;

					break;
#ifdef OPTION__INCLUDE_MODE__FMHD				
				case CMD_START_HD_BER:

					#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
						LCD_Clear(LCD_CLEAR_ALL);
						LCD_DisplayStr("BER Test...\n",0,0);
					#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
					// BER Measurement and check for pass
	                //***************************
	                Test_GetBER_FMHD(&err,&tot,&berPass); // We expect ABER_NullPattern_test1.eti which uses 0xFF for the pattern

					#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
	                	LCD_Clear(LCD_CLEAR_ALL);
						LCD_DisplayNum(err,0,0);
					#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI

					hd_ber = err*100/tot;
					uart0_tx_buf[0] = RSP_START_HD_BER;
					uart0_tx_buf[1] = (u8)hd_ber;
					uart0_tx_num = 2;
					display_refresh_flag = 1;//refreash the LCD GUI
					display_item_str_4ms =200;
					break;
#endif //OPTION_INCLUDE_MODE_FMHD
#ifdef OPTION__INCLUDE_MODE__DAB					
				case CMD_GET_SERVICE_ID_DAB://4154530307000a
					uart0_tx_buf[0] = RSP_GET_SERVICE_ID_DAB;
					uart0_tx_buf[1] = DABServiceListAudioPtr()->SERVICE_COUNT;
					uart0_tx_num = 2;

					break;
				case CMD_TUNE_DAB_ID://4154530308010c
					if(uart0_rx_buf[5]>=DABServiceListAudioPtr()->SERVICE_COUNT)
					{
						uart0_tx_buf[0] = RSP_TUNE_DAB_ID;
						uart0_tx_buf[1] = 0x01;
					}
					else
					{
						getServiceListElement(DABServiceListAudioPtr()->SERVICE_OFFSETS[uart0_rx_buf[5]], 
													&tempListElement);
						#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
							LCD_Clear(LCD_CLEAR_LINE1);
							LCD_DisplayStr("Tuning....\n",0,0);
						#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
						ManualTune_DAB(tempListElement.FREQUENCY_INDEX); // izt on 2

	                	StartProcessingChannel(SERVICE_TYPE_DAB_AUDIO,
						 						tempListElement.SERVICE_ID,
												tempListElement.COMPONENT_ID, 0);
												
						uart0_tx_buf[0] = RSP_TUNE_DAB_ID;
						uart0_tx_buf[1] = 0x00;//ack
						display_refresh_flag = 1;//refreash the LCD GUI
						display_item_str_4ms =200;
					}
					uart0_tx_num = 2;
					break;
#endif //OPTION_INCLUDE_MODE_DAB					
				case CMD_GET_MODE://415453030C000F
						 uart0_tx_buf[0] = RSP_GET_MODE;
						 if(work_mode == fmonly){
							 uart0_tx_buf[1] = 00;
						}else if(work_mode == fmhd){
							uart0_tx_buf[1] = 0x01;
						}else {
							uart0_tx_buf[1] = 0x02;
						}
					uart0_tx_num = 2;
					break;
#ifdef OPTION__INCLUDE_MODE__DAB
				case CMD_START_DAB_BER:
					#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
                    LCD_Clear(LCD_CLEAR_ALL);
				    LCD_DisplayStr("BER Test\n",0,0);					// BER Measurement and check for pass
					#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
	                //***************************
                    #ifdef OPTION__INCLUDE_FRONT_END_TEST_FUNCTIONS
	                    Test_GetBER_DAB(0xFF, &err,&tot, &berPass); // We expect ABER_NullPattern_test1.eti which uses 0xFF for the pattern
                    #endif //OPTION__INCLUDE_FRONT_END_TEST_FUNCTIONS

					#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
	                LCD_Clear(LCD_CLEAR_ALL);
					LCD_DisplayNum(err,0,0);
					#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI

				    //TODO: this is not the proper calculation - why not rely on the pass/fail indication or pass the raw values up to the host?
					dab_ber = err*100/tot;
					uart0_tx_buf[0] = RSP_START_DAB_BER;
					uart0_tx_buf[1] = (u8)dab_ber;
					uart0_tx_num = 2;
					display_refresh_flag = 1;//refreash the LCD GUI
					display_item_str_4ms =200;
					break;
				case CMD_GET_SIGNAL_ERR://415453030d0010
					uart0_tx_buf[0] = RSP_GET_SIGNAL_ERR;
					UpdateMetrics();
			        if((MetricsGetDABPtr()->CNR < 16) && (MetricsGetDABPtr()->CNR > 6)) // "close to error range"
			        {
			            // convert to 0-10 within this range, where 0 is best
						uart0_tx_buf[1] = (u8)(10 - ((MetricsGetDABPtr()->CNR - 6)));
			        }
					else if(MetricsGetDABPtr()->CNR <= 6)
			        {
			            uart0_tx_buf[1] =10; // convert to 10 for in error
			        }
					else
			        {
			            uart0_tx_buf[1] =0; // convert to 0 for well above error threshold
			        }	
					uart0_tx_num = 2;								
					break;	
				case CMD_TUNE_DAB_FREQ://415453070F70410300CA
					uart0_tx_buf[0] = RSP_DAB_TUNE_FREQ;
					uart0_tx_buf[1] = CMD_ACK;
					uart0_tx_num = 2;
					freq_temp = (u32)uart0_rx_buf[8]<<24
									|(u32)uart0_rx_buf[7]<<16
									|(u32)uart0_rx_buf[6]<<8
									|(u32)uart0_rx_buf[5];
					freq_index = freq_to_dab_index(freq_temp);
					if(freq_index == 0xff)
					{
						uart0_tx_buf[1] = CMD_NACK;						
					}
					else
					{
						#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
						LCD_Clear(LCD_CLEAR_LINE1);
						LCD_DisplayStr("Tuning....\n",0,0);
						#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI

						//initDAB_ServiceList(); // Clear the service list
	    				ManualTune_DAB(freq_index); // izt on 2
	    				//BrowseServicesStartCurrentSelection_DAB();	
					}				
					break;
	#endif // OPTION__INCLUDE_MODE__DAB
				case CMD_EXIT_ATS_TEST://415453030a000d
					ats_test_enable_flag = 0;
					uart0_tx_buf[0] = RSP_EXIT_ATS_TEST;
					uart0_tx_buf[1] = 00;
					uart0_tx_num = 2;
					ATS_test_uk_freq_flag = 0;//force the dab scan full frequency list
					break;
				case CMD_START_ATS_TEST://415453030b000e
					ats_test_enable_flag = 1;
					uart0_tx_buf[0] = RSP_START_ATS_TEST;
					uart0_tx_buf[1] = CMD_ACK;
					uart0_tx_num = 2;
					ATS_test_uk_freq_flag = 1;//force the dab scan uk frequency list
					break;
				case CMD_SHIP_ATS_INTERFACE://for internal
					ship_ats_inter_flag = ATS_SHIP_SETTING;
					break;
				default:break;
			}
		}
	}
	if(ats_keypad_test_flag)
	{
		if(ats_key_flag==1)
		{
			uart0_tx_buf[0] = RSP_ENTER_KEYPAD_TEST_MODE;
			uart0_tx_buf[1] = 0;//ack
			switch(ats_key)
			{
				case UP_KEY:		uart0_tx_buf[2] = ATS_UP_KEY;
						break;					
				case SELECT_KEY:	uart0_tx_buf[2] = ATS_SELECT_KEY;
						break;		
				case DOWN_KEY:		uart0_tx_buf[2] = ATS_DOWN_KEY;
						break;		
				case BACK_LIGHT_KEY:uart0_tx_buf[2] = ATS_BKL_TOG_KEY;
						break;			
				case SEEK_UP_KEY:	uart0_tx_buf[2] = ATS_SK_UP_KEY;
						break;		
				case CLOCK_KEY:		uart0_tx_buf[2] = ATS_CLOCK_KEY;
						break;		
				case SEEK_DOWN_KEY:	uart0_tx_buf[2] = ATS_SK_DOWN_KEY;
						break;	
				case HDSEEK_KEY:	uart0_tx_buf[2] = ATS_HD_SEEK_KEY;
						break;		
				case PRESET_INC_KEY:uart0_tx_buf[2] = ATS_PERSET_INC_KEY;
						break;	
				case ALARM_KEY:		uart0_tx_buf[2] = ATS_ALARM_KEY;
						break;		
				case PRESET_DEC_KEY:uart0_tx_buf[2] = ATS_PERSET_DEC_KEY;
						break;	
				case DAB_RESCAN_KEY:uart0_tx_buf[2] = ATS_DAB_RESCAN_KEY;
						break;	
				case MODE_KEY:		uart0_tx_buf[2] = ATS_MODE_KEY;
						break;		
				case MENU_KEY:		uart0_tx_buf[2] = ATS_MENU_KEY;
						break;		
				case ON_OFF_KEY:	uart0_tx_buf[2] = ATS_ON_OFF_KEY;
						break;		
				case SNOOZE_KEY:	uart0_tx_buf[2] = ATS_SNOOZE_KEY;
						break;
				default:			uart0_tx_buf[2] = ATS_NO_KEY;
						break;
			}	
			uart0_tx_num = 3;
			ats_key_flag = 0;//clear
		}
	}
	else if(ats_encode_test_flag)
	{
		if(ats_key_flag==2)
		{
			uart0_tx_buf[0] = RSP_ENTER_ENCODE_TEST_MODE;
			uart0_tx_buf[1] = 0;//ack
			switch(ats_key)
			{
				case TUNE_INC_KNOBS:	uart0_tx_buf[2] = ATS_EN_TUNE_UP_KEY;
						break;					
				case TUNE_DEC_KNOBS:	uart0_tx_buf[2] = ATS_EN_TUNE_DOWN_KEY;
						break;		
				case TUNE_PRESS_KNOBS:	uart0_tx_buf[2] = ATS_EN_TUNE_SELECT_KEY;
						break;		
				case VOLUME_INC_KNOBS:	uart0_tx_buf[2] = ATS_EN_VOLUME_UP_KEY;
						break;			
				case VOLUME_DEC_KNOBS:	uart0_tx_buf[2] = ATS_EN_VOLUME_DOWN_KEY;
						break;		
				case VOLUME_PRESS_KNOBS:uart0_tx_buf[2] = ATS_EN_VOLUME_SELECT_KEY;
						break;		
				default:uart0_tx_buf[2] = ATS_NO_KEY;
						break;
			}	
			uart0_tx_num = 3;
			ats_key_flag = 0;//clear
		}
	}		
//	uart0_tx_buf[0] = RSP_ENTER_KEYPAD_TEST_MODE;
//	uart0_tx_buf[1] = 0;//ack				 
	if(uart0_tx_num >0)
	{
		ats_send_cmd(uart0_tx_buf,uart0_tx_num);
		uart0_tx_num = 0;
	}
}
#endif //OPTION__UART_DRIVER
#endif //ATS_EMBED_CODE
