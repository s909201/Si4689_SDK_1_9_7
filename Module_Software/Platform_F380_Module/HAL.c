/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   SDK layer general hardware abstration layer drivers for C8051F380 based module
   FILE: HAL.c
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#include <platform_options.h>
#include <HAL.h>
#include "delay.h"
#include "sys.h"
#include "si468x_bus.h"
#include "in_chip_eeprom.h"

#ifdef OPTION__MCU_PLATFORM


#define POLL_TIMEOUT_MS 1000

RETURN_CODE initHardware(void)
{
//	Init_Device();
	si468x_reset();

	return SUCCESS;
}

RETURN_CODE audioEnable(void)
{
    #ifdef PLATFORM_F340_DEMOBOARD
        AUDIO_SHUTDOWN = 0;
    #endif
    #ifdef PLATFORM_F380_MODULE_V2_0									
		MUTE = 0;
	#endif
	return SUCCESS;
}

RETURN_CODE audioDisable(void)
{
    #ifdef PLATFORM_F340_DEMOBOARD
        AUDIO_SHUTDOWN = 1;
    #endif
    #ifdef PLATFORM_F380_MODULE_V2_0
		MUTE = 1;
	#endif
	return SUCCESS;
}

//The module does not have any hardware to power down, but it will put the reset line low
RETURN_CODE powerDownHardware(void)
{
	si468x_disable();

	return SUCCESS;
}

// Blocking version of waiting for CTS
RETURN_CODE wait_for_CTS (uint32_t timeout_ms)
{
	RETURN_CODE ret = 0;
	uint8_t status = 0;
	uint32_t i;

	for(i=0; i < timeout_ms; i++)
	{
		si468x_readReply(1,&status);

		if((status & 0x80) == 0x80)
		{
			if((status & 0x40) == 0x40)
			{
				return COMMAND_ERROR;
			}
			return SUCCESS;
		}

		// delay function for 1 ms
		delay(1);
	}

	return TIMEOUT;
}

RETURN_CODE writeCommand (uint16_t length, uint8_t *buffer)
{
	RETURN_CODE ret = wait_for_CTS(POLL_TIMEOUT_MS);

	if((ret == SUCCESS) || (ret == COMMAND_ERROR)) //It is possible that there is a pending command error - we need to be able to send another command to clear out this state
	{
		si468x_writeCommand(length, buffer);

		ret = wait_for_CTS(POLL_TIMEOUT_MS);
	}

	return ret;
}

RETURN_CODE readReply (uint16_t length, uint8_t *buffer)
{
	ClearMemory (buffer, length);
	si468x_readReply(length, buffer);

	return SUCCESS;
}

void delay (uint32_t delay_ms)
{
	wait_ms(delay_ms);
}


/************************************************************************************
save/read the service list information into MCU flash
input:
	start_addr: 0 index for the start of the storage in memory - the driver called should move the address to the correct position
	len: data segment length
	buffer: data pointer
************************************************************************************/
#ifdef OPTION__INCLUDE_MODE__DAB
    #ifdef OPTION__DAB_SERVICE_LIST_PERSISTENCE
    RETURN_CODE writePersistentStorage(uint16_t start_addr, uint16_t length, uint8_t* buffer)
    {
        return write_storage(start_addr, length, buffer);
    }

    RETURN_CODE readPersistentStorage(uint16_t start_addr, uint16_t length, uint8_t* buffer)
    {
        return read_storage(start_addr, length, buffer);
    }

    void erasePersistentStorage()
    {
        erase_storage();
    }
    #endif //OPTION__DAB_SERVICE_LIST_PERSISTENCE
#endif //OPTION__INCLUDE_MODE__DAB

#endif
