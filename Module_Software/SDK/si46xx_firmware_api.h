/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   firmware api header for si468x command/property interface
   FILE: si46xx_firmware_api.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#ifndef _si46xx_firmware_api_h_
#define _si46xx_firmware_api_h_

#include "si46xx_firmware_api_status.h"
#include "common_types.h"
#include "platform_options.h"

#define SI46XX_FIRMWARE_API_REVISION 130524

#define DIGITAL_SERVICE_DATA_MAX_LENGTH__4BYTE (((CMD_GET_DIGITAL_SERVICE_DATA_REP_LENGTH / 4) + 1) * 4)

#define CMD_BUFFER_LENGTH 256	// 256 byte command buffer - this must be evenly divisible by 4

#ifdef OPTION__FULL_SIZE_SPI_BUFFER
	#define RPY_BUFFER_LENGTH (8192 + DIGITAL_SERVICE_DATA_MAX_LENGTH__4BYTE)	//8k DAB max payload + Digital Service Data Header - (this must be evenly divisible by 4)
#endif
#ifdef OPTION__SMALL_SPI_BUFFER
	#define RPY_BUFFER_LENGTH (512 + DIGITAL_SERVICE_DATA_MAX_LENGTH__4BYTE)
#endif

#ifdef OPTION__CONVERT_BIG_ENDIAN
void _swap_16 (uint16_t *pValue);
void _swap_32 (uint32_t *pValue);
#endif

//Necessary helper functions for converting stream data into non-8bit types
uint32_t _recover_32bit_from_big_endian_buffer(uint8_t* buffer);
uint16_t _recover_16bit_from_big_endian_buffer(uint8_t* buffer);
uint32_t _recover_32bit_from_little_endian_buffer(uint8_t* buffer);
uint16_t _recover_16bit_from_little_endian_buffer(uint8_t* buffer);

#define SHARED_FUNCTION_MODE_FM 0
#define SHARED_FUNCTION_MODE_AM 1


//Begin Firmware API
RETURN_CODE read_status(status_bits* status);

RETURN_CODE power_up__command(uint8_t ctsien, uint8_t clk_mode, uint8_t tr_size, uint8_t ibias, uint32_t xtal_freq, uint8_t ctun, uint8_t ibias_run, uint8_t usingROM00);
RETURN_CODE host_load__command(uint16_t segmentLength, uint8_t *imageSegment);
RETURN_CODE flash_load__command(uint32_t start_addr);
RETURN_CODE load_init__command();
RETURN_CODE boot__command();

RETURN_CODE read_offset__command(uint16_t offset);
RETURN_CODE read_storage__command(uint16_t offset);
RETURN_CODE read_storage__reply(uint16_t length, uint8_t* replyDataPtr);


RETURN_CODE get_part_info__command(void);
typedef struct _get_part_info__data
{
	uint8_t CHIPREV;
	uint8_t ROMID;
	uint16_t PART;
}get_part_info__data;
RETURN_CODE get_part_info__reply(get_part_info__data* replyData);



RETURN_CODE get_sys_state__command(void);
typedef struct _get_sys_state__data
{
	uint8_t image;
}get_sys_state__data;
RETURN_CODE get_sys_state__reply(get_sys_state__data* replyData);


#ifndef OPTION__REMOVE_FIRMWARE_FUNCTIONS_NOT_USED_SMALL_SDK
RETURN_CODE get_power_up_args__command(void);
typedef struct _get_power_up_args__data
{
	uint8_t CLK_MODE;
	uint8_t TR_SIZE;
	uint8_t IBIAS;
	uint32_t XTAL_FREQ;
	uint8_t CTUN;
	uint8_t IBIAS_RUN;
}get_power_up_args__data;
RETURN_CODE get_power_up_args__reply(get_power_up_args__data* replyData);
#endif


#ifndef OPTION__REMOVE_FIRMWARE_FUNCTIONS_NOT_USED_SMALL_SDK
RETURN_CODE get_func_info__command(void);
typedef struct _get_func_info__data
{
	uint8_t REVEXT;
	uint8_t REVBRANCH;
	uint8_t REVINT;
	uint8_t NOSVN;
	uint8_t LOCATION;
	uint8_t MIXEDREV;
	uint8_t LOCALMOD;
	uint32_t SVNID;
}get_func_info__data;
RETURN_CODE get_func_info__reply(get_func_info__data* replyData);
#endif


