/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   Top Level API for the Radio Manager of the SDK - MMI interface
   FILE: Firmware_API_Manager.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#ifndef __SI46XX_INTERFACE_HANDLER_TYPE__
#define __SI46XX_INTERFACE_HANDLER_TYPE__

#include "common_types.h"
#include "platform_options.h"
#include "feature_types.h"
#include "si46xx_firmware_api_status.h"

typedef enum _GENERAL_SERVICE_TYPE
{
	//SERVICE_TYPE_FMRX_RDS = 0x00,

	SERVICE_TYPE_HD_AUDIO = 0x10,
	//SERVICE_TYPE_FMHD_SIS = 0x11,
	//SERVICE_TYPE_FMHD_PSD = 0x12,
	SERVICE_TYPE_FMHD_LOT = 0x13,

	SERVICE_TYPE_DAB_AUDIO = 0x20,
	SERVICE_TYPE_DAB_SLS = 0x21,
	//SERVICE_TYPE_DAB_DLS = 0x22, // associated with the current audio service - no need to start seperately
	SERVICE_TYPE_DAB_MOT = 0x23,

	SERVICE_TYPE_DMB_VIDEO = 0x30,
	
	SERVICE_TYPE_ERR
}GENERAL_SERVICE_TYPE;

typedef enum _BASEBAND_STATUS
{
	BASEBAND_IDLE = 0x00,
	BASEBAND_INIT,
	BASEBAND_READY,
	BASEBAND_PROCESSING_COMMAND,
	BASEBAND_SCANNING,
	BASEBAND_FINALIZE,
    BASEBAND_FIRMWAREUPDATE,
	BASEBAND_ERROR
}BASEBAND_STATUS;

typedef enum _AUDIO_MUTE
{
	NOT_MUTED = 0,
	MUTE_LEFT_ONLY = 1,
	MUTE_RIGHT_ONLY = 2,
	MUTE_LEFT_RIGHT = 3,
	MUTE_ERR
}AUDIO_MUTE;

typedef enum _AUDIO_MONO_STEREO_SWITCH
{	
	AUDIO_STEREO = 0,
	AUDIO_MONO = 1,
	AUDIO_ERR
}AUDIO_MONO_STEREO_SWITCH;


#ifdef OPTION__HANDLE_ADVANCED_SERVICES
typedef struct _ServiceList ServiceList;
struct _ServiceList
{
	GENERAL_SERVICE_TYPE type;
	uint32_t service_id;
	uint32_t component_id;
	ServiceList *next;
	uint8_t *bufferPtr;
	uint8_t ignore_packet_count;
};
#endif

// Startup Functions
//************************************************************************************************************************
//************************************************************************************************************************

//************************************************************************************************************************
// Function: Initialize
// Inputs:
//     - mode: the selected mode you would like to start the radio in.  Note this is limited by the part's supported modes
//         example: fmonly, fmhd, dab
// Outputs:
//     - RETURN_CODE
// Description: this is the first function you call when starting or changing radio modes.  It handles firmware download
//     and part configuration
//************************************************************************************************************************
RETURN_CODE Initialize(RADIO_MODE_TYPE mode);

//************************************************************************************************************************
// Function: Finalize
// Inputs: none
// Outputs:
//     - RETURN_CODE
// Description: this is the final function you call when you are finished with the radio.  It will put the part in receiver
//     in its lowest power state
//************************************************************************************************************************
RETURN_CODE Finalize();



// FM + FMHD Functions
//************************************************************************************************************************
//************************************************************************************************************************

//************************************************************************************************************************
// Function: Tune
// Inputs:
//     - freq: the desired tune frequency
//          - for fm/fmhd in 10kHz units. For example - 102.3Mhz = 10230
//          - for am/amhd in 1kHz units. For example - 1000kHz = 1000
// Outputs:
//     - RETURN_CODE
// Description: This function should be called after initial startup in FM/FMHD mode to establish an initial frequency.
//     after initial tune, it is desirable to use TuneStep() and SeekStart() to move between frequencies.
//     Be sure that any calls the SetStepSize() or SetBandLimits() are performed prior to this initial Tune()
//
//     Note: because some amount of time is required for Tune to complete - the host should call SeekTuneCompleteCheck()
//         to verify completion.  No callback is issued because all tune processing occurs in the receiver chip.
//************************************************************************************************************************
RETURN_CODE Tune(uint16_t freq);

