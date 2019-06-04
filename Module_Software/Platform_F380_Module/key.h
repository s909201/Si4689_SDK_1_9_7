/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   header for keypad driver for C8051F380 based module
   FILE: key.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#ifndef _key_h_
#define _key_h_

#include <platform_options.h>

#ifdef PLATFORM_F380_MODULE
u16 ad_convertion(u8 pin_value);
#endif
void key_init(void);
void Timer2_init(void);

void Timer1_init(void);
void key_scan(void);
void ADC_compare_init();
void key_comparator_init();

#define UP_KEY			0xA0		
#define SELECT_KEY		0xA1
#define DOWN_KEY		0xA2
#define BACK_LIGHT_KEY	0xA3		
#define SEEK_UP_KEY		0xA4
#define CLOCK_KEY		0xA5
#define SEEK_DOWN_KEY	0xA6
#define HDSEEK_KEY		0xA7
#define PRESET_INC_KEY	0xA8
#define ALARM_KEY		0xA9
#define PRESET_DEC_KEY	0xAA
#define DAB_RESCAN_KEY	0xAB
#define MODE_KEY		0xAC
#define MENU_KEY		0xAD
#define ON_OFF_KEY		0xAE
#define	SNOOZE_KEY		0xAF

#define CLOCK_HOLD_KEY	0xB0
#define ALARM_HOLD_KEY  0xB1


#define TUNE_PRESS_KNOBS	0xB2
#define TUNE_INC_KNOBS		0xB3
#define TUNE_DEC_KNOBS		0xB4

#define VOLUME_PRESS_KNOBS	0xB5
#define VOLUME_INC_KNOBS	0xB6
#define VOLUME_DEC_KNOBS	0xB7
 

#define PRESET_INC_HOLD_KEY		0XB8
#define PRESET_DEC_HOLD_KEY		0XB9

#define SEEK_UP_HOLD_KEY	0xBA
#define SEEK_DOWN_HOLD_KEY	0xBB

#define HDSEEK_HOLD_KEY 0xBC
#define DAB_RESCAN_HOLD_KEY 0xBD



#define KEY_UP_MODE 	0
#define KEY_DOWN_MODE	1
#define KEY_WAIT_MODE	2
#define KEY_WAIT_UP_MODE	3

#define KEY_STABLE_VALID_TIME 15
#define KEY_HOLD_VALID_TIME		500
#define KNOBS_JUDGE_COUNT	20



#endif