/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   header for fmhd/amhd MMI functions
   FILE: mode_fmhd_amhd.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#ifndef _mode_fmhd_amhd_h_
#define _mode_fmhd_amhd_h_
#include "typedefs.h"
#include <platform_options.h>

#if	(defined OPTION__INCLUDE_MODE__FMHD)||(defined OPTION__INCLUDE_MODE__AMHD)

RETURN_CODE display_hd_ui(void);
RETURN_CODE fmhd_amhd_work_mode(void);
RETURN_CODE fmhd_amhd_initialize(void);
RETURN_CODE fmhd_amhd_set_parameter_default(void);

#endif //OPTION__INCLUDE_MODE__FMHD

#endif //_mode_fmhd_amhd_h_