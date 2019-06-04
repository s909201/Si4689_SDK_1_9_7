/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   SDK DAB service list decoder - decodes the available services and adds them to the overall service database
   FILE: DAB_Service_List_Handler.c
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include "common_types.h"
#include "platform_options.h"
#include "DAB_Service_List_Handler.h"
#include "SDK_Callbacks.h"
#include "Firmware_API_Manager.h"
#include "si46xx_firmware_api.h"

#ifdef OPTION__INCLUDE_MODE__DAB
#ifdef OPTION__DECODE_DAB_SERVICE_LIST

//-----------------------------------------------------------------------------
// local defines
//-----------------------------------------------------------------------------

#define DAB_SERVICE_LIST_VERSION__OFFSET 0
#define DAB_SERVICE_LIST_NUM_SERVICES__OFFSET 2
#define DAB_SERVICE_LIST_ELEMENT_START__OFFSET 6

#define DAB_SERVICE_LIST_SERVICE_ID__OFFSET 0
#define DAB_SERVICE_LIST_SERVICE_INFO1__OFFSET 4
#define DAB_SERVICE_LIST_SERVICE_INFO1__PTY_MASK 0x3E
#define DAB_SERVICE_LIST_SERVICE_INFO1__PTY_SHIFT 1
#define DAB_SERVICE_LIST_SERVICE_INFO1__PDFLAG_MASK 0x01
#define DAB_SERVICE_LIST_SERVICE_INFO1__PDFLAG_AUDIO 0
#define DAB_SERVICE_LIST_SERVICE_INFO1__PDFLAG_DATA 1

#define DAB_SERVICE_LIST_SERVICE_INFO2__OFFSET 5
#define DAB_SERVICE_LIST_SERVICE_INFO2__NUM_COMP_MASK 0x0F
#define DAB_SERVICE_LIST_SERVICE_INFO2__CAID_MASK 0x70
#define DAB_SERVICE_LIST_SERVICE_INFO2__CAID_SHIFT 4
#define DAB_SERVICE_LIST_SERVICE_INFO2__LOCAL_MASK 0x80
#define DAB_SERVICE_LIST_SERVICE_INFO2__LOCAL_SHIFT 7

#define DAB_SERVICE_LIST_SERVICE_INFO3__OFFSET 6
#define DAB_SERVICE_LIST_SERVICE_INFO3__SICHARSET_MASK 0x0F

#define DAB_SERVICE_LIST_SERVICE_LABEL__OFFSET 8

//#define DAB_SERVICE_LIST_SERVICE_LABEL__SIZE 16  //Defined in feature_types.h

#define DAB_SERVICE_LIST_SERVICE_DATA__LENGTH (DAB_SERVICE_LIST_SERVICE_LABEL__OFFSET + DAB_SERVICE_LIST_SERVICE_LABEL__SIZE)

#define DAB_COMPONENT_LIST_COMPONENT_ID__OFFSET 0
#define DAB_COMPONENT_LIST_COMPONENT_ID__TMID_MASK 0xC000 //TMID = 0 means audio service, 1 = data(stream), 2 = FIDC, 3 = data(packet)
#define DAB_COMPONENT_LIST_COMPONENT_ID__TMID_SHIFT 14

#define DAB_COMPONENT_LIST_COMPONENT_INFO__OFFSET 2
#define DAB_COMPONENT_LIST_COMPONENT_INFO__CAFLAG_MASK 0x01     // Anything with CA = 1 can be thrown out - we dont support CA
#define DAB_COMPONENT_LIST_COMPONENT_INFO__PS_MASK 0x02         // Primary (0), Secondary (1) - ignored
#define DAB_COMPONENT_LIST_COMPONENT_INFO__PS_SHIFT 1
#define DAB_COMPONENT_LIST_COMPONENT_INFO__ASCTY_DSCTY_MASK 0xFC
#define DAB_COMPONENT_LIST_COMPONENT_INFO__ASCTY_DSCTY_SHIFT 2
// ASCTY/DSCTY determined by TMID
// ASCTY:   0 = foreground
//          1 = background
//          2 = multichannel extension
// DSCTY:   0 = Unspecified data
//          1 = Traffic message Channel (TMC)
//          2 = Emergency Warning System (EWS)
//          3 = Interactive Text Transmission System (ITTS)
//          4 = Paging
//          5 = Transparent Data Channel (TDC)
//          24 = MPEG-2 Transport Stream, see [29]
//          59 = Embedded IP packets
//          60 = Multimedia Object Transfer (MOT)
//          61 = Proprietary service: no DSCTy signalled
//          62 = Not used
//          63 = Not used

