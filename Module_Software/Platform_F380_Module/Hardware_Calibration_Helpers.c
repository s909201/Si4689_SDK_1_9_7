/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   front end calibration driver for C8051F380 based module
   FILE: Hardware_Calibration_Helpers.c
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#include "common_types.h"
#include "platform_options.h"

#ifdef OPTION__MCU_PLATFORM

#ifdef PLATFORM_F380_MODULE
#define XTALFREQ 19200000
#endif
#ifdef PLATFORM_F340_DEMOBOARD
#define XTALFREQ 6000000
//s#define XTALFREQ 19200000
#endif

#define CLKMODE 1
#define TRSIZE 0x07
#define IBIAS 0x28
//#define XTALFREQ - see definition above

//#define CTUN 0x00   // the value for the module v2.1 with 18pf loading caps
#define CTUN 0x07   // the value for the module v2.2 with 8pf loading cap value

#define IBIASRUN 0x18
RETURN_CODE calibrationGetPowerUpArgs(uint8_t *ctsien, uint8_t *clk_mode, uint8_t *tr_size, uint8_t *ibias, uint32_t *xtal_freq, uint8_t *ctun, uint8_t *ibias_run)
{
    *ctsien = 0;
    *clk_mode = CLKMODE;
    *tr_size = TRSIZE;
    *ibias = IBIAS;
    *xtal_freq = XTALFREQ;
    *ctun = CTUN;
    *ibias_run = IBIASRUN;
    return SUCCESS;
}

#ifdef FRONT_END_CLASSIC
    #define FMHD_SLOPE 0 // still forcing ANTCAP to 1
    #define FMHD_INT 0 // still forcing ANTCAP to 1
    #define FMHD_CONFIG 0
    #define DAB_SLOPE 0xF780 // Updated to match radiated emissions reducing front end
    #define DAB_INT 0x01C0 // Updated to match radiated emissions reducing front end
    #define DAB_CONFIG 1
#endif
#ifdef FRONT_END_BOOST
    #define FMHD_SLOPE 0
    #define FMHD_INT 0
    #define FMHD_CONFIG 1
    #define DAB_SLOPE 0xFD12
    #define DAB_INT 0x009B
    #define DAB_CONFIG 0

   // #define DAB_SLOPE 0xFCA7
   // #define DAB_INT 0xF6

#endif

#ifdef OPTION__INCLUDE_MODE__ANY
RETURN_CODE calibrationGetFrontEndArgs(uint8_t mode, uint16_t *slope, uint16_t *intercept, uint8_t *switchConfig)
{
    switch(mode)
    {
		case fmonly:
		case fmhd:
				*slope = FMHD_SLOPE;
                *intercept = FMHD_INT;
                *switchConfig = FMHD_CONFIG;
			break;
		case dab:
		case dmb:
				*slope = DAB_SLOPE;
                *intercept = DAB_INT;
                *switchConfig = DAB_CONFIG;
			break;
		case am:
		case amhd:
			break;
		default:
			return INVALID_INPUT;
			break;

    }
    return SUCCESS;
}
#endif
#endif