/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   SDK: common definition for various radio protocol features
   FILE: feature_types.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#ifndef _FEATURE_TYPES_
#define _FEATURE_TYPES_

#include "common_types.h"

//******************************************************************
// Metrics for each mode
//******************************************************************
typedef struct _fm_metrics
{
    uint16_t FREQUENCY_10KHZ;
    int8_t RSSI;
    int8_t SNR;
    uint8_t MULTIPATH;
    uint8_t VALID;
}fm_metrics;

typedef struct _am_metrics
{
    uint16_t FREQUENCY_1KHZ;
    int8_t RSSI;
    int8_t SNR;
    uint8_t MODULATION_INDEX;
    uint8_t VALID;
}am_metrics;

typedef struct _fmhd_metrics
{
    uint16_t FREQUENCY_10KHZ;
    int8_t RSSI;
    int8_t SNR;
    uint8_t MULTIPATH;
    uint8_t VALID;
    uint8_t HDLEVEL;
    uint8_t ACQ;
    uint8_t DAAI;
    uint8_t CDNR;
    uint8_t AUDIO_SOURCE;   // 0=analog, 1=digital, 0xFF=none
    uint8_t HDLOGO;         // 0=remove logo, 1=display logo
    uint8_t CURRENT_AUDIO_SERVICE;  // Current Playing Audio Service
    uint8_t CURRENT_AUDIO_SERVICE__LIST_INDEX;  //The Service List Index for the Current Service - 0xFF if service list incomplete
}fmhd_metrics;

typedef struct _amhd_metrics
{
    uint16_t FREQUENCY_1KHZ;
    int8_t RSSI;
    int8_t SNR;
    uint8_t MODULATION_INDEX;
    uint8_t VALID;
    uint8_t HDLEVEL;
    uint8_t ACQ;
    uint8_t DAAI;
    uint8_t CDNR;
    uint8_t AUDIO_SOURCE;   // 0=analog, 1=digital, 0xFF=none
    uint8_t HDLOGO;         // 0=remove logo, 1=display logo
    uint8_t CURRENT_AUDIO_SERVICE;  // Current Playing Audio Service
    uint8_t CURRENT_AUDIO_SERVICE__LIST_INDEX;  //The Service List Index for the Current Service - 0xFF if service list incomplete
}amhd_metrics;




#define DAB_METRIC_AUDIO_SERVICE_LIST__INDEX_NOT_SET 0xFF
#define DAB_METRIC_EID__NOT_SET 0xFFFF
typedef struct _dab_metrics
{
    uint8_t FREQUENCY_INDEX; // not set = 0xFF````
    int8_t RSSI;
    int8_t SNR;
    uint8_t VALID;
    uint8_t ACQ;
    uint8_t FIC_QUALITY;
    uint8_t CNR;
    uint16_t EID;
    uint8_t CURRENT_AUDIO_SERVICE_LIST__SERVICE_INDEX; // none selected = 0xFF
    uint16_t CURRENT_AUDIO_INFO__BIT_RATE; // in kbps, none selected = 0
    uint8_t CURRENT_AUDIO_INFO__MODE; //DAB_AUDIO_INFO_TYPE, none selected = 0xFF

    #ifdef OPTION__ADVANCED_METRICS
        int8_t FFT_OFFSET;
    #endif
}dab_metrics;

typedef struct _radioDNS_fm
{
    uint16_t FREQUENCY_10KHZ;
    uint16_t PI;
    uint16_t GCC;
}radioDNS_fm;

typedef struct _radioDNS_dab
{
    uint8_t SCIDS;
    uint32_t SID;
    uint16_t EID;
    uint16_t GCC;
}radioDNS_dab;

//******************************************************************
// RDS Data - Time Struct
//******************************************************************
#define RDS_RADIO_TEXT_BUFFER_SIZE 64
#define RDS_PROGRAM_SERVICE_BUFFER_SIZE 8

typedef struct _rds_time
{
    uint8_t   ctDayHigh;       // Modified Julian Day high bit
    uint16_t  ctDayLow;        // Modified Julian Day low 16 bits
    uint8_t   ctHour;          // Hour
    uint8_t   ctMinute;        // Minute
    int8_t    ctOffset;        // Local Time Offset from UTC (in half-hours)
}rds_time;

