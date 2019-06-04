/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   firmware api definition for si468x command/property interface
   FILE: si46xx_firmware_api.c
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#include "si46xx_firmware_api_constants.h"
#include "si46xx_firmware_api.h"
#include "HAL.h"
#include "common_types.h"
#include "feature_types.h"

uint8_t lastCommand = 0;
uint8_t lastSertype;

uint32_t	cmd_arg_u32[CMD_BUFFER_LENGTH/4];
uint16_t*	cmd_arg_u16 = (uint16_t*)cmd_arg_u32;
uint8_t*	cmd_arg = (uint8_t*)cmd_arg_u32;

uint32_t	reply_buffer_u32[RPY_BUFFER_LENGTH/4];
uint16_t*	reply_buffer_u16 = (uint16_t*)reply_buffer_u32;
int16_t* reply_buffer_i16 = (int16_t*)reply_buffer_u32;
uint8_t*	reply_buffer = (uint8_t*)reply_buffer_u32;


#ifdef OPTION__CONVERT_BIG_ENDIAN
void _swap_16 (uint16_t *pValue)
{
    uint16_t temp = *pValue;

    ((uint8_t *)pValue)[0] = ((uint8_t *)&temp)[1];
    ((uint8_t *)pValue)[1] = ((uint8_t *)&temp)[0];
}

void _swap_32 (uint32_t *pValue)
{
    uint32_t temp = *pValue;

    ((uint8_t *)pValue)[0] = ((uint8_t *)&temp)[3];
    ((uint8_t *)pValue)[1] = ((uint8_t *)&temp)[2];
    ((uint8_t *)pValue)[2] = ((uint8_t *)&temp)[1];
    ((uint8_t *)pValue)[3] = ((uint8_t *)&temp)[0];
}
#endif

#ifdef OPTION__INCLUDE_MODE__ANY
uint32_t _recover_32bit_from_little_endian_buffer(uint8_t* buffer)
{
    uint32_t dummy = *(uint32_t*)buffer;

    #ifdef OPTION__CONVERT_BIG_ENDIAN
        _swap_32(&dummy);
    #endif

    return dummy;
}
#endif //OPTION__INCLUDE_MODE__ANY

uint16_t _recover_16bit_from_little_endian_buffer(uint8_t* buffer)
{
    uint16_t dummy = *(uint16_t*)buffer;

    #ifdef OPTION__CONVERT_BIG_ENDIAN
        _swap_16(&dummy);
    #endif

    return dummy;
}

#ifdef OPTION__INCLUDE_MODE__ANY
RETURN_CODE read_status(status_bits* status)
{
	RETURN_CODE ret = 0;

	ret = readReply(4,reply_buffer);

	if(ret == SUCCESS)
	{
		status->CTS = CMD_RD_REPLY_REP_CTS_is_true;
		status->ERR_CMD = CMD_RD_REPLY_REP_ERR_CMD_is_true;
		status->DACQINT = CMD_RD_REPLY_REP_DACQINT_is_true;
		status->DSRVINT = CMD_RD_REPLY_REP_DSRVINT_is_true;
		status->RSQINT = CMD_RD_REPLY_REP_RSQINT_is_true;
		status->RDSINT = CMD_RD_REPLY_REP_RDSINT_is_true;
		status->ACFINT = CMD_RD_REPLY_REP_ACFINT_is_true;
		status->STCINT = CMD_RD_REPLY_REP_STCINT_is_true;
		//status->DBGINT = CMD_RD_REPLY_REP_DBGINT_is_true;
        status->DEVNTINT = CMD_RD_REPLY_REP_DEVNTINT_is_true;
	}

	return ret;
}
#endif // OPTION__INCLUDE_MODE__ANY

RETURN_CODE power_up__command(uint8_t ctsien, uint8_t clk_mode, uint8_t tr_size, uint8_t ibias, uint32_t xtal_freq, uint8_t ctun, uint8_t ibias_run, uint8_t usingROM00)
{
	RETURN_CODE ret = 0;

	ClearMemory(cmd_arg, CMD_POWER_UP_LENGTH);

	cmd_arg[0] = CMD_POWER_UP;
	CMD_POWER_UP_ARG_CTSIEN_write_field(ctsien);
	CMD_POWER_UP_ARG_CLK_MODE_write_field(clk_mode);
	CMD_POWER_UP_ARG_TR_SIZE_write_field(tr_size);
	CMD_POWER_UP_ARG_IBIAS_write_field(ibias);
	CMD_POWER_UP_ARG_XTAL_FREQ_write_u32(xtal_freq);
    
    #ifdef OPTION__CONVERT_BIG_ENDIAN
        _swap_32((uint32_t *)&cmd_arg[CMD_POWER_UP_ARG_XTAL_FREQ_INDEX]);
    #endif


	CMD_POWER_UP_ARG_CTUN_write_field(ctun);
	CMD_POWER_UP_ARG_IBIAS_RUN_write_field(ibias_run);

	//This is only applicable for rom00 parts
    if(usingROM00 > 0)
    {
    	cmd_arg[9] = 0x10;	// Non-zero forced byte, not included in constants.
    }

	ret = writeCommand(CMD_POWER_UP_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_POWER_UP;
	}

	return ret;
}


RETURN_CODE host_load__command(uint16_t segmentLength, uint8_t *imageSegment)
{
	RETURN_CODE ret = 0;

	if(segmentLength > (CMD_BUFFER_LENGTH - CMD_HOST_LOAD_ARG_IMAGE_DATA0_INDEX))
	{
		return INVALID_INPUT;
	}

	ClearMemory(cmd_arg, CMD_HOST_LOAD_ARG_IMAGE_DATA0_INDEX);

	cmd_arg[0] = CMD_HOST_LOAD;

	CpyMemory(&cmd_arg[CMD_HOST_LOAD_ARG_IMAGE_DATA0_INDEX], imageSegment, segmentLength);

	ret = writeCommand((segmentLength + CMD_HOST_LOAD_ARG_IMAGE_DATA0_INDEX), cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_HOST_LOAD;
	}

	return ret;
}

RETURN_CODE flash_load__command(uint32_t start_addr)
{
	RETURN_CODE ret = 0;

	ClearMemory(cmd_arg, CMD_FLASH_LOAD_LENGTH);

	cmd_arg[0] = CMD_FLASH_LOAD;
	CMD_FLASH_LOAD_ARG_FLASH_START_ADDR_write_u32(start_addr);

    #ifdef OPTION__CONVERT_BIG_ENDIAN
        _swap_32((uint32_t *)&cmd_arg[CMD_FLASH_LOAD_ARG_FLASH_START_ADDR_INDEX]);
    #endif

	ret = writeCommand(CMD_FLASH_LOAD_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_FLASH_LOAD;
	}

	return ret;
}

RETURN_CODE load_init__command(void)
{
	RETURN_CODE ret = 0;

	ClearMemory(cmd_arg, CMD_LOAD_INIT_LENGTH);

	cmd_arg[0] = CMD_LOAD_INIT;

	ret = writeCommand(CMD_LOAD_INIT_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_LOAD_INIT;
	}

	return ret;
}

RETURN_CODE boot__command(void)
{
	RETURN_CODE ret = 0;

	ClearMemory(cmd_arg, CMD_BOOT_LENGTH);

	cmd_arg[0] = CMD_BOOT;

	ret = writeCommand(CMD_BOOT_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_BOOT;
	}

	return ret;
}

#ifdef OPTION__INCLUDE_MODE__ANY
RETURN_CODE read_offset__command(uint16_t offset)
{
    RETURN_CODE ret = 0;

    ClearMemory(cmd_arg, CMD_READ_OFFSET_LENGTH);

    cmd_arg[0] = CMD_READ_OFFSET;
    CMD_READ_OFFSET_ARG_OFFSET_write_u16(offset);

    #ifdef OPTION__CONVERT_BIG_ENDIAN
        _swap_16((uint16_t *)&cmd_arg[CMD_READ_OFFSET_ARG_OFFSET_INDEX]);
    #endif

    ret = writeCommand(CMD_READ_OFFSET_LENGTH, cmd_arg);

    if(ret == SUCCESS)
    {
        lastCommand = CMD_READ_OFFSET;
    }

    return ret;
}
#endif

RETURN_CODE get_part_info__command(void)
{
	RETURN_CODE ret = 0;

	ClearMemory(cmd_arg, CMD_GET_PART_INFO_LENGTH);

	cmd_arg[0] = CMD_GET_PART_INFO;

	ret = writeCommand(CMD_GET_PART_INFO_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_GET_PART_INFO;
	}

	return ret;
}

RETURN_CODE get_part_info__reply(get_part_info__data* replyData)
{
	RETURN_CODE ret = 0;

	ret = readReply(CMD_GET_PART_INFO_REP_LENGTH,reply_buffer);

	if((ret == SUCCESS) && (lastCommand == CMD_GET_PART_INFO))
	{
		replyData->CHIPREV = CMD_GET_PART_INFO_REP_CHIPREV_value;
		replyData->ROMID = CMD_GET_PART_INFO_REP_ROMID_value;
		replyData->PART = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_GET_PART_INFO_REP_PART_value);
	}
    else
    {
        ret = COMMAND_ERROR;
    }

	return ret;
}


#ifdef OPTION__INCLUDE_MODE__ANY
RETURN_CODE get_sys_state__command(void)
{
	RETURN_CODE ret = 0;

	ClearMemory(cmd_arg, CMD_GET_SYS_STATE_LENGTH);

	cmd_arg[0] = CMD_GET_SYS_STATE;

	ret = writeCommand(CMD_GET_SYS_STATE_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_GET_SYS_STATE;
	}

	return ret;
}

RETURN_CODE get_sys_state__reply(get_sys_state__data* replyData)
{
	RETURN_CODE ret = 0;

	ret = readReply(CMD_GET_SYS_STATE_REP_LENGTH,reply_buffer);

	if((ret == SUCCESS) && (lastCommand == CMD_GET_SYS_STATE))
	{
		replyData->image = CMD_GET_SYS_STATE_REP_IMAGE_value;
	}
    else
    {
        ret = COMMAND_ERROR;
    }

	return ret;
}
#endif //OPTION__INCLUDE_MODE__ANY

#ifndef OPTION__REMOVE_FIRMWARE_FUNCTIONS_NOT_USED_SMALL_SDK
RETURN_CODE get_power_up_args__command(void)
{
	RETURN_CODE ret = 0;

	ClearMemory(cmd_arg, CMD_GET_POWER_UP_ARGS_LENGTH);

	cmd_arg[0] = CMD_GET_POWER_UP_ARGS;

	ret = writeCommand(CMD_GET_POWER_UP_ARGS_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_GET_POWER_UP_ARGS;
	}

	return ret;
}

RETURN_CODE get_power_up_args__reply(get_power_up_args__data* replyData)
{
	RETURN_CODE ret = 0;

	ret = readReply(CMD_GET_POWER_UP_ARGS_REP_LENGTH,reply_buffer);

	if((ret == SUCCESS) && (lastCommand == CMD_GET_POWER_UP_ARGS))
	{
		replyData->CLK_MODE = CMD_GET_POWER_UP_ARGS_REP_CLK_MODE_value;
		replyData->TR_SIZE = CMD_GET_POWER_UP_ARGS_REP_TR_SIZE_value;
		replyData->IBIAS = CMD_GET_POWER_UP_ARGS_REP_IBIAS_value;
		replyData->XTAL_FREQ = _recover_32bit_from_little_endian_buffer((uint8_t*)&CMD_GET_POWER_UP_ARGS_REP_XTAL_FREQ_value);
		replyData->CTUN = CMD_GET_POWER_UP_ARGS_REP_CTUN_value;
		replyData->IBIAS_RUN = CMD_GET_POWER_UP_ARGS_REP_IBIAS_RUN_value;
	}
    else
    {
        ret = COMMAND_ERROR;
    }

	return ret;
}
#endif


#ifndef OPTION__REMOVE_FIRMWARE_FUNCTIONS_NOT_USED_SMALL_SDK
RETURN_CODE get_func_info__command(void)
{
	RETURN_CODE ret = 0;

	ClearMemory(cmd_arg, CMD_GET_FUNC_INFO_LENGTH);

	cmd_arg[0] = CMD_GET_FUNC_INFO;

	ret = writeCommand(CMD_GET_FUNC_INFO_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_GET_FUNC_INFO;
	}

	return ret;
}

RETURN_CODE get_func_info__reply(get_func_info__data* replyData)
{
	RETURN_CODE ret = 0;

	ret = readReply(CMD_GET_FUNC_INFO_REP_LENGTH,reply_buffer);

	if((ret == SUCCESS) && (lastCommand == CMD_GET_FUNC_INFO))
	{
		replyData->REVEXT = CMD_GET_FUNC_INFO_REP_REVEXT_value;
		replyData->REVBRANCH = CMD_GET_FUNC_INFO_REP_REVBRANCH_value;
		replyData->REVINT = CMD_GET_FUNC_INFO_REP_REVINT_value;
		replyData->NOSVN = CMD_GET_FUNC_INFO_REP_NOSVN_value;
		replyData->LOCATION = CMD_GET_FUNC_INFO_REP_LOCATION_value;
		replyData->MIXEDREV = CMD_GET_FUNC_INFO_REP_MIXEDREV_value;
		replyData->LOCALMOD = CMD_GET_FUNC_INFO_REP_LOCALMOD_value;
		replyData->SVNID = _recover_32bit_from_little_endian_buffer((uint8_t*)&CMD_GET_FUNC_INFO_REP_SVNID_value);
	}
    else
    {
        ret = COMMAND_ERROR;
    }

	return ret;
}
#endif


RETURN_CODE set_property__command(uint16_t propid, uint16_t value)
{
	RETURN_CODE ret = 0;

	ClearMemory(cmd_arg, CMD_SET_PROPERTY_LENGTH);

	cmd_arg[0] = CMD_SET_PROPERTY;
	CMD_SET_PROPERTY_ARG_PROPID_write_u16(propid);

    #ifdef OPTION__CONVERT_BIG_ENDIAN
        _swap_16((uint16_t *)&cmd_arg[CMD_SET_PROPERTY_ARG_PROPID_INDEX]);
    #endif

	CMD_SET_PROPERTY_ARG_DATA0_write_u16(value);

    #ifdef OPTION__CONVERT_BIG_ENDIAN
        _swap_16((uint16_t *)&cmd_arg[CMD_SET_PROPERTY_ARG_DATA0_INDEX]);
    #endif

	ret = writeCommand(CMD_SET_PROPERTY_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_SET_PROPERTY;
	}

	return ret;
}