RETURN_CODE set_property__command(uint16_t propid, uint16_t value);

//For simplicity, only one property is read at a time - though block reading is supported if desired
RETURN_CODE get_property__command(uint16_t propid);
RETURN_CODE get_property__reply(uint16_t* value);


RETURN_CODE write_storage__command(uint16_t offset, uint16_t length, uint8_t* buffer);



RETURN_CODE get_digital_service_list__command(uint8_t sertype);
typedef struct _get_digital_service_list__data
{
	uint16_t TOTAL_SIZE;
    uint16_t READ_SIZE;
    uint16_t PROCESSED_ADDR; //Needed when reading in segments
	uint8_t* PAYLOAD;
}get_digital_service_list__data;
RETURN_CODE get_digital_service_list__reply(uint16_t read_offset_index, get_digital_service_list__data* replyData);
RETURN_CODE realign_service_list_buffer(uint16_t *payloadAddr, get_digital_service_list__data *fmhdList, uint16_t nextItemLength);


RETURN_CODE start_digital_service__command(uint8_t sertype, uint32_t service_id, uint32_t comp_id);

#ifndef OPTION__REMOVE_SDK_FUNCTIONS_NOT_USED_BY_MMI
RETURN_CODE stop_digital_service__command(uint8_t sertype, uint32_t service_id, uint32_t comp_id);
#endif


RETURN_CODE get_digital_service_data__command(uint8_t status_only, uint8_t ack);
typedef struct _get_digital_service_data__data
{
    #ifndef OPTION__MINIMAL_FIRMWARE_FUNCTION_IMPLEMENTATION_SMALLER_SDK
	    uint8_t DSRVOVFLINT;
    	uint8_t DSRVPCKTINT;
        //uint8_t DATA_TYPE;
        uint8_t DSCTY;
    #endif
	uint8_t BUFF_COUNT;
	uint8_t SRV_STATE;
    uint8_t DATA_SRC;

	uint32_t SERVICE_ID;
	uint32_t COMPONENT_ID;
	uint16_t UATYPE;
	uint16_t BYTE_COUNT;
	uint16_t SEG_NUM;
	uint16_t NUM_SEGS;
	uint8_t* PAYLOAD;
}get_digital_service_data__data;
RETURN_CODE get_digital_service_data__reply(get_digital_service_data__data* replyData);

#ifdef OPTION__INCLUDE_FRONT_END_TEST_FUNCTIONS
    RETURN_CODE test_get_rssi__command(void);
    RETURN_CODE test_get_rssi__reply(int16_t* highresRssi);
#endif
// **************************************************************************
// Begin FMRX/FMHD commands
// **************************************************************************
#ifdef OPTION__INCLUDE_MODE__FM
RETURN_CODE fm_am_tune_freq__command(uint8_t shared_function_mode, uint8_t dir_tune, uint8_t tunemode, uint8_t injection, uint16_t freq, uint16_t antcap, uint8_t prog_id);


RETURN_CODE fm_am_seek_start__command(uint8_t shared_function_mode, uint8_t force_wb, uint8_t tunemode, uint8_t injection, uint8_t seekup, uint8_t wrap, uint16_t antcap);


RETURN_CODE fm_rsq_status__command(uint8_t rsqack, uint8_t attune, uint8_t cancel, uint8_t stcack);
typedef struct _fm_rsq_status__data
{
    int8_t RSSI;
	uint8_t SNR; 
	uint8_t MULT;
    uint8_t VALID;
	uint16_t READFREQ;
    #ifdef OPTION__INCLUDE_MODE__FMHD
        uint8_t HDLEVEL;
    #endif
    #ifndef OPTION__MINIMAL_FIRMWARE_FUNCTION_IMPLEMENTATION_SMALLER_SDK
	    uint8_t SNRHINT;
	    uint8_t SNRLINT;
	    uint8_t RSSIHINT;
	    uint8_t RSSILINT;
	    uint8_t BLTF;
	    uint8_t FREQOFF; 
	    uint8_t AFCRL;
        uint16_t READANTCAP;
   #endif
}fm_rsq_status__data;

RETURN_CODE fm_rsq_status__reply(fm_rsq_status__data* replyData);

