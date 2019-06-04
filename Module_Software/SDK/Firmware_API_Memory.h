/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   definitions for RDS buffer form for platforms which have an external RDS decoder
   FILE: Firmware_API_Memory.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#ifndef __DATA_SERVICE_BUFFER_SETTINGS__
#define __DATA_SERVICE_BUFFER_SETTINGS__

#include "common_types.h"

// Selectable Buffer Size Limitations for the Internal "RAW" Data Buffers
/*
typedef enum buffer_type_enum
{
	rds
}BUFFER_TYPE;


#ifdef PLATFORM_EVB
#define BUFFER_RDS_MAX_SIZE 16*4*4 // (16 groups deep, 4 blocks per group) * 4
#endif
#ifdef PLATFORM_ANDROID
#define BUFFER_RDS_MAX_SIZE 16*4*4 // (16 groups deep, 4 blocks per group) * 4
#endif
#ifdef PLATFORM_F380_MODULE
#define BUFFER_RDS_MAX_SIZE 16*4 // 16 groups deep, 4 blocks per group
uint32 Buffer_RDS[BUFFER_RDS_MAX_SIZE]; // Preallocate the memory for MCU
#endif

*/

#endif