//************************************************************************************************************************
// Function: SetStepSize
// Inputs
//     - stepsize_khz: the desired frequency spacing for the region in use.  Example: 100 kHz (100) or 200 kHz (200).
// Outputs:
//     - RETURN_CODE
// Description: This function is used to configure the channel spacing for the current region.
//     Thus function should be called before Tune() or SeekStart()
//************************************************************************************************************************
RETURN_CODE SetStepSize(uint8_t stepsize_khz);

#ifndef OPTION__REMOVE_SDK_FUNCTIONS_NOT_USED_BY_MMI
//************************************************************************************************************************
// Function: SetBandLimits
// Inputs
//     - limits: the band limits for the region in use.  Defined in common_types.h: JAPAN_76_90, STANDARD_875_1079, WIDE_78_108
// Outputs:
//     - RETURN_CODE
// Description: This function is used to configure the band limits for the current region.
//     Thus function should be called before Tune() or SeekStart()
//************************************************************************************************************************
RETURN_CODE SetBandLimits(FM_BAND_LIMITS limits);
#endif //OPTION__REMOVE_SDK_FUNCTIONS_NOT_USED_BY_MMI

//************************************************************************************************************************
// Function: TuneStep
// Inputs
//     - stepup: 0: step down, 1: step up.  Used to select the direction for the step.
// Outputs:
//     - RETURN_CODE
// Description: This function is used to advance the current service to the next in the selected direction.
//     For fmonly mode: this will step the frequency: current_frequency + step_size (as defined in SetStepSize())
//          Note: this will also wrap to the other side of a band boundry
//     For fmhd mode:
//          - when HD is acquired on the current frequency, will move to the next service while staying on the frequency.
//          If there is no more subchannels, will advance to the next frequency
//			- when HD is not acquired on the current frequency, will move to the next frequency
//          Note: this will also wrap to the other side of a band boundry
//************************************************************************************************************************
RETURN_CODE TuneStep(uint8_t stepup);

//************************************************************************************************************************
// Function: SeekStart
// Inputs
//     - seekup: 0: seek down, 1: seek up.  Used to select the direction for the seek.
//     - wrap: 0: do not wrap/stop at band edge, 1: wrap.  Used to select if the seek should wrap at the band edge or stop
//     - hdseekonly: 0: seek only with analog indicators for a valid station, 1: seek stop only on stations with HD.
// Outputs:
//     - RETURN_CODE
// Description: This function is used to start a seek to the next valid channel/service.
//     For fmonly mode: this will seek to the next valid frequency according to the RSSI/SNR thresholds
//     For fmhd mode:
//          - when HD is acquired on the current frequency, will move to the next service while staying on the frequency.
//          If there is no more subchannels, will seek to the next valid frequency according to the RSSI/SNR thresholds
//			- when HD is not acquired on the current frequency, will seek to the next valid frequency according to the RSSI/SNR thresholds
// 		Note: this command will start the seek process in the receiver, the user can end the seek early by called SeekStop().
//		Note: The host should keep checking SeekTuneCompleteCheck() for a non-zero value to determine the seek is complete.
//          .  No callback is issued because all seek processing occurs in the receiver chip.
//      Calls to UpdateMetrics are valid to update the current frequency the seek is on while seeking.
//************************************************************************************************************************
RETURN_CODE SeekStart(uint8_t seekup, uint8_t wrap, uint8_t hdseekonly);

#ifndef OPTION__REMOVE_SDK_FUNCTIONS_NOT_USED_BY_MMI
//************************************************************************************************************************
// Function: SeekStop
// Inputs: none
// Outputs:
//     - RETURN_CODE
// Description: This function is used to cancel a seek currently in progress.
//************************************************************************************************************************
RETURN_CODE SeekStop();
#endif //OPTION__REMOVE_SDK_FUNCTIONS_NOT_USED_BY_MMI

