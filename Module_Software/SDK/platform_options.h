/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   Compile options for the overall SDK project
   FILE: platform_options.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/



#ifndef __PLATFORM_OPTIONS__
#define __PLATFORM_OPTIONS__

#include <platform_selector.h>

//Section for choosing platform settings/options
//**************************************
/*
The following options should either be #define in order to select the option, unless otherwise stated.

1) Image Type (select one): OPTION__IMAGETYPE__DAB_FM | OPTION__IMAGETYPE__DAB_FM_AM | OPTION__IMAGETYPE__FMHD | OPTION__IMAGETYPE__ALL
     * Depending on the options selected and MMI complexity, a single image for all modes may not fit in the MCU code space, this option enables basic mode selection for code inclusion

     - OPTION__IMAGETYPE__DAB_FM: this options includes items for compilation which build a host image for a DAB + FM radio
     - OPTION__IMAGETYPE__DAB_FM_AM: this options includes items for compilation which build a host image for a DAB + FM + AM radio
     - OPTION__IMAGETYPE__FMHD: this options includes items for compilation which build a host image for an FMHD radio
     - OPTION__IMAGETYPE__ALL: this options includes all code which build a host image for a DAB + FM + FMHD + AM + AMHD radio - this image is too large to fit on the SDK Demo Module

2) OPTION__REMOVE_FIRMWARE_FUNCTIONS_NOT_USED_SMALL_SDK - Code Size Reduction.  This removes from compilation, functions which are not currently used in the SDK code targeting modules
3) OPTION__MINIMAL_FIRMWARE_FUNCTION_IMPLEMENTATION_SMALLER_SDK - Code Size Reduction.  This removes from compilation, elements in some data structures which are not currently used in the SDK code targeting modules.
4) OPTION__INCLUDE_FRONT_END_TEST_FUNCTIONS - This option should be defined during the hardware calibration phase of your design, but should be removed for the shipping product
5) OPTION__INCLUDE_POWER_SAVING_MODE - This option includes the driver which puts the F380 MCU into a lower power state when possible

6) Boot Mode (select one): OPTION__BOOT_FROM_HOST | OPTION__BOOT_FROM_FLASH | OPTION__BOOT_FROM_FLASH_MINI
     - OPTION__BOOT_FROM_HOST: this option selects the initialization code which expects the host MCU to load all firmware images
     - OPTION__BOOT_FROM_FLASH: this option selects the initialization code which expects all necessary firmware images be loaded from external NVSPI connected flash (not applicable for ROM00)
     - OPTION__BOOT_FROM_FLASH_MINI: this option includes the mini-patch in the code space which is loaded from the host, so that all other firmware images can be loaded from external NVSPI connected flash.
     - OPTION__BOOT_FROM_FLASH_FULL: this option includes the full-patch in the code space which is loaded from the host, so the patch does not have to be kept in the external NVSPI connected flash.

7) OPTION__AUDIO_ANALOG_ENABLE - enables the code which provides analog audio output

8) OPTION__AUDIO_I2S_ENABLE - enables the code which provides I2S digital audio output
     - OPTION__AUDIO_I2S__MASTER_SLAVE: sub-option which sets if the I2S port on the si46xx should operate as Master or Slave (Master 1, Slave 0)
     - OPTION__AUDIO_I2S__SAMPLE_RATE_KHZ: sub-option which sets the I2S port sample rate in kHz: range between 32000 and 48000
     - OPTION__AUDIO_I2S__SAMPLE_SIZE: sub-option which sets the I2S port sample size: range between 2 and 24
     - OPTION__AUDIO_I2S__FRAMING_FORMAT: sub option which sets the I2S framing format: (I2S 0, DSP 6, Left Justified DSP 7, Left Justified 8, Right Justified 9)


9) OPTION__INTB_ENABLE - enables the INTB line fron the si46xx, currently the SDK does not rely on hardware interrupts

10) SPI Bus buffer Size (select one): OPTION__FULL_SIZE_SPI_BUFFER (need ~ 8k ram) | OPTION__SMALL_SPI_BUFFER (need ~ 256 bytes ram)
     - OPTION__FULL_SIZE_SPI_BUFFER: this SPI buffer size is intended for advanced hosts with lots of memory
     - OPTION__SMALL_SPI_BUFFER:  this SPI buffer size is intended for basic hosts (modules) which have very limited RAM resources.

11) OPTION__MCU_PLATFORM - include this option to build the MCU SDK drivers in "HAL.c, Firmware_Load_Helpers.c, and Hardware_Calibration_Helpers.c"
     - this is to prevent commonly named SDK Callback files from being build by the incorrect project files.  Example differentiating between PLATFORM_EVB and PLATFORM_F380_V2_0

12) OPTION__32BIT_IS_LONG - If selected platform type (INT) is not a 32 bit number and uses LONG instead (ex 8051)

13) OPTION__CONVERT_BIG_ENDIAN - If selected platform architecture is BIG_ENDIAN, include this option because the output of the si46xx is little endian and must be converted

14) RDS decode mode basic/advanced (select one or do not define to disable): OPTION__RDS_DECODE_ADVANCED | OPTION__RDS_DECODE_BASIC | OPTION__RDS_BUFFER_V4L2
     - Determines if the basic or advanced PS/RT RDS display functions are used
     - OPTION__RDS_DECODE_ADVANCED:The advanced functions attempt to detect errors and only display complete messages
     - OPTION__RDS_DECODE_BASIC: The basic functions are closely tied to the recommendations in the RBDS specification and are faster to update but more error prone
     - OPTION__RDS_BUFFER_V4L2: Not currently implemented

15) OPTION__DECODE_SIS - define this option to include the HD Radio SIS data handler
16) OPTION__DECODE_PSD - define this option to include the HD Radio PSD data handler
17) OPTION__PSD_FORMAT_ID3 - define this option to use the HD radio PSD in ID3 format, note: this requires a larger reply buffer to work properly and should not be selected unless modifying the SDK source
18) OPTION__DECODE_DLS - define this option to include the DAB DLS data handler

19) OPTION__FORCE_MEMORY_SPACES - If selected platform is based upon the 8051 architecture, define this option to set memory locations

20) OPTION__DECODE_FMHD_SERVICE_LIST - define this option to include the HD Radio service list handler, this is necessary for identifying and tracking digital audio services
21) OPTION__DECODE_DAB_SERVICE_LIST - define this option to include the DAB service list handler, this is necessary for identifying and tracking digital audio services
22) OPTION__SERVICE_LIST_SMALL - Code Size/RAM Usage Reduction - define this option to limit the service list handlers to only tracking audio services with the minimal set of information from the full list
23) OPTION__DAB_SERVICE_LIST_TIMEOUT_TUNE_MS - the value for this option sets the amount of time, in ms, where the software will exit a failed DAB tune.  Example: 10000
24) OPTION__DAB_SERVICE_LIST_SCVLIST_MS - the value for this option sets the amount of time, in ms, where the software will exit a failed DAB service list acquisition.  Example: 20000
25) OPTION__DAB_SERVICE_LIST_TIMEOUT_CALLBACK_RATE_MS - the value for this option sets the amount of time, in ms, between callbacks to the MMI for UI update, during the DAB scan/tune process.  Example: 100
26) OPTION__PROPERTY_DAB_VALID_RSSI_THRESHOLD - the value for this option is used for the property "DAB_VALID_RSSI_THRESHOLD" a value which should be tuned for the antenna in the system to best represent the RSSI for a good frequency during band scan
27) OPTION__FM_TIMEOUT_SEEK_MS - the value for this option sets the amount of time, in ms, where the software will exit a failed FM Seek.  Example: 10000
28) OPTION__FM_SEEK_CALLBACK_RATE_MS - the value for this option sets the amount of time, in ms, between callbacks to the MMI for UI update, during the FM Seek process.  Example: 100
29) OPTION__DECODE_HD_ALERTS - define this option to include the HD Radio Alert handler.
30) OPTION__DAB_SUPPORT_DAB_DAB_LINKING - define this to include the code necesssary for service linking between multiple DAB ensembles - in the A1/A2 case (SID=SID)
31) OPTION__DAB_SUPPORT_DAB_DAB_LINKING_A3 - define this to include the code necesssary for service linking between multiple DAB ensembles - in the A3 case (SID != SID, hard links)
32) OPTION__DAB_SERVICE_LIST_PERSISTENCE - define this option to include the ability to store the service list in persistant storage, this can take 4k or more of flash and may affect your ability to fit any code additions into the MCU
33) OPTION__FMHD_SEEK_HDLEVEL_THRESHOLD - the value for this option sets the HDLEVEL which should be used to qualify a valid HD station to seek stop in HD Seek mode
34) OPTION__FMHD_SEEK_OFDM_SAMPLE_NUMBER - the value for this options sets the FM_RSQ_HD_DETECTION property SAMPLES field.  See AN649 for explanation of this property.
35) OPTION__OPERATE_AS_SLAVE_NO_MMI - define this option to remove all code related to the MMI in a "Master" module usage.  If you are creating a "Slave" module using the SL200, this will free up code space for additional features.
36) OPTION__ADVANCED_METRICS - define this option to include additional metrics for use during evaluation, the advanced metrics are probably unecessary for customer usage so it is recommended not to include this code on the final build.
37) OPTION__MCU_HARDWARE_SPI - define this option to replace the previous software SPI with a driver which uses the F380 SPI hardware block
38) OPTION__DAB_PRESETS_AS_FAVORITES - define this option to replace the previous "stack" style preset implementation with a "favorites" style implementation
     - "Stack" style usage:
          - Add a preset: press and hold the preset+ button
          - Remove a preset: from the preset selection screen, select the desired preset to remove and hold the preset- button.
          - A press to preset+ or preset- enters the preset selection screen.
          - Disadvantages: approximately 1k more code space required, limited to 10 presets.
     - "Favorites style usage:
          - Add a preset: from any service screen (now playing or browse) press (not hold) the preset+ button to mark that service
          - Remove a preset: from any service screen (now playing or browse) press (not hold) the preset- button to remove that service
          - Enter Browse mode of only presets: hold the preset+ button
          - Browse all serivices: hold the preset- button
          - Advantages: smaller code requirements, as many presets as there are services
39) OPTION__FM_SHOW_STATION_NAME_PST - define this option to show the PST for a given station in the MMI main panel.  Note: this is not desirable for US based radios as PST scrolls
40) OPTION__TIME_SETTING - define this option to include MMI code for manually adjusting the clock time (this is auto disabled on the OPTION__IMAGETYPE__DAB_FM_AM and OPTION__IMAGETYPE__DAB_FM images)
41) OPTION__MENU_SETTING - define this option to include the MMI code for a software menu of additional device options/modes (this is auto disabled on the OPTION__IMAGETYPE__DAB_FM_AM image)
42) OPTION__RADIODNS - define this option to include the SDK code necessary to generate a RadioDNS address from FM-RDS and/or DAB
43) OPTION__NVMSPI_RATE_MHZ - this value (if defined will be used to adjust the NVM SPI boot rate (when booting from flash).  Do not define the option to remove the associated code.
44) OPTION__DECODE_DAB_ANNOUNCEMENTS - Note: not yet supported in the Radio Manager, but included as a placeholder to include the firmware api elements
45) OPTION__COMMAND_INPUT_MINIMAL_OPTIONS_SMALLER_SDK - commands with a large number of inputs as bits in a byte are changed to the whole byte at once - results in some code space savings
46) OPTION__EXCLUDE_MFGTEST - code related to the UART based MFGTest is removed from the build regardless of it being selected in platform_selector.h
47) OPTION__DAB_LINK_DISQUALIFIER_SNR_SETTLING_TIME_MS - the allowed time for the SNR metric to settle before checking it for the below threshold
48) OPTION__DAB_LINK_DISQUALIFIER_SNR_THRESHOLD - this is the SNR level at which a potential DAB link will be excluded from the candidates which attempt acquisition
*/