#ifdef OPTION__INCLUDE_MODE__AM
typedef struct _am_rsq_status__data
{
    int8_t RSSI;
	uint8_t SNR; 
	uint8_t MOD;
    uint8_t VALID;
	uint16_t READFREQ;
    #ifdef OPTION__INCLUDE_MODE__AMHD
        uint8_t HDLEVEL;
    #endif
    #ifndef OPTION__MINIMAL_FIRMWARE_FUNCTION_IMPLEMENTATION_SMALLER_SDK
	    uint8_t SNRHINT;
	    uint8_t SNRLINT;
	    uint8_t RSSIHINT;
	    uint8_t RSSILINT;
	    uint8_t BLTF;
	    uint8_t HDDETECTED;
	    uint8_t FLT_HDDETECTED;
	    uint8_t FREQOFF; 
	    uint8_t AFCRL;
        uint16_t READANTCAP;
	uint8_t FILTERED_HDLEVEL;
   #endif
}am_rsq_status__data;


RETURN_CODE am_rsq_status__reply(am_rsq_status__data* replyData);
RETURN_CODE am_rsq_status__command(uint8_t rsqack, uint8_t attune, uint8_t cancel, uint8_t stcack);
#endif

#ifndef OPTION__REMOVE_FIRMWARE_FUNCTIONS_NOT_USED_SMALL_SDK
RETURN_CODE fm_acf_status__command(uint8_t acfack);
typedef struct _fm_acf_status__data
{
	uint8_t BLEND_INT;
	uint8_t HIGHCUT_INT;
	uint8_t SMUTE_INT;
	uint8_t BLEND_CONV;
	uint8_t HIGHCUT_CONV;
	uint8_t SMUTE_CONV;
	uint8_t BLEND_STATE;
	uint8_t HIGHCUT_STATE;
	uint8_t SMUTE_STATE;
	uint8_t ATTN;
	uint8_t HIGHCUT;
	uint8_t PILOT;
	uint8_t STBLEND;
}fm_acf_status__data;
RETURN_CODE fm_acf_status__reply(fm_acf_status__data* replyData);
#endif


RETURN_CODE fm_rds_status__command(uint8_t statusonly, uint8_t mtfifo, uint8_t intack);
typedef struct _fm_rds_status__data
{
    uint8_t TP;
	uint8_t PTY;
	uint16_t PI;
	uint8_t BLEA;
	uint8_t BLEB;
	uint8_t BLEC;
	uint8_t BLED;
	uint16_t BLOCKA;
	uint16_t BLOCKB;
	uint16_t BLOCKC;
	uint16_t BLOCKD;
    uint8_t TPPTYVALID;
	uint8_t PIVALID;
    uint8_t RDSFIFOUSED;

#ifndef OPTION__MINIMAL_FIRMWARE_FUNCTION_IMPLEMENTATION_SMALLER_SDK
	uint8_t RDSTPPTYINT;
	uint8_t RDSPIINT;
	uint8_t RDSSYNCINT;
	uint8_t RDSFIFOINT;
	uint8_t RDSSYNC;
	uint8_t RDSFIFOLOST;
#endif
}fm_rds_status__data;
RETURN_CODE fm_rds_status__reply(fm_rds_status__data* replyData);


#ifndef OPTION__REMOVE_FIRMWARE_FUNCTIONS_NOT_USED_SMALL_SDK
RETURN_CODE fm_rds_blockcount__command(uint8_t clear);
typedef struct _fm_rds_blockcount__data
{
	uint16_t EXPECTED;
	uint16_t RECEIVED;
	uint16_t UNCORRECTABLE;
}fm_rds_blockcount__data;
RETURN_CODE fm_rds_blockcount__reply(fm_rds_blockcount__data* replyData);
#endif

#endif //OPTION__INCLUDE_MODE__FM

