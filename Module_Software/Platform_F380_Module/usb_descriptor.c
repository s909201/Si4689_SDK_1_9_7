/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   usb descriptors for C8051F380 based module
   FILE: usb_descriptor.c
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#include <platform_options.h>
#ifdef OPTION__USB_DRIVER

// Includes
#include "compiler_defs.h"
#include "typedefs.h"
#ifdef PLATFORM_F340_DEMOBOARD
	#include "C8051F340_defs.h"
#endif

#ifdef PLATFORM_F380_MODULE
	#include "C8051F380_defs.h"
#endif



#include "usb_main.h"
#include "usb_descriptor.h"


//---------------------------
// Descriptor Declarations
//---------------------------
const device_descriptor code DeviceDesc = 
{
   0x12,                // bLength
   0x01,                // bDescriptorType
   0x1001,              // bcdUSB
   0x00,                // bDeviceClass
   0x00,                // bDeviceSubClass
   0x00,                // bDeviceProtocol
   EP0_PACKET_SIZE,     // bMaxPacketSize0
   0xC410,              // idVendor
   0x4482,              // idProduct 
   0x0001,              // bcdDevice 
   0x01,                // iManufacturer
   0x02,                // iProduct     
   0x03,                // iSerialNumber
   0x01                 // bNumConfigurations
}; //end of DeviceDesc
#if 0
const configuration_descriptor code ConfigDesc = 
{
   0x09,                // Length
   0x02,                // Type
   0x1B00,              // Totallength
   0x01,                // NumInterfaces
   0x01,                // bConfigurationValue
   0x00,                // iConfiguration
   0x80,                // bmAttributes
   0x32,                // MaxPower


// remove 25 byte HID interface
0x09,					// bLength
0x04,					// bDescriptorType (4)
0x00,					// bInterfaceNumber
0x00,					// bAlternateSetting
0x00,					// bNumEndpoints
0x03,					// bInterfaceClass
0x00,					// bDeviceProtocol
0x00,
0x00,

0x09,
0x21,
0x11,0x01,
0x00,
0x01,
0x22,
27,0x00, // 31 byte report
//25
};

// HID descriptor
const hid_report_descriptor code HidReportDesc = 
{
0x06, 0x00, 0xFF,             // USAGE_PAGE (Vendor Defined Page 1)
0x09, 0x01,                   // USAGE (Vendor Usage 1)
0xA1, 0x01,                   // COLLECTION (Application)
    
0x09, 0x01,                   // USAGE (Vendor Usage 1)
0x75, 0x08,                   // REPORT_SIZE (8)
0x95, 0x01,                   //	DEFAULT REPORT COUNT (1)	
0x26, 0xFF, 0x00,             // LOGICAL_MAXIMUM (255)
0x15, 0x00,                   // LOGICAL_MINIMUM (0)
//18

0x85, 63,                   // REPORT_ID (1)
0x95, 63,                     // REPORT_COUNT (2)
0x09, 0x01,                   // USAGE (Vendor Usage 1)
0xB1, 0x02,                   // FEATURE (Data,Var,Abs)
    
0xC0                          // END_COLLECTION
//27
}; //end of ConfigDesc

#else
const configuration_descriptor code ConfigDesc = 
{
   0x09,                // Length
   0x02,                // Type
   0x1B00,              // Totallength
   0x01,                // NumInterfaces
   0x01,                // bConfigurationValue
   0x00,                // iConfiguration
   0x80,                // bmAttributes
   0x32,                // MaxPower


// remove 25 byte HID interface
0x09,					// bLength
0x04,					// bDescriptorType (4)
0x00,					// bInterfaceNumber
0x00,					// bAlternateSetting
0x00,					// bNumEndpoints
0x03,					// bInterfaceClass
0x00,					// bDeviceProtocol
0x00,
0x00,

0x09,
0x21,
0x11,0x01,
0x00,
0x01,
0x22,
75,0x00, // 19 + 7*8 byte report
//25
};