#ifdef PLATFORM_F380_MODULE
	//#define OPTION__IMAGETYPE__DAB_FM_AM
	#define OPTION__IMAGETYPE__DAB_FM
    //#define OPTION__IMAGETYPE__FMHD_AMHD
	//#define OPTION__IMAGETYPE__FMHD
	#define OPTION__REMOVE_FIRMWARE_FUNCTIONS_NOT_USED_SMALL_SDK
    #define OPTION__MINIMAL_FIRMWARE_FUNCTION_IMPLEMENTATION_SMALLER_SDK
    #define OPTION__COMMAND_INPUT_MINIMAL_OPTIONS_SMALLER_SDK
    #define OPTION__REMOVE_SDK_FUNCTIONS_NOT_USED_BY_MMI
    #define OPTION__EXCLUDE_MFGTEST

    #define OPTION__INCLUDE_FRONT_END_TEST_FUNCTIONS

    #define OPTION__BOOT_FROM_FLASH_MINI
    //#define OPTION__INCLUDE_POWER_SAVING_MODE
    //#define OPTION__BOOT_FROM_FLASH_FULL
    #define OPTION__AUDIO_ANALOG_ENABLE
    //#define OPTION__AUDIO_I2S_ENABLE
    //****************************************************
        // Set Master or Slave (Master 1, Slave 0)
        #define OPTION__AUDIO_I2S__MASTER_SLAVE 0
        //Set Sample Rate (32000 - 48000)
        #define OPTION__AUDIO_I2S__SAMPLE_RATE_KHZ 48000
        //Set Sample Size (2 - 24)
        #define OPTION__AUDIO_I2S__SAMPLE_SIZE 16
        //Set Framing Format (I2S 0, DSP 6, Left Justified DSP 7, Left Justified 8, Right Justified 9)
        #define OPTION__AUDIO_I2S__FRAMING_FORMAT 0
    //****************************************************
    //#define OPTION__INTB_ENABLE
    #define OPTION__SMALL_SPI_BUFFER
    #define OPTION__MCU_PLATFORM
    #define OPTION__32BIT_IS_LONG
    #define OPTION__CONVERT_BIG_ENDIAN
    #define OPTION__RDS_DECODE_ADVANCED
    #define OPTION__DECODE_SIS
    #define OPTION__DECODE_PSD
    #define OPTION__DECODE_HD_ALERTS
    #define OPTION__DECODE_DLS
    #define OPTION__FORCE_MEMORY_SPACES
    #define OPTION__DECODE_FMHD_SERVICE_LIST
    #define OPTION__DECODE_DAB_SERVICE_LIST
    #define OPTION__SERVICE_LIST_SMALL
    #define OPTION__DAB_SERVICE_LIST_TIMEOUT_TUNE_MS 3000         //The total time to allow for DAB Tune before Timeout
    #define OPTION__DAB_SERVICE_LIST_SCVLIST_MS 5000              //The total time to allow for DAB Service List Update before timeout
    #define OPTION__DAB_SERVICE_LIST_TIMEOUT_CALLBACK_RATE_MS 100  //The amount of time between dab bandscan callbacks to the MMI

	#define OPTION__DAB_SERVICE_START_TIMEOUT_MS 1200              //The total time to allow for DAB Service Start before Timeout
    #define OPTION__DAB_SERVICE_START_ATTEMPT_RATE_MS 20          //The amount of time between attempting to start a service
    
    #define OPTION__FM_TIMEOUT_SEEK_MS 30000
    #define OPTION__FM_SEEK_CALLBACK_RATE_MS 100  //The amount of time between fm/fmhd seek callbacks to the MMI

    #define OPTION__AM_TIMEOUT_SEEK_MS 30000
    #define OPTION__AM_SEEK_CALLBACK_RATE_MS 100  //The amount of time between fm/fmhd seek callbacks to the MMI

    #define OPTION__DAB_SUPPORT_DAB_DAB_LINKING
    #define OPTION__DAB_SUPPORT_DAB_DAB_LINKING_A3

    #define OPTION__DAB_SERVICE_LIST_PERSISTENCE
    #define OPTION__FMHD_SEEK_HDLEVEL_THRESHOLD 20
	#define OPTION__AMHD_SEEK_HDLEVEL_THRESHOLD 35//the HD LEVEL undulate of AM is greater than FMHD
    #define OPTION__FMHD_SEEK_OFDM_SAMPLE_NUMBER 0x20
    //#define OPTION__OPERATE_AS_SLAVE_NO_MMI
    //#define OPTION__ADVANCED_METRICS
    #define OPTION__MCU_HARDWARE_SPI
    #define OPTION__DAB_PRESETS_AS_FAVORITES
    //#define OPTION__FM_SHOW_STATION_NAME_PST
   	//#define OPTION__TIME_SETTING
	#define OPTION__MENU_SETTING
	//#define OPTION__RADIODNS
    //#define OPTION__NVMSPI_RATE_MHZ 40
    #define OPTION__PROPERTY_DAB_VALID_RSSI_THRESHOLD 6
    #define OPTION__DAB_VALID_FAST_DETECT_TIME_MS 35
    #define OPTION__DAB_VALID_SYNC_TIME_MS 1200
    #define OPTION__DAB_VALID_ACQ_TIME_MS 2000

    //#define OPTION__DECODE_DAB_ANNOUNCEMENTS
    #define OPTION__DAB_LINK_DISQUALIFIER_SNR_SETTLING_TIME_MS 500
    #define OPTION__DAB_LINK_DISQUALIFIER_SNR_THRESHOLD 5
