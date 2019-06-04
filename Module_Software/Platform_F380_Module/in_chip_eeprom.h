/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   header for persistant storage using internal MCU flash driver for C8051F380 based module
   FILE: in_chip_eeprom.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#ifndef _in_chip_eeprom_h_
#define _in_chip_eeprom_h_

#include <platform_options.h>
#include "typedefs.h"
#include "common_types.h"

void eeprom_wbyte(u16 addr,u8 in_data);
u8 eeprom_rbyte(u16 addr);
void eeprom_page_erase(void); 
RETURN_CODE eeprom_save_parameter(void);
RETURN_CODE eeprom_get_work_mode(void);
RETURN_CODE eeprom_get_parameter(void);

#ifdef OPTION__INCLUDE_MODE__DAB
    #ifdef OPTION__DAB_SERVICE_LIST_PERSISTENCE
        RETURN_CODE write_storage(u16 start_addr,u16 len,u8* buffer);
        RETURN_CODE read_storage(u16 start_addr,u16 len,u8* buffer);
        void erase_storage();
    #endif // OPTION__DAB_SERVICE_LIST_PERSISTENCE
#endif // OPTION__INCLUDE_MODE__DAB

#endif                        