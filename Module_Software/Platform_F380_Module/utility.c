/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   misc utilities for C8051F380 based module
   FILE: utility.c
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/
#include <platform_options.h>
#include "compiler_defs.h"
#include "typedefs.h"
// Includes
#ifdef PLATFORM_F340_DEMOBOARD
	#include "C8051F340_defs.h"
#endif

#ifdef PLATFORM_F380_MODULE
	#include "C8051F380_defs.h"
#endif


#include "utility.h"

//extern const BYTE code SerialNumber[24];



//-----------------------------------------------------------------------------
// convert a UINT16 to a big endian UINT8 array
//-----------------------------------------------------------------------------
#ifdef OPTION__USB_DRIVER
void u16_to_u8ptr(u16 in, u8 xdata *ptr)
{
        ptr[0] = (u8)(in >> 8);
        ptr[1] = (u8)(in);
}
#endif //OPTION_USB_DRIVER
//-------------------------
// Flash functions
//-------------------------
 void flash_page_erase(unsigned int address)
{
        bit EA_SAVE = EA;
        unsigned char VDM0CN_SAVE = VDM0CN;
        char xdata * data pwrite;                       // FLASH write pointer

        EA = 0;                                                                         // Disable interrupts

        pwrite = (char xdata *) address;

        FLKEY  = 0xA5;                                      // Key Sequence 1
        FLKEY  = 0xF1;                                      // Key Sequence 2
        PSCTL |= 0x03;                                      // PSWE = 1; PSEE = 1

        VDM0CN |= 0x80;                                     // enable VDD monitor
        RSTSRC = 0x02;                                      // enable VDD monitor as a reset source

        *pwrite = 0;                                        // initiate page erase

        PSCTL &= ~0x03;                                     // PSWE = 0; PSEE = 0
        EA = EA_SAVE;                                       // restore interrupts
        VDM0CN = VDM0CN_SAVE;
        return;
}
/****************************************************************************************


*****************************************************************************************/
 void flash_write(unsigned int address, unsigned char data1)
{
        bit EA_SAVE = EA;                                    // preserve EA
        unsigned char VDM0CN_SAVE = VDM0CN;
        char xdata * data pwrite;                            // FLASH write pointer

        EA = 0;                                              // disable interrupts
        pwrite = (char xdata *) address;

        FLKEY  = 0xA5;                                       // Key Sequence 1
        FLKEY  = 0xF1;                                       // Key Sequence 2
        PSCTL |= 0x01;                                       // PSWE = 1

        VDM0CN |= 0x80;                                      // enable VDD monitor
        RSTSRC = 0x02;                                       // enable VDD monitor as a reset source

        *pwrite = data1;                                     // write the byte

        PSCTL &= ~0x01;                                      // PSWE = 0
        EA = EA_SAVE;                                        // restore interrupts
        VDM0CN = VDM0CN_SAVE;
        return;
}
/****************************************************************************************


*****************************************************************************************/
 unsigned char flash_read(unsigned int address)
{
        bit EA_SAVE = EA;                                    // preserve EA
        char code * data pread;                              // FLASH read pointer
        unsigned char byte;

        EA = 0;                                              // disable interrupts
        pread = (char code *) address;
        byte = *pread;                                       // read the byte
        EA = EA_SAVE;                                        // restore interrupts
        return byte;
}
/****************************************************************************************


*****************************************************************************************/
#ifdef OPTION__USB_DRIVER
void get_serial_number(char * sn)
{
        u8 i;
        bit EA_SAVE = EA;                                    // preserve EA
        EA = 0;

        for (i=0;i<11;i++)
        {
                sn[i] = flash_read(SERIAL_NUMBER_ADDR+2+(i*2));
        }
        sn[i] = 0;
        EA = EA_SAVE;
}
/****************************************************************************************


*****************************************************************************************/
void set_serial_number(char * sn)
{
        u8 i;
        bit EA_SAVE = EA;                                    // preserve EA
        EA = 0;
        flash_page_erase(SERIAL_NUMBER_ADDR);

        flash_write(SERIAL_NUMBER_ADDR,11*2);
        flash_write(SERIAL_NUMBER_ADDR+1,3);

        for (i=0;i<11;i++)
        {
                flash_write(SERIAL_NUMBER_ADDR+2+(i*2),sn[i]);
                flash_write(SERIAL_NUMBER_ADDR+3+(i*2),0);
        }
        EA = EA_SAVE;
}
#endif //OPTION__USB_DRIVER
//void
//init_serial_number()
//{
//        bit EA_SAVE = EA;                                    // preserve EA
//        EA = 0;
//
//        if ((flash_read(SERIAL_NUMBER_ADDR+0) !=  22) ||
//                (flash_read(SERIAL_NUMBER_ADDR+1) !=   3) ||
//                (flash_read(SERIAL_NUMBER_ADDR+2) != 'G') ||
//                (flash_read(SERIAL_NUMBER_ADDR+3) !=   0) ||
//                (flash_read(SERIAL_NUMBER_ADDR+4) != 'A') ||
//                (flash_read(SERIAL_NUMBER_ADDR+5) !=   0))
//        {
//                set_serial_number("GA000-00-00");
//        }
//        EA = EA_SAVE;
//}