#if (defined OPTION__INCLUDE_MODE__FMHD)||(defined OPTION__INCLUDE_MODE__AMHD)
RETURN_CODE hd_digrad_status__command(uint8_t ack);
typedef struct _hd_digrad_status__data
{
    uint8_t SRCANA;
	uint8_t SRCDIG;
    uint8_t HDLOGO;
	uint8_t ACQ;
    uint8_t DAAI;
	uint8_t CDNR;
    uint8_t AUDIO_PROG_AVAIL;
	uint8_t AUDIO_PROG_PLAYING;

#ifndef OPTION__MINIMAL_FIRMWARE_FUNCTION_IMPLEMENTATION_SMALLER_SDK
	uint8_t SRCANAINT;
	uint8_t SRCDIGINT;
	uint8_t AUDACQINT;
    uint8_t HDLOGOINT;
	uint8_t ACQINT;
	uint8_t AUDACQ;
	uint8_t CDNRHINT;
	uint8_t CDNRLINT;
	uint8_t CDNRH;
	uint8_t CDNRL;
	uint8_t BCTL;
	uint8_t TX_GAIN;
	uint8_t AUDIO_CA;
	uint32_t CORE_AUDIO_ERR;
	uint32_t ENH_AUDIO_ERR;
	uint8_t PTY;
    uint8_t PS_MODE;
    uint8_t CODEC_MODE;
#endif
}hd_digrad_status__data;
RETURN_CODE hd_digrad_status__reply(hd_digrad_status__data* replyData);


RETURN_CODE hd_get_event_status__command(uint8_t ack);
typedef struct _hd_get_event_status__data
{
    uint8_t ALERTINT;
	uint8_t PSDINT;
	uint8_t SISINT;
	uint8_t DSRVLISTINT;
	uint8_t ASRVLISTINT;
	uint8_t PSD;
	uint8_t SIS;
	uint8_t DSRVLIST;
	uint8_t ASRVLIST;
	uint16_t ASRVLISTVER;
	uint16_t DSRVLISTVER;

    uint8_t GENRE;
	uint8_t ALBUM;
	uint8_t ARTIST;
	uint8_t TITLE;
#ifdef UPDATED_SIS_PSD_NOTIFICATIONS
	uint8_t SIS_LOCATION;
	uint8_t SIS_LONG_NAME;
	uint8_t SIS_SHORT_NAME;
	uint8_t SIS_ID;
	uint8_t SIS_SLOGAN;
	uint8_t SIS_BASIC_SIS;
	uint8_t SIS_UNIV_SHORT_NAME;
	uint8_t SIS_LEAP_SEC;
	uint8_t SIS_TIMEZONE;
	uint8_t SIS_MESSAGE;

	uint8_t TEXT;
	uint8_t SHORT;
	uint8_t LANG;
	uint8_t ID;
	uint8_t OWNER;
	uint8_t DESC;
	uint8_t NAME;
	uint8_t RECV;
	uint8_t URL;
	uint8_t VALID;
	uint8_t PRICE;
#endif
}hd_get_event_status__data;
RETURN_CODE hd_get_event_status__reply(hd_get_event_status__data* replyData);


RETURN_CODE fmhd_get_station_info__command(uint8_t info_select);
typedef struct _fmhd_get_station_info__data
{
	uint16_t LENGTH;
    uint8_t INFO_SELECT;
	uint8_t* PAYLOAD;
}fmhd_get_station_info__data;
RETURN_CODE fmhd_get_station_info__reply(fmhd_get_station_info__data* replyData);

RETURN_CODE fmhd_get_psd_decode__command(uint8_t program, uint8_t field);
typedef struct _fmhd_get_psd_decode__data
{
	uint8_t DATATYPE;
	uint8_t LENGTH;
	uint8_t* PAYLOAD;
}fmhd_get_psd_decode__data;
RETURN_CODE fmhd_get_psd_decode__reply(fmhd_get_psd_decode__data* replyData);


RETURN_CODE fmhd_get_alert_message__command();
typedef struct _fmhd_get_alert_message__data
{
	uint16_t LENGTH;
	uint8_t* PAYLOAD;
}fmhd_get_alert_message__data;
RETURN_CODE fmhd_get_alert_message__reply(fmhd_get_alert_message__data* replyData);


RETURN_CODE fmhd_play_alert_tone__command();


