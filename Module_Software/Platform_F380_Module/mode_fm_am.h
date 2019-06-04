/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   MMI: header for fm/am functions
   FILE: mode_fm_am.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#ifndef _mode_fm_am_h_
#define _mode_fm_am_h_
#include "typedefs.h"
#include <platform_options.h>

//#ifdef OPTION__INCLUDE_MODE__FM
RETURN_CODE fm_am_work_mode(void);
RETURN_CODE fm_am_initialize(void);
RETURN_CODE fm_am_set_parameter_default(void);
//#endif //OPTION__INCLUDE_MODE__FM

#endif //_mode_fm_am_h_