#ifdef OPTION__INCLUDE_MODE__ANY
//For simplicity, only one property is read at a time - though block reading is supported if desired: see programming guide
RETURN_CODE get_property__command(uint16_t propid)
{
	RETURN_CODE ret = 0;

	ClearMemory(cmd_arg, CMD_GET_PROPERTY_LENGTH);

	cmd_arg[0] = CMD_GET_PROPERTY;
	CMD_GET_PROPERTY_ARG_COUNT_write_u8(1);
	CMD_GET_PROPERTY_ARG_PROPID_write_u16(propid);

    #ifdef OPTION__CONVERT_BIG_ENDIAN
        _swap_16((uint16_t *)&cmd_arg[CMD_GET_PROPERTY_ARG_PROPID_INDEX]);
    #endif

	ret = writeCommand(CMD_GET_PROPERTY_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_GET_PROPERTY;
	}

	return ret;
}

//Note: this function assumes only one property is being read
RETURN_CODE get_property__reply(uint16_t* value)
{
	RETURN_CODE ret = 0;

	ret = readReply(CMD_GET_PROPERTY_REP_LENGTH,reply_buffer);

	if((ret == SUCCESS) && (lastCommand == CMD_GET_PROPERTY))
	{
		*value = CMD_GET_PROPERTY_REP_DATA0_value;

        #ifdef OPTION__CONVERT_BIG_ENDIAN
            _swap_16((uint16_t *)value);
        #endif
	}
    else
    {
        ret = COMMAND_ERROR;
    }

	return ret;
}
#endif // OPTION__INCLUDE_MODE__ANY

#ifdef OPTION__INCLUDE_MODE__DAB
RETURN_CODE write_storage__command(uint16_t offset, uint16_t length, uint8_t* buffer)
{
	RETURN_CODE ret = 0;
	uint16_t manualWriteLength;

	ClearMemory(cmd_arg, CMD_WRITE_STORAGE_LENGTH);

	cmd_arg[0] = CMD_WRITE_STORAGE;
	CMD_WRITE_STORAGE_ARG_OFFSET_write_u16(offset);
	CMD_WRITE_STORAGE_ARG_LENGTH_write_u16(length);

	#ifdef OPTION__CONVERT_BIG_ENDIAN
        _swap_16((uint16_t *)&cmd_arg[CMD_WRITE_STORAGE_ARG_OFFSET_INDEX]);
		_swap_16((uint16_t *)&cmd_arg[CMD_WRITE_STORAGE_ARG_LENGTH_INDEX]);
    #endif

	CpyMemory(&cmd_arg[CMD_WRITE_STORAGE_ARG_DATA0_INDEX],(uint8_t *)buffer, length);

	//Need to manually control the length given the undefined input length
	manualWriteLength = (CMD_WRITE_STORAGE_ARG_DATA0_INDEX + length);

	ret = writeCommand(manualWriteLength, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_WRITE_STORAGE;
	}

	return ret;
}

RETURN_CODE read_storage__command(uint16_t offset)
{
	RETURN_CODE ret = 0;

	ClearMemory(cmd_arg, CMD_READ_STORAGE_LENGTH);

	cmd_arg[0] = CMD_READ_STORAGE;
	CMD_READ_STORAGE_ARG_OFFSET_write_u16(offset);

	#ifdef OPTION__CONVERT_BIG_ENDIAN
        _swap_16((uint16_t *)&cmd_arg[CMD_READ_STORAGE_ARG_OFFSET_INDEX]);
	#endif

	ret = writeCommand(CMD_READ_STORAGE_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_READ_STORAGE;
	}

	return ret;
}

RETURN_CODE read_storage__reply(uint16_t length, uint8_t* replyDataPtr)
{
	RETURN_CODE ret = 0;

	if((CMD_READ_STORAGE_REP_DATA0_INDEX + length) > RPY_BUFFER_LENGTH)
	{
		// we could potentially make this more robust to allow larger than the buffer reads, but currently unnecessary due to expected usage (service list)
		ClearMemory(replyDataPtr, length);
		return INVALID_INPUT;
	}

	ret = readReply((CMD_READ_STORAGE_REP_DATA0_INDEX + length), reply_buffer);

	if((ret == SUCCESS) && (lastCommand == CMD_READ_STORAGE))
	{
		CpyMemory(replyDataPtr, &reply_buffer[CMD_READ_STORAGE_REP_DATA0_INDEX], length);
	}
	else
	{
		ClearMemory(replyDataPtr, length);
        ret = COMMAND_ERROR;
	}

	return ret;
}
#endif //OPTION__INCLUDE_MODE__DAB

#ifdef OPTION__INCLUDE_MODE__ANY
RETURN_CODE get_digital_service_list__command(uint8_t sertype)
{
	RETURN_CODE ret = 0;

	ClearMemory(cmd_arg, CMD_GET_DIGITAL_SERVICE_LIST_LENGTH);

	cmd_arg[0] = CMD_GET_DIGITAL_SERVICE_LIST;
	CMD_GET_DIGITAL_SERVICE_LIST_ARG_SERTYPE_write_field(sertype);

	ret = writeCommand(CMD_GET_DIGITAL_SERVICE_LIST_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
        lastSertype = sertype;
		lastCommand = CMD_GET_DIGITAL_SERVICE_LIST;
	}

	return ret;
}


RETURN_CODE get_digital_service_list__reply(uint16_t read_offset_index, get_digital_service_list__data* replyData)
{
	RETURN_CODE ret = 0;
    uint16_t manualReadLength;

    if(lastCommand != CMD_GET_DIGITAL_SERVICE_LIST)
    {
        get_digital_service_list__command(lastSertype);
    }

    if(read_offset_index == 0) // First time calling the read reply function
	{
        ret = readReply(CMD_GET_DIGITAL_SERVICE_LIST_REP_DATA_0_INDEX,reply_buffer);
    
	    if((ret == SUCCESS) && (lastCommand == CMD_GET_DIGITAL_SERVICE_LIST))
	    {
		    replyData->TOTAL_SIZE = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_GET_DIGITAL_SERVICE_LIST_REP_SIZE_value);
            //Move the processed address past the Size
            replyData->PROCESSED_ADDR = (CMD_GET_DIGITAL_SERVICE_LIST_REP_DATA_0_INDEX - CMD_GET_DIGITAL_SERVICE_LIST_REP_SIZE_INDEX);

		    //Create a null pointer to the payload until we have read it.
		    replyData->PAYLOAD = 0;
        }
        else
        {
            replyData->TOTAL_SIZE = 0;
            ret = COMMAND_ERROR;
        }
    }

	if(replyData->TOTAL_SIZE > 0)
	{
        if((CMD_GET_DIGITAL_SERVICE_LIST_REP_DATA_0_INDEX + replyData->TOTAL_SIZE) > RPY_BUFFER_LENGTH)
        {
            // Our buffer is too small - check if this is the first read or
            if(read_offset_index == 0)
            {
                // Read the full buffer size
                ret = readReply(RPY_BUFFER_LENGTH,reply_buffer);

                if(ret == SUCCESS)
                {
                    replyData->PAYLOAD = &CMD_GET_DIGITAL_SERVICE_LIST_REP_DATA_0_value;
                    replyData->READ_SIZE = RPY_BUFFER_LENGTH - CMD_GET_DIGITAL_SERVICE_LIST_REP_DATA_0_INDEX;
                }
            }
            // Our buffer is too small - we're reading a second segment into the buffer
            else
            {
                //read_offset requires % 4
                if((read_offset_index % 4) != 0)
                {
                    return INVALID_INPUT;
                }

                ret = read_offset__command(read_offset_index);

                manualReadLength = (replyData->TOTAL_SIZE - read_offset_index + CMD_READ_OFFSET_REP_DATA0_INDEX);

                if(manualReadLength < RPY_BUFFER_LENGTH)
                {
                    //Remaining size will fit in the buffer - only read what is remaining
                    ret |= readReply(manualReadLength,reply_buffer);
                }
                else
                {
                    ret |= readReply(RPY_BUFFER_LENGTH,reply_buffer);
                    manualReadLength = RPY_BUFFER_LENGTH - CMD_READ_OFFSET_REP_DATA0_INDEX;
                }

                if(ret == SUCCESS)
                {
                    replyData->PAYLOAD = &CMD_READ_OFFSET_REP_DATA0_value;
                    replyData->READ_SIZE = manualReadLength - CMD_READ_OFFSET_REP_DATA0_INDEX;
                }
            }
        }
        else
        {
		    // Re-read the reply with the full length of header + payload.
		    ret = readReply(CMD_GET_DIGITAL_SERVICE_LIST_REP_DATA_0_INDEX + replyData->TOTAL_SIZE,reply_buffer);
		    if(ret == SUCCESS)
		    {
			    //Set the pointer to the address in the buffer for the payload data.
			    replyData->PAYLOAD = &CMD_GET_DIGITAL_SERVICE_LIST_REP_DATA_0_value;
                replyData->READ_SIZE = replyData->TOTAL_SIZE;
		    }
        }
	}

	return ret;
}

RETURN_CODE realign_service_list_buffer(uint16_t *payloadAddr, get_digital_service_list__data *serviceList, uint16_t nextItemLength)
{
    RETURN_CODE ret = 0;

    //We need to realign the buffer to the next segment
    if(((*payloadAddr + nextItemLength) > serviceList->READ_SIZE) && (serviceList->READ_SIZE != serviceList->TOTAL_SIZE))
    {
        serviceList->PROCESSED_ADDR = serviceList->PROCESSED_ADDR + *payloadAddr;

        *payloadAddr = 0;
        while((serviceList->PROCESSED_ADDR % 4) != 0)
        {
            serviceList->PROCESSED_ADDR = serviceList->PROCESSED_ADDR - 1;
            *payloadAddr = *payloadAddr + 1;
        }
        
        ret = get_digital_service_list__reply(serviceList->PROCESSED_ADDR,serviceList);
    }

    return ret;
}

RETURN_CODE start_digital_service__command(uint8_t sertype, uint32_t service_id, uint32_t comp_id)
{
	RETURN_CODE ret = 0;

	ClearMemory(cmd_arg, CMD_START_DIGITAL_SERVICE_LENGTH);

	cmd_arg[0] = CMD_START_DIGITAL_SERVICE;
	CMD_START_DIGITAL_SERVICE_ARG_SERTYPE_write_field(sertype);
	CMD_START_DIGITAL_SERVICE_ARG_SERVICE_ID_write_u32(service_id);

    #ifdef OPTION__CONVERT_BIG_ENDIAN
        _swap_32((uint32_t *)&cmd_arg[CMD_START_DIGITAL_SERVICE_ARG_SERVICE_ID_INDEX]);
    #endif

	CMD_START_DIGITAL_SERVICE_ARG_COMP_ID_write_u32(comp_id);

    #ifdef OPTION__CONVERT_BIG_ENDIAN
        _swap_32((uint32_t *)&cmd_arg[CMD_START_DIGITAL_SERVICE_ARG_COMP_ID_INDEX]);
    #endif

	ret = writeCommand(CMD_START_DIGITAL_SERVICE_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_START_DIGITAL_SERVICE;
	}

	return ret;
}
#endif

#ifndef OPTION__REMOVE_SDK_FUNCTIONS_NOT_USED_BY_MMI
RETURN_CODE stop_digital_service__command(uint8_t sertype, uint32_t service_id, uint32_t comp_id)
{
	RETURN_CODE ret = 0;

	ClearMemory(cmd_arg, CMD_STOP_DIGITAL_SERVICE_LENGTH);

	cmd_arg[0] = CMD_STOP_DIGITAL_SERVICE;
	CMD_STOP_DIGITAL_SERVICE_ARG_SERTYPE_write_field(sertype);
	CMD_STOP_DIGITAL_SERVICE_ARG_SERVICE_ID_write_u32(service_id);

    #ifdef OPTION__CONVERT_BIG_ENDIAN
        _swap_32((uint32_t *)&cmd_arg[CMD_STOP_DIGITAL_SERVICE_ARG_SERVICE_ID_INDEX]);
    #endif

	CMD_STOP_DIGITAL_SERVICE_ARG_COMP_ID_write_u32(comp_id);

    #ifdef OPTION__CONVERT_BIG_ENDIAN
        _swap_32((uint32_t *)&cmd_arg[CMD_STOP_DIGITAL_SERVICE_ARG_COMP_ID_INDEX]);
    #endif

	ret = writeCommand(CMD_STOP_DIGITAL_SERVICE_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_STOP_DIGITAL_SERVICE;
	}

	return ret;
}
#endif //OPTION__REMOVE_SDK_FUNCTIONS_NOT_USED_BY_MMI

#ifdef OPTION__INCLUDE_MODE__ANY
RETURN_CODE get_digital_service_data__command(uint8_t status_only, uint8_t ack)
{
	RETURN_CODE ret = 0;

	ClearMemory(cmd_arg, CMD_GET_DIGITAL_SERVICE_DATA_LENGTH);

	cmd_arg[0] = CMD_GET_DIGITAL_SERVICE_DATA;
	CMD_GET_DIGITAL_SERVICE_DATA_ARG_STATUS_ONLY_write_field(status_only);
	CMD_GET_DIGITAL_SERVICE_DATA_ARG_ACK_write_field(ack);

	ret = writeCommand(CMD_GET_DIGITAL_SERVICE_DATA_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_GET_DIGITAL_SERVICE_DATA;
	}

	return ret;
}