#ifdef OPTION__INCLUDE_FRONT_END_TEST_FUNCTIONS
RETURN_CODE fmhd_test_get_ber_info__command(void);
typedef struct _fmhd_test_get_ber_info__data
{
	uint32_t P1_BIT_ERRORS;
	uint32_t P1_BITS_TESTED;
    uint32_t P2_BIT_ERRORS;
	uint32_t P2_BITS_TESTED;
    uint32_t P3_BIT_ERRORS;
	uint32_t P3_BITS_TESTED;
    uint32_t PIDS_BIT_ERRORS;
	uint32_t PIDS_BITS_TESTED;
    uint32_t PIDS_BLOCK_ERRORS;
	uint32_t PIDS_BLOCKS_TESTED;
}fmhd_test_get_ber_info__data;
RETURN_CODE fmhd_test_get_ber_info__reply(fmhd_test_get_ber_info__data* replyData);
#endif


#ifndef OPTION__REMOVE_FIRMWARE_FUNCTIONS_NOT_USED_SMALL_SDK
RETURN_CODE fmhd_set_enabled_ports__command(uint8_t length, uint16_t* portAddresses);
#endif


#ifndef OPTION__REMOVE_FIRMWARE_FUNCTIONS_NOT_USED_SMALL_SDK
RETURN_CODE fmhd_get_enabled_ports__command(void);
typedef struct _fmhd_get_enabled_ports__data
{
	uint8_t LENGTH;
	uint16_t* PAYLOAD;
}fmhd_get_enabled_ports__data;
RETURN_CODE fmhd_get_enabled_ports__reply(fmhd_get_enabled_ports__data* replyData); 
#endif

#endif //OPTION__INCLUDE_MODE__FMHD

// **************************************************************************
// Begin DAB/DMB commands
// **************************************************************************
#ifdef OPTION__INCLUDE_MODE__DAB
RETURN_CODE dab_tune_freq__command(uint8_t injection, uint8_t freq_index, uint16_t antcap);


RETURN_CODE dab_digrad_status__command(uint8_t ack, uint8_t attune, uint8_t fiberr_ack, uint8_t stc_ack);
typedef struct _dab_digrad_status__data
{
	uint8_t ACQINT;
	uint8_t ACQ;
	uint8_t VALID;
	int8_t RSSI;
	uint8_t SNR;
	uint8_t FIC_QUALITY;
	uint8_t CNR;
    uint8_t TUNE_INDEX;

    #ifdef OPTION__ADVANCED_METRICS
        int8_t FFT_OFFSET;
    #endif

#ifndef OPTION__MINIMAL_FIRMWARE_FUNCTION_IMPLEMENTATION_SMALLER_SDK
    uint8_t FICERRINT;
    uint8_t FICERR;
    uint8_t RSSIHINT;
    uint8_t RSSILINT;
    uint16_t FIB_ERROR_COUNT;
	uint32_t TUNE_FREQ;
    uint16_t READANTCAP;
    uint16_t CU_LEVEL;
    uint8_t FAST_DECT;
#endif
}dab_digrad_status__data;
RETURN_CODE dab_digrad_status__reply(dab_digrad_status__data* replyData);


RETURN_CODE dab_get_event_status__command(uint8_t ack);
typedef struct _dab_get_event_status__data
{
	uint8_t RECFGINT;
	uint8_t RECFGWRNINT;
	uint8_t ANNOINT;
    uint8_t ANNO;
    uint8_t OESERVINT;
    uint8_t OESERV;
    uint8_t SERVLINKINT;
    uint8_t SERVLINK;
    uint8_t FREQINFOINT;
    uint8_t FREQINFO;
	uint8_t SVRLISTINT;
	uint8_t SVRLIST;
	uint16_t SVRLISTVER;
}dab_get_event_status__data;
RETURN_CODE dab_get_event_status__reply(dab_get_event_status__data* replyData);


RETURN_CODE dab_get_ensemble_info__command(void);
typedef struct _dab_get_ensemble_info__data
{
	uint16_t EID;
	uint8_t LABEL_LENGTH;
	uint8_t* LABEL;
    

    #ifdef OPTION__RADIODNS
        uint8_t ENSEMBLE_ECC;
    #endif
    
    uint8_t CHARSET;

    #ifndef OPTION__MINIMAL_FIRMWARE_FUNCTION_IMPLEMENTATION_SMALLER_SDK
        uint16_t CHAR_ABREV;
    #endif

}dab_get_ensemble_info__data;
RETURN_CODE dab_get_ensemble_info__reply(dab_get_ensemble_info__data* replyData);