//******************************************************************
// FMHD SIS / PSD - Structs
//******************************************************************
#define FMHD_SIS_SLOGAN_BUFFER_SIZE 95
#define FMHD_SIS_UNIVERSAL_SHORT_NAME_BUFFER_SIZE 15 //need 12 + 3 to allow space for the -FM append option
#define FMHD_SIS_STATION_MESSAGE_BUFFER_SIZE 190
#define FMHD_SIS_STATION_NAME_LONG_BUFFER_SIZE 56
#define FMHD_SIS_STATION_NAME_SHORT_BUFFER_SIZE 7 // need 4 + 3 to allow space for the -FM append option
#define FMHD_SIS_STATION_ID_BUFFER_SIZE 4
#define FMHD_SIS_STATION_LOCATION_BUFFER_SIZE 4

typedef enum _FMHD_SIS_PSD_ENCODING_TYPE
{
    IEC_8859_1 = 0,
    UCS2_LITTLEENDIAN = 4,
    ENCODING_RESERVED = 0xFF
}FMHD_SIS_PSD_ENCODING_TYPE;

typedef enum _FMHD_SIS_PRIORITY_TYPE
{
    REGULAR = 0,
    HIGH = 1,
    PRIORITY_RESERVED = 0xFF
}FMHD_SIS_PRIORITY_TYPE;

typedef struct _fmhd_sis_station_message
{
	FMHD_SIS_PSD_ENCODING_TYPE SM_ENCODING;
    FMHD_SIS_PRIORITY_TYPE SM_PRIORITY;
	uint8_t  SM_TEXT[FMHD_SIS_STATION_MESSAGE_BUFFER_SIZE];
}fmhd_sis_station_message;

typedef struct _fmhd_sis_universal_short_name
{
    FMHD_SIS_PSD_ENCODING_TYPE USN_ENCODING;
    uint8_t USN_APPEND;
    uint8_t USN_TEXT[FMHD_SIS_UNIVERSAL_SHORT_NAME_BUFFER_SIZE]; // Displayed Universal Short Name
}fmhd_sis_universal_short_name;

typedef struct _fmhd_sis_slogan
{
    FMHD_SIS_PSD_ENCODING_TYPE SLGN_ENCODING;
    uint8_t  SLGN_TEXT[FMHD_SIS_SLOGAN_BUFFER_SIZE];          // Displayed Station Slogan
}fmhd_sis_slogan;

//******************************************************************
#define FMHD_PSD_TEXT_TYPE_BUFFER_SIZE 0x7F
#define FMHD_PSD_TITLE_BUFFER_SIZE FMHD_PSD_TEXT_TYPE_BUFFER_SIZE
#define FMHD_PSD_ARTIST_BUFFER_SIZE FMHD_PSD_TEXT_TYPE_BUFFER_SIZE
#define FMHD_PSD_ALBUM_BUFFER_SIZE FMHD_PSD_TEXT_TYPE_BUFFER_SIZE
#define FMHD_PSD_GENRE_BUFFER_SIZE FMHD_PSD_TEXT_TYPE_BUFFER_SIZE

#define FMHD_PSD_COMMENT_SHORT_CONTENT_DESC_BUFFER_SIZE 0x7F
#define FMHD_PSD_COMMENT_ACTUAL_TEXT_BUFFER_SIZE 0x7F
#define FMHD_PSD_UFID_OWNER_ID_BUFFER_SIZE 0x80
#define FMHD_PSD_COMMERCIAL_PRICE_BUFFER_SIZE 0x7F
#define FMHD_PSD_COMMERCIAL_CONTACT_URL_BUFFER_SIZE 0x7F
#define FMHD_PSD_COMMERCIAL_SELLER_BUFFER_SIZE 0x7F
#define FMHD_PSD_COMMERCIAL_DESCRIPTION_BUFFER_SIZE 0x7F

#define FMHD_PSD_GENERIC_BUFFER_SIZE 0x7F

