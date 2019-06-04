/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   usb hid manager for C8051F380 based module
   FILE: usb_hid.c
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#include <platform_options.h>

// Includes
#include "compiler_defs.h"
#include "typedefs.h"

#ifdef PLATFORM_F340_DEMOBOARD
	#include "C8051F340_defs.h"
#endif

#ifdef PLATFORM_F380_MODULE
	#include "C8051F380_defs.h"
#endif

#ifdef OPTION__USB_DRIVER

#include "usb_register.h"
#include "usb_main.h"
#include "usb_descriptor.h"


// Variable Declaration
u8 xdata ReturnBuffer[64];
u8 idata Command;
bit CommandAvailable;

// External Variables
extern setup_buffer Setup;
extern unsigned int DataSize;
extern unsigned int DataSent;
extern BYTE* DataPtr;
extern BYTE Ep_Status[];                     // Endpoint status array


#define ERROR_RETRY 0x7F

/*****************************************************************************\
Set_Idle()

Description: Sets the idle feature on interrupt in endpoint.

Inputs: None

Outputs: None

\*****************************************************************************/
void Set_Idle(void) using USB_REGISTER_BANK
{
   if (Ep_Status[0] != EP_STALL)
   {
      // Set serviced Setup Packet
      POLL_WRITE_BYTE(E0CSR, (rbSOPRDY | rbDATAEND));
   }
}



/*****************************************************************************\
Get_Report()

Description: Sends a given report type to the host.

Inputs: None

Outputs: None

\*****************************************************************************/
void Get_Report(void) using USB_REGISTER_BANK
{
   ReturnBuffer[0] = Setup.wValue.c[LSB];
   
   //DataSize = 64;
   DataSize = ReturnBuffer[0]+1;

   DataPtr = (BYTE*)&ReturnBuffer;

   if (Ep_Status[0] != EP_STALL)
   {
      POLL_WRITE_BYTE(E0CSR, rbSOPRDY);      // Set serviced Setup Packet
      Ep_Status[0] = EP_TX;                  // Endpoint 0 in transmit mode
      DataSent = 0;                          // Reset DataSent counter
   }
}



/*****************************************************************************\
Set_Report()

Description: Receives a report sent from the host.

Inputs: None

Outputs: None

\*****************************************************************************/
void Set_Report(void) using USB_REGISTER_BANK
{
   DataPtr = (BYTE*)&ReturnBuffer;
   DataSize = Setup.wLength.i;

   if (Ep_Status[0] != EP_STALL)
   {
      POLL_WRITE_BYTE(E0CSR, rbSOPRDY);      // Set serviced Setup Packet
      Ep_Status[0] = EP_RX;                  // Endpoint 0 in receive mode
      DataSent = 0;                          // Reset DataSent counter
   }
}

/*****************************************************************************\
Handle_Set_Report()

Description: Sends a report received from the host to the Si470x.

Inputs: None

Outputs: None

\*****************************************************************************/
void Handle_Set_Report(void) using USB_REGISTER_BANK
{
	CommandAvailable = 1;
	Command = ReturnBuffer[1];
	ReturnBuffer[1] = ERROR_RETRY;
}

#endif //#ifdef OPTION__USB_DRIVER