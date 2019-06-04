/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   header for usb descriptors for C8051F380 based module
   FILE: usb_descriptor.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#ifndef  _USB_DESC_H_
#define  _USB_DESC_H_

#include <platform_options.h>
//#ifdef OPTION__USB_DRIVER

// BYTE type definition
#ifndef _BYTE_DEF_
#define _BYTE_DEF_
typedef unsigned char BYTE;
#endif   /* _BYTE_DEF_ */

// WORD type definition, for KEIL Compiler
#ifndef _WORD_DEF_              // Compiler Specific, written for Little Endian
#define _WORD_DEF_
typedef union {unsigned int i; unsigned char c[2];} WORD;
#define LSB 1                   // All words sent to and received from the host are
#define MSB 0                   // little endian, this is switched by software when
                                // neccessary.  These sections of code have been marked
                                // with "Compiler Specific" as above for easier modification
#endif   /* _WORD_DEF_ */

// WORD type definition

#ifndef _BYTE3_DEF_
#define _BYTE3_DEF_
typedef unsigned char BYTE3[3];
#endif   /* _BYTE3_DEF_ */

#define HID_REPORT_DESCRIPTOR_SIZE 0x00A3
#define HID_REPORT_DESCRIPTOR_SIZE_LE 0xA300

//------------------------------------------
// Standard Device Descriptor Type Defintion
//------------------------------------------
typedef code struct
{
   BYTE bLength;                // Size of this Descriptor in Bytes
   BYTE bDescriptorType;        // Descriptor Type (=1)
   WORD bcdUSB;                 // USB Spec Release Number in BCD
   BYTE bDeviceClass;           // Device Class Code
   BYTE bDeviceSubClass;        // Device Subclass Code	
   BYTE bDeviceProtocol;        // Device Protocol Code
   BYTE bMaxPacketSize0;        // Maximum Packet Size for EP0 
   WORD idVendor;               // Vendor ID 
   WORD idProduct;              // Product ID
   WORD bcdDevice;              // Device Release Number in BCD
   BYTE iManufacturer;          // Index of String Desc for Manufacturer
   BYTE iProduct;               // Index of String Desc for Product
   BYTE iSerialNumber;          // Index of String Desc for SerNo
   BYTE bNumConfigurations;     // Number of possible Configurations
} device_descriptor;            // End of Device Descriptor Type

//--------------------------------------------------
// Standard Configuration Descriptor Type Definition
//--------------------------------------------------
typedef code struct 
{
   BYTE bLength;                // Size of this Descriptor in Bytes
   BYTE bDescriptorType;        // Descriptor Type (=2)
   WORD wTotalLength;           // Total Length of Data for this Conf
   BYTE bNumInterfaces;         // No of Interfaces supported by this Conf
   BYTE bConfigurationValue;    // Designator Value for *this* Configuration
   BYTE iConfiguration;         // Index of String Desc for this Conf
   BYTE bmAttributes;           // Configuration Characteristics (see below)
   BYTE bMaxPower;              // Max. Power Consumption in this Conf (*2mA)
   BYTE Array[500];
} configuration_descriptor;     // End of Configuration Descriptor Type

//----------------------------------------------
// Standard Interface Descriptor Type Definition
//----------------------------------------------
typedef code struct 
{
   BYTE bLength;                // Size of this Descriptor in Bytes
   BYTE bDescriptorType;        // Descriptor Type (=4)
   BYTE bInterfaceNumber;       // Number of *this* Interface (0..)
   BYTE bAlternateSetting;      // Alternative for this Interface (if any)
   BYTE bNumEndpoints;          // No of EPs used by this IF (excl. EP0)
   BYTE bInterfaceClass;        // Interface Class Code
   BYTE bInterfaceSubClass;     // Interface Subclass Code
   BYTE bInterfaceProtocol;     // Interface Protocol Code
   BYTE iInterface;             // Index of String Desc for this Interface
} interface_descriptor;         // End of Interface Descriptor Type

//----------------------------------------------
// Audio Class Specific Interface Descriptor Type Definition
//----------------------------------------------
typedef code struct 
{
   BYTE bLength;                // Size of this Descriptor in Bytes
   BYTE bDescriptorType;        // Descriptor type (=0x24)
   BYTE bDescriptorSubtype;     // Descriptor subtype
   WORD bcdADC;                 // Revision of class specification - 1.0
   WORD wTotalLength;           // Total size of class specific descriptors
   BYTE bInCollection;          // Number of streaming interfaces
   BYTE baInterfaceNr;          // AudioStreaming interface 1 belongs to this AudioControl Interface
} audio_interface_descriptor;   // End of Audio Interface Descriptor Type