RETURN_CODE get_digital_service_data__reply(get_digital_service_data__data* replyData)
{
	RETURN_CODE ret = 0;

	ret = readReply(CMD_GET_DIGITAL_SERVICE_DATA_REP_PAYLOAD0_INDEX,reply_buffer);

	if((ret == SUCCESS) && (lastCommand == CMD_GET_DIGITAL_SERVICE_DATA))
	{
        #ifndef OPTION__MINIMAL_FIRMWARE_FUNCTION_IMPLEMENTATION_SMALLER_SDK
            replyData->DSRVOVFLINT = CMD_GET_DIGITAL_SERVICE_DATA_REP_DSRVOVFLINT_value;
		    replyData->DSRVPCKTINT = CMD_GET_DIGITAL_SERVICE_DATA_REP_DSRVPCKTINT_value;
            //replyData->DATA_TYPE = CMD_GET_DIGITAL_SERVICE_DATA_REP_DATA_TYPE_value;
            replyData->DSCTY = CMD_GET_DIGITAL_SERVICE_DATA_REP_DSCTY_value;
        #endif

		replyData->BUFF_COUNT = CMD_GET_DIGITAL_SERVICE_DATA_REP_BUFF_COUNT_value;
		replyData->SRV_STATE = CMD_GET_DIGITAL_SERVICE_DATA_REP_SRV_STATE_value;
        replyData->DATA_SRC = CMD_GET_DIGITAL_SERVICE_DATA_REP_DATA_SRC_value;
		replyData->SERVICE_ID = _recover_32bit_from_little_endian_buffer((uint8_t*)&CMD_GET_DIGITAL_SERVICE_DATA_REP_SERVICE_ID_value);
        replyData->COMPONENT_ID = _recover_32bit_from_little_endian_buffer((uint8_t*)&CMD_GET_DIGITAL_SERVICE_DATA_REP_COMP_ID_value);
        
        replyData->UATYPE = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_GET_DIGITAL_SERVICE_DATA_REP_UATYPE_value);
		replyData->BYTE_COUNT = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_GET_DIGITAL_SERVICE_DATA_REP_BYTE_COUNT_value);
        replyData->SEG_NUM = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_GET_DIGITAL_SERVICE_DATA_REP_SEG_NUM_value);
        replyData->NUM_SEGS = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_GET_DIGITAL_SERVICE_DATA_REP_NUM_SEGS_value);

		//Create a null pointer to the payload until we have read it.
		replyData->PAYLOAD = 0;


		if(replyData->BYTE_COUNT > 0)
		{
			// Re-read the reply with the full length of header + payload.

            //TODO: upgrade this to a version which can be realigned to support buffers larger than the reply buffer size through re-alignment (like get_digital_service_list)
            //  - For now, we have no expectation of any data services for the modules so it is ok to simply limit the length to max buffer size to prevent crash
            if((CMD_GET_DIGITAL_SERVICE_DATA_REP_PAYLOAD0_INDEX + replyData->BYTE_COUNT) > RPY_BUFFER_LENGTH)
            {
                ret = readReply(RPY_BUFFER_LENGTH,reply_buffer);
            }
			else
            {
                ret = readReply(CMD_GET_DIGITAL_SERVICE_DATA_REP_PAYLOAD0_INDEX + replyData->BYTE_COUNT,reply_buffer);
            }

			if(ret == SUCCESS)
			{
				//Set the pointer to the address in the buffer for the payload data.
				replyData->PAYLOAD = &CMD_GET_DIGITAL_SERVICE_DATA_REP_PAYLOAD0_value;
			}
		}
	}
    else
    {
        ret = COMMAND_ERROR;
    }

	return ret;
}
#endif //OPTION__INCLUDE_MODE__ANY

#ifdef OPTION__INCLUDE_FRONT_END_TEST_FUNCTIONS
    #ifdef OPTION__INCLUDE_MODE__DAB
    RETURN_CODE test_get_rssi__command(void)
    {
    	RETURN_CODE ret = 0;

    	ClearMemory(cmd_arg, CMD_TEST_GET_RSSI_LENGTH);

    	cmd_arg[0] = CMD_TEST_GET_RSSI;

    	ret = writeCommand(CMD_TEST_GET_RSSI_LENGTH, cmd_arg);

    	if(ret == SUCCESS)
    	{
    		lastCommand = CMD_TEST_GET_RSSI;
    	}

    	return ret;
    }

    RETURN_CODE test_get_rssi__reply(int16_t* highresRssi)
    {
    	RETURN_CODE ret = 0;

    	ret = readReply(CMD_TEST_GET_RSSI_REP_LENGTH,reply_buffer);

    	if((ret == SUCCESS) && (lastCommand == CMD_TEST_GET_RSSI))
    	{
    		*highresRssi = CMD_TEST_GET_RSSI_REP_RSSI_HIGHRES_value;

            #ifdef OPTION__CONVERT_BIG_ENDIAN
                _swap_16((uint16_t *)highresRssi);
            #endif
    	}
        else
        {
            *highresRssi = 0;
            ret = COMMAND_ERROR;
        }

    	return ret;
    }
    #endif //OPTION__INCLUDE_MODE__DAB
#endif

// **************************************************************************
// Begin FMRX/FMHD commands
// **************************************************************************

RETURN_CODE fm_am_tune_freq__command(uint8_t shared_function_mode, uint8_t dir_tune, uint8_t tunemode, uint8_t injection, uint16_t freq, uint16_t antcap, uint8_t prog_id)
{
	RETURN_CODE ret = 0;
	
	ClearMemory(cmd_arg, CMD_FM_TUNE_FREQ_LENGTH);

	cmd_arg[0] = CMD_FM_TUNE_FREQ;

	if(shared_function_mode == SHARED_FUNCTION_MODE_AM)
	{
		cmd_arg[0] = CMD_AM_TUNE_FREQ;
	}

	CMD_FM_TUNE_FREQ_ARG_DIR_TUNE_write_field(dir_tune);
	CMD_FM_TUNE_FREQ_ARG_TUNE_MODE_write_field(tunemode);
	CMD_FM_TUNE_FREQ_ARG_INJECTION_write_field(injection);
	CMD_FM_TUNE_FREQ_ARG_FREQ_write_u16(freq);

    #ifdef OPTION__CONVERT_BIG_ENDIAN
        _swap_16((uint16_t *)&cmd_arg[CMD_FM_TUNE_FREQ_ARG_FREQ_INDEX]);
    #endif

	CMD_FM_TUNE_FREQ_ARG_ANTCAP_write_u16(antcap);

    #ifdef OPTION__CONVERT_BIG_ENDIAN
        _swap_16((uint16_t *)&cmd_arg[CMD_FM_TUNE_FREQ_ARG_ANTCAP_INDEX]);
    #endif

	CMD_FM_TUNE_FREQ_ARG_PROG_ID_write_u8(prog_id);

	ret = writeCommand(CMD_FM_TUNE_FREQ_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = cmd_arg[0];//CMD_FM_TUNE_FREQ;
	}

	return ret;
}


RETURN_CODE fm_am_seek_start__command(uint8_t shared_function_mode, uint8_t force_wb, uint8_t tunemode, uint8_t injection, uint8_t seekup, uint8_t wrap, uint16_t antcap)
{
	RETURN_CODE ret = 0;
	
	ClearMemory(cmd_arg, CMD_FM_SEEK_START_LENGTH);

    if(shared_function_mode == SHARED_FUNCTION_MODE_AM)
	{
		cmd_arg[0] = CMD_AM_SEEK_START;
	}
    else
    {
        cmd_arg[0] = CMD_FM_SEEK_START;
    }
	        
	CMD_FM_SEEK_START_ARG_FORCE_WB_write_field(force_wb);
	CMD_FM_SEEK_START_ARG_TUNE_MODE_write_field(tunemode);
	CMD_FM_SEEK_START_ARG_INJECTION_write_field(injection);
	CMD_FM_SEEK_START_ARG_SEEKUP_write_field(seekup);
	CMD_FM_SEEK_START_ARG_WRAP_write_field(wrap);
	CMD_FM_SEEK_START_ARG_ANTCAP_write_u16(antcap);

    #ifdef OPTION__CONVERT_BIG_ENDIAN
        _swap_16((uint16_t *)&cmd_arg[CMD_FM_SEEK_START_ARG_ANTCAP_INDEX]);
    #endif

	ret = writeCommand(CMD_FM_SEEK_START_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = cmd_arg[0];
	}

	return ret;
}

RETURN_CODE fm_rsq_status__command(uint8_t rsqack, uint8_t attune, uint8_t cancel, uint8_t stcack)
{
	RETURN_CODE ret = 0;
	
	ClearMemory(cmd_arg, CMD_FM_RSQ_STATUS_LENGTH);

	cmd_arg[0] = CMD_FM_RSQ_STATUS;

	CMD_FM_RSQ_STATUS_ARG_RSQACK_write_field(rsqack);
	CMD_FM_RSQ_STATUS_ARG_ATTUNE_write_field(attune);
	CMD_FM_RSQ_STATUS_ARG_CANCEL_write_field(cancel);
	CMD_FM_RSQ_STATUS_ARG_STCACK_write_field(stcack);

	ret = writeCommand(CMD_FM_RSQ_STATUS_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_FM_RSQ_STATUS;
	}

	return ret;
}



RETURN_CODE fm_rsq_status__reply(fm_rsq_status__data *replyData)
{
	RETURN_CODE ret = 0;

	ret = readReply(CMD_FM_RSQ_STATUS_REP_LENGTH,reply_buffer);

	if((ret == SUCCESS) && (lastCommand == CMD_FM_RSQ_STATUS))
	{
        replyData->RSSI = CMD_FM_RSQ_STATUS_REP_RSSI_value;
		replyData->SNR = CMD_FM_RSQ_STATUS_REP_SNR_value;
        replyData->MULT = CMD_FM_RSQ_STATUS_REP_MULT_value;
        replyData->VALID = CMD_FM_RSQ_STATUS_REP_VALID_is_true;
		replyData->READFREQ = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_FM_RSQ_STATUS_REP_READFREQ_value);
        #ifdef OPTION__INCLUDE_MODE__FMHD
            replyData->HDLEVEL = CMD_FM_RSQ_STATUS_REP_HDLEVEL_value;
        #endif

		#ifndef OPTION__MINIMAL_FIRMWARE_FUNCTION_IMPLEMENTATION_SMALLER_SDK
       		replyData->SNRHINT = CMD_FM_RSQ_STATUS_REP_SNRHINT_is_true;
    		replyData->SNRLINT = CMD_FM_RSQ_STATUS_REP_SNRLINT_is_true;
    		replyData->RSSIHINT = CMD_FM_RSQ_STATUS_REP_RSSIHINT_is_true;
    		replyData->RSSILINT = CMD_FM_RSQ_STATUS_REP_RSSILINT_is_true;
    		replyData->BLTF = CMD_FM_RSQ_STATUS_REP_BLTF_is_true;
		replyData->HDDETECTED = CMD_FM_RSQ_STATUS_REP_HDDETECTED_is_true;
		replyData->FLT_HDDETECTED = CMD_FM_RSQ_STATUS_REP_FLT_HDDETECTED_is_true;
       		replyData->FREQOFF = CMD_FM_RSQ_STATUS_REP_FREQOFF_value;
            replyData->AFCRL = CMD_FM_RSQ_STATUS_REP_AFCRL_is_true;
            replyData->READANTCAP = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_FM_RSQ_STATUS_REP_READANTCAP_value);
            replyData->FILTERED_HDLEVEL = CMD_FM_RSQ_STATUS_REP_FILTERED_HDLEVEL_value;
        #endif
	}
    else
    {
        ret = COMMAND_ERROR;
    }

	return ret;
}

#ifdef OPTION__INCLUDE_MODE__AM
RETURN_CODE am_rsq_status__command(uint8_t rsqack, uint8_t attune, uint8_t cancel, uint8_t stcack)
{
	RETURN_CODE ret = 0;
	
	ClearMemory(cmd_arg, CMD_AM_RSQ_STATUS_LENGTH);

	cmd_arg[0] = CMD_AM_RSQ_STATUS;

	CMD_AM_RSQ_STATUS_ARG_RSQACK_write_field(rsqack);
	CMD_AM_RSQ_STATUS_ARG_ATTUNE_write_field(attune);
	CMD_AM_RSQ_STATUS_ARG_CANCEL_write_field(cancel);
	CMD_AM_RSQ_STATUS_ARG_STCACK_write_field(stcack);

	ret = writeCommand(CMD_AM_RSQ_STATUS_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_AM_RSQ_STATUS;
	}

	return ret;
}

RETURN_CODE am_rsq_status__reply(am_rsq_status__data* replyData)
{
	RETURN_CODE ret = 0;

	ret = readReply(CMD_AM_RSQ_STATUS_REP_LENGTH,reply_buffer);

	if((ret == SUCCESS) && (lastCommand == CMD_AM_RSQ_STATUS))
	{
        replyData->RSSI = CMD_AM_RSQ_STATUS_REP_RSSI_value;
		replyData->SNR = CMD_AM_RSQ_STATUS_REP_SNR_value;
        replyData->MOD = CMD_AM_RSQ_STATUS_REP_MOD_value;
        replyData->VALID = CMD_AM_RSQ_STATUS_REP_VALID_is_true;
		replyData->READFREQ = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_AM_RSQ_STATUS_REP_READFREQ_value);
        #ifdef OPTION__INCLUDE_MODE__AMHD
            replyData->HDLEVEL = CMD_AM_RSQ_STATUS_REP_HDLEVEL_value;
        #endif

		#ifndef OPTION__MINIMAL_FIRMWARE_FUNCTION_IMPLEMENTATION_SMALLER_SDK
       		replyData->SNRHINT = CMD_AM_RSQ_STATUS_REP_SNRHINT_is_true;
    		replyData->SNRLINT = CMD_AM_RSQ_STATUS_REP_SNRLINT_is_true;
    		replyData->RSSIHINT = CMD_AM_RSQ_STATUS_REP_RSSIHINT_is_true;
    		replyData->RSSILINT = CMD_AM_RSQ_STATUS_REP_RSSILINT_is_true;
    		replyData->BLTF = CMD_AM_RSQ_STATUS_REP_BLTF_is_true;
       		replyData->FREQOFF = CMD_AM_RSQ_STATUS_REP_FREQOFF_value;
            replyData->AFCRL = CMD_AM_RSQ_STATUS_REP_AFCRL_is_true;
            replyData->READANTCAP = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_AM_RSQ_STATUS_REP_READANTCAP_value);
        #endif
	}
    else
    {
        ret = COMMAND_ERROR;
    }

	return ret;
}
#endif //#ifdef OPTION__INCLUDE_MODE__AM

#ifndef OPTION__REMOVE_FIRMWARE_FUNCTIONS_NOT_USED_SMALL_SDK
RETURN_CODE fm_acf_status__command(uint8_t acfack)
{
	RETURN_CODE ret = 0;
	
	ClearMemory(cmd_arg, CMD_FM_ACF_STATUS_LENGTH);

	cmd_arg[0] = CMD_FM_ACF_STATUS;
	CMD_FM_ACF_STATUS_ARG_ACFACK_write_field(acfack);

	ret = writeCommand(CMD_FM_ACF_STATUS_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_FM_ACF_STATUS;
	}

	return ret;
}