#define DAB_COMPONENT_LIST_VALID_FLAGS__OFFSET 3

#define DAB_COMPONENT_LIST_COMPONENT_DATA__LENGTH 4


//-----------------------------------------------------------------------------
// Globals
//-----------------------------------------------------------------------------
#ifdef OPTION__SERVICE_LIST_SMALL

// Service List Data

dab_service_list svcListDAB;
#ifdef OPTION__DAB_PRESETS_AS_FAVORITES
    uint8_t favoriteServicesShifted;
#endif //OPTION__DAB_PRESETS_AS_FAVORITES

uint16_t _currentListVersion;
uint16_t _current_service_list_buffer_end_as_offset;

uint8_t DAB_service_list_updated_for_current_freq;

//-----------------------------------------------------------------------------
// After a scan the service list needs to be flushed
//-----------------------------------------------------------------------------
void initDAB_ServiceList(void)
{
    uint8_t index;

    _currentListVersion = DAB_LIST_VERSION_UNKNOWN;
    _current_service_list_buffer_end_as_offset = 0;

    svcListDAB.LIST_OBJECT_VERSION = DAB_SERVICE_LIST_OBJECT_VERSION;
    svcListDAB.SERVICE_COUNT = 0;
    svcListDAB.ENSEMBLE_COUNT = 0;
    
    // Clearing the offset values for external RAM
    for(index = 0; index < DAB_SERVICE_LIST__MAX_SERVICES; index ++)
    {
		svcListDAB.SERVICE_OFFSETS[index] = 0;

        #ifdef OPTION__DAB_PRESETS_AS_FAVORITES
            svcListDAB.SERVICE_FAVORITES[index] = 0;
        #endif //OPTION__DAB_PRESETS_AS_FAVORITES
    }
    for(index = 0; index < DAB_SERVICE_LIST__MAX_ENSEMBLES_FOR_LIST; index ++)
    {
		svcListDAB.ENSEMBLE_OFFSETS[index] = 0;
    }

    //No need to clear the external RAM as it is all pointer based anyway - trust in SERVICE_COUNT
}

RETURN_CODE getServiceListElement(uint16_t offset, dab_service_list_element* listElement)
{
	RETURN_CODE ret = 0;

    //Removing this check as we are using the area beyond the end of the service list for temporary element storage
    /*
    //Make sure we aren't going past the end of the service list
    if(offset > (_current_service_list_buffer_end_as_offset - sizeof(dab_service_list_element)))
    {
        return INVALID_INPUT;
    }
    */

	ret = read_storage__command(offset);
	ret |= read_storage__reply(sizeof(dab_service_list_element), (uint8_t*)listElement);

	return ret;
}

//This will search the list for the matching service
// serviceAddressIndex is the starting point of the search - input 0 to start at the beginning of the list, input the current index + 1 to find alternates
RETURN_CODE findServiceInList(uint32_t serviceID, uint16_t componentID, uint8_t ignoreComponent, uint8_t matchIndex, uint8_t freqIndex, uint8_t* serviceAddressIndex)
{
    RETURN_CODE ret = 0;
	dab_service_list_element tempElement;
    uint8_t serviceLoopIndex;

    for(serviceLoopIndex = *serviceAddressIndex; serviceLoopIndex < svcListDAB.SERVICE_COUNT; serviceLoopIndex++)
    {
		ret = getServiceListElement(svcListDAB.SERVICE_OFFSETS[serviceLoopIndex],&tempElement);

		if(ret == SUCCESS)
		{
            if(matchIndex)
            {
                if((tempElement.SERVICE_ID == serviceID) && ((tempElement.COMPONENT_ID == componentID) || (ignoreComponent > 0)) && (tempElement.FREQUENCY_INDEX == freqIndex))
			    {
				    *serviceAddressIndex = serviceLoopIndex;
				    return SUCCESS;
			    }
            }
            else
            {
                if((tempElement.SERVICE_ID == serviceID) && ((tempElement.COMPONENT_ID == componentID) || (ignoreComponent > 0)) && (tempElement.FREQUENCY_INDEX != freqIndex))
			    {
				    *serviceAddressIndex = serviceLoopIndex;
				    return SUCCESS;
			    }
            }
		}
		else
		{
			break;
		}
    }
     
    return INVALID_INPUT;
}