//************************************************************************************************************************
// Function: SeekTuneCompleteCheck
// Inputs: none
// Outputs:
//     - uint8_t: returned boolean indicating seek/tune is complete.  0 = still processing, 1 = complete.
// Description: Because some amount of time is required for Tune or Seek to complete,
//		the host should call SeekTuneCompleteCheck() to verify completion
//************************************************************************************************************************
uint8_t SeekTuneCompleteCheck();

//************************************************************************************************************************
// Function: ForceMono_FM
// Inputs:
//     - audio_MonStereo:  	AUDIO_STEREO = 0, AUDIO_MONO = 1,
// Outputs:
//     - RETURN_CODE.
// Description: It is desirable during FM testing to force mono for some tests.  This is not necessary for normal operation.
//     Note: this is only applicable to "fmonly" mode.
//************************************************************************************************************************
RETURN_CODE ForceMono_FM(AUDIO_MONO_STEREO_SWITCH audio_MonStereo); //Added for testing device using SDK based platform

//************************************************************************************************************************



// DAB Functions
//************************************************************************************************************************
//************************************************************************************************************************

//************************************************************************************************************************
// Function: SetFrequencyList_DAB
// Inputs:
//     - numFrequencies - the number of frequencies in the new scan list
//     - frequencyListPtr - a pointer to the 32 bit frequency array for the new frequency list
// Outputs:
//     - RETURN_CODE
// Description: This function changes the list of frequencies used by the software when scanning and tuning by index.
//      NOTE: after changing this list, any existing service list information becomes invalid and must be regenerated (through ScanBand_DAB() or ManualTune_DAB())
//
//      NOTE: after changing the list, if saving the currently playing frequency when radio is turned off in order to start previous service upon power on (without rescan) becomes more complicated as well.
//			Power Down
//            1) extract the current ServiceId,ComponentId - GetCurrentServiceIdentification_DAB
//            2) extract the current frequencyIndex - from dabMetrics
//			  3) extract which list mode (full/reduced) is currently being used - from MMI code
//            4) store this information + power down
//			Power Up
//			  1) extract the stored variables
//            2) set the frequency list back reduced mode if previously in that mode (the chip will default to full mode)
//			  3) manually tune to the previous index - ManualTune_DAB
//            4) manually restart the original service - StartProcessingChannel (with the type as SERVICE_TYPE_DAB_AUDIO), and NULL for the bufferPtr)
//            5) to restore the full service list a rescan will be necessary - which will interrupt audio
//************************************************************************************************************************
RETURN_CODE SetFrequencyList_DAB(uint8_t numFrequencies, uint32_t* frequencyListPtr);

//************************************************************************************************************************
// Function: GetFrequencyList_DAB
// Inputs:
//     - bufferSize - the total size of the frequency buffer in bytes.  Necessary to prevent memory overflow.
// Outputs:
//     - numFrequencies - the number of frequencies in the new scan list
//     - frequencyListPtr - a pointer to the 32 bit frequency array for the new frequency list
//     - RETURN_CODE
// Description: This function reads back the current frequency list being used by the radio chip.  It will default to the full european list upon reset
//************************************************************************************************************************
RETURN_CODE GetFrequencyList_DAB(uint8_t bufferSize, uint8_t* numFrequencies, uint32_t* frequencyListPtr);

//************************************************************************************************************************
// Function: ScanBand_DAB
// Inputs: none
// Outputs:
//     - RETURN_CODE
// Description: This function intiates a scan of the European DAB band collecting service list information of available audio
//     programs.  After each valid ensemble's service list is collected, or invalid ensemble skipped, a callback
//     will hand over control to the MMI for UI update: CALLBACK_Updated_Data(DAB_TUNE_SCAN_PROCESS_UPDATE);
//     Once the scan is complete there is a final call to CALLBACK_Updated_Data(DAB_TUNE_SCAN_PROCESS_COMPLETE);
//************************************************************************************************************************
RETURN_CODE ScanBand_DAB();

//************************************************************************************************************************
// Function: ScanBandCancel_DAB
// Inputs: none
// Outputs: none
// Description: This function procides a way to cancel a DAB scan currently in progress.
//************************************************************************************************************************
void ScanBandCancel_DAB();