#define FMHD_ALERT_BUFFER_SIZE 395

#ifdef OPTION__PSD_FORMAT_ID3
typedef enum _FMHD_PSD_FIELD_DATA_TYPE
{
    PSD_UNKNOWN = 0,
    TITLE = 0x01,
    ARTIST = 0x02,
    ALBUM = 0x04,
    GENRE = 0x08,
    COMMENT = 0x10,
    UFID = 0x20,
    COMMERCIAL = 0x40
}FMHD_PSD_FIELD_DATA_TYPE;

typedef enum _FMHD_PSD_SUBFIELD_DATA_TYPE
{
    UNSET_SUBFIELD = 0,
    PRICE_STRING = 0x01,
    VALID_UNTIL = 0x02,
    CONTACT_URL = 0x04,
    RECEIVED_AS = 0x08,
    NAME_OF_SELLER = 0x10,
    DESCRIPTION = 0x20,
    //Reserved 0x40, 0x80
}FMHD_PSD_SUBFIELD_DATA_TYPE;
#else
typedef enum _FMHD_PSD_FIELD_DATA_TYPE
{
    TITLE = 0,
    ARTIST = 1,
    ALBUM = 2,
    GENRE = 3,
    COMMENT_LANGUAGE = 4,
    COMMENT_SHORT_DESC = 5,
    COMMENT_TEXT = 6,
    COMMERCIAL_PRICE_STRING = 8,
    COMMERCIAL_VALID_UNTIL = 9,
    COMMERCIAL_URL = 10,
    COMMERCIAL_RECEIVED_AS = 11,
    COMMERCIAL_NAME_OF_SELLER = 12,
    COMMERCIAL_DESCRIPTION = 13,
    UFID_OWNER = 14,
    UFID_OWNER_ID = 15
}FMHD_PSD_FIELD_DATA_TYPE;
#endif

typedef enum _FMHD_BER_TYPE
{
    HD_P1 = 1,
    HD_P2 = 2,
    HD_P3 = 3,
    HD_PIDS_BIT = 4,
    HD_PIDS_BLOCK = 5
}FMHD_BER_TYPE;

typedef struct _fmhd_psd_generic_string
{
    FMHD_PSD_FIELD_DATA_TYPE FIELD;
    FMHD_SIS_PSD_ENCODING_TYPE ENCODING;
    uint8_t LENGTH;
    uint8_t DATA[FMHD_PSD_GENERIC_BUFFER_SIZE];
}fmhd_psd_generic_string;

typedef struct _fmhd_alert_string
{
    FMHD_SIS_PSD_ENCODING_TYPE ENCODING;
    uint16_t LENGTH;
    uint8_t DATA[FMHD_ALERT_BUFFER_SIZE];
}fmhd_alert_string;

typedef struct _fmhd_psd_ufid
{
    FMHD_PSD_FIELD_DATA_TYPE FIELD;
    uint8_t SUBFIELD;
    FMHD_SIS_PSD_ENCODING_TYPE ENCODING;
    uint8_t LENGTH;
    uint8_t DATA[FMHD_PSD_UFID_OWNER_ID_BUFFER_SIZE];
}fmhd_psd_ufid;

//******************************************************************
// DAB - Time
//******************************************************************
typedef enum _DAB_TIME_REGION_TYPE
{
    LOCAL = 0,
    UTC = 1
}DAB_TIME_REGION_TYPE;

typedef struct _dab_time
{
    uint16_t YEAR;
    uint8_t MONTH;
    uint8_t DAYS;
    uint8_t HOURS;
    uint8_t MINUTES;
    uint8_t SECONDS;
}dab_time;


//******************************************************************
// DAB - Audio Info
//******************************************************************
typedef enum _DAB_AUDIO_INFO_TYPE
{
    DUAL = 0,
    MONO = 1,
    STEREO = 2,
    JOINT_STEREO = 3
}DAB_AUDIO_INFO_TYPE;

//******************************************************************
// DAB - DLS - Structs
//******************************************************************

#define DAB_DLS_BUFFER_SIZE 128

