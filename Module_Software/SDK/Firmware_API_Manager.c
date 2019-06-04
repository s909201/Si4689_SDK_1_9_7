/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   SDK Radio Manager - main radio control logic
   FILE: Firmware_API_Manager.c
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#include "common_types.h"
#include "platform_options.h"
#include "feature_types.h"
#include "si46xx_firmware_api.h"
#include "si46xx_firmware_api_constants.h"
#include "HAL.h"
#include "Firmware_Load_Helpers.h"
#include "Hardware_Calibration_Helpers.h"

#include "Firmware_API_Manager.h"

#include "FMHD_Service_List_Handler.h"
#include "DAB_Service_List_Handler.h"

#include "RDS_Handler.h"
#include "RDS_V4L2_Headers.h"

#include "FMHD_SIS_Handler.h"
#include "FMHD_PSD_Handler.h"
#include "FMHD_Alert_Handler.h"

#include "DAB_DLS_Handler.h"

#include "SDK_Callbacks.h"

#include "hal.h"

#include <stdlib.h>	// Needed for Malloc/Free

// GLOBAL Variables
status_bits _si46xx_status;

#ifdef OPTION__HANDLE_ADVANCED_SERVICES
ServiceList* _service_list = NULL;
#endif

RADIO_MODE_TYPE _current_image_type = UNKNOWN;

uint16_t _current_band_bottom;
uint16_t _current_band_top;
uint16_t _current_band_step;

uint16_t _current_fm_blend_rssi_limits;  // This will be overwritten to force mono

uint32_t _current_audio_service_id;
uint32_t _current_audio_component_id;
uint8_t _last_frequency_index;

fm_metrics _current_fm_metrics;
fmhd_metrics _current_fmhd_metrics;
dab_metrics _current_dab_metrics;
am_metrics _current_am_metrics;
amhd_metrics _current_amhd_metrics;

uint8_t _current_hd_audio_service_as_bitmask;

uint8_t _FM_seek_continue;

uint8_t _AM_seek_continue;


uint8_t _DAB_scan_continue;
uint8_t _DAB_current_browse_service_index;
uint8_t _DAB_service_lost;
uint8_t _service_following_enabled = 0;

uint16_t _ANTCAP_DAB;

uint8_t _dab_favorites_only_browse_enable;

#ifdef OPTION__DAB_SUPPORT_DAB_DAB_LINKING_A3
dab_current_service_links _current_service_links;
#endif

#define FM_SEEK_STEP_SIZE_CONVERSION_FACTOR 10
#define FM_BAND_LIMITS_CONVERSION_FACTOR 10

#define DAB_EVENT_MIN_SVRLIST_PERIOD__NORMAL_VALUE__IN_100MS 10
#define DAB_EVENT_MIN_SVRLIST_PERIOD__DURING_ENSEMBLE_RECONFIG__IN_100MS 1




//******************************************************************************************
// Begin Helper Functions
//******************************************************************************************
RETURN_CODE _set_property(uint8_t group, uint8_t index, uint16_t value)
{
	return set_property__command(((group << 8) | index), value);
}

#ifdef OPTION__INCLUDE_MODE__ANY
RETURN_CODE _get_property(uint8_t group, uint8_t index, uint16_t *value)
{
	RETURN_CODE ret = 0;

	ret = get_property__command(((group << 8) | index));
	ret |= get_property__reply(value);

	return ret;
}
#endif // OPTION__INCLUDE_MODE__ANY

#ifndef OPTION__MINIMAL_FIRMWARE_FUNCTION_IMPLEMENTATION_SMALLER_SDK
RETURN_CODE _set_property_field(uint8_t group, uint8_t index, uint16_t value, uint16_t mask, uint16_t offset)
{
	RETURN_CODE ret = 0;
	uint16_t tempValue = 0;

	ret = _get_property(group, index, &tempValue);

	tempValue = ((tempValue & (~mask)) | (value << offset));

	ret |= _set_property(group, index, tempValue);

	return ret;
}
#endif //OPTION__MINIMAL_FIRMWARE_FUNCTION_IMPLEMENTATION_SMALLER_SDK

//TODO: allow more memory usage to be dynamically allocated for host load on platforms which have memory to spare - to no longer require host_load to use the cmd buffer (limited to 256 bytes)
RETURN_CODE _host_load(RADIO_MODE_TYPE mode)
{
	RETURN_CODE ret = 0;
	uint8_t *firmwareSegment = NULL;
	uint16_t numRead;

	ret = firmwareSetImage(mode);

	if(ret == SUCCESS)
	{
		do{
			numRead = firmwareGetSegment(FIRMWARE_SEGMENT_MAX_LENGTH, &firmwareSegment);

			if(numRead)
			{
				ret |= host_load__command(numRead, firmwareSegment);
				if(ret != SUCCESS)
				{
					return ret;
				}
			}
		}while(numRead != 0);
	}

	return ret;
}

RETURN_CODE _flash_load(RADIO_MODE_TYPE mode)
{
	RETURN_CODE ret = 0;
	uint32_t imageAddr;

	ret = firmwareSetImage(mode);

	if(ret == SUCCESS)
	{
		firmwareGetFlashAddress(&imageAddr);

		ret |= flash_load__command(imageAddr);
	}

	return ret;
}

#ifdef OPTION__BOOT_FROM_HOST
RETURN_CODE _load_firmware__host_load(RADIO_MODE_TYPE mode, uint8_t patchload)
{
	RETURN_CODE ret = 0;

	if(patchload)
	{
		//Load_Init -> Host_Load (Patch)
		ret |= load_init__command();
        if(mode == fmonly)
        {
            ret |= _host_load(patch_fmhd);
        }
        else
        {
            ret |= _host_load((RADIO_MODE_TYPE)((uint8_t)mode | 0xF0));
        }

		// Need to wait 4 ms for the bootloader to patch.
		// Platform specific delay function for 4 ms - defined in HAL
		delay(4);
	}

	//Load_Init -> Host_Load Main image
	ret |= load_init__command();
	ret |= _host_load(mode);
	
	//Boot
	ret |= boot__command();

	return ret;
}
#endif


#ifdef OPTION__NVMSPI_RATE_MHZ
#define SPI_CLOCK_FREQ_PROP_COMMAND_LENGTH 8
RETURN_CODE _adjust_NVMSPI_rate()
{
    uint8_t rawCommand[SPI_CLOCK_FREQ_PROP_COMMAND_LENGTH] = {0x05,0x10,0x00,0x00,0x01,0x00,0x00,0x00};
    uint16_t rate;

    rate = OPTION__NVMSPI_RATE_MHZ * 1000;
    rawCommand[6] = rate & 0xFF;
    rawCommand[7] = rate >> 8;
    return writeCommand(SPI_CLOCK_FREQ_PROP_COMMAND_LENGTH,rawCommand);
}
#endif

#ifdef OPTION__BOOT_FROM_FLASH
//On ROM00 patch load is required for flash load to work.  Leaving the "bool patchload" for future rom versions
RETURN_CODE _load_firmware__flash_load(RADIO_MODE_TYPE mode, uint8_t patchload)
{
	RETURN_CODE ret = 0;

	if(patchload)
	{
		//Load_Init -> Host_Load (Patch)
		ret |= load_init__command();
        if(mode == fmonly)
        {
            ret |= _host_load(patch_fmhd);
        }
        else
        {
            ret |= _host_load((RADIO_MODE_TYPE)((uint8_t)mode | 0xF0));
        }

		// Need to wait 4 ms for the bootloader to patch.
		// delay function for 4 ms - defined in HAL
		delay(4);
	}

    #ifdef OPTION__NVMSPI_RATE_MHZ
        ret |= _adjust_NVMSPI_rate();
    #endif

	//Load_Init -> Flash_Load Main image
	ret |= load_init__command();
	ret |= _flash_load(mode);
	
	//Boot
	ret |= boot__command();

	return ret;
}
#endif



#ifdef OPTION__BOOT_FROM_FLASH_MINI
RETURN_CODE _load_bootloader_patch__flash_load_mini(RADIO_MODE_TYPE mode)
{
    RETURN_CODE ret = 0;
	
	//Load_Init -> Host_Load (Patch (mini))
	ret |= load_init__command();
	ret |= _host_load(patch_mini);

	// Need to wait 4 ms for the bootloader to patch.
	// delay function for 4 ms - defined in HAL
	delay(4);

    //Load_Init -> Flash_Load (Patch (full))
	ret |= load_init__command();
    if(mode == fmonly)
    {
        ret |= _flash_load(patch_fmhd);
    }
    else
    {
        ret |= _flash_load((RADIO_MODE_TYPE)((uint8_t)mode | 0xF0));
    }

	// Need to wait 4 ms for the bootloader to patch.
	// delay function for 4 ms - defined in HAL
	delay(4);

    return ret;
}

//On ROM00 patch load is required for flash load to work.  Leaving the "bool patchload" for future rom versions
RETURN_CODE _load_firmware__flash_load_mini(RADIO_MODE_TYPE mode, uint8_t patchload)
{
	RETURN_CODE ret = 0;

    if(patchload)
	{
	    ret = _load_bootloader_patch__flash_load_mini(mode);
    }

    #ifdef OPTION__NVMSPI_RATE_MHZ
        ret |= _adjust_NVMSPI_rate();
    #endif

	//Load_Init -> Flash_Load Main image
	ret |= load_init__command();
	ret |= _flash_load(mode);
	
	//Boot
	ret |= boot__command();

	return ret;
}

#endif //OPTION__BOOT_FROM_FLASH_MINI

#ifdef OPTION__BOOT_FROM_FLASH_FULL
RETURN_CODE _load_bootloader_patch__host_load_full()
{
    RETURN_CODE ret = 0;
	
	//Load_Init -> Host_Load (Patch (FULL))
	ret |= load_init__command();
	ret |= _host_load(patch_full);

	// Need to wait 4 ms for the bootloader to patch.
	// delay function for 4 ms - defined in HAL
	delay(4);

    return ret;
}

//On ROM00 patch load is required for flash load to work.  Leaving the "bool patchload" for future rom versions
RETURN_CODE _load_firmware__flash_load_full(RADIO_MODE_TYPE mode, uint8_t patchload)
{
	RETURN_CODE ret = 0;

    if(patchload)
	{
	    ret = _load_bootloader_patch__host_load_full();
    }

    #ifdef OPTION__NVMSPI_RATE_MHZ
        ret |= _adjust_NVMSPI_rate();
    #endif

	//Load_Init -> Flash_Load Main image
	ret |= load_init__command();
	ret |= _flash_load(mode);
	
	//Boot
	ret |= boot__command();

	return ret;
}
#endif //OPTION__BOOT_FROM_FLASH_FULL

//******************************************************************************************
// Begin "Private" Functions
//******************************************************************************************

RETURN_CODE _si46xx_initialize(RADIO_MODE_TYPE radio_mode)
{
	RETURN_CODE ret = 0;
	uint8_t ctsien,clk_mode, tr_size, ibias, ctun, ibias_run;
	uint32_t xtal_freq;

	ret = initHardware();
	ret |= audioDisable();

	if(ret == SUCCESS)
	{
		// Get Power_Up args
		ret = calibrationGetPowerUpArgs(&ctsien, &clk_mode, &tr_size, &ibias, &xtal_freq, &ctun, &ibias_run);

		if(ret == SUCCESS)
		{
            //Power_Up
            ret |= power_up__command(ctsien, clk_mode, tr_size, ibias, xtal_freq, ctun, ibias_run, 1);

            if(radio_mode == determine_part)
            {
                return ret;
            }

			#ifdef OPTION__BOOT_FROM_HOST
                ret = _load_firmware__host_load(radio_mode, 1);
			#endif
			#ifdef OPTION__BOOT_FROM_FLASH
				ret = _load_firmware__flash_load(radio_mode, 1);
			#endif
            #ifdef OPTION__BOOT_FROM_FLASH_MINI
                if(radio_mode == patch_firmware_update)
                {
                    ret |= _load_bootloader_patch__flash_load_mini(patch_firmware_update);
                    return ret;
                }
                ret = _load_firmware__flash_load_mini(radio_mode, 1);
            #endif
            #ifdef OPTION__BOOT_FROM_FLASH_FULL
                if(radio_mode == patch_firmware_update)
                {
                    ret |= _load_bootloader_patch__host_load_full();
                    return ret;
                }
                ret = _load_firmware__flash_load_full(radio_mode, 1);
            #endif
		}


		ret |= audioEnable();
	}

	return ret;
}

