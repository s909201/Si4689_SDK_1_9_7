/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   SDK DAB service list decoder header - decodes the available services and adds them to the overall service database
   FILE: DAB_Service_List_Handler.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#ifndef __DAB_SERVICE_LIST_HANDLER__
#define __DAB_SERVICE_LIST_HANDLER__

#include "common_types.h"
#include "platform_options.h"
#include "feature_types.h"
#include "si46xx_firmware_api.h"

#ifdef OPTION__INCLUDE_MODE__DAB
#ifdef OPTION__DECODE_DAB_SERVICE_LIST
//-----------------------------------------------------------------------------
// Defines
//-----------------------------------------------------------------------------
//Note: this needs to change if we ever change the format for DAB list storage so the persistant storage read will know to ignore anything which is of an older version.
#define DAB_SERVICE_LIST_OBJECT_VERSION 1

#define DAB_LIST_VERSION_UNKNOWN 0xFFFF

//-----------------------------------------------------------------------------
// Globals
//-----------------------------------------------------------------------------
extern dab_service_list svcListDAB;

extern uint8_t DAB_service_list_updated_for_current_freq;

extern uint16_t _currentListVersion;
extern uint16_t _current_service_list_buffer_end_as_offset;

//-----------------------------------------------------------------------------
// Function prototypes
//-----------------------------------------------------------------------------

void initDAB_ServiceList(void);
RETURN_CODE getServiceListElement(uint16_t offset, dab_service_list_element* listElement);
RETURN_CODE findServiceInList(uint32_t serviceID, uint16_t componentID, uint8_t ignoreComponent, uint8_t matchIndex, uint8_t freqIndex, uint8_t* serviceAddressIndex);
RETURN_CODE findEnsembleInList(uint8_t frequencyIndex, uint8_t* ensembleAddressIndex);
void updateDAB_ServiceList(get_digital_service_list__data* dabList, uint16_t listVer);

#endif //OPTION__DECODE_DAB_SERVICE_LIST
#endif //OPTION__INCLUDE_MODE__DAB
#endif