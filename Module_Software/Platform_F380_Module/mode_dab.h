/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   MMI: header for dab functions
   FILE: mode_dab.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#ifndef _mode_dab_h_
#define _mode_dab_h_
#include "typedefs.h"
#include <platform_options.h>

#ifdef OPTION__INCLUDE_MODE__DAB

#define DAB_NUM_ENSEMBLES_UK_REGION 11

RETURN_CODE dab_work_mode(void);
RETURN_CODE dmb_work_mode(void);
RETURN_CODE dab_initialize(void);
//RETURN_CODE dab_scan(void);
RETURN_CODE dab_set_parameter_default(void);
RETURN_CODE ChangeFreqListToLimitedUK(void);
RETURN_CODE DAB_scan(void);
#endif //OPTION__INCLUDE_MODE__DAB

#endif //_mode_dab_h_