/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   usb interrupt handler for C8051F380 based module
   FILE: usb_isr.c
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

// Includes

#include <platform_options.h>
#include "compiler_defs.h"
#include "typedefs.h"

#ifdef PLATFORM_F340_DEMOBOARD
	#include "C8051F340_defs.h"
#endif

#ifdef PLATFORM_F380_MODULE
	#include "C8051F380_defs.h"
#endif

#ifdef OPTION__USB_DRIVER

#include "usb_main.h"
#include "usb_descriptor.h"
#include "usb_register.h"

// Variable Declaration
BYTE USB_State;                                    // Holds the USB State
setup_buffer Setup;                                // Buffer for device request
unsigned int DataSize;                             // Size of data to return
unsigned int DataSent;                             // Amount of data sent
BYTE* DataPtr;                                     // Pointer to data to return
BYTE Ep_Status[3] = {EP_IDLE, EP_IDLE, EP_IDLE};   // Endpoint status array

// External Variables
extern data WORD WriteBlock[];



/*****************************************************************************\
Usb_ISR()

Description: Called after any USB type interrupt, this handler determines which
type of interrupt occurred, and calls the specific routine to handle it.

Inputs: None

Outputs: None

\*****************************************************************************/
void Usb_ISR(void) interrupt 8 using USB_REGISTER_BANK
{
   BYTE bCommon, bIn;
   BYTE ControlReg;
   POLL_READ_BYTE(CMINT, bCommon);      // Read all interrupt registers
   POLL_READ_BYTE(IN1INT, bIn);         // this read also clears the register

   if (bCommon)
   {
      if (bCommon & rbSOF)
      {
         POLL_WRITE_BYTE(INDEX, 3);
         POLL_READ_BYTE(EINCSR1, ControlReg);

         if (ControlReg & rbInUNDRUN)
         {
            POLL_WRITE_BYTE(EINCSR1, 0x00);  // Clear under run bit
         }
      }

      if (bCommon & rbRSTINT) Usb_Reset();   // Handle Reset interrupt
      if (bCommon & rbSUSINT) Usb_Suspend(); // Handle Suspend interrupt
   }

   if (bIn & rbEP0)                  
   {
      if (TR2)
      {
         bIn &= ~rbIN3;                      // Turn off transmit complete
      }
                                     
      // Handle Setup packet received or transmitted
      Handle_Setup();
   }
}



/*****************************************************************************\
Usb_Reset()

Description: Clears USB inhibit bit and sets endpoint states to default.

Inputs: None

Outputs: None

\*****************************************************************************/
void Usb_Reset(void) using USB_REGISTER_BANK
{
   USB_State = DEV_DEFAULT;                  // Set device state to default

   // Clear usb inhibit bit, enable suspend detection, turn off ISO update
   POLL_WRITE_BYTE(POWER, 0x01);             

   Ep_Status[0] = EP_IDLE;                   // Set default Endpoint Status
   Ep_Status[1] = EP_HALT;
   Ep_Status[2] = EP_HALT;
}



