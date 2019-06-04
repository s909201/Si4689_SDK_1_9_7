/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   SDK HD radio alert decoder
   FILE: FMHD_Alert_Handler.c
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include "common_types.h"
#include "platform_options.h"
#include "FMHD_Alert_Handler.h"
#include "SDK_Callbacks.h"

#ifdef OPTION__INCLUDE_MODE__FMHD
#ifdef OPTION__DECODE_HD_ALERTS

//-----------------------------------------------------------------------------
// local defines
//-----------------------------------------------------------------------------
#define ALERT__ENCODING__OFFSET 0
#define ALERT__TOTAL_LENGTH__OFFSET 1
#define ALERT__CRC7__OFFSET 3
#define ALERT__CNT_LENGTH__OFFSET 4
#define ALERT__MSGID__OFFSET 5
#define ALERT__CRC12__OFFSET 6
#define ALERT__MSG_LENGTH__OFFSET 8
#define ALERT__MESSAGE_PAYLOAD__OFFSET 10

#define ALERT_CRC12_PASS 0x0AAA

//0x81 0x80 0x00 0xC0 -> Status
//0x13 0x00 -> Buffer Length (Header)
//0x00 -> Encoding
//0x09 0x00 = Total Length = 9 bytes
//0x4C -> CRC-7
//0x06 -> CNT bytes
//0x02 -> MSG ID

//0xAA 0x0A = 0x0AAA -> CRC pass
//0x02 0x00 = msg length 2

//MESSAGE
//0x02 (MSGID)
//0xAA 0x9A 0x54 0x40 0x92 0x00 (CNT) ?
//0x4D 0x32 (String)

//-----------------------------------------------------------------------------
// Globals
//-----------------------------------------------------------------------------
uint16_t currentMessageID;

// Alert Data
fmhd_alert_string alertDisplay;   // Displayed Alert

//-----------------------------------------------------------------------------
// After changing services, the PSD tracking variables need to be
// initialized.
//-----------------------------------------------------------------------------
void initAlerts(void)
{
    alertDisplay.ENCODING = ENCODING_RESERVED;
    alertDisplay.LENGTH = 0;
    ClearMemory(alertDisplay.DATA,sizeof(alertDisplay.DATA));
    
    currentMessageID =0xFF00;
}


//-----------------------------------------------------------------------------
// After an Alert interrupt, process the data.
//-----------------------------------------------------------------------------
void updateAlerts(fmhd_get_alert_message__data* alertData)
{
    uint8_t CNTlength = 0;
    uint16_t expectedBufferLength = 0;

    if(alertData->LENGTH != 0)
    {
        if((alertData->PAYLOAD[ALERT__MSGID__OFFSET] != currentMessageID) && (_recover_16bit_from_little_endian_buffer(&alertData->PAYLOAD[ALERT__CRC12__OFFSET]) == ALERT_CRC12_PASS))
        {
            // We have a new message and it passes CRC - update the alert string
            currentMessageID = alertData->PAYLOAD[ALERT__MSGID__OFFSET];
            
            alertDisplay.ENCODING = (FMHD_SIS_PSD_ENCODING_TYPE)alertData->PAYLOAD[ALERT__ENCODING__OFFSET];
            alertDisplay.LENGTH = _recover_16bit_from_little_endian_buffer(&alertData->PAYLOAD[ALERT__MSG_LENGTH__OFFSET]);
            if(alertDisplay.LENGTH > FMHD_ALERT_BUFFER_SIZE)
            {
                alertDisplay.LENGTH = FMHD_ALERT_BUFFER_SIZE;
            }

            expectedBufferLength = ALERT__MESSAGE_PAYLOAD__OFFSET + _recover_16bit_from_little_endian_buffer(&alertData->PAYLOAD[ALERT__TOTAL_LENGTH__OFFSET]);
            if(expectedBufferLength > alertData->LENGTH)
            {
                //The buffer was cut short because the reply buffer was too small to handle such a large alert.  Adjust accordingly
                alertDisplay.LENGTH = alertDisplay.LENGTH - (expectedBufferLength - alertData->LENGTH);
            }

            CNTlength = alertData->PAYLOAD[ALERT__CNT_LENGTH__OFFSET];
            CpyMemory(alertDisplay.DATA,&alertData->PAYLOAD[ALERT__MESSAGE_PAYLOAD__OFFSET + 1 + CNTlength],alertDisplay.LENGTH);

            fmhd_play_alert_tone__command();

            CALLBACK_Updated_Data(UPDATED_HD_ALERT);
        }
    }
}

#endif //OPTION__DECODE_HD_ALERTS
#endif //OPTION__INCLUDE_MODE__FMHD