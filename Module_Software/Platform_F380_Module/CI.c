/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   command interpreter for mcu flash update for C8051F380 based module
   FILE: CI.c
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#pragma userclass (code = ci)

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

//#ifdef OPTION__USB_DRIVER

#include "USB_REGISTER.h"
#include "USB_MAIN.h"

// Variable Declaration;
idata unsigned char ChipReg;
idata unsigned char CmdBuff[3];
idata unsigned char FlashPage = 0x00;
idata unsigned int PageBase;

// Constants
#define COMMAND_OK	0x01
#define COMMAND_FAILED 0x02
#define UPDATE_PAGE 27

static void SetPage(void);
static void ErasePage(void);
static void WritePage(void);
static void CRConPage(void);
static void ReadFlashByte(void);
static void GetCommand(void);
static void SendByte(unsigned char bData);
static void WaitStatus(void);

/*****************************************************************************
Radio_Flasher()

Description: Main command interpretter routine.  Responsible for decoding
message type and calling correct subroutine.

Inputs: 

Outputs: None

The command to get into the interpretter MUST be set report 0xFF FF AA BB
AA is the current hardware version, BB is the current software version

All Command Interpretter messages are get and set report HID class requests.
Command from the host have report format KK XX YY ZZ

Byte 0 (KK) is the report ID(= 0xFF for all command interpretter messages)
Byte 1 (XX) designates what type of command interpretter message this is.
Byte 2 (YY) has different uses for different messages
Byte 3 (ZZ) has different uses for different messages

Command Interpretter responses are one byte COMMAND_OK(0x01) and where
possible COMMAND_FAILED(0x02), no response is also considered command failed
*****************************************************************************/

//The optimization of this for size (project wide OT(8,SIZE) caused a C51.LIB funciton to be called
//   which breaks update as the LIB is not in the bootloader sector and update failed once the sector which has the lib is erased
//   Restoring the default compiler optimization for this function alone to provide benefit of project wide size reduction without breaking update
#pragma OT(8, SPEED)
void  Radio_Flasher(void) using USB_REGISTER_BANK
{
   EA = OFF;
   EA = OFF;
   POLL_WRITE_BYTE(INDEX, 0);
   POLL_WRITE_BYTE(E0CSR, (rbSOPRDY | rbDATAEND));
   PageBase = 0xFFFF;
   while (1)
   {
      GetCommand();

      switch (CmdBuff[0])
      {
         case 0x00:                          // Get Software Version Command
            // Return report ID byte
            SendByte(1);

            //SendByte(Host_Data[1]);
            SendByte(5);
            WaitStatus();
            break;

         case 0x01:                          // Set Page Command
            SetPage();
            break;

         case 0x02:                          // Erase Page Command
            ErasePage();
            break;

         case 0x03:                          // Write Page Command
            WritePage();
            break;

         case 0x04:                          // CRC on Page Command
            CRConPage();
            break;

         case 0x05:                          // Read Flash Byte Command
            ReadFlashByte();
            break;

         case 0x06:                          // Reset Device/Bus Reset Command
            RSTSRC |= 0x10;
            break;

         case 0x07:                          // Get Hardware Version Command
            // Return report ID byte
            SendByte(1);

            //SendByte(Host_Data[2]);
            SendByte(0xa);
            WaitStatus();
            break;

         default:
            // Return report ID byte
            SendByte(1);

            SendByte(COMMAND_FAILED);
            WaitStatus();
            break;

      }
   }
   return;
}



/*****************************************************************************\
SetPage()

Description: Sets the global variables FlashPage and PageBase. PageBase is the
16-bit address of the first byte of the Flash page.  The contents of FlashPage
and PageBase are used as the target Flash pages for following operations
(Erase, Write, CRC, Go).

Inputs: None

Outputs: None

\*****************************************************************************/
static void SetPage(void) using USB_REGISTER_BANK
{
   unsigned char Page;

   Page = CmdBuff[1];
   if ((Page >= UPDATE_PAGE) && (Page < UPDATE_PAGE+4))
   {
      // Return report ID byte
      SendByte(1);

      SendByte(COMMAND_FAILED);
      WaitStatus();
   }
   else
   {
      FlashPage = Page;
      PageBase = (unsigned int)(FlashPage << 9);   // Convert to 16-bit address

      // Return report ID byte
      SendByte(1);

      SendByte(COMMAND_OK);
      WaitStatus();
   }
   return;
}



