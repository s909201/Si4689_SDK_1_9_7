/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   SDK DAB DLS decoder
   FILE: DAB_DLS_Handler.c
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include "common_types.h"
#include "platform_options.h"
#include "DAB_DLS_Handler.h"
#include "SDK_Callbacks.h"
//#include "si46xx_firmware_api.h"

#ifdef OPTION__INCLUDE_MODE__DAB
#ifdef OPTION__DECODE_DLS

//-----------------------------------------------------------------------------
// local defines
//-----------------------------------------------------------------------------
#define PREFIX0__PAYLOAD_INDEX 0
#define PREFIX0__TOGGLE_MASK 0x80
#define PREFIX0__TOGGLE_SHIFT 7
#define PREFIX0__COMMAND_MASK 0x10
#define PREFIX0__COMMAND_TYPE_MASK 0x0F
    #define PREFIX0__COMMAND_DLS_MESSAGE 0x00
    #define PREFIX0__COMMAND_DLS_CLEAR 0x01
    #define PREFIX0__COMMAND_DL_PLUS_COMMAND 0x10

#define PREFIX1__PAYLOAD_INDEX 1
#define PREFIX1__DLS_CHARSET_MASK 0xF0
#define PREFIX1__DLS_CHARSET_SHIFT 4
#define PREFIX1__COMMAND_LINK_MASK 0x10

#define DLS_MESSAGE_DATA__PAYLOAD_INDEX 2

//-----------------------------------------------------------------------------
// Globals
//-----------------------------------------------------------------------------

// DLS Basic String Data
dab_dls_string dlsDisplay;   // Displayed dls for current program


void _update_generic_dls_string(dab_dls_string* dest, uint8_t* src, uint8_t len)
{
    dest->LENGTH = len;
    if(len > DAB_DLS_BUFFER_SIZE)
    {
        dest->LENGTH = DAB_DLS_BUFFER_SIZE;
    }
    else
    {
        dest->LENGTH = len;
    }
    CpyMemory(dest->DATA, src, dest->LENGTH);
    CALLBACK_Updated_Data(UPDATED_DLS_STRING);
}

//-----------------------------------------------------------------------------
// After changing services, the DLS tracking variables need to be initialized.
//-----------------------------------------------------------------------------
void initDLS(void)
{
    dlsDisplay.ENCODING = DLS_ENCODING_RESERVED;
    dlsDisplay.TOGGLE = 0;
    dlsDisplay.LENGTH = 0;
    ClearMemory(dlsDisplay.DATA,sizeof(dlsDisplay.DATA));
}

//-----------------------------------------------------------------------------
// After a DLS interrupt, process the data.
//-----------------------------------------------------------------------------

void updateDLS(get_digital_service_data__data dlsData)
{
    if(((dlsData.PAYLOAD[PREFIX0__PAYLOAD_INDEX] & PREFIX0__COMMAND_MASK) == 0))
    {
        dlsDisplay.TOGGLE = ((dlsData.PAYLOAD[PREFIX0__PAYLOAD_INDEX] & PREFIX0__TOGGLE_MASK) >> PREFIX0__TOGGLE_SHIFT);
        dlsDisplay.ENCODING = (DAB_DLS_ENCODING_TYPE)((dlsData.PAYLOAD[PREFIX1__PAYLOAD_INDEX] & PREFIX1__DLS_CHARSET_MASK) >> PREFIX1__DLS_CHARSET_SHIFT);
        if(dlsDisplay.ENCODING == 4)
        {
            dlsDisplay.ENCODING = 6;
        }
        _update_generic_dls_string(&dlsDisplay, &dlsData.PAYLOAD[DLS_MESSAGE_DATA__PAYLOAD_INDEX], (uint8_t)(dlsData.BYTE_COUNT - DLS_MESSAGE_DATA__PAYLOAD_INDEX));
    }
    else
    {
        //We have a DL+ command
        if(((dlsData.PAYLOAD[PREFIX0__PAYLOAD_INDEX] & PREFIX0__COMMAND_TYPE_MASK) == PREFIX0__COMMAND_DLS_CLEAR))
        {
            initDLS();
            CALLBACK_Updated_Data(CLEAR_DLS_COMMAND);
        }
        else
        {
            //TODO: add DL+ support for larger memory hosts - the MCU based SDK really can't handle the dynamic memory requirements of DL+
        }
    }
}

#endif //OPTION__DECODE_DLS
#endif //OPTION__INCLUDE_MODE__DAB