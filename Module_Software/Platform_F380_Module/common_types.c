/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   common memory function drivers for C8051F380 based module
   FILE: common_types.c
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#include "compiler_defs.h"
#include "typedefs.h"

#include <platform_options.h>

#include "common_types.h"

//The STDLIB items take up too much code space, they are being replaced by local functions to reduce the code size

void ClearMemory(uint8_t* ptr, uint16_t num)
{
    uint32_t i;

    for(i=0;i<num;i++)
    {
        ptr[i] = 0;
    }
}

void CpyMemory(uint8_t* dPtr, uint8_t* sPtr, uint16_t num)
{
    uint32_t i;

    for(i=0;i<num;i++)
    {
        dPtr[i] = sPtr[i];
    }
}

uint8_t CompareMemory(uint8_t* ptr1, uint8_t* ptr2, uint16_t num)
{
    uint32_t i;

    for(i=0;i<num;i++)
    {
        if(ptr1[i] != ptr2[i])
        {
            return 1;
        }
    }
    return 0;
}
