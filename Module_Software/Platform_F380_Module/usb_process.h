/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   header for entry point for usb command handler for C8051F380 based module
   FILE: usb_process.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#ifndef _USB_PROCESS_H_
#define _USB_PROCESS_H_

#include <platform_options.h>

#ifdef OPTION__USB_DRIVER


void usb_process(void);

void release_gpio(unsigned char pin);
u8 readStatus(void);

#define USB_error  u8

#define cmd_usb_open                   0x00
#define cmd_usb_version                0x01
#define cmd_usb_close                  0x02
#define cmd_usb_getSerialNumber        0x03
#define cmd_usb_setSerialNumber        0x04
#define cmd_usb_reset                  0x05
#define cmd_usb_command                0x06
#define cmd_usb_setBusMode             0x07
#define cmd_usb_setSfr                 0x08
#define cmd_usb_getSfr                 0x09
#define cmd_usb_rxGetRdsFifo           0x0A
#define cmd_usb_rxAutoseekStart        0x0B
#define cmd_usb_rxAutoseekStatus       0x0C
#define cmd_usb_rxScanStart            0x0D
#define cmd_usb_rxScanStatus           0x0E
#define cmd_usb_rxSearchAbort          0x0F
#define cmd_usb_setOpMode              0x10
#define cmd_usb_getStatus              0x11
#define cmd_usb_getLastStatus          0x12
#define cmd_usb_writeCommand           0x13
#define cmd_usb_readReply              0x14
#define cmd_usb_setReg                 0x15
#define cmd_usb_getReg                 0x16
#define cmd_usb_patchDataBurst         0x17
#define cmd_usb_flash				0xFF



#define USB_CTS_AUTO           (0)
#define USB_CTS_PRECMD         (1)
#define USB_CTS_POSTCMD        (2)
#define USB_CTS_ALWAYS         (3)
#define USB_CTS_NEVER          (4)



// Status bits
#define USB_STATUS_CTS         (1<<7)
#define USB_STATUS_ERR         (1<<6)
#define USB_STATUS_RDSINT      (1<<2)
#define USB_STATUS_RSQINT      (1<<1)
#define USB_STATUS_STCINT      (1<<0)


#define USB_error_ok                     0x00
#define USB_error_invalid_command        0x01
#define USB_error_search_in_progress     0x02
#define USB_error_poll_timeout           0x03
#define USB_error_retry                  0x7f
#define USB_error_invalid_handle         0x80
#define USB_error_invalid_parameter      0x81
#define USB_error_device_disconnected    0x82
#define USB_error_device_timeout         0x83
#define USB_error_unimplemented          0x84
#define USB_error_errbit                 0xF0
#define USB_error_test1                  0x47


#endif //#ifdef OPTION__USB_DRIVER

#endif
