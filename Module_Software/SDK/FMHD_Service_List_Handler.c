/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   SDK HD radio service list handler - for determining the details of what audio services are available on a given channel
   FILE: FMHD_Service_List_Handler.c
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include "common_types.h"
#include "platform_options.h"
#include "FMHD_Service_List_Handler.h"
#include "SDK_Callbacks.h"
//#include "si46xx_firmware_api.h"

#ifdef OPTION__INCLUDE_MODE__FMHD
#ifdef OPTION__DECODE_FMHD_SERVICE_LIST

//-----------------------------------------------------------------------------
// local defines
//-----------------------------------------------------------------------------
#define SERVICE_LIST_NUM_SERVICES__SIZE 1

#define SERVICE_LIST_SERVICE_NUMBER__OFFSET 0
#define SERVICE_LIST_PRIORITY__OFFSET 2
#define SERVICE_LIST_SEQUENCE_NUMBER__OFFSET 3
#define SERVICE_LIST_STATUS_FLAG__OFFSET 5
#define SERVICE_LIST_RECEIVE_TIME__OFFSET 6
#define SERVICE_LIST_SRVC_PRVD_NAME_ENCODING__OFFSET 10
#define SERVICE_LIST_SRVC_PRVD_NAME_LENGTH__OFFSET 11
#define SERVICE_LIST_SRVC_PRVD_NAME__OFFSET 12
#define SERVICE_LIST_SRVC_DISP_NAME_ENCODING__OFFSET 0  //based 0 again because of variable length
#define SERVICE_LIST_SRVC_DISP_NAME_LENGTH__OFFSET 1
#define SERVICE_LIST_SRVC_DISP_NAME__OFFSET 2

#define COMPONENT_LIST_NUM_COMPONENTS__SIZE 1

#define COMPONENT_LIST_COMP_TYPE__OFFSET 0
#define COMPONENT_LIST_PROGRAM_PORT_NUMBER__OFFSET 1
#define COMPONENT_LIST_PROGRAM_TYPE__OFFSET 3
#define COMPONENT_LIST_PROCESSING__OFFSET 6
#define COMPONENT_LIST_PROG_PRIORITY__OFFSET 7
#define COMPONENT_LIST_ACCESS_RIGHTS__OFFSET 8
#define COMPONENT_LIST_MIME_HASH_VALUE__OFFSET 9
#define COMPONENT_LIST_IDENTIFIER_LENGTH__OFFSET 13
#define COMPONENT_LIST_PROVIDER_ID__OFFSET 14
#define COMPONENT_LIST_SERVICE_ID__OFFSET 18
#define COMPONENT_LIST_EXPANDED_SERVICE_ID__OFFSET 22


#define LIST_VERSION_UNKNOWN 0xFFFF
//-----------------------------------------------------------------------------
// Globals
//-----------------------------------------------------------------------------

// Service List Data
fmhd_service_list_fast svcListFast;
fmhd_service_list svcListFull_Audio;

uint16_t _currentAudioListVersion;
uint16_t _currentDataListVersion;

