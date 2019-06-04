/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   SDK HD radio PSD decoder header
   FILE: FMHD_PSD_Handler.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/


#ifndef __FMHD_PSD_HANDLER__
#define __FMHD_PSD_HANDLER__

#include "common_types.h"
#include "platform_options.h"
#include "feature_types.h"
#include "si46xx_firmware_api.h"

#ifdef OPTION__INCLUDE_MODE__FMHD
#ifdef OPTION__DECODE_PSD
//-----------------------------------------------------------------------------
// Defines
//-----------------------------------------------------------------------------
#ifdef OPTION__PSD_FORMAT_ID3
#define PSD_CID_MPS 0x5100
#define PSD_CID_SPS1 0x5201
#define PSD_CID_SPS2 0x5202
#define PSD_CID_SPS3 0x5203
#define PSD_CID_SPS4 0x5204
#define PSD_CID_SPS5 0x5205
#define PSD_CID_SPS6 0x5206
#define PSD_CID_SPS7 0x5207
#endif

//-----------------------------------------------------------------------------
// Globals
//-----------------------------------------------------------------------------
extern fmhd_psd_generic_string titleDisplay;   // Displayed PSD Title for current program
extern fmhd_psd_generic_string artistDisplay;  // Displayed PSD Artist for current program
extern fmhd_psd_generic_string albumDisplay;   // Displayed PSD Album for current program
extern fmhd_psd_generic_string genreDisplay;   // Displayed PSD Genre for current program

//-----------------------------------------------------------------------------
// Function prototypes
//-----------------------------------------------------------------------------
void initPSD(void);

#ifdef OPTION__PSD_FORMAT_ID3
void updatePSD(get_digital_service_data__data psdData);
#else
void updatePSD(FMHD_PSD_FIELD_DATA_TYPE field, fmhd_get_psd_decode__data psdData);
#endif

#endif //OPTION__DECODE_PSD
#endif //OPTION__INCLUDE_MODE__FMHD

#endif