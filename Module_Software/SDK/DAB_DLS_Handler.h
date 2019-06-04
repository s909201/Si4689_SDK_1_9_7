/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   SDK DAB DLS decoder header
   FILE: DAB_DLS_Handler.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#ifndef __FMHD_DLS_HANDLER__
#define __FMHD_DLS_HANDLER__

#include "common_types.h"
#include "platform_options.h"
#include "feature_types.h"
#include "si46xx_firmware_api.h"

#ifdef OPTION__INCLUDE_MODE__DAB
#ifdef OPTION__DECODE_DLS
//-----------------------------------------------------------------------------
// Defines
//-----------------------------------------------------------------------------
typedef enum _DAB_DLS_PLUS_TAG_TYPE
{
    DL_PLUS_TITLE,
    DL_PLUS_NOT_IN_USE = 0xFF
}DAB_DLS_PLUS_TAG_TYPE;

//-----------------------------------------------------------------------------
// Globals
//-----------------------------------------------------------------------------
extern dab_dls_string dlsDisplay;   // Displayed dls for current program


//-----------------------------------------------------------------------------
// Function prototypes
//-----------------------------------------------------------------------------
void initDLS(void);
void updateDLS(get_digital_service_data__data dlsData);

#endif //OPTION__DECODE_DLS
#endif //OPTION__INCLUDE_MODE__DAB

#endif