//----------------------------------------------
// Input Terminal Descriptor Type Definition
//----------------------------------------------
typedef code struct 
{
   BYTE bLength;                // Size of this Descriptor in Bytes
   BYTE bDescriptorType;        // Descriptor type
   BYTE bDescriptorSubtype;     // Descriptor subtype
   WORD bTerminalID;            // Unique terminal identification
   WORD wTerminalType;          // Audio terminal type
   BYTE bAssocTerminal;         // TerminalID of associated input/output terminal
   BYTE bNrChannels;            // Number of logical channels in audio cluster
   BYTE wChannelConfig;         // Channel configuration
   BYTE iChannelNames;          // Index of String Desc
   BYTE iTerminal;	            // Index of String Desc for this terminal
} input_terminal_descriptor;    // End of Input Terminal Descriptor Type

//----------------------------------------------
// Output Terminal Descriptor Type Definition
//----------------------------------------------
typedef code struct 
{
   BYTE bLength;                // Size of this Descriptor in Bytes
   BYTE bDescriptorType;        // Descriptor type
   BYTE bDescriptorSubtype;     // Descriptor subtype
   BYTE bTerminalID;            // Unique terminal identification
   WORD wTerminalType;          // Audio terminal type
   BYTE bAssocTerminal;         // TerminalID of associated input/output terminal
   BYTE bSourceID;              // Terminal ID of source
   BYTE iTerminal;              // Index of String Desc for this terminal
} output_terminal_descriptor;   // End of Output Terminal Descriptor Type

//----------------------------------------------
// Audio Class-Specific Stream Interface Descriptor Type Definition
//----------------------------------------------
typedef code struct 
{
   BYTE bLength;                // Size of this Descriptor in Bytes
   BYTE bDescriptorType;        // Descriptor Type (=0x24)
   BYTE bDescriptorSubtype;     // Descriptor subtype
   BYTE bTerminalLink;          // ID of associated terminal
   BYTE bDelay;                 // Interface delay
   WORD wFormatTag;             // Stream format
} stream_interface_descriptor;  // End of Audio Stream Interface Descriptor Type

//----------------------------------------------
// Type I Format Descriptor Type Definition
//----------------------------------------------
typedef code struct 
{
   BYTE bLength;                // Size of this Descriptor in Bytes
   BYTE bDescriptorType;        // Descriptor Type (=0x24)
   BYTE bDescriptorSubtype;     // Descriptor subtype
   BYTE bFormatType;            // Stream format type
   BYTE bNrChannels;            // Number of logical channels
   BYTE bSubFrameSize;          // 
   BYTE bBitResolution;         //
   BYTE bSamFreqType;           //
   BYTE3 bSamFreq;              //
} typeI_format_descriptor;      // End of Type I Format Descriptor Type

//---------------------------------------------
// Standard Endpoint Descriptor Type Definition
//---------------------------------------------
typedef code struct 
{
   BYTE bLength;                // Size of this Descriptor in Bytes
   BYTE bDescriptorType;        // Descriptor Type (=5)
   BYTE bEndpointAddress;       // Endpoint Address (Number + Direction)
   BYTE bmAttributes;           // Endpoint Attributes (Transfer Type)
   WORD wMaxPacketSize;	        // Max. Endpoint Packet Size
   BYTE bInterval;              // Polling Interval (Interrupt) ms
   BYTE ph1;
   BYTE ph2;
} endpoint_descriptor;          // End of Endpoint Descriptor Type

//---------------------------------------------
// Audio Class-Specific Endpoint Descriptor Type Definition
//---------------------------------------------
typedef code struct 
{
   BYTE bLength;                // Size of this Descriptor in Bytes
   BYTE bDescriptorType;        // Descriptor Type (=5)
   BYTE bDescriptorSubtype;     // Descriptor subtype
   BYTE bmAttributes;           // Endpoint Attributes (Transfer Type)
   BYTE bLockDelayUnits;	    // Max. Endpoint Packet Size
   WORD LockDelay;              // Polling Interval (Interrupt) ms
} audio_endpoint_descriptor;    // End of audio Endpoint Descriptor Type

//------------------------------------------
// HID Report Descriptor Type Defintion
//------------------------------------------
typedef code struct
{
   BYTE Array[500];                 // Size of this Descriptor in Bytes
} hid_report_descriptor;            // End of HID Report Descriptor Type

//-----------------------------
// Setup Packet Type Definition
//-----------------------------
typedef struct 
{
   BYTE bmRequestType;          // Request recipient, type, and direction
   BYTE bRequest;               // Specific standard request number
   WORD wValue;                 // varies according to request
   WORD wIndex;                 // varies according to request
   WORD wLength;                // Number of bytes to transfer
} setup_buffer;                 // End of Setup Packet Type

//#endif //OPTION__USB_DRIVER

#endif  /* _USB_DESC_H_ */