RETURN_CODE findEnsembleInList(uint8_t frequencyIndex, uint8_t* ensembleAddressIndex)
{
    RETURN_CODE ret = 0;
	dab_service_list_element tempElement;
    uint8_t ensembleLoopIndex;

    for(ensembleLoopIndex = 0; ensembleLoopIndex < svcListDAB.ENSEMBLE_COUNT; ensembleLoopIndex++)
    {
        ret = getServiceListElement(svcListDAB.ENSEMBLE_OFFSETS[ensembleLoopIndex],&tempElement);

		if(ret == SUCCESS)
		{
            if(tempElement.FREQUENCY_INDEX == frequencyIndex)
			{
				*ensembleAddressIndex = ensembleLoopIndex;
				return SUCCESS;
			}
		}
		else
		{
			break;
		}
    }
     
    return INVALID_INPUT;
}


uint8_t _convert_ASCII_upper(uint8_t character)
{
    if((character <= 0x7A) && (character >= 0x61))
    {
        // Convert characters to upper case for comparison
        return (character - 0x20);
    }
    else
    {
        return character;
    }
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
RETURN_CODE _insertion_sort_alphabetical_single_element(uint8_t newElementIndex, dab_service_list_element currentElementToInsert)
{
    RETURN_CODE ret = 0;
    dab_service_list_element tempElement;
    uint8_t sortIndex;
    uint8_t foundIndex = 0xFF;
    uint8_t shiftIndex;
    uint8_t compareIndex;
    uint16_t tempOffset;
    uint8_t tempCharAscii_old;
    uint8_t tempCharAscii_new;

    #ifdef OPTION__DAB_PRESETS_AS_FAVORITES
        uint8_t tempFavorite;
    #endif

    if(newElementIndex > 0)
    {
        //Find the sort index for the new element
        for(sortIndex = 0; sortIndex < newElementIndex; sortIndex ++)
        {
            if(svcListDAB.SERVICE_NAME_CHAR0[sortIndex] > _convert_ASCII_upper(currentElementToInsert.SERVICE_NAME[0]))
            {
                //index found
                foundIndex = sortIndex;
                break;
            }
            else if(svcListDAB.SERVICE_NAME_CHAR0[sortIndex] == _convert_ASCII_upper(currentElementToInsert.SERVICE_NAME[0]))
            {
                //single character match - need to read out the values from si46xx to compare more of the string
                ret = getServiceListElement(svcListDAB.SERVICE_OFFSETS[sortIndex],&tempElement);

                if(ret == SUCCESS)
                {
                    for(compareIndex = 1; compareIndex <= DAB_SERVICE_LIST_SERVICE_LABEL__SIZE; compareIndex ++)
                    {
                        tempCharAscii_old = _convert_ASCII_upper(tempElement.SERVICE_NAME[compareIndex]);
                        tempCharAscii_new = _convert_ASCII_upper(currentElementToInsert.SERVICE_NAME[compareIndex]);

                        if(tempCharAscii_old > tempCharAscii_new)
                        {
                            //Sort Index found
                            foundIndex = sortIndex;
                            break;
                        }
                        else if(tempCharAscii_old < tempCharAscii_new)
                        {
                            //Determined it is not the position
                            break;
                        }
                    }
                }
                else
                {
                    return INVALID_INPUT;
                }

                if(foundIndex != 0xFF)
                {
                    // We have found the index so we should stop searching
                    break;
                }
            }
        }
    }

    //If we never found an index, the current position is fine.
    if(foundIndex != 0xFF)
    {
        tempOffset = svcListDAB.SERVICE_OFFSETS[newElementIndex];
        #ifdef OPTION__DAB_PRESETS_AS_FAVORITES
            tempFavorite = svcListDAB.SERVICE_FAVORITES[newElementIndex];
        #endif

        //set the value and shift the elements higher than the inserted value
        for(shiftIndex = newElementIndex; shiftIndex > foundIndex; shiftIndex --)
        {
            svcListDAB.SERVICE_OFFSETS[shiftIndex] = svcListDAB.SERVICE_OFFSETS[shiftIndex-1];
            svcListDAB.SERVICE_NAME_CHAR0[shiftIndex] = svcListDAB.SERVICE_NAME_CHAR0[shiftIndex-1];

            #ifdef OPTION__DAB_PRESETS_AS_FAVORITES
                svcListDAB.SERVICE_FAVORITES[shiftIndex] = svcListDAB.SERVICE_FAVORITES[shiftIndex-1];
            #endif //OPTION__DAB_PRESETS_AS_FAVORITES
        }

        svcListDAB.SERVICE_OFFSETS[foundIndex] = tempOffset;
        svcListDAB.SERVICE_NAME_CHAR0[foundIndex] = _convert_ASCII_upper(currentElementToInsert.SERVICE_NAME[0]);

        #ifdef OPTION__DAB_PRESETS_AS_FAVORITES
            svcListDAB.SERVICE_FAVORITES[foundIndex] = tempFavorite;
        #endif
    }

    return ret;
}

RETURN_CODE _insertion_sort_alphabetical_list(uint8_t initialServiceCount)
{
    RETURN_CODE ret = 0;
    dab_service_list_element sortElement;
    uint8_t loopCount;
    uint8_t sortPosition;

    #ifdef OPTION__DAB_PRESETS_AS_FAVORITES
        uint8_t favoritesLoopIndex = 0;
        dab_service_list_element favoriteTempElement;
    #endif

    for(loopCount = 0; loopCount < (svcListDAB.SERVICE_COUNT - initialServiceCount); loopCount ++)
    {
        sortPosition = (initialServiceCount + loopCount);
        ret |= getServiceListElement((sortPosition*sizeof(dab_service_list_element)),&sortElement);

        if(ret != SUCCESS)
        {
            return ret;
        }

        #ifdef OPTION__DAB_PRESETS_AS_FAVORITES
            //We need to decide if the new element was a favorite
            svcListDAB.SERVICE_FAVORITES[sortPosition] = 0;
            for(favoritesLoopIndex = 0; favoritesLoopIndex < favoriteServicesShifted; favoritesLoopIndex ++)
            {
                getServiceListElement((DAB_SERVICE_LIST__MAX_SERVICES + favoritesLoopIndex)*sizeof(dab_service_list_element),&favoriteTempElement);
                if((sortElement.SERVICE_ID == favoriteTempElement.SERVICE_ID) && (sortElement.COMPONENT_ID == favoriteTempElement.COMPONENT_ID))
                {
                    svcListDAB.SERVICE_FAVORITES[sortPosition] = 1;
                    break;
                }
            }
        #endif //OPTION__DAB_PRESETS_AS_FAVORITES

        //If we cleared the index lists we need to repopulate
        if(svcListDAB.SERVICE_NAME_CHAR0[sortPosition] == 0)
        {
            svcListDAB.SERVICE_NAME_CHAR0[sortPosition] = _convert_ASCII_upper(sortElement.SERVICE_NAME[0]);
        }

        ret = _insertion_sort_alphabetical_single_element(sortPosition,sortElement);
    }

    return ret;
}


//-----------------------------------------------------------------------------
// Need an internal function for realigning the packed service list - when retiring/updating an existing list
//-----------------------------------------------------------------------------
RETURN_CODE _repack_stored_dab_list(uint8_t ensembleOffsetIndex)
{
	RETURN_CODE ret = 0;
	dab_service_list_element tempElement;
    uint8_t shiftIndex;
	uint8_t shiftedServices = 0;
    uint8_t serviceIndexOfFoundEnsemble;
    uint8_t removedServiceCount = 0;
    uint8_t currentEnd = 0;
    uint16_t serviceOffsetShiftSize;

    svcListDAB.ENSEMBLE_COUNT = svcListDAB.ENSEMBLE_COUNT - 1;


    if(ensembleOffsetIndex < svcListDAB.ENSEMBLE_COUNT)
    {
        removedServiceCount = ((svcListDAB.ENSEMBLE_OFFSETS[ensembleOffsetIndex+1] - svcListDAB.ENSEMBLE_OFFSETS[ensembleOffsetIndex]) / sizeof(dab_service_list_element));
    }
    else
    {
        removedServiceCount = ((_current_service_list_buffer_end_as_offset - svcListDAB.ENSEMBLE_OFFSETS[ensembleOffsetIndex]) / sizeof(dab_service_list_element));
        _current_service_list_buffer_end_as_offset = svcListDAB.ENSEMBLE_OFFSETS[ensembleOffsetIndex];
    }
    serviceIndexOfFoundEnsemble = (svcListDAB.ENSEMBLE_OFFSETS[ensembleOffsetIndex] / sizeof(dab_service_list_element));
        

    #ifdef OPTION__DAB_PRESETS_AS_FAVORITES
        favoriteServicesShifted = 0;
        // We need to retain the information about current favorites
        //for(shiftIndex = serviceIndexOfFoundEnsemble; shiftIndex < (serviceIndexOfFoundEnsemble + removedServiceCount); shiftIndex ++)
        for(shiftIndex = 0; shiftIndex < svcListDAB.SERVICE_COUNT; shiftIndex++)
        {
            if(svcListDAB.SERVICE_FAVORITES[shiftIndex] == 1)
            {
                ret = getServiceListElement(svcListDAB.SERVICE_OFFSETS[shiftIndex], &tempElement);
                if(ret == SUCCESS)
                {
                    //Temporarily store it at the end of the memory space
                    ret |= write_storage__command((DAB_SERVICE_LIST__MAX_SERVICES + favoriteServicesShifted)*sizeof(dab_service_list_element),sizeof(dab_service_list_element),(uint8_t*)&tempElement);
    				if(ret == SUCCESS)
    				{
    					favoriteServicesShifted++;
    				}
                }

                if(ret != SUCCESS)
    			{
    				return ret;
    			}
            }
        }
    #endif //OPTION__DAB_PRESETS_AS_FAVORITES

    //We can skip copying services if the removed set was at the end of the current list
    if(ensembleOffsetIndex < svcListDAB.ENSEMBLE_COUNT)
    {
		//Adjust the ensemble offset array
        serviceOffsetShiftSize = removedServiceCount * sizeof(dab_service_list_element);
		for(shiftIndex = ensembleOffsetIndex + 1; shiftIndex <= svcListDAB.ENSEMBLE_COUNT; shiftIndex ++)
        {
			svcListDAB.ENSEMBLE_OFFSETS[shiftIndex] = (svcListDAB.ENSEMBLE_OFFSETS[shiftIndex + 1] - serviceOffsetShiftSize);
        }

		//Copy/Repack the services
		for(shiftIndex = (serviceIndexOfFoundEnsemble + removedServiceCount); shiftIndex < svcListDAB.SERVICE_COUNT; shiftIndex ++)
		{
			ret = getServiceListElement(shiftIndex*sizeof(dab_service_list_element), &tempElement);
			if(ret == SUCCESS)
			{
				ret |= write_storage__command((serviceIndexOfFoundEnsemble + shiftedServices)*sizeof(dab_service_list_element),sizeof(dab_service_list_element),(uint8_t*)&tempElement);
				if(ret == SUCCESS)
				{
					shiftedServices++;
				}
			}

			if(ret != SUCCESS)
			{
				return ret;
			}
		}

        _current_service_list_buffer_end_as_offset = _current_service_list_buffer_end_as_offset - serviceOffsetShiftSize;
    }

    svcListDAB.SERVICE_COUNT = svcListDAB.SERVICE_COUNT - removedServiceCount;

    //Clear the service list sorted pointers
    for(shiftIndex = 0; shiftIndex < svcListDAB.SERVICE_COUNT; shiftIndex++)
    {
        //ret = getServiceListElement(shiftIndex*sizeof(dab_service_list_element), &tempElement);
		if(ret == SUCCESS)
		{
            svcListDAB.SERVICE_OFFSETS[shiftIndex] = shiftIndex*sizeof(dab_service_list_element);
            //svcListDAB.SERVICE_NAME_CHAR0[shiftIndex] = _convert_ASCII_upper(tempElement.SERVICE_NAME[0]);
            svcListDAB.SERVICE_NAME_CHAR0[shiftIndex] = 0;

            #ifdef OPTION__DAB_PRESETS_AS_FAVORITES
                svcListDAB.SERVICE_FAVORITES[shiftIndex] = 0;
            #endif
        }
    }

    //Correct the service indexes by resorting
    ret |= _insertion_sort_alphabetical_list(0);

	return ret;
}

RETURN_CODE _add_data_to_buffer(dab_service_list_element* elementToAdd)
{
    RETURN_CODE ret = 0;

    if(_current_service_list_buffer_end_as_offset + sizeof(dab_service_list_element) <= DAB_SERVICE_LIST__MAX_OFFSET)
    {
        //Sufficient space in the buffer go ahead and add.
		ret = write_storage__command(_current_service_list_buffer_end_as_offset, sizeof(dab_service_list_element), (uint8_t*)elementToAdd);

		if(ret == SUCCESS)
		{
			_current_service_list_buffer_end_as_offset += sizeof(dab_service_list_element);
		}
    }
    else
    {
        return INVALID_INPUT;
    }

	return ret;
}

void _error_in_list(uint16_t listVer)
{
    DAB_service_list_updated_for_current_freq = 1;
    _currentListVersion = listVer;
    CALLBACK_Updated_Data(SERVICE_LIST_BUFFER_FULL_ERROR);
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void updateDAB_ServiceList(get_digital_service_list__data* dabList, uint16_t listVer)
{
    RETURN_CODE ret = 0;
#ifdef OPTION__DAB_SUPPORT_DAB_DAB_LINKING
    uint8_t initLoop;
#endif
    uint16_t slAddr = 0; //Current Service List Addr in the current buffer - note this may be broken up and reset
    uint8_t serviceLoop = 0;
    uint8_t serviceNum = 0;
    uint8_t componentLoop = 0;
    uint8_t componentNum = 0;
    uint16_t tempBufferEnd;
    uint8_t firstService = 0;
    //Variables for confirming playing service is present in updated list
    uint32_t currentServiceID = 0;
    uint16_t currentComponentID = 0;
    uint8_t currentServiceIndex = 0;
    uint8_t initialServiceCount = 0;
    uint8_t tempNumComponents = 0;

    dab_service_list_element tempElement;
    dab_get_component_info__data dgci;
    uint8_t ensembleOffsetIndex;


    if((listVer == _currentListVersion) && (_currentListVersion != DAB_LIST_VERSION_UNKNOWN))
    {
        //we have no need to process the list - it is the same list we already have
        return;
    }

    CALLBACK_Updated_Data(DAB_SERVICE_LIST_REQUIRED_UPDATE);

#ifdef OPTION__DAB_PRESETS_AS_FAVORITES
    favoriteServicesShifted = 0;
#endif //OPTION__DAB_PRESETS_AS_FAVORITES

    //Check if we need to replace any existing ensembles
    ret = findEnsembleInList(MetricsGetDABPtr()->FREQUENCY_INDEX, &ensembleOffsetIndex);
    if(ret == SUCCESS)
    {
        // We found the current index in our list - need to remove its entries and repack
        ret = _repack_stored_dab_list(ensembleOffsetIndex);
        
        if(ret != SUCCESS)
            {
                _error_in_list(listVer);
                return;
            }
    }


    initialServiceCount = svcListDAB.SERVICE_COUNT;

    //By reading from the si46xx internal memory - we have thrown away the service list buffer - need to re-read
    ret |= get_digital_service_list__command(0); // DAB only has one type of list
    ret |= get_digital_service_list__reply(0,dabList);

    if(dabList->TOTAL_SIZE > 0)
    {
        // the service list fit into a single transaction, easier processing logic here
        serviceNum = dabList->PAYLOAD[slAddr+DAB_SERVICE_LIST_NUM_SERVICES__OFFSET];
        slAddr += DAB_SERVICE_LIST_ELEMENT_START__OFFSET;

        //Initialize the Linking Info items in the temp element, will be the same for all items in the list
        tempElement.ENSEMBLE_ID = MetricsGetDABPtr()->EID;

#ifdef OPTION__DAB_SUPPORT_DAB_DAB_LINKING
        for(initLoop = 0; initLoop < DAB_SERVICE_LIST__MAX_NUMBER_OF_LINKED_FREQUENCIES; initLoop ++)
        {
            tempElement.FREQUENCY_INDEXES_LINKED[initLoop] = DAB_SERVICE_LIST__LINKED_INDEX_DEFAULT;
        }
#endif

        for(serviceLoop = 0; serviceLoop < serviceNum; serviceLoop ++)
        {
            componentNum = 0;
            ret = realign_service_list_buffer(&slAddr,dabList,DAB_SERVICE_LIST_SERVICE_DATA__LENGTH);
            // If error we can't proceed
            if(ret != SUCCESS)
            {
                _error_in_list(listVer);
                return;
            }

            // Need to assign the number of components to know how much to skip if not audio
            tempNumComponents = (dabList->PAYLOAD[slAddr+DAB_SERVICE_LIST_SERVICE_INFO2__OFFSET] & DAB_SERVICE_LIST_SERVICE_INFO2__NUM_COMP_MASK);

            //Check if this is an audio service
            if((dabList->PAYLOAD[slAddr+DAB_SERVICE_LIST_SERVICE_INFO1__OFFSET] & DAB_SERVICE_LIST_SERVICE_INFO1__PDFLAG_MASK) == DAB_SERVICE_LIST_SERVICE_INFO1__PDFLAG_AUDIO)
            {
                //set the frequency index from the current metrics - also set during tune
                tempElement.FREQUENCY_INDEX = MetricsGetDABPtr()->FREQUENCY_INDEX;

                tempElement.SERVICE_ID = _recover_32bit_from_little_endian_buffer(&dabList->PAYLOAD[slAddr+DAB_SERVICE_LIST_SERVICE_ID__OFFSET]);
                
                tempElement.SERVICE_PTY = ((dabList->PAYLOAD[slAddr+DAB_SERVICE_LIST_SERVICE_INFO1__OFFSET] & DAB_SERVICE_LIST_SERVICE_INFO1__PTY_MASK) >> DAB_SERVICE_LIST_SERVICE_INFO1__PTY_SHIFT);

                //Hold the service label in seperate memory for later deciding to use component label or not
                tempElement.SERVICE_NAME_ENCODING = (dabList->PAYLOAD[slAddr+DAB_SERVICE_LIST_SERVICE_INFO3__OFFSET] & DAB_SERVICE_LIST_SERVICE_INFO3__SICHARSET_MASK);
                CpyMemory(tempElement.SERVICE_NAME, &dabList->PAYLOAD[slAddr+DAB_SERVICE_LIST_SERVICE_LABEL__OFFSET], DAB_SERVICE_LIST_SERVICE_LABEL__SIZE);

                //Increment the buffer address after reading service info
                slAddr += DAB_SERVICE_LIST_SERVICE_DATA__LENGTH;

                ret = realign_service_list_buffer(&slAddr, dabList,tempNumComponents * DAB_COMPONENT_LIST_COMPONENT_DATA__LENGTH);
                // If error we can't proceed
                if(ret != SUCCESS)
                {
                    _error_in_list(listVer);
                    return;
                }                

                
                for(componentLoop = 0; componentLoop < tempNumComponents; componentLoop++)
                {
                    tempElement.COMPONENT_ID = _recover_16bit_from_little_endian_buffer(&dabList->PAYLOAD[slAddr+DAB_COMPONENT_LIST_COMPONENT_ID__OFFSET]);
                    if(((tempElement.COMPONENT_ID & DAB_COMPONENT_LIST_COMPONENT_ID__TMID_MASK) == 0) &&
                        ((dabList->PAYLOAD[slAddr+DAB_COMPONENT_LIST_COMPONENT_INFO__OFFSET] & DAB_COMPONENT_LIST_COMPONENT_INFO__CAFLAG_MASK) == 0))
                    {
                        
                        //This is an audio component without conditional access - add it to the list.
                        tempBufferEnd = _current_service_list_buffer_end_as_offset;

                        if(svcListDAB.SERVICE_COUNT < DAB_SERVICE_LIST__MAX_SERVICES)
                        {
                            //Write the service info to the service list
                            if(_add_data_to_buffer(&tempElement) != SUCCESS)
                            {
                                _error_in_list(listVer);
                                return; // Stop processing we're out of space
                            }
                            else
                            {
                                //Service sucessfully added - increment the service count
                                svcListDAB.SERVICE_OFFSETS[svcListDAB.SERVICE_COUNT] = tempBufferEnd;
                                svcListDAB.SERVICE_NAME_CHAR0[svcListDAB.SERVICE_COUNT] = _convert_ASCII_upper(tempElement.SERVICE_NAME[0]);

                                svcListDAB.SERVICE_COUNT++;

                                if(firstService == 0)
                                {
    						        svcListDAB.ENSEMBLE_OFFSETS[svcListDAB.ENSEMBLE_COUNT] = tempBufferEnd;
                                    svcListDAB.ENSEMBLE_COUNT ++;
                                    firstService = 1;
                                }
                            }
                        }
                        else
                        {
                            CALLBACK_Updated_Data(SERVICE_LIST_BUFFER_FULL_ERROR);
                        }
                    }

                    slAddr += DAB_COMPONENT_LIST_COMPONENT_DATA__LENGTH;
                }
            }
            else
            {
                slAddr += DAB_SERVICE_LIST_SERVICE_DATA__LENGTH + (DAB_COMPONENT_LIST_COMPONENT_DATA__LENGTH * tempNumComponents);
            }
        }

        if(ret == SUCCESS)
        {
            //Replace all the service labels with the component labels
            for(componentLoop = initialServiceCount; componentLoop < svcListDAB.SERVICE_COUNT; componentLoop++)
            {
                ret = getServiceListElement(svcListDAB.SERVICE_OFFSETS[componentLoop], &tempElement);

                //DRUK indicates the component info is preferred over service info if present
			    ret |= dab_get_component_info__command(tempElement.SERVICE_ID,tempElement.COMPONENT_ID);
			    ret |= dab_get_component_info__reply(&dgci);

			    if((ret == SUCCESS) && (dgci.LABEL[0] != 0))
			    {
                    ClearMemory(tempElement.SERVICE_NAME,DAB_SERVICE_LIST_SERVICE_LABEL__SIZE);
				    CpyMemory(tempElement.SERVICE_NAME,dgci.LABEL,dgci.LABEL_LENGTH);
                    tempElement.SERVICE_NAME_ENCODING = dgci.CHARSETID;

                    ret = write_storage__command(svcListDAB.SERVICE_OFFSETS[componentLoop],sizeof(dab_service_list_element),(uint8_t*)&tempElement);

                    svcListDAB.SERVICE_NAME_CHAR0[componentLoop] = _convert_ASCII_upper(tempElement.SERVICE_NAME[0]);
			    }
            }

            //We updated the list so we should keep track of this version to avoid reprocessing it
            DAB_service_list_updated_for_current_freq = 1;
            _currentListVersion = listVer;

            //Sort the list
            svcListDAB.ENSEMBLE_OFFSETS[svcListDAB.ENSEMBLE_COUNT] = _current_service_list_buffer_end_as_offset;
            ret |= _insertion_sort_alphabetical_list(initialServiceCount);

            //Tell the MMI we have a new service list with the new list
            CALLBACK_Updated_Data(UPDATED_SERVICE_LIST_DAB);
        }
    }
}

#else
void updateDAB_ServiceList(get_digital_service_list__data* dabList, uint16_t listVer)
{
    //Not implemented - Stub
    return;
}

#endif //OPTION__SERVICE_LIST_SMALL

#endif // OPTION__DECODE_DAB_SERVICE_LIST
#endif // OPTION__INCLUDE_MODE__DAB