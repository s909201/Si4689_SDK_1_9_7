/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   MMI specific type definitions
   FILE: typedefs.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#ifndef _typed_h_
#define _typed_h_

typedef  unsigned char u8;
typedef  unsigned int  u16;
typedef  unsigned long  u32;

#define false 0
#define true  1

typedef struct _time_struct
{
 	u8 sec;
 	u8 min;
 	u8 hour;
 	u8 day;
 	u8 week;
 	u8 month;
 	u8 year;
}time_struct;

typedef struct _dab_preset_struct
{
	u8 valid;
	u8 freq_index;	
	u32 service_id;
	u16 component_id;
	u8 label_str[17];//16+1 the last one character is '\n'
}dab_preset_struct;

typedef struct _fmhd_preset_struct
{
	u8 valid;
	u16 frequency;
	u8 component_id;
	u8 service_name[6];//if service_name == 0xFF,0xFF... mean it is a analog station,not digital
}fmhd_preset_struct;

typedef struct _amhd_preset_struct
{
	u8 valid;
	u16 frequency;
	u8 component_id;
	u8 service_name[6];//if service_name == 0xFF,0xFF... mean it is a analog station,not digital
}amhd_preset_struct;


#endif