// HID descriptor
const hid_report_descriptor code HidReportDesc = 
{
0x06, 0x00, 0xFF,             // USAGE_PAGE (Vendor Defined Page 1)
0x09, 0x01,                   // USAGE (Vendor Usage 1)
0xA1, 0x01,                   // COLLECTION (Application)
    
0x09, 0x01,                   // USAGE (Vendor Usage 1)
0x75, 0x08,                   // REPORT_SIZE (8)
0x95, 0x01,                   //	DEFAULT REPORT COUNT (1)	
0x26, 0xFF, 0x00,             // LOGICAL_MAXIMUM (255)
0x15, 0x00,                   // LOGICAL_MINIMUM (0)
//18

0x85, 63,                     // REPORT_ID (63)
0x95, 63,                     // REPORT_COUNT (63)
0x09, 0x01,                   // USAGE (Vendor Usage 1)
0xB1, 0x02,                   // FEATURE (Data,Var,Abs)

0x85, 0x1,                   // REPORT_ID (63)
0x95, 1,                     // REPORT_COUNT (63)
0x09, 0x01,                   // USAGE (Vendor Usage 1)
0xB1, 0x02,                   // FEATURE (Data,Var,Abs)

0x85, 0x02,                   // REPORT_ID (2)
0x95, 2,                      // REPORT_COUNT (2)
0x09, 0x01,                   // USAGE (Vendor Usage 1)
0xB1, 0x02,                   // FEATURE (Data,Var,Abs)

0x85, 0x03,                   // REPORT_ID (2)
0x95, 3,                      // REPORT_COUNT (2)
0x09, 0x01,                   // USAGE (Vendor Usage 1)
0xB1, 0x02,                   // FEATURE (Data,Var,Abs)

0x85, 0x04,                   // REPORT_ID (2)
0x95, 4,                      // REPORT_COUNT (2)
0x09, 0x01,                   // USAGE (Vendor Usage 1)
0xB1, 0x02,                   // FEATURE (Data,Var,Abs)

0x85, 0x05,                   // REPORT_ID (2)
0x95, 5,                      // REPORT_COUNT (2)
0x09, 0x01,                   // USAGE (Vendor Usage 1)
0xB1, 0x02,                   // FEATURE (Data,Var,Abs)
    
0x85, 0x06,                   // REPORT_ID (2)
0x95, 6,                      // REPORT_COUNT (2)
0x09, 0x01,                   // USAGE (Vendor Usage 1)
0xB1, 0x02,                   // FEATURE (Data,Var,Abs)
    
0xC0                          // END_COLLECTION
//18 + 1 + 7*8
}; //end of ConfigDesc


#endif

#define STR0LEN 4

const BYTE code String0Desc[STR0LEN] =
{
   STR0LEN, 0x03, 0x09, 0x04
}; //end of String0Desc

#define STR1LEN sizeof("SILICON LABORATORIES INC.")*2

const BYTE code String1Desc[STR1LEN] =
{
   STR1LEN, 0x03,
   'S', 0,
   'I', 0,
   'L', 0,
   'I', 0,
   'C', 0,
   'O', 0,
   'N', 0,
   ' ', 0,
   'L', 0,
   'A', 0,
   'B', 0,
   'O', 0,
   'R', 0,
   'A', 0,
   'T', 0,
   'O', 0,
   'R', 0,
   'I', 0,
   'E', 0,
   'S', 0,
   ' ', 0,
   'I', 0,
   'N', 0,
   'C', 0,
   '.', 0
  }; //end of String1Desc

#define PRODLEN (sizeof("Si468x Demoboard")*2)
const BYTE code ProductName[PRODLEN] = {
	PRODLEN, 0x03,
	'S', 0,
	'i', 0,
	'4', 0,
	'6', 0,
	'8', 0,
	'x', 0,
	' ', 0,
	'D', 0,
	'e', 0,
	'm', 0,
	'o', 0,
	'b', 0,
	'o', 0,
	'a', 0,
	'r', 0,
	'd', 0
};
#define SERIAL_NUMBER_ADDR 0x3600
//const BYTE code SerialNumber[24] _at_ SERIAL_NUMBER_ADDR;
const BYTE code SerialNumber[512] _at_ SERIAL_NUMBER_ADDR;

BYTE* const code StringDescTable[] = 
{
   String0Desc,
   String1Desc,
   ProductName,
   SerialNumber
};

#endif//#ifdef OPTION__USB_DRIVER