#ifdef OPTION__DECODE_DAB_ANNOUNCEMENTS
//#ifndef OPTION__REMOVE_FIRMWARE_FUNCTIONS_NOT_USED_SMALL_SDK
RETURN_CODE dab_get_announcement_support_info__command(uint8_t src, uint32_t sid);
typedef struct _dab_get_announcement_support_info__data
{
	uint8_t NUM_IDS;
	uint16_t ASU;
	uint16_t* ID;
}dab_get_announcement_support_info__data;
RETURN_CODE dab_get_announcement_support_info__reply(dab_get_announcement_support_info__data* replyData);
//#endif //OPTION__REMOVE_FIRMWARE_FUNCTIONS_NOT_USED_SMALL_SDK

RETURN_CODE dab_get_announcement_info__command(void);
typedef struct _dab_get_announcement_info__data
{
	uint8_t ANNO_Q_OVFL;
	uint8_t ANNO_Q_SIZE;
	uint8_t CLUSTER_ID;
    uint8_t SRC;
    uint8_t REGION_FLAG;
    uint8_t ANNO_STAT;
    uint16_t ASW;
    uint16_t ID1;
    uint16_t ID2;
    uint8_t REGIONID1;
    uint8_t REGIONID2;
}dab_get_announcement_info__data;
RETURN_CODE dab_get_announcement_info__reply(dab_get_announcement_info__data* replyData);
#endif //OPTION__DECODE_DAB_ANNOUNCEMENTS

RETURN_CODE dab_set_freq_list__command(uint8_t num_freqs, uint32_t* freq);


RETURN_CODE dab_get_freq_list__command(void);
typedef struct _dab_get_freq_list__data
{
	uint8_t NUM_FREQS;
	uint32_t* FREQ;
}dab_get_freq_list__data;
RETURN_CODE dab_get_freq_list__reply(dab_get_freq_list__data* replyData);


RETURN_CODE dab_get_component_info__command(uint32_t serviceid, uint32_t compid);
typedef struct _dab_get_component_info__data
{
    uint8_t CHARSETID;
	uint8_t LABEL_LENGTH;
	uint8_t* LABEL;

    #ifdef OPTION__RADIODNS
        uint8_t GLOBAL_ID;
    #endif

#ifndef OPTION__MINIMAL_FIRMWARE_FUNCTION_IMPLEMENTATION_SMALLER_SDK
	uint8_t LANG;
	uint16_t CHAR_ABREV;
	uint8_t NUMUA;
	uint16_t UATYPE;
	uint8_t UADATALEN;
	uint8_t* UADATA;
#endif
}dab_get_component_info__data;
RETURN_CODE dab_get_component_info__reply(dab_get_component_info__data* replyData);


RETURN_CODE dab_get_time__command(uint8_t time_type);
typedef struct _dab_get_time__data
{
	uint16_t YEAR;
	uint8_t MONTHS;
	uint8_t DAYS;
	uint8_t HOURS;
	uint8_t MINUTES;
	uint8_t SECONDS;
}dab_get_time__data;
RETURN_CODE dab_get_time__reply(dab_get_time__data* replyData);

RETURN_CODE dab_get_audio_info__command(void);
typedef struct _dab_get_audio_info__data
{
	uint16_t AUDIO_BIT_RATE;
	uint16_t AUDIO_SAMPLE_RATE;
    uint8_t AUDIO_MODE;

#ifndef OPTION__MINIMAL_FIRMWARE_FUNCTION_IMPLEMENTATION_SMALLER_SDK
    uint8_t AUDIO_PS_FLAG;
	uint8_t AUDIO_SBR_FLAG;
    uint8_t AUDIO_DRC_GAIN;
#endif
}dab_get_audio_info__data;
RETURN_CODE dab_get_audio_info__reply(dab_get_audio_info__data* replyData);


#ifdef OPTION__DAB_SUPPORT_DAB_DAB_LINKING

#ifndef OPTION__COMMAND_INPUT_MINIMAL_OPTIONS_SMALLER_SDK
    RETURN_CODE dab_get_service_linking_info__command(uint8_t active, uint8_t activeen,
                                                  uint8_t linktype, uint8_t linktypeen,
                                                  uint8_t hard, uint8_t harden,
                                                  uint8_t ils, uint8_t ilsen,
                                                  uint32_t serviceid);
#else
    RETURN_CODE dab_get_service_linking_info__command(uint32_t serviceid, uint8_t arg1, uint8_t arg2);