typedef enum _DAB_DLS_ENCODING_TYPE
{
    DLS_EBU = 0,
    DLS_UCS2 = 6,
    DLS_UTF8 = 0x0F,
    DLS_ENCODING_RESERVED = 0xFF
}DAB_DLS_ENCODING_TYPE;

typedef struct _dab_dls_string
{
    DAB_DLS_ENCODING_TYPE ENCODING;
    uint8_t TOGGLE;
    uint8_t LENGTH;
    uint8_t DATA[DAB_DLS_BUFFER_SIZE];
}dab_dls_string;

//******************************************************************
// Service List - FMHD
//******************************************************************
typedef struct _fmhd_service_list_fast
{
    uint8_t MAIN_LIST_COMPLETE;
    uint8_t AUDIO_SERVICE_PRESENT_BITMASK;
}fmhd_service_list_fast;

//This combines audio/data ("service type") and "processing" fields into one type
//TODO: add service types for "special" audio and all data types
typedef enum _FMHD_SERVICE_TYPE
{
    ST_AUDIO = 0,
    ST_UNSUPPORTED = 0xFE,
    ST_UNDEFINED = 0xFF
}FMHD_SERVICE_TYPE;

#define FMHD_MAX_NUMBER_AUDIO_SERVICES 8

#ifdef OPTION__SERVICE_LIST_SMALL
#define FMHD_SRVC_DISP_NAME_MAX_LENGTH 16
#define HD_SRVC_LIST_MAX_ITEMS 8
//#define FMHD_SRVC_NAME_BUFFER_TOTAL_SIZE (FMHD_SRVC_DISP_NAME_MAX_LENGTH * FMHD_SRVC_LIST_MAX_ITEMS)

typedef struct _fmhd_service_list_element
{
    FMHD_SERVICE_TYPE SERVICE_TYPE;
    uint16_t PROGRAM_PORT_NUMBER; //Component ID
    uint8_t SERVICE_NAME_ENCODING;
    uint8_t SERVICE_NAME_LENGTH;
    uint8_t SERVICE_NAME[FMHD_SRVC_DISP_NAME_MAX_LENGTH];
}fmhd_service_list_element;

typedef struct _fmhd_service_list
{
    uint8_t SERVICE_COUNT;
    fmhd_service_list_element SERVICE[HD_SRVC_LIST_MAX_ITEMS];
}fmhd_service_list;

#else //Full FMHD service List
//TODO: finish this implementation
#define SRVC_PRVD_NAME_MAX_LENGTH 255
#define SRVC_DISP_NAME_MAX_LENGTH 255
#define EXPANDED_SERVICE_ID_MAX_LENGTH 247

typedef struct _fmhd_service_list_element
{
    uint16_t SERVICE_NUMBER;
    uint8_t PRIORITY;
    uint16_t SEQUENCE_NUMBER;
    uint8_t STATUS_FLAG;
    uint32_t RECEIVE_TIME;
    uint8_t SRVC_PRVD_NAME_ENCODING;
    uint8_t SRVC_PRVD_NAME_LENGTH;
    uint8_t SRVC_PRVD_NAME[SRVC_PRVD_NAME_MAX_LENGTH];
    uint8_t SRVC_DISP_NAME_ENCODING;
    uint8_t SRVC_DISP_NAME_LENGTH;
    uint8_t SRVC_DISP_NAME[SRVC_DISP_NAME_MAX_LENGTH];
}fmhd_service_list_element;

typedef struct _fmhd_component_list_element
{
    uint8_t COMP_TYPE;
    uint16_t PROGRAM_PORT_NUMBER;
    uint16_t PROGRAM_TYPE;
    //uint8_t RESERVED_PADDING;
    uint8_t PROCESSING;
    uint8_t PROG_PRIORITY;
    uint8_t ACCESS_RIGHTS;
    uint32_t MIME_HASH_VALUE;
    uint8_t IDENTIFIER_LENGTH;
    uint32_t PROVIDER_ID;
    uint32_t SERVICE_ID;
    uint8_t EXPANDED_SERVICE_ID[EXPANDED_SERVICE_ID_MAX_LENGTH];
}fmhd_component_list_element;
#endif