#endif

#ifdef PLATFORM_F340_DEMOBOARD
	//#define OPTION__IMAGETYPE__DAB_FM_AM
	#define OPTION__IMAGETYPE__DAB_FM
    //#define OPTION__IMAGETYPE__FMHD_AMHD
	//#define OPTION__IMAGETYPE__FMHD
	#define OPTION__REMOVE_FIRMWARE_FUNCTIONS_NOT_USED_SMALL_SDK
    #define OPTION__MINIMAL_FIRMWARE_FUNCTION_IMPLEMENTATION_SMALLER_SDK
    #define OPTION__COMMAND_INPUT_MINIMAL_OPTIONS_SMALLER_SDK
    #define OPTION__REMOVE_SDK_FUNCTIONS_NOT_USED_BY_MMI
    #define OPTION__EXCLUDE_MFGTEST

    #define OPTION__INCLUDE_FRONT_END_TEST_FUNCTIONS
    #define OPTION__BOOT_FROM_FLASH_MINI
    //#define OPTION__INCLUDE_POWER_SAVING_MODE
    //#define OPTION__BOOT_FROM_FLASH_FULL
    #define OPTION__AUDIO_ANALOG_ENABLE
    //#define OPTION__AUDIO_I2S_ENABLE
    //****************************************************
        // Set Master or Slave (Master 1, Slave 0)
        #define OPTION__AUDIO_I2S__MASTER_SLAVE 0
        //Set Sample Rate (32000 - 48000)
        #define OPTION__AUDIO_I2S__SAMPLE_RATE_KHZ 48000
        //Set Sample Size (2 - 24)
        #define OPTION__AUDIO_I2S__SAMPLE_SIZE 16
        //Set Framing Format (I2S 0, DSP 6, Left Justified DSP 7, Left Justified 8, Right Justified 9)
        #define OPTION__AUDIO_I2S__FRAMING_FORMAT 0
    //****************************************************
    //#define OPTION__INTB_ENABLE
    #define OPTION__SMALL_SPI_BUFFER
    #define OPTION__MCU_PLATFORM
    #define OPTION__32BIT_IS_LONG
    #define OPTION__CONVERT_BIG_ENDIAN
    #define OPTION__RDS_DECODE_ADVANCED
    #define OPTION__DECODE_SIS
    #define OPTION__DECODE_PSD
    #define OPTION__DECODE_HD_ALERTS
    #define OPTION__DECODE_DLS
    #define OPTION__FORCE_MEMORY_SPACES
    #define OPTION__DECODE_FMHD_SERVICE_LIST
    #define OPTION__DECODE_DAB_SERVICE_LIST
    #define OPTION__SERVICE_LIST_SMALL
    #define OPTION__DAB_SERVICE_LIST_TIMEOUT_TUNE_MS 3000         //The total time to allow for DAB Tune before Timeout
    #define OPTION__DAB_SERVICE_LIST_SCVLIST_MS 5000              //The total time to allow for DAB Service List Update before timeout
    #define OPTION__DAB_SERVICE_LIST_TIMEOUT_CALLBACK_RATE_MS 100  //The amount of time between dab bandscan callbacks to the MMI

	#define OPTION__DAB_SERVICE_START_TIMEOUT_MS 1200              //The total time to allow for DAB Service Start before Timeout
    #define OPTION__DAB_SERVICE_START_ATTEMPT_RATE_MS 20          //The amount of time between attempting to start a service
    
    #define OPTION__FM_TIMEOUT_SEEK_MS 10000
    #define OPTION__FM_SEEK_CALLBACK_RATE_MS 100  //The amount of time between fm/fmhd seek callbacks to the MMI

    #define OPTION__AM_TIMEOUT_SEEK_MS 10000
    #define OPTION__AM_SEEK_CALLBACK_RATE_MS 100  //The amount of time between fm/fmhd seek callbacks to the MMI

    #define OPTION__DAB_SUPPORT_DAB_DAB_LINKING
    #define OPTION__DAB_SUPPORT_DAB_DAB_LINKING_A3

    #define OPTION__DAB_SERVICE_LIST_PERSISTENCE
    #define OPTION__FMHD_SEEK_HDLEVEL_THRESHOLD 20
	#define OPTION__AMHD_SEEK_HDLEVEL_THRESHOLD 35//the HD LEVEL undulate of AM is greater than FMHD
    #define OPTION__FMHD_SEEK_OFDM_SAMPLE_NUMBER 0x20
    //#define OPTION__OPERATE_AS_SLAVE_NO_MMI
    //#define OPTION__ADVANCED_METRICS
    #define OPTION__MCU_HARDWARE_SPI
    #define OPTION__DAB_PRESETS_AS_FAVORITES
    //#define OPTION__FM_SHOW_STATION_NAME_PST
   	//#define OPTION__TIME_SETTING
	#define OPTION__MENU_SETTING
	//#define OPTION__RADIODNS

    #define OPTION__PROPERTY_DAB_VALID_RSSI_THRESHOLD 6
    #define OPTION__DAB_VALID_FAST_DETECT_TIME_MS 35
    #define OPTION__DAB_VALID_SYNC_TIME_MS 1200
    #define OPTION__DAB_VALID_ACQ_TIME_MS 2000

    //#define OPTION__DECODE_DAB_ANNOUNCEMENTS
    #define OPTION__DAB_LINK_DISQUALIFIER_SNR_SETTLING_TIME_MS 500
    #define OPTION__DAB_LINK_DISQUALIFIER_SNR_THRESHOLD 5
