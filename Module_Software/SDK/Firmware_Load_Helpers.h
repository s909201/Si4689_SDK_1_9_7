/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   definition for SDK driver interface to firmware loading driver
   FILE: Firmware_Load_Helpers.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#ifndef __FIRMWARE_LOAD_HELPERS__
#define __FIRMWARE_LOAD_HELPERS__

#define FIRMWARE_SEGMENT_MAX_LENGTH	(CMD_BUFFER_LENGTH - 4)  // Command buffer is currently limited to 256, we need 4 bytes for the command

extern RETURN_CODE firmwareSetImage(RADIO_MODE_TYPE mode);
extern uint16_t firmwareGetSegment(uint16_t requestedLength, uint8_t** firmwareSegment);
extern RETURN_CODE firmwareGetFlashAddress(uint32_t* addr);

#endif