/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   hardware options for various revisions of C8051F380 based module
   FILE: platform_selector.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#ifndef __PLATFORM_SELECTOR__
#define __PLATFORM_SELECTOR__

//#define debug

//---------------------VERSION CONTROL---------------------
#define PLATFORM_F380_MODULE_V2_0
//#define PLATFORM_F380_MODULE_V1_4
//#define PLATFORM_F380_MODULE_V1_2

//TODO: Currently there is a bug with the Sysclk_Init() function for this platform
//#define PLATFORM_F340_DEMOBOARD

//----------------------------------------------------------

#ifdef PLATFORM_F380_MODULE_V1_2
	#define PLATFORM_F380_MODULE
	#define UPDATE_IMAGE_BY_TUNER
	#define OPTION__USB_DRIVER
    #define FRONT_END_BOOST
    #define SPI_BUS_MANUAL
    #define INTB_MANUAL
    #define NO_ALARM_HARDWARE_REMOVE_ALARM_CODE
#endif

#ifdef PLATFORM_F380_MODULE_V1_4
	#define PLATFORM_F380_MODULE
	#define UPDATE_IMAGE_BY_TUNER
    #define OPTION__USB_DRIVER
    #define FRONT_END_BOOST
    #define SPI_BUS_CORRECTED
    #define INTB_CORRECTED
    #define NO_ALARM_HARDWARE_REMOVE_ALARM_CODE
#endif

#ifdef PLATFORM_F380_MODULE_V2_0
	#define PLATFORM_F380_MODULE
	#define UPDATE_IMAGE_BY_TUNER
	#define OPTION__USB_DRIVER
 	#define FRONT_END_CLASSIC
    #define SPI_BUS_CORRECTED
    #define INTB_CORRECTED
    #define NO_ALARM_HARDWARE_REMOVE_ALARM_CODE
 	#define ATS_EMBED_CODE
	#define OPTION__UART_DRIVER
#endif

#ifdef PLATFORM_F340_DEMOBOARD
	#define UPDATE_IMAGE_BY_MCU
    #define OPTION__USB_DRIVER
    #define FRONT_END_CLASSIC
#endif




#endif
