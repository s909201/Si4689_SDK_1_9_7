/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   SDK HD radio alert decoder header
   FILE: FMHD_Alert_Handler.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#ifndef __FMHD_ALERT_HANDLER__
#define __FMHD_ALERT_HANDLER__

#include "common_types.h"
#include "platform_options.h"
#include "feature_types.h"
#include "si46xx_firmware_api.h"

#ifdef OPTION__INCLUDE_MODE__FMHD
#ifdef OPTION__DECODE_HD_ALERTS
//-----------------------------------------------------------------------------
// Defines
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
// Globals
//-----------------------------------------------------------------------------
extern fmhd_alert_string alertDisplay;   // Displayed Alert

//-----------------------------------------------------------------------------
// Function prototypes
//-----------------------------------------------------------------------------
void initAlerts(void);

void updateAlerts(fmhd_get_alert_message__data* alertData);

#endif //OPTION__DECODE_HD_ALERTS
#endif //OPTION__INCLUDE_MODE__FMHD

#endif