//-----------------------------------------------------------------------------
// After changing Frequencies the service list needs to be flushed
//-----------------------------------------------------------------------------
void initHD_ServiceList(void)
{
    uint8_t i = 0;
    svcListFast.AUDIO_SERVICE_PRESENT_BITMASK = 0;
    svcListFast.MAIN_LIST_COMPLETE = 0;

    _currentAudioListVersion = LIST_VERSION_UNKNOWN;
    _currentDataListVersion = LIST_VERSION_UNKNOWN;

    svcListFull_Audio.SERVICE_COUNT = 0;
    for(i = 0;i<HD_SRVC_LIST_MAX_ITEMS;i++)
    {
        svcListFull_Audio.SERVICE[i].SERVICE_TYPE = ST_UNDEFINED;
    }
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

#ifdef OPTION__SERVICE_LIST_SMALL
void updateFMHD_ServiceList_Audio(get_digital_service_list__data* fmhdList, uint16_t listVer)
{
    RETURN_CODE ret = 0;
    uint16_t slAddr = 0; //Current Service List Addr in the current buffer - note this may be broken up and reset
    uint8_t currentServiceNumber = 0;
    uint8_t prvdNameSize = 0;
    uint8_t esidNameSize = 0;
    uint8_t serviceLoop = 0;
    uint8_t serviceNum = 0;
    uint8_t componentLoop = 0;
    uint8_t componentNum = 0;
    uint8_t bitmaskTemp = 0;

    if((listVer == _currentAudioListVersion) && (_currentAudioListVersion != LIST_VERSION_UNKNOWN))
    {
        //we have no need to process the list - it is the same list we already have
        return;
    }

    if(fmhdList->TOTAL_SIZE > 0)
    {
        // Clear the fast list bitmask as we will repopulate it from the main list
        svcListFast.AUDIO_SERVICE_PRESENT_BITMASK = 0;
        svcListFull_Audio.SERVICE_COUNT = 0;

        // the service list fit into a single transaction, easier processing logic here
        serviceNum = fmhdList->PAYLOAD[slAddr];
        slAddr += SERVICE_LIST_NUM_SERVICES__SIZE;
        for(serviceLoop = 0; serviceLoop < serviceNum; serviceLoop ++)
        {
            ret |= realign_service_list_buffer(&slAddr,fmhdList,SERVICE_LIST_SRVC_PRVD_NAME_LENGTH__OFFSET);

            //advance the pointer to beyond the non-fixed provider name size
            prvdNameSize = fmhdList->PAYLOAD[slAddr+SERVICE_LIST_SRVC_PRVD_NAME_LENGTH__OFFSET];
            slAddr += (prvdNameSize + SERVICE_LIST_SRVC_PRVD_NAME__OFFSET);

            ret |= realign_service_list_buffer(&slAddr, fmhdList, (fmhdList->PAYLOAD[slAddr+SERVICE_LIST_SRVC_DISP_NAME_LENGTH__OFFSET] + SERVICE_LIST_SRVC_DISP_NAME_LENGTH__OFFSET));

            //read the service name info
            svcListFull_Audio.SERVICE[currentServiceNumber].SERVICE_NAME_ENCODING = fmhdList->PAYLOAD[slAddr+SERVICE_LIST_SRVC_DISP_NAME_ENCODING__OFFSET];
                
            //Need to ensure the service display name is not copied longer than our allowed buffer size
            if(fmhdList->PAYLOAD[slAddr+SERVICE_LIST_SRVC_DISP_NAME_LENGTH__OFFSET] <= FMHD_SRVC_DISP_NAME_MAX_LENGTH)
            {
                svcListFull_Audio.SERVICE[currentServiceNumber].SERVICE_NAME_LENGTH = fmhdList->PAYLOAD[slAddr+SERVICE_LIST_SRVC_DISP_NAME_LENGTH__OFFSET];
            }
            else
            {
                svcListFull_Audio.SERVICE[currentServiceNumber].SERVICE_NAME_LENGTH = FMHD_SRVC_DISP_NAME_MAX_LENGTH;
            }
            CpyMemory(svcListFull_Audio.SERVICE[currentServiceNumber].SERVICE_NAME, &fmhdList->PAYLOAD[slAddr+SERVICE_LIST_SRVC_DISP_NAME__OFFSET], svcListFull_Audio.SERVICE[currentServiceNumber].SERVICE_NAME_LENGTH);

            //Increment the buffer address
            slAddr += (fmhdList->PAYLOAD[slAddr+SERVICE_LIST_SRVC_DISP_NAME_LENGTH__OFFSET] + SERVICE_LIST_SRVC_DISP_NAME__OFFSET);

            ret |= realign_service_list_buffer(&slAddr, fmhdList,COMPONENT_LIST_NUM_COMPONENTS__SIZE);

            componentNum = fmhdList->PAYLOAD[slAddr];
            slAddr += COMPONENT_LIST_NUM_COMPONENTS__SIZE;

            for(componentLoop = 0; componentLoop < componentNum; componentLoop++)
            {
                ret |= realign_service_list_buffer(&slAddr,fmhdList,COMPONENT_LIST_EXPANDED_SERVICE_ID__OFFSET);

                if((componentLoop > 0) && (svcListFull_Audio.SERVICE[currentServiceNumber].SERVICE_TYPE != ST_UNSUPPORTED))
                {
                    //we have more than 1 component in this service need to copy the previous services general info
                    svcListFull_Audio.SERVICE[currentServiceNumber].SERVICE_NAME_ENCODING = svcListFull_Audio.SERVICE[currentServiceNumber - 1].SERVICE_NAME_ENCODING;
                    svcListFull_Audio.SERVICE[currentServiceNumber].SERVICE_NAME_LENGTH = svcListFull_Audio.SERVICE[currentServiceNumber - 1].SERVICE_NAME_LENGTH;
                    CpyMemory(svcListFull_Audio.SERVICE[currentServiceNumber].SERVICE_NAME,svcListFull_Audio.SERVICE[currentServiceNumber - 1].SERVICE_NAME, svcListFull_Audio.SERVICE[currentServiceNumber].SERVICE_NAME_LENGTH);
                }
                svcListFull_Audio.SERVICE[currentServiceNumber].PROGRAM_PORT_NUMBER = _recover_16bit_from_little_endian_buffer(&fmhdList->PAYLOAD[slAddr+COMPONENT_LIST_PROGRAM_PORT_NUMBER__OFFSET]);

                if(svcListFull_Audio.SERVICE[currentServiceNumber].PROGRAM_PORT_NUMBER < FMHD_MAX_NUMBER_AUDIO_SERVICES)
                {
                    //This is an audio service
                    svcListFull_Audio.SERVICE[currentServiceNumber].SERVICE_TYPE = ST_AUDIO;

                    //Update the fast list bitmask with the port found here
                    bitmaskTemp = (1 << svcListFull_Audio.SERVICE[currentServiceNumber].PROGRAM_PORT_NUMBER);
                    svcListFast.AUDIO_SERVICE_PRESENT_BITMASK |= bitmaskTemp;
                    currentServiceNumber ++;
                    svcListFull_Audio.SERVICE_COUNT ++;
                }
                else
                {
                    // We don't handle any other types than the primary audio streams in the small list
                    svcListFull_Audio.SERVICE[currentServiceNumber].SERVICE_TYPE = ST_UNSUPPORTED;

                    //Do not increment currentServiceNumber - we will replace its contents if a new service group or ignore
                }

                //Determine the length of the Provider/Service ID fields.
                //Note the expanded service ID length includes the Service Provider ID and Service ID field size (currently 8)
                esidNameSize = fmhdList->PAYLOAD[slAddr+COMPONENT_LIST_IDENTIFIER_LENGTH__OFFSET];
                slAddr += (COMPONENT_LIST_PROVIDER_ID__OFFSET + esidNameSize);  // see above note for why we base off PROVIDER_ID offset rather than EXPANDED_SERVICE_ID offset
                
                ret |= realign_service_list_buffer(&slAddr,fmhdList, (COMPONENT_LIST_PROVIDER_ID__OFFSET + esidNameSize));

                if(currentServiceNumber == HD_SRVC_LIST_MAX_ITEMS)
                {
                    //We have run out of list space - we have to lose the remaining list as our buffer is too small
                    return;
                }
            }
        }

        if(ret == SUCCESS)
        {
            svcListFast.MAIN_LIST_COMPLETE = 1;
            //We updated the list so we should keep track of this version to avoid reprocessing it
            _currentAudioListVersion = listVer;
            CALLBACK_Updated_Data(UPDATED_SERVICE_LIST_AUDIO);
        }
    }
}

//void updateFMHD_ServiceList_Data(get_digital_service_list__data* fmhdList, uint16_t listVer)
//{
    //Not implemented - Stub
//    return;
//}

#else
void updateFMHD_ServiceList_Audio(get_digital_service_list__data* fmhdList, uint16_t listVer)
{
    //Not implemented - Stub
    return;
}

//void updateFMHD_ServiceList_Data(get_digital_service_list__data* fmhdList, uint16_t listVer)
//{
    //Not implemented - Stub
//    return;
//}
#endif

#endif //OPTION__DECODE_FMHD_SERVICE_LIST
#endif //OPTION__INCLUDE_MODE__FMHD