/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   MMI: non-radio mode header
   FILE: mode_other.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#ifndef _mode_other_h_
#define _mode_other_h_

#include "typedefs.h"
#include <platform_options.h>

/****************************************************************************************

******************************************************************************************/
RETURN_CODE clock_work_mode(void);

#ifndef NO_ALARM_HARDWARE_REMOVE_ALARM_CODE
    RETURN_CODE alarm_work_mode(void);
    void alarm_time_up_mode(void);
    void detect_alarm(void);
#endif //NO_ALARM_HARDWARE_REMOVE_ALARM_CODE

RETURN_CODE menu_work_mode(void);
RETURN_CODE	volume_work_mode(void);
RETURN_CODE audio_mute(void);
RETURN_CODE clock_initialize(void);
void time_value_update(time_struct *time_temp,u8 work_mode);
void idle_mode(void);

#define TIME_DOT_ITEM		0x01
#define TIME_MIN_ITEM		0x02
#define TIME_HOUR_ITEM		0x04
#define TIME_DAY_ITEM		0x08
#define TIME_MON_ITEM		0x10
#define TIME_YEAR_ITEM		0x20
#define TIME_WEEK_ITEM		0x40

#define TIME_DOT_X			TIME_HOUR_X+3
#define TIME_DOT_Y			1	

#define TIME_MIN_X			TIME_HOUR_X+5
#define TIME_MIN_Y			TIME_DOT_Y

#define TIME_HOUR_X			4
#define TIME_HOUR_Y			TIME_DOT_Y

#define TIME_DAY_X			TIME_MON_X+3
#define TIME_DAY_Y			0

#define TIME_MON_X			TIME_YEAR_X+5
#define TIME_MON_Y			TIME_DAY_Y


#define TIME_YEAR_X			1
#define TIME_YEAR_Y			TIME_DAY_Y

#define TIME_WEEK_X			TIME_DAY_X+3
#define TIME_WEEK_Y			TIME_DAY_Y


#define SELECT_YEAR_ITEM		1
#define SELECT_MON_ITEM			2
#define SELECT_DAY_ITEM			3
#define SELECT_WEEK_ITEM		4
#define SELECT_HOUR_ITEM		5
#define SELECT_MIN_ITEM			6





#define BACK_LIGHT		0
#define HD_SEEK			1
#define DAB_RESCAN		2
#define MONO_STEREO		3
#define SNOOZE			4
#define VERSION			5
#define DAB_MANUAL_TUNE	6
#define DAB_GET_TIME	7
#define BATTERY			8
#define FM_FREQ_STEP_SIZE	9
#define FMHD_FREQ_STEP_SIZE 10
#define AUTO_TIME_CORRECT   11
#define DAB_UK_FREQ_LIST	12
#define FMHD_EMPHASIS		13
#define DAB_ERROR_BIT		14
//#define DAB_BIT_RATE		15
#define DAB_AUDIO_INFO		15


#endif