#ifdef OPTION__INCLUDE_MODE__ANY
RETURN_CODE _si46xx_configure_properties(RADIO_MODE_TYPE radio_mode)
{
	RETURN_CODE ret = 0;
	uint16_t pinConfig = 0;
	uint16_t FE_slope = 0;
	uint16_t FE_intercept = 0;
//	uint16_t FE_slope = 0xFB1E;
//	uint16_t FE_intercept = 0x15B;
	uint8_t FE_config = 0;

	//Configure Mode Specific Properties
	//************************************************************************
	switch (radio_mode)
	{
	case fmonly:
	case fmhd:
#ifdef OPTION__INCLUDE_MODE__FM
		//Configure Front End Calibration
		ret = calibrationGetFrontEndArgs(radio_mode, &FE_slope, &FE_intercept, &FE_config);
		ret |= _set_property(PROP_FM_TUNE_FE_VARM_GROUP, PROP_FM_TUNE_FE_VARM_INDEX, FE_slope);
		ret |= _set_property(PROP_FM_TUNE_FE_VARB_GROUP, PROP_FM_TUNE_FE_VARB_INDEX, FE_intercept);
		ret |= _set_property(PROP_FM_TUNE_FE_CFG_GROUP, PROP_FM_TUNE_FE_CFG_INDEX, FE_config);

        ret |= _set_property(PROP_FM_RDS_INTERRUPT_SOURCE_GROUP, PROP_FM_RDS_INTERRUPT_SOURCE_INDEX, (PROP_FM_RDS_INTERRUPT_SOURCE_RDSRECV_BIT)); // Setup non-Empty RDS fifo to interrupt
        ret |= _set_property(PROP_FM_RDS_INTERRUPT_FIFO_COUNT_GROUP, PROP_FM_RDS_INTERRUPT_FIFO_COUNT_INDEX, 1); // Configure FIFO for 1 packet
        //Enable RDS - only add packets to FIFO is BLOCKB is 1-2 errors or better
        ret |= _set_property(PROP_FM_RDS_CONFIG_GROUP, PROP_FM_RDS_CONFIG_INDEX, (( PROP_FM_RDS_CONFIG_BLETHB_ENUM_BLER_1_2_ERRORS<< PROP_FM_RDS_CONFIG_BLETHB_LSB ) | PROP_FM_RDS_CONFIG_RDSEN_BIT));

        //Adjust the Valid SNR settling time to prevent false seek stop around over-deviated FM
        ret |= _set_property(PROP_FM_VALID_SNR_THRESHOLD_GROUP,PROP_FM_VALID_SNR_THRESHOLD_INDEX,15);
        ret |= _set_property(PROP_FM_VALID_SNR_TIME_GROUP,PROP_FM_VALID_SNR_TIME_INDEX,PROP_FM_VALID_SNR_TIME_SNRVALTIME_RANGE_MAX);

    #ifdef OPTION__INCLUDE_MODE__FMHD
        if(radio_mode == fmhd)
        {
            // Enable interrupt from SIS and Service List(s)
            ret |= _set_property(PROP_HD_EVENT_INTERRUPT_SOURCE_GROUP, PROP_HD_EVENT_INTERRUPT_SOURCE_INDEX, (PROP_HD_EVENT_INTERRUPT_SOURCE_ALERT_INTEN_BIT | PROP_HD_EVENT_INTERRUPT_SOURCE_PSD_INTEN_BIT | PROP_HD_EVENT_INTERRUPT_SOURCE_SIS_INTEN_BIT | PROP_HD_EVENT_INTERRUPT_SOURCE_DSRVLIST_INTEN_BIT | PROP_HD_EVENT_INTERRUPT_SOURCE_ASRVLIST_INTEN_BIT));
            // Choose SIS information to include in BASIC_SIS_TYPE
            #ifdef OPTION__DECODE_SIS
                ret |= _set_property(PROP_HD_EVENT_SIS_CONFIG_GROUP, PROP_HD_EVENT_SIS_CONFIG_INDEX, (PROP_HD_EVENT_SIS_CONFIG_LOCATION_BIT | PROP_HD_EVENT_SIS_CONFIG_NAME_LF_BIT | PROP_HD_EVENT_SIS_CONFIG_NAME_SF_BIT | PROP_HD_EVENT_SIS_CONFIG_ID_BIT));
            #endif
            #ifdef OPTION__DECODE_PSD
                // Enable ALL program services to provide PSD when active
                ret |= _set_property(PROP_HD_PSD_ENABLE_GROUP, PROP_HD_PSD_ENABLE_INDEX, (PROP_HD_PSD_ENABLE_MPS_BIT | PROP_HD_PSD_ENABLE_SPS1_BIT | PROP_HD_PSD_ENABLE_SPS2_BIT | PROP_HD_PSD_ENABLE_SPS3_BIT | PROP_HD_PSD_ENABLE_SPS4_BIT | PROP_HD_PSD_ENABLE_SPS5_BIT | PROP_HD_PSD_ENABLE_SPS6_BIT | PROP_HD_PSD_ENABLE_SPS7_BIT));
                // Enable the supported PSD data types to be read through the PSD_DECODE API
                ret |= _set_property(PROP_HD_PSD_FIELD_MASK_GROUP, PROP_HD_PSD_FIELD_MASK_INDEX, (PROP_HD_PSD_FIELD_MASK_TITLE_BIT | PROP_HD_PSD_FIELD_MASK_ARTIST_BIT | PROP_HD_PSD_FIELD_MASK_ALBUM_BIT | PROP_HD_PSD_FIELD_MASK_GENRE_BIT));
            #endif

            ret |= _set_property(PROP_FM_RSQ_HD_DETECTION_GROUP, PROP_FM_RSQ_HD_DETECTION_INDEX, ((PROP_FM_RSQ_HD_DETECTION_DEFAULT & 0xFF00) | OPTION__FMHD_SEEK_OFDM_SAMPLE_NUMBER));

            #ifdef OPTION__INCLUDE_FRONT_END_TEST_FUNCTIONS
                ret |= _set_property(PROP_HD_TEST_DEBUG_AUDIO_GROUP, PROP_HD_TEST_DEBUG_AUDIO_INDEX, 0); // Test mode for HD split mode disabled - property required elsewhere for ibiquity certification
            #endif

            // Firmware image FMHD_RADIO 3.0.16 has a default value for the audio time alignment which is incorrect.  This needs to be manually set until a new image is released.
            ret |= _set_property(PROP_HD_CODEC_MODE_0_SAMPLES_DELAY_GROUP, PROP_HD_CODEC_MODE_0_SAMPLES_DELAY_INDEX, 3710);
        }
    #endif //OPTION__INCLUDE_MODE__FMHD

        ret |= _get_property(PROP_FM_SEEK_FREQUENCY_SPACING_GROUP,PROP_FM_SEEK_FREQUENCY_SPACING_INDEX,&_current_band_step);
        _current_band_step = (_current_band_step & PROP_FM_SEEK_FREQUENCY_SPACING_FMSKSPACE_MASK);

        ret |= _get_property(PROP_FM_SEEK_BAND_BOTTOM_GROUP,PROP_FM_SEEK_BAND_BOTTOM_INDEX,&_current_band_bottom);
        ret |= _get_property(PROP_FM_SEEK_BAND_TOP_GROUP,PROP_FM_SEEK_BAND_TOP_INDEX,&_current_band_top);
#endif //OPTION__INCLUDE_MODE__FM
		break;
	case dmb:
	case dab:
#ifdef OPTION__INCLUDE_MODE__DAB
		//Configure Front End Calibration
		ret = calibrationGetFrontEndArgs(radio_mode, &FE_slope, &FE_intercept, &FE_config);
		ret |= _set_property(PROP_DAB_TUNE_FE_VARM_GROUP, PROP_DAB_TUNE_FE_VARM_INDEX, FE_slope);
		ret |= _set_property(PROP_DAB_TUNE_FE_VARB_GROUP, PROP_DAB_TUNE_FE_VARB_INDEX, FE_intercept);
		ret |= _set_property(PROP_DAB_TUNE_FE_CFG_GROUP, PROP_DAB_TUNE_FE_CFG_INDEX, FE_config);
        _ANTCAP_DAB = 0; // For Calibrated FE

        #ifdef OPTION__DECODE_DLS
            // Enable DLS
            //TODO: if using advanced services (TDC/MOT) this property needs to be set to enable those items as well
            ret |= _set_property(PROP_DAB_XPAD_ENABLE_GROUP,PROP_DAB_XPAD_ENABLE_INDEX, (PROP_DAB_XPAD_ENABLE_DLS_ENABLE_BIT));
        #endif

        ret |= _set_property(PROP_DAB_EVENT_INTERRUPT_SOURCE_GROUP, PROP_DAB_EVENT_INTERRUPT_SOURCE_INDEX, (PROP_DAB_EVENT_INTERRUPT_SOURCE_RECFG_INTEN_BIT | PROP_DAB_EVENT_INTERRUPT_SOURCE_RECFGWRN_INTEN_BIT | PROP_DAB_EVENT_INTERRUPT_SOURCE_SRVLIST_INTEN_BIT)); // Event Interrupts

        //The current default is too high resulting in missed frequencies on band scan - customizeable threshold for varying antenna/system performance.
        ret |= _set_property(PROP_DAB_VALID_RSSI_THRESHOLD_GROUP, PROP_DAB_VALID_RSSI_THRESHOLD_INDEX, OPTION__PROPERTY_DAB_VALID_RSSI_THRESHOLD);

        //Adjust user defined values for allowed time for qualifying the DAB ensemble before giving up and declaring station invalid.
            //ret |= _set_property(PROP_DAB_VALID_DETECT_TIME_GROUP, PROP_DAB_VALID_DETECT_TIME_INDEX, OPTION__DAB_VALID_FAST_DETECT_TIME_MS); // Quick check is DAB present
            //ret |= _set_property(PROP_DAB_VALID_SYNC_TIME_GROUP, PROP_DAB_VALID_SYNC_TIME_INDEX, OPTION__DAB_VALID_SYNC_TIME_MS); // Allowed time to sync to ensemble
            //ret |= _set_property(PROP_DAB_VALID_ACQ_TIME_GROUP, PROP_DAB_VALID_ACQ_TIME_INDEX, OPTION__DAB_VALID_ACQ_TIME_MS); // Allowed time to acquire the ensemble

        // Set the service list debounce time - no need to do it here, we reset this value at each tune, in order to ensure we have not left it in a bad state by retuning during a reconfig
        //ret |= _set_property(PROP_DAB_EVENT_MIN_SVRLIST_PERIOD_GROUP,PROP_DAB_EVENT_MIN_SVRLIST_PERIOD_INDEX,DAB_EVENT_MIN_SVRLIST_PERIOD__NORMAL_VALUE__IN_100MS); // Force Service List event debounce time
#endif //OPTION__INCLUDE_MODE__DAB

		break;
	case am:
	case amhd:
    #ifdef OPTION__INCLUDE_MODE__AMHD
        if(radio_mode == amhd)
        {
            // Enable interrupt from SIS and Service List(s)
            ret |= _set_property(PROP_HD_EVENT_INTERRUPT_SOURCE_GROUP, PROP_HD_EVENT_INTERRUPT_SOURCE_INDEX, (PROP_HD_EVENT_INTERRUPT_SOURCE_ALERT_INTEN_BIT | PROP_HD_EVENT_INTERRUPT_SOURCE_PSD_INTEN_BIT | PROP_HD_EVENT_INTERRUPT_SOURCE_SIS_INTEN_BIT | PROP_HD_EVENT_INTERRUPT_SOURCE_DSRVLIST_INTEN_BIT | PROP_HD_EVENT_INTERRUPT_SOURCE_ASRVLIST_INTEN_BIT));
            // Choose SIS information to include in BASIC_SIS_TYPE
            #ifdef OPTION__DECODE_SIS
                ret |= _set_property(PROP_HD_EVENT_SIS_CONFIG_GROUP, PROP_HD_EVENT_SIS_CONFIG_INDEX, (PROP_HD_EVENT_SIS_CONFIG_LOCATION_BIT | PROP_HD_EVENT_SIS_CONFIG_NAME_LF_BIT | PROP_HD_EVENT_SIS_CONFIG_NAME_SF_BIT | PROP_HD_EVENT_SIS_CONFIG_ID_BIT));
            #endif
            #ifdef OPTION__DECODE_PSD
                // Enable ALL program services to provide PSD when active
                ret |= _set_property(PROP_HD_PSD_ENABLE_GROUP, PROP_HD_PSD_ENABLE_INDEX, (PROP_HD_PSD_ENABLE_MPS_BIT | PROP_HD_PSD_ENABLE_SPS1_BIT | PROP_HD_PSD_ENABLE_SPS2_BIT | PROP_HD_PSD_ENABLE_SPS3_BIT | PROP_HD_PSD_ENABLE_SPS4_BIT | PROP_HD_PSD_ENABLE_SPS5_BIT | PROP_HD_PSD_ENABLE_SPS6_BIT | PROP_HD_PSD_ENABLE_SPS7_BIT));
                // Enable the supported PSD data types to be read through the PSD_DECODE API
                ret |= _set_property(PROP_HD_PSD_FIELD_MASK_GROUP, PROP_HD_PSD_FIELD_MASK_INDEX, (PROP_HD_PSD_FIELD_MASK_TITLE_BIT | PROP_HD_PSD_FIELD_MASK_ARTIST_BIT | PROP_HD_PSD_FIELD_MASK_ALBUM_BIT | PROP_HD_PSD_FIELD_MASK_GENRE_BIT));
            #endif

            //ret |= _set_property(PROP_FM_RSQ_HD_DETECTION_GROUP, PROP_FM_RSQ_HD_DETECTION_INDEX, ((PROP_FM_RSQ_HD_DETECTION_DEFAULT & 0xFF00) | OPTION__FMHD_SEEK_OFDM_SAMPLE_NUMBER));

           // #ifdef OPTION__INCLUDE_FRONT_END_TEST_FUNCTIONS
           //     ret |= _set_property(PROP_HD_TEST_DEBUG_AUDIO_GROUP, PROP_HD_TEST_DEBUG_AUDIO_INDEX, 0); // Test mode for HD split mode disabled - property required elsewhere for ibiquity certification
           // #endif

            // Firmware image FMHD_RADIO 3.0.16 has a default value for the audio time alignment which is incorrect.  This needs to be manually set until a new image is released.
           // ret |= _set_property(PROP_HD_CODEC_MODE_0_SAMPLES_DELAY_GROUP, PROP_HD_CODEC_MODE_0_SAMPLES_DELAY_INDEX, 3710);
        }
    #endif //OPTION__INCLUDE_MODE__FMHD
        ret |= _get_property(PROP_AM_SEEK_FREQUENCY_SPACING_GROUP,PROP_AM_SEEK_FREQUENCY_SPACING_INDEX,&_current_band_step);
        _current_band_step = (_current_band_step & PROP_AM_SEEK_FREQUENCY_SPACING_AMSKSPACE_MASK);

        ret |= _get_property(PROP_AM_SEEK_BAND_BOTTOM_GROUP,PROP_AM_SEEK_BAND_BOTTOM_INDEX,&_current_band_bottom);
        ret |= _get_property(PROP_AM_SEEK_BAND_TOP_GROUP,PROP_AM_SEEK_BAND_TOP_INDEX,&_current_band_top);
		break;
	default:
		return INVALID_INPUT;
		break;
	}
	//************************************************************************

	//Configure Generic Properties
	//************************************************************************
	//Configure Interrupts :: CTS, DSRV, RDS, DEVNT
    //TODO: fix si46xx_firmware_api_constants.h to include PROP_INT_CTL_ENABLE for RDS
	ret |= _set_property(PROP_INT_CTL_ENABLE_GROUP,PROP_INT_CTL_ENABLE_INDEX, (PROP_INT_CTL_ENABLE_DEVNTIEN_BIT | PROP_INT_CTL_ENABLE_CTSIEN_BIT | PROP_INT_CTL_ENABLE_DSRVIEN_BIT | 0x0004));
	
	//Configure Pins
	#ifdef OPTION__INTB_ENABLE
		pinConfig |= PROP_PIN_CONFIG_ENABLE_INTBOUTEN_BIT;
	#endif
	#ifdef OPTION__AUDIO_I2S_ENABLE
		pinConfig |= PROP_PIN_CONFIG_ENABLE_I2SOUTEN_BIT;
	#endif
	#ifdef OPTION__AUDIO_ANALOG_ENABLE
		pinConfig |= PROP_PIN_CONFIG_ENABLE_DACOUTEN_BIT;
	#endif
	ret |= _set_property(PROP_PIN_CONFIG_ENABLE_GROUP, PROP_PIN_CONFIG_ENABLE_INDEX, pinConfig);

	//Configure digital service interrupt source
	ret |= _set_property(PROP_DIGITAL_SERVICE_INT_SOURCE_GROUP, PROP_DIGITAL_SERVICE_INT_SOURCE_INDEX, (PROP_DIGITAL_SERVICE_INT_SOURCE_DSRVPCKTINT_BIT));



	////Configure the Digital I/O mode settings
	#ifdef OPTION__AUDIO_I2S_ENABLE
    	// Slave mode
    	ret |= _set_property_field(PROP_DIGITAL_IO_OUTPUT_SELECT_GROUP, PROP_DIGITAL_IO_OUTPUT_SELECT_INDEX, OPTION__AUDIO_I2S__MASTER_SLAVE, PROP_DIGITAL_IO_OUTPUT_SELECT_MASTER_MASK, PROP_DIGITAL_IO_OUTPUT_SELECT_MASTER_LSB);
    	// Sample Rate = 48kHz
    	ret |= _set_property(PROP_DIGITAL_IO_OUTPUT_SAMPLE_RATE_GROUP, PROP_DIGITAL_IO_OUTPUT_SAMPLE_RATE_INDEX, OPTION__AUDIO_I2S__SAMPLE_RATE_KHZ);
    	// Sample Size = 16
    	ret |= _set_property_field(PROP_DIGITAL_IO_OUTPUT_FORMAT_GROUP, PROP_DIGITAL_IO_OUTPUT_FORMAT_INDEX, OPTION__AUDIO_I2S__SAMPLE_SIZE, PROP_DIGITAL_IO_OUTPUT_FORMAT_SAMPL_SIZE_MASK, PROP_DIGITAL_IO_OUTPUT_FORMAT_SAMPL_SIZE_LSB);
    	// Framing Format
    	ret |= _set_property_field(PROP_DIGITAL_IO_OUTPUT_FORMAT_GROUP, PROP_DIGITAL_IO_OUTPUT_FORMAT_INDEX, OPTION__AUDIO_I2S__FRAMING_FORMAT, PROP_DIGITAL_IO_OUTPUT_FORMAT_FRAMING_FORMAT_MASK, PROP_DIGITAL_IO_OUTPUT_FORMAT_FRAMING_FORMAT_LSB);
    	// 
	#endif

	// Add any additional property settings desired here - all remaining properties assume defaults and can be changed manually using GetProperty/SetProperty
	//		example: attack/release times, threasholds, etc
	//************************************************************************

	return ret;
}
#endif // OPTION__INCLUDE_MODE__ANY

RETURN_CODE _si46xx_powerdown(void)
{
	return powerDownHardware();
}

#ifdef OPTION__HANDLE_ADVANCED_SERVICES
void _empty_service_list(void)
{
	//Clean up the memory used in the Linked List
	ServiceList* temp;
	while(_service_list != NULL)
	{
		temp = _service_list;
		_service_list = _service_list->next;
		free(temp);
	}
}
#endif

void _empty_status(void)
{
	//Clean up the last values set for the status word
	_si46xx_status.ACFINT = 0;
	_si46xx_status.CTS = 0;
	_si46xx_status.DACQINT = 0;
	//_si46xx_status.DBGINT = 0;
	_si46xx_status.DSRVINT = 0;
	_si46xx_status.ERR_CMD = 0;
	_si46xx_status.RDSINT = 0;
	_si46xx_status.RSQINT = 0;
	_si46xx_status.STCINT = 0;
}

#ifdef OPTION__INCLUDE_MODE__ANY
RETURN_CODE _update_status(void)
{
	return read_status(&_si46xx_status); 
}
#endif //OPTION__INCLUDE_MODE__ANY

#ifdef OPTION__HANDLE_ADVANCED_SERVICES
ServiceList* _deleteNode(ServiceList *currP, uint32_t service_id, uint32_t component_id, GENERAL_SERVICE_TYPE* removedType)
{
	ServiceList *tempNextP;

	//See if we are at end of list.
	if (currP == NULL)
	{
		return NULL;
	}

    // Check to see if current node is one to be deleted.
	if ((currP->service_id == service_id) && (currP->component_id == component_id))
	{
		*removedType = currP->type;

		//Save the next pointer in the node.
		tempNextP = currP->next;

		//Deallocate the node.
		free(currP);

		return tempNextP;
	}

	// Check the rest of the list, fixing the next pointer in case the next node is the one removed.
	currP->next = _deleteNode(currP->next, service_id, component_id, removedType);

	//Return the pointer to where we were called from.  Since we did not remove this node it will be the same.
	return currP;
}
#endif

#ifdef OPTION__INCLUDE_MODE__FM
void _empty_metrics_fm(void)
{
    _current_fm_metrics.FREQUENCY_10KHZ = 0;
    _current_fm_metrics.MULTIPATH = 0;
    _current_fm_metrics.RSSI = 0;
    _current_fm_metrics.SNR = 0;
    _current_fm_metrics.VALID = 0;
}
#endif

#ifdef OPTION__INCLUDE_MODE__AM
void _empty_metrics_am(void)
{
    _current_am_metrics.FREQUENCY_1KHZ = 0;
    _current_am_metrics.MODULATION_INDEX = 0;
    _current_am_metrics.RSSI = 0;
    _current_am_metrics.SNR = 0;
    _current_am_metrics.VALID = 0;
}
#endif//OPTOIN__INCLUDE_MODE__AM

#ifdef OPTION__INCLUDE_MODE__FMHD
void _empty_metrics_fmhd(void)
{
    _current_fmhd_metrics.FREQUENCY_10KHZ = 0;
    _current_fmhd_metrics.MULTIPATH = 0;
    _current_fmhd_metrics.RSSI = 0;
    _current_fmhd_metrics.SNR = 0;
    _current_fmhd_metrics.VALID = 0;
    _current_fmhd_metrics.ACQ = 0;
    _current_fmhd_metrics.AUDIO_SOURCE = 0;
    _current_fmhd_metrics.CDNR = 0;
    _current_fmhd_metrics.DAAI = 0;
	_current_amhd_metrics.HDLOGO = 0;
    //_current_fmhd_metrics.HDDETECTED = 0;
    _current_fmhd_metrics.CURRENT_AUDIO_SERVICE = 0;
    _current_fmhd_metrics.CURRENT_AUDIO_SERVICE__LIST_INDEX = 0xFF;


}
#endif //OPTION__INCLUDE_MODE__FMHD

#ifdef OPTION__INCLUDE_MODE__AMHD
void _empty_metrics_amhd(void)
{
    _current_amhd_metrics.FREQUENCY_1KHZ = 0;
    _current_amhd_metrics.MODULATION_INDEX = 0;
    _current_amhd_metrics.RSSI = 0;
    _current_amhd_metrics.SNR = 0;
    _current_amhd_metrics.VALID = 0;
    _current_amhd_metrics.ACQ = 0;
    _current_amhd_metrics.AUDIO_SOURCE = 0;
    _current_amhd_metrics.CDNR = 0;
    _current_amhd_metrics.DAAI = 0;
	_current_amhd_metrics.HDLOGO = 0;
    //_current_fmhd_metrics.HDDETECTED = 0;
    _current_amhd_metrics.CURRENT_AUDIO_SERVICE = 0;
    _current_amhd_metrics.CURRENT_AUDIO_SERVICE__LIST_INDEX = 0xFF;
}
#endif //OPTION__INCLUDE_MODE__FMHD


#ifdef OPTION__INCLUDE_MODE__DAB
void _empty_metrics_dab(void)
{
    _current_dab_metrics.FREQUENCY_INDEX = 0xFF;
    _current_dab_metrics.RSSI = 0;
    _current_dab_metrics.SNR = 0;
    _current_dab_metrics.VALID = 0;
    _current_dab_metrics.ACQ = 0;
    _current_dab_metrics.CNR = 0;
    _current_dab_metrics.FIC_QUALITY = 0;
    _current_dab_metrics.EID = DAB_METRIC_EID__NOT_SET;
    _current_dab_metrics.CURRENT_AUDIO_SERVICE_LIST__SERVICE_INDEX = DAB_METRIC_AUDIO_SERVICE_LIST__INDEX_NOT_SET;
    _current_dab_metrics.CURRENT_AUDIO_INFO__BIT_RATE = 0;
    _current_dab_metrics.CURRENT_AUDIO_INFO__MODE = DAB_METRIC_AUDIO_SERVICE_LIST__INDEX_NOT_SET;
}
#endif //OPTION__INCLUDE_MODE__DAB

#ifdef OPTION__INCLUDE_MODE__FMHD
#ifdef OPTION__DECODE_SIS
RETURN_CODE _update_SIS_worker(FMHD_SIS_DATA_TYPE updateType)
{
    RETURN_CODE ret = 0;
    fmhd_get_station_info__data fgsi;

    ret = fmhd_get_station_info__command(updateType);
    ret |= fmhd_get_station_info__reply(&fgsi);

    if(ret == SUCCESS)
    {
        updateSIS(fgsi);
    }

    return ret;
}
#endif

RETURN_CODE _update_HD_service_list_worker(hd_get_event_status__data fges)
{
    RETURN_CODE ret = 0;
    get_digital_service_list__data gdsl;

    //TODO: replace if data service support is added
    //if(fges.DSRVLISTINT && fges.DSRVLIST)
    //{
    //    ret = get_digital_service_list__command(CMD_GET_DIGITAL_SERVICE_LIST_ARG_SERTYPE_ENUM_DATA);
    //    ret |= get_digital_service_list__reply(0,&gdsl);
    //    if(ret == SUCCESS)
    //    {
            
    //        updateFMHD_ServiceList_Data(&gdsl, fges.DSRVLISTVER);
    //    }
    //}
    if(fges.ASRVLISTINT && fges.ASRVLIST)
    {
        ret = get_digital_service_list__command(CMD_GET_DIGITAL_SERVICE_LIST_ARG_SERTYPE_ENUM_AUDIO);
        ret |= get_digital_service_list__reply(0,&gdsl);
        if(ret == SUCCESS)
        {
            updateFMHD_ServiceList_Audio(&gdsl, fges.ASRVLISTVER);
        }
    }

    return ret;
}

void _update_current_service_list_index_fmhd()
{
    uint8_t fmhdListIndex;

    for(fmhdListIndex = 0; fmhdListIndex < svcListFull_Audio.SERVICE_COUNT; fmhdListIndex++)
    {
        if(svcListFull_Audio.SERVICE[fmhdListIndex].PROGRAM_PORT_NUMBER == _current_audio_component_id)
        {
            _current_fmhd_metrics.CURRENT_AUDIO_SERVICE__LIST_INDEX = fmhdListIndex;
            break;
        }
        else
        {
            //Not found - clear the reference
            _current_fmhd_metrics.CURRENT_AUDIO_SERVICE__LIST_INDEX = 0xFF;
        }
    }
}

//Commenting out as it is currently unused
/*
#ifdef OPTION__INCLUDE_MODE__AMHD
void _update_current_service_list_index_amhd()
{
    uint8_t amhdListIndex;

    for(amhdListIndex = 0; amhdListIndex < svcListFull_Audio.SERVICE_COUNT; amhdListIndex++)
    {
        if(svcListFull_Audio.SERVICE[amhdListIndex].PROGRAM_PORT_NUMBER == _current_audio_component_id)
        {
            _current_amhd_metrics.CURRENT_AUDIO_SERVICE__LIST_INDEX = amhdListIndex;
            break;
        }
        else
        {
            //Not found - clear the reference
            _current_amhd_metrics.CURRENT_AUDIO_SERVICE__LIST_INDEX = 0xFF;
        }
    }
}
#endif
*/

//Note you cannot assume the SPS will be in order - example: service list could be MPS, SPS1, SPS7
RETURN_CODE _step_to_next_service_hd(uint8_t stepup)
{
    RETURN_CODE ret = 0;
    uint8_t bitMaskTemp = _current_hd_audio_service_as_bitmask;
    uint32_t compIDTemp = _current_audio_component_id;

    if(stepup > 0)
    {
        //Step Up
        while(bitMaskTemp != 0x80)
        {
            bitMaskTemp = bitMaskTemp << 1;
            compIDTemp ++;
            if(bitMaskTemp & svcListFast.AUDIO_SERVICE_PRESENT_BITMASK)
            {
                ret = StartProcessingChannel(SERVICE_TYPE_HD_AUDIO, 0, compIDTemp, NULL);
                if(ret == SUCCESS)
                {
					if(_current_image_type == fmhd)
					{
                    	_current_fmhd_metrics.CURRENT_AUDIO_SERVICE = _current_audio_component_id; //Force metrics for fast switching
                    	_update_current_service_list_index_fmhd();
					}
                #ifdef OPTION__INCLUDE_MODE__AMHD
					else if(_current_image_type == amhd)
					{
                    	_current_amhd_metrics.CURRENT_AUDIO_SERVICE = _current_audio_component_id; //Force metrics for fast switching
                    	_update_current_service_list_index_fmhd();
					}
                #endif
                }
                return ret;
            }
        }
    }
    else
    {
        //Step Down
        while(bitMaskTemp != 0x01)
        {
            bitMaskTemp = bitMaskTemp >> 1;
            compIDTemp --;
            if(bitMaskTemp & svcListFast.AUDIO_SERVICE_PRESENT_BITMASK)
            {
                ret = StartProcessingChannel(SERVICE_TYPE_HD_AUDIO, 0, compIDTemp, NULL);
                if(ret == SUCCESS)
                {
					if(_current_image_type == fmhd)
					{
                    	_current_fmhd_metrics.CURRENT_AUDIO_SERVICE = _current_audio_component_id; //Force metrics for fast switching
                    	_update_current_service_list_index_fmhd();
					}
                #ifdef OPTION__INCLUDE_MODE__AMHD
					else if(_current_image_type == amhd)
					{
                    	_current_amhd_metrics.CURRENT_AUDIO_SERVICE = _current_audio_component_id; //Force metrics for fast switching
                    	_update_current_service_list_index_fmhd();
					}
                #endif
                }
                return ret;
            }
        }
    }
    return INVALID_INPUT;
}
#endif //OPTION__INCLUDE_MODE__FMHD

