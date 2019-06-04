/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   header for mcu initialization drivers for C8051F380 based module
   FILE: sys.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#ifndef _sys_h_
#define _sys_h_

#include "compiler_defs.h"
#include "typedefs.h"
#include <platform_options.h>

void Init_Device(void);
#define SYS_INT_OSC 0x00
#define SYS_4X_DIV_2 0x02
#define SYSCLK                   24000000    // SYSCLK frequency in Hz
void Timer3_Init_lowpower(void);
void Timer3_Init_buzzer(void);
void Port_IO_lowpower_Init(void);

#ifdef PLATFORM_F380_MODULE
#include "C8051F380_defs.h"

		/*****************************LCD ***********************/

		sbit LCD_DATA = P2;
		sbit LCD_EN = P3^0;
		sbit LCD_RW = P3^1;

		sbit LCD_RST = P3^2;
		//sbit LCD_CS = P3^3;

#ifdef PLATFORM_F380_MODULE_V2_0
		#define MUTE LCD_RST
#endif

		sbit LCD_RS = P3^4;
		sbit DISP_BKLIGHT = P3^5;


		/***********************************************************/

		/********************KEY************************************/


		#define T2HIGH  ((u8)((65535-4000)>>8))
		#define T2LOW   ((u8)(65535-4000))


#ifdef PLATFORM_F380_MODULE_V2_0


		sbit ALARM_BUZZER_PIN	 = P3^3;
		sbit VOLUME_B	= P3^6;
		sbit VOLUME_A	= P3^7;
		//sbit TUNING_CONFIRM = P4^0;
		#define VOLUME_CONFIRM !!(0x01&P4)

		//sbit VOLUME_A	= P4^5;
		//sbit VOLUME_B	= P4^6;
		//sbit VOLUME_CONFIRM = P4^7;
		//as because the address of P4 is out of SFR scale so can't use sbit 
		#define TUNING_A  !!(0x20&P4)
		#define TUNING_B  !!(0x40&P4)
		#define TUNING_CONFIRM  !!(0x80&P4)
		

//		#define DISP_BKLIGHT_OFF do{ P3 |=0X20;P3MDIN &=~0X20; P3MDOUT &=~0x20;P3 |= 0X20;}while(0)
//		#define DISP_BKLIGHT_ON  do{ P3MDIN |=0X20; P3MDOUT |=0x20; P3 |=0X20;}while(0)
#else

		/**************************knobs************************************/
		sbit TUNING_B	= P3^6;
		sbit TUNING_A	= P3^7;
		//sbit TUNING_CONFIRM = P4^0;
		#define TUNING_CONFIRM !!(0x01&P4)

		//sbit VOLUME_A	= P4^5;
		//sbit VOLUME_B	= P4^6;
		//sbit VOLUME_CONFIRM = P4^7;
		//as because the address of P4 is out of SFR scale so can't use sbit 
		#define VOLUME_A  !!(0x20&P4)
		#define VOLUME_B  !!(0x40&P4)
		#define VOLUME_CONFIRM  !!(0x80&P4)
		/********************************************************************/
#endif
		
		sbit BAT_DISP	= P0^2;
		sbit BAT_IN		= P0^3;
		sbit REM		= P0^1;


		sbit si468x_RST  = P1^4;

		sbit SYS_ON		= P1^5;

#ifdef SPI_BUS_MANUAL

#ifndef OPTION__MCU_HARDWARE_SPI
		sbit si468x_SSB  = P1^0;
		sbit si468x_SCLK = P1^1;
		sbit si468x_MOSI = P1^2;
		sbit si468x_MISO= P1^3;
#endif //OPTION__MCU_HARDWARE_SPI

#ifdef OPTION__MCU_HARDWARE_SPI
				sbit si468x_SSB  = P1^3;
			//#define si468x_SSB  NSSMD0
#endif //OPTION__MCU_HARDWARE_SPI

#endif//SPI_BUS_MANUAL


#ifdef SPI_BUS_CORRECTED
		sbit  si468x_SCLK = P1^0;
		sbit  si468x_MISO= P1^1;
		sbit si468x_MOSI = P1^2;
		sbit si468x_SSB = P1^3;
#endif //SPI_BUS_CORRECTED
		sbit si4680_INTB = P1^5;
		
#endif//PLATFORM_F380_MODULE



#ifdef PLATFORM_F340_DEMOBOARD
#include "C8051F340_defs.h"

		/*****************************LCD ***********************/
		sbit  SDA = P2^3;
		sbit  SCL = P2^4;
		sbit  DISP_RST = P0^4;
		sbit  DISP_BKLIGHT = P0^5;

		#define SDA_OUT	 P2MDOUT
		#define SDA_HEX	 0x08
		/***********************************************************/

		/********************KEY************************************/
		#define KEY_R	P2
		#define KEY_C	P1

		#define T1HIGH  ((u8)(65535-4000)>>8)
		#define T1LOW   ((u8)(65535-4000))


		/**************************knobs************************************/
		sbit TUNING_A	= P0^6;
		sbit TUNING_B	= P0^7;
		sbit TUNING_CONFIRM = P1^0;

		sbit VOLUME_B	= P1^1;
		sbit VOLUME_A	= P1^2;
		sbit VOLUME_CONFIRM = P1^3;
		/********************************************************************/


		/********************flash SPI bus *********************************************/
		sbit SST_CE  = P0^3;
		sbit SST_OUT = P0^2;
		sbit SST_IN  = P0^1;
		sbit SST_CLK = P0^0;


		/***************************************************************************************/
		sbit si468x_RST  = P2^6;
        sbit AUDIO_SHUTDOWN = P2^7;
#endif

#endif
