/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   SDK FMHD SIS decoder
   FILE: FMHD_SIS_Handler.c
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include "common_types.h"
#include "platform_options.h"
#include "FMHD_SIS_Handler.h"
#include "SDK_Callbacks.h"
//#include "si46xx_firmware_api.h"

#ifdef OPTION__INCLUDE_MODE__FMHD
#ifdef OPTION__DECODE_SIS

//-----------------------------------------------------------------------------
// local defines
//-----------------------------------------------------------------------------
#define STATION_MESSAGE_HEADER__ENCODING_OFFSET 1
#define STATION_MESSAGE_HEADER__PRIORITY_OFFSET 2
#define STATION_MESSAGE_HEADER__DATA_OFFSET 3

#define UNIVERSAL_SHORT_NAME_HEADER__ENCODING_OFFSET 1
#define UNIVERSAL_SHORT_NAME_HEADER__APPEND_OFFSET 2
#define UNIVERSAL_SHORT_NAME_HEADER__DATA_OFFSET 3

#define SLOGAN_HEADER__ENCODING_OFFSET 1
#define SLOGAN_HEADER__DATA_OFFSET 2

#define BASIC_SIS_HEADER__NUM_TYPES_OFFSET 0x0A
#define BASIC_SIS_HEADER__DATA_BASE_ADDR_OFFSET 0x0B

#define BASIC_SIS_DATA_HEADER__TYPE_OFFSET 0
#define BASIC_SIS_DATA_HEADER__STATUS_OFFSET 1
#define BASIC_SIS_DATA_HEADER__LENGTH_OFFSET 2
#define BASIC_SIS_DATA_HEADER__DATA_OFFSET 3

#define STATION_LOCATION_HIGH_LOW_MASK 0x80

//-----------------------------------------------------------------------------
// Globals
//-----------------------------------------------------------------------------

// SIS Data
fmhd_sis_slogan  slgnDisplay;                                       // Displayed Station Slogan
fmhd_sis_universal_short_name  usnDisplay;                          // Displayed Universal Short Name
fmhd_sis_station_message  smDisplay;                             // Displayed Station Message

uint8_t  snlDisplay[FMHD_SIS_STATION_NAME_LONG_BUFFER_SIZE];    // Displayed Station Name - Long (backup to Station Slogan)
uint8_t  snsDisplay[FMHD_SIS_STATION_NAME_SHORT_BUFFER_SIZE];   // Displayed Station Name - Short (backup to Universal Short Name (primary for US))

// Unformatted raw data for higher level hosts
uint8_t  stationID[FMHD_SIS_STATION_ID_BUFFER_SIZE];
uint8_t  stationLocationLat[FMHD_SIS_STATION_LOCATION_BUFFER_SIZE];
uint8_t  stationLocationLong[FMHD_SIS_STATION_LOCATION_BUFFER_SIZE];

//update status variables

uint8_t SISupdateStatus;



static void update_sm(fmhd_get_station_info__data sisData)
{
    if(sisData.LENGTH <= STATION_MESSAGE_HEADER__DATA_OFFSET)
    {
        // Not enough data to process
        return;
    }

    smDisplay.SM_PRIORITY = (FMHD_SIS_PRIORITY_TYPE)sisData.PAYLOAD[STATION_MESSAGE_HEADER__PRIORITY_OFFSET];
    smDisplay.SM_ENCODING = (FMHD_SIS_PSD_ENCODING_TYPE)sisData.PAYLOAD[STATION_MESSAGE_HEADER__ENCODING_OFFSET];

    CpyMemory(smDisplay.SM_TEXT, &sisData.PAYLOAD[STATION_MESSAGE_HEADER__DATA_OFFSET], (sisData.LENGTH - STATION_MESSAGE_HEADER__DATA_OFFSET));

    SISupdateStatus |= UPDATED_SM;
    CALLBACK_Updated_Data(UPDATED_SIS_STATION_MESSAGE);
}

