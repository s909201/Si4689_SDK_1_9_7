/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   header for lcd driver for C8051F380 based module
   FILE: lcd.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#ifndef _LCD_H_
#define _LCD_H_

#include "typedefs.h"

void LCD_DisplayStr(u8 *str,u8 x,u8 y);
void LCD_init(void);
void LCD_DisplayNum(u16 num,u8 x,u8 y);
void LCD_DisplayNum32(u32 num,u8 x,u8 y);

void LCD_Clear(u8 mode);

#ifdef PLATFORM_F380_MODULE
	void LCD_LoadDefineData(void);
#endif

#ifdef PLATFORM_F340_DEMOBOARD
	void LCD_LoadDefineData(u8 j);
#endif


void LCD_DisplayCBD(u8 define_num,u8 x,u8 y);
u8 UCS2_To_EBU(u8 len,u8* usc2_str,u8* ascii_str);
u8 UTF8_To_EBU(u8 len,u8* utf8_str,u8* ascii_str);

#define DEF_HORN 	0
#define DEF_DELETE		1
#define DEF_ALARM			2
#define DEF_FRECTANGLE  	3								
#define DEF_SERECTANLG 		4
#define DEF_SFRECTANGLE 	5
#define DEF_SSFRECTANGLE 	6
#define DEF_SSERECTANGLE	7

#define LCD_CLEAR_ALL	0
#define LCD_CLEAR_LINE1	1
#define LCD_CLEAR_LINE2	2


#ifdef PLATFORM_F380_MODULE
	#define LCD_BL_ON		1
	#define LCD_BL_OFF		0
#endif


#ifdef PLATFORM_F340_DEMOBOARD
	#define LCD_BL_ON			0
	#define LCD_BL_OFF			1
#endif

#endif