#endif
//**************************************

#ifdef PLATFORM_EVB
    #define OPTION__IMAGETYPE__ALL
    //#define OPTION__REMOVE_FIRMWARE_FUNCTIONS_NOT_USED_SMALL_SDK
    #define OPTION__INCLUDE_FRONT_END_TEST_FUNCTIONS
    #define OPTION__BOOT_FROM_HOST
    //#define OPTION__BOOT_FROM_FLASH
    //#define OPTION__BOOT_FROM_FLASH_MINI
    #define OPTION__AUDIO_ANALOG_ENABLE
    #define OPTION__AUDIO_I2S_ENABLE
    //****************************************************
        // Set Master or Slave (Master 1, Slave 0)
        #define OPTION__AUDIO_I2S__MASTER_SLAVE 0
        //Set Sample Rate (32000 - 48000)
        #define OPTION__AUDIO_I2S__SAMPLE_RATE_KHZ 48000
        //Set Sample Size (2 - 24)
        #define OPTION__AUDIO_I2S__SAMPLE_SIZE 16
        //Set Framing Format (I2S 0, DSP 6, Left Justified DSP 7, Left Justified 8, Right Justified 9)
        #define OPTION__AUDIO_I2S__FRAMING_FORMAT 0
    //****************************************************
    #define OPTION__INTB_ENABLE
    //#define OPTION__FULL_SIZE_SPI_BUFFER
    #define OPTION__SMALL_SPI_BUFFER
    #define OPTION__RDS_DECODE_ADVANCED
    //#define OPTION__RDS_DECODE_BASIC
    #define OPTION__DECODE_SIS
    #define OPTION__DECODE_PSD
    #define OPTION__DECODE_HD_ALERTS
    //#define OPTION__PSD_FORMAT_ID3
    #define OPTION__DECODE_DLS
    #define OPTION__DECODE_FMHD_SERVICE_LIST
    #define OPTION__DECODE_DAB_SERVICE_LIST
    #define	OPTION__SERVICE_LIST_SMALL
    #define OPTION__DAB_SERVICE_LIST_TIMEOUT_TUNE_MS 3000         //The total time to allow for DAB Tune before Timeout
    #define OPTION__DAB_SERVICE_LIST_SCVLIST_MS 5000              //The total time to allow for DAB Service List Update before timeout
    #define OPTION__DAB_SERVICE_LIST_TIMEOUT_CALLBACK_RATE_MS 100  //The amount of time between dab bandscan callbacks to the MMI

	#define OPTION__DAB_SERVICE_START_TIMEOUT_MS 1200              //The total time to allow for DAB Service Start before Timeout
    #define OPTION__DAB_SERVICE_START_ATTEMPT_RATE_MS 20          //The amount of time between attempting to start a service
    
    #define OPTION__FM_TIMEOUT_SEEK_MS 30000
    #define OPTION__FM_SEEK_CALLBACK_RATE_MS 10  //The amount of time between fm/fmhd seek callbacks to the MMI

	#define OPTION__AM_TIMEOUT_SEEK_MS 30000
    #define OPTION__AM_SEEK_CALLBACK_RATE_MS 100  //The amount of time between fm/fmhd seek callbacks to the MMI

    #define OPTION__DAB_SUPPORT_DAB_DAB_LINKING
    #define OPTION__DAB_SUPPORT_DAB_DAB_LINKING_A3

    #define OPTION__DAB_SERVICE_LIST_PERSISTENCE
    #define OPTION__FMHD_SEEK_HDLEVEL_THRESHOLD 20
    #define OPTION__AMHD_SEEK_HDLEVEL_THRESHOLD 35//the HD LEVEL undulate of AM is greater than FMHD
    #define OPTION__FMHD_SEEK_OFDM_SAMPLE_NUMBER 0x20
    
    #define OPTION__PROPERTY_DAB_VALID_RSSI_THRESHOLD 6
    #define OPTION__DAB_VALID_FAST_DETECT_TIME_MS 35
    #define OPTION__DAB_VALID_SYNC_TIME_MS 1200
    #define OPTION__DAB_VALID_ACQ_TIME_MS 2000

    #define OPTION__DECODE_DAB_ANNOUNCEMENTS

    #define OPTION__EXCLUDE_MFGTEST

    #define OPTION__DAB_LINK_DISQUALIFIER_SNR_SETTLING_TIME_MS 500
    #define OPTION__DAB_LINK_DISQUALIFIER_SNR_THRESHOLD 5