//************************************************************************************************************************
// Function: ManualTune_DAB
// Inputs:
//     - freqIndex - the frequency index desired to tune to - based upon those determined by SetFrequencyList_DAB()/GetFrequencyList_DAB()
// Outputs:
//     - RETURN_CODE - will give TIMEOUT indication if the frequency was unable to tune.
// Description: This function provides a way to manually set the ensemble to a user indicated preference, the service list will update
//************************************************************************************************************************
RETURN_CODE ManualTune_DAB(uint8_t freqIndex);

//************************************************************************************************************************
// Function: ReacquireCurrentService_DAB
// Inputs: none
// Outputs:
//     - RETURN_CODE - will give TIMEOUT/INVALID_INPUT indication if the attempt was unsuccessful.  Will give INVALID_MODE if currently ACQUIRED.
// Description: This function provides a way to run a check if the currently playing service needs to attempt to be restarted.
//       This can be called periodically with little overhead.
//************************************************************************************************************************
RETURN_CODE ReacquireCurrentService_DAB();

//************************************************************************************************************************
// Function: BrowseServicesReset_DAB
// Inputs: none
// Outputs: none
// Description: This function resets the browse index in the service list back to the current playing service.
//      For example:
//      a service list has 3 entries BBC1, BBC2, and BBC3 - the current playing service is BBC2.  If a user browses up one service
//      the UI would show information for BBC3.  If the user does not indicate to start the service after some time, the UI
//      would return to the "Now Playing" screen.  Without a callto BrowseServicesReset_DAB, on the next browse up,
//      the browsed service would be BBC1 instead of BBC3.
//************************************************************************************************************************
void BrowseServicesReset_DAB();

//************************************************************************************************************************
// Function: BrowseServicesChangeSelection_DAB
// Inputs:
//     - stepup: 0: step down, 1: step up.  Used to select the direction for the step in the service list.
// Outputs:
//     - service_name - a pointer to the string for the current browsed service (length = 16 characters)
//     - service_name_encoding - a variable created by caller to be changed to the encoding for the service_name string.
//			    EBU = 0, UCS2 = 6, UTF8 = 0x0F,
//     - service_pty - a variable created by the caller to be changed to the pty for the current browsed service
//     - RETURN_CODE
// Description: This function moves up/down the service list and provides UI information for enabling a user to select a service
//      Note: be sure to call BrowseServicesReset_DAB() after leaving the browse menu in order to start browsing at the current service
//************************************************************************************************************************
RETURN_CODE BrowseServicesChangeSelection_DAB(uint8_t stepup, uint8_t* service_name, uint8_t* service_name_encoding, uint8_t* service_pty);

//************************************************************************************************************************
// Function: BrowseServicesStartCurrentSelection_DAB
// Inputs: none
// Outputs:
//     - RETURN_CODE
// Description: While in a browsing mode, this function starts the current browsed service.
//      For example: the user has browsed up 2 times with calls to BrowseServicesChangeSelection_DAB(..) and has decided to
//          start that service - this function would then be called.
//************************************************************************************************************************
RETURN_CODE BrowseServicesStartCurrentSelection_DAB();


#ifdef OPTION__DAB_PRESETS_AS_FAVORITES
//************************************************************************************************************************
// Function: FavoritesSetCurrentService_DAB
// Inputs: none
// Outputs: none
// Description: This function sets the currently visible service as a favorite.
//************************************************************************************************************************
void FavoritesSetCurrentService_DAB();

//************************************************************************************************************************
// Function: FavoritesRemoveCurrentService_DAB
// Inputs: none
// Outputs: none
// Description: This function removed the currently visible service from the favorite list
//************************************************************************************************************************
void FavoritesRemoveCurrentService_DAB();

//************************************************************************************************************************
// Function: FavoritesBrowseOnly_DAB
// Inputs:
//     - enable = 0 = browse all services, 1 = browse only favorites.  toggle to enable favorites mode
// Outputs: none
// Description: This function enables or disables the favorites only service browse mode.
//************************************************************************************************************************
void FavoritesBrowseOnly_DAB(uint8_t enable);