RETURN_CODE fm_acf_status__reply(fm_acf_status__data* replyData)
{
	RETURN_CODE ret = 0;

	ret = readReply(CMD_FM_ACF_STATUS_REP_LENGTH,reply_buffer);

	if((ret == SUCCESS) && (lastCommand == CMD_FM_ACF_STATUS))
	{
		replyData->BLEND_INT = CMD_FM_ACF_STATUS_REP_BLEND_INT_value;
		replyData->HIGHCUT_INT = CMD_FM_ACF_STATUS_REP_HIGHCUT_INT_value;
		replyData->SMUTE_INT = CMD_FM_ACF_STATUS_REP_SMUTE_INT_value;
		replyData->BLEND_CONV = CMD_FM_ACF_STATUS_REP_BLEND_CONV_value;
		replyData->HIGHCUT_CONV = CMD_FM_ACF_STATUS_REP_HIGHCUT_CONV_value;
		replyData->SMUTE_CONV = CMD_FM_ACF_STATUS_REP_SMUTE_CONV_value;
		replyData->BLEND_STATE = CMD_FM_ACF_STATUS_REP_BLEND_STATE_value;
		replyData->HIGHCUT_STATE = CMD_FM_ACF_STATUS_REP_HIGHCUT_STATE_value;
		replyData->SMUTE_STATE = CMD_FM_ACF_STATUS_REP_SMUTE_STATE_value;
		replyData->ATTN = CMD_FM_ACF_STATUS_REP_ATTN_value;
		replyData->HIGHCUT = CMD_FM_ACF_STATUS_REP_HIGHCUT_value;
		replyData->PILOT = CMD_FM_ACF_STATUS_REP_PILOT_value;
		replyData->STBLEND = CMD_FM_ACF_STATUS_REP_STBLEND_value;
	}
    else
    {
        ret = COMMAND_ERROR;
    }

	return ret;
}
#endif


RETURN_CODE fm_rds_status__command(uint8_t statusonly, uint8_t mtfifo, uint8_t intack)
{
	RETURN_CODE ret = 0;
	
	ClearMemory(cmd_arg, CMD_FM_RDS_STATUS_LENGTH);

	cmd_arg[0] = CMD_FM_RDS_STATUS;
	CMD_FM_RDS_STATUS_ARG_STATUSONLY_write_field(statusonly);
	CMD_FM_RDS_STATUS_ARG_MTFIFO_write_field(mtfifo);
	CMD_FM_RDS_STATUS_ARG_INTACK_write_field(intack);

	ret = writeCommand(CMD_FM_RDS_STATUS_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_FM_RDS_STATUS;
	}

	return ret;
}

RETURN_CODE fm_rds_status__reply(fm_rds_status__data* replyData)
{
	RETURN_CODE ret = 0;

	ret = readReply(CMD_FM_RDS_STATUS_REP_LENGTH,reply_buffer);

	if((ret == SUCCESS) && (lastCommand == CMD_FM_RDS_STATUS))
	{
        replyData->TP = CMD_FM_RDS_STATUS_REP_TP_value;
		replyData->PTY = CMD_FM_RDS_STATUS_REP_PTY_value;
		replyData->PI = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_FM_RDS_STATUS_REP_PI_value);
        replyData->BLEA = CMD_FM_RDS_STATUS_REP_BLEA_value;
		replyData->BLEB = CMD_FM_RDS_STATUS_REP_BLEB_value;
		replyData->BLEC = CMD_FM_RDS_STATUS_REP_BLEC_value;
		replyData->BLED = CMD_FM_RDS_STATUS_REP_BLED_value;
		replyData->BLOCKA = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_FM_RDS_STATUS_REP_BLOCKA_value);
		replyData->BLOCKB = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_FM_RDS_STATUS_REP_BLOCKB_value);
		replyData->BLOCKC = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_FM_RDS_STATUS_REP_BLOCKC_value);
		replyData->BLOCKD = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_FM_RDS_STATUS_REP_BLOCKD_value);

        replyData->TPPTYVALID = CMD_FM_RDS_STATUS_REP_TPPTYVALID_value;
		replyData->PIVALID = CMD_FM_RDS_STATUS_REP_PIVALID_value;
        replyData->RDSFIFOUSED = CMD_FM_RDS_STATUS_REP_RDSFIFOUSED_value;

        #ifndef OPTION__MINIMAL_FIRMWARE_FUNCTION_IMPLEMENTATION_SMALLER_SDK
		    replyData->RDSTPPTYINT = CMD_FM_RDS_STATUS_REP_RDSTPPTYINT_value;
		    replyData->RDSPIINT = CMD_FM_RDS_STATUS_REP_RDSPIINT_value;
		    replyData->RDSSYNCINT = CMD_FM_RDS_STATUS_REP_RDSSYNCINT_value;
		    replyData->RDSFIFOINT = CMD_FM_RDS_STATUS_REP_RDSFIFOINT_value;
		    replyData->RDSSYNC = CMD_FM_RDS_STATUS_REP_RDSSYNC_value;
		    replyData->RDSFIFOLOST = CMD_FM_RDS_STATUS_REP_RDSFIFOLOST_value;
		        
        #endif
	}
    else
    {
        ret = COMMAND_ERROR;
    }

	return ret;
}


#ifndef OPTION__REMOVE_FIRMWARE_FUNCTIONS_NOT_USED_SMALL_SDK
RETURN_CODE fm_rds_blockcount__command(uint8_t clear)
{
	RETURN_CODE ret = 0;
	
	ClearMemory(cmd_arg, CMD_FM_RDS_BLOCKCOUNT_LENGTH);

	cmd_arg[0] = CMD_FM_RDS_BLOCKCOUNT;
	CMD_FM_RDS_BLOCKCOUNT_ARG_CLEAR_write_field(clear);

	ret = writeCommand(CMD_FM_RDS_BLOCKCOUNT_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_FM_RDS_BLOCKCOUNT;
	}

	return ret;
}

RETURN_CODE fm_rds_blockcount__reply(fm_rds_blockcount__data* replyData)
{
	RETURN_CODE ret = 0;

	ret = readReply(CMD_FM_RDS_BLOCKCOUNT_REP_LENGTH,reply_buffer);

	if((ret == SUCCESS) && (lastCommand == CMD_FM_RDS_BLOCKCOUNT))
	{
		replyData->EXPECTED = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_FM_RDS_BLOCKCOUNT_REP_EXPECTED_value);
		replyData->RECEIVED = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_FM_RDS_BLOCKCOUNT_REP_RECEIVED_value);
		replyData->UNCORRECTABLE = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_FM_RDS_BLOCKCOUNT_REP_UNCORRECTABLE_value);  
    }
    else
    {
        ret = COMMAND_ERROR;
    }

	return ret;
}
#endif

#ifdef OPTION__INCLUDE_MODE__FMHD
RETURN_CODE hd_digrad_status__command(uint8_t ack)
{
	RETURN_CODE ret = 0;
	
	ClearMemory(cmd_arg, CMD_HD_DIGRAD_STATUS_LENGTH);

	cmd_arg[0] = CMD_HD_DIGRAD_STATUS;
	CMD_HD_DIGRAD_STATUS_ARG_DIGRAD_ACK_write_field(ack);

	ret = writeCommand(CMD_HD_DIGRAD_STATUS_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_HD_DIGRAD_STATUS;
	}

	return ret;
}


RETURN_CODE hd_digrad_status__reply(hd_digrad_status__data* replyData)
{
	RETURN_CODE ret = 0;

	ret = readReply(CMD_HD_DIGRAD_STATUS_REP_LENGTH,reply_buffer);

	if((ret == SUCCESS) && (lastCommand == CMD_HD_DIGRAD_STATUS))
	{
        replyData->SRCANA = CMD_HD_DIGRAD_STATUS_REP_SRCANA_value;
		replyData->SRCDIG = CMD_HD_DIGRAD_STATUS_REP_SRCDIG_value;
        replyData->HDLOGO = CMD_HD_DIGRAD_STATUS_REP_HDLOGO_value;
		replyData->ACQ = CMD_HD_DIGRAD_STATUS_REP_ACQ_value;
        replyData->DAAI = CMD_HD_DIGRAD_STATUS_REP_DAAI_value;
		replyData->CDNR = CMD_HD_DIGRAD_STATUS_REP_CDNR_value;
        replyData->AUDIO_PROG_AVAIL = CMD_HD_DIGRAD_STATUS_REP_AUDIO_PROG_AVAIL_value;
		replyData->AUDIO_PROG_PLAYING = CMD_HD_DIGRAD_STATUS_REP_AUDIO_PROG_PLAYING_value;

        #ifndef OPTION__MINIMAL_FIRMWARE_FUNCTION_IMPLEMENTATION_SMALLER_SDK
		    replyData->SRCANAINT = CMD_HD_DIGRAD_STATUS_REP_SRCANAINT_value;
		    replyData->SRCDIGINT = CMD_HD_DIGRAD_STATUS_REP_SRCDIGINT_value;
		    replyData->AUDACQINT = CMD_HD_DIGRAD_STATUS_REP_AUDACQINT_value;
            replyData->HDLOGOINT = CMD_HD_DIGRAD_STATUS_REP_HDLOGOINT_value;
		    replyData->ACQINT = CMD_HD_DIGRAD_STATUS_REP_ACQINT_value;
		    replyData->AUDACQ = CMD_HD_DIGRAD_STATUS_REP_AUDACQ_value;
		    replyData->CDNRHINT = CMD_HD_DIGRAD_STATUS_REP_CDNRHINT_value;
		    replyData->CDNRLINT = CMD_HD_DIGRAD_STATUS_REP_CDNRLINT_value;
		    replyData->CDNRH = CMD_HD_DIGRAD_STATUS_REP_CDNRH_value;
		    replyData->CDNRL = CMD_HD_DIGRAD_STATUS_REP_CDNRL_value;
		    replyData->BCTL = CMD_HD_DIGRAD_STATUS_REP_BCTL_value;
		    replyData->TX_GAIN = CMD_HD_DIGRAD_STATUS_REP_TX_GAIN_value;
		    replyData->AUDIO_CA = CMD_HD_DIGRAD_STATUS_REP_AUDIO_CA_value;
		    replyData->CORE_AUDIO_ERR = _recover_32bit_from_little_endian_buffer((uint8_t*)&CMD_HD_DIGRAD_STATUS_REP_CORE_AUDIO_ERR_value);
            replyData->ENH_AUDIO_ERR = _recover_32bit_from_little_endian_buffer((uint8_t*)&CMD_HD_DIGRAD_STATUS_REP_ENH_AUDIO_ERR_value);
        
            replyData->PTY = CMD_HD_DIGRAD_STATUS_REP_PTY_value;
            replyData->PS_MODE = CMD_HD_DIGRAD_STATUS_REP_PS_MODE_value;
            replyData->CODEC_MODE =  CMD_HD_DIGRAD_STATUS_REP_CODEC_MODE_value;
        #endif
    }
    else
    {
        ret = COMMAND_ERROR;
    }

	return ret;
}

RETURN_CODE hd_get_event_status__command(uint8_t ack)
{
	RETURN_CODE ret = 0;
	
	ClearMemory(cmd_arg, CMD_HD_GET_EVENT_STATUS_LENGTH);

	cmd_arg[0] = CMD_HD_GET_EVENT_STATUS;
	CMD_HD_GET_EVENT_STATUS_ARG_EVENT_ACK_write_field(ack);

	ret = writeCommand(CMD_HD_GET_EVENT_STATUS_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_HD_GET_EVENT_STATUS;
	}

	return ret;
}

//TODO: update to include new SIS and PSD info if updating to "simple" implementation
//UPDATED_SIS_PSD_NOTIFICATIONS
RETURN_CODE hd_get_event_status__reply(hd_get_event_status__data* replyData)
{
	RETURN_CODE ret = 0;

	ret = readReply(CMD_HD_GET_EVENT_STATUS_REP_LENGTH,reply_buffer);

	if((ret == SUCCESS) && (lastCommand == CMD_HD_GET_EVENT_STATUS))
	{
        replyData->ALERTINT = CMD_HD_GET_EVENT_STATUS_REP_ALERTINT_value;
		replyData->PSDINT = CMD_HD_GET_EVENT_STATUS_REP_PSDINT_value;
		replyData->SISINT = CMD_HD_GET_EVENT_STATUS_REP_SISINT_value;
		replyData->DSRVLISTINT = CMD_HD_GET_EVENT_STATUS_REP_DSRVLISTINT_value;
		replyData->ASRVLISTINT = CMD_HD_GET_EVENT_STATUS_REP_ASRVLISTINT_value;
		replyData->PSD = CMD_HD_GET_EVENT_STATUS_REP_PSD_value;
		replyData->SIS = CMD_HD_GET_EVENT_STATUS_REP_SIS_value;
		replyData->DSRVLIST = CMD_HD_GET_EVENT_STATUS_REP_DSRVLIST_value;
		replyData->ASRVLIST = CMD_HD_GET_EVENT_STATUS_REP_ASRVLIST_value;
		replyData->ASRVLISTVER = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_HD_GET_EVENT_STATUS_REP_ASRVLISTVER_value);
        replyData->DSRVLISTVER = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_HD_GET_EVENT_STATUS_REP_DSRVLISTVER_value);  

        //Required PSD notifications
        replyData->GENRE = CMD_HD_GET_EVENT_STATUS_REP_GENRE_value;
		replyData->ALBUM = CMD_HD_GET_EVENT_STATUS_REP_ALBUM_value;
		replyData->ARTIST = CMD_HD_GET_EVENT_STATUS_REP_ARTIST_value;
		replyData->TITLE = CMD_HD_GET_EVENT_STATUS_REP_TITLE_value;