/*****************************************************************************\
ErasePage()

Description: The ErasePage routine enables flash erases, writes a dummy data
byte to the currently selected flash page and then disables flash erases.
Note the "address" parameter is of type xdata.  This tricks the compiler into
using MOVX which is required to write to flash in C8051Fxxx devices.

Inputs: None

Outputs: None

\*****************************************************************************/
static void ErasePage(void) using USB_REGISTER_BANK
{
   char xdata * FlashAddress;

   FlashAddress = PageBase;
   FLKEY = 0xA5;
   FLKEY = 0xF1;
   PSCTL = 0x03;           // Enable writes (PSWE) and page erase (PSEE)
   *FlashAddress = 0x00;   // Dummy write to page to initiate erase 
   PSCTL = 0x00;           // Disable writes and page erase


   // Return report ID byte
   SendByte(1);

   SendByte(COMMAND_OK);
   WaitStatus();

  
   return;
}



/*****************************************************************************\
WritePage()

Description: WritePage() programs 512 bytes of data to the currently selected
Flash page starting at the beginning of the page (lowest address).  Once the
download is complete, COMMAND_OK is sent to signal the end of the operation.

Inputs: None

Outputs: None

\*****************************************************************************/
static void WritePage(void) using USB_REGISTER_BANK
{
   unsigned int n = 0;
   char xdata * FlashAddress;


   // Download to Flash.
   FlashAddress = PageBase;                  // Start at base of page
   PSCTL = 0x01;                             // Enable writes

   while (n < 512)
   {
      if (n != 0)
      {
         ChipReg = 0;
         while(!(ChipReg & rbOPRDY))   POLL_READ_BYTE(E0CSR, ChipReg); 
         POLL_WRITE_BYTE(E0CSR, rbSOPRDY);
      }

      ChipReg = 0;
      while(!(ChipReg & rbOPRDY))   POLL_READ_BYTE(E0CSR, ChipReg);

      while(USB0ADR & 0x80);                 // Wait for BUSY->'0' (data ready)
      USB0ADR = (0x80 | FIFO_EP0);           // Set address and initiate read

      ChipReg = 63;

      while ((ChipReg) && (n < 512))
      {
         FLKEY = 0xA5;
         FLKEY = 0xF1;
         while(USB0ADR & 0x80);              // Wait for BUSY->'0' (data ready)
         USB0ADR = (0x80 | FIFO_EP0);        // Set address and initiate read
         ChipReg--;
         n++;
         while(USB0ADR & 0x80);              // Wait for BUSY->'0' (data ready)
         *FlashAddress++ = (USB0DAT);	
      }

      POLL_WRITE_BYTE(E0CSR, (rbSOPRDY | rbDATAEND));
   }

   PSCTL = 0x00;                             // Disable writes
   return;
}



/*****************************************************************************\
CRConPage()

Description: Returns a 16-bit CRC on the currently selected 512-byte Flash
page.  The high byte is sent first followed by the lower byte of the CRC.  No
additional response is transmitted.

Inputs: None

Outputs: None

****************************************************************************/
static void CRConPage(void) using USB_REGISTER_BANK
{
   unsigned int k, j, CRC;
   unsigned char code * data FlashPtr;

   FlashPtr = (unsigned char xdata *)PageBase;
   CRC = 0x0000;

   // Process each byte in the page into the running CRC
   for (k = 0; k < 512; k++)
   {
      // Read the next Flash byte and XOR it with the upper 8 bits
      // of the running CRC.
      CRC ^= (*FlashPtr++ << 8);

      // For each bit in the upper byte of the CRC, shift CRC
      // left, test the MSB, and if set, XOR the CRC with the
      // polynomial coefficients (0x1021)
      for (j = 0; j < 8; j++)
      {
         CRC = CRC << 1;
         if (CRC & 0x8000 ) CRC ^= 0x1021;
      }
   }

   // Return report ID byte
   SendByte(2);

   // Send back the calculated CRC
   SendByte((unsigned char)(CRC & 0x00FF));
   SendByte((unsigned char)(CRC >> 8));

   WaitStatus();
   return;
}



