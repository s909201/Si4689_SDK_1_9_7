/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   entry point for usb command handler for C8051F380 based module
   FILE: usb_process.c
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#include <intrins.h>
#include <stddef.h>

#include <platform_options.h>

#ifdef OPTION__USB_DRIVER

#include "compiler_defs.h"
#include "typedefs.h"
#include "usb_process.h"
#include "si468x_bus.h"
#include "Firmware_API_Manager.h"
#include "si46xx_firmware_api.h"



#ifdef PLATFORM_F340_DEMOBOARD
	#include "C8051F340_defs.h"
#endif

#ifdef PLATFORM_F380_MODULE
	#include "C8051F380_defs.h"
#endif

#include "usb_hid.h"
#include "SST25VF032B.h"

#include "main.h"
#include "delay.h"
#include "sys.h"
#include "HAL.h"
#include "utility.h"
#include "LCD.h"
#include "mode_common.h"
extern void  Radio_Flasher(void);
u8 data LastStatus;
bit ctsDirty;


/* readReply  reads the reply regardless of the busmode */
USB_error USB_readReply(u8 bytes, u8 xdata *dataIn)
{
    si468x_readReply(bytes,dataIn);
    return USB_error_ok;
}
#define FLASH_WRITE_ADDRESS			0xAA
#define FLASH_ERASE         		0xAB
#define FLASH_WRITE_PATCH_COMPELE	0xAC
#define FLASH_WRITE_FW_COMPELE		0xAD
/* writeCommand writes the command regardless of the busmode */
USB_error USB_writeCommand(u8 bytes, u8 xdata *dataOut)
{

#ifdef UPDATE_IMAGE_BY_MCU
	bytes = 0;
	if(dataOut[0] == FLASH_WRITE_ADDRESS && dataOut[1] == 0x55)//set the patch data address of flash
	{	
		data_addr = 0;
														// as there are two data need to load into flash
		data_addr =(u32)dataOut[2];
		data_addr <<=8;

		data_addr +=(u32)dataOut[3];
		data_addr <<=8;
		
		data_addr +=(u32)dataOut[4];
		data_addr <<=8;

		data_addr +=(u32)dataOut[5];
	}
 	if(dataOut[0] == FLASH_ERASE && dataOut[1] == 0x55)//erase the flash,before writing
	{
		Chip_Erase();
	}
#endif

#ifdef UPDATE_IMAGE_BY_TUNER

		u8 xdata i;
		i  = 0;

	//si468x_writeCommand(bytes,dataOut);


	if(dataOut[0]==0xB2 && dataOut[1]==0x55 && dataOut[2]==0x55)//erase flash make si468x into flash progarming state
	{		
		display_mode = IDLE_MODE;
		power_flag = 0;


		StartFirmwareUpdate();
		wait_ms(1);	
		load_init__command();

#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI			
		LCD_Clear(LCD_CLEAR_ALL);
		LCD_DisplayStr("Update flash\n",0,0);
		LCD_DisplayStr("Doing...\n",0,1);
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI

		firmware_download_flag = 1;

   		EIE1 = 0x02;                    // Enable USB0 Interrupts
		EIE2 = 0x00;
		IE = 0x80;

	}
	else if(dataOut[0]==0x05 && dataOut[1]==0xFE && dataOut[2]==0xC0 && dataOut[3]==0xDE)//sector erase 0xDEC0
	{
		si468x_writeCommand(bytes,dataOut);
	}
	else
	{
		//si468x_writeCommand(bytes,dataOut);
		if(dataOut[0]==0x05 && dataOut[1]==0xF3 && dataOut[2]==0x0C && dataOut[3]==0xED)//0xED0C
		{
			si468x_SSB = 0;
		}
		while(bytes--)
		{
			si468x_write(dataOut[i++]);
		}
	}
#endif			 
    ctsDirty = 1;
    return USB_error_ok;

}


u8 readStatus(void)
{
    u8 idata status;

    si468x_readReply(1,&status);

//	status = 0x80;///////////////////////////////////////

    if (status & USB_STATUS_CTS)
    {
        ctsDirty = 0;
    }	
    LastStatus = status;
   return status;
}