#endif


// Image Type Conditionals based on selected build mode
// If FMHD is desired it is assumed that FM mode will also be included as many functions are shared
// If DAB is desired it is assumed that FM mode will also be included as there are compilation complications with removing FM entirely
#ifdef OPTION__IMAGETYPE__FM
    #define OPTION__INCLUDE_MODE__FM
    #undef OPTION__INCLUDE_MODE__DAB
    #undef OPTION__INCLUDE_MODE__FMHD
    #undef OPTION__INCLUDE_MODE__AMHD
    #undef OPTION__INCLUDE_MODE__AM
    #define OPTION__INCLUDE_MODE__ANY
#endif
#ifdef OPTION__IMAGETYPE__DAB_FM
    #define OPTION__INCLUDE_MODE__FM
    #define OPTION__INCLUDE_MODE__DAB
    #undef OPTION__INCLUDE_MODE__FMHD
	#undef OPTION__INCLUDE_MODE__AMHD
	#undef OPTION__INCLUDE_MODE__AM
    #define OPTION__INCLUDE_MODE__ANY
    #undef OPTION__TIME_SETTING
#endif

#ifdef OPTION__IMAGETYPE__DAB_FM_AM
	#define OPTION__INCLUDE_MODE__FM
	#define OPTION__INCLUDE_MODE__DAB
    #undef OPTION__INCLUDE_MODE__FMHD
    #undef OPTION__INCLUDE_MODE__AMHD
	#define OPTION__INCLUDE_MODE__AM
    #define OPTION__INCLUDE_MODE__ANY
    #undef OPTION__TIME_SETTING
	#undef OPTION__MENU_SETTING