//************************************************************************************************************************
// Function: FavoritesIsCurrentServiceAFavorite_DAB
// Inputs: none
// Outputs:
//     - uint8_t: 0 = not a favorite, 1 = favorite
// Description: This function provides easy access to the favorites status for a given service for updating the UI
//************************************************************************************************************************
uint8_t FavoritesIsCurrentServiceAFavorite_DAB();
#endif

//************************************************************************************************************************
// Function: GetCurrentServiceIdentification_DAB
// Inputs: none
// Outputs:
//     - serviceId = the current playing service's service id
//     - componentId = the current playing service's component id
// Description: This function returns the service id and component id of the currently playing audio service.  This is
//      necessary to manually restart the current service after power down using the - ManualTune_DAB and StartProcessingChannel apis
//************************************************************************************************************************
void GetCurrentServiceIdentification_DAB(uint32_t* serviceId, uint16_t* componentId);

//************************************************************************************************************************
// Function: StartLastServiceByIndex
// Inputs:
//      - serviceListIndex = the index obtained from the DAB Metrics for the previously played service's location in the service list
// Outputs: none
// Description: This function will attempt to start the previously played service.
//************************************************************************************************************************
RETURN_CODE StartLastServiceByIndex(uint8_t serviceListIndex);


#ifdef OPTION__DAB_SERVICE_LIST_PERSISTENCE
//************************************************************************************************************************
// Function: SaveServiceList_DAB
// Inputs: none
// Outputs: none
// Description: This function stores the current service list database into persistent storage for use when powering down the radio
//************************************************************************************************************************
RETURN_CODE SaveServiceList_DAB();

//************************************************************************************************************************
// Function: LoadServiceList_DAB
// Inputs: none
// Outputs:
//      - lastPlayedIndex = the service list index of the last played service, this is the correct input for calling StartLastServiceByIndex
//                to resume the previous service.
// Description: This function loads the saved service list database into RAM for use when powering up the radio
//************************************************************************************************************************
RETURN_CODE LoadServiceList_DAB(uint8_t* lastPlayedIndex);

//************************************************************************************************************************
// Function: EraseServiceList_DAB
// Inputs: none
// Outputs: none
// Description: This function clears the saved service list
//************************************************************************************************************************
void EraseServiceList_DAB();

#endif

//************************************************************************************************************************
// Function: GetCurrentServiceString_DAB
// Inputs: none
// Outputs:
//     - service_name - a pointer to the string for the current playing service (length = 16 characters)
//     - service_name_encoding - a variable created by caller to be changed to the encoding for the service_name string.
//			    EBU = 0, UCS2 = 6, UTF8 = 0x0F,
//     - service_pty - a variable created by the caller to be changed to the pty for the current playing service
//     - RETURN_CODE
// Description: This function provides service information for display about the current playing service.
//      For example: While in a "now playing" mode, this function would be called to populate the UI
//************************************************************************************************************************
RETURN_CODE GetCurrentServiceString_DAB(uint8_t* service_name, uint8_t* service_name_encoding, uint8_t* service_pty);

//************************************************************************************************************************
// Function: GetCurrentBrowseServiceString_DAB
// Inputs: none
// Outputs:
//     - service_name - a pointer to the string for the current playing service (length = 16 characters)
//     - service_name_encoding - a variable created by caller to be changed to the encoding for the service_name string.
//			    EBU = 0, UCS2 = 6, UTF8 = 0x0F,
//     - service_pty - a variable created by the caller to be changed to the pty for the current playing service
//     - RETURN_CODE
// Description: This function provides service information for display about the current selected service for browsing.
//      This is related to "BrowseServicesChangeSelection_DAB()" but enables a re-read of the information without adjusting the browse index
//************************************************************************************************************************
RETURN_CODE GetCurrentBrowseServiceString_DAB(uint8_t* service_name, uint8_t* service_name_encoding, uint8_t* service_pty);


