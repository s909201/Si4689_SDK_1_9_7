/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   Main entry for C8051F380 based module
   FILE: main.c
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#define _MAIN_C_

#include "typedefs.h"
#include "compiler_defs.h"

#include <string.h>
#include "main.h"
#include "sys.h"
#include "LCD.h"
#include "delay.h"
#include "key.h"
#include "Firmware_API_Manager.h"
#include "mode_common.h"
#include "mode_other.h"
#include "in_chip_eeprom.h"

#ifdef OPTION__USB_DRIVER
	#include "usb_process.h"
#endif

#ifdef PLATFORM_F340_DEMOBOARD
	#include "SST25VF032B.h"
#endif

#ifdef PLATFORM_F380_MODULE
	#include "EEPROM.h"
#endif

#ifdef  ATS_EMBED_CODE
	#include "uart.h"
#endif

#ifdef OPTION__OPERATE_AS_SLAVE_NO_MMI
	#include "mode_slave.h"
#endif
//sbit temp = P0^5;
/************************************************************************

************************************************************************/
void main()
{
    RETURN_CODE ret = 0;
	Init_Device();
	Init_variable();
	while(1)
	{
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
		ret |=time_update();
		key_scan();
		idle_mode();
		ret |= key_process();
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI

		ret |= state_update();
		ret |= work_mode_process();
		ret |= display_mode_update();

#ifdef OPTION__OPERATE_AS_SLAVE_NO_MMI
		slave_receive_cmd();
#endif		

#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
	#ifndef NO_ALARM_HARDWARE_REMOVE_ALARM_CODE
		detect_alarm();
	#endif //NO_ALARM_HARDWARE_REMOVE_ALARM_CODE
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI

#ifdef OPTION__USB_DRIVER
        usb_process();
#endif //OPTION__USB_DRIVER

#ifdef ATS_EMBED_CODE
		if(ship_ats_inter_flag != ATS_SHIP_SETTING)
		{
			ats_cmd_process();
		}
#endif		
	}
	ret = Finalize();
}