#ifdef OPTION__INCLUDE_MODE__FM
#define NUM_STC_CHECKS_BEFORE_TIMEOUT 3
RETURN_CODE _FM_confirm_seek_complete()
{
    RETURN_CODE ret = SUCCESS;
    uint16_t timeout;
    uint16_t prevFrequency = 0;
    uint8_t prevFreqCount = 0;

    // Confirm tune complete
    timeout = OPTION__FM_TIMEOUT_SEEK_MS;
    while(((SeekTuneCompleteCheck() == 0) && (timeout > 0)) && (_FM_seek_continue == 1) && (ret == SUCCESS))
    {
        delay(OPTION__FM_SEEK_CALLBACK_RATE_MS);
        timeout -= OPTION__FM_SEEK_CALLBACK_RATE_MS;
        ret |= UpdateMetrics();
        //*************************************************************
        // Workaround to avoid waiting for timeout if STC doesn't get set - SI4680-1557
        //*************************************************************
        switch(_current_image_type)
        {
            case fmonly:
                if(prevFrequency == _current_fm_metrics.FREQUENCY_10KHZ)
                {
                    prevFreqCount++;
                }
                prevFrequency = _current_fm_metrics.FREQUENCY_10KHZ;
                break;
            #ifdef OPTION__INCLUDE_MODE__FMHD
                case fmhd:
                    if(prevFrequency == _current_fmhd_metrics.FREQUENCY_10KHZ)
                    {
                        prevFreqCount++;
                    }
                    prevFrequency = _current_fmhd_metrics.FREQUENCY_10KHZ;
                    break;
            #endif
        }
        //*************************************************************
        CALLBACK_Updated_Data(FM_SEEK_PROCESS_UPDATE); // Hands off control to the MMI code for UI update (button checks) - opportunity to cancel the scan
        
        if(prevFreqCount > NUM_STC_CHECKS_BEFORE_TIMEOUT){return TIMEOUT;}
    }

    return ret;
}

    #ifdef OPTION__INCLUDE_MODE__FMHD
    RETURN_CODE _FMHD_confirm_seek_complete(uint8_t resetAfterInitial, uint8_t seekup, uint16_t initialFreq)
    {
        RETURN_CODE ret = SUCCESS;
        uint16_t timeout;
        uint16_t prevFrequency = 0;
        uint8_t prevFreqCount = 0;

        // Confirm tune complete
        timeout = OPTION__FM_TIMEOUT_SEEK_MS;
        while(((SeekTuneCompleteCheck() == 0) && (timeout > 0)) && (_FM_seek_continue == 1) && (ret == SUCCESS))
        {
            delay(OPTION__FM_SEEK_CALLBACK_RATE_MS);
            timeout -= OPTION__FM_SEEK_CALLBACK_RATE_MS;
            ret |= UpdateMetrics();
            //*************************************************************
            // Workaround to avoid waiting for timeout if STC doesn't get set - SI4680-1557
            //*************************************************************
            if(prevFrequency == _current_fmhd_metrics.FREQUENCY_10KHZ)
            {
                prevFreqCount++;
            }
            prevFrequency = _current_fmhd_metrics.FREQUENCY_10KHZ;
            //*************************************************************
            if(prevFreqCount > NUM_STC_CHECKS_BEFORE_TIMEOUT)
            {
                ret = fm_am_tune_freq__command(SHARED_FUNCTION_MODE_FM, 0,CMD_FM_TUNE_FREQ_ARG_TUNE_MODE_ENUM_TUNE_HYBRID,0,_current_fmhd_metrics.FREQUENCY_10KHZ,1, 0); // force ANTCAP to 1 for best performance
                return TIMEOUT;
            }
            if(resetAfterInitial != 0)
            {
            if(((seekup > 0) && (prevFrequency >= initialFreq)) || ((seekup == 0) && (prevFrequency <= initialFreq)))
            {
                ret = fm_rsq_status__command(0,0,1,1); //We need to cancel the ongoing seek
                ret |= fm_am_tune_freq__command(SHARED_FUNCTION_MODE_FM, 0,CMD_FM_TUNE_FREQ_ARG_TUNE_MODE_ENUM_TUNE_HYBRID,0,initialFreq,1, 0); // force ANTCAP to 1 for best performance
                return TIMEOUT;
            }
            }

            CALLBACK_Updated_Data(FM_SEEK_PROCESS_UPDATE); // Hands off control to the MMI code for UI update (button checks) - opportunity to cancel the scan
        }

        return ret;
    }
    #endif //OPTION__INCLUDE_MODE__FMHD

#endif //OPTION__INCLUDE_MODE__FM

#ifdef OPTION__INCLUDE_MODE__AM
#define NUM_STC_CHECKS_BEFORE_TIMEOUT 3
RETURN_CODE _AM_confirm_seek_complete()
{
    RETURN_CODE ret = SUCCESS;
    uint16_t timeout;

    // Confirm tune complete
    timeout = OPTION__AM_TIMEOUT_SEEK_MS;
    while(((SeekTuneCompleteCheck() == 0) && (timeout > 0)) && (_AM_seek_continue == 1) && (ret == SUCCESS))
    {
        delay(OPTION__AM_SEEK_CALLBACK_RATE_MS);
        timeout -= OPTION__AM_SEEK_CALLBACK_RATE_MS;
        ret = UpdateMetrics();   
        CALLBACK_Updated_Data(AM_SEEK_PROCESS_UPDATE); // Hands off control to the MMI code for UI update (button checks) - opportunity to cancel the scan
    }

    ret |= UpdateMetrics();

    return ret;
}
#endif//OPTION__INCLUDE_MODE__AM

//Commenting out as it is currently unused
/*
#ifdef OPTION__INCLUDE_MODE__AMHD
RETURN_CODE _AMHD_confirm_seek_complete(uint8_t resetAfterInitial, uint8_t seekup, uint16_t initialFreq)
{
    RETURN_CODE ret = SUCCESS;
    uint16_t timeout;
    uint16_t prevFrequency = 0;
    uint8_t prevFreqCount = 0;

    // Confirm tune complete
    timeout = OPTION__AM_TIMEOUT_SEEK_MS;
    while(((SeekTuneCompleteCheck() == 0) && (timeout > 0)) && (_AM_seek_continue == 1) && (ret == SUCCESS))
    {
        delay(OPTION__AM_SEEK_CALLBACK_RATE_MS);
        timeout -= OPTION__AM_SEEK_CALLBACK_RATE_MS;
        ret |= UpdateMetrics();
        //*************************************************************
        // Workaround to avoid waiting for timeout if STC doesn't get set - SI4680-1557
        //*************************************************************
        if(prevFrequency == _current_amhd_metrics.FREQUENCY_1KHZ)
        {
            prevFreqCount++;
        }
        prevFrequency = _current_amhd_metrics.FREQUENCY_1KHZ;
        //*************************************************************
        if(prevFreqCount > NUM_STC_CHECKS_BEFORE_TIMEOUT)
        {
            ret = fm_am_tune_freq__command(SHARED_FUNCTION_MODE_AM, 0,CMD_AM_TUNE_FREQ_ARG_TUNE_MODE_ENUM_TUNE_HYBRID,0,_current_amhd_metrics.FREQUENCY_1KHZ,1, 0); // force ANTCAP to 1 for best performance
            return TIMEOUT;
        }
        if(resetAfterInitial != 0)
        {
	        if(((seekup > 0) && (prevFrequency >= initialFreq)) || ((seekup == 0) && (prevFrequency <= initialFreq)))
	        {
	            ret = am_rsq_status__command(0,0,1,1); //We need to cancel the ongoing seek
	            ret |= fm_am_tune_freq__command(SHARED_FUNCTION_MODE_AM, 0,CMD_AM_TUNE_FREQ_ARG_TUNE_MODE_ENUM_TUNE_HYBRID,0,initialFreq,1, 0); // force ANTCAP to 1 for best performance
	            return TIMEOUT;
	        }
        }

        CALLBACK_Updated_Data(AM_SEEK_PROCESS_UPDATE); // Hands off control to the MMI code for UI update (button checks) - opportunity to cancel the scan
    }

    return ret;
}
#endif //OPTION__INCLUDE_MODE__AMHD
*/

#ifdef OPTION__INCLUDE_MODE__DAB
RETURN_CODE _DAB_tune(uint8_t freq_index)
{
    RETURN_CODE ret = 0;

    ret |= dab_tune_freq__command(0,freq_index,_ANTCAP_DAB);
    _empty_metrics_dab();

    //_current_audio_service_id = 0;
    //_current_audio_component_id = 0;
    if(ret == SUCCESS)
    {
        _current_dab_metrics.FREQUENCY_INDEX = freq_index;
        DAB_service_list_updated_for_current_freq = 0;

        // Set the service list debounce time back to the default
        //ret |= _set_property(PROP_DAB_EVENT_MIN_SVRLIST_PERIOD_GROUP,PROP_DAB_EVENT_MIN_SVRLIST_PERIOD_INDEX,DAB_EVENT_MIN_SVRLIST_PERIOD__NORMAL_VALUE__IN_100MS); // Force Service List event debounce time
    }

    return ret;
}

RETURN_CODE _DAB_confirm_tune_complete(uint8_t provideCallback, uint8_t fullCheck)
{
    RETURN_CODE ret = 0;
    dab_digrad_status__data dab_ds;
    dab_get_ensemble_info__data dgeid;
    uint16_t timeout;

    // Confirm tune complete
    timeout = OPTION__DAB_SERVICE_LIST_TIMEOUT_TUNE_MS;
    while(((SeekTuneCompleteCheck() == 0) && (timeout > 0)) && (_DAB_scan_continue == 1))
    {
        delay(OPTION__DAB_VALID_FAST_DETECT_TIME_MS);
        timeout -= OPTION__DAB_VALID_FAST_DETECT_TIME_MS;
        if(provideCallback > 0)
        {
            CALLBACK_Updated_Data(DAB_TUNE_SCAN_PROCESS_UPDATE); // Hands off control to the MMI code for UI update (button checks) - opportunity to cancel the scan
        }
    }

    // Confirm a good frequency was found
    //ret |= UpdateMetrics(); // Removed because we call this function from Update metrics
    ret = dab_digrad_status__command(0,0,0,0);    // Dont STC_ACK as we use it in the main loop to confirm we are tuned.        
    ret |= dab_digrad_status__reply(&dab_ds);

    if(fullCheck > 0)
    {
        if(ret == SUCCESS)
        {
            if(!((dab_ds.ACQ > 0) && (dab_ds.VALID > 0)))
            {
                return TIMEOUT; // Bad freq
            }
        }

        ret |= dab_get_ensemble_info__command();
        ret |= dab_get_ensemble_info__reply(&dgeid);

        _current_dab_metrics.EID = dgeid.EID;
    }
    else
    {
        if(ret == SUCCESS)
        {
            if(!(dab_ds.VALID > 0))
            {
                return TIMEOUT; // Bad freq
            }
        }
    }
    return ret;
}

RETURN_CODE _DAB_confirm_service_list_complete(uint8_t provideCallback)
{
    RETURN_CODE ret = 0;
    uint16_t timeout;        

    //Confirm service list received
    timeout = OPTION__DAB_SERVICE_LIST_SCVLIST_MS;
    while((timeout > 0) && (_DAB_scan_continue == 1))
    {
        ret |= UpdateServiceList();

        if(DAB_service_list_updated_for_current_freq == 1)
        {
            return ret;
        }

        delay(OPTION__DAB_SERVICE_LIST_TIMEOUT_CALLBACK_RATE_MS);
        timeout -= OPTION__DAB_SERVICE_LIST_TIMEOUT_CALLBACK_RATE_MS;
        if(provideCallback > 0)
        {
            CALLBACK_Updated_Data(DAB_TUNE_SCAN_PROCESS_UPDATE); // Hands off control to the MMI code for UI update (button checks) - opportunity to cancel the scan
        }
    }

    return TIMEOUT;
}

RETURN_CODE _DAB_update_metrics_current_service_in_list()
{
    RETURN_CODE ret = 0;
    uint8_t tempServiceIndex = 0;

    ret = findServiceInList(_current_audio_service_id, _current_audio_component_id,0,1, _current_dab_metrics.FREQUENCY_INDEX, &tempServiceIndex); 

	if(ret == SUCCESS)
	{
		_current_dab_metrics.CURRENT_AUDIO_SERVICE_LIST__SERVICE_INDEX = tempServiceIndex;
	}
    else
    {
        _current_dab_metrics.CURRENT_AUDIO_SERVICE_LIST__SERVICE_INDEX = 0xFF;

        //current service not found in the new list - notify the MMI
        CALLBACK_Updated_Data(EVENT_CURRENT_SERVICE_NO_LONGER_AVAILABLE);
    }

    BrowseServicesReset_DAB();

    return ret;
}

RETURN_CODE _DAB_tune_full_process(uint8_t freqIndex)
{
	RETURN_CODE ret = 0;

    _service_following_enabled = 0; //We want to disable service following until we are sitting on an ensemble with a service started
	ret = _DAB_tune(freqIndex);

    if(ret == SUCCESS)
    {
        // Confirm tune complete
        ret = _DAB_confirm_tune_complete(1,1);

        if(ret == TIMEOUT)
        {
            return TIMEOUT; // no good frequency found - move on in scan
        }

        if(ret == SUCCESS)
        {
            ret = _DAB_confirm_service_list_complete(1);
        }
    }

	return ret;
}

#ifdef OPTION__DAB_SUPPORT_DAB_DAB_LINKING_A3
void _service_linking_clear_service_links()
{   
    //No need to clear the memory for the links themselves as they will be only be used when the NUM_LINKS is non-zero and they will have been overwritten before incrementing NUM_LINKS
    _current_service_links.NUM_LINKS = 0;

}
#endif

RETURN_CODE _DAB_start_service_worker(uint32_t serviceId,uint16_t componentId, uint8_t freqIndex, uint8_t forceRetune)
{
    RETURN_CODE ret = 0;
    uint16_t timeout;

    if((_current_dab_metrics.FREQUENCY_INDEX != freqIndex) || (forceRetune))
	{
        CALLBACK_Updated_Data(DAB_TUNE_REQUIRED_UPDATE);
        _DAB_scan_continue = 1;
		ret = _DAB_tune(freqIndex);
	}

    ret = _DAB_confirm_tune_complete(0,1);

	if(ret == SUCCESS) 
	{
        delay(OPTION__DAB_LINK_DISQUALIFIER_SNR_SETTLING_TIME_MS); // Allow for SNR to settle

        ret = UpdateMetrics();

        if((ret == SUCCESS) && (_current_dab_metrics.SNR >= OPTION__DAB_LINK_DISQUALIFIER_SNR_THRESHOLD))
        {
            timeout = OPTION__DAB_SERVICE_START_TIMEOUT_MS;
            do
            {
                delay(OPTION__DAB_SERVICE_START_ATTEMPT_RATE_MS);
                timeout -= OPTION__DAB_SERVICE_START_ATTEMPT_RATE_MS;
                ret = StartProcessingChannel(SERVICE_TYPE_DAB_AUDIO, serviceId, componentId, 0);
            }while((ret != SUCCESS) && (timeout > 0));

            ret = _DAB_confirm_service_list_complete(0);

            ret = _DAB_update_metrics_current_service_in_list();
            if(ret == SUCCESS)
            {
                _service_following_enabled = 1; //We want to enable service following while we are dealing with starting services
                return SUCCESS;
            }
        }
        else
        {
            return TIMEOUT;
        }

    }


    return ret;
}

#ifdef OPTION__DAB_SUPPORT_DAB_DAB_LINKING_A3
RETURN_CODE _DAB_start_service_A3_helper()
{
    RETURN_CODE ret = 0;
    dab_service_list_element tempListElement;
    uint8_t foundServiceListIndex = 0;
    uint8_t i;

    // We have failed to start all service candidates with SID=SID.  Now try the linked services (A3)
    for(i=0;i<_current_service_links.NUM_LINKS;i++)
    {
        
        ret = _DAB_start_service_worker(_current_service_links.LINKS[i].SERVICE_ID, _current_service_links.LINKS[i].COMPONENT_ID, _current_service_links.LINKS[i].FREQUENCY_INDEX, 1); //Always force a re-tune for A3 candidates
        if(ret == SUCCESS)
        {
            return ret;
        }
        else if(ret != TIMEOUT)
        {
            // Give it one more try to see if the ComponentID was not matching the expected value - we would have tuned above so we can check the database for the service
            ret = findServiceInList(_current_service_links.LINKS[i].SERVICE_ID, _current_service_links.LINKS[i].COMPONENT_ID,1,1, _current_service_links.LINKS[i].FREQUENCY_INDEX, &foundServiceListIndex);
            if(ret == SUCCESS)
            {
                ret = getServiceListElement(svcListDAB.SERVICE_OFFSETS[foundServiceListIndex], &tempListElement);

		        if(ret == SUCCESS)
                {
                    ret = _DAB_start_service_worker(tempListElement.SERVICE_ID, tempListElement.COMPONENT_ID, tempListElement.FREQUENCY_INDEX, 0);
                    if(ret == SUCCESS)
                    {
                        return ret;
                    }
                }
            }

        }
    }

    return ret;
}
#endif