#ifdef UPDATED_SIS_PSD_NOTIFICATIONS
		replyData->SIS_LOCATION = CMD_HD_GET_EVENT_STATUS_REP_SIS_LOCATION_value;
		replyData->SIS_LONG_NAME = CMD_HD_GET_EVENT_STATUS_REP_SIS_LONG_NAME_value;
		replyData->SIS_SHORT_NAME = CMD_HD_GET_EVENT_STATUS_REP_SIS_SHORT_NAME_value;
		replyData->SIS_ID = CMD_HD_GET_EVENT_STATUS_REP_SIS_ID_value;
		replyData->SIS_SLOGAN = CMD_HD_GET_EVENT_STATUS_REP_SIS_SLOGAN_value;
		replyData->SIS_BASIC_SIS = CMD_HD_GET_EVENT_STATUS_REP_SIS_BASIC_SIS_value;
		replyData->SIS_UNIV_SHORT_NAME = CMD_HD_GET_EVENT_STATUS_REP_SIS_UNIV_SHORT_NAME_value;
		replyData->SIS_LEAP_SEC = CMD_HD_GET_EVENT_STATUS_REP_SIS_LEAP_SEC_value;
		replyData->SIS_TIMEZONE = CMD_HD_GET_EVENT_STATUS_REP_SIS_TIMEZONE_value;
		replyData->SIS_MESSAGE = CMD_HD_GET_EVENT_STATUS_REP_SIS_MESSAGE_value;

		replyData->TEXT = CMD_HD_GET_EVENT_STATUS_REP_TEXT_value;
		replyData->SHORT = CMD_HD_GET_EVENT_STATUS_REP_SHORT_value;
		replyData->LANG = CMD_HD_GET_EVENT_STATUS_REP_LANG_value;
		replyData->ID = CMD_HD_GET_EVENT_STATUS_REP_ID_value;
		replyData->OWNER = CMD_HD_GET_EVENT_STATUS_REP_OWNER_value;
		replyData->DESC = CMD_HD_GET_EVENT_STATUS_REP_DESC_value;
		replyData->NAME = CMD_HD_GET_EVENT_STATUS_REP_NAME_value;
		replyData->RECV = CMD_HD_GET_EVENT_STATUS_REP_RECV_value;
		replyData->URL = CMD_HD_GET_EVENT_STATUS_REP_URL_value;
		replyData->VALID = CMD_HD_GET_EVENT_STATUS_REP_VALID_value;
		replyData->PRICE = CMD_HD_GET_EVENT_STATUS_REP_PRICE_value;
#endif
    }
    else
    {
        ret = COMMAND_ERROR;
    }

	return ret;
}

RETURN_CODE fmhd_get_psd_decode__command(uint8_t program, uint8_t field)
{
	RETURN_CODE ret = 0;

	ClearMemory(cmd_arg, CMD_HD_GET_PSD_DECODE_LENGTH);

	cmd_arg[0] = CMD_HD_GET_PSD_DECODE;
	CMD_HD_GET_PSD_DECODE_ARG_PROGRAM_write_u8(program);
	CMD_HD_GET_PSD_DECODE_ARG_FIELD_write_u8(field);

	ret = writeCommand(CMD_HD_GET_PSD_DECODE_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_HD_GET_PSD_DECODE;
	}

	return ret;
}

RETURN_CODE fmhd_get_psd_decode__reply(fmhd_get_psd_decode__data* replyData)
{
	RETURN_CODE ret = 0;

	ret = readReply(CMD_HD_GET_PSD_DECODE_REP_DATA0_INDEX,reply_buffer);

	if((ret == SUCCESS) && (lastCommand == CMD_HD_GET_PSD_DECODE))
	{
		replyData->DATATYPE = CMD_HD_GET_PSD_DECODE_REP_DATATYPE_value;
        //Need to correct for inconsistency between the API returns and the definitions per iBiquity
        switch(replyData->DATATYPE)
        {
            case 0:
                replyData->DATATYPE = IEC_8859_1;
                break;
            case 1:
                replyData->DATATYPE = UCS2_LITTLEENDIAN;
                break;
            default:
                replyData->DATATYPE = ENCODING_RESERVED;
                break;
        }

		replyData->LENGTH = CMD_HD_GET_PSD_DECODE_REP_LENGTH_value;

		//Create a null pointer to the payload until we have read it.
		replyData->PAYLOAD = 0;

		if(replyData->LENGTH > 0)
		{
			// Re-read the reply with the full length of header + payload.
			ret = readReply(CMD_HD_GET_PSD_DECODE_REP_DATA0_INDEX + replyData->LENGTH,reply_buffer);
			if(ret == SUCCESS)
			{
				//Set the pointer to the address in the buffer for the payload data.
				replyData->PAYLOAD = &CMD_HD_GET_PSD_DECODE_REP_DATA0_value;
			}
		}
	}
    else
    {
        ret = COMMAND_ERROR;
    }

	return ret;
}

RETURN_CODE fmhd_get_alert_message__command()
{
	RETURN_CODE ret = 0;

	ClearMemory(cmd_arg, CMD_HD_GET_ALERT_MSG_LENGTH);

	cmd_arg[0] = CMD_HD_GET_ALERT_MSG;

	ret = writeCommand(CMD_HD_GET_ALERT_MSG_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_HD_GET_ALERT_MSG;
	}

	return ret;
}

RETURN_CODE fmhd_get_alert_message__reply(fmhd_get_alert_message__data* replyData)
{
	RETURN_CODE ret = 0;

	ret = readReply(CMD_HD_GET_ALERT_MSG_REP_DATA0_INDEX,reply_buffer);

	if((ret == SUCCESS) && (lastCommand == CMD_HD_GET_ALERT_MSG))
	{
		replyData->LENGTH = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_HD_GET_ALERT_MSG_REP_LENGTH_value);

		//Create a null pointer to the payload until we have read it.
		replyData->PAYLOAD = 0;

		if(replyData->LENGTH > 0)
		{
            // Limiting the total length for the Alert text if we are using the small read buffer.
            // It is not worth the code size to do a segmented read for alert messages on small devices which would take forever to scroll a 400 character string
            if((replyData->LENGTH + CMD_HD_GET_ALERT_MSG_REP_DATA0_INDEX) > RPY_BUFFER_LENGTH)
            {
                replyData->LENGTH = (RPY_BUFFER_LENGTH - CMD_HD_GET_ALERT_MSG_REP_DATA0_INDEX);
            }

			// Re-read the reply with the full length of header + payload.
			ret = readReply(CMD_HD_GET_ALERT_MSG_REP_DATA0_INDEX + replyData->LENGTH,reply_buffer);
			if(ret == SUCCESS)
			{
				//Set the pointer to the address in the buffer for the payload data.
				replyData->PAYLOAD = &CMD_HD_GET_ALERT_MSG_REP_DATA0_value;
			}
		}
	}
    else
    {
        ret = COMMAND_ERROR;
    }

	return ret;
}

RETURN_CODE fmhd_play_alert_tone__command()
{
	RETURN_CODE ret = 0;

	ClearMemory(cmd_arg, CMD_HD_PLAY_ALERT_TONE_LENGTH);

	cmd_arg[0] = CMD_HD_PLAY_ALERT_TONE;

	ret = writeCommand(CMD_HD_PLAY_ALERT_TONE_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_HD_PLAY_ALERT_TONE;
	}

	return ret;
}


//We need to know what type of data it is and this is not returned in the reply - new variable to track it internally
uint8_t fmhd_get_station_info__info_select_sent;

RETURN_CODE fmhd_get_station_info__command(uint8_t info_select)
{
	RETURN_CODE ret = 0;
	
	ClearMemory(cmd_arg, CMD_HD_GET_STATION_INFO_LENGTH);

	cmd_arg[0] = CMD_HD_GET_STATION_INFO;
	CMD_HD_GET_STATION_INFO_ARG_INFO_SELECT_write_u8(info_select);

	ret = writeCommand(CMD_HD_GET_STATION_INFO_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
        fmhd_get_station_info__info_select_sent = info_select;
		lastCommand = CMD_HD_GET_STATION_INFO;
	}

	return ret;
}

RETURN_CODE fmhd_get_station_info__reply(fmhd_get_station_info__data* replyData)
{
	RETURN_CODE ret = 0;

	ret = readReply(CMD_HD_GET_STATION_INFO_REP_DATA0_INDEX,reply_buffer);

	if((ret == SUCCESS) && (lastCommand == CMD_HD_GET_STATION_INFO))
	{
		replyData->LENGTH = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_HD_GET_STATION_INFO_REP_LENGTH_value);
        replyData->INFO_SELECT = fmhd_get_station_info__info_select_sent;
		
		//Create a null pointer to the payload until we have read it.
		replyData->PAYLOAD = 0;

		if(replyData->LENGTH > 0)
		{
			// Re-read the reply with the full length of header + payload.
			ret = readReply(CMD_HD_GET_STATION_INFO_REP_DATA0_INDEX + replyData->LENGTH,reply_buffer);
			if(ret == SUCCESS)
			{
				//Set the pointer to the address in the buffer for the payload data.
				replyData->PAYLOAD = &CMD_HD_GET_STATION_INFO_REP_DATA0_value;
			}
		}
	}
    else
    {
        ret = COMMAND_ERROR;
    }

	return ret;
}


#ifdef OPTION__INCLUDE_FRONT_END_TEST_FUNCTIONS
RETURN_CODE fmhd_test_get_ber_info__command(void)
{
	RETURN_CODE ret = 0;
	
	ClearMemory(cmd_arg, CMD_HD_TEST_GET_BER_INFO_LENGTH);

	cmd_arg[0] = CMD_HD_TEST_GET_BER_INFO;

	ret = writeCommand(CMD_HD_TEST_GET_BER_INFO_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_HD_TEST_GET_BER_INFO;
	}

	return ret;
}

RETURN_CODE fmhd_test_get_ber_info__reply(fmhd_test_get_ber_info__data* replyData)
{
	RETURN_CODE ret = 0;

	ret = readReply(CMD_HD_TEST_GET_BER_INFO_REP_LENGTH,reply_buffer);

	if((ret == SUCCESS) && (lastCommand == CMD_HD_TEST_GET_BER_INFO))
	{
        replyData->P1_BIT_ERRORS = _recover_32bit_from_little_endian_buffer((uint8_t*)&CMD_HD_TEST_GET_BER_INFO_REP_P1_BIT_ERRORS_value);
        replyData->P1_BITS_TESTED = _recover_32bit_from_little_endian_buffer((uint8_t*)&CMD_HD_TEST_GET_BER_INFO_REP_P1_BITS_TESTED_value);

        replyData->P2_BIT_ERRORS = _recover_32bit_from_little_endian_buffer((uint8_t*)&CMD_HD_TEST_GET_BER_INFO_REP_P2_BIT_ERRORS_value);
        replyData->P2_BITS_TESTED = _recover_32bit_from_little_endian_buffer((uint8_t*)&CMD_HD_TEST_GET_BER_INFO_REP_P2_BITS_TESTED_value);

        replyData->P3_BIT_ERRORS = _recover_32bit_from_little_endian_buffer((uint8_t*)&CMD_HD_TEST_GET_BER_INFO_REP_P3_BIT_ERRORS_value);
        replyData->P3_BITS_TESTED = _recover_32bit_from_little_endian_buffer((uint8_t*)&CMD_HD_TEST_GET_BER_INFO_REP_P3_BITS_TESTED_value);
        
        replyData->PIDS_BIT_ERRORS = _recover_32bit_from_little_endian_buffer((uint8_t*)&CMD_HD_TEST_GET_BER_INFO_REP_PIDS_BIT_ERRORS_value);
        replyData->PIDS_BITS_TESTED = _recover_32bit_from_little_endian_buffer((uint8_t*)&CMD_HD_TEST_GET_BER_INFO_REP_PIDS_BITS_TESTED_value);
        
		replyData->PIDS_BLOCK_ERRORS = _recover_32bit_from_little_endian_buffer((uint8_t*)&CMD_HD_TEST_GET_BER_INFO_REP_PIDS_BLOCK_ERRORS_value);
        replyData->PIDS_BLOCKS_TESTED = _recover_32bit_from_little_endian_buffer((uint8_t*)&CMD_HD_TEST_GET_BER_INFO_REP_PIDS_BLOCKS_TESTED_value);       
	}
    else
    {
        ret = COMMAND_ERROR;
    }

	return ret;
}
#endif


#ifndef OPTION__REMOVE_FIRMWARE_FUNCTIONS_NOT_USED_SMALL_SDK
RETURN_CODE fmhd_set_enabled_ports__command(uint8_t length, uint16_t* portAddresses)
{
	RETURN_CODE ret = 0;
	uint16_t manualWriteLength;
    #ifdef OPTION__CONVERT_BIG_ENDIAN
	    uint16_t i;
    #endif

	ClearMemory(cmd_arg, CMD_HD_SET_ENABLED_PORTS_ARG_DATA_0_INDEX);

	cmd_arg[0] = CMD_HD_SET_ENABLED_PORTS;
	CMD_HD_SET_ENABLED_PORTS_ARG_LENGTH_write_u8(length);

	CpyMemory(&cmd_arg[CMD_HD_SET_ENABLED_PORTS_ARG_DATA_0_INDEX],(uint8_t *)portAddresses, (length * 2));

    #ifdef OPTION__CONVERT_BIG_ENDIAN
        for(i=0;i<length;i++)
        {
            _swap_16((uint16_t *)&cmd_arg[(CMD_HD_SET_ENABLED_PORTS_ARG_DATA_0_INDEX + (i * 2))]);
        }
    #endif

	//Need to manually control the length given the undefined input length
	manualWriteLength = (CMD_HD_SET_ENABLED_PORTS_ARG_DATA_0_INDEX + ((CMD_HD_SET_ENABLED_PORTS_ARG_DATA_0_SIZE / 8) * length));

	ret = writeCommand(manualWriteLength, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_HD_SET_ENABLED_PORTS;
	}

	return ret;
}
#endif


#ifndef OPTION__REMOVE_FIRMWARE_FUNCTIONS_NOT_USED_SMALL_SDK
RETURN_CODE fmhd_get_enabled_ports__command(void)
{
	RETURN_CODE ret = 0;
	
	ClearMemory(cmd_arg, CMD_HD_GET_ENABLED_PORTS_LENGTH);

	cmd_arg[0] = CMD_HD_GET_ENABLED_PORTS;

	ret = writeCommand(CMD_HD_GET_ENABLED_PORTS_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_HD_GET_ENABLED_PORTS;
	}

	return ret;
}

