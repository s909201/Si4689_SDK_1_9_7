/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   header for boot flash driver for C8051F380 based module
   FILE: SST25VF032B.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#ifndef _SST25VF032B_H_
#define _SST25VF032B_H_

#include <platform_options.h>

#ifdef PLATFORM_F340_DEMOBOARD
void SST_Init(void);

void Group_Write_Flash(u32 Dst,u8 xdata * Wbuffer,u8 Len);
void Byte_Write_Flash(u32 Dst, u8 byte);
void Group_Read_Flash(u32 Dst,u8 xdata * Rbuffer, u8 Len);
void Chip_Erase();
void Block_Erase_4K(u32 Dst);

#define SPI_IO_OUT 	//while(0){P0 |=0xFF;P0MDIN = 0xFF;P0MDOUT =0x3d;}
#define SPI_IO_IN	//while(0){P0|=0x0F;P0MDIN &=~0x0F;P0MDOUT &=~0x0F;} 

#endif

#endif