/*****************************************************************************\
Handle_Setup()

Description: Decodes incoming setup requests, loads data packets on fifo in
transmit mode, and retrieves data from fifo in receive mode

Inputs: None

Outputs: None

\*****************************************************************************/
void Handle_Setup(void) using USB_REGISTER_BANK                    
{                                   
   BYTE ControlReg;                          // Storage for EP control register

   POLL_WRITE_BYTE(INDEX, 0);                // Set Index to Endpoint Zero
   POLL_READ_BYTE(E0CSR, ControlReg);        // Read control register

   // Handle Status Phase of Set Address command
   if (Ep_Status[0] == EP_ADDRESS)
   {
      POLL_WRITE_BYTE(FADDR, Setup.wValue.c[LSB]);
      Ep_Status[0] = EP_IDLE;
   }

   // If last packet was a sent stall, reset STSTL bit and return EP0 to idle
   if (ControlReg & rbSTSTL)
   {
      POLL_WRITE_BYTE(E0CSR, 0);
      Ep_Status[0] = EP_IDLE;
      return;
   }

   // If last setup transaction was ended prematurely set Serviced Setup End
   // bit and return EP0 to idle state
   if (ControlReg & rbSUEND)
   {
      POLL_WRITE_BYTE(E0CSR, rbSSUEND);
      Ep_Status[0] = EP_IDLE;
   }

   if (Ep_Status[0] == EP_IDLE)              // If Endpoint 0 is in idle mode
   {
      // Make sure that EP 0 has an Out Packet ready from host although if EP0 
      // is idle, this should always be the case
      if (ControlReg & rbOPRDY)
      {
         // Get Setup Packet off of Fifo, it is currently Big-Endian
         Fifo_Read(FIFO_EP0, 8, (BYTE *)&Setup);


         // Compiler Specific - these next three statements swap the
			// bytes of the setup packet words to Big Endian so they
			// can be compared to other 16-bit values elsewhere properly
         Setup.wValue.i = Setup.wValue.c[MSB] + 256*Setup.wValue.c[LSB];
         Setup.wIndex.i = Setup.wIndex.c[MSB] + 256*Setup.wIndex.c[LSB];
         Setup.wLength.i = Setup.wLength.c[MSB] + 256*Setup.wLength.c[LSB];
                                        
         if ((Setup.bmRequestType & TYPE_MASK) == CLASS_TYPE)
		   {
            // Call correct subroutine to handle each kind of
            // class-specific request
            switch (Setup.bRequest)               
            {
               case SET_IDLE:          Set_Idle();          break;
               case GET_REPORT:        Get_Report();        break;
               case SET_REPORT:        Set_Report();        break;
                 
               // Send stall to host if invalid request          
               default:                Force_Stall();       break;   
                
            }
         }
   		else
   		{
            // Call correct subroutine to handle each kind of 
            // standard request
            switch (Setup.bRequest)        
            {                              
               case GET_STATUS:        Get_Status();        break;             
               case CLEAR_FEATURE:     Clear_Feature();     break;
               case SET_FEATURE:       Set_Feature();       break;
               case SET_ADDRESS:       Set_Address();       break;
               case GET_DESCRIPTOR:    Get_Descriptor();    break;
               case GET_CONFIGURATION: Get_Configuration(); break;
               case SET_CONFIGURATION: Set_Configuration(); break;
               case GET_INTERFACE:     Get_Interface();     break;
               case SET_INTERFACE:     Set_Interface();     break;

               // Send stall to host if invalid request
               default:                Force_Stall();       break;
            }
         }
      }
   } 

   if (Ep_Status[0] == EP_TX)                // See if endpoint should transmit
   {
      if (!(ControlReg & rbINPRDY))          // Don't overwrite last packet
      {
         POLL_READ_BYTE(E0CSR, ControlReg);  // Read control register
		 
         // Check to see if Setup End or Out Packet received, if so do not put 
         // any new data on FIFO
         if ((!(ControlReg & rbSUEND)) || (!(ControlReg & rbOPRDY)))
         {
            // Add In Packet ready flag to E0CSR bitmask
            ControlReg = rbINPRDY;              
            if (DataSize >= EP0_PACKET_SIZE)
            {
               // Break Data into multiple packets if larger than Max Packet
               Fifo_Write(FIFO_EP0, EP0_PACKET_SIZE, (BYTE *)DataPtr);
               DataPtr  += EP0_PACKET_SIZE;  // Advance data pointer
               DataSize -= EP0_PACKET_SIZE;  // Decrement data size
               DataSent += EP0_PACKET_SIZE;  // Increment data sent counter
            }
            else                             
            {
               // If data is less than Max Packet size or zero
               Fifo_Write(FIFO_EP0, DataSize, (BYTE *)DataPtr);
               ControlReg |= rbDATAEND;      // Add Data End bit to bitmask
               Ep_Status[0] = EP_IDLE;       // Return EP 0 to idle state
            }
            if (DataSent == Setup.wLength.i)
            {      
               // This case exists when the host requests an even multiple of
               // your endpoint zero max packet size, and you need to exit
               // transmit mode without sending a zero length packet
               ControlReg |= rbDATAEND;      // Add Data End bit to mask
               Ep_Status[0] = EP_IDLE;       // Return EP 0 to idle state
            }
            POLL_WRITE_BYTE(E0CSR, ControlReg); // Write mask to E0CSR
         }
      }
   }

   if (Ep_Status[0] == EP_RX)                // See if endpoint should transmit
   {
      POLL_READ_BYTE(E0CSR, ControlReg);     // Read control register
      if (ControlReg & rbOPRDY)              // Verify packet was received
      {
         ControlReg = rbSOPRDY;
   		if (DataSize >= EP0_PACKET_SIZE)
   		{
            Fifo_Read(FIFO_EP0, EP0_PACKET_SIZE, (BYTE *)DataPtr);
            DataPtr  += EP0_PACKET_SIZE;     // Advance data pointer
            DataSize -= EP0_PACKET_SIZE;     // Decrement data size
            DataSent += EP0_PACKET_SIZE;     // Increment data sent counter
   		}
   		else
   		{
            Fifo_Read(FIFO_EP0, DataSize, (BYTE *)DataPtr);
   			ControlReg |= rbDATAEND;
   			Ep_Status[0] = EP_IDLE;
   		}
   		if (DataSent == Setup.wLength.i)
   		{
   			ControlReg |= rbDATAEND;
   			Ep_Status[0] = EP_IDLE;
   		}
         if ((Ep_Status[0] == EP_IDLE) && (Setup.bRequest == SET_REPORT))
         {
            Handle_Set_Report();
         }
         POLL_WRITE_BYTE(E0CSR, ControlReg);
      }
   }	
}