//******************************************************************
// Service List - DAB
//******************************************************************
#define DAB_SERVICE_LIST_SERVICE_LABEL__SIZE 16

typedef enum _DAB_SERVICE_TYPE
{
    ST_DAB_AUDIO = 0,
    ST_DAB_PLUS_AUDIO = 1,
    ST_DAB_UNSUPPORTED = 0xFE,
    ST_DAB_UNDEFINED = 0xFF
}DAB_SERVICE_TYPE;

#ifdef OPTION__SERVICE_LIST_SMALL

#define DAB_STANDARD__MAX_ENSEMBLES_EUROPE 36       // All ensembles are not used, but this represents the largest set of ensembles in the default frequency list

#define DAB_SERVICE_LIST__MAX_ENSEMBLES_FOR_LIST 10 // Currently no region has nearly this many ensembles - max could be DAB_STANDARD__MAX_ENSEMBLES_EUROPE

#ifndef OPTION__DAB_PRESETS_AS_FAVORITES
    #define DAB_SERVICE_LIST__MAX_SERVICES 104
#else
    #define DAB_SERVICE_LIST__MAX_SERVICES 101
#endif

#define DAB_SERVICE_LIST__MAX_NUMBER_OF_LINKED_FREQUENCIES 4
#define DAB_SERVICE_LIST__LINKED_INDEX_DEFAULT 0xFF
#define DAB_SERVICE_LIST__MAX_NUMBER_OF_ENSEMBLE_CANDIDATE_FREQUENCIES_TO_ATTEMPT_AT_SERVICE_START DAB_STANDARD__MAX_ENSEMBLES_EUROPE

#define DAB_SERVICE_LIST__MAX_OFFSET 8195 // The in chip storage RAM is limited to 8 kB.


typedef struct _dab_service_list_element
{
    uint32_t SERVICE_ID;
    uint16_t COMPONENT_ID;
    uint8_t FREQUENCY_INDEX;
#ifdef OPTION__DAB_SUPPORT_DAB_DAB_LINKING
    uint8_t FREQUENCY_INDEXES_LINKED[DAB_SERVICE_LIST__MAX_NUMBER_OF_LINKED_FREQUENCIES];
#endif
    uint16_t ENSEMBLE_ID;
    uint8_t SERVICE_PTY;
    uint8_t SERVICE_NAME_ENCODING;
    uint8_t SERVICE_NAME[DAB_SERVICE_LIST_SERVICE_LABEL__SIZE];
}dab_service_list_element;

typedef struct _dab_service_list
{
    uint8_t LIST_OBJECT_VERSION;
    uint8_t SERVICE_COUNT;
    uint8_t ENSEMBLE_COUNT;
    uint16_t SERVICE_OFFSETS[DAB_SERVICE_LIST__MAX_SERVICES];
    uint8_t SERVICE_NAME_CHAR0[DAB_SERVICE_LIST__MAX_SERVICES];
    uint16_t ENSEMBLE_OFFSETS[DAB_SERVICE_LIST__MAX_ENSEMBLES_FOR_LIST];
#ifdef OPTION__DAB_PRESETS_AS_FAVORITES
    uint8_t SERVICE_FAVORITES[DAB_SERVICE_LIST__MAX_SERVICES];
#endif
}dab_service_list;

#else // FULL Service List
//TODO: add full service list storage below.
#endif


#ifdef OPTION__DAB_SUPPORT_DAB_DAB_LINKING_A3
typedef struct _dab_service_link_element
{
    uint32_t SERVICE_ID;
    uint16_t COMPONENT_ID;
    uint8_t FREQUENCY_INDEX;
}dab_service_link_element;

#define SERVICE_LINKING_A3_MAX_NUMBER_OF_LINKS_FOR_CURRENT_SERVICE 10
typedef struct _dab_current_service_links
{
    uint8_t NUM_LINKS;
    dab_service_link_element LINKS[SERVICE_LINKING_A3_MAX_NUMBER_OF_LINKS_FOR_CURRENT_SERVICE];
}dab_current_service_links;

#endif //OPTION__DAB_SUPPORT_DAB_DAB_LINKING_A3

#endif