#ifndef OPTION__REMOVE_SDK_FUNCTIONS_NOT_USED_BY_MMI
//************************************************************************************************************************
// Function: GetCurrentEnsembleNameString_DAB
// Inputs: none
// Outputs:
//     - ensemble_name - a pointer to the string for the currently tuned ensemble (length = 16 characters, encoding = EBU)
//     - RETURN_CODE
// Description: This function provides the string which describes the currently tuned ensemble.
//************************************************************************************************************************
RETURN_CODE GetCurrentEnsembleNameString_DAB(uint8_t* ensemble_name);
#endif //OPTION__REMOVE_SDK_FUNCTIONS_NOT_USED_BY_MMI

//************************************************************************************************************************
// Function: GetCurrentTime_DAB
// Inputs:
//     - region - the location desired for the current time (see DAB_TIME_REGION_TYPE)
// Outputs:
//     - time_data - the current time info from the tuned ensemble (see DAB_TIME for the struct format)
//     - RETURN_CODE
// Description: This function provides the current time for the tuned ensemble in local or UTC.
//************************************************************************************************************************
RETURN_CODE GetCurrentTime_DAB(DAB_TIME_REGION_TYPE region, dab_time* time_data);

// Common Functions
//************************************************************************************************************************
//************************************************************************************************************************

//************************************************************************************************************************
// Function: AudioLevel
// Inputs:
//     - level: the volume level of the audio output by the receiver.  Range = 0 -> 63
// Outputs:
//     - RETURN_CODE
// Description: This function provides control of the volume level of the audio output by the receiver.
//************************************************************************************************************************
RETURN_CODE AudioLevel(uint16_t level);

//************************************************************************************************************************
// Function: AudioMute
// Inputs:
//     - mute: the desired mute type:
//          	NOT_MUTED = 0, MUTE_LEFT_ONLY = 1, MUTE_RIGHT_ONLY = 2, MUTE_LEFT_RIGHT = 3,
// Outputs:
//     - RETURN_CODE
// Description: This function provides control of mute for the audio output by the receiver.
//************************************************************************************************************************
RETURN_CODE AudioMute(AUDIO_MUTE mute);

//************************************************************************************************************************
// Function: UpdateMetrics
// Inputs: none
// Outputs:
//     - RETURN_CODE
// Description: This function updates the receiver metrics for the current operating mode.  This function is intended to be
//      called periodically to provide up to date info for signal level indicators.
//
//      To get the metrics: call the listed function for the current mode to get a pointer to the metrics which were updated
//      - fm_metrics* MetricsGetFMPtr();
//      - fmhd_metrics* MetricsGetFMHDPtr();
//      - dab_metrics* MetricsGetDABPtr();
//      Note: you do not need to create a variable simply call the function and dereference the result:
//          example MetricsGetFMPtr()->FREQUENCY_10KHZ
//
// Be careful not to call this function too often as it will always read from the reciever to perform the update.
//************************************************************************************************************************
RETURN_CODE UpdateMetrics();

//************************************************************************************************************************
// Function: UpdateServiceList
// Inputs: none
// Outputs:
//     - RETURN_CODE
// Description: This function is called whenever the host expects a service list for the current freq/ensemble should be updated.
//************************************************************************************************************************
RETURN_CODE UpdateServiceList();

//************************************************************************************************************************
// Function: UpdateDataServiceData
// Inputs: none
// Outputs:
//     - RETURN_CODE
// Description: This function handles the necessary processes to update the Data services running.  It should be called periodically.
//      dab: updates DLS
//      fmhd: updates SIS and PSD, as well as RDS
//      fmonly: updates RDS
//
//      To access the data buffers - see the pointer functions in the Data Buffer Pointers section for the desired data type.
//			example: PSDGetTitlePtr, SISGetSloganPtr, DLSGetPtr, RDSGetRadioTextPtr, etc
//************************************************************************************************************************
RETURN_CODE UpdateDataServiceData();



// Special Functions
//************************************************************************************************************************
//************************************************************************************************************************
RETURN_CODE Get_part(uint16_t* chip_part);

// Advanced Functions
RETURN_CODE StartProcessingChannel(GENERAL_SERVICE_TYPE type, uint32_t service_id, uint32_t component_id, uint8_t *service_buffer);

#ifndef OPTION__REMOVE_SDK_FUNCTIONS_NOT_USED_BY_MMI
    RETURN_CODE StopProcessingChannel(uint32_t service_id, uint32_t component_id);