USB_error waitForCts(void)
{
    u16 i=1000;
    USB_error error = USB_error_ok;

    while (--i && !(readStatus() & USB_STATUS_CTS))
    {
        wait_us(500);
    }
    if (!i)
    {
        error = USB_error_poll_timeout;
    }
    return error;
}
//			USB_command(iodata[0], iodata[1], &iodata[3], iodata[2], iodata);
USB_error USB_command(u8 cts, u8 cmdSize, u8 xdata *cmd, u8 replySize, u8 xdata *reply)
{
    USB_error error = USB_error_ok;
    if ((cts==USB_CTS_AUTO && ctsDirty) || (cts == USB_CTS_PRECMD) || (cts == USB_CTS_ALWAYS))
    {
        error = waitForCts();
        if (error) return error;
    }
    USB_writeCommand(cmdSize, cmd);
    if (replySize)
    {
        if ((cts == USB_CTS_AUTO && ctsDirty) || (cts == USB_CTS_POSTCMD) || (cts == USB_CTS_ALWAYS))
        {
            error = waitForCts();
            if (error) return error;
        }
        error = USB_readReply(replySize, reply);
    }
    else if ((cts == USB_CTS_POSTCMD) || (cts == USB_CTS_ALWAYS))
    {
            error = waitForCts();
            if (error) return error;
    }
    return error;
}


USB_error USB_patchDataBurst(u8 byteCount,u8 xdata *patchData)
{
    USB_error error;

#ifdef UPDATE_IMAGE_BY_MCU
	Group_Write_Flash(data_addr,patchData,byteCount);
	data_addr +=byteCount;

	if(data_addr >= 0x00300040)
	{
		error = 1;
	}
#endif

#ifdef UPDATE_IMAGE_BY_TUNER

	u8 i;
		for(i=0;i<byteCount;i++)
		{
			//si468x_writeCommand(byteCount,patchData);
			si468x_write(patchData[i]);
		}

#endif

    return error;
}

extern void si468x_reset(void);
extern void  Radio_Flasher(void);
u8 doCmd(u8 cmd, u8 xdata *iodata)
{
    u8 error = USB_error_ok;
    switch(cmd)
    {
        //case USB_usb_countDevices:
        //    break;
        case cmd_usb_version:
        case cmd_usb_open:
            u16_to_u8ptr(0x0013,iodata);
            break;
        case cmd_usb_close:
            break;
        case cmd_usb_getSerialNumber:
            get_serial_number(iodata);
            break;
        case cmd_usb_setSerialNumber:
            if(iodata[0] == 'C' && (iodata[1] == 'B' || iodata[1] == 'D'))
            {
                set_serial_number(iodata);
            }
            break;
        case cmd_usb_flash:
            if (iodata[0] == 0xde &&iodata[1] == 0xad &&iodata[2] == 0xbe &&iodata[3] == 0xef)
            {
                Radio_Flasher();
            }
			break;
        case cmd_usb_reset:
            si468x_reset();
            break;
        case cmd_usb_writeCommand:
            error = USB_writeCommand(iodata[0], iodata+1);
            break;
        case cmd_usb_readReply://1
            error = USB_readReply(iodata[0], iodata);
            break;
        case cmd_usb_getStatus:
            readStatus(); // this updates LastStatus
            // fallthrough to USB_usb_getLastStatus
        case cmd_usb_getLastStatus:
            iodata[0] = LastStatus;
            break;
        case cmd_usb_patchDataBurst:
            USB_patchDataBurst(iodata[0],iodata+1);
            break;
        case cmd_usb_command:
//USB_error USB_command(u8 cts, u8 cmdSize, u8 xdata *cmd, u8 replySize, u8 xdata *reply)
			error = USB_command(iodata[0], iodata[1], &iodata[3], iodata[2], iodata);
			break;
        default:
            error = USB_error_invalid_command;
    }
    return error;
}


extern bit CommandAvailable;

void usb_process(void)
{
   ctsDirty = 1;
    if (CommandAvailable)
    {
#ifdef OPTION__INCLUDE_POWER_SAVING_MODE
		wake_up_time = NO_KEY_WAKUP_TIME;
#endif //OPTION__INCLUDE_POWER_SAVING_MODE

        ReturnBuffer[1] = doCmd(Command, &ReturnBuffer[2]);
        CommandAvailable = 0;
		while(firmware_download_flag)
		{
			if(CommandAvailable)
			{
        		CommandAvailable = 0;
        		ReturnBuffer[1] = doCmd(Command, &ReturnBuffer[2]);

			}
		}
    }

}
#endif //#ifdef OPTION__USB_DRIVER