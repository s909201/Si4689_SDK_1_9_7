/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   header for Main entry for C8051F380 based module
   FILE: main.c
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#ifndef _main_h_
#define _main_h_

#ifndef	_MAIN_C_
	#define global extern  
#else
	#define global
#endif

#include "typedefs.h"
#include <platform_options.h>
#include "common_types.h"
#include "platform_selector.h"

global bit key_flag;

	global u8 xdata key_mode;
	global u8 xdata key_value;
	global u8 xdata key_up_count;
	global u16 xdata key_down_count;
#ifdef PLATFORM_F380_MODULE
	global u16 xdata key_vlaue_array[4];
#endif

	//global u8 xdata key_value;

global bit key_down_flag;
global bit  key_up_flag;
global bit  key_hold_flag;
global u8 tuning_status;
global bit TA_old;
global bit TB_old;
global u8 tuning_value;

global u8 volume_status;
global bit VA_old;
global bit VB_old;
global u8 volume_value;

global bit volume_confirm;
global bit tuning_confirm;
global bit knobs_flag;
global u8 knobs_count;
global bit knobs_press_flag;
global bit temp_knobs;
global bit key_scan_flag;

#ifdef PLATFORM_F340_DEMOBOARD
	global u8 xdata spi_rbuffer[64];
#endif

global u32 xdata data_addr;

global RADIO_MODE_TYPE work_mode;
global RADIO_MODE_TYPE current_work_mode;//persist the current mode for determining 
										//whether the tuner need to reboot or not  
global u8 work_mode_index;
global u8 band_size;
global u8 xdata display_mode;
global u8 xdata seek_state;


global u8 loop_display_times;

global bit power_flag;
global bit power_save_flag;//adjust whether it need to re-initial the radio chip
global u16 xdata chip_part;
global u8 *pband;

global u16 xdata am_freq;
global u8 xdata am_freq_step_size;

global u16 xdata amhd_freq;
global u8 xdata amhd_freq_step_size;

global u8 xdata fm_freq_step_size;

global u16 xdata fm_freq;
global u8 xdata fm_freq_step_size;

global u16 xdata fmhd_freq;
global u8 xdata fmhd_freq_step_size;
global bit fmhd_seekonly;

global u8 xdata fmhd_ber_mode;

global bit dab_browse_flag;
global bit dab_scan_flag;
global bit dab_reduced_list_flag;
global bit dab_uk_freq_list_flag;
global bit dab_favorites_only_flag;

global u16 xdata display_item_str_4ms;
global u16 xdata display_delay_4ms;
global bit display_delay_en;
global bit display_refresh_flag;
global bit display_entered_volume_work_mode;
global u8 xdata pfunc;
global u8 xdata volume;
global bit mute_flag;
global bit mono_stereo_flag;

global u8 xdata item_loop;


//------------------TIME------------------------------------------------------------
//#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
	global u8 xdata time_count;
	global u8 xdata time_refresh_item;
	global bit time_sec_flag;
	global bit time_dot_flag;
	global time_struct xdata time;
	global u8* xdata pselect_item_value;
	global u8 xdata select_item_min_scale;
	global u8 xdata select_item_max_scale;
	global u8 xdata select_item;
	global u16 xdata select_item_flash_delay;

	global u8 xdata auto_time_correct_flag;
	#define AUTO_TIME_CORRECT_ENABLE	0x8F

	global time_struct xdata alarm_time;
	global bit alarm_flag,alarm_time_up;

	global bit  buzzer_on_flag;
	global u16  buzzer_interval_count;





	global u8 xdata wake_up_time;

//#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI

//----------------RDS-----------------------------
global u8 xdata rds_update_ready_item;
//---------------------------------------------------
//------------------SIS------------------------------
global u8 xdata sis_update_ready_item;
//------------------PSD------------------------------
global u8 xdata psd_update_ready_item;
//------------------Alert------------------------------
global u8 xdata alert_update_ready_item;
//------------------DLS-----------------------------
global u8 xdata dls_update_ready_item;


//-----------------PSET----------------------------

	#define MAX_PRESET_NUM	10
	global u8 xdata pset_table_index;
	global u16 xdata fm_pset_table[MAX_PRESET_NUM];
	#ifdef OPTION__FM_SHOW_STATION_NAME_PST
	global u8 xdata fm_pty_pset_table[MAX_PRESET_NUM][12];
	#endif


	#ifdef OPTION__INCLUDE_MODE__AM
	global u16 xdata am_pset_table[MAX_PRESET_NUM];
	#endif


	#ifdef OPTION__INCLUDE_MODE__FMHD

		//#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
			global fmhd_preset_struct xdata fmhd_pset_table[MAX_PRESET_NUM];
		//#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
	    global bit ber_running_flag;

        #ifdef OPTION__INCLUDE_FRONT_END_TEST_FUNCTIONS
            global fmhd_split_mode_setting;
        #endif
	#endif

#ifdef OPTION__INCLUDE_MODE__AMHD
	global amhd_preset_struct xdata amhd_pset_table[MAX_PRESET_NUM];
#endif


	#ifdef OPTION__INCLUDE_MODE__DAB
		#ifndef OPTION__DAB_PRESETS_AS_FAVORITES
			global dab_preset_struct xdata dab_pset_table[MAX_PRESET_NUM];
		#endif //OPTION__DAB_PRESETS_AS_FAVORITES
		global u8 xdata dab_last_played_service_list_index;
	#endif



//----------------MENU----------------------
//#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
	global bit menu_select_flag;
	global u8 xdata menu_index;
	global u8 xdata current_menu_item;
//#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI

global bit LCD_BL_flag;
global u8 xdata LCD_buf[8];


//------usb---------------------
global bit firmware_download_flag;

global u8 xdata dab_manual_freq_index;

global u8 xdata ship_ats_inter_flag;

#ifdef OPTION__UART_DRIVER
	global u8 xdata uart0_rx_buf[32];
	global u8 xdata uart0_tx_buf[32];
	global bit uart0_rx_flag;
	global bit uart0_rx_start_flag;
	global bit uart0_tx_flag;
	global u8 xdata uart0_rx_num;
#endif


#ifdef ATS_EMBED_CODE
	global u8 xdata ats_key_flag;
	global bit ats_keypad_test_flag;
	global bit ats_encode_test_flag;
	global u8 xdata ats_key;
	global bit ats_test_enable_flag;
	global bit ats_mode_switch_flag;
	#define ATS_SHIP_SETTING	0x8F
	global bit ATS_test_uk_freq_flag;
	global bit ATS_RDS_valid_flag;
#endif

#endif