#endif

status_bits GetSi46XXStatus();


// The following Properties are excluded from SetProperty as there are other direct APIs do perform the desired action
//   - Set Property will return INVALID_INPUT if called for these properties
// **************************************************************
// FM_SEEK_BAND_BOTTOM
// FM_SEEK_BAND_TOP
// FM_SEEK_FREQUENCY_SPACING
// **************************************************************
RETURN_CODE SetProperty(uint16_t prop_id, uint16_t value);
RETURN_CODE GetProperty(uint16_t prop_id, uint16_t *value);


//************************************************************************************************************************
// Function: StartFirmwareUpdate
// Inputs: none
// Outputs:
//     - RETURN_CODE
// Description: This function puts the part into firmware update mode - listening on the USB for image download commands
//************************************************************************************************************************
RETURN_CODE StartFirmwareUpdate();


#ifdef OPTION__RADIODNS
//************************************************************************************************************************
// Function: UpdateRadioDNS_FMRDS
// Inputs:
//     - none
// Outputs:
//     - elements - all the elements needed to compose the radioDNS address string
//     - RETURN_CODE
// Description: This function calculates each of the pieces of the FM RDS RadioDNS string
//     Note: This does not support the country code form of the string as that information is not available from the broadcast alone
// String format: <frequency>.<pi>.<gcc>.fm.radiodns.org
//     - frequency: in 5 characters (leading 0 for frequencies below 100MHz)
//     - pi: in 4 characters
//     - gcc: in 3 characters
//************************************************************************************************************************
RETURN_CODE UpdateRadioDNS_FMRDS(radioDNS_fm* elements);

//************************************************************************************************************************
// Function: UpdateRadioDNS_DAB
// Inputs:
//     - none
// Outputs:
//     - elements - all the elements needed to compose the radioDNS address string
//     - RETURN_CODE
// Description: This function calculates each of the pieces of the DAB RadioDNS string
//     Note: This does not support the <apptype-uatype>.<pa>. variant
// String format: <scids>.<sid>.<eid>.<gcc>.dab.radiodns.org
//     - scids: in 1 character
//     - sid: in 4 characters (when the upper 16 bits are 0) or
//            in 8 characters (when the upper 16 bits are non-zero)
//     - eid: in 4 characters
//     - gcc: in 3 characters
//************************************************************************************************************************
RETURN_CODE UpdateRadioDNS_DAB(radioDNS_dab* elements);
#endif


#ifdef OPTION__INCLUDE_FRONT_END_TEST_FUNCTIONS
//************************************************************************************************************************
// Function: Test_DeterminePeakANTCAP_DAB
// Inputs:
//     - freqIndex - the DAB frequency to use for the test
// Outputs:
//     - antcapPeak - the antcap value determined to generate the best highres RSSI
// Description: This function performs a single run of the front end calibration process to collect the peak ANTCAP value
//************************************************************************************************************************
void Test_DeterminePeakANTCAP_DAB(uint8_t freqIndex, uint16_t* antcapPeak);
extern uint16_t _ANTCAP_DAB; // variable available globally for updating the user with the state of the process

//************************************************************************************************************************
// Function: Test_GetBER_DAB
// Inputs:
//     - berPattern - the 8 bit pattern for the test ETI.  example 0b11111111 or 0b00000000
// Outputs:
//     - errorBits - the number of error bits recieved from the (audio) test pattern ETI
//     - totalBits - the total number of bits recieved from the (audio) test pattern ETI
//     - passResult - the boolean (1 = pass, 0 = fail) for the BER calculation being less than 10e-4.
//     - RETURN_CODE
// Description: This function provides the current BER.  the BER test is expected to capture 1,000,000 samples
//************************************************************************************************************************
RETURN_CODE Test_GetBER_DAB(uint8_t berPattern, uint32_t* errorBits, uint32_t* totalBits, uint8_t* passResult);


