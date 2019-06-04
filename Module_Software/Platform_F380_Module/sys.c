/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   mcu initialization drivers for C8051F380 based module
   FILE: sys.c
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

#ifdef OPTION__OPERATE_AS_SLAVE_NO_MMI
	#define OPTION__UART_DRIVER
#endif

#ifdef ATS_EMBED_CODE
	#define OPTION__UART_DRIVER
#endif

#include "delay.h"
#include "sys.h"
#include "LCD.h"
#include "key.h"
#include "si468x_bus.h"
#include "main.h"
#include "uart.h"
#include "mode_common.h"


#ifdef PLATFORM_F340_DEMOBOARD
	#include "SST25VF032B.h"
#endif

#include "usb_descriptor.h"
#include "usb_register.h"
/*****************************************************************************\
Sysclk_Init()
Description: Initialize the system and USB clock.
Inputs: None
Outputs: None
\*****************************************************************************/
void Sysclk_Init(void)
{
	u16 i;
    // Configure internal oscillator for its maximum frequency and enable
    // missing clock detector
    // OSCICN |= 0x03;

    // Select internal oscillator as input to clock multiplier
    CLKMUL  = 0x00;

    CLKMUL |= 0x80;                           // Enable clock multiplier
    CLKMUL |= 0xC0;                           // Initialize the clock multiplier
    Delay();                                  // Delay for clock multiplier

    while(!(CLKMUL & 0x20));                  // Wait for multiplier to lock
    CLKSEL  = SYS_INT_OSC;                    // Select system clock

#ifdef OPTION__USB_DRIVER
    CLKSEL |= SYS_4X_DIV_2;                   // Select USB clock
#endif // OPTION__USB_DRIVER

//	CLKSEL |= 0x0a; 
    OSCICN |= 0x83;
	OSCLCN    &=~0x80;//disable internal low frequency
/*
    P0SKIP    = 0xCF;
    XBR0      = 0x08;
    XBR1      = 0x40;
*/
    // Timer 0 operates in mode 1 (16-bit counter/timer).
    // Note: Timer 0 is used in the function wait_us.

    // Timer 1 operates in mode 1 (16-bit counter/timer).
    // Note: Timer 1 is used for the function key scan.
    TMOD      = 0x01;  

    // Counter/Timer 0 uses the system clock.
	CKCON = 0x04;

    TCON  = 0x01;        
	TR0 = 0;                            // Disable Timer 0.
#ifdef PLATFORM_F380_MODULE

//*************************************************
//  OSCXCN    |= 0x61;//external crystal 32768Hz
//*************************************************
    //modified the XTAL parameters to lower the drive strength
    // as the original (datasheet recommended) setting seems to be overdriving the XTAL.
    // additional loading capacitance also works but that is more difficult as it is a BOM change.

    OSCXCN    |= 0x61;
//*************************************************

    for (i = 0; i < 3000; i++);  // Wait 1ms for initialization
//    while ((OSCXCN & 0x80) == 0);

//Timer5 for soft RTC timeKeeping

	//16 bit auto reroad count = 4096

#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
    SFRPAGE   = CONFIG_PAGE;
    TMR5CN    = 0x05;
    TMR5RLL   = 0xFF;
    TMR5RLH   = 0xEF;
    TMR5L     = 0xFF;
    TMR5H     = 0xEF;
    SFRPAGE   = LEGACY_PAGE;
    EIE2      |= 0x20;
#endif // OPTION__OPERATE_AS_SLAVE_NO_MMI
#endif //PLATFORM_F380_MODULE
}