RETURN_CODE _DAB_start_service_from_list(uint8_t servicelistIndex)
{
    RETURN_CODE ret = 0;
    dab_service_list_element masterListElement;
    dab_service_list_element tempListElement;
    uint8_t linkedIndex;

    //Variables for finding the list of serviceListIndexes to check
    uint8_t foundServiceListIndex = 0;
    uint8_t candidateServices[DAB_SERVICE_LIST__MAX_NUMBER_OF_ENSEMBLE_CANDIDATE_FREQUENCIES_TO_ATTEMPT_AT_SERVICE_START] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    uint8_t numCandidateServiceIndexes = 0;
    uint8_t currentServiceCandidate = 0;

    uint8_t ensembleFrequencyIndexCandidates[DAB_SERVICE_LIST__MAX_NUMBER_OF_ENSEMBLE_CANDIDATE_FREQUENCIES_TO_ATTEMPT_AT_SERVICE_START] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    int8_t ensembleFrequencyIndexRF[DAB_SERVICE_LIST__MAX_NUMBER_OF_ENSEMBLE_CANDIDATE_FREQUENCIES_TO_ATTEMPT_AT_SERVICE_START] =         {0,    0,    0,    0,    0,    0,    0,    0,    0,    0};
    uint8_t numFrequencyIndexCandidates = 0;

    uint8_t i,j,k=0;


    if((svcListDAB.SERVICE_COUNT > 0) && (servicelistIndex < svcListDAB.SERVICE_COUNT))
    {
        _service_following_enabled = 0; //We want to disable service following while we are dealing with starting services
		ret = getServiceListElement(svcListDAB.SERVICE_OFFSETS[servicelistIndex], &masterListElement);

		if(ret == SUCCESS)
        {
            //Add the desired index to the candidate index array
            candidateServices[numCandidateServiceIndexes++] = servicelistIndex;

            //Find any duplicated copies of the desired service from the list to our candidates
            do
            {
                ret = findServiceInList(masterListElement.SERVICE_ID, masterListElement.COMPONENT_ID,0,0, masterListElement.FREQUENCY_INDEX, &foundServiceListIndex);
                if(ret == SUCCESS)
                {
                    candidateServices[numCandidateServiceIndexes] = foundServiceListIndex;
                    numCandidateServiceIndexes++;
                    foundServiceListIndex++; //Need to increment or we would search starting at the already found position.
                }
                else
                {
                    break;
                }
            }while(numCandidateServiceIndexes < DAB_SERVICE_LIST__MAX_NUMBER_OF_ENSEMBLE_CANDIDATE_FREQUENCIES_TO_ATTEMPT_AT_SERVICE_START);


            //Now go through all service list indexes to determine the RF ensemble index for that candidate
            for(currentServiceCandidate = 0; currentServiceCandidate < numCandidateServiceIndexes; currentServiceCandidate++)
            {
                ret = getServiceListElement(svcListDAB.SERVICE_OFFSETS[candidateServices[currentServiceCandidate]], &tempListElement);

		        if(ret == SUCCESS)
                {

                    //Compile list of ensemble indexes we should check for RF ranking
                    if(numFrequencyIndexCandidates < DAB_SERVICE_LIST__MAX_NUMBER_OF_ENSEMBLE_CANDIDATE_FREQUENCIES_TO_ATTEMPT_AT_SERVICE_START)
                    {
                        ensembleFrequencyIndexCandidates[numFrequencyIndexCandidates++] = tempListElement.FREQUENCY_INDEX;
                    }
                    else
                    {
                        break;
                    }

                    #ifdef OPTION__DAB_SUPPORT_DAB_DAB_LINKING
                        //Add any items recieved through service linkign info
                        for(linkedIndex = 0; linkedIndex < DAB_SERVICE_LIST__MAX_NUMBER_OF_LINKED_FREQUENCIES; linkedIndex ++)
                        {
                            if(tempListElement.FREQUENCY_INDEXES_LINKED[linkedIndex] != DAB_SERVICE_LIST__LINKED_INDEX_DEFAULT)
                            {
                                if(numFrequencyIndexCandidates < DAB_SERVICE_LIST__MAX_NUMBER_OF_ENSEMBLE_CANDIDATE_FREQUENCIES_TO_ATTEMPT_AT_SERVICE_START)
                                {
                                    ensembleFrequencyIndexCandidates[numFrequencyIndexCandidates++] = tempListElement.FREQUENCY_INDEXES_LINKED[linkedIndex];
                                }
                                else
                                {
                                    break;
                                }

                            }
                            else
                            {
                                break;
                            }
                        }
                    #endif // OPTION__DAB_SUPPORT_DAB_DAB_LINKING
                }
            }

            //remove duplicates from the rf ensemble list
            while(i<(numFrequencyIndexCandidates-1))
            {
                j=i+1;
                while(j<numFrequencyIndexCandidates)
                {
                    if(ensembleFrequencyIndexCandidates[i] == ensembleFrequencyIndexCandidates[j])
                    {
                        k=j;
                        while(k<numFrequencyIndexCandidates)
                        {
                            ensembleFrequencyIndexCandidates[k] = ensembleFrequencyIndexCandidates[k+1];
                            k++;
                        }
                        numFrequencyIndexCandidates--;
                        
                    }
                    else
                    {
                        j++;
                    }
                }
                i++;
            }

            //Do a tune/RF check on all available candidates if there is more than one choice
            if(numFrequencyIndexCandidates > 1)
            {
                CALLBACK_Updated_Data(DAB_TUNE_REQUIRED_UPDATE);
                //We need to do this as fast as possible - specific code for this RF check
                ret = _set_property(PROP_DAB_VALID_SYNC_TIME_GROUP, PROP_DAB_VALID_SYNC_TIME_INDEX, PROP_DAB_VALID_SYNC_TIME_MS_RANGE_MIN);
                ret = _set_property(PROP_DAB_VALID_ACQ_TIME_GROUP, PROP_DAB_VALID_ACQ_TIME_INDEX, PROP_DAB_VALID_ACQ_TIME_MS_RANGE_MIN);


                for(i=0;i<numFrequencyIndexCandidates;i++)
                {
                    _DAB_scan_continue = 1;
    		        ret = _DAB_tune(ensembleFrequencyIndexCandidates[i]);
                    ret |= _DAB_confirm_tune_complete(0,0);

                    if(ret == SUCCESS)
                    {
                        ret = UpdateMetrics();
                        ensembleFrequencyIndexRF[i] = _current_dab_metrics.RSSI;
                    }
                    else
                    {
                        ensembleFrequencyIndexRF[i] = CMD_DAB_DIGRAD_STATUS_REP_RSSI_MIN;
                    }
                }

                ret = _set_property(PROP_DAB_VALID_SYNC_TIME_GROUP, PROP_DAB_VALID_SYNC_TIME_INDEX, OPTION__DAB_VALID_SYNC_TIME_MS);    // Go back to the user defined value
                ret = _set_property(PROP_DAB_VALID_ACQ_TIME_GROUP, PROP_DAB_VALID_ACQ_TIME_INDEX, OPTION__DAB_VALID_ACQ_TIME_MS);       // Go back to the user defined value
            

                //Sort the candidate ensembles by strongest RF
                //j is being reused as the swapped indicator in the bubble sort.
                //k is being reused as the temp variable for swaps
                do
                {
                    j=0;
                    for(i=1;i<numFrequencyIndexCandidates;i++)
                    {
                        if(ensembleFrequencyIndexRF[i-1] < ensembleFrequencyIndexRF[i])
                        {
                            k = ensembleFrequencyIndexRF[i-1];
                            ensembleFrequencyIndexRF[i-1] = ensembleFrequencyIndexRF[i];
                            ensembleFrequencyIndexRF[i] = k;
                            k = ensembleFrequencyIndexCandidates[i-1];
                            ensembleFrequencyIndexCandidates[i-1] = ensembleFrequencyIndexCandidates[i];
                            ensembleFrequencyIndexCandidates[i] = k;
                            j = 1; // we swapped, will need to loop again
                        }
                    }
                }while(j > 0);

            }
            

            //Start Attempting Component start
            for(i=0;i<numFrequencyIndexCandidates;i++)
            {
                //NOTE: numFrequencyIndexCandidates - 1 will force a retune if we previously had to do a RF level check because of more than 1 candidate
                ret = _DAB_start_service_worker(masterListElement.SERVICE_ID,masterListElement.COMPONENT_ID,ensembleFrequencyIndexCandidates[i], (numFrequencyIndexCandidates - 1));
                
                if(ret == SUCCESS)
                {
                    return ret;
                }
            }

            #ifdef OPTION__DAB_SUPPORT_DAB_DAB_LINKING_A3
                if(_DAB_start_service_A3_helper() == SUCCESS)
                {
                    return SUCCESS;
                }
            #endif

            return TIMEOUT;
        }
    }

    return INVALID_INPUT;
}


RETURN_CODE _return_service_string_info_from_service_list(uint8_t service_index, uint8_t* service_name, uint8_t* service_name_encoding, uint8_t* service_pty)
{
	RETURN_CODE ret = 0;
    dab_service_list_element tempListElement;

    ClearMemory(service_name, DAB_SERVICE_LIST_SERVICE_LABEL__SIZE);
    *service_name_encoding = 0;
    *service_pty = 0;

    if(service_index < svcListDAB.SERVICE_COUNT)
    {
		ret = getServiceListElement(svcListDAB.SERVICE_OFFSETS[service_index], &tempListElement);

		if(ret == SUCCESS)
		{
			//There is only one component for this service or the component info did not exist - just show the service info.
			CpyMemory(service_name, tempListElement.SERVICE_NAME, DAB_SERVICE_LIST_SERVICE_LABEL__SIZE);
			*service_name_encoding = tempListElement.SERVICE_NAME_ENCODING;				
			*service_pty = tempListElement.SERVICE_PTY;
		}
    }
	else
	{
		return INVALID_INPUT;
	}

	return ret;
}

#ifdef OPTION__DAB_SUPPORT_DAB_DAB_LINKING
#define DAB_FREQ_INFO_MAX_ITEMS 20
typedef struct _dab_frequency_info__dab_dab_linking_element
{
    uint8_t NUM_ELEMENTS;
    uint8_t INDEX_ARRAY[DAB_FREQ_INFO_MAX_ITEMS];
    uint16_t EID_ARRAY[DAB_FREQ_INFO_MAX_ITEMS];
}dab_frequency_info__dab_dab_linking_element;

dab_frequency_info__dab_dab_linking_element _freqInfo; //Global variable to avoid pushing this on the stack

#define RNM__DAB_ENSEMBLE 0
#define RNM__DAB_ENSEMBLE_ALT 1

RETURN_CODE _service_linking_update_freq_info()
{
    RETURN_CODE ret = 0;
    uint8_t i;

    dab_get_freq_info__data dgfid;
    dab_fi_element tempFiElement;

    //Need local memory to copy the frequency info to as it could change between start and end of processing
    _freqInfo.NUM_ELEMENTS = 0;
    
    //First check for matching EIDs (MFN): EID=EID, SID=SID
    ret = dab_get_freq_info__command();
    ret |= dab_get_freq_info__reply(&dgfid);

    if((ret == SUCCESS) && (dgfid.NUM_ELEMENTS > 0))
    {
        for(i = 0; i < dgfid.NUM_ELEMENTS; i++)
        {
            tempFiElement = dgfid.PAYLOAD[i];

            if((tempFiElement.RNM == RNM__DAB_ENSEMBLE) || (tempFiElement.RNM == RNM__DAB_ENSEMBLE_ALT))
            {
                _freqInfo.INDEX_ARRAY[_freqInfo.NUM_ELEMENTS] =  tempFiElement.FREQ_INDEX;
                _freqInfo.EID_ARRAY[_freqInfo.NUM_ELEMENTS] = (uint16_t)tempFiElement.ID;
                _freqInfo.NUM_ELEMENTS ++;
            }

            if(_freqInfo.NUM_ELEMENTS == DAB_FREQ_INFO_MAX_ITEMS)
            {
                //Out of allocated memory for tracking the EIDs, continue on with what we have so far.
                break;
            }
        }
    }

    return ret;
}

RETURN_CODE _service_linking_add_linking_info_to_list_element(dab_service_list_element* listElement, uint8_t freqIndex, uint16_t serviceOffset)
{
    RETURN_CODE ret = 0;
    uint8_t linkLoop;

    for(linkLoop=0;linkLoop < DAB_SERVICE_LIST__MAX_NUMBER_OF_LINKED_FREQUENCIES;linkLoop++)
    {
        if((listElement->FREQUENCY_INDEXES_LINKED[linkLoop] == DAB_SERVICE_LIST__LINKED_INDEX_DEFAULT) || (listElement->FREQUENCY_INDEXES_LINKED[linkLoop] == freqIndex))
        {
            listElement->FREQUENCY_INDEXES_LINKED[linkLoop] = freqIndex;

            //Updated with the service with the alternate frequency
		    ret |= write_storage__command(serviceOffset, sizeof(dab_service_list_element), (uint8_t*)listElement);
            CALLBACK_Updated_Data(UPDATED_SERVICE_LINKING_DAB);
            break;
        }
    }

    return ret;
}


//Basic Linking cases A1 and A2 assume SID=SID
//These links are stored in persistant storage with the service database
RETURN_CODE _update_DAB_service_following_worker()
{
    RETURN_CODE ret = 0;
    uint8_t i,j,k = 0;

    dab_get_oe_services_info__data dgoesid;

    dab_service_list_element tempListElement;
    uint8_t ensembleAddressIndex;
    uint16_t serviceOffset;

    for(i = 0; i < _freqInfo.NUM_ELEMENTS; i++)
    {
        //Use this commented line for unit testing with ServiceFollowing-FraunhoferIIS-2010-10-18.eti (A1 case)
        //if(_freqInfo.EID_ARRAY[i] == 0xDAB6)
        if(_freqInfo.EID_ARRAY[i] == _current_dab_metrics.EID)
        {
            //We found a matching ensemble signaled on another frequency index
            //Add this frequency index to each item for the matching ensemble in the list

            ret = findEnsembleInList(_current_dab_metrics.FREQUENCY_INDEX, &ensembleAddressIndex);
            if(ret == SUCCESS)
            {
                j = 0;
                serviceOffset = svcListDAB.ENSEMBLE_OFFSETS[ensembleAddressIndex];
                while((serviceOffset / sizeof(dab_service_list_element) < svcListDAB.SERVICE_COUNT))
                {
                    serviceOffset += (sizeof(dab_service_list_element) * j++);
                    ret = getServiceListElement(serviceOffset, &tempListElement);
                
                    if((ret == SUCCESS) && (tempListElement.FREQUENCY_INDEX == _current_dab_metrics.FREQUENCY_INDEX))
                    {
                        ret = _service_linking_add_linking_info_to_list_element(&tempListElement, _freqInfo.INDEX_ARRAY[i], serviceOffset);
                    }
                    else
                    {
                        break;
                    }
                }
            }   
        }
    }

    //Now look for the linking info to see if the service is on a non-duplicated ensemble.  EID!=EID, SID=SID
    //Note: we only look at this linking info if there is frequency info to correlate (hard links only)
    ret |= findEnsembleInList(_current_dab_metrics.FREQUENCY_INDEX, &ensembleAddressIndex);

    if(ret == SUCCESS)
    {
        j = 0;
        serviceOffset = svcListDAB.ENSEMBLE_OFFSETS[ensembleAddressIndex];
        while((serviceOffset / sizeof(dab_service_list_element) < svcListDAB.SERVICE_COUNT))
        {
            serviceOffset += (sizeof(dab_service_list_element) * j++);
            ret = getServiceListElement(serviceOffset, &tempListElement);

            if((ret == SUCCESS) && (tempListElement.FREQUENCY_INDEX == _current_dab_metrics.FREQUENCY_INDEX))
            {
                ret = dab_get_oe_services_info__command(tempListElement.SERVICE_ID);
                ret |= dab_get_oe_services_info__reply(&dgoesid);

                if(ret == SUCCESS)
                {
                    for(k=0; k < dgoesid.NUM_EIDS; k++)
                    {
                        for(i = 0; i < _freqInfo.NUM_ELEMENTS; i++)
                        {
                            //Use this commented line for unit testing with ServiceFollowing-FraunhoferIIS-2010-10-18.eti (A2 case)
                            //if(0x1234 == dgoesid.EIDS[k])
                            if(_freqInfo.EID_ARRAY[i] == dgoesid.EIDS[k])
                            {
                                ret |= _service_linking_add_linking_info_to_list_element(&tempListElement,_freqInfo.INDEX_ARRAY[i], serviceOffset);
                            }
                        }  
                    }
                }
                else
                {
                    continue;
                }
            }
            else
            {
                break;
            }
        }
    }

    return ret;
}

#ifdef OPTION__DAB_SUPPORT_DAB_DAB_LINKING_A3

//Linking support for A3, where SID != SID.  The expectation is OPTION__DAB_SUPPORT_DAB_DAB_LINKING is also selected
//This is not stored in persistant storage because it gets updates frequently and activates/deactivates throughout the day.
RETURN_CODE _update_DAB_DAB_service_linking_worker()
{
    RETURN_CODE ret = 0;

    uint8_t i, j, k;
    dab_get_service_linking_info__data dgslid;
    dab_linking_set linkSet;
    uint32_t candidateServices[SERVICE_LINKING_A3_MAX_NUMBER_OF_LINKS_FOR_CURRENT_SERVICE];
    uint8_t numCandidates = 0;

    dab_get_oe_services_info__data dgoesid;


    //We are updating the links - clear any old links
    _service_linking_clear_service_links();

    //Step 1: get all of the alternate service IDs to consider for the current service - FIG 0/6
    //**********************************************************************************************
    #ifndef OPTION__COMMAND_INPUT_MINIMAL_OPTIONS_SMALLER_SDK
        ret = dab_get_service_linking_info__command(1, 1, 0, 1, 1, 1, 0, 0, _current_audio_service_id);
    #else
        //cmd_arg[1] = 0x82; //ACTIVE = 1   | LINKTYPE = 0   | HARD = 1   | ILS = 0
        //cmd_arg[2] = 0x92; //ACTIVEEN = 1 | LINKTYPEEN = 1 | HARDEN = 1 | ILSEN = 0
        ret = dab_get_service_linking_info__command(_current_audio_service_id, 0x82, 0x92);
    #endif

    ret|= dab_get_service_linking_info__reply(&dgslid);

    if(ret == SUCCESS)
    {
        for(i = 0; i < dgslid.NUM_LINKSETS; i++)
        {
            ret |= dab_get_service_linking_info__get_element(i, &dgslid, &linkSet);

            for(j = 0; j < linkSet.NUMLINKS; j ++)
            {
                candidateServices[numCandidates++] = linkSet.LINKID[j];

                if(numCandidates == SERVICE_LINKING_A3_MAX_NUMBER_OF_LINKS_FOR_CURRENT_SERVICE)
                {
                    //We ran out of space for service ID candidates, moving on.
                    break;
                }
            }

        }
    }
    //**********************************************************************************************

    //Step 2: get all the EIDs for the SIDs obtained in step 1 - FIG 0/24
    //**********************************************************************************************
    if(ret == SUCCESS)
    {
        //Loop will only enter if we have some candidates
        for(i = 0; i < numCandidates; i++)
        {
            ret = dab_get_oe_services_info__command(candidateServices[i]);
            ret |= dab_get_oe_services_info__reply(&dgoesid);

            if(ret == SUCCESS)
            {
                //Step 3: get all the frequency indexes for the EIDs in step 2 - FIG 0/21
                //**********************************************************************************************
                for(j=0; j < dgoesid.NUM_EIDS; j++)
                {
                    for(k = 0; k < _freqInfo.NUM_ELEMENTS; k++)
                    {
                        if(_freqInfo.EID_ARRAY[k] == dgoesid.EIDS[j])
                        {
                            _current_service_links.LINKS[_current_service_links.NUM_LINKS].SERVICE_ID = candidateServices[i];
                            _current_service_links.LINKS[_current_service_links.NUM_LINKS].COMPONENT_ID = _current_audio_component_id;
                            _current_service_links.LINKS[_current_service_links.NUM_LINKS].FREQUENCY_INDEX = _freqInfo.INDEX_ARRAY[k];
                            _current_service_links.NUM_LINKS ++;

                            if(_current_service_links.NUM_LINKS == SERVICE_LINKING_A3_MAX_NUMBER_OF_LINKS_FOR_CURRENT_SERVICE)
                            {
                                //We ran out of space for service ID candidates, moving on.
                                break;
                            }
                        }
                    }  
                }
                //**********************************************************************************************
            }
        }

    }


    return ret;
    //**********************************************************************************************

}
#endif //OPTION__DAB_SUPPORT_DAB_DAB_LINKING_A3

#endif //OPTION__DAB_SUPPORT_DAB_DAB_LINKING

RETURN_CODE _update_DAB_service_list_worker(dab_get_event_status__data dges)
{
    RETURN_CODE ret = 0;
    get_digital_service_list__data gdsl;
    dab_service_list_element tempElement;
    uint8_t tempServiceIndex = 0;

    if(dges.SVRLISTINT && dges.SVRLIST)
    {
        ret = get_digital_service_list__command(0); // DAB only has one type of list
        ret |= get_digital_service_list__reply(0,&gdsl);
        if(ret == SUCCESS)
        {
            updateDAB_ServiceList(&gdsl, dges.SVRLISTVER);
            ret = _DAB_update_metrics_current_service_in_list();

            //**********************************************************
            // Current Component is no longer in this service - fall back to the Main Service
            if(ret != SUCCESS)
            {

                //Attempt to find another component on the main service
                ret = findServiceInList(_current_audio_service_id,_current_audio_component_id,1,1,_current_dab_metrics.FREQUENCY_INDEX, &tempServiceIndex);
        
                if(ret == SUCCESS)
                {
                    //We found another component in the service
                    //ret = _DAB_start_service_from_list(tempServiceIndex);
                    ret = getServiceListElement(svcListDAB.SERVICE_OFFSETS[tempServiceIndex], &tempElement);
                    ret |= StartProcessingChannel(SERVICE_TYPE_DAB_AUDIO, tempElement.SERVICE_ID,tempElement.COMPONENT_ID, 0);
                    //ret |= _DAB_update_metrics_current_service_in_list(); //removed as this is redundant (StartPocessingChannel does this too)
                }

                //current service not found in the new list - notify the MMI
                CALLBACK_Updated_Data(EVENT_CURRENT_SERVICE_NO_LONGER_AVAILABLE);
            }
            //**********************************************************

            #ifdef OPTION__DAB_SERVICE_LIST_PERSISTENCE
                SaveServiceList_DAB();
            #endif

        }
    }
    if(dges.ANNOINT)
    {
        //TODO: process announcements
    }
    if(dges.RECFGINT)
    { 
        // Manually increase the service list debounce time as we have exited the reconfig window
        //ret |= _set_property(PROP_DAB_EVENT_MIN_SVRLIST_PERIOD_GROUP,PROP_DAB_EVENT_MIN_SVRLIST_PERIOD_INDEX,DAB_EVENT_MIN_SVRLIST_PERIOD__NORMAL_VALUE__IN_100MS);

        // Issue callback that the service list has reconfigured
        CALLBACK_Updated_Data(EVENT_ENSEMBLE_RECONFIGURATION);
    }
    if(dges.RECFGWRNINT)
    {
        //Manually reduce the service list debounce time to ensure the new list is as soon as possible after the update
        //ret |= _set_property(PROP_DAB_EVENT_MIN_SVRLIST_PERIOD_GROUP,PROP_DAB_EVENT_MIN_SVRLIST_PERIOD_INDEX,DAB_EVENT_MIN_SVRLIST_PERIOD__DURING_ENSEMBLE_RECONFIG__IN_100MS);

        //Issue callback that the service list reconfiguration is pending
        CALLBACK_Updated_Data(EVENT_ENSEMBLE_RECONFIGURATION_WARNING);
    }
    #ifdef OPTION__DAB_SUPPORT_DAB_DAB_LINKING
        if(dges.FREQINFO)
        {
            ret |= _service_linking_update_freq_info();
        }

        if(dges.FREQINFO || dges.OESERV)
        {
            ret |= _update_DAB_service_following_worker();
        }

        #ifdef OPTION__DAB_SUPPORT_DAB_DAB_LINKING_A3
            if(dges.SERVLINK && dges.FREQINFO && dges.OESERV && (dges.SERVLINKINT || dges.FREQINFOINT || dges.OESERVINT) && (_DAB_service_lost == 0))
            {
                ret |= _update_DAB_DAB_service_linking_worker();
            }
        #endif //OPTION__DAB_SUPPORT_DAB_DAB_LINKING_A3

    #endif //OPTION__DAB_SUPPORT_DAB_DAB_LINKING

    return ret;
}



#endif //OPTION__INCLUDE_MODE__DAB

//******************************************************************************************
// Begin "Public" Functions
//******************************************************************************************

