/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   Generic header for main drivers necessary to be implemented for host mcu to control si468x
   FILE: HAL.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#ifndef __HAL__
#define __HAL__

#include "common_types.h"

extern RETURN_CODE initHardware(void);
extern RETURN_CODE audioEnable(void);
extern RETURN_CODE audioDisable(void);
extern RETURN_CODE powerDownHardware(void);
extern RETURN_CODE writeCommand (uint16_t length, uint8_t *buffer);
extern RETURN_CODE readReply (uint16_t length, uint8_t *buffer);
extern RETURN_CODE wait_for_CTS (uint32_t timeout_ms);
extern void delay (uint32_t delay_ms);
RETURN_CODE wait_for_CTS (uint32_t timeout_ms);

#ifdef OPTION__INCLUDE_MODE__DAB
    #ifdef OPTION__DAB_SERVICE_LIST_PERSISTENCE
    extern RETURN_CODE writePersistentStorage(uint16_t start_addr, uint16_t length, uint8_t* buffer);
    extern RETURN_CODE readPersistentStorage(uint16_t start_addr, uint16_t length, uint8_t* buffer);
    extern void erasePersistentStorage();
    #endif // OPTION__DAB_SERVICE_LIST_PERSISTENCE
#endif // OPTION__INCLUDE_MODE__DAB

#endif