#endif

#ifdef OPTION__IMAGETYPE__FMHD
    #define OPTION__INCLUDE_MODE__FM
    #undef OPTION__INCLUDE_MODE__DAB
    #define OPTION__INCLUDE_MODE__FMHD
	#undef OPTION__INCLUDE_MODE__AMHD
	#undef OPTION__INCLUDE_MODE__AM
    #define OPTION__INCLUDE_MODE__ANY
#endif

#ifdef OPTION__IMAGETYPE__FMHD_AMHD
    #define OPTION__INCLUDE_MODE__FM
    #undef OPTION__INCLUDE_MODE__DAB
    #define OPTION__INCLUDE_MODE__FMHD
	#define OPTION__INCLUDE_MODE__AMHD
	#define OPTION__INCLUDE_MODE__AM
    #define OPTION__INCLUDE_MODE__ANY
    #undef OPTION__TIME_SETTING
#endif


#ifdef OPTION__IMAGETYPE__ALL
    #define OPTION__INCLUDE_MODE__FM
    #define OPTION__INCLUDE_MODE__FMHD
    #define OPTION__INCLUDE_MODE__DAB
	#define OPTION__INCLUDE_MODE__AM
	#define OPTION__INCLUDE_MODE__AMHD
    #define OPTION__INCLUDE_MODE__ANY
#endif

#ifdef OPTION__EXCLUDE_MFGTEST
    #undef ATS_EMBED_CODE
	#undef OPTION__UART_DRIVER
#endif

#endif