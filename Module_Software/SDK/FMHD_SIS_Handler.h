/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   SDK SIS decoder header
   FILE: FMHD_SIS_Handler.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#ifndef __FMHD_SIS_HANDLER__
#define __FMHD_SIS_HANDLER__

#include "common_types.h"
#include "platform_options.h"
#include "feature_types.h"
#include "si46xx_firmware_api.h"

#ifdef OPTION__INCLUDE_MODE__FMHD
#ifdef OPTION__DECODE_SIS

//-----------------------------------------------------------------------------
// Defines
//-----------------------------------------------------------------------------

//TODO: add time tracking support if needed
//  - though there does not seem to be an actual current time information provided OTA (GPS time is referenced in spec?)

typedef enum _FMHD_SIS_DATA_TYPE
{
    STATION_MESSAGE = 0x01,
    TIME_ZONE = 0x02,
    LEAP_SECONDS = 0x03,
    UNIVERSAL_SHORT_NAME = 0x04,
    BASIC_SIS_DATA = 0x05,
    SLOGAN = 0x06
}FMHD_SIS_DATA_TYPE;

typedef enum _FMHD_SIS_ALFN_STATUS
{
    VALID = 0x00,
    ACQUIRING = 0x01,
    FAILURE = 0x02,
    INVALID = 0x03,
    ALFN_STATUS_RESERVED = 0xFF
}FMHD_SIS_ALFN_STATUS;

typedef enum _FMHD_SIS_TIME_LOCK_STATUS
{
    UNLOCKED = 0x00,
    LOCKED = 0x01,
    NOT_VALID = 0xFF
}FMHD_SIS_TIME_LOCK_STATUS;

typedef enum _FMHD_TIME_ZONE_REGION
{
    NEWFOUNDLAND = 0x072E,
    ATLANTIC = 0x0710,
    EASTERN = 0x06D4,
    CENTRAL = 0x0698,
    MOUNTAIN = 0x065C,
    PACIFIC = 0x0620,
    ALASKA = 0x05E4,
    HAWAII_ALEUTIAN = 0x05A8,
    SAMOA = 0x056C,
    CHAMORRO = 0x0258,
    TIME_ZONE_RESERVED = 0xFFFF
}FMHD_TIME_ZONE_REGION;

typedef enum _FMHD_DST_SCHEDULE
{
    NONE = 0x00,
    US_CANADA = 0x01,
    EU = 0x02,
    DST_SCHEDULE_RESERVED = 0xFF
}FMHD_DST_SCHEDULE;

typedef enum _FMHD_DST_LOCAL
{
    NOT_PRACTICED = 0x00,
    PRACTICED = 0x01,
    DST_LOCAL_RESERVED = 0xFF
}FMHD_DST_LOCAL;

typedef enum _FMHD_DST_REGIONAL
{
    NOT_IN_EFFECT = 0x00,
    IN_EFFECT = 0x01,
    DST_REGIONAL_RESERVED = 0xFF
}FMHD_DST_REGIONAL;

typedef enum _FMHD_SIS_STATUS_TYPE
{
    NO_DATA = 0x00,
    AVAILABLE = 0x01,
    AVAILABLE_NEW = 0x02,
    AVAILABLE_PARTIAL = 0x03,
    STATUS_RESERVED = 0xFF
}FMHD_SIS_STATUS_TYPE;

typedef enum _FMHD_SIS_BASIC_DATA_TYPE
{
    STATIONID = 0x00,
    STATIONNAMESHORT = 0x01,
    STATIONNAMELONG = 0x02,
    STATIONLOCATION = 0x04,
    BASIC_DATA_RESERVED = 0xFF
}FMHD_SIS_BASIC_DATA_TYPE;

typedef enum _FMHD_SIS_UPDATED_BITS
{
    UPDATED_SLGN = 0x01,
    UPDATED_USN = 0x02,
    UPDATED_SM = 0x04,
    UPDATED_SNL = 0x08,
    UPDATED_SNS = 0x10,
    UPDATED_SID = 0x20,
    UPDATED_LAT = 0x40,
    UPDATED_LONG = 0x80
}FMHD_SIS_UPDATED_BITS;

//-----------------------------------------------------------------------------
// Globals
//-----------------------------------------------------------------------------
extern fmhd_sis_slogan  slgnDisplay;                                       // Displayed Station Slogan
extern fmhd_sis_universal_short_name  usnDisplay;                          // Displayed Universal Short Name
extern fmhd_sis_station_message smDisplay;                             // Displayed Station Message

extern uint8_t  snlDisplay[FMHD_SIS_STATION_NAME_LONG_BUFFER_SIZE];    // Displayed Station Name - Long (backup to Station Slogan)
extern uint8_t  snsDisplay[FMHD_SIS_STATION_NAME_SHORT_BUFFER_SIZE];   // Displayed Station Name - Short (backup to Universal Short Name (primary for US))


// Unformatted raw data for higher level hosts
extern uint8_t  stationID[FMHD_SIS_STATION_ID_BUFFER_SIZE];
extern uint8_t  stationLocationLat[FMHD_SIS_STATION_LOCATION_BUFFER_SIZE];
extern uint8_t  stationLocationLong[FMHD_SIS_STATION_LOCATION_BUFFER_SIZE];

extern uint8_t SISupdateStatus;

//-----------------------------------------------------------------------------
// Function prototypes
//-----------------------------------------------------------------------------
void initSIS(void);
void updateSIS(fmhd_get_station_info__data sisData);

#endif //OPTION__DECODE_SIS
#endif //OPTION__INCLUDE_MODE__FMHD

#endif