#ifdef OPTION__INCLUDE_MODE__ANY
RETURN_CODE Initialize(RADIO_MODE_TYPE mode)
{
	RETURN_CODE ret = 0;
	get_sys_state__data gss;

    _current_audio_service_id = 0;
    _current_audio_component_id = 0;

#ifdef OPTION__INCLUDE_MODE__FM
    _empty_metrics_fm();
#endif

#ifdef OPTION__INCLUDE_MODE__AM
    _empty_metrics_am();
#endif

#ifdef OPTION__INCLUDE_MODE__AMHD
    _empty_metrics_amhd();
#endif

#ifdef OPTION__INCLUDE_MODE__FMHD
    _empty_metrics_fmhd();
#endif
#ifdef OPTION__INCLUDE_MODE__DAB
    _empty_metrics_dab();
    _dab_favorites_only_browse_enable = 0;
    #ifdef OPTION__DAB_SUPPORT_DAB_DAB_LINKING_A3
        _service_linking_clear_service_links();
    #endif //OPTION__DAB_SUPPORT_DAB_DAB_LINKING_A3
#endif
    
	// Load the firmware for the device
	ret = _si46xx_initialize(mode);

	// Configure the essential properties, others are left to the higher level application
	ret |= _si46xx_configure_properties(mode);

	if(ret == SUCCESS)
	{
		//Determine what mode we are in to track for other functions.
		ret = get_sys_state__command();
		get_sys_state__reply(&gss);

		if(ret == SUCCESS)
		{
            if(gss.image != mode)
            {
                
                if((mode == fmonly) && (gss.image == fmhd))
                {
                    //escape the error path as we only have an FMHD image type - manually force fmonly
                    _current_image_type = fmonly;
                    return ret;
                }
            #ifdef OPTION__INCLUDE_MODE__AMHD
				else if((mode == amhd)&&(gss.image == am))
				{
                    //escape the error path as we only have an FMHD image type - manually force fmonly
                    _current_image_type = amhd;
                    return ret;
				}
            #endif
                else
                {
                    //error: the loaded image did not match the image requested - return error to indicate firmware load driver needs debug
                    return INVALID_MODE;
                }
            }

			_current_image_type = (RADIO_MODE_TYPE)gss.image;
		}
	}

	return ret;
}
#endif //OPTION__INCLUDE_MODE__ANY

RETURN_CODE Finalize(void)
{
	RETURN_CODE ret = 0;

#ifdef OPTION__HANDLE_ADVANCED_SERVICES
	_empty_service_list();
#endif
	_empty_status();

	ret = _si46xx_powerdown();

	return ret;
}

#if defined (OPTION__INCLUDE_MODE__FM)|| defined(OPTION__INCLUDE_MODE__AM)
//freq is provided in 10kHz for fm/fmhd
//freq is provided in 1kHz for am/amhd
RETURN_CODE Tune(uint16_t freq)
{
	RETURN_CODE ret = 0;

#ifdef OPTION__HANDLE_ADVANCED_SERVICES
    _empty_service_list();
#endif

	switch(_current_image_type)
	{
	case fmonly:
		ret = fm_am_tune_freq__command(SHARED_FUNCTION_MODE_FM, 0,CMD_FM_TUNE_FREQ_ARG_TUNE_MODE_ENUM_TUNE_ANALOG_ONLY,0,freq,1, 0); // force ANTCAP to 1 for best performance
        _empty_metrics_fm();
        initRDS();
        if(ret == SUCCESS)
        {
            _current_fm_metrics.FREQUENCY_10KHZ = freq; //Force metrics for fast switching
        }
		break;
#ifdef OPTION__INCLUDE_MODE__AM
	case am:
		ret = fm_am_tune_freq__command(SHARED_FUNCTION_MODE_AM, 0,CMD_FM_TUNE_FREQ_ARG_TUNE_MODE_ENUM_TUNE_ANALOG_ONLY,0,freq,1, 0); // force ANTCAP to 1 for best performance

        _empty_metrics_am();
       // initRDS();
        if(ret == SUCCESS)
        {
            _current_am_metrics.FREQUENCY_1KHZ = freq; //Force metrics for fast switching
        }
		break;
#endif //OPTION__INCLUDE_MODE__AM
#ifdef OPTION__INCLUDE_MODE__FMHD
	case fmhd:
		ret = fm_am_tune_freq__command(SHARED_FUNCTION_MODE_FM, 0,CMD_FM_TUNE_FREQ_ARG_TUNE_MODE_ENUM_TUNE_HYBRID,0,freq,1, 0); // force ANTCAP to 1 for best performance
        _current_hd_audio_service_as_bitmask = 1;
        _current_audio_service_id = 0;
        _current_audio_component_id = 0;
        _empty_metrics_fmhd();
        initRDS();
        #ifdef OPTION__DECODE_FMHD_SERVICE_LIST
            initHD_ServiceList();
        #endif
        #ifdef OPTION__DECODE_SIS
            initSIS();
        #endif
        #ifdef OPTION__DECODE_PSD
            initPSD();
        #endif
        #ifdef OPTION__DECODE_HD_ALERTS
            initAlerts();
        #endif
        if(ret == SUCCESS)
        {
            _current_fmhd_metrics.FREQUENCY_10KHZ = freq; //Force metrics for fast switching
        }
		break;
#endif
#ifdef OPTION__INCLUDE_MODE__AMHD
	case amhd:
		ret = fm_am_tune_freq__command(SHARED_FUNCTION_MODE_AM,0,CMD_AM_TUNE_FREQ_ARG_TUNE_MODE_ENUM_TUNE_HYBRID,0,freq,0, 0); // force ANTCAP to 1 for best performance
        _current_hd_audio_service_as_bitmask = 1;
        _current_audio_service_id = 0;
        _current_audio_component_id = 0;
        _empty_metrics_amhd();
        //initRDS();
        #ifdef OPTION__DECODE_AMHD_SERVICE_LIST
            initHD_ServiceList();
        #endif
        #ifdef OPTION__DECODE_SIS
            initSIS();
        #endif
        #ifdef OPTION__DECODE_PSD
            initPSD();
        #endif
        #ifdef OPTION__DECODE_HD_ALERTS
            initAlerts();
        #endif
        if(ret == SUCCESS)
        {
            _current_amhd_metrics.FREQUENCY_1KHZ = freq; //Force metrics for fast switching
        }
		break;
#endif
	default:
		return INVALID_MODE; // The device is not in a known state, TUNE is not supported when not running a valid firmware image
		break;
	}

	// There is no wait for STC, though the tune is not considered valid until STC is set.

	return ret;
}

RETURN_CODE SetStepSize(uint8_t stepsize_khz)
{
    RETURN_CODE ret = 0;
    uint16_t desiredStep = stepsize_khz;
    uint16_t currentStepProp;

	if(_current_image_type == fmonly ||_current_image_type == fmhd)
	{
    	desiredStep = (stepsize_khz / FM_SEEK_STEP_SIZE_CONVERSION_FACTOR);
	}

    switch(desiredStep)
    {
        case 5:
            break;
		case 9:
        case 10:
            if(_current_image_type == fmonly)
            {
                while((_current_fm_metrics.FREQUENCY_10KHZ % desiredStep) != 0)
                {
                    TuneStep(1);
                }
            }
#ifdef OPTION__INCLUDE_MODE__FMHD
            else if(_current_image_type == fmhd)
            {
                while((_current_fmhd_metrics.FREQUENCY_10KHZ % desiredStep) != 0)
                {
                    TuneStep(1);
                }
            }
#endif //option__include_mode__fmhd

#ifdef OPTION__INCLUDE_MODE__AM
			else if(_current_image_type == am)
			{
				while((_current_am_metrics.FREQUENCY_1KHZ % desiredStep)!=0)
				{
					TuneStep(1);
				}
			}
#endif
            break;
        case 20:
            if(_current_image_type == fmonly)
            {
                while((_current_fm_metrics.FREQUENCY_10KHZ % desiredStep) != 10)
                {
                    TuneStep(1);
                }
            }
#ifdef OPTION__INCLUDE_MODE__FMHD
            else if(_current_image_type == fmhd)
            {
                while((_current_fmhd_metrics.FREQUENCY_10KHZ % desiredStep) != 10)
                {
                    TuneStep(1);
                }
            }
#endif
            break;
        default:
            return INVALID_INPUT;
            break;
    }
	if(_current_image_type == fmonly ||_current_image_type == fmhd)
	{
    	ret |= _get_property(PROP_FM_SEEK_FREQUENCY_SPACING_GROUP, PROP_FM_SEEK_FREQUENCY_SPACING_INDEX, &currentStepProp);
    	currentStepProp = currentStepProp & (0xFFFF - PROP_FM_SEEK_FREQUENCY_SPACING_FMSKSPACE_MASK); // Clear the spacing value
    	ret |= _set_property(PROP_FM_SEEK_FREQUENCY_SPACING_GROUP, PROP_FM_SEEK_FREQUENCY_SPACING_INDEX, (currentStepProp | (desiredStep & PROP_FM_SEEK_FREQUENCY_SPACING_FMSKSPACE_MASK)));
	}
#if defined (OPTION__INCLUDE_MODE__AM)||defined (OPTION__INCLUDE_MODE__AMHD)
	else if(_current_image_type == am ||_current_image_type == amhd)
	{
    	ret |= _get_property(PROP_AM_SEEK_FREQUENCY_SPACING_GROUP, PROP_AM_SEEK_FREQUENCY_SPACING_INDEX, &currentStepProp);
    	currentStepProp = currentStepProp & (0xFFFF - PROP_AM_SEEK_FREQUENCY_SPACING_AMSKSPACE_MASK); // Clear the spacing value
    	ret |= _set_property(PROP_AM_SEEK_FREQUENCY_SPACING_GROUP, PROP_AM_SEEK_FREQUENCY_SPACING_INDEX, (currentStepProp | (desiredStep & PROP_AM_SEEK_FREQUENCY_SPACING_AMSKSPACE_MASK)));
	}
#endif
    if(ret == SUCCESS)
    {
        _current_band_step = desiredStep;
    }

    return ret;
}

#ifndef OPTION__REMOVE_SDK_FUNCTIONS_NOT_USED_BY_MMI
RETURN_CODE SetBandLimits(FM_BAND_LIMITS limits)
{
    RETURN_CODE ret = 0;
    switch(limits)
    {
        case JAPAN_76_90:
            ret |= _set_property(PROP_FM_SEEK_BAND_BOTTOM_GROUP, PROP_FM_SEEK_BAND_BOTTOM_INDEX, PROP_FM_SEEK_BAND_BOTTOM_FMSKFREQL_ENUM_JAPAN_MIN);
            ret |= _set_property(PROP_FM_SEEK_BAND_TOP_GROUP, PROP_FM_SEEK_BAND_TOP_INDEX, PROP_FM_SEEK_BAND_BOTTOM_FMSKFREQL_ENUM_JAPAN_MAX);
            break;
        case STANDARD_875_1079:
            ret |= _set_property(PROP_FM_SEEK_BAND_BOTTOM_GROUP, PROP_FM_SEEK_BAND_BOTTOM_INDEX, PROP_FM_SEEK_BAND_BOTTOM_FMSKFREQL_ENUM_STANDARD_MIN);
            ret |= _set_property(PROP_FM_SEEK_BAND_TOP_GROUP, PROP_FM_SEEK_BAND_TOP_INDEX, PROP_FM_SEEK_BAND_BOTTOM_FMSKFREQL_ENUM_STANDARD_MAX);
            break;
        case WIDE_78_108:
            ret |= _set_property(PROP_FM_SEEK_BAND_BOTTOM_GROUP, PROP_FM_SEEK_BAND_BOTTOM_INDEX, PROP_FM_SEEK_BAND_BOTTOM_FMSKFREQL_ENUM_WIDE_MIN);
            ret |= _set_property(PROP_FM_SEEK_BAND_TOP_GROUP, PROP_FM_SEEK_BAND_TOP_INDEX, PROP_FM_SEEK_BAND_TOP_FMSKFREQH_ENUM_WIDE_MAX);
            break;
        default:
            ret = INVALID_INPUT;
            break;
    }

    if(ret == SUCCESS)
    {
        ret |= _get_property(PROP_FM_SEEK_BAND_BOTTOM_GROUP,PROP_FM_SEEK_BAND_BOTTOM_INDEX,&_current_band_bottom);
        ret |= _get_property(PROP_FM_SEEK_BAND_TOP_GROUP,PROP_FM_SEEK_BAND_TOP_INDEX,&_current_band_top);
    }

    return ret;
}
#endif //#ifndef OPTION__REMOVE_SDK_FUNCTIONS_NOT_USED_BY_MMI

RETURN_CODE TuneStep(uint8_t stepup)
{
    RETURN_CODE ret = 0;
    uint16_t desiredFrequency;

    if(SeekTuneCompleteCheck() > 0)
    {
        switch(_current_image_type)
	    {
	    case fmonly:
            if(stepup)
            {
                desiredFrequency = _current_fm_metrics.FREQUENCY_10KHZ + _current_band_step;
                if(desiredFrequency > _current_band_top)
                {
                    desiredFrequency = _current_band_bottom;
                }
            }
            else
            {
                desiredFrequency = _current_fm_metrics.FREQUENCY_10KHZ - _current_band_step;
                if(desiredFrequency < _current_band_bottom)
                {
                    desiredFrequency = _current_band_top;
                }
            }
            ret = Tune(desiredFrequency);
            if(ret == SUCCESS)
            {
                _current_fm_metrics.FREQUENCY_10KHZ = desiredFrequency;
            }
		    break;
#ifdef OPTION__INCLUDE_MODE__AM			
		case am:
            if(stepup)
            {
                desiredFrequency = _current_am_metrics.FREQUENCY_1KHZ + _current_band_step;
                if(desiredFrequency > _current_band_top)
                {
                    desiredFrequency = _current_band_bottom;
                }
            }
            else
            {
                desiredFrequency = _current_am_metrics.FREQUENCY_1KHZ - _current_band_step;
                if(desiredFrequency < _current_band_bottom)
                {
                    desiredFrequency = _current_band_top;
                }
            }
            ret = Tune(desiredFrequency);
            if(ret == SUCCESS)
            {
                _current_am_metrics.FREQUENCY_1KHZ = desiredFrequency;
            }
		    break;
#endif			
#ifdef OPTION__INCLUDE_MODE__FMHD
	    case fmhd:
            ret = _step_to_next_service_hd(stepup);
            if(ret != SUCCESS) // There was no digital service available - need to step frequency
            {
                if(stepup)
                {
                    desiredFrequency = _current_fmhd_metrics.FREQUENCY_10KHZ + _current_band_step;
                    if(desiredFrequency > _current_band_top)
                    {
                        desiredFrequency = _current_band_bottom;
                    }
                }
                else
                {
                    desiredFrequency = _current_fmhd_metrics.FREQUENCY_10KHZ - _current_band_step;
                    if(desiredFrequency < _current_band_bottom)
                    {
                        desiredFrequency = _current_band_top;
                    }
                }
                ret = Tune(desiredFrequency);
                if(ret == SUCCESS)
                {
                    _current_fmhd_metrics.FREQUENCY_10KHZ = desiredFrequency;
                    #ifdef OPTION__DECODE_HD_ALERTS
                        initAlerts(); // If we change frequencies we want alerts to reset
                    #endif
                }
            }
            #ifdef OPTION__DECODE_PSD
                initPSD(); // PSD buffers need to be cleared after changing digital services
            #endif
		    break;
#endif


#ifdef OPTION__INCLUDE_MODE__AMHD
	    case amhd:
            ret = _step_to_next_service_hd(stepup);
            if(ret != SUCCESS) // There was no digital service available - need to step frequency
            {
                if(stepup)
                {
                    desiredFrequency = _current_amhd_metrics.FREQUENCY_1KHZ + _current_band_step;
                    if(desiredFrequency > _current_band_top)
                    {
                        desiredFrequency = _current_band_bottom;
                    }
                }
                else
                {
                    desiredFrequency = _current_amhd_metrics.FREQUENCY_1KHZ - _current_band_step;
                    if(desiredFrequency < _current_band_bottom)
                    {
                        desiredFrequency = _current_band_top;
                    }
                }
                ret = Tune(desiredFrequency);
                if(ret == SUCCESS)
                {
                    _current_amhd_metrics.FREQUENCY_1KHZ = desiredFrequency;
                    #ifdef OPTION__DECODE_HD_ALERTS
                        initAlerts(); // If we change frequencies we want alerts to reset
                    #endif
                }
            }
            #ifdef OPTION__DECODE_PSD
                initPSD(); // PSD buffers need to be cleared after changing digital services
            #endif
		    break;
#endif
	    default:
		    return INVALID_MODE; // The device is not in a known state, TUNE is not supported when not running a valid firmware image
		    break;
        }
    }
    else
    {
        ret = COMMAND_ERROR; // Tune was called too fast, if error call again
    }

    return ret;
}


RETURN_CODE SeekStart(uint8_t seekup, uint8_t wrap, uint8_t hdseekonly)
{
	RETURN_CODE ret = 0;

#if defined(OPTION__INCLUDE_MODE__FMHD)||defined(OPTION__INCLUDE_MODE__AMHD)
	uint16_t hdSeekInitialFrequency;
    uint8_t tempWrapValue;
    uint8_t wrapHasHappened;
#endif

	switch(_current_image_type)
	{
	case fmonly:
        _FM_seek_continue = 1;
        ret = fm_am_seek_start__command(SHARED_FUNCTION_MODE_FM, 0, CMD_FM_SEEK_START_ARG_TUNE_MODE_ENUM_TUNE_ANALOG_ONLY, 0, seekup, wrap, 0);
    #ifdef OPTION__HANDLE_ADVANCED_SERVICES
        _empty_service_list();
    #endif
        _empty_metrics_fm();
        initRDS();
        ret |= _FM_confirm_seek_complete();
        _FM_seek_continue = 0;
		break;
#ifdef OPTION__INCLUDE_MODE__AM	
    case am:
        _AM_seek_continue = 1;
        ret = fm_am_seek_start__command(SHARED_FUNCTION_MODE_AM, 0, CMD_AM_SEEK_START_ARG_TUNE_MODE_ENUM_TUNE_ANALOG_ONLY, 0, seekup, wrap, 0);
    #ifdef OPTION__HANDLE_ADVANCED_SERVICES
        _empty_service_list();
    #endif
        _empty_metrics_am();
        ret |= _AM_confirm_seek_complete();
        _AM_seek_continue = 0;
		break;
#endif
#ifdef OPTION__INCLUDE_MODE__FMHD
	case fmhd:
        ret = _step_to_next_service_hd(seekup);
        if(ret != SUCCESS) // There was no digital service to seek to
        {
            _FM_seek_continue = 1;
            ret |= AudioMute(MUTE_LEFT_RIGHT); // need to mute or there will be audible audio during a managed seek

            // Clear the system information
            _current_hd_audio_service_as_bitmask = 1;
            _current_audio_service_id = 0;
            _current_audio_component_id = 0;
#ifdef OPTION__HANDLE_ADVANCED_SERVICES
            _empty_service_list();
#endif

            _empty_metrics_fmhd();

            initHD_ServiceList();
            initRDS();
            #ifdef OPTION__DECODE_SIS
                initSIS();
            #endif
            #ifdef OPTION__DECODE_PSD
                initPSD();
            #endif
            #ifdef OPTION__DECODE_HD_ALERTS
                initAlerts();
            #endif

            if(hdseekonly > 0)
            {
                ret = UpdateMetrics();
                hdSeekInitialFrequency = _current_fmhd_metrics.FREQUENCY_10KHZ;
                wrapHasHappened = 0;
                do
                {
                    if(((wrap !=0) && (seekup > 0) && (_current_fmhd_metrics.FREQUENCY_10KHZ == _current_band_top)) ||
                        ((wrap !=0) && (seekup == 0) && (_current_fmhd_metrics.FREQUENCY_10KHZ == _current_band_bottom)))
                    {
                        tempWrapValue = 1;
                        wrapHasHappened = 1;
                    }
                    else
                    {
                        tempWrapValue = 0;
                    }
                    ret = fm_am_seek_start__command(SHARED_FUNCTION_MODE_FM, 0, CMD_FM_SEEK_START_ARG_TUNE_MODE_ENUM_TUNE_HYBRID, 0, seekup, tempWrapValue, 0);
                    ret |= _FMHD_confirm_seek_complete(wrapHasHappened,seekup,hdSeekInitialFrequency);
                    ret |= UpdateMetrics();
                }
                while(  (ret == SUCCESS) && 
                        (_current_fmhd_metrics.HDLEVEL < OPTION__FMHD_SEEK_HDLEVEL_THRESHOLD) &&  
                        (hdSeekInitialFrequency != _current_fmhd_metrics.FREQUENCY_10KHZ));
            }
            else
            {
                ret = fm_am_seek_start__command(SHARED_FUNCTION_MODE_FM, 0, CMD_FM_SEEK_START_ARG_TUNE_MODE_ENUM_TUNE_ANALOG_ONLY, 0, seekup, wrap, 0);
                ret |= _FM_confirm_seek_complete();
                ret |= fm_am_tune_freq__command(SHARED_FUNCTION_MODE_FM, 0, CMD_FM_TUNE_FREQ_ARG_TUNE_MODE_ENUM_TUNE_HYBRID,0,_current_fmhd_metrics.FREQUENCY_10KHZ,1, 0); // force ANTCAP to 1 for best performance
            }

            ret = AudioMute(NOT_MUTED); // We muted the audio when we started seek so we need to re-enable the audio.

            _FM_seek_continue = 0;
        }
		break;
#endif


#ifdef OPTION__INCLUDE_MODE__AMHD
	case amhd:
        ret = _step_to_next_service_hd(seekup);
        if(ret != SUCCESS) // There was no digital service to seek to
        {
		//	 ret |=_get_property(PROP_AM_VALID_SNR_THRESHOLD_GROUP,PROP_AM_VALID_SNR_THRESHOLD_INDEX,&(current_AM_SNR_TH));
    	//	 ret |=_get_property(PROP_AM_VALID_RSSI_THRESHOLD_GROUP,PROP_AM_VALID_RSSI_THRESHOLD_INDEX,&(current_AM_RSSI_TH));   


            _AM_seek_continue = 1;
            ret |= AudioMute(MUTE_LEFT_RIGHT); // need to mute or there will be audible audio during a managed seek

            // Clear the system information
            _current_hd_audio_service_as_bitmask = 1;
            _current_audio_service_id = 0;
            _current_audio_component_id = 0;


	

#ifdef OPTION__HANDLE_ADVANCED_SERVICES
            _empty_service_list();
#endif

            _empty_metrics_amhd();


            initHD_ServiceList();
            initRDS();
            #ifdef OPTION__DECODE_SIS
                initSIS();
            #endif
            #ifdef OPTION__DECODE_PSD
                initPSD();
            #endif
            #ifdef OPTION__DECODE_HD_ALERTS
                initAlerts();
            #endif


                ret = fm_am_seek_start__command(SHARED_FUNCTION_MODE_AM,0, CMD_AM_SEEK_START_ARG_TUNE_MODE_ENUM_TUNE_ANALOG_ONLY, 0, seekup, wrap, 0);
                _AM_confirm_seek_complete();
                ret |= fm_am_tune_freq__command(SHARED_FUNCTION_MODE_AM,0, CMD_AM_TUNE_FREQ_ARG_TUNE_MODE_ENUM_TUNE_HYBRID,0,_current_amhd_metrics.FREQUENCY_1KHZ,1, 0); // force ANTCAP to 1 for best performance

            ret = AudioMute(NOT_MUTED); // We muted the audio when we started seek so we need to re-enable the audio.

            _AM_seek_continue = 0;
        }
		break;
#endif
	default:
		return INVALID_MODE; // The device is not in a known state, SEEK is not supported when not running a valid firmware image
		break;
	}

    ret |= UpdateMetrics();
    CALLBACK_Updated_Data(FM_SEEK_PROCESS_COMPLETE);

	return ret;
}