RETURN_CODE fmhd_get_enabled_ports__reply(fmhd_get_enabled_ports__data* replyData)
{
	RETURN_CODE ret = 0;
    uint16_t manualReadLength;
    #ifdef OPTION__CONVERT_BIG_ENDIAN
	    uint16_t i;
    #endif

	ret = readReply(CMD_HD_GET_ENABLED_PORTS_REP_DATA_0_INDEX,reply_buffer);

	if((ret == SUCCESS) && (lastCommand == CMD_HD_GET_ENABLED_PORTS))
	{
		replyData->LENGTH = CMD_HD_GET_ENABLED_PORTS_REP_LENGTH_value;
		
		//Create a null pointer to the payload until we have read it.
		replyData->PAYLOAD = 0;

		if(replyData->LENGTH > 0)
		{
			// Re-read the reply with the full length of header + payload.
			manualReadLength = (CMD_HD_GET_ENABLED_PORTS_REP_DATA_0_INDEX + (2 * replyData->LENGTH));

			ret = readReply(manualReadLength,reply_buffer);
			if(ret == SUCCESS)
			{
				//Set the pointer to the address in the buffer for the payload data.
				replyData->PAYLOAD = (uint16_t*)&CMD_HD_GET_ENABLED_PORTS_REP_DATA_0_value;
			
                #ifdef OPTION__CONVERT_BIG_ENDIAN
                    for(i=0;i<replyData->LENGTH;i++)
                    {
                        _swap_16((uint16_t *)&replyData->PAYLOAD[(i * 2)]);
                    }
                #endif
            }
		}
	}
    else
    {
        ret = COMMAND_ERROR;
    }

	return ret;
}
#endif

#endif //OPTION__INCLUDE_MODE__FMHD

// **************************************************************************
// Begin DAB/DMB commands
// **************************************************************************
#ifdef OPTION__INCLUDE_MODE__DAB
RETURN_CODE dab_tune_freq__command(uint8_t injection, uint8_t freq_index, uint16_t antcap)
{
	RETURN_CODE ret = 0;
	
	ClearMemory(cmd_arg, CMD_DAB_TUNE_FREQ_LENGTH);

	cmd_arg[0] = CMD_DAB_TUNE_FREQ;
	CMD_DAB_TUNE_FREQ_ARG_INJECTION_write_field(injection);
	CMD_DAB_TUNE_FREQ_ARG_FREQ_INDEX_write_u8(freq_index);
	CMD_DAB_TUNE_FREQ_ARG_ANTCAP_write_u16(antcap);

    #ifdef OPTION__CONVERT_BIG_ENDIAN
        _swap_16((uint16_t *)&cmd_arg[CMD_DAB_TUNE_FREQ_ARG_ANTCAP_INDEX]);
    #endif

	ret = writeCommand(CMD_DAB_TUNE_FREQ_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_DAB_TUNE_FREQ;
	}

	return ret;
}


RETURN_CODE dab_digrad_status__command(uint8_t ack, uint8_t attune, uint8_t fiberr_ack, uint8_t stc_ack)
{
	RETURN_CODE ret = 0;
	
	ClearMemory(cmd_arg, CMD_DAB_DIGRAD_STATUS_LENGTH);

	cmd_arg[0] = CMD_DAB_DIGRAD_STATUS;
	CMD_DAB_DIGRAD_STATUS_ARG_DIGRAD_ACK_write_field(ack);
	CMD_DAB_DIGRAD_STATUS_ARG_ATTUNE_write_field(attune);
    CMD_DAB_DIGRAD_STATUS_ARG_FIBERR_ACK_write_field(fiberr_ack);
	CMD_DAB_DIGRAD_STATUS_ARG_STC_ACK_write_field(stc_ack);

	ret = writeCommand(CMD_DAB_DIGRAD_STATUS_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_DAB_DIGRAD_STATUS;
	}

	return ret;
}

RETURN_CODE dab_digrad_status__reply(dab_digrad_status__data* replyData)
{
	RETURN_CODE ret = 0;

	ret = readReply(CMD_DAB_DIGRAD_STATUS_REP_LENGTH,reply_buffer);

	if((ret == SUCCESS) && (lastCommand == CMD_DAB_DIGRAD_STATUS))
	{
		replyData->ACQINT = CMD_DAB_DIGRAD_STATUS_REP_ACQINT_value;
		replyData->ACQ = CMD_DAB_DIGRAD_STATUS_REP_ACQ_value;
		replyData->VALID = CMD_DAB_DIGRAD_STATUS_REP_VALID_value;
		replyData->RSSI = CMD_DAB_DIGRAD_STATUS_REP_RSSI_value;
		replyData->SNR = CMD_DAB_DIGRAD_STATUS_REP_SNR_value;
		replyData->FIC_QUALITY = CMD_DAB_DIGRAD_STATUS_REP_FIC_QUALITY_value;
		replyData->CNR = CMD_DAB_DIGRAD_STATUS_REP_CNR_value;
        replyData->TUNE_INDEX = CMD_DAB_DIGRAD_STATUS_REP_TUNE_INDEX_value;

        #ifdef OPTION__ADVANCED_METRICS
            replyData->FFT_OFFSET = CMD_DAB_DIGRAD_STATUS_REP_FFT_OFFSET_value;
        #endif

        #ifndef OPTION__MINIMAL_FIRMWARE_FUNCTION_IMPLEMENTATION_SMALLER_SDK
            replyData->FICERRINT = CMD_DAB_DIGRAD_STATUS_REP_FICERRINT_value;
            replyData->FICERR = CMD_DAB_DIGRAD_STATUS_REP_FICERR_value;
            replyData->RSSIHINT = CMD_DAB_DIGRAD_STATUS_REP_RSSIHINT_value;
            replyData->RSSILINT = CMD_DAB_DIGRAD_STATUS_REP_RSSILINT_value;
            replyData->FIB_ERROR_COUNT = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_DAB_DIGRAD_STATUS_REP_FIB_ERROR_COUNT_value);
	        replyData->TUNE_FREQ  = _recover_32bit_from_little_endian_buffer((uint8_t*)&CMD_DAB_DIGRAD_STATUS_REP_TUNE_FREQ_value);
            replyData->READANTCAP = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_DAB_DIGRAD_STATUS_REP_READANTCAP_value);
            replyData->CU_LEVEL = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_DAB_DIGRAD_STATUS_REP_CU_LEVEL_value);
            replyData->FAST_DECT = CMD_DAB_DIGRAD_STATUS_REP_FAST_DECT_value;
        #endif
	}
    else
    {
        ret = COMMAND_ERROR;
    }

	return ret;
}

RETURN_CODE dab_get_event_status__command(uint8_t ack)
{
	RETURN_CODE ret = 0;
	
	ClearMemory(cmd_arg, CMD_DAB_GET_EVENT_STATUS_LENGTH);

	cmd_arg[0] = CMD_DAB_GET_EVENT_STATUS;
	CMD_DAB_GET_EVENT_STATUS_ARG_EVENT_ACK_write_field(ack);

	ret = writeCommand(CMD_DAB_GET_EVENT_STATUS_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_DAB_GET_EVENT_STATUS;
	}

	return ret;
}

RETURN_CODE dab_get_event_status__reply(dab_get_event_status__data* replyData)
{
	RETURN_CODE ret = 0;

	ret = readReply(CMD_DAB_GET_EVENT_STATUS_REP_LENGTH,reply_buffer);

	if((ret == SUCCESS) && (lastCommand == CMD_DAB_GET_EVENT_STATUS))
	{
		replyData->RECFGINT = CMD_DAB_GET_EVENT_STATUS_REP_RECFGINT_value;
		replyData->RECFGWRNINT = CMD_DAB_GET_EVENT_STATUS_REP_RECFGWRNINT_value;
		replyData->ANNOINT = CMD_DAB_GET_EVENT_STATUS_REP_ANNOINT_value;
        replyData->ANNO = CMD_DAB_GET_EVENT_STATUS_REP_ANNO_value;
        replyData->OESERVINT = CMD_DAB_GET_EVENT_STATUS_REP_OESERVINT_value;
        replyData->OESERV = CMD_DAB_GET_EVENT_STATUS_REP_OESERV_value;
        replyData->SERVLINKINT = CMD_DAB_GET_EVENT_STATUS_REP_SERVLINKINT_value;
        replyData->SERVLINK = CMD_DAB_GET_EVENT_STATUS_REP_SERVLINK_value;
        replyData->FREQINFOINT = CMD_DAB_GET_EVENT_STATUS_REP_FREQINFOINT_value;
        replyData->FREQINFO = CMD_DAB_GET_EVENT_STATUS_REP_FREQ_INFO_value;
		replyData->SVRLISTINT = CMD_DAB_GET_EVENT_STATUS_REP_SVRLISTINT_value;
		replyData->SVRLIST = CMD_DAB_GET_EVENT_STATUS_REP_SVRLIST_value;
		replyData->SVRLISTVER = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_DAB_GET_EVENT_STATUS_REP_SVRLISTVER_value);    
    }
    else
    {
        ret = COMMAND_ERROR;
    }

	return ret;
}

RETURN_CODE dab_get_ensemble_info__command(void)
{
	RETURN_CODE ret = 0;
	
	ClearMemory(cmd_arg, CMD_DAB_GET_ENSEMBLE_INFO_LENGTH);

	cmd_arg[0] = CMD_DAB_GET_ENSEMBLE_INFO;

	ret = writeCommand(CMD_DAB_GET_ENSEMBLE_INFO_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_DAB_GET_ENSEMBLE_INFO;
	}

	return ret;
}

// NOTE: this function returns a fixed length array for LABEL (16 bytes) - manually overriding the REP_LENGTH constant to accomodate this
RETURN_CODE dab_get_ensemble_info__reply(dab_get_ensemble_info__data* replyData)
{
	RETURN_CODE ret = 0;

	ret = readReply(CMD_DAB_GET_ENSEMBLE_INFO_REP_LENGTH,reply_buffer);

	if((ret == SUCCESS) && (lastCommand == CMD_DAB_GET_ENSEMBLE_INFO))
	{
		replyData->EID = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_DAB_GET_ENSEMBLE_INFO_REP_EID_value);

		replyData->LABEL_LENGTH = 16;
		replyData->LABEL = &CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL0_value;

        #ifdef OPTION__RADIODNS
            replyData->ENSEMBLE_ECC = CMD_DAB_GET_ENSEMBLE_INFO_REP_ENSEMBLE_ECC_value;
        #endif

        replyData->CHARSET = CMD_DAB_GET_ENSEMBLE_INFO_REP_CHARSET_value;

        #ifndef OPTION__MINIMAL_FIRMWARE_FUNCTION_IMPLEMENTATION_SMALLER_SDK
            replyData->CHAR_ABREV = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_DAB_GET_ENSEMBLE_INFO_REP_CHAR_ABREV_value);
        #endif
	}
    else
    {
        ret = COMMAND_ERROR;
    }

	return ret;
}


#ifdef OPTION__DECODE_DAB_ANNOUNCEMENTS
RETURN_CODE dab_get_announcement_support_info__command(uint8_t src, uint32_t sid)
{
    RETURN_CODE ret = 0;
	
	ClearMemory(cmd_arg, CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_LENGTH);

	cmd_arg[0] = CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO;
    CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_ARG_SRC_write_field(src);
    CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_ARG_SID_write_u32(sid);

    #ifdef OPTION__CONVERT_BIG_ENDIAN
        _swap_32((uint32_t *)&cmd_arg[CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_ARG_SID_INDEX]);
    #endif

	ret = writeCommand(CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO;
	}

	return ret;
}

RETURN_CODE dab_get_announcement_support_info__reply(dab_get_announcement_support_info__data* replyData)
{
    RETURN_CODE ret = 0;
    uint16_t manualReadLength;
    #ifdef OPTION__CONVERT_BIG_ENDIAN
        uint16_t i;
    #endif

	ret = readReply(CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_ID0_INDEX,reply_buffer);

	if((ret == SUCCESS) && (lastCommand == CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO))
	{
        replyData->ASU = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_ASU_value);


		replyData->NUM_IDS = CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_NUM_IDS_value;

		//Create a null pointer to the payload until we have read it.
		replyData->ID = 0;

		if(replyData->NUM_IDS > 0)
		{
			// Re-read the reply with the full length of header + payload.
			manualReadLength = (CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_ID0_INDEX + ((CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_ID0_SIZE / 8) * replyData->NUM_IDS));

			ret = readReply(manualReadLength,reply_buffer);
			if(ret == SUCCESS)
			{
				//Set the pointer to the address in the buffer for the payload data.
				replyData->ID = (uint16_t*)&CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_ID0_value;
			
                #ifdef OPTION__CONVERT_BIG_ENDIAN
                    for(i=0;i<replyData->NUM_IDS;i++)
                    {
                        _swap_16((uint16_t *)&replyData->ID[i]);
                    }
                #endif
            }
		}
	}
    else
    {
        ret = COMMAND_ERROR;
    }

	return ret;
}

RETURN_CODE dab_get_announcement_info__command(void)
{
    RETURN_CODE ret = 0;
	
	ClearMemory(cmd_arg, CMD_DAB_GET_ANNOUNCEMENT_INFO_LENGTH);

	cmd_arg[0] = CMD_DAB_GET_ANNOUNCEMENT_INFO;

	ret = writeCommand(CMD_DAB_GET_ANNOUNCEMENT_INFO_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_DAB_GET_ANNOUNCEMENT_INFO;
	}

	return ret;
}

RETURN_CODE dab_get_announcement_info__reply(dab_get_announcement_info__data* replyData)
{
	RETURN_CODE ret = 0;

	ret = readReply(CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_LENGTH,reply_buffer);

	if((ret == SUCCESS) && (lastCommand == CMD_DAB_GET_ANNOUNCEMENT_INFO))
	{
		replyData->ANNO_Q_OVFL = CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ANNO_Q_OVFL_value;
		replyData->ANNO_Q_SIZE = CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ANNO_Q_SIZE_value;
		replyData->CLUSTER_ID = CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_CLUSTER_ID_value;
        replyData->SRC = CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_SRC_value;
        replyData->REGION_FLAG = CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_REGION_FLAG_value;
        replyData->ANNO_STAT = CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ANNO_STAT_value;

        replyData->ASW = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ASW_value);
        replyData->ID1 = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ID1_value);
		replyData->ID2 = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ID2_value);

		replyData->REGIONID1 = CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_REGIONID1_value;
		replyData->REGIONID2 = CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_REGIONID2_value;    
    }
    else
    {
        ret = COMMAND_ERROR;
    }

	return ret;
}
#endif //OPTION__DECODE_DAB_ANNOUNCEMENTS