/*****************************************************************************\
ReadFlashByte()

Description: Reads a single byte of Flash located at the 16-bit address held in
the second and third bytes of the command buffer.

Inputs: None

Outputs: None

\*****************************************************************************/
static void ReadFlashByte(void) using USB_REGISTER_BANK
{
   unsigned int Addr16;
   unsigned char code * data FlashPtr;

   // Build 16-bit address
   Addr16 = CmdBuff[1];
   Addr16 = Addr16 << 8;
   FlashPtr = Addr16 | (unsigned int) CmdBuff[2];

   // Return report ID byte
   SendByte(1);

   // Return Flash byte
   SendByte(*FlashPtr);

   WaitStatus();

   return;
}



/*****************************************************************************\
GetCommand()

Description: Polls the USB until a command is received,

Inputs: None

Outputs: None

\*****************************************************************************/
static void GetCommand(void) using USB_REGISTER_BANK
{
   ChipReg = 0;
   while(!(ChipReg & rbOPRDY))   POLL_READ_BYTE(E0CSR, ChipReg);
   POLL_WRITE_BYTE(E0CSR, rbSOPRDY);

   ChipReg = 0;
   while(!(ChipReg & rbOPRDY))   POLL_READ_BYTE(E0CSR, ChipReg);

   while(USB0ADR & 0x80);                    // Wait for BUSY->'0' (data ready)
   USB0ADR = (0x80 | FIFO_EP0);              // Set address and initiate read
   while(USB0ADR & 0x80);                    // Wait for BUSY->'0' (data ready)
   CmdBuff[0] = USB0DAT;

   while(USB0ADR & 0x80);                    // Wait for BUSY->'0' (data ready)
   USB0ADR = (0x80 | FIFO_EP0);              // Set address and initiate read
   while(USB0ADR & 0x80);                    // Wait for BUSY->'0' (data ready)
   CmdBuff[0] = USB0DAT;

   while(USB0ADR & 0x80);                    // Wait for BUSY->'0' (data ready)
   USB0ADR = (0x80 | FIFO_EP0);              // Set address and initiate read
   while(USB0ADR & 0x80);                    // Wait for BUSY->'0' (data ready)
   CmdBuff[1] = USB0DAT;

   while(USB0ADR & 0x80);                    // Wait for BUSY->'0' (data ready)
   USB0ADR = (0x80 | FIFO_EP0);              // Set address and initiate read
   while(USB0ADR & 0x80);                    // Wait for BUSY->'0' (data ready)
   CmdBuff[2] = USB0DAT;

   POLL_WRITE_BYTE(E0CSR, (rbSOPRDY | rbDATAEND));

   ChipReg = 0;
   while(!(ChipReg & rbOPRDY))   POLL_READ_BYTE(E0CSR, ChipReg);
   POLL_WRITE_BYTE(E0CSR, rbSOPRDY);

   return;
}



/*****************************************************************************\
SendByte()

Description: Sends data to USB host

Inputs:
bData - data to send

Outputs: None

\*****************************************************************************/
static void SendByte(BYTE bData) using USB_REGISTER_BANK
{
   while(USB0ADR & 0x80);                    // Wait for BUSY->'0'
   USB0ADR = (FIFO_EP0);                     // Set address

   USB0DAT = bData;
   while(USB0ADR & 0x80);

   return;
}
/*****************************************************************************\
WaitStatus()

Description: Finishes the status phase of USB command

Inputs: None

Outputs: None

\*****************************************************************************/
static void WaitStatus(void) using USB_REGISTER_BANK
{
   POLL_WRITE_BYTE(E0CSR, (rbINPRDY | rbDATAEND));
   return;
}
//#endif //#ifdef OPTION__USB_DRIVER