#ifndef OPTION__REMOVE_SDK_FUNCTIONS_NOT_USED_BY_MMI
RETURN_CODE SeekStop(void)
{
    RETURN_CODE ret = 0;
    _FM_seek_continue = 0;

    switch(_current_image_type)
	{
    	case fmonly:
    	case fmhd:
    		ret = fm_rsq_status__command(0,0,1,0);       
    		break;
    	case am:
    	case amhd:
    		ret = am_rsq_status__command(0,0,1,0);       
    		break;
    	default:
    		return INVALID_MODE; // The device is not in a known state, SEEK is not supported when not running a valid firmware image
    		break;
	}

	return ret;
}
#endif //OPTION__REMOVE_SDK_FUNCTIONS_NOT_USED_BY_MMI
#endif //OPTION__INCLUDE_MODE__FM

#ifdef OPTION__INCLUDE_MODE__ANY
uint8_t SeekTuneCompleteCheck(void)
{
    status_bits status;
    status = GetSi46XXStatus();

    return status.STCINT;
}
#endif

#ifdef OPTION__INCLUDE_MODE__DAB
RETURN_CODE SetFrequencyList_DAB(uint8_t numFrequencies, uint32_t* frequencyListPtr)
{
	RETURN_CODE ret = 0;

	ret = dab_set_freq_list__command(numFrequencies,frequencyListPtr);

	return ret;
}

RETURN_CODE GetFrequencyList_DAB(uint8_t bufferSize, uint8_t* numFrequencies, uint32_t* frequencyListPtr)
{
	RETURN_CODE ret = 0;
	dab_get_freq_list__data dgfl;

    //get current frequency list
	ret = dab_get_freq_list__command();
	ret |= dab_get_freq_list__reply(&dgfl);
    
    if(ret == SUCCESS)
    {
	    *numFrequencies = dgfl.NUM_FREQS;
        ClearMemory((uint8_t*)frequencyListPtr, bufferSize);

        if((bufferSize * 4) < (*numFrequencies * 4))
        {
            return INVALID_INPUT;
        }

        CpyMemory((uint8_t*)frequencyListPtr, (uint8_t*)dgfl.FREQ, (*numFrequencies * 4));
    }
    else
    {
        *numFrequencies = 0;
        ClearMemory((uint8_t*)frequencyListPtr, bufferSize);
    }

	return ret;
}

RETURN_CODE ScanBand_DAB()
{
    RETURN_CODE ret = 0;
    uint8_t freqIndex;
	dab_get_freq_list__data dgfl;

    _DAB_scan_continue = 1;
    _DAB_service_lost = 0; //We dont want to keep trying to reacuire after the user has selected a new service
    initDAB_ServiceList(); // Clear the service list
	
#ifdef OPTION__DAB_SERVICE_LIST_PERSISTENCE
    EraseServiceList_DAB();
#endif // OPTION__DAB_SERVICE_LIST_PERSISTENCE

    #ifdef OPTION__DAB_SUPPORT_DAB_DAB_LINKING_A3
        _service_linking_clear_service_links();
    #endif //OPTION__DAB_SUPPORT_DAB_DAB_LINKING_A3

    _DAB_current_browse_service_index = DAB_METRIC_AUDIO_SERVICE_LIST__INDEX_NOT_SET;
    _DAB_service_lost = 0;

	//get current frequency list
	ret = dab_get_freq_list__command();
	ret |= dab_get_freq_list__reply(&dgfl);

	if(ret == SUCCESS)
	{
		for(freqIndex=0; freqIndex<dgfl.NUM_FREQS; freqIndex++)
		{
			ret = _DAB_tune_full_process(freqIndex);
		}

		ret = SUCCESS;
	}

    CALLBACK_Updated_Data(DAB_TUNE_SCAN_PROCESS_COMPLETE);

	return ret;
}

RETURN_CODE ManualTune_DAB(uint8_t freqIndex)
{
	RETURN_CODE ret = 0;

	_DAB_scan_continue = 1;
	_DAB_current_browse_service_index = DAB_METRIC_AUDIO_SERVICE_LIST__INDEX_NOT_SET;
    _DAB_service_lost = 0;

	ret = _DAB_tune_full_process(freqIndex);

	CALLBACK_Updated_Data(DAB_TUNE_SCAN_PROCESS_COMPLETE);

	return ret;
}

RETURN_CODE ReacquireCurrentService_DAB()
{
    RETURN_CODE ret = 0;
    uint8_t serviceIndex = 0;
    if((_DAB_service_lost == 1) && ((_current_dab_metrics.CURRENT_AUDIO_SERVICE_LIST__SERVICE_INDEX < svcListDAB.SERVICE_COUNT) || (_current_dab_metrics.CURRENT_AUDIO_SERVICE_LIST__SERVICE_INDEX == 0xFF)))
    {
        ret = findServiceInList(_current_audio_service_id, (uint16_t)_current_audio_component_id, 0, 1, _last_frequency_index, &serviceIndex);

        if(ret == SUCCESS)
        {
            ret = _DAB_start_service_from_list(serviceIndex);
        }
        else
        {
            ret = _DAB_start_service_A3_helper();
            if(ret == SUCCESS)
            {
                return ret;
            }
            else
            {
                //Attempt to return to the original service in case the service list got updated for the frequency by a different ensemble on the same freq
                ret = _DAB_start_service_worker(_current_audio_service_id,(uint16_t)_current_audio_component_id, _last_frequency_index, 1);
            }
        }

        return ret;

    }

    return INVALID_MODE;
}

void ScanBandCancel_DAB()
{
    _DAB_scan_continue = 0;
}

void BrowseServicesReset_DAB()
{
    _DAB_current_browse_service_index = _current_dab_metrics.CURRENT_AUDIO_SERVICE_LIST__SERVICE_INDEX;
}

void _dab_browse_step_up_down_worker(uint8_t stepup)
{
    if(stepup == 0)
	{
		if(_DAB_current_browse_service_index < (svcListDAB.SERVICE_COUNT - 1))
		{
			// Not at the end of the list - move service index up
			_DAB_current_browse_service_index ++;
		}
		else
		{
			//We have reached the end of the list - wrap to bottom
			_DAB_current_browse_service_index = 0;
		}
	}
	else
	{
		if(_DAB_current_browse_service_index > 0)
		{
			// Not at the end of the list - move service index down
			_DAB_current_browse_service_index --;
		}
		else
		{
			//We have reached the end of the list - wrap to top
			_DAB_current_browse_service_index = (svcListDAB.SERVICE_COUNT - 1);
		}
	}
}

RETURN_CODE BrowseServicesChangeSelection_DAB(uint8_t stepup, uint8_t* service_name, uint8_t* service_name_encoding, uint8_t* service_pty)
{
    RETURN_CODE ret = 0;
    dab_service_list_element tempListElement;
    uint8_t browseIndexInitial;

    
	switch(_current_image_type)
	{
		case dab:
		case dmb:
			if(svcListDAB.SERVICE_COUNT > 0)
			{
				if(_DAB_current_browse_service_index == DAB_METRIC_AUDIO_SERVICE_LIST__INDEX_NOT_SET)
				{
					//We are not tuned so we want to start at the top of the list
					_DAB_current_browse_service_index = 0;
   				}

                browseIndexInitial = _DAB_current_browse_service_index;
                ret = getServiceListElement(svcListDAB.SERVICE_OFFSETS[_DAB_current_browse_service_index], &tempListElement);

                if(ret == SUCCESS)
                {
                    do
                    {
                        #ifdef OPTION__DAB_PRESETS_AS_FAVORITES
                            if(_dab_favorites_only_browse_enable > 0)
                            {
                                do
                                {
                                    _dab_browse_step_up_down_worker(stepup);
                                }while((browseIndexInitial != _DAB_current_browse_service_index) &&
                                       (svcListDAB.SERVICE_FAVORITES[_DAB_current_browse_service_index] == 0));
                            }
                            else
                            {
                        #endif
        				        _dab_browse_step_up_down_worker(stepup);
                        #ifdef OPTION__DAB_PRESETS_AS_FAVORITES
                            }
                        #endif
				        ret |= _return_service_string_info_from_service_list(_DAB_current_browse_service_index, service_name, service_name_encoding, service_pty);
                    }while(
                            (CompareMemory(tempListElement.SERVICE_NAME,service_name,DAB_SERVICE_LIST_SERVICE_LABEL__SIZE) == 0) &&
                            (browseIndexInitial != _DAB_current_browse_service_index));

                }
                    
			}
			else
			{
				ClearMemory(service_name,DAB_SERVICE_LIST_SERVICE_LABEL__SIZE);
				*service_name_encoding = 0;
				*service_pty = 0;
				return INVALID_INPUT;
			}
			break;
		default:
			return INVALID_MODE; // The device is not in a valid state, BrowseServices_DAB is not supported when not running a valid firmware image
			break;
	}

    return ret;
}

RETURN_CODE BrowseServicesStartCurrentSelection_DAB()
{
    RETURN_CODE ret = 0;

    if((_DAB_current_browse_service_index == DAB_METRIC_AUDIO_SERVICE_LIST__INDEX_NOT_SET) && 
                    (svcListDAB.SERVICE_COUNT > 0))
    {
        _DAB_current_browse_service_index = 0; 
    }
    
    ret = StartLastServiceByIndex(_DAB_current_browse_service_index);

    return ret;
}

void GetCurrentServiceIdentification_DAB(uint32_t* serviceId, uint16_t* componentId)
{
	*serviceId = _current_audio_service_id;
	*componentId = (uint16_t)_current_audio_component_id;
}

RETURN_CODE StartLastServiceByIndex(uint8_t serviceListIndex)
{
    RETURN_CODE ret = 0;

    _DAB_service_lost = 0; //We dont want to keep trying to reacuire after the user has selected a new service
    ret = _DAB_start_service_from_list(serviceListIndex);

    if(ret != SUCCESS)
    {
        ret = _DAB_update_metrics_current_service_in_list();
    }

    return ret;
}

#ifdef OPTION__DAB_PRESETS_AS_FAVORITES
void FavoritesSetCurrentService_DAB()
{
    svcListDAB.SERVICE_FAVORITES[_DAB_current_browse_service_index] = 1;
}

void FavoritesRemoveCurrentService_DAB()
{
    svcListDAB.SERVICE_FAVORITES[_DAB_current_browse_service_index] = 0;
}

void FavoritesBrowseOnly_DAB(uint8_t enable)
{
    _dab_favorites_only_browse_enable = enable;
}

uint8_t FavoritesIsCurrentServiceAFavorite_DAB()
{
    if(svcListDAB.SERVICE_COUNT > 0)
    {
        return svcListDAB.SERVICE_FAVORITES[_DAB_current_browse_service_index];
    }
    else
    {
        return 0;
    }
}
#endif

#ifdef OPTION__DAB_SERVICE_LIST_PERSISTENCE
RETURN_CODE SaveServiceList_DAB()
{
    RETURN_CODE ret = 0;
    uint8_t serviceIndex;
    uint16_t currentAddrStorage = 0;
    uint16_t currentAddrRAM = 0;
    dab_service_list_element currentService;
    
    EraseServiceList_DAB();

    //Save the Last Played Service
    ret = writePersistentStorage(currentAddrStorage++,1,(uint8_t*)&_current_dab_metrics.CURRENT_AUDIO_SERVICE_LIST__SERVICE_INDEX);

    //Store our list pointers
    ret |= writePersistentStorage(currentAddrStorage,sizeof(dab_service_list),(uint8_t*)&svcListDAB);
    currentAddrStorage += sizeof(dab_service_list);

    //Store the current services in persistent storage
    for(serviceIndex = 0; serviceIndex < svcListDAB.SERVICE_COUNT; serviceIndex++)
    {
        ret = getServiceListElement(currentAddrRAM, &currentService);
        ret |= writePersistentStorage(currentAddrStorage, sizeof(dab_service_list_element), (uint8_t*)&currentService);

        currentAddrStorage += sizeof(dab_service_list_element);
        currentAddrRAM += sizeof(dab_service_list_element);

        if(ret != SUCCESS)
        {
            break;
        }
    }

    if(ret != SUCCESS)
    {
        EraseServiceList_DAB();
    }

    return ret;
}

RETURN_CODE LoadServiceList_DAB(uint8_t* lastPlayedIndex)
{
    RETURN_CODE ret = 0;
    uint8_t serviceIndex;
    uint16_t currentAddrStorage = 0;
    uint16_t currentAddrRAM = 0;
    dab_service_list_element currentService;

    initDAB_ServiceList();

    ret = readPersistentStorage(currentAddrStorage++, 1 , lastPlayedIndex);

    //Load the current service from persistent storage
    ret |= readPersistentStorage(currentAddrStorage,sizeof(dab_service_list),(uint8_t*)&svcListDAB);

    if(svcListDAB.LIST_OBJECT_VERSION != DAB_SERVICE_LIST_OBJECT_VERSION)
    {
        //The saved list is not valid for this software version - need to clear the list
        initDAB_ServiceList();
        EraseServiceList_DAB();
        return INVALID_INPUT;
    }

    currentAddrStorage += sizeof(dab_service_list);

    //replace the current services in radio RAM
    for(serviceIndex = 0; serviceIndex < svcListDAB.SERVICE_COUNT; serviceIndex++)
    {
        ret |= readPersistentStorage(currentAddrStorage, sizeof(dab_service_list_element), (uint8_t*)&currentService);
        if((ret == SUCCESS) && (currentService.SERVICE_ID != 0))
        {
            ret |= write_storage__command(currentAddrRAM, sizeof(dab_service_list_element), (uint8_t*)&currentService);

            currentAddrStorage += sizeof(dab_service_list_element);
            currentAddrRAM += sizeof(dab_service_list_element);
        }
        else
        {
            initDAB_ServiceList();
            EraseServiceList_DAB();
            return INVALID_INPUT;
        }     
    }

    //Need to override the internal list tracking variables so that the handler will process the next list recieved.
    _currentListVersion = DAB_LIST_VERSION_UNKNOWN;
    _current_service_list_buffer_end_as_offset = currentAddrRAM;

    _empty_metrics_dab();
    _DAB_scan_continue = 1;
    _DAB_service_lost = 0;

    return ret;
}

void EraseServiceList_DAB()
{
    erasePersistentStorage();
}
#endif

RETURN_CODE GetCurrentServiceString_DAB(uint8_t* service_name, uint8_t* service_name_encoding, uint8_t* service_pty)
{
    return _return_service_string_info_from_service_list(_current_dab_metrics.CURRENT_AUDIO_SERVICE_LIST__SERVICE_INDEX, service_name, service_name_encoding, service_pty);
}

RETURN_CODE GetCurrentBrowseServiceString_DAB(uint8_t* service_name, uint8_t* service_name_encoding, uint8_t* service_pty)
{
    return _return_service_string_info_from_service_list(_DAB_current_browse_service_index, service_name, service_name_encoding, service_pty);
}


#ifndef OPTION__REMOVE_SDK_FUNCTIONS_NOT_USED_BY_MMI
RETURN_CODE GetCurrentEnsembleNameString_DAB(uint8_t* ensemble_name)
{
	RETURN_CODE ret = 0;
	dab_get_ensemble_info__data dgei;

	ret = dab_get_ensemble_info__command();
	ret |= dab_get_ensemble_info__reply(&dgei);

	if(ret == SUCCESS)
	{
		CpyMemory(ensemble_name,dgei.LABEL,dgei.LABEL_LENGTH);
	}

	return ret;
}
#endif //OPTION__REMOVE_SDK_FUNCTIONS_NOT_USED_BY_MMI

RETURN_CODE GetCurrentTime_DAB(DAB_TIME_REGION_TYPE region, dab_time* time_data)
{
    RETURN_CODE ret = 0;

    ret = dab_get_time__command((uint8_t)region);
    ret |= dab_get_time__reply((dab_get_time__data*) time_data);

    if(ret != SUCCESS)
    {
        ClearMemory((uint8_t*)time_data,sizeof(dab_time));
    }

    return ret;
}

#endif //OPTION__INCLUDE_MODE__DAB

RETURN_CODE AudioLevel(uint16_t level)
{
	if(level > PROP_AUDIO_ANALOG_VOLUME_VOL_ENUM_MAX_VOL)
	{
		return INVALID_INPUT;
	}

	return _set_property(PROP_AUDIO_ANALOG_VOLUME_GROUP, PROP_AUDIO_ANALOG_VOLUME_INDEX, level);
}

RETURN_CODE AudioMute(AUDIO_MUTE mute)
{
	RETURN_CODE ret = 0;

	if(mute >= MUTE_ERR)
	{
		return INVALID_INPUT;
	}

	ret = _set_property(PROP_AUDIO_MUTE_GROUP,PROP_AUDIO_MUTE_INDEX,mute);

	if(mute == MUTE_LEFT_RIGHT)
	{
		ret |= audioDisable();
	}
	else
	{
		ret |= audioEnable();
	}

    return ret;
}
//**************************************************************************************
// Test function added to the SDK for measuring MONO performance of the 46xx
//******************************************************************************************
#ifdef OPTION__INCLUDE_MODE__FM
//FM_BLEND_RSSI_LIMITS: XMAX = 120, XMIN = 120 to force mono
#define FORCE_MONO_SETTING 0x7878
RETURN_CODE ForceMono_FM(AUDIO_MONO_STEREO_SWITCH audio_MonStereo)
{
    RETURN_CODE ret = 0;
    uint16_t tempPropValue;

    if(_current_image_type == fmonly)
    {

        switch(audio_MonStereo)
        {
        case AUDIO_MONO:
            // User wishes to force mono - need to read the current property setting in case it isn't the default
            ret = _get_property(PROP_FM_BLEND_RSSI_LIMITS_GROUP, PROP_FM_BLEND_RSSI_LIMITS_INDEX, &_current_fm_blend_rssi_limits);
		    ret |= _set_property(PROP_FM_BLEND_RSSI_LIMITS_GROUP, PROP_FM_BLEND_RSSI_LIMITS_INDEX, FORCE_MONO_SETTING); // Force to 120 for each field to cause mono
            break;
        case AUDIO_STEREO:
            // User wishes to re-enable stereo - return the previous setting.  Need to check if it has been changed by the MMI outside of this function
            ret = _get_property(PROP_FM_BLEND_RSSI_LIMITS_GROUP, PROP_FM_BLEND_RSSI_LIMITS_INDEX, &tempPropValue);

            if((ret == SUCCESS) && (tempPropValue == FORCE_MONO_SETTING)) // Check for 0 to see that we are still in "force mono" state, if it is something else -the user probably changed it manually already
            {
                ret |= _set_property(PROP_FM_BLEND_RSSI_LIMITS_GROUP, PROP_FM_BLEND_RSSI_LIMITS_INDEX, _current_fm_blend_rssi_limits); // Return the user set value back to its previous
            }
	        break;
        default:
		    return INVALID_INPUT;
	        break;
        }

    }
    else
    {
        return INVALID_MODE;
    }

    return ret;
}
#endif //OPTION__INCLUDE_MODE__FM
//******************************************************************************************/

//******************************************************************************************/
 RETURN_CODE Get_part(uint16_t* chip_part)
{
	RETURN_CODE ret = 0;
	get_part_info__data  PartInfo_str;

    ret = _si46xx_initialize(determine_part);
    
	ret |= get_part_info__command();
	ret |= get_part_info__reply(&PartInfo_str);
	*chip_part =PartInfo_str.PART;
	return ret;
}

