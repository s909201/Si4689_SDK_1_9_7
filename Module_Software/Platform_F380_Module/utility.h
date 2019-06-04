/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   header for misc utilities for C8051F380 based module
   FILE: utility.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#ifndef _UTILITY_H_
#define _UTILITY_H_

#include "typedefs.h"

#define SERIAL_NUMBER_ADDR 0x3600
#define SERIAL_NUMBER_LEN (11*2 + 2)


// #define PTRMACRO

#ifdef PTRMACRO
#define u8ptr_to_u16(ptr) ((u16)(*ptr) << 8) | (u16)(*(ptr+1))
#define u16_to_u8ptr(in,ptr) (*(ptr) = (u8)((in) >> 8), *((ptr)+1) = (u8)((in)))
#else
void u16_to_u8ptr(u16 in, u8 xdata * ptr);
#endif

void _nop_(void);

void get_serial_number(char * sn);
void set_serial_number(char * sn);
void init_serial_number(void);

 void flash_page_erase(unsigned int address);
 void flash_write(unsigned int address, unsigned char data1);
 unsigned char flash_read(unsigned int address);

#endif