RETURN_CODE dab_set_freq_list__command(uint8_t num_freqs, uint32_t* freq)
{
	RETURN_CODE ret = 0;
	uint16_t manualWriteLength;
    #ifdef OPTION__CONVERT_BIG_ENDIAN
	    uint16_t i;
    #endif

	ClearMemory(cmd_arg, CMD_DAB_SET_FREQ_LIST_ARG_FREQ_0_INDEX);

	cmd_arg[0] = CMD_DAB_SET_FREQ_LIST;
	CMD_DAB_SET_FREQ_LIST_ARG_NUM_FREQS_write_u8(num_freqs);

	CpyMemory(&cmd_arg[CMD_DAB_SET_FREQ_LIST_ARG_FREQ_0_INDEX],(uint8_t *)freq, (num_freqs * 4));

    #ifdef OPTION__CONVERT_BIG_ENDIAN
        for(i=0;i<num_freqs;i++)
        {
            _swap_32((uint32_t *)&cmd_arg[(CMD_DAB_SET_FREQ_LIST_ARG_FREQ_0_INDEX + (i * 4))]);
        }
    #endif

	//Need to manually control the length given the undefined input length
	manualWriteLength = (CMD_DAB_SET_FREQ_LIST_ARG_FREQ_0_INDEX + ((CMD_DAB_SET_FREQ_LIST_ARG_FREQ_0_SIZE / 8) * num_freqs));

	ret = writeCommand(manualWriteLength, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_DAB_SET_FREQ_LIST;
	}

	return ret;
}


RETURN_CODE dab_get_freq_list__command(void)
{
	RETURN_CODE ret = 0;
	
	ClearMemory(cmd_arg, CMD_DAB_GET_FREQ_LIST_LENGTH);

	cmd_arg[0] = CMD_DAB_GET_FREQ_LIST;

	ret = writeCommand(CMD_DAB_GET_FREQ_LIST_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_DAB_GET_FREQ_LIST;
	}

	return ret;
}

RETURN_CODE dab_get_freq_list__reply(dab_get_freq_list__data* replyData)
{
	RETURN_CODE ret = 0;
    uint16_t manualReadLength;
    #ifdef OPTION__CONVERT_BIG_ENDIAN
        uint16_t i;
    #endif

	ret = readReply(CMD_DAB_GET_FREQ_LIST_REP_FREQ_0_INDEX,reply_buffer);

	if((ret == SUCCESS) && (lastCommand == CMD_DAB_GET_FREQ_LIST))
	{
		replyData->NUM_FREQS = CMD_DAB_GET_FREQ_LIST_REP_NUM_FREQS_value;

		//Create a null pointer to the payload until we have read it.
		replyData->FREQ = 0;

		if(replyData->NUM_FREQS > 0)
		{
			// Re-read the reply with the full length of header + payload.
			manualReadLength = (CMD_DAB_GET_FREQ_LIST_REP_FREQ_0_INDEX + ((CMD_DAB_GET_FREQ_LIST_REP_FREQ_0_SIZE / 8) * replyData->NUM_FREQS));

			ret = readReply(manualReadLength,reply_buffer);
			if(ret == SUCCESS)
			{
				//Set the pointer to the address in the buffer for the payload data.
				replyData->FREQ = (uint32_t*)&CMD_DAB_GET_FREQ_LIST_REP_FREQ_0_value;
			
                #ifdef OPTION__CONVERT_BIG_ENDIAN
                    for(i=0;i<replyData->NUM_FREQS;i++)
                    {
                        _swap_32((uint32_t *)&replyData->FREQ[i]);
                    }
                #endif
            }
		}
	}
    else
    {
        ret = COMMAND_ERROR;
    }

	return ret;
}


RETURN_CODE dab_get_component_info__command(uint32_t serviceid, uint32_t compid)
{
	RETURN_CODE ret = 0;
	
	ClearMemory(cmd_arg, CMD_DAB_GET_COMPONENT_INFO_LENGTH);

	cmd_arg[0] = CMD_DAB_GET_COMPONENT_INFO;
	CMD_DAB_GET_COMPONENT_INFO_ARG_SERVICEID_write_u32(serviceid);

    #ifdef OPTION__CONVERT_BIG_ENDIAN
        _swap_32((uint32_t *)&cmd_arg[CMD_DAB_GET_COMPONENT_INFO_ARG_SERVICEID_INDEX]);
    #endif

	CMD_DAB_GET_COMPONENT_INFO_ARG_COMPID_write_u32(compid);

    #ifdef OPTION__CONVERT_BIG_ENDIAN
        _swap_32((uint32_t *)&cmd_arg[CMD_DAB_GET_COMPONENT_INFO_ARG_COMPID_INDEX]);
    #endif

	ret = writeCommand(CMD_DAB_GET_COMPONENT_INFO_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_DAB_GET_COMPONENT_INFO;
	}

	return ret;
}

RETURN_CODE dab_get_component_info__reply(dab_get_component_info__data* replyData)
{
	RETURN_CODE ret = 0;

	ret = readReply(CMD_DAB_GET_COMPONENT_INFO_REP_UADATA0_INDEX,reply_buffer);

	if((ret == SUCCESS) && (lastCommand == CMD_DAB_GET_COMPONENT_INFO))
	{

		replyData->CHARSETID = CMD_DAB_GET_COMPONENT_INFO_REP_CHARSETID_value;
		replyData->LABEL_LENGTH = 16;
		//Set the pointer to the address in the buffer for the 16 bytes of LABEL data.
		replyData->LABEL = &CMD_DAB_GET_COMPONENT_INFO_REP_LABEL0_value;

        #ifdef OPTION__RADIODNS
            replyData->GLOBAL_ID = CMD_DAB_GET_COMPONENT_INFO_REP_GLOBAL_ID_value;
        #endif

        #ifndef OPTION__MINIMAL_FIRMWARE_FUNCTION_IMPLEMENTATION_SMALLER_SDK
            
		    replyData->LANG = CMD_DAB_GET_COMPONENT_INFO_REP_LANG_value;
		    replyData->CHAR_ABREV = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_DAB_GET_COMPONENT_INFO_REP_CHAR_ABREV_value);
        
            replyData->NUMUA = CMD_DAB_GET_COMPONENT_INFO_REP_NUMUA_value;
		    replyData->UATYPE = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_DAB_GET_COMPONENT_INFO_REP_UATYPE_value);
        
            replyData->UADATALEN = CMD_DAB_GET_COMPONENT_INFO_REP_UADATALEN_value;

		    //Create a null pointer to the payload until we have read it.
		    replyData->UADATA = 0;

		    if(replyData->UADATALEN > 0)
		    {
			    // Re-read the reply with the full length of header + payload.
			    uint16_t manualReadLength = (CMD_DAB_GET_COMPONENT_INFO_REP_UADATA0_INDEX + replyData->UADATALEN);

			    ret = readReply(manualReadLength,reply_buffer);
			    if(ret == SUCCESS)
			    {
				    //Set the pointer to the address in the buffer for the payload data.
				    replyData->UADATA = (uint8_t*)&CMD_DAB_GET_COMPONENT_INFO_REP_UADATA0_value;
			    }
		    }
        #endif
	}
    else
    {
        ret = COMMAND_ERROR;
    }

	return ret;
}

RETURN_CODE dab_get_time__command(uint8_t time_type)
{
	RETURN_CODE ret = 0;
	
	ClearMemory(cmd_arg, CMD_DAB_GET_TIME_LENGTH);

	cmd_arg[0] = CMD_DAB_GET_TIME;
	CMD_DAB_GET_TIME_ARG_TIME_TYPE_write_u8(time_type);

	ret = writeCommand(CMD_DAB_GET_TIME_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_DAB_GET_TIME;
	}

	return ret;
}

RETURN_CODE dab_get_time__reply(dab_get_time__data* replyData)
{
	RETURN_CODE ret = 0;

	ret = readReply(CMD_DAB_GET_TIME_REP_LENGTH,reply_buffer);

	if((ret == SUCCESS) && (lastCommand == CMD_DAB_GET_TIME))
	{
		replyData->YEAR = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_DAB_GET_TIME_REP_YEAR_value);

		replyData->MONTHS = CMD_DAB_GET_TIME_REP_MONTHS_value;
		replyData->DAYS = CMD_DAB_GET_TIME_REP_DAYS_value;
		replyData->HOURS = CMD_DAB_GET_TIME_REP_HOURS_value;
		replyData->MINUTES = CMD_DAB_GET_TIME_REP_MINUTES_value;
		replyData->SECONDS = CMD_DAB_GET_TIME_REP_SECONDS_value;
	}
    else
    {
        ret = COMMAND_ERROR;
    }

	return ret;
}

RETURN_CODE dab_get_audio_info__command(void)
{
	RETURN_CODE ret = 0;
	
	ClearMemory(cmd_arg, CMD_DAB_GET_AUDIO_INFO_LENGTH);

	cmd_arg[0] = CMD_DAB_GET_AUDIO_INFO;

	ret = writeCommand(CMD_DAB_GET_AUDIO_INFO_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_DAB_GET_AUDIO_INFO;
	}

	return ret;
}

RETURN_CODE dab_get_audio_info__reply(dab_get_audio_info__data* replyData)
{
	RETURN_CODE ret = 0;

	ret = readReply(CMD_DAB_GET_AUDIO_INFO_REP_LENGTH,reply_buffer);

	if((ret == SUCCESS) && (lastCommand == CMD_DAB_GET_AUDIO_INFO))
	{
		replyData->AUDIO_BIT_RATE = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_BIT_RATE_value);

		replyData->AUDIO_SAMPLE_RATE = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_SAMPLE_RATE_value);

        replyData->AUDIO_MODE = CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_MODE_value;

        #ifndef OPTION__MINIMAL_FIRMWARE_FUNCTION_IMPLEMENTATION_SMALLER_SDK
		    replyData->AUDIO_PS_FLAG = CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_PS_FLAG_value;
		    replyData->AUDIO_SBR_FLAG = CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_SBR_FLAG_value;
            replyData->AUDIO_DRC_GAIN = CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_DRC_GAIN_value;
        #endif
	}
    else
    {
        ret = COMMAND_ERROR;
    }

	return ret;
}


//TODO: add DAB_GET_SUBCHAN_INFO

#ifdef OPTION__DAB_SUPPORT_DAB_DAB_LINKING
#ifdef OPTION__DAB_SUPPORT_DAB_DAB_LINKING_A3

#ifndef OPTION__COMMAND_INPUT_MINIMAL_OPTIONS_SMALLER_SDK
RETURN_CODE dab_get_service_linking_info__command(uint8_t active, uint8_t activeen,
                                                  uint8_t linktype, uint8_t linktypeen,
                                                  uint8_t hard, uint8_t harden,
                                                  uint8_t ils, uint8_t ilsen,
                                                  uint32_t serviceid)
{
    RETURN_CODE ret = 0;
	
	ClearMemory(cmd_arg, CMD_DAB_GET_SERVICE_LINKING_INFO_LENGTH);

	cmd_arg[0] = CMD_DAB_GET_SERVICE_LINKING_INFO;
    CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ACTIVE_write_field(active);
    CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ACTIVEEN_write_field(activeen);
    CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_LINKTYPE_write_field(linktype);
    CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_LINKTYPEEN_write_field(linktypeen);
    CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_HARD_write_field(hard);
    CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_HARDEN_write_field(harden);
    CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ILS_write_field(ils);
    CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ILSEN_write_field(ilsen);
    CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_SERVICEID_write_u32(serviceid);

    #ifdef OPTION__CONVERT_BIG_ENDIAN
        _swap_32((uint32_t *)&cmd_arg[CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_SERVICEID_INDEX]);
    #endif

	ret = writeCommand(CMD_DAB_GET_SERVICE_LINKING_INFO_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_DAB_GET_SERVICE_LINKING_INFO;
	}

	return ret;
}
#else
RETURN_CODE dab_get_service_linking_info__command(uint32_t serviceid, uint8_t arg1, uint8_t arg2)
{
    RETURN_CODE ret = 0;
	
	ClearMemory(cmd_arg, CMD_DAB_GET_SERVICE_LINKING_INFO_LENGTH);

	cmd_arg[0] = CMD_DAB_GET_SERVICE_LINKING_INFO;
    cmd_arg[1] = arg1;
    cmd_arg[2] = arg2;
    CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_SERVICEID_write_u32(serviceid);

    #ifdef OPTION__CONVERT_BIG_ENDIAN
        _swap_32((uint32_t *)&cmd_arg[CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_SERVICEID_INDEX]);
    #endif

	ret = writeCommand(CMD_DAB_GET_SERVICE_LINKING_INFO_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_DAB_GET_SERVICE_LINKING_INFO;
	}

	return ret;
}
#endif

RETURN_CODE dab_get_service_linking_info__reply(dab_get_service_linking_info__data* replyData)
{
    RETURN_CODE ret = 0;
    uint16_t manualReadLength;

	ret = readReply(CMD_DAB_GET_SERVICE_LINKING_INFO_REP_LSN_0_INDEX, reply_buffer);

	if((ret == SUCCESS) && (lastCommand == CMD_DAB_GET_SERVICE_LINKING_INFO))
	{
        replyData->SIZE = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_DAB_GET_SERVICE_LINKING_INFO_REP_SIZE_value);
        replyData->NUM_LINKSETS = CMD_DAB_GET_SERVICE_LINKING_INFO_REP_NUM_LINKSETS_value;

		//Create a null pointer to the payload until we have read it.
		replyData->PAYLOAD = 0;

		if(replyData->SIZE > 0)
		{
			// Re-read the reply with the full length of header + payload.
			manualReadLength = (CMD_DAB_GET_SERVICE_LINKING_INFO_REP_LSN_0_INDEX + replyData->SIZE);

            if(manualReadLength > RPY_BUFFER_LENGTH)
            {
                replyData->NUM_LINKSETS = 0;
                return HAL_ERROR;  //Our reply buffer is too small to hold a service linking buffer of this size.  Linking not supported for this ensemble.
                //TODO: rather than dropping the buffer when it is too large, this could be done with buffer shifting but it takes too many resources for our current platform.
            }

			ret = readReply(manualReadLength,reply_buffer);
            replyData->PAYLOAD = (uint8_t*)&CMD_DAB_GET_SERVICE_LINKING_INFO_REP_LSN_0_value;
		}
	}
    else
    {
        ret = COMMAND_ERROR;
    }

	return ret;
}

#define NUMLINKS_OFFSET (CMD_DAB_GET_SERVICE_LINKING_INFO_REP_LINKID_0_0_INDEX - CMD_DAB_GET_SERVICE_LINKING_INFO_REP_LSN_0_INDEX)