/*****************************************************************************\
Usb_Suspend()

Description: Power down all hardware and halt oscillator when suspend 
signalling present on bus.

Inputs: None

Outputs: None

\*****************************************************************************/
void Usb_Suspend(void) using USB_REGISTER_BANK
{
   volatile int k;
   k++;
}



/*****************************************************************************\
Fifo_Read()

Description: Read data from selected endpoint FIFO.

Inputs:
addr - target address
uNumBytes - number of bytes to read
pData - destination for read data

Outputs: None

\*****************************************************************************/
void Fifo_Read(BYTE addr, UINT uNumBytes, BYTE* pData) using USB_REGISTER_BANK
{
   UINT i;

   if (uNumBytes)                            // Check if >0 bytes requested,
   {      
      USB0ADR = (addr);                      // Set address
      USB0ADR |= 0xC0;                       // Set auto-read and initiate 
                                             // first read      

      // Unload <NumBytes> from the selected FIFO
      for (i=0;i<uNumBytes-1;i++)
      {         
         while (USB0ADR & 0x80);             // Wait for BUSY->'0' (data ready)
         pData[i] = USB0DAT;                 // Copy data byte
      }

      USB0ADR = 0;                           // Clear auto-read

      while (USB0ADR & 0x80);                // Wait for BUSY->'0' (data ready)
      pData[i] = USB0DAT;                    // Copy data byte
   }
}



/*****************************************************************************\
Fifo_Write()

Description: Writes data to selected endpoint FIFO.

Inputs:
addr - target address
uNumBytes - number of bytes to write
pData - location of source data

Outputs: None

\*****************************************************************************/
void Fifo_Write(BYTE addr, UINT uNumBytes, BYTE* pData) using USB_REGISTER_BANK
{
   UINT i;
                                          
   // If >0 bytes requested,
   if (uNumBytes) 
   {
      while (USB0ADR & 0x80);                // Wait for BUSY->'0'
                                             // (register available)
      USB0ADR = (addr);                      // Set address (mask out bits7-6)

      // Write <NumBytes> to the selected FIFO
      for (i=0;i<uNumBytes;i++)
      {  
         USB0DAT = pData[i];
         while (USB0ADR & 0x80);             // Wait for BUSY->'0' (data ready)
      }
   }
}


#if 0
/*****************************************************************************\
Fifo_Purge()

Description: Purges one packet from the selected endpoint in FIFO.

Inputs:
Index - which endpoint to purge

Outputs: None

\*****************************************************************************/
void Fifo_Purge(BYTE Index) using USB_REGISTER_BANK
{                                         
   POLL_WRITE_BYTE(INDEX, Index);            // Set Index
   POLL_WRITE_BYTE(EINCSR1, rbInFLUSH);      // Flush In Fifo
}
#endif


/*****************************************************************************\
Force_Stall()

Description: Sends a procedural stall to the host.

Inputs: None

Outputs: None

\*****************************************************************************/
void Force_Stall(void) using USB_REGISTER_BANK
{
   POLL_WRITE_BYTE(INDEX, 0);
   POLL_WRITE_BYTE(E0CSR, rbSDSTL);          // Set the send stall bit
   Ep_Status[0] = EP_STALL;                  // Put the endpoint in stall state
}
#endif //#ifdef OPTION__USB_DRIVER