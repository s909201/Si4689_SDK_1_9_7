#ifndef __HARDWARE_CALIBRATION_HELPERS__
#define __HARDWARE_CALIBRATION_HELPERS__

#include "common_types.h"
#include "platform_options.h"

extern RETURN_CODE calibrationGetPowerUpArgs(uint8_t *ctsien, uint8_t *clk_mode, uint8_t *tr_size, uint8_t *ibias, uint32_t *xtal_freq, uint8_t *ctun, uint8_t *ibias_run);
extern RETURN_CODE calibrationGetFrontEndArgs(uint8_t mode, uint16_t *slope, uint16_t *intercept, uint8_t *switchConfig);

#endif