RETURN_CODE dab_get_service_linking_info__get_element(uint8_t linkset_index, dab_get_service_linking_info__data* replyData, dab_linking_set* linkSetPtr)
{
    #ifdef OPTION__CONVERT_BIG_ENDIAN
        uint8_t i=0;
    #endif
    dab_get_service_linking_info_set__data* linkSetPayloadPtr;
    uint8_t payloadOffset = 0;

    if(linkset_index >= replyData->NUM_LINKSETS)
    {
        return INVALID_INPUT;
    }

    //Find the offset for the desired linkset
    while(i++ <= linkset_index)
    {
        linkSetPayloadPtr = (dab_get_service_linking_info_set__data*)&replyData->PAYLOAD[payloadOffset];
        payloadOffset += (NUMLINKS_OFFSET + (4 * linkSetPayloadPtr->NUMLINKS));
    }

    #ifndef OPTION__MINIMAL_FIRMWARE_FUNCTION_IMPLEMENTATION_SMALLER_SDK
        //Remove these items as they will be filtered to match what is being input to the command, not reason to waste code space reading them out if we assume the firmware works properly
        //We would only need to adjust this if we are extending to DAB/FM or adding soft linking support
        linkSetPtr->LSN = _recover_16bit_from_little_endian_buffer((uint8_t*)&linkSetPayloadPtr->LSN);
        linkSetPtr->ACTIVE = (linkSetPayloadPtr->LINKINFO & CMD_DAB_GET_SERVICE_LINKING_INFO_REP_ACTIVE_MASK) >> CMD_DAB_GET_SERVICE_LINKING_INFO_REP_ACTIVE_LSB;
        linkSetPtr->SHD = (linkSetPayloadPtr->LINKINFO & CMD_DAB_GET_SERVICE_LINKING_INFO_REP_SHD_MASK) >> CMD_DAB_GET_SERVICE_LINKING_INFO_REP_SHD_LSB;
        linkSetPtr->LINKTYPE = (linkSetPayloadPtr->LINKINFO & CMD_DAB_GET_SERVICE_LINKING_INFO_REP_LINK_TYPE_MASK) >> CMD_DAB_GET_SERVICE_LINKING_INFO_REP_LINK_TYPE_LSB;
        linkSetPtr->HARD = (linkSetPayloadPtr->LINKINFO & CMD_DAB_GET_SERVICE_LINKING_INFO_REP_HARD_MASK) >> CMD_DAB_GET_SERVICE_LINKING_INFO_REP_HARD_LSB;
        linkSetPtr->ILS = (linkSetPayloadPtr->LINKINFO & CMD_DAB_GET_SERVICE_LINKING_INFO_REP_ILS_MASK) >> CMD_DAB_GET_SERVICE_LINKING_INFO_REP_ILS_LSB;
    #endif

    linkSetPtr->NUMLINKS = linkSetPayloadPtr->NUMLINKS;
    linkSetPtr->LINKID = &linkSetPayloadPtr->LINKID;

    #ifdef OPTION__CONVERT_BIG_ENDIAN
        #ifndef OPTION__MINIMAL_FIRMWARE_FUNCTION_IMPLEMENTATION_SMALLER_SDK
            _swap_16(&linkSetPayloadPtr->LSN);
        #endif

        for(i=0;i<linkSetPtr->NUMLINKS;i++)
        {
            _swap_32(&linkSetPtr->LINKID[i]);
        }
    #endif

    return SUCCESS;
}
#endif //OPTION__DAB_SUPPORT_DAB_DAB_LINKING_A3

RETURN_CODE dab_get_freq_info__command(void)
{
    RETURN_CODE ret = 0;
	
	ClearMemory(cmd_arg, CMD_DAB_GET_FREQ_INFO_LENGTH);

	cmd_arg[0] = CMD_DAB_GET_FREQ_INFO;

	ret = writeCommand(CMD_DAB_GET_FREQ_INFO_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_DAB_GET_FREQ_INFO;
	}

	return ret;
}

RETURN_CODE dab_get_freq_info__reply(dab_get_freq_info__data* replyData)
{
    RETURN_CODE ret = 0;
    uint16_t manualReadLength;
    #ifdef OPTION__CONVERT_BIG_ENDIAN
        uint8_t i;
    #endif

	ret = readReply(CMD_DAB_GET_FREQ_INFO_REP_FI_ID_0_INDEX, reply_buffer);

	if((ret == SUCCESS) && (lastCommand == CMD_DAB_GET_FREQ_INFO))
	{
		replyData->NUM_ELEMENTS = _recover_32bit_from_little_endian_buffer((uint8_t*)&CMD_DAB_GET_FREQ_INFO_REP_LENGTH_FI_LIST_value);

		//Create a null pointer to the payload until we have read it.
		replyData->PAYLOAD = 0;

		if(replyData->NUM_ELEMENTS > 0)
		{
			// Re-read the reply with the full length of header + payload.
			manualReadLength = (CMD_DAB_GET_FREQ_INFO_REP_FI_ID_0_INDEX + (replyData->NUM_ELEMENTS * sizeof(dab_fi_element)));

            if(manualReadLength > RPY_BUFFER_LENGTH)
            {
                replyData->NUM_ELEMENTS = 0;
                return HAL_ERROR;  //Our reply buffer is too small to hold a frequency info buffer of this size.  Linking not supported for this ensemble.
                //TODO: rather than dropping the buffer when it is too large, this could be done with buffer shifting but it takes too many resources for our current platform.
            }

			ret = readReply(manualReadLength,reply_buffer);
            replyData->PAYLOAD = (dab_fi_element*)&CMD_DAB_GET_FREQ_INFO_REP_FI_ID_0_value;
            
            #ifdef OPTION__CONVERT_BIG_ENDIAN
                for(i=0;i<replyData->NUM_ELEMENTS;i++)
                {
                    _swap_32((uint32_t *)&replyData->PAYLOAD->ID);
                    _swap_32((uint32_t *)&replyData->PAYLOAD->FREQ);
                    replyData->PAYLOAD += 1;
                }
                replyData->PAYLOAD = (dab_fi_element*)&CMD_DAB_GET_FREQ_INFO_REP_FI_ID_0_value;
            #endif
		}
	}
    else
    {
        ret = COMMAND_ERROR;
    }

	return ret;
}


RETURN_CODE dab_get_oe_services_info__command(uint32_t serviceid)
{
    RETURN_CODE ret = 0;
	
	ClearMemory(cmd_arg, CMD_DAB_GET_OE_SERVICES_INFO_LENGTH);

	cmd_arg[0] = CMD_DAB_GET_OE_SERVICES_INFO;
    CMD_DAB_GET_OE_SERVICES_INFO_ARG_SERVICEID_write_u32(serviceid);


    #ifdef OPTION__CONVERT_BIG_ENDIAN
        _swap_32((uint32_t *)&cmd_arg[CMD_DAB_GET_OE_SERVICES_INFO_ARG_SERVICEID_INDEX]);
    #endif

	ret = writeCommand(CMD_DAB_GET_OE_SERVICES_INFO_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_DAB_GET_OE_SERVICES_INFO;
	}

	return ret;
}

RETURN_CODE dab_get_oe_services_info__reply(dab_get_oe_services_info__data* replyData)
{
    RETURN_CODE ret = 0;
    uint16_t manualReadLength;
    #ifdef OPTION__CONVERT_BIG_ENDIAN
        uint8_t i;
    #endif

	ret = readReply(CMD_DAB_GET_OE_SERVICES_INFO_REP_EID_0_INDEX, reply_buffer);

	if((ret == SUCCESS) && (lastCommand == CMD_DAB_GET_OE_SERVICES_INFO))
	{
		replyData->SIZE = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_DAB_GET_OE_SERVICES_INFO_REP_SIZE_value);
        replyData->NUM_EIDS = CMD_DAB_GET_OE_SERVICES_INFO_REP_NUM_EIDS_value;

		//Create a null pointer to the payload until we have read it.
		replyData->EIDS = 0;

		if(replyData->NUM_EIDS > 0)
		{
			// Re-read the reply with the full length of header + payload.
			manualReadLength = (CMD_DAB_GET_OE_SERVICES_INFO_REP_EID_0_INDEX + (replyData->NUM_EIDS * sizeof(uint16_t)));

            if(manualReadLength > RPY_BUFFER_LENGTH)
            {
                replyData->NUM_EIDS = 0;
                return HAL_ERROR;  //Our reply buffer is too small to hold a frequency info buffer of this size.  Linking not supported for this ensemble.
                //TODO: rather than dropping the buffer when it is too large, this could be done with buffer shifting but it takes too many resources for our current platform.
            }

			ret = readReply(manualReadLength,reply_buffer);
            replyData->EIDS = (uint16_t*)&CMD_DAB_GET_OE_SERVICES_INFO_REP_EID_0_value;
            
            #ifdef OPTION__CONVERT_BIG_ENDIAN
                for(i=0;i<replyData->NUM_EIDS;i++)
                {
                    _swap_16(&replyData->EIDS[i]);
                }
            #endif
		}
	}
    else
    {
        ret = COMMAND_ERROR;
    }

	return ret;
}
#endif //OPTION__DAB_SUPPORT_DAB_DAB_LINKING

#ifdef OPTION__RADIODNS
RETURN_CODE dab_get_service_info__command(uint32_t service_id)
{
    RETURN_CODE ret = 0;
	
	ClearMemory(cmd_arg, CMD_DAB_GET_SERVICE_INFO_LENGTH);

	cmd_arg[0] = CMD_DAB_GET_SERVICE_INFO;
    CMD_DAB_GET_SERVICE_INFO_ARG_SERVICEID_write_u32(service_id);

    #ifdef OPTION__CONVERT_BIG_ENDIAN
        _swap_32((uint32_t *)&cmd_arg[CMD_DAB_GET_SERVICE_INFO_ARG_SERVICEID_INDEX]);
    #endif

	ret = writeCommand(CMD_DAB_GET_SERVICE_INFO_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_DAB_GET_SERVICE_INFO;
	}

	return ret;
}


RETURN_CODE dab_get_service_info__reply(dab_get_service_info__data* replyData)
{
	RETURN_CODE ret = 0;

	ret = readReply(CMD_DAB_GET_SERVICE_INFO_REP_LENGTH,reply_buffer);

	if((ret == SUCCESS) && (lastCommand == CMD_DAB_GET_SERVICE_INFO))
	{
		replyData->SRV_ECC = CMD_DAB_GET_SERVICE_INFO_REP_SRV_ECC_value;

        #ifndef OPTION__MINIMAL_FIRMWARE_FUNCTION_IMPLEMENTATION_SMALLER_SDK
		    replyData->SRV_LINKING_INFO = CMD_DAB_GET_SERVICE_INFO_REP_SRV_LINKING_INFO_value;
            replyData->PTY = CMD_DAB_GET_SERVICE_INFO_REP_PTY_value;
            replyData->PD_FLAG = CMD_DAB_GET_SERVICE_INFO_REP_PD_FLAG_value;
            replyData->LOCAL = CMD_DAB_GET_SERVICE_INFO_REP_LOCAL_value;
            replyData->CAID = CMD_DAB_GET_SERVICE_INFO_REP_CAID_value;
            replyData->NUM_COMP = CMD_DAB_GET_SERVICE_INFO_REP_NUM_COMP_value;
            replyData->SICHARSET = CMD_DAB_GET_SERVICE_INFO_REP_SICHARSET_value;

            replyData->LABEL_LENGTH = 16;
		    //Set the pointer to the address in the buffer for the 16 bytes of LABEL data.
		    replyData->LABEL = &CMD_DAB_GET_SERVICE_INFO_REP_LABEL0_value;

            replyData->CHAR_ABREV = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_DAB_GET_SERVICE_INFO_REP_CHAR_ABREV_value);
        #endif
	}
    else
    {
        ret = COMMAND_ERROR;
    }

	return ret;
}
#endif //OPTION__RADIODNS

#ifndef OPTION__MINIMAL_FIRMWARE_FUNCTION_IMPLEMENTATION_SMALLER_SDK
RETURN_CODE dab_acf_status__command(void)
{
	RETURN_CODE ret = 0;
	
	ClearMemory(cmd_arg, CMD_DAB_ACF_STATUS_LENGTH);

	cmd_arg[0] = CMD_DAB_ACF_STATUS;

	ret = writeCommand(CMD_DAB_ACF_STATUS_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_DAB_ACF_STATUS;
	}

	return ret;
}

RETURN_CODE dab_acf_status__reply(dab_acf_status__data* replyData)
{
	RETURN_CODE ret = 0;

	ret = readReply(CMD_DAB_ACF_STATUS_REP_LENGTH,reply_buffer);

	if((ret == SUCCESS) && (lastCommand == CMD_DAB_ACF_STATUS))
	{
		replyData->AUDIO_LEVEL = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_DAB_ACF_STATUS_REP_AUDIO_LEVEL_value);
		replyData->CMFT_NOISE_LEVEL = _recover_16bit_from_little_endian_buffer((uint8_t*)&CMD_DAB_ACF_STATUS_REP_CMFT_NOISE_LEVEL_value);
    }
    else
    {
        ret = COMMAND_ERROR;
    }

	return ret;
}
#endif

#ifdef OPTION__INCLUDE_FRONT_END_TEST_FUNCTIONS
RETURN_CODE dab_test_ber_info__command(void)
{
	RETURN_CODE ret = 0;
	
	ClearMemory(cmd_arg, CMD_DAB_TEST_GET_BER_INFO_LENGTH);

	cmd_arg[0] = CMD_DAB_TEST_GET_BER_INFO;

	ret = writeCommand(CMD_DAB_TEST_GET_BER_INFO_LENGTH, cmd_arg);

	if(ret == SUCCESS)
	{
		lastCommand = CMD_DAB_TEST_GET_BER_INFO;
	}

	return ret;
}

RETURN_CODE dab_test_ber_info__reply(dab_test_ber_info__data* replyData)
{
	RETURN_CODE ret = 0;

	ret = readReply(CMD_DAB_TEST_GET_BER_INFO_REP_LENGTH,reply_buffer);

	if((ret == SUCCESS) && (lastCommand == CMD_DAB_TEST_GET_BER_INFO))
	{
		replyData->ERR_BITS = _recover_32bit_from_little_endian_buffer((uint8_t*)&CMD_DAB_TEST_GET_BER_INFO_REP_ERR_BITS_value);
		replyData->TOTAL_BITS = _recover_32bit_from_little_endian_buffer((uint8_t*)&CMD_DAB_TEST_GET_BER_INFO_REP_TOTAL_BITS_value);
    }
    else
    {
        ret = COMMAND_ERROR;
    }

	return ret;
}
#endif

#endif //OPTION__INCLUDE_MODE__DAB