static void update_usn(fmhd_get_station_info__data sisData)
{
    if(sisData.LENGTH <= UNIVERSAL_SHORT_NAME_HEADER__DATA_OFFSET)
    {
        // Not enough data to process
        return;
    }

    usnDisplay.USN_ENCODING = (FMHD_SIS_PSD_ENCODING_TYPE)sisData.PAYLOAD[UNIVERSAL_SHORT_NAME_HEADER__ENCODING_OFFSET];
    usnDisplay.USN_APPEND = sisData.PAYLOAD[UNIVERSAL_SHORT_NAME_HEADER__APPEND_OFFSET];

    CpyMemory(usnDisplay.USN_TEXT, &sisData.PAYLOAD[UNIVERSAL_SHORT_NAME_HEADER__DATA_OFFSET], (sisData.LENGTH - UNIVERSAL_SHORT_NAME_HEADER__DATA_OFFSET));

    SISupdateStatus |= UPDATED_USN;
    CALLBACK_Updated_Data(UPDATED_SIS_UNIVERSAL_SHORT_NAME);
}


static void update_basic_sis(fmhd_get_station_info__data sisData)
{
    uint8_t i;
    uint8_t basicSISnumTypes;
    uint8_t basicSISaddr;
    uint8_t basicSISdataLength;

    basicSISnumTypes = sisData.PAYLOAD[BASIC_SIS_HEADER__NUM_TYPES_OFFSET];
    basicSISaddr = BASIC_SIS_HEADER__DATA_BASE_ADDR_OFFSET; // The starting address in the buffer for SIS data types

    //TODO: process the header information if desired - currently ignored
    for(i=0; i<basicSISnumTypes; i++)
    {
        basicSISdataLength = sisData.PAYLOAD[basicSISaddr + BASIC_SIS_DATA_HEADER__LENGTH_OFFSET];
        if((sisData.PAYLOAD[basicSISaddr+BASIC_SIS_DATA_HEADER__STATUS_OFFSET] != AVAILABLE_NEW) || (basicSISdataLength == 0))
        {
            basicSISaddr += (BASIC_SIS_DATA_HEADER__DATA_OFFSET + basicSISdataLength); //move the packet address to next packet
            continue; // The data is not worth processing, moving along
        }

        switch(sisData.PAYLOAD[basicSISaddr+BASIC_SIS_DATA_HEADER__TYPE_OFFSET]) {
            case STATIONID:
                CpyMemory(stationID, &sisData.PAYLOAD[basicSISaddr + BASIC_SIS_DATA_HEADER__DATA_OFFSET], basicSISdataLength); //Length should be 4
                SISupdateStatus |= UPDATED_SID;
                CALLBACK_Updated_Data(UPDATED_SIS_STATION_ID);
                break;
            case STATIONNAMESHORT:
                CpyMemory(snsDisplay, &sisData.PAYLOAD[basicSISaddr + BASIC_SIS_DATA_HEADER__DATA_OFFSET], basicSISdataLength); //Length should be 1-7
                SISupdateStatus |= UPDATED_SNS;
                CALLBACK_Updated_Data(UPDATED_SIS_STATION_NAME_SHORT);
                break;
            case STATIONNAMELONG:
                CpyMemory(snlDisplay, &sisData.PAYLOAD[basicSISaddr + BASIC_SIS_DATA_HEADER__DATA_OFFSET], basicSISdataLength); //Length should be 1-56
                SISupdateStatus |= UPDATED_SNL;
                CALLBACK_Updated_Data(UPDATED_SIS_STATION_NAME_LONG);
                break;
            case STATIONLOCATION:
                if(sisData.PAYLOAD[basicSISaddr + BASIC_SIS_DATA_HEADER__DATA_OFFSET] & STATION_LOCATION_HIGH_LOW_MASK)
                {
                    // High = Lat
                    CpyMemory(stationLocationLat, &sisData.PAYLOAD[basicSISaddr + BASIC_SIS_DATA_HEADER__DATA_OFFSET], basicSISdataLength); //Length should be 4
                    SISupdateStatus |= UPDATED_LAT;
                    CALLBACK_Updated_Data(UPDATED_SIS_LOC_LAT);
                }
                else
                {
                    // Low = Long
                    CpyMemory(stationLocationLong, &sisData.PAYLOAD[basicSISaddr + BASIC_SIS_DATA_HEADER__DATA_OFFSET], basicSISdataLength); //Length should be 4
                    SISupdateStatus |= UPDATED_LONG;
                    CALLBACK_Updated_Data(UPDATED_SIS_LOC_LON);
                }
                break;
            default:
                break;
        }

        basicSISaddr += (BASIC_SIS_DATA_HEADER__DATA_OFFSET + basicSISdataLength); //move the packet address to next packet
    }
}