//******************************************************************************************/

#ifdef OPTION__INCLUDE_MODE__ANY
RETURN_CODE UpdateMetrics(void)
{
	RETURN_CODE ret = 0;
#ifdef OPTION__INCLUDE_MODE__FM
    fm_rsq_status__data fm_rsq;
#endif

#ifdef OPTION__INCLUDE_MODE__AM
    am_rsq_status__data am_rsq;
#endif

#ifdef OPTION__INCLUDE_MODE__FMHD
    hd_digrad_status__data fmhd_ds;
#endif

#ifdef OPTION__INCLUDE_MODE__AMHD
    hd_digrad_status__data amhd_ds;
#endif

#ifdef OPTION__INCLUDE_MODE__DAB
    dab_digrad_status__data dab_ds;
    dab_get_audio_info__data dgai;
#endif

	switch(_current_image_type)
	{
#ifdef OPTION__INCLUDE_MODE__FM
	case fmonly:
        ret = fm_rsq_status__command(1,0,0,0); //Dont ack the STC we check it to confirm tune/seek status
        ret |= fm_rsq_status__reply(&fm_rsq);
        if(ret == SUCCESS)
        {
            _current_fm_metrics.FREQUENCY_10KHZ = fm_rsq.READFREQ;
            _current_fm_metrics.MULTIPATH = fm_rsq.MULT;
            _current_fm_metrics.RSSI = fm_rsq.RSSI;
            _current_fm_metrics.SNR = fm_rsq.SNR;
            _current_fm_metrics.VALID = fm_rsq.VALID;
        }
        else
        {
            _empty_metrics_fm();
        }
		break;
#endif //OPTION__INCLUDE_MODE__FM

#ifdef OPTION__INCLUDE_MODE__AM
	case am:
        ret = am_rsq_status__command(1,0,0,0); //Dont ack the STC we check it to confirm tune/seek status
        ret |= am_rsq_status__reply(&am_rsq);
        if(ret == SUCCESS)
        {
            _current_am_metrics.FREQUENCY_1KHZ = am_rsq.READFREQ;
            _current_am_metrics.RSSI = am_rsq.RSSI;
            _current_am_metrics.SNR = am_rsq.SNR;
			_current_am_metrics.MODULATION_INDEX = am_rsq.MOD;
            _current_am_metrics.VALID = am_rsq.VALID;
        }
        else
        {
            _empty_metrics_am();
        }
		break;
#endif //OPTION__INCLUDE_MODE__AM

#ifdef OPTION__INCLUDE_MODE__FMHD
	case fmhd:
		ret = fm_rsq_status__command(1,0,0,0); //Dont ack the STC we check it to confirm tune/seek status
        ret |= fm_rsq_status__reply(&fm_rsq);
        ret |= hd_digrad_status__command(0); // Dont ACK as we may need the interrupt to trigger a restart of services
        ret |= hd_digrad_status__reply(&fmhd_ds);
        if(ret == SUCCESS)
        {
            _current_fmhd_metrics.FREQUENCY_10KHZ = fm_rsq.READFREQ;
            _current_fmhd_metrics.MULTIPATH = fm_rsq.MULT;
            _current_fmhd_metrics.RSSI = fm_rsq.RSSI;
            _current_fmhd_metrics.SNR = fm_rsq.SNR;
            _current_fmhd_metrics.VALID = fm_rsq.VALID;
            _current_fmhd_metrics.HDLEVEL = fm_rsq.HDLEVEL;

            _current_fmhd_metrics.ACQ = fmhd_ds.ACQ;
            if(fmhd_ds.SRCDIG)
            {
                _current_fmhd_metrics.AUDIO_SOURCE = 1;
            }else if(fmhd_ds.SRCANA)
            {
                _current_fmhd_metrics.AUDIO_SOURCE = 0;
            }else
            {
                _current_fmhd_metrics.AUDIO_SOURCE = 0xFF;
            }
            _current_fmhd_metrics.HDLOGO = fmhd_ds.HDLOGO;


            _current_fmhd_metrics.CDNR = fmhd_ds.CDNR;
            _current_fmhd_metrics.DAAI = fmhd_ds.DAAI;

            _current_fmhd_metrics.CURRENT_AUDIO_SERVICE = fmhd_ds.AUDIO_PROG_PLAYING;

            if(svcListFast.MAIN_LIST_COMPLETE == 0)
            {
                svcListFast.AUDIO_SERVICE_PRESENT_BITMASK = fmhd_ds.AUDIO_PROG_AVAIL;
                _current_fmhd_metrics.CURRENT_AUDIO_SERVICE__LIST_INDEX = 0xFF;
                CALLBACK_Updated_Data(UPDATED_SERVICE_LIST_FAST);
            }
            else
            {
                _update_current_service_list_index_fmhd();
            }
        }
        else
        {
            _empty_metrics_fmhd();
        }
		break;
#endif //OPTION__INCLUDE_MODE__FMHD


#ifdef OPTION__INCLUDE_MODE__AMHD
	case amhd:
		ret = am_rsq_status__command(1,0,0,0); //Dont ack the STC we check it to confirm tune/seek status
        ret |= am_rsq_status__reply(&am_rsq);
        ret |= hd_digrad_status__command(0); // Dont ACK as we may need the interrupt to trigger a restart of services
        ret |= hd_digrad_status__reply(&amhd_ds);
        if(ret == SUCCESS)
        {
            _current_amhd_metrics.FREQUENCY_1KHZ = am_rsq.READFREQ;
			_current_amhd_metrics.MODULATION_INDEX = am_rsq.MOD;
            _current_amhd_metrics.RSSI = am_rsq.RSSI;
            _current_amhd_metrics.SNR = am_rsq.SNR;
            _current_amhd_metrics.VALID = am_rsq.VALID;
            _current_amhd_metrics.HDLEVEL = am_rsq.HDLEVEL;

            _current_amhd_metrics.ACQ = amhd_ds.ACQ;
            if(amhd_ds.SRCDIG)
            {
                _current_amhd_metrics.AUDIO_SOURCE = 1;
            }else if(amhd_ds.SRCANA)
            {
                _current_amhd_metrics.AUDIO_SOURCE = 0;
            }else
            {
                _current_amhd_metrics.AUDIO_SOURCE = 0xFF;
            }
            _current_amhd_metrics.HDLOGO = amhd_ds.HDLOGO;


            _current_amhd_metrics.CDNR = amhd_ds.CDNR;
            _current_amhd_metrics.DAAI = amhd_ds.DAAI;

            _current_amhd_metrics.CURRENT_AUDIO_SERVICE = amhd_ds.AUDIO_PROG_PLAYING;

            if(svcListFast.MAIN_LIST_COMPLETE == 0)
            {
                svcListFast.AUDIO_SERVICE_PRESENT_BITMASK = amhd_ds.AUDIO_PROG_AVAIL;
                _current_amhd_metrics.CURRENT_AUDIO_SERVICE__LIST_INDEX = 0xFF;
                CALLBACK_Updated_Data(UPDATED_SERVICE_LIST_FAST);
            }
            else
            {
                _update_current_service_list_index_fmhd();
            }
        }
        else
        {
            _empty_metrics_amhd();
        }
		break;
#endif //OPTION__INCLUDE_MODE__FMHD


#ifdef OPTION__INCLUDE_MODE__DAB
	case dmb:
	case dab:
		ret = dab_digrad_status__command(0,0,0,0);    // Dont STC_ACK as we use it in the main loop to confirm we are tuned.        
        ret |= dab_digrad_status__reply(&dab_ds);
        //ret |= dab_digrad_status__command(1,0,0,0);    // Dont STC_ACK as we use it in the main loop to confirm we are tuned. 

        if(ret == SUCCESS)
        {
			//Service Following will begin if this logic is true.  If you would like to start attempting alternates before full acquisition loss (which is usually after the audio has already become impossible to decode), add desired logic in this conditional based upon other metrics like SNR
            if((dab_ds.ACQ == 0) && (dab_ds.ACQINT == 1))
            {
                ret |= dab_digrad_status__command(1,0,0,0);    // Dont STC_ACK as we use it in the main loop to confirm we are tuned.
                //we were not longer acquired to that service - need to search for alternate
                _DAB_service_lost = 1;
                _last_frequency_index = _current_dab_metrics.FREQUENCY_INDEX;
                CALLBACK_Updated_Data(EVENT_CURRENT_SERVICE_NO_LONGER_AVAILABLE);
            }            


            if(_current_dab_metrics.CURRENT_AUDIO_SERVICE_LIST__SERVICE_INDEX != DAB_METRIC_AUDIO_SERVICE_LIST__INDEX_NOT_SET)
            {          
                ret |= dab_get_audio_info__command();
                ret |= dab_get_audio_info__reply(&dgai);

                if(ret == SUCCESS)
                {
                    _current_dab_metrics.CURRENT_AUDIO_INFO__BIT_RATE = dgai.AUDIO_BIT_RATE;
                    _current_dab_metrics.CURRENT_AUDIO_INFO__MODE = dgai.AUDIO_MODE;
                }
            }


            _current_dab_metrics.FREQUENCY_INDEX = dab_ds.TUNE_INDEX;
            _current_dab_metrics.RSSI = dab_ds.RSSI;
            _current_dab_metrics.SNR = dab_ds.SNR;
            _current_dab_metrics.ACQ = dab_ds.ACQ;
            _current_dab_metrics.VALID = dab_ds.VALID;
            _current_dab_metrics.FIC_QUALITY = dab_ds.FIC_QUALITY;
            _current_dab_metrics.CNR =  dab_ds.CNR;

            #ifdef OPTION__ADVANCED_METRICS
                _current_dab_metrics.FFT_OFFSET = dab_ds.FFT_OFFSET;
            #endif
        }
        else
        {
            _empty_metrics_dab();
        }
		break;
#endif //OPTION__INCLUDE_MODE__DAB
	default:
		return INVALID_MODE; // The device is not in a known state, SEEK is not supported when not running a valid firmware image
		break;
	}

	return ret;
}
#endif //OPTION__INCLUDE_MODE__ANY

#ifdef OPTION__INCLUDE_MODE__ANY
RETURN_CODE UpdateServiceList(void)
{
    RETURN_CODE ret = 0;
#ifdef OPTION__INCLUDE_MODE__FMHD
    hd_get_event_status__data fges;
#endif
#ifdef OPTION__INCLUDE_MODE__DAB
    dab_get_event_status__data dges;
#endif

    switch(_current_image_type)
    {
#ifdef OPTION__INCLUDE_MODE__FMHD
    case fmhd:
	case amhd:
        ret = hd_get_event_status__command(0); // Do not ack as we may need it for SIS
        ret |= hd_get_event_status__reply(&fges);
	    if(ret == SUCCESS)
        {
            ret = _update_HD_service_list_worker(fges);
        }
        break;
#endif //OPTION__INCLUDE_MODE__FMHD
#ifdef OPTION__INCLUDE_MODE__DAB
    case dmb:
	case dab:
        ret = dab_get_event_status__command(1);
        ret |= dab_get_event_status__reply(&dges);
        if(ret == SUCCESS)
        {
            ret = _update_DAB_service_list_worker(dges);
        }
        break;
#endif //OPTION__INCLUDE_MODE__DAB
	default:break;
    }
    

    return ret;
}
#endif //OPTION__INCLUDE_MODE__ANY


#define SIS_UPDATE__SHORT_NAME_MASK (UPDATED_USN | UPDATED_SNS)
#define SIS_UPDATE__LONG_NAME_MASK (UPDATED_SLGN | UPDATED_SNL | UPDATED_SM)

#ifdef OPTION__INCLUDE_MODE__ANY
RETURN_CODE UpdateDataServiceData(void)
{
    RETURN_CODE ret = 0;
	get_digital_service_data__data gdsd;

#ifdef OPTION__HANDLE_ADVANCED_SERVICES
	ServiceList* currP;
	GENERAL_SERVICE_TYPE packetType;
#endif

#ifdef OPTION__INCLUDE_MODE__FM
	fm_rds_status__data frs;
#endif
#ifdef OPTION__INCLUDE_MODE__FMHD
    uint8_t i;
    hd_get_event_status__data fges;
#ifndef OPTION__PSD_FORMAT_ID3
    fmhd_get_psd_decode__data fgpd;
#endif
#ifdef OPTION__DECODE_HD_ALERTS
    fmhd_get_alert_message__data fgamd;
#endif
#endif

	//dab_digrad_status__data dds;

    _update_status();

    // Update RDS if present
#ifdef OPTION__INCLUDE_MODE__FM
	if(_si46xx_status.RDSINT)
	{
        do{
			ret = fm_rds_status__command(0,0,1);
			ret |= fm_rds_status__reply(&frs);

			if(ret == SUCCESS)
			{
                #ifdef OPTION__RDS_BUFFER_V4L2
				    //TODO: add rds blocks to undecoded buffer - V4L2
                #else
                    updateRDS(frs);
                #endif
			}
        }while((ret == SUCCESS) && (frs.RDSFIFOUSED > 1));
    }
#endif //OPTION__INCLUDE_MODE__FM

    // Update SIS/Service List if present
    if(_si46xx_status.DEVNTINT)
    {
#ifdef OPTION__INCLUDE_MODE__FMHD
        if(_current_image_type == fmhd || _current_image_type == amhd)
        {
            ret = hd_get_event_status__command(1);  //ack the event status
            ret |= hd_get_event_status__reply(&fges);

            if(ret == SUCCESS)
            {
                #ifdef OPTION__DECODE_HD_ALERTS
                    if(fges.ALERTINT)
                    {
                        ret |= fmhd_get_alert_message__command();
                        ret |= fmhd_get_alert_message__reply(&fgamd);

                        updateAlerts(&fgamd);
                    }
                #endif

                #ifdef OPTION__DECODE_SIS
                    if(fges.SIS && fges.SISINT)
                    {
                        //TODO: if the definitions for the SIS DATA TYPES change - this will need to be corrected
                        for(i=STATION_MESSAGE; i<=SLOGAN; i++)
                        {
                            ret |= _update_SIS_worker((FMHD_SIS_DATA_TYPE)i);
                        }

                        //Need to request BASIC again to get longitude data
                        ret |= _update_SIS_worker(BASIC_SIS_DATA);
                    }
                #endif

                #ifdef OPTION__DECODE_PSD
                    #ifndef OPTION__PSD_FORMAT_ID3

                        if(fges.PSD && fges.PSDINT)
                        {
                            if(fges.TITLE)
                            {
                                ret |= fmhd_get_psd_decode__command(0xFF,TITLE);
                                ret |= fmhd_get_psd_decode__reply(&fgpd);
                                if(ret == SUCCESS)
                                {
                                    updatePSD(TITLE,fgpd);
                                }
                            }
                            if(fges.ARTIST)
                            {
                                ret |= fmhd_get_psd_decode__command(0xFF,ARTIST);
                                ret |= fmhd_get_psd_decode__reply(&fgpd);
                                if(ret == SUCCESS)
                                {
                                    updatePSD(ARTIST,fgpd);
                                }
                            }
                            if(fges.ALBUM)
                            {
                                ret |= fmhd_get_psd_decode__command(0xFF,ALBUM);
                                ret |= fmhd_get_psd_decode__reply(&fgpd);
                                if(ret == SUCCESS)
                                {
                                    updatePSD(ALBUM,fgpd);
                                }
                            }
                            if(fges.GENRE)
                            {
                                ret |= fmhd_get_psd_decode__command(0xFF,GENRE);
                                ret |= fmhd_get_psd_decode__reply(&fgpd);
                                if(ret == SUCCESS)
                                {
                                    updatePSD(GENRE,fgpd);
                                }
                            }
                        }

                    #endif
                #endif

                //We ACKed the event interrupt, so we need to send the event status to the service list update function
                //Handle Service List update
                ret |= _update_HD_service_list_worker(fges);
            }
        }
#endif //OPTION__INCLUDE_MODE__FMHD


    }

	//Check for valid data in the data service interface
	//TODO - this currently only checks for the DSRVINT, not the actual data ready bit in GET_DIGITAL_SERVICE_DATA
	//**************************************************************************
	if(_si46xx_status.DSRVINT) // Data Ready
	{
        //TODO: loop this read to handler all data service items in the buffer
		ret = get_digital_service_data__command(0,1);
		ret |= get_digital_service_data__reply(&gdsd);

		// NO OTHER COMMANDS CAN BE ISSUED BEFORE PROCESSING DATA - PAYLOAD has been READ already

		if((gdsd.BYTE_COUNT > 0) && (ret == SUCCESS))	//Sometimes this loops gets in a state where the command to read digital service data always reports a command error.
		{

			//Send to appropriate handler
            //If PSD data we handle is seperately from the tracked service list
#ifdef OPTION__INCLUDE_MODE__FMHD
            #ifdef OPTION__DECODE_PSD
                #ifdef OPTION__PSD_FORMAT_ID3
                    if(_current_image_type == fmhd)
                    {
                        switch(gdsd.COMPONENT_ID)
                        {
                            case PSD_CID_MPS:
                            case PSD_CID_SPS1:
                            case PSD_CID_SPS2:
                            case PSD_CID_SPS3:
                            case PSD_CID_SPS4:
                            case PSD_CID_SPS5:
                            case PSD_CID_SPS6:
                            case PSD_CID_SPS7:
                                updatePSD(gdsd);
                                //Packet was PSD - no need to run through the data handler
                                return ret;
                            default:
                                break;
                        }
                    }
                #endif //OPTION__PSD_FORMAT_ID3
            #endif //OPTION__DECODE_PSD
#endif //OPTION__INCLUDE_MODE__FMHD
#ifdef OPTION__INCLUDE_MODE__DAB
            #ifdef OPTION__DECODE_DLS
                if(_current_image_type == dab)
                {
                    //TODO current implementation will not work long term - as we need to handle other PAD data types, TDC, MOT, etc
                    if((gdsd.SERVICE_ID == _current_audio_service_id) && (gdsd.COMPONENT_ID == _current_audio_component_id))
                    {
                        if(gdsd.DATA_SRC == CMD_GET_DIGITAL_SERVICE_DATA_REP_DATA_SRC_ENUM_PAD_DLS)
                        {
                            updateDLS(gdsd);
                        }
                        
                        return ret;
                    }
                }
            #endif
#endif //OPTION__INCLUDE_MODE__DAB

            // Check if there are digital services to update
#ifdef OPTION__HANDLE_ADVANCED_SERVICES
	        if(_service_list != NULL)
	        {
			    currP = _service_list;
			    packetType = SERVICE_TYPE_ERR;
			    do
			    {
				    if(currP->ignore_packet_count == 0)
				    {
					    if((currP->service_id == gdsd.SERVICE_ID) && (currP->component_id == gdsd.COMPONENT_ID))
					    {
						    packetType = currP->type;
						    
                            switch(packetType)
			                {
			                case SERVICE_TYPE_FMHD_LOT:
			                case SERVICE_TYPE_DAB_SLS:
			                //case SERVICE_TYPE_DAB_DLS:
			                case SERVICE_TYPE_DAB_MOT:
			                case SERVICE_TYPE_DMB_VIDEO:
                                //TODO: implement data service handlers
                                //CpyMemory(currP->bufferPtr,gdsd.PAYLOAD,gdsd.BYTE_COUNT);
				                break;
			                case SERVICE_TYPE_ERR:
				                //No packet found for a selected service - discard packet
				                break;
			                }
					    }
				    }
				    else
				    {
					    currP->ignore_packet_count --;
				    }
				    currP = currP->next;
			    }while(currP != NULL);
            }
#endif
		}
	}
    
    return SUCCESS;
}
#endif //OPTION__INCLUDE_MODE__ANY

#ifdef OPTION__INCLUDE_MODE__ANY
RETURN_CODE StartProcessingChannel(GENERAL_SERVICE_TYPE type, uint32_t service_id, uint32_t component_id, uint8_t *service_buffer)
{
	RETURN_CODE ret = 0;
#ifdef OPTION__HANDLE_ADVANCED_SERVICES
    ServiceList *node;
#endif
	
    //Check if it is an audio or data service we need to start
    switch(type)
    {
#if defined (OPTION__INCLUDE_MODE__FMHD)||defined(OPTION__INCLUDE_MODE__AMHD)
        case SERVICE_TYPE_HD_AUDIO:
            #ifdef OPTION__DECODE_PSD
                initPSD();
            #endif
            ret = start_digital_service__command(0,service_id,component_id);
            if(ret == SUCCESS)
            {
                _current_hd_audio_service_as_bitmask = (1 << component_id);
                _current_audio_service_id = service_id;
                _current_audio_component_id = component_id;
            }
            break;
#endif
#ifdef OPTION__INCLUDE_MODE__DAB
        case SERVICE_TYPE_DAB_AUDIO:
            #ifdef OPTION__DECODE_DLS
                initDLS();
            #endif
            ret = start_digital_service__command(0,service_id,component_id);

            if(ret == SUCCESS)
            {
                _current_audio_service_id = service_id;
                _current_audio_component_id = component_id;

                #ifdef OPTION__DAB_SUPPORT_DAB_DAB_LINKING_A3
                    _service_linking_clear_service_links();
                #endif //OPTION__DAB_SUPPORT_DAB_DAB_LINKING_A3
                _DAB_service_lost = 0;
            }

            break;
#endif
#ifdef OPTION__HANDLE_ADVANCED_SERVICES
        case SERVICE_TYPE_FMHD_LOT:
        case SERVICE_TYPE_DAB_SLS:
        case SERVICE_TYPE_DAB_MOT:
        case SERVICE_TYPE_DMB_VIDEO:

            //Add the selected service to the linked list
	        node = (ServiceList*)malloc(sizeof(ServiceList));

	        node->type = type;
	        node->service_id = service_id;
	        node->component_id = component_id;
	        node->next = _service_list;
	        node->bufferPtr = service_buffer;

	        _service_list = node;

	        // Check the current number of packets in the buffer for how many should be ignored by this service
	        // *****************************************************************************************************
	        ret = get_digital_service_data__command(1,0);
	
	        if(ret == SUCCESS)
	        {
		        get_digital_service_data__data gdsd;
		        ret = get_digital_service_data__reply(&gdsd);
		
		        if(ret == SUCCESS)
		        {
			        // when a new service is started in the handler we want to be sure we ignore the current packets in the data buffer, to ensure only fresh data is included.
			        node->ignore_packet_count = gdsd.BUFF_COUNT;
		        }
		        else
		        {
			        //Failure - we will just live with 0 ignored packets
			        node->ignore_packet_count = 0;
		        }
	        }
	        else
	        {
		        node->ignore_packet_count = 0;
	        }
	        // *****************************************************************************************************
            break;
#endif
        default:
            return INVALID_INPUT;
            break;
    }
    
    return ret;
}
#endif //OPTION__INCLUDE_MODE__ANY