#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
/******************************************************************
timer5 use external crystal 32768/8=4096 as timer source
so set the count to 4096 ,after timer5 overflow,1 second flag will be set
*********************************************************************/
#ifdef PLATFORM_F380_MODULE
void Timer5_isr() interrupt 20
{
	time_sec_flag = 1;
    SFRPAGE   = CONFIG_PAGE;
	TF5H = 0;
    SFRPAGE   = LEGACY_PAGE;
}
#endif //PLATFORM_F380_MODULE
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
/************************************************************************
timer3 use external crystal 32768/8=4096 as timer3 source 
1/32768/8 = 244us 244us*50 = 12.2ms ADC window conversion period
for ADC window detect for Button scan when in idle mode
**************************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
#ifdef PLATFORM_F380_MODULE
#ifndef NO_ALARM_HARDWARE_REMOVE_ALARM_CODE
void Timer3_Init_lowpower(void)
{
    TMR3CN    = 0x01;
    TMR3RLL   = 0xCD;
    TMR3RLH   = 0xFF;
    TMR3L     = 0xCD;
    TMR3H     = 0xFF;
	TMR3CN   |= 0x04;
    EIE1   &= ~0x80;
}
#endif //NO_ALARM_HARDWARE_REMOVE_ALARM_CODE

/*******************************************************************************
sysclk/12 = 2MHZ ~=500ns
********************************************************************************/
#define BUZZER_INTERVALU_COUNT_VALUE	500 //(0.1*60000)
#ifndef NO_ALARM_HARDWARE_REMOVE_ALARM_CODE
void Timer3_Init_buzzer(void)
{
    TMR3CN    = 0x04;
    TMR3RLL   = (65535-400);
    TMR3RLH   = (65535-400)>>8;
    TMR3L     = (65535-400);
    TMR3H     = (65535-400)>>8;

	EIE1      |= 0x80;

 	buzzer_on_flag = 1 ;
 	buzzer_interval_count = BUZZER_INTERVALU_COUNT_VALUE;
}
#endif //NO_ALARM_HARDWARE_REMOVE_ALARM_CODE
/**********************************************************************************
wave : __---__---__---_______interval ct1/2_____________---__---__--__________________
the wave frequency is 2K____
***********************************************************************************/
void Timer3_isr(void) interrupt INTERRUPT_TIMER3
{
	TMR3CN = 0x04;

	if(buzzer_interval_count >0)
	{	
		buzzer_interval_count --;
	}
	else
	{
		buzzer_on_flag ^=1;
		buzzer_interval_count = BUZZER_INTERVALU_COUNT_VALUE;
	}	
	if(buzzer_on_flag)
	{
		ALARM_BUZZER_PIN ^=1;
	}
	else
	{
		ALARM_BUZZER_PIN = 0;
	}
}
#endif //PLATFORM_F380_MODULE
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
/******************************************************************
*********************************************************************/
// Peripheral specific initialization functions,
// Called from the Init_Device() function
#ifdef OPTION__INCLUDE_POWER_SAVING_MODE
void Port_IO_lowpower_Init()
{

	P0 = 0x00;
	P0MDIN = 0X00;
	P0MDOUT = 0X00;

	P1 = 0x00;
	P1MDIN = 0x00;
	P1MDOUT = 0x00;

	P2 = 0x00;
	P2MDIN = 0x00;
	P2MDOUT = 0x00;

	P3 = 0x00;
	P3MDIN = 0x00;
	P3MDOUT = 0x00;


	P3 = 0x00;
	P3MDIN = 0x00;
	P3MDOUT = 0x00;


	P4 = 0x00;
	P4MDIN = 0x00;
	P4MDOUT = 0x00;

/*
	P4 = 0x00;
	P4MDIN = 0x00;
    P4MDOUT   = 0x18;
*/

    P0SKIP    = 0xFF;
    P1SKIP    = 0xFF;
    P2SKIP    = 0xFF;
    P3SKIP    = 0xFF;

	XBR0      = 0x10;//enable compratator
	XBR1	  = 0xc0 ;
	XBR2      = 0;

//   POLL_WRITE_BYTE(POWER,  0x08);   // Force Asynchronous USB Reset

//	REN0 = 0;//enable receive interrupt
//	ES0 = 0;                            // Enable UART0 interrupt
//CLKMUL = 0;

}
#endif
void Port_IO_Init()
{

#ifdef PLATFORM_F340_DEMOBOARD

/*
	P0 = 0XFF;
	P0MDIN	  = 0xFF;
    P0MDOUT   = 0x3d;
*/

	P0 = 0xFF;
	P0MDIN	  = 0xFF;
    P0MDOUT   = 0x3d;


	P1	= 0XFF;
	P1MDIN	  = 0xFF;
	P1MDOUT   = 0x00;

	P2	= 0xC0;	
	P2MDIN	  = 0xFF;
    P2MDOUT   = 0xDF;


    P0SKIP    = 0xFF;
    P1SKIP    = 0xFF;
    P2SKIP    = 0xFF;
    P3SKIP    = 0x01;

//    XBR0      = 0x02;
    XBR1      = 0x40;

#endif
#ifdef PLATFORM_F380_MODULE

    //TODO: Still needs to be verified for all features on Port0

 //   P0MDIN = 0x31;
 //   P0MDOUT = 0x31;
    //P0SKIP = 0xCF;


	P0MDIN = 0x34;
	P0MDOUT = 0x10;          	          // Enable Tx as push-pull output
	//P0MDOUT = 0xD0;
	P0 = 0xFF; 
 
	P0SKIP = 0xCF;//SKIP I/O for uart1

#ifdef PLATFORM_F380_MODULE_V1_2
    P1MDIN    = 0xDF;
	P1MDOUT   = 0xF7;
	P1	= 0xFF;
#endif

#ifdef PLATFORM_F380_MODULE_V1_4
    P1MDIN    = 0xDF;
	P1MDOUT   = 0xFD;
	P1	= 0xFF;
#endif

#ifdef PLATFORM_F380_MODULE_V2_0
    P1MDIN    = 0xFF;
	P1MDOUT   = 0xFD;
	P1	= 0xFF;
#endif
	P2MDIN    = 0xFF;
    P3MDIN    = 0xFF;
    P4MDIN    &=~ 0x1E;
	//P4MDIN = 0XFF;

    P2MDOUT   = 0xFF;
    P3MDOUT   = 0x3F;
    //P4MDOUT   = 0x1E;
	P4MDOUT = 0X00;
	P3 = 0xFF;
	P4 = 0xFF;

    P1SKIP    = 0xFF;
    P2SKIP    = 0xFF;
    P3SKIP    = 0xFF;

	XBR0      = 0x01;

#ifdef OPTION__MCU_HARDWARE_SPI
	XBR0 |= 0x02;
	P1SKIP &= ~0x0F;
#endif

    XBR1      = 0x40;
    XBR2      = 0x00;
#endif
}


