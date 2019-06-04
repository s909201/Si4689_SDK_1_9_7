/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   SDK HD radio service list handler header - for determining the details of what audio services are available on a given channel
   FILE: FMHD_Service_List_Handler.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#ifndef __FMHD_SERVICE_LIST_HANDLER__
#define __FMHD_SERVICE_LIST_HANDLER__

#include "common_types.h"
#include "platform_options.h"
#include "feature_types.h"
#include "si46xx_firmware_api.h"

#ifdef OPTION__INCLUDE_MODE__FMHD
#ifdef OPTION__DECODE_FMHD_SERVICE_LIST
//-----------------------------------------------------------------------------
// Defines
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
// Globals
//-----------------------------------------------------------------------------
extern fmhd_service_list_fast svcListFast; // The first service list available before the main list is complete
extern fmhd_service_list svcListFull_Audio;   // Displayed Audio Service List for current frequency


//-----------------------------------------------------------------------------
// Function prototypes
//-----------------------------------------------------------------------------

void initHD_ServiceList(void);
void updateFMHD_ServiceList_Audio(get_digital_service_list__data* fmhdList, uint16_t listVer);
//void updateFMHD_ServiceList_Data(get_digital_service_list__data* fmhdList, uint16_t listVer);


#endif //OPTION__DECODE_FMHD_SERVICE_LIST
#endif //OPTION__INCLUDE_MODE__FMHD
#endif