#ifndef OPTION__REMOVE_SDK_FUNCTIONS_NOT_USED_BY_MMI
RETURN_CODE StopProcessingChannel(uint32_t service_id, uint32_t component_id)
{
	RETURN_CODE ret = 0;
    GENERAL_SERVICE_TYPE removedServiceType = SERVICE_TYPE_ERR;

    //Check if it is the current audio service
    if((service_id == _current_audio_service_id) && (component_id == _current_audio_component_id))
    {
        //End as an audio service
        ret = stop_digital_service__command(0,service_id,component_id);
        _current_audio_service_id = 0;
        _current_audio_component_id = 0;

        #ifdef OPTION__INCLUDE_MODE__DAB
            #ifdef OPTION__DAB_SUPPORT_DAB_DAB_LINKING_A3
                _service_linking_clear_service_links();
            #endif //OPTION__DAB_SUPPORT_DAB_DAB_LINKING_A3
        #endif
    }
#ifdef OPTION__HANDLE_ADVANCED_SERVICES
    else
    {
        //Remove from active service - linked list
        _service_list = _deleteNode(_service_list, service_id, component_id, &removedServiceType);

	    if(removedServiceType == SERVICE_TYPE_ERR)
	    {
		    return INVALID_INPUT;
	    }
        else
        {
            //stop the data service
            ret = stop_digital_service__command(1,service_id,component_id);
        }
    }
#endif

	return ret;
}
#endif //OPTION__MINIMAL_FIRMWARE_FUNCTION_IMPLEMENTATION_SMALLER_SDK

#ifdef OPTION__INCLUDE_MODE__ANY
status_bits GetSi46XXStatus(void)
{
	RETURN_CODE ret = _update_status();

	if(ret != SUCCESS)
	{
		_empty_status();
	}

	return _si46xx_status;
}

RETURN_CODE SetProperty(uint16_t prop_id, uint16_t value)
{
    uint8_t prop_group;
    uint8_t prop_index;

    prop_group = (uint8_t)(prop_id >> 8);
    prop_index = (uint8_t)(prop_id & 0xFF);

    if(
        ((prop_group == PROP_FM_SEEK_BAND_BOTTOM_GROUP) && (prop_index == PROP_FM_SEEK_BAND_BOTTOM_INDEX)) ||
        ((prop_group == PROP_FM_SEEK_BAND_TOP_GROUP) && (prop_index == PROP_FM_SEEK_BAND_TOP_INDEX)) ||
        ((prop_group == PROP_FM_SEEK_BAND_TOP_GROUP) && (prop_index == PROP_FM_SEEK_BAND_TOP_INDEX))
        )
    {
        return INVALID_INPUT;
    }

	return set_property__command(prop_id, value);
}

RETURN_CODE GetProperty(uint16_t prop_id, uint16_t *value)
{
	RETURN_CODE ret = 0;

	ret = get_property__command(prop_id);
	ret |= get_property__reply(value);

	return ret;
}
#endif //OPTION__INCLUDE_MODE__ANY

RETURN_CODE StartFirmwareUpdate()
{
    RETURN_CODE ret = 0;

    _current_audio_service_id = 0;
    _current_audio_component_id = 0;


#ifdef OPTION__INCLUDE_MODE__FM
    _empty_metrics_fm();
#endif
#ifdef OPTION__INCLUDE_MODE__FMHD
    _empty_metrics_fmhd();
#endif
#ifdef OPTION__INCLUDE_MODE__DAB
    _empty_metrics_dab();
    #ifdef OPTION__DAB_SUPPORT_DAB_DAB_LINKING_A3
        _service_linking_clear_service_links();
    #endif //OPTION__DAB_SUPPORT_DAB_DAB_LINKING_A3
#endif
    

	// Load the bootloader firmware for the device
	ret = _si46xx_initialize(patch_firmware_update);

	if(ret == SUCCESS)
	{
		//Determine what mode we are in to track for other functions.
        _current_image_type = patch_firmware_update;

        CALLBACK_Updated_Data(EVENT_READY_FOR_FIRMWARE_UPDATE);
	}

	return ret;
}

#ifdef OPTION__RADIODNS
#ifdef OPTION__INCLUDE_MODE__FM
//Calculates each of the pieces of the RDS RadioDNS string
//Note: This does not support the country code form of the string as that information is not available from the broadcast alone
//
//String format: <frequency>.<pi>.<gcc>.fm.radiodns.org
//    - frequency: in 5 characters (leading 0 for frequencies below 100MHz)
//    - pi: in 4 characters
//    - gcc: in 3 characters
RETURN_CODE UpdateRadioDNS_FMRDS(radioDNS_fm* elements)
{
    if(_current_image_type == fmonly || _current_image_type == fmhd)
    {
        UpdateMetrics();
        if(_current_image_type == fmonly)
        {
            elements->FREQUENCY_10KHZ = _current_fm_metrics.FREQUENCY_10KHZ;
        }
        else
        {
            elements->FREQUENCY_10KHZ = _current_fmhd_metrics.FREQUENCY_10KHZ;
        }

        
        elements->PI = RDSGetProgramIdentifier();
        if(elements->PI == 0)
        {
            return INVALID_INPUT;
        }

        elements->GCC = RDSGetECC();
        if(elements->GCC == 0)
        {
            return INVALID_INPUT;
        }
        elements->GCC = (elements->GCC | ((elements->PI & 0xF000) >> 4));

        return SUCCESS;
    }
    
    return INVALID_MODE;
}
#endif //OPTION__INCLUDE_MODE__FM

#ifdef OPTION__INCLUDE_MODE__DAB

//Calculates each of the pieces of the DAB RadioDNS string
//Note: This does not support the <apptype-uatype>.<pa>. variant
//
//String format: <scids>.<sid>.<eid>.<gcc>.dab.radiodns.org
//    - scids: in 1 character
//    - sid: in 4 characters (when the upper 16 bits are 0) or
//           in 8 characters (when the upper 16 bits are non-zero)
//    - eid: in 4 characters
//    - gcc: in 3 characters
RETURN_CODE UpdateRadioDNS_DAB(radioDNS_dab* elements)
{
    RETURN_CODE ret = 0;
    dab_get_ensemble_info__data dgei;
    dab_get_service_info__data dgsi;
    dab_get_component_info__data dgci;
    uint32_t tempGCC = 0;

    if(_current_image_type == dab)
    {
        if(_current_audio_service_id != 0)
        {
            elements->SID = _current_audio_service_id;

            ret |= dab_get_service_info__command(_current_audio_service_id);
            ret |= dab_get_service_info__reply(&dgsi);

            ret |= dab_get_component_info__command(_current_audio_service_id, _current_audio_component_id);
            ret |= dab_get_component_info__reply(&dgci);

            //Do ensemble info read last so the LABEL field is still valid in the reply buffer (even though it isn't used)
            //Illustrative of proper usage of the api
            ret |= dab_get_ensemble_info__command();
            ret |= dab_get_ensemble_info__reply(&dgei);

            if(ret == SUCCESS)
            {
                elements->SCIDS = dgci.GLOBAL_ID;
                elements->EID = dgei.EID;

                if((_current_audio_service_id & 0xFFFF0000) == 0)
                {
                    //use the service ECC if available, otherwise use the ensemble ecc.
                    if(dgsi.SRV_ECC != 0)
                    {
                        tempGCC = dgsi.SRV_ECC;
                    }
                    else
                    {
                        tempGCC = dgei.ENSEMBLE_ECC;
                    }

                    elements->GCC = (uint16_t)(tempGCC | ((_current_audio_service_id & 0x0000F000) >> 4));
                }
                else
                {
                    tempGCC = (((_current_audio_service_id & 0x00F00000) >> 12) | (_current_audio_service_id >> 24));
                    elements->GCC = (uint16_t)tempGCC;
                }
            }

            return ret;
        }

        return INVALID_INPUT;
    }
    
    return INVALID_MODE;   
}
#endif //OPTION__INCLUDE_MODE__DAB

#endif


#ifdef OPTION__INCLUDE_FRONT_END_TEST_FUNCTIONS
#ifdef OPTION__INCLUDE_MODE__DAB
void Test_DeterminePeakANTCAP_DAB(uint8_t freqIndex, uint16_t* antcapPeak)
{
    // Not checking return codes because RSSI read failures will set value to 0
    int16_t rssi;
    int16_t peakRSSI;
    int32_t avgRSSI;
    uint8_t loop5;
    uint16_t antcapTemp = _ANTCAP_DAB;
    
    *antcapPeak = 0;
    peakRSSI = 0;

    for(_ANTCAP_DAB = 1; _ANTCAP_DAB <= CMD_DAB_TUNE_FREQ_ARG_ANTCAP_MAX; _ANTCAP_DAB++)
    {
        _DAB_scan_continue = 1;
        _service_following_enabled = 0; //We want to disable service following while we are dealing with starting services
        _DAB_tune(freqIndex);
        _DAB_confirm_tune_complete(0,1);
        
        avgRSSI = 0;        

        for(loop5 = 0;loop5 < 5; loop5 ++)
        {
            test_get_rssi__command();
            test_get_rssi__reply(&rssi);
            avgRSSI = avgRSSI + rssi;
        }

        avgRSSI = avgRSSI / 5;
        if(avgRSSI > peakRSSI)
        {
            peakRSSI = (int16_t)avgRSSI;
            *antcapPeak = _ANTCAP_DAB;
        }

        CALLBACK_Updated_Data(DAB_FRONT_END_CAL_PROCESS_UPDATE);
    }

    _ANTCAP_DAB = antcapTemp;
}

#define DAB_BER_TIMEOUT_100MS 100
#define DAB_BER_DELAY_100MS 100
#define DAB_BER_TEST_DURATION_BITS 1000000
RETURN_CODE Test_GetBER_DAB(uint8_t berPattern, uint32_t* errorBits, uint32_t* totalBits, uint8_t* passResult)
{
    RETURN_CODE ret = 0;
    uint16_t berTimeSpent100MS = 0;
    dab_test_ber_info__data dtbi;

    *passResult = 0;

    ret = _set_property(PROP_DAB_TEST_BER_CONFIG_GROUP, PROP_DAB_TEST_BER_CONFIG_INDEX, 0);
    ret |= _set_property(PROP_DAB_TEST_BER_CONFIG_GROUP, PROP_DAB_TEST_BER_CONFIG_INDEX, PROP_DAB_TEST_BER_CONFIG_ENABLE_BIT | berPattern);

    do{
        delay(DAB_BER_DELAY_100MS); // delay first to ensure we have some bits tested
        berTimeSpent100MS += 1; // in units of 100ms
        ret = dab_test_ber_info__command();
        ret |= dab_test_ber_info__reply(&dtbi);
        *totalBits = dtbi.TOTAL_BITS;
        if((*totalBits == 0) && (berTimeSpent100MS > 10))
        {
            //no bits tested - likely not acquired
            ret = TIMEOUT;
            break;
        }
    }while((dtbi.TOTAL_BITS < DAB_BER_TEST_DURATION_BITS) && (berTimeSpent100MS < DAB_BER_TIMEOUT_100MS));

    if(berTimeSpent100MS > DAB_BER_TIMEOUT_100MS)
    {
        ret = TIMEOUT;
    }

    if(ret == SUCCESS)
    {
        *errorBits = dtbi.ERR_BITS;
	    
       
        //Convert err for determining 1e-4 results
        if((dtbi.ERR_BITS < 429496) && (((dtbi.ERR_BITS * 10000) / dtbi.TOTAL_BITS) < 1))
		{
			*passResult = 1;
		}
		else
		{
			*passResult = 0;
		}
    }
    else
    {
        *errorBits = 0;
    }

    return ret;
}
#endif //OPTION__INCLUDE_MODE__DAB


#ifdef OPTION__INCLUDE_MODE__FMHD

#define HD_BER_TIMEOUT_100MS 100
#define HD_BER_DELAY_100MS 100
#define HD_BER_TEST_DURATION_BITS 1000000
RETURN_CODE Test_GetBER_FMHD(uint32_t* errorBits, uint32_t* totalBits, uint8_t* passResult)
{
    RETURN_CODE ret = 0;
    uint16_t berTimeSpent100MS = 0;
    fmhd_test_get_ber_info__data ftgbi;

    *passResult = 0;

    ret = _set_property(PROP_HD_TEST_BER_CONFIG_GROUP, PROP_HD_TEST_BER_CONFIG_INDEX, 0);
    ret |= _set_property(PROP_HD_TEST_BER_CONFIG_GROUP, PROP_HD_TEST_BER_CONFIG_INDEX, PROP_HD_TEST_BER_CONFIG_ENABLE_BIT);

    do{
        delay(HD_BER_DELAY_100MS); // delay first to ensure we have some bits tested
        berTimeSpent100MS += 1; // in units of 100ms
        ret |= fmhd_test_get_ber_info__command();
        ret |= fmhd_test_get_ber_info__reply(&ftgbi);
        *totalBits = ftgbi.P1_BITS_TESTED;
        if((*totalBits == 0) && (berTimeSpent100MS > 10))
        {
            //no bits tested - likely not acquired
            ret = TIMEOUT;
            break;
        }
    }while((ftgbi.P1_BITS_TESTED < HD_BER_TEST_DURATION_BITS) && (berTimeSpent100MS < HD_BER_TIMEOUT_100MS));

    if(berTimeSpent100MS > HD_BER_TIMEOUT_100MS)
    {
        ret = TIMEOUT;
    }

    if(ret == SUCCESS)
    {
        *errorBits = ftgbi.P1_BIT_ERRORS;

		//Convert err for determining 5e-5 results
		if((ftgbi.P1_BIT_ERRORS < 214748) && (((ftgbi.P1_BIT_ERRORS * 20000) / ftgbi.P1_BITS_TESTED) < 1))
		{
			*passResult = 1;
		}
    }
    else
    {
        *errorBits = 0;
    }

    return ret;
}


RETURN_CODE Test_StartFreeRunningBER_FMHD()
{
    RETURN_CODE ret = 0;

    ret = _set_property(PROP_HD_TEST_BER_CONFIG_GROUP, PROP_HD_TEST_BER_CONFIG_INDEX, 0);
    ret |= _set_property(PROP_HD_TEST_BER_CONFIG_GROUP, PROP_HD_TEST_BER_CONFIG_INDEX, PROP_HD_TEST_BER_CONFIG_ENABLE_BIT);

    return ret;
}

RETURN_CODE Test_GetFreeRunningBER_FMHD(uint8_t bitType, uint32_t* errorBits, uint32_t* totalBits)
{
    RETURN_CODE ret = 0;
    fmhd_test_get_ber_info__data ftgbi;

    ret |= fmhd_test_get_ber_info__command();
    ret |= fmhd_test_get_ber_info__reply(&ftgbi);

    if(ret == SUCCESS)
    {
        switch(bitType)
        {
            case HD_P1:
                *totalBits = ftgbi.P1_BITS_TESTED;
                *errorBits = ftgbi.P1_BIT_ERRORS;
                break;
            case HD_P2:
                *totalBits = ftgbi.P2_BITS_TESTED;
                *errorBits = ftgbi.P2_BIT_ERRORS;
                break;
            case HD_P3:
                *totalBits = ftgbi.P3_BITS_TESTED;
                *errorBits = ftgbi.P3_BIT_ERRORS;
                break;
            case HD_PIDS_BIT:
                *totalBits = ftgbi.PIDS_BITS_TESTED;
                *errorBits = ftgbi.PIDS_BIT_ERRORS;
                break;
            case HD_PIDS_BLOCK:
                *totalBits = ftgbi.PIDS_BLOCKS_TESTED;
                *errorBits = ftgbi.PIDS_BLOCK_ERRORS;
                break;
            default:
                ret = INVALID_INPUT;
                break;
        }  
    }
    
    if(ret != SUCCESS)
    {
        *totalBits = 0;
        *errorBits = 0;
    }

    return ret;
}

#endif //OPTION__INCLUDE_MODE__FMHD



#endif //OPTION__INCLUDE_FRONT_END_TEST_FUNCTIONS


#ifdef OPTION__INCLUDE_MODE__FM
fm_metrics* MetricsGetFMPtr()
{
    return &_current_fm_metrics;
}

#ifdef OPTION__RDS_BUFFER_V4L2
//TODO: add V4L2
#else
uint8_t* RDSGetRadioTextPtr()
{
    return rtDisplay;
}
uint8_t* RDSGetProgramServiceTextPtr()
{
    return psDisplay;
}
uint16_t RDSGetProgramIdentifier(void)
{
    return piDisplay;
}
uint8_t  RDSGetProgramType(void)
{
    return ptyDisplay;
}
#ifdef OPTION__RADIODNS
    uint8_t RDSGetECC(void)
    {
        return eccDisplay;
    }
#endif
rds_time RDSGetCurrentTime(void)
{
    return currentTime;
}

    #ifndef OPTION__REMOVE_SDK_FUNCTIONS_NOT_USED_BY_MMI
        void ConfigureRDSOptions(uint8_t ignore_AB_flag)
        {
                ignoreAB(ignore_AB_flag);
        }
    #endif //OPTION__REMOVE_SDK_FUNCTIONS_NOT_USED_BY_MMI
#endif
#endif //OPTION__INCLUDE_MODE__FM



#ifdef OPTION__INCLUDE_MODE__AM
am_metrics* MetricsGetAMPtr()
{
    return &_current_am_metrics;
}
#endif

#ifdef OPTION__INCLUDE_MODE__AMHD
amhd_metrics* MetricsGetAMHDPtr()
{
    return &_current_amhd_metrics;
}
#endif


#ifdef OPTION__INCLUDE_MODE__FMHD
fmhd_metrics* MetricsGetFMHDPtr()
{
    return &_current_fmhd_metrics;
}

fmhd_service_list_fast* FMHDServiceListFastPtr()
{
    return &svcListFast;
}
fmhd_service_list* FMHDServiceListAudioPtr()
{
    return &svcListFull_Audio;
}

#ifdef OPTION__DECODE_SIS
fmhd_sis_slogan* SISGetSloganPtr()
{
    return &slgnDisplay;
}

fmhd_sis_universal_short_name* SISGetUSNPtr()
{
    return &usnDisplay;
}

fmhd_sis_station_message* SISGetSMPtr()
{
    return &smDisplay;
}

uint8_t* SISGetSNLPtr()
{
    return snlDisplay;
}

uint8_t* SISGetSNSPtr()
{
    return snsDisplay;
}

uint8_t* SISGetStationIDPtr()
{
    return stationID;
}

uint8_t* SISGetStationLocLatPtr()
{
    return stationLocationLat;
}

uint8_t* SISGetStationLocLongPtr()
{
    return stationLocationLong;
}
#endif //OPTION__DECODE_SIS

#ifdef OPTION__DECODE_PSD
fmhd_psd_generic_string* PSDGetTitlePtr()
{
    return &titleDisplay;
}
fmhd_psd_generic_string* PSDGetArtistPtr()
{
    return &artistDisplay;
}
fmhd_psd_generic_string* PSDGetAlbumPtr()
{
    return &albumDisplay;
}
fmhd_psd_generic_string* PSDGetGenrePtr()
{
    return &genreDisplay;
}
#endif //OPTION__DECODE_PSD

#ifdef OPTION__DECODE_HD_ALERTS
fmhd_alert_string* HDAlertGetPtr()
{
   return &alertDisplay;     
}

#endif //OPTION__DECODE_HD_ALERTS

#endif //OPTION__INCLUDE_MODE__FMHD


#ifdef OPTION__INCLUDE_MODE__DAB
dab_service_list* DABServiceListAudioPtr()
{
    return &svcListDAB;
}

dab_metrics* MetricsGetDABPtr()
{
    return &_current_dab_metrics;
}
#ifdef OPTION__DECODE_DLS
dab_dls_string* DLSGetPtr()
{
    return &dlsDisplay;
}

#endif //OPTION__DECODE_DLS

#endif //OPTION__INCLUDE_MODE__DAB