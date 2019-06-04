/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   MMI: header for general radio functions
   FILE: mode_common.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#ifndef _mode_command_h_
#define _mode_command_h_

#include "common_types.h"
#include "feature_types.h"

RETURN_CODE 	power_process(void);
RETURN_CODE 	band_switch_mode(void);

//RETURN_CODE 	scan(void);
RETURN_CODE 	volume_inc(void);
RETURN_CODE 	volume_dec(void);
RETURN_CODE		key_process(void);
RETURN_CODE		state_update(void);
RETURN_CODE		display_mode_update(void);
RETURN_CODE 	idle(void);
RETURN_CODE 	work_mode_process(void);
RETURN_CODE 	pset_operate(u8 operate);
RETURN_CODE 	time_update(void);
RETURN_CODE 	auto_time_correct_func(void);
RETURN_CODE 	detece_key(void);
u8 get_HD_service_name(u8* buffer);
u8 get_HD_service_count(void);
u8 str_to_lcd_buf(u8 *lcd_buf,u8 lcd_disp_len,u8 *input_str,u8 input_offset,u8 str_max_len,u8 end_character);



#ifdef OPTION__INCLUDE_MODE__FM
    RETURN_CODE 	seek_up(void);
    RETURN_CODE 	seek_down(void);
    RETURN_CODE     tune_up_down(u8 up_downb); // replaced the two individual up/down tune functions with a single function to reduce space
    //RETURN_CODE 	tune_up(void);
    //RETURN_CODE 	tune_down(void);
    RETURN_CODE     set_freq_spacing(void); // the global variable should be set already before calling this function
//    RETURN_CODE 	analog_seek_process(u8 *state,u16 *freq);
    RETURN_CODE 	show_freq(u8 x,u8 y);
#endif

RETURN_CODE 	display_metric(void);
void Init_variable(void);
u8 freq_to_str(u16 freq,u8* buffer);
u8 display_data_item(u8 state);
void decode_str(u8* out_str,u8* out_str_len,u8* in_str,u8 in_str_len,DAB_DLS_ENCODING_TYPE encode);


#define IDLE 			0
#define BANDSWITCH		1
#define FM_TUNE			2
#define FMHD_TUNE		3

#define FM_FREQ_CONVERSION_FACTOR 10
//10350
//#define FM_FREQUENCY_STEP	   100
//#define FM_MAX_FREQUENCY	10800
//#define FM_MIN_FREQUENCY	 8750

//#define FMHD_FREQUENCY_STEP	   100
//#define FMHD_MAX_FREQUENCY	10800
//#define FMHD_MIN_FREQUENCY	 8750



#define MAX_VOLUME		63
#define VOLUME_STEP		4



#define TIME_UP			0
#define END_TIME		65535

#define NO_KEY_WAKUP_TIME 10 //sec



#define FM_MODE				0
#define FMHD_MODE			1
#define DAB_MODE			3
#define DMB_MODE			4
#define MENU_MODE			5
#define VOLUME_MODE			6
#define CLOCK_MODE			7
#define ALARM_MODE			8
#define MUTE_MODE 			9
#define BAND_SWITCH_MODE	10
#define MAIN_MODE			11
#define IDLE_MODE			12
#define ALARM_TIMEUP_MODE  13
#define DAB_START_PSET_CHANNEL 14
#define FMHD_START_PSET_CHANNEL 15
#define FM_START_PSET		16
#define AM_START_PSET		17
#define AM_MODE				18
#define AMHD_MODE			19
#define AMHD_START_PSET_CHANNEL	20



#define SEEK_NULL		0
#define SEEK_START_UP	1
#define SEEK_START_DOWN	2
#define SEEK_PROCESS	3
#define SEEK_COMPLETE	4
#define SEEK_STOP		5


#define STATUS_UPDATE_INTERVAL   130 //about a half of second update status



#define ADD_PRESET		PRESET_INC_HOLD_KEY
#define DEL_PRESET		PRESET_DEC_HOLD_KEY
#define INC_PRESET		PRESET_INC_KEY
#define DEC_PRESET		PRESET_DEC_KEY


///////////////display item like RDS,PSD,SIS, METRIC
#define ITEM_METRIC_LOOP_TIMES	 	6
#define ITEM_RDS_PI_LOOP_TIMES		6
#define ITEM_RDS_PTY_LOOP_TIMES		6	
#define ITEM_RDS_RT_LOOP_TIMES		64
#define ITEM_RDS_PST_LOOP_TIMES		6
#define ITEM_RDS_TIME_LOOP_TIMES		6	
#define ITEM_RDS_ALT_FREQ_LOOP_TIMES	6

#define ITEM_SIS_SLOGAN_TIMES					FMHD_SIS_SLOGAN_BUFFER_SIZE
#define ITEM_SIS_UNIVERSAL_SHORT_NAME_TIMES		FMHD_SIS_UNIVERSAL_SHORT_NAME_BUFFER_SIZE
#define ITEM_SIS_STATION_MESSAGE_TIMES			FMHD_SIS_STATION_MESSAGE_BUFFER_SIZE
#define ITEM_SIS_STATION_NAME_LONG_TIMES		FMHD_SIS_STATION_NAME_LONG_BUFFER_SIZE
#define ITEM_SIS_STATION_NAME_SHORT_TIMES		6
#define ITEM_SIS_STATION_ID_TIMES				6
#define ITEM_SIS_LOC_LAT_TIMES		6
#define ITEM_SIS_LOC_LON_TIMES		6

#define ITEM_PSD_TITLE_TIMES		FMHD_PSD_GENERIC_BUFFER_SIZE
#define ITEM_PSD_ARTIST_TIMES		FMHD_PSD_GENERIC_BUFFER_SIZE
#define ITEM_PSD_ALBUM_TIMES		FMHD_PSD_GENERIC_BUFFER_SIZE
#define ITEM_PSD_GENRE_TIMES		FMHD_PSD_GENERIC_BUFFER_SIZE




#define ITEM_AUTO_ROLL		0
#define ITEM_METRIC			1
#define ITEM_RDS_PI			2
#define ITEM_RDS_PTY		3
#define ITEM_RDS_RT			4
#define ITEM_RDS_PST		5
#define ITEM_RDS_TIME		6		
#define ITEM_RDS_ALT_FREQ	7

#define ITEM_SIS_SLOGAN					8
#define ITEM_SIS_UNIVERSAL_SHORT_NAME	9
#define ITEM_SIS_STATION_MESSAGE		10
#define ITEM_SIS_STATION_NAME_LONG		11
#define ITEM_SIS_STATION_NAME_SHORT		12
#define ITEM_SIS_STATION_ID				13
#define ITEM_SIS_LOC_LAT				14
#define ITEM_SIS_LOC_LON				15

#define ITEM_PSD_TITLE		16
#define ITEM_PSD_ARTIST		17
#define ITEM_PSD_ALBUM		18
#define ITEM_PSD_GENRE		19
#define ITEM_DLS_STRING		20
#define ITEM_ALERT_HD		21
#define ITEM_RADIODNS_STRING 22



#define ITEM_NEXT  	0x10
#define ITEM_STAND  0x20


#endif