//************************************************************************************************************************
// Function: Test_GetBER_FMHD
// Inputs: none, the BER test is expected to capture 1,000,000 samples per iBiquity
// Outputs:
//     - errorBits - the number of error bits recieved from IB_FMr208c_e1wfc204
//     - totalBits - the total number of bits recieved from IB_FMr208c_e1wfc204
//     - passResult - the boolean (1 = pass, 0 = fail) for the BER calculation being less than 5e-5.
//     - RETURN_CODE
// Description: This function provides the current BER
//************************************************************************************************************************
RETURN_CODE Test_GetBER_FMHD(uint32_t* errorBits, uint32_t* totalBits, uint8_t* passResult);

//************************************************************************************************************************
// Function: Test_StartFreeRunningBER_FMHD
// Inputs: none
// Outputs: none
// Description: This function enables and resets the BER counters, this is intended to be used before Test_GetFreeRunningBER_FMHD
//************************************************************************************************************************
RETURN_CODE Test_StartFreeRunningBER_FMHD();

//************************************************************************************************************************
// Function: Test_GetFreeRunningBER_FMHD
// Inputs:
//     - bitType: an enumeration for the HD BER type to check: see definition of FMHD_BER_TYPE
// Outputs:
//     - errorBits - the number of error bits recieved
//     - totalBits - the total number of bits recieved
// Description: This function provides the current BER
//************************************************************************************************************************
RETURN_CODE Test_GetFreeRunningBER_FMHD(uint8_t bitType, uint32_t* errorBits, uint32_t* totalBits);


#endif

// Data Buffer Pointers
//************************************************************************************************************************
//************************************************************************************************************************

//Metrics
fm_metrics* MetricsGetFMPtr();
fmhd_metrics* MetricsGetFMHDPtr();
dab_metrics* MetricsGetDABPtr();
am_metrics* MetricsGetAMPtr();
amhd_metrics* MetricsGetAMHDPtr();

//Service Lists
#ifdef OPTION__DECODE_FMHD_SERVICE_LIST
    fmhd_service_list_fast* FMHDServiceListFastPtr();
    fmhd_service_list* FMHDServiceListAudioPtr();
#endif

#ifdef OPTION__DECODE_DAB_SERVICE_LIST
    dab_service_list* DABServiceListAudioPtr();
#endif

// RDS
uint16_t RDSGetProgramIdentifier();
uint8_t  RDSGetProgramType();
#ifdef OPTION__RADIODNS
    uint8_t RDSGetECC();
#endif
#ifdef OPTION__RDS_BUFFER_V4L2
    //TODO: add V4L2
#else
    #ifndef OPTION__REMOVE_SDK_FUNCTIONS_NOT_USED_BY_MMI
        void ConfigureRDSOptions(uint8_t ignore_AB_flag);
    #endif //OPTION__REMOVE_SDK_FUNCTIONS_NOT_USED_BY_MMI

    uint8_t* RDSGetRadioTextPtr();   // Displayed Radio Text (64 bytes)
    uint8_t* RDSGetProgramServiceTextPtr();    // Displayed Program Service text (8 bytes)
    rds_time RDSGetCurrentTime();
#endif
//TODO: add BLER interface if desired
//TODO: add AF APIs


#ifdef OPTION__DECODE_SIS
    fmhd_sis_slogan* SISGetSloganPtr();
    fmhd_sis_universal_short_name* SISGetUSNPtr();
    fmhd_sis_station_message* SISGetSMPtr();
    uint8_t* SISGetSNLPtr();
    uint8_t* SISGetSNSPtr();
    uint8_t* SISGetStationIDPtr();
    uint8_t* SISGetStationLocLatPtr();
    uint8_t* SISGetStationLocLongPtr();
#endif

#ifdef OPTION__DECODE_PSD
    fmhd_psd_generic_string* PSDGetTitlePtr();
    fmhd_psd_generic_string* PSDGetArtistPtr();
    fmhd_psd_generic_string* PSDGetAlbumPtr();

    // On Genre: Need to check for (x) format amd flag
    // C-SDK layer will not process those as the memory footprint is too large to carry the lookup table
    fmhd_psd_generic_string* PSDGetGenrePtr();
#endif

#ifdef OPTION__DECODE_HD_ALERTS
    fmhd_alert_string* HDAlertGetPtr();
#endif

#ifdef OPTION__DECODE_DLS
    dab_dls_string* DLSGetPtr();
#endif



#endif