static void update_slgn(fmhd_get_station_info__data sisData)
{
    if(sisData.LENGTH <= SLOGAN_HEADER__DATA_OFFSET)
    {
        // Not enough data to process
        return;
    }

    slgnDisplay.SLGN_ENCODING = (FMHD_SIS_PSD_ENCODING_TYPE)sisData.PAYLOAD[SLOGAN_HEADER__ENCODING_OFFSET];

    CpyMemory(slgnDisplay.SLGN_TEXT, &sisData.PAYLOAD[SLOGAN_HEADER__DATA_OFFSET], (sisData.LENGTH - SLOGAN_HEADER__DATA_OFFSET));

    SISupdateStatus |= UPDATED_SLGN;
    CALLBACK_Updated_Data(UPDATED_SIS_SLOGAN);
}


//-----------------------------------------------------------------------------
// After tuning to a new station, the SIS tracking variables need to be
// initialized.
//-----------------------------------------------------------------------------
void initSIS(void)
{
    slgnDisplay.SLGN_ENCODING = ENCODING_RESERVED;
    ClearMemory(slgnDisplay.SLGN_TEXT,sizeof(slgnDisplay.SLGN_TEXT));

    usnDisplay.USN_ENCODING = ENCODING_RESERVED;
    usnDisplay.USN_APPEND = 0xFF;
    ClearMemory(usnDisplay.USN_TEXT,sizeof(usnDisplay.USN_TEXT));

    smDisplay.SM_ENCODING = ENCODING_RESERVED;
    smDisplay.SM_PRIORITY = PRIORITY_RESERVED;
    ClearMemory(smDisplay.SM_TEXT,sizeof(smDisplay.SM_TEXT));

    ClearMemory(snlDisplay,sizeof(snlDisplay));

    ClearMemory(snsDisplay,sizeof(snsDisplay));

    ClearMemory(stationID,sizeof(stationID));
    ClearMemory(stationLocationLat,sizeof(stationLocationLat));
    ClearMemory(stationLocationLong,sizeof(stationLocationLong));

    SISupdateStatus = 0;
}

//-----------------------------------------------------------------------------
// After an SIS interrupt, process the data.
//-----------------------------------------------------------------------------
void updateSIS(fmhd_get_station_info__data sisData)
{
    if(sisData.LENGTH != 0)  // It is possible that some SIS data is not present when the interrupt fires.
    {
        switch ((FMHD_SIS_DATA_TYPE)sisData.INFO_SELECT) {
	        case STATION_MESSAGE:
                update_sm(sisData);
	            break;
	        case TIME_ZONE:
            case LEAP_SECONDS:
                //TODO: add support if required - Currently not supported
                return;
	            break;
	        case UNIVERSAL_SHORT_NAME:
                update_usn(sisData);
	            break;
	        case BASIC_SIS_DATA:
                update_basic_sis(sisData);
	            break;
            case SLOGAN:
                update_slgn(sisData);
                break;
	        default:
	            break;
        }
    }
}

#endif //OPTION__DECODE_SIS
#endif //OPTION__INCLUDE_MODE__FMHD