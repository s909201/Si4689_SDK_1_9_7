/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   first byte of status word from si468x
   FILE: si46xx_firmware_api_status.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#ifndef __SI46XX_FIRMWARE_API_STATUS__
#define __SI46XX_FIRMWARE_API_STATUS__

#include "common_types.h"

typedef struct _status_bits
{
	uint8_t CTS;
	uint8_t ERR_CMD;
	uint8_t DACQINT;
	uint8_t DSRVINT;
	uint8_t RSQINT;
	uint8_t RDSINT;
	uint8_t ACFINT;
	uint8_t STCINT;
	//uint8_t DBGINT;
    uint8_t DEVNTINT;
}status_bits;


#endif