#endif

//simplified format - LINKINFO elements listed as independent variables
typedef struct _dab_link_set
{
    #ifndef OPTION__MINIMAL_FIRMWARE_FUNCTION_IMPLEMENTATION_SMALLER_SDK
        uint16_t LSN;
        uint8_t ACTIVE;
        uint8_t SHD;
        uint8_t LINKTYPE;
        uint8_t HARD;
        uint8_t ILS;
    #endif
    uint8_t NUMLINKS;
    uint32_t* LINKID;
}dab_linking_set;

//format as provided in API
typedef struct _dab_get_service_linking_info_set__data
{
    uint16_t LSN;
    uint8_t LINKINFO;
    uint8_t NUMLINKS;
    uint32_t* LINKID;
}dab_get_service_linking_info_set__data;
typedef struct _dab_get_service_linking_info__data
{
    uint16_t SIZE;
    uint8_t NUM_LINKSETS;
    uint8_t* PAYLOAD;
}dab_get_service_linking_info__data;
RETURN_CODE dab_get_service_linking_info__reply(dab_get_service_linking_info__data* replyData);
RETURN_CODE dab_get_service_linking_info__get_element(uint8_t linkset_index, dab_get_service_linking_info__data* replyData, dab_linking_set* linkSetPtr);


RETURN_CODE dab_get_freq_info__command(void);
typedef struct _dab_fi_element
{
    uint32_t ID;
    uint32_t FREQ;
    uint8_t FREQ_INDEX;
    uint8_t RNM;
    uint8_t CONTINUITY;
    uint8_t CONTROL;
}dab_fi_element;
typedef struct _dab_get_freq_info__data
{
    uint32_t NUM_ELEMENTS;
    dab_fi_element* PAYLOAD;
}dab_get_freq_info__data;
RETURN_CODE dab_get_freq_info__reply(dab_get_freq_info__data* replyData);


RETURN_CODE dab_get_oe_services_info__command(uint32_t service_id);
typedef struct _dab_get_oe_services_info__data
{
    uint16_t SIZE;
    uint8_t NUM_EIDS;
    uint16_t* EIDS;
}dab_get_oe_services_info__data;
RETURN_CODE dab_get_oe_services_info__reply(dab_get_oe_services_info__data* replyData);

#endif //OPTION__DAB_SUPPORT_DAB_DAB_LINKING

#ifdef OPTION__RADIODNS
RETURN_CODE dab_get_service_info__command(uint32_t service_id);
typedef struct _dab_get_service_info__data
{
    uint8_t SRV_ECC;

#ifndef OPTION__MINIMAL_FIRMWARE_FUNCTION_IMPLEMENTATION_SMALLER_SDK
    uint8_t SRV_LINKING_INFO;
    uint8_t PTY;
    uint8_t PD_FLAG;
    uint8_t LOCAL;
    uint8_t CAID;
    uint8_t NUM_COMP;
    uint8_t SICHARSET;

    uint8_t LABEL_LENGTH;
	uint8_t* LABEL;
    uint16_t CHAR_ABREV;
#endif
}dab_get_service_info__data;
RETURN_CODE dab_get_service_info__reply(dab_get_service_info__data* replyData);
#endif //OPTION__RADIODNS

#ifndef OPTION__MINIMAL_FIRMWARE_FUNCTION_IMPLEMENTATION_SMALLER_SDK
RETURN_CODE dab_acf_status__command(void);
typedef struct _dab_acf_status__data
{
    uint32_t AUDIO_LEVEL;
    uint32_t CMFT_NOISE_LEVEL;
}dab_acf_status__data;
RETURN_CODE dab_acf_status__reply(dab_acf_status__data* replyData);
#endif

#ifdef OPTION__INCLUDE_FRONT_END_TEST_FUNCTIONS
    RETURN_CODE dab_test_ber_info__command(void);
    typedef struct _dab_test_ber_info__data
    {
	    uint32_t ERR_BITS;
	    uint32_t TOTAL_BITS;
    }dab_test_ber_info__data;
    RETURN_CODE dab_test_ber_info__reply(dab_test_ber_info__data* replyData);
#endif

#endif //OPTION__INCLUDE_MODE__DAB

#endif //_si46xx_firmware_api_h_
