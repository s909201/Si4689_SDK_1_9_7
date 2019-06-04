/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   SDK RDS decoder header
   FILE: RDS_Handler.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#ifndef __RDS_HANDLER__
#define __RDS_HANDLER__

#include "common_types.h"
#include "platform_options.h"
#include "feature_types.h"
#include "si46xx_firmware_api.h"

//TODO: add AF support if desired
#ifdef OPTION__INCLUDE_MODE__FM

    #ifdef OPTION__RDS_BUFFER_V4L2
    // TODO: add V4L2 implementation of RDS buffers
    #else
    //-----------------------------------------------------------------------------
    // Defines
    //-----------------------------------------------------------------------------

    //-----------------------------------------------------------------------------
    // Globals
    //-----------------------------------------------------------------------------
    extern uint8_t   rtDisplay[RDS_RADIO_TEXT_BUFFER_SIZE];   // Displayed Radio Text
    extern uint8_t   psDisplay[RDS_PROGRAM_SERVICE_BUFFER_SIZE];    // Displayed Program Service text
    extern uint16_t  piDisplay;              // Displayed Program Identifier
    extern uint8_t   ptyDisplay;             // Displayed Program Type

#ifdef OPTION__RADIODNS
	extern uint8_t eccDisplay;               //ECC, a necessary component of the RADIODNS address
#endif

    extern rds_time currentTime;            // Calculated time from the RDS stream

    //-----------------------------------------------------------------------------
    // Function prototypes
    //-----------------------------------------------------------------------------
    void initRDS(void); // Call after each Tune to clear the variables

#ifndef OPTION__REMOVE_SDK_FUNCTIONS_NOT_USED_BY_MMI
    void ignoreAB(uint8_t ignore); // Some regions have poor AB usage and it should be ignored (default)
#endif //OPTION__REMOVE_SDK_FUNCTIONS_NOT_USED_BY_MMI

    void updateRDS(fm_rds_status__data rdsData); // Call after new RDS data is received
    #endif


#endif //OPTION__INCLUDE_MODE__FM
#endif //__RDS_HANDLER__