/*****************************************************************************\
Usb0_Init()

Description: Initialize USB0, enable transceiver and USB0 interrupts.

Inputs: None

Outputs: None 

\*****************************************************************************/
#ifdef OPTION__USB_DRIVER

static void Usb0_Init(void)
{
   POLL_WRITE_BYTE(POWER,  0x08);   // Force Asynchronous USB Reset
   POLL_WRITE_BYTE(IN1IE,  0x01);   // Enable Endpoint 0 in interrupts
   POLL_WRITE_BYTE(OUT1IE, 0x00);   // Disable Endpoint interrupts

   // Enable SOF, Reset, and Suspend interrupt
   POLL_WRITE_BYTE(CMIE, rbSOFE | rbRSTINTE | rbSUSINTE);

   USB0XCN = 0xE0;                  // Enable transceiver; select full speed
   POLL_WRITE_BYTE(CLKREC, 0x80);   // Enable clock recovery, single-step mode
                                    // disabled

   EIE1 |= 0x02;                    // Enable USB0 Interrupts

                                    // Enable USB0 by clearing the USB Inhibit bit
   POLL_WRITE_BYTE(POWER,  0x01);   // and enable suspend detection
}
#endif //#ifdef OPTION__USB_DRIVER
/********************************************************************************
system init include port clock 
*********************************************************************************/
void Init_Device(void)
{
	if(power_flag == 1)
	{
		return;
	}

    PCA0MD &= ~0x40;                          // Disable Watchdog timer
    VDM0CN |= 0x80;                           // Enable the VDD Monitor

    IE = 0;

    Port_IO_Init();

    Sysclk_Init();                            // Initialize oscillator

// 	Select VDD Monitor as a Reset Source
    RSTSRC = 0x02;

	Timer2_init();
//	Timer3_Init_lowpower();// for ADC window detect

#ifdef OPTION__UART_DRIVER
	Timer1_init();//Baud Rate generator
	uart0_init();
	timer4_init();
#endif


#ifdef PLATFORM_F340_DEMOBOARD
	SST_Init();
#endif


#ifdef OPTION__USB_DRIVER
	Usb0_Init();
#endif //OPTION__USB_DRIVER

#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
	key_init();
	LCD_init();
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI

#ifdef OPTION__MCU_HARDWARE_SPI
	spi0_init();
#endif

#ifdef PLATFORM_F380_MODULE_V2_0
	SYS_ON = 1;
	MUTE = 0;
#endif

    EA = 1;                                   // Global Interrupt enable

}
