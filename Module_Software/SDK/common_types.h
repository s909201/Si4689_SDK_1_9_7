/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   Non-specific types needed for the SDK
   FILE: common_types.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#ifndef _COMMON_TYPES_
#define _COMMON_TYPES_

#include <platform_options.h>

// Other platforms will require the error codes to be defined
#define SUCCESS			0x00
#define HAL_ERROR		0x01
#define INVALID_INPUT	0x02
#define INVALID_MODE	0x04
#define TIMEOUT			0x08
#define COMMAND_ERROR	0x20
#define UNSUPPORTED_FUNCTION	0x80

typedef unsigned char	uint8_t;
typedef signed char		int8_t;
typedef unsigned short	uint16_t;
typedef signed short	int16_t;
typedef uint8_t		    RETURN_CODE;

#ifdef OPTION__32BIT_IS_LONG
typedef unsigned long	uint32_t;
typedef signed long		int32_t;
#else
typedef unsigned int	uint32_t;
typedef signed int		int32_t;
#endif

//This matches the definition in GET_SYS_STATE with supplemental types for fmonly and patches
typedef enum _RADIO_MODE_TYPE {
	fmonly = 0,
    fmhd = 1,
	dab = 2,
	dmb = 3, //Also known as data only DAB
    fmdemod = 4,
	am = 5,
	amhd = 6,

    determine_part = 0xE0,
    patch_full = 0xE1,

    //Need to have a patch type for each mode as the patches could be different
    patch_fmhd = 0xF1,
    patch_dab = 0xF2,
    patch_dmb = 0xF3,
    patch_demod = 0xF4,
    patch_am = 0xF5,
	patch_amhd = 0xF6,

    patch_firmware_update = 0xFD,
    patch_mini = 0xFE,
	UNKNOWN
}RADIO_MODE_TYPE;

typedef enum _FM_BAND_LIMITS {
    JAPAN_76_90,
    STANDARD_875_1079,
    WIDE_78_108
}FM_BAND_LIMITS;

#ifdef OPTION__FORCE_MEMORY_SPACES
    #define MEMORY_SPACE__CODE code
#else
    #define MEMORY_SPACE__CODE
#endif

//Creating macros which can easily be replaced for alternate platforms during porting - if necessary.
//**********************************************************************

#ifdef PLATFORM_EVB
    #include <string.h> //Needed for memory operations
    #define ClearMemory(ptr, num) memset((ptr), 0, (num))
    #define CpyMemory(dPtr, sPtr, num) memcpy((dPtr), (sPtr), (num))
    #define CompareMemory(ptr1, ptr2, num) memcmp((ptr1), (ptr2), (num))
#else
    void ClearMemory(uint8_t* ptr, uint16_t num);
    void CpyMemory(uint8_t* dPtr, uint8_t* sPtr, uint16_t num);
    uint8_t CompareMemory(uint8_t* ptr1, uint8_t* ptr2, uint16_t num);
#endif
//**********************************************************************


#endif