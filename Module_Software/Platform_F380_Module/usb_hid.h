/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   header for usb hid manager for C8051F380 based module
   FILE: usb_hid.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#ifndef _USB_HID_H_
#define _USB_HID_H_

#include <platform_options.h>

#ifdef OPTION__USB_DRIVER

extern u8 idata Command;
extern bit CommandAvailable;
extern u8 xdata ReturnBuffer[64];

#endif //#ifdef OPTION__USB_DRIVER

#endif

