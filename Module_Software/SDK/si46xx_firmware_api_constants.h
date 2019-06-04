/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   firmware api definitions for manipulating the command/property interface
   FILE: si46xx_firmware_api_constants.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

/*
 * Automatically generated file. Do not edit.
 * - Covers DAB 5.0.5,FMHD 5.0.4, AMHD 2.0.11
 */

#define CMD_RD_REPLY             0x00
#define CMD_RD_REPLY_LENGTH 1
#define CMD_RD_REPLY_REP_LENGTH 6
//RD_REPLY REPLY
      #define CMD_RD_REPLY_REP_CTS_TYPE bitfield
      #define CMD_RD_REPLY_REP_CTS_SIZE 1
      #define CMD_RD_REPLY_REP_CTS_MASK 0x80
      #define CMD_RD_REPLY_REP_CTS_BIT  0x80
      #define CMD_RD_REPLY_REP_CTS_MSB  7
      #define CMD_RD_REPLY_REP_CTS_LSB  7
      #define CMD_RD_REPLY_REP_CTS_is_true (reply_buffer[0]&0x80)
      #define CMD_RD_REPLY_REP_CTS_value (((reply_buffer[0]&0x80))>>7)
      #define CMD_RD_REPLY_REP_ERR_CMD_TYPE bitfield
      #define CMD_RD_REPLY_REP_ERR_CMD_SIZE 1
      #define CMD_RD_REPLY_REP_ERR_CMD_MASK 0x40
      #define CMD_RD_REPLY_REP_ERR_CMD_BIT  0x40
      #define CMD_RD_REPLY_REP_ERR_CMD_MSB  6
      #define CMD_RD_REPLY_REP_ERR_CMD_LSB  6
      #define CMD_RD_REPLY_REP_ERR_CMD_is_true (reply_buffer[0]&0x40)
      #define CMD_RD_REPLY_REP_ERR_CMD_value (((reply_buffer[0]&0x40))>>6)
      #define CMD_RD_REPLY_REP_DACQINT_TYPE bitfield
      #define CMD_RD_REPLY_REP_DACQINT_SIZE 1
      #define CMD_RD_REPLY_REP_DACQINT_MASK 0x20
      #define CMD_RD_REPLY_REP_DACQINT_BIT  0x20
      #define CMD_RD_REPLY_REP_DACQINT_MSB  5
      #define CMD_RD_REPLY_REP_DACQINT_LSB  5
      #define CMD_RD_REPLY_REP_DACQINT_is_true (reply_buffer[0]&0x20)
      #define CMD_RD_REPLY_REP_DACQINT_value (((reply_buffer[0]&0x20))>>5)
      #define CMD_RD_REPLY_REP_DSRVINT_TYPE bitfield
      #define CMD_RD_REPLY_REP_DSRVINT_SIZE 1
      #define CMD_RD_REPLY_REP_DSRVINT_MASK 0x10
      #define CMD_RD_REPLY_REP_DSRVINT_BIT  0x10
      #define CMD_RD_REPLY_REP_DSRVINT_MSB  4
      #define CMD_RD_REPLY_REP_DSRVINT_LSB  4
      #define CMD_RD_REPLY_REP_DSRVINT_is_true (reply_buffer[0]&0x10)
      #define CMD_RD_REPLY_REP_DSRVINT_value (((reply_buffer[0]&0x10))>>4)
      #define CMD_RD_REPLY_REP_RSQINT_TYPE bitfield
      #define CMD_RD_REPLY_REP_RSQINT_SIZE 1
      #define CMD_RD_REPLY_REP_RSQINT_MASK 0x08
      #define CMD_RD_REPLY_REP_RSQINT_BIT  0x08
      #define CMD_RD_REPLY_REP_RSQINT_MSB  3
      #define CMD_RD_REPLY_REP_RSQINT_LSB  3
      #define CMD_RD_REPLY_REP_RSQINT_is_true (reply_buffer[0]&0x8)
      #define CMD_RD_REPLY_REP_RSQINT_value (((reply_buffer[0]&0x8))>>3)
      #define CMD_RD_REPLY_REP_RDSINT_TYPE bitfield
      #define CMD_RD_REPLY_REP_RDSINT_SIZE 1
      #define CMD_RD_REPLY_REP_RDSINT_MASK 0x04
      #define CMD_RD_REPLY_REP_RDSINT_BIT  0x04
      #define CMD_RD_REPLY_REP_RDSINT_MSB  2
      #define CMD_RD_REPLY_REP_RDSINT_LSB  2
      #define CMD_RD_REPLY_REP_RDSINT_is_true (reply_buffer[0]&0x4)
      #define CMD_RD_REPLY_REP_RDSINT_value (((reply_buffer[0]&0x4))>>2)
      #define CMD_RD_REPLY_REP_ACFINT_TYPE bitfield
      #define CMD_RD_REPLY_REP_ACFINT_SIZE 1
      #define CMD_RD_REPLY_REP_ACFINT_MASK 0x02
      #define CMD_RD_REPLY_REP_ACFINT_BIT  0x02
      #define CMD_RD_REPLY_REP_ACFINT_MSB  1
      #define CMD_RD_REPLY_REP_ACFINT_LSB  1
      #define CMD_RD_REPLY_REP_ACFINT_is_true (reply_buffer[0]&0x2)
      #define CMD_RD_REPLY_REP_ACFINT_value (((reply_buffer[0]&0x2))>>1)
      #define CMD_RD_REPLY_REP_STCINT_TYPE bitfield
      #define CMD_RD_REPLY_REP_STCINT_SIZE 1
      #define CMD_RD_REPLY_REP_STCINT_MASK 0x01
      #define CMD_RD_REPLY_REP_STCINT_BIT  0x01
      #define CMD_RD_REPLY_REP_STCINT_MSB  0
      #define CMD_RD_REPLY_REP_STCINT_LSB  0
      #define CMD_RD_REPLY_REP_STCINT_is_true (reply_buffer[0]&0x1)
      #define CMD_RD_REPLY_REP_STCINT_value (((reply_buffer[0]&0x1)))
      #define CMD_RD_REPLY_REP_DEVNTINT_TYPE bitfield
      #define CMD_RD_REPLY_REP_DEVNTINT_SIZE 1
      #define CMD_RD_REPLY_REP_DEVNTINT_MASK 0x20
      #define CMD_RD_REPLY_REP_DEVNTINT_BIT  0x20
      #define CMD_RD_REPLY_REP_DEVNTINT_MSB  5
      #define CMD_RD_REPLY_REP_DEVNTINT_LSB  5
      #define CMD_RD_REPLY_REP_DEVNTINT_is_true (reply_buffer[1]&0x20)
      #define CMD_RD_REPLY_REP_DEVNTINT_value (((reply_buffer[1]&0x20))>>5)
      #define CMD_RD_REPLY_REP_DACFINT_TYPE bitfield
      #define CMD_RD_REPLY_REP_DACFINT_SIZE 1
      #define CMD_RD_REPLY_REP_DACFINT_MASK 0x01
      #define CMD_RD_REPLY_REP_DACFINT_BIT  0x01
      #define CMD_RD_REPLY_REP_DACFINT_MSB  0
      #define CMD_RD_REPLY_REP_DACFINT_LSB  0
      #define CMD_RD_REPLY_REP_DACFINT_is_true (reply_buffer[1]&0x1)
      #define CMD_RD_REPLY_REP_DACFINT_value (((reply_buffer[1]&0x1)))
      #define CMD_RD_REPLY_REP_PUP_STATE_TYPE bitfield
      #define CMD_RD_REPLY_REP_PUP_STATE_SIZE 2
      #define CMD_RD_REPLY_REP_PUP_STATE_MASK 0xC0
      #define CMD_RD_REPLY_REP_PUP_STATE_MSB  7
      #define CMD_RD_REPLY_REP_PUP_STATE_LSB  6
      #define CMD_RD_REPLY_REP_PUP_STATE_value (((reply_buffer[3]&0xC0))>>6)
      #define CMD_RD_REPLY_REP_PUP_STATE_ENUM_RESET 0
      #define CMD_RD_REPLY_REP_PUP_STATE_ENUM_RESET_HOT 1
      #define CMD_RD_REPLY_REP_PUP_STATE_ENUM_BL 2
      #define CMD_RD_REPLY_REP_PUP_STATE_ENUM_APP 3
      #define CMD_RD_REPLY_REP_RFFE_ERR_TYPE bitfield
      #define CMD_RD_REPLY_REP_RFFE_ERR_SIZE 1
      #define CMD_RD_REPLY_REP_RFFE_ERR_MASK 0x20
      #define CMD_RD_REPLY_REP_RFFE_ERR_BIT  0x20
      #define CMD_RD_REPLY_REP_RFFE_ERR_MSB  5
      #define CMD_RD_REPLY_REP_RFFE_ERR_LSB  5
      #define CMD_RD_REPLY_REP_RFFE_ERR_is_true (reply_buffer[3]&0x20)
      #define CMD_RD_REPLY_REP_RFFE_ERR_value (((reply_buffer[3]&0x20))>>5)
      #define CMD_RD_REPLY_REP_DSPERR_TYPE bitfield
      #define CMD_RD_REPLY_REP_DSPERR_SIZE 1
      #define CMD_RD_REPLY_REP_DSPERR_MASK 0x10
      #define CMD_RD_REPLY_REP_DSPERR_BIT  0x10
      #define CMD_RD_REPLY_REP_DSPERR_MSB  4
      #define CMD_RD_REPLY_REP_DSPERR_LSB  4
      #define CMD_RD_REPLY_REP_DSPERR_is_true (reply_buffer[3]&0x10)
      #define CMD_RD_REPLY_REP_DSPERR_value (((reply_buffer[3]&0x10))>>4)
      #define CMD_RD_REPLY_REP_REPOFERR_TYPE bitfield
      #define CMD_RD_REPLY_REP_REPOFERR_SIZE 1
      #define CMD_RD_REPLY_REP_REPOFERR_MASK 0x08
      #define CMD_RD_REPLY_REP_REPOFERR_BIT  0x08
      #define CMD_RD_REPLY_REP_REPOFERR_MSB  3
      #define CMD_RD_REPLY_REP_REPOFERR_LSB  3
      #define CMD_RD_REPLY_REP_REPOFERR_is_true (reply_buffer[3]&0x8)
      #define CMD_RD_REPLY_REP_REPOFERR_value (((reply_buffer[3]&0x8))>>3)
      #define CMD_RD_REPLY_REP_CMDOFERR_TYPE bitfield
      #define CMD_RD_REPLY_REP_CMDOFERR_SIZE 1
      #define CMD_RD_REPLY_REP_CMDOFERR_MASK 0x04
      #define CMD_RD_REPLY_REP_CMDOFERR_BIT  0x04
      #define CMD_RD_REPLY_REP_CMDOFERR_MSB  2
      #define CMD_RD_REPLY_REP_CMDOFERR_LSB  2
      #define CMD_RD_REPLY_REP_CMDOFERR_is_true (reply_buffer[3]&0x4)
      #define CMD_RD_REPLY_REP_CMDOFERR_value (((reply_buffer[3]&0x4))>>2)
      #define CMD_RD_REPLY_REP_ARBERR_TYPE bitfield
      #define CMD_RD_REPLY_REP_ARBERR_SIZE 1
      #define CMD_RD_REPLY_REP_ARBERR_MASK 0x02
      #define CMD_RD_REPLY_REP_ARBERR_BIT  0x02
      #define CMD_RD_REPLY_REP_ARBERR_MSB  1
      #define CMD_RD_REPLY_REP_ARBERR_LSB  1
      #define CMD_RD_REPLY_REP_ARBERR_is_true (reply_buffer[3]&0x2)
      #define CMD_RD_REPLY_REP_ARBERR_value (((reply_buffer[3]&0x2))>>1)
      #define CMD_RD_REPLY_REP_ERRNR_TYPE bitfield
      #define CMD_RD_REPLY_REP_ERRNR_SIZE 1
      #define CMD_RD_REPLY_REP_ERRNR_MASK 0x01
      #define CMD_RD_REPLY_REP_ERRNR_BIT  0x01
      #define CMD_RD_REPLY_REP_ERRNR_MSB  0
      #define CMD_RD_REPLY_REP_ERRNR_LSB  0
      #define CMD_RD_REPLY_REP_ERRNR_is_true (reply_buffer[3]&0x1)
      #define CMD_RD_REPLY_REP_ERRNR_value (((reply_buffer[3]&0x1)))
      #define CMD_RD_REPLY_REP_DATA_0_TYPE u8
      #define CMD_RD_REPLY_REP_DATA_0_SIZE 8
      #define CMD_RD_REPLY_REP_DATA_0_MASK 0xFF
      #define CMD_RD_REPLY_REP_DATA_0_MSB  7
      #define CMD_RD_REPLY_REP_DATA_0_LSB  0
      #define CMD_RD_REPLY_REP_DATA_0_INDEX 0x04
      #define CMD_RD_REPLY_REP_DATA_0_value (((reply_buffer[4])))
      #define CMD_RD_REPLY_REP_DATA_N_TYPE u8
      #define CMD_RD_REPLY_REP_DATA_N_SIZE 8
      #define CMD_RD_REPLY_REP_DATA_N_MASK 0xFF
      #define CMD_RD_REPLY_REP_DATA_N_MSB  7
      #define CMD_RD_REPLY_REP_DATA_N_LSB  0
      #define CMD_RD_REPLY_REP_DATA_N_INDEX 0x05
      #define CMD_RD_REPLY_REP_DATA_N_value (((reply_buffer[5])))

#define CMD_POWER_UP             0x01
#define CMD_POWER_UP_LENGTH 16
#define CMD_POWER_UP_REP_LENGTH 4
//POWER_UP ARGS
      #define CMD_POWER_UP_ARG_CTSIEN_TYPE bitfield
      #define CMD_POWER_UP_ARG_CTSIEN_SIZE 1
      #define CMD_POWER_UP_ARG_CTSIEN_MASK 0x80
      #define CMD_POWER_UP_ARG_CTSIEN_BIT  0x80
      #define CMD_POWER_UP_ARG_CTSIEN_MSB  7
      #define CMD_POWER_UP_ARG_CTSIEN_LSB  7
      #define CMD_POWER_UP_ARG_CTSIEN_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x80) | (((x)<<7)&0x80)))
      #define CMD_POWER_UP_ARG_CTSIEN_ENUM_DISABLE 0
      #define CMD_POWER_UP_ARG_CTSIEN_ENUM_ENABLE 1
      #define CMD_POWER_UP_ARG_CLK_MODE_TYPE bitfield
      #define CMD_POWER_UP_ARG_CLK_MODE_SIZE 2
      #define CMD_POWER_UP_ARG_CLK_MODE_MASK 0x30
      #define CMD_POWER_UP_ARG_CLK_MODE_MSB  5
      #define CMD_POWER_UP_ARG_CLK_MODE_LSB  4
      #define CMD_POWER_UP_ARG_CLK_MODE_write_field(x) (cmd_arg[2] = ((cmd_arg[2]&~0x30) | (((x)<<4)&0x30)))
      #define CMD_POWER_UP_ARG_CLK_MODE_ENUM_OFF 0
      #define CMD_POWER_UP_ARG_CLK_MODE_ENUM_XOSC 1
      #define CMD_POWER_UP_ARG_CLK_MODE_ENUM_SING_BF 2
      #define CMD_POWER_UP_ARG_CLK_MODE_ENUM_DIFF_BF 3
      #define CMD_POWER_UP_ARG_TR_SIZE_TYPE bitfield
      #define CMD_POWER_UP_ARG_TR_SIZE_SIZE 4
      #define CMD_POWER_UP_ARG_TR_SIZE_MASK 0x0F
      #define CMD_POWER_UP_ARG_TR_SIZE_MSB  3
      #define CMD_POWER_UP_ARG_TR_SIZE_LSB  0
      #define CMD_POWER_UP_ARG_TR_SIZE_write_field(x) (cmd_arg[2] = ((cmd_arg[2]&~0xF) | (((x)<<0)&0xF)))
      #define CMD_POWER_UP_ARG_TR_SIZE_MIN 0
      #define CMD_POWER_UP_ARG_TR_SIZE_MAX 15
      #define CMD_POWER_UP_ARG_IBIAS_TYPE bitfield
      #define CMD_POWER_UP_ARG_IBIAS_SIZE 7
      #define CMD_POWER_UP_ARG_IBIAS_MASK 0x7F
      #define CMD_POWER_UP_ARG_IBIAS_MSB  6
      #define CMD_POWER_UP_ARG_IBIAS_LSB  0
      #define CMD_POWER_UP_ARG_IBIAS_write_field(x) (cmd_arg[3] = ((cmd_arg[3]&~0x7F) | (((x)<<0)&0x7F)))
      #define CMD_POWER_UP_ARG_IBIAS_MIN 0
      #define CMD_POWER_UP_ARG_IBIAS_MAX 127
      #define CMD_POWER_UP_ARG_XTAL_FREQ_TYPE u32
      #define CMD_POWER_UP_ARG_XTAL_FREQ_SIZE 32
      #define CMD_POWER_UP_ARG_XTAL_FREQ_MASK 0xFFFFFFFF
      #define CMD_POWER_UP_ARG_XTAL_FREQ_MSB  31
      #define CMD_POWER_UP_ARG_XTAL_FREQ_LSB  0
      #define CMD_POWER_UP_ARG_XTAL_FREQ_INDEX 0x04
      #define CMD_POWER_UP_ARG_XTAL_FREQ_write_u32(x) (cmd_arg_u32[1] = (x))
      #define CMD_POWER_UP_ARG_CTUN_TYPE bitfield
      #define CMD_POWER_UP_ARG_CTUN_SIZE 6
      #define CMD_POWER_UP_ARG_CTUN_MASK 0x3F
      #define CMD_POWER_UP_ARG_CTUN_MSB  5
      #define CMD_POWER_UP_ARG_CTUN_LSB  0
      #define CMD_POWER_UP_ARG_CTUN_write_field(x) (cmd_arg[8] = ((cmd_arg[8]&~0x3F) | (((x)<<0)&0x3F)))
      #define CMD_POWER_UP_ARG_CTUN_MIN 0
      #define CMD_POWER_UP_ARG_CTUN_MAX 63
      #define CMD_POWER_UP_ARG_IBIAS_RUN_TYPE bitfield
      #define CMD_POWER_UP_ARG_IBIAS_RUN_SIZE 7
      #define CMD_POWER_UP_ARG_IBIAS_RUN_MASK 0x7F
      #define CMD_POWER_UP_ARG_IBIAS_RUN_MSB  6
      #define CMD_POWER_UP_ARG_IBIAS_RUN_LSB  0
      #define CMD_POWER_UP_ARG_IBIAS_RUN_write_field(x) (cmd_arg[13] = ((cmd_arg[13]&~0x7F) | (((x)<<0)&0x7F)))
      #define CMD_POWER_UP_ARG_IBIAS_RUN_MIN 0
      #define CMD_POWER_UP_ARG_IBIAS_RUN_MAX 127

#define CMD_HOST_LOAD            0x04
//HOST_LOAD ARGS
      #define CMD_HOST_LOAD_ARG_IMAGE_DATA0_TYPE u8
      #define CMD_HOST_LOAD_ARG_IMAGE_DATA0_SIZE 8
      #define CMD_HOST_LOAD_ARG_IMAGE_DATA0_MASK 0xFF
      #define CMD_HOST_LOAD_ARG_IMAGE_DATA0_MSB  7
      #define CMD_HOST_LOAD_ARG_IMAGE_DATA0_LSB  0
      #define CMD_HOST_LOAD_ARG_IMAGE_DATA0_INDEX 0x04
      #define CMD_HOST_LOAD_ARG_IMAGE_DATA0_write_u8(x) (cmd_arg[4] = (x))
      #define CMD_HOST_LOAD_ARG_IMAGE_DATA1_TYPE u8
      #define CMD_HOST_LOAD_ARG_IMAGE_DATA1_SIZE 8
      #define CMD_HOST_LOAD_ARG_IMAGE_DATA1_MASK 0xFF
      #define CMD_HOST_LOAD_ARG_IMAGE_DATA1_MSB  7
      #define CMD_HOST_LOAD_ARG_IMAGE_DATA1_LSB  0
      #define CMD_HOST_LOAD_ARG_IMAGE_DATA1_INDEX 0x05
      #define CMD_HOST_LOAD_ARG_IMAGE_DATA1_write_u8(x) (cmd_arg[5] = (x))
      #define CMD_HOST_LOAD_ARG_IMAGE_DATA2_TYPE u8
      #define CMD_HOST_LOAD_ARG_IMAGE_DATA2_SIZE 8
      #define CMD_HOST_LOAD_ARG_IMAGE_DATA2_MASK 0xFF
      #define CMD_HOST_LOAD_ARG_IMAGE_DATA2_MSB  7
      #define CMD_HOST_LOAD_ARG_IMAGE_DATA2_LSB  0
      #define CMD_HOST_LOAD_ARG_IMAGE_DATA2_INDEX 0x06
      #define CMD_HOST_LOAD_ARG_IMAGE_DATA2_write_u8(x) (cmd_arg[6] = (x))
      #define CMD_HOST_LOAD_ARG_IMAGE_DATA3_TYPE u8
      #define CMD_HOST_LOAD_ARG_IMAGE_DATA3_SIZE 8
      #define CMD_HOST_LOAD_ARG_IMAGE_DATA3_MASK 0xFF
      #define CMD_HOST_LOAD_ARG_IMAGE_DATA3_MSB  7
      #define CMD_HOST_LOAD_ARG_IMAGE_DATA3_LSB  0
      #define CMD_HOST_LOAD_ARG_IMAGE_DATA3_INDEX 0x07
      #define CMD_HOST_LOAD_ARG_IMAGE_DATA3_write_u8(x) (cmd_arg[7] = (x))
      #define CMD_HOST_LOAD_ARG_IMAGE_DATA_N_TYPE u8
      #define CMD_HOST_LOAD_ARG_IMAGE_DATA_N_SIZE 8
      #define CMD_HOST_LOAD_ARG_IMAGE_DATA_N_MASK 0xFF
      #define CMD_HOST_LOAD_ARG_IMAGE_DATA_N_MSB  7
      #define CMD_HOST_LOAD_ARG_IMAGE_DATA_N_LSB  0
      #define CMD_HOST_LOAD_ARG_IMAGE_DATA_N_INDEX 0x08
      #define CMD_HOST_LOAD_ARG_IMAGE_DATA_N_write_u8(x) (cmd_arg[8] = (x))

#define CMD_FLASH_LOAD           0x05
#define CMD_FLASH_LOAD_LENGTH 12
#define CMD_FLASH_LOAD_REP_LENGTH 4
//FLASH_LOAD ARGS
      #define CMD_FLASH_LOAD_ARG_FLASH_START_ADDR_TYPE u32
      #define CMD_FLASH_LOAD_ARG_FLASH_START_ADDR_SIZE 32
      #define CMD_FLASH_LOAD_ARG_FLASH_START_ADDR_MASK 0xFFFFFFFF
      #define CMD_FLASH_LOAD_ARG_FLASH_START_ADDR_MSB  31
      #define CMD_FLASH_LOAD_ARG_FLASH_START_ADDR_LSB  0
      #define CMD_FLASH_LOAD_ARG_FLASH_START_ADDR_INDEX 0x04
      #define CMD_FLASH_LOAD_ARG_FLASH_START_ADDR_write_u32(x) (cmd_arg_u32[1] = (x))

#define CMD_LOAD_INIT            0x06
#define CMD_LOAD_INIT_LENGTH 2
#define CMD_LOAD_INIT_REP_LENGTH 4

#define CMD_BOOT                 0x07
#define CMD_BOOT_LENGTH 2
#define CMD_BOOT_REP_LENGTH 4

#define CMD_GET_PART_INFO        0x08
#define CMD_GET_PART_INFO_LENGTH 2
#define CMD_GET_PART_INFO_REP_LENGTH 23
//GET_PART_INFO REPLY
      #define CMD_GET_PART_INFO_REP_CHIPREV_TYPE u8
      #define CMD_GET_PART_INFO_REP_CHIPREV_SIZE 8
      #define CMD_GET_PART_INFO_REP_CHIPREV_MASK 0xFF
      #define CMD_GET_PART_INFO_REP_CHIPREV_MSB  7
      #define CMD_GET_PART_INFO_REP_CHIPREV_LSB  0
      #define CMD_GET_PART_INFO_REP_CHIPREV_INDEX 0x04
      #define CMD_GET_PART_INFO_REP_CHIPREV_value (((reply_buffer[4])))
      #define CMD_GET_PART_INFO_REP_ROMID_TYPE u8
      #define CMD_GET_PART_INFO_REP_ROMID_SIZE 8
      #define CMD_GET_PART_INFO_REP_ROMID_MASK 0xFF
      #define CMD_GET_PART_INFO_REP_ROMID_MSB  7
      #define CMD_GET_PART_INFO_REP_ROMID_LSB  0
      #define CMD_GET_PART_INFO_REP_ROMID_INDEX 0x05
      #define CMD_GET_PART_INFO_REP_ROMID_value (((reply_buffer[5])))
      #define CMD_GET_PART_INFO_REP_PART_TYPE u16
      #define CMD_GET_PART_INFO_REP_PART_SIZE 16
      #define CMD_GET_PART_INFO_REP_PART_MASK 0xFFFF
      #define CMD_GET_PART_INFO_REP_PART_MSB  15
      #define CMD_GET_PART_INFO_REP_PART_LSB  0
      #define CMD_GET_PART_INFO_REP_PART_INDEX 0x08
      #define CMD_GET_PART_INFO_REP_PART_value (((reply_buffer_u16[4])))

#define CMD_GET_SYS_STATE        0x09
#define CMD_GET_SYS_STATE_LENGTH 2
#define CMD_GET_SYS_STATE_REP_LENGTH 6
//GET_SYS_STATE REPLY
      #define CMD_GET_SYS_STATE_REP_IMAGE_TYPE u8
      #define CMD_GET_SYS_STATE_REP_IMAGE_SIZE 8
      #define CMD_GET_SYS_STATE_REP_IMAGE_MASK 0xFF
      #define CMD_GET_SYS_STATE_REP_IMAGE_MSB  7
      #define CMD_GET_SYS_STATE_REP_IMAGE_LSB  0
      #define CMD_GET_SYS_STATE_REP_IMAGE_INDEX 0x04
      #define CMD_GET_SYS_STATE_REP_IMAGE_value (((reply_buffer[4])))
      #define CMD_GET_SYS_STATE_REP_IMAGE_ENUM_BL 0
      #define CMD_GET_SYS_STATE_REP_IMAGE_ENUM_FMHD 1
      #define CMD_GET_SYS_STATE_REP_IMAGE_ENUM_DAB 2
      #define CMD_GET_SYS_STATE_REP_IMAGE_ENUM_TDMB_DAB_DATA_ONLY 3
      #define CMD_GET_SYS_STATE_REP_IMAGE_ENUM_FMHD_DEMOD 4
      #define CMD_GET_SYS_STATE_REP_IMAGE_ENUM_AMHD 5
      #define CMD_GET_SYS_STATE_REP_IMAGE_ENUM_AMHD_DEMOD 6
      #define CMD_GET_SYS_STATE_REP_IMAGE_ENUM_DAB_DEMOD 7
      #define CMD_GET_SYS_STATE_REP_IMAGE_ENUM_RESERVED 16

#define CMD_GET_POWER_UP_ARGS    0x0A
#define CMD_GET_POWER_UP_ARGS_LENGTH 2
#define CMD_GET_POWER_UP_ARGS_REP_LENGTH 18
//GET_POWER_UP_ARGS REPLY
      #define CMD_GET_POWER_UP_ARGS_REP_CLK_MODE_TYPE bitfield
      #define CMD_GET_POWER_UP_ARGS_REP_CLK_MODE_SIZE 2
      #define CMD_GET_POWER_UP_ARGS_REP_CLK_MODE_MASK 0x30
      #define CMD_GET_POWER_UP_ARGS_REP_CLK_MODE_MSB  5
      #define CMD_GET_POWER_UP_ARGS_REP_CLK_MODE_LSB  4
      #define CMD_GET_POWER_UP_ARGS_REP_CLK_MODE_value (((reply_buffer[6]&0x30))>>4)
      #define CMD_GET_POWER_UP_ARGS_REP_TR_SIZE_TYPE bitfield
      #define CMD_GET_POWER_UP_ARGS_REP_TR_SIZE_SIZE 4
      #define CMD_GET_POWER_UP_ARGS_REP_TR_SIZE_MASK 0x0F
      #define CMD_GET_POWER_UP_ARGS_REP_TR_SIZE_MSB  3
      #define CMD_GET_POWER_UP_ARGS_REP_TR_SIZE_LSB  0
      #define CMD_GET_POWER_UP_ARGS_REP_TR_SIZE_value (((reply_buffer[6]&0xF)))
      #define CMD_GET_POWER_UP_ARGS_REP_IBIAS_TYPE bitfield
      #define CMD_GET_POWER_UP_ARGS_REP_IBIAS_SIZE 7
      #define CMD_GET_POWER_UP_ARGS_REP_IBIAS_MASK 0x7F
      #define CMD_GET_POWER_UP_ARGS_REP_IBIAS_MSB  6
      #define CMD_GET_POWER_UP_ARGS_REP_IBIAS_LSB  0
      #define CMD_GET_POWER_UP_ARGS_REP_IBIAS_value (((reply_buffer[7]&0x7F)))
      #define CMD_GET_POWER_UP_ARGS_REP_XTAL_FREQ_TYPE u32
      #define CMD_GET_POWER_UP_ARGS_REP_XTAL_FREQ_SIZE 32
      #define CMD_GET_POWER_UP_ARGS_REP_XTAL_FREQ_MASK 0xFFFFFFFF
      #define CMD_GET_POWER_UP_ARGS_REP_XTAL_FREQ_MSB  31
      #define CMD_GET_POWER_UP_ARGS_REP_XTAL_FREQ_LSB  0
      #define CMD_GET_POWER_UP_ARGS_REP_XTAL_FREQ_INDEX 0x08
      #define CMD_GET_POWER_UP_ARGS_REP_XTAL_FREQ_value (((reply_buffer_u32[2])))
      #define CMD_GET_POWER_UP_ARGS_REP_CTUN_TYPE bitfield
      #define CMD_GET_POWER_UP_ARGS_REP_CTUN_SIZE 6
      #define CMD_GET_POWER_UP_ARGS_REP_CTUN_MASK 0x3F
      #define CMD_GET_POWER_UP_ARGS_REP_CTUN_MSB  5
      #define CMD_GET_POWER_UP_ARGS_REP_CTUN_LSB  0
      #define CMD_GET_POWER_UP_ARGS_REP_CTUN_value (((reply_buffer[12]&0x3F)))
      #define CMD_GET_POWER_UP_ARGS_REP_IBIAS_RUN_TYPE bitfield
      #define CMD_GET_POWER_UP_ARGS_REP_IBIAS_RUN_SIZE 7
      #define CMD_GET_POWER_UP_ARGS_REP_IBIAS_RUN_MASK 0x7F
      #define CMD_GET_POWER_UP_ARGS_REP_IBIAS_RUN_MSB  6
      #define CMD_GET_POWER_UP_ARGS_REP_IBIAS_RUN_LSB  0
      #define CMD_GET_POWER_UP_ARGS_REP_IBIAS_RUN_value (((reply_buffer[17]&0x7F)))

#define CMD_READ_OFFSET          0x10
#define CMD_READ_OFFSET_LENGTH 4
#define CMD_READ_OFFSET_REP_LENGTH 5
//READ_OFFSET ARGS
      #define CMD_READ_OFFSET_ARG_OFFSET_TYPE u16
      #define CMD_READ_OFFSET_ARG_OFFSET_SIZE 16
      #define CMD_READ_OFFSET_ARG_OFFSET_MASK 0xFFFF
      #define CMD_READ_OFFSET_ARG_OFFSET_MSB  15
      #define CMD_READ_OFFSET_ARG_OFFSET_LSB  0
      #define CMD_READ_OFFSET_ARG_OFFSET_INDEX 0x02
      #define CMD_READ_OFFSET_ARG_OFFSET_write_u16(x) (cmd_arg_u16[1] = (x))
//READ_OFFSET REPLY
      #define CMD_READ_OFFSET_REP_DATA0_TYPE u8
      #define CMD_READ_OFFSET_REP_DATA0_SIZE 8
      #define CMD_READ_OFFSET_REP_DATA0_MASK 0xFF
      #define CMD_READ_OFFSET_REP_DATA0_MSB  7
      #define CMD_READ_OFFSET_REP_DATA0_LSB  0
      #define CMD_READ_OFFSET_REP_DATA0_INDEX 0x04
      #define CMD_READ_OFFSET_REP_DATA0_value (((reply_buffer[4])))

#define CMD_GET_FUNC_INFO        0x12
#define CMD_GET_FUNC_INFO_LENGTH 2
#define CMD_GET_FUNC_INFO_REP_LENGTH 12
//GET_FUNC_INFO REPLY
      #define CMD_GET_FUNC_INFO_REP_REVEXT_TYPE u8
      #define CMD_GET_FUNC_INFO_REP_REVEXT_SIZE 8
      #define CMD_GET_FUNC_INFO_REP_REVEXT_MASK 0xFF
      #define CMD_GET_FUNC_INFO_REP_REVEXT_MSB  7
      #define CMD_GET_FUNC_INFO_REP_REVEXT_LSB  0
      #define CMD_GET_FUNC_INFO_REP_REVEXT_INDEX 0x04
      #define CMD_GET_FUNC_INFO_REP_REVEXT_value (((reply_buffer[4])))
      #define CMD_GET_FUNC_INFO_REP_REVBRANCH_TYPE u8
      #define CMD_GET_FUNC_INFO_REP_REVBRANCH_SIZE 8
      #define CMD_GET_FUNC_INFO_REP_REVBRANCH_MASK 0xFF
      #define CMD_GET_FUNC_INFO_REP_REVBRANCH_MSB  7
      #define CMD_GET_FUNC_INFO_REP_REVBRANCH_LSB  0
      #define CMD_GET_FUNC_INFO_REP_REVBRANCH_INDEX 0x05
      #define CMD_GET_FUNC_INFO_REP_REVBRANCH_value (((reply_buffer[5])))
      #define CMD_GET_FUNC_INFO_REP_REVINT_TYPE u8
      #define CMD_GET_FUNC_INFO_REP_REVINT_SIZE 8
      #define CMD_GET_FUNC_INFO_REP_REVINT_MASK 0xFF
      #define CMD_GET_FUNC_INFO_REP_REVINT_MSB  7
      #define CMD_GET_FUNC_INFO_REP_REVINT_LSB  0
      #define CMD_GET_FUNC_INFO_REP_REVINT_INDEX 0x06
      #define CMD_GET_FUNC_INFO_REP_REVINT_value (((reply_buffer[6])))
      #define CMD_GET_FUNC_INFO_REP_NOSVN_TYPE bitfield
      #define CMD_GET_FUNC_INFO_REP_NOSVN_SIZE 1
      #define CMD_GET_FUNC_INFO_REP_NOSVN_MASK 0x80
      #define CMD_GET_FUNC_INFO_REP_NOSVN_BIT  0x80
      #define CMD_GET_FUNC_INFO_REP_NOSVN_MSB  7
      #define CMD_GET_FUNC_INFO_REP_NOSVN_LSB  7
      #define CMD_GET_FUNC_INFO_REP_NOSVN_is_true (reply_buffer[7]&0x80)
      #define CMD_GET_FUNC_INFO_REP_NOSVN_value (((reply_buffer[7]&0x80))>>7)
      #define CMD_GET_FUNC_INFO_REP_LOCATION_TYPE bitfield
      #define CMD_GET_FUNC_INFO_REP_LOCATION_SIZE 2
      #define CMD_GET_FUNC_INFO_REP_LOCATION_MASK 0x30
      #define CMD_GET_FUNC_INFO_REP_LOCATION_MSB  5
      #define CMD_GET_FUNC_INFO_REP_LOCATION_LSB  4
      #define CMD_GET_FUNC_INFO_REP_LOCATION_value (((reply_buffer[7]&0x30))>>4)
      #define CMD_GET_FUNC_INFO_REP_MIXEDREV_TYPE bitfield
      #define CMD_GET_FUNC_INFO_REP_MIXEDREV_SIZE 1
      #define CMD_GET_FUNC_INFO_REP_MIXEDREV_MASK 0x02
      #define CMD_GET_FUNC_INFO_REP_MIXEDREV_BIT  0x02
      #define CMD_GET_FUNC_INFO_REP_MIXEDREV_MSB  1
      #define CMD_GET_FUNC_INFO_REP_MIXEDREV_LSB  1
      #define CMD_GET_FUNC_INFO_REP_MIXEDREV_is_true (reply_buffer[7]&0x2)
      #define CMD_GET_FUNC_INFO_REP_MIXEDREV_value (((reply_buffer[7]&0x2))>>1)
      #define CMD_GET_FUNC_INFO_REP_LOCALMOD_TYPE bitfield
      #define CMD_GET_FUNC_INFO_REP_LOCALMOD_SIZE 1
      #define CMD_GET_FUNC_INFO_REP_LOCALMOD_MASK 0x01
      #define CMD_GET_FUNC_INFO_REP_LOCALMOD_BIT  0x01
      #define CMD_GET_FUNC_INFO_REP_LOCALMOD_MSB  0
      #define CMD_GET_FUNC_INFO_REP_LOCALMOD_LSB  0
      #define CMD_GET_FUNC_INFO_REP_LOCALMOD_is_true (reply_buffer[7]&0x1)
      #define CMD_GET_FUNC_INFO_REP_LOCALMOD_value (((reply_buffer[7]&0x1)))
      #define CMD_GET_FUNC_INFO_REP_SVNID_TYPE u32
      #define CMD_GET_FUNC_INFO_REP_SVNID_SIZE 32
      #define CMD_GET_FUNC_INFO_REP_SVNID_MASK 0xFFFFFFFF
      #define CMD_GET_FUNC_INFO_REP_SVNID_MSB  31
      #define CMD_GET_FUNC_INFO_REP_SVNID_LSB  0
      #define CMD_GET_FUNC_INFO_REP_SVNID_INDEX 0x08
      #define CMD_GET_FUNC_INFO_REP_SVNID_value (((reply_buffer_u32[2])))

#define CMD_SET_PROPERTY         0x13
#define CMD_SET_PROPERTY_LENGTH 6
#define CMD_SET_PROPERTY_REP_LENGTH 4
//SET_PROPERTY ARGS
      #define CMD_SET_PROPERTY_ARG_PROPID_TYPE u16
      #define CMD_SET_PROPERTY_ARG_PROPID_SIZE 16
      #define CMD_SET_PROPERTY_ARG_PROPID_MASK 0xFFFF
      #define CMD_SET_PROPERTY_ARG_PROPID_MSB  15
      #define CMD_SET_PROPERTY_ARG_PROPID_LSB  0
      #define CMD_SET_PROPERTY_ARG_PROPID_INDEX 0x02
      #define CMD_SET_PROPERTY_ARG_PROPID_write_u16(x) (cmd_arg_u16[1] = (x))
      #define CMD_SET_PROPERTY_ARG_DATA0_TYPE u16
      #define CMD_SET_PROPERTY_ARG_DATA0_SIZE 16
      #define CMD_SET_PROPERTY_ARG_DATA0_MASK 0xFFFF
      #define CMD_SET_PROPERTY_ARG_DATA0_MSB  15
      #define CMD_SET_PROPERTY_ARG_DATA0_LSB  0
      #define CMD_SET_PROPERTY_ARG_DATA0_INDEX 0x04
      #define CMD_SET_PROPERTY_ARG_DATA0_write_u16(x) (cmd_arg_u16[2] = (x))

#define CMD_GET_PROPERTY         0x14
#define CMD_GET_PROPERTY_LENGTH 4
#define CMD_GET_PROPERTY_REP_LENGTH 6
//GET_PROPERTY ARGS
      #define CMD_GET_PROPERTY_ARG_COUNT_TYPE u8
      #define CMD_GET_PROPERTY_ARG_COUNT_SIZE 8
      #define CMD_GET_PROPERTY_ARG_COUNT_MASK 0xFF
      #define CMD_GET_PROPERTY_ARG_COUNT_MSB  7
      #define CMD_GET_PROPERTY_ARG_COUNT_LSB  0
      #define CMD_GET_PROPERTY_ARG_COUNT_INDEX 0x01
      #define CMD_GET_PROPERTY_ARG_COUNT_write_u8(x) (cmd_arg[1] = (x))
      #define CMD_GET_PROPERTY_ARG_PROPID_TYPE u16
      #define CMD_GET_PROPERTY_ARG_PROPID_SIZE 16
      #define CMD_GET_PROPERTY_ARG_PROPID_MASK 0xFFFF
      #define CMD_GET_PROPERTY_ARG_PROPID_MSB  15
      #define CMD_GET_PROPERTY_ARG_PROPID_LSB  0
      #define CMD_GET_PROPERTY_ARG_PROPID_INDEX 0x02
      #define CMD_GET_PROPERTY_ARG_PROPID_write_u16(x) (cmd_arg_u16[1] = (x))
//GET_PROPERTY REPLY
      #define CMD_GET_PROPERTY_REP_DATA0_TYPE u16
      #define CMD_GET_PROPERTY_REP_DATA0_SIZE 16
      #define CMD_GET_PROPERTY_REP_DATA0_MASK 0xFFFF
      #define CMD_GET_PROPERTY_REP_DATA0_MSB  15
      #define CMD_GET_PROPERTY_REP_DATA0_LSB  0
      #define CMD_GET_PROPERTY_REP_DATA0_INDEX 0x04
      #define CMD_GET_PROPERTY_REP_DATA0_value (((reply_buffer_u16[2])))

#define CMD_WRITE_STORAGE        0x15
#define CMD_WRITE_STORAGE_LENGTH 9
#define CMD_WRITE_STORAGE_REP_LENGTH 4
//WRITE_STORAGE ARGS
      #define CMD_WRITE_STORAGE_ARG_OFFSET_TYPE u16
      #define CMD_WRITE_STORAGE_ARG_OFFSET_SIZE 16
      #define CMD_WRITE_STORAGE_ARG_OFFSET_MASK 0xFFFF
      #define CMD_WRITE_STORAGE_ARG_OFFSET_MSB  15
      #define CMD_WRITE_STORAGE_ARG_OFFSET_LSB  0
      #define CMD_WRITE_STORAGE_ARG_OFFSET_INDEX 0x02
      #define CMD_WRITE_STORAGE_ARG_OFFSET_write_u16(x) (cmd_arg_u16[1] = (x))
      #define CMD_WRITE_STORAGE_ARG_LENGTH_TYPE u16
      #define CMD_WRITE_STORAGE_ARG_LENGTH_SIZE 16
      #define CMD_WRITE_STORAGE_ARG_LENGTH_MASK 0xFFFF
      #define CMD_WRITE_STORAGE_ARG_LENGTH_MSB  15
      #define CMD_WRITE_STORAGE_ARG_LENGTH_LSB  0
      #define CMD_WRITE_STORAGE_ARG_LENGTH_INDEX 0x04
      #define CMD_WRITE_STORAGE_ARG_LENGTH_write_u16(x) (cmd_arg_u16[2] = (x))
      #define CMD_WRITE_STORAGE_ARG_DATA0_TYPE u8
      #define CMD_WRITE_STORAGE_ARG_DATA0_SIZE 8
      #define CMD_WRITE_STORAGE_ARG_DATA0_MASK 0xFF
      #define CMD_WRITE_STORAGE_ARG_DATA0_MSB  7
      #define CMD_WRITE_STORAGE_ARG_DATA0_LSB  0
      #define CMD_WRITE_STORAGE_ARG_DATA0_INDEX 0x08
      #define CMD_WRITE_STORAGE_ARG_DATA0_write_u8(x) (cmd_arg[8] = (x))

#define CMD_READ_STORAGE         0x16
#define CMD_READ_STORAGE_LENGTH 4
#define CMD_READ_STORAGE_REP_LENGTH 5
//READ_STORAGE ARGS
      #define CMD_READ_STORAGE_ARG_OFFSET_TYPE u16
      #define CMD_READ_STORAGE_ARG_OFFSET_SIZE 16
      #define CMD_READ_STORAGE_ARG_OFFSET_MASK 0xFFFF
      #define CMD_READ_STORAGE_ARG_OFFSET_MSB  15
      #define CMD_READ_STORAGE_ARG_OFFSET_LSB  0
      #define CMD_READ_STORAGE_ARG_OFFSET_INDEX 0x02
      #define CMD_READ_STORAGE_ARG_OFFSET_write_u16(x) (cmd_arg_u16[1] = (x))
//READ_STORAGE REPLY
      #define CMD_READ_STORAGE_REP_DATA0_TYPE u8
      #define CMD_READ_STORAGE_REP_DATA0_SIZE 8
      #define CMD_READ_STORAGE_REP_DATA0_MASK 0xFF
      #define CMD_READ_STORAGE_REP_DATA0_MSB  7
      #define CMD_READ_STORAGE_REP_DATA0_LSB  0
      #define CMD_READ_STORAGE_REP_DATA0_INDEX 0x04
      #define CMD_READ_STORAGE_REP_DATA0_value (((reply_buffer[4])))

#define CMD_FM_TUNE_FREQ         0x30
#define CMD_FM_TUNE_FREQ_LENGTH 7
#define CMD_FM_TUNE_FREQ_REP_LENGTH 4
//FM_TUNE_FREQ ARGS
      #define CMD_FM_TUNE_FREQ_ARG_DIR_TUNE_TYPE bitfield
      #define CMD_FM_TUNE_FREQ_ARG_DIR_TUNE_SIZE 1
      #define CMD_FM_TUNE_FREQ_ARG_DIR_TUNE_MASK 0x20
      #define CMD_FM_TUNE_FREQ_ARG_DIR_TUNE_BIT  0x20
      #define CMD_FM_TUNE_FREQ_ARG_DIR_TUNE_MSB  5
      #define CMD_FM_TUNE_FREQ_ARG_DIR_TUNE_LSB  5
      #define CMD_FM_TUNE_FREQ_ARG_DIR_TUNE_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x20) | (((x)<<5)&0x20)))
      #define CMD_FM_TUNE_FREQ_ARG_TUNE_MODE_TYPE bitfield
      #define CMD_FM_TUNE_FREQ_ARG_TUNE_MODE_SIZE 2
      #define CMD_FM_TUNE_FREQ_ARG_TUNE_MODE_MASK 0x0C
      #define CMD_FM_TUNE_FREQ_ARG_TUNE_MODE_MSB  3
      #define CMD_FM_TUNE_FREQ_ARG_TUNE_MODE_LSB  2
      #define CMD_FM_TUNE_FREQ_ARG_TUNE_MODE_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0xC) | (((x)<<2)&0xC)))
      #define CMD_FM_TUNE_FREQ_ARG_TUNE_MODE_ENUM_TUNE_ANALOG_ONLY 0
      #define CMD_FM_TUNE_FREQ_ARG_TUNE_MODE_ENUM_RESERVED 1
      #define CMD_FM_TUNE_FREQ_ARG_TUNE_MODE_ENUM_TUNE_HYBRID 2
      #define CMD_FM_TUNE_FREQ_ARG_TUNE_MODE_ENUM_TUNE_DIGITAL_ONLY 3
      #define CMD_FM_TUNE_FREQ_ARG_INJECTION_TYPE bitfield
      #define CMD_FM_TUNE_FREQ_ARG_INJECTION_SIZE 2
      #define CMD_FM_TUNE_FREQ_ARG_INJECTION_MASK 0x03
      #define CMD_FM_TUNE_FREQ_ARG_INJECTION_MSB  1
      #define CMD_FM_TUNE_FREQ_ARG_INJECTION_LSB  0
      #define CMD_FM_TUNE_FREQ_ARG_INJECTION_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x3) | (((x)<<0)&0x3)))
      #define CMD_FM_TUNE_FREQ_ARG_INJECTION_ENUM_FULL_AUTO 0
      #define CMD_FM_TUNE_FREQ_ARG_INJECTION_ENUM_LOW_SIDE 1
      #define CMD_FM_TUNE_FREQ_ARG_INJECTION_ENUM_HIGH_SIDE 2
      #define CMD_FM_TUNE_FREQ_ARG_FREQ_TYPE u16
      #define CMD_FM_TUNE_FREQ_ARG_FREQ_SIZE 16
      #define CMD_FM_TUNE_FREQ_ARG_FREQ_MASK 0xFFFF
      #define CMD_FM_TUNE_FREQ_ARG_FREQ_MSB  15
      #define CMD_FM_TUNE_FREQ_ARG_FREQ_LSB  0
      #define CMD_FM_TUNE_FREQ_ARG_FREQ_INDEX 0x02
      #define CMD_FM_TUNE_FREQ_ARG_FREQ_write_u16(x) (cmd_arg_u16[1] = (x))
      #define CMD_FM_TUNE_FREQ_ARG_ANTCAP_TYPE u16
      #define CMD_FM_TUNE_FREQ_ARG_ANTCAP_SIZE 16
      #define CMD_FM_TUNE_FREQ_ARG_ANTCAP_MASK 0xFFFF
      #define CMD_FM_TUNE_FREQ_ARG_ANTCAP_MSB  15
      #define CMD_FM_TUNE_FREQ_ARG_ANTCAP_LSB  0
      #define CMD_FM_TUNE_FREQ_ARG_ANTCAP_INDEX 0x04
      #define CMD_FM_TUNE_FREQ_ARG_ANTCAP_write_u16(x) (cmd_arg_u16[2] = (x))
      #define CMD_FM_TUNE_FREQ_ARG_ANTCAP_MIN 0
      #define CMD_FM_TUNE_FREQ_ARG_ANTCAP_MAX 128
      #define CMD_FM_TUNE_FREQ_ARG_ANTCAP_ENUM_AUTO 0
      #define CMD_FM_TUNE_FREQ_ARG_PROG_ID_TYPE u8
      #define CMD_FM_TUNE_FREQ_ARG_PROG_ID_SIZE 8
      #define CMD_FM_TUNE_FREQ_ARG_PROG_ID_MASK 0xFF
      #define CMD_FM_TUNE_FREQ_ARG_PROG_ID_MSB  7
      #define CMD_FM_TUNE_FREQ_ARG_PROG_ID_LSB  0
      #define CMD_FM_TUNE_FREQ_ARG_PROG_ID_INDEX 0x06
      #define CMD_FM_TUNE_FREQ_ARG_PROG_ID_write_u8(x) (cmd_arg[6] = (x))
      #define CMD_FM_TUNE_FREQ_ARG_PROG_ID_MIN 0
      #define CMD_FM_TUNE_FREQ_ARG_PROG_ID_MAX 7

#define CMD_FM_SEEK_START        0x31
#define CMD_FM_SEEK_START_LENGTH 6
#define CMD_FM_SEEK_START_REP_LENGTH 4
//FM_SEEK_START ARGS
      #define CMD_FM_SEEK_START_ARG_FORCE_WB_TYPE bitfield
      #define CMD_FM_SEEK_START_ARG_FORCE_WB_SIZE 1
      #define CMD_FM_SEEK_START_ARG_FORCE_WB_MASK 0x10
      #define CMD_FM_SEEK_START_ARG_FORCE_WB_BIT  0x10
      #define CMD_FM_SEEK_START_ARG_FORCE_WB_MSB  4
      #define CMD_FM_SEEK_START_ARG_FORCE_WB_LSB  4
      #define CMD_FM_SEEK_START_ARG_FORCE_WB_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x10) | (((x)<<4)&0x10)))
      #define CMD_FM_SEEK_START_ARG_TUNE_MODE_TYPE bitfield
      #define CMD_FM_SEEK_START_ARG_TUNE_MODE_SIZE 2
      #define CMD_FM_SEEK_START_ARG_TUNE_MODE_MASK 0x0C
      #define CMD_FM_SEEK_START_ARG_TUNE_MODE_MSB  3
      #define CMD_FM_SEEK_START_ARG_TUNE_MODE_LSB  2
      #define CMD_FM_SEEK_START_ARG_TUNE_MODE_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0xC) | (((x)<<2)&0xC)))
      #define CMD_FM_SEEK_START_ARG_TUNE_MODE_ENUM_TUNE_ANALOG_ONLY 0
      #define CMD_FM_SEEK_START_ARG_TUNE_MODE_ENUM_RESERVED 1
      #define CMD_FM_SEEK_START_ARG_TUNE_MODE_ENUM_TUNE_HYBRID 2
      #define CMD_FM_SEEK_START_ARG_TUNE_MODE_ENUM_TUNE_DIGITAL_ONLY 3
      #define CMD_FM_SEEK_START_ARG_INJECTION_TYPE bitfield
      #define CMD_FM_SEEK_START_ARG_INJECTION_SIZE 2
      #define CMD_FM_SEEK_START_ARG_INJECTION_MASK 0x03
      #define CMD_FM_SEEK_START_ARG_INJECTION_MSB  1
      #define CMD_FM_SEEK_START_ARG_INJECTION_LSB  0
      #define CMD_FM_SEEK_START_ARG_INJECTION_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x3) | (((x)<<0)&0x3)))
      #define CMD_FM_SEEK_START_ARG_INJECTION_ENUM_FULL_AUTO 0
      #define CMD_FM_SEEK_START_ARG_INJECTION_ENUM_LOW_SIDE 1
      #define CMD_FM_SEEK_START_ARG_INJECTION_ENUM_HIGH_SIDE 2
      #define CMD_FM_SEEK_START_ARG_SEEKUP_TYPE bitfield
      #define CMD_FM_SEEK_START_ARG_SEEKUP_SIZE 1
      #define CMD_FM_SEEK_START_ARG_SEEKUP_MASK 0x02
      #define CMD_FM_SEEK_START_ARG_SEEKUP_BIT  0x02
      #define CMD_FM_SEEK_START_ARG_SEEKUP_MSB  1
      #define CMD_FM_SEEK_START_ARG_SEEKUP_LSB  1
      #define CMD_FM_SEEK_START_ARG_SEEKUP_write_field(x) (cmd_arg[2] = ((cmd_arg[2]&~0x2) | (((x)<<1)&0x2)))
      #define CMD_FM_SEEK_START_ARG_SEEKUP_ENUM_DOWN 0
      #define CMD_FM_SEEK_START_ARG_SEEKUP_ENUM_UP 1
      #define CMD_FM_SEEK_START_ARG_WRAP_TYPE bitfield
      #define CMD_FM_SEEK_START_ARG_WRAP_SIZE 1
      #define CMD_FM_SEEK_START_ARG_WRAP_MASK 0x01
      #define CMD_FM_SEEK_START_ARG_WRAP_BIT  0x01
      #define CMD_FM_SEEK_START_ARG_WRAP_MSB  0
      #define CMD_FM_SEEK_START_ARG_WRAP_LSB  0
      #define CMD_FM_SEEK_START_ARG_WRAP_write_field(x) (cmd_arg[2] = ((cmd_arg[2]&~0x1) | (((x)<<0)&0x1)))
      #define CMD_FM_SEEK_START_ARG_WRAP_ENUM_HALT 0
      #define CMD_FM_SEEK_START_ARG_WRAP_ENUM_WRAP 1
      #define CMD_FM_SEEK_START_ARG_ANTCAP_TYPE u16
      #define CMD_FM_SEEK_START_ARG_ANTCAP_SIZE 16
      #define CMD_FM_SEEK_START_ARG_ANTCAP_MASK 0xFFFF
      #define CMD_FM_SEEK_START_ARG_ANTCAP_MSB  15
      #define CMD_FM_SEEK_START_ARG_ANTCAP_LSB  0
      #define CMD_FM_SEEK_START_ARG_ANTCAP_INDEX 0x04
      #define CMD_FM_SEEK_START_ARG_ANTCAP_write_u16(x) (cmd_arg_u16[2] = (x))
      #define CMD_FM_SEEK_START_ARG_ANTCAP_MIN 0
      #define CMD_FM_SEEK_START_ARG_ANTCAP_MAX 128
      #define CMD_FM_SEEK_START_ARG_ANTCAP_ENUM_AUTO 0

#define CMD_FM_RSQ_STATUS        0x32
#define CMD_FM_RSQ_STATUS_LENGTH 2
#define CMD_FM_RSQ_STATUS_REP_LENGTH 23
//FM_RSQ_STATUS ARGS
      #define CMD_FM_RSQ_STATUS_ARG_RSQACK_TYPE bitfield
      #define CMD_FM_RSQ_STATUS_ARG_RSQACK_SIZE 1
      #define CMD_FM_RSQ_STATUS_ARG_RSQACK_MASK 0x08
      #define CMD_FM_RSQ_STATUS_ARG_RSQACK_BIT  0x08
      #define CMD_FM_RSQ_STATUS_ARG_RSQACK_MSB  3
      #define CMD_FM_RSQ_STATUS_ARG_RSQACK_LSB  3
      #define CMD_FM_RSQ_STATUS_ARG_RSQACK_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x8) | (((x)<<3)&0x8)))
      #define CMD_FM_RSQ_STATUS_ARG_ATTUNE_TYPE bitfield
      #define CMD_FM_RSQ_STATUS_ARG_ATTUNE_SIZE 1
      #define CMD_FM_RSQ_STATUS_ARG_ATTUNE_MASK 0x04
      #define CMD_FM_RSQ_STATUS_ARG_ATTUNE_BIT  0x04
      #define CMD_FM_RSQ_STATUS_ARG_ATTUNE_MSB  2
      #define CMD_FM_RSQ_STATUS_ARG_ATTUNE_LSB  2
      #define CMD_FM_RSQ_STATUS_ARG_ATTUNE_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x4) | (((x)<<2)&0x4)))
      #define CMD_FM_RSQ_STATUS_ARG_ATTUNE_ENUM_CUR_STATUS 0
      #define CMD_FM_RSQ_STATUS_ARG_ATTUNE_ENUM_ATTUNE_STATUS 1
      #define CMD_FM_RSQ_STATUS_ARG_CANCEL_TYPE bitfield
      #define CMD_FM_RSQ_STATUS_ARG_CANCEL_SIZE 1
      #define CMD_FM_RSQ_STATUS_ARG_CANCEL_MASK 0x02
      #define CMD_FM_RSQ_STATUS_ARG_CANCEL_BIT  0x02
      #define CMD_FM_RSQ_STATUS_ARG_CANCEL_MSB  1
      #define CMD_FM_RSQ_STATUS_ARG_CANCEL_LSB  1
      #define CMD_FM_RSQ_STATUS_ARG_CANCEL_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x2) | (((x)<<1)&0x2)))
      #define CMD_FM_RSQ_STATUS_ARG_STCACK_TYPE bitfield
      #define CMD_FM_RSQ_STATUS_ARG_STCACK_SIZE 1
      #define CMD_FM_RSQ_STATUS_ARG_STCACK_MASK 0x01
      #define CMD_FM_RSQ_STATUS_ARG_STCACK_BIT  0x01
      #define CMD_FM_RSQ_STATUS_ARG_STCACK_MSB  0
      #define CMD_FM_RSQ_STATUS_ARG_STCACK_LSB  0
      #define CMD_FM_RSQ_STATUS_ARG_STCACK_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x1) | (((x)<<0)&0x1)))
//FM_RSQ_STATUS REPLY
      #define CMD_FM_RSQ_STATUS_REP_HDLEVELHINT_TYPE bitfield
      #define CMD_FM_RSQ_STATUS_REP_HDLEVELHINT_SIZE 1
      #define CMD_FM_RSQ_STATUS_REP_HDLEVELHINT_MASK 0x20
      #define CMD_FM_RSQ_STATUS_REP_HDLEVELHINT_BIT  0x20
      #define CMD_FM_RSQ_STATUS_REP_HDLEVELHINT_MSB  5
      #define CMD_FM_RSQ_STATUS_REP_HDLEVELHINT_LSB  5
      #define CMD_FM_RSQ_STATUS_REP_HDLEVELHINT_is_true (reply_buffer[4]&0x20)
      #define CMD_FM_RSQ_STATUS_REP_HDLEVELHINT_value (((reply_buffer[4]&0x20))>>5)
      #define CMD_FM_RSQ_STATUS_REP_HDLEVELLINT_TYPE bitfield
      #define CMD_FM_RSQ_STATUS_REP_HDLEVELLINT_SIZE 1
      #define CMD_FM_RSQ_STATUS_REP_HDLEVELLINT_MASK 0x10
      #define CMD_FM_RSQ_STATUS_REP_HDLEVELLINT_BIT  0x10
      #define CMD_FM_RSQ_STATUS_REP_HDLEVELLINT_MSB  4
      #define CMD_FM_RSQ_STATUS_REP_HDLEVELLINT_LSB  4
      #define CMD_FM_RSQ_STATUS_REP_HDLEVELLINT_is_true (reply_buffer[4]&0x10)
      #define CMD_FM_RSQ_STATUS_REP_HDLEVELLINT_value (((reply_buffer[4]&0x10))>>4)
      #define CMD_FM_RSQ_STATUS_REP_SNRHINT_TYPE bitfield
      #define CMD_FM_RSQ_STATUS_REP_SNRHINT_SIZE 1
      #define CMD_FM_RSQ_STATUS_REP_SNRHINT_MASK 0x08
      #define CMD_FM_RSQ_STATUS_REP_SNRHINT_BIT  0x08
      #define CMD_FM_RSQ_STATUS_REP_SNRHINT_MSB  3
      #define CMD_FM_RSQ_STATUS_REP_SNRHINT_LSB  3
      #define CMD_FM_RSQ_STATUS_REP_SNRHINT_is_true (reply_buffer[4]&0x8)
      #define CMD_FM_RSQ_STATUS_REP_SNRHINT_value (((reply_buffer[4]&0x8))>>3)
      #define CMD_FM_RSQ_STATUS_REP_SNRLINT_TYPE bitfield
      #define CMD_FM_RSQ_STATUS_REP_SNRLINT_SIZE 1
      #define CMD_FM_RSQ_STATUS_REP_SNRLINT_MASK 0x04
      #define CMD_FM_RSQ_STATUS_REP_SNRLINT_BIT  0x04
      #define CMD_FM_RSQ_STATUS_REP_SNRLINT_MSB  2
      #define CMD_FM_RSQ_STATUS_REP_SNRLINT_LSB  2
      #define CMD_FM_RSQ_STATUS_REP_SNRLINT_is_true (reply_buffer[4]&0x4)
      #define CMD_FM_RSQ_STATUS_REP_SNRLINT_value (((reply_buffer[4]&0x4))>>2)
      #define CMD_FM_RSQ_STATUS_REP_RSSIHINT_TYPE bitfield
      #define CMD_FM_RSQ_STATUS_REP_RSSIHINT_SIZE 1
      #define CMD_FM_RSQ_STATUS_REP_RSSIHINT_MASK 0x02
      #define CMD_FM_RSQ_STATUS_REP_RSSIHINT_BIT  0x02
      #define CMD_FM_RSQ_STATUS_REP_RSSIHINT_MSB  1
      #define CMD_FM_RSQ_STATUS_REP_RSSIHINT_LSB  1
      #define CMD_FM_RSQ_STATUS_REP_RSSIHINT_is_true (reply_buffer[4]&0x2)
      #define CMD_FM_RSQ_STATUS_REP_RSSIHINT_value (((reply_buffer[4]&0x2))>>1)
      #define CMD_FM_RSQ_STATUS_REP_RSSILINT_TYPE bitfield
      #define CMD_FM_RSQ_STATUS_REP_RSSILINT_SIZE 1
      #define CMD_FM_RSQ_STATUS_REP_RSSILINT_MASK 0x01
      #define CMD_FM_RSQ_STATUS_REP_RSSILINT_BIT  0x01
      #define CMD_FM_RSQ_STATUS_REP_RSSILINT_MSB  0
      #define CMD_FM_RSQ_STATUS_REP_RSSILINT_LSB  0
      #define CMD_FM_RSQ_STATUS_REP_RSSILINT_is_true (reply_buffer[4]&0x1)
      #define CMD_FM_RSQ_STATUS_REP_RSSILINT_value (((reply_buffer[4]&0x1)))
      #define CMD_FM_RSQ_STATUS_REP_BLTF_TYPE bitfield
      #define CMD_FM_RSQ_STATUS_REP_BLTF_SIZE 1
      #define CMD_FM_RSQ_STATUS_REP_BLTF_MASK 0x80
      #define CMD_FM_RSQ_STATUS_REP_BLTF_BIT  0x80
      #define CMD_FM_RSQ_STATUS_REP_BLTF_MSB  7
      #define CMD_FM_RSQ_STATUS_REP_BLTF_LSB  7
      #define CMD_FM_RSQ_STATUS_REP_BLTF_is_true (reply_buffer[5]&0x80)
      #define CMD_FM_RSQ_STATUS_REP_BLTF_value (((reply_buffer[5]&0x80))>>7)
      #define CMD_FM_RSQ_STATUS_REP_HDDETECTED_TYPE bitfield
      #define CMD_FM_RSQ_STATUS_REP_HDDETECTED_SIZE 1
      #define CMD_FM_RSQ_STATUS_REP_HDDETECTED_MASK 0x20
      #define CMD_FM_RSQ_STATUS_REP_HDDETECTED_BIT  0x20
      #define CMD_FM_RSQ_STATUS_REP_HDDETECTED_MSB  5
      #define CMD_FM_RSQ_STATUS_REP_HDDETECTED_LSB  5
      #define CMD_FM_RSQ_STATUS_REP_HDDETECTED_is_true (reply_buffer[5]&0x20)
      #define CMD_FM_RSQ_STATUS_REP_HDDETECTED_value (((reply_buffer[5]&0x20))>>5)
      #define CMD_FM_RSQ_STATUS_REP_FLT_HDDETECTED_TYPE bitfield
      #define CMD_FM_RSQ_STATUS_REP_FLT_HDDETECTED_SIZE 1
      #define CMD_FM_RSQ_STATUS_REP_FLT_HDDETECTED_MASK 0x10
      #define CMD_FM_RSQ_STATUS_REP_FLT_HDDETECTED_BIT  0x10
      #define CMD_FM_RSQ_STATUS_REP_FLT_HDDETECTED_MSB  4
      #define CMD_FM_RSQ_STATUS_REP_FLT_HDDETECTED_LSB  4
      #define CMD_FM_RSQ_STATUS_REP_FLT_HDDETECTED_is_true (reply_buffer[5]&0x10)
      #define CMD_FM_RSQ_STATUS_REP_FLT_HDDETECTED_value (((reply_buffer[5]&0x10))>>4)
      #define CMD_FM_RSQ_STATUS_REP_AFCRL_TYPE bitfield
      #define CMD_FM_RSQ_STATUS_REP_AFCRL_SIZE 1
      #define CMD_FM_RSQ_STATUS_REP_AFCRL_MASK 0x02
      #define CMD_FM_RSQ_STATUS_REP_AFCRL_BIT  0x02
      #define CMD_FM_RSQ_STATUS_REP_AFCRL_MSB  1
      #define CMD_FM_RSQ_STATUS_REP_AFCRL_LSB  1
      #define CMD_FM_RSQ_STATUS_REP_AFCRL_is_true (reply_buffer[5]&0x2)
      #define CMD_FM_RSQ_STATUS_REP_AFCRL_value (((reply_buffer[5]&0x2))>>1)
      #define CMD_FM_RSQ_STATUS_REP_VALID_TYPE bitfield
      #define CMD_FM_RSQ_STATUS_REP_VALID_SIZE 1
      #define CMD_FM_RSQ_STATUS_REP_VALID_MASK 0x01
      #define CMD_FM_RSQ_STATUS_REP_VALID_BIT  0x01
      #define CMD_FM_RSQ_STATUS_REP_VALID_MSB  0
      #define CMD_FM_RSQ_STATUS_REP_VALID_LSB  0
      #define CMD_FM_RSQ_STATUS_REP_VALID_is_true (reply_buffer[5]&0x1)
      #define CMD_FM_RSQ_STATUS_REP_VALID_value (((reply_buffer[5]&0x1)))
      #define CMD_FM_RSQ_STATUS_REP_READFREQ_TYPE u16
      #define CMD_FM_RSQ_STATUS_REP_READFREQ_SIZE 16
      #define CMD_FM_RSQ_STATUS_REP_READFREQ_MASK 0xFFFF
      #define CMD_FM_RSQ_STATUS_REP_READFREQ_MSB  15
      #define CMD_FM_RSQ_STATUS_REP_READFREQ_LSB  0
      #define CMD_FM_RSQ_STATUS_REP_READFREQ_INDEX 0x06
      #define CMD_FM_RSQ_STATUS_REP_READFREQ_value (((reply_buffer_u16[3])))
      #define CMD_FM_RSQ_STATUS_REP_FREQOFF_TYPE i8
      #define CMD_FM_RSQ_STATUS_REP_FREQOFF_SIZE 8
      #define CMD_FM_RSQ_STATUS_REP_FREQOFF_MASK 0xFF
      #define CMD_FM_RSQ_STATUS_REP_FREQOFF_MSB  7
      #define CMD_FM_RSQ_STATUS_REP_FREQOFF_LSB  0
      #define CMD_FM_RSQ_STATUS_REP_FREQOFF_INDEX 0x08
      #define CMD_FM_RSQ_STATUS_REP_FREQOFF_value (((uint8_t)(reply_buffer[8])))
      #define CMD_FM_RSQ_STATUS_REP_FREQOFF_MIN -128
      #define CMD_FM_RSQ_STATUS_REP_FREQOFF_MAX 127
      #define CMD_FM_RSQ_STATUS_REP_RSSI_TYPE i8
      #define CMD_FM_RSQ_STATUS_REP_RSSI_SIZE 8
      #define CMD_FM_RSQ_STATUS_REP_RSSI_MASK 0xFF
      #define CMD_FM_RSQ_STATUS_REP_RSSI_MSB  7
      #define CMD_FM_RSQ_STATUS_REP_RSSI_LSB  0
      #define CMD_FM_RSQ_STATUS_REP_RSSI_INDEX 0x09
      #define CMD_FM_RSQ_STATUS_REP_RSSI_value (((uint8_t)(reply_buffer[9])))
      #define CMD_FM_RSQ_STATUS_REP_RSSI_MIN -128
      #define CMD_FM_RSQ_STATUS_REP_RSSI_MAX 127
      #define CMD_FM_RSQ_STATUS_REP_SNR_TYPE i8
      #define CMD_FM_RSQ_STATUS_REP_SNR_SIZE 8
      #define CMD_FM_RSQ_STATUS_REP_SNR_MASK 0xFF
      #define CMD_FM_RSQ_STATUS_REP_SNR_MSB  7
      #define CMD_FM_RSQ_STATUS_REP_SNR_LSB  0
      #define CMD_FM_RSQ_STATUS_REP_SNR_INDEX 0x0A
      #define CMD_FM_RSQ_STATUS_REP_SNR_value (((uint8_t)(reply_buffer[10])))
      #define CMD_FM_RSQ_STATUS_REP_SNR_MIN -128
      #define CMD_FM_RSQ_STATUS_REP_SNR_MAX 127
      #define CMD_FM_RSQ_STATUS_REP_MULT_TYPE u8
      #define CMD_FM_RSQ_STATUS_REP_MULT_SIZE 8
      #define CMD_FM_RSQ_STATUS_REP_MULT_MASK 0xFF
      #define CMD_FM_RSQ_STATUS_REP_MULT_MSB  7
      #define CMD_FM_RSQ_STATUS_REP_MULT_LSB  0
      #define CMD_FM_RSQ_STATUS_REP_MULT_INDEX 0x0B
      #define CMD_FM_RSQ_STATUS_REP_MULT_value (((reply_buffer[11])))
      #define CMD_FM_RSQ_STATUS_REP_MULT_MIN 0
      #define CMD_FM_RSQ_STATUS_REP_MULT_MAX 255
      #define CMD_FM_RSQ_STATUS_REP_READANTCAP_TYPE u16
      #define CMD_FM_RSQ_STATUS_REP_READANTCAP_SIZE 16
      #define CMD_FM_RSQ_STATUS_REP_READANTCAP_MASK 0xFFFF
      #define CMD_FM_RSQ_STATUS_REP_READANTCAP_MSB  15
      #define CMD_FM_RSQ_STATUS_REP_READANTCAP_LSB  0
      #define CMD_FM_RSQ_STATUS_REP_READANTCAP_INDEX 0x0C
      #define CMD_FM_RSQ_STATUS_REP_READANTCAP_value (((reply_buffer_u16[6])))
      #define CMD_FM_RSQ_STATUS_REP_HDLEVEL_TYPE u8
      #define CMD_FM_RSQ_STATUS_REP_HDLEVEL_SIZE 8
      #define CMD_FM_RSQ_STATUS_REP_HDLEVEL_MASK 0xFF
      #define CMD_FM_RSQ_STATUS_REP_HDLEVEL_MSB  7
      #define CMD_FM_RSQ_STATUS_REP_HDLEVEL_LSB  0
      #define CMD_FM_RSQ_STATUS_REP_HDLEVEL_INDEX 0x0F
      #define CMD_FM_RSQ_STATUS_REP_HDLEVEL_value (((reply_buffer[15])))
      #define CMD_FM_RSQ_STATUS_REP_HDLEVEL_MIN 0
      #define CMD_FM_RSQ_STATUS_REP_HDLEVEL_MAX 100
      #define CMD_FM_RSQ_STATUS_REP_FILTERED_HDLEVEL_TYPE u8
      #define CMD_FM_RSQ_STATUS_REP_FILTERED_HDLEVEL_SIZE 8
      #define CMD_FM_RSQ_STATUS_REP_FILTERED_HDLEVEL_MASK 0xFF
      #define CMD_FM_RSQ_STATUS_REP_FILTERED_HDLEVEL_MSB  7
      #define CMD_FM_RSQ_STATUS_REP_FILTERED_HDLEVEL_LSB  0
      #define CMD_FM_RSQ_STATUS_REP_FILTERED_HDLEVEL_INDEX 0x10
      #define CMD_FM_RSQ_STATUS_REP_FILTERED_HDLEVEL_value (((reply_buffer[16])))
      #define CMD_FM_RSQ_STATUS_REP_FILTERED_HDLEVEL_MIN 0
      #define CMD_FM_RSQ_STATUS_REP_FILTERED_HDLEVEL_MAX 100
      #define CMD_FM_RSQ_STATUS_REP_HDSB_OFFSET_TYPE i8
      #define CMD_FM_RSQ_STATUS_REP_HDSB_OFFSET_SIZE 8
      #define CMD_FM_RSQ_STATUS_REP_HDSB_OFFSET_MASK 0xFF
      #define CMD_FM_RSQ_STATUS_REP_HDSB_OFFSET_MSB  7
      #define CMD_FM_RSQ_STATUS_REP_HDSB_OFFSET_LSB  0
      #define CMD_FM_RSQ_STATUS_REP_HDSB_OFFSET_INDEX 0x16
      #define CMD_FM_RSQ_STATUS_REP_HDSB_OFFSET_value (((uint8_t)(reply_buffer[22])))
      #define CMD_FM_RSQ_STATUS_REP_HDSB_OFFSET_MIN -128
      #define CMD_FM_RSQ_STATUS_REP_HDSB_OFFSET_MAX 127

#define CMD_FM_ACF_STATUS        0x33
#define CMD_FM_ACF_STATUS_LENGTH 2
#define CMD_FM_ACF_STATUS_REP_LENGTH 11
//FM_ACF_STATUS ARGS
      #define CMD_FM_ACF_STATUS_ARG_ACFACK_TYPE bitfield
      #define CMD_FM_ACF_STATUS_ARG_ACFACK_SIZE 1
      #define CMD_FM_ACF_STATUS_ARG_ACFACK_MASK 0x01
      #define CMD_FM_ACF_STATUS_ARG_ACFACK_BIT  0x01
      #define CMD_FM_ACF_STATUS_ARG_ACFACK_MSB  0
      #define CMD_FM_ACF_STATUS_ARG_ACFACK_LSB  0
      #define CMD_FM_ACF_STATUS_ARG_ACFACK_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x1) | (((x)<<0)&0x1)))
//FM_ACF_STATUS REPLY
      #define CMD_FM_ACF_STATUS_REP_BLEND_INT_TYPE bitfield
      #define CMD_FM_ACF_STATUS_REP_BLEND_INT_SIZE 1
      #define CMD_FM_ACF_STATUS_REP_BLEND_INT_MASK 0x04
      #define CMD_FM_ACF_STATUS_REP_BLEND_INT_BIT  0x04
      #define CMD_FM_ACF_STATUS_REP_BLEND_INT_MSB  2
      #define CMD_FM_ACF_STATUS_REP_BLEND_INT_LSB  2
      #define CMD_FM_ACF_STATUS_REP_BLEND_INT_is_true (reply_buffer[4]&0x4)
      #define CMD_FM_ACF_STATUS_REP_BLEND_INT_value (((reply_buffer[4]&0x4))>>2)
      #define CMD_FM_ACF_STATUS_REP_HIGHCUT_INT_TYPE bitfield
      #define CMD_FM_ACF_STATUS_REP_HIGHCUT_INT_SIZE 1
      #define CMD_FM_ACF_STATUS_REP_HIGHCUT_INT_MASK 0x02
      #define CMD_FM_ACF_STATUS_REP_HIGHCUT_INT_BIT  0x02
      #define CMD_FM_ACF_STATUS_REP_HIGHCUT_INT_MSB  1
      #define CMD_FM_ACF_STATUS_REP_HIGHCUT_INT_LSB  1
      #define CMD_FM_ACF_STATUS_REP_HIGHCUT_INT_is_true (reply_buffer[4]&0x2)
      #define CMD_FM_ACF_STATUS_REP_HIGHCUT_INT_value (((reply_buffer[4]&0x2))>>1)
      #define CMD_FM_ACF_STATUS_REP_SMUTE_INT_TYPE bitfield
      #define CMD_FM_ACF_STATUS_REP_SMUTE_INT_SIZE 1
      #define CMD_FM_ACF_STATUS_REP_SMUTE_INT_MASK 0x01
      #define CMD_FM_ACF_STATUS_REP_SMUTE_INT_BIT  0x01
      #define CMD_FM_ACF_STATUS_REP_SMUTE_INT_MSB  0
      #define CMD_FM_ACF_STATUS_REP_SMUTE_INT_LSB  0
      #define CMD_FM_ACF_STATUS_REP_SMUTE_INT_is_true (reply_buffer[4]&0x1)
      #define CMD_FM_ACF_STATUS_REP_SMUTE_INT_value (((reply_buffer[4]&0x1)))
      #define CMD_FM_ACF_STATUS_REP_BLEND_CONV_TYPE bitfield
      #define CMD_FM_ACF_STATUS_REP_BLEND_CONV_SIZE 1
      #define CMD_FM_ACF_STATUS_REP_BLEND_CONV_MASK 0x40
      #define CMD_FM_ACF_STATUS_REP_BLEND_CONV_BIT  0x40
      #define CMD_FM_ACF_STATUS_REP_BLEND_CONV_MSB  6
      #define CMD_FM_ACF_STATUS_REP_BLEND_CONV_LSB  6
      #define CMD_FM_ACF_STATUS_REP_BLEND_CONV_is_true (reply_buffer[5]&0x40)
      #define CMD_FM_ACF_STATUS_REP_BLEND_CONV_value (((reply_buffer[5]&0x40))>>6)
      #define CMD_FM_ACF_STATUS_REP_HIGHCUT_CONV_TYPE bitfield
      #define CMD_FM_ACF_STATUS_REP_HIGHCUT_CONV_SIZE 1
      #define CMD_FM_ACF_STATUS_REP_HIGHCUT_CONV_MASK 0x20
      #define CMD_FM_ACF_STATUS_REP_HIGHCUT_CONV_BIT  0x20
      #define CMD_FM_ACF_STATUS_REP_HIGHCUT_CONV_MSB  5
      #define CMD_FM_ACF_STATUS_REP_HIGHCUT_CONV_LSB  5
      #define CMD_FM_ACF_STATUS_REP_HIGHCUT_CONV_is_true (reply_buffer[5]&0x20)
      #define CMD_FM_ACF_STATUS_REP_HIGHCUT_CONV_value (((reply_buffer[5]&0x20))>>5)
      #define CMD_FM_ACF_STATUS_REP_SMUTE_CONV_TYPE bitfield
      #define CMD_FM_ACF_STATUS_REP_SMUTE_CONV_SIZE 1
      #define CMD_FM_ACF_STATUS_REP_SMUTE_CONV_MASK 0x10
      #define CMD_FM_ACF_STATUS_REP_SMUTE_CONV_BIT  0x10
      #define CMD_FM_ACF_STATUS_REP_SMUTE_CONV_MSB  4
      #define CMD_FM_ACF_STATUS_REP_SMUTE_CONV_LSB  4
      #define CMD_FM_ACF_STATUS_REP_SMUTE_CONV_is_true (reply_buffer[5]&0x10)
      #define CMD_FM_ACF_STATUS_REP_SMUTE_CONV_value (((reply_buffer[5]&0x10))>>4)
      #define CMD_FM_ACF_STATUS_REP_BLEND_STATE_TYPE bitfield
      #define CMD_FM_ACF_STATUS_REP_BLEND_STATE_SIZE 1
      #define CMD_FM_ACF_STATUS_REP_BLEND_STATE_MASK 0x04
      #define CMD_FM_ACF_STATUS_REP_BLEND_STATE_BIT  0x04
      #define CMD_FM_ACF_STATUS_REP_BLEND_STATE_MSB  2
      #define CMD_FM_ACF_STATUS_REP_BLEND_STATE_LSB  2
      #define CMD_FM_ACF_STATUS_REP_BLEND_STATE_is_true (reply_buffer[5]&0x4)
      #define CMD_FM_ACF_STATUS_REP_BLEND_STATE_value (((reply_buffer[5]&0x4))>>2)
      #define CMD_FM_ACF_STATUS_REP_HIGHCUT_STATE_TYPE bitfield
      #define CMD_FM_ACF_STATUS_REP_HIGHCUT_STATE_SIZE 1
      #define CMD_FM_ACF_STATUS_REP_HIGHCUT_STATE_MASK 0x02
      #define CMD_FM_ACF_STATUS_REP_HIGHCUT_STATE_BIT  0x02
      #define CMD_FM_ACF_STATUS_REP_HIGHCUT_STATE_MSB  1
      #define CMD_FM_ACF_STATUS_REP_HIGHCUT_STATE_LSB  1
      #define CMD_FM_ACF_STATUS_REP_HIGHCUT_STATE_is_true (reply_buffer[5]&0x2)
      #define CMD_FM_ACF_STATUS_REP_HIGHCUT_STATE_value (((reply_buffer[5]&0x2))>>1)
      #define CMD_FM_ACF_STATUS_REP_SMUTE_STATE_TYPE bitfield
      #define CMD_FM_ACF_STATUS_REP_SMUTE_STATE_SIZE 1
      #define CMD_FM_ACF_STATUS_REP_SMUTE_STATE_MASK 0x01
      #define CMD_FM_ACF_STATUS_REP_SMUTE_STATE_BIT  0x01
      #define CMD_FM_ACF_STATUS_REP_SMUTE_STATE_MSB  0
      #define CMD_FM_ACF_STATUS_REP_SMUTE_STATE_LSB  0
      #define CMD_FM_ACF_STATUS_REP_SMUTE_STATE_is_true (reply_buffer[5]&0x1)
      #define CMD_FM_ACF_STATUS_REP_SMUTE_STATE_value (((reply_buffer[5]&0x1)))
      #define CMD_FM_ACF_STATUS_REP_ATTN_TYPE bitfield
      #define CMD_FM_ACF_STATUS_REP_ATTN_SIZE 5
      #define CMD_FM_ACF_STATUS_REP_ATTN_MASK 0x1F
      #define CMD_FM_ACF_STATUS_REP_ATTN_MSB  4
      #define CMD_FM_ACF_STATUS_REP_ATTN_LSB  0
      #define CMD_FM_ACF_STATUS_REP_ATTN_value (((reply_buffer[6]&0x1F)))
      #define CMD_FM_ACF_STATUS_REP_ATTN_MIN 0
      #define CMD_FM_ACF_STATUS_REP_ATTN_MAX 31
      #define CMD_FM_ACF_STATUS_REP_HIGHCUT_TYPE u8
      #define CMD_FM_ACF_STATUS_REP_HIGHCUT_SIZE 8
      #define CMD_FM_ACF_STATUS_REP_HIGHCUT_MASK 0xFF
      #define CMD_FM_ACF_STATUS_REP_HIGHCUT_MSB  7
      #define CMD_FM_ACF_STATUS_REP_HIGHCUT_LSB  0
      #define CMD_FM_ACF_STATUS_REP_HIGHCUT_INDEX 0x07
      #define CMD_FM_ACF_STATUS_REP_HIGHCUT_value (((reply_buffer[7])))
      #define CMD_FM_ACF_STATUS_REP_HIGHCUT_MIN 10
      #define CMD_FM_ACF_STATUS_REP_HIGHCUT_MAX 200
      #define CMD_FM_ACF_STATUS_REP_PILOT_TYPE bitfield
      #define CMD_FM_ACF_STATUS_REP_PILOT_SIZE 1
      #define CMD_FM_ACF_STATUS_REP_PILOT_MASK 0x80
      #define CMD_FM_ACF_STATUS_REP_PILOT_BIT  0x80
      #define CMD_FM_ACF_STATUS_REP_PILOT_MSB  7
      #define CMD_FM_ACF_STATUS_REP_PILOT_LSB  7
      #define CMD_FM_ACF_STATUS_REP_PILOT_is_true (reply_buffer[8]&0x80)
      #define CMD_FM_ACF_STATUS_REP_PILOT_value (((reply_buffer[8]&0x80))>>7)
      #define CMD_FM_ACF_STATUS_REP_PILOT_ENUM_MONO 0
      #define CMD_FM_ACF_STATUS_REP_PILOT_ENUM_STEREO 1
      #define CMD_FM_ACF_STATUS_REP_STBLEND_TYPE bitfield
      #define CMD_FM_ACF_STATUS_REP_STBLEND_SIZE 7
      #define CMD_FM_ACF_STATUS_REP_STBLEND_MASK 0x7F
      #define CMD_FM_ACF_STATUS_REP_STBLEND_MSB  6
      #define CMD_FM_ACF_STATUS_REP_STBLEND_LSB  0
      #define CMD_FM_ACF_STATUS_REP_STBLEND_value (((reply_buffer[8]&0x7F)))

#define CMD_FM_RDS_STATUS        0x34
#define CMD_FM_RDS_STATUS_LENGTH 2
#define CMD_FM_RDS_STATUS_REP_LENGTH 20
//FM_RDS_STATUS ARGS
      #define CMD_FM_RDS_STATUS_ARG_STATUSONLY_TYPE bitfield
      #define CMD_FM_RDS_STATUS_ARG_STATUSONLY_SIZE 1
      #define CMD_FM_RDS_STATUS_ARG_STATUSONLY_MASK 0x04
      #define CMD_FM_RDS_STATUS_ARG_STATUSONLY_BIT  0x04
      #define CMD_FM_RDS_STATUS_ARG_STATUSONLY_MSB  2
      #define CMD_FM_RDS_STATUS_ARG_STATUSONLY_LSB  2
      #define CMD_FM_RDS_STATUS_ARG_STATUSONLY_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x4) | (((x)<<2)&0x4)))
      #define CMD_FM_RDS_STATUS_ARG_STATUSONLY_ENUM_DEQUEUE 0
      #define CMD_FM_RDS_STATUS_ARG_STATUSONLY_ENUM_STATUSONLY 1
      #define CMD_FM_RDS_STATUS_ARG_MTFIFO_TYPE bitfield
      #define CMD_FM_RDS_STATUS_ARG_MTFIFO_SIZE 1
      #define CMD_FM_RDS_STATUS_ARG_MTFIFO_MASK 0x02
      #define CMD_FM_RDS_STATUS_ARG_MTFIFO_BIT  0x02
      #define CMD_FM_RDS_STATUS_ARG_MTFIFO_MSB  1
      #define CMD_FM_RDS_STATUS_ARG_MTFIFO_LSB  1
      #define CMD_FM_RDS_STATUS_ARG_MTFIFO_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x2) | (((x)<<1)&0x2)))
      #define CMD_FM_RDS_STATUS_ARG_INTACK_TYPE bitfield
      #define CMD_FM_RDS_STATUS_ARG_INTACK_SIZE 1
      #define CMD_FM_RDS_STATUS_ARG_INTACK_MASK 0x01
      #define CMD_FM_RDS_STATUS_ARG_INTACK_BIT  0x01
      #define CMD_FM_RDS_STATUS_ARG_INTACK_MSB  0
      #define CMD_FM_RDS_STATUS_ARG_INTACK_LSB  0
      #define CMD_FM_RDS_STATUS_ARG_INTACK_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x1) | (((x)<<0)&0x1)))
//FM_RDS_STATUS REPLY
      #define CMD_FM_RDS_STATUS_REP_RDSTPPTYINT_TYPE bitfield
      #define CMD_FM_RDS_STATUS_REP_RDSTPPTYINT_SIZE 1
      #define CMD_FM_RDS_STATUS_REP_RDSTPPTYINT_MASK 0x10
      #define CMD_FM_RDS_STATUS_REP_RDSTPPTYINT_BIT  0x10
      #define CMD_FM_RDS_STATUS_REP_RDSTPPTYINT_MSB  4
      #define CMD_FM_RDS_STATUS_REP_RDSTPPTYINT_LSB  4
      #define CMD_FM_RDS_STATUS_REP_RDSTPPTYINT_is_true (reply_buffer[4]&0x10)
      #define CMD_FM_RDS_STATUS_REP_RDSTPPTYINT_value (((reply_buffer[4]&0x10))>>4)
      #define CMD_FM_RDS_STATUS_REP_RDSPIINT_TYPE bitfield
      #define CMD_FM_RDS_STATUS_REP_RDSPIINT_SIZE 1
      #define CMD_FM_RDS_STATUS_REP_RDSPIINT_MASK 0x08
      #define CMD_FM_RDS_STATUS_REP_RDSPIINT_BIT  0x08
      #define CMD_FM_RDS_STATUS_REP_RDSPIINT_MSB  3
      #define CMD_FM_RDS_STATUS_REP_RDSPIINT_LSB  3
      #define CMD_FM_RDS_STATUS_REP_RDSPIINT_is_true (reply_buffer[4]&0x8)
      #define CMD_FM_RDS_STATUS_REP_RDSPIINT_value (((reply_buffer[4]&0x8))>>3)
      #define CMD_FM_RDS_STATUS_REP_RDSSYNCINT_TYPE bitfield
      #define CMD_FM_RDS_STATUS_REP_RDSSYNCINT_SIZE 1
      #define CMD_FM_RDS_STATUS_REP_RDSSYNCINT_MASK 0x02
      #define CMD_FM_RDS_STATUS_REP_RDSSYNCINT_BIT  0x02
      #define CMD_FM_RDS_STATUS_REP_RDSSYNCINT_MSB  1
      #define CMD_FM_RDS_STATUS_REP_RDSSYNCINT_LSB  1
      #define CMD_FM_RDS_STATUS_REP_RDSSYNCINT_is_true (reply_buffer[4]&0x2)
      #define CMD_FM_RDS_STATUS_REP_RDSSYNCINT_value (((reply_buffer[4]&0x2))>>1)
      #define CMD_FM_RDS_STATUS_REP_RDSFIFOINT_TYPE bitfield
      #define CMD_FM_RDS_STATUS_REP_RDSFIFOINT_SIZE 1
      #define CMD_FM_RDS_STATUS_REP_RDSFIFOINT_MASK 0x01
      #define CMD_FM_RDS_STATUS_REP_RDSFIFOINT_BIT  0x01
      #define CMD_FM_RDS_STATUS_REP_RDSFIFOINT_MSB  0
      #define CMD_FM_RDS_STATUS_REP_RDSFIFOINT_LSB  0
      #define CMD_FM_RDS_STATUS_REP_RDSFIFOINT_is_true (reply_buffer[4]&0x1)
      #define CMD_FM_RDS_STATUS_REP_RDSFIFOINT_value (((reply_buffer[4]&0x1)))
      #define CMD_FM_RDS_STATUS_REP_TPPTYVALID_TYPE bitfield
      #define CMD_FM_RDS_STATUS_REP_TPPTYVALID_SIZE 1
      #define CMD_FM_RDS_STATUS_REP_TPPTYVALID_MASK 0x10
      #define CMD_FM_RDS_STATUS_REP_TPPTYVALID_BIT  0x10
      #define CMD_FM_RDS_STATUS_REP_TPPTYVALID_MSB  4
      #define CMD_FM_RDS_STATUS_REP_TPPTYVALID_LSB  4
      #define CMD_FM_RDS_STATUS_REP_TPPTYVALID_is_true (reply_buffer[5]&0x10)
      #define CMD_FM_RDS_STATUS_REP_TPPTYVALID_value (((reply_buffer[5]&0x10))>>4)
      #define CMD_FM_RDS_STATUS_REP_PIVALID_TYPE bitfield
      #define CMD_FM_RDS_STATUS_REP_PIVALID_SIZE 1
      #define CMD_FM_RDS_STATUS_REP_PIVALID_MASK 0x08
      #define CMD_FM_RDS_STATUS_REP_PIVALID_BIT  0x08
      #define CMD_FM_RDS_STATUS_REP_PIVALID_MSB  3
      #define CMD_FM_RDS_STATUS_REP_PIVALID_LSB  3
      #define CMD_FM_RDS_STATUS_REP_PIVALID_is_true (reply_buffer[5]&0x8)
      #define CMD_FM_RDS_STATUS_REP_PIVALID_value (((reply_buffer[5]&0x8))>>3)
      #define CMD_FM_RDS_STATUS_REP_RDSSYNC_TYPE bitfield
      #define CMD_FM_RDS_STATUS_REP_RDSSYNC_SIZE 1
      #define CMD_FM_RDS_STATUS_REP_RDSSYNC_MASK 0x02
      #define CMD_FM_RDS_STATUS_REP_RDSSYNC_BIT  0x02
      #define CMD_FM_RDS_STATUS_REP_RDSSYNC_MSB  1
      #define CMD_FM_RDS_STATUS_REP_RDSSYNC_LSB  1
      #define CMD_FM_RDS_STATUS_REP_RDSSYNC_is_true (reply_buffer[5]&0x2)
      #define CMD_FM_RDS_STATUS_REP_RDSSYNC_value (((reply_buffer[5]&0x2))>>1)
      #define CMD_FM_RDS_STATUS_REP_RDSFIFOLOST_TYPE bitfield
      #define CMD_FM_RDS_STATUS_REP_RDSFIFOLOST_SIZE 1
      #define CMD_FM_RDS_STATUS_REP_RDSFIFOLOST_MASK 0x01
      #define CMD_FM_RDS_STATUS_REP_RDSFIFOLOST_BIT  0x01
      #define CMD_FM_RDS_STATUS_REP_RDSFIFOLOST_MSB  0
      #define CMD_FM_RDS_STATUS_REP_RDSFIFOLOST_LSB  0
      #define CMD_FM_RDS_STATUS_REP_RDSFIFOLOST_is_true (reply_buffer[5]&0x1)
      #define CMD_FM_RDS_STATUS_REP_RDSFIFOLOST_value (((reply_buffer[5]&0x1)))
      #define CMD_FM_RDS_STATUS_REP_TP_TYPE bitfield
      #define CMD_FM_RDS_STATUS_REP_TP_SIZE 1
      #define CMD_FM_RDS_STATUS_REP_TP_MASK 0x20
      #define CMD_FM_RDS_STATUS_REP_TP_BIT  0x20
      #define CMD_FM_RDS_STATUS_REP_TP_MSB  5
      #define CMD_FM_RDS_STATUS_REP_TP_LSB  5
      #define CMD_FM_RDS_STATUS_REP_TP_is_true (reply_buffer[6]&0x20)
      #define CMD_FM_RDS_STATUS_REP_TP_value (((reply_buffer[6]&0x20))>>5)
      #define CMD_FM_RDS_STATUS_REP_PTY_TYPE bitfield
      #define CMD_FM_RDS_STATUS_REP_PTY_SIZE 5
      #define CMD_FM_RDS_STATUS_REP_PTY_MASK 0x1F
      #define CMD_FM_RDS_STATUS_REP_PTY_MSB  4
      #define CMD_FM_RDS_STATUS_REP_PTY_LSB  0
      #define CMD_FM_RDS_STATUS_REP_PTY_value (((reply_buffer[6]&0x1F)))
      #define CMD_FM_RDS_STATUS_REP_PI_TYPE u16
      #define CMD_FM_RDS_STATUS_REP_PI_SIZE 16
      #define CMD_FM_RDS_STATUS_REP_PI_MASK 0xFFFF
      #define CMD_FM_RDS_STATUS_REP_PI_MSB  15
      #define CMD_FM_RDS_STATUS_REP_PI_LSB  0
      #define CMD_FM_RDS_STATUS_REP_PI_INDEX 0x08
      #define CMD_FM_RDS_STATUS_REP_PI_value (((reply_buffer_u16[4])))
      #define CMD_FM_RDS_STATUS_REP_RDSFIFOUSED_TYPE u8
      #define CMD_FM_RDS_STATUS_REP_RDSFIFOUSED_SIZE 8
      #define CMD_FM_RDS_STATUS_REP_RDSFIFOUSED_MASK 0xFF
      #define CMD_FM_RDS_STATUS_REP_RDSFIFOUSED_MSB  7
      #define CMD_FM_RDS_STATUS_REP_RDSFIFOUSED_LSB  0
      #define CMD_FM_RDS_STATUS_REP_RDSFIFOUSED_INDEX 0x0A
      #define CMD_FM_RDS_STATUS_REP_RDSFIFOUSED_value (((reply_buffer[10])))
      #define CMD_FM_RDS_STATUS_REP_BLEA_TYPE bitfield
      #define CMD_FM_RDS_STATUS_REP_BLEA_SIZE 2
      #define CMD_FM_RDS_STATUS_REP_BLEA_MASK 0xC0
      #define CMD_FM_RDS_STATUS_REP_BLEA_MSB  7
      #define CMD_FM_RDS_STATUS_REP_BLEA_LSB  6
      #define CMD_FM_RDS_STATUS_REP_BLEA_value (((reply_buffer[11]&0xC0))>>6)
      #define CMD_FM_RDS_STATUS_REP_BLEA_ENUM_NONE 0
      #define CMD_FM_RDS_STATUS_REP_BLEA_ENUM_ONETOTWO 1
      #define CMD_FM_RDS_STATUS_REP_BLEA_ENUM_THREETOFIVE 2
      #define CMD_FM_RDS_STATUS_REP_BLEA_ENUM_SIXORMORE 3
      #define CMD_FM_RDS_STATUS_REP_BLEB_TYPE bitfield
      #define CMD_FM_RDS_STATUS_REP_BLEB_SIZE 2
      #define CMD_FM_RDS_STATUS_REP_BLEB_MASK 0x30
      #define CMD_FM_RDS_STATUS_REP_BLEB_MSB  5
      #define CMD_FM_RDS_STATUS_REP_BLEB_LSB  4
      #define CMD_FM_RDS_STATUS_REP_BLEB_value (((reply_buffer[11]&0x30))>>4)
      #define CMD_FM_RDS_STATUS_REP_BLEC_TYPE bitfield
      #define CMD_FM_RDS_STATUS_REP_BLEC_SIZE 2
      #define CMD_FM_RDS_STATUS_REP_BLEC_MASK 0x0C
      #define CMD_FM_RDS_STATUS_REP_BLEC_MSB  3
      #define CMD_FM_RDS_STATUS_REP_BLEC_LSB  2
      #define CMD_FM_RDS_STATUS_REP_BLEC_value (((reply_buffer[11]&0xC))>>2)
      #define CMD_FM_RDS_STATUS_REP_BLED_TYPE bitfield
      #define CMD_FM_RDS_STATUS_REP_BLED_SIZE 2
      #define CMD_FM_RDS_STATUS_REP_BLED_MASK 0x03
      #define CMD_FM_RDS_STATUS_REP_BLED_MSB  1
      #define CMD_FM_RDS_STATUS_REP_BLED_LSB  0
      #define CMD_FM_RDS_STATUS_REP_BLED_value (((reply_buffer[11]&0x3)))
      #define CMD_FM_RDS_STATUS_REP_BLOCKA_TYPE u16
      #define CMD_FM_RDS_STATUS_REP_BLOCKA_SIZE 16
      #define CMD_FM_RDS_STATUS_REP_BLOCKA_MASK 0xFFFF
      #define CMD_FM_RDS_STATUS_REP_BLOCKA_MSB  15
      #define CMD_FM_RDS_STATUS_REP_BLOCKA_LSB  0
      #define CMD_FM_RDS_STATUS_REP_BLOCKA_INDEX 0x0C
      #define CMD_FM_RDS_STATUS_REP_BLOCKA_value (((reply_buffer_u16[6])))
      #define CMD_FM_RDS_STATUS_REP_BLOCKB_TYPE u16
      #define CMD_FM_RDS_STATUS_REP_BLOCKB_SIZE 16
      #define CMD_FM_RDS_STATUS_REP_BLOCKB_MASK 0xFFFF
      #define CMD_FM_RDS_STATUS_REP_BLOCKB_MSB  15
      #define CMD_FM_RDS_STATUS_REP_BLOCKB_LSB  0
      #define CMD_FM_RDS_STATUS_REP_BLOCKB_INDEX 0x0E
      #define CMD_FM_RDS_STATUS_REP_BLOCKB_value (((reply_buffer_u16[7])))
      #define CMD_FM_RDS_STATUS_REP_BLOCKC_TYPE u16
      #define CMD_FM_RDS_STATUS_REP_BLOCKC_SIZE 16
      #define CMD_FM_RDS_STATUS_REP_BLOCKC_MASK 0xFFFF
      #define CMD_FM_RDS_STATUS_REP_BLOCKC_MSB  15
      #define CMD_FM_RDS_STATUS_REP_BLOCKC_LSB  0
      #define CMD_FM_RDS_STATUS_REP_BLOCKC_INDEX 0x10
      #define CMD_FM_RDS_STATUS_REP_BLOCKC_value (((reply_buffer_u16[8])))
      #define CMD_FM_RDS_STATUS_REP_BLOCKD_TYPE u16
      #define CMD_FM_RDS_STATUS_REP_BLOCKD_SIZE 16
      #define CMD_FM_RDS_STATUS_REP_BLOCKD_MASK 0xFFFF
      #define CMD_FM_RDS_STATUS_REP_BLOCKD_MSB  15
      #define CMD_FM_RDS_STATUS_REP_BLOCKD_LSB  0
      #define CMD_FM_RDS_STATUS_REP_BLOCKD_INDEX 0x12
      #define CMD_FM_RDS_STATUS_REP_BLOCKD_value (((reply_buffer_u16[9])))

#define CMD_FM_RDS_BLOCKCOUNT    0x35
#define CMD_FM_RDS_BLOCKCOUNT_LENGTH 2
#define CMD_FM_RDS_BLOCKCOUNT_REP_LENGTH 10
//FM_RDS_BLOCKCOUNT ARGS
      #define CMD_FM_RDS_BLOCKCOUNT_ARG_CLEAR_TYPE bitfield
      #define CMD_FM_RDS_BLOCKCOUNT_ARG_CLEAR_SIZE 1
      #define CMD_FM_RDS_BLOCKCOUNT_ARG_CLEAR_MASK 0x01
      #define CMD_FM_RDS_BLOCKCOUNT_ARG_CLEAR_BIT  0x01
      #define CMD_FM_RDS_BLOCKCOUNT_ARG_CLEAR_MSB  0
      #define CMD_FM_RDS_BLOCKCOUNT_ARG_CLEAR_LSB  0
      #define CMD_FM_RDS_BLOCKCOUNT_ARG_CLEAR_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x1) | (((x)<<0)&0x1)))
//FM_RDS_BLOCKCOUNT REPLY
      #define CMD_FM_RDS_BLOCKCOUNT_REP_EXPECTED_TYPE u16
      #define CMD_FM_RDS_BLOCKCOUNT_REP_EXPECTED_SIZE 16
      #define CMD_FM_RDS_BLOCKCOUNT_REP_EXPECTED_MASK 0xFFFF
      #define CMD_FM_RDS_BLOCKCOUNT_REP_EXPECTED_MSB  15
      #define CMD_FM_RDS_BLOCKCOUNT_REP_EXPECTED_LSB  0
      #define CMD_FM_RDS_BLOCKCOUNT_REP_EXPECTED_INDEX 0x04
      #define CMD_FM_RDS_BLOCKCOUNT_REP_EXPECTED_value (((reply_buffer_u16[2])))
      #define CMD_FM_RDS_BLOCKCOUNT_REP_RECEIVED_TYPE u16
      #define CMD_FM_RDS_BLOCKCOUNT_REP_RECEIVED_SIZE 16
      #define CMD_FM_RDS_BLOCKCOUNT_REP_RECEIVED_MASK 0xFFFF
      #define CMD_FM_RDS_BLOCKCOUNT_REP_RECEIVED_MSB  15
      #define CMD_FM_RDS_BLOCKCOUNT_REP_RECEIVED_LSB  0
      #define CMD_FM_RDS_BLOCKCOUNT_REP_RECEIVED_INDEX 0x06
      #define CMD_FM_RDS_BLOCKCOUNT_REP_RECEIVED_value (((reply_buffer_u16[3])))
      #define CMD_FM_RDS_BLOCKCOUNT_REP_UNCORRECTABLE_TYPE u16
      #define CMD_FM_RDS_BLOCKCOUNT_REP_UNCORRECTABLE_SIZE 16
      #define CMD_FM_RDS_BLOCKCOUNT_REP_UNCORRECTABLE_MASK 0xFFFF
      #define CMD_FM_RDS_BLOCKCOUNT_REP_UNCORRECTABLE_MSB  15
      #define CMD_FM_RDS_BLOCKCOUNT_REP_UNCORRECTABLE_LSB  0
      #define CMD_FM_RDS_BLOCKCOUNT_REP_UNCORRECTABLE_INDEX 0x08
      #define CMD_FM_RDS_BLOCKCOUNT_REP_UNCORRECTABLE_value (((reply_buffer_u16[4])))

#define CMD_AM_TUNE_FREQ         0x40
#define CMD_AM_TUNE_FREQ_LENGTH 6
#define CMD_AM_TUNE_FREQ_REP_LENGTH 4
//AM_TUNE_FREQ ARGS
      #define CMD_AM_TUNE_FREQ_ARG_TUNE_MODE_TYPE bitfield
      #define CMD_AM_TUNE_FREQ_ARG_TUNE_MODE_SIZE 2
      #define CMD_AM_TUNE_FREQ_ARG_TUNE_MODE_MASK 0x0C
      #define CMD_AM_TUNE_FREQ_ARG_TUNE_MODE_MSB  3
      #define CMD_AM_TUNE_FREQ_ARG_TUNE_MODE_LSB  2
      #define CMD_AM_TUNE_FREQ_ARG_TUNE_MODE_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0xC) | (((x)<<2)&0xC)))
      #define CMD_AM_TUNE_FREQ_ARG_TUNE_MODE_ENUM_TUNE_ANALOG_ONLY 0
      #define CMD_AM_TUNE_FREQ_ARG_TUNE_MODE_ENUM_RESERVED 1
      #define CMD_AM_TUNE_FREQ_ARG_TUNE_MODE_ENUM_TUNE_HYBRID 2
      #define CMD_AM_TUNE_FREQ_ARG_TUNE_MODE_ENUM_TUNE_DIGITAL_ONLY 3
      #define CMD_AM_TUNE_FREQ_ARG_INJECTION_TYPE bitfield
      #define CMD_AM_TUNE_FREQ_ARG_INJECTION_SIZE 2
      #define CMD_AM_TUNE_FREQ_ARG_INJECTION_MASK 0x03
      #define CMD_AM_TUNE_FREQ_ARG_INJECTION_MSB  1
      #define CMD_AM_TUNE_FREQ_ARG_INJECTION_LSB  0
      #define CMD_AM_TUNE_FREQ_ARG_INJECTION_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x3) | (((x)<<0)&0x3)))
      #define CMD_AM_TUNE_FREQ_ARG_INJECTION_ENUM_FULL_AUTO 0
      #define CMD_AM_TUNE_FREQ_ARG_INJECTION_ENUM_LOW_SIDE 1
      #define CMD_AM_TUNE_FREQ_ARG_INJECTION_ENUM_HIGH_SIDE 2
      #define CMD_AM_TUNE_FREQ_ARG_FREQ_TYPE u16
      #define CMD_AM_TUNE_FREQ_ARG_FREQ_SIZE 16
      #define CMD_AM_TUNE_FREQ_ARG_FREQ_MASK 0xFFFF
      #define CMD_AM_TUNE_FREQ_ARG_FREQ_MSB  15
      #define CMD_AM_TUNE_FREQ_ARG_FREQ_LSB  0
      #define CMD_AM_TUNE_FREQ_ARG_FREQ_INDEX 0x02
      #define CMD_AM_TUNE_FREQ_ARG_FREQ_write_u16(x) (cmd_arg_u16[1] = (x))
      #define CMD_AM_TUNE_FREQ_ARG_ANTCAP_TYPE u16
      #define CMD_AM_TUNE_FREQ_ARG_ANTCAP_SIZE 16
      #define CMD_AM_TUNE_FREQ_ARG_ANTCAP_MASK 0xFFFF
      #define CMD_AM_TUNE_FREQ_ARG_ANTCAP_MSB  15
      #define CMD_AM_TUNE_FREQ_ARG_ANTCAP_LSB  0
      #define CMD_AM_TUNE_FREQ_ARG_ANTCAP_INDEX 0x04
      #define CMD_AM_TUNE_FREQ_ARG_ANTCAP_write_u16(x) (cmd_arg_u16[2] = (x))
      #define CMD_AM_TUNE_FREQ_ARG_ANTCAP_MIN 0
      #define CMD_AM_TUNE_FREQ_ARG_ANTCAP_MAX 4096
      #define CMD_AM_TUNE_FREQ_ARG_ANTCAP_ENUM_AUTO 0

#define CMD_AM_SEEK_START        0x41
#define CMD_AM_SEEK_START_LENGTH 6
#define CMD_AM_SEEK_START_REP_LENGTH 4
//AM_SEEK_START ARGS
      #define CMD_AM_SEEK_START_ARG_FORCE_WB_TYPE bitfield
      #define CMD_AM_SEEK_START_ARG_FORCE_WB_SIZE 1
      #define CMD_AM_SEEK_START_ARG_FORCE_WB_MASK 0x10
      #define CMD_AM_SEEK_START_ARG_FORCE_WB_BIT  0x10
      #define CMD_AM_SEEK_START_ARG_FORCE_WB_MSB  4
      #define CMD_AM_SEEK_START_ARG_FORCE_WB_LSB  4
      #define CMD_AM_SEEK_START_ARG_FORCE_WB_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x10) | (((x)<<4)&0x10)))
      #define CMD_AM_SEEK_START_ARG_TUNE_MODE_TYPE bitfield
      #define CMD_AM_SEEK_START_ARG_TUNE_MODE_SIZE 2
      #define CMD_AM_SEEK_START_ARG_TUNE_MODE_MASK 0x0C
      #define CMD_AM_SEEK_START_ARG_TUNE_MODE_MSB  3
      #define CMD_AM_SEEK_START_ARG_TUNE_MODE_LSB  2
      #define CMD_AM_SEEK_START_ARG_TUNE_MODE_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0xC) | (((x)<<2)&0xC)))
      #define CMD_AM_SEEK_START_ARG_TUNE_MODE_ENUM_TUNE_ANALOG_ONLY 0
      #define CMD_AM_SEEK_START_ARG_TUNE_MODE_ENUM_RESERVED 1
      #define CMD_AM_SEEK_START_ARG_TUNE_MODE_ENUM_TUNE_HYBRID 2
      #define CMD_AM_SEEK_START_ARG_TUNE_MODE_ENUM_TUNE_DIGITAL_ONLY 3
      #define CMD_AM_SEEK_START_ARG_INJECTION_TYPE bitfield
      #define CMD_AM_SEEK_START_ARG_INJECTION_SIZE 2
      #define CMD_AM_SEEK_START_ARG_INJECTION_MASK 0x03
      #define CMD_AM_SEEK_START_ARG_INJECTION_MSB  1
      #define CMD_AM_SEEK_START_ARG_INJECTION_LSB  0
      #define CMD_AM_SEEK_START_ARG_INJECTION_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x3) | (((x)<<0)&0x3)))
      #define CMD_AM_SEEK_START_ARG_INJECTION_ENUM_FULL_AUTO 0
      #define CMD_AM_SEEK_START_ARG_INJECTION_ENUM_LOW_SIDE 1
      #define CMD_AM_SEEK_START_ARG_INJECTION_ENUM_HIGH_SIDE 2
      #define CMD_AM_SEEK_START_ARG_SEEKUP_TYPE bitfield
      #define CMD_AM_SEEK_START_ARG_SEEKUP_SIZE 1
      #define CMD_AM_SEEK_START_ARG_SEEKUP_MASK 0x02
      #define CMD_AM_SEEK_START_ARG_SEEKUP_BIT  0x02
      #define CMD_AM_SEEK_START_ARG_SEEKUP_MSB  1
      #define CMD_AM_SEEK_START_ARG_SEEKUP_LSB  1
      #define CMD_AM_SEEK_START_ARG_SEEKUP_write_field(x) (cmd_arg[2] = ((cmd_arg[2]&~0x2) | (((x)<<1)&0x2)))
      #define CMD_AM_SEEK_START_ARG_SEEKUP_ENUM_DOWN 0
      #define CMD_AM_SEEK_START_ARG_SEEKUP_ENUM_UP 1
      #define CMD_AM_SEEK_START_ARG_WRAP_TYPE bitfield
      #define CMD_AM_SEEK_START_ARG_WRAP_SIZE 1
      #define CMD_AM_SEEK_START_ARG_WRAP_MASK 0x01
      #define CMD_AM_SEEK_START_ARG_WRAP_BIT  0x01
      #define CMD_AM_SEEK_START_ARG_WRAP_MSB  0
      #define CMD_AM_SEEK_START_ARG_WRAP_LSB  0
      #define CMD_AM_SEEK_START_ARG_WRAP_write_field(x) (cmd_arg[2] = ((cmd_arg[2]&~0x1) | (((x)<<0)&0x1)))
      #define CMD_AM_SEEK_START_ARG_WRAP_ENUM_HALT 0
      #define CMD_AM_SEEK_START_ARG_WRAP_ENUM_WRAP 1
      #define CMD_AM_SEEK_START_ARG_ANTCAP_TYPE u16
      #define CMD_AM_SEEK_START_ARG_ANTCAP_SIZE 16
      #define CMD_AM_SEEK_START_ARG_ANTCAP_MASK 0xFFFF
      #define CMD_AM_SEEK_START_ARG_ANTCAP_MSB  15
      #define CMD_AM_SEEK_START_ARG_ANTCAP_LSB  0
      #define CMD_AM_SEEK_START_ARG_ANTCAP_INDEX 0x04
      #define CMD_AM_SEEK_START_ARG_ANTCAP_write_u16(x) (cmd_arg_u16[2] = (x))
      #define CMD_AM_SEEK_START_ARG_ANTCAP_MIN 0
      #define CMD_AM_SEEK_START_ARG_ANTCAP_MAX 4096
      #define CMD_AM_SEEK_START_ARG_ANTCAP_ENUM_AUTO 0

#define CMD_AM_RSQ_STATUS        0x42
#define CMD_AM_RSQ_STATUS_LENGTH 2
#define CMD_AM_RSQ_STATUS_REP_LENGTH 17
//AM_RSQ_STATUS ARGS
      #define CMD_AM_RSQ_STATUS_ARG_RSQACK_TYPE bitfield
      #define CMD_AM_RSQ_STATUS_ARG_RSQACK_SIZE 1
      #define CMD_AM_RSQ_STATUS_ARG_RSQACK_MASK 0x08
      #define CMD_AM_RSQ_STATUS_ARG_RSQACK_BIT  0x08
      #define CMD_AM_RSQ_STATUS_ARG_RSQACK_MSB  3
      #define CMD_AM_RSQ_STATUS_ARG_RSQACK_LSB  3
      #define CMD_AM_RSQ_STATUS_ARG_RSQACK_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x8) | (((x)<<3)&0x8)))
      #define CMD_AM_RSQ_STATUS_ARG_ATTUNE_TYPE bitfield
      #define CMD_AM_RSQ_STATUS_ARG_ATTUNE_SIZE 1
      #define CMD_AM_RSQ_STATUS_ARG_ATTUNE_MASK 0x04
      #define CMD_AM_RSQ_STATUS_ARG_ATTUNE_BIT  0x04
      #define CMD_AM_RSQ_STATUS_ARG_ATTUNE_MSB  2
      #define CMD_AM_RSQ_STATUS_ARG_ATTUNE_LSB  2
      #define CMD_AM_RSQ_STATUS_ARG_ATTUNE_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x4) | (((x)<<2)&0x4)))
      #define CMD_AM_RSQ_STATUS_ARG_ATTUNE_ENUM_CUR_STATUS 0
      #define CMD_AM_RSQ_STATUS_ARG_ATTUNE_ENUM_ATTUNE_STATUS 1
      #define CMD_AM_RSQ_STATUS_ARG_CANCEL_TYPE bitfield
      #define CMD_AM_RSQ_STATUS_ARG_CANCEL_SIZE 1
      #define CMD_AM_RSQ_STATUS_ARG_CANCEL_MASK 0x02
      #define CMD_AM_RSQ_STATUS_ARG_CANCEL_BIT  0x02
      #define CMD_AM_RSQ_STATUS_ARG_CANCEL_MSB  1
      #define CMD_AM_RSQ_STATUS_ARG_CANCEL_LSB  1
      #define CMD_AM_RSQ_STATUS_ARG_CANCEL_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x2) | (((x)<<1)&0x2)))
      #define CMD_AM_RSQ_STATUS_ARG_STCACK_TYPE bitfield
      #define CMD_AM_RSQ_STATUS_ARG_STCACK_SIZE 1
      #define CMD_AM_RSQ_STATUS_ARG_STCACK_MASK 0x01
      #define CMD_AM_RSQ_STATUS_ARG_STCACK_BIT  0x01
      #define CMD_AM_RSQ_STATUS_ARG_STCACK_MSB  0
      #define CMD_AM_RSQ_STATUS_ARG_STCACK_LSB  0
      #define CMD_AM_RSQ_STATUS_ARG_STCACK_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x1) | (((x)<<0)&0x1)))
//AM_RSQ_STATUS REPLY
      #define CMD_AM_RSQ_STATUS_REP_SNRHINT_TYPE bitfield
      #define CMD_AM_RSQ_STATUS_REP_SNRHINT_SIZE 1
      #define CMD_AM_RSQ_STATUS_REP_SNRHINT_MASK 0x08
      #define CMD_AM_RSQ_STATUS_REP_SNRHINT_BIT  0x08
      #define CMD_AM_RSQ_STATUS_REP_SNRHINT_MSB  3
      #define CMD_AM_RSQ_STATUS_REP_SNRHINT_LSB  3
      #define CMD_AM_RSQ_STATUS_REP_SNRHINT_is_true (reply_buffer[4]&0x8)
      #define CMD_AM_RSQ_STATUS_REP_SNRHINT_value (((reply_buffer[4]&0x8))>>3)
      #define CMD_AM_RSQ_STATUS_REP_SNRLINT_TYPE bitfield
      #define CMD_AM_RSQ_STATUS_REP_SNRLINT_SIZE 1
      #define CMD_AM_RSQ_STATUS_REP_SNRLINT_MASK 0x04
      #define CMD_AM_RSQ_STATUS_REP_SNRLINT_BIT  0x04
      #define CMD_AM_RSQ_STATUS_REP_SNRLINT_MSB  2
      #define CMD_AM_RSQ_STATUS_REP_SNRLINT_LSB  2
      #define CMD_AM_RSQ_STATUS_REP_SNRLINT_is_true (reply_buffer[4]&0x4)
      #define CMD_AM_RSQ_STATUS_REP_SNRLINT_value (((reply_buffer[4]&0x4))>>2)
      #define CMD_AM_RSQ_STATUS_REP_RSSIHINT_TYPE bitfield
      #define CMD_AM_RSQ_STATUS_REP_RSSIHINT_SIZE 1
      #define CMD_AM_RSQ_STATUS_REP_RSSIHINT_MASK 0x02
      #define CMD_AM_RSQ_STATUS_REP_RSSIHINT_BIT  0x02
      #define CMD_AM_RSQ_STATUS_REP_RSSIHINT_MSB  1
      #define CMD_AM_RSQ_STATUS_REP_RSSIHINT_LSB  1
      #define CMD_AM_RSQ_STATUS_REP_RSSIHINT_is_true (reply_buffer[4]&0x2)
      #define CMD_AM_RSQ_STATUS_REP_RSSIHINT_value (((reply_buffer[4]&0x2))>>1)
      #define CMD_AM_RSQ_STATUS_REP_RSSILINT_TYPE bitfield
      #define CMD_AM_RSQ_STATUS_REP_RSSILINT_SIZE 1
      #define CMD_AM_RSQ_STATUS_REP_RSSILINT_MASK 0x01
      #define CMD_AM_RSQ_STATUS_REP_RSSILINT_BIT  0x01
      #define CMD_AM_RSQ_STATUS_REP_RSSILINT_MSB  0
      #define CMD_AM_RSQ_STATUS_REP_RSSILINT_LSB  0
      #define CMD_AM_RSQ_STATUS_REP_RSSILINT_is_true (reply_buffer[4]&0x1)
      #define CMD_AM_RSQ_STATUS_REP_RSSILINT_value (((reply_buffer[4]&0x1)))
      #define CMD_AM_RSQ_STATUS_REP_BLTF_TYPE bitfield
      #define CMD_AM_RSQ_STATUS_REP_BLTF_SIZE 1
      #define CMD_AM_RSQ_STATUS_REP_BLTF_MASK 0x80
      #define CMD_AM_RSQ_STATUS_REP_BLTF_BIT  0x80
      #define CMD_AM_RSQ_STATUS_REP_BLTF_MSB  7
      #define CMD_AM_RSQ_STATUS_REP_BLTF_LSB  7
      #define CMD_AM_RSQ_STATUS_REP_BLTF_is_true (reply_buffer[5]&0x80)
      #define CMD_AM_RSQ_STATUS_REP_BLTF_value (((reply_buffer[5]&0x80))>>7)
      #define CMD_AM_RSQ_STATUS_REP_HDDETECTED_TYPE bitfield
      #define CMD_AM_RSQ_STATUS_REP_HDDETECTED_SIZE 1
      #define CMD_AM_RSQ_STATUS_REP_HDDETECTED_MASK 0x20
      #define CMD_AM_RSQ_STATUS_REP_HDDETECTED_BIT  0x20
      #define CMD_AM_RSQ_STATUS_REP_HDDETECTED_MSB  5
      #define CMD_AM_RSQ_STATUS_REP_HDDETECTED_LSB  5
      #define CMD_AM_RSQ_STATUS_REP_HDDETECTED_is_true (reply_buffer[5]&0x20)
      #define CMD_AM_RSQ_STATUS_REP_HDDETECTED_value (((reply_buffer[5]&0x20))>>5)
      #define CMD_AM_RSQ_STATUS_REP_FLT_HDDETECTED_TYPE bitfield
      #define CMD_AM_RSQ_STATUS_REP_FLT_HDDETECTED_SIZE 1
      #define CMD_AM_RSQ_STATUS_REP_FLT_HDDETECTED_MASK 0x10
      #define CMD_AM_RSQ_STATUS_REP_FLT_HDDETECTED_BIT  0x10
      #define CMD_AM_RSQ_STATUS_REP_FLT_HDDETECTED_MSB  4
      #define CMD_AM_RSQ_STATUS_REP_FLT_HDDETECTED_LSB  4
      #define CMD_AM_RSQ_STATUS_REP_FLT_HDDETECTED_is_true (reply_buffer[5]&0x10)
      #define CMD_AM_RSQ_STATUS_REP_FLT_HDDETECTED_value (((reply_buffer[5]&0x10))>>4)
      #define CMD_AM_RSQ_STATUS_REP_AFCRL_TYPE bitfield
      #define CMD_AM_RSQ_STATUS_REP_AFCRL_SIZE 1
      #define CMD_AM_RSQ_STATUS_REP_AFCRL_MASK 0x02
      #define CMD_AM_RSQ_STATUS_REP_AFCRL_BIT  0x02
      #define CMD_AM_RSQ_STATUS_REP_AFCRL_MSB  1
      #define CMD_AM_RSQ_STATUS_REP_AFCRL_LSB  1
      #define CMD_AM_RSQ_STATUS_REP_AFCRL_is_true (reply_buffer[5]&0x2)
      #define CMD_AM_RSQ_STATUS_REP_AFCRL_value (((reply_buffer[5]&0x2))>>1)
      #define CMD_AM_RSQ_STATUS_REP_VALID_TYPE bitfield
      #define CMD_AM_RSQ_STATUS_REP_VALID_SIZE 1
      #define CMD_AM_RSQ_STATUS_REP_VALID_MASK 0x01
      #define CMD_AM_RSQ_STATUS_REP_VALID_BIT  0x01
      #define CMD_AM_RSQ_STATUS_REP_VALID_MSB  0
      #define CMD_AM_RSQ_STATUS_REP_VALID_LSB  0
      #define CMD_AM_RSQ_STATUS_REP_VALID_is_true (reply_buffer[5]&0x1)
      #define CMD_AM_RSQ_STATUS_REP_VALID_value (((reply_buffer[5]&0x1)))
      #define CMD_AM_RSQ_STATUS_REP_READFREQ_TYPE u16
      #define CMD_AM_RSQ_STATUS_REP_READFREQ_SIZE 16
      #define CMD_AM_RSQ_STATUS_REP_READFREQ_MASK 0xFFFF
      #define CMD_AM_RSQ_STATUS_REP_READFREQ_MSB  15
      #define CMD_AM_RSQ_STATUS_REP_READFREQ_LSB  0
      #define CMD_AM_RSQ_STATUS_REP_READFREQ_INDEX 0x06
      #define CMD_AM_RSQ_STATUS_REP_READFREQ_value (((reply_buffer_u16[3])))
      #define CMD_AM_RSQ_STATUS_REP_FREQOFF_TYPE i8
      #define CMD_AM_RSQ_STATUS_REP_FREQOFF_SIZE 8
      #define CMD_AM_RSQ_STATUS_REP_FREQOFF_MASK 0xFF
      #define CMD_AM_RSQ_STATUS_REP_FREQOFF_MSB  7
      #define CMD_AM_RSQ_STATUS_REP_FREQOFF_LSB  0
      #define CMD_AM_RSQ_STATUS_REP_FREQOFF_INDEX 0x08
      #define CMD_AM_RSQ_STATUS_REP_FREQOFF_value (((uint8_t)(reply_buffer[8])))
      #define CMD_AM_RSQ_STATUS_REP_FREQOFF_MIN -128
      #define CMD_AM_RSQ_STATUS_REP_FREQOFF_MAX 127
      #define CMD_AM_RSQ_STATUS_REP_RSSI_TYPE i8
      #define CMD_AM_RSQ_STATUS_REP_RSSI_SIZE 8
      #define CMD_AM_RSQ_STATUS_REP_RSSI_MASK 0xFF
      #define CMD_AM_RSQ_STATUS_REP_RSSI_MSB  7
      #define CMD_AM_RSQ_STATUS_REP_RSSI_LSB  0
      #define CMD_AM_RSQ_STATUS_REP_RSSI_INDEX 0x09
      #define CMD_AM_RSQ_STATUS_REP_RSSI_value (((uint8_t)(reply_buffer[9])))
      #define CMD_AM_RSQ_STATUS_REP_RSSI_MIN -128
      #define CMD_AM_RSQ_STATUS_REP_RSSI_MAX 127
      #define CMD_AM_RSQ_STATUS_REP_SNR_TYPE i8
      #define CMD_AM_RSQ_STATUS_REP_SNR_SIZE 8
      #define CMD_AM_RSQ_STATUS_REP_SNR_MASK 0xFF
      #define CMD_AM_RSQ_STATUS_REP_SNR_MSB  7
      #define CMD_AM_RSQ_STATUS_REP_SNR_LSB  0
      #define CMD_AM_RSQ_STATUS_REP_SNR_INDEX 0x0A
      #define CMD_AM_RSQ_STATUS_REP_SNR_value (((uint8_t)(reply_buffer[10])))
      #define CMD_AM_RSQ_STATUS_REP_SNR_MIN -128
      #define CMD_AM_RSQ_STATUS_REP_SNR_MAX 127
      #define CMD_AM_RSQ_STATUS_REP_MOD_TYPE u8
      #define CMD_AM_RSQ_STATUS_REP_MOD_SIZE 8
      #define CMD_AM_RSQ_STATUS_REP_MOD_MASK 0xFF
      #define CMD_AM_RSQ_STATUS_REP_MOD_MSB  7
      #define CMD_AM_RSQ_STATUS_REP_MOD_LSB  0
      #define CMD_AM_RSQ_STATUS_REP_MOD_INDEX 0x0B
      #define CMD_AM_RSQ_STATUS_REP_MOD_value (((reply_buffer[11])))
      #define CMD_AM_RSQ_STATUS_REP_MOD_MIN 0
      #define CMD_AM_RSQ_STATUS_REP_MOD_MAX 100
      #define CMD_AM_RSQ_STATUS_REP_READANTCAP_TYPE u16
      #define CMD_AM_RSQ_STATUS_REP_READANTCAP_SIZE 16
      #define CMD_AM_RSQ_STATUS_REP_READANTCAP_MASK 0xFFFF
      #define CMD_AM_RSQ_STATUS_REP_READANTCAP_MSB  15
      #define CMD_AM_RSQ_STATUS_REP_READANTCAP_LSB  0
      #define CMD_AM_RSQ_STATUS_REP_READANTCAP_INDEX 0x0C
      #define CMD_AM_RSQ_STATUS_REP_READANTCAP_value (((reply_buffer_u16[6])))
      #define CMD_AM_RSQ_STATUS_REP_HDLEVEL_TYPE u8
      #define CMD_AM_RSQ_STATUS_REP_HDLEVEL_SIZE 8
      #define CMD_AM_RSQ_STATUS_REP_HDLEVEL_MASK 0xFF
      #define CMD_AM_RSQ_STATUS_REP_HDLEVEL_MSB  7
      #define CMD_AM_RSQ_STATUS_REP_HDLEVEL_LSB  0
      #define CMD_AM_RSQ_STATUS_REP_HDLEVEL_INDEX 0x0F
      #define CMD_AM_RSQ_STATUS_REP_HDLEVEL_value (((reply_buffer[15])))
      #define CMD_AM_RSQ_STATUS_REP_HDLEVEL_MIN 0
      #define CMD_AM_RSQ_STATUS_REP_HDLEVEL_MAX 100
      #define CMD_AM_RSQ_STATUS_REP_FILTERED_HDLEVEL_TYPE u8
      #define CMD_AM_RSQ_STATUS_REP_FILTERED_HDLEVEL_SIZE 8
      #define CMD_AM_RSQ_STATUS_REP_FILTERED_HDLEVEL_MASK 0xFF
      #define CMD_AM_RSQ_STATUS_REP_FILTERED_HDLEVEL_MSB  7
      #define CMD_AM_RSQ_STATUS_REP_FILTERED_HDLEVEL_LSB  0
      #define CMD_AM_RSQ_STATUS_REP_FILTERED_HDLEVEL_INDEX 0x10
      #define CMD_AM_RSQ_STATUS_REP_FILTERED_HDLEVEL_value (((reply_buffer[16])))
      #define CMD_AM_RSQ_STATUS_REP_FILTERED_HDLEVEL_MIN 0
      #define CMD_AM_RSQ_STATUS_REP_FILTERED_HDLEVEL_MAX 100

#define CMD_AM_ACF_STATUS        0x43
#define CMD_AM_ACF_STATUS_LENGTH 2
#define CMD_AM_ACF_STATUS_REP_LENGTH 9
//AM_ACF_STATUS ARGS
      #define CMD_AM_ACF_STATUS_ARG_ACFACK_TYPE bitfield
      #define CMD_AM_ACF_STATUS_ARG_ACFACK_SIZE 1
      #define CMD_AM_ACF_STATUS_ARG_ACFACK_MASK 0x01
      #define CMD_AM_ACF_STATUS_ARG_ACFACK_BIT  0x01
      #define CMD_AM_ACF_STATUS_ARG_ACFACK_MSB  0
      #define CMD_AM_ACF_STATUS_ARG_ACFACK_LSB  0
      #define CMD_AM_ACF_STATUS_ARG_ACFACK_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x1) | (((x)<<0)&0x1)))
//AM_ACF_STATUS REPLY
      #define CMD_AM_ACF_STATUS_REP_HIGHCUT_INT_TYPE bitfield
      #define CMD_AM_ACF_STATUS_REP_HIGHCUT_INT_SIZE 1
      #define CMD_AM_ACF_STATUS_REP_HIGHCUT_INT_MASK 0x02
      #define CMD_AM_ACF_STATUS_REP_HIGHCUT_INT_BIT  0x02
      #define CMD_AM_ACF_STATUS_REP_HIGHCUT_INT_MSB  1
      #define CMD_AM_ACF_STATUS_REP_HIGHCUT_INT_LSB  1
      #define CMD_AM_ACF_STATUS_REP_HIGHCUT_INT_is_true (reply_buffer[4]&0x2)
      #define CMD_AM_ACF_STATUS_REP_HIGHCUT_INT_value (((reply_buffer[4]&0x2))>>1)
      #define CMD_AM_ACF_STATUS_REP_SMUTE_INT_TYPE bitfield
      #define CMD_AM_ACF_STATUS_REP_SMUTE_INT_SIZE 1
      #define CMD_AM_ACF_STATUS_REP_SMUTE_INT_MASK 0x01
      #define CMD_AM_ACF_STATUS_REP_SMUTE_INT_BIT  0x01
      #define CMD_AM_ACF_STATUS_REP_SMUTE_INT_MSB  0
      #define CMD_AM_ACF_STATUS_REP_SMUTE_INT_LSB  0
      #define CMD_AM_ACF_STATUS_REP_SMUTE_INT_is_true (reply_buffer[4]&0x1)
      #define CMD_AM_ACF_STATUS_REP_SMUTE_INT_value (((reply_buffer[4]&0x1)))
      #define CMD_AM_ACF_STATUS_REP_HIGHCUT_CONV_TYPE bitfield
      #define CMD_AM_ACF_STATUS_REP_HIGHCUT_CONV_SIZE 1
      #define CMD_AM_ACF_STATUS_REP_HIGHCUT_CONV_MASK 0x20
      #define CMD_AM_ACF_STATUS_REP_HIGHCUT_CONV_BIT  0x20
      #define CMD_AM_ACF_STATUS_REP_HIGHCUT_CONV_MSB  5
      #define CMD_AM_ACF_STATUS_REP_HIGHCUT_CONV_LSB  5
      #define CMD_AM_ACF_STATUS_REP_HIGHCUT_CONV_is_true (reply_buffer[5]&0x20)
      #define CMD_AM_ACF_STATUS_REP_HIGHCUT_CONV_value (((reply_buffer[5]&0x20))>>5)
      #define CMD_AM_ACF_STATUS_REP_SMUTE_CONV_TYPE bitfield
      #define CMD_AM_ACF_STATUS_REP_SMUTE_CONV_SIZE 1
      #define CMD_AM_ACF_STATUS_REP_SMUTE_CONV_MASK 0x10
      #define CMD_AM_ACF_STATUS_REP_SMUTE_CONV_BIT  0x10
      #define CMD_AM_ACF_STATUS_REP_SMUTE_CONV_MSB  4
      #define CMD_AM_ACF_STATUS_REP_SMUTE_CONV_LSB  4
      #define CMD_AM_ACF_STATUS_REP_SMUTE_CONV_is_true (reply_buffer[5]&0x10)
      #define CMD_AM_ACF_STATUS_REP_SMUTE_CONV_value (((reply_buffer[5]&0x10))>>4)
      #define CMD_AM_ACF_STATUS_REP_HIGHCUT_STATE_TYPE bitfield
      #define CMD_AM_ACF_STATUS_REP_HIGHCUT_STATE_SIZE 1
      #define CMD_AM_ACF_STATUS_REP_HIGHCUT_STATE_MASK 0x02
      #define CMD_AM_ACF_STATUS_REP_HIGHCUT_STATE_BIT  0x02
      #define CMD_AM_ACF_STATUS_REP_HIGHCUT_STATE_MSB  1
      #define CMD_AM_ACF_STATUS_REP_HIGHCUT_STATE_LSB  1
      #define CMD_AM_ACF_STATUS_REP_HIGHCUT_STATE_is_true (reply_buffer[5]&0x2)
      #define CMD_AM_ACF_STATUS_REP_HIGHCUT_STATE_value (((reply_buffer[5]&0x2))>>1)
      #define CMD_AM_ACF_STATUS_REP_SMUTE_STATE_TYPE bitfield
      #define CMD_AM_ACF_STATUS_REP_SMUTE_STATE_SIZE 1
      #define CMD_AM_ACF_STATUS_REP_SMUTE_STATE_MASK 0x01
      #define CMD_AM_ACF_STATUS_REP_SMUTE_STATE_BIT  0x01
      #define CMD_AM_ACF_STATUS_REP_SMUTE_STATE_MSB  0
      #define CMD_AM_ACF_STATUS_REP_SMUTE_STATE_LSB  0
      #define CMD_AM_ACF_STATUS_REP_SMUTE_STATE_is_true (reply_buffer[5]&0x1)
      #define CMD_AM_ACF_STATUS_REP_SMUTE_STATE_value (((reply_buffer[5]&0x1)))
      #define CMD_AM_ACF_STATUS_REP_ATTN_TYPE bitfield
      #define CMD_AM_ACF_STATUS_REP_ATTN_SIZE 5
      #define CMD_AM_ACF_STATUS_REP_ATTN_MASK 0x1F
      #define CMD_AM_ACF_STATUS_REP_ATTN_MSB  4
      #define CMD_AM_ACF_STATUS_REP_ATTN_LSB  0
      #define CMD_AM_ACF_STATUS_REP_ATTN_value (((reply_buffer[6]&0x1F)))
      #define CMD_AM_ACF_STATUS_REP_ATTN_MIN 0
      #define CMD_AM_ACF_STATUS_REP_ATTN_MAX 31
      #define CMD_AM_ACF_STATUS_REP_HIGHCUT_TYPE u8
      #define CMD_AM_ACF_STATUS_REP_HIGHCUT_SIZE 8
      #define CMD_AM_ACF_STATUS_REP_HIGHCUT_MASK 0xFF
      #define CMD_AM_ACF_STATUS_REP_HIGHCUT_MSB  7
      #define CMD_AM_ACF_STATUS_REP_HIGHCUT_LSB  0
      #define CMD_AM_ACF_STATUS_REP_HIGHCUT_INDEX 0x07
      #define CMD_AM_ACF_STATUS_REP_HIGHCUT_value (((reply_buffer[7])))
      #define CMD_AM_ACF_STATUS_REP_HIGHCUT_MIN 10
      #define CMD_AM_ACF_STATUS_REP_HIGHCUT_MAX 50
      #define CMD_AM_ACF_STATUS_REP_LOWCUT_TYPE u8
      #define CMD_AM_ACF_STATUS_REP_LOWCUT_SIZE 8
      #define CMD_AM_ACF_STATUS_REP_LOWCUT_MASK 0xFF
      #define CMD_AM_ACF_STATUS_REP_LOWCUT_MSB  7
      #define CMD_AM_ACF_STATUS_REP_LOWCUT_LSB  0
      #define CMD_AM_ACF_STATUS_REP_LOWCUT_INDEX 0x08
      #define CMD_AM_ACF_STATUS_REP_LOWCUT_value (((reply_buffer[8])))

#define CMD_GET_DIGITAL_SERVICE_LIST 0x80
#define CMD_GET_DIGITAL_SERVICE_LIST_LENGTH 2
#define CMD_GET_DIGITAL_SERVICE_LIST_REP_LENGTH 8
//GET_DIGITAL_SERVICE_LIST ARGS
      #define CMD_GET_DIGITAL_SERVICE_LIST_ARG_SERTYPE_TYPE bitfield
      #define CMD_GET_DIGITAL_SERVICE_LIST_ARG_SERTYPE_SIZE 2
      #define CMD_GET_DIGITAL_SERVICE_LIST_ARG_SERTYPE_MASK 0x03
      #define CMD_GET_DIGITAL_SERVICE_LIST_ARG_SERTYPE_MSB  1
      #define CMD_GET_DIGITAL_SERVICE_LIST_ARG_SERTYPE_LSB  0
      #define CMD_GET_DIGITAL_SERVICE_LIST_ARG_SERTYPE_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x3) | (((x)<<0)&0x3)))
      #define CMD_GET_DIGITAL_SERVICE_LIST_ARG_SERTYPE_ENUM_AUDIO 0
      #define CMD_GET_DIGITAL_SERVICE_LIST_ARG_SERTYPE_ENUM_DATA 1
      #define CMD_GET_DIGITAL_SERVICE_LIST_ARG_SERTYPE_ENUM_AUDINFO 2
      #define CMD_GET_DIGITAL_SERVICE_LIST_ARG_SERTYPE_ENUM_DATAINFO 3
//GET_DIGITAL_SERVICE_LIST REPLY
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_SIZE_TYPE u16
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_SIZE_SIZE 16
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_SIZE_MASK 0xFFFF
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_SIZE_MSB  15
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_SIZE_LSB  0
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_SIZE_INDEX 0x04
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_SIZE_value (((reply_buffer_u16[2])))
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_DATA_0_TYPE u8
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_DATA_0_SIZE 8
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_DATA_0_MASK 0xFF
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_DATA_0_MSB  7
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_DATA_0_LSB  0
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_DATA_0_INDEX 0x06
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_DATA_0_value (((reply_buffer[6])))
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_DATA_N_TYPE u8
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_DATA_N_SIZE 8
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_DATA_N_MASK 0xFF
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_DATA_N_MSB  7
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_DATA_N_LSB  0
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_DATA_N_INDEX 0x07
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_DATA_N_value (((reply_buffer[7])))

#define CMD_GET_DIGITAL_SERVICE_LIST 0x80
#define CMD_GET_DIGITAL_SERVICE_LIST_LENGTH 2
#define CMD_GET_DIGITAL_SERVICE_LIST_REP_LENGTH 8
//GET_DIGITAL_SERVICE_LIST ARGS
      #define CMD_GET_DIGITAL_SERVICE_LIST_ARG_SERTYPE_TYPE bitfield
      #define CMD_GET_DIGITAL_SERVICE_LIST_ARG_SERTYPE_SIZE 2
      #define CMD_GET_DIGITAL_SERVICE_LIST_ARG_SERTYPE_MASK 0x03
      #define CMD_GET_DIGITAL_SERVICE_LIST_ARG_SERTYPE_MSB  1
      #define CMD_GET_DIGITAL_SERVICE_LIST_ARG_SERTYPE_LSB  0
      #define CMD_GET_DIGITAL_SERVICE_LIST_ARG_SERTYPE_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x3) | (((x)<<0)&0x3)))
      #define CMD_GET_DIGITAL_SERVICE_LIST_ARG_SERTYPE_ENUM_AUDIO 0
      #define CMD_GET_DIGITAL_SERVICE_LIST_ARG_SERTYPE_ENUM_DATA 1
      #define CMD_GET_DIGITAL_SERVICE_LIST_ARG_SERTYPE_ENUM_AUDINFO 2
      #define CMD_GET_DIGITAL_SERVICE_LIST_ARG_SERTYPE_ENUM_DATAINFO 3
//GET_DIGITAL_SERVICE_LIST REPLY
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_SIZE_TYPE u16
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_SIZE_SIZE 16
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_SIZE_MASK 0xFFFF
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_SIZE_MSB  15
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_SIZE_LSB  0
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_SIZE_INDEX 0x04
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_SIZE_value (((reply_buffer_u16[2])))
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_DATA_0_TYPE u8
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_DATA_0_SIZE 8
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_DATA_0_MASK 0xFF
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_DATA_0_MSB  7
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_DATA_0_LSB  0
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_DATA_0_INDEX 0x06
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_DATA_0_value (((reply_buffer[6])))
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_DATA_N_TYPE u8
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_DATA_N_SIZE 8
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_DATA_N_MASK 0xFF
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_DATA_N_MSB  7
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_DATA_N_LSB  0
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_DATA_N_INDEX 0x07
      #define CMD_GET_DIGITAL_SERVICE_LIST_REP_DATA_N_value (((reply_buffer[7])))

#define CMD_START_DIGITAL_SERVICE 0x81
#define CMD_START_DIGITAL_SERVICE_LENGTH 12
#define CMD_START_DIGITAL_SERVICE_REP_LENGTH 4
//START_DIGITAL_SERVICE ARGS
      #define CMD_START_DIGITAL_SERVICE_ARG_SERTYPE_TYPE bitfield
      #define CMD_START_DIGITAL_SERVICE_ARG_SERTYPE_SIZE 1
      #define CMD_START_DIGITAL_SERVICE_ARG_SERTYPE_MASK 0x01
      #define CMD_START_DIGITAL_SERVICE_ARG_SERTYPE_BIT  0x01
      #define CMD_START_DIGITAL_SERVICE_ARG_SERTYPE_MSB  0
      #define CMD_START_DIGITAL_SERVICE_ARG_SERTYPE_LSB  0
      #define CMD_START_DIGITAL_SERVICE_ARG_SERTYPE_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x1) | (((x)<<0)&0x1)))
      #define CMD_START_DIGITAL_SERVICE_ARG_SERTYPE_ENUM_AUDIO 0
      #define CMD_START_DIGITAL_SERVICE_ARG_SERTYPE_ENUM_DATA 1
      #define CMD_START_DIGITAL_SERVICE_ARG_SERVICE_ID_TYPE u32
      #define CMD_START_DIGITAL_SERVICE_ARG_SERVICE_ID_SIZE 32
      #define CMD_START_DIGITAL_SERVICE_ARG_SERVICE_ID_MASK 0xFFFFFFFF
      #define CMD_START_DIGITAL_SERVICE_ARG_SERVICE_ID_MSB  31
      #define CMD_START_DIGITAL_SERVICE_ARG_SERVICE_ID_LSB  0
      #define CMD_START_DIGITAL_SERVICE_ARG_SERVICE_ID_INDEX 0x04
      #define CMD_START_DIGITAL_SERVICE_ARG_SERVICE_ID_write_u32(x) (cmd_arg_u32[1] = (x))
      #define CMD_START_DIGITAL_SERVICE_ARG_COMP_ID_TYPE u32
      #define CMD_START_DIGITAL_SERVICE_ARG_COMP_ID_SIZE 32
      #define CMD_START_DIGITAL_SERVICE_ARG_COMP_ID_MASK 0xFFFFFFFF
      #define CMD_START_DIGITAL_SERVICE_ARG_COMP_ID_MSB  31
      #define CMD_START_DIGITAL_SERVICE_ARG_COMP_ID_LSB  0
      #define CMD_START_DIGITAL_SERVICE_ARG_COMP_ID_INDEX 0x08
      #define CMD_START_DIGITAL_SERVICE_ARG_COMP_ID_write_u32(x) (cmd_arg_u32[2] = (x))

#define CMD_START_DIGITAL_SERVICE 0x81
#define CMD_START_DIGITAL_SERVICE_LENGTH 12
#define CMD_START_DIGITAL_SERVICE_REP_LENGTH 4
//START_DIGITAL_SERVICE ARGS
      #define CMD_START_DIGITAL_SERVICE_ARG_SERTYPE_TYPE bitfield
      #define CMD_START_DIGITAL_SERVICE_ARG_SERTYPE_SIZE 1
      #define CMD_START_DIGITAL_SERVICE_ARG_SERTYPE_MASK 0x01
      #define CMD_START_DIGITAL_SERVICE_ARG_SERTYPE_BIT  0x01
      #define CMD_START_DIGITAL_SERVICE_ARG_SERTYPE_MSB  0
      #define CMD_START_DIGITAL_SERVICE_ARG_SERTYPE_LSB  0
      #define CMD_START_DIGITAL_SERVICE_ARG_SERTYPE_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x1) | (((x)<<0)&0x1)))
      #define CMD_START_DIGITAL_SERVICE_ARG_SERTYPE_ENUM_AUDIO 0
      #define CMD_START_DIGITAL_SERVICE_ARG_SERTYPE_ENUM_DATA 1
      #define CMD_START_DIGITAL_SERVICE_ARG_SERVICE_ID_TYPE u32
      #define CMD_START_DIGITAL_SERVICE_ARG_SERVICE_ID_SIZE 32
      #define CMD_START_DIGITAL_SERVICE_ARG_SERVICE_ID_MASK 0xFFFFFFFF
      #define CMD_START_DIGITAL_SERVICE_ARG_SERVICE_ID_MSB  31
      #define CMD_START_DIGITAL_SERVICE_ARG_SERVICE_ID_LSB  0
      #define CMD_START_DIGITAL_SERVICE_ARG_SERVICE_ID_INDEX 0x04
      #define CMD_START_DIGITAL_SERVICE_ARG_SERVICE_ID_write_u32(x) (cmd_arg_u32[1] = (x))
      #define CMD_START_DIGITAL_SERVICE_ARG_COMP_ID_TYPE u32
      #define CMD_START_DIGITAL_SERVICE_ARG_COMP_ID_SIZE 32
      #define CMD_START_DIGITAL_SERVICE_ARG_COMP_ID_MASK 0xFFFFFFFF
      #define CMD_START_DIGITAL_SERVICE_ARG_COMP_ID_MSB  31
      #define CMD_START_DIGITAL_SERVICE_ARG_COMP_ID_LSB  0
      #define CMD_START_DIGITAL_SERVICE_ARG_COMP_ID_INDEX 0x08
      #define CMD_START_DIGITAL_SERVICE_ARG_COMP_ID_write_u32(x) (cmd_arg_u32[2] = (x))

#define CMD_STOP_DIGITAL_SERVICE 0x82
#define CMD_STOP_DIGITAL_SERVICE_LENGTH 12
#define CMD_STOP_DIGITAL_SERVICE_REP_LENGTH 4
//STOP_DIGITAL_SERVICE ARGS
      #define CMD_STOP_DIGITAL_SERVICE_ARG_SERTYPE_TYPE bitfield
      #define CMD_STOP_DIGITAL_SERVICE_ARG_SERTYPE_SIZE 1
      #define CMD_STOP_DIGITAL_SERVICE_ARG_SERTYPE_MASK 0x01
      #define CMD_STOP_DIGITAL_SERVICE_ARG_SERTYPE_BIT  0x01
      #define CMD_STOP_DIGITAL_SERVICE_ARG_SERTYPE_MSB  0
      #define CMD_STOP_DIGITAL_SERVICE_ARG_SERTYPE_LSB  0
      #define CMD_STOP_DIGITAL_SERVICE_ARG_SERTYPE_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x1) | (((x)<<0)&0x1)))
      #define CMD_STOP_DIGITAL_SERVICE_ARG_SERTYPE_ENUM_AUDIO 0
      #define CMD_STOP_DIGITAL_SERVICE_ARG_SERTYPE_ENUM_DATA 1
      #define CMD_STOP_DIGITAL_SERVICE_ARG_SERVICE_ID_TYPE u32
      #define CMD_STOP_DIGITAL_SERVICE_ARG_SERVICE_ID_SIZE 32
      #define CMD_STOP_DIGITAL_SERVICE_ARG_SERVICE_ID_MASK 0xFFFFFFFF
      #define CMD_STOP_DIGITAL_SERVICE_ARG_SERVICE_ID_MSB  31
      #define CMD_STOP_DIGITAL_SERVICE_ARG_SERVICE_ID_LSB  0
      #define CMD_STOP_DIGITAL_SERVICE_ARG_SERVICE_ID_INDEX 0x04
      #define CMD_STOP_DIGITAL_SERVICE_ARG_SERVICE_ID_write_u32(x) (cmd_arg_u32[1] = (x))
      #define CMD_STOP_DIGITAL_SERVICE_ARG_COMP_ID_TYPE u32
      #define CMD_STOP_DIGITAL_SERVICE_ARG_COMP_ID_SIZE 32
      #define CMD_STOP_DIGITAL_SERVICE_ARG_COMP_ID_MASK 0xFFFFFFFF
      #define CMD_STOP_DIGITAL_SERVICE_ARG_COMP_ID_MSB  31
      #define CMD_STOP_DIGITAL_SERVICE_ARG_COMP_ID_LSB  0
      #define CMD_STOP_DIGITAL_SERVICE_ARG_COMP_ID_INDEX 0x08
      #define CMD_STOP_DIGITAL_SERVICE_ARG_COMP_ID_write_u32(x) (cmd_arg_u32[2] = (x))

#define CMD_GET_DIGITAL_SERVICE_DATA 0x84
#define CMD_GET_DIGITAL_SERVICE_DATA_LENGTH 2
#define CMD_GET_DIGITAL_SERVICE_DATA_REP_LENGTH 26
//GET_DIGITAL_SERVICE_DATA ARGS
      #define CMD_GET_DIGITAL_SERVICE_DATA_ARG_STATUS_ONLY_TYPE bitfield
      #define CMD_GET_DIGITAL_SERVICE_DATA_ARG_STATUS_ONLY_SIZE 1
      #define CMD_GET_DIGITAL_SERVICE_DATA_ARG_STATUS_ONLY_MASK 0x10
      #define CMD_GET_DIGITAL_SERVICE_DATA_ARG_STATUS_ONLY_BIT  0x10
      #define CMD_GET_DIGITAL_SERVICE_DATA_ARG_STATUS_ONLY_MSB  4
      #define CMD_GET_DIGITAL_SERVICE_DATA_ARG_STATUS_ONLY_LSB  4
      #define CMD_GET_DIGITAL_SERVICE_DATA_ARG_STATUS_ONLY_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x10) | (((x)<<4)&0x10)))
      #define CMD_GET_DIGITAL_SERVICE_DATA_ARG_ACK_TYPE bitfield
      #define CMD_GET_DIGITAL_SERVICE_DATA_ARG_ACK_SIZE 1
      #define CMD_GET_DIGITAL_SERVICE_DATA_ARG_ACK_MASK 0x01
      #define CMD_GET_DIGITAL_SERVICE_DATA_ARG_ACK_BIT  0x01
      #define CMD_GET_DIGITAL_SERVICE_DATA_ARG_ACK_MSB  0
      #define CMD_GET_DIGITAL_SERVICE_DATA_ARG_ACK_LSB  0
      #define CMD_GET_DIGITAL_SERVICE_DATA_ARG_ACK_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x1) | (((x)<<0)&0x1)))
      #define CMD_GET_DIGITAL_SERVICE_DATA_ARG_ACK_ENUM_DONT_ACK 0
      #define CMD_GET_DIGITAL_SERVICE_DATA_ARG_ACK_ENUM_ACK 1
//GET_DIGITAL_SERVICE_DATA REPLY
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_DSRVOVFLINT_TYPE bitfield
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_DSRVOVFLINT_SIZE 1
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_DSRVOVFLINT_MASK 0x02
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_DSRVOVFLINT_BIT  0x02
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_DSRVOVFLINT_MSB  1
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_DSRVOVFLINT_LSB  1
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_DSRVOVFLINT_is_true (reply_buffer[4]&0x2)
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_DSRVOVFLINT_value (((reply_buffer[4]&0x2))>>1)
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_DSRVPCKTINT_TYPE bitfield
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_DSRVPCKTINT_SIZE 1
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_DSRVPCKTINT_MASK 0x01
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_DSRVPCKTINT_BIT  0x01
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_DSRVPCKTINT_MSB  0
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_DSRVPCKTINT_LSB  0
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_DSRVPCKTINT_is_true (reply_buffer[4]&0x1)
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_DSRVPCKTINT_value (((reply_buffer[4]&0x1)))
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_BUFF_COUNT_TYPE u8
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_BUFF_COUNT_SIZE 8
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_BUFF_COUNT_MASK 0xFF
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_BUFF_COUNT_MSB  7
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_BUFF_COUNT_LSB  0
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_BUFF_COUNT_INDEX 0x05
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_BUFF_COUNT_value (((reply_buffer[5])))
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_SRV_STATE_TYPE u8
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_SRV_STATE_SIZE 8
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_SRV_STATE_MASK 0xFF
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_SRV_STATE_MSB  7
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_SRV_STATE_LSB  0
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_SRV_STATE_INDEX 0x06
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_SRV_STATE_value (((reply_buffer[6])))
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_SRV_STATE_ENUM_PLAYING 0
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_SRV_STATE_ENUM_STOPPED 1
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_SRV_STATE_ENUM_OVERFLOW 2
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_SRV_STATE_ENUM_NEW_OBJECT 3
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_SRV_STATE_ENUM_PACKET_ERRORS 4
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_DATA_SRC_TYPE bitfield
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_DATA_SRC_SIZE 2
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_DATA_SRC_MASK 0xC0
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_DATA_SRC_MSB  7
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_DATA_SRC_LSB  6
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_DATA_SRC_value (((reply_buffer[7]&0xC0))>>6)
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_DATA_SRC_ENUM_DATA_SERVICE 0
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_DATA_SRC_ENUM_PAD_DATA 1
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_DATA_SRC_ENUM_PAD_DLS 2
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_DATA_SRC_ENUM_RFU 3
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_DSCTY_TYPE bitfield
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_DSCTY_SIZE 6
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_DSCTY_MASK 0x3F
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_DSCTY_MSB  5
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_DSCTY_LSB  0
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_DSCTY_value (((reply_buffer[7]&0x3F)))
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_SERVICE_ID_TYPE u32
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_SERVICE_ID_SIZE 32
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_SERVICE_ID_MASK 0xFFFFFFFF
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_SERVICE_ID_MSB  31
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_SERVICE_ID_LSB  0
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_SERVICE_ID_INDEX 0x08
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_SERVICE_ID_value (((reply_buffer_u32[2])))
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_COMP_ID_TYPE u32
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_COMP_ID_SIZE 32
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_COMP_ID_MASK 0xFFFFFFFF
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_COMP_ID_MSB  31
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_COMP_ID_LSB  0
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_COMP_ID_INDEX 0x0C
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_COMP_ID_value (((reply_buffer_u32[3])))
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_RFU_TYPE u16
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_RFU_SIZE 16
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_RFU_MASK 0xFFFF
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_RFU_MSB  15
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_RFU_LSB  0
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_RFU_INDEX 0x10
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_RFU_value (((reply_buffer_u16[8])))
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_UATYPE_TYPE u16
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_UATYPE_SIZE 16
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_UATYPE_MASK 0xFFFF
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_UATYPE_MSB  15
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_UATYPE_LSB  0
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_UATYPE_INDEX 0x10
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_UATYPE_value (((reply_buffer_u16[8])))
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_BYTE_COUNT_TYPE u16
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_BYTE_COUNT_SIZE 16
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_BYTE_COUNT_MASK 0xFFFF
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_BYTE_COUNT_MSB  15
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_BYTE_COUNT_LSB  0
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_BYTE_COUNT_INDEX 0x12
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_BYTE_COUNT_value (((reply_buffer_u16[9])))
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_SEG_NUM_TYPE u16
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_SEG_NUM_SIZE 16
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_SEG_NUM_MASK 0xFFFF
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_SEG_NUM_MSB  15
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_SEG_NUM_LSB  0
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_SEG_NUM_INDEX 0x14
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_SEG_NUM_value (((reply_buffer_u16[10])))
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_NUM_SEGS_TYPE u16
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_NUM_SEGS_SIZE 16
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_NUM_SEGS_MASK 0xFFFF
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_NUM_SEGS_MSB  15
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_NUM_SEGS_LSB  0
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_NUM_SEGS_INDEX 0x16
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_NUM_SEGS_value (((reply_buffer_u16[11])))
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_PAYLOAD0_TYPE u8
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_PAYLOAD0_SIZE 8
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_PAYLOAD0_MASK 0xFF
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_PAYLOAD0_MSB  7
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_PAYLOAD0_LSB  0
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_PAYLOAD0_INDEX 0x18
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_PAYLOAD0_value (((reply_buffer[24])))
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_PAYLOADN_TYPE u8
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_PAYLOADN_SIZE 8
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_PAYLOADN_MASK 0xFF
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_PAYLOADN_MSB  7
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_PAYLOADN_LSB  0
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_PAYLOADN_INDEX 0x19
      #define CMD_GET_DIGITAL_SERVICE_DATA_REP_PAYLOADN_value (((reply_buffer[25])))

#define CMD_HD_ACQUIRE           0x90
#define CMD_HD_ACQUIRE_LENGTH 5
#define CMD_HD_ACQUIRE_REP_LENGTH 4
//HD_ACQUIRE ARGS
      #define CMD_HD_ACQUIRE_ARG_DIR_TUNE_TYPE bitfield
      #define CMD_HD_ACQUIRE_ARG_DIR_TUNE_SIZE 1
      #define CMD_HD_ACQUIRE_ARG_DIR_TUNE_MASK 0x20
      #define CMD_HD_ACQUIRE_ARG_DIR_TUNE_BIT  0x20
      #define CMD_HD_ACQUIRE_ARG_DIR_TUNE_MSB  5
      #define CMD_HD_ACQUIRE_ARG_DIR_TUNE_LSB  5
      #define CMD_HD_ACQUIRE_ARG_DIR_TUNE_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x20) | (((x)<<5)&0x20)))
      #define CMD_HD_ACQUIRE_ARG_DIG_TUNE_TYPE bitfield
      #define CMD_HD_ACQUIRE_ARG_DIG_TUNE_SIZE 1
      #define CMD_HD_ACQUIRE_ARG_DIG_TUNE_MASK 0x04
      #define CMD_HD_ACQUIRE_ARG_DIG_TUNE_BIT  0x04
      #define CMD_HD_ACQUIRE_ARG_DIG_TUNE_MSB  2
      #define CMD_HD_ACQUIRE_ARG_DIG_TUNE_LSB  2
      #define CMD_HD_ACQUIRE_ARG_DIG_TUNE_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x4) | (((x)<<2)&0x4)))
      #define CMD_HD_ACQUIRE_ARG_FREQ_TYPE u16
      #define CMD_HD_ACQUIRE_ARG_FREQ_SIZE 16
      #define CMD_HD_ACQUIRE_ARG_FREQ_MASK 0xFFFF
      #define CMD_HD_ACQUIRE_ARG_FREQ_MSB  15
      #define CMD_HD_ACQUIRE_ARG_FREQ_LSB  0
      #define CMD_HD_ACQUIRE_ARG_FREQ_INDEX 0x02
      #define CMD_HD_ACQUIRE_ARG_FREQ_write_u16(x) (cmd_arg_u16[1] = (x))
      #define CMD_HD_ACQUIRE_ARG_PROG_ID_TYPE u8
      #define CMD_HD_ACQUIRE_ARG_PROG_ID_SIZE 8
      #define CMD_HD_ACQUIRE_ARG_PROG_ID_MASK 0xFF
      #define CMD_HD_ACQUIRE_ARG_PROG_ID_MSB  7
      #define CMD_HD_ACQUIRE_ARG_PROG_ID_LSB  0
      #define CMD_HD_ACQUIRE_ARG_PROG_ID_INDEX 0x04
      #define CMD_HD_ACQUIRE_ARG_PROG_ID_write_u8(x) (cmd_arg[4] = (x))
      #define CMD_HD_ACQUIRE_ARG_PROG_ID_MIN 0
      #define CMD_HD_ACQUIRE_ARG_PROG_ID_MAX 7

#define CMD_HD_LEVEL_STATUS      0x91
#define CMD_HD_LEVEL_STATUS_LENGTH 2
#define CMD_HD_LEVEL_STATUS_REP_LENGTH 7
//HD_LEVEL_STATUS ARGS
      #define CMD_HD_LEVEL_STATUS_ARG_ACK_TYPE bitfield
      #define CMD_HD_LEVEL_STATUS_ARG_ACK_SIZE 1
      #define CMD_HD_LEVEL_STATUS_ARG_ACK_MASK 0x01
      #define CMD_HD_LEVEL_STATUS_ARG_ACK_BIT  0x01
      #define CMD_HD_LEVEL_STATUS_ARG_ACK_MSB  0
      #define CMD_HD_LEVEL_STATUS_ARG_ACK_LSB  0
      #define CMD_HD_LEVEL_STATUS_ARG_ACK_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x1) | (((x)<<0)&0x1)))
//HD_LEVEL_STATUS REPLY
      #define CMD_HD_LEVEL_STATUS_REP_HDDETECTED_TYPE bitfield
      #define CMD_HD_LEVEL_STATUS_REP_HDDETECTED_SIZE 1
      #define CMD_HD_LEVEL_STATUS_REP_HDDETECTED_MASK 0x80
      #define CMD_HD_LEVEL_STATUS_REP_HDDETECTED_BIT  0x80
      #define CMD_HD_LEVEL_STATUS_REP_HDDETECTED_MSB  7
      #define CMD_HD_LEVEL_STATUS_REP_HDDETECTED_LSB  7
      #define CMD_HD_LEVEL_STATUS_REP_HDDETECTED_is_true (reply_buffer[4]&0x80)
      #define CMD_HD_LEVEL_STATUS_REP_HDDETECTED_value (((reply_buffer[4]&0x80))>>7)
      #define CMD_HD_LEVEL_STATUS_REP_FLT_HDDETECTED_TYPE bitfield
      #define CMD_HD_LEVEL_STATUS_REP_FLT_HDDETECTED_SIZE 1
      #define CMD_HD_LEVEL_STATUS_REP_FLT_HDDETECTED_MASK 0x40
      #define CMD_HD_LEVEL_STATUS_REP_FLT_HDDETECTED_BIT  0x40
      #define CMD_HD_LEVEL_STATUS_REP_FLT_HDDETECTED_MSB  6
      #define CMD_HD_LEVEL_STATUS_REP_FLT_HDDETECTED_LSB  6
      #define CMD_HD_LEVEL_STATUS_REP_FLT_HDDETECTED_is_true (reply_buffer[4]&0x40)
      #define CMD_HD_LEVEL_STATUS_REP_FLT_HDDETECTED_value (((reply_buffer[4]&0x40))>>6)
      #define CMD_HD_LEVEL_STATUS_REP_RESERVED_TYPE bitfield
      #define CMD_HD_LEVEL_STATUS_REP_RESERVED_SIZE 6
      #define CMD_HD_LEVEL_STATUS_REP_RESERVED_MASK 0x3F
      #define CMD_HD_LEVEL_STATUS_REP_RESERVED_MSB  5
      #define CMD_HD_LEVEL_STATUS_REP_RESERVED_LSB  0
      #define CMD_HD_LEVEL_STATUS_REP_RESERVED_value (((reply_buffer[4]&0x3F)))
      #define CMD_HD_LEVEL_STATUS_REP_HDLEVEL_TYPE u8
      #define CMD_HD_LEVEL_STATUS_REP_HDLEVEL_SIZE 8
      #define CMD_HD_LEVEL_STATUS_REP_HDLEVEL_MASK 0xFF
      #define CMD_HD_LEVEL_STATUS_REP_HDLEVEL_MSB  7
      #define CMD_HD_LEVEL_STATUS_REP_HDLEVEL_LSB  0
      #define CMD_HD_LEVEL_STATUS_REP_HDLEVEL_INDEX 0x05
      #define CMD_HD_LEVEL_STATUS_REP_HDLEVEL_value (((reply_buffer[5])))
      #define CMD_HD_LEVEL_STATUS_REP_HDLEVEL_MIN 0
      #define CMD_HD_LEVEL_STATUS_REP_HDLEVEL_MAX 100
      #define CMD_HD_LEVEL_STATUS_REP_FILTERED_HDLEVEL_TYPE u8
      #define CMD_HD_LEVEL_STATUS_REP_FILTERED_HDLEVEL_SIZE 8
      #define CMD_HD_LEVEL_STATUS_REP_FILTERED_HDLEVEL_MASK 0xFF
      #define CMD_HD_LEVEL_STATUS_REP_FILTERED_HDLEVEL_MSB  7
      #define CMD_HD_LEVEL_STATUS_REP_FILTERED_HDLEVEL_LSB  0
      #define CMD_HD_LEVEL_STATUS_REP_FILTERED_HDLEVEL_INDEX 0x06
      #define CMD_HD_LEVEL_STATUS_REP_FILTERED_HDLEVEL_value (((reply_buffer[6])))
      #define CMD_HD_LEVEL_STATUS_REP_FILTERED_HDLEVEL_MIN 0
      #define CMD_HD_LEVEL_STATUS_REP_FILTERED_HDLEVEL_MAX 100

#define CMD_HD_DIGRAD_STATUS     0x92
#define CMD_HD_DIGRAD_STATUS_LENGTH 2
#define CMD_HD_DIGRAD_STATUS_REP_LENGTH 23
//HD_DIGRAD_STATUS ARGS
      #define CMD_HD_DIGRAD_STATUS_ARG_DIGRAD_ACK_TYPE bitfield
      #define CMD_HD_DIGRAD_STATUS_ARG_DIGRAD_ACK_SIZE 1
      #define CMD_HD_DIGRAD_STATUS_ARG_DIGRAD_ACK_MASK 0x01
      #define CMD_HD_DIGRAD_STATUS_ARG_DIGRAD_ACK_BIT  0x01
      #define CMD_HD_DIGRAD_STATUS_ARG_DIGRAD_ACK_MSB  0
      #define CMD_HD_DIGRAD_STATUS_ARG_DIGRAD_ACK_LSB  0
      #define CMD_HD_DIGRAD_STATUS_ARG_DIGRAD_ACK_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x1) | (((x)<<0)&0x1)))
//HD_DIGRAD_STATUS REPLY
      #define CMD_HD_DIGRAD_STATUS_REP_HDLOGOINT_TYPE bitfield
      #define CMD_HD_DIGRAD_STATUS_REP_HDLOGOINT_SIZE 1
      #define CMD_HD_DIGRAD_STATUS_REP_HDLOGOINT_MASK 0x80
      #define CMD_HD_DIGRAD_STATUS_REP_HDLOGOINT_BIT  0x80
      #define CMD_HD_DIGRAD_STATUS_REP_HDLOGOINT_MSB  7
      #define CMD_HD_DIGRAD_STATUS_REP_HDLOGOINT_LSB  7
      #define CMD_HD_DIGRAD_STATUS_REP_HDLOGOINT_is_true (reply_buffer[4]&0x80)
      #define CMD_HD_DIGRAD_STATUS_REP_HDLOGOINT_value (((reply_buffer[4]&0x80))>>7)
      #define CMD_HD_DIGRAD_STATUS_REP_SRCANAINT_TYPE bitfield
      #define CMD_HD_DIGRAD_STATUS_REP_SRCANAINT_SIZE 1
      #define CMD_HD_DIGRAD_STATUS_REP_SRCANAINT_MASK 0x40
      #define CMD_HD_DIGRAD_STATUS_REP_SRCANAINT_BIT  0x40
      #define CMD_HD_DIGRAD_STATUS_REP_SRCANAINT_MSB  6
      #define CMD_HD_DIGRAD_STATUS_REP_SRCANAINT_LSB  6
      #define CMD_HD_DIGRAD_STATUS_REP_SRCANAINT_is_true (reply_buffer[4]&0x40)
      #define CMD_HD_DIGRAD_STATUS_REP_SRCANAINT_value (((reply_buffer[4]&0x40))>>6)
      #define CMD_HD_DIGRAD_STATUS_REP_SRCDIGINT_TYPE bitfield
      #define CMD_HD_DIGRAD_STATUS_REP_SRCDIGINT_SIZE 1
      #define CMD_HD_DIGRAD_STATUS_REP_SRCDIGINT_MASK 0x20
      #define CMD_HD_DIGRAD_STATUS_REP_SRCDIGINT_BIT  0x20
      #define CMD_HD_DIGRAD_STATUS_REP_SRCDIGINT_MSB  5
      #define CMD_HD_DIGRAD_STATUS_REP_SRCDIGINT_LSB  5
      #define CMD_HD_DIGRAD_STATUS_REP_SRCDIGINT_is_true (reply_buffer[4]&0x20)
      #define CMD_HD_DIGRAD_STATUS_REP_SRCDIGINT_value (((reply_buffer[4]&0x20))>>5)
      #define CMD_HD_DIGRAD_STATUS_REP_AUDACQINT_TYPE bitfield
      #define CMD_HD_DIGRAD_STATUS_REP_AUDACQINT_SIZE 1
      #define CMD_HD_DIGRAD_STATUS_REP_AUDACQINT_MASK 0x08
      #define CMD_HD_DIGRAD_STATUS_REP_AUDACQINT_BIT  0x08
      #define CMD_HD_DIGRAD_STATUS_REP_AUDACQINT_MSB  3
      #define CMD_HD_DIGRAD_STATUS_REP_AUDACQINT_LSB  3
      #define CMD_HD_DIGRAD_STATUS_REP_AUDACQINT_is_true (reply_buffer[4]&0x8)
      #define CMD_HD_DIGRAD_STATUS_REP_AUDACQINT_value (((reply_buffer[4]&0x8))>>3)
      #define CMD_HD_DIGRAD_STATUS_REP_ACQINT_TYPE bitfield
      #define CMD_HD_DIGRAD_STATUS_REP_ACQINT_SIZE 1
      #define CMD_HD_DIGRAD_STATUS_REP_ACQINT_MASK 0x04
      #define CMD_HD_DIGRAD_STATUS_REP_ACQINT_BIT  0x04
      #define CMD_HD_DIGRAD_STATUS_REP_ACQINT_MSB  2
      #define CMD_HD_DIGRAD_STATUS_REP_ACQINT_LSB  2
      #define CMD_HD_DIGRAD_STATUS_REP_ACQINT_is_true (reply_buffer[4]&0x4)
      #define CMD_HD_DIGRAD_STATUS_REP_ACQINT_value (((reply_buffer[4]&0x4))>>2)
      #define CMD_HD_DIGRAD_STATUS_REP_CDNRHINT_TYPE bitfield
      #define CMD_HD_DIGRAD_STATUS_REP_CDNRHINT_SIZE 1
      #define CMD_HD_DIGRAD_STATUS_REP_CDNRHINT_MASK 0x02
      #define CMD_HD_DIGRAD_STATUS_REP_CDNRHINT_BIT  0x02
      #define CMD_HD_DIGRAD_STATUS_REP_CDNRHINT_MSB  1
      #define CMD_HD_DIGRAD_STATUS_REP_CDNRHINT_LSB  1
      #define CMD_HD_DIGRAD_STATUS_REP_CDNRHINT_is_true (reply_buffer[4]&0x2)
      #define CMD_HD_DIGRAD_STATUS_REP_CDNRHINT_value (((reply_buffer[4]&0x2))>>1)
      #define CMD_HD_DIGRAD_STATUS_REP_CDNRLINT_TYPE bitfield
      #define CMD_HD_DIGRAD_STATUS_REP_CDNRLINT_SIZE 1
      #define CMD_HD_DIGRAD_STATUS_REP_CDNRLINT_MASK 0x01
      #define CMD_HD_DIGRAD_STATUS_REP_CDNRLINT_BIT  0x01
      #define CMD_HD_DIGRAD_STATUS_REP_CDNRLINT_MSB  0
      #define CMD_HD_DIGRAD_STATUS_REP_CDNRLINT_LSB  0
      #define CMD_HD_DIGRAD_STATUS_REP_CDNRLINT_is_true (reply_buffer[4]&0x1)
      #define CMD_HD_DIGRAD_STATUS_REP_CDNRLINT_value (((reply_buffer[4]&0x1)))
      #define CMD_HD_DIGRAD_STATUS_REP_HDLOGO_TYPE bitfield
      #define CMD_HD_DIGRAD_STATUS_REP_HDLOGO_SIZE 1
      #define CMD_HD_DIGRAD_STATUS_REP_HDLOGO_MASK 0x80
      #define CMD_HD_DIGRAD_STATUS_REP_HDLOGO_BIT  0x80
      #define CMD_HD_DIGRAD_STATUS_REP_HDLOGO_MSB  7
      #define CMD_HD_DIGRAD_STATUS_REP_HDLOGO_LSB  7
      #define CMD_HD_DIGRAD_STATUS_REP_HDLOGO_is_true (reply_buffer[5]&0x80)
      #define CMD_HD_DIGRAD_STATUS_REP_HDLOGO_value (((reply_buffer[5]&0x80))>>7)
      #define CMD_HD_DIGRAD_STATUS_REP_SRCANA_TYPE bitfield
      #define CMD_HD_DIGRAD_STATUS_REP_SRCANA_SIZE 1
      #define CMD_HD_DIGRAD_STATUS_REP_SRCANA_MASK 0x40
      #define CMD_HD_DIGRAD_STATUS_REP_SRCANA_BIT  0x40
      #define CMD_HD_DIGRAD_STATUS_REP_SRCANA_MSB  6
      #define CMD_HD_DIGRAD_STATUS_REP_SRCANA_LSB  6
      #define CMD_HD_DIGRAD_STATUS_REP_SRCANA_is_true (reply_buffer[5]&0x40)
      #define CMD_HD_DIGRAD_STATUS_REP_SRCANA_value (((reply_buffer[5]&0x40))>>6)
      #define CMD_HD_DIGRAD_STATUS_REP_SRCDIG_TYPE bitfield
      #define CMD_HD_DIGRAD_STATUS_REP_SRCDIG_SIZE 1
      #define CMD_HD_DIGRAD_STATUS_REP_SRCDIG_MASK 0x20
      #define CMD_HD_DIGRAD_STATUS_REP_SRCDIG_BIT  0x20
      #define CMD_HD_DIGRAD_STATUS_REP_SRCDIG_MSB  5
      #define CMD_HD_DIGRAD_STATUS_REP_SRCDIG_LSB  5
      #define CMD_HD_DIGRAD_STATUS_REP_SRCDIG_is_true (reply_buffer[5]&0x20)
      #define CMD_HD_DIGRAD_STATUS_REP_SRCDIG_value (((reply_buffer[5]&0x20))>>5)
      #define CMD_HD_DIGRAD_STATUS_REP_AUDACQ_TYPE bitfield
      #define CMD_HD_DIGRAD_STATUS_REP_AUDACQ_SIZE 1
      #define CMD_HD_DIGRAD_STATUS_REP_AUDACQ_MASK 0x08
      #define CMD_HD_DIGRAD_STATUS_REP_AUDACQ_BIT  0x08
      #define CMD_HD_DIGRAD_STATUS_REP_AUDACQ_MSB  3
      #define CMD_HD_DIGRAD_STATUS_REP_AUDACQ_LSB  3
      #define CMD_HD_DIGRAD_STATUS_REP_AUDACQ_is_true (reply_buffer[5]&0x8)
      #define CMD_HD_DIGRAD_STATUS_REP_AUDACQ_value (((reply_buffer[5]&0x8))>>3)
      #define CMD_HD_DIGRAD_STATUS_REP_ACQ_TYPE bitfield
      #define CMD_HD_DIGRAD_STATUS_REP_ACQ_SIZE 1
      #define CMD_HD_DIGRAD_STATUS_REP_ACQ_MASK 0x04
      #define CMD_HD_DIGRAD_STATUS_REP_ACQ_BIT  0x04
      #define CMD_HD_DIGRAD_STATUS_REP_ACQ_MSB  2
      #define CMD_HD_DIGRAD_STATUS_REP_ACQ_LSB  2
      #define CMD_HD_DIGRAD_STATUS_REP_ACQ_is_true (reply_buffer[5]&0x4)
      #define CMD_HD_DIGRAD_STATUS_REP_ACQ_value (((reply_buffer[5]&0x4))>>2)
      #define CMD_HD_DIGRAD_STATUS_REP_CDNRH_TYPE bitfield
      #define CMD_HD_DIGRAD_STATUS_REP_CDNRH_SIZE 1
      #define CMD_HD_DIGRAD_STATUS_REP_CDNRH_MASK 0x02
      #define CMD_HD_DIGRAD_STATUS_REP_CDNRH_BIT  0x02
      #define CMD_HD_DIGRAD_STATUS_REP_CDNRH_MSB  1
      #define CMD_HD_DIGRAD_STATUS_REP_CDNRH_LSB  1
      #define CMD_HD_DIGRAD_STATUS_REP_CDNRH_is_true (reply_buffer[5]&0x2)
      #define CMD_HD_DIGRAD_STATUS_REP_CDNRH_value (((reply_buffer[5]&0x2))>>1)
      #define CMD_HD_DIGRAD_STATUS_REP_CDNRL_TYPE bitfield
      #define CMD_HD_DIGRAD_STATUS_REP_CDNRL_SIZE 1
      #define CMD_HD_DIGRAD_STATUS_REP_CDNRL_MASK 0x01
      #define CMD_HD_DIGRAD_STATUS_REP_CDNRL_BIT  0x01
      #define CMD_HD_DIGRAD_STATUS_REP_CDNRL_MSB  0
      #define CMD_HD_DIGRAD_STATUS_REP_CDNRL_LSB  0
      #define CMD_HD_DIGRAD_STATUS_REP_CDNRL_is_true (reply_buffer[5]&0x1)
      #define CMD_HD_DIGRAD_STATUS_REP_CDNRL_value (((reply_buffer[5]&0x1)))
      #define CMD_HD_DIGRAD_STATUS_REP_BCTL_TYPE bitfield
      #define CMD_HD_DIGRAD_STATUS_REP_BCTL_SIZE 2
      #define CMD_HD_DIGRAD_STATUS_REP_BCTL_MASK 0xC0
      #define CMD_HD_DIGRAD_STATUS_REP_BCTL_MSB  7
      #define CMD_HD_DIGRAD_STATUS_REP_BCTL_LSB  6
      #define CMD_HD_DIGRAD_STATUS_REP_BCTL_value (((reply_buffer[6]&0xC0))>>6)
      #define CMD_HD_DIGRAD_STATUS_REP_DAAI_TYPE bitfield
      #define CMD_HD_DIGRAD_STATUS_REP_DAAI_SIZE 6
      #define CMD_HD_DIGRAD_STATUS_REP_DAAI_MASK 0x3F
      #define CMD_HD_DIGRAD_STATUS_REP_DAAI_MSB  5
      #define CMD_HD_DIGRAD_STATUS_REP_DAAI_LSB  0
      #define CMD_HD_DIGRAD_STATUS_REP_DAAI_value (((reply_buffer[6]&0x3F)))
      #define CMD_HD_DIGRAD_STATUS_REP_CDNR_TYPE u8
      #define CMD_HD_DIGRAD_STATUS_REP_CDNR_SIZE 8
      #define CMD_HD_DIGRAD_STATUS_REP_CDNR_MASK 0xFF
      #define CMD_HD_DIGRAD_STATUS_REP_CDNR_MSB  7
      #define CMD_HD_DIGRAD_STATUS_REP_CDNR_LSB  0
      #define CMD_HD_DIGRAD_STATUS_REP_CDNR_INDEX 0x07
      #define CMD_HD_DIGRAD_STATUS_REP_CDNR_value (((reply_buffer[7])))
      #define CMD_HD_DIGRAD_STATUS_REP_TX_GAIN_TYPE bitfield
      #define CMD_HD_DIGRAD_STATUS_REP_TX_GAIN_SIZE 5
      #define CMD_HD_DIGRAD_STATUS_REP_TX_GAIN_MASK 0x1F
      #define CMD_HD_DIGRAD_STATUS_REP_TX_GAIN_MSB  4
      #define CMD_HD_DIGRAD_STATUS_REP_TX_GAIN_LSB  0
      #define CMD_HD_DIGRAD_STATUS_REP_TX_GAIN_value (((reply_buffer[8]&0x1F)))
      #define CMD_HD_DIGRAD_STATUS_REP_AUDIO_PROG_AVAIL_TYPE u8
      #define CMD_HD_DIGRAD_STATUS_REP_AUDIO_PROG_AVAIL_SIZE 8
      #define CMD_HD_DIGRAD_STATUS_REP_AUDIO_PROG_AVAIL_MASK 0xFF
      #define CMD_HD_DIGRAD_STATUS_REP_AUDIO_PROG_AVAIL_MSB  7
      #define CMD_HD_DIGRAD_STATUS_REP_AUDIO_PROG_AVAIL_LSB  0
      #define CMD_HD_DIGRAD_STATUS_REP_AUDIO_PROG_AVAIL_INDEX 0x09
      #define CMD_HD_DIGRAD_STATUS_REP_AUDIO_PROG_AVAIL_value (((reply_buffer[9])))
      #define CMD_HD_DIGRAD_STATUS_REP_AUDIO_PROG_PLAYING_TYPE u8
      #define CMD_HD_DIGRAD_STATUS_REP_AUDIO_PROG_PLAYING_SIZE 8
      #define CMD_HD_DIGRAD_STATUS_REP_AUDIO_PROG_PLAYING_MASK 0xFF
      #define CMD_HD_DIGRAD_STATUS_REP_AUDIO_PROG_PLAYING_MSB  7
      #define CMD_HD_DIGRAD_STATUS_REP_AUDIO_PROG_PLAYING_LSB  0
      #define CMD_HD_DIGRAD_STATUS_REP_AUDIO_PROG_PLAYING_INDEX 0x0A
      #define CMD_HD_DIGRAD_STATUS_REP_AUDIO_PROG_PLAYING_value (((reply_buffer[10])))
      #define CMD_HD_DIGRAD_STATUS_REP_AUDIO_CA_TYPE u8
      #define CMD_HD_DIGRAD_STATUS_REP_AUDIO_CA_SIZE 8
      #define CMD_HD_DIGRAD_STATUS_REP_AUDIO_CA_MASK 0xFF
      #define CMD_HD_DIGRAD_STATUS_REP_AUDIO_CA_MSB  7
      #define CMD_HD_DIGRAD_STATUS_REP_AUDIO_CA_LSB  0
      #define CMD_HD_DIGRAD_STATUS_REP_AUDIO_CA_INDEX 0x0B
      #define CMD_HD_DIGRAD_STATUS_REP_AUDIO_CA_value (((reply_buffer[11])))
      #define CMD_HD_DIGRAD_STATUS_REP_CORE_AUDIO_ERR_TYPE u32
      #define CMD_HD_DIGRAD_STATUS_REP_CORE_AUDIO_ERR_SIZE 32
      #define CMD_HD_DIGRAD_STATUS_REP_CORE_AUDIO_ERR_MASK 0xFFFFFFFF
      #define CMD_HD_DIGRAD_STATUS_REP_CORE_AUDIO_ERR_MSB  31
      #define CMD_HD_DIGRAD_STATUS_REP_CORE_AUDIO_ERR_LSB  0
      #define CMD_HD_DIGRAD_STATUS_REP_CORE_AUDIO_ERR_INDEX 0x0C
      #define CMD_HD_DIGRAD_STATUS_REP_CORE_AUDIO_ERR_value (((reply_buffer_u32[3])))
      #define CMD_HD_DIGRAD_STATUS_REP_ENH_AUDIO_ERR_TYPE u32
      #define CMD_HD_DIGRAD_STATUS_REP_ENH_AUDIO_ERR_SIZE 32
      #define CMD_HD_DIGRAD_STATUS_REP_ENH_AUDIO_ERR_MASK 0xFFFFFFFF
      #define CMD_HD_DIGRAD_STATUS_REP_ENH_AUDIO_ERR_MSB  31
      #define CMD_HD_DIGRAD_STATUS_REP_ENH_AUDIO_ERR_LSB  0
      #define CMD_HD_DIGRAD_STATUS_REP_ENH_AUDIO_ERR_INDEX 0x10
      #define CMD_HD_DIGRAD_STATUS_REP_ENH_AUDIO_ERR_value (((reply_buffer_u32[4])))
      #define CMD_HD_DIGRAD_STATUS_REP_PTY_TYPE u8
      #define CMD_HD_DIGRAD_STATUS_REP_PTY_SIZE 8
      #define CMD_HD_DIGRAD_STATUS_REP_PTY_MASK 0xFF
      #define CMD_HD_DIGRAD_STATUS_REP_PTY_MSB  7
      #define CMD_HD_DIGRAD_STATUS_REP_PTY_LSB  0
      #define CMD_HD_DIGRAD_STATUS_REP_PTY_INDEX 0x14
      #define CMD_HD_DIGRAD_STATUS_REP_PTY_value (((reply_buffer[20])))
      #define CMD_HD_DIGRAD_STATUS_REP_PS_MODE_TYPE u8
      #define CMD_HD_DIGRAD_STATUS_REP_PS_MODE_SIZE 8
      #define CMD_HD_DIGRAD_STATUS_REP_PS_MODE_MASK 0xFF
      #define CMD_HD_DIGRAD_STATUS_REP_PS_MODE_MSB  7
      #define CMD_HD_DIGRAD_STATUS_REP_PS_MODE_LSB  0
      #define CMD_HD_DIGRAD_STATUS_REP_PS_MODE_INDEX 0x15
      #define CMD_HD_DIGRAD_STATUS_REP_PS_MODE_value (((reply_buffer[21])))
      #define CMD_HD_DIGRAD_STATUS_REP_CODEC_MODE_TYPE u8
      #define CMD_HD_DIGRAD_STATUS_REP_CODEC_MODE_SIZE 8
      #define CMD_HD_DIGRAD_STATUS_REP_CODEC_MODE_MASK 0xFF
      #define CMD_HD_DIGRAD_STATUS_REP_CODEC_MODE_MSB  7
      #define CMD_HD_DIGRAD_STATUS_REP_CODEC_MODE_LSB  0
      #define CMD_HD_DIGRAD_STATUS_REP_CODEC_MODE_INDEX 0x16
      #define CMD_HD_DIGRAD_STATUS_REP_CODEC_MODE_value (((reply_buffer[22])))

#define CMD_HD_GET_EVENT_STATUS  0x93
#define CMD_HD_GET_EVENT_STATUS_LENGTH 2
#define CMD_HD_GET_EVENT_STATUS_REP_LENGTH 18
//HD_GET_EVENT_STATUS ARGS
      #define CMD_HD_GET_EVENT_STATUS_ARG_EVENT_ACK_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_ARG_EVENT_ACK_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_ARG_EVENT_ACK_MASK 0x01
      #define CMD_HD_GET_EVENT_STATUS_ARG_EVENT_ACK_BIT  0x01
      #define CMD_HD_GET_EVENT_STATUS_ARG_EVENT_ACK_MSB  0
      #define CMD_HD_GET_EVENT_STATUS_ARG_EVENT_ACK_LSB  0
      #define CMD_HD_GET_EVENT_STATUS_ARG_EVENT_ACK_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x1) | (((x)<<0)&0x1)))
//HD_GET_EVENT_STATUS REPLY
      #define CMD_HD_GET_EVENT_STATUS_REP_DINFOINT_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_DINFOINT_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_DINFOINT_MASK 0x80
      #define CMD_HD_GET_EVENT_STATUS_REP_DINFOINT_BIT  0x80
      #define CMD_HD_GET_EVENT_STATUS_REP_DINFOINT_MSB  7
      #define CMD_HD_GET_EVENT_STATUS_REP_DINFOINT_LSB  7
      #define CMD_HD_GET_EVENT_STATUS_REP_DINFOINT_is_true (reply_buffer[4]&0x80)
      #define CMD_HD_GET_EVENT_STATUS_REP_DINFOINT_value (((reply_buffer[4]&0x80))>>7)
      #define CMD_HD_GET_EVENT_STATUS_REP_AINFOINT_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_AINFOINT_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_AINFOINT_MASK 0x40
      #define CMD_HD_GET_EVENT_STATUS_REP_AINFOINT_BIT  0x40
      #define CMD_HD_GET_EVENT_STATUS_REP_AINFOINT_MSB  6
      #define CMD_HD_GET_EVENT_STATUS_REP_AINFOINT_LSB  6
      #define CMD_HD_GET_EVENT_STATUS_REP_AINFOINT_is_true (reply_buffer[4]&0x40)
      #define CMD_HD_GET_EVENT_STATUS_REP_AINFOINT_value (((reply_buffer[4]&0x40))>>6)
      #define CMD_HD_GET_EVENT_STATUS_REP_ALERTINT_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_ALERTINT_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_ALERTINT_MASK 0x10
      #define CMD_HD_GET_EVENT_STATUS_REP_ALERTINT_BIT  0x10
      #define CMD_HD_GET_EVENT_STATUS_REP_ALERTINT_MSB  4
      #define CMD_HD_GET_EVENT_STATUS_REP_ALERTINT_LSB  4
      #define CMD_HD_GET_EVENT_STATUS_REP_ALERTINT_is_true (reply_buffer[4]&0x10)
      #define CMD_HD_GET_EVENT_STATUS_REP_ALERTINT_value (((reply_buffer[4]&0x10))>>4)
      #define CMD_HD_GET_EVENT_STATUS_REP_PSDINT_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_PSDINT_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_PSDINT_MASK 0x08
      #define CMD_HD_GET_EVENT_STATUS_REP_PSDINT_BIT  0x08
      #define CMD_HD_GET_EVENT_STATUS_REP_PSDINT_MSB  3
      #define CMD_HD_GET_EVENT_STATUS_REP_PSDINT_LSB  3
      #define CMD_HD_GET_EVENT_STATUS_REP_PSDINT_is_true (reply_buffer[4]&0x8)
      #define CMD_HD_GET_EVENT_STATUS_REP_PSDINT_value (((reply_buffer[4]&0x8))>>3)
      #define CMD_HD_GET_EVENT_STATUS_REP_SISINT_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_SISINT_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_SISINT_MASK 0x04
      #define CMD_HD_GET_EVENT_STATUS_REP_SISINT_BIT  0x04
      #define CMD_HD_GET_EVENT_STATUS_REP_SISINT_MSB  2
      #define CMD_HD_GET_EVENT_STATUS_REP_SISINT_LSB  2
      #define CMD_HD_GET_EVENT_STATUS_REP_SISINT_is_true (reply_buffer[4]&0x4)
      #define CMD_HD_GET_EVENT_STATUS_REP_SISINT_value (((reply_buffer[4]&0x4))>>2)
      #define CMD_HD_GET_EVENT_STATUS_REP_DSRVLISTINT_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_DSRVLISTINT_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_DSRVLISTINT_MASK 0x02
      #define CMD_HD_GET_EVENT_STATUS_REP_DSRVLISTINT_BIT  0x02
      #define CMD_HD_GET_EVENT_STATUS_REP_DSRVLISTINT_MSB  1
      #define CMD_HD_GET_EVENT_STATUS_REP_DSRVLISTINT_LSB  1
      #define CMD_HD_GET_EVENT_STATUS_REP_DSRVLISTINT_is_true (reply_buffer[4]&0x2)
      #define CMD_HD_GET_EVENT_STATUS_REP_DSRVLISTINT_value (((reply_buffer[4]&0x2))>>1)
      #define CMD_HD_GET_EVENT_STATUS_REP_ASRVLISTINT_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_ASRVLISTINT_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_ASRVLISTINT_MASK 0x01
      #define CMD_HD_GET_EVENT_STATUS_REP_ASRVLISTINT_BIT  0x01
      #define CMD_HD_GET_EVENT_STATUS_REP_ASRVLISTINT_MSB  0
      #define CMD_HD_GET_EVENT_STATUS_REP_ASRVLISTINT_LSB  0
      #define CMD_HD_GET_EVENT_STATUS_REP_ASRVLISTINT_is_true (reply_buffer[4]&0x1)
      #define CMD_HD_GET_EVENT_STATUS_REP_ASRVLISTINT_value (((reply_buffer[4]&0x1)))
      #define CMD_HD_GET_EVENT_STATUS_REP_DINFO_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_DINFO_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_DINFO_MASK 0x80
      #define CMD_HD_GET_EVENT_STATUS_REP_DINFO_BIT  0x80
      #define CMD_HD_GET_EVENT_STATUS_REP_DINFO_MSB  7
      #define CMD_HD_GET_EVENT_STATUS_REP_DINFO_LSB  7
      #define CMD_HD_GET_EVENT_STATUS_REP_DINFO_is_true (reply_buffer[5]&0x80)
      #define CMD_HD_GET_EVENT_STATUS_REP_DINFO_value (((reply_buffer[5]&0x80))>>7)
      #define CMD_HD_GET_EVENT_STATUS_REP_AINFO_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_AINFO_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_AINFO_MASK 0x40
      #define CMD_HD_GET_EVENT_STATUS_REP_AINFO_BIT  0x40
      #define CMD_HD_GET_EVENT_STATUS_REP_AINFO_MSB  6
      #define CMD_HD_GET_EVENT_STATUS_REP_AINFO_LSB  6
      #define CMD_HD_GET_EVENT_STATUS_REP_AINFO_is_true (reply_buffer[5]&0x40)
      #define CMD_HD_GET_EVENT_STATUS_REP_AINFO_value (((reply_buffer[5]&0x40))>>6)
      #define CMD_HD_GET_EVENT_STATUS_REP_PSD_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_PSD_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_PSD_MASK 0x08
      #define CMD_HD_GET_EVENT_STATUS_REP_PSD_BIT  0x08
      #define CMD_HD_GET_EVENT_STATUS_REP_PSD_MSB  3
      #define CMD_HD_GET_EVENT_STATUS_REP_PSD_LSB  3
      #define CMD_HD_GET_EVENT_STATUS_REP_PSD_is_true (reply_buffer[5]&0x8)
      #define CMD_HD_GET_EVENT_STATUS_REP_PSD_value (((reply_buffer[5]&0x8))>>3)
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_MASK 0x04
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_BIT  0x04
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_MSB  2
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_LSB  2
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_is_true (reply_buffer[5]&0x4)
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_value (((reply_buffer[5]&0x4))>>2)
      #define CMD_HD_GET_EVENT_STATUS_REP_DSRVLIST_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_DSRVLIST_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_DSRVLIST_MASK 0x02
      #define CMD_HD_GET_EVENT_STATUS_REP_DSRVLIST_BIT  0x02
      #define CMD_HD_GET_EVENT_STATUS_REP_DSRVLIST_MSB  1
      #define CMD_HD_GET_EVENT_STATUS_REP_DSRVLIST_LSB  1
      #define CMD_HD_GET_EVENT_STATUS_REP_DSRVLIST_is_true (reply_buffer[5]&0x2)
      #define CMD_HD_GET_EVENT_STATUS_REP_DSRVLIST_value (((reply_buffer[5]&0x2))>>1)
      #define CMD_HD_GET_EVENT_STATUS_REP_ASRVLIST_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_ASRVLIST_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_ASRVLIST_MASK 0x01
      #define CMD_HD_GET_EVENT_STATUS_REP_ASRVLIST_BIT  0x01
      #define CMD_HD_GET_EVENT_STATUS_REP_ASRVLIST_MSB  0
      #define CMD_HD_GET_EVENT_STATUS_REP_ASRVLIST_LSB  0
      #define CMD_HD_GET_EVENT_STATUS_REP_ASRVLIST_is_true (reply_buffer[5]&0x1)
      #define CMD_HD_GET_EVENT_STATUS_REP_ASRVLIST_value (((reply_buffer[5]&0x1)))
      #define CMD_HD_GET_EVENT_STATUS_REP_ASRVLISTVER_TYPE u16
      #define CMD_HD_GET_EVENT_STATUS_REP_ASRVLISTVER_SIZE 16
      #define CMD_HD_GET_EVENT_STATUS_REP_ASRVLISTVER_MASK 0xFFFF
      #define CMD_HD_GET_EVENT_STATUS_REP_ASRVLISTVER_MSB  15
      #define CMD_HD_GET_EVENT_STATUS_REP_ASRVLISTVER_LSB  0
      #define CMD_HD_GET_EVENT_STATUS_REP_ASRVLISTVER_INDEX 0x06
      #define CMD_HD_GET_EVENT_STATUS_REP_ASRVLISTVER_value (((reply_buffer_u16[3])))
      #define CMD_HD_GET_EVENT_STATUS_REP_DSRVLISTVER_TYPE u16
      #define CMD_HD_GET_EVENT_STATUS_REP_DSRVLISTVER_SIZE 16
      #define CMD_HD_GET_EVENT_STATUS_REP_DSRVLISTVER_MASK 0xFFFF
      #define CMD_HD_GET_EVENT_STATUS_REP_DSRVLISTVER_MSB  15
      #define CMD_HD_GET_EVENT_STATUS_REP_DSRVLISTVER_LSB  0
      #define CMD_HD_GET_EVENT_STATUS_REP_DSRVLISTVER_INDEX 0x08
      #define CMD_HD_GET_EVENT_STATUS_REP_DSRVLISTVER_value (((reply_buffer_u16[4])))
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_LOCATION_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_LOCATION_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_LOCATION_MASK 0x10
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_LOCATION_BIT  0x10
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_LOCATION_MSB  4
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_LOCATION_LSB  4
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_LOCATION_is_true (reply_buffer[10]&0x10)
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_LOCATION_value (((reply_buffer[10]&0x10))>>4)
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_LONG_NAME_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_LONG_NAME_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_LONG_NAME_MASK 0x04
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_LONG_NAME_BIT  0x04
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_LONG_NAME_MSB  2
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_LONG_NAME_LSB  2
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_LONG_NAME_is_true (reply_buffer[10]&0x4)
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_LONG_NAME_value (((reply_buffer[10]&0x4))>>2)
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_SHORT_NAME_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_SHORT_NAME_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_SHORT_NAME_MASK 0x02
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_SHORT_NAME_BIT  0x02
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_SHORT_NAME_MSB  1
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_SHORT_NAME_LSB  1
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_SHORT_NAME_is_true (reply_buffer[10]&0x2)
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_SHORT_NAME_value (((reply_buffer[10]&0x2))>>1)
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_ID_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_ID_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_ID_MASK 0x01
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_ID_BIT  0x01
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_ID_MSB  0
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_ID_LSB  0
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_ID_is_true (reply_buffer[10]&0x1)
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_ID_value (((reply_buffer[10]&0x1)))
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_SLOGAN_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_SLOGAN_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_SLOGAN_MASK 0x20
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_SLOGAN_BIT  0x20
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_SLOGAN_MSB  5
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_SLOGAN_LSB  5
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_SLOGAN_is_true (reply_buffer[11]&0x20)
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_SLOGAN_value (((reply_buffer[11]&0x20))>>5)
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_BASIC_SIS_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_BASIC_SIS_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_BASIC_SIS_MASK 0x10
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_BASIC_SIS_BIT  0x10
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_BASIC_SIS_MSB  4
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_BASIC_SIS_LSB  4
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_BASIC_SIS_is_true (reply_buffer[11]&0x10)
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_BASIC_SIS_value (((reply_buffer[11]&0x10))>>4)
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_UNIV_SHORT_NAME_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_UNIV_SHORT_NAME_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_UNIV_SHORT_NAME_MASK 0x08
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_UNIV_SHORT_NAME_BIT  0x08
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_UNIV_SHORT_NAME_MSB  3
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_UNIV_SHORT_NAME_LSB  3
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_UNIV_SHORT_NAME_is_true (reply_buffer[11]&0x8)
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_UNIV_SHORT_NAME_value (((reply_buffer[11]&0x8))>>3)
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_LEAP_SEC_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_LEAP_SEC_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_LEAP_SEC_MASK 0x04
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_LEAP_SEC_BIT  0x04
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_LEAP_SEC_MSB  2
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_LEAP_SEC_LSB  2
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_LEAP_SEC_is_true (reply_buffer[11]&0x4)
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_LEAP_SEC_value (((reply_buffer[11]&0x4))>>2)
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_TIMEZONE_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_TIMEZONE_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_TIMEZONE_MASK 0x02
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_TIMEZONE_BIT  0x02
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_TIMEZONE_MSB  1
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_TIMEZONE_LSB  1
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_TIMEZONE_is_true (reply_buffer[11]&0x2)
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_TIMEZONE_value (((reply_buffer[11]&0x2))>>1)
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_MESSAGE_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_MESSAGE_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_MESSAGE_MASK 0x01
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_MESSAGE_BIT  0x01
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_MESSAGE_MSB  0
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_MESSAGE_LSB  0
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_MESSAGE_is_true (reply_buffer[11]&0x1)
      #define CMD_HD_GET_EVENT_STATUS_REP_SIS_MESSAGE_value (((reply_buffer[11]&0x1)))
      #define CMD_HD_GET_EVENT_STATUS_REP_TEXT_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_TEXT_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_TEXT_MASK 0x40
      #define CMD_HD_GET_EVENT_STATUS_REP_TEXT_BIT  0x40
      #define CMD_HD_GET_EVENT_STATUS_REP_TEXT_MSB  6
      #define CMD_HD_GET_EVENT_STATUS_REP_TEXT_LSB  6
      #define CMD_HD_GET_EVENT_STATUS_REP_TEXT_is_true (reply_buffer[12]&0x40)
      #define CMD_HD_GET_EVENT_STATUS_REP_TEXT_value (((reply_buffer[12]&0x40))>>6)
      #define CMD_HD_GET_EVENT_STATUS_REP_SHORT_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_SHORT_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_SHORT_MASK 0x20
      #define CMD_HD_GET_EVENT_STATUS_REP_SHORT_BIT  0x20
      #define CMD_HD_GET_EVENT_STATUS_REP_SHORT_MSB  5
      #define CMD_HD_GET_EVENT_STATUS_REP_SHORT_LSB  5
      #define CMD_HD_GET_EVENT_STATUS_REP_SHORT_is_true (reply_buffer[12]&0x20)
      #define CMD_HD_GET_EVENT_STATUS_REP_SHORT_value (((reply_buffer[12]&0x20))>>5)
      #define CMD_HD_GET_EVENT_STATUS_REP_LANG_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_LANG_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_LANG_MASK 0x10
      #define CMD_HD_GET_EVENT_STATUS_REP_LANG_BIT  0x10
      #define CMD_HD_GET_EVENT_STATUS_REP_LANG_MSB  4
      #define CMD_HD_GET_EVENT_STATUS_REP_LANG_LSB  4
      #define CMD_HD_GET_EVENT_STATUS_REP_LANG_is_true (reply_buffer[12]&0x10)
      #define CMD_HD_GET_EVENT_STATUS_REP_LANG_value (((reply_buffer[12]&0x10))>>4)
      #define CMD_HD_GET_EVENT_STATUS_REP_GENRE_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_GENRE_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_GENRE_MASK 0x08
      #define CMD_HD_GET_EVENT_STATUS_REP_GENRE_BIT  0x08
      #define CMD_HD_GET_EVENT_STATUS_REP_GENRE_MSB  3
      #define CMD_HD_GET_EVENT_STATUS_REP_GENRE_LSB  3
      #define CMD_HD_GET_EVENT_STATUS_REP_GENRE_is_true (reply_buffer[12]&0x8)
      #define CMD_HD_GET_EVENT_STATUS_REP_GENRE_value (((reply_buffer[12]&0x8))>>3)
      #define CMD_HD_GET_EVENT_STATUS_REP_ALBUM_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_ALBUM_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_ALBUM_MASK 0x04
      #define CMD_HD_GET_EVENT_STATUS_REP_ALBUM_BIT  0x04
      #define CMD_HD_GET_EVENT_STATUS_REP_ALBUM_MSB  2
      #define CMD_HD_GET_EVENT_STATUS_REP_ALBUM_LSB  2
      #define CMD_HD_GET_EVENT_STATUS_REP_ALBUM_is_true (reply_buffer[12]&0x4)
      #define CMD_HD_GET_EVENT_STATUS_REP_ALBUM_value (((reply_buffer[12]&0x4))>>2)
      #define CMD_HD_GET_EVENT_STATUS_REP_ARTIST_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_ARTIST_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_ARTIST_MASK 0x02
      #define CMD_HD_GET_EVENT_STATUS_REP_ARTIST_BIT  0x02
      #define CMD_HD_GET_EVENT_STATUS_REP_ARTIST_MSB  1
      #define CMD_HD_GET_EVENT_STATUS_REP_ARTIST_LSB  1
      #define CMD_HD_GET_EVENT_STATUS_REP_ARTIST_is_true (reply_buffer[12]&0x2)
      #define CMD_HD_GET_EVENT_STATUS_REP_ARTIST_value (((reply_buffer[12]&0x2))>>1)
      #define CMD_HD_GET_EVENT_STATUS_REP_TITLE_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_TITLE_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_TITLE_MASK 0x01
      #define CMD_HD_GET_EVENT_STATUS_REP_TITLE_BIT  0x01
      #define CMD_HD_GET_EVENT_STATUS_REP_TITLE_MSB  0
      #define CMD_HD_GET_EVENT_STATUS_REP_TITLE_LSB  0
      #define CMD_HD_GET_EVENT_STATUS_REP_TITLE_is_true (reply_buffer[12]&0x1)
      #define CMD_HD_GET_EVENT_STATUS_REP_TITLE_value (((reply_buffer[12]&0x1)))
      #define CMD_HD_GET_EVENT_STATUS_REP_ID_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_ID_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_ID_MASK 0x80
      #define CMD_HD_GET_EVENT_STATUS_REP_ID_BIT  0x80
      #define CMD_HD_GET_EVENT_STATUS_REP_ID_MSB  7
      #define CMD_HD_GET_EVENT_STATUS_REP_ID_LSB  7
      #define CMD_HD_GET_EVENT_STATUS_REP_ID_is_true (reply_buffer[13]&0x80)
      #define CMD_HD_GET_EVENT_STATUS_REP_ID_value (((reply_buffer[13]&0x80))>>7)
      #define CMD_HD_GET_EVENT_STATUS_REP_OWNER_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_OWNER_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_OWNER_MASK 0x40
      #define CMD_HD_GET_EVENT_STATUS_REP_OWNER_BIT  0x40
      #define CMD_HD_GET_EVENT_STATUS_REP_OWNER_MSB  6
      #define CMD_HD_GET_EVENT_STATUS_REP_OWNER_LSB  6
      #define CMD_HD_GET_EVENT_STATUS_REP_OWNER_is_true (reply_buffer[13]&0x40)
      #define CMD_HD_GET_EVENT_STATUS_REP_OWNER_value (((reply_buffer[13]&0x40))>>6)
      #define CMD_HD_GET_EVENT_STATUS_REP_DESC_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_DESC_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_DESC_MASK 0x20
      #define CMD_HD_GET_EVENT_STATUS_REP_DESC_BIT  0x20
      #define CMD_HD_GET_EVENT_STATUS_REP_DESC_MSB  5
      #define CMD_HD_GET_EVENT_STATUS_REP_DESC_LSB  5
      #define CMD_HD_GET_EVENT_STATUS_REP_DESC_is_true (reply_buffer[13]&0x20)
      #define CMD_HD_GET_EVENT_STATUS_REP_DESC_value (((reply_buffer[13]&0x20))>>5)
      #define CMD_HD_GET_EVENT_STATUS_REP_NAME_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_NAME_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_NAME_MASK 0x10
      #define CMD_HD_GET_EVENT_STATUS_REP_NAME_BIT  0x10
      #define CMD_HD_GET_EVENT_STATUS_REP_NAME_MSB  4
      #define CMD_HD_GET_EVENT_STATUS_REP_NAME_LSB  4
      #define CMD_HD_GET_EVENT_STATUS_REP_NAME_is_true (reply_buffer[13]&0x10)
      #define CMD_HD_GET_EVENT_STATUS_REP_NAME_value (((reply_buffer[13]&0x10))>>4)
      #define CMD_HD_GET_EVENT_STATUS_REP_RECV_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_RECV_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_RECV_MASK 0x08
      #define CMD_HD_GET_EVENT_STATUS_REP_RECV_BIT  0x08
      #define CMD_HD_GET_EVENT_STATUS_REP_RECV_MSB  3
      #define CMD_HD_GET_EVENT_STATUS_REP_RECV_LSB  3
      #define CMD_HD_GET_EVENT_STATUS_REP_RECV_is_true (reply_buffer[13]&0x8)
      #define CMD_HD_GET_EVENT_STATUS_REP_RECV_value (((reply_buffer[13]&0x8))>>3)
      #define CMD_HD_GET_EVENT_STATUS_REP_URL_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_URL_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_URL_MASK 0x04
      #define CMD_HD_GET_EVENT_STATUS_REP_URL_BIT  0x04
      #define CMD_HD_GET_EVENT_STATUS_REP_URL_MSB  2
      #define CMD_HD_GET_EVENT_STATUS_REP_URL_LSB  2
      #define CMD_HD_GET_EVENT_STATUS_REP_URL_is_true (reply_buffer[13]&0x4)
      #define CMD_HD_GET_EVENT_STATUS_REP_URL_value (((reply_buffer[13]&0x4))>>2)
      #define CMD_HD_GET_EVENT_STATUS_REP_VALID_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_VALID_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_VALID_MASK 0x02
      #define CMD_HD_GET_EVENT_STATUS_REP_VALID_BIT  0x02
      #define CMD_HD_GET_EVENT_STATUS_REP_VALID_MSB  1
      #define CMD_HD_GET_EVENT_STATUS_REP_VALID_LSB  1
      #define CMD_HD_GET_EVENT_STATUS_REP_VALID_is_true (reply_buffer[13]&0x2)
      #define CMD_HD_GET_EVENT_STATUS_REP_VALID_value (((reply_buffer[13]&0x2))>>1)
      #define CMD_HD_GET_EVENT_STATUS_REP_PRICE_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_PRICE_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_PRICE_MASK 0x01
      #define CMD_HD_GET_EVENT_STATUS_REP_PRICE_BIT  0x01
      #define CMD_HD_GET_EVENT_STATUS_REP_PRICE_MSB  0
      #define CMD_HD_GET_EVENT_STATUS_REP_PRICE_LSB  0
      #define CMD_HD_GET_EVENT_STATUS_REP_PRICE_is_true (reply_buffer[13]&0x1)
      #define CMD_HD_GET_EVENT_STATUS_REP_PRICE_value (((reply_buffer[13]&0x1)))
      #define CMD_HD_GET_EVENT_STATUS_REP_ARMSGAVAIL_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_ARMSGAVAIL_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_ARMSGAVAIL_MASK 0x04
      #define CMD_HD_GET_EVENT_STATUS_REP_ARMSGAVAIL_BIT  0x04
      #define CMD_HD_GET_EVENT_STATUS_REP_ARMSGAVAIL_MSB  2
      #define CMD_HD_GET_EVENT_STATUS_REP_ARMSGAVAIL_LSB  2
      #define CMD_HD_GET_EVENT_STATUS_REP_ARMSGAVAIL_is_true (reply_buffer[14]&0x4)
      #define CMD_HD_GET_EVENT_STATUS_REP_ARMSGAVAIL_value (((reply_buffer[14]&0x4))>>2)
      #define CMD_HD_GET_EVENT_STATUS_REP_ARFRM0_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_ARFRM0_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_ARFRM0_MASK 0x02
      #define CMD_HD_GET_EVENT_STATUS_REP_ARFRM0_BIT  0x02
      #define CMD_HD_GET_EVENT_STATUS_REP_ARFRM0_MSB  1
      #define CMD_HD_GET_EVENT_STATUS_REP_ARFRM0_LSB  1
      #define CMD_HD_GET_EVENT_STATUS_REP_ARFRM0_is_true (reply_buffer[14]&0x2)
      #define CMD_HD_GET_EVENT_STATUS_REP_ARFRM0_value (((reply_buffer[14]&0x2))>>1)
      #define CMD_HD_GET_EVENT_STATUS_REP_ARFRM_TYPE bitfield
      #define CMD_HD_GET_EVENT_STATUS_REP_ARFRM_SIZE 1
      #define CMD_HD_GET_EVENT_STATUS_REP_ARFRM_MASK 0x01
      #define CMD_HD_GET_EVENT_STATUS_REP_ARFRM_BIT  0x01
      #define CMD_HD_GET_EVENT_STATUS_REP_ARFRM_MSB  0
      #define CMD_HD_GET_EVENT_STATUS_REP_ARFRM_LSB  0
      #define CMD_HD_GET_EVENT_STATUS_REP_ARFRM_is_true (reply_buffer[14]&0x1)
      #define CMD_HD_GET_EVENT_STATUS_REP_ARFRM_value (((reply_buffer[14]&0x1)))
      #define CMD_HD_GET_EVENT_STATUS_REP_ARFRAMECNT_TYPE u8
      #define CMD_HD_GET_EVENT_STATUS_REP_ARFRAMECNT_SIZE 8
      #define CMD_HD_GET_EVENT_STATUS_REP_ARFRAMECNT_MASK 0xFF
      #define CMD_HD_GET_EVENT_STATUS_REP_ARFRAMECNT_MSB  7
      #define CMD_HD_GET_EVENT_STATUS_REP_ARFRAMECNT_LSB  0
      #define CMD_HD_GET_EVENT_STATUS_REP_ARFRAMECNT_INDEX 0x0F
      #define CMD_HD_GET_EVENT_STATUS_REP_ARFRAMECNT_value (((reply_buffer[15])))
      #define CMD_HD_GET_EVENT_STATUS_REP_ARMSGID_TYPE u8
      #define CMD_HD_GET_EVENT_STATUS_REP_ARMSGID_SIZE 8
      #define CMD_HD_GET_EVENT_STATUS_REP_ARMSGID_MASK 0xFF
      #define CMD_HD_GET_EVENT_STATUS_REP_ARMSGID_MSB  7
      #define CMD_HD_GET_EVENT_STATUS_REP_ARMSGID_LSB  0
      #define CMD_HD_GET_EVENT_STATUS_REP_ARMSGID_INDEX 0x10
      #define CMD_HD_GET_EVENT_STATUS_REP_ARMSGID_value (((reply_buffer[16])))
      #define CMD_HD_GET_EVENT_STATUS_REP_ARCRC7_TYPE u8
      #define CMD_HD_GET_EVENT_STATUS_REP_ARCRC7_SIZE 8
      #define CMD_HD_GET_EVENT_STATUS_REP_ARCRC7_MASK 0xFF
      #define CMD_HD_GET_EVENT_STATUS_REP_ARCRC7_MSB  7
      #define CMD_HD_GET_EVENT_STATUS_REP_ARCRC7_LSB  0
      #define CMD_HD_GET_EVENT_STATUS_REP_ARCRC7_INDEX 0x11
      #define CMD_HD_GET_EVENT_STATUS_REP_ARCRC7_value (((reply_buffer[17])))

#define CMD_HD_GET_STATION_INFO  0x94
#define CMD_HD_GET_STATION_INFO_LENGTH 2
#define CMD_HD_GET_STATION_INFO_REP_LENGTH 7
//HD_GET_STATION_INFO ARGS
      #define CMD_HD_GET_STATION_INFO_ARG_INFO_SELECT_TYPE u8
      #define CMD_HD_GET_STATION_INFO_ARG_INFO_SELECT_SIZE 8
      #define CMD_HD_GET_STATION_INFO_ARG_INFO_SELECT_MASK 0xFF
      #define CMD_HD_GET_STATION_INFO_ARG_INFO_SELECT_MSB  7
      #define CMD_HD_GET_STATION_INFO_ARG_INFO_SELECT_LSB  0
      #define CMD_HD_GET_STATION_INFO_ARG_INFO_SELECT_INDEX 0x01
      #define CMD_HD_GET_STATION_INFO_ARG_INFO_SELECT_write_u8(x) (cmd_arg[1] = (x))
      #define CMD_HD_GET_STATION_INFO_ARG_INFO_SELECT_ENUM_RSVD 0
      #define CMD_HD_GET_STATION_INFO_ARG_INFO_SELECT_ENUM_STAMESSAGE 1
      #define CMD_HD_GET_STATION_INFO_ARG_INFO_SELECT_ENUM_TIMEZONE 2
      #define CMD_HD_GET_STATION_INFO_ARG_INFO_SELECT_ENUM_LEAPSECONDS 3
      #define CMD_HD_GET_STATION_INFO_ARG_INFO_SELECT_ENUM_UNISHORTNAME 4
      #define CMD_HD_GET_STATION_INFO_ARG_INFO_SELECT_ENUM_BASICSIS 5
      #define CMD_HD_GET_STATION_INFO_ARG_INFO_SELECT_ENUM_SLOGAN 6
//HD_GET_STATION_INFO REPLY
      #define CMD_HD_GET_STATION_INFO_REP_LENGTH_TYPE u16
      #define CMD_HD_GET_STATION_INFO_REP_LENGTH_SIZE 16
      #define CMD_HD_GET_STATION_INFO_REP_LENGTH_MASK 0xFFFF
      #define CMD_HD_GET_STATION_INFO_REP_LENGTH_MSB  15
      #define CMD_HD_GET_STATION_INFO_REP_LENGTH_LSB  0
      #define CMD_HD_GET_STATION_INFO_REP_LENGTH_INDEX 0x04
      #define CMD_HD_GET_STATION_INFO_REP_LENGTH_value (((reply_buffer_u16[2])))
      #define CMD_HD_GET_STATION_INFO_REP_DATA0_TYPE u8
      #define CMD_HD_GET_STATION_INFO_REP_DATA0_SIZE 8
      #define CMD_HD_GET_STATION_INFO_REP_DATA0_MASK 0xFF
      #define CMD_HD_GET_STATION_INFO_REP_DATA0_MSB  7
      #define CMD_HD_GET_STATION_INFO_REP_DATA0_LSB  0
      #define CMD_HD_GET_STATION_INFO_REP_DATA0_INDEX 0x06
      #define CMD_HD_GET_STATION_INFO_REP_DATA0_value (((reply_buffer[6])))

#define CMD_HD_GET_PSD_DECODE    0x95
#define CMD_HD_GET_PSD_DECODE_LENGTH 3
#define CMD_HD_GET_PSD_DECODE_REP_LENGTH 9
//HD_GET_PSD_DECODE ARGS
      #define CMD_HD_GET_PSD_DECODE_ARG_PROGRAM_TYPE u8
      #define CMD_HD_GET_PSD_DECODE_ARG_PROGRAM_SIZE 8
      #define CMD_HD_GET_PSD_DECODE_ARG_PROGRAM_MASK 0xFF
      #define CMD_HD_GET_PSD_DECODE_ARG_PROGRAM_MSB  7
      #define CMD_HD_GET_PSD_DECODE_ARG_PROGRAM_LSB  0
      #define CMD_HD_GET_PSD_DECODE_ARG_PROGRAM_INDEX 0x01
      #define CMD_HD_GET_PSD_DECODE_ARG_PROGRAM_write_u8(x) (cmd_arg[1] = (x))
      #define CMD_HD_GET_PSD_DECODE_ARG_PROGRAM_ENUM_MPS 0
      #define CMD_HD_GET_PSD_DECODE_ARG_PROGRAM_ENUM_SPS1 1
      #define CMD_HD_GET_PSD_DECODE_ARG_PROGRAM_ENUM_SPS2 2
      #define CMD_HD_GET_PSD_DECODE_ARG_PROGRAM_ENUM_SPS3 3
      #define CMD_HD_GET_PSD_DECODE_ARG_PROGRAM_ENUM_SPS4 4
      #define CMD_HD_GET_PSD_DECODE_ARG_PROGRAM_ENUM_SPS5 5
      #define CMD_HD_GET_PSD_DECODE_ARG_PROGRAM_ENUM_SPS6 6
      #define CMD_HD_GET_PSD_DECODE_ARG_PROGRAM_ENUM_SPS7 7
      #define CMD_HD_GET_PSD_DECODE_ARG_PROGRAM_ENUM_CURRENT 0xFF
      #define CMD_HD_GET_PSD_DECODE_ARG_FIELD_TYPE u8
      #define CMD_HD_GET_PSD_DECODE_ARG_FIELD_SIZE 8
      #define CMD_HD_GET_PSD_DECODE_ARG_FIELD_MASK 0xFF
      #define CMD_HD_GET_PSD_DECODE_ARG_FIELD_MSB  7
      #define CMD_HD_GET_PSD_DECODE_ARG_FIELD_LSB  0
      #define CMD_HD_GET_PSD_DECODE_ARG_FIELD_INDEX 0x02
      #define CMD_HD_GET_PSD_DECODE_ARG_FIELD_write_u8(x) (cmd_arg[2] = (x))
      #define CMD_HD_GET_PSD_DECODE_ARG_FIELD_ENUM_TITLE 0
      #define CMD_HD_GET_PSD_DECODE_ARG_FIELD_ENUM_ARTIST 1
      #define CMD_HD_GET_PSD_DECODE_ARG_FIELD_ENUM_ALBUM 2
      #define CMD_HD_GET_PSD_DECODE_ARG_FIELD_ENUM_GENRE 3
      #define CMD_HD_GET_PSD_DECODE_ARG_FIELD_ENUM_LANG 4
      #define CMD_HD_GET_PSD_DECODE_ARG_FIELD_ENUM_SHORT 5
      #define CMD_HD_GET_PSD_DECODE_ARG_FIELD_ENUM_TEXT 6
      #define CMD_HD_GET_PSD_DECODE_ARG_FIELD_ENUM_PRICE 8
      #define CMD_HD_GET_PSD_DECODE_ARG_FIELD_ENUM_VALID 9
      #define CMD_HD_GET_PSD_DECODE_ARG_FIELD_ENUM_URL 10
      #define CMD_HD_GET_PSD_DECODE_ARG_FIELD_ENUM_RECV 11
      #define CMD_HD_GET_PSD_DECODE_ARG_FIELD_ENUM_NAME 12
      #define CMD_HD_GET_PSD_DECODE_ARG_FIELD_ENUM_DESC 13
      #define CMD_HD_GET_PSD_DECODE_ARG_FIELD_ENUM_OWNER 14
      #define CMD_HD_GET_PSD_DECODE_ARG_FIELD_ENUM_ID 15
//HD_GET_PSD_DECODE REPLY
      #define CMD_HD_GET_PSD_DECODE_REP_DATATYPE_TYPE u8
      #define CMD_HD_GET_PSD_DECODE_REP_DATATYPE_SIZE 8
      #define CMD_HD_GET_PSD_DECODE_REP_DATATYPE_MASK 0xFF
      #define CMD_HD_GET_PSD_DECODE_REP_DATATYPE_MSB  7
      #define CMD_HD_GET_PSD_DECODE_REP_DATATYPE_LSB  0
      #define CMD_HD_GET_PSD_DECODE_REP_DATATYPE_INDEX 0x06
      #define CMD_HD_GET_PSD_DECODE_REP_DATATYPE_value (((reply_buffer[6])))
      #define CMD_HD_GET_PSD_DECODE_REP_DATATYPE_ENUM_ISO_IEC_8859 0
      #define CMD_HD_GET_PSD_DECODE_REP_DATATYPE_ENUM_ISO_IEC_10646 1
      #define CMD_HD_GET_PSD_DECODE_REP_LENGTH_TYPE u8
      #define CMD_HD_GET_PSD_DECODE_REP_LENGTH_SIZE 8
      #define CMD_HD_GET_PSD_DECODE_REP_LENGTH_MASK 0xFF
      #define CMD_HD_GET_PSD_DECODE_REP_LENGTH_MSB  7
      #define CMD_HD_GET_PSD_DECODE_REP_LENGTH_LSB  0
      #define CMD_HD_GET_PSD_DECODE_REP_LENGTH_INDEX 0x07
      #define CMD_HD_GET_PSD_DECODE_REP_LENGTH_value (((reply_buffer[7])))
      #define CMD_HD_GET_PSD_DECODE_REP_DATA0_TYPE u8
      #define CMD_HD_GET_PSD_DECODE_REP_DATA0_SIZE 8
      #define CMD_HD_GET_PSD_DECODE_REP_DATA0_MASK 0xFF
      #define CMD_HD_GET_PSD_DECODE_REP_DATA0_MSB  7
      #define CMD_HD_GET_PSD_DECODE_REP_DATA0_LSB  0
      #define CMD_HD_GET_PSD_DECODE_REP_DATA0_INDEX 0x08
      #define CMD_HD_GET_PSD_DECODE_REP_DATA0_value (((reply_buffer[8])))

#define CMD_HD_GET_ALERT_MSG     0x96
#define CMD_HD_GET_ALERT_MSG_LENGTH 2
#define CMD_HD_GET_ALERT_MSG_REP_LENGTH 7
//HD_GET_ALERT_MSG REPLY
      #define CMD_HD_GET_ALERT_MSG_REP_LENGTH_TYPE u16
      #define CMD_HD_GET_ALERT_MSG_REP_LENGTH_SIZE 16
      #define CMD_HD_GET_ALERT_MSG_REP_LENGTH_MASK 0xFFFF
      #define CMD_HD_GET_ALERT_MSG_REP_LENGTH_MSB  15
      #define CMD_HD_GET_ALERT_MSG_REP_LENGTH_LSB  0
      #define CMD_HD_GET_ALERT_MSG_REP_LENGTH_INDEX 0x04
      #define CMD_HD_GET_ALERT_MSG_REP_LENGTH_value (((reply_buffer_u16[2])))
      #define CMD_HD_GET_ALERT_MSG_REP_DATA0_TYPE u8
      #define CMD_HD_GET_ALERT_MSG_REP_DATA0_SIZE 8
      #define CMD_HD_GET_ALERT_MSG_REP_DATA0_MASK 0xFF
      #define CMD_HD_GET_ALERT_MSG_REP_DATA0_MSB  7
      #define CMD_HD_GET_ALERT_MSG_REP_DATA0_LSB  0
      #define CMD_HD_GET_ALERT_MSG_REP_DATA0_INDEX 0x06
      #define CMD_HD_GET_ALERT_MSG_REP_DATA0_value (((reply_buffer[6])))

#define CMD_HD_PLAY_ALERT_TONE   0x97
#define CMD_HD_PLAY_ALERT_TONE_LENGTH 2
#define CMD_HD_PLAY_ALERT_TONE_REP_LENGTH 4

#define CMD_HD_TEST_GET_BER_INFO 0x98
#define CMD_HD_TEST_GET_BER_INFO_LENGTH 2
#define CMD_HD_TEST_GET_BER_INFO_REP_LENGTH 44
//HD_TEST_GET_BER_INFO REPLY
      #define CMD_HD_TEST_GET_BER_INFO_REP_PIDS_BLOCK_ERRORS_TYPE u32
      #define CMD_HD_TEST_GET_BER_INFO_REP_PIDS_BLOCK_ERRORS_SIZE 32
      #define CMD_HD_TEST_GET_BER_INFO_REP_PIDS_BLOCK_ERRORS_MASK 0xFFFFFFFF
      #define CMD_HD_TEST_GET_BER_INFO_REP_PIDS_BLOCK_ERRORS_MSB  31
      #define CMD_HD_TEST_GET_BER_INFO_REP_PIDS_BLOCK_ERRORS_LSB  0
      #define CMD_HD_TEST_GET_BER_INFO_REP_PIDS_BLOCK_ERRORS_INDEX 0x04
      #define CMD_HD_TEST_GET_BER_INFO_REP_PIDS_BLOCK_ERRORS_value (((reply_buffer_u32[1])))
      #define CMD_HD_TEST_GET_BER_INFO_REP_PIDS_BLOCKS_TESTED_TYPE u32
      #define CMD_HD_TEST_GET_BER_INFO_REP_PIDS_BLOCKS_TESTED_SIZE 32
      #define CMD_HD_TEST_GET_BER_INFO_REP_PIDS_BLOCKS_TESTED_MASK 0xFFFFFFFF
      #define CMD_HD_TEST_GET_BER_INFO_REP_PIDS_BLOCKS_TESTED_MSB  31
      #define CMD_HD_TEST_GET_BER_INFO_REP_PIDS_BLOCKS_TESTED_LSB  0
      #define CMD_HD_TEST_GET_BER_INFO_REP_PIDS_BLOCKS_TESTED_INDEX 0x08
      #define CMD_HD_TEST_GET_BER_INFO_REP_PIDS_BLOCKS_TESTED_value (((reply_buffer_u32[2])))
      #define CMD_HD_TEST_GET_BER_INFO_REP_PIDS_BIT_ERRORS_TYPE u32
      #define CMD_HD_TEST_GET_BER_INFO_REP_PIDS_BIT_ERRORS_SIZE 32
      #define CMD_HD_TEST_GET_BER_INFO_REP_PIDS_BIT_ERRORS_MASK 0xFFFFFFFF
      #define CMD_HD_TEST_GET_BER_INFO_REP_PIDS_BIT_ERRORS_MSB  31
      #define CMD_HD_TEST_GET_BER_INFO_REP_PIDS_BIT_ERRORS_LSB  0
      #define CMD_HD_TEST_GET_BER_INFO_REP_PIDS_BIT_ERRORS_INDEX 0x0C
      #define CMD_HD_TEST_GET_BER_INFO_REP_PIDS_BIT_ERRORS_value (((reply_buffer_u32[3])))
      #define CMD_HD_TEST_GET_BER_INFO_REP_PIDS_BITS_TESTED_TYPE u32
      #define CMD_HD_TEST_GET_BER_INFO_REP_PIDS_BITS_TESTED_SIZE 32
      #define CMD_HD_TEST_GET_BER_INFO_REP_PIDS_BITS_TESTED_MASK 0xFFFFFFFF
      #define CMD_HD_TEST_GET_BER_INFO_REP_PIDS_BITS_TESTED_MSB  31
      #define CMD_HD_TEST_GET_BER_INFO_REP_PIDS_BITS_TESTED_LSB  0
      #define CMD_HD_TEST_GET_BER_INFO_REP_PIDS_BITS_TESTED_INDEX 0x10
      #define CMD_HD_TEST_GET_BER_INFO_REP_PIDS_BITS_TESTED_value (((reply_buffer_u32[4])))
      #define CMD_HD_TEST_GET_BER_INFO_REP_P3_BIT_ERRORS_TYPE u32
      #define CMD_HD_TEST_GET_BER_INFO_REP_P3_BIT_ERRORS_SIZE 32
      #define CMD_HD_TEST_GET_BER_INFO_REP_P3_BIT_ERRORS_MASK 0xFFFFFFFF
      #define CMD_HD_TEST_GET_BER_INFO_REP_P3_BIT_ERRORS_MSB  31
      #define CMD_HD_TEST_GET_BER_INFO_REP_P3_BIT_ERRORS_LSB  0
      #define CMD_HD_TEST_GET_BER_INFO_REP_P3_BIT_ERRORS_INDEX 0x14
      #define CMD_HD_TEST_GET_BER_INFO_REP_P3_BIT_ERRORS_value (((reply_buffer_u32[5])))
      #define CMD_HD_TEST_GET_BER_INFO_REP_P3_BITS_TESTED_TYPE u32
      #define CMD_HD_TEST_GET_BER_INFO_REP_P3_BITS_TESTED_SIZE 32
      #define CMD_HD_TEST_GET_BER_INFO_REP_P3_BITS_TESTED_MASK 0xFFFFFFFF
      #define CMD_HD_TEST_GET_BER_INFO_REP_P3_BITS_TESTED_MSB  31
      #define CMD_HD_TEST_GET_BER_INFO_REP_P3_BITS_TESTED_LSB  0
      #define CMD_HD_TEST_GET_BER_INFO_REP_P3_BITS_TESTED_INDEX 0x18
      #define CMD_HD_TEST_GET_BER_INFO_REP_P3_BITS_TESTED_value (((reply_buffer_u32[6])))
      #define CMD_HD_TEST_GET_BER_INFO_REP_P2_BIT_ERRORS_TYPE u32
      #define CMD_HD_TEST_GET_BER_INFO_REP_P2_BIT_ERRORS_SIZE 32
      #define CMD_HD_TEST_GET_BER_INFO_REP_P2_BIT_ERRORS_MASK 0xFFFFFFFF
      #define CMD_HD_TEST_GET_BER_INFO_REP_P2_BIT_ERRORS_MSB  31
      #define CMD_HD_TEST_GET_BER_INFO_REP_P2_BIT_ERRORS_LSB  0
      #define CMD_HD_TEST_GET_BER_INFO_REP_P2_BIT_ERRORS_INDEX 0x1C
      #define CMD_HD_TEST_GET_BER_INFO_REP_P2_BIT_ERRORS_value (((reply_buffer_u32[7])))
      #define CMD_HD_TEST_GET_BER_INFO_REP_P2_BITS_TESTED_TYPE u32
      #define CMD_HD_TEST_GET_BER_INFO_REP_P2_BITS_TESTED_SIZE 32
      #define CMD_HD_TEST_GET_BER_INFO_REP_P2_BITS_TESTED_MASK 0xFFFFFFFF
      #define CMD_HD_TEST_GET_BER_INFO_REP_P2_BITS_TESTED_MSB  31
      #define CMD_HD_TEST_GET_BER_INFO_REP_P2_BITS_TESTED_LSB  0
      #define CMD_HD_TEST_GET_BER_INFO_REP_P2_BITS_TESTED_INDEX 0x20
      #define CMD_HD_TEST_GET_BER_INFO_REP_P2_BITS_TESTED_value (((reply_buffer_u32[8])))
      #define CMD_HD_TEST_GET_BER_INFO_REP_P1_BIT_ERRORS_TYPE u32
      #define CMD_HD_TEST_GET_BER_INFO_REP_P1_BIT_ERRORS_SIZE 32
      #define CMD_HD_TEST_GET_BER_INFO_REP_P1_BIT_ERRORS_MASK 0xFFFFFFFF
      #define CMD_HD_TEST_GET_BER_INFO_REP_P1_BIT_ERRORS_MSB  31
      #define CMD_HD_TEST_GET_BER_INFO_REP_P1_BIT_ERRORS_LSB  0
      #define CMD_HD_TEST_GET_BER_INFO_REP_P1_BIT_ERRORS_INDEX 0x24
      #define CMD_HD_TEST_GET_BER_INFO_REP_P1_BIT_ERRORS_value (((reply_buffer_u32[9])))
      #define CMD_HD_TEST_GET_BER_INFO_REP_P1_BITS_TESTED_TYPE u32
      #define CMD_HD_TEST_GET_BER_INFO_REP_P1_BITS_TESTED_SIZE 32
      #define CMD_HD_TEST_GET_BER_INFO_REP_P1_BITS_TESTED_MASK 0xFFFFFFFF
      #define CMD_HD_TEST_GET_BER_INFO_REP_P1_BITS_TESTED_MSB  31
      #define CMD_HD_TEST_GET_BER_INFO_REP_P1_BITS_TESTED_LSB  0
      #define CMD_HD_TEST_GET_BER_INFO_REP_P1_BITS_TESTED_INDEX 0x28
      #define CMD_HD_TEST_GET_BER_INFO_REP_P1_BITS_TESTED_value (((reply_buffer_u32[10])))

#define CMD_HD_SET_ENABLED_PORTS 0x99
#define CMD_HD_SET_ENABLED_PORTS_LENGTH 4
#define CMD_HD_SET_ENABLED_PORTS_REP_LENGTH 4
//HD_SET_ENABLED_PORTS ARGS
      #define CMD_HD_SET_ENABLED_PORTS_ARG_LENGTH_TYPE u8
      #define CMD_HD_SET_ENABLED_PORTS_ARG_LENGTH_SIZE 8
      #define CMD_HD_SET_ENABLED_PORTS_ARG_LENGTH_MASK 0xFF
      #define CMD_HD_SET_ENABLED_PORTS_ARG_LENGTH_MSB  7
      #define CMD_HD_SET_ENABLED_PORTS_ARG_LENGTH_LSB  0
      #define CMD_HD_SET_ENABLED_PORTS_ARG_LENGTH_INDEX 0x01
      #define CMD_HD_SET_ENABLED_PORTS_ARG_LENGTH_write_u8(x) (cmd_arg[1] = (x))
      #define CMD_HD_SET_ENABLED_PORTS_ARG_DATA_0_TYPE u16
      #define CMD_HD_SET_ENABLED_PORTS_ARG_DATA_0_SIZE 16
      #define CMD_HD_SET_ENABLED_PORTS_ARG_DATA_0_MASK 0xFFFF
      #define CMD_HD_SET_ENABLED_PORTS_ARG_DATA_0_MSB  15
      #define CMD_HD_SET_ENABLED_PORTS_ARG_DATA_0_LSB  0
      #define CMD_HD_SET_ENABLED_PORTS_ARG_DATA_0_INDEX 0x02
      #define CMD_HD_SET_ENABLED_PORTS_ARG_DATA_0_write_u16(x) (cmd_arg_u16[1] = (x))

#define CMD_HD_GET_ENABLED_PORTS 0x9A
#define CMD_HD_GET_ENABLED_PORTS_LENGTH 2
#define CMD_HD_GET_ENABLED_PORTS_REP_LENGTH 8
//HD_GET_ENABLED_PORTS REPLY
      #define CMD_HD_GET_ENABLED_PORTS_REP_LENGTH_TYPE u8
      #define CMD_HD_GET_ENABLED_PORTS_REP_LENGTH_SIZE 8
      #define CMD_HD_GET_ENABLED_PORTS_REP_LENGTH_MASK 0xFF
      #define CMD_HD_GET_ENABLED_PORTS_REP_LENGTH_MSB  7
      #define CMD_HD_GET_ENABLED_PORTS_REP_LENGTH_LSB  0
      #define CMD_HD_GET_ENABLED_PORTS_REP_LENGTH_INDEX 0x04
      #define CMD_HD_GET_ENABLED_PORTS_REP_LENGTH_value (((reply_buffer[4])))
      #define CMD_HD_GET_ENABLED_PORTS_REP_DATA_0_TYPE u16
      #define CMD_HD_GET_ENABLED_PORTS_REP_DATA_0_SIZE 16
      #define CMD_HD_GET_ENABLED_PORTS_REP_DATA_0_MASK 0xFFFF
      #define CMD_HD_GET_ENABLED_PORTS_REP_DATA_0_MSB  15
      #define CMD_HD_GET_ENABLED_PORTS_REP_DATA_0_LSB  0
      #define CMD_HD_GET_ENABLED_PORTS_REP_DATA_0_INDEX 0x06
      #define CMD_HD_GET_ENABLED_PORTS_REP_DATA_0_value (((reply_buffer_u16[3])))

#define CMD_HD_IDLE              0x9B
#define CMD_HD_IDLE_LENGTH 2
#define CMD_HD_IDLE_REP_LENGTH 4

#define CMD_HD_ACF_STATUS        0x9C
#define CMD_HD_ACF_STATUS_LENGTH 2
#define CMD_HD_ACF_STATUS_REP_LENGTH 10
//HD_ACF_STATUS ARGS
      #define CMD_HD_ACF_STATUS_ARG_ACFACK_TYPE bitfield
      #define CMD_HD_ACF_STATUS_ARG_ACFACK_SIZE 1
      #define CMD_HD_ACF_STATUS_ARG_ACFACK_MASK 0x01
      #define CMD_HD_ACF_STATUS_ARG_ACFACK_BIT  0x01
      #define CMD_HD_ACF_STATUS_ARG_ACFACK_MSB  0
      #define CMD_HD_ACF_STATUS_ARG_ACFACK_LSB  0
      #define CMD_HD_ACF_STATUS_ARG_ACFACK_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x1) | (((x)<<0)&0x1)))
//HD_ACF_STATUS REPLY
      #define CMD_HD_ACF_STATUS_REP_STEREO_SEP_INT_TYPE bitfield
      #define CMD_HD_ACF_STATUS_REP_STEREO_SEP_INT_SIZE 1
      #define CMD_HD_ACF_STATUS_REP_STEREO_SEP_INT_MASK 0x04
      #define CMD_HD_ACF_STATUS_REP_STEREO_SEP_INT_BIT  0x04
      #define CMD_HD_ACF_STATUS_REP_STEREO_SEP_INT_MSB  2
      #define CMD_HD_ACF_STATUS_REP_STEREO_SEP_INT_LSB  2
      #define CMD_HD_ACF_STATUS_REP_STEREO_SEP_INT_is_true (reply_buffer[4]&0x4)
      #define CMD_HD_ACF_STATUS_REP_STEREO_SEP_INT_value (((reply_buffer[4]&0x4))>>2)
      #define CMD_HD_ACF_STATUS_REP_AUDIO_BW_INT_TYPE bitfield
      #define CMD_HD_ACF_STATUS_REP_AUDIO_BW_INT_SIZE 1
      #define CMD_HD_ACF_STATUS_REP_AUDIO_BW_INT_MASK 0x02
      #define CMD_HD_ACF_STATUS_REP_AUDIO_BW_INT_BIT  0x02
      #define CMD_HD_ACF_STATUS_REP_AUDIO_BW_INT_MSB  1
      #define CMD_HD_ACF_STATUS_REP_AUDIO_BW_INT_LSB  1
      #define CMD_HD_ACF_STATUS_REP_AUDIO_BW_INT_is_true (reply_buffer[4]&0x2)
      #define CMD_HD_ACF_STATUS_REP_AUDIO_BW_INT_value (((reply_buffer[4]&0x2))>>1)
      #define CMD_HD_ACF_STATUS_REP_COMF_NOISE_INT_TYPE bitfield
      #define CMD_HD_ACF_STATUS_REP_COMF_NOISE_INT_SIZE 1
      #define CMD_HD_ACF_STATUS_REP_COMF_NOISE_INT_MASK 0x01
      #define CMD_HD_ACF_STATUS_REP_COMF_NOISE_INT_BIT  0x01
      #define CMD_HD_ACF_STATUS_REP_COMF_NOISE_INT_MSB  0
      #define CMD_HD_ACF_STATUS_REP_COMF_NOISE_INT_LSB  0
      #define CMD_HD_ACF_STATUS_REP_COMF_NOISE_INT_is_true (reply_buffer[4]&0x1)
      #define CMD_HD_ACF_STATUS_REP_COMF_NOISE_INT_value (((reply_buffer[4]&0x1)))
      #define CMD_HD_ACF_STATUS_REP_STEREO_SEP_CONV_TYPE bitfield
      #define CMD_HD_ACF_STATUS_REP_STEREO_SEP_CONV_SIZE 1
      #define CMD_HD_ACF_STATUS_REP_STEREO_SEP_CONV_MASK 0x40
      #define CMD_HD_ACF_STATUS_REP_STEREO_SEP_CONV_BIT  0x40
      #define CMD_HD_ACF_STATUS_REP_STEREO_SEP_CONV_MSB  6
      #define CMD_HD_ACF_STATUS_REP_STEREO_SEP_CONV_LSB  6
      #define CMD_HD_ACF_STATUS_REP_STEREO_SEP_CONV_is_true (reply_buffer[5]&0x40)
      #define CMD_HD_ACF_STATUS_REP_STEREO_SEP_CONV_value (((reply_buffer[5]&0x40))>>6)
      #define CMD_HD_ACF_STATUS_REP_AUDIO_BW_CONV_TYPE bitfield
      #define CMD_HD_ACF_STATUS_REP_AUDIO_BW_CONV_SIZE 1
      #define CMD_HD_ACF_STATUS_REP_AUDIO_BW_CONV_MASK 0x20
      #define CMD_HD_ACF_STATUS_REP_AUDIO_BW_CONV_BIT  0x20
      #define CMD_HD_ACF_STATUS_REP_AUDIO_BW_CONV_MSB  5
      #define CMD_HD_ACF_STATUS_REP_AUDIO_BW_CONV_LSB  5
      #define CMD_HD_ACF_STATUS_REP_AUDIO_BW_CONV_is_true (reply_buffer[5]&0x20)
      #define CMD_HD_ACF_STATUS_REP_AUDIO_BW_CONV_value (((reply_buffer[5]&0x20))>>5)
      #define CMD_HD_ACF_STATUS_REP_COMF_NOISE_CONV_TYPE bitfield
      #define CMD_HD_ACF_STATUS_REP_COMF_NOISE_CONV_SIZE 1
      #define CMD_HD_ACF_STATUS_REP_COMF_NOISE_CONV_MASK 0x10
      #define CMD_HD_ACF_STATUS_REP_COMF_NOISE_CONV_BIT  0x10
      #define CMD_HD_ACF_STATUS_REP_COMF_NOISE_CONV_MSB  4
      #define CMD_HD_ACF_STATUS_REP_COMF_NOISE_CONV_LSB  4
      #define CMD_HD_ACF_STATUS_REP_COMF_NOISE_CONV_is_true (reply_buffer[5]&0x10)
      #define CMD_HD_ACF_STATUS_REP_COMF_NOISE_CONV_value (((reply_buffer[5]&0x10))>>4)
      #define CMD_HD_ACF_STATUS_REP_STEREO_SEP_STATE_TYPE bitfield
      #define CMD_HD_ACF_STATUS_REP_STEREO_SEP_STATE_SIZE 1
      #define CMD_HD_ACF_STATUS_REP_STEREO_SEP_STATE_MASK 0x04
      #define CMD_HD_ACF_STATUS_REP_STEREO_SEP_STATE_BIT  0x04
      #define CMD_HD_ACF_STATUS_REP_STEREO_SEP_STATE_MSB  2
      #define CMD_HD_ACF_STATUS_REP_STEREO_SEP_STATE_LSB  2
      #define CMD_HD_ACF_STATUS_REP_STEREO_SEP_STATE_is_true (reply_buffer[5]&0x4)
      #define CMD_HD_ACF_STATUS_REP_STEREO_SEP_STATE_value (((reply_buffer[5]&0x4))>>2)
      #define CMD_HD_ACF_STATUS_REP_AUDIO_BW_STATE_TYPE bitfield
      #define CMD_HD_ACF_STATUS_REP_AUDIO_BW_STATE_SIZE 1
      #define CMD_HD_ACF_STATUS_REP_AUDIO_BW_STATE_MASK 0x02
      #define CMD_HD_ACF_STATUS_REP_AUDIO_BW_STATE_BIT  0x02
      #define CMD_HD_ACF_STATUS_REP_AUDIO_BW_STATE_MSB  1
      #define CMD_HD_ACF_STATUS_REP_AUDIO_BW_STATE_LSB  1
      #define CMD_HD_ACF_STATUS_REP_AUDIO_BW_STATE_is_true (reply_buffer[5]&0x2)
      #define CMD_HD_ACF_STATUS_REP_AUDIO_BW_STATE_value (((reply_buffer[5]&0x2))>>1)
      #define CMD_HD_ACF_STATUS_REP_COMF_NOISE_STATE_TYPE bitfield
      #define CMD_HD_ACF_STATUS_REP_COMF_NOISE_STATE_SIZE 1
      #define CMD_HD_ACF_STATUS_REP_COMF_NOISE_STATE_MASK 0x01
      #define CMD_HD_ACF_STATUS_REP_COMF_NOISE_STATE_BIT  0x01
      #define CMD_HD_ACF_STATUS_REP_COMF_NOISE_STATE_MSB  0
      #define CMD_HD_ACF_STATUS_REP_COMF_NOISE_STATE_LSB  0
      #define CMD_HD_ACF_STATUS_REP_COMF_NOISE_STATE_is_true (reply_buffer[5]&0x1)
      #define CMD_HD_ACF_STATUS_REP_COMF_NOISE_STATE_value (((reply_buffer[5]&0x1)))
      #define CMD_HD_ACF_STATUS_REP_COMFORT_NOISE_LEVEL_TYPE u16
      #define CMD_HD_ACF_STATUS_REP_COMFORT_NOISE_LEVEL_SIZE 16
      #define CMD_HD_ACF_STATUS_REP_COMFORT_NOISE_LEVEL_MASK 0xFFFF
      #define CMD_HD_ACF_STATUS_REP_COMFORT_NOISE_LEVEL_MSB  15
      #define CMD_HD_ACF_STATUS_REP_COMFORT_NOISE_LEVEL_LSB  0
      #define CMD_HD_ACF_STATUS_REP_COMFORT_NOISE_LEVEL_INDEX 0x06
      #define CMD_HD_ACF_STATUS_REP_COMFORT_NOISE_LEVEL_value (((reply_buffer_u16[3])))
      #define CMD_HD_ACF_STATUS_REP_AUDIO_BW_TYPE u8
      #define CMD_HD_ACF_STATUS_REP_AUDIO_BW_SIZE 8
      #define CMD_HD_ACF_STATUS_REP_AUDIO_BW_MASK 0xFF
      #define CMD_HD_ACF_STATUS_REP_AUDIO_BW_MSB  7
      #define CMD_HD_ACF_STATUS_REP_AUDIO_BW_LSB  0
      #define CMD_HD_ACF_STATUS_REP_AUDIO_BW_INDEX 0x08
      #define CMD_HD_ACF_STATUS_REP_AUDIO_BW_value (((reply_buffer[8])))
      #define CMD_HD_ACF_STATUS_REP_STEREO_SEP_TYPE u8
      #define CMD_HD_ACF_STATUS_REP_STEREO_SEP_SIZE 8
      #define CMD_HD_ACF_STATUS_REP_STEREO_SEP_MASK 0xFF
      #define CMD_HD_ACF_STATUS_REP_STEREO_SEP_MSB  7
      #define CMD_HD_ACF_STATUS_REP_STEREO_SEP_LSB  0
      #define CMD_HD_ACF_STATUS_REP_STEREO_SEP_INDEX 0x09
      #define CMD_HD_ACF_STATUS_REP_STEREO_SEP_value (((reply_buffer[9])))

#define CMD_DAB_TUNE_FREQ        0xB0
#define CMD_DAB_TUNE_FREQ_LENGTH 6
#define CMD_DAB_TUNE_FREQ_REP_LENGTH 4
//DAB_TUNE_FREQ ARGS
      #define CMD_DAB_TUNE_FREQ_ARG_INJECTION_TYPE bitfield
      #define CMD_DAB_TUNE_FREQ_ARG_INJECTION_SIZE 2
      #define CMD_DAB_TUNE_FREQ_ARG_INJECTION_MASK 0x03
      #define CMD_DAB_TUNE_FREQ_ARG_INJECTION_MSB  1
      #define CMD_DAB_TUNE_FREQ_ARG_INJECTION_LSB  0
      #define CMD_DAB_TUNE_FREQ_ARG_INJECTION_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x3) | (((x)<<0)&0x3)))
      #define CMD_DAB_TUNE_FREQ_ARG_INJECTION_ENUM_FULL_AUTO 0
      #define CMD_DAB_TUNE_FREQ_ARG_INJECTION_ENUM_LOW_SIDE 1
      #define CMD_DAB_TUNE_FREQ_ARG_INJECTION_ENUM_HIGH_SIDE 2
      #define CMD_DAB_TUNE_FREQ_ARG_FREQ_INDEX_TYPE u8
      #define CMD_DAB_TUNE_FREQ_ARG_FREQ_INDEX_SIZE 8
      #define CMD_DAB_TUNE_FREQ_ARG_FREQ_INDEX_MASK 0xFF
      #define CMD_DAB_TUNE_FREQ_ARG_FREQ_INDEX_MSB  7
      #define CMD_DAB_TUNE_FREQ_ARG_FREQ_INDEX_LSB  0
      #define CMD_DAB_TUNE_FREQ_ARG_FREQ_INDEX_INDEX 0x02
      #define CMD_DAB_TUNE_FREQ_ARG_FREQ_INDEX_write_u8(x) (cmd_arg[2] = (x))
      #define CMD_DAB_TUNE_FREQ_ARG_ANTCAP_TYPE u16
      #define CMD_DAB_TUNE_FREQ_ARG_ANTCAP_SIZE 16
      #define CMD_DAB_TUNE_FREQ_ARG_ANTCAP_MASK 0xFFFF
      #define CMD_DAB_TUNE_FREQ_ARG_ANTCAP_MSB  15
      #define CMD_DAB_TUNE_FREQ_ARG_ANTCAP_LSB  0
      #define CMD_DAB_TUNE_FREQ_ARG_ANTCAP_INDEX 0x04
      #define CMD_DAB_TUNE_FREQ_ARG_ANTCAP_write_u16(x) (cmd_arg_u16[2] = (x))
      #define CMD_DAB_TUNE_FREQ_ARG_ANTCAP_MIN 0
      #define CMD_DAB_TUNE_FREQ_ARG_ANTCAP_MAX 128
      #define CMD_DAB_TUNE_FREQ_ARG_ANTCAP_ENUM_AUTO 0


#define CMD_DAB_DIGRAD_STATUS    0xB2
#define CMD_DAB_DIGRAD_STATUS_LENGTH 2
#define CMD_DAB_DIGRAD_STATUS_REP_LENGTH 23
//DAB_DIGRAD_STATUS ARGS
      #define CMD_DAB_DIGRAD_STATUS_ARG_DIGRAD_ACK_TYPE bitfield
      #define CMD_DAB_DIGRAD_STATUS_ARG_DIGRAD_ACK_SIZE 1
      #define CMD_DAB_DIGRAD_STATUS_ARG_DIGRAD_ACK_MASK 0x08
      #define CMD_DAB_DIGRAD_STATUS_ARG_DIGRAD_ACK_BIT  0x08
      #define CMD_DAB_DIGRAD_STATUS_ARG_DIGRAD_ACK_MSB  3
      #define CMD_DAB_DIGRAD_STATUS_ARG_DIGRAD_ACK_LSB  3
      #define CMD_DAB_DIGRAD_STATUS_ARG_DIGRAD_ACK_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x8) | (((x)<<3)&0x8)))
      #define CMD_DAB_DIGRAD_STATUS_ARG_ATTUNE_TYPE bitfield
      #define CMD_DAB_DIGRAD_STATUS_ARG_ATTUNE_SIZE 1
      #define CMD_DAB_DIGRAD_STATUS_ARG_ATTUNE_MASK 0x04
      #define CMD_DAB_DIGRAD_STATUS_ARG_ATTUNE_BIT  0x04
      #define CMD_DAB_DIGRAD_STATUS_ARG_ATTUNE_MSB  2
      #define CMD_DAB_DIGRAD_STATUS_ARG_ATTUNE_LSB  2
      #define CMD_DAB_DIGRAD_STATUS_ARG_ATTUNE_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x4) | (((x)<<2)&0x4)))
      #define CMD_DAB_DIGRAD_STATUS_ARG_ATTUNE_ENUM_CUR_STATUS 0
      #define CMD_DAB_DIGRAD_STATUS_ARG_ATTUNE_ENUM_ATTUNE_STATUS 1
      #define CMD_DAB_DIGRAD_STATUS_ARG_FIBERR_ACK_TYPE bitfield
      #define CMD_DAB_DIGRAD_STATUS_ARG_FIBERR_ACK_SIZE 1
      #define CMD_DAB_DIGRAD_STATUS_ARG_FIBERR_ACK_MASK 0x02
      #define CMD_DAB_DIGRAD_STATUS_ARG_FIBERR_ACK_BIT  0x02
      #define CMD_DAB_DIGRAD_STATUS_ARG_FIBERR_ACK_MSB  1
      #define CMD_DAB_DIGRAD_STATUS_ARG_FIBERR_ACK_LSB  1
      #define CMD_DAB_DIGRAD_STATUS_ARG_FIBERR_ACK_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x2) | (((x)<<1)&0x2)))
      #define CMD_DAB_DIGRAD_STATUS_ARG_STC_ACK_TYPE bitfield
      #define CMD_DAB_DIGRAD_STATUS_ARG_STC_ACK_SIZE 1
      #define CMD_DAB_DIGRAD_STATUS_ARG_STC_ACK_MASK 0x01
      #define CMD_DAB_DIGRAD_STATUS_ARG_STC_ACK_BIT  0x01
      #define CMD_DAB_DIGRAD_STATUS_ARG_STC_ACK_MSB  0
      #define CMD_DAB_DIGRAD_STATUS_ARG_STC_ACK_LSB  0
      #define CMD_DAB_DIGRAD_STATUS_ARG_STC_ACK_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x1) | (((x)<<0)&0x1)))
//DAB_DIGRAD_STATUS REPLY
      #define CMD_DAB_DIGRAD_STATUS_REP_FICERRINT_TYPE bitfield
      #define CMD_DAB_DIGRAD_STATUS_REP_FICERRINT_SIZE 1
      #define CMD_DAB_DIGRAD_STATUS_REP_FICERRINT_MASK 0x08
      #define CMD_DAB_DIGRAD_STATUS_REP_FICERRINT_BIT  0x08
      #define CMD_DAB_DIGRAD_STATUS_REP_FICERRINT_MSB  3
      #define CMD_DAB_DIGRAD_STATUS_REP_FICERRINT_LSB  3
      #define CMD_DAB_DIGRAD_STATUS_REP_FICERRINT_is_true (reply_buffer[4]&0x8)
      #define CMD_DAB_DIGRAD_STATUS_REP_FICERRINT_value (((reply_buffer[4]&0x8))>>3)
      #define CMD_DAB_DIGRAD_STATUS_REP_ACQINT_TYPE bitfield
      #define CMD_DAB_DIGRAD_STATUS_REP_ACQINT_SIZE 1
      #define CMD_DAB_DIGRAD_STATUS_REP_ACQINT_MASK 0x04
      #define CMD_DAB_DIGRAD_STATUS_REP_ACQINT_BIT  0x04
      #define CMD_DAB_DIGRAD_STATUS_REP_ACQINT_MSB  2
      #define CMD_DAB_DIGRAD_STATUS_REP_ACQINT_LSB  2
      #define CMD_DAB_DIGRAD_STATUS_REP_ACQINT_is_true (reply_buffer[4]&0x4)
      #define CMD_DAB_DIGRAD_STATUS_REP_ACQINT_value (((reply_buffer[4]&0x4))>>2)
      #define CMD_DAB_DIGRAD_STATUS_REP_RSSIHINT_TYPE bitfield
      #define CMD_DAB_DIGRAD_STATUS_REP_RSSIHINT_SIZE 1
      #define CMD_DAB_DIGRAD_STATUS_REP_RSSIHINT_MASK 0x02
      #define CMD_DAB_DIGRAD_STATUS_REP_RSSIHINT_BIT  0x02
      #define CMD_DAB_DIGRAD_STATUS_REP_RSSIHINT_MSB  1
      #define CMD_DAB_DIGRAD_STATUS_REP_RSSIHINT_LSB  1
      #define CMD_DAB_DIGRAD_STATUS_REP_RSSIHINT_is_true (reply_buffer[4]&0x2)
      #define CMD_DAB_DIGRAD_STATUS_REP_RSSIHINT_value (((reply_buffer[4]&0x2))>>1)
      #define CMD_DAB_DIGRAD_STATUS_REP_RSSILINT_TYPE bitfield
      #define CMD_DAB_DIGRAD_STATUS_REP_RSSILINT_SIZE 1
      #define CMD_DAB_DIGRAD_STATUS_REP_RSSILINT_MASK 0x01
      #define CMD_DAB_DIGRAD_STATUS_REP_RSSILINT_BIT  0x01
      #define CMD_DAB_DIGRAD_STATUS_REP_RSSILINT_MSB  0
      #define CMD_DAB_DIGRAD_STATUS_REP_RSSILINT_LSB  0
      #define CMD_DAB_DIGRAD_STATUS_REP_RSSILINT_is_true (reply_buffer[4]&0x1)
      #define CMD_DAB_DIGRAD_STATUS_REP_RSSILINT_value (((reply_buffer[4]&0x1)))
      #define CMD_DAB_DIGRAD_STATUS_REP_FICERR_TYPE bitfield
      #define CMD_DAB_DIGRAD_STATUS_REP_FICERR_SIZE 1
      #define CMD_DAB_DIGRAD_STATUS_REP_FICERR_MASK 0x08
      #define CMD_DAB_DIGRAD_STATUS_REP_FICERR_BIT  0x08
      #define CMD_DAB_DIGRAD_STATUS_REP_FICERR_MSB  3
      #define CMD_DAB_DIGRAD_STATUS_REP_FICERR_LSB  3
      #define CMD_DAB_DIGRAD_STATUS_REP_FICERR_is_true (reply_buffer[5]&0x8)
      #define CMD_DAB_DIGRAD_STATUS_REP_FICERR_value (((reply_buffer[5]&0x8))>>3)
      #define CMD_DAB_DIGRAD_STATUS_REP_ACQ_TYPE bitfield
      #define CMD_DAB_DIGRAD_STATUS_REP_ACQ_SIZE 1
      #define CMD_DAB_DIGRAD_STATUS_REP_ACQ_MASK 0x04
      #define CMD_DAB_DIGRAD_STATUS_REP_ACQ_BIT  0x04
      #define CMD_DAB_DIGRAD_STATUS_REP_ACQ_MSB  2
      #define CMD_DAB_DIGRAD_STATUS_REP_ACQ_LSB  2
      #define CMD_DAB_DIGRAD_STATUS_REP_ACQ_is_true (reply_buffer[5]&0x4)
      #define CMD_DAB_DIGRAD_STATUS_REP_ACQ_value (((reply_buffer[5]&0x4))>>2)
      #define CMD_DAB_DIGRAD_STATUS_REP_VALID_TYPE bitfield
      #define CMD_DAB_DIGRAD_STATUS_REP_VALID_SIZE 1
      #define CMD_DAB_DIGRAD_STATUS_REP_VALID_MASK 0x01
      #define CMD_DAB_DIGRAD_STATUS_REP_VALID_BIT  0x01
      #define CMD_DAB_DIGRAD_STATUS_REP_VALID_MSB  0
      #define CMD_DAB_DIGRAD_STATUS_REP_VALID_LSB  0
      #define CMD_DAB_DIGRAD_STATUS_REP_VALID_is_true (reply_buffer[5]&0x1)
      #define CMD_DAB_DIGRAD_STATUS_REP_VALID_value (((reply_buffer[5]&0x1)))
      #define CMD_DAB_DIGRAD_STATUS_REP_RSSI_TYPE i8
      #define CMD_DAB_DIGRAD_STATUS_REP_RSSI_SIZE 8
      #define CMD_DAB_DIGRAD_STATUS_REP_RSSI_MASK 0xFF
      #define CMD_DAB_DIGRAD_STATUS_REP_RSSI_MSB  7
      #define CMD_DAB_DIGRAD_STATUS_REP_RSSI_LSB  0
      #define CMD_DAB_DIGRAD_STATUS_REP_RSSI_INDEX 0x06
      #define CMD_DAB_DIGRAD_STATUS_REP_RSSI_value (((uint8_t)(reply_buffer[6])))
      #define CMD_DAB_DIGRAD_STATUS_REP_RSSI_MIN -128
      #define CMD_DAB_DIGRAD_STATUS_REP_RSSI_MAX 63
      #define CMD_DAB_DIGRAD_STATUS_REP_SNR_TYPE u8
      #define CMD_DAB_DIGRAD_STATUS_REP_SNR_SIZE 8
      #define CMD_DAB_DIGRAD_STATUS_REP_SNR_MASK 0xFF
      #define CMD_DAB_DIGRAD_STATUS_REP_SNR_MSB  7
      #define CMD_DAB_DIGRAD_STATUS_REP_SNR_LSB  0
      #define CMD_DAB_DIGRAD_STATUS_REP_SNR_INDEX 0x07
      #define CMD_DAB_DIGRAD_STATUS_REP_SNR_value (((reply_buffer[7])))
      #define CMD_DAB_DIGRAD_STATUS_REP_SNR_MIN 0
      #define CMD_DAB_DIGRAD_STATUS_REP_SNR_MAX 20
      #define CMD_DAB_DIGRAD_STATUS_REP_FIC_QUALITY_TYPE u8
      #define CMD_DAB_DIGRAD_STATUS_REP_FIC_QUALITY_SIZE 8
      #define CMD_DAB_DIGRAD_STATUS_REP_FIC_QUALITY_MASK 0xFF
      #define CMD_DAB_DIGRAD_STATUS_REP_FIC_QUALITY_MSB  7
      #define CMD_DAB_DIGRAD_STATUS_REP_FIC_QUALITY_LSB  0
      #define CMD_DAB_DIGRAD_STATUS_REP_FIC_QUALITY_INDEX 0x08
      #define CMD_DAB_DIGRAD_STATUS_REP_FIC_QUALITY_value (((reply_buffer[8])))
      #define CMD_DAB_DIGRAD_STATUS_REP_FIC_QUALITY_MIN 0
      #define CMD_DAB_DIGRAD_STATUS_REP_FIC_QUALITY_MAX 100
      #define CMD_DAB_DIGRAD_STATUS_REP_CNR_TYPE u8
      #define CMD_DAB_DIGRAD_STATUS_REP_CNR_SIZE 8
      #define CMD_DAB_DIGRAD_STATUS_REP_CNR_MASK 0xFF
      #define CMD_DAB_DIGRAD_STATUS_REP_CNR_MSB  7
      #define CMD_DAB_DIGRAD_STATUS_REP_CNR_LSB  0
      #define CMD_DAB_DIGRAD_STATUS_REP_CNR_INDEX 0x09
      #define CMD_DAB_DIGRAD_STATUS_REP_CNR_value (((reply_buffer[9])))
      #define CMD_DAB_DIGRAD_STATUS_REP_CNR_MIN 0
      #define CMD_DAB_DIGRAD_STATUS_REP_CNR_MAX 54
      #define CMD_DAB_DIGRAD_STATUS_REP_FIB_ERROR_COUNT_TYPE u16
      #define CMD_DAB_DIGRAD_STATUS_REP_FIB_ERROR_COUNT_SIZE 16
      #define CMD_DAB_DIGRAD_STATUS_REP_FIB_ERROR_COUNT_MASK 0xFFFF
      #define CMD_DAB_DIGRAD_STATUS_REP_FIB_ERROR_COUNT_MSB  15
      #define CMD_DAB_DIGRAD_STATUS_REP_FIB_ERROR_COUNT_LSB  0
      #define CMD_DAB_DIGRAD_STATUS_REP_FIB_ERROR_COUNT_INDEX 0x0A
      #define CMD_DAB_DIGRAD_STATUS_REP_FIB_ERROR_COUNT_value (((reply_buffer_u16[5])))
      #define CMD_DAB_DIGRAD_STATUS_REP_TUNE_FREQ_TYPE u32
      #define CMD_DAB_DIGRAD_STATUS_REP_TUNE_FREQ_SIZE 32
      #define CMD_DAB_DIGRAD_STATUS_REP_TUNE_FREQ_MASK 0xFFFFFFFF
      #define CMD_DAB_DIGRAD_STATUS_REP_TUNE_FREQ_MSB  31
      #define CMD_DAB_DIGRAD_STATUS_REP_TUNE_FREQ_LSB  0
      #define CMD_DAB_DIGRAD_STATUS_REP_TUNE_FREQ_INDEX 0x0C
      #define CMD_DAB_DIGRAD_STATUS_REP_TUNE_FREQ_value (((reply_buffer_u32[3])))
      #define CMD_DAB_DIGRAD_STATUS_REP_TUNE_INDEX_TYPE u8
      #define CMD_DAB_DIGRAD_STATUS_REP_TUNE_INDEX_SIZE 8
      #define CMD_DAB_DIGRAD_STATUS_REP_TUNE_INDEX_MASK 0xFF
      #define CMD_DAB_DIGRAD_STATUS_REP_TUNE_INDEX_MSB  7
      #define CMD_DAB_DIGRAD_STATUS_REP_TUNE_INDEX_LSB  0
      #define CMD_DAB_DIGRAD_STATUS_REP_TUNE_INDEX_INDEX 0x10
      #define CMD_DAB_DIGRAD_STATUS_REP_TUNE_INDEX_value (((reply_buffer[16])))
      #define CMD_DAB_DIGRAD_STATUS_REP_TUNE_INDEX_MIN 0
      #define CMD_DAB_DIGRAD_STATUS_REP_TUNE_INDEX_MAX 47
      #define CMD_DAB_DIGRAD_STATUS_REP_FFT_OFFSET_TYPE i8
      #define CMD_DAB_DIGRAD_STATUS_REP_FFT_OFFSET_SIZE 8
      #define CMD_DAB_DIGRAD_STATUS_REP_FFT_OFFSET_MASK 0xFF
      #define CMD_DAB_DIGRAD_STATUS_REP_FFT_OFFSET_MSB  7
      #define CMD_DAB_DIGRAD_STATUS_REP_FFT_OFFSET_LSB  0
      #define CMD_DAB_DIGRAD_STATUS_REP_FFT_OFFSET_INDEX 0x11
      #define CMD_DAB_DIGRAD_STATUS_REP_FFT_OFFSET_value (((uint8_t)(reply_buffer[17])))
      #define CMD_DAB_DIGRAD_STATUS_REP_READANTCAP_TYPE u16
      #define CMD_DAB_DIGRAD_STATUS_REP_READANTCAP_SIZE 16
      #define CMD_DAB_DIGRAD_STATUS_REP_READANTCAP_MASK 0xFFFF
      #define CMD_DAB_DIGRAD_STATUS_REP_READANTCAP_MSB  15
      #define CMD_DAB_DIGRAD_STATUS_REP_READANTCAP_LSB  0
      #define CMD_DAB_DIGRAD_STATUS_REP_READANTCAP_INDEX 0x12
      #define CMD_DAB_DIGRAD_STATUS_REP_READANTCAP_value (((reply_buffer_u16[9])))
      #define CMD_DAB_DIGRAD_STATUS_REP_CU_LEVEL_TYPE u16
      #define CMD_DAB_DIGRAD_STATUS_REP_CU_LEVEL_SIZE 16
      #define CMD_DAB_DIGRAD_STATUS_REP_CU_LEVEL_MASK 0xFFFF
      #define CMD_DAB_DIGRAD_STATUS_REP_CU_LEVEL_MSB  15
      #define CMD_DAB_DIGRAD_STATUS_REP_CU_LEVEL_LSB  0
      #define CMD_DAB_DIGRAD_STATUS_REP_CU_LEVEL_INDEX 0x14
      #define CMD_DAB_DIGRAD_STATUS_REP_CU_LEVEL_value (((reply_buffer_u16[10])))
      #define CMD_DAB_DIGRAD_STATUS_REP_CU_LEVEL_MIN 0
      #define CMD_DAB_DIGRAD_STATUS_REP_CU_LEVEL_MAX 470
      #define CMD_DAB_DIGRAD_STATUS_REP_FAST_DECT_TYPE u8
      #define CMD_DAB_DIGRAD_STATUS_REP_FAST_DECT_SIZE 8
      #define CMD_DAB_DIGRAD_STATUS_REP_FAST_DECT_MASK 0xFF
      #define CMD_DAB_DIGRAD_STATUS_REP_FAST_DECT_MSB  7
      #define CMD_DAB_DIGRAD_STATUS_REP_FAST_DECT_LSB  0
      #define CMD_DAB_DIGRAD_STATUS_REP_FAST_DECT_INDEX 0x16
      #define CMD_DAB_DIGRAD_STATUS_REP_FAST_DECT_value (((reply_buffer[22])))

#define CMD_DAB_GET_EVENT_STATUS 0xB3
#define CMD_DAB_GET_EVENT_STATUS_LENGTH 2
#define CMD_DAB_GET_EVENT_STATUS_REP_LENGTH 8
//DAB_GET_EVENT_STATUS ARGS
      #define CMD_DAB_GET_EVENT_STATUS_ARG_EVENT_ACK_TYPE bitfield
      #define CMD_DAB_GET_EVENT_STATUS_ARG_EVENT_ACK_SIZE 1
      #define CMD_DAB_GET_EVENT_STATUS_ARG_EVENT_ACK_MASK 0x01
      #define CMD_DAB_GET_EVENT_STATUS_ARG_EVENT_ACK_BIT  0x01
      #define CMD_DAB_GET_EVENT_STATUS_ARG_EVENT_ACK_MSB  0
      #define CMD_DAB_GET_EVENT_STATUS_ARG_EVENT_ACK_LSB  0
      #define CMD_DAB_GET_EVENT_STATUS_ARG_EVENT_ACK_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x1) | (((x)<<0)&0x1)))
//DAB_GET_EVENT_STATUS REPLY
      #define CMD_DAB_GET_EVENT_STATUS_REP_RECFGINT_TYPE bitfield
      #define CMD_DAB_GET_EVENT_STATUS_REP_RECFGINT_SIZE 1
      #define CMD_DAB_GET_EVENT_STATUS_REP_RECFGINT_MASK 0x80
      #define CMD_DAB_GET_EVENT_STATUS_REP_RECFGINT_BIT  0x80
      #define CMD_DAB_GET_EVENT_STATUS_REP_RECFGINT_MSB  7
      #define CMD_DAB_GET_EVENT_STATUS_REP_RECFGINT_LSB  7
      #define CMD_DAB_GET_EVENT_STATUS_REP_RECFGINT_is_true (reply_buffer[4]&0x80)
      #define CMD_DAB_GET_EVENT_STATUS_REP_RECFGINT_value (((reply_buffer[4]&0x80))>>7)
      #define CMD_DAB_GET_EVENT_STATUS_REP_RECFGWRNINT_TYPE bitfield
      #define CMD_DAB_GET_EVENT_STATUS_REP_RECFGWRNINT_SIZE 1
      #define CMD_DAB_GET_EVENT_STATUS_REP_RECFGWRNINT_MASK 0x40
      #define CMD_DAB_GET_EVENT_STATUS_REP_RECFGWRNINT_BIT  0x40
      #define CMD_DAB_GET_EVENT_STATUS_REP_RECFGWRNINT_MSB  6
      #define CMD_DAB_GET_EVENT_STATUS_REP_RECFGWRNINT_LSB  6
      #define CMD_DAB_GET_EVENT_STATUS_REP_RECFGWRNINT_is_true (reply_buffer[4]&0x40)
      #define CMD_DAB_GET_EVENT_STATUS_REP_RECFGWRNINT_value (((reply_buffer[4]&0x40))>>6)
      #define CMD_DAB_GET_EVENT_STATUS_REP_ANNOINT_TYPE bitfield
      #define CMD_DAB_GET_EVENT_STATUS_REP_ANNOINT_SIZE 1
      #define CMD_DAB_GET_EVENT_STATUS_REP_ANNOINT_MASK 0x10
      #define CMD_DAB_GET_EVENT_STATUS_REP_ANNOINT_BIT  0x10
      #define CMD_DAB_GET_EVENT_STATUS_REP_ANNOINT_MSB  4
      #define CMD_DAB_GET_EVENT_STATUS_REP_ANNOINT_LSB  4
      #define CMD_DAB_GET_EVENT_STATUS_REP_ANNOINT_is_true (reply_buffer[4]&0x10)
      #define CMD_DAB_GET_EVENT_STATUS_REP_ANNOINT_value (((reply_buffer[4]&0x10))>>4)
      #define CMD_DAB_GET_EVENT_STATUS_REP_OESERVINT_TYPE bitfield
      #define CMD_DAB_GET_EVENT_STATUS_REP_OESERVINT_SIZE 1
      #define CMD_DAB_GET_EVENT_STATUS_REP_OESERVINT_MASK 0x08
      #define CMD_DAB_GET_EVENT_STATUS_REP_OESERVINT_BIT  0x08
      #define CMD_DAB_GET_EVENT_STATUS_REP_OESERVINT_MSB  3
      #define CMD_DAB_GET_EVENT_STATUS_REP_OESERVINT_LSB  3
      #define CMD_DAB_GET_EVENT_STATUS_REP_OESERVINT_is_true (reply_buffer[4]&0x8)
      #define CMD_DAB_GET_EVENT_STATUS_REP_OESERVINT_value (((reply_buffer[4]&0x8))>>3)
      #define CMD_DAB_GET_EVENT_STATUS_REP_SERVLINKINT_TYPE bitfield
      #define CMD_DAB_GET_EVENT_STATUS_REP_SERVLINKINT_SIZE 1
      #define CMD_DAB_GET_EVENT_STATUS_REP_SERVLINKINT_MASK 0x04
      #define CMD_DAB_GET_EVENT_STATUS_REP_SERVLINKINT_BIT  0x04
      #define CMD_DAB_GET_EVENT_STATUS_REP_SERVLINKINT_MSB  2
      #define CMD_DAB_GET_EVENT_STATUS_REP_SERVLINKINT_LSB  2
      #define CMD_DAB_GET_EVENT_STATUS_REP_SERVLINKINT_is_true (reply_buffer[4]&0x4)
      #define CMD_DAB_GET_EVENT_STATUS_REP_SERVLINKINT_value (((reply_buffer[4]&0x4))>>2)
      #define CMD_DAB_GET_EVENT_STATUS_REP_FREQINFOINT_TYPE bitfield
      #define CMD_DAB_GET_EVENT_STATUS_REP_FREQINFOINT_SIZE 1
      #define CMD_DAB_GET_EVENT_STATUS_REP_FREQINFOINT_MASK 0x02
      #define CMD_DAB_GET_EVENT_STATUS_REP_FREQINFOINT_BIT  0x02
      #define CMD_DAB_GET_EVENT_STATUS_REP_FREQINFOINT_MSB  1
      #define CMD_DAB_GET_EVENT_STATUS_REP_FREQINFOINT_LSB  1
      #define CMD_DAB_GET_EVENT_STATUS_REP_FREQINFOINT_is_true (reply_buffer[4]&0x2)
      #define CMD_DAB_GET_EVENT_STATUS_REP_FREQINFOINT_value (((reply_buffer[4]&0x2))>>1)
      #define CMD_DAB_GET_EVENT_STATUS_REP_SVRLISTINT_TYPE bitfield
      #define CMD_DAB_GET_EVENT_STATUS_REP_SVRLISTINT_SIZE 1
      #define CMD_DAB_GET_EVENT_STATUS_REP_SVRLISTINT_MASK 0x01
      #define CMD_DAB_GET_EVENT_STATUS_REP_SVRLISTINT_BIT  0x01
      #define CMD_DAB_GET_EVENT_STATUS_REP_SVRLISTINT_MSB  0
      #define CMD_DAB_GET_EVENT_STATUS_REP_SVRLISTINT_LSB  0
      #define CMD_DAB_GET_EVENT_STATUS_REP_SVRLISTINT_is_true (reply_buffer[4]&0x1)
      #define CMD_DAB_GET_EVENT_STATUS_REP_SVRLISTINT_value (((reply_buffer[4]&0x1)))
      #define CMD_DAB_GET_EVENT_STATUS_REP_ANNO_TYPE bitfield
      #define CMD_DAB_GET_EVENT_STATUS_REP_ANNO_SIZE 1
      #define CMD_DAB_GET_EVENT_STATUS_REP_ANNO_MASK 0x10
      #define CMD_DAB_GET_EVENT_STATUS_REP_ANNO_BIT  0x10
      #define CMD_DAB_GET_EVENT_STATUS_REP_ANNO_MSB  4
      #define CMD_DAB_GET_EVENT_STATUS_REP_ANNO_LSB  4
      #define CMD_DAB_GET_EVENT_STATUS_REP_ANNO_is_true (reply_buffer[5]&0x10)
      #define CMD_DAB_GET_EVENT_STATUS_REP_ANNO_value (((reply_buffer[5]&0x10))>>4)
      #define CMD_DAB_GET_EVENT_STATUS_REP_ANNO_ENUM_INACTIVE 0
      #define CMD_DAB_GET_EVENT_STATUS_REP_ANNO_ENUM_ACTIVE 1
      #define CMD_DAB_GET_EVENT_STATUS_REP_OESERV_TYPE bitfield
      #define CMD_DAB_GET_EVENT_STATUS_REP_OESERV_SIZE 1
      #define CMD_DAB_GET_EVENT_STATUS_REP_OESERV_MASK 0x08
      #define CMD_DAB_GET_EVENT_STATUS_REP_OESERV_BIT  0x08
      #define CMD_DAB_GET_EVENT_STATUS_REP_OESERV_MSB  3
      #define CMD_DAB_GET_EVENT_STATUS_REP_OESERV_LSB  3
      #define CMD_DAB_GET_EVENT_STATUS_REP_OESERV_is_true (reply_buffer[5]&0x8)
      #define CMD_DAB_GET_EVENT_STATUS_REP_OESERV_value (((reply_buffer[5]&0x8))>>3)
      #define CMD_DAB_GET_EVENT_STATUS_REP_SERVLINK_TYPE bitfield
      #define CMD_DAB_GET_EVENT_STATUS_REP_SERVLINK_SIZE 1
      #define CMD_DAB_GET_EVENT_STATUS_REP_SERVLINK_MASK 0x04
      #define CMD_DAB_GET_EVENT_STATUS_REP_SERVLINK_BIT  0x04
      #define CMD_DAB_GET_EVENT_STATUS_REP_SERVLINK_MSB  2
      #define CMD_DAB_GET_EVENT_STATUS_REP_SERVLINK_LSB  2
      #define CMD_DAB_GET_EVENT_STATUS_REP_SERVLINK_is_true (reply_buffer[5]&0x4)
      #define CMD_DAB_GET_EVENT_STATUS_REP_SERVLINK_value (((reply_buffer[5]&0x4))>>2)
      #define CMD_DAB_GET_EVENT_STATUS_REP_FREQ_INFO_TYPE bitfield
      #define CMD_DAB_GET_EVENT_STATUS_REP_FREQ_INFO_SIZE 1
      #define CMD_DAB_GET_EVENT_STATUS_REP_FREQ_INFO_MASK 0x02
      #define CMD_DAB_GET_EVENT_STATUS_REP_FREQ_INFO_BIT  0x02
      #define CMD_DAB_GET_EVENT_STATUS_REP_FREQ_INFO_MSB  1
      #define CMD_DAB_GET_EVENT_STATUS_REP_FREQ_INFO_LSB  1
      #define CMD_DAB_GET_EVENT_STATUS_REP_FREQ_INFO_is_true (reply_buffer[5]&0x2)
      #define CMD_DAB_GET_EVENT_STATUS_REP_FREQ_INFO_value (((reply_buffer[5]&0x2))>>1)
      #define CMD_DAB_GET_EVENT_STATUS_REP_SVRLIST_TYPE bitfield
      #define CMD_DAB_GET_EVENT_STATUS_REP_SVRLIST_SIZE 1
      #define CMD_DAB_GET_EVENT_STATUS_REP_SVRLIST_MASK 0x01
      #define CMD_DAB_GET_EVENT_STATUS_REP_SVRLIST_BIT  0x01
      #define CMD_DAB_GET_EVENT_STATUS_REP_SVRLIST_MSB  0
      #define CMD_DAB_GET_EVENT_STATUS_REP_SVRLIST_LSB  0
      #define CMD_DAB_GET_EVENT_STATUS_REP_SVRLIST_is_true (reply_buffer[5]&0x1)
      #define CMD_DAB_GET_EVENT_STATUS_REP_SVRLIST_value (((reply_buffer[5]&0x1)))
      #define CMD_DAB_GET_EVENT_STATUS_REP_SVRLISTVER_TYPE u16
      #define CMD_DAB_GET_EVENT_STATUS_REP_SVRLISTVER_SIZE 16
      #define CMD_DAB_GET_EVENT_STATUS_REP_SVRLISTVER_MASK 0xFFFF
      #define CMD_DAB_GET_EVENT_STATUS_REP_SVRLISTVER_MSB  15
      #define CMD_DAB_GET_EVENT_STATUS_REP_SVRLISTVER_LSB  0
      #define CMD_DAB_GET_EVENT_STATUS_REP_SVRLISTVER_INDEX 0x06
      #define CMD_DAB_GET_EVENT_STATUS_REP_SVRLISTVER_value (((reply_buffer_u16[3])))

#define CMD_DAB_GET_ENSEMBLE_INFO 0xB4
#define CMD_DAB_GET_ENSEMBLE_INFO_LENGTH 2
#define CMD_DAB_GET_ENSEMBLE_INFO_REP_LENGTH 26
//DAB_GET_ENSEMBLE_INFO REPLY
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_EID_TYPE u16
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_EID_SIZE 16
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_EID_MASK 0xFFFF
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_EID_MSB  15
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_EID_LSB  0
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_EID_INDEX 0x04
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_EID_value (((reply_buffer_u16[2])))
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL0_TYPE u8
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL0_SIZE 8
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL0_MASK 0xFF
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL0_MSB  7
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL0_LSB  0
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL0_INDEX 0x06
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL0_value (((reply_buffer[6])))
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL1_TYPE u8
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL1_SIZE 8
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL1_MASK 0xFF
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL1_MSB  7
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL1_LSB  0
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL1_INDEX 0x07
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL1_value (((reply_buffer[7])))
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL2_TYPE u8
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL2_SIZE 8
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL2_MASK 0xFF
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL2_MSB  7
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL2_LSB  0
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL2_INDEX 0x08
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL2_value (((reply_buffer[8])))
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL3_TYPE u8
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL3_SIZE 8
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL3_MASK 0xFF
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL3_MSB  7
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL3_LSB  0
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL3_INDEX 0x09
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL3_value (((reply_buffer[9])))
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL4_TYPE u8
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL4_SIZE 8
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL4_MASK 0xFF
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL4_MSB  7
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL4_LSB  0
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL4_INDEX 0x0A
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL4_value (((reply_buffer[10])))
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL5_TYPE u8
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL5_SIZE 8
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL5_MASK 0xFF
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL5_MSB  7
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL5_LSB  0
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL5_INDEX 0x0B
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL5_value (((reply_buffer[11])))
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL6_TYPE u8
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL6_SIZE 8
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL6_MASK 0xFF
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL6_MSB  7
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL6_LSB  0
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL6_INDEX 0x0C
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL6_value (((reply_buffer[12])))
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL7_TYPE u8
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL7_SIZE 8
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL7_MASK 0xFF
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL7_MSB  7
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL7_LSB  0
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL7_INDEX 0x0D
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL7_value (((reply_buffer[13])))
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL8_TYPE u8
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL8_SIZE 8
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL8_MASK 0xFF
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL8_MSB  7
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL8_LSB  0
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL8_INDEX 0x0E
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL8_value (((reply_buffer[14])))
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL9_TYPE u8
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL9_SIZE 8
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL9_MASK 0xFF
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL9_MSB  7
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL9_LSB  0
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL9_INDEX 0x0F
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL9_value (((reply_buffer[15])))
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL10_TYPE u8
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL10_SIZE 8
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL10_MASK 0xFF
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL10_MSB  7
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL10_LSB  0
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL10_INDEX 0x10
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL10_value (((reply_buffer[16])))
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL11_TYPE u8
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL11_SIZE 8
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL11_MASK 0xFF
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL11_MSB  7
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL11_LSB  0
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL11_INDEX 0x11
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL11_value (((reply_buffer[17])))
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL12_TYPE u8
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL12_SIZE 8
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL12_MASK 0xFF
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL12_MSB  7
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL12_LSB  0
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL12_INDEX 0x12
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL12_value (((reply_buffer[18])))
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL13_TYPE u8
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL13_SIZE 8
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL13_MASK 0xFF
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL13_MSB  7
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL13_LSB  0
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL13_INDEX 0x13
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL13_value (((reply_buffer[19])))
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL14_TYPE u8
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL14_SIZE 8
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL14_MASK 0xFF
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL14_MSB  7
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL14_LSB  0
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL14_INDEX 0x14
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL14_value (((reply_buffer[20])))
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL15_TYPE u8
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL15_SIZE 8
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL15_MASK 0xFF
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL15_MSB  7
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL15_LSB  0
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL15_INDEX 0x15
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_LABEL15_value (((reply_buffer[21])))
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_ENSEMBLE_ECC_TYPE u8
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_ENSEMBLE_ECC_SIZE 8
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_ENSEMBLE_ECC_MASK 0xFF
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_ENSEMBLE_ECC_MSB  7
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_ENSEMBLE_ECC_LSB  0
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_ENSEMBLE_ECC_INDEX 0x16
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_ENSEMBLE_ECC_value (((reply_buffer[22])))
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_CHARSET_TYPE u8
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_CHARSET_SIZE 8
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_CHARSET_MASK 0xFF
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_CHARSET_MSB  7
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_CHARSET_LSB  0
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_CHARSET_INDEX 0x17
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_CHARSET_value (((reply_buffer[23])))
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_CHAR_ABREV_TYPE u16
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_CHAR_ABREV_SIZE 16
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_CHAR_ABREV_MASK 0xFFFF
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_CHAR_ABREV_MSB  15
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_CHAR_ABREV_LSB  0
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_CHAR_ABREV_INDEX 0x18
      #define CMD_DAB_GET_ENSEMBLE_INFO_REP_CHAR_ABREV_value (((reply_buffer_u16[12])))

#define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO 0xB5
#define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_LENGTH 8
#define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_LENGTH 12
//DAB_GET_ANNOUNCEMENT_SUPPORT_INFO ARGS
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_ARG_SRC_TYPE bitfield
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_ARG_SRC_SIZE 2
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_ARG_SRC_MASK 0x03
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_ARG_SRC_MSB  1
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_ARG_SRC_LSB  0
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_ARG_SRC_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x3) | (((x)<<0)&0x3)))
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_ARG_SRC_ENUM_CE 0
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_ARG_SRC_ENUM_OE 1
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_ARG_SRC_ENUM_FM 2
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_ARG_SID_TYPE u32
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_ARG_SID_SIZE 32
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_ARG_SID_MASK 0xFFFFFFFF
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_ARG_SID_MSB  31
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_ARG_SID_LSB  0
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_ARG_SID_INDEX 0x04
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_ARG_SID_write_u32(x) (cmd_arg_u32[1] = (x))
//DAB_GET_ANNOUNCEMENT_SUPPORT_INFO REPLY
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_NUM_IDS_TYPE u8
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_NUM_IDS_SIZE 8
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_NUM_IDS_MASK 0xFF
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_NUM_IDS_MSB  7
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_NUM_IDS_LSB  0
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_NUM_IDS_INDEX 0x04
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_NUM_IDS_value (((reply_buffer[4])))
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_RESERVED_TYPE u8
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_RESERVED_SIZE 8
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_RESERVED_MASK 0xFF
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_RESERVED_MSB  7
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_RESERVED_LSB  0
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_RESERVED_INDEX 0x05
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_RESERVED_value (((reply_buffer[5])))
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_ASU_TYPE u16
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_ASU_SIZE 16
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_ASU_MASK 0xFFFF
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_ASU_MSB  15
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_ASU_LSB  0
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_ASU_INDEX 0x06
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_ASU_value (((reply_buffer_u16[3])))
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_ID0_TYPE u16
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_ID0_SIZE 16
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_ID0_MASK 0xFFFF
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_ID0_MSB  15
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_ID0_LSB  0
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_ID0_INDEX 0x08
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_ID0_value (((reply_buffer_u16[4])))
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_IDN_TYPE u16
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_IDN_SIZE 16
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_IDN_MASK 0xFFFF
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_IDN_MSB  15
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_IDN_LSB  0
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_IDN_INDEX 0x0A
      #define CMD_DAB_GET_ANNOUNCEMENT_SUPPORT_INFO_REP_IDN_value (((reply_buffer_u16[5])))

#define CMD_DAB_GET_ANNOUNCEMENT_INFO 0xB6
#define CMD_DAB_GET_ANNOUNCEMENT_INFO_LENGTH 1
#define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_LENGTH 16
//DAB_GET_ANNOUNCEMENT_INFO REPLY
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ANNO_Q_OVFL_TYPE bitfield
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ANNO_Q_OVFL_SIZE 1
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ANNO_Q_OVFL_MASK 0x01
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ANNO_Q_OVFL_BIT  0x01
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ANNO_Q_OVFL_MSB  0
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ANNO_Q_OVFL_LSB  0
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ANNO_Q_OVFL_is_true (reply_buffer[4]&0x1)
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ANNO_Q_OVFL_value (((reply_buffer[4]&0x1)))
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ANNO_Q_OVFL_ENUM_FALSE 0
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ANNO_Q_OVFL_ENUM_TRUE 1
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ANNO_Q_SIZE_TYPE bitfield
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ANNO_Q_SIZE_SIZE 5
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ANNO_Q_SIZE_MASK 0x1F
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ANNO_Q_SIZE_MSB  4
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ANNO_Q_SIZE_LSB  0
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ANNO_Q_SIZE_value (((reply_buffer[5]&0x1F)))
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_CLUSTER_ID_TYPE u8
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_CLUSTER_ID_SIZE 8
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_CLUSTER_ID_MASK 0xFF
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_CLUSTER_ID_MSB  7
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_CLUSTER_ID_LSB  0
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_CLUSTER_ID_INDEX 0x06
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_CLUSTER_ID_value (((reply_buffer[6])))
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ANNO_STAT_TYPE bitfield
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ANNO_STAT_SIZE 1
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ANNO_STAT_MASK 0x08
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ANNO_STAT_BIT  0x08
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ANNO_STAT_MSB  3
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ANNO_STAT_LSB  3
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ANNO_STAT_is_true (reply_buffer[7]&0x8)
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ANNO_STAT_value (((reply_buffer[7]&0x8))>>3)
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ANNO_STAT_ENUM_OFF 0
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ANNO_STAT_ENUM_ON 1
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_REGION_FLAG_TYPE bitfield
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_REGION_FLAG_SIZE 1
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_REGION_FLAG_MASK 0x04
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_REGION_FLAG_BIT  0x04
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_REGION_FLAG_MSB  2
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_REGION_FLAG_LSB  2
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_REGION_FLAG_is_true (reply_buffer[7]&0x4)
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_REGION_FLAG_value (((reply_buffer[7]&0x4))>>2)
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_REGION_FLAG_ENUM_OFF 0
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_REGION_FLAG_ENUM_ON 1
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_SRC_TYPE bitfield
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_SRC_SIZE 2
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_SRC_MASK 0x03
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_SRC_MSB  1
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_SRC_LSB  0
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_SRC_value (((reply_buffer[7]&0x3)))
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_SRC_ENUM_CE 0
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_SRC_ENUM_OE 1
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_SRC_ENUM_FM 2
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_SRC_ENUM_RESERVED 3
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ASW_TYPE u16
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ASW_SIZE 16
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ASW_MASK 0xFFFF
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ASW_MSB  15
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ASW_LSB  0
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ASW_INDEX 0x08
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ASW_value (((reply_buffer_u16[4])))
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ID1_TYPE u16
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ID1_SIZE 16
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ID1_MASK 0xFFFF
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ID1_MSB  15
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ID1_LSB  0
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ID1_INDEX 0x0A
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ID1_value (((reply_buffer_u16[5])))
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ID2_TYPE u16
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ID2_SIZE 16
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ID2_MASK 0xFFFF
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ID2_MSB  15
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ID2_LSB  0
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ID2_INDEX 0x0C
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_ID2_value (((reply_buffer_u16[6])))
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_REGIONID1_TYPE u8
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_REGIONID1_SIZE 8
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_REGIONID1_MASK 0xFF
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_REGIONID1_MSB  7
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_REGIONID1_LSB  0
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_REGIONID1_INDEX 0x0E
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_REGIONID1_value (((reply_buffer[14])))
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_REGIONID2_TYPE u8
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_REGIONID2_SIZE 8
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_REGIONID2_MASK 0xFF
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_REGIONID2_MSB  7
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_REGIONID2_LSB  0
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_REGIONID2_INDEX 0x0F
      #define CMD_DAB_GET_ANNOUNCEMENT_INFO_REP_REGIONID2_value (((reply_buffer[15])))

#define CMD_DAB_GET_SERVICE_LINKING_INFO 0xB7
#define CMD_DAB_GET_SERVICE_LINKING_INFO_LENGTH 8
#define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_LENGTH 16
//DAB_GET_SERVICE_LINKING_INFO ARGS
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ACTIVE_TYPE bitfield
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ACTIVE_SIZE 1
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ACTIVE_MASK 0x80
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ACTIVE_BIT  0x80
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ACTIVE_MSB  7
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ACTIVE_LSB  7
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ACTIVE_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x80) | (((x)<<7)&0x80)))
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_LINKTYPE_TYPE bitfield
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_LINKTYPE_SIZE 2
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_LINKTYPE_MASK 0x30
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_LINKTYPE_MSB  5
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_LINKTYPE_LSB  4
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_LINKTYPE_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x30) | (((x)<<4)&0x30)))
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_SELRSVD2_TYPE bitfield
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_SELRSVD2_SIZE 1
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_SELRSVD2_MASK 0x08
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_SELRSVD2_BIT  0x08
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_SELRSVD2_MSB  3
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_SELRSVD2_LSB  3
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_SELRSVD2_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x8) | (((x)<<3)&0x8)))
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_SELRSVD1_TYPE bitfield
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_SELRSVD1_SIZE 1
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_SELRSVD1_MASK 0x04
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_SELRSVD1_BIT  0x04
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_SELRSVD1_MSB  2
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_SELRSVD1_LSB  2
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_SELRSVD1_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x4) | (((x)<<2)&0x4)))
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_HARD_TYPE bitfield
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_HARD_SIZE 1
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_HARD_MASK 0x02
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_HARD_BIT  0x02
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_HARD_MSB  1
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_HARD_LSB  1
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_HARD_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x2) | (((x)<<1)&0x2)))
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ILS_TYPE bitfield
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ILS_SIZE 1
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ILS_MASK 0x01
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ILS_BIT  0x01
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ILS_MSB  0
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ILS_LSB  0
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ILS_write_field(x) (cmd_arg[1] = ((cmd_arg[1]&~0x1) | (((x)<<0)&0x1)))
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ACTIVEEN_TYPE bitfield
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ACTIVEEN_SIZE 1
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ACTIVEEN_MASK 0x80
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ACTIVEEN_BIT  0x80
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ACTIVEEN_MSB  7
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ACTIVEEN_LSB  7
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ACTIVEEN_write_field(x) (cmd_arg[2] = ((cmd_arg[2]&~0x80) | (((x)<<7)&0x80)))
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_LINKTYPEEN_TYPE bitfield
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_LINKTYPEEN_SIZE 1
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_LINKTYPEEN_MASK 0x10
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_LINKTYPEEN_BIT  0x10
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_LINKTYPEEN_MSB  4
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_LINKTYPEEN_LSB  4
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_LINKTYPEEN_write_field(x) (cmd_arg[2] = ((cmd_arg[2]&~0x10) | (((x)<<4)&0x10)))
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ENRESVD2_TYPE bitfield
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ENRESVD2_SIZE 1
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ENRESVD2_MASK 0x08
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ENRESVD2_BIT  0x08
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ENRESVD2_MSB  3
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ENRESVD2_LSB  3
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ENRESVD2_write_field(x) (cmd_arg[2] = ((cmd_arg[2]&~0x8) | (((x)<<3)&0x8)))
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ENRESVD1_TYPE bitfield
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ENRESVD1_SIZE 1
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ENRESVD1_MASK 0x04
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ENRESVD1_BIT  0x04
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ENRESVD1_MSB  2
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ENRESVD1_LSB  2
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ENRESVD1_write_field(x) (cmd_arg[2] = ((cmd_arg[2]&~0x4) | (((x)<<2)&0x4)))
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_HARDEN_TYPE bitfield
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_HARDEN_SIZE 1
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_HARDEN_MASK 0x02
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_HARDEN_BIT  0x02
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_HARDEN_MSB  1
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_HARDEN_LSB  1
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_HARDEN_write_field(x) (cmd_arg[2] = ((cmd_arg[2]&~0x2) | (((x)<<1)&0x2)))
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ILSEN_TYPE bitfield
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ILSEN_SIZE 1
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ILSEN_MASK 0x01
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ILSEN_BIT  0x01
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ILSEN_MSB  0
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ILSEN_LSB  0
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_ILSEN_write_field(x) (cmd_arg[2] = ((cmd_arg[2]&~0x1) | (((x)<<0)&0x1)))
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_SERVICEID_TYPE u32
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_SERVICEID_SIZE 32
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_SERVICEID_MASK 0xFFFFFFFF
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_SERVICEID_MSB  31
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_SERVICEID_LSB  0
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_SERVICEID_INDEX 0x04
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_ARG_SERVICEID_write_u32(x) (cmd_arg_u32[1] = (x))
//DAB_GET_SERVICE_LINKING_INFO REPLY
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_SIZE_TYPE u16
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_SIZE_SIZE 16
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_SIZE_MASK 0xFFFF
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_SIZE_MSB  15
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_SIZE_LSB  0
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_SIZE_INDEX 0x04
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_SIZE_value (((reply_buffer_u16[2])))
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_NUM_LINKSETS_TYPE u8
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_NUM_LINKSETS_SIZE 8
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_NUM_LINKSETS_MASK 0xFF
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_NUM_LINKSETS_MSB  7
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_NUM_LINKSETS_LSB  0
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_NUM_LINKSETS_INDEX 0x06
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_NUM_LINKSETS_value (((reply_buffer[6])))
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_LSN_0_TYPE u16
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_LSN_0_SIZE 16
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_LSN_0_MASK 0xFFFF
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_LSN_0_MSB  15
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_LSN_0_LSB  0
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_LSN_0_INDEX 0x08
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_LSN_0_value (((reply_buffer_u16[4])))
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_ACTIVE_TYPE bitfield
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_ACTIVE_SIZE 1
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_ACTIVE_MASK 0x80
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_ACTIVE_BIT  0x80
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_ACTIVE_MSB  7
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_ACTIVE_LSB  7
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_ACTIVE_is_true (reply_buffer[10]&0x80)
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_ACTIVE_value (((reply_buffer[10]&0x80))>>7)
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_SHD_TYPE bitfield
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_SHD_SIZE 1
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_SHD_MASK 0x40
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_SHD_BIT  0x40
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_SHD_MSB  6
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_SHD_LSB  6
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_SHD_is_true (reply_buffer[10]&0x40)
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_SHD_value (((reply_buffer[10]&0x40))>>6)
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_LINK_TYPE_TYPE bitfield
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_LINK_TYPE_SIZE 2
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_LINK_TYPE_MASK 0x30
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_LINK_TYPE_MSB  5
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_LINK_TYPE_LSB  4
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_LINK_TYPE_value (((reply_buffer[10]&0x30))>>4)
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_RSVD2_TYPE bitfield
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_RSVD2_SIZE 1
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_RSVD2_MASK 0x08
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_RSVD2_BIT  0x08
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_RSVD2_MSB  3
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_RSVD2_LSB  3
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_RSVD2_is_true (reply_buffer[10]&0x8)
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_RSVD2_value (((reply_buffer[10]&0x8))>>3)
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_RSVD1_TYPE bitfield
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_RSVD1_SIZE 1
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_RSVD1_MASK 0x04
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_RSVD1_BIT  0x04
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_RSVD1_MSB  2
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_RSVD1_LSB  2
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_RSVD1_is_true (reply_buffer[10]&0x4)
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_RSVD1_value (((reply_buffer[10]&0x4))>>2)
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_HARD_TYPE bitfield
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_HARD_SIZE 1
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_HARD_MASK 0x02
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_HARD_BIT  0x02
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_HARD_MSB  1
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_HARD_LSB  1
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_HARD_is_true (reply_buffer[10]&0x2)
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_HARD_value (((reply_buffer[10]&0x2))>>1)
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_ILS_TYPE bitfield
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_ILS_SIZE 1
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_ILS_MASK 0x01
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_ILS_BIT  0x01
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_ILS_MSB  0
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_ILS_LSB  0
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_ILS_is_true (reply_buffer[10]&0x1)
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_ILS_value (((reply_buffer[10]&0x1)))
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_NUM_LINKS_0_TYPE u8
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_NUM_LINKS_0_SIZE 8
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_NUM_LINKS_0_MASK 0xFF
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_NUM_LINKS_0_MSB  7
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_NUM_LINKS_0_LSB  0
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_NUM_LINKS_0_INDEX 0x0B
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_NUM_LINKS_0_value (((reply_buffer[11])))
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_LINKID_0_0_TYPE u32
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_LINKID_0_0_SIZE 32
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_LINKID_0_0_MASK 0xFFFFFFFF
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_LINKID_0_0_MSB  31
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_LINKID_0_0_LSB  0
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_LINKID_0_0_INDEX 0x0C
      #define CMD_DAB_GET_SERVICE_LINKING_INFO_REP_LINKID_0_0_value (((reply_buffer_u32[3])))

#define CMD_DAB_SET_FREQ_LIST    0xB8
//DAB_SET_FREQ_LIST ARGS
      #define CMD_DAB_SET_FREQ_LIST_ARG_NUM_FREQS_TYPE u8
      #define CMD_DAB_SET_FREQ_LIST_ARG_NUM_FREQS_SIZE 8
      #define CMD_DAB_SET_FREQ_LIST_ARG_NUM_FREQS_MASK 0xFF
      #define CMD_DAB_SET_FREQ_LIST_ARG_NUM_FREQS_MSB  7
      #define CMD_DAB_SET_FREQ_LIST_ARG_NUM_FREQS_LSB  0
      #define CMD_DAB_SET_FREQ_LIST_ARG_NUM_FREQS_INDEX 0x01
      #define CMD_DAB_SET_FREQ_LIST_ARG_NUM_FREQS_write_u8(x) (cmd_arg[1] = (x))
      #define CMD_DAB_SET_FREQ_LIST_ARG_NUM_FREQS_MIN 1
      #define CMD_DAB_SET_FREQ_LIST_ARG_NUM_FREQS_MAX 48
      #define CMD_DAB_SET_FREQ_LIST_ARG_FREQ_0_TYPE u32
      #define CMD_DAB_SET_FREQ_LIST_ARG_FREQ_0_SIZE 32
      #define CMD_DAB_SET_FREQ_LIST_ARG_FREQ_0_MASK 0xFFFFFFFF
      #define CMD_DAB_SET_FREQ_LIST_ARG_FREQ_0_MSB  31
      #define CMD_DAB_SET_FREQ_LIST_ARG_FREQ_0_LSB  0
      #define CMD_DAB_SET_FREQ_LIST_ARG_FREQ_0_INDEX 0x04
      #define CMD_DAB_SET_FREQ_LIST_ARG_FREQ_0_write_u32(x) (cmd_arg_u32[1] = (x))
      #define CMD_DAB_SET_FREQ_LIST_ARG_FREQ_1_TYPE u32
      #define CMD_DAB_SET_FREQ_LIST_ARG_FREQ_1_SIZE 32
      #define CMD_DAB_SET_FREQ_LIST_ARG_FREQ_1_MASK 0xFFFFFFFF
      #define CMD_DAB_SET_FREQ_LIST_ARG_FREQ_1_MSB  31
      #define CMD_DAB_SET_FREQ_LIST_ARG_FREQ_1_LSB  0
      #define CMD_DAB_SET_FREQ_LIST_ARG_FREQ_1_INDEX 0x08
      #define CMD_DAB_SET_FREQ_LIST_ARG_FREQ_1_write_u32(x) (cmd_arg_u32[2] = (x))
      #define CMD_DAB_SET_FREQ_LIST_ARG_FREQ_N_TYPE u32
      #define CMD_DAB_SET_FREQ_LIST_ARG_FREQ_N_SIZE 32
      #define CMD_DAB_SET_FREQ_LIST_ARG_FREQ_N_MASK 0xFFFFFFFF
      #define CMD_DAB_SET_FREQ_LIST_ARG_FREQ_N_MSB  31
      #define CMD_DAB_SET_FREQ_LIST_ARG_FREQ_N_LSB  0
      #define CMD_DAB_SET_FREQ_LIST_ARG_FREQ_N_INDEX 0x0C
      #define CMD_DAB_SET_FREQ_LIST_ARG_FREQ_N_write_u32(x) (cmd_arg_u32[3] = (x))

#define CMD_DAB_GET_FREQ_LIST    0xB9
#define CMD_DAB_GET_FREQ_LIST_LENGTH 2
#define CMD_DAB_GET_FREQ_LIST_REP_LENGTH 12
//DAB_GET_FREQ_LIST REPLY
      #define CMD_DAB_GET_FREQ_LIST_REP_NUM_FREQS_TYPE u8
      #define CMD_DAB_GET_FREQ_LIST_REP_NUM_FREQS_SIZE 8
      #define CMD_DAB_GET_FREQ_LIST_REP_NUM_FREQS_MASK 0xFF
      #define CMD_DAB_GET_FREQ_LIST_REP_NUM_FREQS_MSB  7
      #define CMD_DAB_GET_FREQ_LIST_REP_NUM_FREQS_LSB  0
      #define CMD_DAB_GET_FREQ_LIST_REP_NUM_FREQS_INDEX 0x04
      #define CMD_DAB_GET_FREQ_LIST_REP_NUM_FREQS_value (((reply_buffer[4])))
      #define CMD_DAB_GET_FREQ_LIST_REP_FREQ_0_TYPE u32
      #define CMD_DAB_GET_FREQ_LIST_REP_FREQ_0_SIZE 32
      #define CMD_DAB_GET_FREQ_LIST_REP_FREQ_0_MASK 0xFFFFFFFF
      #define CMD_DAB_GET_FREQ_LIST_REP_FREQ_0_MSB  31
      #define CMD_DAB_GET_FREQ_LIST_REP_FREQ_0_LSB  0
      #define CMD_DAB_GET_FREQ_LIST_REP_FREQ_0_INDEX 0x08
      #define CMD_DAB_GET_FREQ_LIST_REP_FREQ_0_value (((reply_buffer_u32[2])))

#define CMD_DAB_GET_COMPONENT_INFO 0xBB
#define CMD_DAB_GET_COMPONENT_INFO_LENGTH 12
#define CMD_DAB_GET_COMPONENT_INFO_REP_LENGTH 33
//DAB_GET_COMPONENT_INFO ARGS
      #define CMD_DAB_GET_COMPONENT_INFO_ARG_SERVICEID_TYPE u32
      #define CMD_DAB_GET_COMPONENT_INFO_ARG_SERVICEID_SIZE 32
      #define CMD_DAB_GET_COMPONENT_INFO_ARG_SERVICEID_MASK 0xFFFFFFFF
      #define CMD_DAB_GET_COMPONENT_INFO_ARG_SERVICEID_MSB  31
      #define CMD_DAB_GET_COMPONENT_INFO_ARG_SERVICEID_LSB  0
      #define CMD_DAB_GET_COMPONENT_INFO_ARG_SERVICEID_INDEX 0x04
      #define CMD_DAB_GET_COMPONENT_INFO_ARG_SERVICEID_write_u32(x) (cmd_arg_u32[1] = (x))
      #define CMD_DAB_GET_COMPONENT_INFO_ARG_COMPID_TYPE u32
      #define CMD_DAB_GET_COMPONENT_INFO_ARG_COMPID_SIZE 32
      #define CMD_DAB_GET_COMPONENT_INFO_ARG_COMPID_MASK 0xFFFFFFFF
      #define CMD_DAB_GET_COMPONENT_INFO_ARG_COMPID_MSB  31
      #define CMD_DAB_GET_COMPONENT_INFO_ARG_COMPID_LSB  0
      #define CMD_DAB_GET_COMPONENT_INFO_ARG_COMPID_INDEX 0x08
      #define CMD_DAB_GET_COMPONENT_INFO_ARG_COMPID_write_u32(x) (cmd_arg_u32[2] = (x))
//DAB_GET_COMPONENT_INFO REPLY
      #define CMD_DAB_GET_COMPONENT_INFO_REP_GLOBAL_ID_TYPE u8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_GLOBAL_ID_SIZE 8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_GLOBAL_ID_MASK 0xFF
      #define CMD_DAB_GET_COMPONENT_INFO_REP_GLOBAL_ID_MSB  7
      #define CMD_DAB_GET_COMPONENT_INFO_REP_GLOBAL_ID_LSB  0
      #define CMD_DAB_GET_COMPONENT_INFO_REP_GLOBAL_ID_INDEX 0x04
      #define CMD_DAB_GET_COMPONENT_INFO_REP_GLOBAL_ID_value (((reply_buffer[4])))
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LANG_TYPE bitfield
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LANG_SIZE 6
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LANG_MASK 0x3F
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LANG_MSB  5
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LANG_LSB  0
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LANG_value (((reply_buffer[6]&0x3F)))
      #define CMD_DAB_GET_COMPONENT_INFO_REP_CHARSETID_TYPE bitfield
      #define CMD_DAB_GET_COMPONENT_INFO_REP_CHARSETID_SIZE 6
      #define CMD_DAB_GET_COMPONENT_INFO_REP_CHARSETID_MASK 0x3F
      #define CMD_DAB_GET_COMPONENT_INFO_REP_CHARSETID_MSB  5
      #define CMD_DAB_GET_COMPONENT_INFO_REP_CHARSETID_LSB  0
      #define CMD_DAB_GET_COMPONENT_INFO_REP_CHARSETID_value (((reply_buffer[7]&0x3F)))
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL0_TYPE u8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL0_SIZE 8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL0_MASK 0xFF
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL0_MSB  7
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL0_LSB  0
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL0_INDEX 0x08
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL0_value (((reply_buffer[8])))
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL1_TYPE u8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL1_SIZE 8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL1_MASK 0xFF
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL1_MSB  7
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL1_LSB  0
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL1_INDEX 0x09
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL1_value (((reply_buffer[9])))
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL2_TYPE u8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL2_SIZE 8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL2_MASK 0xFF
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL2_MSB  7
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL2_LSB  0
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL2_INDEX 0x0A
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL2_value (((reply_buffer[10])))
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL3_TYPE u8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL3_SIZE 8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL3_MASK 0xFF
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL3_MSB  7
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL3_LSB  0
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL3_INDEX 0x0B
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL3_value (((reply_buffer[11])))
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL4_TYPE u8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL4_SIZE 8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL4_MASK 0xFF
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL4_MSB  7
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL4_LSB  0
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL4_INDEX 0x0C
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL4_value (((reply_buffer[12])))
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL5_TYPE u8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL5_SIZE 8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL5_MASK 0xFF
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL5_MSB  7
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL5_LSB  0
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL5_INDEX 0x0D
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL5_value (((reply_buffer[13])))
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL6_TYPE u8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL6_SIZE 8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL6_MASK 0xFF
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL6_MSB  7
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL6_LSB  0
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL6_INDEX 0x0E
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL6_value (((reply_buffer[14])))
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL7_TYPE u8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL7_SIZE 8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL7_MASK 0xFF
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL7_MSB  7
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL7_LSB  0
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL7_INDEX 0x0F
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL7_value (((reply_buffer[15])))
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL8_TYPE u8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL8_SIZE 8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL8_MASK 0xFF
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL8_MSB  7
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL8_LSB  0
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL8_INDEX 0x10
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL8_value (((reply_buffer[16])))
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL9_TYPE u8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL9_SIZE 8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL9_MASK 0xFF
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL9_MSB  7
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL9_LSB  0
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL9_INDEX 0x11
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL9_value (((reply_buffer[17])))
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL10_TYPE u8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL10_SIZE 8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL10_MASK 0xFF
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL10_MSB  7
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL10_LSB  0
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL10_INDEX 0x12
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL10_value (((reply_buffer[18])))
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL11_TYPE u8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL11_SIZE 8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL11_MASK 0xFF
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL11_MSB  7
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL11_LSB  0
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL11_INDEX 0x13
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL11_value (((reply_buffer[19])))
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL12_TYPE u8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL12_SIZE 8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL12_MASK 0xFF
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL12_MSB  7
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL12_LSB  0
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL12_INDEX 0x14
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL12_value (((reply_buffer[20])))
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL13_TYPE u8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL13_SIZE 8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL13_MASK 0xFF
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL13_MSB  7
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL13_LSB  0
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL13_INDEX 0x15
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL13_value (((reply_buffer[21])))
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL14_TYPE u8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL14_SIZE 8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL14_MASK 0xFF
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL14_MSB  7
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL14_LSB  0
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL14_INDEX 0x16
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL14_value (((reply_buffer[22])))
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL15_TYPE u8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL15_SIZE 8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL15_MASK 0xFF
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL15_MSB  7
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL15_LSB  0
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL15_INDEX 0x17
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LABEL15_value (((reply_buffer[23])))
      #define CMD_DAB_GET_COMPONENT_INFO_REP_CHAR_ABREV_TYPE u16
      #define CMD_DAB_GET_COMPONENT_INFO_REP_CHAR_ABREV_SIZE 16
      #define CMD_DAB_GET_COMPONENT_INFO_REP_CHAR_ABREV_MASK 0xFFFF
      #define CMD_DAB_GET_COMPONENT_INFO_REP_CHAR_ABREV_MSB  15
      #define CMD_DAB_GET_COMPONENT_INFO_REP_CHAR_ABREV_LSB  0
      #define CMD_DAB_GET_COMPONENT_INFO_REP_CHAR_ABREV_INDEX 0x18
      #define CMD_DAB_GET_COMPONENT_INFO_REP_CHAR_ABREV_value (((reply_buffer_u16[12])))
      #define CMD_DAB_GET_COMPONENT_INFO_REP_NUMUA_TYPE u8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_NUMUA_SIZE 8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_NUMUA_MASK 0xFF
      #define CMD_DAB_GET_COMPONENT_INFO_REP_NUMUA_MSB  7
      #define CMD_DAB_GET_COMPONENT_INFO_REP_NUMUA_LSB  0
      #define CMD_DAB_GET_COMPONENT_INFO_REP_NUMUA_INDEX 0x1A
      #define CMD_DAB_GET_COMPONENT_INFO_REP_NUMUA_value (((reply_buffer[26])))
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LENUA_TYPE u8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LENUA_SIZE 8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LENUA_MASK 0xFF
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LENUA_MSB  7
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LENUA_LSB  0
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LENUA_INDEX 0x1B
      #define CMD_DAB_GET_COMPONENT_INFO_REP_LENUA_value (((reply_buffer[27])))
      #define CMD_DAB_GET_COMPONENT_INFO_REP_UATYPE_TYPE u16
      #define CMD_DAB_GET_COMPONENT_INFO_REP_UATYPE_SIZE 16
      #define CMD_DAB_GET_COMPONENT_INFO_REP_UATYPE_MASK 0xFFFF
      #define CMD_DAB_GET_COMPONENT_INFO_REP_UATYPE_MSB  15
      #define CMD_DAB_GET_COMPONENT_INFO_REP_UATYPE_LSB  0
      #define CMD_DAB_GET_COMPONENT_INFO_REP_UATYPE_INDEX 0x1C
      #define CMD_DAB_GET_COMPONENT_INFO_REP_UATYPE_value (((reply_buffer_u16[14])))
      #define CMD_DAB_GET_COMPONENT_INFO_REP_UADATALEN_TYPE u8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_UADATALEN_SIZE 8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_UADATALEN_MASK 0xFF
      #define CMD_DAB_GET_COMPONENT_INFO_REP_UADATALEN_MSB  7
      #define CMD_DAB_GET_COMPONENT_INFO_REP_UADATALEN_LSB  0
      #define CMD_DAB_GET_COMPONENT_INFO_REP_UADATALEN_INDEX 0x1E
      #define CMD_DAB_GET_COMPONENT_INFO_REP_UADATALEN_value (((reply_buffer[30])))
      #define CMD_DAB_GET_COMPONENT_INFO_REP_UADATA0_TYPE u8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_UADATA0_SIZE 8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_UADATA0_MASK 0xFF
      #define CMD_DAB_GET_COMPONENT_INFO_REP_UADATA0_MSB  7
      #define CMD_DAB_GET_COMPONENT_INFO_REP_UADATA0_LSB  0
      #define CMD_DAB_GET_COMPONENT_INFO_REP_UADATA0_INDEX 0x1F
      #define CMD_DAB_GET_COMPONENT_INFO_REP_UADATA0_value (((reply_buffer[31])))
      #define CMD_DAB_GET_COMPONENT_INFO_REP_UADATAN_TYPE u8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_UADATAN_SIZE 8
      #define CMD_DAB_GET_COMPONENT_INFO_REP_UADATAN_MASK 0xFF
      #define CMD_DAB_GET_COMPONENT_INFO_REP_UADATAN_MSB  7
      #define CMD_DAB_GET_COMPONENT_INFO_REP_UADATAN_LSB  0
      #define CMD_DAB_GET_COMPONENT_INFO_REP_UADATAN_INDEX 0x20
      #define CMD_DAB_GET_COMPONENT_INFO_REP_UADATAN_value (((reply_buffer[32])))

#define CMD_DAB_GET_TIME         0xBC
#define CMD_DAB_GET_TIME_LENGTH 2
#define CMD_DAB_GET_TIME_REP_LENGTH 11
//DAB_GET_TIME ARGS
      #define CMD_DAB_GET_TIME_ARG_TIME_TYPE_TYPE u8
      #define CMD_DAB_GET_TIME_ARG_TIME_TYPE_SIZE 8
      #define CMD_DAB_GET_TIME_ARG_TIME_TYPE_MASK 0xFF
      #define CMD_DAB_GET_TIME_ARG_TIME_TYPE_MSB  7
      #define CMD_DAB_GET_TIME_ARG_TIME_TYPE_LSB  0
      #define CMD_DAB_GET_TIME_ARG_TIME_TYPE_INDEX 0x01
      #define CMD_DAB_GET_TIME_ARG_TIME_TYPE_write_u8(x) (cmd_arg[1] = (x))
//DAB_GET_TIME REPLY
      #define CMD_DAB_GET_TIME_REP_YEAR_TYPE u16
      #define CMD_DAB_GET_TIME_REP_YEAR_SIZE 16
      #define CMD_DAB_GET_TIME_REP_YEAR_MASK 0xFFFF
      #define CMD_DAB_GET_TIME_REP_YEAR_MSB  15
      #define CMD_DAB_GET_TIME_REP_YEAR_LSB  0
      #define CMD_DAB_GET_TIME_REP_YEAR_INDEX 0x04
      #define CMD_DAB_GET_TIME_REP_YEAR_value (((reply_buffer_u16[2])))
      #define CMD_DAB_GET_TIME_REP_MONTHS_TYPE u8
      #define CMD_DAB_GET_TIME_REP_MONTHS_SIZE 8
      #define CMD_DAB_GET_TIME_REP_MONTHS_MASK 0xFF
      #define CMD_DAB_GET_TIME_REP_MONTHS_MSB  7
      #define CMD_DAB_GET_TIME_REP_MONTHS_LSB  0
      #define CMD_DAB_GET_TIME_REP_MONTHS_INDEX 0x06
      #define CMD_DAB_GET_TIME_REP_MONTHS_value (((reply_buffer[6])))
      #define CMD_DAB_GET_TIME_REP_DAYS_TYPE u8
      #define CMD_DAB_GET_TIME_REP_DAYS_SIZE 8
      #define CMD_DAB_GET_TIME_REP_DAYS_MASK 0xFF
      #define CMD_DAB_GET_TIME_REP_DAYS_MSB  7
      #define CMD_DAB_GET_TIME_REP_DAYS_LSB  0
      #define CMD_DAB_GET_TIME_REP_DAYS_INDEX 0x07
      #define CMD_DAB_GET_TIME_REP_DAYS_value (((reply_buffer[7])))
      #define CMD_DAB_GET_TIME_REP_HOURS_TYPE u8
      #define CMD_DAB_GET_TIME_REP_HOURS_SIZE 8
      #define CMD_DAB_GET_TIME_REP_HOURS_MASK 0xFF
      #define CMD_DAB_GET_TIME_REP_HOURS_MSB  7
      #define CMD_DAB_GET_TIME_REP_HOURS_LSB  0
      #define CMD_DAB_GET_TIME_REP_HOURS_INDEX 0x08
      #define CMD_DAB_GET_TIME_REP_HOURS_value (((reply_buffer[8])))
      #define CMD_DAB_GET_TIME_REP_MINUTES_TYPE u8
      #define CMD_DAB_GET_TIME_REP_MINUTES_SIZE 8
      #define CMD_DAB_GET_TIME_REP_MINUTES_MASK 0xFF
      #define CMD_DAB_GET_TIME_REP_MINUTES_MSB  7
      #define CMD_DAB_GET_TIME_REP_MINUTES_LSB  0
      #define CMD_DAB_GET_TIME_REP_MINUTES_INDEX 0x09
      #define CMD_DAB_GET_TIME_REP_MINUTES_value (((reply_buffer[9])))
      #define CMD_DAB_GET_TIME_REP_SECONDS_TYPE u8
      #define CMD_DAB_GET_TIME_REP_SECONDS_SIZE 8
      #define CMD_DAB_GET_TIME_REP_SECONDS_MASK 0xFF
      #define CMD_DAB_GET_TIME_REP_SECONDS_MSB  7
      #define CMD_DAB_GET_TIME_REP_SECONDS_LSB  0
      #define CMD_DAB_GET_TIME_REP_SECONDS_INDEX 0x0A
      #define CMD_DAB_GET_TIME_REP_SECONDS_value (((reply_buffer[10])))

#define CMD_DAB_GET_AUDIO_INFO   0xBD
#define CMD_DAB_GET_AUDIO_INFO_LENGTH 2
#define CMD_DAB_GET_AUDIO_INFO_REP_LENGTH 10
//DAB_GET_AUDIO_INFO REPLY
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_BIT_RATE_TYPE u16
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_BIT_RATE_SIZE 16
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_BIT_RATE_MASK 0xFFFF
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_BIT_RATE_MSB  15
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_BIT_RATE_LSB  0
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_BIT_RATE_INDEX 0x04
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_BIT_RATE_value (((reply_buffer_u16[2])))
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_SAMPLE_RATE_TYPE u16
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_SAMPLE_RATE_SIZE 16
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_SAMPLE_RATE_MASK 0xFFFF
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_SAMPLE_RATE_MSB  15
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_SAMPLE_RATE_LSB  0
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_SAMPLE_RATE_INDEX 0x06
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_SAMPLE_RATE_value (((reply_buffer_u16[3])))
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_PS_FLAG_TYPE bitfield
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_PS_FLAG_SIZE 1
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_PS_FLAG_MASK 0x08
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_PS_FLAG_BIT  0x08
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_PS_FLAG_MSB  3
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_PS_FLAG_LSB  3
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_PS_FLAG_is_true (reply_buffer[8]&0x8)
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_PS_FLAG_value (((reply_buffer[8]&0x8))>>3)
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_PS_FLAG_ENUM_SBR_FLAG_OFF 0
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_PS_FLAG_ENUM_SBR_FLAG_ON 1
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_SBR_FLAG_TYPE bitfield
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_SBR_FLAG_SIZE 1
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_SBR_FLAG_MASK 0x04
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_SBR_FLAG_BIT  0x04
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_SBR_FLAG_MSB  2
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_SBR_FLAG_LSB  2
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_SBR_FLAG_is_true (reply_buffer[8]&0x4)
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_SBR_FLAG_value (((reply_buffer[8]&0x4))>>2)
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_SBR_FLAG_ENUM_SBR_FLAG_OFF 0
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_SBR_FLAG_ENUM_SBR_FLAG_ON 1
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_MODE_TYPE bitfield
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_MODE_SIZE 2
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_MODE_MASK 0x03
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_MODE_MSB  1
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_MODE_LSB  0
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_MODE_value (((reply_buffer[8]&0x3)))
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_MODE_ENUM_AM_DUAL 0
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_MODE_ENUM_AM_SINGLE 1
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_MODE_ENUM_AM_STEREO 2
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_MODE_ENUM_AM_JOINT 3
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_DRC_GAIN_TYPE u8
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_DRC_GAIN_SIZE 8
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_DRC_GAIN_MASK 0xFF
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_DRC_GAIN_MSB  7
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_DRC_GAIN_LSB  0
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_DRC_GAIN_INDEX 0x09
      #define CMD_DAB_GET_AUDIO_INFO_REP_AUDIO_DRC_GAIN_value (((reply_buffer[9])))

#define CMD_DAB_GET_SUBCHAN_INFO 0xBE
#define CMD_DAB_GET_SUBCHAN_INFO_LENGTH 12
#define CMD_DAB_GET_SUBCHAN_INFO_REP_LENGTH 12
//DAB_GET_SUBCHAN_INFO ARGS
      #define CMD_DAB_GET_SUBCHAN_INFO_ARG_SERVICEID_TYPE u32
      #define CMD_DAB_GET_SUBCHAN_INFO_ARG_SERVICEID_SIZE 32
      #define CMD_DAB_GET_SUBCHAN_INFO_ARG_SERVICEID_MASK 0xFFFFFFFF
      #define CMD_DAB_GET_SUBCHAN_INFO_ARG_SERVICEID_MSB  31
      #define CMD_DAB_GET_SUBCHAN_INFO_ARG_SERVICEID_LSB  0
      #define CMD_DAB_GET_SUBCHAN_INFO_ARG_SERVICEID_INDEX 0x04
      #define CMD_DAB_GET_SUBCHAN_INFO_ARG_SERVICEID_write_u32(x) (cmd_arg_u32[1] = (x))
      #define CMD_DAB_GET_SUBCHAN_INFO_ARG_COMPID_TYPE u32
      #define CMD_DAB_GET_SUBCHAN_INFO_ARG_COMPID_SIZE 32
      #define CMD_DAB_GET_SUBCHAN_INFO_ARG_COMPID_MASK 0xFFFFFFFF
      #define CMD_DAB_GET_SUBCHAN_INFO_ARG_COMPID_MSB  31
      #define CMD_DAB_GET_SUBCHAN_INFO_ARG_COMPID_LSB  0
      #define CMD_DAB_GET_SUBCHAN_INFO_ARG_COMPID_INDEX 0x08
      #define CMD_DAB_GET_SUBCHAN_INFO_ARG_COMPID_write_u32(x) (cmd_arg_u32[2] = (x))
//DAB_GET_SUBCHAN_INFO REPLY
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_SERVICE_MODE_TYPE u8
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_SERVICE_MODE_SIZE 8
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_SERVICE_MODE_MASK 0xFF
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_SERVICE_MODE_MSB  7
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_SERVICE_MODE_LSB  0
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_SERVICE_MODE_INDEX 0x04
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_SERVICE_MODE_value (((reply_buffer[4])))
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_SERVICE_MODE_ENUM_AUDIO_STREAM_SERVICE 0
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_SERVICE_MODE_ENUM_DATA_STREAM_SERVICE 1
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_SERVICE_MODE_ENUM_FIDC_SERVICE 2
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_SERVICE_MODE_ENUM_MSC_DATA_PACKET_SERVICE 3
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_SERVICE_MODE_ENUM_DAB_PLUS 4
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_SERVICE_MODE_ENUM_DAB 5
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_SERVICE_MODE_ENUM_FIC_SERVICE 6
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_SERVICE_MODE_ENUM_XPAD_DATA 7
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_SERVICE_MODE_ENUM_NO_MEDIA 8
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_PROTECTION_INFO_TYPE u8
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_PROTECTION_INFO_SIZE 8
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_PROTECTION_INFO_MASK 0xFF
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_PROTECTION_INFO_MSB  7
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_PROTECTION_INFO_LSB  0
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_PROTECTION_INFO_INDEX 0x05
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_PROTECTION_INFO_value (((reply_buffer[5])))
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_PROTECTION_INFO_ENUM_UEP_L1 1
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_PROTECTION_INFO_ENUM_UEP_L2 2
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_PROTECTION_INFO_ENUM_UEP_L3 3
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_PROTECTION_INFO_ENUM_UEP_L4 4
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_PROTECTION_INFO_ENUM_UEP_L5 5
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_PROTECTION_INFO_ENUM_EEP_L6 6
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_PROTECTION_INFO_ENUM_EEP_L7 7
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_PROTECTION_INFO_ENUM_EEP_L8 8
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_PROTECTION_INFO_ENUM_EEP_L9 9
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_PROTECTION_INFO_ENUM_EEP_L10 10
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_PROTECTION_INFO_ENUM_EEP_L11 11
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_PROTECTION_INFO_ENUM_EEP_L12 12
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_PROTECTION_INFO_ENUM_EEP_L13 13
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_SUBCHAN_BIT_RATE_TYPE u16
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_SUBCHAN_BIT_RATE_SIZE 16
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_SUBCHAN_BIT_RATE_MASK 0xFFFF
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_SUBCHAN_BIT_RATE_MSB  15
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_SUBCHAN_BIT_RATE_LSB  0
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_SUBCHAN_BIT_RATE_INDEX 0x06
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_SUBCHAN_BIT_RATE_value (((reply_buffer_u16[3])))
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_NUM_CU_TYPE u16
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_NUM_CU_SIZE 16
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_NUM_CU_MASK 0xFFFF
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_NUM_CU_MSB  15
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_NUM_CU_LSB  0
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_NUM_CU_INDEX 0x08
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_NUM_CU_value (((reply_buffer_u16[4])))
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_CU_ADDRESS_TYPE u16
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_CU_ADDRESS_SIZE 16
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_CU_ADDRESS_MASK 0xFFFF
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_CU_ADDRESS_MSB  15
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_CU_ADDRESS_LSB  0
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_CU_ADDRESS_INDEX 0x0A
      #define CMD_DAB_GET_SUBCHAN_INFO_REP_CU_ADDRESS_value (((reply_buffer_u16[5])))

#define CMD_DAB_GET_FREQ_INFO    0xBF
#define CMD_DAB_GET_FREQ_INFO_LENGTH 2
#define CMD_DAB_GET_FREQ_INFO_REP_LENGTH 20
//DAB_GET_FREQ_INFO REPLY
      #define CMD_DAB_GET_FREQ_INFO_REP_LENGTH_FI_LIST_TYPE u32
      #define CMD_DAB_GET_FREQ_INFO_REP_LENGTH_FI_LIST_SIZE 32
      #define CMD_DAB_GET_FREQ_INFO_REP_LENGTH_FI_LIST_MASK 0xFFFFFFFF
      #define CMD_DAB_GET_FREQ_INFO_REP_LENGTH_FI_LIST_MSB  31
      #define CMD_DAB_GET_FREQ_INFO_REP_LENGTH_FI_LIST_LSB  0
      #define CMD_DAB_GET_FREQ_INFO_REP_LENGTH_FI_LIST_INDEX 0x04
      #define CMD_DAB_GET_FREQ_INFO_REP_LENGTH_FI_LIST_value (((reply_buffer_u32[1])))
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_ID_0_TYPE u32
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_ID_0_SIZE 32
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_ID_0_MASK 0xFFFFFFFF
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_ID_0_MSB  31
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_ID_0_LSB  0
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_ID_0_INDEX 0x08
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_ID_0_value (((reply_buffer_u32[2])))
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_FREQ_0_TYPE u32
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_FREQ_0_SIZE 32
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_FREQ_0_MASK 0xFFFFFFFF
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_FREQ_0_MSB  31
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_FREQ_0_LSB  0
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_FREQ_0_INDEX 0x0C
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_FREQ_0_value (((reply_buffer_u32[3])))
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_FREQ_INDEX_0_TYPE i8
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_FREQ_INDEX_0_SIZE 8
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_FREQ_INDEX_0_MASK 0xFF
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_FREQ_INDEX_0_MSB  7
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_FREQ_INDEX_0_LSB  0
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_FREQ_INDEX_0_INDEX 0x10
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_FREQ_INDEX_0_value (((uint8_t)(reply_buffer[16])))
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_RNM_0_TYPE u8
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_RNM_0_SIZE 8
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_RNM_0_MASK 0xFF
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_RNM_0_MSB  7
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_RNM_0_LSB  0
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_RNM_0_INDEX 0x11
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_RNM_0_value (((reply_buffer[17])))
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_CONTINUITY_0_TYPE u8
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_CONTINUITY_0_SIZE 8
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_CONTINUITY_0_MASK 0xFF
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_CONTINUITY_0_MSB  7
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_CONTINUITY_0_LSB  0
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_CONTINUITY_0_INDEX 0x12
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_CONTINUITY_0_value (((reply_buffer[18])))
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_CONTROL_0_TYPE u8
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_CONTROL_0_SIZE 8
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_CONTROL_0_MASK 0xFF
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_CONTROL_0_MSB  7
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_CONTROL_0_LSB  0
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_CONTROL_0_INDEX 0x13
      #define CMD_DAB_GET_FREQ_INFO_REP_FI_CONTROL_0_value (((reply_buffer[19])))

#define CMD_DAB_GET_SERVICE_INFO 0xC0
#define CMD_DAB_GET_SERVICE_INFO_LENGTH 8
#define CMD_DAB_GET_SERVICE_INFO_REP_LENGTH 26
//DAB_GET_SERVICE_INFO ARGS
      #define CMD_DAB_GET_SERVICE_INFO_ARG_SERVICEID_TYPE u32
      #define CMD_DAB_GET_SERVICE_INFO_ARG_SERVICEID_SIZE 32
      #define CMD_DAB_GET_SERVICE_INFO_ARG_SERVICEID_MASK 0xFFFFFFFF
      #define CMD_DAB_GET_SERVICE_INFO_ARG_SERVICEID_MSB  31
      #define CMD_DAB_GET_SERVICE_INFO_ARG_SERVICEID_LSB  0
      #define CMD_DAB_GET_SERVICE_INFO_ARG_SERVICEID_INDEX 0x04
      #define CMD_DAB_GET_SERVICE_INFO_ARG_SERVICEID_write_u32(x) (cmd_arg_u32[1] = (x))
//DAB_GET_SERVICE_INFO REPLY
      #define CMD_DAB_GET_SERVICE_INFO_REP_SRV_LINKING_INFO_TYPE bitfield
      #define CMD_DAB_GET_SERVICE_INFO_REP_SRV_LINKING_INFO_SIZE 1
      #define CMD_DAB_GET_SERVICE_INFO_REP_SRV_LINKING_INFO_MASK 0x40
      #define CMD_DAB_GET_SERVICE_INFO_REP_SRV_LINKING_INFO_BIT  0x40
      #define CMD_DAB_GET_SERVICE_INFO_REP_SRV_LINKING_INFO_MSB  6
      #define CMD_DAB_GET_SERVICE_INFO_REP_SRV_LINKING_INFO_LSB  6
      #define CMD_DAB_GET_SERVICE_INFO_REP_SRV_LINKING_INFO_is_true (reply_buffer[4]&0x40)
      #define CMD_DAB_GET_SERVICE_INFO_REP_SRV_LINKING_INFO_value (((reply_buffer[4]&0x40))>>6)
      #define CMD_DAB_GET_SERVICE_INFO_REP_PTY_TYPE bitfield
      #define CMD_DAB_GET_SERVICE_INFO_REP_PTY_SIZE 5
      #define CMD_DAB_GET_SERVICE_INFO_REP_PTY_MASK 0x3E
      #define CMD_DAB_GET_SERVICE_INFO_REP_PTY_MSB  5
      #define CMD_DAB_GET_SERVICE_INFO_REP_PTY_LSB  1
      #define CMD_DAB_GET_SERVICE_INFO_REP_PTY_value (((reply_buffer[4]&0x3E))>>1)
      #define CMD_DAB_GET_SERVICE_INFO_REP_PD_FLAG_TYPE bitfield
      #define CMD_DAB_GET_SERVICE_INFO_REP_PD_FLAG_SIZE 1
      #define CMD_DAB_GET_SERVICE_INFO_REP_PD_FLAG_MASK 0x01
      #define CMD_DAB_GET_SERVICE_INFO_REP_PD_FLAG_BIT  0x01
      #define CMD_DAB_GET_SERVICE_INFO_REP_PD_FLAG_MSB  0
      #define CMD_DAB_GET_SERVICE_INFO_REP_PD_FLAG_LSB  0
      #define CMD_DAB_GET_SERVICE_INFO_REP_PD_FLAG_is_true (reply_buffer[4]&0x1)
      #define CMD_DAB_GET_SERVICE_INFO_REP_PD_FLAG_value (((reply_buffer[4]&0x1)))
      #define CMD_DAB_GET_SERVICE_INFO_REP_LOCAL_TYPE bitfield
      #define CMD_DAB_GET_SERVICE_INFO_REP_LOCAL_SIZE 1
      #define CMD_DAB_GET_SERVICE_INFO_REP_LOCAL_MASK 0x80
      #define CMD_DAB_GET_SERVICE_INFO_REP_LOCAL_BIT  0x80
      #define CMD_DAB_GET_SERVICE_INFO_REP_LOCAL_MSB  7
      #define CMD_DAB_GET_SERVICE_INFO_REP_LOCAL_LSB  7
      #define CMD_DAB_GET_SERVICE_INFO_REP_LOCAL_is_true (reply_buffer[5]&0x80)
      #define CMD_DAB_GET_SERVICE_INFO_REP_LOCAL_value (((reply_buffer[5]&0x80))>>7)
      #define CMD_DAB_GET_SERVICE_INFO_REP_CAID_TYPE bitfield
      #define CMD_DAB_GET_SERVICE_INFO_REP_CAID_SIZE 3
      #define CMD_DAB_GET_SERVICE_INFO_REP_CAID_MASK 0x70
      #define CMD_DAB_GET_SERVICE_INFO_REP_CAID_MSB  6
      #define CMD_DAB_GET_SERVICE_INFO_REP_CAID_LSB  4
      #define CMD_DAB_GET_SERVICE_INFO_REP_CAID_value (((reply_buffer[5]&0x70))>>4)
      #define CMD_DAB_GET_SERVICE_INFO_REP_NUM_COMP_TYPE bitfield
      #define CMD_DAB_GET_SERVICE_INFO_REP_NUM_COMP_SIZE 4
      #define CMD_DAB_GET_SERVICE_INFO_REP_NUM_COMP_MASK 0x0F
      #define CMD_DAB_GET_SERVICE_INFO_REP_NUM_COMP_MSB  3
      #define CMD_DAB_GET_SERVICE_INFO_REP_NUM_COMP_LSB  0
      #define CMD_DAB_GET_SERVICE_INFO_REP_NUM_COMP_value (((reply_buffer[5]&0xF)))
      #define CMD_DAB_GET_SERVICE_INFO_REP_SICHARSET_TYPE bitfield
      #define CMD_DAB_GET_SERVICE_INFO_REP_SICHARSET_SIZE 4
      #define CMD_DAB_GET_SERVICE_INFO_REP_SICHARSET_MASK 0x0F
      #define CMD_DAB_GET_SERVICE_INFO_REP_SICHARSET_MSB  3
      #define CMD_DAB_GET_SERVICE_INFO_REP_SICHARSET_LSB  0
      #define CMD_DAB_GET_SERVICE_INFO_REP_SICHARSET_value (((reply_buffer[6]&0xF)))
      #define CMD_DAB_GET_SERVICE_INFO_REP_SRV_ECC_TYPE u8
      #define CMD_DAB_GET_SERVICE_INFO_REP_SRV_ECC_SIZE 8
      #define CMD_DAB_GET_SERVICE_INFO_REP_SRV_ECC_MASK 0xFF
      #define CMD_DAB_GET_SERVICE_INFO_REP_SRV_ECC_MSB  7
      #define CMD_DAB_GET_SERVICE_INFO_REP_SRV_ECC_LSB  0
      #define CMD_DAB_GET_SERVICE_INFO_REP_SRV_ECC_INDEX 0x07
      #define CMD_DAB_GET_SERVICE_INFO_REP_SRV_ECC_value (((reply_buffer[7])))
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL0_TYPE u8
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL0_SIZE 8
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL0_MASK 0xFF
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL0_MSB  7
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL0_LSB  0
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL0_INDEX 0x08
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL0_value (((reply_buffer[8])))
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL1_TYPE u8
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL1_SIZE 8
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL1_MASK 0xFF
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL1_MSB  7
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL1_LSB  0
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL1_INDEX 0x09
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL1_value (((reply_buffer[9])))
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL2_TYPE u8
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL2_SIZE 8
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL2_MASK 0xFF
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL2_MSB  7
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL2_LSB  0
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL2_INDEX 0x0A
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL2_value (((reply_buffer[10])))
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL3_TYPE u8
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL3_SIZE 8
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL3_MASK 0xFF
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL3_MSB  7
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL3_LSB  0
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL3_INDEX 0x0B
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL3_value (((reply_buffer[11])))
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL4_TYPE u8
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL4_SIZE 8
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL4_MASK 0xFF
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL4_MSB  7
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL4_LSB  0
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL4_INDEX 0x0C
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL4_value (((reply_buffer[12])))
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL5_TYPE u8
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL5_SIZE 8
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL5_MASK 0xFF
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL5_MSB  7
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL5_LSB  0
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL5_INDEX 0x0D
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL5_value (((reply_buffer[13])))
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL6_TYPE u8
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL6_SIZE 8
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL6_MASK 0xFF
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL6_MSB  7
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL6_LSB  0
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL6_INDEX 0x0E
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL6_value (((reply_buffer[14])))
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL7_TYPE u8
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL7_SIZE 8
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL7_MASK 0xFF
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL7_MSB  7
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL7_LSB  0
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL7_INDEX 0x0F
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL7_value (((reply_buffer[15])))
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL8_TYPE u8
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL8_SIZE 8
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL8_MASK 0xFF
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL8_MSB  7
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL8_LSB  0
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL8_INDEX 0x10
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL8_value (((reply_buffer[16])))
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL9_TYPE u8
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL9_SIZE 8
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL9_MASK 0xFF
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL9_MSB  7
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL9_LSB  0
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL9_INDEX 0x11
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL9_value (((reply_buffer[17])))
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL10_TYPE u8
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL10_SIZE 8
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL10_MASK 0xFF
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL10_MSB  7
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL10_LSB  0
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL10_INDEX 0x12
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL10_value (((reply_buffer[18])))
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL11_TYPE u8
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL11_SIZE 8
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL11_MASK 0xFF
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL11_MSB  7
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL11_LSB  0
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL11_INDEX 0x13
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL11_value (((reply_buffer[19])))
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL12_TYPE u8
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL12_SIZE 8
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL12_MASK 0xFF
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL12_MSB  7
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL12_LSB  0
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL12_INDEX 0x14
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL12_value (((reply_buffer[20])))
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL13_TYPE u8
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL13_SIZE 8
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL13_MASK 0xFF
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL13_MSB  7
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL13_LSB  0
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL13_INDEX 0x15
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL13_value (((reply_buffer[21])))
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL14_TYPE u8
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL14_SIZE 8
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL14_MASK 0xFF
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL14_MSB  7
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL14_LSB  0
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL14_INDEX 0x16
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL14_value (((reply_buffer[22])))
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL15_TYPE u8
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL15_SIZE 8
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL15_MASK 0xFF
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL15_MSB  7
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL15_LSB  0
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL15_INDEX 0x17
      #define CMD_DAB_GET_SERVICE_INFO_REP_LABEL15_value (((reply_buffer[23])))
      #define CMD_DAB_GET_SERVICE_INFO_REP_CHAR_ABREV_TYPE u16
      #define CMD_DAB_GET_SERVICE_INFO_REP_CHAR_ABREV_SIZE 16
      #define CMD_DAB_GET_SERVICE_INFO_REP_CHAR_ABREV_MASK 0xFFFF
      #define CMD_DAB_GET_SERVICE_INFO_REP_CHAR_ABREV_MSB  15
      #define CMD_DAB_GET_SERVICE_INFO_REP_CHAR_ABREV_LSB  0
      #define CMD_DAB_GET_SERVICE_INFO_REP_CHAR_ABREV_INDEX 0x18
      #define CMD_DAB_GET_SERVICE_INFO_REP_CHAR_ABREV_value (((reply_buffer_u16[12])))

//Note: this was manually corrected from the 4.0.4 build's output, need to confirm it matches once we re-integrate
#define CMD_DAB_GET_OE_SERVICES_INFO 0xC1
#define CMD_DAB_GET_OE_SERVICES_INFO_LENGTH 8
#define CMD_DAB_GET_OE_SERVICES_INFO_REP_LENGTH 10
//DAB_GET_OE_SERVICES_INFO ARGS
      #define CMD_DAB_GET_OE_SERVICES_INFO_ARG_SERVICEID_TYPE u32
      #define CMD_DAB_GET_OE_SERVICES_INFO_ARG_SERVICEID_SIZE 32
      #define CMD_DAB_GET_OE_SERVICES_INFO_ARG_SERVICEID_MASK 0xFFFFFFFF
      #define CMD_DAB_GET_OE_SERVICES_INFO_ARG_SERVICEID_MSB  31
      #define CMD_DAB_GET_OE_SERVICES_INFO_ARG_SERVICEID_LSB  0
      #define CMD_DAB_GET_OE_SERVICES_INFO_ARG_SERVICEID_INDEX 0x04
      #define CMD_DAB_GET_OE_SERVICES_INFO_ARG_SERVICEID_write_u32(x) (cmd_arg_u32[1] = (x))
//DAB_GET_OE_SERVICES_INFO REPLY
      #define CMD_DAB_GET_OE_SERVICES_INFO_REP_SIZE_TYPE u16
      #define CMD_DAB_GET_OE_SERVICES_INFO_REP_SIZE_SIZE 16
      #define CMD_DAB_GET_OE_SERVICES_INFO_REP_SIZE_MASK 0xFFFF
      #define CMD_DAB_GET_OE_SERVICES_INFO_REP_SIZE_MSB  15
      #define CMD_DAB_GET_OE_SERVICES_INFO_REP_SIZE_LSB  0
      #define CMD_DAB_GET_OE_SERVICES_INFO_REP_SIZE_INDEX 0x04
      #define CMD_DAB_GET_OE_SERVICES_INFO_REP_SIZE_value (((reply_buffer_u16[2])))
      #define CMD_DAB_GET_OE_SERVICES_INFO_REP_NUM_EIDS_TYPE u8
      #define CMD_DAB_GET_OE_SERVICES_INFO_REP_NUM_EIDS_SIZE 8
      #define CMD_DAB_GET_OE_SERVICES_INFO_REP_NUM_EIDS_MASK 0xFF
      #define CMD_DAB_GET_OE_SERVICES_INFO_REP_NUM_EIDS_MSB  7
      #define CMD_DAB_GET_OE_SERVICES_INFO_REP_NUM_EIDS_LSB  0
      #define CMD_DAB_GET_OE_SERVICES_INFO_REP_NUM_EIDS_INDEX 0x06
      #define CMD_DAB_GET_OE_SERVICES_INFO_REP_NUM_EIDS_value (((reply_buffer[6])))
      #define CMD_DAB_GET_OE_SERVICES_INFO_REP_EID_0_TYPE u16
      #define CMD_DAB_GET_OE_SERVICES_INFO_REP_EID_0_SIZE 16
      #define CMD_DAB_GET_OE_SERVICES_INFO_REP_EID_0_MASK 0xFFFF
      #define CMD_DAB_GET_OE_SERVICES_INFO_REP_EID_0_MSB  15
      #define CMD_DAB_GET_OE_SERVICES_INFO_REP_EID_0_LSB  0
      #define CMD_DAB_GET_OE_SERVICES_INFO_REP_EID_0_INDEX 0x08
      #define CMD_DAB_GET_OE_SERVICES_INFO_REP_EID_0_value (((reply_buffer_u16[4])))
#define CMD_DAB_ACF_STATUS       0xC2
#define CMD_DAB_ACF_STATUS_LENGTH 2
#define CMD_DAB_ACF_STATUS_REP_LENGTH 10
      #define CMD_DAB_ACF_STATUS_REP_RFU1_TYPE u8
      #define CMD_DAB_ACF_STATUS_REP_RFU1_SIZE 8
      #define CMD_DAB_ACF_STATUS_REP_RFU1_MASK 0xFF
      #define CMD_DAB_ACF_STATUS_REP_RFU1_MSB  7
      #define CMD_DAB_ACF_STATUS_REP_RFU1_LSB  0
      #define CMD_DAB_ACF_STATUS_REP_RFU1_INDEX 0x04
      #define CMD_DAB_ACF_STATUS_REP_RFU1_value (((reply_buffer[4])))
      #define CMD_DAB_ACF_STATUS_REP_RFU2_TYPE u8
      #define CMD_DAB_ACF_STATUS_REP_RFU2_SIZE 8
      #define CMD_DAB_ACF_STATUS_REP_RFU2_MASK 0xFF
      #define CMD_DAB_ACF_STATUS_REP_RFU2_MSB  7
      #define CMD_DAB_ACF_STATUS_REP_RFU2_LSB  0
      #define CMD_DAB_ACF_STATUS_REP_RFU2_INDEX 0x05
      #define CMD_DAB_ACF_STATUS_REP_RFU2_value (((reply_buffer[5])))
      #define CMD_DAB_ACF_STATUS_REP_AUDIO_LEVEL_TYPE u16
      #define CMD_DAB_ACF_STATUS_REP_AUDIO_LEVEL_SIZE 16
      #define CMD_DAB_ACF_STATUS_REP_AUDIO_LEVEL_MASK 0xFFFF
      #define CMD_DAB_ACF_STATUS_REP_AUDIO_LEVEL_MSB  15
      #define CMD_DAB_ACF_STATUS_REP_AUDIO_LEVEL_LSB  0
      #define CMD_DAB_ACF_STATUS_REP_AUDIO_LEVEL_INDEX 0x06
      #define CMD_DAB_ACF_STATUS_REP_AUDIO_LEVEL_value (((reply_buffer_u16[3])))
      #define CMD_DAB_ACF_STATUS_REP_CMFT_NOISE_LEVEL_TYPE u16
      #define CMD_DAB_ACF_STATUS_REP_CMFT_NOISE_LEVEL_SIZE 16
      #define CMD_DAB_ACF_STATUS_REP_CMFT_NOISE_LEVEL_MASK 0xFFFF
      #define CMD_DAB_ACF_STATUS_REP_CMFT_NOISE_LEVEL_MSB  15
      #define CMD_DAB_ACF_STATUS_REP_CMFT_NOISE_LEVEL_LSB  0
      #define CMD_DAB_ACF_STATUS_REP_CMFT_NOISE_LEVEL_INDEX 0x08
      #define CMD_DAB_ACF_STATUS_REP_CMFT_NOISE_LEVEL_value (((reply_buffer_u16[4])))

#define CMD_TEST_GET_RSSI        0xE5
#define CMD_TEST_GET_RSSI_LENGTH 2
#define CMD_TEST_GET_RSSI_REP_LENGTH 6
//TEST_GET_RSSI REPLY
      #define CMD_TEST_GET_RSSI_REP_RSSI_HIGHRES_TYPE i16
      #define CMD_TEST_GET_RSSI_REP_RSSI_HIGHRES_SIZE 16
      #define CMD_TEST_GET_RSSI_REP_RSSI_HIGHRES_MASK 0xFFFF
      #define CMD_TEST_GET_RSSI_REP_RSSI_HIGHRES_MSB  15
      #define CMD_TEST_GET_RSSI_REP_RSSI_HIGHRES_LSB  0
      #define CMD_TEST_GET_RSSI_REP_RSSI_HIGHRES_INDEX 0x04
      #define CMD_TEST_GET_RSSI_REP_RSSI_HIGHRES_value (((uint16_t)(reply_buffer_i16[2])))

#define CMD_DAB_TEST_GET_BER_INFO 0xE8
#define CMD_DAB_TEST_GET_BER_INFO_LENGTH 2
#define CMD_DAB_TEST_GET_BER_INFO_REP_LENGTH 12
//DAB_TEST_GET_BER_INFO REPLY
      #define CMD_DAB_TEST_GET_BER_INFO_REP_ERR_BITS_TYPE u32
      #define CMD_DAB_TEST_GET_BER_INFO_REP_ERR_BITS_SIZE 32
      #define CMD_DAB_TEST_GET_BER_INFO_REP_ERR_BITS_MASK 0xFFFFFFFF
      #define CMD_DAB_TEST_GET_BER_INFO_REP_ERR_BITS_MSB  31
      #define CMD_DAB_TEST_GET_BER_INFO_REP_ERR_BITS_LSB  0
      #define CMD_DAB_TEST_GET_BER_INFO_REP_ERR_BITS_INDEX 0x04
      #define CMD_DAB_TEST_GET_BER_INFO_REP_ERR_BITS_value (((reply_buffer_u32[1])))
      #define CMD_DAB_TEST_GET_BER_INFO_REP_TOTAL_BITS_TYPE u32
      #define CMD_DAB_TEST_GET_BER_INFO_REP_TOTAL_BITS_SIZE 32
      #define CMD_DAB_TEST_GET_BER_INFO_REP_TOTAL_BITS_MASK 0xFFFFFFFF
      #define CMD_DAB_TEST_GET_BER_INFO_REP_TOTAL_BITS_MSB  31
      #define CMD_DAB_TEST_GET_BER_INFO_REP_TOTAL_BITS_LSB  0
      #define CMD_DAB_TEST_GET_BER_INFO_REP_TOTAL_BITS_INDEX 0x08
      #define CMD_DAB_TEST_GET_BER_INFO_REP_TOTAL_BITS_value (((reply_buffer_u32[2])))
// Reply Status
    #define REP_STATUS_value cmd_reply_STATUS
      #define REP_STATUS_STCINT_TYPE bit
      #define REP_STATUS_STCINT_SIZE 1
      #define REP_STATUS_STCINT_MASK 0x01
      #define REP_STATUS_STCINT_BIT  0x01
      #define REP_STATUS_STCINT_MSB  0
      #define REP_STATUS_STCINT_LSB  0
      #define REP_STATUS_ACFINT_TYPE bit
      #define REP_STATUS_ACFINT_SIZE 1
      #define REP_STATUS_ACFINT_MASK 0x02
      #define REP_STATUS_ACFINT_BIT  0x02
      #define REP_STATUS_ACFINT_MSB  1
      #define REP_STATUS_ACFINT_LSB  1
      #define REP_STATUS_RDSINT_TYPE bit
      #define REP_STATUS_RDSINT_SIZE 1
      #define REP_STATUS_RDSINT_MASK 0x04
      #define REP_STATUS_RDSINT_BIT  0x04
      #define REP_STATUS_RDSINT_MSB  2
      #define REP_STATUS_RDSINT_LSB  2
      #define REP_STATUS_RSQINT_TYPE bit
      #define REP_STATUS_RSQINT_SIZE 1
      #define REP_STATUS_RSQINT_MASK 0x08
      #define REP_STATUS_RSQINT_BIT  0x08
      #define REP_STATUS_RSQINT_MSB  3
      #define REP_STATUS_RSQINT_LSB  3
      #define REP_STATUS_DSRVINT_TYPE bit
      #define REP_STATUS_DSRVINT_SIZE 1
      #define REP_STATUS_DSRVINT_MASK 0x10
      #define REP_STATUS_DSRVINT_BIT  0x10
      #define REP_STATUS_DSRVINT_MSB  4
      #define REP_STATUS_DSRVINT_LSB  4
      #define REP_STATUS_DACQINT_TYPE bit
      #define REP_STATUS_DACQINT_SIZE 1
      #define REP_STATUS_DACQINT_MASK 0x20
      #define REP_STATUS_DACQINT_BIT  0x20
      #define REP_STATUS_DACQINT_MSB  5
      #define REP_STATUS_DACQINT_LSB  5
      #define REP_STATUS_ERR_CMD_TYPE bit
      #define REP_STATUS_ERR_CMD_SIZE 1
      #define REP_STATUS_ERR_CMD_MASK 0x40
      #define REP_STATUS_ERR_CMD_BIT  0x40
      #define REP_STATUS_ERR_CMD_MSB  6
      #define REP_STATUS_ERR_CMD_LSB  6
      #define REP_STATUS_CTS_TYPE bit
      #define REP_STATUS_CTS_SIZE 1
      #define REP_STATUS_CTS_MASK 0x80
      #define REP_STATUS_CTS_BIT  0x80
      #define REP_STATUS_CTS_MSB  7
      #define REP_STATUS_CTS_LSB  7
      #define REP_STATUS_DACFINT_TYPE bit
      #define REP_STATUS_DACFINT_SIZE 1
      #define REP_STATUS_DACFINT_MASK 0x01
      #define REP_STATUS_DACFINT_BIT  0x01
      #define REP_STATUS_DACFINT_MSB  0
      #define REP_STATUS_DACFINT_LSB  0
      #define REP_STATUS_RSVDINT_9_TYPE bit
      #define REP_STATUS_RSVDINT_9_SIZE 1
      #define REP_STATUS_RSVDINT_9_MASK 0x02
      #define REP_STATUS_RSVDINT_9_BIT  0x02
      #define REP_STATUS_RSVDINT_9_MSB  1
      #define REP_STATUS_RSVDINT_9_LSB  1
      #define REP_STATUS_RSVDINT_10_TYPE bit
      #define REP_STATUS_RSVDINT_10_SIZE 1
      #define REP_STATUS_RSVDINT_10_MASK 0x04
      #define REP_STATUS_RSVDINT_10_BIT  0x04
      #define REP_STATUS_RSVDINT_10_MSB  2
      #define REP_STATUS_RSVDINT_10_LSB  2
      #define REP_STATUS_RSVDINT_11_TYPE bit
      #define REP_STATUS_RSVDINT_11_SIZE 1
      #define REP_STATUS_RSVDINT_11_MASK 0x08
      #define REP_STATUS_RSVDINT_11_BIT  0x08
      #define REP_STATUS_RSVDINT_11_MSB  3
      #define REP_STATUS_RSVDINT_11_LSB  3
      #define REP_STATUS_RSVDINT_12_TYPE bit
      #define REP_STATUS_RSVDINT_12_SIZE 1
      #define REP_STATUS_RSVDINT_12_MASK 0x10
      #define REP_STATUS_RSVDINT_12_BIT  0x10
      #define REP_STATUS_RSVDINT_12_MSB  4
      #define REP_STATUS_RSVDINT_12_LSB  4
      #define REP_STATUS_DEVNTINT_TYPE bit
      #define REP_STATUS_DEVNTINT_SIZE 1
      #define REP_STATUS_DEVNTINT_MASK 0x20
      #define REP_STATUS_DEVNTINT_BIT  0x20
      #define REP_STATUS_DEVNTINT_MSB  5
      #define REP_STATUS_DEVNTINT_LSB  5
      #define REP_STATUS_RSVDINT_14_TYPE bit
      #define REP_STATUS_RSVDINT_14_SIZE 1
      #define REP_STATUS_RSVDINT_14_MASK 0x40
      #define REP_STATUS_RSVDINT_14_BIT  0x40
      #define REP_STATUS_RSVDINT_14_MSB  6
      #define REP_STATUS_RSVDINT_14_LSB  6
      #define REP_STATUS_DBGINT_TYPE bit
      #define REP_STATUS_DBGINT_SIZE 1
      #define REP_STATUS_DBGINT_MASK 0x80
      #define REP_STATUS_DBGINT_BIT  0x80
      #define REP_STATUS_DBGINT_MSB  7
      #define REP_STATUS_DBGINT_LSB  7

#define PROP_INT_CTL_ENABLE_MASK 0xFFFF
#define PROP_INT_CTL_ENABLE_INDEX 0x00
#define PROP_INT_CTL_ENABLE_GROUP 0x00
#define PROP_INT_CTL_ENABLE_value() (sys_prop_ReturnProperty(PROP_INT_CTL_ENABLE_GROUP, PROP_INT_CTL_ENABLE_INDEX))
#define PROP_INT_CTL_ENABLE_DEVNTIEN_LSB 13
#define PROP_INT_CTL_ENABLE_DEVNTIEN_MSB 13
#define PROP_INT_CTL_ENABLE_DEVNTIEN_MASK 0x2000
#define PROP_INT_CTL_ENABLE_DEVNTIEN_BIT 0x2000
#define PROP_INT_CTL_ENABLE_DEVNTIEN_value() (((PROP_INT_CTL_ENABLE_value()) & 0x2000)>>13)
#define PROP_INT_CTL_ENABLE_CTSIEN_LSB 7
#define PROP_INT_CTL_ENABLE_CTSIEN_MSB 7
#define PROP_INT_CTL_ENABLE_CTSIEN_MASK 0x80
#define PROP_INT_CTL_ENABLE_CTSIEN_BIT 0x80
#define PROP_INT_CTL_ENABLE_CTSIEN_value() (((PROP_INT_CTL_ENABLE_value()) & 0x80)>>7)
#define PROP_INT_CTL_ENABLE_ERR_CMDIEN_LSB 6
#define PROP_INT_CTL_ENABLE_ERR_CMDIEN_MSB 6
#define PROP_INT_CTL_ENABLE_ERR_CMDIEN_MASK 0x40
#define PROP_INT_CTL_ENABLE_ERR_CMDIEN_BIT 0x40
#define PROP_INT_CTL_ENABLE_ERR_CMDIEN_value() (((PROP_INT_CTL_ENABLE_value()) & 0x40)>>6)
#define PROP_INT_CTL_ENABLE_DACQIEN_LSB 5
#define PROP_INT_CTL_ENABLE_DACQIEN_MSB 5
#define PROP_INT_CTL_ENABLE_DACQIEN_MASK 0x20
#define PROP_INT_CTL_ENABLE_DACQIEN_BIT 0x20
#define PROP_INT_CTL_ENABLE_DACQIEN_value() (((PROP_INT_CTL_ENABLE_value()) & 0x20)>>5)
#define PROP_INT_CTL_ENABLE_DSRVIEN_LSB 4
#define PROP_INT_CTL_ENABLE_DSRVIEN_MSB 4
#define PROP_INT_CTL_ENABLE_DSRVIEN_MASK 0x10
#define PROP_INT_CTL_ENABLE_DSRVIEN_BIT 0x10
#define PROP_INT_CTL_ENABLE_DSRVIEN_value() (((PROP_INT_CTL_ENABLE_value()) & 0x10)>>4)
#define PROP_INT_CTL_ENABLE_RSQIEN_LSB 3
#define PROP_INT_CTL_ENABLE_RSQIEN_MSB 3
#define PROP_INT_CTL_ENABLE_RSQIEN_MASK 0x8
#define PROP_INT_CTL_ENABLE_RSQIEN_BIT 0x8
#define PROP_INT_CTL_ENABLE_RSQIEN_value() (((PROP_INT_CTL_ENABLE_value()) & 0x8)>>3)
#define PROP_INT_CTL_ENABLE_RDSIEN_LSB 2
#define PROP_INT_CTL_ENABLE_RDSIEN_MSB 2
#define PROP_INT_CTL_ENABLE_RDSIEN_MASK 0x4
#define PROP_INT_CTL_ENABLE_RDSIEN_BIT 0x4
#define PROP_INT_CTL_ENABLE_RDSIEN_value() (((PROP_INT_CTL_ENABLE_value()) & 0x4)>>2)
#define PROP_INT_CTL_ENABLE_ACFIEN_LSB 1
#define PROP_INT_CTL_ENABLE_ACFIEN_MSB 1
#define PROP_INT_CTL_ENABLE_ACFIEN_MASK 0x2
#define PROP_INT_CTL_ENABLE_ACFIEN_BIT 0x2
#define PROP_INT_CTL_ENABLE_ACFIEN_value() (((PROP_INT_CTL_ENABLE_value()) & 0x2)>>1)
#define PROP_INT_CTL_ENABLE_STCIEN_LSB 0
#define PROP_INT_CTL_ENABLE_STCIEN_MSB 0
#define PROP_INT_CTL_ENABLE_STCIEN_MASK 0x1
#define PROP_INT_CTL_ENABLE_STCIEN_BIT 0x1
#define PROP_INT_CTL_ENABLE_STCIEN_value() (((PROP_INT_CTL_ENABLE_value()) & 0x1)>>0)
#define PROP_INT_CTL_ENABLE_DEFAULT 0x0000

#define PROP_INT_CTL_REPEAT_MASK 0xFFFF
#define PROP_INT_CTL_REPEAT_INDEX 0x01
#define PROP_INT_CTL_REPEAT_GROUP 0x00
#define PROP_INT_CTL_REPEAT_value() (sys_prop_ReturnProperty(PROP_INT_CTL_REPEAT_GROUP, PROP_INT_CTL_REPEAT_INDEX))
#define PROP_INT_CTL_REPEAT_DEVNTREP_LSB 13
#define PROP_INT_CTL_REPEAT_DEVNTREP_MSB 13
#define PROP_INT_CTL_REPEAT_DEVNTREP_MASK 0x2000
#define PROP_INT_CTL_REPEAT_DEVNTREP_BIT 0x2000
#define PROP_INT_CTL_REPEAT_DEVNTREP_value() (((PROP_INT_CTL_REPEAT_value()) & 0x2000)>>13)
#define PROP_INT_CTL_REPEAT_DACQREP_LSB 5
#define PROP_INT_CTL_REPEAT_DACQREP_MSB 5
#define PROP_INT_CTL_REPEAT_DACQREP_MASK 0x20
#define PROP_INT_CTL_REPEAT_DACQREP_BIT 0x20
#define PROP_INT_CTL_REPEAT_DACQREP_value() (((PROP_INT_CTL_REPEAT_value()) & 0x20)>>5)
#define PROP_INT_CTL_REPEAT_DSRVREP_LSB 4
#define PROP_INT_CTL_REPEAT_DSRVREP_MSB 4
#define PROP_INT_CTL_REPEAT_DSRVREP_MASK 0x10
#define PROP_INT_CTL_REPEAT_DSRVREP_BIT 0x10
#define PROP_INT_CTL_REPEAT_DSRVREP_value() (((PROP_INT_CTL_REPEAT_value()) & 0x10)>>4)
#define PROP_INT_CTL_REPEAT_RSQREP_LSB 3
#define PROP_INT_CTL_REPEAT_RSQREP_MSB 3
#define PROP_INT_CTL_REPEAT_RSQREP_MASK 0x8
#define PROP_INT_CTL_REPEAT_RSQREP_BIT 0x8
#define PROP_INT_CTL_REPEAT_RSQREP_value() (((PROP_INT_CTL_REPEAT_value()) & 0x8)>>3)
#define PROP_INT_CTL_REPEAT_RDSREP_LSB 2
#define PROP_INT_CTL_REPEAT_RDSREP_MSB 2
#define PROP_INT_CTL_REPEAT_RDSREP_MASK 0x4
#define PROP_INT_CTL_REPEAT_RDSREP_BIT 0x4
#define PROP_INT_CTL_REPEAT_RDSREP_value() (((PROP_INT_CTL_REPEAT_value()) & 0x4)>>2)
#define PROP_INT_CTL_REPEAT_ACFREP_LSB 1
#define PROP_INT_CTL_REPEAT_ACFREP_MSB 1
#define PROP_INT_CTL_REPEAT_ACFREP_MASK 0x2
#define PROP_INT_CTL_REPEAT_ACFREP_BIT 0x2
#define PROP_INT_CTL_REPEAT_ACFREP_value() (((PROP_INT_CTL_REPEAT_value()) & 0x2)>>1)
#define PROP_INT_CTL_REPEAT_STCREP_LSB 0
#define PROP_INT_CTL_REPEAT_STCREP_MSB 0
#define PROP_INT_CTL_REPEAT_STCREP_MASK 0x1
#define PROP_INT_CTL_REPEAT_STCREP_BIT 0x1
#define PROP_INT_CTL_REPEAT_STCREP_value() (((PROP_INT_CTL_REPEAT_value()) & 0x1)>>0)
#define PROP_INT_CTL_REPEAT_DEFAULT 0x0000

#define PROP_DIGITAL_IO_OUTPUT_SELECT_MASK 0xFFFF
#define PROP_DIGITAL_IO_OUTPUT_SELECT_INDEX 0x00
#define PROP_DIGITAL_IO_OUTPUT_SELECT_GROUP 0x02
#define PROP_DIGITAL_IO_OUTPUT_SELECT_value() (sys_prop_ReturnProperty(PROP_DIGITAL_IO_OUTPUT_SELECT_GROUP, PROP_DIGITAL_IO_OUTPUT_SELECT_INDEX))
#define PROP_DIGITAL_IO_OUTPUT_SELECT_MASTER_LSB 15
#define PROP_DIGITAL_IO_OUTPUT_SELECT_MASTER_MSB 15
#define PROP_DIGITAL_IO_OUTPUT_SELECT_MASTER_MASK 0x8000
#define PROP_DIGITAL_IO_OUTPUT_SELECT_MASTER_BIT 0x8000
#define PROP_DIGITAL_IO_OUTPUT_SELECT_MASTER_value() (((PROP_DIGITAL_IO_OUTPUT_SELECT_value()) & 0x8000)>>15)
#define PROP_DIGITAL_IO_OUTPUT_SELECT_MASTER_ENUM_SLAVE_MODE 0
#define PROP_DIGITAL_IO_OUTPUT_SELECT_MASTER_ENUM_MASTER_MODE 1
#define PROP_DIGITAL_IO_OUTPUT_SELECT_DEFAULT 0





#define PROP_DIGITAL_IO_OUTPUT_SAMPLE_RATE_MASK 0xFFFF
#define PROP_DIGITAL_IO_OUTPUT_SAMPLE_RATE_INDEX 0x01
#define PROP_DIGITAL_IO_OUTPUT_SAMPLE_RATE_GROUP 0x02
#define PROP_DIGITAL_IO_OUTPUT_SAMPLE_RATE_value() (sys_prop_ReturnProperty(PROP_DIGITAL_IO_OUTPUT_SAMPLE_RATE_GROUP, PROP_DIGITAL_IO_OUTPUT_SAMPLE_RATE_INDEX))
#define PROP_DIGITAL_IO_OUTPUT_SAMPLE_RATE_OUTPUT_SAMPLE_RATE_LSB 0
#define PROP_DIGITAL_IO_OUTPUT_SAMPLE_RATE_OUTPUT_SAMPLE_RATE_MSB 15
#define PROP_DIGITAL_IO_OUTPUT_SAMPLE_RATE_OUTPUT_SAMPLE_RATE_MASK 0xFFFF
#define PROP_DIGITAL_IO_OUTPUT_SAMPLE_RATE_OUTPUT_SAMPLE_RATE_value() (((PROP_DIGITAL_IO_OUTPUT_SAMPLE_RATE_value()) & 0xFFFF)>>0)
#define PROP_DIGITAL_IO_OUTPUT_SAMPLE_RATE_OUTPUT_SAMPLE_RATE_ENUM_MIN 32000
#define PROP_DIGITAL_IO_OUTPUT_SAMPLE_RATE_OUTPUT_SAMPLE_RATE_ENUM_MAX 48000
#define PROP_DIGITAL_IO_OUTPUT_SAMPLE_RATE_OUTPUT_SAMPLE_RATE_RANGE_MIN (32000)
#define PROP_DIGITAL_IO_OUTPUT_SAMPLE_RATE_OUTPUT_SAMPLE_RATE_RANGE_MAX (48000)
#define PROP_DIGITAL_IO_OUTPUT_SAMPLE_RATE_DEFAULT 48000

#define PROP_DIGITAL_IO_OUTPUT_FORMAT_MASK 0xFFFF
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_INDEX 0x02
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_GROUP 0x02
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_value() (sys_prop_ReturnProperty(PROP_DIGITAL_IO_OUTPUT_FORMAT_GROUP, PROP_DIGITAL_IO_OUTPUT_FORMAT_INDEX))
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_SAMPL_SIZE_LSB 8
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_SAMPL_SIZE_MSB 13
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_SAMPL_SIZE_MASK 0x3F00
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_SAMPL_SIZE_value() (((PROP_DIGITAL_IO_OUTPUT_FORMAT_value()) & 0x3F00)>>8)
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_SAMPL_SIZE_RANGE_MIN (8)
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_SAMPL_SIZE_RANGE_MAX (24)
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_SLOT_SIZE_LSB 4
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_SLOT_SIZE_MSB 7
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_SLOT_SIZE_MASK 0xF0
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_SLOT_SIZE_value() (((PROP_DIGITAL_IO_OUTPUT_FORMAT_value()) & 0xF0)>>4)
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_SLOT_SIZE_ENUM_SLOT_SIZE_IS_SAMPLE_SIZE 0x0
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_SLOT_SIZE_ENUM_SLOT_SIZE_IS_8 0x2
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_SLOT_SIZE_ENUM_SLOT_SIZE_IS_16 0x4
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_SLOT_SIZE_ENUM_SLOT_SIZE_IS_20 0x5
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_SLOT_SIZE_ENUM_SLOT_SIZE_IS_24 0x6
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_SLOT_SIZE_ENUM_SLOT_SIZE_IS_32 0x7
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_FRAMING_FORMAT_LSB 0
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_FRAMING_FORMAT_MSB 3
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_FRAMING_FORMAT_MASK 0xF
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_FRAMING_FORMAT_value() (((PROP_DIGITAL_IO_OUTPUT_FORMAT_value()) & 0xF)>>0)
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_FRAMING_FORMAT_ENUM_I2S_MODE 0x0
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_FRAMING_FORMAT_ENUM_DSP_MODE 0x6
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_FRAMING_FORMAT_ENUM_LEFT_JUSTIFIED_DSP_MODE 0x7
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_FRAMING_FORMAT_ENUM_LEFT_JUSTIFIED_MODE 0x8
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_FRAMING_FORMAT_ENUM_RIGHT_JUSTIFIED_MODE 0x9
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_DEFAULT 0x1800

#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_MASK 0xFFFF
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_INDEX 0x03
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_GROUP 0x02
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_value() (sys_prop_ReturnProperty(PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_GROUP, PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_INDEX))
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_FSLATE_EN_LSB 13
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_FSLATE_EN_MSB 13
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_FSLATE_EN_MASK 0x2000
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_FSLATE_EN_BIT 0x2000
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_FSLATE_EN_value() (((PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_value()) & 0x2000)>>13)
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_FSLATE_EN_ENUM_DEFAULT 0
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_FSLATE_EN_ENUM_ENABLE 1
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_FSINV_EN_LSB 12
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_FSINV_EN_MSB 12
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_FSINV_EN_MASK 0x1000
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_FSINV_EN_BIT 0x1000
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_FSINV_EN_value() (((PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_value()) & 0x1000)>>12)
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_FSINV_EN_ENUM_DEFAULT 0
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_FSINV_EN_ENUM_ENABLE 1
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_RJUST_EN_LSB 11
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_RJUST_EN_MSB 11
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_RJUST_EN_MASK 0x800
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_RJUST_EN_BIT 0x800
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_RJUST_EN_value() (((PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_value()) & 0x800)>>11)
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_RJUST_EN_ENUM_DEFAULT 0
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_RJUST_EN_ENUM_ENABLE 1
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_CLKINV_EN_LSB 10
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_CLKINV_EN_MSB 10
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_CLKINV_EN_MASK 0x400
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_CLKINV_EN_BIT 0x400
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_CLKINV_EN_value() (((PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_value()) & 0x400)>>10)
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_CLKINV_EN_ENUM_DEFAULT 0
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_CLKINV_EN_ENUM_ENABLE 1
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_SWAP_EN_LSB 9
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_SWAP_EN_MSB 9
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_SWAP_EN_MASK 0x200
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_SWAP_EN_BIT 0x200
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_SWAP_EN_value() (((PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_value()) & 0x200)>>9)
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_SWAP_EN_ENUM_DEFAULT 0
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_SWAP_EN_ENUM_ENABLE 1
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_BITORDER_EN_LSB 8
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_BITORDER_EN_MSB 8
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_BITORDER_EN_MASK 0x100
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_BITORDER_EN_BIT 0x100
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_BITORDER_EN_value() (((PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_value()) & 0x100)>>8)
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_BITORDER_EN_ENUM_DEFAULT 0
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_BITORDER_EN_ENUM_ENABLE 1
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_FSLATE_LSB 5
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_FSLATE_MSB 5
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_FSLATE_MASK 0x20
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_FSLATE_BIT 0x20
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_FSLATE_value() (((PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_value()) & 0x20)>>5)
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_FSLATE_ENUM_SECOND_CLOCK 0
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_FSLATE_ENUM_FIRST_CLOCK 1
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_FSINV_LSB 4
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_FSINV_MSB 4
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_FSINV_MASK 0x10
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_FSINV_BIT 0x10
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_FSINV_value() (((PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_value()) & 0x10)>>4)
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_FSINV_ENUM_NOINVERT 0
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_FSINV_ENUM_INVERT 1
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_RJUST_LSB 3
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_RJUST_MSB 3
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_RJUST_MASK 0x8
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_RJUST_BIT 0x8
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_RJUST_value() (((PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_value()) & 0x8)>>3)
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_RJUST_ENUM_LEFT_JUSTIFY 0
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_RJUST_ENUM_RIGHT_JUSTIFY 1
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_CLKINV_LSB 2
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_CLKINV_MSB 2
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_CLKINV_MASK 0x4
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_CLKINV_BIT 0x4
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_CLKINV_value() (((PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_value()) & 0x4)>>2)
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_CLKINV_ENUM_NORMAL_DCLK 0
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_CLKINV_ENUM_INVERTED_DCLK 1
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_SWAP_LSB 1
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_SWAP_MSB 1
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_SWAP_MASK 0x2
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_SWAP_BIT 0x2
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_SWAP_value() (((PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_value()) & 0x2)>>1)
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_SWAP_ENUM_LEFT_FIRST 0
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_SWAP_ENUM_RIGHT_FIRST 1
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_BITORDER_LSB 0
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_BITORDER_MSB 0
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_BITORDER_MASK 0x1
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_BITORDER_BIT 0x1
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_BITORDER_value() (((PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_value()) & 0x1)>>0)
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_BITORDER_ENUM_MSB_FIRST 0
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_BITORDER_ENUM_LSB_FIRST 1
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_1_DEFAULT 0

#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_MASK 0xFFFF
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_INDEX 0x04
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_GROUP 0x02
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_value() (sys_prop_ReturnProperty(PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_GROUP, PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_INDEX))
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_FILL_EN_LSB 14
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_FILL_EN_MSB 14
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_FILL_EN_MASK 0x4000
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_FILL_EN_BIT 0x4000
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_FILL_EN_value() (((PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_value()) & 0x4000)>>14)
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_FILL_EN_ENUM_DEFAULT 0
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_FILL_EN_ENUM_ENABLE 1
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_SEQEN_EN_LSB 9
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_SEQEN_EN_MSB 9
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_SEQEN_EN_MASK 0x200
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_SEQEN_EN_BIT 0x200
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_SEQEN_EN_value() (((PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_value()) & 0x200)>>9)
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_SEQEN_EN_ENUM_DEFAULT 0
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_SEQEN_EN_ENUM_ENABLE 1
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_FSEDGE_EN_LSB 8
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_FSEDGE_EN_MSB 8
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_FSEDGE_EN_MASK 0x100
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_FSEDGE_EN_BIT 0x100
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_FSEDGE_EN_value() (((PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_value()) & 0x100)>>8)
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_FSEDGE_EN_ENUM_DEFAULT 0
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_FSEDGE_EN_ENUM_ENABLE 1
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_FILL_LSB 6
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_FILL_MSB 7
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_FILL_MASK 0xC0
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_FILL_value() (((PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_value()) & 0xC0)>>6)
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_FILL_ENUM_ZEROS 0
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_FILL_ENUM_ONES 1
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_FILL_ENUM_SIGN 2
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_FILL_ENUM_RAND 3
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_SEQEN_LSB 1
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_SEQEN_MSB 1
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_SEQEN_MASK 0x2
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_SEQEN_BIT 0x2
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_SEQEN_value() (((PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_value()) & 0x2)>>1)
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_SEQEN_ENUM_SINGLE 0
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_SEQEN_ENUM_SEQUENTIAL 1
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_FSEDGE_LSB 0
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_FSEDGE_MSB 0
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_FSEDGE_MASK 0x1
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_FSEDGE_BIT 0x1
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_FSEDGE_value() (((PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_value()) & 0x1)>>0)
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_FSEDGE_ENUM_SINGLE 0
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_FSEDGE_ENUM_BOTH 1
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_2_DEFAULT 0

#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_3_MASK 0xFFFF
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_3_INDEX 0x05
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_3_GROUP 0x02
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_3_value() (sys_prop_ReturnProperty(PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_3_GROUP, PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_3_INDEX))
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_3_FSH_EN_LSB 15
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_3_FSH_EN_MSB 15
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_3_FSH_EN_MASK 0x8000
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_3_FSH_EN_BIT 0x8000
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_3_FSH_EN_value() (((PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_3_value()) & 0x8000)>>15)
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_3_FSH_EN_ENUM_DEFAULT 0
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_3_FSH_EN_ENUM_ENABLE 1
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_3_FSH_LSB 0
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_3_FSH_MSB 14
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_3_FSH_MASK 0x7FFF
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_3_FSH_value() (((PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_3_value()) & 0x7FFF)>>0)
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_3_FSH_RANGE_MIN (0)
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_3_FSH_RANGE_MAX (32767)
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_3_DEFAULT 0

#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_4_MASK 0xFFFF
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_4_INDEX 0x06
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_4_GROUP 0x02
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_4_value() (sys_prop_ReturnProperty(PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_4_GROUP, PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_4_INDEX))
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_4_FSL_EN_LSB 15
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_4_FSL_EN_MSB 15
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_4_FSL_EN_MASK 0x8000
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_4_FSL_EN_BIT 0x8000
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_4_FSL_EN_value() (((PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_4_value()) & 0x8000)>>15)
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_4_FSL_EN_ENUM_DEFAULT 0
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_4_FSL_EN_ENUM_ENABLE 1
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_4_FSL_LSB 0
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_4_FSL_MSB 14
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_4_FSL_MASK 0x7FFF
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_4_FSL_value() (((PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_4_value()) & 0x7FFF)>>0)
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_4_FSL_RANGE_MIN (0)
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_4_FSL_RANGE_MAX (32767)
#define PROP_DIGITAL_IO_OUTPUT_FORMAT_OVERRIDES_4_DEFAULT 0

#define PROP_AUDIO_ANALOG_VOLUME_MASK 0x3F
#define PROP_AUDIO_ANALOG_VOLUME_INDEX 0x00
#define PROP_AUDIO_ANALOG_VOLUME_GROUP 0x03
#define PROP_AUDIO_ANALOG_VOLUME_value() (sys_prop_ReturnProperty(PROP_AUDIO_ANALOG_VOLUME_GROUP, PROP_AUDIO_ANALOG_VOLUME_INDEX))
#define PROP_AUDIO_ANALOG_VOLUME_VOL_LSB 0
#define PROP_AUDIO_ANALOG_VOLUME_VOL_MSB 5
#define PROP_AUDIO_ANALOG_VOLUME_VOL_MASK 0x3F
#define PROP_AUDIO_ANALOG_VOLUME_VOL_value() (((PROP_AUDIO_ANALOG_VOLUME_value()) & 0x3F)>>0)
#define PROP_AUDIO_ANALOG_VOLUME_VOL_ENUM_MIN_VOL 0
#define PROP_AUDIO_ANALOG_VOLUME_VOL_ENUM_MAX_VOL 63
#define PROP_AUDIO_ANALOG_VOLUME_VOL_RANGE_MIN (0)
#define PROP_AUDIO_ANALOG_VOLUME_VOL_RANGE_MAX (63)
#define PROP_AUDIO_ANALOG_VOLUME_DEFAULT 63

#define PROP_AUDIO_MUTE_MASK 0xFFFF
#define PROP_AUDIO_MUTE_INDEX 0x01
#define PROP_AUDIO_MUTE_GROUP 0x03
#define PROP_AUDIO_MUTE_value() (sys_prop_ReturnProperty(PROP_AUDIO_MUTE_GROUP, PROP_AUDIO_MUTE_INDEX))
#define PROP_AUDIO_MUTE_MUTE_LSB 0
#define PROP_AUDIO_MUTE_MUTE_MSB 1
#define PROP_AUDIO_MUTE_MUTE_MASK 0x3
#define PROP_AUDIO_MUTE_MUTE_value() (((PROP_AUDIO_MUTE_value()) & 0x3)>>0)
#define PROP_AUDIO_MUTE_MUTE_ENUM_UNMUTE 0
#define PROP_AUDIO_MUTE_MUTE_ENUM_MUTE_LEFT 1
#define PROP_AUDIO_MUTE_MUTE_ENUM_MUTE_RIGHT 2
#define PROP_AUDIO_MUTE_MUTE_ENUM_MUTE_LEFT_AND_RIGHT 3
#define PROP_AUDIO_MUTE_DEFAULT 0x0000

#define PROP_AUDIO_OUTPUT_CONFIG_MASK 0xFFFF
#define PROP_AUDIO_OUTPUT_CONFIG_INDEX 0x02
#define PROP_AUDIO_OUTPUT_CONFIG_GROUP 0x03
#define PROP_AUDIO_OUTPUT_CONFIG_value() (sys_prop_ReturnProperty(PROP_AUDIO_OUTPUT_CONFIG_GROUP, PROP_AUDIO_OUTPUT_CONFIG_INDEX))
#define PROP_AUDIO_OUTPUT_CONFIG_MONO_LSB 0
#define PROP_AUDIO_OUTPUT_CONFIG_MONO_MSB 0
#define PROP_AUDIO_OUTPUT_CONFIG_MONO_MASK 0x1
#define PROP_AUDIO_OUTPUT_CONFIG_MONO_BIT 0x1
#define PROP_AUDIO_OUTPUT_CONFIG_MONO_value() (((PROP_AUDIO_OUTPUT_CONFIG_value()) & 0x1)>>0)
#define PROP_AUDIO_OUTPUT_CONFIG_MONO_ENUM_STEREO 0
#define PROP_AUDIO_OUTPUT_CONFIG_MONO_ENUM_MONO 1
#define PROP_AUDIO_OUTPUT_CONFIG_DEFAULT 0x0000

#define PROP_AM_AVC_MIN_GAIN_MASK 0xFFFF
#define PROP_AM_AVC_MIN_GAIN_INDEX 0x00
#define PROP_AM_AVC_MIN_GAIN_GROUP 0x05
#define PROP_AM_AVC_MIN_GAIN_value() (sys_prop_ReturnProperty(PROP_AM_AVC_MIN_GAIN_GROUP, PROP_AM_AVC_MIN_GAIN_INDEX))
#define PROP_AM_AVC_MIN_GAIN_MINGAIN_LSB 0
#define PROP_AM_AVC_MIN_GAIN_MINGAIN_MSB 15
#define PROP_AM_AVC_MIN_GAIN_MINGAIN_MASK 0xFFFF
#define PROP_AM_AVC_MIN_GAIN_MINGAIN_value() (((PROP_AM_AVC_MIN_GAIN_value()) & 0xFFFF)>>0)
#define PROP_AM_AVC_MIN_GAIN_MINGAIN_RANGE_MIN (-4096)
#define PROP_AM_AVC_MIN_GAIN_MINGAIN_RANGE_MAX (3061)
#define PROP_AM_AVC_MIN_GAIN_DEFAULT -2048

#define PROP_AM_AVC_MAX_GAIN_MASK 0xFFFF
#define PROP_AM_AVC_MAX_GAIN_INDEX 0x01
#define PROP_AM_AVC_MAX_GAIN_GROUP 0x05
#define PROP_AM_AVC_MAX_GAIN_value() (sys_prop_ReturnProperty(PROP_AM_AVC_MAX_GAIN_GROUP, PROP_AM_AVC_MAX_GAIN_INDEX))
#define PROP_AM_AVC_MAX_GAIN_MAXGAIN_LSB 0
#define PROP_AM_AVC_MAX_GAIN_MAXGAIN_MSB 14
#define PROP_AM_AVC_MAX_GAIN_MAXGAIN_MASK 0x7FFF
#define PROP_AM_AVC_MAX_GAIN_MAXGAIN_value() (((PROP_AM_AVC_MAX_GAIN_value()) & 0x7FFF)>>0)
#define PROP_AM_AVC_MAX_GAIN_MAXGAIN_RANGE_MIN (0)
#define PROP_AM_AVC_MAX_GAIN_MAXGAIN_RANGE_MAX (32767)
#define PROP_AM_AVC_MAX_GAIN_DEFAULT 10220







#define PROP_PIN_CONFIG_ENABLE_MASK 0xFFFF
#define PROP_PIN_CONFIG_ENABLE_INDEX 0x00
#define PROP_PIN_CONFIG_ENABLE_GROUP 0x08
#define PROP_PIN_CONFIG_ENABLE_value() (sys_prop_ReturnProperty(PROP_PIN_CONFIG_ENABLE_GROUP, PROP_PIN_CONFIG_ENABLE_INDEX))
#define PROP_PIN_CONFIG_ENABLE_INTBOUTEN_LSB 15
#define PROP_PIN_CONFIG_ENABLE_INTBOUTEN_MSB 15
#define PROP_PIN_CONFIG_ENABLE_INTBOUTEN_MASK 0x8000
#define PROP_PIN_CONFIG_ENABLE_INTBOUTEN_BIT 0x8000
#define PROP_PIN_CONFIG_ENABLE_INTBOUTEN_value() (((PROP_PIN_CONFIG_ENABLE_value()) & 0x8000)>>15)
#define PROP_PIN_CONFIG_ENABLE_I2SOUTEN_LSB 1
#define PROP_PIN_CONFIG_ENABLE_I2SOUTEN_MSB 1
#define PROP_PIN_CONFIG_ENABLE_I2SOUTEN_MASK 0x2
#define PROP_PIN_CONFIG_ENABLE_I2SOUTEN_BIT 0x2
#define PROP_PIN_CONFIG_ENABLE_I2SOUTEN_value() (((PROP_PIN_CONFIG_ENABLE_value()) & 0x2)>>1)
#define PROP_PIN_CONFIG_ENABLE_DACOUTEN_LSB 0
#define PROP_PIN_CONFIG_ENABLE_DACOUTEN_MSB 0
#define PROP_PIN_CONFIG_ENABLE_DACOUTEN_MASK 0x1
#define PROP_PIN_CONFIG_ENABLE_DACOUTEN_BIT 0x1
#define PROP_PIN_CONFIG_ENABLE_DACOUTEN_value() (((PROP_PIN_CONFIG_ENABLE_value()) & 0x1)>>0)
#define PROP_PIN_CONFIG_ENABLE_DEFAULT 0x8001


#define PROP_PIN_CONFIG_BBI_MASK 0xFFFF
#define PROP_PIN_CONFIG_BBI_INDEX 0x01
#define PROP_PIN_CONFIG_BBI_GROUP 0x08
#define PROP_PIN_CONFIG_BBI_value() (sys_prop_ReturnProperty(PROP_PIN_CONFIG_BBI_GROUP, PROP_PIN_CONFIG_BBI_INDEX))
#define PROP_PIN_CONFIG_BBI_SHIFTQ_LSB 13
#define PROP_PIN_CONFIG_BBI_SHIFTQ_MSB 15
#define PROP_PIN_CONFIG_BBI_SHIFTQ_MASK 0xE000
#define PROP_PIN_CONFIG_BBI_SHIFTQ_value() (((PROP_PIN_CONFIG_BBI_value()) & 0xE000)>>13)
#define PROP_PIN_CONFIG_BBI_SHIFTQ_ENUM_NONE 0
#define PROP_PIN_CONFIG_BBI_SHIFTQ_ENUM_LEFT1 1
#define PROP_PIN_CONFIG_BBI_SHIFTQ_ENUM_LEFT2 2
#define PROP_PIN_CONFIG_BBI_SHIFTQ_ENUM_LEFT3 3
#define PROP_PIN_CONFIG_BBI_SHIFTQ_ENUM_RIGHT3 5
#define PROP_PIN_CONFIG_BBI_SHIFTQ_ENUM_RIGHT2 6
#define PROP_PIN_CONFIG_BBI_SHIFTQ_ENUM_RIGHT1 7
#define PROP_PIN_CONFIG_BBI_SHIFTI_LSB 10
#define PROP_PIN_CONFIG_BBI_SHIFTI_MSB 12
#define PROP_PIN_CONFIG_BBI_SHIFTI_MASK 0x1C00
#define PROP_PIN_CONFIG_BBI_SHIFTI_value() (((PROP_PIN_CONFIG_BBI_value()) & 0x1C00)>>10)
#define PROP_PIN_CONFIG_BBI_SHIFTI_ENUM_NONE 0
#define PROP_PIN_CONFIG_BBI_SHIFTI_ENUM_LEFT1 1
#define PROP_PIN_CONFIG_BBI_SHIFTI_ENUM_LEFT2 2
#define PROP_PIN_CONFIG_BBI_SHIFTI_ENUM_LEFT3 3
#define PROP_PIN_CONFIG_BBI_SHIFTI_ENUM_RIGHT3 5
#define PROP_PIN_CONFIG_BBI_SHIFTI_ENUM_RIGHT2 6
#define PROP_PIN_CONFIG_BBI_SHIFTI_ENUM_RIGHT1 7
#define PROP_PIN_CONFIG_BBI_IQSWAP_LSB 6
#define PROP_PIN_CONFIG_BBI_IQSWAP_MSB 6
#define PROP_PIN_CONFIG_BBI_IQSWAP_MASK 0x40
#define PROP_PIN_CONFIG_BBI_IQSWAP_BIT 0x40
#define PROP_PIN_CONFIG_BBI_IQSWAP_value() (((PROP_PIN_CONFIG_BBI_value()) & 0x40)>>6)
#define PROP_PIN_CONFIG_BBI_IQSWAP_ENUM_FALSE 0
#define PROP_PIN_CONFIG_BBI_IQSWAP_ENUM_TRUE 1
#define PROP_PIN_CONFIG_BBI_FORMAT_LSB 0
#define PROP_PIN_CONFIG_BBI_FORMAT_MSB 2
#define PROP_PIN_CONFIG_BBI_FORMAT_MASK 0x7
#define PROP_PIN_CONFIG_BBI_FORMAT_value() (((PROP_PIN_CONFIG_BBI_value()) & 0x7)>>0)
#define PROP_PIN_CONFIG_BBI_FORMAT_ENUM_SPLIT 0x0
#define PROP_PIN_CONFIG_BBI_FORMAT_ENUM_MUXED 0x1
#define PROP_PIN_CONFIG_BBI_FORMAT_ENUM_AFE16 0x2
#define PROP_PIN_CONFIG_BBI_FORMAT_ENUM_IOBUS 0x3
#define PROP_PIN_CONFIG_BBI_FORMAT_ENUM_AFE12 0x6
#define PROP_PIN_CONFIG_BBI_DEFAULT 0x0000

#define PROP_PIN_CONFIG_I2SOUT_PDRV_MASK 0xFFFF
#define PROP_PIN_CONFIG_I2SOUT_PDRV_INDEX 0x02
#define PROP_PIN_CONFIG_I2SOUT_PDRV_GROUP 0x08
#define PROP_PIN_CONFIG_I2SOUT_PDRV_value() (sys_prop_ReturnProperty(PROP_PIN_CONFIG_I2SOUT_PDRV_GROUP, PROP_PIN_CONFIG_I2SOUT_PDRV_INDEX))
#define PROP_PIN_CONFIG_I2SOUT_PDRV_DOUT_PDRV_LSB 8
#define PROP_PIN_CONFIG_I2SOUT_PDRV_DOUT_PDRV_MSB 11
#define PROP_PIN_CONFIG_I2SOUT_PDRV_DOUT_PDRV_MASK 0xF00
#define PROP_PIN_CONFIG_I2SOUT_PDRV_DOUT_PDRV_value() (((PROP_PIN_CONFIG_I2SOUT_PDRV_value()) & 0xF00)>>8)
#define PROP_PIN_CONFIG_I2SOUT_PDRV_DOUT_PDRV_RANGE_MIN (0)
#define PROP_PIN_CONFIG_I2SOUT_PDRV_DOUT_PDRV_RANGE_MAX (7)
#define PROP_PIN_CONFIG_I2SOUT_PDRV_DFS_PDRV_LSB 4
#define PROP_PIN_CONFIG_I2SOUT_PDRV_DFS_PDRV_MSB 7
#define PROP_PIN_CONFIG_I2SOUT_PDRV_DFS_PDRV_MASK 0xF0
#define PROP_PIN_CONFIG_I2SOUT_PDRV_DFS_PDRV_value() (((PROP_PIN_CONFIG_I2SOUT_PDRV_value()) & 0xF0)>>4)
#define PROP_PIN_CONFIG_I2SOUT_PDRV_DFS_PDRV_RANGE_MIN (0)
#define PROP_PIN_CONFIG_I2SOUT_PDRV_DFS_PDRV_RANGE_MAX (7)
#define PROP_PIN_CONFIG_I2SOUT_PDRV_DCLK_PDRV_LSB 0
#define PROP_PIN_CONFIG_I2SOUT_PDRV_DCLK_PDRV_MSB 3
#define PROP_PIN_CONFIG_I2SOUT_PDRV_DCLK_PDRV_MASK 0xF
#define PROP_PIN_CONFIG_I2SOUT_PDRV_DCLK_PDRV_value() (((PROP_PIN_CONFIG_I2SOUT_PDRV_value()) & 0xF)>>0)
#define PROP_PIN_CONFIG_I2SOUT_PDRV_DCLK_PDRV_RANGE_MIN (0)
#define PROP_PIN_CONFIG_I2SOUT_PDRV_DCLK_PDRV_RANGE_MAX (7)
#define PROP_PIN_CONFIG_I2SOUT_PDRV_DEFAULT 0x0444

#define PROP_PIN_CONFIG_I2SOUT_ODRV_MASK 0xFFFF
#define PROP_PIN_CONFIG_I2SOUT_ODRV_INDEX 0x03
#define PROP_PIN_CONFIG_I2SOUT_ODRV_GROUP 0x08
#define PROP_PIN_CONFIG_I2SOUT_ODRV_value() (sys_prop_ReturnProperty(PROP_PIN_CONFIG_I2SOUT_ODRV_GROUP, PROP_PIN_CONFIG_I2SOUT_ODRV_INDEX))
#define PROP_PIN_CONFIG_I2SOUT_ODRV_DOUT_ODRV_LSB 8
#define PROP_PIN_CONFIG_I2SOUT_ODRV_DOUT_ODRV_MSB 11
#define PROP_PIN_CONFIG_I2SOUT_ODRV_DOUT_ODRV_MASK 0xF00
#define PROP_PIN_CONFIG_I2SOUT_ODRV_DOUT_ODRV_value() (((PROP_PIN_CONFIG_I2SOUT_ODRV_value()) & 0xF00)>>8)
#define PROP_PIN_CONFIG_I2SOUT_ODRV_DOUT_ODRV_RANGE_MIN (0)
#define PROP_PIN_CONFIG_I2SOUT_ODRV_DOUT_ODRV_RANGE_MAX (15)
#define PROP_PIN_CONFIG_I2SOUT_ODRV_DFS_ODRV_LSB 4
#define PROP_PIN_CONFIG_I2SOUT_ODRV_DFS_ODRV_MSB 7
#define PROP_PIN_CONFIG_I2SOUT_ODRV_DFS_ODRV_MASK 0xF0
#define PROP_PIN_CONFIG_I2SOUT_ODRV_DFS_ODRV_value() (((PROP_PIN_CONFIG_I2SOUT_ODRV_value()) & 0xF0)>>4)
#define PROP_PIN_CONFIG_I2SOUT_ODRV_DFS_ODRV_RANGE_MIN (0)
#define PROP_PIN_CONFIG_I2SOUT_ODRV_DFS_ODRV_RANGE_MAX (15)
#define PROP_PIN_CONFIG_I2SOUT_ODRV_DCLK_ODRV_LSB 0
#define PROP_PIN_CONFIG_I2SOUT_ODRV_DCLK_ODRV_MSB 3
#define PROP_PIN_CONFIG_I2SOUT_ODRV_DCLK_ODRV_MASK 0xF
#define PROP_PIN_CONFIG_I2SOUT_ODRV_DCLK_ODRV_value() (((PROP_PIN_CONFIG_I2SOUT_ODRV_value()) & 0xF)>>0)
#define PROP_PIN_CONFIG_I2SOUT_ODRV_DCLK_ODRV_RANGE_MIN (0)
#define PROP_PIN_CONFIG_I2SOUT_ODRV_DCLK_ODRV_RANGE_MAX (15)
#define PROP_PIN_CONFIG_I2SOUT_ODRV_DEFAULT 0x0888

#define PROP_WAKE_TONE_ENABLE_MASK 0xFFFF
#define PROP_WAKE_TONE_ENABLE_INDEX 0x00
#define PROP_WAKE_TONE_ENABLE_GROUP 0x09
#define PROP_WAKE_TONE_ENABLE_value() (sys_prop_ReturnProperty(PROP_WAKE_TONE_ENABLE_GROUP, PROP_WAKE_TONE_ENABLE_INDEX))
#define PROP_WAKE_TONE_ENABLE_ENABLE_LSB 0
#define PROP_WAKE_TONE_ENABLE_ENABLE_MSB 0
#define PROP_WAKE_TONE_ENABLE_ENABLE_MASK 0x1
#define PROP_WAKE_TONE_ENABLE_ENABLE_BIT 0x1
#define PROP_WAKE_TONE_ENABLE_ENABLE_value() (((PROP_WAKE_TONE_ENABLE_value()) & 0x1)>>0)
#define PROP_WAKE_TONE_ENABLE_DEFAULT 0

#define PROP_WAKE_TONE_PERIOD_MASK 0xFFFF
#define PROP_WAKE_TONE_PERIOD_INDEX 0x01
#define PROP_WAKE_TONE_PERIOD_GROUP 0x09
#define PROP_WAKE_TONE_PERIOD_value() (sys_prop_ReturnProperty(PROP_WAKE_TONE_PERIOD_GROUP, PROP_WAKE_TONE_PERIOD_INDEX))
#define PROP_WAKE_TONE_PERIOD_PERIOD_LSB 0
#define PROP_WAKE_TONE_PERIOD_PERIOD_MSB 15
#define PROP_WAKE_TONE_PERIOD_PERIOD_MASK 0xFFFF
#define PROP_WAKE_TONE_PERIOD_PERIOD_value() (((PROP_WAKE_TONE_PERIOD_value()) & 0xFFFF)>>0)
#define PROP_WAKE_TONE_PERIOD_PERIOD_RANGE_MIN (50)
#define PROP_WAKE_TONE_PERIOD_PERIOD_RANGE_MAX (2000)
#define PROP_WAKE_TONE_PERIOD_DEFAULT 250

#define PROP_WAKE_TONE_FREQ_MASK 0xFFFF
#define PROP_WAKE_TONE_FREQ_INDEX 0x02
#define PROP_WAKE_TONE_FREQ_GROUP 0x09
#define PROP_WAKE_TONE_FREQ_value() (sys_prop_ReturnProperty(PROP_WAKE_TONE_FREQ_GROUP, PROP_WAKE_TONE_FREQ_INDEX))
#define PROP_WAKE_TONE_FREQ_FREQ_LSB 0
#define PROP_WAKE_TONE_FREQ_FREQ_MSB 15
#define PROP_WAKE_TONE_FREQ_FREQ_MASK 0xFFFF
#define PROP_WAKE_TONE_FREQ_FREQ_value() (((PROP_WAKE_TONE_FREQ_value()) & 0xFFFF)>>0)
#define PROP_WAKE_TONE_FREQ_FREQ_RANGE_MIN (100)
#define PROP_WAKE_TONE_FREQ_FREQ_RANGE_MAX (2000)
#define PROP_WAKE_TONE_FREQ_DEFAULT 750

#define PROP_WAKE_TONE_AMPLITUDE_MASK 0xFFFF
#define PROP_WAKE_TONE_AMPLITUDE_INDEX 0x03
#define PROP_WAKE_TONE_AMPLITUDE_GROUP 0x09
#define PROP_WAKE_TONE_AMPLITUDE_value() (sys_prop_ReturnProperty(PROP_WAKE_TONE_AMPLITUDE_GROUP, PROP_WAKE_TONE_AMPLITUDE_INDEX))
#define PROP_WAKE_TONE_AMPLITUDE_AMP_LSB 0
#define PROP_WAKE_TONE_AMPLITUDE_AMP_MSB 4
#define PROP_WAKE_TONE_AMPLITUDE_AMP_MASK 0x1F
#define PROP_WAKE_TONE_AMPLITUDE_AMP_value() (((PROP_WAKE_TONE_AMPLITUDE_value()) & 0x1F)>>0)
#define PROP_WAKE_TONE_AMPLITUDE_AMP_RANGE_MIN (0)
#define PROP_WAKE_TONE_AMPLITUDE_AMP_RANGE_MAX (31)
#define PROP_WAKE_TONE_AMPLITUDE_DEFAULT 8

#define PROP_FM_TUNE_FE_VARM_MASK 0xFFFF
#define PROP_FM_TUNE_FE_VARM_INDEX 0x10
#define PROP_FM_TUNE_FE_VARM_GROUP 0x17
#define PROP_FM_TUNE_FE_VARM_value() (sys_prop_ReturnProperty(PROP_FM_TUNE_FE_VARM_GROUP, PROP_FM_TUNE_FE_VARM_INDEX))
#define PROP_FM_TUNE_FE_VARM_FE_VARM_LSB 0
#define PROP_FM_TUNE_FE_VARM_FE_VARM_MSB 15
#define PROP_FM_TUNE_FE_VARM_FE_VARM_MASK 0xFFFF
#define PROP_FM_TUNE_FE_VARM_FE_VARM_value() (((PROP_FM_TUNE_FE_VARM_value()) & 0xFFFF)>>0)
#define PROP_FM_TUNE_FE_VARM_DEFAULT 0

#define PROP_DAB_TUNE_FE_VARM_MASK 0xFFFF
#define PROP_DAB_TUNE_FE_VARM_INDEX 0x10
#define PROP_DAB_TUNE_FE_VARM_GROUP 0x17
#define PROP_DAB_TUNE_FE_VARM_value() (sys_prop_ReturnProperty(PROP_DAB_TUNE_FE_VARM_GROUP, PROP_DAB_TUNE_FE_VARM_INDEX))
#define PROP_DAB_TUNE_FE_VARM_FE_VARM_LSB 0
#define PROP_DAB_TUNE_FE_VARM_FE_VARM_MSB 15
#define PROP_DAB_TUNE_FE_VARM_FE_VARM_MASK 0xFFFF
#define PROP_DAB_TUNE_FE_VARM_FE_VARM_value() (((PROP_DAB_TUNE_FE_VARM_value()) & 0xFFFF)>>0)
#define PROP_DAB_TUNE_FE_VARM_DEFAULT 0

#define PROP_FM_TUNE_FE_VARB_MASK 0xFFFF
#define PROP_FM_TUNE_FE_VARB_INDEX 0x11
#define PROP_FM_TUNE_FE_VARB_GROUP 0x17
#define PROP_FM_TUNE_FE_VARB_value() (sys_prop_ReturnProperty(PROP_FM_TUNE_FE_VARB_GROUP, PROP_FM_TUNE_FE_VARB_INDEX))
#define PROP_FM_TUNE_FE_VARB_FE_VARB_LSB 0
#define PROP_FM_TUNE_FE_VARB_FE_VARB_MSB 15
#define PROP_FM_TUNE_FE_VARB_FE_VARB_MASK 0xFFFF
#define PROP_FM_TUNE_FE_VARB_FE_VARB_value() (((PROP_FM_TUNE_FE_VARB_value()) & 0xFFFF)>>0)
#define PROP_FM_TUNE_FE_VARB_DEFAULT 0

#define PROP_DAB_TUNE_FE_VARB_MASK 0xFFFF
#define PROP_DAB_TUNE_FE_VARB_INDEX 0x11
#define PROP_DAB_TUNE_FE_VARB_GROUP 0x17
#define PROP_DAB_TUNE_FE_VARB_value() (sys_prop_ReturnProperty(PROP_DAB_TUNE_FE_VARB_GROUP, PROP_DAB_TUNE_FE_VARB_INDEX))
#define PROP_DAB_TUNE_FE_VARB_FE_VARB_LSB 0
#define PROP_DAB_TUNE_FE_VARB_FE_VARB_MSB 15
#define PROP_DAB_TUNE_FE_VARB_FE_VARB_MASK 0xFFFF
#define PROP_DAB_TUNE_FE_VARB_FE_VARB_value() (((PROP_DAB_TUNE_FE_VARB_value()) & 0xFFFF)>>0)
#define PROP_DAB_TUNE_FE_VARB_DEFAULT 0

#define PROP_FM_TUNE_FE_CFG_MASK 0xFFFF
#define PROP_FM_TUNE_FE_CFG_INDEX 0x12
#define PROP_FM_TUNE_FE_CFG_GROUP 0x17
#define PROP_FM_TUNE_FE_CFG_value() (sys_prop_ReturnProperty(PROP_FM_TUNE_FE_CFG_GROUP, PROP_FM_TUNE_FE_CFG_INDEX))
#define PROP_FM_TUNE_FE_CFG_VHFCAPS_LSB 1
#define PROP_FM_TUNE_FE_CFG_VHFCAPS_MSB 1
#define PROP_FM_TUNE_FE_CFG_VHFCAPS_MASK 0x2
#define PROP_FM_TUNE_FE_CFG_VHFCAPS_BIT 0x2
#define PROP_FM_TUNE_FE_CFG_VHFCAPS_value() (((PROP_FM_TUNE_FE_CFG_value()) & 0x2)>>1)
#define PROP_FM_TUNE_FE_CFG_VHFCAPS_ENUM_MATCHING 0
#define PROP_FM_TUNE_FE_CFG_VHFCAPS_ENUM_DECOUPLE 1
#define PROP_FM_TUNE_FE_CFG_VHFSW_LSB 0
#define PROP_FM_TUNE_FE_CFG_VHFSW_MSB 0
#define PROP_FM_TUNE_FE_CFG_VHFSW_MASK 0x1
#define PROP_FM_TUNE_FE_CFG_VHFSW_BIT 0x1
#define PROP_FM_TUNE_FE_CFG_VHFSW_value() (((PROP_FM_TUNE_FE_CFG_value()) & 0x1)>>0)
#define PROP_FM_TUNE_FE_CFG_VHFSW_ENUM_SW_OPEN 0
#define PROP_FM_TUNE_FE_CFG_VHFSW_ENUM_SW_CLOSED 1
#define PROP_FM_TUNE_FE_CFG_DEFAULT 0x0000

#define PROP_DAB_TUNE_FE_CFG_MASK 0xFFFF
#define PROP_DAB_TUNE_FE_CFG_INDEX 0x12
#define PROP_DAB_TUNE_FE_CFG_GROUP 0x17
#define PROP_DAB_TUNE_FE_CFG_value() (sys_prop_ReturnProperty(PROP_DAB_TUNE_FE_CFG_GROUP, PROP_DAB_TUNE_FE_CFG_INDEX))
#define PROP_DAB_TUNE_FE_CFG_VHFCAPS_LSB 1
#define PROP_DAB_TUNE_FE_CFG_VHFCAPS_MSB 1
#define PROP_DAB_TUNE_FE_CFG_VHFCAPS_MASK 0x2
#define PROP_DAB_TUNE_FE_CFG_VHFCAPS_BIT 0x2
#define PROP_DAB_TUNE_FE_CFG_VHFCAPS_value() (((PROP_DAB_TUNE_FE_CFG_value()) & 0x2)>>1)
#define PROP_DAB_TUNE_FE_CFG_VHFCAPS_ENUM_MATCHING 0
#define PROP_DAB_TUNE_FE_CFG_VHFCAPS_ENUM_DECOUPLE 1
#define PROP_DAB_TUNE_FE_CFG_VHFSW_LSB 0
#define PROP_DAB_TUNE_FE_CFG_VHFSW_MSB 0
#define PROP_DAB_TUNE_FE_CFG_VHFSW_MASK 0x1
#define PROP_DAB_TUNE_FE_CFG_VHFSW_BIT 0x1
#define PROP_DAB_TUNE_FE_CFG_VHFSW_value() (((PROP_DAB_TUNE_FE_CFG_value()) & 0x1)>>0)
#define PROP_DAB_TUNE_FE_CFG_VHFSW_ENUM_SW_OPEN 0
#define PROP_DAB_TUNE_FE_CFG_VHFSW_ENUM_SW_CLOSED 1
#define PROP_DAB_TUNE_FE_CFG_DEFAULT 0x0001

#define PROP_AM_CHBW_SQ_LIMITS_MASK 0xFFFF
#define PROP_AM_CHBW_SQ_LIMITS_INDEX 0x00
#define PROP_AM_CHBW_SQ_LIMITS_GROUP 0x22
#define PROP_AM_CHBW_SQ_LIMITS_value() (sys_prop_ReturnProperty(PROP_AM_CHBW_SQ_LIMITS_GROUP, PROP_AM_CHBW_SQ_LIMITS_INDEX))
#define PROP_AM_CHBW_SQ_LIMITS_SQ_MAX_LSB 8
#define PROP_AM_CHBW_SQ_LIMITS_SQ_MAX_MSB 15
#define PROP_AM_CHBW_SQ_LIMITS_SQ_MAX_MASK 0xFF00
#define PROP_AM_CHBW_SQ_LIMITS_SQ_MAX_value() (int8_t)(((PROP_AM_CHBW_SQ_LIMITS_value()) & 0xFF00)>>8)
#define PROP_AM_CHBW_SQ_LIMITS_SQ_MAX_RANGE_MIN (-128)
#define PROP_AM_CHBW_SQ_LIMITS_SQ_MAX_RANGE_MAX (127)
#define PROP_AM_CHBW_SQ_LIMITS_SQ_MIN_LSB 0
#define PROP_AM_CHBW_SQ_LIMITS_SQ_MIN_MSB 7
#define PROP_AM_CHBW_SQ_LIMITS_SQ_MIN_MASK 0xFF
#define PROP_AM_CHBW_SQ_LIMITS_SQ_MIN_value() (int8_t)(((PROP_AM_CHBW_SQ_LIMITS_value()) & 0xFF)>>0)
#define PROP_AM_CHBW_SQ_LIMITS_SQ_MIN_RANGE_MIN (-128)
#define PROP_AM_CHBW_SQ_LIMITS_SQ_MIN_RANGE_MAX (127)
#define PROP_AM_CHBW_SQ_LIMITS_DEFAULT 0x1E0F

#define PROP_AM_CHBW_SQ_CHBW_MASK 0xFFFF
#define PROP_AM_CHBW_SQ_CHBW_INDEX 0x01
#define PROP_AM_CHBW_SQ_CHBW_GROUP 0x22
#define PROP_AM_CHBW_SQ_CHBW_value() (sys_prop_ReturnProperty(PROP_AM_CHBW_SQ_CHBW_GROUP, PROP_AM_CHBW_SQ_CHBW_INDEX))
#define PROP_AM_CHBW_SQ_CHBW_MAX_LSB 8
#define PROP_AM_CHBW_SQ_CHBW_MAX_MSB 15
#define PROP_AM_CHBW_SQ_CHBW_MAX_MASK 0xFF00
#define PROP_AM_CHBW_SQ_CHBW_MAX_value() (((PROP_AM_CHBW_SQ_CHBW_value()) & 0xFF00)>>8)
#define PROP_AM_CHBW_SQ_CHBW_MAX_RANGE_MIN (15)
#define PROP_AM_CHBW_SQ_CHBW_MAX_RANGE_MAX (100)
#define PROP_AM_CHBW_SQ_CHBW_MIN_LSB 0
#define PROP_AM_CHBW_SQ_CHBW_MIN_MSB 7
#define PROP_AM_CHBW_SQ_CHBW_MIN_MASK 0xFF
#define PROP_AM_CHBW_SQ_CHBW_MIN_value() (((PROP_AM_CHBW_SQ_CHBW_value()) & 0xFF)>>0)
#define PROP_AM_CHBW_SQ_CHBW_MIN_RANGE_MIN (15)
#define PROP_AM_CHBW_SQ_CHBW_MIN_RANGE_MAX (100)
#define PROP_AM_CHBW_SQ_CHBW_DEFAULT 0x2314

#define PROP_AM_CHBW_SQ_WIDENING_TIME_MASK 0xFFFF
#define PROP_AM_CHBW_SQ_WIDENING_TIME_INDEX 0x02
#define PROP_AM_CHBW_SQ_WIDENING_TIME_GROUP 0x22
#define PROP_AM_CHBW_SQ_WIDENING_TIME_value() (sys_prop_ReturnProperty(PROP_AM_CHBW_SQ_WIDENING_TIME_GROUP, PROP_AM_CHBW_SQ_WIDENING_TIME_INDEX))
#define PROP_AM_CHBW_SQ_WIDENING_TIME_WIDENING_TIME_LSB 0
#define PROP_AM_CHBW_SQ_WIDENING_TIME_WIDENING_TIME_MSB 15
#define PROP_AM_CHBW_SQ_WIDENING_TIME_WIDENING_TIME_MASK 0xFFFF
#define PROP_AM_CHBW_SQ_WIDENING_TIME_WIDENING_TIME_value() (((PROP_AM_CHBW_SQ_WIDENING_TIME_value()) & 0xFFFF)>>0)
#define PROP_AM_CHBW_SQ_WIDENING_TIME_WIDENING_TIME_RANGE_MIN (16)
#define PROP_AM_CHBW_SQ_WIDENING_TIME_WIDENING_TIME_RANGE_MAX (32767)
#define PROP_AM_CHBW_SQ_WIDENING_TIME_DEFAULT 2048

#define PROP_AM_CHBW_SQ_NARROWING_TIME_MASK 0xFFFF
#define PROP_AM_CHBW_SQ_NARROWING_TIME_INDEX 0x03
#define PROP_AM_CHBW_SQ_NARROWING_TIME_GROUP 0x22
#define PROP_AM_CHBW_SQ_NARROWING_TIME_value() (sys_prop_ReturnProperty(PROP_AM_CHBW_SQ_NARROWING_TIME_GROUP, PROP_AM_CHBW_SQ_NARROWING_TIME_INDEX))
#define PROP_AM_CHBW_SQ_NARROWING_TIME_NARROWING_TIME_LSB 0
#define PROP_AM_CHBW_SQ_NARROWING_TIME_NARROWING_TIME_MSB 15
#define PROP_AM_CHBW_SQ_NARROWING_TIME_NARROWING_TIME_MASK 0xFFFF
#define PROP_AM_CHBW_SQ_NARROWING_TIME_NARROWING_TIME_value() (((PROP_AM_CHBW_SQ_NARROWING_TIME_value()) & 0xFFFF)>>0)
#define PROP_AM_CHBW_SQ_NARROWING_TIME_NARROWING_TIME_RANGE_MIN (16)
#define PROP_AM_CHBW_SQ_NARROWING_TIME_NARROWING_TIME_RANGE_MAX (32767)
#define PROP_AM_CHBW_SQ_NARROWING_TIME_DEFAULT 16

#define PROP_AM_CHBW_OVERRIDE_BW_MASK 0xFFFF
#define PROP_AM_CHBW_OVERRIDE_BW_INDEX 0x04
#define PROP_AM_CHBW_OVERRIDE_BW_GROUP 0x22
#define PROP_AM_CHBW_OVERRIDE_BW_value() (sys_prop_ReturnProperty(PROP_AM_CHBW_OVERRIDE_BW_GROUP, PROP_AM_CHBW_OVERRIDE_BW_INDEX))
#define PROP_AM_CHBW_OVERRIDE_BW_OVERRIDE_BW_LSB 0
#define PROP_AM_CHBW_OVERRIDE_BW_OVERRIDE_BW_MSB 7
#define PROP_AM_CHBW_OVERRIDE_BW_OVERRIDE_BW_MASK 0xFF
#define PROP_AM_CHBW_OVERRIDE_BW_OVERRIDE_BW_value() (uint8_t)(((PROP_AM_CHBW_OVERRIDE_BW_value()) & 0xFF)>>0)
#define PROP_AM_CHBW_OVERRIDE_BW_OVERRIDE_BW_RANGE_MIN (0)
#define PROP_AM_CHBW_OVERRIDE_BW_OVERRIDE_BW_RANGE_MAX (55)
#define PROP_AM_CHBW_OVERRIDE_BW_DEFAULT 0

#define PROP_FM_TUNE_HDSB_OFFSET_THRESHOLD_MASK 0xFFFF
#define PROP_FM_TUNE_HDSB_OFFSET_THRESHOLD_INDEX 0x06
#define PROP_FM_TUNE_HDSB_OFFSET_THRESHOLD_GROUP 0x30
#define PROP_FM_TUNE_HDSB_OFFSET_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_FM_TUNE_HDSB_OFFSET_THRESHOLD_GROUP, PROP_FM_TUNE_HDSB_OFFSET_THRESHOLD_INDEX))
#define PROP_FM_TUNE_HDSB_OFFSET_THRESHOLD_SBOFFSET_LSB 0
#define PROP_FM_TUNE_HDSB_OFFSET_THRESHOLD_SBOFFSET_MSB 7
#define PROP_FM_TUNE_HDSB_OFFSET_THRESHOLD_SBOFFSET_MASK 0xFF
#define PROP_FM_TUNE_HDSB_OFFSET_THRESHOLD_SBOFFSET_value() (((PROP_FM_TUNE_HDSB_OFFSET_THRESHOLD_value()) & 0xFF)>>0)
#define PROP_FM_TUNE_HDSB_OFFSET_THRESHOLD_SBOFFSET_RANGE_MIN (0)
#define PROP_FM_TUNE_HDSB_OFFSET_THRESHOLD_SBOFFSET_RANGE_MAX (127)
#define PROP_FM_TUNE_HDSB_OFFSET_THRESHOLD_DEFAULT 2

#define PROP_FM_SEEK_BAND_BOTTOM_MASK 0xFFFF
#define PROP_FM_SEEK_BAND_BOTTOM_INDEX 0x00
#define PROP_FM_SEEK_BAND_BOTTOM_GROUP 0x31
#define PROP_FM_SEEK_BAND_BOTTOM_value() (sys_prop_ReturnProperty(PROP_FM_SEEK_BAND_BOTTOM_GROUP, PROP_FM_SEEK_BAND_BOTTOM_INDEX))
#define PROP_FM_SEEK_BAND_BOTTOM_FMSKFREQL_LSB 0
#define PROP_FM_SEEK_BAND_BOTTOM_FMSKFREQL_MSB 15
#define PROP_FM_SEEK_BAND_BOTTOM_FMSKFREQL_MASK 0xFFFF
#define PROP_FM_SEEK_BAND_BOTTOM_FMSKFREQL_value() (uint16_t)(((PROP_FM_SEEK_BAND_BOTTOM_value()) & 0xFFFF)>>0)
#define PROP_FM_SEEK_BAND_BOTTOM_FMSKFREQL_ENUM_JAPAN_MIN 7600
#define PROP_FM_SEEK_BAND_BOTTOM_FMSKFREQL_ENUM_WIDE_MIN 7800
#define PROP_FM_SEEK_BAND_BOTTOM_FMSKFREQL_ENUM_STANDARD_MIN 8750
#define PROP_FM_SEEK_BAND_BOTTOM_FMSKFREQL_ENUM_JAPAN_MAX 9000
#define PROP_FM_SEEK_BAND_BOTTOM_FMSKFREQL_ENUM_STANDARD_MAX 10790
#define PROP_FM_SEEK_BAND_BOTTOM_FMSKFREQL_ENUM_WIDE_MAX 10800
#define PROP_FM_SEEK_BAND_BOTTOM_FMSKFREQL_RANGE_MIN (7600)
#define PROP_FM_SEEK_BAND_BOTTOM_FMSKFREQL_RANGE_MAX (10800)
#define PROP_FM_SEEK_BAND_BOTTOM_DEFAULT 8750

#define PROP_FM_SEEK_BAND_TOP_MASK 0xFFFF
#define PROP_FM_SEEK_BAND_TOP_INDEX 0x01
#define PROP_FM_SEEK_BAND_TOP_GROUP 0x31
#define PROP_FM_SEEK_BAND_TOP_value() (sys_prop_ReturnProperty(PROP_FM_SEEK_BAND_TOP_GROUP, PROP_FM_SEEK_BAND_TOP_INDEX))
#define PROP_FM_SEEK_BAND_TOP_FMSKFREQH_LSB 0
#define PROP_FM_SEEK_BAND_TOP_FMSKFREQH_MSB 15
#define PROP_FM_SEEK_BAND_TOP_FMSKFREQH_MASK 0xFFFF
#define PROP_FM_SEEK_BAND_TOP_FMSKFREQH_value() (uint16_t)(((PROP_FM_SEEK_BAND_TOP_value()) & 0xFFFF)>>0)
#define PROP_FM_SEEK_BAND_TOP_FMSKFREQH_ENUM_JAPAN_MIN 7600
#define PROP_FM_SEEK_BAND_TOP_FMSKFREQH_ENUM_WIDE_MIN 7800
#define PROP_FM_SEEK_BAND_TOP_FMSKFREQH_ENUM_STANDARD_MIN 8750
#define PROP_FM_SEEK_BAND_TOP_FMSKFREQH_ENUM_JAPAN_MAX 9000
#define PROP_FM_SEEK_BAND_TOP_FMSKFREQH_ENUM_STANDARD_MAX 10790
#define PROP_FM_SEEK_BAND_TOP_FMSKFREQH_ENUM_WIDE_MAX 10800
#define PROP_FM_SEEK_BAND_TOP_FMSKFREQH_RANGE_MIN (7600)
#define PROP_FM_SEEK_BAND_TOP_FMSKFREQH_RANGE_MAX (10800)
#define PROP_FM_SEEK_BAND_TOP_DEFAULT 10790

#define PROP_FM_SEEK_FREQUENCY_SPACING_MASK 0xFFFF
#define PROP_FM_SEEK_FREQUENCY_SPACING_INDEX 0x02
#define PROP_FM_SEEK_FREQUENCY_SPACING_GROUP 0x31
#define PROP_FM_SEEK_FREQUENCY_SPACING_value() (sys_prop_ReturnProperty(PROP_FM_SEEK_FREQUENCY_SPACING_GROUP, PROP_FM_SEEK_FREQUENCY_SPACING_INDEX))
#define PROP_FM_SEEK_FREQUENCY_SPACING_FMSKSPACE_LSB 0
#define PROP_FM_SEEK_FREQUENCY_SPACING_FMSKSPACE_MSB 4
#define PROP_FM_SEEK_FREQUENCY_SPACING_FMSKSPACE_MASK 0x1F
#define PROP_FM_SEEK_FREQUENCY_SPACING_FMSKSPACE_value() (((PROP_FM_SEEK_FREQUENCY_SPACING_value()) & 0x1F)>>0)
#define PROP_FM_SEEK_FREQUENCY_SPACING_FMSKSPACE_RANGE_MIN (1)
#define PROP_FM_SEEK_FREQUENCY_SPACING_FMSKSPACE_RANGE_MAX (31)
#define PROP_FM_SEEK_FREQUENCY_SPACING_DEFAULT 10

#define PROP_FM_VALID_MAX_TUNE_ERROR_MASK 0xFFFF
#define PROP_FM_VALID_MAX_TUNE_ERROR_INDEX 0x00
#define PROP_FM_VALID_MAX_TUNE_ERROR_GROUP 0x32
#define PROP_FM_VALID_MAX_TUNE_ERROR_value() (sys_prop_ReturnProperty(PROP_FM_VALID_MAX_TUNE_ERROR_GROUP, PROP_FM_VALID_MAX_TUNE_ERROR_INDEX))
#define PROP_FM_VALID_MAX_TUNE_ERROR_FMMAXTUNEERR_LSB 0
#define PROP_FM_VALID_MAX_TUNE_ERROR_FMMAXTUNEERR_MSB 7
#define PROP_FM_VALID_MAX_TUNE_ERROR_FMMAXTUNEERR_MASK 0xFF
#define PROP_FM_VALID_MAX_TUNE_ERROR_FMMAXTUNEERR_value() (uint8_t)(((PROP_FM_VALID_MAX_TUNE_ERROR_value()) & 0xFF)>>0)
#define PROP_FM_VALID_MAX_TUNE_ERROR_FMMAXTUNEERR_RANGE_MIN (0)
#define PROP_FM_VALID_MAX_TUNE_ERROR_FMMAXTUNEERR_RANGE_MAX (126)
#define PROP_FM_VALID_MAX_TUNE_ERROR_DEFAULT 114

#define PROP_FM_VALID_RSSI_TIME_MASK 0xFFFF
#define PROP_FM_VALID_RSSI_TIME_INDEX 0x01
#define PROP_FM_VALID_RSSI_TIME_GROUP 0x32
#define PROP_FM_VALID_RSSI_TIME_value() (sys_prop_ReturnProperty(PROP_FM_VALID_RSSI_TIME_GROUP, PROP_FM_VALID_RSSI_TIME_INDEX))
#define PROP_FM_VALID_RSSI_TIME_SSIVALTIME_LSB 0
#define PROP_FM_VALID_RSSI_TIME_SSIVALTIME_MSB 5
#define PROP_FM_VALID_RSSI_TIME_SSIVALTIME_MASK 0x3F
#define PROP_FM_VALID_RSSI_TIME_SSIVALTIME_value() (((PROP_FM_VALID_RSSI_TIME_value()) & 0x3F)>>0)
#define PROP_FM_VALID_RSSI_TIME_SSIVALTIME_RANGE_MIN (0)
#define PROP_FM_VALID_RSSI_TIME_SSIVALTIME_RANGE_MAX (63)
#define PROP_FM_VALID_RSSI_TIME_DEFAULT 15

#define PROP_FM_VALID_RSSI_THRESHOLD_MASK 0xFFFF
#define PROP_FM_VALID_RSSI_THRESHOLD_INDEX 0x02
#define PROP_FM_VALID_RSSI_THRESHOLD_GROUP 0x32
#define PROP_FM_VALID_RSSI_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_FM_VALID_RSSI_THRESHOLD_GROUP, PROP_FM_VALID_RSSI_THRESHOLD_INDEX))
#define PROP_FM_VALID_RSSI_THRESHOLD_FMVALRSSI_LSB 0
#define PROP_FM_VALID_RSSI_THRESHOLD_FMVALRSSI_MSB 7
#define PROP_FM_VALID_RSSI_THRESHOLD_FMVALRSSI_MASK 0xFF
#define PROP_FM_VALID_RSSI_THRESHOLD_FMVALRSSI_value() (int8_t)(((PROP_FM_VALID_RSSI_THRESHOLD_value()) & 0xFF)>>0)
#define PROP_FM_VALID_RSSI_THRESHOLD_FMVALRSSI_RANGE_MIN (-128)
#define PROP_FM_VALID_RSSI_THRESHOLD_FMVALRSSI_RANGE_MAX (127)
#define PROP_FM_VALID_RSSI_THRESHOLD_DEFAULT 17

#define PROP_FM_VALID_SNR_TIME_MASK 0xFFFF
#define PROP_FM_VALID_SNR_TIME_INDEX 0x03
#define PROP_FM_VALID_SNR_TIME_GROUP 0x32
#define PROP_FM_VALID_SNR_TIME_value() (sys_prop_ReturnProperty(PROP_FM_VALID_SNR_TIME_GROUP, PROP_FM_VALID_SNR_TIME_INDEX))
#define PROP_FM_VALID_SNR_TIME_SNRVALTIME_LSB 0
#define PROP_FM_VALID_SNR_TIME_SNRVALTIME_MSB 5
#define PROP_FM_VALID_SNR_TIME_SNRVALTIME_MASK 0x3F
#define PROP_FM_VALID_SNR_TIME_SNRVALTIME_value() (((PROP_FM_VALID_SNR_TIME_value()) & 0x3F)>>0)
#define PROP_FM_VALID_SNR_TIME_SNRVALTIME_RANGE_MIN (0)
#define PROP_FM_VALID_SNR_TIME_SNRVALTIME_RANGE_MAX (63)
#define PROP_FM_VALID_SNR_TIME_DEFAULT 40

#define PROP_FM_VALID_SNR_THRESHOLD_MASK 0xFFFF
#define PROP_FM_VALID_SNR_THRESHOLD_INDEX 0x04
#define PROP_FM_VALID_SNR_THRESHOLD_GROUP 0x32
#define PROP_FM_VALID_SNR_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_FM_VALID_SNR_THRESHOLD_GROUP, PROP_FM_VALID_SNR_THRESHOLD_INDEX))
#define PROP_FM_VALID_SNR_THRESHOLD_FMVALSNR_LSB 0
#define PROP_FM_VALID_SNR_THRESHOLD_FMVALSNR_MSB 7
#define PROP_FM_VALID_SNR_THRESHOLD_FMVALSNR_MASK 0xFF
#define PROP_FM_VALID_SNR_THRESHOLD_FMVALSNR_value() (int8_t)(((PROP_FM_VALID_SNR_THRESHOLD_value()) & 0xFF)>>0)
#define PROP_FM_VALID_SNR_THRESHOLD_FMVALSNR_RANGE_MIN (-128)
#define PROP_FM_VALID_SNR_THRESHOLD_FMVALSNR_RANGE_MAX (127)
#define PROP_FM_VALID_SNR_THRESHOLD_DEFAULT 10

#define PROP_FM_VALID_HDLEVEL_THRESHOLD_MASK 0xFFFF
#define PROP_FM_VALID_HDLEVEL_THRESHOLD_INDEX 0x06
#define PROP_FM_VALID_HDLEVEL_THRESHOLD_GROUP 0x32
#define PROP_FM_VALID_HDLEVEL_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_FM_VALID_HDLEVEL_THRESHOLD_GROUP, PROP_FM_VALID_HDLEVEL_THRESHOLD_INDEX))
#define PROP_FM_VALID_HDLEVEL_THRESHOLD_FMVALHDLEVEL_LSB 0
#define PROP_FM_VALID_HDLEVEL_THRESHOLD_FMVALHDLEVEL_MSB 7
#define PROP_FM_VALID_HDLEVEL_THRESHOLD_FMVALHDLEVEL_MASK 0xFF
#define PROP_FM_VALID_HDLEVEL_THRESHOLD_FMVALHDLEVEL_value() (int8_t)(((PROP_FM_VALID_HDLEVEL_THRESHOLD_value()) & 0xFF)>>0)
#define PROP_FM_VALID_HDLEVEL_THRESHOLD_FMVALHDLEVEL_RANGE_MIN (0)
#define PROP_FM_VALID_HDLEVEL_THRESHOLD_FMVALHDLEVEL_RANGE_MAX (100)
#define PROP_FM_VALID_HDLEVEL_THRESHOLD_DEFAULT 0

#define PROP_FM_RSQ_INTERRUPT_SOURCE_MASK 0xFFFF
#define PROP_FM_RSQ_INTERRUPT_SOURCE_INDEX 0x00
#define PROP_FM_RSQ_INTERRUPT_SOURCE_GROUP 0x33
#define PROP_FM_RSQ_INTERRUPT_SOURCE_value() (sys_prop_ReturnProperty(PROP_FM_RSQ_INTERRUPT_SOURCE_GROUP, PROP_FM_RSQ_INTERRUPT_SOURCE_INDEX))
#define PROP_FM_RSQ_INTERRUPT_SOURCE_MULTHINT_LSB 7
#define PROP_FM_RSQ_INTERRUPT_SOURCE_MULTHINT_MSB 7
#define PROP_FM_RSQ_INTERRUPT_SOURCE_MULTHINT_MASK 0x80
#define PROP_FM_RSQ_INTERRUPT_SOURCE_MULTHINT_BIT 0x80
#define PROP_FM_RSQ_INTERRUPT_SOURCE_MULTHINT_value() (((PROP_FM_RSQ_INTERRUPT_SOURCE_value()) & 0x80)>>7)
#define PROP_FM_RSQ_INTERRUPT_SOURCE_MULTLINT_LSB 6
#define PROP_FM_RSQ_INTERRUPT_SOURCE_MULTLINT_MSB 6
#define PROP_FM_RSQ_INTERRUPT_SOURCE_MULTLINT_MASK 0x40
#define PROP_FM_RSQ_INTERRUPT_SOURCE_MULTLINT_BIT 0x40
#define PROP_FM_RSQ_INTERRUPT_SOURCE_MULTLINT_value() (((PROP_FM_RSQ_INTERRUPT_SOURCE_value()) & 0x40)>>6)
#define PROP_FM_RSQ_INTERRUPT_SOURCE_HDLEVELHINT_LSB 5
#define PROP_FM_RSQ_INTERRUPT_SOURCE_HDLEVELHINT_MSB 5
#define PROP_FM_RSQ_INTERRUPT_SOURCE_HDLEVELHINT_MASK 0x20
#define PROP_FM_RSQ_INTERRUPT_SOURCE_HDLEVELHINT_BIT 0x20
#define PROP_FM_RSQ_INTERRUPT_SOURCE_HDLEVELHINT_value() (((PROP_FM_RSQ_INTERRUPT_SOURCE_value()) & 0x20)>>5)
#define PROP_FM_RSQ_INTERRUPT_SOURCE_HDLEVELLINT_LSB 4
#define PROP_FM_RSQ_INTERRUPT_SOURCE_HDLEVELLINT_MSB 4
#define PROP_FM_RSQ_INTERRUPT_SOURCE_HDLEVELLINT_MASK 0x10
#define PROP_FM_RSQ_INTERRUPT_SOURCE_HDLEVELLINT_BIT 0x10
#define PROP_FM_RSQ_INTERRUPT_SOURCE_HDLEVELLINT_value() (((PROP_FM_RSQ_INTERRUPT_SOURCE_value()) & 0x10)>>4)
#define PROP_FM_RSQ_INTERRUPT_SOURCE_SNRHINT_LSB 3
#define PROP_FM_RSQ_INTERRUPT_SOURCE_SNRHINT_MSB 3
#define PROP_FM_RSQ_INTERRUPT_SOURCE_SNRHINT_MASK 0x8
#define PROP_FM_RSQ_INTERRUPT_SOURCE_SNRHINT_BIT 0x8
#define PROP_FM_RSQ_INTERRUPT_SOURCE_SNRHINT_value() (((PROP_FM_RSQ_INTERRUPT_SOURCE_value()) & 0x8)>>3)
#define PROP_FM_RSQ_INTERRUPT_SOURCE_SNRLINT_LSB 2
#define PROP_FM_RSQ_INTERRUPT_SOURCE_SNRLINT_MSB 2
#define PROP_FM_RSQ_INTERRUPT_SOURCE_SNRLINT_MASK 0x4
#define PROP_FM_RSQ_INTERRUPT_SOURCE_SNRLINT_BIT 0x4
#define PROP_FM_RSQ_INTERRUPT_SOURCE_SNRLINT_value() (((PROP_FM_RSQ_INTERRUPT_SOURCE_value()) & 0x4)>>2)
#define PROP_FM_RSQ_INTERRUPT_SOURCE_RSSIHINT_LSB 1
#define PROP_FM_RSQ_INTERRUPT_SOURCE_RSSIHINT_MSB 1
#define PROP_FM_RSQ_INTERRUPT_SOURCE_RSSIHINT_MASK 0x2
#define PROP_FM_RSQ_INTERRUPT_SOURCE_RSSIHINT_BIT 0x2
#define PROP_FM_RSQ_INTERRUPT_SOURCE_RSSIHINT_value() (((PROP_FM_RSQ_INTERRUPT_SOURCE_value()) & 0x2)>>1)
#define PROP_FM_RSQ_INTERRUPT_SOURCE_RSSILINT_LSB 0
#define PROP_FM_RSQ_INTERRUPT_SOURCE_RSSILINT_MSB 0
#define PROP_FM_RSQ_INTERRUPT_SOURCE_RSSILINT_MASK 0x1
#define PROP_FM_RSQ_INTERRUPT_SOURCE_RSSILINT_BIT 0x1
#define PROP_FM_RSQ_INTERRUPT_SOURCE_RSSILINT_value() (((PROP_FM_RSQ_INTERRUPT_SOURCE_value()) & 0x1)>>0)
#define PROP_FM_RSQ_INTERRUPT_SOURCE_DEFAULT 0

#define PROP_FM_RSQ_SNR_HIGH_THRESHOLD_MASK 0xFFFF
#define PROP_FM_RSQ_SNR_HIGH_THRESHOLD_INDEX 0x01
#define PROP_FM_RSQ_SNR_HIGH_THRESHOLD_GROUP 0x33
#define PROP_FM_RSQ_SNR_HIGH_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_FM_RSQ_SNR_HIGH_THRESHOLD_GROUP, PROP_FM_RSQ_SNR_HIGH_THRESHOLD_INDEX))
#define PROP_FM_RSQ_SNR_HIGH_THRESHOLD_SNRH_LSB 0
#define PROP_FM_RSQ_SNR_HIGH_THRESHOLD_SNRH_MSB 7
#define PROP_FM_RSQ_SNR_HIGH_THRESHOLD_SNRH_MASK 0xFF
#define PROP_FM_RSQ_SNR_HIGH_THRESHOLD_SNRH_value() (int8_t)(((PROP_FM_RSQ_SNR_HIGH_THRESHOLD_value()) & 0xFF)>>0)
#define PROP_FM_RSQ_SNR_HIGH_THRESHOLD_SNRH_RANGE_MIN (-128)
#define PROP_FM_RSQ_SNR_HIGH_THRESHOLD_SNRH_RANGE_MAX (127)
#define PROP_FM_RSQ_SNR_HIGH_THRESHOLD_DEFAULT 127

#define PROP_FM_RSQ_SNR_LOW_THRESHOLD_MASK 0xFFFF
#define PROP_FM_RSQ_SNR_LOW_THRESHOLD_INDEX 0x02
#define PROP_FM_RSQ_SNR_LOW_THRESHOLD_GROUP 0x33
#define PROP_FM_RSQ_SNR_LOW_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_FM_RSQ_SNR_LOW_THRESHOLD_GROUP, PROP_FM_RSQ_SNR_LOW_THRESHOLD_INDEX))
#define PROP_FM_RSQ_SNR_LOW_THRESHOLD_SNRL_LSB 0
#define PROP_FM_RSQ_SNR_LOW_THRESHOLD_SNRL_MSB 7
#define PROP_FM_RSQ_SNR_LOW_THRESHOLD_SNRL_MASK 0xFF
#define PROP_FM_RSQ_SNR_LOW_THRESHOLD_SNRL_value() (int8_t)(((PROP_FM_RSQ_SNR_LOW_THRESHOLD_value()) & 0xFF)>>0)
#define PROP_FM_RSQ_SNR_LOW_THRESHOLD_SNRL_RANGE_MIN (-128)
#define PROP_FM_RSQ_SNR_LOW_THRESHOLD_SNRL_RANGE_MAX (127)
#define PROP_FM_RSQ_SNR_LOW_THRESHOLD_DEFAULT -128

#define PROP_FM_RSQ_RSSI_HIGH_THRESHOLD_MASK 0xFFFF
#define PROP_FM_RSQ_RSSI_HIGH_THRESHOLD_INDEX 0x03
#define PROP_FM_RSQ_RSSI_HIGH_THRESHOLD_GROUP 0x33
#define PROP_FM_RSQ_RSSI_HIGH_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_FM_RSQ_RSSI_HIGH_THRESHOLD_GROUP, PROP_FM_RSQ_RSSI_HIGH_THRESHOLD_INDEX))
#define PROP_FM_RSQ_RSSI_HIGH_THRESHOLD_RSSIH_LSB 0
#define PROP_FM_RSQ_RSSI_HIGH_THRESHOLD_RSSIH_MSB 7
#define PROP_FM_RSQ_RSSI_HIGH_THRESHOLD_RSSIH_MASK 0xFF
#define PROP_FM_RSQ_RSSI_HIGH_THRESHOLD_RSSIH_value() (int8_t)(((PROP_FM_RSQ_RSSI_HIGH_THRESHOLD_value()) & 0xFF)>>0)
#define PROP_FM_RSQ_RSSI_HIGH_THRESHOLD_RSSIH_RANGE_MIN (-128)
#define PROP_FM_RSQ_RSSI_HIGH_THRESHOLD_RSSIH_RANGE_MAX (127)
#define PROP_FM_RSQ_RSSI_HIGH_THRESHOLD_DEFAULT 127

#define PROP_FM_RSQ_RSSI_LOW_THRESHOLD_MASK 0xFFFF
#define PROP_FM_RSQ_RSSI_LOW_THRESHOLD_INDEX 0x04
#define PROP_FM_RSQ_RSSI_LOW_THRESHOLD_GROUP 0x33
#define PROP_FM_RSQ_RSSI_LOW_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_FM_RSQ_RSSI_LOW_THRESHOLD_GROUP, PROP_FM_RSQ_RSSI_LOW_THRESHOLD_INDEX))
#define PROP_FM_RSQ_RSSI_LOW_THRESHOLD_RSSIL_LSB 0
#define PROP_FM_RSQ_RSSI_LOW_THRESHOLD_RSSIL_MSB 7
#define PROP_FM_RSQ_RSSI_LOW_THRESHOLD_RSSIL_MASK 0xFF
#define PROP_FM_RSQ_RSSI_LOW_THRESHOLD_RSSIL_value() (int8_t)(((PROP_FM_RSQ_RSSI_LOW_THRESHOLD_value()) & 0xFF)>>0)
#define PROP_FM_RSQ_RSSI_LOW_THRESHOLD_RSSIL_RANGE_MIN (-128)
#define PROP_FM_RSQ_RSSI_LOW_THRESHOLD_RSSIL_RANGE_MAX (127)
#define PROP_FM_RSQ_RSSI_LOW_THRESHOLD_DEFAULT -128

#define PROP_FM_RSQ_HD_DETECTION_MASK 0xFFFF
#define PROP_FM_RSQ_HD_DETECTION_INDEX 0x07
#define PROP_FM_RSQ_HD_DETECTION_GROUP 0x33
#define PROP_FM_RSQ_HD_DETECTION_value() (sys_prop_ReturnProperty(PROP_FM_RSQ_HD_DETECTION_GROUP, PROP_FM_RSQ_HD_DETECTION_INDEX))
#define PROP_FM_RSQ_HD_DETECTION_SAMPLES_LSB 0
#define PROP_FM_RSQ_HD_DETECTION_SAMPLES_MSB 7
#define PROP_FM_RSQ_HD_DETECTION_SAMPLES_MASK 0xFF
#define PROP_FM_RSQ_HD_DETECTION_SAMPLES_value() (uint8_t)(((PROP_FM_RSQ_HD_DETECTION_value()) & 0xFF)>>0)
#define PROP_FM_RSQ_HD_DETECTION_SAMPLES_RANGE_MIN (5)
#define PROP_FM_RSQ_HD_DETECTION_SAMPLES_RANGE_MAX (64)
#define PROP_FM_RSQ_HD_DETECTION_DEFAULT 0x000d

#define PROP_FM_RSQ_HD_LEVEL_TIME_CONST_MASK 0xFFFF
#define PROP_FM_RSQ_HD_LEVEL_TIME_CONST_INDEX 0x08
#define PROP_FM_RSQ_HD_LEVEL_TIME_CONST_GROUP 0x33
#define PROP_FM_RSQ_HD_LEVEL_TIME_CONST_value() (sys_prop_ReturnProperty(PROP_FM_RSQ_HD_LEVEL_TIME_CONST_GROUP, PROP_FM_RSQ_HD_LEVEL_TIME_CONST_INDEX))
#define PROP_FM_RSQ_HD_LEVEL_TIME_CONST_FILTER_TIME_CONSTANT_LSB 0
#define PROP_FM_RSQ_HD_LEVEL_TIME_CONST_FILTER_TIME_CONSTANT_MSB 7
#define PROP_FM_RSQ_HD_LEVEL_TIME_CONST_FILTER_TIME_CONSTANT_MASK 0xFF
#define PROP_FM_RSQ_HD_LEVEL_TIME_CONST_FILTER_TIME_CONSTANT_value() (uint8_t)(((PROP_FM_RSQ_HD_LEVEL_TIME_CONST_value()) & 0xFF)>>0)
#define PROP_FM_RSQ_HD_LEVEL_TIME_CONST_FILTER_TIME_CONSTANT_RANGE_MIN (1)
#define PROP_FM_RSQ_HD_LEVEL_TIME_CONST_FILTER_TIME_CONSTANT_RANGE_MAX (255)
#define PROP_FM_RSQ_HD_LEVEL_TIME_CONST_DEFAULT 32

#define PROP_FM_RSQ_HDDETECTED_THD_MASK 0xFFFF
#define PROP_FM_RSQ_HDDETECTED_THD_INDEX 0x09
#define PROP_FM_RSQ_HDDETECTED_THD_GROUP 0x33
#define PROP_FM_RSQ_HDDETECTED_THD_value() (sys_prop_ReturnProperty(PROP_FM_RSQ_HDDETECTED_THD_GROUP, PROP_FM_RSQ_HDDETECTED_THD_INDEX))
#define PROP_FM_RSQ_HDDETECTED_THD_HDDETECTED_THD_LSB 8
#define PROP_FM_RSQ_HDDETECTED_THD_HDDETECTED_THD_MSB 15
#define PROP_FM_RSQ_HDDETECTED_THD_HDDETECTED_THD_MASK 0xFF00
#define PROP_FM_RSQ_HDDETECTED_THD_HDDETECTED_THD_value() (uint8_t)(((PROP_FM_RSQ_HDDETECTED_THD_value()) & 0xFF00)>>8)
#define PROP_FM_RSQ_HDDETECTED_THD_HDDETECTED_THD_RANGE_MIN (1)
#define PROP_FM_RSQ_HDDETECTED_THD_HDDETECTED_THD_RANGE_MAX (100)
#define PROP_FM_RSQ_HDDETECTED_THD_FLT_HDDETECTED_THD_LSB 0
#define PROP_FM_RSQ_HDDETECTED_THD_FLT_HDDETECTED_THD_MSB 7
#define PROP_FM_RSQ_HDDETECTED_THD_FLT_HDDETECTED_THD_MASK 0xFF
#define PROP_FM_RSQ_HDDETECTED_THD_FLT_HDDETECTED_THD_value() (uint8_t)(((PROP_FM_RSQ_HDDETECTED_THD_value()) & 0xFF)>>0)
#define PROP_FM_RSQ_HDDETECTED_THD_FLT_HDDETECTED_THD_RANGE_MIN (1)
#define PROP_FM_RSQ_HDDETECTED_THD_FLT_HDDETECTED_THD_RANGE_MAX (100)
#define PROP_FM_RSQ_HDDETECTED_THD_DEFAULT 0x1e1e

#define PROP_FM_RSQ_HDLEVEL_HIGH_THRESHOLD_MASK 0xFFFF
#define PROP_FM_RSQ_HDLEVEL_HIGH_THRESHOLD_INDEX 0x0A
#define PROP_FM_RSQ_HDLEVEL_HIGH_THRESHOLD_GROUP 0x33
#define PROP_FM_RSQ_HDLEVEL_HIGH_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_FM_RSQ_HDLEVEL_HIGH_THRESHOLD_GROUP, PROP_FM_RSQ_HDLEVEL_HIGH_THRESHOLD_INDEX))
#define PROP_FM_RSQ_HDLEVEL_HIGH_THRESHOLD_HDLEVELH_LSB 0
#define PROP_FM_RSQ_HDLEVEL_HIGH_THRESHOLD_HDLEVELH_MSB 7
#define PROP_FM_RSQ_HDLEVEL_HIGH_THRESHOLD_HDLEVELH_MASK 0xFF
#define PROP_FM_RSQ_HDLEVEL_HIGH_THRESHOLD_HDLEVELH_value() (uint8_t)(((PROP_FM_RSQ_HDLEVEL_HIGH_THRESHOLD_value()) & 0xFF)>>0)
#define PROP_FM_RSQ_HDLEVEL_HIGH_THRESHOLD_HDLEVELH_RANGE_MIN (0)
#define PROP_FM_RSQ_HDLEVEL_HIGH_THRESHOLD_HDLEVELH_RANGE_MAX (100)
#define PROP_FM_RSQ_HDLEVEL_HIGH_THRESHOLD_DEFAULT 100

#define PROP_FM_RSQ_HDLEVEL_LOW_THRESHOLD_MASK 0xFFFF
#define PROP_FM_RSQ_HDLEVEL_LOW_THRESHOLD_INDEX 0x0B
#define PROP_FM_RSQ_HDLEVEL_LOW_THRESHOLD_GROUP 0x33
#define PROP_FM_RSQ_HDLEVEL_LOW_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_FM_RSQ_HDLEVEL_LOW_THRESHOLD_GROUP, PROP_FM_RSQ_HDLEVEL_LOW_THRESHOLD_INDEX))
#define PROP_FM_RSQ_HDLEVEL_LOW_THRESHOLD_HDLEVELL_LSB 0
#define PROP_FM_RSQ_HDLEVEL_LOW_THRESHOLD_HDLEVELL_MSB 7
#define PROP_FM_RSQ_HDLEVEL_LOW_THRESHOLD_HDLEVELL_MASK 0xFF
#define PROP_FM_RSQ_HDLEVEL_LOW_THRESHOLD_HDLEVELL_value() (uint8_t)(((PROP_FM_RSQ_HDLEVEL_LOW_THRESHOLD_value()) & 0xFF)>>0)
#define PROP_FM_RSQ_HDLEVEL_LOW_THRESHOLD_HDLEVELL_RANGE_MIN (0)
#define PROP_FM_RSQ_HDLEVEL_LOW_THRESHOLD_HDLEVELL_RANGE_MAX (100)
#define PROP_FM_RSQ_HDLEVEL_LOW_THRESHOLD_DEFAULT 0

#define PROP_FM_ACF_INTERRUPT_SOURCE_MASK 0xFFFF
#define PROP_FM_ACF_INTERRUPT_SOURCE_INDEX 0x00
#define PROP_FM_ACF_INTERRUPT_SOURCE_GROUP 0x34
#define PROP_FM_ACF_INTERRUPT_SOURCE_value() (sys_prop_ReturnProperty(PROP_FM_ACF_INTERRUPT_SOURCE_GROUP, PROP_FM_ACF_INTERRUPT_SOURCE_INDEX))
#define PROP_FM_ACF_INTERRUPT_SOURCE_BLEND_INTEN_LSB 2
#define PROP_FM_ACF_INTERRUPT_SOURCE_BLEND_INTEN_MSB 2
#define PROP_FM_ACF_INTERRUPT_SOURCE_BLEND_INTEN_MASK 0x4
#define PROP_FM_ACF_INTERRUPT_SOURCE_BLEND_INTEN_BIT 0x4
#define PROP_FM_ACF_INTERRUPT_SOURCE_BLEND_INTEN_value() (((PROP_FM_ACF_INTERRUPT_SOURCE_value()) & 0x4)>>2)
#define PROP_FM_ACF_INTERRUPT_SOURCE_HIGHCUT_INTEN_LSB 1
#define PROP_FM_ACF_INTERRUPT_SOURCE_HIGHCUT_INTEN_MSB 1
#define PROP_FM_ACF_INTERRUPT_SOURCE_HIGHCUT_INTEN_MASK 0x2
#define PROP_FM_ACF_INTERRUPT_SOURCE_HIGHCUT_INTEN_BIT 0x2
#define PROP_FM_ACF_INTERRUPT_SOURCE_HIGHCUT_INTEN_value() (((PROP_FM_ACF_INTERRUPT_SOURCE_value()) & 0x2)>>1)
#define PROP_FM_ACF_INTERRUPT_SOURCE_SMUTE_INTEN_LSB 0
#define PROP_FM_ACF_INTERRUPT_SOURCE_SMUTE_INTEN_MSB 0
#define PROP_FM_ACF_INTERRUPT_SOURCE_SMUTE_INTEN_MASK 0x1
#define PROP_FM_ACF_INTERRUPT_SOURCE_SMUTE_INTEN_BIT 0x1
#define PROP_FM_ACF_INTERRUPT_SOURCE_SMUTE_INTEN_value() (((PROP_FM_ACF_INTERRUPT_SOURCE_value()) & 0x1)>>0)
#define PROP_FM_ACF_INTERRUPT_SOURCE_DEFAULT 0

#define PROP_FM_ACF_SOFTMUTE_THRESHOLD_MASK 0xFFFF
#define PROP_FM_ACF_SOFTMUTE_THRESHOLD_INDEX 0x01
#define PROP_FM_ACF_SOFTMUTE_THRESHOLD_GROUP 0x34
#define PROP_FM_ACF_SOFTMUTE_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_FM_ACF_SOFTMUTE_THRESHOLD_GROUP, PROP_FM_ACF_SOFTMUTE_THRESHOLD_INDEX))
#define PROP_FM_ACF_SOFTMUTE_THRESHOLD_SMATTN_THRESH_LSB 0
#define PROP_FM_ACF_SOFTMUTE_THRESHOLD_SMATTN_THRESH_MSB 4
#define PROP_FM_ACF_SOFTMUTE_THRESHOLD_SMATTN_THRESH_MASK 0x1F
#define PROP_FM_ACF_SOFTMUTE_THRESHOLD_SMATTN_THRESH_value() (((PROP_FM_ACF_SOFTMUTE_THRESHOLD_value()) & 0x1F)>>0)
#define PROP_FM_ACF_SOFTMUTE_THRESHOLD_SMATTN_THRESH_RANGE_MIN (0)
#define PROP_FM_ACF_SOFTMUTE_THRESHOLD_SMATTN_THRESH_RANGE_MAX (31)
#define PROP_FM_ACF_SOFTMUTE_THRESHOLD_DEFAULT 31

#define PROP_FM_ACF_HIGHCUT_THRESHOLD_MASK 0xFFFF
#define PROP_FM_ACF_HIGHCUT_THRESHOLD_INDEX 0x02
#define PROP_FM_ACF_HIGHCUT_THRESHOLD_GROUP 0x34
#define PROP_FM_ACF_HIGHCUT_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_FM_ACF_HIGHCUT_THRESHOLD_GROUP, PROP_FM_ACF_HIGHCUT_THRESHOLD_INDEX))
#define PROP_FM_ACF_HIGHCUT_THRESHOLD_HIGHCUT_THRESH_LSB 0
#define PROP_FM_ACF_HIGHCUT_THRESHOLD_HIGHCUT_THRESH_MSB 7
#define PROP_FM_ACF_HIGHCUT_THRESHOLD_HIGHCUT_THRESH_MASK 0xFF
#define PROP_FM_ACF_HIGHCUT_THRESHOLD_HIGHCUT_THRESH_value() (uint8_t)(((PROP_FM_ACF_HIGHCUT_THRESHOLD_value()) & 0xFF)>>0)
#define PROP_FM_ACF_HIGHCUT_THRESHOLD_HIGHCUT_THRESH_RANGE_MIN (0)
#define PROP_FM_ACF_HIGHCUT_THRESHOLD_HIGHCUT_THRESH_RANGE_MAX (200)
#define PROP_FM_ACF_HIGHCUT_THRESHOLD_DEFAULT 0

#define PROP_FM_ACF_BLEND_THRESHOLD_MASK 0xFFFF
#define PROP_FM_ACF_BLEND_THRESHOLD_INDEX 0x03
#define PROP_FM_ACF_BLEND_THRESHOLD_GROUP 0x34
#define PROP_FM_ACF_BLEND_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_FM_ACF_BLEND_THRESHOLD_GROUP, PROP_FM_ACF_BLEND_THRESHOLD_INDEX))
#define PROP_FM_ACF_BLEND_THRESHOLD_BLEND_THRESH_LSB 0
#define PROP_FM_ACF_BLEND_THRESHOLD_BLEND_THRESH_MSB 6
#define PROP_FM_ACF_BLEND_THRESHOLD_BLEND_THRESH_MASK 0x7F
#define PROP_FM_ACF_BLEND_THRESHOLD_BLEND_THRESH_value() (((PROP_FM_ACF_BLEND_THRESHOLD_value()) & 0x7F)>>0)
#define PROP_FM_ACF_BLEND_THRESHOLD_BLEND_THRESH_RANGE_MIN (0)
#define PROP_FM_ACF_BLEND_THRESHOLD_BLEND_THRESH_RANGE_MAX (100)
#define PROP_FM_ACF_BLEND_THRESHOLD_DEFAULT 0

#define PROP_FM_ACF_SOFTMUTE_TOLERANCE_MASK 0xFFFF
#define PROP_FM_ACF_SOFTMUTE_TOLERANCE_INDEX 0x04
#define PROP_FM_ACF_SOFTMUTE_TOLERANCE_GROUP 0x34
#define PROP_FM_ACF_SOFTMUTE_TOLERANCE_value() (sys_prop_ReturnProperty(PROP_FM_ACF_SOFTMUTE_TOLERANCE_GROUP, PROP_FM_ACF_SOFTMUTE_TOLERANCE_INDEX))
#define PROP_FM_ACF_SOFTMUTE_TOLERANCE_SMUTE_TOL_LSB 0
#define PROP_FM_ACF_SOFTMUTE_TOLERANCE_SMUTE_TOL_MSB 4
#define PROP_FM_ACF_SOFTMUTE_TOLERANCE_SMUTE_TOL_MASK 0x1F
#define PROP_FM_ACF_SOFTMUTE_TOLERANCE_SMUTE_TOL_value() (((PROP_FM_ACF_SOFTMUTE_TOLERANCE_value()) & 0x1F)>>0)
#define PROP_FM_ACF_SOFTMUTE_TOLERANCE_SMUTE_TOL_RANGE_MIN (0)
#define PROP_FM_ACF_SOFTMUTE_TOLERANCE_SMUTE_TOL_RANGE_MAX (31)
#define PROP_FM_ACF_SOFTMUTE_TOLERANCE_DEFAULT 2

#define PROP_FM_ACF_HIGHCUT_TOLERANCE_MASK 0xFFFF
#define PROP_FM_ACF_HIGHCUT_TOLERANCE_INDEX 0x05
#define PROP_FM_ACF_HIGHCUT_TOLERANCE_GROUP 0x34
#define PROP_FM_ACF_HIGHCUT_TOLERANCE_value() (sys_prop_ReturnProperty(PROP_FM_ACF_HIGHCUT_TOLERANCE_GROUP, PROP_FM_ACF_HIGHCUT_TOLERANCE_INDEX))
#define PROP_FM_ACF_HIGHCUT_TOLERANCE_HIGHCUT_TOL_LSB 0
#define PROP_FM_ACF_HIGHCUT_TOLERANCE_HIGHCUT_TOL_MSB 7
#define PROP_FM_ACF_HIGHCUT_TOLERANCE_HIGHCUT_TOL_MASK 0xFF
#define PROP_FM_ACF_HIGHCUT_TOLERANCE_HIGHCUT_TOL_value() (uint8_t)(((PROP_FM_ACF_HIGHCUT_TOLERANCE_value()) & 0xFF)>>0)
#define PROP_FM_ACF_HIGHCUT_TOLERANCE_HIGHCUT_TOL_RANGE_MIN (0)
#define PROP_FM_ACF_HIGHCUT_TOLERANCE_HIGHCUT_TOL_RANGE_MAX (200)
#define PROP_FM_ACF_HIGHCUT_TOLERANCE_DEFAULT 20

#define PROP_FM_ACF_BLEND_TOLERANCE_MASK 0xFFFF
#define PROP_FM_ACF_BLEND_TOLERANCE_INDEX 0x06
#define PROP_FM_ACF_BLEND_TOLERANCE_GROUP 0x34
#define PROP_FM_ACF_BLEND_TOLERANCE_value() (sys_prop_ReturnProperty(PROP_FM_ACF_BLEND_TOLERANCE_GROUP, PROP_FM_ACF_BLEND_TOLERANCE_INDEX))
#define PROP_FM_ACF_BLEND_TOLERANCE_BLEND_TOL_LSB 0
#define PROP_FM_ACF_BLEND_TOLERANCE_BLEND_TOL_MSB 6
#define PROP_FM_ACF_BLEND_TOLERANCE_BLEND_TOL_MASK 0x7F
#define PROP_FM_ACF_BLEND_TOLERANCE_BLEND_TOL_value() (((PROP_FM_ACF_BLEND_TOLERANCE_value()) & 0x7F)>>0)
#define PROP_FM_ACF_BLEND_TOLERANCE_BLEND_TOL_RANGE_MIN (0)
#define PROP_FM_ACF_BLEND_TOLERANCE_BLEND_TOL_RANGE_MAX (100)
#define PROP_FM_ACF_BLEND_TOLERANCE_DEFAULT 5

#define PROP_FM_ACF_CONTROL_SOURCE_MASK 0xFFFF
#define PROP_FM_ACF_CONTROL_SOURCE_INDEX 0x08
#define PROP_FM_ACF_CONTROL_SOURCE_GROUP 0x34
#define PROP_FM_ACF_CONTROL_SOURCE_value() (sys_prop_ReturnProperty(PROP_FM_ACF_CONTROL_SOURCE_GROUP, PROP_FM_ACF_CONTROL_SOURCE_INDEX))
#define PROP_FM_ACF_CONTROL_SOURCE_DEV_CHBW_LSB 1
#define PROP_FM_ACF_CONTROL_SOURCE_DEV_CHBW_MSB 1
#define PROP_FM_ACF_CONTROL_SOURCE_DEV_CHBW_MASK 0x2
#define PROP_FM_ACF_CONTROL_SOURCE_DEV_CHBW_BIT 0x2
#define PROP_FM_ACF_CONTROL_SOURCE_DEV_CHBW_value() (((PROP_FM_ACF_CONTROL_SOURCE_value()) & 0x2)>>1)
#define PROP_FM_ACF_CONTROL_SOURCE_DEV_CHBW_ENUM_CHBW_USE_RSSI 0
#define PROP_FM_ACF_CONTROL_SOURCE_DEV_CHBW_ENUM_CHBW_USE_DEV 1
#define PROP_FM_ACF_CONTROL_SOURCE_DEFAULT 0

#define PROP_FM_SOFTMUTE_SNR_LIMITS_MASK 0xFFFF
#define PROP_FM_SOFTMUTE_SNR_LIMITS_INDEX 0x00
#define PROP_FM_SOFTMUTE_SNR_LIMITS_GROUP 0x35
#define PROP_FM_SOFTMUTE_SNR_LIMITS_value() (sys_prop_ReturnProperty(PROP_FM_SOFTMUTE_SNR_LIMITS_GROUP, PROP_FM_SOFTMUTE_SNR_LIMITS_INDEX))
#define PROP_FM_SOFTMUTE_SNR_LIMITS_XMAX_LSB 8
#define PROP_FM_SOFTMUTE_SNR_LIMITS_XMAX_MSB 15
#define PROP_FM_SOFTMUTE_SNR_LIMITS_XMAX_MASK 0xFF00
#define PROP_FM_SOFTMUTE_SNR_LIMITS_XMAX_value() (int8_t)(((PROP_FM_SOFTMUTE_SNR_LIMITS_value()) & 0xFF00)>>8)
#define PROP_FM_SOFTMUTE_SNR_LIMITS_XMAX_RANGE_MIN (-20)
#define PROP_FM_SOFTMUTE_SNR_LIMITS_XMAX_RANGE_MAX (64)
#define PROP_FM_SOFTMUTE_SNR_LIMITS_XMIN_LSB 0
#define PROP_FM_SOFTMUTE_SNR_LIMITS_XMIN_MSB 7
#define PROP_FM_SOFTMUTE_SNR_LIMITS_XMIN_MASK 0xFF
#define PROP_FM_SOFTMUTE_SNR_LIMITS_XMIN_value() (int8_t)(((PROP_FM_SOFTMUTE_SNR_LIMITS_value()) & 0xFF)>>0)
#define PROP_FM_SOFTMUTE_SNR_LIMITS_XMIN_RANGE_MIN (-20)
#define PROP_FM_SOFTMUTE_SNR_LIMITS_XMIN_RANGE_MAX (64)
#define PROP_FM_SOFTMUTE_SNR_LIMITS_DEFAULT 0x0602

#define PROP_FM_SOFTMUTE_SNR_ATTENUATION_MASK 0xFFFF
#define PROP_FM_SOFTMUTE_SNR_ATTENUATION_INDEX 0x01
#define PROP_FM_SOFTMUTE_SNR_ATTENUATION_GROUP 0x35
#define PROP_FM_SOFTMUTE_SNR_ATTENUATION_value() (sys_prop_ReturnProperty(PROP_FM_SOFTMUTE_SNR_ATTENUATION_GROUP, PROP_FM_SOFTMUTE_SNR_ATTENUATION_INDEX))
#define PROP_FM_SOFTMUTE_SNR_ATTENUATION_ATTENMIN_LSB 8
#define PROP_FM_SOFTMUTE_SNR_ATTENUATION_ATTENMIN_MSB 15
#define PROP_FM_SOFTMUTE_SNR_ATTENUATION_ATTENMIN_MASK 0xFF00
#define PROP_FM_SOFTMUTE_SNR_ATTENUATION_ATTENMIN_value() (uint8_t)(((PROP_FM_SOFTMUTE_SNR_ATTENUATION_value()) & 0xFF00)>>8)
#define PROP_FM_SOFTMUTE_SNR_ATTENUATION_ATTENMIN_RANGE_MIN (0)
#define PROP_FM_SOFTMUTE_SNR_ATTENUATION_ATTENMIN_RANGE_MAX (31)
#define PROP_FM_SOFTMUTE_SNR_ATTENUATION_ATTENMAX_LSB 0
#define PROP_FM_SOFTMUTE_SNR_ATTENUATION_ATTENMAX_MSB 7
#define PROP_FM_SOFTMUTE_SNR_ATTENUATION_ATTENMAX_MASK 0xFF
#define PROP_FM_SOFTMUTE_SNR_ATTENUATION_ATTENMAX_value() (uint8_t)(((PROP_FM_SOFTMUTE_SNR_ATTENUATION_value()) & 0xFF)>>0)
#define PROP_FM_SOFTMUTE_SNR_ATTENUATION_ATTENMAX_RANGE_MIN (0)
#define PROP_FM_SOFTMUTE_SNR_ATTENUATION_ATTENMAX_RANGE_MAX (31)
#define PROP_FM_SOFTMUTE_SNR_ATTENUATION_DEFAULT 0x0008

#define PROP_FM_SOFTMUTE_SNR_ATTACK_TIME_MASK 0xFFFF
#define PROP_FM_SOFTMUTE_SNR_ATTACK_TIME_INDEX 0x02
#define PROP_FM_SOFTMUTE_SNR_ATTACK_TIME_GROUP 0x35
#define PROP_FM_SOFTMUTE_SNR_ATTACK_TIME_value() (sys_prop_ReturnProperty(PROP_FM_SOFTMUTE_SNR_ATTACK_TIME_GROUP, PROP_FM_SOFTMUTE_SNR_ATTACK_TIME_INDEX))
#define PROP_FM_SOFTMUTE_SNR_ATTACK_TIME_ATTACK_LSB 0
#define PROP_FM_SOFTMUTE_SNR_ATTACK_TIME_ATTACK_MSB 15
#define PROP_FM_SOFTMUTE_SNR_ATTACK_TIME_ATTACK_MASK 0xFFFF
#define PROP_FM_SOFTMUTE_SNR_ATTACK_TIME_ATTACK_value() (uint16_t)(((PROP_FM_SOFTMUTE_SNR_ATTACK_TIME_value()) & 0xFFFF)>>0)
#define PROP_FM_SOFTMUTE_SNR_ATTACK_TIME_ATTACK_RANGE_MIN (16)
#define PROP_FM_SOFTMUTE_SNR_ATTACK_TIME_ATTACK_RANGE_MAX (65535)
#define PROP_FM_SOFTMUTE_SNR_ATTACK_TIME_DEFAULT 16

#define PROP_FM_SOFTMUTE_SNR_RELEASE_TIME_MASK 0xFFFF
#define PROP_FM_SOFTMUTE_SNR_RELEASE_TIME_INDEX 0x03
#define PROP_FM_SOFTMUTE_SNR_RELEASE_TIME_GROUP 0x35
#define PROP_FM_SOFTMUTE_SNR_RELEASE_TIME_value() (sys_prop_ReturnProperty(PROP_FM_SOFTMUTE_SNR_RELEASE_TIME_GROUP, PROP_FM_SOFTMUTE_SNR_RELEASE_TIME_INDEX))
#define PROP_FM_SOFTMUTE_SNR_RELEASE_TIME_RELEASE_LSB 0
#define PROP_FM_SOFTMUTE_SNR_RELEASE_TIME_RELEASE_MSB 15
#define PROP_FM_SOFTMUTE_SNR_RELEASE_TIME_RELEASE_MASK 0xFFFF
#define PROP_FM_SOFTMUTE_SNR_RELEASE_TIME_RELEASE_value() (uint16_t)(((PROP_FM_SOFTMUTE_SNR_RELEASE_TIME_value()) & 0xFFFF)>>0)
#define PROP_FM_SOFTMUTE_SNR_RELEASE_TIME_RELEASE_RANGE_MIN (16)
#define PROP_FM_SOFTMUTE_SNR_RELEASE_TIME_RELEASE_RANGE_MAX (65535)
#define PROP_FM_SOFTMUTE_SNR_RELEASE_TIME_DEFAULT 4000

#define PROP_FM_HIGHCUT_RSSI_LIMITS_MASK 0xFFFF
#define PROP_FM_HIGHCUT_RSSI_LIMITS_INDEX 0x00
#define PROP_FM_HIGHCUT_RSSI_LIMITS_GROUP 0x36
#define PROP_FM_HIGHCUT_RSSI_LIMITS_value() (sys_prop_ReturnProperty(PROP_FM_HIGHCUT_RSSI_LIMITS_GROUP, PROP_FM_HIGHCUT_RSSI_LIMITS_INDEX))
#define PROP_FM_HIGHCUT_RSSI_LIMITS_XMAX_LSB 8
#define PROP_FM_HIGHCUT_RSSI_LIMITS_XMAX_MSB 15
#define PROP_FM_HIGHCUT_RSSI_LIMITS_XMAX_MASK 0xFF00
#define PROP_FM_HIGHCUT_RSSI_LIMITS_XMAX_value() (int8_t)(((PROP_FM_HIGHCUT_RSSI_LIMITS_value()) & 0xFF00)>>8)
#define PROP_FM_HIGHCUT_RSSI_LIMITS_XMAX_RANGE_MIN (-20)
#define PROP_FM_HIGHCUT_RSSI_LIMITS_XMAX_RANGE_MAX (120)
#define PROP_FM_HIGHCUT_RSSI_LIMITS_XMIN_LSB 0
#define PROP_FM_HIGHCUT_RSSI_LIMITS_XMIN_MSB 7
#define PROP_FM_HIGHCUT_RSSI_LIMITS_XMIN_MASK 0xFF
#define PROP_FM_HIGHCUT_RSSI_LIMITS_XMIN_value() (int8_t)(((PROP_FM_HIGHCUT_RSSI_LIMITS_value()) & 0xFF)>>0)
#define PROP_FM_HIGHCUT_RSSI_LIMITS_XMIN_RANGE_MIN (-20)
#define PROP_FM_HIGHCUT_RSSI_LIMITS_XMIN_RANGE_MAX (120)
#define PROP_FM_HIGHCUT_RSSI_LIMITS_DEFAULT 0x0C06

#define PROP_FM_HIGHCUT_RSSI_CUTOFF_FREQ_MASK 0xFFFF
#define PROP_FM_HIGHCUT_RSSI_CUTOFF_FREQ_INDEX 0x01
#define PROP_FM_HIGHCUT_RSSI_CUTOFF_FREQ_GROUP 0x36
#define PROP_FM_HIGHCUT_RSSI_CUTOFF_FREQ_value() (sys_prop_ReturnProperty(PROP_FM_HIGHCUT_RSSI_CUTOFF_FREQ_GROUP, PROP_FM_HIGHCUT_RSSI_CUTOFF_FREQ_INDEX))
#define PROP_FM_HIGHCUT_RSSI_CUTOFF_FREQ_YMAX_LSB 8
#define PROP_FM_HIGHCUT_RSSI_CUTOFF_FREQ_YMAX_MSB 15
#define PROP_FM_HIGHCUT_RSSI_CUTOFF_FREQ_YMAX_MASK 0xFF00
#define PROP_FM_HIGHCUT_RSSI_CUTOFF_FREQ_YMAX_value() (uint8_t)(((PROP_FM_HIGHCUT_RSSI_CUTOFF_FREQ_value()) & 0xFF00)>>8)
#define PROP_FM_HIGHCUT_RSSI_CUTOFF_FREQ_YMAX_RANGE_MIN (0)
#define PROP_FM_HIGHCUT_RSSI_CUTOFF_FREQ_YMAX_RANGE_MAX (200)
#define PROP_FM_HIGHCUT_RSSI_CUTOFF_FREQ_YMIN_LSB 0
#define PROP_FM_HIGHCUT_RSSI_CUTOFF_FREQ_YMIN_MSB 7
#define PROP_FM_HIGHCUT_RSSI_CUTOFF_FREQ_YMIN_MASK 0xFF
#define PROP_FM_HIGHCUT_RSSI_CUTOFF_FREQ_YMIN_value() (uint8_t)(((PROP_FM_HIGHCUT_RSSI_CUTOFF_FREQ_value()) & 0xFF)>>0)
#define PROP_FM_HIGHCUT_RSSI_CUTOFF_FREQ_YMIN_RANGE_MIN (0)
#define PROP_FM_HIGHCUT_RSSI_CUTOFF_FREQ_YMIN_RANGE_MAX (200)
#define PROP_FM_HIGHCUT_RSSI_CUTOFF_FREQ_DEFAULT 0xC828

#define PROP_FM_HIGHCUT_RSSI_ATTACK_TIME_MASK 0xFFFF
#define PROP_FM_HIGHCUT_RSSI_ATTACK_TIME_INDEX 0x02
#define PROP_FM_HIGHCUT_RSSI_ATTACK_TIME_GROUP 0x36
#define PROP_FM_HIGHCUT_RSSI_ATTACK_TIME_value() (sys_prop_ReturnProperty(PROP_FM_HIGHCUT_RSSI_ATTACK_TIME_GROUP, PROP_FM_HIGHCUT_RSSI_ATTACK_TIME_INDEX))
#define PROP_FM_HIGHCUT_RSSI_ATTACK_TIME_ATTACK_LSB 0
#define PROP_FM_HIGHCUT_RSSI_ATTACK_TIME_ATTACK_MSB 15
#define PROP_FM_HIGHCUT_RSSI_ATTACK_TIME_ATTACK_MASK 0xFFFF
#define PROP_FM_HIGHCUT_RSSI_ATTACK_TIME_ATTACK_value() (uint16_t)(((PROP_FM_HIGHCUT_RSSI_ATTACK_TIME_value()) & 0xFFFF)>>0)
#define PROP_FM_HIGHCUT_RSSI_ATTACK_TIME_ATTACK_RANGE_MIN (1)
#define PROP_FM_HIGHCUT_RSSI_ATTACK_TIME_ATTACK_RANGE_MAX (65535)
#define PROP_FM_HIGHCUT_RSSI_ATTACK_TIME_DEFAULT 16

#define PROP_FM_HIGHCUT_RSSI_RELEASE_TIME_MASK 0xFFFF
#define PROP_FM_HIGHCUT_RSSI_RELEASE_TIME_INDEX 0x03
#define PROP_FM_HIGHCUT_RSSI_RELEASE_TIME_GROUP 0x36
#define PROP_FM_HIGHCUT_RSSI_RELEASE_TIME_value() (sys_prop_ReturnProperty(PROP_FM_HIGHCUT_RSSI_RELEASE_TIME_GROUP, PROP_FM_HIGHCUT_RSSI_RELEASE_TIME_INDEX))
#define PROP_FM_HIGHCUT_RSSI_RELEASE_TIME_RELEASE_LSB 0
#define PROP_FM_HIGHCUT_RSSI_RELEASE_TIME_RELEASE_MSB 15
#define PROP_FM_HIGHCUT_RSSI_RELEASE_TIME_RELEASE_MASK 0xFFFF
#define PROP_FM_HIGHCUT_RSSI_RELEASE_TIME_RELEASE_value() (uint16_t)(((PROP_FM_HIGHCUT_RSSI_RELEASE_TIME_value()) & 0xFFFF)>>0)
#define PROP_FM_HIGHCUT_RSSI_RELEASE_TIME_RELEASE_RANGE_MIN (1)
#define PROP_FM_HIGHCUT_RSSI_RELEASE_TIME_RELEASE_RANGE_MAX (65535)
#define PROP_FM_HIGHCUT_RSSI_RELEASE_TIME_DEFAULT 4000

#define PROP_FM_HIGHCUT_SNR_LIMITS_MASK 0xFFFF
#define PROP_FM_HIGHCUT_SNR_LIMITS_INDEX 0x04
#define PROP_FM_HIGHCUT_SNR_LIMITS_GROUP 0x36
#define PROP_FM_HIGHCUT_SNR_LIMITS_value() (sys_prop_ReturnProperty(PROP_FM_HIGHCUT_SNR_LIMITS_GROUP, PROP_FM_HIGHCUT_SNR_LIMITS_INDEX))
#define PROP_FM_HIGHCUT_SNR_LIMITS_XMAX_LSB 8
#define PROP_FM_HIGHCUT_SNR_LIMITS_XMAX_MSB 15
#define PROP_FM_HIGHCUT_SNR_LIMITS_XMAX_MASK 0xFF00
#define PROP_FM_HIGHCUT_SNR_LIMITS_XMAX_value() (int8_t)(((PROP_FM_HIGHCUT_SNR_LIMITS_value()) & 0xFF00)>>8)
#define PROP_FM_HIGHCUT_SNR_LIMITS_XMAX_RANGE_MIN (-20)
#define PROP_FM_HIGHCUT_SNR_LIMITS_XMAX_RANGE_MAX (64)
#define PROP_FM_HIGHCUT_SNR_LIMITS_XMIN_LSB 0
#define PROP_FM_HIGHCUT_SNR_LIMITS_XMIN_MSB 7
#define PROP_FM_HIGHCUT_SNR_LIMITS_XMIN_MASK 0xFF
#define PROP_FM_HIGHCUT_SNR_LIMITS_XMIN_value() (int8_t)(((PROP_FM_HIGHCUT_SNR_LIMITS_value()) & 0xFF)>>0)
#define PROP_FM_HIGHCUT_SNR_LIMITS_XMIN_RANGE_MIN (-20)
#define PROP_FM_HIGHCUT_SNR_LIMITS_XMIN_RANGE_MAX (64)
#define PROP_FM_HIGHCUT_SNR_LIMITS_DEFAULT 0x0903

#define PROP_FM_HIGHCUT_SNR_CUTOFF_FREQ_MASK 0xFFFF
#define PROP_FM_HIGHCUT_SNR_CUTOFF_FREQ_INDEX 0x05
#define PROP_FM_HIGHCUT_SNR_CUTOFF_FREQ_GROUP 0x36
#define PROP_FM_HIGHCUT_SNR_CUTOFF_FREQ_value() (sys_prop_ReturnProperty(PROP_FM_HIGHCUT_SNR_CUTOFF_FREQ_GROUP, PROP_FM_HIGHCUT_SNR_CUTOFF_FREQ_INDEX))
#define PROP_FM_HIGHCUT_SNR_CUTOFF_FREQ_YMAX_LSB 8
#define PROP_FM_HIGHCUT_SNR_CUTOFF_FREQ_YMAX_MSB 15
#define PROP_FM_HIGHCUT_SNR_CUTOFF_FREQ_YMAX_MASK 0xFF00
#define PROP_FM_HIGHCUT_SNR_CUTOFF_FREQ_YMAX_value() (uint8_t)(((PROP_FM_HIGHCUT_SNR_CUTOFF_FREQ_value()) & 0xFF00)>>8)
#define PROP_FM_HIGHCUT_SNR_CUTOFF_FREQ_YMAX_RANGE_MIN (0)
#define PROP_FM_HIGHCUT_SNR_CUTOFF_FREQ_YMAX_RANGE_MAX (200)
#define PROP_FM_HIGHCUT_SNR_CUTOFF_FREQ_YMIN_LSB 0
#define PROP_FM_HIGHCUT_SNR_CUTOFF_FREQ_YMIN_MSB 7
#define PROP_FM_HIGHCUT_SNR_CUTOFF_FREQ_YMIN_MASK 0xFF
#define PROP_FM_HIGHCUT_SNR_CUTOFF_FREQ_YMIN_value() (uint8_t)(((PROP_FM_HIGHCUT_SNR_CUTOFF_FREQ_value()) & 0xFF)>>0)
#define PROP_FM_HIGHCUT_SNR_CUTOFF_FREQ_YMIN_RANGE_MIN (0)
#define PROP_FM_HIGHCUT_SNR_CUTOFF_FREQ_YMIN_RANGE_MAX (200)
#define PROP_FM_HIGHCUT_SNR_CUTOFF_FREQ_DEFAULT 0xc828

#define PROP_FM_HIGHCUT_SNR_ATTACK_TIME_MASK 0xFFFF
#define PROP_FM_HIGHCUT_SNR_ATTACK_TIME_INDEX 0x06
#define PROP_FM_HIGHCUT_SNR_ATTACK_TIME_GROUP 0x36
#define PROP_FM_HIGHCUT_SNR_ATTACK_TIME_value() (sys_prop_ReturnProperty(PROP_FM_HIGHCUT_SNR_ATTACK_TIME_GROUP, PROP_FM_HIGHCUT_SNR_ATTACK_TIME_INDEX))
#define PROP_FM_HIGHCUT_SNR_ATTACK_TIME_ATTACK_LSB 0
#define PROP_FM_HIGHCUT_SNR_ATTACK_TIME_ATTACK_MSB 15
#define PROP_FM_HIGHCUT_SNR_ATTACK_TIME_ATTACK_MASK 0xFFFF
#define PROP_FM_HIGHCUT_SNR_ATTACK_TIME_ATTACK_value() (uint16_t)(((PROP_FM_HIGHCUT_SNR_ATTACK_TIME_value()) & 0xFFFF)>>0)
#define PROP_FM_HIGHCUT_SNR_ATTACK_TIME_ATTACK_RANGE_MIN (1)
#define PROP_FM_HIGHCUT_SNR_ATTACK_TIME_ATTACK_RANGE_MAX (65535)
#define PROP_FM_HIGHCUT_SNR_ATTACK_TIME_DEFAULT 16

#define PROP_FM_HIGHCUT_SNR_RELEASE_TIME_MASK 0xFFFF
#define PROP_FM_HIGHCUT_SNR_RELEASE_TIME_INDEX 0x07
#define PROP_FM_HIGHCUT_SNR_RELEASE_TIME_GROUP 0x36
#define PROP_FM_HIGHCUT_SNR_RELEASE_TIME_value() (sys_prop_ReturnProperty(PROP_FM_HIGHCUT_SNR_RELEASE_TIME_GROUP, PROP_FM_HIGHCUT_SNR_RELEASE_TIME_INDEX))
#define PROP_FM_HIGHCUT_SNR_RELEASE_TIME_RELEASE_LSB 0
#define PROP_FM_HIGHCUT_SNR_RELEASE_TIME_RELEASE_MSB 15
#define PROP_FM_HIGHCUT_SNR_RELEASE_TIME_RELEASE_MASK 0xFFFF
#define PROP_FM_HIGHCUT_SNR_RELEASE_TIME_RELEASE_value() (uint16_t)(((PROP_FM_HIGHCUT_SNR_RELEASE_TIME_value()) & 0xFFFF)>>0)
#define PROP_FM_HIGHCUT_SNR_RELEASE_TIME_RELEASE_RANGE_MIN (1)
#define PROP_FM_HIGHCUT_SNR_RELEASE_TIME_RELEASE_RANGE_MAX (65535)
#define PROP_FM_HIGHCUT_SNR_RELEASE_TIME_DEFAULT 4000

#define PROP_FM_HIGHCUT_MULTIPATH_LIMITS_MASK 0xFFFF
#define PROP_FM_HIGHCUT_MULTIPATH_LIMITS_INDEX 0x08
#define PROP_FM_HIGHCUT_MULTIPATH_LIMITS_GROUP 0x36
#define PROP_FM_HIGHCUT_MULTIPATH_LIMITS_value() (sys_prop_ReturnProperty(PROP_FM_HIGHCUT_MULTIPATH_LIMITS_GROUP, PROP_FM_HIGHCUT_MULTIPATH_LIMITS_INDEX))
#define PROP_FM_HIGHCUT_MULTIPATH_LIMITS_XMAX_LSB 8
#define PROP_FM_HIGHCUT_MULTIPATH_LIMITS_XMAX_MSB 15
#define PROP_FM_HIGHCUT_MULTIPATH_LIMITS_XMAX_MASK 0xFF00
#define PROP_FM_HIGHCUT_MULTIPATH_LIMITS_XMAX_value() (uint8_t)(((PROP_FM_HIGHCUT_MULTIPATH_LIMITS_value()) & 0xFF00)>>8)
#define PROP_FM_HIGHCUT_MULTIPATH_LIMITS_XMAX_RANGE_MIN (0)
#define PROP_FM_HIGHCUT_MULTIPATH_LIMITS_XMAX_RANGE_MAX (255)
#define PROP_FM_HIGHCUT_MULTIPATH_LIMITS_XMIN_LSB 0
#define PROP_FM_HIGHCUT_MULTIPATH_LIMITS_XMIN_MSB 7
#define PROP_FM_HIGHCUT_MULTIPATH_LIMITS_XMIN_MASK 0xFF
#define PROP_FM_HIGHCUT_MULTIPATH_LIMITS_XMIN_value() (uint8_t)(((PROP_FM_HIGHCUT_MULTIPATH_LIMITS_value()) & 0xFF)>>0)
#define PROP_FM_HIGHCUT_MULTIPATH_LIMITS_XMIN_RANGE_MIN (0)
#define PROP_FM_HIGHCUT_MULTIPATH_LIMITS_XMIN_RANGE_MAX (255)
#define PROP_FM_HIGHCUT_MULTIPATH_LIMITS_DEFAULT 0x2D3C

#define PROP_FM_HIGHCUT_MULTIPATH_CUTOFF_FREQ_MASK 0xFFFF
#define PROP_FM_HIGHCUT_MULTIPATH_CUTOFF_FREQ_INDEX 0x09
#define PROP_FM_HIGHCUT_MULTIPATH_CUTOFF_FREQ_GROUP 0x36
#define PROP_FM_HIGHCUT_MULTIPATH_CUTOFF_FREQ_value() (sys_prop_ReturnProperty(PROP_FM_HIGHCUT_MULTIPATH_CUTOFF_FREQ_GROUP, PROP_FM_HIGHCUT_MULTIPATH_CUTOFF_FREQ_INDEX))
#define PROP_FM_HIGHCUT_MULTIPATH_CUTOFF_FREQ_YMAX_LSB 8
#define PROP_FM_HIGHCUT_MULTIPATH_CUTOFF_FREQ_YMAX_MSB 15
#define PROP_FM_HIGHCUT_MULTIPATH_CUTOFF_FREQ_YMAX_MASK 0xFF00
#define PROP_FM_HIGHCUT_MULTIPATH_CUTOFF_FREQ_YMAX_value() (uint8_t)(((PROP_FM_HIGHCUT_MULTIPATH_CUTOFF_FREQ_value()) & 0xFF00)>>8)
#define PROP_FM_HIGHCUT_MULTIPATH_CUTOFF_FREQ_YMAX_RANGE_MIN (0)
#define PROP_FM_HIGHCUT_MULTIPATH_CUTOFF_FREQ_YMAX_RANGE_MAX (200)
#define PROP_FM_HIGHCUT_MULTIPATH_CUTOFF_FREQ_YMIN_LSB 0
#define PROP_FM_HIGHCUT_MULTIPATH_CUTOFF_FREQ_YMIN_MSB 7
#define PROP_FM_HIGHCUT_MULTIPATH_CUTOFF_FREQ_YMIN_MASK 0xFF
#define PROP_FM_HIGHCUT_MULTIPATH_CUTOFF_FREQ_YMIN_value() (uint8_t)(((PROP_FM_HIGHCUT_MULTIPATH_CUTOFF_FREQ_value()) & 0xFF)>>0)
#define PROP_FM_HIGHCUT_MULTIPATH_CUTOFF_FREQ_YMIN_RANGE_MIN (0)
#define PROP_FM_HIGHCUT_MULTIPATH_CUTOFF_FREQ_YMIN_RANGE_MAX (200)
#define PROP_FM_HIGHCUT_MULTIPATH_CUTOFF_FREQ_DEFAULT 0xc828

#define PROP_FM_HIGHCUT_MULTIPATH_ATTACK_TIME_MASK 0xFFFF
#define PROP_FM_HIGHCUT_MULTIPATH_ATTACK_TIME_INDEX 0x0A
#define PROP_FM_HIGHCUT_MULTIPATH_ATTACK_TIME_GROUP 0x36
#define PROP_FM_HIGHCUT_MULTIPATH_ATTACK_TIME_value() (sys_prop_ReturnProperty(PROP_FM_HIGHCUT_MULTIPATH_ATTACK_TIME_GROUP, PROP_FM_HIGHCUT_MULTIPATH_ATTACK_TIME_INDEX))
#define PROP_FM_HIGHCUT_MULTIPATH_ATTACK_TIME_ATTACK_LSB 0
#define PROP_FM_HIGHCUT_MULTIPATH_ATTACK_TIME_ATTACK_MSB 15
#define PROP_FM_HIGHCUT_MULTIPATH_ATTACK_TIME_ATTACK_MASK 0xFFFF
#define PROP_FM_HIGHCUT_MULTIPATH_ATTACK_TIME_ATTACK_value() (uint16_t)(((PROP_FM_HIGHCUT_MULTIPATH_ATTACK_TIME_value()) & 0xFFFF)>>0)
#define PROP_FM_HIGHCUT_MULTIPATH_ATTACK_TIME_ATTACK_RANGE_MIN (1)
#define PROP_FM_HIGHCUT_MULTIPATH_ATTACK_TIME_ATTACK_RANGE_MAX (65535)
#define PROP_FM_HIGHCUT_MULTIPATH_ATTACK_TIME_DEFAULT 16

#define PROP_FM_HIGHCUT_MULTIPATH_RELEASE_TIME_MASK 0xFFFF
#define PROP_FM_HIGHCUT_MULTIPATH_RELEASE_TIME_INDEX 0x0B
#define PROP_FM_HIGHCUT_MULTIPATH_RELEASE_TIME_GROUP 0x36
#define PROP_FM_HIGHCUT_MULTIPATH_RELEASE_TIME_value() (sys_prop_ReturnProperty(PROP_FM_HIGHCUT_MULTIPATH_RELEASE_TIME_GROUP, PROP_FM_HIGHCUT_MULTIPATH_RELEASE_TIME_INDEX))
#define PROP_FM_HIGHCUT_MULTIPATH_RELEASE_TIME_RELEASE_LSB 0
#define PROP_FM_HIGHCUT_MULTIPATH_RELEASE_TIME_RELEASE_MSB 15
#define PROP_FM_HIGHCUT_MULTIPATH_RELEASE_TIME_RELEASE_MASK 0xFFFF
#define PROP_FM_HIGHCUT_MULTIPATH_RELEASE_TIME_RELEASE_value() (uint16_t)(((PROP_FM_HIGHCUT_MULTIPATH_RELEASE_TIME_value()) & 0xFFFF)>>0)
#define PROP_FM_HIGHCUT_MULTIPATH_RELEASE_TIME_RELEASE_RANGE_MIN (1)
#define PROP_FM_HIGHCUT_MULTIPATH_RELEASE_TIME_RELEASE_RANGE_MAX (65535)
#define PROP_FM_HIGHCUT_MULTIPATH_RELEASE_TIME_DEFAULT 4000

#define PROP_FM_BLEND_RSSI_LIMITS_MASK 0xFFFF
#define PROP_FM_BLEND_RSSI_LIMITS_INDEX 0x00
#define PROP_FM_BLEND_RSSI_LIMITS_GROUP 0x37
#define PROP_FM_BLEND_RSSI_LIMITS_value() (sys_prop_ReturnProperty(PROP_FM_BLEND_RSSI_LIMITS_GROUP, PROP_FM_BLEND_RSSI_LIMITS_INDEX))
#define PROP_FM_BLEND_RSSI_LIMITS_XMAX_LSB 8
#define PROP_FM_BLEND_RSSI_LIMITS_XMAX_MSB 15
#define PROP_FM_BLEND_RSSI_LIMITS_XMAX_MASK 0xFF00
#define PROP_FM_BLEND_RSSI_LIMITS_XMAX_value() (int8_t)(((PROP_FM_BLEND_RSSI_LIMITS_value()) & 0xFF00)>>8)
#define PROP_FM_BLEND_RSSI_LIMITS_XMAX_RANGE_MIN (-20)
#define PROP_FM_BLEND_RSSI_LIMITS_XMAX_RANGE_MAX (120)
#define PROP_FM_BLEND_RSSI_LIMITS_XMIN_LSB 0
#define PROP_FM_BLEND_RSSI_LIMITS_XMIN_MSB 7
#define PROP_FM_BLEND_RSSI_LIMITS_XMIN_MASK 0xFF
#define PROP_FM_BLEND_RSSI_LIMITS_XMIN_value() (int8_t)(((PROP_FM_BLEND_RSSI_LIMITS_value()) & 0xFF)>>0)
#define PROP_FM_BLEND_RSSI_LIMITS_XMIN_RANGE_MIN (-20)
#define PROP_FM_BLEND_RSSI_LIMITS_XMIN_RANGE_MAX (120)
#define PROP_FM_BLEND_RSSI_LIMITS_DEFAULT 0x2010

#define PROP_FM_BLEND_RSSI_ATTACK_TIME_MASK 0xFFFF
#define PROP_FM_BLEND_RSSI_ATTACK_TIME_INDEX 0x02
#define PROP_FM_BLEND_RSSI_ATTACK_TIME_GROUP 0x37
#define PROP_FM_BLEND_RSSI_ATTACK_TIME_value() (sys_prop_ReturnProperty(PROP_FM_BLEND_RSSI_ATTACK_TIME_GROUP, PROP_FM_BLEND_RSSI_ATTACK_TIME_INDEX))
#define PROP_FM_BLEND_RSSI_ATTACK_TIME_ATTACK_LSB 0
#define PROP_FM_BLEND_RSSI_ATTACK_TIME_ATTACK_MSB 15
#define PROP_FM_BLEND_RSSI_ATTACK_TIME_ATTACK_MASK 0xFFFF
#define PROP_FM_BLEND_RSSI_ATTACK_TIME_ATTACK_value() (uint16_t)(((PROP_FM_BLEND_RSSI_ATTACK_TIME_value()) & 0xFFFF)>>0)
#define PROP_FM_BLEND_RSSI_ATTACK_TIME_ATTACK_RANGE_MIN (16)
#define PROP_FM_BLEND_RSSI_ATTACK_TIME_ATTACK_RANGE_MAX (65535)
#define PROP_FM_BLEND_RSSI_ATTACK_TIME_DEFAULT 16

#define PROP_FM_BLEND_RSSI_RELEASE_TIME_MASK 0xFFFF
#define PROP_FM_BLEND_RSSI_RELEASE_TIME_INDEX 0x03
#define PROP_FM_BLEND_RSSI_RELEASE_TIME_GROUP 0x37
#define PROP_FM_BLEND_RSSI_RELEASE_TIME_value() (sys_prop_ReturnProperty(PROP_FM_BLEND_RSSI_RELEASE_TIME_GROUP, PROP_FM_BLEND_RSSI_RELEASE_TIME_INDEX))
#define PROP_FM_BLEND_RSSI_RELEASE_TIME_RELEASE_LSB 0
#define PROP_FM_BLEND_RSSI_RELEASE_TIME_RELEASE_MSB 15
#define PROP_FM_BLEND_RSSI_RELEASE_TIME_RELEASE_MASK 0xFFFF
#define PROP_FM_BLEND_RSSI_RELEASE_TIME_RELEASE_value() (uint16_t)(((PROP_FM_BLEND_RSSI_RELEASE_TIME_value()) & 0xFFFF)>>0)
#define PROP_FM_BLEND_RSSI_RELEASE_TIME_RELEASE_RANGE_MIN (16)
#define PROP_FM_BLEND_RSSI_RELEASE_TIME_RELEASE_RANGE_MAX (65535)
#define PROP_FM_BLEND_RSSI_RELEASE_TIME_DEFAULT 4000

#define PROP_FM_BLEND_SNR_LIMITS_MASK 0xFFFF
#define PROP_FM_BLEND_SNR_LIMITS_INDEX 0x04
#define PROP_FM_BLEND_SNR_LIMITS_GROUP 0x37
#define PROP_FM_BLEND_SNR_LIMITS_value() (sys_prop_ReturnProperty(PROP_FM_BLEND_SNR_LIMITS_GROUP, PROP_FM_BLEND_SNR_LIMITS_INDEX))
#define PROP_FM_BLEND_SNR_LIMITS_XMAX_LSB 8
#define PROP_FM_BLEND_SNR_LIMITS_XMAX_MSB 15
#define PROP_FM_BLEND_SNR_LIMITS_XMAX_MASK 0xFF00
#define PROP_FM_BLEND_SNR_LIMITS_XMAX_value() (int8_t)(((PROP_FM_BLEND_SNR_LIMITS_value()) & 0xFF00)>>8)
#define PROP_FM_BLEND_SNR_LIMITS_XMAX_RANGE_MIN (-20)
#define PROP_FM_BLEND_SNR_LIMITS_XMAX_RANGE_MAX (64)
#define PROP_FM_BLEND_SNR_LIMITS_XMIN_LSB 0
#define PROP_FM_BLEND_SNR_LIMITS_XMIN_MSB 7
#define PROP_FM_BLEND_SNR_LIMITS_XMIN_MASK 0xFF
#define PROP_FM_BLEND_SNR_LIMITS_XMIN_value() (int8_t)(((PROP_FM_BLEND_SNR_LIMITS_value()) & 0xFF)>>0)
#define PROP_FM_BLEND_SNR_LIMITS_XMIN_RANGE_MIN (-20)
#define PROP_FM_BLEND_SNR_LIMITS_XMIN_RANGE_MAX (64)
#define PROP_FM_BLEND_SNR_LIMITS_DEFAULT 0x180F

#define PROP_FM_BLEND_SNR_ATTACK_TIME_MASK 0xFFFF
#define PROP_FM_BLEND_SNR_ATTACK_TIME_INDEX 0x06
#define PROP_FM_BLEND_SNR_ATTACK_TIME_GROUP 0x37
#define PROP_FM_BLEND_SNR_ATTACK_TIME_value() (sys_prop_ReturnProperty(PROP_FM_BLEND_SNR_ATTACK_TIME_GROUP, PROP_FM_BLEND_SNR_ATTACK_TIME_INDEX))
#define PROP_FM_BLEND_SNR_ATTACK_TIME_ATTACK_LSB 0
#define PROP_FM_BLEND_SNR_ATTACK_TIME_ATTACK_MSB 15
#define PROP_FM_BLEND_SNR_ATTACK_TIME_ATTACK_MASK 0xFFFF
#define PROP_FM_BLEND_SNR_ATTACK_TIME_ATTACK_value() (uint16_t)(((PROP_FM_BLEND_SNR_ATTACK_TIME_value()) & 0xFFFF)>>0)
#define PROP_FM_BLEND_SNR_ATTACK_TIME_ATTACK_RANGE_MIN (16)
#define PROP_FM_BLEND_SNR_ATTACK_TIME_ATTACK_RANGE_MAX (65535)
#define PROP_FM_BLEND_SNR_ATTACK_TIME_DEFAULT 16

#define PROP_FM_BLEND_SNR_RELEASE_TIME_MASK 0xFFFF
#define PROP_FM_BLEND_SNR_RELEASE_TIME_INDEX 0x07
#define PROP_FM_BLEND_SNR_RELEASE_TIME_GROUP 0x37
#define PROP_FM_BLEND_SNR_RELEASE_TIME_value() (sys_prop_ReturnProperty(PROP_FM_BLEND_SNR_RELEASE_TIME_GROUP, PROP_FM_BLEND_SNR_RELEASE_TIME_INDEX))
#define PROP_FM_BLEND_SNR_RELEASE_TIME_RELEASE_LSB 0
#define PROP_FM_BLEND_SNR_RELEASE_TIME_RELEASE_MSB 15
#define PROP_FM_BLEND_SNR_RELEASE_TIME_RELEASE_MASK 0xFFFF
#define PROP_FM_BLEND_SNR_RELEASE_TIME_RELEASE_value() (uint16_t)(((PROP_FM_BLEND_SNR_RELEASE_TIME_value()) & 0xFFFF)>>0)
#define PROP_FM_BLEND_SNR_RELEASE_TIME_RELEASE_RANGE_MIN (16)
#define PROP_FM_BLEND_SNR_RELEASE_TIME_RELEASE_RANGE_MAX (65535)
#define PROP_FM_BLEND_SNR_RELEASE_TIME_DEFAULT 4000

#define PROP_FM_BLEND_MULTIPATH_LIMITS_MASK 0xFFFF
#define PROP_FM_BLEND_MULTIPATH_LIMITS_INDEX 0x08
#define PROP_FM_BLEND_MULTIPATH_LIMITS_GROUP 0x37
#define PROP_FM_BLEND_MULTIPATH_LIMITS_value() (sys_prop_ReturnProperty(PROP_FM_BLEND_MULTIPATH_LIMITS_GROUP, PROP_FM_BLEND_MULTIPATH_LIMITS_INDEX))
#define PROP_FM_BLEND_MULTIPATH_LIMITS_XMAX_LSB 8
#define PROP_FM_BLEND_MULTIPATH_LIMITS_XMAX_MSB 15
#define PROP_FM_BLEND_MULTIPATH_LIMITS_XMAX_MASK 0xFF00
#define PROP_FM_BLEND_MULTIPATH_LIMITS_XMAX_value() (uint8_t)(((PROP_FM_BLEND_MULTIPATH_LIMITS_value()) & 0xFF00)>>8)
#define PROP_FM_BLEND_MULTIPATH_LIMITS_XMAX_RANGE_MIN (0)
#define PROP_FM_BLEND_MULTIPATH_LIMITS_XMAX_RANGE_MAX (255)
#define PROP_FM_BLEND_MULTIPATH_LIMITS_XMIN_LSB 0
#define PROP_FM_BLEND_MULTIPATH_LIMITS_XMIN_MSB 7
#define PROP_FM_BLEND_MULTIPATH_LIMITS_XMIN_MASK 0xFF
#define PROP_FM_BLEND_MULTIPATH_LIMITS_XMIN_value() (uint8_t)(((PROP_FM_BLEND_MULTIPATH_LIMITS_value()) & 0xFF)>>0)
#define PROP_FM_BLEND_MULTIPATH_LIMITS_XMIN_RANGE_MIN (0)
#define PROP_FM_BLEND_MULTIPATH_LIMITS_XMIN_RANGE_MAX (255)
#define PROP_FM_BLEND_MULTIPATH_LIMITS_DEFAULT 0x2D3C

#define PROP_FM_BLEND_MULTIPATH_ATTACK_TIME_MASK 0xFFFF
#define PROP_FM_BLEND_MULTIPATH_ATTACK_TIME_INDEX 0x0A
#define PROP_FM_BLEND_MULTIPATH_ATTACK_TIME_GROUP 0x37
#define PROP_FM_BLEND_MULTIPATH_ATTACK_TIME_value() (sys_prop_ReturnProperty(PROP_FM_BLEND_MULTIPATH_ATTACK_TIME_GROUP, PROP_FM_BLEND_MULTIPATH_ATTACK_TIME_INDEX))
#define PROP_FM_BLEND_MULTIPATH_ATTACK_TIME_ATTACK_LSB 0
#define PROP_FM_BLEND_MULTIPATH_ATTACK_TIME_ATTACK_MSB 15
#define PROP_FM_BLEND_MULTIPATH_ATTACK_TIME_ATTACK_MASK 0xFFFF
#define PROP_FM_BLEND_MULTIPATH_ATTACK_TIME_ATTACK_value() (uint16_t)(((PROP_FM_BLEND_MULTIPATH_ATTACK_TIME_value()) & 0xFFFF)>>0)
#define PROP_FM_BLEND_MULTIPATH_ATTACK_TIME_ATTACK_RANGE_MIN (16)
#define PROP_FM_BLEND_MULTIPATH_ATTACK_TIME_ATTACK_RANGE_MAX (65535)
#define PROP_FM_BLEND_MULTIPATH_ATTACK_TIME_DEFAULT 16

#define PROP_FM_BLEND_MULTIPATH_RELEASE_TIME_MASK 0xFFFF
#define PROP_FM_BLEND_MULTIPATH_RELEASE_TIME_INDEX 0x0B
#define PROP_FM_BLEND_MULTIPATH_RELEASE_TIME_GROUP 0x37
#define PROP_FM_BLEND_MULTIPATH_RELEASE_TIME_value() (sys_prop_ReturnProperty(PROP_FM_BLEND_MULTIPATH_RELEASE_TIME_GROUP, PROP_FM_BLEND_MULTIPATH_RELEASE_TIME_INDEX))
#define PROP_FM_BLEND_MULTIPATH_RELEASE_TIME_RELEASE_LSB 0
#define PROP_FM_BLEND_MULTIPATH_RELEASE_TIME_RELEASE_MSB 15
#define PROP_FM_BLEND_MULTIPATH_RELEASE_TIME_RELEASE_MASK 0xFFFF
#define PROP_FM_BLEND_MULTIPATH_RELEASE_TIME_RELEASE_value() (uint16_t)(((PROP_FM_BLEND_MULTIPATH_RELEASE_TIME_value()) & 0xFFFF)>>0)
#define PROP_FM_BLEND_MULTIPATH_RELEASE_TIME_RELEASE_RANGE_MIN (16)
#define PROP_FM_BLEND_MULTIPATH_RELEASE_TIME_RELEASE_RANGE_MAX (65535)
#define PROP_FM_BLEND_MULTIPATH_RELEASE_TIME_DEFAULT 4000

#define PROP_FM_AUDIO_DE_EMPHASIS_MASK 0xFFFF
#define PROP_FM_AUDIO_DE_EMPHASIS_INDEX 0x00
#define PROP_FM_AUDIO_DE_EMPHASIS_GROUP 0x39
#define PROP_FM_AUDIO_DE_EMPHASIS_value() (sys_prop_ReturnProperty(PROP_FM_AUDIO_DE_EMPHASIS_GROUP, PROP_FM_AUDIO_DE_EMPHASIS_INDEX))
#define PROP_FM_AUDIO_DE_EMPHASIS_DE_EMPH_LSB 0
#define PROP_FM_AUDIO_DE_EMPHASIS_DE_EMPH_MSB 1
#define PROP_FM_AUDIO_DE_EMPHASIS_DE_EMPH_MASK 0x3
#define PROP_FM_AUDIO_DE_EMPHASIS_DE_EMPH_value() (((PROP_FM_AUDIO_DE_EMPHASIS_value()) & 0x3)>>0)
#define PROP_FM_AUDIO_DE_EMPHASIS_DE_EMPH_ENUM_75US 0
#define PROP_FM_AUDIO_DE_EMPHASIS_DE_EMPH_ENUM_50US 1
#define PROP_FM_AUDIO_DE_EMPHASIS_DE_EMPH_ENUM_OFF 2
#define PROP_FM_AUDIO_DE_EMPHASIS_DEFAULT 0

#define PROP_FM_RDS_INTERRUPT_SOURCE_MASK 0xFFFF
#define PROP_FM_RDS_INTERRUPT_SOURCE_INDEX 0x00
#define PROP_FM_RDS_INTERRUPT_SOURCE_GROUP 0x3C
#define PROP_FM_RDS_INTERRUPT_SOURCE_value() (sys_prop_ReturnProperty(PROP_FM_RDS_INTERRUPT_SOURCE_GROUP, PROP_FM_RDS_INTERRUPT_SOURCE_INDEX))
#define PROP_FM_RDS_INTERRUPT_SOURCE_RDSTPPTY_LSB 4
#define PROP_FM_RDS_INTERRUPT_SOURCE_RDSTPPTY_MSB 4
#define PROP_FM_RDS_INTERRUPT_SOURCE_RDSTPPTY_MASK 0x10
#define PROP_FM_RDS_INTERRUPT_SOURCE_RDSTPPTY_BIT 0x10
#define PROP_FM_RDS_INTERRUPT_SOURCE_RDSTPPTY_value() (((PROP_FM_RDS_INTERRUPT_SOURCE_value()) & 0x10)>>4)
#define PROP_FM_RDS_INTERRUPT_SOURCE_RDSTPPTY_ENUM_DISABLED 0
#define PROP_FM_RDS_INTERRUPT_SOURCE_RDSTPPTY_ENUM_ENABLED 1
#define PROP_FM_RDS_INTERRUPT_SOURCE_RDSPI_LSB 3
#define PROP_FM_RDS_INTERRUPT_SOURCE_RDSPI_MSB 3
#define PROP_FM_RDS_INTERRUPT_SOURCE_RDSPI_MASK 0x8
#define PROP_FM_RDS_INTERRUPT_SOURCE_RDSPI_BIT 0x8
#define PROP_FM_RDS_INTERRUPT_SOURCE_RDSPI_value() (((PROP_FM_RDS_INTERRUPT_SOURCE_value()) & 0x8)>>3)
#define PROP_FM_RDS_INTERRUPT_SOURCE_RDSPI_ENUM_DISABLED 0
#define PROP_FM_RDS_INTERRUPT_SOURCE_RDSPI_ENUM_ENABLED 1
#define PROP_FM_RDS_INTERRUPT_SOURCE_RDSSYNC_LSB 1
#define PROP_FM_RDS_INTERRUPT_SOURCE_RDSSYNC_MSB 1
#define PROP_FM_RDS_INTERRUPT_SOURCE_RDSSYNC_MASK 0x2
#define PROP_FM_RDS_INTERRUPT_SOURCE_RDSSYNC_BIT 0x2
#define PROP_FM_RDS_INTERRUPT_SOURCE_RDSSYNC_value() (((PROP_FM_RDS_INTERRUPT_SOURCE_value()) & 0x2)>>1)
#define PROP_FM_RDS_INTERRUPT_SOURCE_RDSSYNC_ENUM_DISABLED 0
#define PROP_FM_RDS_INTERRUPT_SOURCE_RDSSYNC_ENUM_ENABLED 1
#define PROP_FM_RDS_INTERRUPT_SOURCE_RDSRECV_LSB 0
#define PROP_FM_RDS_INTERRUPT_SOURCE_RDSRECV_MSB 0
#define PROP_FM_RDS_INTERRUPT_SOURCE_RDSRECV_MASK 0x1
#define PROP_FM_RDS_INTERRUPT_SOURCE_RDSRECV_BIT 0x1
#define PROP_FM_RDS_INTERRUPT_SOURCE_RDSRECV_value() (((PROP_FM_RDS_INTERRUPT_SOURCE_value()) & 0x1)>>0)
#define PROP_FM_RDS_INTERRUPT_SOURCE_RDSRECV_ENUM_DISABLED 0
#define PROP_FM_RDS_INTERRUPT_SOURCE_RDSRECV_ENUM_ENABLED 1
#define PROP_FM_RDS_INTERRUPT_SOURCE_DEFAULT 0x0000

#define PROP_FM_RDS_INTERRUPT_FIFO_COUNT_MASK 0xFFFF
#define PROP_FM_RDS_INTERRUPT_FIFO_COUNT_INDEX 0x01
#define PROP_FM_RDS_INTERRUPT_FIFO_COUNT_GROUP 0x3C
#define PROP_FM_RDS_INTERRUPT_FIFO_COUNT_value() (sys_prop_ReturnProperty(PROP_FM_RDS_INTERRUPT_FIFO_COUNT_GROUP, PROP_FM_RDS_INTERRUPT_FIFO_COUNT_INDEX))
#define PROP_FM_RDS_INTERRUPT_FIFO_COUNT_DEPTH_LSB 0
#define PROP_FM_RDS_INTERRUPT_FIFO_COUNT_DEPTH_MSB 7
#define PROP_FM_RDS_INTERRUPT_FIFO_COUNT_DEPTH_MASK 0xFF
#define PROP_FM_RDS_INTERRUPT_FIFO_COUNT_DEPTH_value() (uint8_t)(((PROP_FM_RDS_INTERRUPT_FIFO_COUNT_value()) & 0xFF)>>0)
#define PROP_FM_RDS_INTERRUPT_FIFO_COUNT_DEPTH_RANGE_MIN (0)
#define PROP_FM_RDS_INTERRUPT_FIFO_COUNT_DEPTH_RANGE_MAX (25)
#define PROP_FM_RDS_INTERRUPT_FIFO_COUNT_DEFAULT 0x0000

#define PROP_FM_RDS_CONFIG_MASK 0xFFFF
#define PROP_FM_RDS_CONFIG_INDEX 0x02
#define PROP_FM_RDS_CONFIG_GROUP 0x3C
#define PROP_FM_RDS_CONFIG_value() (sys_prop_ReturnProperty(PROP_FM_RDS_CONFIG_GROUP, PROP_FM_RDS_CONFIG_INDEX))
#define PROP_FM_RDS_CONFIG_BLETHB_LSB 6
#define PROP_FM_RDS_CONFIG_BLETHB_MSB 7
#define PROP_FM_RDS_CONFIG_BLETHB_MASK 0xC0
#define PROP_FM_RDS_CONFIG_BLETHB_value() (((PROP_FM_RDS_CONFIG_value()) & 0xC0)>>6)
#define PROP_FM_RDS_CONFIG_BLETHB_ENUM_BLER_NO_ERRORS 0
#define PROP_FM_RDS_CONFIG_BLETHB_ENUM_BLER_1_2_ERRORS 1
#define PROP_FM_RDS_CONFIG_BLETHB_ENUM_BLER_3_5_ERRORS 2
#define PROP_FM_RDS_CONFIG_BLETHB_ENUM_BLER_UNCORRECTABLE 3
#define PROP_FM_RDS_CONFIG_BLETHCD_LSB 4
#define PROP_FM_RDS_CONFIG_BLETHCD_MSB 5
#define PROP_FM_RDS_CONFIG_BLETHCD_MASK 0x30
#define PROP_FM_RDS_CONFIG_BLETHCD_value() (((PROP_FM_RDS_CONFIG_value()) & 0x30)>>4)
#define PROP_FM_RDS_CONFIG_BLETHCD_ENUM_BLER_NO_ERRORS 0
#define PROP_FM_RDS_CONFIG_BLETHCD_ENUM_BLER_1_2_ERRORS 1
#define PROP_FM_RDS_CONFIG_BLETHCD_ENUM_BLER_3_5_ERRORS 2
#define PROP_FM_RDS_CONFIG_BLETHCD_ENUM_BLER_UNCORRECTABLE 3
#define PROP_FM_RDS_CONFIG_RDSEN_LSB 0
#define PROP_FM_RDS_CONFIG_RDSEN_MSB 0
#define PROP_FM_RDS_CONFIG_RDSEN_MASK 0x1
#define PROP_FM_RDS_CONFIG_RDSEN_BIT 0x1
#define PROP_FM_RDS_CONFIG_RDSEN_value() (((PROP_FM_RDS_CONFIG_value()) & 0x1)>>0)
#define PROP_FM_RDS_CONFIG_DEFAULT 0x0000

#define PROP_FM_RDS_CONFIDENCE_MASK 0xFFFF
#define PROP_FM_RDS_CONFIDENCE_INDEX 0x03
#define PROP_FM_RDS_CONFIDENCE_GROUP 0x3C
#define PROP_FM_RDS_CONFIDENCE_value() (sys_prop_ReturnProperty(PROP_FM_RDS_CONFIDENCE_GROUP, PROP_FM_RDS_CONFIDENCE_INDEX))
#define PROP_FM_RDS_CONFIDENCE_CONFIDENCEA_LSB 12
#define PROP_FM_RDS_CONFIDENCE_CONFIDENCEA_MSB 15
#define PROP_FM_RDS_CONFIDENCE_CONFIDENCEA_MASK 0xF000
#define PROP_FM_RDS_CONFIDENCE_CONFIDENCEA_value() (((PROP_FM_RDS_CONFIDENCE_value()) & 0xF000)>>12)
#define PROP_FM_RDS_CONFIDENCE_CONFIDENCEA_RANGE_MIN (1)
#define PROP_FM_RDS_CONFIDENCE_CONFIDENCEA_RANGE_MAX (15)
#define PROP_FM_RDS_CONFIDENCE_CONFIDENCEB_LSB 8
#define PROP_FM_RDS_CONFIDENCE_CONFIDENCEB_MSB 11
#define PROP_FM_RDS_CONFIDENCE_CONFIDENCEB_MASK 0xF00
#define PROP_FM_RDS_CONFIDENCE_CONFIDENCEB_value() (((PROP_FM_RDS_CONFIDENCE_value()) & 0xF00)>>8)
#define PROP_FM_RDS_CONFIDENCE_CONFIDENCEB_RANGE_MIN (1)
#define PROP_FM_RDS_CONFIDENCE_CONFIDENCEB_RANGE_MAX (15)
#define PROP_FM_RDS_CONFIDENCE_CONFIDENCEC_LSB 4
#define PROP_FM_RDS_CONFIDENCE_CONFIDENCEC_MSB 7
#define PROP_FM_RDS_CONFIDENCE_CONFIDENCEC_MASK 0xF0
#define PROP_FM_RDS_CONFIDENCE_CONFIDENCEC_value() (((PROP_FM_RDS_CONFIDENCE_value()) & 0xF0)>>4)
#define PROP_FM_RDS_CONFIDENCE_CONFIDENCEC_RANGE_MIN (1)
#define PROP_FM_RDS_CONFIDENCE_CONFIDENCEC_RANGE_MAX (15)
#define PROP_FM_RDS_CONFIDENCE_CONFIDENCED_LSB 0
#define PROP_FM_RDS_CONFIDENCE_CONFIDENCED_MSB 3
#define PROP_FM_RDS_CONFIDENCE_CONFIDENCED_MASK 0xF
#define PROP_FM_RDS_CONFIDENCE_CONFIDENCED_value() (((PROP_FM_RDS_CONFIDENCE_value()) & 0xF)>>0)
#define PROP_FM_RDS_CONFIDENCE_CONFIDENCED_RANGE_MIN (1)
#define PROP_FM_RDS_CONFIDENCE_CONFIDENCED_RANGE_MAX (15)
#define PROP_FM_RDS_CONFIDENCE_DEFAULT 0x1111

#define PROP_FM_NB_DETECT_THRESHOLD_MASK 0xFFFF
#define PROP_FM_NB_DETECT_THRESHOLD_INDEX 0x00
#define PROP_FM_NB_DETECT_THRESHOLD_GROUP 0x3E
#define PROP_FM_NB_DETECT_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_FM_NB_DETECT_THRESHOLD_GROUP, PROP_FM_NB_DETECT_THRESHOLD_INDEX))
#define PROP_FM_NB_DETECT_THRESHOLD_DETECT_THRESHOLD_LSB 0
#define PROP_FM_NB_DETECT_THRESHOLD_DETECT_THRESHOLD_MSB 15
#define PROP_FM_NB_DETECT_THRESHOLD_DETECT_THRESHOLD_MASK 0xFFFF
#define PROP_FM_NB_DETECT_THRESHOLD_DETECT_THRESHOLD_value() (((PROP_FM_NB_DETECT_THRESHOLD_value()) & 0xFFFF)>>0)
#define PROP_FM_NB_DETECT_THRESHOLD_DETECT_THRESHOLD_RANGE_MIN (0)
#define PROP_FM_NB_DETECT_THRESHOLD_DETECT_THRESHOLD_RANGE_MAX (90)
#define PROP_FM_NB_DETECT_THRESHOLD_DEFAULT 18

#define PROP_FM_NB_INTERVAL_MASK 0xFFFF
#define PROP_FM_NB_INTERVAL_INDEX 0x01
#define PROP_FM_NB_INTERVAL_GROUP 0x3E
#define PROP_FM_NB_INTERVAL_value() (sys_prop_ReturnProperty(PROP_FM_NB_INTERVAL_GROUP, PROP_FM_NB_INTERVAL_INDEX))
#define PROP_FM_NB_INTERVAL_INTERVAL_LSB 0
#define PROP_FM_NB_INTERVAL_INTERVAL_MSB 15
#define PROP_FM_NB_INTERVAL_INTERVAL_MASK 0xFFFF
#define PROP_FM_NB_INTERVAL_INTERVAL_value() (((PROP_FM_NB_INTERVAL_value()) & 0xFFFF)>>0)
#define PROP_FM_NB_INTERVAL_INTERVAL_RANGE_MIN (1)
#define PROP_FM_NB_INTERVAL_INTERVAL_RANGE_MAX (20)
#define PROP_FM_NB_INTERVAL_DEFAULT 4

#define PROP_FM_NB_WEAK_SIGNAL_THRESHOLD_MASK 0xFFFF
#define PROP_FM_NB_WEAK_SIGNAL_THRESHOLD_INDEX 0x05
#define PROP_FM_NB_WEAK_SIGNAL_THRESHOLD_GROUP 0x3E
#define PROP_FM_NB_WEAK_SIGNAL_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_FM_NB_WEAK_SIGNAL_THRESHOLD_GROUP, PROP_FM_NB_WEAK_SIGNAL_THRESHOLD_INDEX))
#define PROP_FM_NB_WEAK_SIGNAL_THRESHOLD_WEAK_SIGNAL_THRESHOLD_LSB 0
#define PROP_FM_NB_WEAK_SIGNAL_THRESHOLD_WEAK_SIGNAL_THRESHOLD_MSB 15
#define PROP_FM_NB_WEAK_SIGNAL_THRESHOLD_WEAK_SIGNAL_THRESHOLD_MASK 0xFFFF
#define PROP_FM_NB_WEAK_SIGNAL_THRESHOLD_WEAK_SIGNAL_THRESHOLD_value() (((PROP_FM_NB_WEAK_SIGNAL_THRESHOLD_value()) & 0xFFFF)>>0)
#define PROP_FM_NB_WEAK_SIGNAL_THRESHOLD_DEFAULT 0x3500

#define PROP_FM_NB_STRONG_SIGNAL_SHUTOFF_MASK 0xFFFF
#define PROP_FM_NB_STRONG_SIGNAL_SHUTOFF_INDEX 0x06
#define PROP_FM_NB_STRONG_SIGNAL_SHUTOFF_GROUP 0x3E
#define PROP_FM_NB_STRONG_SIGNAL_SHUTOFF_value() (sys_prop_ReturnProperty(PROP_FM_NB_STRONG_SIGNAL_SHUTOFF_GROUP, PROP_FM_NB_STRONG_SIGNAL_SHUTOFF_INDEX))
#define PROP_FM_NB_STRONG_SIGNAL_SHUTOFF_RSSI_THRESH_LSB 0
#define PROP_FM_NB_STRONG_SIGNAL_SHUTOFF_RSSI_THRESH_MSB 6
#define PROP_FM_NB_STRONG_SIGNAL_SHUTOFF_RSSI_THRESH_MASK 0x7F
#define PROP_FM_NB_STRONG_SIGNAL_SHUTOFF_RSSI_THRESH_value() (((PROP_FM_NB_STRONG_SIGNAL_SHUTOFF_value()) & 0x7F)>>0)
#define PROP_FM_NB_STRONG_SIGNAL_SHUTOFF_RSSI_THRESH_RANGE_MIN (0)
#define PROP_FM_NB_STRONG_SIGNAL_SHUTOFF_RSSI_THRESH_RANGE_MAX (127)
#define PROP_FM_NB_STRONG_SIGNAL_SHUTOFF_DEFAULT 50

#define PROP_FM_NB_MODE_CONTROL_MASK 0xFFFF
#define PROP_FM_NB_MODE_CONTROL_INDEX 0x09
#define PROP_FM_NB_MODE_CONTROL_GROUP 0x3E
#define PROP_FM_NB_MODE_CONTROL_value() (sys_prop_ReturnProperty(PROP_FM_NB_MODE_CONTROL_GROUP, PROP_FM_NB_MODE_CONTROL_INDEX))
#define PROP_FM_NB_MODE_CONTROL_RSSI_NB_LSB 0
#define PROP_FM_NB_MODE_CONTROL_RSSI_NB_MSB 0
#define PROP_FM_NB_MODE_CONTROL_RSSI_NB_MASK 0x1
#define PROP_FM_NB_MODE_CONTROL_RSSI_NB_BIT 0x1
#define PROP_FM_NB_MODE_CONTROL_RSSI_NB_value() (((PROP_FM_NB_MODE_CONTROL_value()) & 0x1)>>0)
#define PROP_FM_NB_MODE_CONTROL_RSSI_NB_ENUM_USE_SNR 0
#define PROP_FM_NB_MODE_CONTROL_RSSI_NB_ENUM_USE_RSSI 1
#define PROP_FM_NB_MODE_CONTROL_DEFAULT 0

#define PROP_FM_NB_WEAK_BLANK_INTERVAL_MASK 0xFFFF
#define PROP_FM_NB_WEAK_BLANK_INTERVAL_INDEX 0x0A
#define PROP_FM_NB_WEAK_BLANK_INTERVAL_GROUP 0x3E
#define PROP_FM_NB_WEAK_BLANK_INTERVAL_value() (sys_prop_ReturnProperty(PROP_FM_NB_WEAK_BLANK_INTERVAL_GROUP, PROP_FM_NB_WEAK_BLANK_INTERVAL_INDEX))
#define PROP_FM_NB_WEAK_BLANK_INTERVAL_WEAK_BLANK_INTERVAL_LSB 0
#define PROP_FM_NB_WEAK_BLANK_INTERVAL_WEAK_BLANK_INTERVAL_MSB 15
#define PROP_FM_NB_WEAK_BLANK_INTERVAL_WEAK_BLANK_INTERVAL_MASK 0xFFFF
#define PROP_FM_NB_WEAK_BLANK_INTERVAL_WEAK_BLANK_INTERVAL_value() (((PROP_FM_NB_WEAK_BLANK_INTERVAL_value()) & 0xFFFF)>>0)
#define PROP_FM_NB_WEAK_BLANK_INTERVAL_WEAK_BLANK_INTERVAL_RANGE_MIN (1)
#define PROP_FM_NB_WEAK_BLANK_INTERVAL_WEAK_BLANK_INTERVAL_RANGE_MAX (20)
#define PROP_FM_NB_WEAK_BLANK_INTERVAL_DEFAULT 5

#define PROP_FM_NB_STRONG_WEAK_SWITCH_MASK 0xFFFF
#define PROP_FM_NB_STRONG_WEAK_SWITCH_INDEX 0x0B
#define PROP_FM_NB_STRONG_WEAK_SWITCH_GROUP 0x3E
#define PROP_FM_NB_STRONG_WEAK_SWITCH_value() (sys_prop_ReturnProperty(PROP_FM_NB_STRONG_WEAK_SWITCH_GROUP, PROP_FM_NB_STRONG_WEAK_SWITCH_INDEX))
#define PROP_FM_NB_STRONG_WEAK_SWITCH_HIGH_LSB 8
#define PROP_FM_NB_STRONG_WEAK_SWITCH_HIGH_MSB 14
#define PROP_FM_NB_STRONG_WEAK_SWITCH_HIGH_MASK 0x7F00
#define PROP_FM_NB_STRONG_WEAK_SWITCH_HIGH_value() (((PROP_FM_NB_STRONG_WEAK_SWITCH_value()) & 0x7F00)>>8)
#define PROP_FM_NB_STRONG_WEAK_SWITCH_HIGH_RANGE_MIN (-127)
#define PROP_FM_NB_STRONG_WEAK_SWITCH_HIGH_RANGE_MAX (127)
#define PROP_FM_NB_STRONG_WEAK_SWITCH_LOW_LSB 0
#define PROP_FM_NB_STRONG_WEAK_SWITCH_LOW_MSB 6
#define PROP_FM_NB_STRONG_WEAK_SWITCH_LOW_MASK 0x7F
#define PROP_FM_NB_STRONG_WEAK_SWITCH_LOW_value() (((PROP_FM_NB_STRONG_WEAK_SWITCH_value()) & 0x7F)>>0)
#define PROP_FM_NB_STRONG_WEAK_SWITCH_LOW_RANGE_MIN (-127)
#define PROP_FM_NB_STRONG_WEAK_SWITCH_LOW_RANGE_MAX (127)
#define PROP_FM_NB_STRONG_WEAK_SWITCH_DEFAULT 0x0b09

#define PROP_FM_CHBW_RSSI_MIN_MAX_MASK 0xFFFF
#define PROP_FM_CHBW_RSSI_MIN_MAX_INDEX 0x00
#define PROP_FM_CHBW_RSSI_MIN_MAX_GROUP 0x3F
#define PROP_FM_CHBW_RSSI_MIN_MAX_value() (sys_prop_ReturnProperty(PROP_FM_CHBW_RSSI_MIN_MAX_GROUP, PROP_FM_CHBW_RSSI_MIN_MAX_INDEX))
#define PROP_FM_CHBW_RSSI_MIN_MAX_MAX_LSB 8
#define PROP_FM_CHBW_RSSI_MIN_MAX_MAX_MSB 15
#define PROP_FM_CHBW_RSSI_MIN_MAX_MAX_MASK 0xFF00
#define PROP_FM_CHBW_RSSI_MIN_MAX_MAX_value() (((PROP_FM_CHBW_RSSI_MIN_MAX_value()) & 0xFF00)>>8)
#define PROP_FM_CHBW_RSSI_MIN_MAX_MAX_RANGE_MIN (1)
#define PROP_FM_CHBW_RSSI_MIN_MAX_MAX_RANGE_MAX (150)
#define PROP_FM_CHBW_RSSI_MIN_MAX_MIN_LSB 0
#define PROP_FM_CHBW_RSSI_MIN_MAX_MIN_MSB 7
#define PROP_FM_CHBW_RSSI_MIN_MAX_MIN_MASK 0xFF
#define PROP_FM_CHBW_RSSI_MIN_MAX_MIN_value() (((PROP_FM_CHBW_RSSI_MIN_MAX_value()) & 0xFF)>>0)
#define PROP_FM_CHBW_RSSI_MIN_MAX_MIN_RANGE_MIN (1)
#define PROP_FM_CHBW_RSSI_MIN_MAX_MIN_RANGE_MAX (150)
#define PROP_FM_CHBW_RSSI_MIN_MAX_DEFAULT 0x7837

#define PROP_FM_CHBW_RSSI_HIGH_THRESHOLD_MASK 0xFFFF
#define PROP_FM_CHBW_RSSI_HIGH_THRESHOLD_INDEX 0x01
#define PROP_FM_CHBW_RSSI_HIGH_THRESHOLD_GROUP 0x3F
#define PROP_FM_CHBW_RSSI_HIGH_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_FM_CHBW_RSSI_HIGH_THRESHOLD_GROUP, PROP_FM_CHBW_RSSI_HIGH_THRESHOLD_INDEX))
#define PROP_FM_CHBW_RSSI_HIGH_THRESHOLD_RSSIMAX_LSB 0
#define PROP_FM_CHBW_RSSI_HIGH_THRESHOLD_RSSIMAX_MSB 7
#define PROP_FM_CHBW_RSSI_HIGH_THRESHOLD_RSSIMAX_MASK 0xFF
#define PROP_FM_CHBW_RSSI_HIGH_THRESHOLD_RSSIMAX_value() (int8_t)(((PROP_FM_CHBW_RSSI_HIGH_THRESHOLD_value()) & 0xFF)>>0)
#define PROP_FM_CHBW_RSSI_HIGH_THRESHOLD_RSSIMAX_RANGE_MIN (-128)
#define PROP_FM_CHBW_RSSI_HIGH_THRESHOLD_RSSIMAX_RANGE_MAX (127)
#define PROP_FM_CHBW_RSSI_HIGH_THRESHOLD_DEFAULT 12

#define PROP_FM_CHBW_RSSI_LOW_THRESHOLD_MASK 0xFFFF
#define PROP_FM_CHBW_RSSI_LOW_THRESHOLD_INDEX 0x02
#define PROP_FM_CHBW_RSSI_LOW_THRESHOLD_GROUP 0x3F
#define PROP_FM_CHBW_RSSI_LOW_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_FM_CHBW_RSSI_LOW_THRESHOLD_GROUP, PROP_FM_CHBW_RSSI_LOW_THRESHOLD_INDEX))
#define PROP_FM_CHBW_RSSI_LOW_THRESHOLD_RSSIMIN_LSB 0
#define PROP_FM_CHBW_RSSI_LOW_THRESHOLD_RSSIMIN_MSB 7
#define PROP_FM_CHBW_RSSI_LOW_THRESHOLD_RSSIMIN_MASK 0xFF
#define PROP_FM_CHBW_RSSI_LOW_THRESHOLD_RSSIMIN_value() (int8_t)(((PROP_FM_CHBW_RSSI_LOW_THRESHOLD_value()) & 0xFF)>>0)
#define PROP_FM_CHBW_RSSI_LOW_THRESHOLD_RSSIMIN_RANGE_MIN (-128)
#define PROP_FM_CHBW_RSSI_LOW_THRESHOLD_RSSIMIN_RANGE_MAX (127)
#define PROP_FM_CHBW_RSSI_LOW_THRESHOLD_DEFAULT -4

#define PROP_FM_CHBW_RSSI_WIDENING_TIME_MASK 0xFFFF
#define PROP_FM_CHBW_RSSI_WIDENING_TIME_INDEX 0x03
#define PROP_FM_CHBW_RSSI_WIDENING_TIME_GROUP 0x3F
#define PROP_FM_CHBW_RSSI_WIDENING_TIME_value() (sys_prop_ReturnProperty(PROP_FM_CHBW_RSSI_WIDENING_TIME_GROUP, PROP_FM_CHBW_RSSI_WIDENING_TIME_INDEX))
#define PROP_FM_CHBW_RSSI_WIDENING_TIME_WIDENING_TIME_LSB 0
#define PROP_FM_CHBW_RSSI_WIDENING_TIME_WIDENING_TIME_MSB 15
#define PROP_FM_CHBW_RSSI_WIDENING_TIME_WIDENING_TIME_MASK 0xFFFF
#define PROP_FM_CHBW_RSSI_WIDENING_TIME_WIDENING_TIME_value() (((PROP_FM_CHBW_RSSI_WIDENING_TIME_value()) & 0xFFFF)>>0)
#define PROP_FM_CHBW_RSSI_WIDENING_TIME_WIDENING_TIME_RANGE_MIN (1)
#define PROP_FM_CHBW_RSSI_WIDENING_TIME_WIDENING_TIME_RANGE_MAX (32767)
#define PROP_FM_CHBW_RSSI_WIDENING_TIME_DEFAULT 16

#define PROP_FM_CHBW_RSSI_NARROWING_TIME_MASK 0xFFFF
#define PROP_FM_CHBW_RSSI_NARROWING_TIME_INDEX 0x04
#define PROP_FM_CHBW_RSSI_NARROWING_TIME_GROUP 0x3F
#define PROP_FM_CHBW_RSSI_NARROWING_TIME_value() (sys_prop_ReturnProperty(PROP_FM_CHBW_RSSI_NARROWING_TIME_GROUP, PROP_FM_CHBW_RSSI_NARROWING_TIME_INDEX))
#define PROP_FM_CHBW_RSSI_NARROWING_TIME_NARROWING_TIME_LSB 0
#define PROP_FM_CHBW_RSSI_NARROWING_TIME_NARROWING_TIME_MSB 15
#define PROP_FM_CHBW_RSSI_NARROWING_TIME_NARROWING_TIME_MASK 0xFFFF
#define PROP_FM_CHBW_RSSI_NARROWING_TIME_NARROWING_TIME_value() (((PROP_FM_CHBW_RSSI_NARROWING_TIME_value()) & 0xFFFF)>>0)
#define PROP_FM_CHBW_RSSI_NARROWING_TIME_NARROWING_TIME_RANGE_MIN (1)
#define PROP_FM_CHBW_RSSI_NARROWING_TIME_NARROWING_TIME_RANGE_MAX (32767)
#define PROP_FM_CHBW_RSSI_NARROWING_TIME_DEFAULT 2048

#define PROP_FM_CHBW_ASSI100_MIN_MAX_MASK 0xFFFF
#define PROP_FM_CHBW_ASSI100_MIN_MAX_INDEX 0x05
#define PROP_FM_CHBW_ASSI100_MIN_MAX_GROUP 0x3F
#define PROP_FM_CHBW_ASSI100_MIN_MAX_value() (sys_prop_ReturnProperty(PROP_FM_CHBW_ASSI100_MIN_MAX_GROUP, PROP_FM_CHBW_ASSI100_MIN_MAX_INDEX))
#define PROP_FM_CHBW_ASSI100_MIN_MAX_MAX_LSB 8
#define PROP_FM_CHBW_ASSI100_MIN_MAX_MAX_MSB 15
#define PROP_FM_CHBW_ASSI100_MIN_MAX_MAX_MASK 0xFF00
#define PROP_FM_CHBW_ASSI100_MIN_MAX_MAX_value() (((PROP_FM_CHBW_ASSI100_MIN_MAX_value()) & 0xFF00)>>8)
#define PROP_FM_CHBW_ASSI100_MIN_MAX_MAX_RANGE_MIN (1)
#define PROP_FM_CHBW_ASSI100_MIN_MAX_MAX_RANGE_MAX (150)
#define PROP_FM_CHBW_ASSI100_MIN_MAX_MIN_LSB 0
#define PROP_FM_CHBW_ASSI100_MIN_MAX_MIN_MSB 7
#define PROP_FM_CHBW_ASSI100_MIN_MAX_MIN_MASK 0xFF
#define PROP_FM_CHBW_ASSI100_MIN_MAX_MIN_value() (((PROP_FM_CHBW_ASSI100_MIN_MAX_value()) & 0xFF)>>0)
#define PROP_FM_CHBW_ASSI100_MIN_MAX_MIN_RANGE_MIN (1)
#define PROP_FM_CHBW_ASSI100_MIN_MAX_MIN_RANGE_MAX (150)
#define PROP_FM_CHBW_ASSI100_MIN_MAX_DEFAULT 0x7850

#define PROP_FM_CHBW_ASSI100_LOW_THRESHOLD_MASK 0xFFFF
#define PROP_FM_CHBW_ASSI100_LOW_THRESHOLD_INDEX 0x06
#define PROP_FM_CHBW_ASSI100_LOW_THRESHOLD_GROUP 0x3F
#define PROP_FM_CHBW_ASSI100_LOW_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_FM_CHBW_ASSI100_LOW_THRESHOLD_GROUP, PROP_FM_CHBW_ASSI100_LOW_THRESHOLD_INDEX))
#define PROP_FM_CHBW_ASSI100_LOW_THRESHOLD_ASSI100MIN_LSB 0
#define PROP_FM_CHBW_ASSI100_LOW_THRESHOLD_ASSI100MIN_MSB 7
#define PROP_FM_CHBW_ASSI100_LOW_THRESHOLD_ASSI100MIN_MASK 0xFF
#define PROP_FM_CHBW_ASSI100_LOW_THRESHOLD_ASSI100MIN_value() (int8_t)(((PROP_FM_CHBW_ASSI100_LOW_THRESHOLD_value()) & 0xFF)>>0)
#define PROP_FM_CHBW_ASSI100_LOW_THRESHOLD_ASSI100MIN_RANGE_MIN (-128)
#define PROP_FM_CHBW_ASSI100_LOW_THRESHOLD_ASSI100MIN_RANGE_MAX (127)
#define PROP_FM_CHBW_ASSI100_LOW_THRESHOLD_DEFAULT 7

#define PROP_FM_CHBW_ASSI100_HIGH_THRESHOLD_MASK 0xFFFF
#define PROP_FM_CHBW_ASSI100_HIGH_THRESHOLD_INDEX 0x07
#define PROP_FM_CHBW_ASSI100_HIGH_THRESHOLD_GROUP 0x3F
#define PROP_FM_CHBW_ASSI100_HIGH_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_FM_CHBW_ASSI100_HIGH_THRESHOLD_GROUP, PROP_FM_CHBW_ASSI100_HIGH_THRESHOLD_INDEX))
#define PROP_FM_CHBW_ASSI100_HIGH_THRESHOLD_ASSI100MAX_LSB 0
#define PROP_FM_CHBW_ASSI100_HIGH_THRESHOLD_ASSI100MAX_MSB 7
#define PROP_FM_CHBW_ASSI100_HIGH_THRESHOLD_ASSI100MAX_MASK 0xFF
#define PROP_FM_CHBW_ASSI100_HIGH_THRESHOLD_ASSI100MAX_value() (int8_t)(((PROP_FM_CHBW_ASSI100_HIGH_THRESHOLD_value()) & 0xFF)>>0)
#define PROP_FM_CHBW_ASSI100_HIGH_THRESHOLD_ASSI100MAX_RANGE_MIN (-128)
#define PROP_FM_CHBW_ASSI100_HIGH_THRESHOLD_ASSI100MAX_RANGE_MAX (127)
#define PROP_FM_CHBW_ASSI100_HIGH_THRESHOLD_DEFAULT 20

#define PROP_FM_CHBW_ASSI100_WIDENING_TIME_MASK 0xFFFF
#define PROP_FM_CHBW_ASSI100_WIDENING_TIME_INDEX 0x08
#define PROP_FM_CHBW_ASSI100_WIDENING_TIME_GROUP 0x3F
#define PROP_FM_CHBW_ASSI100_WIDENING_TIME_value() (sys_prop_ReturnProperty(PROP_FM_CHBW_ASSI100_WIDENING_TIME_GROUP, PROP_FM_CHBW_ASSI100_WIDENING_TIME_INDEX))
#define PROP_FM_CHBW_ASSI100_WIDENING_TIME_WIDENING_TIME_LSB 0
#define PROP_FM_CHBW_ASSI100_WIDENING_TIME_WIDENING_TIME_MSB 15
#define PROP_FM_CHBW_ASSI100_WIDENING_TIME_WIDENING_TIME_MASK 0xFFFF
#define PROP_FM_CHBW_ASSI100_WIDENING_TIME_WIDENING_TIME_value() (((PROP_FM_CHBW_ASSI100_WIDENING_TIME_value()) & 0xFFFF)>>0)
#define PROP_FM_CHBW_ASSI100_WIDENING_TIME_WIDENING_TIME_RANGE_MIN (1)
#define PROP_FM_CHBW_ASSI100_WIDENING_TIME_WIDENING_TIME_RANGE_MAX (32767)
#define PROP_FM_CHBW_ASSI100_WIDENING_TIME_DEFAULT 3200

#define PROP_FM_CHBW_ASSI100_NARROWING_TIME_MASK 0xFFFF
#define PROP_FM_CHBW_ASSI100_NARROWING_TIME_INDEX 0x09
#define PROP_FM_CHBW_ASSI100_NARROWING_TIME_GROUP 0x3F
#define PROP_FM_CHBW_ASSI100_NARROWING_TIME_value() (sys_prop_ReturnProperty(PROP_FM_CHBW_ASSI100_NARROWING_TIME_GROUP, PROP_FM_CHBW_ASSI100_NARROWING_TIME_INDEX))
#define PROP_FM_CHBW_ASSI100_NARROWING_TIME_NARROWING_TIME_LSB 0
#define PROP_FM_CHBW_ASSI100_NARROWING_TIME_NARROWING_TIME_MSB 15
#define PROP_FM_CHBW_ASSI100_NARROWING_TIME_NARROWING_TIME_MASK 0xFFFF
#define PROP_FM_CHBW_ASSI100_NARROWING_TIME_NARROWING_TIME_value() (((PROP_FM_CHBW_ASSI100_NARROWING_TIME_value()) & 0xFFFF)>>0)
#define PROP_FM_CHBW_ASSI100_NARROWING_TIME_NARROWING_TIME_RANGE_MIN (1)
#define PROP_FM_CHBW_ASSI100_NARROWING_TIME_NARROWING_TIME_RANGE_MAX (32767)
#define PROP_FM_CHBW_ASSI100_NARROWING_TIME_DEFAULT 320

#define PROP_FM_CHBW_WEAKSIG_THR_MASK 0xFFFF
#define PROP_FM_CHBW_WEAKSIG_THR_INDEX 0x0A
#define PROP_FM_CHBW_WEAKSIG_THR_GROUP 0x3F
#define PROP_FM_CHBW_WEAKSIG_THR_value() (sys_prop_ReturnProperty(PROP_FM_CHBW_WEAKSIG_THR_GROUP, PROP_FM_CHBW_WEAKSIG_THR_INDEX))
#define PROP_FM_CHBW_WEAKSIG_THR_HIGH_LSB 8
#define PROP_FM_CHBW_WEAKSIG_THR_HIGH_MSB 15
#define PROP_FM_CHBW_WEAKSIG_THR_HIGH_MASK 0xFF00
#define PROP_FM_CHBW_WEAKSIG_THR_HIGH_value() (int8_t)(((PROP_FM_CHBW_WEAKSIG_THR_value()) & 0xFF00)>>8)
#define PROP_FM_CHBW_WEAKSIG_THR_HIGH_RANGE_MIN (-128)
#define PROP_FM_CHBW_WEAKSIG_THR_HIGH_RANGE_MAX (127)
#define PROP_FM_CHBW_WEAKSIG_THR_LOW_LSB 0
#define PROP_FM_CHBW_WEAKSIG_THR_LOW_MSB 7
#define PROP_FM_CHBW_WEAKSIG_THR_LOW_MASK 0xFF
#define PROP_FM_CHBW_WEAKSIG_THR_LOW_value() (int8_t)(((PROP_FM_CHBW_WEAKSIG_THR_value()) & 0xFF)>>0)
#define PROP_FM_CHBW_WEAKSIG_THR_LOW_RANGE_MIN (-128)
#define PROP_FM_CHBW_WEAKSIG_THR_LOW_RANGE_MAX (127)
#define PROP_FM_CHBW_WEAKSIG_THR_DEFAULT 0x100d

#define PROP_FM_CHBW_ASSI100_CONTROL_MASK 0xFFFF
#define PROP_FM_CHBW_ASSI100_CONTROL_INDEX 0x0B
#define PROP_FM_CHBW_ASSI100_CONTROL_GROUP 0x3F
#define PROP_FM_CHBW_ASSI100_CONTROL_value() (sys_prop_ReturnProperty(PROP_FM_CHBW_ASSI100_CONTROL_GROUP, PROP_FM_CHBW_ASSI100_CONTROL_INDEX))
#define PROP_FM_CHBW_ASSI100_CONTROL_FREQOFF_CHBW_MODE_LSB 8
#define PROP_FM_CHBW_ASSI100_CONTROL_FREQOFF_CHBW_MODE_MSB 9
#define PROP_FM_CHBW_ASSI100_CONTROL_FREQOFF_CHBW_MODE_MASK 0x300
#define PROP_FM_CHBW_ASSI100_CONTROL_FREQOFF_CHBW_MODE_value() (((PROP_FM_CHBW_ASSI100_CONTROL_value()) & 0x300)>>8)
#define PROP_FM_CHBW_ASSI100_CONTROL_FREQOFF_CHBW_MODE_ENUM_200KHZ_BLK_DEV 0
#define PROP_FM_CHBW_ASSI100_CONTROL_FREQOFF_CHBW_MODE_ENUM_POST_CF_FREQOFF 1
#define PROP_FM_CHBW_ASSI100_CONTROL_FREQOFF_CHBW_MODE_ENUM_AVG 2
#define PROP_FM_CHBW_ASSI100_CONTROL_MODE_LSB 0
#define PROP_FM_CHBW_ASSI100_CONTROL_MODE_MSB 0
#define PROP_FM_CHBW_ASSI100_CONTROL_MODE_MASK 0x1
#define PROP_FM_CHBW_ASSI100_CONTROL_MODE_BIT 0x1
#define PROP_FM_CHBW_ASSI100_CONTROL_MODE_value() (((PROP_FM_CHBW_ASSI100_CONTROL_value()) & 0x1)>>0)
#define PROP_FM_CHBW_ASSI100_CONTROL_MODE_ENUM_AUTO 0
#define PROP_FM_CHBW_ASSI100_CONTROL_MODE_ENUM_MAX 1
#define PROP_FM_CHBW_ASSI100_CONTROL_DEFAULT 0x0200

#define PROP_FM_CHBW_STRONGDEV_MIN_MAX_MASK 0xFFFF
#define PROP_FM_CHBW_STRONGDEV_MIN_MAX_INDEX 0x0C
#define PROP_FM_CHBW_STRONGDEV_MIN_MAX_GROUP 0x3F
#define PROP_FM_CHBW_STRONGDEV_MIN_MAX_value() (sys_prop_ReturnProperty(PROP_FM_CHBW_STRONGDEV_MIN_MAX_GROUP, PROP_FM_CHBW_STRONGDEV_MIN_MAX_INDEX))
#define PROP_FM_CHBW_STRONGDEV_MIN_MAX_MAX_LSB 8
#define PROP_FM_CHBW_STRONGDEV_MIN_MAX_MAX_MSB 15
#define PROP_FM_CHBW_STRONGDEV_MIN_MAX_MAX_MASK 0xFF00
#define PROP_FM_CHBW_STRONGDEV_MIN_MAX_MAX_value() (((PROP_FM_CHBW_STRONGDEV_MIN_MAX_value()) & 0xFF00)>>8)
#define PROP_FM_CHBW_STRONGDEV_MIN_MAX_MAX_RANGE_MIN (1)
#define PROP_FM_CHBW_STRONGDEV_MIN_MAX_MAX_RANGE_MAX (150)
#define PROP_FM_CHBW_STRONGDEV_MIN_MAX_MIN_LSB 0
#define PROP_FM_CHBW_STRONGDEV_MIN_MAX_MIN_MSB 7
#define PROP_FM_CHBW_STRONGDEV_MIN_MAX_MIN_MASK 0xFF
#define PROP_FM_CHBW_STRONGDEV_MIN_MAX_MIN_value() (((PROP_FM_CHBW_STRONGDEV_MIN_MAX_value()) & 0xFF)>>0)
#define PROP_FM_CHBW_STRONGDEV_MIN_MAX_MIN_RANGE_MIN (1)
#define PROP_FM_CHBW_STRONGDEV_MIN_MAX_MIN_RANGE_MAX (150)
#define PROP_FM_CHBW_STRONGDEV_MIN_MAX_DEFAULT 0x7864

#define PROP_FM_CHBW_STRONGDEV_LOW_THRESHOLD_MASK 0xFFFF
#define PROP_FM_CHBW_STRONGDEV_LOW_THRESHOLD_INDEX 0x0D
#define PROP_FM_CHBW_STRONGDEV_LOW_THRESHOLD_GROUP 0x3F
#define PROP_FM_CHBW_STRONGDEV_LOW_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_FM_CHBW_STRONGDEV_LOW_THRESHOLD_GROUP, PROP_FM_CHBW_STRONGDEV_LOW_THRESHOLD_INDEX))
#define PROP_FM_CHBW_STRONGDEV_LOW_THRESHOLD_STRONGDEVMIN_LSB 0
#define PROP_FM_CHBW_STRONGDEV_LOW_THRESHOLD_STRONGDEVMIN_MSB 15
#define PROP_FM_CHBW_STRONGDEV_LOW_THRESHOLD_STRONGDEVMIN_MASK 0xFFFF
#define PROP_FM_CHBW_STRONGDEV_LOW_THRESHOLD_STRONGDEVMIN_value() (((PROP_FM_CHBW_STRONGDEV_LOW_THRESHOLD_value()) & 0xFFFF)>>0)
#define PROP_FM_CHBW_STRONGDEV_LOW_THRESHOLD_STRONGDEVMIN_RANGE_MIN (0)
#define PROP_FM_CHBW_STRONGDEV_LOW_THRESHOLD_STRONGDEVMIN_RANGE_MAX (127)
#define PROP_FM_CHBW_STRONGDEV_LOW_THRESHOLD_DEFAULT 8

#define PROP_FM_CHBW_STRONGDEV_HIGH_THRESHOLD_MASK 0xFFFF
#define PROP_FM_CHBW_STRONGDEV_HIGH_THRESHOLD_INDEX 0x0E
#define PROP_FM_CHBW_STRONGDEV_HIGH_THRESHOLD_GROUP 0x3F
#define PROP_FM_CHBW_STRONGDEV_HIGH_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_FM_CHBW_STRONGDEV_HIGH_THRESHOLD_GROUP, PROP_FM_CHBW_STRONGDEV_HIGH_THRESHOLD_INDEX))
#define PROP_FM_CHBW_STRONGDEV_HIGH_THRESHOLD_STRONGDEVMAX_LSB 0
#define PROP_FM_CHBW_STRONGDEV_HIGH_THRESHOLD_STRONGDEVMAX_MSB 15
#define PROP_FM_CHBW_STRONGDEV_HIGH_THRESHOLD_STRONGDEVMAX_MASK 0xFFFF
#define PROP_FM_CHBW_STRONGDEV_HIGH_THRESHOLD_STRONGDEVMAX_value() (((PROP_FM_CHBW_STRONGDEV_HIGH_THRESHOLD_value()) & 0xFFFF)>>0)
#define PROP_FM_CHBW_STRONGDEV_HIGH_THRESHOLD_STRONGDEVMAX_RANGE_MIN (0)
#define PROP_FM_CHBW_STRONGDEV_HIGH_THRESHOLD_STRONGDEVMAX_RANGE_MAX (127)
#define PROP_FM_CHBW_STRONGDEV_HIGH_THRESHOLD_DEFAULT 19

#define PROP_FM_CHBW_STRONGDEV_WIDENING_TIME_MASK 0xFFFF
#define PROP_FM_CHBW_STRONGDEV_WIDENING_TIME_INDEX 0x0F
#define PROP_FM_CHBW_STRONGDEV_WIDENING_TIME_GROUP 0x3F
#define PROP_FM_CHBW_STRONGDEV_WIDENING_TIME_value() (sys_prop_ReturnProperty(PROP_FM_CHBW_STRONGDEV_WIDENING_TIME_GROUP, PROP_FM_CHBW_STRONGDEV_WIDENING_TIME_INDEX))
#define PROP_FM_CHBW_STRONGDEV_WIDENING_TIME_WIDENING_TIME_LSB 0
#define PROP_FM_CHBW_STRONGDEV_WIDENING_TIME_WIDENING_TIME_MSB 15
#define PROP_FM_CHBW_STRONGDEV_WIDENING_TIME_WIDENING_TIME_MASK 0xFFFF
#define PROP_FM_CHBW_STRONGDEV_WIDENING_TIME_WIDENING_TIME_value() (((PROP_FM_CHBW_STRONGDEV_WIDENING_TIME_value()) & 0xFFFF)>>0)
#define PROP_FM_CHBW_STRONGDEV_WIDENING_TIME_WIDENING_TIME_RANGE_MIN (1)
#define PROP_FM_CHBW_STRONGDEV_WIDENING_TIME_WIDENING_TIME_RANGE_MAX (32767)
#define PROP_FM_CHBW_STRONGDEV_WIDENING_TIME_DEFAULT 4096

#define PROP_FM_CHBW_STRONGDEV_NARROWING_TIME_MASK 0xFFFF
#define PROP_FM_CHBW_STRONGDEV_NARROWING_TIME_INDEX 0x10
#define PROP_FM_CHBW_STRONGDEV_NARROWING_TIME_GROUP 0x3F
#define PROP_FM_CHBW_STRONGDEV_NARROWING_TIME_value() (sys_prop_ReturnProperty(PROP_FM_CHBW_STRONGDEV_NARROWING_TIME_GROUP, PROP_FM_CHBW_STRONGDEV_NARROWING_TIME_INDEX))
#define PROP_FM_CHBW_STRONGDEV_NARROWING_TIME_NARROWING_TIME_LSB 0
#define PROP_FM_CHBW_STRONGDEV_NARROWING_TIME_NARROWING_TIME_MSB 15
#define PROP_FM_CHBW_STRONGDEV_NARROWING_TIME_NARROWING_TIME_MASK 0xFFFF
#define PROP_FM_CHBW_STRONGDEV_NARROWING_TIME_NARROWING_TIME_value() (((PROP_FM_CHBW_STRONGDEV_NARROWING_TIME_value()) & 0xFFFF)>>0)
#define PROP_FM_CHBW_STRONGDEV_NARROWING_TIME_NARROWING_TIME_RANGE_MIN (1)
#define PROP_FM_CHBW_STRONGDEV_NARROWING_TIME_NARROWING_TIME_RANGE_MAX (32767)
#define PROP_FM_CHBW_STRONGDEV_NARROWING_TIME_DEFAULT 512

#define PROP_AM_SEEK_BAND_BOTTOM_MASK 0xFFFF
#define PROP_AM_SEEK_BAND_BOTTOM_INDEX 0x00
#define PROP_AM_SEEK_BAND_BOTTOM_GROUP 0x41
#define PROP_AM_SEEK_BAND_BOTTOM_value() (sys_prop_ReturnProperty(PROP_AM_SEEK_BAND_BOTTOM_GROUP, PROP_AM_SEEK_BAND_BOTTOM_INDEX))
#define PROP_AM_SEEK_BAND_BOTTOM_AMSKFREQL_LSB 0
#define PROP_AM_SEEK_BAND_BOTTOM_AMSKFREQL_MSB 15
#define PROP_AM_SEEK_BAND_BOTTOM_AMSKFREQL_MASK 0xFFFF
#define PROP_AM_SEEK_BAND_BOTTOM_AMSKFREQL_value() (uint16_t)(((PROP_AM_SEEK_BAND_BOTTOM_value()) & 0xFFFF)>>0)
#define PROP_AM_SEEK_BAND_BOTTOM_AMSKFREQL_RANGE_MIN (520)
#define PROP_AM_SEEK_BAND_BOTTOM_AMSKFREQL_RANGE_MAX (1710)
#define PROP_AM_SEEK_BAND_BOTTOM_DEFAULT 520

#define PROP_AM_SEEK_BAND_TOP_MASK 0xFFFF
#define PROP_AM_SEEK_BAND_TOP_INDEX 0x01
#define PROP_AM_SEEK_BAND_TOP_GROUP 0x41
#define PROP_AM_SEEK_BAND_TOP_value() (sys_prop_ReturnProperty(PROP_AM_SEEK_BAND_TOP_GROUP, PROP_AM_SEEK_BAND_TOP_INDEX))
#define PROP_AM_SEEK_BAND_TOP_AMSKFREQH_LSB 0
#define PROP_AM_SEEK_BAND_TOP_AMSKFREQH_MSB 15
#define PROP_AM_SEEK_BAND_TOP_AMSKFREQH_MASK 0xFFFF
#define PROP_AM_SEEK_BAND_TOP_AMSKFREQH_value() (uint16_t)(((PROP_AM_SEEK_BAND_TOP_value()) & 0xFFFF)>>0)
#define PROP_AM_SEEK_BAND_TOP_AMSKFREQH_RANGE_MIN (520)
#define PROP_AM_SEEK_BAND_TOP_AMSKFREQH_RANGE_MAX (1710)
#define PROP_AM_SEEK_BAND_TOP_DEFAULT 1710

#define PROP_AM_SEEK_FREQUENCY_SPACING_MASK 0xFFFF
#define PROP_AM_SEEK_FREQUENCY_SPACING_INDEX 0x02
#define PROP_AM_SEEK_FREQUENCY_SPACING_GROUP 0x41
#define PROP_AM_SEEK_FREQUENCY_SPACING_value() (sys_prop_ReturnProperty(PROP_AM_SEEK_FREQUENCY_SPACING_GROUP, PROP_AM_SEEK_FREQUENCY_SPACING_INDEX))
#define PROP_AM_SEEK_FREQUENCY_SPACING_AMSKSPACE_LSB 0
#define PROP_AM_SEEK_FREQUENCY_SPACING_AMSKSPACE_MSB 4
#define PROP_AM_SEEK_FREQUENCY_SPACING_AMSKSPACE_MASK 0x1F
#define PROP_AM_SEEK_FREQUENCY_SPACING_AMSKSPACE_value() (((PROP_AM_SEEK_FREQUENCY_SPACING_value()) & 0x1F)>>0)
#define PROP_AM_SEEK_FREQUENCY_SPACING_AMSKSPACE_RANGE_MIN (1)
#define PROP_AM_SEEK_FREQUENCY_SPACING_AMSKSPACE_RANGE_MAX (31)
#define PROP_AM_SEEK_FREQUENCY_SPACING_DEFAULT 10

#define PROP_AM_VALID_MAX_TUNE_ERROR_MASK 0xFFFF
#define PROP_AM_VALID_MAX_TUNE_ERROR_INDEX 0x00
#define PROP_AM_VALID_MAX_TUNE_ERROR_GROUP 0x42
#define PROP_AM_VALID_MAX_TUNE_ERROR_value() (sys_prop_ReturnProperty(PROP_AM_VALID_MAX_TUNE_ERROR_GROUP, PROP_AM_VALID_MAX_TUNE_ERROR_INDEX))
#define PROP_AM_VALID_MAX_TUNE_ERROR_AMMAXTUNEERR_LSB 0
#define PROP_AM_VALID_MAX_TUNE_ERROR_AMMAXTUNEERR_MSB 7
#define PROP_AM_VALID_MAX_TUNE_ERROR_AMMAXTUNEERR_MASK 0xFF
#define PROP_AM_VALID_MAX_TUNE_ERROR_AMMAXTUNEERR_value() (uint8_t)(((PROP_AM_VALID_MAX_TUNE_ERROR_value()) & 0xFF)>>0)
#define PROP_AM_VALID_MAX_TUNE_ERROR_AMMAXTUNEERR_RANGE_MIN (0)
#define PROP_AM_VALID_MAX_TUNE_ERROR_AMMAXTUNEERR_RANGE_MAX (126)
#define PROP_AM_VALID_MAX_TUNE_ERROR_DEFAULT 75

#define PROP_AM_VALID_RSSI_TIME_MASK 0xFFFF
#define PROP_AM_VALID_RSSI_TIME_INDEX 0x01
#define PROP_AM_VALID_RSSI_TIME_GROUP 0x42
#define PROP_AM_VALID_RSSI_TIME_value() (sys_prop_ReturnProperty(PROP_AM_VALID_RSSI_TIME_GROUP, PROP_AM_VALID_RSSI_TIME_INDEX))
#define PROP_AM_VALID_RSSI_TIME_SSIVALTIME_LSB 0
#define PROP_AM_VALID_RSSI_TIME_SSIVALTIME_MSB 5
#define PROP_AM_VALID_RSSI_TIME_SSIVALTIME_MASK 0x3F
#define PROP_AM_VALID_RSSI_TIME_SSIVALTIME_value() (((PROP_AM_VALID_RSSI_TIME_value()) & 0x3F)>>0)
#define PROP_AM_VALID_RSSI_TIME_SSIVALTIME_RANGE_MIN (0)
#define PROP_AM_VALID_RSSI_TIME_SSIVALTIME_RANGE_MAX (63)
#define PROP_AM_VALID_RSSI_TIME_DEFAULT 8

#define PROP_AM_VALID_RSSI_THRESHOLD_MASK 0xFFFF
#define PROP_AM_VALID_RSSI_THRESHOLD_INDEX 0x02
#define PROP_AM_VALID_RSSI_THRESHOLD_GROUP 0x42
#define PROP_AM_VALID_RSSI_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_AM_VALID_RSSI_THRESHOLD_GROUP, PROP_AM_VALID_RSSI_THRESHOLD_INDEX))
#define PROP_AM_VALID_RSSI_THRESHOLD_AMVALRSSI_LSB 0
#define PROP_AM_VALID_RSSI_THRESHOLD_AMVALRSSI_MSB 7
#define PROP_AM_VALID_RSSI_THRESHOLD_AMVALRSSI_MASK 0xFF
#define PROP_AM_VALID_RSSI_THRESHOLD_AMVALRSSI_value() (int8_t)(((PROP_AM_VALID_RSSI_THRESHOLD_value()) & 0xFF)>>0)
#define PROP_AM_VALID_RSSI_THRESHOLD_AMVALRSSI_RANGE_MIN (-128)
#define PROP_AM_VALID_RSSI_THRESHOLD_AMVALRSSI_RANGE_MAX (127)
#define PROP_AM_VALID_RSSI_THRESHOLD_DEFAULT 35

#define PROP_AM_VALID_SNR_TIME_MASK 0xFFFF
#define PROP_AM_VALID_SNR_TIME_INDEX 0x03
#define PROP_AM_VALID_SNR_TIME_GROUP 0x42
#define PROP_AM_VALID_SNR_TIME_value() (sys_prop_ReturnProperty(PROP_AM_VALID_SNR_TIME_GROUP, PROP_AM_VALID_SNR_TIME_INDEX))
#define PROP_AM_VALID_SNR_TIME_SNRVALTIME_LSB 0
#define PROP_AM_VALID_SNR_TIME_SNRVALTIME_MSB 5
#define PROP_AM_VALID_SNR_TIME_SNRVALTIME_MASK 0x3F
#define PROP_AM_VALID_SNR_TIME_SNRVALTIME_value() (((PROP_AM_VALID_SNR_TIME_value()) & 0x3F)>>0)
#define PROP_AM_VALID_SNR_TIME_SNRVALTIME_RANGE_MIN (17)
#define PROP_AM_VALID_SNR_TIME_SNRVALTIME_RANGE_MAX (63)
#define PROP_AM_VALID_SNR_TIME_DEFAULT 40

#define PROP_AM_VALID_SNR_THRESHOLD_MASK 0xFFFF
#define PROP_AM_VALID_SNR_THRESHOLD_INDEX 0x04
#define PROP_AM_VALID_SNR_THRESHOLD_GROUP 0x42
#define PROP_AM_VALID_SNR_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_AM_VALID_SNR_THRESHOLD_GROUP, PROP_AM_VALID_SNR_THRESHOLD_INDEX))
#define PROP_AM_VALID_SNR_THRESHOLD_AMVALSNR_LSB 0
#define PROP_AM_VALID_SNR_THRESHOLD_AMVALSNR_MSB 7
#define PROP_AM_VALID_SNR_THRESHOLD_AMVALSNR_MASK 0xFF
#define PROP_AM_VALID_SNR_THRESHOLD_AMVALSNR_value() (int8_t)(((PROP_AM_VALID_SNR_THRESHOLD_value()) & 0xFF)>>0)
#define PROP_AM_VALID_SNR_THRESHOLD_AMVALSNR_RANGE_MIN (-128)
#define PROP_AM_VALID_SNR_THRESHOLD_AMVALSNR_RANGE_MAX (127)
#define PROP_AM_VALID_SNR_THRESHOLD_DEFAULT 4

#define PROP_AM_VALID_HDLEVEL_THRESHOLD_MASK 0xFFFF
#define PROP_AM_VALID_HDLEVEL_THRESHOLD_INDEX 0x05
#define PROP_AM_VALID_HDLEVEL_THRESHOLD_GROUP 0x42
#define PROP_AM_VALID_HDLEVEL_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_AM_VALID_HDLEVEL_THRESHOLD_GROUP, PROP_AM_VALID_HDLEVEL_THRESHOLD_INDEX))
#define PROP_AM_VALID_HDLEVEL_THRESHOLD_AMVALHDLEVEL_LSB 0
#define PROP_AM_VALID_HDLEVEL_THRESHOLD_AMVALHDLEVEL_MSB 7
#define PROP_AM_VALID_HDLEVEL_THRESHOLD_AMVALHDLEVEL_MASK 0xFF
#define PROP_AM_VALID_HDLEVEL_THRESHOLD_AMVALHDLEVEL_value() (int8_t)(((PROP_AM_VALID_HDLEVEL_THRESHOLD_value()) & 0xFF)>>0)
#define PROP_AM_VALID_HDLEVEL_THRESHOLD_AMVALHDLEVEL_RANGE_MIN (0)
#define PROP_AM_VALID_HDLEVEL_THRESHOLD_AMVALHDLEVEL_RANGE_MAX (100)
#define PROP_AM_VALID_HDLEVEL_THRESHOLD_DEFAULT 0

#define PROP_AM_RSQ_INTERRUPT_SOURCE_MASK 0xFFFF
#define PROP_AM_RSQ_INTERRUPT_SOURCE_INDEX 0x00
#define PROP_AM_RSQ_INTERRUPT_SOURCE_GROUP 0x43
#define PROP_AM_RSQ_INTERRUPT_SOURCE_value() (sys_prop_ReturnProperty(PROP_AM_RSQ_INTERRUPT_SOURCE_GROUP, PROP_AM_RSQ_INTERRUPT_SOURCE_INDEX))
#define PROP_AM_RSQ_INTERRUPT_SOURCE_SNRHINT_LSB 3
#define PROP_AM_RSQ_INTERRUPT_SOURCE_SNRHINT_MSB 3
#define PROP_AM_RSQ_INTERRUPT_SOURCE_SNRHINT_MASK 0x8
#define PROP_AM_RSQ_INTERRUPT_SOURCE_SNRHINT_BIT 0x8
#define PROP_AM_RSQ_INTERRUPT_SOURCE_SNRHINT_value() (((PROP_AM_RSQ_INTERRUPT_SOURCE_value()) & 0x8)>>3)
#define PROP_AM_RSQ_INTERRUPT_SOURCE_SNRLINT_LSB 2
#define PROP_AM_RSQ_INTERRUPT_SOURCE_SNRLINT_MSB 2
#define PROP_AM_RSQ_INTERRUPT_SOURCE_SNRLINT_MASK 0x4
#define PROP_AM_RSQ_INTERRUPT_SOURCE_SNRLINT_BIT 0x4
#define PROP_AM_RSQ_INTERRUPT_SOURCE_SNRLINT_value() (((PROP_AM_RSQ_INTERRUPT_SOURCE_value()) & 0x4)>>2)
#define PROP_AM_RSQ_INTERRUPT_SOURCE_RSSIHINT_LSB 1
#define PROP_AM_RSQ_INTERRUPT_SOURCE_RSSIHINT_MSB 1
#define PROP_AM_RSQ_INTERRUPT_SOURCE_RSSIHINT_MASK 0x2
#define PROP_AM_RSQ_INTERRUPT_SOURCE_RSSIHINT_BIT 0x2
#define PROP_AM_RSQ_INTERRUPT_SOURCE_RSSIHINT_value() (((PROP_AM_RSQ_INTERRUPT_SOURCE_value()) & 0x2)>>1)
#define PROP_AM_RSQ_INTERRUPT_SOURCE_RSSILINT_LSB 0
#define PROP_AM_RSQ_INTERRUPT_SOURCE_RSSILINT_MSB 0
#define PROP_AM_RSQ_INTERRUPT_SOURCE_RSSILINT_MASK 0x1
#define PROP_AM_RSQ_INTERRUPT_SOURCE_RSSILINT_BIT 0x1
#define PROP_AM_RSQ_INTERRUPT_SOURCE_RSSILINT_value() (((PROP_AM_RSQ_INTERRUPT_SOURCE_value()) & 0x1)>>0)
#define PROP_AM_RSQ_INTERRUPT_SOURCE_DEFAULT 0

#define PROP_AM_RSQ_SNR_HIGH_THRESHOLD_MASK 0xFFFF
#define PROP_AM_RSQ_SNR_HIGH_THRESHOLD_INDEX 0x01
#define PROP_AM_RSQ_SNR_HIGH_THRESHOLD_GROUP 0x43
#define PROP_AM_RSQ_SNR_HIGH_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_AM_RSQ_SNR_HIGH_THRESHOLD_GROUP, PROP_AM_RSQ_SNR_HIGH_THRESHOLD_INDEX))
#define PROP_AM_RSQ_SNR_HIGH_THRESHOLD_SNRH_LSB 0
#define PROP_AM_RSQ_SNR_HIGH_THRESHOLD_SNRH_MSB 7
#define PROP_AM_RSQ_SNR_HIGH_THRESHOLD_SNRH_MASK 0xFF
#define PROP_AM_RSQ_SNR_HIGH_THRESHOLD_SNRH_value() (int8_t)(((PROP_AM_RSQ_SNR_HIGH_THRESHOLD_value()) & 0xFF)>>0)
#define PROP_AM_RSQ_SNR_HIGH_THRESHOLD_SNRH_RANGE_MIN (-128)
#define PROP_AM_RSQ_SNR_HIGH_THRESHOLD_SNRH_RANGE_MAX (127)
#define PROP_AM_RSQ_SNR_HIGH_THRESHOLD_DEFAULT 127

#define PROP_AM_RSQ_SNR_LOW_THRESHOLD_MASK 0xFFFF
#define PROP_AM_RSQ_SNR_LOW_THRESHOLD_INDEX 0x02
#define PROP_AM_RSQ_SNR_LOW_THRESHOLD_GROUP 0x43
#define PROP_AM_RSQ_SNR_LOW_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_AM_RSQ_SNR_LOW_THRESHOLD_GROUP, PROP_AM_RSQ_SNR_LOW_THRESHOLD_INDEX))
#define PROP_AM_RSQ_SNR_LOW_THRESHOLD_SNRL_LSB 0
#define PROP_AM_RSQ_SNR_LOW_THRESHOLD_SNRL_MSB 7
#define PROP_AM_RSQ_SNR_LOW_THRESHOLD_SNRL_MASK 0xFF
#define PROP_AM_RSQ_SNR_LOW_THRESHOLD_SNRL_value() (int8_t)(((PROP_AM_RSQ_SNR_LOW_THRESHOLD_value()) & 0xFF)>>0)
#define PROP_AM_RSQ_SNR_LOW_THRESHOLD_SNRL_RANGE_MIN (-128)
#define PROP_AM_RSQ_SNR_LOW_THRESHOLD_SNRL_RANGE_MAX (127)
#define PROP_AM_RSQ_SNR_LOW_THRESHOLD_DEFAULT -128

#define PROP_AM_RSQ_RSSI_HIGH_THRESHOLD_MASK 0xFFFF
#define PROP_AM_RSQ_RSSI_HIGH_THRESHOLD_INDEX 0x03
#define PROP_AM_RSQ_RSSI_HIGH_THRESHOLD_GROUP 0x43
#define PROP_AM_RSQ_RSSI_HIGH_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_AM_RSQ_RSSI_HIGH_THRESHOLD_GROUP, PROP_AM_RSQ_RSSI_HIGH_THRESHOLD_INDEX))
#define PROP_AM_RSQ_RSSI_HIGH_THRESHOLD_RSSIH_LSB 0
#define PROP_AM_RSQ_RSSI_HIGH_THRESHOLD_RSSIH_MSB 7
#define PROP_AM_RSQ_RSSI_HIGH_THRESHOLD_RSSIH_MASK 0xFF
#define PROP_AM_RSQ_RSSI_HIGH_THRESHOLD_RSSIH_value() (int8_t)(((PROP_AM_RSQ_RSSI_HIGH_THRESHOLD_value()) & 0xFF)>>0)
#define PROP_AM_RSQ_RSSI_HIGH_THRESHOLD_RSSIH_RANGE_MIN (-128)
#define PROP_AM_RSQ_RSSI_HIGH_THRESHOLD_RSSIH_RANGE_MAX (127)
#define PROP_AM_RSQ_RSSI_HIGH_THRESHOLD_DEFAULT 127

#define PROP_AM_RSQ_RSSI_LOW_THRESHOLD_MASK 0xFFFF
#define PROP_AM_RSQ_RSSI_LOW_THRESHOLD_INDEX 0x04
#define PROP_AM_RSQ_RSSI_LOW_THRESHOLD_GROUP 0x43
#define PROP_AM_RSQ_RSSI_LOW_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_AM_RSQ_RSSI_LOW_THRESHOLD_GROUP, PROP_AM_RSQ_RSSI_LOW_THRESHOLD_INDEX))
#define PROP_AM_RSQ_RSSI_LOW_THRESHOLD_RSSIL_LSB 0
#define PROP_AM_RSQ_RSSI_LOW_THRESHOLD_RSSIL_MSB 7
#define PROP_AM_RSQ_RSSI_LOW_THRESHOLD_RSSIL_MASK 0xFF
#define PROP_AM_RSQ_RSSI_LOW_THRESHOLD_RSSIL_value() (int8_t)(((PROP_AM_RSQ_RSSI_LOW_THRESHOLD_value()) & 0xFF)>>0)
#define PROP_AM_RSQ_RSSI_LOW_THRESHOLD_RSSIL_RANGE_MIN (-128)
#define PROP_AM_RSQ_RSSI_LOW_THRESHOLD_RSSIL_RANGE_MAX (127)
#define PROP_AM_RSQ_RSSI_LOW_THRESHOLD_DEFAULT -128

#define PROP_AM_RSQ_HD_DETECTION_MASK 0xFFFF
#define PROP_AM_RSQ_HD_DETECTION_INDEX 0x05
#define PROP_AM_RSQ_HD_DETECTION_GROUP 0x43
#define PROP_AM_RSQ_HD_DETECTION_value() (sys_prop_ReturnProperty(PROP_AM_RSQ_HD_DETECTION_GROUP, PROP_AM_RSQ_HD_DETECTION_INDEX))
#define PROP_AM_RSQ_HD_DETECTION_SAMPLES_LSB 0
#define PROP_AM_RSQ_HD_DETECTION_SAMPLES_MSB 7
#define PROP_AM_RSQ_HD_DETECTION_SAMPLES_MASK 0xFF
#define PROP_AM_RSQ_HD_DETECTION_SAMPLES_value() (uint8_t)(((PROP_AM_RSQ_HD_DETECTION_value()) & 0xFF)>>0)
#define PROP_AM_RSQ_HD_DETECTION_SAMPLES_RANGE_MIN (20)
#define PROP_AM_RSQ_HD_DETECTION_SAMPLES_RANGE_MAX (64)
#define PROP_AM_RSQ_HD_DETECTION_DEFAULT 48

#define PROP_AM_RSQ_HD_LEVEL_TIME_CONST_MASK 0xFFFF
#define PROP_AM_RSQ_HD_LEVEL_TIME_CONST_INDEX 0x06
#define PROP_AM_RSQ_HD_LEVEL_TIME_CONST_GROUP 0x43
#define PROP_AM_RSQ_HD_LEVEL_TIME_CONST_value() (sys_prop_ReturnProperty(PROP_AM_RSQ_HD_LEVEL_TIME_CONST_GROUP, PROP_AM_RSQ_HD_LEVEL_TIME_CONST_INDEX))
#define PROP_AM_RSQ_HD_LEVEL_TIME_CONST_FILTER_TIME_CONSTANT_LSB 0
#define PROP_AM_RSQ_HD_LEVEL_TIME_CONST_FILTER_TIME_CONSTANT_MSB 7
#define PROP_AM_RSQ_HD_LEVEL_TIME_CONST_FILTER_TIME_CONSTANT_MASK 0xFF
#define PROP_AM_RSQ_HD_LEVEL_TIME_CONST_FILTER_TIME_CONSTANT_value() (uint8_t)(((PROP_AM_RSQ_HD_LEVEL_TIME_CONST_value()) & 0xFF)>>0)
#define PROP_AM_RSQ_HD_LEVEL_TIME_CONST_FILTER_TIME_CONSTANT_RANGE_MIN (1)
#define PROP_AM_RSQ_HD_LEVEL_TIME_CONST_FILTER_TIME_CONSTANT_RANGE_MAX (255)
#define PROP_AM_RSQ_HD_LEVEL_TIME_CONST_DEFAULT 32

#define PROP_AM_RSQ_HDDETECTED_THD_MASK 0xFFFF
#define PROP_AM_RSQ_HDDETECTED_THD_INDEX 0x07
#define PROP_AM_RSQ_HDDETECTED_THD_GROUP 0x43
#define PROP_AM_RSQ_HDDETECTED_THD_value() (sys_prop_ReturnProperty(PROP_AM_RSQ_HDDETECTED_THD_GROUP, PROP_AM_RSQ_HDDETECTED_THD_INDEX))
#define PROP_AM_RSQ_HDDETECTED_THD_HDDETECTED_THD_LSB 8
#define PROP_AM_RSQ_HDDETECTED_THD_HDDETECTED_THD_MSB 15
#define PROP_AM_RSQ_HDDETECTED_THD_HDDETECTED_THD_MASK 0xFF00
#define PROP_AM_RSQ_HDDETECTED_THD_HDDETECTED_THD_value() (uint8_t)(((PROP_AM_RSQ_HDDETECTED_THD_value()) & 0xFF00)>>8)
#define PROP_AM_RSQ_HDDETECTED_THD_HDDETECTED_THD_RANGE_MIN (1)
#define PROP_AM_RSQ_HDDETECTED_THD_HDDETECTED_THD_RANGE_MAX (100)
#define PROP_AM_RSQ_HDDETECTED_THD_FLT_HDDETECTED_THD_LSB 0
#define PROP_AM_RSQ_HDDETECTED_THD_FLT_HDDETECTED_THD_MSB 7
#define PROP_AM_RSQ_HDDETECTED_THD_FLT_HDDETECTED_THD_MASK 0xFF
#define PROP_AM_RSQ_HDDETECTED_THD_FLT_HDDETECTED_THD_value() (uint8_t)(((PROP_AM_RSQ_HDDETECTED_THD_value()) & 0xFF)>>0)
#define PROP_AM_RSQ_HDDETECTED_THD_FLT_HDDETECTED_THD_RANGE_MIN (1)
#define PROP_AM_RSQ_HDDETECTED_THD_FLT_HDDETECTED_THD_RANGE_MAX (100)
#define PROP_AM_RSQ_HDDETECTED_THD_DEFAULT 0x1E1E

#define PROP_AM_ACF_INTERRUPT_SOURCE_MASK 0xFFFF
#define PROP_AM_ACF_INTERRUPT_SOURCE_INDEX 0x00
#define PROP_AM_ACF_INTERRUPT_SOURCE_GROUP 0x44
#define PROP_AM_ACF_INTERRUPT_SOURCE_value() (sys_prop_ReturnProperty(PROP_AM_ACF_INTERRUPT_SOURCE_GROUP, PROP_AM_ACF_INTERRUPT_SOURCE_INDEX))
#define PROP_AM_ACF_INTERRUPT_SOURCE_HIGHCUT_INTEN_LSB 1
#define PROP_AM_ACF_INTERRUPT_SOURCE_HIGHCUT_INTEN_MSB 1
#define PROP_AM_ACF_INTERRUPT_SOURCE_HIGHCUT_INTEN_MASK 0x2
#define PROP_AM_ACF_INTERRUPT_SOURCE_HIGHCUT_INTEN_BIT 0x2
#define PROP_AM_ACF_INTERRUPT_SOURCE_HIGHCUT_INTEN_value() (((PROP_AM_ACF_INTERRUPT_SOURCE_value()) & 0x2)>>1)
#define PROP_AM_ACF_INTERRUPT_SOURCE_SMUTE_INTEN_LSB 0
#define PROP_AM_ACF_INTERRUPT_SOURCE_SMUTE_INTEN_MSB 0
#define PROP_AM_ACF_INTERRUPT_SOURCE_SMUTE_INTEN_MASK 0x1
#define PROP_AM_ACF_INTERRUPT_SOURCE_SMUTE_INTEN_BIT 0x1
#define PROP_AM_ACF_INTERRUPT_SOURCE_SMUTE_INTEN_value() (((PROP_AM_ACF_INTERRUPT_SOURCE_value()) & 0x1)>>0)
#define PROP_AM_ACF_INTERRUPT_SOURCE_DEFAULT 0

#define PROP_AM_ACF_SOFTMUTE_THRESHOLD_MASK 0xFFFF
#define PROP_AM_ACF_SOFTMUTE_THRESHOLD_INDEX 0x01
#define PROP_AM_ACF_SOFTMUTE_THRESHOLD_GROUP 0x44
#define PROP_AM_ACF_SOFTMUTE_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_AM_ACF_SOFTMUTE_THRESHOLD_GROUP, PROP_AM_ACF_SOFTMUTE_THRESHOLD_INDEX))
#define PROP_AM_ACF_SOFTMUTE_THRESHOLD_SMATTN_THRESH_LSB 0
#define PROP_AM_ACF_SOFTMUTE_THRESHOLD_SMATTN_THRESH_MSB 4
#define PROP_AM_ACF_SOFTMUTE_THRESHOLD_SMATTN_THRESH_MASK 0x1F
#define PROP_AM_ACF_SOFTMUTE_THRESHOLD_SMATTN_THRESH_value() (((PROP_AM_ACF_SOFTMUTE_THRESHOLD_value()) & 0x1F)>>0)
#define PROP_AM_ACF_SOFTMUTE_THRESHOLD_SMATTN_THRESH_RANGE_MIN (0)
#define PROP_AM_ACF_SOFTMUTE_THRESHOLD_SMATTN_THRESH_RANGE_MAX (31)
#define PROP_AM_ACF_SOFTMUTE_THRESHOLD_DEFAULT 31

#define PROP_AM_ACF_HIGHCUT_THRESHOLD_MASK 0xFFFF
#define PROP_AM_ACF_HIGHCUT_THRESHOLD_INDEX 0x02
#define PROP_AM_ACF_HIGHCUT_THRESHOLD_GROUP 0x44
#define PROP_AM_ACF_HIGHCUT_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_AM_ACF_HIGHCUT_THRESHOLD_GROUP, PROP_AM_ACF_HIGHCUT_THRESHOLD_INDEX))
#define PROP_AM_ACF_HIGHCUT_THRESHOLD_HIGHCUT_THRESH_LSB 0
#define PROP_AM_ACF_HIGHCUT_THRESHOLD_HIGHCUT_THRESH_MSB 7
#define PROP_AM_ACF_HIGHCUT_THRESHOLD_HIGHCUT_THRESH_MASK 0xFF
#define PROP_AM_ACF_HIGHCUT_THRESHOLD_HIGHCUT_THRESH_value() (uint8_t)(((PROP_AM_ACF_HIGHCUT_THRESHOLD_value()) & 0xFF)>>0)
#define PROP_AM_ACF_HIGHCUT_THRESHOLD_HIGHCUT_THRESH_RANGE_MIN (0)
#define PROP_AM_ACF_HIGHCUT_THRESHOLD_HIGHCUT_THRESH_RANGE_MAX (200)
#define PROP_AM_ACF_HIGHCUT_THRESHOLD_DEFAULT 0

#define PROP_AM_ACF_SOFTMUTE_TOLERANCE_MASK 0xFFFF
#define PROP_AM_ACF_SOFTMUTE_TOLERANCE_INDEX 0x03
#define PROP_AM_ACF_SOFTMUTE_TOLERANCE_GROUP 0x44
#define PROP_AM_ACF_SOFTMUTE_TOLERANCE_value() (sys_prop_ReturnProperty(PROP_AM_ACF_SOFTMUTE_TOLERANCE_GROUP, PROP_AM_ACF_SOFTMUTE_TOLERANCE_INDEX))
#define PROP_AM_ACF_SOFTMUTE_TOLERANCE_SMUTE_TOL_LSB 0
#define PROP_AM_ACF_SOFTMUTE_TOLERANCE_SMUTE_TOL_MSB 4
#define PROP_AM_ACF_SOFTMUTE_TOLERANCE_SMUTE_TOL_MASK 0x1F
#define PROP_AM_ACF_SOFTMUTE_TOLERANCE_SMUTE_TOL_value() (((PROP_AM_ACF_SOFTMUTE_TOLERANCE_value()) & 0x1F)>>0)
#define PROP_AM_ACF_SOFTMUTE_TOLERANCE_SMUTE_TOL_RANGE_MIN (0)
#define PROP_AM_ACF_SOFTMUTE_TOLERANCE_SMUTE_TOL_RANGE_MAX (31)
#define PROP_AM_ACF_SOFTMUTE_TOLERANCE_DEFAULT 2

#define PROP_AM_ACF_HIGHCUT_TOLERANCE_MASK 0xFFFF
#define PROP_AM_ACF_HIGHCUT_TOLERANCE_INDEX 0x04
#define PROP_AM_ACF_HIGHCUT_TOLERANCE_GROUP 0x44
#define PROP_AM_ACF_HIGHCUT_TOLERANCE_value() (sys_prop_ReturnProperty(PROP_AM_ACF_HIGHCUT_TOLERANCE_GROUP, PROP_AM_ACF_HIGHCUT_TOLERANCE_INDEX))
#define PROP_AM_ACF_HIGHCUT_TOLERANCE_HIGHCUT_TOL_LSB 0
#define PROP_AM_ACF_HIGHCUT_TOLERANCE_HIGHCUT_TOL_MSB 7
#define PROP_AM_ACF_HIGHCUT_TOLERANCE_HIGHCUT_TOL_MASK 0xFF
#define PROP_AM_ACF_HIGHCUT_TOLERANCE_HIGHCUT_TOL_value() (uint8_t)(((PROP_AM_ACF_HIGHCUT_TOLERANCE_value()) & 0xFF)>>0)
#define PROP_AM_ACF_HIGHCUT_TOLERANCE_HIGHCUT_TOL_RANGE_MIN (0)
#define PROP_AM_ACF_HIGHCUT_TOLERANCE_HIGHCUT_TOL_RANGE_MAX (200)
#define PROP_AM_ACF_HIGHCUT_TOLERANCE_DEFAULT 20

#define PROP_AM_ACF_CONTROL_SOURCE_MASK 0xFFFF
#define PROP_AM_ACF_CONTROL_SOURCE_INDEX 0x05
#define PROP_AM_ACF_CONTROL_SOURCE_GROUP 0x44
#define PROP_AM_ACF_CONTROL_SOURCE_value() (sys_prop_ReturnProperty(PROP_AM_ACF_CONTROL_SOURCE_GROUP, PROP_AM_ACF_CONTROL_SOURCE_INDEX))
#define PROP_AM_ACF_CONTROL_SOURCE_AFC_DIS_LSB 3
#define PROP_AM_ACF_CONTROL_SOURCE_AFC_DIS_MSB 3
#define PROP_AM_ACF_CONTROL_SOURCE_AFC_DIS_MASK 0x8
#define PROP_AM_ACF_CONTROL_SOURCE_AFC_DIS_BIT 0x8
#define PROP_AM_ACF_CONTROL_SOURCE_AFC_DIS_value() (((PROP_AM_ACF_CONTROL_SOURCE_value()) & 0x8)>>3)
#define PROP_AM_ACF_CONTROL_SOURCE_AFC_DIS_ENUM_NONE 0
#define PROP_AM_ACF_CONTROL_SOURCE_AFC_DIS_ENUM_DISABLE_AFC 1
#define PROP_AM_ACF_CONTROL_SOURCE_AFC_SM_LSB 2
#define PROP_AM_ACF_CONTROL_SOURCE_AFC_SM_MSB 2
#define PROP_AM_ACF_CONTROL_SOURCE_AFC_SM_MASK 0x4
#define PROP_AM_ACF_CONTROL_SOURCE_AFC_SM_BIT 0x4
#define PROP_AM_ACF_CONTROL_SOURCE_AFC_SM_value() (((PROP_AM_ACF_CONTROL_SOURCE_value()) & 0x4)>>2)
#define PROP_AM_ACF_CONTROL_SOURCE_AFC_SM_ENUM_NONE 0
#define PROP_AM_ACF_CONTROL_SOURCE_AFC_SM_ENUM_USE_AFCRAIL 1
#define PROP_AM_ACF_CONTROL_SOURCE_USE_RSSI_LSB 0
#define PROP_AM_ACF_CONTROL_SOURCE_USE_RSSI_MSB 0
#define PROP_AM_ACF_CONTROL_SOURCE_USE_RSSI_MASK 0x1
#define PROP_AM_ACF_CONTROL_SOURCE_USE_RSSI_BIT 0x1
#define PROP_AM_ACF_CONTROL_SOURCE_USE_RSSI_value() (((PROP_AM_ACF_CONTROL_SOURCE_value()) & 0x1)>>0)
#define PROP_AM_ACF_CONTROL_SOURCE_USE_RSSI_ENUM_ACF_USE_SNR 0
#define PROP_AM_ACF_CONTROL_SOURCE_USE_RSSI_ENUM_ACF_USE_RSSI 1
#define PROP_AM_ACF_CONTROL_SOURCE_DEFAULT 0

#define PROP_AM_SOFTMUTE_SQ_LIMITS_MASK 0xFFFF
#define PROP_AM_SOFTMUTE_SQ_LIMITS_INDEX 0x00
#define PROP_AM_SOFTMUTE_SQ_LIMITS_GROUP 0x45
#define PROP_AM_SOFTMUTE_SQ_LIMITS_value() (sys_prop_ReturnProperty(PROP_AM_SOFTMUTE_SQ_LIMITS_GROUP, PROP_AM_SOFTMUTE_SQ_LIMITS_INDEX))
#define PROP_AM_SOFTMUTE_SQ_LIMITS_XMAX_LSB 8
#define PROP_AM_SOFTMUTE_SQ_LIMITS_XMAX_MSB 15
#define PROP_AM_SOFTMUTE_SQ_LIMITS_XMAX_MASK 0xFF00
#define PROP_AM_SOFTMUTE_SQ_LIMITS_XMAX_value() (int8_t)(((PROP_AM_SOFTMUTE_SQ_LIMITS_value()) & 0xFF00)>>8)
#define PROP_AM_SOFTMUTE_SQ_LIMITS_XMAX_RANGE_MIN (-20)
#define PROP_AM_SOFTMUTE_SQ_LIMITS_XMAX_RANGE_MAX (64)
#define PROP_AM_SOFTMUTE_SQ_LIMITS_XMIN_LSB 0
#define PROP_AM_SOFTMUTE_SQ_LIMITS_XMIN_MSB 7
#define PROP_AM_SOFTMUTE_SQ_LIMITS_XMIN_MASK 0xFF
#define PROP_AM_SOFTMUTE_SQ_LIMITS_XMIN_value() (int8_t)(((PROP_AM_SOFTMUTE_SQ_LIMITS_value()) & 0xFF)>>0)
#define PROP_AM_SOFTMUTE_SQ_LIMITS_XMIN_RANGE_MIN (-20)
#define PROP_AM_SOFTMUTE_SQ_LIMITS_XMIN_RANGE_MAX (64)
#define PROP_AM_SOFTMUTE_SQ_LIMITS_DEFAULT 0x0800

#define PROP_AM_SOFTMUTE_SQ_ATTENUATION_MASK 0xFFFF
#define PROP_AM_SOFTMUTE_SQ_ATTENUATION_INDEX 0x01
#define PROP_AM_SOFTMUTE_SQ_ATTENUATION_GROUP 0x45
#define PROP_AM_SOFTMUTE_SQ_ATTENUATION_value() (sys_prop_ReturnProperty(PROP_AM_SOFTMUTE_SQ_ATTENUATION_GROUP, PROP_AM_SOFTMUTE_SQ_ATTENUATION_INDEX))
#define PROP_AM_SOFTMUTE_SQ_ATTENUATION_ATTENMIN_LSB 8
#define PROP_AM_SOFTMUTE_SQ_ATTENUATION_ATTENMIN_MSB 15
#define PROP_AM_SOFTMUTE_SQ_ATTENUATION_ATTENMIN_MASK 0xFF00
#define PROP_AM_SOFTMUTE_SQ_ATTENUATION_ATTENMIN_value() (uint8_t)(((PROP_AM_SOFTMUTE_SQ_ATTENUATION_value()) & 0xFF00)>>8)
#define PROP_AM_SOFTMUTE_SQ_ATTENUATION_ATTENMIN_RANGE_MIN (0)
#define PROP_AM_SOFTMUTE_SQ_ATTENUATION_ATTENMIN_RANGE_MAX (31)
#define PROP_AM_SOFTMUTE_SQ_ATTENUATION_ATTENMAX_LSB 0
#define PROP_AM_SOFTMUTE_SQ_ATTENUATION_ATTENMAX_MSB 7
#define PROP_AM_SOFTMUTE_SQ_ATTENUATION_ATTENMAX_MASK 0xFF
#define PROP_AM_SOFTMUTE_SQ_ATTENUATION_ATTENMAX_value() (uint8_t)(((PROP_AM_SOFTMUTE_SQ_ATTENUATION_value()) & 0xFF)>>0)
#define PROP_AM_SOFTMUTE_SQ_ATTENUATION_ATTENMAX_RANGE_MIN (0)
#define PROP_AM_SOFTMUTE_SQ_ATTENUATION_ATTENMAX_RANGE_MAX (31)
#define PROP_AM_SOFTMUTE_SQ_ATTENUATION_DEFAULT 0x000C

#define PROP_AM_SOFTMUTE_SQ_ATTACK_TIME_MASK 0xFFFF
#define PROP_AM_SOFTMUTE_SQ_ATTACK_TIME_INDEX 0x02
#define PROP_AM_SOFTMUTE_SQ_ATTACK_TIME_GROUP 0x45
#define PROP_AM_SOFTMUTE_SQ_ATTACK_TIME_value() (sys_prop_ReturnProperty(PROP_AM_SOFTMUTE_SQ_ATTACK_TIME_GROUP, PROP_AM_SOFTMUTE_SQ_ATTACK_TIME_INDEX))
#define PROP_AM_SOFTMUTE_SQ_ATTACK_TIME_ATTACK_LSB 0
#define PROP_AM_SOFTMUTE_SQ_ATTACK_TIME_ATTACK_MSB 15
#define PROP_AM_SOFTMUTE_SQ_ATTACK_TIME_ATTACK_MASK 0xFFFF
#define PROP_AM_SOFTMUTE_SQ_ATTACK_TIME_ATTACK_value() (uint16_t)(((PROP_AM_SOFTMUTE_SQ_ATTACK_TIME_value()) & 0xFFFF)>>0)
#define PROP_AM_SOFTMUTE_SQ_ATTACK_TIME_ATTACK_RANGE_MIN (16)
#define PROP_AM_SOFTMUTE_SQ_ATTACK_TIME_ATTACK_RANGE_MAX (65535)
#define PROP_AM_SOFTMUTE_SQ_ATTACK_TIME_DEFAULT 120

#define PROP_AM_SOFTMUTE_SQ_RELEASE_TIME_MASK 0xFFFF
#define PROP_AM_SOFTMUTE_SQ_RELEASE_TIME_INDEX 0x03
#define PROP_AM_SOFTMUTE_SQ_RELEASE_TIME_GROUP 0x45
#define PROP_AM_SOFTMUTE_SQ_RELEASE_TIME_value() (sys_prop_ReturnProperty(PROP_AM_SOFTMUTE_SQ_RELEASE_TIME_GROUP, PROP_AM_SOFTMUTE_SQ_RELEASE_TIME_INDEX))
#define PROP_AM_SOFTMUTE_SQ_RELEASE_TIME_RELEASE_LSB 0
#define PROP_AM_SOFTMUTE_SQ_RELEASE_TIME_RELEASE_MSB 15
#define PROP_AM_SOFTMUTE_SQ_RELEASE_TIME_RELEASE_MASK 0xFFFF
#define PROP_AM_SOFTMUTE_SQ_RELEASE_TIME_RELEASE_value() (uint16_t)(((PROP_AM_SOFTMUTE_SQ_RELEASE_TIME_value()) & 0xFFFF)>>0)
#define PROP_AM_SOFTMUTE_SQ_RELEASE_TIME_RELEASE_RANGE_MIN (16)
#define PROP_AM_SOFTMUTE_SQ_RELEASE_TIME_RELEASE_RANGE_MAX (65535)
#define PROP_AM_SOFTMUTE_SQ_RELEASE_TIME_DEFAULT 500

#define PROP_AM_HIGHCUT_SQ_LIMITS_MASK 0xFFFF
#define PROP_AM_HIGHCUT_SQ_LIMITS_INDEX 0x00
#define PROP_AM_HIGHCUT_SQ_LIMITS_GROUP 0x46
#define PROP_AM_HIGHCUT_SQ_LIMITS_value() (sys_prop_ReturnProperty(PROP_AM_HIGHCUT_SQ_LIMITS_GROUP, PROP_AM_HIGHCUT_SQ_LIMITS_INDEX))
#define PROP_AM_HIGHCUT_SQ_LIMITS_SQ_MAX_LSB 8
#define PROP_AM_HIGHCUT_SQ_LIMITS_SQ_MAX_MSB 15
#define PROP_AM_HIGHCUT_SQ_LIMITS_SQ_MAX_MASK 0xFF00
#define PROP_AM_HIGHCUT_SQ_LIMITS_SQ_MAX_value() (int8_t)(((PROP_AM_HIGHCUT_SQ_LIMITS_value()) & 0xFF00)>>8)
#define PROP_AM_HIGHCUT_SQ_LIMITS_SQ_MAX_RANGE_MIN (-20)
#define PROP_AM_HIGHCUT_SQ_LIMITS_SQ_MAX_RANGE_MAX (64)
#define PROP_AM_HIGHCUT_SQ_LIMITS_SQ_MIN_LSB 0
#define PROP_AM_HIGHCUT_SQ_LIMITS_SQ_MIN_MSB 7
#define PROP_AM_HIGHCUT_SQ_LIMITS_SQ_MIN_MASK 0xFF
#define PROP_AM_HIGHCUT_SQ_LIMITS_SQ_MIN_value() (int8_t)(((PROP_AM_HIGHCUT_SQ_LIMITS_value()) & 0xFF)>>0)
#define PROP_AM_HIGHCUT_SQ_LIMITS_SQ_MIN_RANGE_MIN (-20)
#define PROP_AM_HIGHCUT_SQ_LIMITS_SQ_MIN_RANGE_MAX (64)
#define PROP_AM_HIGHCUT_SQ_LIMITS_DEFAULT 0x0a06

#define PROP_AM_HIGHCUT_SQ_CUTOFF_FREQ_MASK 0xFFFF
#define PROP_AM_HIGHCUT_SQ_CUTOFF_FREQ_INDEX 0x01
#define PROP_AM_HIGHCUT_SQ_CUTOFF_FREQ_GROUP 0x46
#define PROP_AM_HIGHCUT_SQ_CUTOFF_FREQ_value() (sys_prop_ReturnProperty(PROP_AM_HIGHCUT_SQ_CUTOFF_FREQ_GROUP, PROP_AM_HIGHCUT_SQ_CUTOFF_FREQ_INDEX))
#define PROP_AM_HIGHCUT_SQ_CUTOFF_FREQ_MAX_LSB 8
#define PROP_AM_HIGHCUT_SQ_CUTOFF_FREQ_MAX_MSB 15
#define PROP_AM_HIGHCUT_SQ_CUTOFF_FREQ_MAX_MASK 0xFF00
#define PROP_AM_HIGHCUT_SQ_CUTOFF_FREQ_MAX_value() (((PROP_AM_HIGHCUT_SQ_CUTOFF_FREQ_value()) & 0xFF00)>>8)
#define PROP_AM_HIGHCUT_SQ_CUTOFF_FREQ_MAX_RANGE_MIN (10)
#define PROP_AM_HIGHCUT_SQ_CUTOFF_FREQ_MAX_RANGE_MAX (50)
#define PROP_AM_HIGHCUT_SQ_CUTOFF_FREQ_MIN_LSB 0
#define PROP_AM_HIGHCUT_SQ_CUTOFF_FREQ_MIN_MSB 7
#define PROP_AM_HIGHCUT_SQ_CUTOFF_FREQ_MIN_MASK 0xFF
#define PROP_AM_HIGHCUT_SQ_CUTOFF_FREQ_MIN_value() (((PROP_AM_HIGHCUT_SQ_CUTOFF_FREQ_value()) & 0xFF)>>0)
#define PROP_AM_HIGHCUT_SQ_CUTOFF_FREQ_MIN_RANGE_MIN (10)
#define PROP_AM_HIGHCUT_SQ_CUTOFF_FREQ_MIN_RANGE_MAX (50)
#define PROP_AM_HIGHCUT_SQ_CUTOFF_FREQ_DEFAULT 0x280A

#define PROP_AM_HIGHCUT_SQ_ATTACK_TIME_MASK 0xFFFF
#define PROP_AM_HIGHCUT_SQ_ATTACK_TIME_INDEX 0x02
#define PROP_AM_HIGHCUT_SQ_ATTACK_TIME_GROUP 0x46
#define PROP_AM_HIGHCUT_SQ_ATTACK_TIME_value() (sys_prop_ReturnProperty(PROP_AM_HIGHCUT_SQ_ATTACK_TIME_GROUP, PROP_AM_HIGHCUT_SQ_ATTACK_TIME_INDEX))
#define PROP_AM_HIGHCUT_SQ_ATTACK_TIME_ATTACK_LSB 0
#define PROP_AM_HIGHCUT_SQ_ATTACK_TIME_ATTACK_MSB 15
#define PROP_AM_HIGHCUT_SQ_ATTACK_TIME_ATTACK_MASK 0xFFFF
#define PROP_AM_HIGHCUT_SQ_ATTACK_TIME_ATTACK_value() (((PROP_AM_HIGHCUT_SQ_ATTACK_TIME_value()) & 0xFFFF)>>0)
#define PROP_AM_HIGHCUT_SQ_ATTACK_TIME_ATTACK_RANGE_MIN (1)
#define PROP_AM_HIGHCUT_SQ_ATTACK_TIME_ATTACK_RANGE_MAX (32767)
#define PROP_AM_HIGHCUT_SQ_ATTACK_TIME_DEFAULT 16

#define PROP_AM_HIGHCUT_SQ_RELEASE_TIME_MASK 0xFFFF
#define PROP_AM_HIGHCUT_SQ_RELEASE_TIME_INDEX 0x03
#define PROP_AM_HIGHCUT_SQ_RELEASE_TIME_GROUP 0x46
#define PROP_AM_HIGHCUT_SQ_RELEASE_TIME_value() (sys_prop_ReturnProperty(PROP_AM_HIGHCUT_SQ_RELEASE_TIME_GROUP, PROP_AM_HIGHCUT_SQ_RELEASE_TIME_INDEX))
#define PROP_AM_HIGHCUT_SQ_RELEASE_TIME_RELEASE_LSB 0
#define PROP_AM_HIGHCUT_SQ_RELEASE_TIME_RELEASE_MSB 15
#define PROP_AM_HIGHCUT_SQ_RELEASE_TIME_RELEASE_MASK 0xFFFF
#define PROP_AM_HIGHCUT_SQ_RELEASE_TIME_RELEASE_value() (((PROP_AM_HIGHCUT_SQ_RELEASE_TIME_value()) & 0xFFFF)>>0)
#define PROP_AM_HIGHCUT_SQ_RELEASE_TIME_RELEASE_RANGE_MIN (1)
#define PROP_AM_HIGHCUT_SQ_RELEASE_TIME_RELEASE_RANGE_MAX (32767)
#define PROP_AM_HIGHCUT_SQ_RELEASE_TIME_DEFAULT 2000

#define PROP_AM_DEMOD_AFC_RANGE_MASK 0xFFFF
#define PROP_AM_DEMOD_AFC_RANGE_INDEX 0x00
#define PROP_AM_DEMOD_AFC_RANGE_GROUP 0x48
#define PROP_AM_DEMOD_AFC_RANGE_value() (sys_prop_ReturnProperty(PROP_AM_DEMOD_AFC_RANGE_GROUP, PROP_AM_DEMOD_AFC_RANGE_INDEX))
#define PROP_AM_DEMOD_AFC_RANGE_RANGE_LSB 0
#define PROP_AM_DEMOD_AFC_RANGE_RANGE_MSB 15
#define PROP_AM_DEMOD_AFC_RANGE_RANGE_MASK 0xFFFF
#define PROP_AM_DEMOD_AFC_RANGE_RANGE_value() (((PROP_AM_DEMOD_AFC_RANGE_value()) & 0xFFFF)>>0)
#define PROP_AM_DEMOD_AFC_RANGE_RANGE_RANGE_MIN (0)
#define PROP_AM_DEMOD_AFC_RANGE_RANGE_RANGE_MAX (6000)
#define PROP_AM_DEMOD_AFC_RANGE_DEFAULT 0x0000

#define PROP_DIGITAL_SERVICE_INT_SOURCE_MASK 0xFFFF
#define PROP_DIGITAL_SERVICE_INT_SOURCE_INDEX 0x00
#define PROP_DIGITAL_SERVICE_INT_SOURCE_GROUP 0x81
#define PROP_DIGITAL_SERVICE_INT_SOURCE_value() (sys_prop_ReturnProperty(PROP_DIGITAL_SERVICE_INT_SOURCE_GROUP, PROP_DIGITAL_SERVICE_INT_SOURCE_INDEX))
#define PROP_DIGITAL_SERVICE_INT_SOURCE_DSRVOVFLINT_LSB 1
#define PROP_DIGITAL_SERVICE_INT_SOURCE_DSRVOVFLINT_MSB 1
#define PROP_DIGITAL_SERVICE_INT_SOURCE_DSRVOVFLINT_MASK 0x2
#define PROP_DIGITAL_SERVICE_INT_SOURCE_DSRVOVFLINT_BIT 0x2
#define PROP_DIGITAL_SERVICE_INT_SOURCE_DSRVOVFLINT_value() (((PROP_DIGITAL_SERVICE_INT_SOURCE_value()) & 0x2)>>1)
#define PROP_DIGITAL_SERVICE_INT_SOURCE_DSRVPCKTINT_LSB 0
#define PROP_DIGITAL_SERVICE_INT_SOURCE_DSRVPCKTINT_MSB 0
#define PROP_DIGITAL_SERVICE_INT_SOURCE_DSRVPCKTINT_MASK 0x1
#define PROP_DIGITAL_SERVICE_INT_SOURCE_DSRVPCKTINT_BIT 0x1
#define PROP_DIGITAL_SERVICE_INT_SOURCE_DSRVPCKTINT_value() (((PROP_DIGITAL_SERVICE_INT_SOURCE_value()) & 0x1)>>0)
#define PROP_DIGITAL_SERVICE_INT_SOURCE_DEFAULT 0x0000


#define PROP_DIGITAL_SERVICE_RESTART_DELAY_MASK 0xFFFF
#define PROP_DIGITAL_SERVICE_RESTART_DELAY_INDEX 0x01
#define PROP_DIGITAL_SERVICE_RESTART_DELAY_GROUP 0x81
#define PROP_DIGITAL_SERVICE_RESTART_DELAY_value() (sys_prop_ReturnProperty(PROP_DIGITAL_SERVICE_RESTART_DELAY_GROUP, PROP_DIGITAL_SERVICE_RESTART_DELAY_INDEX))
#define PROP_DIGITAL_SERVICE_RESTART_DELAY_RESTART_DELAY_LSB 0
#define PROP_DIGITAL_SERVICE_RESTART_DELAY_RESTART_DELAY_MSB 15
#define PROP_DIGITAL_SERVICE_RESTART_DELAY_RESTART_DELAY_MASK 0xFFFF
#define PROP_DIGITAL_SERVICE_RESTART_DELAY_RESTART_DELAY_value() (((PROP_DIGITAL_SERVICE_RESTART_DELAY_value()) & 0xFFFF)>>0)
#define PROP_DIGITAL_SERVICE_RESTART_DELAY_RESTART_DELAY_RANGE_MIN (100)
#define PROP_DIGITAL_SERVICE_RESTART_DELAY_RESTART_DELAY_RANGE_MAX (65535)
#define PROP_DIGITAL_SERVICE_RESTART_DELAY_DEFAULT 200

#define PROP_HD_BLEND_OPTIONS_MASK 0xFFFF
#define PROP_HD_BLEND_OPTIONS_INDEX 0x01
#define PROP_HD_BLEND_OPTIONS_GROUP 0x91
#define PROP_HD_BLEND_OPTIONS_value() (sys_prop_ReturnProperty(PROP_HD_BLEND_OPTIONS_GROUP, PROP_HD_BLEND_OPTIONS_INDEX))
#define PROP_HD_BLEND_OPTIONS_BANDWIDTH_MANAGEMENT_CTRL_LSB 9
#define PROP_HD_BLEND_OPTIONS_BANDWIDTH_MANAGEMENT_CTRL_MSB 9
#define PROP_HD_BLEND_OPTIONS_BANDWIDTH_MANAGEMENT_CTRL_MASK 0x200
#define PROP_HD_BLEND_OPTIONS_BANDWIDTH_MANAGEMENT_CTRL_BIT 0x200
#define PROP_HD_BLEND_OPTIONS_BANDWIDTH_MANAGEMENT_CTRL_value() (((PROP_HD_BLEND_OPTIONS_value()) & 0x200)>>9)
#define PROP_HD_BLEND_OPTIONS_BANDWIDTH_MANAGEMENT_CTRL_ENUM_USE_DAAI 0
#define PROP_HD_BLEND_OPTIONS_BANDWIDTH_MANAGEMENT_CTRL_ENUM_USE_CDNO 1
#define PROP_HD_BLEND_OPTIONS_MONO_STEREO_TRANSITION_ENABLE_LSB 8
#define PROP_HD_BLEND_OPTIONS_MONO_STEREO_TRANSITION_ENABLE_MSB 8
#define PROP_HD_BLEND_OPTIONS_MONO_STEREO_TRANSITION_ENABLE_MASK 0x100
#define PROP_HD_BLEND_OPTIONS_MONO_STEREO_TRANSITION_ENABLE_BIT 0x100
#define PROP_HD_BLEND_OPTIONS_MONO_STEREO_TRANSITION_ENABLE_value() (((PROP_HD_BLEND_OPTIONS_value()) & 0x100)>>8)
#define PROP_HD_BLEND_OPTIONS_MONO_STEREO_TRANSITION_ENABLE_ENUM_DISABLE 0
#define PROP_HD_BLEND_OPTIONS_MONO_STEREO_TRANSITION_ENABLE_ENUM_ENABLE 1
#define PROP_HD_BLEND_OPTIONS_BANDWIDTH_MANAGEMENT_ENABLE_LSB 7
#define PROP_HD_BLEND_OPTIONS_BANDWIDTH_MANAGEMENT_ENABLE_MSB 7
#define PROP_HD_BLEND_OPTIONS_BANDWIDTH_MANAGEMENT_ENABLE_MASK 0x80
#define PROP_HD_BLEND_OPTIONS_BANDWIDTH_MANAGEMENT_ENABLE_BIT 0x80
#define PROP_HD_BLEND_OPTIONS_BANDWIDTH_MANAGEMENT_ENABLE_value() (((PROP_HD_BLEND_OPTIONS_value()) & 0x80)>>7)
#define PROP_HD_BLEND_OPTIONS_BANDWIDTH_MANAGEMENT_ENABLE_ENUM_DISABLE 0
#define PROP_HD_BLEND_OPTIONS_BANDWIDTH_MANAGEMENT_ENABLE_ENUM_ENABLE 1
#define PROP_HD_BLEND_OPTIONS_SERV_SWITCH_RAMP_ENABLE_LSB 6
#define PROP_HD_BLEND_OPTIONS_SERV_SWITCH_RAMP_ENABLE_MSB 6
#define PROP_HD_BLEND_OPTIONS_SERV_SWITCH_RAMP_ENABLE_MASK 0x40
#define PROP_HD_BLEND_OPTIONS_SERV_SWITCH_RAMP_ENABLE_BIT 0x40
#define PROP_HD_BLEND_OPTIONS_SERV_SWITCH_RAMP_ENABLE_value() (((PROP_HD_BLEND_OPTIONS_value()) & 0x40)>>6)
#define PROP_HD_BLEND_OPTIONS_SERV_SWITCH_RAMP_ENABLE_ENUM_DISABLE 0
#define PROP_HD_BLEND_OPTIONS_SERV_SWITCH_RAMP_ENABLE_ENUM_ENABLE 1
#define PROP_HD_BLEND_OPTIONS_SERV_LOSS_NOISE_ENABLE_LSB 5
#define PROP_HD_BLEND_OPTIONS_SERV_LOSS_NOISE_ENABLE_MSB 5
#define PROP_HD_BLEND_OPTIONS_SERV_LOSS_NOISE_ENABLE_MASK 0x20
#define PROP_HD_BLEND_OPTIONS_SERV_LOSS_NOISE_ENABLE_BIT 0x20
#define PROP_HD_BLEND_OPTIONS_SERV_LOSS_NOISE_ENABLE_value() (((PROP_HD_BLEND_OPTIONS_value()) & 0x20)>>5)
#define PROP_HD_BLEND_OPTIONS_SERV_LOSS_NOISE_ENABLE_ENUM_DISABLE 0
#define PROP_HD_BLEND_OPTIONS_SERV_LOSS_NOISE_ENABLE_ENUM_ENABLE 1
#define PROP_HD_BLEND_OPTIONS_SERV_LOSS_RAMP_ENABLE_LSB 4
#define PROP_HD_BLEND_OPTIONS_SERV_LOSS_RAMP_ENABLE_MSB 4
#define PROP_HD_BLEND_OPTIONS_SERV_LOSS_RAMP_ENABLE_MASK 0x10
#define PROP_HD_BLEND_OPTIONS_SERV_LOSS_RAMP_ENABLE_BIT 0x10
#define PROP_HD_BLEND_OPTIONS_SERV_LOSS_RAMP_ENABLE_value() (((PROP_HD_BLEND_OPTIONS_value()) & 0x10)>>4)
#define PROP_HD_BLEND_OPTIONS_SERV_LOSS_RAMP_ENABLE_ENUM_DISABLE 0
#define PROP_HD_BLEND_OPTIONS_SERV_LOSS_RAMP_ENABLE_ENUM_ENABLE 1
#define PROP_HD_BLEND_OPTIONS_BLEND_DECISION_ENABLE_LSB 3
#define PROP_HD_BLEND_OPTIONS_BLEND_DECISION_ENABLE_MSB 3
#define PROP_HD_BLEND_OPTIONS_BLEND_DECISION_ENABLE_MASK 0x8
#define PROP_HD_BLEND_OPTIONS_BLEND_DECISION_ENABLE_BIT 0x8
#define PROP_HD_BLEND_OPTIONS_BLEND_DECISION_ENABLE_value() (((PROP_HD_BLEND_OPTIONS_value()) & 0x8)>>3)
#define PROP_HD_BLEND_OPTIONS_BLEND_DECISION_ENABLE_ENUM_DISABLE 0
#define PROP_HD_BLEND_OPTIONS_BLEND_DECISION_ENABLE_ENUM_ENABLE 1
#define PROP_HD_BLEND_OPTIONS_BLEND_PIN_CTRL_LSB 2
#define PROP_HD_BLEND_OPTIONS_BLEND_PIN_CTRL_MSB 2
#define PROP_HD_BLEND_OPTIONS_BLEND_PIN_CTRL_MASK 0x4
#define PROP_HD_BLEND_OPTIONS_BLEND_PIN_CTRL_BIT 0x4
#define PROP_HD_BLEND_OPTIONS_BLEND_PIN_CTRL_value() (((PROP_HD_BLEND_OPTIONS_value()) & 0x4)>>2)
#define PROP_HD_BLEND_OPTIONS_BLEND_PIN_CTRL_ENUM_AUTO 0
#define PROP_HD_BLEND_OPTIONS_BLEND_PIN_CTRL_ENUM_FORCE_ANALOG 1
#define PROP_HD_BLEND_OPTIONS_ACQ_LOSS_LSB 0
#define PROP_HD_BLEND_OPTIONS_ACQ_LOSS_MSB 1
#define PROP_HD_BLEND_OPTIONS_ACQ_LOSS_MASK 0x3
#define PROP_HD_BLEND_OPTIONS_ACQ_LOSS_value() (((PROP_HD_BLEND_OPTIONS_value()) & 0x3)>>0)
#define PROP_HD_BLEND_OPTIONS_ACQ_LOSS_ENUM_ANALOG 0
#define PROP_HD_BLEND_OPTIONS_ACQ_LOSS_ENUM_SILENCE 1
#define PROP_HD_BLEND_OPTIONS_ACQ_LOSS_ENUM_HYBRID 2
#define PROP_HD_BLEND_OPTIONS_DEFAULT 0x000A

#define PROP_HD_BLEND_ANALOG_TO_HD_TRANSITION_TIME_MASK 0xFFFF
#define PROP_HD_BLEND_ANALOG_TO_HD_TRANSITION_TIME_INDEX 0x02
#define PROP_HD_BLEND_ANALOG_TO_HD_TRANSITION_TIME_GROUP 0x91
#define PROP_HD_BLEND_ANALOG_TO_HD_TRANSITION_TIME_value() (sys_prop_ReturnProperty(PROP_HD_BLEND_ANALOG_TO_HD_TRANSITION_TIME_GROUP, PROP_HD_BLEND_ANALOG_TO_HD_TRANSITION_TIME_INDEX))
#define PROP_HD_BLEND_ANALOG_TO_HD_TRANSITION_TIME_BLEND_TIME_LSB 0
#define PROP_HD_BLEND_ANALOG_TO_HD_TRANSITION_TIME_BLEND_TIME_MSB 15
#define PROP_HD_BLEND_ANALOG_TO_HD_TRANSITION_TIME_BLEND_TIME_MASK 0xFFFF
#define PROP_HD_BLEND_ANALOG_TO_HD_TRANSITION_TIME_BLEND_TIME_value() (uint16_t)(((PROP_HD_BLEND_ANALOG_TO_HD_TRANSITION_TIME_value()) & 0xFFFF)>>0)
#define PROP_HD_BLEND_ANALOG_TO_HD_TRANSITION_TIME_DEFAULT 750

#define PROP_HD_BLEND_HD_TO_ANALOG_TRANSITION_TIME_MASK 0xFFFF
#define PROP_HD_BLEND_HD_TO_ANALOG_TRANSITION_TIME_INDEX 0x03
#define PROP_HD_BLEND_HD_TO_ANALOG_TRANSITION_TIME_GROUP 0x91
#define PROP_HD_BLEND_HD_TO_ANALOG_TRANSITION_TIME_value() (sys_prop_ReturnProperty(PROP_HD_BLEND_HD_TO_ANALOG_TRANSITION_TIME_GROUP, PROP_HD_BLEND_HD_TO_ANALOG_TRANSITION_TIME_INDEX))
#define PROP_HD_BLEND_HD_TO_ANALOG_TRANSITION_TIME_BLEND_TIME_LSB 0
#define PROP_HD_BLEND_HD_TO_ANALOG_TRANSITION_TIME_BLEND_TIME_MSB 15
#define PROP_HD_BLEND_HD_TO_ANALOG_TRANSITION_TIME_BLEND_TIME_MASK 0xFFFF
#define PROP_HD_BLEND_HD_TO_ANALOG_TRANSITION_TIME_BLEND_TIME_value() (uint16_t)(((PROP_HD_BLEND_HD_TO_ANALOG_TRANSITION_TIME_value()) & 0xFFFF)>>0)
#define PROP_HD_BLEND_HD_TO_ANALOG_TRANSITION_TIME_DEFAULT 100

#define PROP_HD_BLEND_DYNAMIC_GAIN_MASK 0xFFFF
#define PROP_HD_BLEND_DYNAMIC_GAIN_INDEX 0x06
#define PROP_HD_BLEND_DYNAMIC_GAIN_GROUP 0x91
#define PROP_HD_BLEND_DYNAMIC_GAIN_value() (sys_prop_ReturnProperty(PROP_HD_BLEND_DYNAMIC_GAIN_GROUP, PROP_HD_BLEND_DYNAMIC_GAIN_INDEX))
#define PROP_HD_BLEND_DYNAMIC_GAIN_DGAIN_OVERRIDE_LSB 8
#define PROP_HD_BLEND_DYNAMIC_GAIN_DGAIN_OVERRIDE_MSB 8
#define PROP_HD_BLEND_DYNAMIC_GAIN_DGAIN_OVERRIDE_MASK 0x100
#define PROP_HD_BLEND_DYNAMIC_GAIN_DGAIN_OVERRIDE_BIT 0x100
#define PROP_HD_BLEND_DYNAMIC_GAIN_DGAIN_OVERRIDE_value() (((PROP_HD_BLEND_DYNAMIC_GAIN_value()) & 0x100)>>8)
#define PROP_HD_BLEND_DYNAMIC_GAIN_DGAIN_OVERRIDE_ENUM_NO_OVERRIDE 0
#define PROP_HD_BLEND_DYNAMIC_GAIN_DGAIN_OVERRIDE_ENUM_OVERRIDE 1
#define PROP_HD_BLEND_DYNAMIC_GAIN_DGAIN_LSB 0
#define PROP_HD_BLEND_DYNAMIC_GAIN_DGAIN_MSB 7
#define PROP_HD_BLEND_DYNAMIC_GAIN_DGAIN_MASK 0xFF
#define PROP_HD_BLEND_DYNAMIC_GAIN_DGAIN_value() (int8_t)(((PROP_HD_BLEND_DYNAMIC_GAIN_value()) & 0xFF)>>0)
#define PROP_HD_BLEND_DYNAMIC_GAIN_DGAIN_RANGE_MIN (-128)
#define PROP_HD_BLEND_DYNAMIC_GAIN_DGAIN_RANGE_MAX (127)
#define PROP_HD_BLEND_DYNAMIC_GAIN_DEFAULT 0

#define PROP_HD_BLEND_DECISION_ANA_TO_DIG_THRESHOLD_MASK 0xFFFF
#define PROP_HD_BLEND_DECISION_ANA_TO_DIG_THRESHOLD_INDEX 0x09
#define PROP_HD_BLEND_DECISION_ANA_TO_DIG_THRESHOLD_GROUP 0x91
#define PROP_HD_BLEND_DECISION_ANA_TO_DIG_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_HD_BLEND_DECISION_ANA_TO_DIG_THRESHOLD_GROUP, PROP_HD_BLEND_DECISION_ANA_TO_DIG_THRESHOLD_INDEX))
#define PROP_HD_BLEND_DECISION_ANA_TO_DIG_THRESHOLD_A2D_THRESHOLD_LSB 0
#define PROP_HD_BLEND_DECISION_ANA_TO_DIG_THRESHOLD_A2D_THRESHOLD_MSB 7
#define PROP_HD_BLEND_DECISION_ANA_TO_DIG_THRESHOLD_A2D_THRESHOLD_MASK 0xFF
#define PROP_HD_BLEND_DECISION_ANA_TO_DIG_THRESHOLD_A2D_THRESHOLD_value() (uint8_t)(((PROP_HD_BLEND_DECISION_ANA_TO_DIG_THRESHOLD_value()) & 0xFF)>>0)
#define PROP_HD_BLEND_DECISION_ANA_TO_DIG_THRESHOLD_DEFAULT 58

#define PROP_HD_BLEND_DECISION_ANA_TO_DIG_DELAY_MASK 0xFFFF
#define PROP_HD_BLEND_DECISION_ANA_TO_DIG_DELAY_INDEX 0x0A
#define PROP_HD_BLEND_DECISION_ANA_TO_DIG_DELAY_GROUP 0x91
#define PROP_HD_BLEND_DECISION_ANA_TO_DIG_DELAY_value() (sys_prop_ReturnProperty(PROP_HD_BLEND_DECISION_ANA_TO_DIG_DELAY_GROUP, PROP_HD_BLEND_DECISION_ANA_TO_DIG_DELAY_INDEX))
#define PROP_HD_BLEND_DECISION_ANA_TO_DIG_DELAY_A2D_DELAY_LSB 0
#define PROP_HD_BLEND_DECISION_ANA_TO_DIG_DELAY_A2D_DELAY_MSB 15
#define PROP_HD_BLEND_DECISION_ANA_TO_DIG_DELAY_A2D_DELAY_MASK 0xFFFF
#define PROP_HD_BLEND_DECISION_ANA_TO_DIG_DELAY_A2D_DELAY_value() (uint16_t)(((PROP_HD_BLEND_DECISION_ANA_TO_DIG_DELAY_value()) & 0xFFFF)>>0)
#define PROP_HD_BLEND_DECISION_ANA_TO_DIG_DELAY_DEFAULT 5000

#define PROP_HD_BLEND_SERV_LOSS_RAMP_UP_TIME_MASK 0xFFFF
#define PROP_HD_BLEND_SERV_LOSS_RAMP_UP_TIME_INDEX 0x0B
#define PROP_HD_BLEND_SERV_LOSS_RAMP_UP_TIME_GROUP 0x91
#define PROP_HD_BLEND_SERV_LOSS_RAMP_UP_TIME_value() (sys_prop_ReturnProperty(PROP_HD_BLEND_SERV_LOSS_RAMP_UP_TIME_GROUP, PROP_HD_BLEND_SERV_LOSS_RAMP_UP_TIME_INDEX))
#define PROP_HD_BLEND_SERV_LOSS_RAMP_UP_TIME_SERV_LOSS_RAMP_UP_TIME_LSB 0
#define PROP_HD_BLEND_SERV_LOSS_RAMP_UP_TIME_SERV_LOSS_RAMP_UP_TIME_MSB 15
#define PROP_HD_BLEND_SERV_LOSS_RAMP_UP_TIME_SERV_LOSS_RAMP_UP_TIME_MASK 0xFFFF
#define PROP_HD_BLEND_SERV_LOSS_RAMP_UP_TIME_SERV_LOSS_RAMP_UP_TIME_value() (((PROP_HD_BLEND_SERV_LOSS_RAMP_UP_TIME_value()) & 0xFFFF)>>0)
#define PROP_HD_BLEND_SERV_LOSS_RAMP_UP_TIME_SERV_LOSS_RAMP_UP_TIME_RANGE_MIN (50)
#define PROP_HD_BLEND_SERV_LOSS_RAMP_UP_TIME_SERV_LOSS_RAMP_UP_TIME_RANGE_MAX (2000)
#define PROP_HD_BLEND_SERV_LOSS_RAMP_UP_TIME_DEFAULT 750

#define PROP_HD_BLEND_SERV_LOSS_RAMP_DOWN_TIME_MASK 0xFFFF
#define PROP_HD_BLEND_SERV_LOSS_RAMP_DOWN_TIME_INDEX 0x0C
#define PROP_HD_BLEND_SERV_LOSS_RAMP_DOWN_TIME_GROUP 0x91
#define PROP_HD_BLEND_SERV_LOSS_RAMP_DOWN_TIME_value() (sys_prop_ReturnProperty(PROP_HD_BLEND_SERV_LOSS_RAMP_DOWN_TIME_GROUP, PROP_HD_BLEND_SERV_LOSS_RAMP_DOWN_TIME_INDEX))
#define PROP_HD_BLEND_SERV_LOSS_RAMP_DOWN_TIME_SERV_LOSS_RAMP_DOWN_TIME_LSB 0
#define PROP_HD_BLEND_SERV_LOSS_RAMP_DOWN_TIME_SERV_LOSS_RAMP_DOWN_TIME_MSB 15
#define PROP_HD_BLEND_SERV_LOSS_RAMP_DOWN_TIME_SERV_LOSS_RAMP_DOWN_TIME_MASK 0xFFFF
#define PROP_HD_BLEND_SERV_LOSS_RAMP_DOWN_TIME_SERV_LOSS_RAMP_DOWN_TIME_value() (((PROP_HD_BLEND_SERV_LOSS_RAMP_DOWN_TIME_value()) & 0xFFFF)>>0)
#define PROP_HD_BLEND_SERV_LOSS_RAMP_DOWN_TIME_SERV_LOSS_RAMP_DOWN_TIME_RANGE_MIN (50)
#define PROP_HD_BLEND_SERV_LOSS_RAMP_DOWN_TIME_SERV_LOSS_RAMP_DOWN_TIME_RANGE_MAX (2000)
#define PROP_HD_BLEND_SERV_LOSS_RAMP_DOWN_TIME_DEFAULT 250

#define PROP_HD_BLEND_SERV_LOSS_NOISE_RAMP_UP_TIME_MASK 0xFFFF
#define PROP_HD_BLEND_SERV_LOSS_NOISE_RAMP_UP_TIME_INDEX 0x0D
#define PROP_HD_BLEND_SERV_LOSS_NOISE_RAMP_UP_TIME_GROUP 0x91
#define PROP_HD_BLEND_SERV_LOSS_NOISE_RAMP_UP_TIME_value() (sys_prop_ReturnProperty(PROP_HD_BLEND_SERV_LOSS_NOISE_RAMP_UP_TIME_GROUP, PROP_HD_BLEND_SERV_LOSS_NOISE_RAMP_UP_TIME_INDEX))
#define PROP_HD_BLEND_SERV_LOSS_NOISE_RAMP_UP_TIME_SERV_LOSS_NOISE_RAMP_UP_TIME_LSB 0
#define PROP_HD_BLEND_SERV_LOSS_NOISE_RAMP_UP_TIME_SERV_LOSS_NOISE_RAMP_UP_TIME_MSB 15
#define PROP_HD_BLEND_SERV_LOSS_NOISE_RAMP_UP_TIME_SERV_LOSS_NOISE_RAMP_UP_TIME_MASK 0xFFFF
#define PROP_HD_BLEND_SERV_LOSS_NOISE_RAMP_UP_TIME_SERV_LOSS_NOISE_RAMP_UP_TIME_value() (((PROP_HD_BLEND_SERV_LOSS_NOISE_RAMP_UP_TIME_value()) & 0xFFFF)>>0)
#define PROP_HD_BLEND_SERV_LOSS_NOISE_RAMP_UP_TIME_SERV_LOSS_NOISE_RAMP_UP_TIME_RANGE_MIN (50)
#define PROP_HD_BLEND_SERV_LOSS_NOISE_RAMP_UP_TIME_SERV_LOSS_NOISE_RAMP_UP_TIME_RANGE_MAX (2000)
#define PROP_HD_BLEND_SERV_LOSS_NOISE_RAMP_UP_TIME_DEFAULT 1000

#define PROP_HD_BLEND_SERV_LOSS_NOISE_RAMP_DOWN_TIME_MASK 0xFFFF
#define PROP_HD_BLEND_SERV_LOSS_NOISE_RAMP_DOWN_TIME_INDEX 0x0E
#define PROP_HD_BLEND_SERV_LOSS_NOISE_RAMP_DOWN_TIME_GROUP 0x91
#define PROP_HD_BLEND_SERV_LOSS_NOISE_RAMP_DOWN_TIME_value() (sys_prop_ReturnProperty(PROP_HD_BLEND_SERV_LOSS_NOISE_RAMP_DOWN_TIME_GROUP, PROP_HD_BLEND_SERV_LOSS_NOISE_RAMP_DOWN_TIME_INDEX))
#define PROP_HD_BLEND_SERV_LOSS_NOISE_RAMP_DOWN_TIME_SERV_LOSS_NOISE_RAMP_DOWN_TIME_LSB 0
#define PROP_HD_BLEND_SERV_LOSS_NOISE_RAMP_DOWN_TIME_SERV_LOSS_NOISE_RAMP_DOWN_TIME_MSB 15
#define PROP_HD_BLEND_SERV_LOSS_NOISE_RAMP_DOWN_TIME_SERV_LOSS_NOISE_RAMP_DOWN_TIME_MASK 0xFFFF
#define PROP_HD_BLEND_SERV_LOSS_NOISE_RAMP_DOWN_TIME_SERV_LOSS_NOISE_RAMP_DOWN_TIME_value() (((PROP_HD_BLEND_SERV_LOSS_NOISE_RAMP_DOWN_TIME_value()) & 0xFFFF)>>0)
#define PROP_HD_BLEND_SERV_LOSS_NOISE_RAMP_DOWN_TIME_SERV_LOSS_NOISE_RAMP_DOWN_TIME_RANGE_MIN (50)
#define PROP_HD_BLEND_SERV_LOSS_NOISE_RAMP_DOWN_TIME_SERV_LOSS_NOISE_RAMP_DOWN_TIME_RANGE_MAX (2000)
#define PROP_HD_BLEND_SERV_LOSS_NOISE_RAMP_DOWN_TIME_DEFAULT 250

#define PROP_HD_BLEND_SERV_LOSS_NOISE_LEVEL_MASK 0xFFFF
#define PROP_HD_BLEND_SERV_LOSS_NOISE_LEVEL_INDEX 0x0F
#define PROP_HD_BLEND_SERV_LOSS_NOISE_LEVEL_GROUP 0x91
#define PROP_HD_BLEND_SERV_LOSS_NOISE_LEVEL_value() (sys_prop_ReturnProperty(PROP_HD_BLEND_SERV_LOSS_NOISE_LEVEL_GROUP, PROP_HD_BLEND_SERV_LOSS_NOISE_LEVEL_INDEX))
#define PROP_HD_BLEND_SERV_LOSS_NOISE_LEVEL_SERV_LOSS_NOISE_LEVEL_LSB 0
#define PROP_HD_BLEND_SERV_LOSS_NOISE_LEVEL_SERV_LOSS_NOISE_LEVEL_MSB 15
#define PROP_HD_BLEND_SERV_LOSS_NOISE_LEVEL_SERV_LOSS_NOISE_LEVEL_MASK 0xFFFF
#define PROP_HD_BLEND_SERV_LOSS_NOISE_LEVEL_SERV_LOSS_NOISE_LEVEL_value() (((PROP_HD_BLEND_SERV_LOSS_NOISE_LEVEL_value()) & 0xFFFF)>>0)
#define PROP_HD_BLEND_SERV_LOSS_NOISE_LEVEL_SERV_LOSS_NOISE_LEVEL_RANGE_MIN (0)
#define PROP_HD_BLEND_SERV_LOSS_NOISE_LEVEL_SERV_LOSS_NOISE_LEVEL_RANGE_MAX (16383)
#define PROP_HD_BLEND_SERV_LOSS_NOISE_LEVEL_DEFAULT 512

#define PROP_HD_BLEND_SERV_LOSS_NOISE_DAAI_THRESHOLD_MASK 0xFFFF
#define PROP_HD_BLEND_SERV_LOSS_NOISE_DAAI_THRESHOLD_INDEX 0x10
#define PROP_HD_BLEND_SERV_LOSS_NOISE_DAAI_THRESHOLD_GROUP 0x91
#define PROP_HD_BLEND_SERV_LOSS_NOISE_DAAI_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_HD_BLEND_SERV_LOSS_NOISE_DAAI_THRESHOLD_GROUP, PROP_HD_BLEND_SERV_LOSS_NOISE_DAAI_THRESHOLD_INDEX))
#define PROP_HD_BLEND_SERV_LOSS_NOISE_DAAI_THRESHOLD_SERV_LOSS_NOISE_DAAI_THRESHOLD_LSB 0
#define PROP_HD_BLEND_SERV_LOSS_NOISE_DAAI_THRESHOLD_SERV_LOSS_NOISE_DAAI_THRESHOLD_MSB 15
#define PROP_HD_BLEND_SERV_LOSS_NOISE_DAAI_THRESHOLD_SERV_LOSS_NOISE_DAAI_THRESHOLD_MASK 0xFFFF
#define PROP_HD_BLEND_SERV_LOSS_NOISE_DAAI_THRESHOLD_SERV_LOSS_NOISE_DAAI_THRESHOLD_value() (((PROP_HD_BLEND_SERV_LOSS_NOISE_DAAI_THRESHOLD_value()) & 0xFFFF)>>0)
#define PROP_HD_BLEND_SERV_LOSS_NOISE_DAAI_THRESHOLD_SERV_LOSS_NOISE_DAAI_THRESHOLD_RANGE_MIN (0)
#define PROP_HD_BLEND_SERV_LOSS_NOISE_DAAI_THRESHOLD_SERV_LOSS_NOISE_DAAI_THRESHOLD_RANGE_MAX (60)
#define PROP_HD_BLEND_SERV_LOSS_NOISE_DAAI_THRESHOLD_DEFAULT 40

#define PROP_HD_BLEND_SERV_LOSS_NOISE_AUDIO_START_DELAY_MASK 0xFFFF
#define PROP_HD_BLEND_SERV_LOSS_NOISE_AUDIO_START_DELAY_INDEX 0x11
#define PROP_HD_BLEND_SERV_LOSS_NOISE_AUDIO_START_DELAY_GROUP 0x91
#define PROP_HD_BLEND_SERV_LOSS_NOISE_AUDIO_START_DELAY_value() (sys_prop_ReturnProperty(PROP_HD_BLEND_SERV_LOSS_NOISE_AUDIO_START_DELAY_GROUP, PROP_HD_BLEND_SERV_LOSS_NOISE_AUDIO_START_DELAY_INDEX))
#define PROP_HD_BLEND_SERV_LOSS_NOISE_AUDIO_START_DELAY_SERV_LOSS_NOISE_AUDIO_START_DELAY_LSB 0
#define PROP_HD_BLEND_SERV_LOSS_NOISE_AUDIO_START_DELAY_SERV_LOSS_NOISE_AUDIO_START_DELAY_MSB 15
#define PROP_HD_BLEND_SERV_LOSS_NOISE_AUDIO_START_DELAY_SERV_LOSS_NOISE_AUDIO_START_DELAY_MASK 0xFFFF
#define PROP_HD_BLEND_SERV_LOSS_NOISE_AUDIO_START_DELAY_SERV_LOSS_NOISE_AUDIO_START_DELAY_value() (((PROP_HD_BLEND_SERV_LOSS_NOISE_AUDIO_START_DELAY_value()) & 0xFFFF)>>0)
#define PROP_HD_BLEND_SERV_LOSS_NOISE_AUDIO_START_DELAY_SERV_LOSS_NOISE_AUDIO_START_DELAY_RANGE_MIN (0)
#define PROP_HD_BLEND_SERV_LOSS_NOISE_AUDIO_START_DELAY_SERV_LOSS_NOISE_AUDIO_START_DELAY_RANGE_MAX (200)
#define PROP_HD_BLEND_SERV_LOSS_NOISE_AUDIO_START_DELAY_DEFAULT 4

#define PROP_HD_BLEND_SERV_SWITCH_RAMP_UP_TIME_MASK 0xFFFF
#define PROP_HD_BLEND_SERV_SWITCH_RAMP_UP_TIME_INDEX 0x12
#define PROP_HD_BLEND_SERV_SWITCH_RAMP_UP_TIME_GROUP 0x91
#define PROP_HD_BLEND_SERV_SWITCH_RAMP_UP_TIME_value() (sys_prop_ReturnProperty(PROP_HD_BLEND_SERV_SWITCH_RAMP_UP_TIME_GROUP, PROP_HD_BLEND_SERV_SWITCH_RAMP_UP_TIME_INDEX))
#define PROP_HD_BLEND_SERV_SWITCH_RAMP_UP_TIME_SERV_SWITCH_RAMP_UP_TIME_LSB 0
#define PROP_HD_BLEND_SERV_SWITCH_RAMP_UP_TIME_SERV_SWITCH_RAMP_UP_TIME_MSB 15
#define PROP_HD_BLEND_SERV_SWITCH_RAMP_UP_TIME_SERV_SWITCH_RAMP_UP_TIME_MASK 0xFFFF
#define PROP_HD_BLEND_SERV_SWITCH_RAMP_UP_TIME_SERV_SWITCH_RAMP_UP_TIME_value() (((PROP_HD_BLEND_SERV_SWITCH_RAMP_UP_TIME_value()) & 0xFFFF)>>0)
#define PROP_HD_BLEND_SERV_SWITCH_RAMP_UP_TIME_SERV_SWITCH_RAMP_UP_TIME_RANGE_MIN (50)
#define PROP_HD_BLEND_SERV_SWITCH_RAMP_UP_TIME_SERV_SWITCH_RAMP_UP_TIME_RANGE_MAX (2000)
#define PROP_HD_BLEND_SERV_SWITCH_RAMP_UP_TIME_DEFAULT 184

#define PROP_HD_BLEND_SERV_SWITCH_RAMP_DOWN_TIME_MASK 0xFFFF
#define PROP_HD_BLEND_SERV_SWITCH_RAMP_DOWN_TIME_INDEX 0x13
#define PROP_HD_BLEND_SERV_SWITCH_RAMP_DOWN_TIME_GROUP 0x91
#define PROP_HD_BLEND_SERV_SWITCH_RAMP_DOWN_TIME_value() (sys_prop_ReturnProperty(PROP_HD_BLEND_SERV_SWITCH_RAMP_DOWN_TIME_GROUP, PROP_HD_BLEND_SERV_SWITCH_RAMP_DOWN_TIME_INDEX))
#define PROP_HD_BLEND_SERV_SWITCH_RAMP_DOWN_TIME_SERV_SWITCH_RAMP_DOWN_TIME_LSB 0
#define PROP_HD_BLEND_SERV_SWITCH_RAMP_DOWN_TIME_SERV_SWITCH_RAMP_DOWN_TIME_MSB 15
#define PROP_HD_BLEND_SERV_SWITCH_RAMP_DOWN_TIME_SERV_SWITCH_RAMP_DOWN_TIME_MASK 0xFFFF
#define PROP_HD_BLEND_SERV_SWITCH_RAMP_DOWN_TIME_SERV_SWITCH_RAMP_DOWN_TIME_value() (((PROP_HD_BLEND_SERV_SWITCH_RAMP_DOWN_TIME_value()) & 0xFFFF)>>0)
#define PROP_HD_BLEND_SERV_SWITCH_RAMP_DOWN_TIME_SERV_SWITCH_RAMP_DOWN_TIME_RANGE_MIN (50)
#define PROP_HD_BLEND_SERV_SWITCH_RAMP_DOWN_TIME_SERV_SWITCH_RAMP_DOWN_TIME_RANGE_MAX (2000)
#define PROP_HD_BLEND_SERV_SWITCH_RAMP_DOWN_TIME_DEFAULT 184

#define PROP_HD_BLEND_BWM_CTRL_THRES_MASK 0xFFFF
#define PROP_HD_BLEND_BWM_CTRL_THRES_INDEX 0x20
#define PROP_HD_BLEND_BWM_CTRL_THRES_GROUP 0x91
#define PROP_HD_BLEND_BWM_CTRL_THRES_value() (sys_prop_ReturnProperty(PROP_HD_BLEND_BWM_CTRL_THRES_GROUP, PROP_HD_BLEND_BWM_CTRL_THRES_INDEX))
#define PROP_HD_BLEND_BWM_CTRL_THRES_BWM_CTRL_THRES_LSB 0
#define PROP_HD_BLEND_BWM_CTRL_THRES_BWM_CTRL_THRES_MSB 15
#define PROP_HD_BLEND_BWM_CTRL_THRES_BWM_CTRL_THRES_MASK 0xFFFF
#define PROP_HD_BLEND_BWM_CTRL_THRES_BWM_CTRL_THRES_value() (((PROP_HD_BLEND_BWM_CTRL_THRES_value()) & 0xFFFF)>>0)
#define PROP_HD_BLEND_BWM_CTRL_THRES_BWM_CTRL_THRES_RANGE_MIN (0)
#define PROP_HD_BLEND_BWM_CTRL_THRES_BWM_CTRL_THRES_RANGE_MAX (100)
#define PROP_HD_BLEND_BWM_CTRL_THRES_DEFAULT 0x003C

#define PROP_HD_BLEND_BWM_CTRL_LEVEL_MASK 0xFFFF
#define PROP_HD_BLEND_BWM_CTRL_LEVEL_INDEX 0x21
#define PROP_HD_BLEND_BWM_CTRL_LEVEL_GROUP 0x91
#define PROP_HD_BLEND_BWM_CTRL_LEVEL_value() (sys_prop_ReturnProperty(PROP_HD_BLEND_BWM_CTRL_LEVEL_GROUP, PROP_HD_BLEND_BWM_CTRL_LEVEL_INDEX))
#define PROP_HD_BLEND_BWM_CTRL_LEVEL_MAX_LSB 8
#define PROP_HD_BLEND_BWM_CTRL_LEVEL_MAX_MSB 15
#define PROP_HD_BLEND_BWM_CTRL_LEVEL_MAX_MASK 0xFF00
#define PROP_HD_BLEND_BWM_CTRL_LEVEL_MAX_value() (((PROP_HD_BLEND_BWM_CTRL_LEVEL_value()) & 0xFF00)>>8)
#define PROP_HD_BLEND_BWM_CTRL_LEVEL_MAX_RANGE_MIN (10)
#define PROP_HD_BLEND_BWM_CTRL_LEVEL_MAX_RANGE_MAX (200)
#define PROP_HD_BLEND_BWM_CTRL_LEVEL_MIN_LSB 0
#define PROP_HD_BLEND_BWM_CTRL_LEVEL_MIN_MSB 7
#define PROP_HD_BLEND_BWM_CTRL_LEVEL_MIN_MASK 0xFF
#define PROP_HD_BLEND_BWM_CTRL_LEVEL_MIN_value() (((PROP_HD_BLEND_BWM_CTRL_LEVEL_value()) & 0xFF)>>0)
#define PROP_HD_BLEND_BWM_CTRL_LEVEL_MIN_RANGE_MIN (10)
#define PROP_HD_BLEND_BWM_CTRL_LEVEL_MIN_RANGE_MAX (200)
#define PROP_HD_BLEND_BWM_CTRL_LEVEL_DEFAULT 0x9628

#define PROP_HD_BLEND_BWM_CTRL_RAMP_UP_TIME_MASK 0xFFFF
#define PROP_HD_BLEND_BWM_CTRL_RAMP_UP_TIME_INDEX 0x22
#define PROP_HD_BLEND_BWM_CTRL_RAMP_UP_TIME_GROUP 0x91
#define PROP_HD_BLEND_BWM_CTRL_RAMP_UP_TIME_value() (sys_prop_ReturnProperty(PROP_HD_BLEND_BWM_CTRL_RAMP_UP_TIME_GROUP, PROP_HD_BLEND_BWM_CTRL_RAMP_UP_TIME_INDEX))
#define PROP_HD_BLEND_BWM_CTRL_RAMP_UP_TIME_BWM_CTRL_RAMP_UP_TIME_LSB 0
#define PROP_HD_BLEND_BWM_CTRL_RAMP_UP_TIME_BWM_CTRL_RAMP_UP_TIME_MSB 15
#define PROP_HD_BLEND_BWM_CTRL_RAMP_UP_TIME_BWM_CTRL_RAMP_UP_TIME_MASK 0xFFFF
#define PROP_HD_BLEND_BWM_CTRL_RAMP_UP_TIME_BWM_CTRL_RAMP_UP_TIME_value() (((PROP_HD_BLEND_BWM_CTRL_RAMP_UP_TIME_value()) & 0xFFFF)>>0)
#define PROP_HD_BLEND_BWM_CTRL_RAMP_UP_TIME_BWM_CTRL_RAMP_UP_TIME_RANGE_MIN (1)
#define PROP_HD_BLEND_BWM_CTRL_RAMP_UP_TIME_BWM_CTRL_RAMP_UP_TIME_RANGE_MAX (32767)
#define PROP_HD_BLEND_BWM_CTRL_RAMP_UP_TIME_DEFAULT 5000

#define PROP_HD_BLEND_BWM_CTRL_RAMP_DOWN_TIME_MASK 0xFFFF
#define PROP_HD_BLEND_BWM_CTRL_RAMP_DOWN_TIME_INDEX 0x23
#define PROP_HD_BLEND_BWM_CTRL_RAMP_DOWN_TIME_GROUP 0x91
#define PROP_HD_BLEND_BWM_CTRL_RAMP_DOWN_TIME_value() (sys_prop_ReturnProperty(PROP_HD_BLEND_BWM_CTRL_RAMP_DOWN_TIME_GROUP, PROP_HD_BLEND_BWM_CTRL_RAMP_DOWN_TIME_INDEX))
#define PROP_HD_BLEND_BWM_CTRL_RAMP_DOWN_TIME_BWM_CTRL_RAMP_DOWN_TIME_LSB 0
#define PROP_HD_BLEND_BWM_CTRL_RAMP_DOWN_TIME_BWM_CTRL_RAMP_DOWN_TIME_MSB 15
#define PROP_HD_BLEND_BWM_CTRL_RAMP_DOWN_TIME_BWM_CTRL_RAMP_DOWN_TIME_MASK 0xFFFF
#define PROP_HD_BLEND_BWM_CTRL_RAMP_DOWN_TIME_BWM_CTRL_RAMP_DOWN_TIME_value() (((PROP_HD_BLEND_BWM_CTRL_RAMP_DOWN_TIME_value()) & 0xFFFF)>>0)
#define PROP_HD_BLEND_BWM_CTRL_RAMP_DOWN_TIME_BWM_CTRL_RAMP_DOWN_TIME_RANGE_MIN (1)
#define PROP_HD_BLEND_BWM_CTRL_RAMP_DOWN_TIME_BWM_CTRL_RAMP_DOWN_TIME_RANGE_MAX (32767)
#define PROP_HD_BLEND_BWM_CTRL_RAMP_DOWN_TIME_DEFAULT 200

#define PROP_HD_BLEND_BWM_BLEND_THRES_MASK 0xFFFF
#define PROP_HD_BLEND_BWM_BLEND_THRES_INDEX 0x24
#define PROP_HD_BLEND_BWM_BLEND_THRES_GROUP 0x91
#define PROP_HD_BLEND_BWM_BLEND_THRES_value() (sys_prop_ReturnProperty(PROP_HD_BLEND_BWM_BLEND_THRES_GROUP, PROP_HD_BLEND_BWM_BLEND_THRES_INDEX))
#define PROP_HD_BLEND_BWM_BLEND_THRES_BWM_BLEND_THRES_LSB 0
#define PROP_HD_BLEND_BWM_BLEND_THRES_BWM_BLEND_THRES_MSB 15
#define PROP_HD_BLEND_BWM_BLEND_THRES_BWM_BLEND_THRES_MASK 0xFFFF
#define PROP_HD_BLEND_BWM_BLEND_THRES_BWM_BLEND_THRES_value() (((PROP_HD_BLEND_BWM_BLEND_THRES_value()) & 0xFFFF)>>0)
#define PROP_HD_BLEND_BWM_BLEND_THRES_BWM_BLEND_THRES_RANGE_MIN (0)
#define PROP_HD_BLEND_BWM_BLEND_THRES_BWM_BLEND_THRES_RANGE_MAX (200)
#define PROP_HD_BLEND_BWM_BLEND_THRES_DEFAULT 0x0032

#define PROP_HD_BLEND_BWM_BLEND_LEVEL_MASK 0xFFFF
#define PROP_HD_BLEND_BWM_BLEND_LEVEL_INDEX 0x25
#define PROP_HD_BLEND_BWM_BLEND_LEVEL_GROUP 0x91
#define PROP_HD_BLEND_BWM_BLEND_LEVEL_value() (sys_prop_ReturnProperty(PROP_HD_BLEND_BWM_BLEND_LEVEL_GROUP, PROP_HD_BLEND_BWM_BLEND_LEVEL_INDEX))
#define PROP_HD_BLEND_BWM_BLEND_LEVEL_MAX_LSB 8
#define PROP_HD_BLEND_BWM_BLEND_LEVEL_MAX_MSB 15
#define PROP_HD_BLEND_BWM_BLEND_LEVEL_MAX_MASK 0xFF00
#define PROP_HD_BLEND_BWM_BLEND_LEVEL_MAX_value() (((PROP_HD_BLEND_BWM_BLEND_LEVEL_value()) & 0xFF00)>>8)
#define PROP_HD_BLEND_BWM_BLEND_LEVEL_MAX_RANGE_MIN (0)
#define PROP_HD_BLEND_BWM_BLEND_LEVEL_MAX_RANGE_MAX (127)
#define PROP_HD_BLEND_BWM_BLEND_LEVEL_MIN_LSB 0
#define PROP_HD_BLEND_BWM_BLEND_LEVEL_MIN_MSB 7
#define PROP_HD_BLEND_BWM_BLEND_LEVEL_MIN_MASK 0xFF
#define PROP_HD_BLEND_BWM_BLEND_LEVEL_MIN_value() (((PROP_HD_BLEND_BWM_BLEND_LEVEL_value()) & 0xFF)>>0)
#define PROP_HD_BLEND_BWM_BLEND_LEVEL_MIN_RANGE_MIN (0)
#define PROP_HD_BLEND_BWM_BLEND_LEVEL_MIN_RANGE_MAX (127)
#define PROP_HD_BLEND_BWM_BLEND_LEVEL_DEFAULT 0x7F00

#define PROP_HD_BLEND_BWM_BLEND_RAMP_UP_TIME_MASK 0xFFFF
#define PROP_HD_BLEND_BWM_BLEND_RAMP_UP_TIME_INDEX 0x26
#define PROP_HD_BLEND_BWM_BLEND_RAMP_UP_TIME_GROUP 0x91
#define PROP_HD_BLEND_BWM_BLEND_RAMP_UP_TIME_value() (sys_prop_ReturnProperty(PROP_HD_BLEND_BWM_BLEND_RAMP_UP_TIME_GROUP, PROP_HD_BLEND_BWM_BLEND_RAMP_UP_TIME_INDEX))
#define PROP_HD_BLEND_BWM_BLEND_RAMP_UP_TIME_BWM_BLEND_RAMP_UP_TIME_LSB 0
#define PROP_HD_BLEND_BWM_BLEND_RAMP_UP_TIME_BWM_BLEND_RAMP_UP_TIME_MSB 15
#define PROP_HD_BLEND_BWM_BLEND_RAMP_UP_TIME_BWM_BLEND_RAMP_UP_TIME_MASK 0xFFFF
#define PROP_HD_BLEND_BWM_BLEND_RAMP_UP_TIME_BWM_BLEND_RAMP_UP_TIME_value() (((PROP_HD_BLEND_BWM_BLEND_RAMP_UP_TIME_value()) & 0xFFFF)>>0)
#define PROP_HD_BLEND_BWM_BLEND_RAMP_UP_TIME_BWM_BLEND_RAMP_UP_TIME_RANGE_MIN (1)
#define PROP_HD_BLEND_BWM_BLEND_RAMP_UP_TIME_BWM_BLEND_RAMP_UP_TIME_RANGE_MAX (32767)
#define PROP_HD_BLEND_BWM_BLEND_RAMP_UP_TIME_DEFAULT 400

#define PROP_HD_BLEND_BWM_BLEND_RAMP_DOWN_TIME_MASK 0xFFFF
#define PROP_HD_BLEND_BWM_BLEND_RAMP_DOWN_TIME_INDEX 0x27
#define PROP_HD_BLEND_BWM_BLEND_RAMP_DOWN_TIME_GROUP 0x91
#define PROP_HD_BLEND_BWM_BLEND_RAMP_DOWN_TIME_value() (sys_prop_ReturnProperty(PROP_HD_BLEND_BWM_BLEND_RAMP_DOWN_TIME_GROUP, PROP_HD_BLEND_BWM_BLEND_RAMP_DOWN_TIME_INDEX))
#define PROP_HD_BLEND_BWM_BLEND_RAMP_DOWN_TIME_BWM_BLEND_RAMP_DOWN_TIME_LSB 0
#define PROP_HD_BLEND_BWM_BLEND_RAMP_DOWN_TIME_BWM_BLEND_RAMP_DOWN_TIME_MSB 15
#define PROP_HD_BLEND_BWM_BLEND_RAMP_DOWN_TIME_BWM_BLEND_RAMP_DOWN_TIME_MASK 0xFFFF
#define PROP_HD_BLEND_BWM_BLEND_RAMP_DOWN_TIME_BWM_BLEND_RAMP_DOWN_TIME_value() (((PROP_HD_BLEND_BWM_BLEND_RAMP_DOWN_TIME_value()) & 0xFFFF)>>0)
#define PROP_HD_BLEND_BWM_BLEND_RAMP_DOWN_TIME_BWM_BLEND_RAMP_DOWN_TIME_RANGE_MIN (1)
#define PROP_HD_BLEND_BWM_BLEND_RAMP_DOWN_TIME_BWM_BLEND_RAMP_DOWN_TIME_RANGE_MAX (32767)
#define PROP_HD_BLEND_BWM_BLEND_RAMP_DOWN_TIME_DEFAULT 16

#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_MASK 0xFFFF
#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_INDEX 0x00
#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_GROUP 0x92
#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_value() (sys_prop_ReturnProperty(PROP_HD_DIGRAD_INTERRUPT_SOURCE_GROUP, PROP_HD_DIGRAD_INTERRUPT_SOURCE_INDEX))
#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_HDLOGOINTEN_LSB 7
#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_HDLOGOINTEN_MSB 7
#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_HDLOGOINTEN_MASK 0x80
#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_HDLOGOINTEN_BIT 0x80
#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_HDLOGOINTEN_value() (((PROP_HD_DIGRAD_INTERRUPT_SOURCE_value()) & 0x80)>>7)
#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_SRCANAINTEN_LSB 6
#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_SRCANAINTEN_MSB 6
#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_SRCANAINTEN_MASK 0x40
#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_SRCANAINTEN_BIT 0x40
#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_SRCANAINTEN_value() (((PROP_HD_DIGRAD_INTERRUPT_SOURCE_value()) & 0x40)>>6)
#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_SRCDIGINTEN_LSB 5
#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_SRCDIGINTEN_MSB 5
#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_SRCDIGINTEN_MASK 0x20
#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_SRCDIGINTEN_BIT 0x20
#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_SRCDIGINTEN_value() (((PROP_HD_DIGRAD_INTERRUPT_SOURCE_value()) & 0x20)>>5)
#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_AUDACQINTEN_LSB 3
#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_AUDACQINTEN_MSB 3
#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_AUDACQINTEN_MASK 0x8
#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_AUDACQINTEN_BIT 0x8
#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_AUDACQINTEN_value() (((PROP_HD_DIGRAD_INTERRUPT_SOURCE_value()) & 0x8)>>3)
#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_ACQINTEN_LSB 2
#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_ACQINTEN_MSB 2
#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_ACQINTEN_MASK 0x4
#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_ACQINTEN_BIT 0x4
#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_ACQINTEN_value() (((PROP_HD_DIGRAD_INTERRUPT_SOURCE_value()) & 0x4)>>2)
#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_CDNRHINTEN_LSB 1
#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_CDNRHINTEN_MSB 1
#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_CDNRHINTEN_MASK 0x2
#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_CDNRHINTEN_BIT 0x2
#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_CDNRHINTEN_value() (((PROP_HD_DIGRAD_INTERRUPT_SOURCE_value()) & 0x2)>>1)
#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_CDNRLINTEN_LSB 0
#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_CDNRLINTEN_MSB 0
#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_CDNRLINTEN_MASK 0x1
#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_CDNRLINTEN_BIT 0x1
#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_CDNRLINTEN_value() (((PROP_HD_DIGRAD_INTERRUPT_SOURCE_value()) & 0x1)>>0)
#define PROP_HD_DIGRAD_INTERRUPT_SOURCE_DEFAULT 0

#define PROP_HD_DIGRAD_CDNR_LOW_THRESHOLD_MASK 0xFFFF
#define PROP_HD_DIGRAD_CDNR_LOW_THRESHOLD_INDEX 0x01
#define PROP_HD_DIGRAD_CDNR_LOW_THRESHOLD_GROUP 0x92
#define PROP_HD_DIGRAD_CDNR_LOW_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_HD_DIGRAD_CDNR_LOW_THRESHOLD_GROUP, PROP_HD_DIGRAD_CDNR_LOW_THRESHOLD_INDEX))
#define PROP_HD_DIGRAD_CDNR_LOW_THRESHOLD_CDNR_LOW_THRESHOLD_LSB 0
#define PROP_HD_DIGRAD_CDNR_LOW_THRESHOLD_CDNR_LOW_THRESHOLD_MSB 15
#define PROP_HD_DIGRAD_CDNR_LOW_THRESHOLD_CDNR_LOW_THRESHOLD_MASK 0xFFFF
#define PROP_HD_DIGRAD_CDNR_LOW_THRESHOLD_CDNR_LOW_THRESHOLD_value() (((PROP_HD_DIGRAD_CDNR_LOW_THRESHOLD_value()) & 0xFFFF)>>0)
#define PROP_HD_DIGRAD_CDNR_LOW_THRESHOLD_DEFAULT 0

#define PROP_HD_DIGRAD_CDNR_HIGH_THRESHOLD_MASK 0xFFFF
#define PROP_HD_DIGRAD_CDNR_HIGH_THRESHOLD_INDEX 0x02
#define PROP_HD_DIGRAD_CDNR_HIGH_THRESHOLD_GROUP 0x92
#define PROP_HD_DIGRAD_CDNR_HIGH_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_HD_DIGRAD_CDNR_HIGH_THRESHOLD_GROUP, PROP_HD_DIGRAD_CDNR_HIGH_THRESHOLD_INDEX))
#define PROP_HD_DIGRAD_CDNR_HIGH_THRESHOLD_CDNR_HIGH_THRESHOLD_LSB 0
#define PROP_HD_DIGRAD_CDNR_HIGH_THRESHOLD_CDNR_HIGH_THRESHOLD_MSB 15
#define PROP_HD_DIGRAD_CDNR_HIGH_THRESHOLD_CDNR_HIGH_THRESHOLD_MASK 0xFFFF
#define PROP_HD_DIGRAD_CDNR_HIGH_THRESHOLD_CDNR_HIGH_THRESHOLD_value() (((PROP_HD_DIGRAD_CDNR_HIGH_THRESHOLD_value()) & 0xFFFF)>>0)
#define PROP_HD_DIGRAD_CDNR_HIGH_THRESHOLD_DEFAULT 127

#define PROP_HD_EVENT_INTERRUPT_SOURCE_MASK 0xFFFF
#define PROP_HD_EVENT_INTERRUPT_SOURCE_INDEX 0x00
#define PROP_HD_EVENT_INTERRUPT_SOURCE_GROUP 0x93
#define PROP_HD_EVENT_INTERRUPT_SOURCE_value() (sys_prop_ReturnProperty(PROP_HD_EVENT_INTERRUPT_SOURCE_GROUP, PROP_HD_EVENT_INTERRUPT_SOURCE_INDEX))
#define PROP_HD_EVENT_INTERRUPT_SOURCE_DINFO_INTEN_LSB 7
#define PROP_HD_EVENT_INTERRUPT_SOURCE_DINFO_INTEN_MSB 7
#define PROP_HD_EVENT_INTERRUPT_SOURCE_DINFO_INTEN_MASK 0x80
#define PROP_HD_EVENT_INTERRUPT_SOURCE_DINFO_INTEN_BIT 0x80
#define PROP_HD_EVENT_INTERRUPT_SOURCE_DINFO_INTEN_value() (((PROP_HD_EVENT_INTERRUPT_SOURCE_value()) & 0x80)>>7)
#define PROP_HD_EVENT_INTERRUPT_SOURCE_AINFO_INTEN_LSB 6
#define PROP_HD_EVENT_INTERRUPT_SOURCE_AINFO_INTEN_MSB 6
#define PROP_HD_EVENT_INTERRUPT_SOURCE_AINFO_INTEN_MASK 0x40
#define PROP_HD_EVENT_INTERRUPT_SOURCE_AINFO_INTEN_BIT 0x40
#define PROP_HD_EVENT_INTERRUPT_SOURCE_AINFO_INTEN_value() (((PROP_HD_EVENT_INTERRUPT_SOURCE_value()) & 0x40)>>6)
#define PROP_HD_EVENT_INTERRUPT_SOURCE_ALERT_INTEN_LSB 4
#define PROP_HD_EVENT_INTERRUPT_SOURCE_ALERT_INTEN_MSB 4
#define PROP_HD_EVENT_INTERRUPT_SOURCE_ALERT_INTEN_MASK 0x10
#define PROP_HD_EVENT_INTERRUPT_SOURCE_ALERT_INTEN_BIT 0x10
#define PROP_HD_EVENT_INTERRUPT_SOURCE_ALERT_INTEN_value() (((PROP_HD_EVENT_INTERRUPT_SOURCE_value()) & 0x10)>>4)
#define PROP_HD_EVENT_INTERRUPT_SOURCE_PSD_INTEN_LSB 3
#define PROP_HD_EVENT_INTERRUPT_SOURCE_PSD_INTEN_MSB 3
#define PROP_HD_EVENT_INTERRUPT_SOURCE_PSD_INTEN_MASK 0x8
#define PROP_HD_EVENT_INTERRUPT_SOURCE_PSD_INTEN_BIT 0x8
#define PROP_HD_EVENT_INTERRUPT_SOURCE_PSD_INTEN_value() (((PROP_HD_EVENT_INTERRUPT_SOURCE_value()) & 0x8)>>3)
#define PROP_HD_EVENT_INTERRUPT_SOURCE_SIS_INTEN_LSB 2
#define PROP_HD_EVENT_INTERRUPT_SOURCE_SIS_INTEN_MSB 2
#define PROP_HD_EVENT_INTERRUPT_SOURCE_SIS_INTEN_MASK 0x4
#define PROP_HD_EVENT_INTERRUPT_SOURCE_SIS_INTEN_BIT 0x4
#define PROP_HD_EVENT_INTERRUPT_SOURCE_SIS_INTEN_value() (((PROP_HD_EVENT_INTERRUPT_SOURCE_value()) & 0x4)>>2)
#define PROP_HD_EVENT_INTERRUPT_SOURCE_DSRVLIST_INTEN_LSB 1
#define PROP_HD_EVENT_INTERRUPT_SOURCE_DSRVLIST_INTEN_MSB 1
#define PROP_HD_EVENT_INTERRUPT_SOURCE_DSRVLIST_INTEN_MASK 0x2
#define PROP_HD_EVENT_INTERRUPT_SOURCE_DSRVLIST_INTEN_BIT 0x2
#define PROP_HD_EVENT_INTERRUPT_SOURCE_DSRVLIST_INTEN_value() (((PROP_HD_EVENT_INTERRUPT_SOURCE_value()) & 0x2)>>1)
#define PROP_HD_EVENT_INTERRUPT_SOURCE_ASRVLIST_INTEN_LSB 0
#define PROP_HD_EVENT_INTERRUPT_SOURCE_ASRVLIST_INTEN_MSB 0
#define PROP_HD_EVENT_INTERRUPT_SOURCE_ASRVLIST_INTEN_MASK 0x1
#define PROP_HD_EVENT_INTERRUPT_SOURCE_ASRVLIST_INTEN_BIT 0x1
#define PROP_HD_EVENT_INTERRUPT_SOURCE_ASRVLIST_INTEN_value() (((PROP_HD_EVENT_INTERRUPT_SOURCE_value()) & 0x1)>>0)
#define PROP_HD_EVENT_INTERRUPT_SOURCE_DEFAULT 0

#define PROP_HD_EVENT_SIS_CONFIG_MASK 0xFFFF
#define PROP_HD_EVENT_SIS_CONFIG_INDEX 0x01
#define PROP_HD_EVENT_SIS_CONFIG_GROUP 0x93
#define PROP_HD_EVENT_SIS_CONFIG_value() (sys_prop_ReturnProperty(PROP_HD_EVENT_SIS_CONFIG_GROUP, PROP_HD_EVENT_SIS_CONFIG_INDEX))
#define PROP_HD_EVENT_SIS_CONFIG_LOCATION_LSB 4
#define PROP_HD_EVENT_SIS_CONFIG_LOCATION_MSB 4
#define PROP_HD_EVENT_SIS_CONFIG_LOCATION_MASK 0x10
#define PROP_HD_EVENT_SIS_CONFIG_LOCATION_BIT 0x10
#define PROP_HD_EVENT_SIS_CONFIG_LOCATION_value() (((PROP_HD_EVENT_SIS_CONFIG_value()) & 0x10)>>4)
#define PROP_HD_EVENT_SIS_CONFIG_RSVD_LSB 3
#define PROP_HD_EVENT_SIS_CONFIG_RSVD_MSB 3
#define PROP_HD_EVENT_SIS_CONFIG_RSVD_MASK 0x8
#define PROP_HD_EVENT_SIS_CONFIG_RSVD_BIT 0x8
#define PROP_HD_EVENT_SIS_CONFIG_RSVD_value() (((PROP_HD_EVENT_SIS_CONFIG_value()) & 0x8)>>3)
#define PROP_HD_EVENT_SIS_CONFIG_NAME_LF_LSB 2
#define PROP_HD_EVENT_SIS_CONFIG_NAME_LF_MSB 2
#define PROP_HD_EVENT_SIS_CONFIG_NAME_LF_MASK 0x4
#define PROP_HD_EVENT_SIS_CONFIG_NAME_LF_BIT 0x4
#define PROP_HD_EVENT_SIS_CONFIG_NAME_LF_value() (((PROP_HD_EVENT_SIS_CONFIG_value()) & 0x4)>>2)
#define PROP_HD_EVENT_SIS_CONFIG_NAME_SF_LSB 1
#define PROP_HD_EVENT_SIS_CONFIG_NAME_SF_MSB 1
#define PROP_HD_EVENT_SIS_CONFIG_NAME_SF_MASK 0x2
#define PROP_HD_EVENT_SIS_CONFIG_NAME_SF_BIT 0x2
#define PROP_HD_EVENT_SIS_CONFIG_NAME_SF_value() (((PROP_HD_EVENT_SIS_CONFIG_value()) & 0x2)>>1)
#define PROP_HD_EVENT_SIS_CONFIG_ID_LSB 0
#define PROP_HD_EVENT_SIS_CONFIG_ID_MSB 0
#define PROP_HD_EVENT_SIS_CONFIG_ID_MASK 0x1
#define PROP_HD_EVENT_SIS_CONFIG_ID_BIT 0x1
#define PROP_HD_EVENT_SIS_CONFIG_ID_value() (((PROP_HD_EVENT_SIS_CONFIG_value()) & 0x1)>>0)
#define PROP_HD_EVENT_SIS_CONFIG_DEFAULT 0x0017

#define PROP_HD_EVENT_ALERT_CONFIG_MASK 0xFFFF
#define PROP_HD_EVENT_ALERT_CONFIG_INDEX 0x02
#define PROP_HD_EVENT_ALERT_CONFIG_GROUP 0x93
#define PROP_HD_EVENT_ALERT_CONFIG_value() (sys_prop_ReturnProperty(PROP_HD_EVENT_ALERT_CONFIG_GROUP, PROP_HD_EVENT_ALERT_CONFIG_INDEX))
#define PROP_HD_EVENT_ALERT_CONFIG_PLAY_TONE_LSB 1
#define PROP_HD_EVENT_ALERT_CONFIG_PLAY_TONE_MSB 1
#define PROP_HD_EVENT_ALERT_CONFIG_PLAY_TONE_MASK 0x2
#define PROP_HD_EVENT_ALERT_CONFIG_PLAY_TONE_BIT 0x2
#define PROP_HD_EVENT_ALERT_CONFIG_PLAY_TONE_value() (((PROP_HD_EVENT_ALERT_CONFIG_value()) & 0x2)>>1)
#define PROP_HD_EVENT_ALERT_CONFIG_ENABLE_LSB 0
#define PROP_HD_EVENT_ALERT_CONFIG_ENABLE_MSB 0
#define PROP_HD_EVENT_ALERT_CONFIG_ENABLE_MASK 0x1
#define PROP_HD_EVENT_ALERT_CONFIG_ENABLE_BIT 0x1
#define PROP_HD_EVENT_ALERT_CONFIG_ENABLE_value() (((PROP_HD_EVENT_ALERT_CONFIG_value()) & 0x1)>>0)
#define PROP_HD_EVENT_ALERT_CONFIG_DEFAULT 0x0001

#define PROP_HD_ACF_INTERRUPT_SOURCE_MASK 0xFFFF
#define PROP_HD_ACF_INTERRUPT_SOURCE_INDEX 0x00
#define PROP_HD_ACF_INTERRUPT_SOURCE_GROUP 0x94
#define PROP_HD_ACF_INTERRUPT_SOURCE_value() (sys_prop_ReturnProperty(PROP_HD_ACF_INTERRUPT_SOURCE_GROUP, PROP_HD_ACF_INTERRUPT_SOURCE_INDEX))
#define PROP_HD_ACF_INTERRUPT_SOURCE_STEREO_SEP_INTEN_LSB 2
#define PROP_HD_ACF_INTERRUPT_SOURCE_STEREO_SEP_INTEN_MSB 2
#define PROP_HD_ACF_INTERRUPT_SOURCE_STEREO_SEP_INTEN_MASK 0x4
#define PROP_HD_ACF_INTERRUPT_SOURCE_STEREO_SEP_INTEN_BIT 0x4
#define PROP_HD_ACF_INTERRUPT_SOURCE_STEREO_SEP_INTEN_value() (((PROP_HD_ACF_INTERRUPT_SOURCE_value()) & 0x4)>>2)
#define PROP_HD_ACF_INTERRUPT_SOURCE_AUDIO_BW_INTEN_LSB 1
#define PROP_HD_ACF_INTERRUPT_SOURCE_AUDIO_BW_INTEN_MSB 1
#define PROP_HD_ACF_INTERRUPT_SOURCE_AUDIO_BW_INTEN_MASK 0x2
#define PROP_HD_ACF_INTERRUPT_SOURCE_AUDIO_BW_INTEN_BIT 0x2
#define PROP_HD_ACF_INTERRUPT_SOURCE_AUDIO_BW_INTEN_value() (((PROP_HD_ACF_INTERRUPT_SOURCE_value()) & 0x2)>>1)
#define PROP_HD_ACF_INTERRUPT_SOURCE_COMF_NOISE_INTEN_LSB 0
#define PROP_HD_ACF_INTERRUPT_SOURCE_COMF_NOISE_INTEN_MSB 0
#define PROP_HD_ACF_INTERRUPT_SOURCE_COMF_NOISE_INTEN_MASK 0x1
#define PROP_HD_ACF_INTERRUPT_SOURCE_COMF_NOISE_INTEN_BIT 0x1
#define PROP_HD_ACF_INTERRUPT_SOURCE_COMF_NOISE_INTEN_value() (((PROP_HD_ACF_INTERRUPT_SOURCE_value()) & 0x1)>>0)
#define PROP_HD_ACF_INTERRUPT_SOURCE_DEFAULT 0

#define PROP_HD_ACF_COMF_NOISE_THRESHOLD_MASK 0xFFFF
#define PROP_HD_ACF_COMF_NOISE_THRESHOLD_INDEX 0x01
#define PROP_HD_ACF_COMF_NOISE_THRESHOLD_GROUP 0x94
#define PROP_HD_ACF_COMF_NOISE_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_HD_ACF_COMF_NOISE_THRESHOLD_GROUP, PROP_HD_ACF_COMF_NOISE_THRESHOLD_INDEX))
#define PROP_HD_ACF_COMF_NOISE_THRESHOLD_COMF_NOISE_THRESH_LSB 0
#define PROP_HD_ACF_COMF_NOISE_THRESHOLD_COMF_NOISE_THRESH_MSB 15
#define PROP_HD_ACF_COMF_NOISE_THRESHOLD_COMF_NOISE_THRESH_MASK 0xFFFF
#define PROP_HD_ACF_COMF_NOISE_THRESHOLD_COMF_NOISE_THRESH_value() (((PROP_HD_ACF_COMF_NOISE_THRESHOLD_value()) & 0xFFFF)>>0)
#define PROP_HD_ACF_COMF_NOISE_THRESHOLD_COMF_NOISE_THRESH_RANGE_MIN (0)
#define PROP_HD_ACF_COMF_NOISE_THRESHOLD_COMF_NOISE_THRESH_RANGE_MAX (16383)
#define PROP_HD_ACF_COMF_NOISE_THRESHOLD_DEFAULT 512

#define PROP_HD_ACF_AUDIO_BW_THRESHOLD_MASK 0xFFFF
#define PROP_HD_ACF_AUDIO_BW_THRESHOLD_INDEX 0x02
#define PROP_HD_ACF_AUDIO_BW_THRESHOLD_GROUP 0x94
#define PROP_HD_ACF_AUDIO_BW_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_HD_ACF_AUDIO_BW_THRESHOLD_GROUP, PROP_HD_ACF_AUDIO_BW_THRESHOLD_INDEX))
#define PROP_HD_ACF_AUDIO_BW_THRESHOLD_AUDIO_BW_THRESH_LSB 0
#define PROP_HD_ACF_AUDIO_BW_THRESHOLD_AUDIO_BW_THRESH_MSB 7
#define PROP_HD_ACF_AUDIO_BW_THRESHOLD_AUDIO_BW_THRESH_MASK 0xFF
#define PROP_HD_ACF_AUDIO_BW_THRESHOLD_AUDIO_BW_THRESH_value() (((PROP_HD_ACF_AUDIO_BW_THRESHOLD_value()) & 0xFF)>>0)
#define PROP_HD_ACF_AUDIO_BW_THRESHOLD_AUDIO_BW_THRESH_RANGE_MIN (0)
#define PROP_HD_ACF_AUDIO_BW_THRESHOLD_AUDIO_BW_THRESH_RANGE_MAX (150)
#define PROP_HD_ACF_AUDIO_BW_THRESHOLD_DEFAULT 40

#define PROP_HD_ACF_STEREO_SEP_THRESHOLD_MASK 0xFFFF
#define PROP_HD_ACF_STEREO_SEP_THRESHOLD_INDEX 0x03
#define PROP_HD_ACF_STEREO_SEP_THRESHOLD_GROUP 0x94
#define PROP_HD_ACF_STEREO_SEP_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_HD_ACF_STEREO_SEP_THRESHOLD_GROUP, PROP_HD_ACF_STEREO_SEP_THRESHOLD_INDEX))
#define PROP_HD_ACF_STEREO_SEP_THRESHOLD_STEREO_SEP_THRESH_LSB 0
#define PROP_HD_ACF_STEREO_SEP_THRESHOLD_STEREO_SEP_THRESH_MSB 7
#define PROP_HD_ACF_STEREO_SEP_THRESHOLD_STEREO_SEP_THRESH_MASK 0xFF
#define PROP_HD_ACF_STEREO_SEP_THRESHOLD_STEREO_SEP_THRESH_value() (((PROP_HD_ACF_STEREO_SEP_THRESHOLD_value()) & 0xFF)>>0)
#define PROP_HD_ACF_STEREO_SEP_THRESHOLD_STEREO_SEP_THRESH_RANGE_MIN (0)
#define PROP_HD_ACF_STEREO_SEP_THRESHOLD_STEREO_SEP_THRESH_RANGE_MAX (127)
#define PROP_HD_ACF_STEREO_SEP_THRESHOLD_DEFAULT 0

#define PROP_HD_ACF_COMF_NOISE_TOLERANCE_MASK 0xFFFF
#define PROP_HD_ACF_COMF_NOISE_TOLERANCE_INDEX 0x04
#define PROP_HD_ACF_COMF_NOISE_TOLERANCE_GROUP 0x94
#define PROP_HD_ACF_COMF_NOISE_TOLERANCE_value() (sys_prop_ReturnProperty(PROP_HD_ACF_COMF_NOISE_TOLERANCE_GROUP, PROP_HD_ACF_COMF_NOISE_TOLERANCE_INDEX))
#define PROP_HD_ACF_COMF_NOISE_TOLERANCE_COMF_NOISE_TOL_LSB 0
#define PROP_HD_ACF_COMF_NOISE_TOLERANCE_COMF_NOISE_TOL_MSB 15
#define PROP_HD_ACF_COMF_NOISE_TOLERANCE_COMF_NOISE_TOL_MASK 0xFFFF
#define PROP_HD_ACF_COMF_NOISE_TOLERANCE_COMF_NOISE_TOL_value() (((PROP_HD_ACF_COMF_NOISE_TOLERANCE_value()) & 0xFFFF)>>0)
#define PROP_HD_ACF_COMF_NOISE_TOLERANCE_COMF_NOISE_TOL_RANGE_MIN (0)
#define PROP_HD_ACF_COMF_NOISE_TOLERANCE_COMF_NOISE_TOL_RANGE_MAX (100)
#define PROP_HD_ACF_COMF_NOISE_TOLERANCE_DEFAULT 5

#define PROP_HD_ACF_AUDIO_BW_TOLERANCE_MASK 0xFFFF
#define PROP_HD_ACF_AUDIO_BW_TOLERANCE_INDEX 0x05
#define PROP_HD_ACF_AUDIO_BW_TOLERANCE_GROUP 0x94
#define PROP_HD_ACF_AUDIO_BW_TOLERANCE_value() (sys_prop_ReturnProperty(PROP_HD_ACF_AUDIO_BW_TOLERANCE_GROUP, PROP_HD_ACF_AUDIO_BW_TOLERANCE_INDEX))
#define PROP_HD_ACF_AUDIO_BW_TOLERANCE_BW_TOL_LSB 0
#define PROP_HD_ACF_AUDIO_BW_TOLERANCE_BW_TOL_MSB 7
#define PROP_HD_ACF_AUDIO_BW_TOLERANCE_BW_TOL_MASK 0xFF
#define PROP_HD_ACF_AUDIO_BW_TOLERANCE_BW_TOL_value() (((PROP_HD_ACF_AUDIO_BW_TOLERANCE_value()) & 0xFF)>>0)
#define PROP_HD_ACF_AUDIO_BW_TOLERANCE_BW_TOL_RANGE_MIN (0)
#define PROP_HD_ACF_AUDIO_BW_TOLERANCE_BW_TOL_RANGE_MAX (100)
#define PROP_HD_ACF_AUDIO_BW_TOLERANCE_DEFAULT 2

#define PROP_HD_ACF_STEREO_SEP_TOLERANCE_MASK 0xFFFF
#define PROP_HD_ACF_STEREO_SEP_TOLERANCE_INDEX 0x06
#define PROP_HD_ACF_STEREO_SEP_TOLERANCE_GROUP 0x94
#define PROP_HD_ACF_STEREO_SEP_TOLERANCE_value() (sys_prop_ReturnProperty(PROP_HD_ACF_STEREO_SEP_TOLERANCE_GROUP, PROP_HD_ACF_STEREO_SEP_TOLERANCE_INDEX))
#define PROP_HD_ACF_STEREO_SEP_TOLERANCE_STEREO_SEP_TOL_LSB 0
#define PROP_HD_ACF_STEREO_SEP_TOLERANCE_STEREO_SEP_TOL_MSB 7
#define PROP_HD_ACF_STEREO_SEP_TOLERANCE_STEREO_SEP_TOL_MASK 0xFF
#define PROP_HD_ACF_STEREO_SEP_TOLERANCE_STEREO_SEP_TOL_value() (((PROP_HD_ACF_STEREO_SEP_TOLERANCE_value()) & 0xFF)>>0)
#define PROP_HD_ACF_STEREO_SEP_TOLERANCE_STEREO_SEP_TOL_RANGE_MIN (0)
#define PROP_HD_ACF_STEREO_SEP_TOLERANCE_STEREO_SEP_TOL_RANGE_MAX (100)
#define PROP_HD_ACF_STEREO_SEP_TOLERANCE_DEFAULT 5

#define PROP_HD_PSD_ENABLE_MASK 0xFFFF
#define PROP_HD_PSD_ENABLE_INDEX 0x00
#define PROP_HD_PSD_ENABLE_GROUP 0x95
#define PROP_HD_PSD_ENABLE_value() (sys_prop_ReturnProperty(PROP_HD_PSD_ENABLE_GROUP, PROP_HD_PSD_ENABLE_INDEX))
#define PROP_HD_PSD_ENABLE_ASPS7_LSB 15
#define PROP_HD_PSD_ENABLE_ASPS7_MSB 15
#define PROP_HD_PSD_ENABLE_ASPS7_MASK 0x8000
#define PROP_HD_PSD_ENABLE_ASPS7_BIT 0x8000
#define PROP_HD_PSD_ENABLE_ASPS7_value() (((PROP_HD_PSD_ENABLE_value()) & 0x8000)>>15)
#define PROP_HD_PSD_ENABLE_ASPS6_LSB 14
#define PROP_HD_PSD_ENABLE_ASPS6_MSB 14
#define PROP_HD_PSD_ENABLE_ASPS6_MASK 0x4000
#define PROP_HD_PSD_ENABLE_ASPS6_BIT 0x4000
#define PROP_HD_PSD_ENABLE_ASPS6_value() (((PROP_HD_PSD_ENABLE_value()) & 0x4000)>>14)
#define PROP_HD_PSD_ENABLE_ASPS5_LSB 13
#define PROP_HD_PSD_ENABLE_ASPS5_MSB 13
#define PROP_HD_PSD_ENABLE_ASPS5_MASK 0x2000
#define PROP_HD_PSD_ENABLE_ASPS5_BIT 0x2000
#define PROP_HD_PSD_ENABLE_ASPS5_value() (((PROP_HD_PSD_ENABLE_value()) & 0x2000)>>13)
#define PROP_HD_PSD_ENABLE_ASPS4_LSB 12
#define PROP_HD_PSD_ENABLE_ASPS4_MSB 12
#define PROP_HD_PSD_ENABLE_ASPS4_MASK 0x1000
#define PROP_HD_PSD_ENABLE_ASPS4_BIT 0x1000
#define PROP_HD_PSD_ENABLE_ASPS4_value() (((PROP_HD_PSD_ENABLE_value()) & 0x1000)>>12)
#define PROP_HD_PSD_ENABLE_ASPS3_LSB 11
#define PROP_HD_PSD_ENABLE_ASPS3_MSB 11
#define PROP_HD_PSD_ENABLE_ASPS3_MASK 0x800
#define PROP_HD_PSD_ENABLE_ASPS3_BIT 0x800
#define PROP_HD_PSD_ENABLE_ASPS3_value() (((PROP_HD_PSD_ENABLE_value()) & 0x800)>>11)
#define PROP_HD_PSD_ENABLE_ASPS2_LSB 10
#define PROP_HD_PSD_ENABLE_ASPS2_MSB 10
#define PROP_HD_PSD_ENABLE_ASPS2_MASK 0x400
#define PROP_HD_PSD_ENABLE_ASPS2_BIT 0x400
#define PROP_HD_PSD_ENABLE_ASPS2_value() (((PROP_HD_PSD_ENABLE_value()) & 0x400)>>10)
#define PROP_HD_PSD_ENABLE_ASPS1_LSB 9
#define PROP_HD_PSD_ENABLE_ASPS1_MSB 9
#define PROP_HD_PSD_ENABLE_ASPS1_MASK 0x200
#define PROP_HD_PSD_ENABLE_ASPS1_BIT 0x200
#define PROP_HD_PSD_ENABLE_ASPS1_value() (((PROP_HD_PSD_ENABLE_value()) & 0x200)>>9)
#define PROP_HD_PSD_ENABLE_AMPS_LSB 8
#define PROP_HD_PSD_ENABLE_AMPS_MSB 8
#define PROP_HD_PSD_ENABLE_AMPS_MASK 0x100
#define PROP_HD_PSD_ENABLE_AMPS_BIT 0x100
#define PROP_HD_PSD_ENABLE_AMPS_value() (((PROP_HD_PSD_ENABLE_value()) & 0x100)>>8)
#define PROP_HD_PSD_ENABLE_SPS7_LSB 7
#define PROP_HD_PSD_ENABLE_SPS7_MSB 7
#define PROP_HD_PSD_ENABLE_SPS7_MASK 0x80
#define PROP_HD_PSD_ENABLE_SPS7_BIT 0x80
#define PROP_HD_PSD_ENABLE_SPS7_value() (((PROP_HD_PSD_ENABLE_value()) & 0x80)>>7)
#define PROP_HD_PSD_ENABLE_SPS6_LSB 6
#define PROP_HD_PSD_ENABLE_SPS6_MSB 6
#define PROP_HD_PSD_ENABLE_SPS6_MASK 0x40
#define PROP_HD_PSD_ENABLE_SPS6_BIT 0x40
#define PROP_HD_PSD_ENABLE_SPS6_value() (((PROP_HD_PSD_ENABLE_value()) & 0x40)>>6)
#define PROP_HD_PSD_ENABLE_SPS5_LSB 5
#define PROP_HD_PSD_ENABLE_SPS5_MSB 5
#define PROP_HD_PSD_ENABLE_SPS5_MASK 0x20
#define PROP_HD_PSD_ENABLE_SPS5_BIT 0x20
#define PROP_HD_PSD_ENABLE_SPS5_value() (((PROP_HD_PSD_ENABLE_value()) & 0x20)>>5)
#define PROP_HD_PSD_ENABLE_SPS4_LSB 4
#define PROP_HD_PSD_ENABLE_SPS4_MSB 4
#define PROP_HD_PSD_ENABLE_SPS4_MASK 0x10
#define PROP_HD_PSD_ENABLE_SPS4_BIT 0x10
#define PROP_HD_PSD_ENABLE_SPS4_value() (((PROP_HD_PSD_ENABLE_value()) & 0x10)>>4)
#define PROP_HD_PSD_ENABLE_SPS3_LSB 3
#define PROP_HD_PSD_ENABLE_SPS3_MSB 3
#define PROP_HD_PSD_ENABLE_SPS3_MASK 0x8
#define PROP_HD_PSD_ENABLE_SPS3_BIT 0x8
#define PROP_HD_PSD_ENABLE_SPS3_value() (((PROP_HD_PSD_ENABLE_value()) & 0x8)>>3)
#define PROP_HD_PSD_ENABLE_SPS2_LSB 2
#define PROP_HD_PSD_ENABLE_SPS2_MSB 2
#define PROP_HD_PSD_ENABLE_SPS2_MASK 0x4
#define PROP_HD_PSD_ENABLE_SPS2_BIT 0x4
#define PROP_HD_PSD_ENABLE_SPS2_value() (((PROP_HD_PSD_ENABLE_value()) & 0x4)>>2)
#define PROP_HD_PSD_ENABLE_SPS1_LSB 1
#define PROP_HD_PSD_ENABLE_SPS1_MSB 1
#define PROP_HD_PSD_ENABLE_SPS1_MASK 0x2
#define PROP_HD_PSD_ENABLE_SPS1_BIT 0x2
#define PROP_HD_PSD_ENABLE_SPS1_value() (((PROP_HD_PSD_ENABLE_value()) & 0x2)>>1)
#define PROP_HD_PSD_ENABLE_MPS_LSB 0
#define PROP_HD_PSD_ENABLE_MPS_MSB 0
#define PROP_HD_PSD_ENABLE_MPS_MASK 0x1
#define PROP_HD_PSD_ENABLE_MPS_BIT 0x1
#define PROP_HD_PSD_ENABLE_MPS_value() (((PROP_HD_PSD_ENABLE_value()) & 0x1)>>0)
#define PROP_HD_PSD_ENABLE_DEFAULT 0

#define PROP_HD_PSD_FIELD_MASK_MASK 0xFFFF
#define PROP_HD_PSD_FIELD_MASK_INDEX 0x01
#define PROP_HD_PSD_FIELD_MASK_GROUP 0x95
#define PROP_HD_PSD_FIELD_MASK_value() (sys_prop_ReturnProperty(PROP_HD_PSD_FIELD_MASK_GROUP, PROP_HD_PSD_FIELD_MASK_INDEX))
#define PROP_HD_PSD_FIELD_MASK_ID_LSB 15
#define PROP_HD_PSD_FIELD_MASK_ID_MSB 15
#define PROP_HD_PSD_FIELD_MASK_ID_MASK 0x8000
#define PROP_HD_PSD_FIELD_MASK_ID_BIT 0x8000
#define PROP_HD_PSD_FIELD_MASK_ID_value() (((PROP_HD_PSD_FIELD_MASK_value()) & 0x8000)>>15)
#define PROP_HD_PSD_FIELD_MASK_OWNER_LSB 14
#define PROP_HD_PSD_FIELD_MASK_OWNER_MSB 14
#define PROP_HD_PSD_FIELD_MASK_OWNER_MASK 0x4000
#define PROP_HD_PSD_FIELD_MASK_OWNER_BIT 0x4000
#define PROP_HD_PSD_FIELD_MASK_OWNER_value() (((PROP_HD_PSD_FIELD_MASK_value()) & 0x4000)>>14)
#define PROP_HD_PSD_FIELD_MASK_DESC_LSB 13
#define PROP_HD_PSD_FIELD_MASK_DESC_MSB 13
#define PROP_HD_PSD_FIELD_MASK_DESC_MASK 0x2000
#define PROP_HD_PSD_FIELD_MASK_DESC_BIT 0x2000
#define PROP_HD_PSD_FIELD_MASK_DESC_value() (((PROP_HD_PSD_FIELD_MASK_value()) & 0x2000)>>13)
#define PROP_HD_PSD_FIELD_MASK_NAME_LSB 12
#define PROP_HD_PSD_FIELD_MASK_NAME_MSB 12
#define PROP_HD_PSD_FIELD_MASK_NAME_MASK 0x1000
#define PROP_HD_PSD_FIELD_MASK_NAME_BIT 0x1000
#define PROP_HD_PSD_FIELD_MASK_NAME_value() (((PROP_HD_PSD_FIELD_MASK_value()) & 0x1000)>>12)
#define PROP_HD_PSD_FIELD_MASK_RECV_LSB 11
#define PROP_HD_PSD_FIELD_MASK_RECV_MSB 11
#define PROP_HD_PSD_FIELD_MASK_RECV_MASK 0x800
#define PROP_HD_PSD_FIELD_MASK_RECV_BIT 0x800
#define PROP_HD_PSD_FIELD_MASK_RECV_value() (((PROP_HD_PSD_FIELD_MASK_value()) & 0x800)>>11)
#define PROP_HD_PSD_FIELD_MASK_URL_LSB 10
#define PROP_HD_PSD_FIELD_MASK_URL_MSB 10
#define PROP_HD_PSD_FIELD_MASK_URL_MASK 0x400
#define PROP_HD_PSD_FIELD_MASK_URL_BIT 0x400
#define PROP_HD_PSD_FIELD_MASK_URL_value() (((PROP_HD_PSD_FIELD_MASK_value()) & 0x400)>>10)
#define PROP_HD_PSD_FIELD_MASK_VALID_LSB 9
#define PROP_HD_PSD_FIELD_MASK_VALID_MSB 9
#define PROP_HD_PSD_FIELD_MASK_VALID_MASK 0x200
#define PROP_HD_PSD_FIELD_MASK_VALID_BIT 0x200
#define PROP_HD_PSD_FIELD_MASK_VALID_value() (((PROP_HD_PSD_FIELD_MASK_value()) & 0x200)>>9)
#define PROP_HD_PSD_FIELD_MASK_PRICE_LSB 8
#define PROP_HD_PSD_FIELD_MASK_PRICE_MSB 8
#define PROP_HD_PSD_FIELD_MASK_PRICE_MASK 0x100
#define PROP_HD_PSD_FIELD_MASK_PRICE_BIT 0x100
#define PROP_HD_PSD_FIELD_MASK_PRICE_value() (((PROP_HD_PSD_FIELD_MASK_value()) & 0x100)>>8)
#define PROP_HD_PSD_FIELD_MASK_TEXT_LSB 6
#define PROP_HD_PSD_FIELD_MASK_TEXT_MSB 6
#define PROP_HD_PSD_FIELD_MASK_TEXT_MASK 0x40
#define PROP_HD_PSD_FIELD_MASK_TEXT_BIT 0x40
#define PROP_HD_PSD_FIELD_MASK_TEXT_value() (((PROP_HD_PSD_FIELD_MASK_value()) & 0x40)>>6)
#define PROP_HD_PSD_FIELD_MASK_SHORT_LSB 5
#define PROP_HD_PSD_FIELD_MASK_SHORT_MSB 5
#define PROP_HD_PSD_FIELD_MASK_SHORT_MASK 0x20
#define PROP_HD_PSD_FIELD_MASK_SHORT_BIT 0x20
#define PROP_HD_PSD_FIELD_MASK_SHORT_value() (((PROP_HD_PSD_FIELD_MASK_value()) & 0x20)>>5)
#define PROP_HD_PSD_FIELD_MASK_LANG_LSB 4
#define PROP_HD_PSD_FIELD_MASK_LANG_MSB 4
#define PROP_HD_PSD_FIELD_MASK_LANG_MASK 0x10
#define PROP_HD_PSD_FIELD_MASK_LANG_BIT 0x10
#define PROP_HD_PSD_FIELD_MASK_LANG_value() (((PROP_HD_PSD_FIELD_MASK_value()) & 0x10)>>4)
#define PROP_HD_PSD_FIELD_MASK_GENRE_LSB 3
#define PROP_HD_PSD_FIELD_MASK_GENRE_MSB 3
#define PROP_HD_PSD_FIELD_MASK_GENRE_MASK 0x8
#define PROP_HD_PSD_FIELD_MASK_GENRE_BIT 0x8
#define PROP_HD_PSD_FIELD_MASK_GENRE_value() (((PROP_HD_PSD_FIELD_MASK_value()) & 0x8)>>3)
#define PROP_HD_PSD_FIELD_MASK_ALBUM_LSB 2
#define PROP_HD_PSD_FIELD_MASK_ALBUM_MSB 2
#define PROP_HD_PSD_FIELD_MASK_ALBUM_MASK 0x4
#define PROP_HD_PSD_FIELD_MASK_ALBUM_BIT 0x4
#define PROP_HD_PSD_FIELD_MASK_ALBUM_value() (((PROP_HD_PSD_FIELD_MASK_value()) & 0x4)>>2)
#define PROP_HD_PSD_FIELD_MASK_ARTIST_LSB 1
#define PROP_HD_PSD_FIELD_MASK_ARTIST_MSB 1
#define PROP_HD_PSD_FIELD_MASK_ARTIST_MASK 0x2
#define PROP_HD_PSD_FIELD_MASK_ARTIST_BIT 0x2
#define PROP_HD_PSD_FIELD_MASK_ARTIST_value() (((PROP_HD_PSD_FIELD_MASK_value()) & 0x2)>>1)
#define PROP_HD_PSD_FIELD_MASK_TITLE_LSB 0
#define PROP_HD_PSD_FIELD_MASK_TITLE_MSB 0
#define PROP_HD_PSD_FIELD_MASK_TITLE_MASK 0x1
#define PROP_HD_PSD_FIELD_MASK_TITLE_BIT 0x1
#define PROP_HD_PSD_FIELD_MASK_TITLE_value() (((PROP_HD_PSD_FIELD_MASK_value()) & 0x1)>>0)
#define PROP_HD_PSD_FIELD_MASK_DEFAULT 0xFFFF

#define PROP_HD_AUDIO_CTRL_FRAME_DELAY_MASK 0xFFFF
#define PROP_HD_AUDIO_CTRL_FRAME_DELAY_INDEX 0x00
#define PROP_HD_AUDIO_CTRL_FRAME_DELAY_GROUP 0x97
#define PROP_HD_AUDIO_CTRL_FRAME_DELAY_value() (sys_prop_ReturnProperty(PROP_HD_AUDIO_CTRL_FRAME_DELAY_GROUP, PROP_HD_AUDIO_CTRL_FRAME_DELAY_INDEX))
#define PROP_HD_AUDIO_CTRL_FRAME_DELAY_DELAY_LSB 0
#define PROP_HD_AUDIO_CTRL_FRAME_DELAY_DELAY_MSB 3
#define PROP_HD_AUDIO_CTRL_FRAME_DELAY_DELAY_MASK 0xF
#define PROP_HD_AUDIO_CTRL_FRAME_DELAY_DELAY_value() (((PROP_HD_AUDIO_CTRL_FRAME_DELAY_value()) & 0xF)>>0)
#define PROP_HD_AUDIO_CTRL_FRAME_DELAY_DELAY_RANGE_MIN (4)
#define PROP_HD_AUDIO_CTRL_FRAME_DELAY_DELAY_RANGE_MAX (21)
#define PROP_HD_AUDIO_CTRL_FRAME_DELAY_DEFAULT 6

#define PROP_HD_AUDIO_CTRL_PROGRAM_LOSS_THRESHOLD_MASK 0xFFFF
#define PROP_HD_AUDIO_CTRL_PROGRAM_LOSS_THRESHOLD_INDEX 0x01
#define PROP_HD_AUDIO_CTRL_PROGRAM_LOSS_THRESHOLD_GROUP 0x97
#define PROP_HD_AUDIO_CTRL_PROGRAM_LOSS_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_HD_AUDIO_CTRL_PROGRAM_LOSS_THRESHOLD_GROUP, PROP_HD_AUDIO_CTRL_PROGRAM_LOSS_THRESHOLD_INDEX))
#define PROP_HD_AUDIO_CTRL_PROGRAM_LOSS_THRESHOLD_TRESH_LSB 0
#define PROP_HD_AUDIO_CTRL_PROGRAM_LOSS_THRESHOLD_TRESH_MSB 3
#define PROP_HD_AUDIO_CTRL_PROGRAM_LOSS_THRESHOLD_TRESH_MASK 0xF
#define PROP_HD_AUDIO_CTRL_PROGRAM_LOSS_THRESHOLD_TRESH_value() (((PROP_HD_AUDIO_CTRL_PROGRAM_LOSS_THRESHOLD_value()) & 0xF)>>0)
#define PROP_HD_AUDIO_CTRL_PROGRAM_LOSS_THRESHOLD_TRESH_RANGE_MIN (0)
#define PROP_HD_AUDIO_CTRL_PROGRAM_LOSS_THRESHOLD_TRESH_RANGE_MAX (14)
#define PROP_HD_AUDIO_CTRL_PROGRAM_LOSS_THRESHOLD_DEFAULT 0

#define PROP_HD_AUDIO_CTRL_BALL_GAME_ENABLE_MASK 0xFFFF
#define PROP_HD_AUDIO_CTRL_BALL_GAME_ENABLE_INDEX 0x02
#define PROP_HD_AUDIO_CTRL_BALL_GAME_ENABLE_GROUP 0x97
#define PROP_HD_AUDIO_CTRL_BALL_GAME_ENABLE_value() (sys_prop_ReturnProperty(PROP_HD_AUDIO_CTRL_BALL_GAME_ENABLE_GROUP, PROP_HD_AUDIO_CTRL_BALL_GAME_ENABLE_INDEX))
#define PROP_HD_AUDIO_CTRL_BALL_GAME_ENABLE_MODE_LSB 0
#define PROP_HD_AUDIO_CTRL_BALL_GAME_ENABLE_MODE_MSB 0
#define PROP_HD_AUDIO_CTRL_BALL_GAME_ENABLE_MODE_MASK 0x1
#define PROP_HD_AUDIO_CTRL_BALL_GAME_ENABLE_MODE_BIT 0x1
#define PROP_HD_AUDIO_CTRL_BALL_GAME_ENABLE_MODE_value() (((PROP_HD_AUDIO_CTRL_BALL_GAME_ENABLE_value()) & 0x1)>>0)
#define PROP_HD_AUDIO_CTRL_BALL_GAME_ENABLE_MODE_RANGE_MIN (0)
#define PROP_HD_AUDIO_CTRL_BALL_GAME_ENABLE_MODE_RANGE_MAX (1)
#define PROP_HD_AUDIO_CTRL_BALL_GAME_ENABLE_DEFAULT 1

#define PROP_HD_CODEC_MODE_0_BLEND_THRESHOLD_MASK 0xFFFF
#define PROP_HD_CODEC_MODE_0_BLEND_THRESHOLD_INDEX 0x00
#define PROP_HD_CODEC_MODE_0_BLEND_THRESHOLD_GROUP 0x99
#define PROP_HD_CODEC_MODE_0_BLEND_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_HD_CODEC_MODE_0_BLEND_THRESHOLD_GROUP, PROP_HD_CODEC_MODE_0_BLEND_THRESHOLD_INDEX))
#define PROP_HD_CODEC_MODE_0_BLEND_THRESHOLD_LEVEL_LSB 0
#define PROP_HD_CODEC_MODE_0_BLEND_THRESHOLD_LEVEL_MSB 2
#define PROP_HD_CODEC_MODE_0_BLEND_THRESHOLD_LEVEL_MASK 0x7
#define PROP_HD_CODEC_MODE_0_BLEND_THRESHOLD_LEVEL_value() (((PROP_HD_CODEC_MODE_0_BLEND_THRESHOLD_value()) & 0x7)>>0)
#define PROP_HD_CODEC_MODE_0_BLEND_THRESHOLD_DEFAULT 3

#define PROP_HD_CODEC_MODE_0_SAMPLES_DELAY_MASK 0xFFFF
#define PROP_HD_CODEC_MODE_0_SAMPLES_DELAY_INDEX 0x01
#define PROP_HD_CODEC_MODE_0_SAMPLES_DELAY_GROUP 0x99
#define PROP_HD_CODEC_MODE_0_SAMPLES_DELAY_value() (sys_prop_ReturnProperty(PROP_HD_CODEC_MODE_0_SAMPLES_DELAY_GROUP, PROP_HD_CODEC_MODE_0_SAMPLES_DELAY_INDEX))
#define PROP_HD_CODEC_MODE_0_SAMPLES_DELAY_COUNT_LSB 0
#define PROP_HD_CODEC_MODE_0_SAMPLES_DELAY_COUNT_MSB 13
#define PROP_HD_CODEC_MODE_0_SAMPLES_DELAY_COUNT_MASK 0x3FFF
#define PROP_HD_CODEC_MODE_0_SAMPLES_DELAY_COUNT_value() (uint16_t)(((PROP_HD_CODEC_MODE_0_SAMPLES_DELAY_value()) & 0x3FFF)>>0)
#define PROP_FMHD_HD_CODEC_MODE_0_SAMPLES_DELAY_DEFAULT 3693
#define PROP_AMHD_HD_CODEC_MODE_0_SAMPLES_DELAY_DEFAULT 0


#define PROP_HD_CODEC_MODE_0_BLEND_RATE_MASK 0xFFFF
#define PROP_HD_CODEC_MODE_0_BLEND_RATE_INDEX 0x02
#define PROP_HD_CODEC_MODE_0_BLEND_RATE_GROUP 0x99
#define PROP_HD_CODEC_MODE_0_BLEND_RATE_value() (sys_prop_ReturnProperty(PROP_HD_CODEC_MODE_0_BLEND_RATE_GROUP, PROP_HD_CODEC_MODE_0_BLEND_RATE_INDEX))
#define PROP_HD_CODEC_MODE_0_BLEND_RATE_HOLD_LSB 0
#define PROP_HD_CODEC_MODE_0_BLEND_RATE_HOLD_MSB 7
#define PROP_HD_CODEC_MODE_0_BLEND_RATE_HOLD_MASK 0xFF
#define PROP_HD_CODEC_MODE_0_BLEND_RATE_HOLD_value() (uint8_t)(((PROP_HD_CODEC_MODE_0_BLEND_RATE_value()) & 0xFF)>>0)
#define PROP_HD_CODEC_MODE_0_BLEND_RATE_HOLD_RANGE_MIN (1)
#define PROP_HD_CODEC_MODE_0_BLEND_RATE_HOLD_RANGE_MAX (8)
#define PROP_HD_CODEC_MODE_0_BLEND_RATE_DEFAULT 1


#define PROP_HD_CODEC_MODE_2_BLEND_THRESHOLD_MASK 0xFFFF
#define PROP_HD_CODEC_MODE_2_BLEND_THRESHOLD_INDEX 0x03
#define PROP_HD_CODEC_MODE_2_BLEND_THRESHOLD_GROUP 0x99
#define PROP_HD_CODEC_MODE_2_BLEND_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_HD_CODEC_MODE_2_BLEND_THRESHOLD_GROUP, PROP_HD_CODEC_MODE_2_BLEND_THRESHOLD_INDEX))
#define PROP_HD_CODEC_MODE_2_BLEND_THRESHOLD_LEVEL_LSB 0
#define PROP_HD_CODEC_MODE_2_BLEND_THRESHOLD_LEVEL_MSB 2
#define PROP_HD_CODEC_MODE_2_BLEND_THRESHOLD_LEVEL_MASK 0x7
#define PROP_HD_CODEC_MODE_2_BLEND_THRESHOLD_LEVEL_value() (((PROP_HD_CODEC_MODE_2_BLEND_THRESHOLD_value()) & 0x7)>>0)
#define PROP_HD_CODEC_MODE_2_BLEND_THRESHOLD_DEFAULT 3

#define PROP_HD_CODEC_MODE_2_SAMPLES_DELAY_MASK 0xFFFF
#define PROP_HD_CODEC_MODE_2_SAMPLES_DELAY_INDEX 0x04
#define PROP_HD_CODEC_MODE_2_SAMPLES_DELAY_GROUP 0x99
#define PROP_HD_CODEC_MODE_2_SAMPLES_DELAY_value() (sys_prop_ReturnProperty(PROP_HD_CODEC_MODE_2_SAMPLES_DELAY_GROUP, PROP_HD_CODEC_MODE_2_SAMPLES_DELAY_INDEX))
#define PROP_HD_CODEC_MODE_2_SAMPLES_DELAY_COUNT_LSB 0
#define PROP_HD_CODEC_MODE_2_SAMPLES_DELAY_COUNT_MSB 13
#define PROP_HD_CODEC_MODE_2_SAMPLES_DELAY_COUNT_MASK 0x3FFF
#define PROP_HD_CODEC_MODE_2_SAMPLES_DELAY_COUNT_value() (uint16_t)(((PROP_HD_CODEC_MODE_2_SAMPLES_DELAY_value()) & 0x3FFF)>>0)
#define PROP_FMHD_HD_CODEC_MODE_2_SAMPLES_DELAY_DEFAULT 0
#define PROP_AMHD_HD_CODEC_MODE_2_SAMPLES_DELAY_DEFAULT 7398


#define PROP_HD_CODEC_MODE_2_BLEND_RATE_MASK 0xFFFF
#define PROP_HD_CODEC_MODE_2_BLEND_RATE_INDEX 0x05
#define PROP_HD_CODEC_MODE_2_BLEND_RATE_GROUP 0x99
#define PROP_HD_CODEC_MODE_2_BLEND_RATE_value() (sys_prop_ReturnProperty(PROP_HD_CODEC_MODE_2_BLEND_RATE_GROUP, PROP_HD_CODEC_MODE_2_BLEND_RATE_INDEX))
#define PROP_HD_CODEC_MODE_2_BLEND_RATE_HOLD_LSB 0
#define PROP_HD_CODEC_MODE_2_BLEND_RATE_HOLD_MSB 7
#define PROP_HD_CODEC_MODE_2_BLEND_RATE_HOLD_MASK 0xFF
#define PROP_HD_CODEC_MODE_2_BLEND_RATE_HOLD_value() (uint8_t)(((PROP_HD_CODEC_MODE_2_BLEND_RATE_value()) & 0xFF)>>0)
#define PROP_HD_CODEC_MODE_2_BLEND_RATE_HOLD_RANGE_MIN (1)
#define PROP_HD_CODEC_MODE_2_BLEND_RATE_HOLD_RANGE_MAX (8)
#define PROP_HD_CODEC_MODE_2_BLEND_RATE_DEFAULT 1

#define PROP_HD_CODEC_MODE_10_BLEND_THRESHOLD_MASK 0xFFFF
#define PROP_HD_CODEC_MODE_10_BLEND_THRESHOLD_INDEX 0x06
#define PROP_HD_CODEC_MODE_10_BLEND_THRESHOLD_GROUP 0x99
#define PROP_HD_CODEC_MODE_10_BLEND_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_HD_CODEC_MODE_10_BLEND_THRESHOLD_GROUP, PROP_HD_CODEC_MODE_10_BLEND_THRESHOLD_INDEX))
#define PROP_HD_CODEC_MODE_10_BLEND_THRESHOLD_LEVEL_LSB 0
#define PROP_HD_CODEC_MODE_10_BLEND_THRESHOLD_LEVEL_MSB 2
#define PROP_HD_CODEC_MODE_10_BLEND_THRESHOLD_LEVEL_MASK 0x7
#define PROP_HD_CODEC_MODE_10_BLEND_THRESHOLD_LEVEL_value() (((PROP_HD_CODEC_MODE_10_BLEND_THRESHOLD_value()) & 0x7)>>0)
#define PROP_HD_CODEC_MODE_10_BLEND_THRESHOLD_DEFAULT 3

#define PROP_HD_CODEC_MODE_10_SAMPLES_DELAY_MASK 0xFFFF
#define PROP_HD_CODEC_MODE_10_SAMPLES_DELAY_INDEX 0x07
#define PROP_HD_CODEC_MODE_10_SAMPLES_DELAY_GROUP 0x99
#define PROP_HD_CODEC_MODE_10_SAMPLES_DELAY_value() (sys_prop_ReturnProperty(PROP_HD_CODEC_MODE_10_SAMPLES_DELAY_GROUP, PROP_HD_CODEC_MODE_10_SAMPLES_DELAY_INDEX))
#define PROP_HD_CODEC_MODE_10_SAMPLES_DELAY_COUNT_LSB 0
#define PROP_HD_CODEC_MODE_10_SAMPLES_DELAY_COUNT_MSB 13
#define PROP_HD_CODEC_MODE_10_SAMPLES_DELAY_COUNT_MASK 0x3FFF
#define PROP_HD_CODEC_MODE_10_SAMPLES_DELAY_COUNT_value() (uint16_t)(((PROP_HD_CODEC_MODE_10_SAMPLES_DELAY_value()) & 0x3FFF)>>0)
#define PROP_HD_CODEC_MODE_10_SAMPLES_DELAY_DEFAULT 0


#define PROP_HD_CODEC_MODE_10_BLEND_RATE_MASK 0xFFFF
#define PROP_HD_CODEC_MODE_10_BLEND_RATE_INDEX 0x08
#define PROP_HD_CODEC_MODE_10_BLEND_RATE_GROUP 0x99
#define PROP_HD_CODEC_MODE_10_BLEND_RATE_value() (sys_prop_ReturnProperty(PROP_HD_CODEC_MODE_10_BLEND_RATE_GROUP, PROP_HD_CODEC_MODE_10_BLEND_RATE_INDEX))
#define PROP_HD_CODEC_MODE_10_BLEND_RATE_HOLD_LSB 0
#define PROP_HD_CODEC_MODE_10_BLEND_RATE_HOLD_MSB 7
#define PROP_HD_CODEC_MODE_10_BLEND_RATE_HOLD_MASK 0xFF
#define PROP_HD_CODEC_MODE_10_BLEND_RATE_HOLD_value() (uint8_t)(((PROP_HD_CODEC_MODE_10_BLEND_RATE_value()) & 0xFF)>>0)
#define PROP_HD_CODEC_MODE_10_BLEND_RATE_HOLD_RANGE_MIN (1)
#define PROP_HD_CODEC_MODE_10_BLEND_RATE_HOLD_RANGE_MAX (8)
#define PROP_HD_CODEC_MODE_10_BLEND_RATE_DEFAULT 1

#define PROP_HD_CODEC_MODE_13_BLEND_THRESHOLD_MASK 0xFFFF
#define PROP_HD_CODEC_MODE_13_BLEND_THRESHOLD_INDEX 0x09
#define PROP_HD_CODEC_MODE_13_BLEND_THRESHOLD_GROUP 0x99
#define PROP_HD_CODEC_MODE_13_BLEND_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_HD_CODEC_MODE_13_BLEND_THRESHOLD_GROUP, PROP_HD_CODEC_MODE_13_BLEND_THRESHOLD_INDEX))
#define PROP_HD_CODEC_MODE_13_BLEND_THRESHOLD_LEVEL_LSB 0
#define PROP_HD_CODEC_MODE_13_BLEND_THRESHOLD_LEVEL_MSB 2
#define PROP_HD_CODEC_MODE_13_BLEND_THRESHOLD_LEVEL_MASK 0x7
#define PROP_HD_CODEC_MODE_13_BLEND_THRESHOLD_LEVEL_value() (((PROP_HD_CODEC_MODE_13_BLEND_THRESHOLD_value()) & 0x7)>>0)
#define PROP_HD_CODEC_MODE_13_BLEND_THRESHOLD_DEFAULT 3


#define PROP_HD_CODEC_MODE_13_SAMPLES_DELAY_MASK 0xFFFF
#define PROP_HD_CODEC_MODE_13_SAMPLES_DELAY_INDEX 0x0A
#define PROP_HD_CODEC_MODE_13_SAMPLES_DELAY_GROUP 0x99
#define PROP_HD_CODEC_MODE_13_SAMPLES_DELAY_value() (sys_prop_ReturnProperty(PROP_HD_CODEC_MODE_13_SAMPLES_DELAY_GROUP, PROP_HD_CODEC_MODE_13_SAMPLES_DELAY_INDEX))
#define PROP_HD_CODEC_MODE_13_SAMPLES_DELAY_COUNT_LSB 0
#define PROP_HD_CODEC_MODE_13_SAMPLES_DELAY_COUNT_MSB 13
#define PROP_HD_CODEC_MODE_13_SAMPLES_DELAY_COUNT_MASK 0x3FFF
#define PROP_HD_CODEC_MODE_13_SAMPLES_DELAY_COUNT_value() (uint16_t)(((PROP_HD_CODEC_MODE_13_SAMPLES_DELAY_value()) & 0x3FFF)>>0)
#define PROP_HD_CODEC_MODE_13_SAMPLES_DELAY_DEFAULT 0

#define PROP_HD_CODEC_MODE_13_BLEND_RATE_MASK 0xFFFF
#define PROP_HD_CODEC_MODE_13_BLEND_RATE_INDEX 0x0B
#define PROP_HD_CODEC_MODE_13_BLEND_RATE_GROUP 0x99
#define PROP_HD_CODEC_MODE_13_BLEND_RATE_value() (sys_prop_ReturnProperty(PROP_HD_CODEC_MODE_13_BLEND_RATE_GROUP, PROP_HD_CODEC_MODE_13_BLEND_RATE_INDEX))
#define PROP_HD_CODEC_MODE_13_BLEND_RATE_HOLD_LSB 0
#define PROP_HD_CODEC_MODE_13_BLEND_RATE_HOLD_MSB 7
#define PROP_HD_CODEC_MODE_13_BLEND_RATE_HOLD_MASK 0xFF
#define PROP_HD_CODEC_MODE_13_BLEND_RATE_HOLD_value() (uint8_t)(((PROP_HD_CODEC_MODE_13_BLEND_RATE_value()) & 0xFF)>>0)
#define PROP_HD_CODEC_MODE_13_BLEND_RATE_HOLD_RANGE_MIN (1)
#define PROP_HD_CODEC_MODE_13_BLEND_RATE_HOLD_RANGE_MAX (8)
#define PROP_HD_CODEC_MODE_13_BLEND_RATE_DEFAULT 1

#define PROP_HD_CODEC_MODE_1_BLEND_THRESHOLD_MASK 0xFFFF
#define PROP_HD_CODEC_MODE_1_BLEND_THRESHOLD_INDEX 0x0C
#define PROP_HD_CODEC_MODE_1_BLEND_THRESHOLD_GROUP 0x99
#define PROP_HD_CODEC_MODE_1_BLEND_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_HD_CODEC_MODE_1_BLEND_THRESHOLD_GROUP, PROP_HD_CODEC_MODE_1_BLEND_THRESHOLD_INDEX))
#define PROP_HD_CODEC_MODE_1_BLEND_THRESHOLD_LEVEL_LSB 0
#define PROP_HD_CODEC_MODE_1_BLEND_THRESHOLD_LEVEL_MSB 2
#define PROP_HD_CODEC_MODE_1_BLEND_THRESHOLD_LEVEL_MASK 0x7
#define PROP_HD_CODEC_MODE_1_BLEND_THRESHOLD_LEVEL_value() (((PROP_HD_CODEC_MODE_1_BLEND_THRESHOLD_value()) & 0x7)>>0)
#define PROP_HD_CODEC_MODE_1_BLEND_THRESHOLD_DEFAULT 3

#define PROP_HD_CODEC_MODE_1_SAMPLES_DELAY_MASK 0xFFFF
#define PROP_HD_CODEC_MODE_1_SAMPLES_DELAY_INDEX 0x0D
#define PROP_HD_CODEC_MODE_1_SAMPLES_DELAY_GROUP 0x99
#define PROP_HD_CODEC_MODE_1_SAMPLES_DELAY_value() (sys_prop_ReturnProperty(PROP_HD_CODEC_MODE_1_SAMPLES_DELAY_GROUP, PROP_HD_CODEC_MODE_1_SAMPLES_DELAY_INDEX))
#define PROP_HD_CODEC_MODE_1_SAMPLES_DELAY_COUNT_LSB 0
#define PROP_HD_CODEC_MODE_1_SAMPLES_DELAY_COUNT_MSB 13
#define PROP_HD_CODEC_MODE_1_SAMPLES_DELAY_COUNT_MASK 0x3FFF
#define PROP_HD_CODEC_MODE_1_SAMPLES_DELAY_COUNT_value() (uint16_t)(((PROP_HD_CODEC_MODE_1_SAMPLES_DELAY_value()) & 0x3FFF)>>0)
#define PROP_HD_CODEC_MODE_1_SAMPLES_DELAY_DEFAULT 0

#define PROP_HD_CODEC_MODE_1_BLEND_RATE_MASK 0xFFFF
#define PROP_HD_CODEC_MODE_1_BLEND_RATE_INDEX 0x0E
#define PROP_HD_CODEC_MODE_1_BLEND_RATE_GROUP 0x99
#define PROP_HD_CODEC_MODE_1_BLEND_RATE_value() (sys_prop_ReturnProperty(PROP_HD_CODEC_MODE_1_BLEND_RATE_GROUP, PROP_HD_CODEC_MODE_1_BLEND_RATE_INDEX))
#define PROP_HD_CODEC_MODE_1_BLEND_RATE_HOLD_LSB 0
#define PROP_HD_CODEC_MODE_1_BLEND_RATE_HOLD_MSB 7
#define PROP_HD_CODEC_MODE_1_BLEND_RATE_HOLD_MASK 0xFF
#define PROP_HD_CODEC_MODE_1_BLEND_RATE_HOLD_value() (uint8_t)(((PROP_HD_CODEC_MODE_1_BLEND_RATE_value()) & 0xFF)>>0)
#define PROP_HD_CODEC_MODE_1_BLEND_RATE_HOLD_RANGE_MIN (1)
#define PROP_HD_CODEC_MODE_1_BLEND_RATE_HOLD_RANGE_MAX (8)
#define PROP_HD_CODEC_MODE_1_BLEND_RATE_DEFAULT 1

#define PROP_HD_CODEC_MODE_3_BLEND_THRESHOLD_MASK 0xFFFF
#define PROP_HD_CODEC_MODE_3_BLEND_THRESHOLD_INDEX 0x0F
#define PROP_HD_CODEC_MODE_3_BLEND_THRESHOLD_GROUP 0x99
#define PROP_HD_CODEC_MODE_3_BLEND_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_HD_CODEC_MODE_3_BLEND_THRESHOLD_GROUP, PROP_HD_CODEC_MODE_3_BLEND_THRESHOLD_INDEX))
#define PROP_HD_CODEC_MODE_3_BLEND_THRESHOLD_LEVEL_LSB 0
#define PROP_HD_CODEC_MODE_3_BLEND_THRESHOLD_LEVEL_MSB 2
#define PROP_HD_CODEC_MODE_3_BLEND_THRESHOLD_LEVEL_MASK 0x7
#define PROP_HD_CODEC_MODE_3_BLEND_THRESHOLD_LEVEL_value() (((PROP_HD_CODEC_MODE_3_BLEND_THRESHOLD_value()) & 0x7)>>0)
#define PROP_HD_CODEC_MODE_3_BLEND_THRESHOLD_DEFAULT 3

#define PROP_HD_CODEC_MODE_3_SAMPLES_DELAY_MASK 0xFFFF
#define PROP_HD_CODEC_MODE_3_SAMPLES_DELAY_INDEX 0x10
#define PROP_HD_CODEC_MODE_3_SAMPLES_DELAY_GROUP 0x99
#define PROP_HD_CODEC_MODE_3_SAMPLES_DELAY_value() (sys_prop_ReturnProperty(PROP_HD_CODEC_MODE_3_SAMPLES_DELAY_GROUP, PROP_HD_CODEC_MODE_3_SAMPLES_DELAY_INDEX))
#define PROP_HD_CODEC_MODE_3_SAMPLES_DELAY_COUNT_LSB 0
#define PROP_HD_CODEC_MODE_3_SAMPLES_DELAY_COUNT_MSB 13
#define PROP_HD_CODEC_MODE_3_SAMPLES_DELAY_COUNT_MASK 0x3FFF
#define PROP_HD_CODEC_MODE_3_SAMPLES_DELAY_COUNT_value() (uint16_t)(((PROP_HD_CODEC_MODE_3_SAMPLES_DELAY_value()) & 0x3FFF)>>0)
#define PROP_HD_CODEC_MODE_3_SAMPLES_DELAY_DEFAULT 0

#define PROP_HD_CODEC_MODE_3_BLEND_RATE_MASK 0xFFFF
#define PROP_HD_CODEC_MODE_3_BLEND_RATE_INDEX 0x11
#define PROP_HD_CODEC_MODE_3_BLEND_RATE_GROUP 0x99
#define PROP_HD_CODEC_MODE_3_BLEND_RATE_value() (sys_prop_ReturnProperty(PROP_HD_CODEC_MODE_3_BLEND_RATE_GROUP, PROP_HD_CODEC_MODE_3_BLEND_RATE_INDEX))
#define PROP_HD_CODEC_MODE_3_BLEND_RATE_HOLD_LSB 0
#define PROP_HD_CODEC_MODE_3_BLEND_RATE_HOLD_MSB 7
#define PROP_HD_CODEC_MODE_3_BLEND_RATE_HOLD_MASK 0xFF
#define PROP_HD_CODEC_MODE_3_BLEND_RATE_HOLD_value() (uint8_t)(((PROP_HD_CODEC_MODE_3_BLEND_RATE_value()) & 0xFF)>>0)
#define PROP_HD_CODEC_MODE_3_BLEND_RATE_HOLD_RANGE_MIN (1)
#define PROP_HD_CODEC_MODE_3_BLEND_RATE_HOLD_RANGE_MAX (8)
#define PROP_HD_CODEC_MODE_3_BLEND_RATE_DEFAULT 1

#define PROP_HD_SERVICE_MODE_CONTROL_MP11_ENABLE_MASK 0xFFFF
#define PROP_HD_SERVICE_MODE_CONTROL_MP11_ENABLE_INDEX 0x00
#define PROP_HD_SERVICE_MODE_CONTROL_MP11_ENABLE_GROUP 0x9A
#define PROP_HD_SERVICE_MODE_CONTROL_MP11_ENABLE_value() (sys_prop_ReturnProperty(PROP_HD_SERVICE_MODE_CONTROL_MP11_ENABLE_GROUP, PROP_HD_SERVICE_MODE_CONTROL_MP11_ENABLE_INDEX))
#define PROP_HD_SERVICE_MODE_CONTROL_MP11_ENABLE_ENABLE_LSB 0
#define PROP_HD_SERVICE_MODE_CONTROL_MP11_ENABLE_ENABLE_MSB 0
#define PROP_HD_SERVICE_MODE_CONTROL_MP11_ENABLE_ENABLE_MASK 0x1
#define PROP_HD_SERVICE_MODE_CONTROL_MP11_ENABLE_ENABLE_BIT 0x1
#define PROP_HD_SERVICE_MODE_CONTROL_MP11_ENABLE_ENABLE_value() (((PROP_HD_SERVICE_MODE_CONTROL_MP11_ENABLE_value()) & 0x1)>>0)
#define PROP_HD_SERVICE_MODE_CONTROL_MP11_ENABLE_DEFAULT 0x0000

#define PROP_HD_EZBLEND_ENABLE_MASK 0xFFFF
#define PROP_HD_EZBLEND_ENABLE_INDEX 0x00
#define PROP_HD_EZBLEND_ENABLE_GROUP 0x9B
#define PROP_HD_EZBLEND_ENABLE_value() (sys_prop_ReturnProperty(PROP_HD_EZBLEND_ENABLE_GROUP, PROP_HD_EZBLEND_ENABLE_INDEX))
#define PROP_HD_EZBLEND_ENABLE_ENABLE_LSB 0
#define PROP_HD_EZBLEND_ENABLE_ENABLE_MSB 0
#define PROP_HD_EZBLEND_ENABLE_ENABLE_MASK 0x1
#define PROP_HD_EZBLEND_ENABLE_ENABLE_BIT 0x1
#define PROP_HD_EZBLEND_ENABLE_ENABLE_value() (((PROP_HD_EZBLEND_ENABLE_value()) & 0x1)>>0)
#define PROP_HD_EZBLEND_ENABLE_DEFAULT 0

#define PROP_HD_EZBLEND_MPS_BLEND_THRESHOLD_MASK 0xFFFF
#define PROP_HD_EZBLEND_MPS_BLEND_THRESHOLD_INDEX 0x01
#define PROP_HD_EZBLEND_MPS_BLEND_THRESHOLD_GROUP 0x9B
#define PROP_HD_EZBLEND_MPS_BLEND_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_HD_EZBLEND_MPS_BLEND_THRESHOLD_GROUP, PROP_HD_EZBLEND_MPS_BLEND_THRESHOLD_INDEX))
#define PROP_HD_EZBLEND_MPS_BLEND_THRESHOLD_MPS_BLEND_THRESHOLD_LSB 0
#define PROP_HD_EZBLEND_MPS_BLEND_THRESHOLD_MPS_BLEND_THRESHOLD_MSB 7
#define PROP_HD_EZBLEND_MPS_BLEND_THRESHOLD_MPS_BLEND_THRESHOLD_MASK 0xFF
#define PROP_HD_EZBLEND_MPS_BLEND_THRESHOLD_MPS_BLEND_THRESHOLD_value() (uint8_t)(((PROP_HD_EZBLEND_MPS_BLEND_THRESHOLD_value()) & 0xFF)>>0)
#define PROP_HD_EZBLEND_MPS_BLEND_THRESHOLD_MPS_BLEND_THRESHOLD_RANGE_MIN (0)
#define PROP_HD_EZBLEND_MPS_BLEND_THRESHOLD_MPS_BLEND_THRESHOLD_RANGE_MAX (7)
#define PROP_HD_EZBLEND_MPS_BLEND_THRESHOLD_DEFAULT 3

#define PROP_HD_EZBLEND_MPS_BLEND_RATE_MASK 0xFFFF
#define PROP_HD_EZBLEND_MPS_BLEND_RATE_INDEX 0x02
#define PROP_HD_EZBLEND_MPS_BLEND_RATE_GROUP 0x9B
#define PROP_HD_EZBLEND_MPS_BLEND_RATE_value() (sys_prop_ReturnProperty(PROP_HD_EZBLEND_MPS_BLEND_RATE_GROUP, PROP_HD_EZBLEND_MPS_BLEND_RATE_INDEX))
#define PROP_HD_EZBLEND_MPS_BLEND_RATE_MPS_BLEND_RATE_LSB 0
#define PROP_HD_EZBLEND_MPS_BLEND_RATE_MPS_BLEND_RATE_MSB 7
#define PROP_HD_EZBLEND_MPS_BLEND_RATE_MPS_BLEND_RATE_MASK 0xFF
#define PROP_HD_EZBLEND_MPS_BLEND_RATE_MPS_BLEND_RATE_value() (uint8_t)(((PROP_HD_EZBLEND_MPS_BLEND_RATE_value()) & 0xFF)>>0)
#define PROP_HD_EZBLEND_MPS_BLEND_RATE_MPS_BLEND_RATE_RANGE_MIN (1)
#define PROP_HD_EZBLEND_MPS_BLEND_RATE_MPS_BLEND_RATE_RANGE_MAX (8)
#define PROP_HD_EZBLEND_MPS_BLEND_RATE_DEFAULT 3

#define PROP_HD_EZBLEND_MPS_SAMPLES_DELAY_MASK 0xFFFF
#define PROP_HD_EZBLEND_MPS_SAMPLES_DELAY_INDEX 0x03
#define PROP_HD_EZBLEND_MPS_SAMPLES_DELAY_GROUP 0x9B
#define PROP_HD_EZBLEND_MPS_SAMPLES_DELAY_value() (sys_prop_ReturnProperty(PROP_HD_EZBLEND_MPS_SAMPLES_DELAY_GROUP, PROP_HD_EZBLEND_MPS_SAMPLES_DELAY_INDEX))
#define PROP_HD_EZBLEND_MPS_SAMPLES_DELAY_MPS_SAMPLES_DELAY_LSB 0
#define PROP_HD_EZBLEND_MPS_SAMPLES_DELAY_MPS_SAMPLES_DELAY_MSB 15
#define PROP_HD_EZBLEND_MPS_SAMPLES_DELAY_MPS_SAMPLES_DELAY_MASK 0xFFFF
#define PROP_HD_EZBLEND_MPS_SAMPLES_DELAY_MPS_SAMPLES_DELAY_value() (uint16_t)(((PROP_HD_EZBLEND_MPS_SAMPLES_DELAY_value()) & 0xFFFF)>>0)
#define PROP_HD_EZBLEND_MPS_SAMPLES_DELAY_DEFAULT 3693

#define PROP_HD_EZBLEND_SPS_BLEND_THRESHOLD_MASK 0xFFFF
#define PROP_HD_EZBLEND_SPS_BLEND_THRESHOLD_INDEX 0x04
#define PROP_HD_EZBLEND_SPS_BLEND_THRESHOLD_GROUP 0x9B
#define PROP_HD_EZBLEND_SPS_BLEND_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_HD_EZBLEND_SPS_BLEND_THRESHOLD_GROUP, PROP_HD_EZBLEND_SPS_BLEND_THRESHOLD_INDEX))
#define PROP_HD_EZBLEND_SPS_BLEND_THRESHOLD_SPS_BLEND_THRESHOLD_LSB 0
#define PROP_HD_EZBLEND_SPS_BLEND_THRESHOLD_SPS_BLEND_THRESHOLD_MSB 7
#define PROP_HD_EZBLEND_SPS_BLEND_THRESHOLD_SPS_BLEND_THRESHOLD_MASK 0xFF
#define PROP_HD_EZBLEND_SPS_BLEND_THRESHOLD_SPS_BLEND_THRESHOLD_value() (uint8_t)(((PROP_HD_EZBLEND_SPS_BLEND_THRESHOLD_value()) & 0xFF)>>0)
#define PROP_HD_EZBLEND_SPS_BLEND_THRESHOLD_SPS_BLEND_THRESHOLD_RANGE_MIN (0)
#define PROP_HD_EZBLEND_SPS_BLEND_THRESHOLD_SPS_BLEND_THRESHOLD_RANGE_MAX (7)
#define PROP_HD_EZBLEND_SPS_BLEND_THRESHOLD_DEFAULT 4

#define PROP_HD_EZBLEND_SPS_BLEND_RATE_MASK 0xFFFF
#define PROP_HD_EZBLEND_SPS_BLEND_RATE_INDEX 0x05
#define PROP_HD_EZBLEND_SPS_BLEND_RATE_GROUP 0x9B
#define PROP_HD_EZBLEND_SPS_BLEND_RATE_value() (sys_prop_ReturnProperty(PROP_HD_EZBLEND_SPS_BLEND_RATE_GROUP, PROP_HD_EZBLEND_SPS_BLEND_RATE_INDEX))
#define PROP_HD_EZBLEND_SPS_BLEND_RATE_SPS_BLEND_RATE_LSB 0
#define PROP_HD_EZBLEND_SPS_BLEND_RATE_SPS_BLEND_RATE_MSB 7
#define PROP_HD_EZBLEND_SPS_BLEND_RATE_SPS_BLEND_RATE_MASK 0xFF
#define PROP_HD_EZBLEND_SPS_BLEND_RATE_SPS_BLEND_RATE_value() (uint8_t)(((PROP_HD_EZBLEND_SPS_BLEND_RATE_value()) & 0xFF)>>0)
#define PROP_HD_EZBLEND_SPS_BLEND_RATE_SPS_BLEND_RATE_RANGE_MIN (1)
#define PROP_HD_EZBLEND_SPS_BLEND_RATE_SPS_BLEND_RATE_RANGE_MAX (8)
#define PROP_HD_EZBLEND_SPS_BLEND_RATE_DEFAULT 1

#define PROP_HD_LEVEL_HD_DETECTION_MASK 0xFFFF
#define PROP_HD_LEVEL_HD_DETECTION_INDEX 0x00
#define PROP_HD_LEVEL_HD_DETECTION_GROUP 0x9D
#define PROP_HD_LEVEL_HD_DETECTION_value() (sys_prop_ReturnProperty(PROP_HD_LEVEL_HD_DETECTION_GROUP, PROP_HD_LEVEL_HD_DETECTION_INDEX))
#define PROP_HD_LEVEL_HD_DETECTION_SAMPLES_LSB 0
#define PROP_HD_LEVEL_HD_DETECTION_SAMPLES_MSB 7
#define PROP_HD_LEVEL_HD_DETECTION_SAMPLES_MASK 0xFF
#define PROP_HD_LEVEL_HD_DETECTION_SAMPLES_value() (uint8_t)(((PROP_HD_LEVEL_HD_DETECTION_value()) & 0xFF)>>0)

#define PROP_HD_LEVEL_HDDETECTED_THRESHOLD_MASK 0xFFFF
#define PROP_HD_LEVEL_HDDETECTED_THRESHOLD_INDEX 0x01
#define PROP_HD_LEVEL_HDDETECTED_THRESHOLD_GROUP 0x9D
#define PROP_HD_LEVEL_HDDETECTED_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_HD_LEVEL_HDDETECTED_THRESHOLD_GROUP, PROP_HD_LEVEL_HDDETECTED_THRESHOLD_INDEX))
#define PROP_HD_LEVEL_HDDETECTED_THRESHOLD_FLT_HDDETECTED_THRESHOLD_LSB 8
#define PROP_HD_LEVEL_HDDETECTED_THRESHOLD_FLT_HDDETECTED_THRESHOLD_MSB 15
#define PROP_HD_LEVEL_HDDETECTED_THRESHOLD_FLT_HDDETECTED_THRESHOLD_MASK 0xFF00
#define PROP_HD_LEVEL_HDDETECTED_THRESHOLD_FLT_HDDETECTED_THRESHOLD_value() (uint8_t)(((PROP_HD_LEVEL_HDDETECTED_THRESHOLD_value()) & 0xFF00)>>8)
#define PROP_HD_LEVEL_HDDETECTED_THRESHOLD_FLT_HDDETECTED_THRESHOLD_RANGE_MIN (0)
#define PROP_HD_LEVEL_HDDETECTED_THRESHOLD_FLT_HDDETECTED_THRESHOLD_RANGE_MAX (100)
#define PROP_HD_LEVEL_HDDETECTED_THRESHOLD_HDDETECTED_THRESHOLD_LSB 0
#define PROP_HD_LEVEL_HDDETECTED_THRESHOLD_HDDETECTED_THRESHOLD_MSB 7
#define PROP_HD_LEVEL_HDDETECTED_THRESHOLD_HDDETECTED_THRESHOLD_MASK 0xFF
#define PROP_HD_LEVEL_HDDETECTED_THRESHOLD_HDDETECTED_THRESHOLD_value() (uint8_t)(((PROP_HD_LEVEL_HDDETECTED_THRESHOLD_value()) & 0xFF)>>0)
#define PROP_HD_LEVEL_HDDETECTED_THRESHOLD_HDDETECTED_THRESHOLD_RANGE_MIN (0)
#define PROP_HD_LEVEL_HDDETECTED_THRESHOLD_HDDETECTED_THRESHOLD_RANGE_MAX (100)
#define PROP_HD_LEVEL_FILTER_TIME_CONSTANT_MASK 0xFFFF
#define PROP_HD_LEVEL_FILTER_TIME_CONSTANT_INDEX 0x02
#define PROP_HD_LEVEL_FILTER_TIME_CONSTANT_GROUP 0x9D
#define PROP_HD_LEVEL_FILTER_TIME_CONSTANT_value() (sys_prop_ReturnProperty(PROP_HD_LEVEL_FILTER_TIME_CONSTANT_GROUP, PROP_HD_LEVEL_FILTER_TIME_CONSTANT_INDEX))
#define PROP_HD_LEVEL_FILTER_TIME_CONSTANT_FILTER_TIME_CONSTANT_LSB 0
#define PROP_HD_LEVEL_FILTER_TIME_CONSTANT_FILTER_TIME_CONSTANT_MSB 7
#define PROP_HD_LEVEL_FILTER_TIME_CONSTANT_FILTER_TIME_CONSTANT_MASK 0xFF
#define PROP_HD_LEVEL_FILTER_TIME_CONSTANT_FILTER_TIME_CONSTANT_value() (uint8_t)(((PROP_HD_LEVEL_FILTER_TIME_CONSTANT_value()) & 0xFF)>>0)
#define PROP_HD_LEVEL_FILTER_TIME_CONSTANT_FILTER_TIME_CONSTANT_RANGE_MIN (1)
#define PROP_HD_LEVEL_FILTER_TIME_CONSTANT_FILTER_TIME_CONSTANT_RANGE_MAX (255)
#define PROP_HD_LEVEL_FILTER_TIME_CONSTANT_DEFAULT 0x20
#define PROP_HD_ENHANCED_STREAM_HOLDOFF_CONFIG_MASK 0xFFFF
#define PROP_HD_ENHANCED_STREAM_HOLDOFF_CONFIG_INDEX 0x00
#define PROP_HD_ENHANCED_STREAM_HOLDOFF_CONFIG_GROUP 0x9F
#define PROP_HD_ENHANCED_STREAM_HOLDOFF_CONFIG_value() (sys_prop_ReturnProperty(PROP_HD_ENHANCED_STREAM_HOLDOFF_CONFIG_GROUP, PROP_HD_ENHANCED_STREAM_HOLDOFF_CONFIG_INDEX))
#define PROP_HD_ENHANCED_STREAM_HOLDOFF_CONFIG_ENABLE_LSB 0
#define PROP_HD_ENHANCED_STREAM_HOLDOFF_CONFIG_ENABLE_MSB 0
#define PROP_HD_ENHANCED_STREAM_HOLDOFF_CONFIG_ENABLE_MASK 0x1
#define PROP_HD_ENHANCED_STREAM_HOLDOFF_CONFIG_ENABLE_BIT 0x1
#define PROP_HD_ENHANCED_STREAM_HOLDOFF_CONFIG_ENABLE_value() (((PROP_HD_ENHANCED_STREAM_HOLDOFF_CONFIG_value()) & 0x1)>>0)
#define PROP_HD_ENHANCED_STREAM_HOLDOFF_CONFIG_DEFAULT 0

#define PROP_HD_ENHANCED_STREAM_HOLDOFF_THRESHOLDS_MASK 0xFFFF
#define PROP_HD_ENHANCED_STREAM_HOLDOFF_THRESHOLDS_INDEX 0x01
#define PROP_HD_ENHANCED_STREAM_HOLDOFF_THRESHOLDS_GROUP 0x9F
#define PROP_HD_ENHANCED_STREAM_HOLDOFF_THRESHOLDS_value() (sys_prop_ReturnProperty(PROP_HD_ENHANCED_STREAM_HOLDOFF_THRESHOLDS_GROUP, PROP_HD_ENHANCED_STREAM_HOLDOFF_THRESHOLDS_INDEX))
#define PROP_HD_ENHANCED_STREAM_HOLDOFF_THRESHOLDS_ALLDIG_LSB 8
#define PROP_HD_ENHANCED_STREAM_HOLDOFF_THRESHOLDS_ALLDIG_MSB 15
#define PROP_HD_ENHANCED_STREAM_HOLDOFF_THRESHOLDS_ALLDIG_MASK 0xFF00
#define PROP_HD_ENHANCED_STREAM_HOLDOFF_THRESHOLDS_ALLDIG_value() (uint8_t)(((PROP_HD_ENHANCED_STREAM_HOLDOFF_THRESHOLDS_value()) & 0xFF00)>>8)
#define PROP_HD_ENHANCED_STREAM_HOLDOFF_THRESHOLDS_ALLDIG_RANGE_MIN (47)
#define PROP_HD_ENHANCED_STREAM_HOLDOFF_THRESHOLDS_ALLDIG_RANGE_MAX (80)
#define PROP_HD_ENHANCED_STREAM_HOLDOFF_THRESHOLDS_HYBRID_LSB 0
#define PROP_HD_ENHANCED_STREAM_HOLDOFF_THRESHOLDS_HYBRID_MSB 7
#define PROP_HD_ENHANCED_STREAM_HOLDOFF_THRESHOLDS_HYBRID_MASK 0xFF
#define PROP_HD_ENHANCED_STREAM_HOLDOFF_THRESHOLDS_HYBRID_value() (uint8_t)(((PROP_HD_ENHANCED_STREAM_HOLDOFF_THRESHOLDS_value()) & 0xFF)>>0)
#define PROP_HD_ENHANCED_STREAM_HOLDOFF_THRESHOLDS_HYBRID_RANGE_MIN (47)
#define PROP_HD_ENHANCED_STREAM_HOLDOFF_THRESHOLDS_HYBRID_RANGE_MAX (80)
#define PROP_HD_ENHANCED_STREAM_HOLDOFF_THRESHOLDS_DEFAULT 0x2F2F

#define PROP_DAB_DIGRAD_INTERRUPT_SOURCE_MASK 0xFFFF
#define PROP_DAB_DIGRAD_INTERRUPT_SOURCE_INDEX 0x00
#define PROP_DAB_DIGRAD_INTERRUPT_SOURCE_GROUP 0xB0
#define PROP_DAB_DIGRAD_INTERRUPT_SOURCE_value() (sys_prop_ReturnProperty(PROP_DAB_DIGRAD_INTERRUPT_SOURCE_GROUP, PROP_DAB_DIGRAD_INTERRUPT_SOURCE_INDEX))
#define PROP_DAB_DIGRAD_INTERRUPT_SOURCE_HARDMUTEIEN_LSB 4
#define PROP_DAB_DIGRAD_INTERRUPT_SOURCE_HARDMUTEIEN_MSB 4
#define PROP_DAB_DIGRAD_INTERRUPT_SOURCE_HARDMUTEIEN_MASK 0x10
#define PROP_DAB_DIGRAD_INTERRUPT_SOURCE_HARDMUTEIEN_BIT 0x10
#define PROP_DAB_DIGRAD_INTERRUPT_SOURCE_HARDMUTEIEN_value() (((PROP_DAB_DIGRAD_INTERRUPT_SOURCE_value()) & 0x10)>>4)
#define PROP_DAB_DIGRAD_INTERRUPT_SOURCE_FICERRIEN_LSB 3
#define PROP_DAB_DIGRAD_INTERRUPT_SOURCE_FICERRIEN_MSB 3
#define PROP_DAB_DIGRAD_INTERRUPT_SOURCE_FICERRIEN_MASK 0x8
#define PROP_DAB_DIGRAD_INTERRUPT_SOURCE_FICERRIEN_BIT 0x8
#define PROP_DAB_DIGRAD_INTERRUPT_SOURCE_FICERRIEN_value() (((PROP_DAB_DIGRAD_INTERRUPT_SOURCE_value()) & 0x8)>>3)
#define PROP_DAB_DIGRAD_INTERRUPT_SOURCE_ACQIEN_LSB 2
#define PROP_DAB_DIGRAD_INTERRUPT_SOURCE_ACQIEN_MSB 2
#define PROP_DAB_DIGRAD_INTERRUPT_SOURCE_ACQIEN_MASK 0x4
#define PROP_DAB_DIGRAD_INTERRUPT_SOURCE_ACQIEN_BIT 0x4
#define PROP_DAB_DIGRAD_INTERRUPT_SOURCE_ACQIEN_value() (((PROP_DAB_DIGRAD_INTERRUPT_SOURCE_value()) & 0x4)>>2)
#define PROP_DAB_DIGRAD_INTERRUPT_SOURCE_RSSIHIEN_LSB 1
#define PROP_DAB_DIGRAD_INTERRUPT_SOURCE_RSSIHIEN_MSB 1
#define PROP_DAB_DIGRAD_INTERRUPT_SOURCE_RSSIHIEN_MASK 0x2
#define PROP_DAB_DIGRAD_INTERRUPT_SOURCE_RSSIHIEN_BIT 0x2
#define PROP_DAB_DIGRAD_INTERRUPT_SOURCE_RSSIHIEN_value() (((PROP_DAB_DIGRAD_INTERRUPT_SOURCE_value()) & 0x2)>>1)
#define PROP_DAB_DIGRAD_INTERRUPT_SOURCE_RSSILIEN_LSB 0
#define PROP_DAB_DIGRAD_INTERRUPT_SOURCE_RSSILIEN_MSB 0
#define PROP_DAB_DIGRAD_INTERRUPT_SOURCE_RSSILIEN_MASK 0x1
#define PROP_DAB_DIGRAD_INTERRUPT_SOURCE_RSSILIEN_BIT 0x1
#define PROP_DAB_DIGRAD_INTERRUPT_SOURCE_RSSILIEN_value() (((PROP_DAB_DIGRAD_INTERRUPT_SOURCE_value()) & 0x1)>>0)
#define PROP_DAB_DIGRAD_INTERRUPT_SOURCE_DEFAULT 0

#define PROP_DAB_DIGRAD_RSSI_HIGH_THRESHOLD_MASK 0xFFFF
#define PROP_DAB_DIGRAD_RSSI_HIGH_THRESHOLD_INDEX 0x01
#define PROP_DAB_DIGRAD_RSSI_HIGH_THRESHOLD_GROUP 0xB0
#define PROP_DAB_DIGRAD_RSSI_HIGH_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_DAB_DIGRAD_RSSI_HIGH_THRESHOLD_GROUP, PROP_DAB_DIGRAD_RSSI_HIGH_THRESHOLD_INDEX))
#define PROP_DAB_DIGRAD_RSSI_HIGH_THRESHOLD_HIGH_THRESHOLD_LSB 0
#define PROP_DAB_DIGRAD_RSSI_HIGH_THRESHOLD_HIGH_THRESHOLD_MSB 7
#define PROP_DAB_DIGRAD_RSSI_HIGH_THRESHOLD_HIGH_THRESHOLD_MASK 0xFF
#define PROP_DAB_DIGRAD_RSSI_HIGH_THRESHOLD_HIGH_THRESHOLD_value() (int8_t)(((PROP_DAB_DIGRAD_RSSI_HIGH_THRESHOLD_value()) & 0xFF)>>0)
#define PROP_DAB_DIGRAD_RSSI_HIGH_THRESHOLD_HIGH_THRESHOLD_RANGE_MIN (-128)
#define PROP_DAB_DIGRAD_RSSI_HIGH_THRESHOLD_HIGH_THRESHOLD_RANGE_MAX (127)
#define PROP_DAB_DIGRAD_RSSI_HIGH_THRESHOLD_DEFAULT 127

#define PROP_DAB_DIGRAD_RSSI_LOW_THRESHOLD_MASK 0xFFFF
#define PROP_DAB_DIGRAD_RSSI_LOW_THRESHOLD_INDEX 0x02
#define PROP_DAB_DIGRAD_RSSI_LOW_THRESHOLD_GROUP 0xB0
#define PROP_DAB_DIGRAD_RSSI_LOW_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_DAB_DIGRAD_RSSI_LOW_THRESHOLD_GROUP, PROP_DAB_DIGRAD_RSSI_LOW_THRESHOLD_INDEX))
#define PROP_DAB_DIGRAD_RSSI_LOW_THRESHOLD_LOW_THRESHOLD_LSB 0
#define PROP_DAB_DIGRAD_RSSI_LOW_THRESHOLD_LOW_THRESHOLD_MSB 7
#define PROP_DAB_DIGRAD_RSSI_LOW_THRESHOLD_LOW_THRESHOLD_MASK 0xFF
#define PROP_DAB_DIGRAD_RSSI_LOW_THRESHOLD_LOW_THRESHOLD_value() (int8_t)(((PROP_DAB_DIGRAD_RSSI_LOW_THRESHOLD_value()) & 0xFF)>>0)
#define PROP_DAB_DIGRAD_RSSI_LOW_THRESHOLD_LOW_THRESHOLD_RANGE_MIN (-128)
#define PROP_DAB_DIGRAD_RSSI_LOW_THRESHOLD_LOW_THRESHOLD_RANGE_MAX (127)
#define PROP_DAB_DIGRAD_RSSI_LOW_THRESHOLD_DEFAULT -128

#define PROP_DAB_VALID_RSSI_TIME_MASK 0xFFFF
#define PROP_DAB_VALID_RSSI_TIME_INDEX 0x00
#define PROP_DAB_VALID_RSSI_TIME_GROUP 0xB2
#define PROP_DAB_VALID_RSSI_TIME_value() (sys_prop_ReturnProperty(PROP_DAB_VALID_RSSI_TIME_GROUP, PROP_DAB_VALID_RSSI_TIME_INDEX))
#define PROP_DAB_VALID_RSSI_TIME_MS_LSB 0
#define PROP_DAB_VALID_RSSI_TIME_MS_MSB 5
#define PROP_DAB_VALID_RSSI_TIME_MS_MASK 0x3F
#define PROP_DAB_VALID_RSSI_TIME_MS_value() (((PROP_DAB_VALID_RSSI_TIME_value()) & 0x3F)>>0)
#define PROP_DAB_VALID_RSSI_TIME_MS_RANGE_MIN (0)
#define PROP_DAB_VALID_RSSI_TIME_MS_RANGE_MAX (63)
#define PROP_DAB_VALID_RSSI_TIME_DEFAULT 30

#define PROP_DAB_VALID_RSSI_THRESHOLD_MASK 0xFFFF
#define PROP_DAB_VALID_RSSI_THRESHOLD_INDEX 0x01
#define PROP_DAB_VALID_RSSI_THRESHOLD_GROUP 0xB2
#define PROP_DAB_VALID_RSSI_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_DAB_VALID_RSSI_THRESHOLD_GROUP, PROP_DAB_VALID_RSSI_THRESHOLD_INDEX))
#define PROP_DAB_VALID_RSSI_THRESHOLD_LEVEL_LSB 0
#define PROP_DAB_VALID_RSSI_THRESHOLD_LEVEL_MSB 7
#define PROP_DAB_VALID_RSSI_THRESHOLD_LEVEL_MASK 0xFF
#define PROP_DAB_VALID_RSSI_THRESHOLD_LEVEL_value() (int8_t)(((PROP_DAB_VALID_RSSI_THRESHOLD_value()) & 0xFF)>>0)
#define PROP_DAB_VALID_RSSI_THRESHOLD_LEVEL_RANGE_MIN (-128)
#define PROP_DAB_VALID_RSSI_THRESHOLD_LEVEL_RANGE_MAX (127)
#define PROP_DAB_VALID_RSSI_THRESHOLD_DEFAULT 12

#define PROP_DAB_VALID_ACQ_TIME_MASK 0xFFFF
#define PROP_DAB_VALID_ACQ_TIME_INDEX 0x02
#define PROP_DAB_VALID_ACQ_TIME_GROUP 0xB2
#define PROP_DAB_VALID_ACQ_TIME_value() (sys_prop_ReturnProperty(PROP_DAB_VALID_ACQ_TIME_GROUP, PROP_DAB_VALID_ACQ_TIME_INDEX))
#define PROP_DAB_VALID_ACQ_TIME_MS_LSB 0
#define PROP_DAB_VALID_ACQ_TIME_MS_MSB 10
#define PROP_DAB_VALID_ACQ_TIME_MS_MASK 0x7FF
#define PROP_DAB_VALID_ACQ_TIME_MS_value() (((PROP_DAB_VALID_ACQ_TIME_value()) & 0x7FF)>>0)
#define PROP_DAB_VALID_ACQ_TIME_MS_RANGE_MIN (0)
#define PROP_DAB_VALID_ACQ_TIME_MS_RANGE_MAX (2047)
#define PROP_DAB_VALID_ACQ_TIME_DEFAULT 2000

#define PROP_DAB_VALID_SYNC_TIME_MASK 0xFFFF
#define PROP_DAB_VALID_SYNC_TIME_INDEX 0x03
#define PROP_DAB_VALID_SYNC_TIME_GROUP 0xB2
#define PROP_DAB_VALID_SYNC_TIME_value() (sys_prop_ReturnProperty(PROP_DAB_VALID_SYNC_TIME_GROUP, PROP_DAB_VALID_SYNC_TIME_INDEX))
#define PROP_DAB_VALID_SYNC_TIME_MS_LSB 0
#define PROP_DAB_VALID_SYNC_TIME_MS_MSB 10
#define PROP_DAB_VALID_SYNC_TIME_MS_MASK 0x7FF
#define PROP_DAB_VALID_SYNC_TIME_MS_value() (((PROP_DAB_VALID_SYNC_TIME_value()) & 0x7FF)>>0)
#define PROP_DAB_VALID_SYNC_TIME_MS_RANGE_MIN (0)
#define PROP_DAB_VALID_SYNC_TIME_MS_RANGE_MAX (2047)
#define PROP_DAB_VALID_SYNC_TIME_DEFAULT 1200

#define PROP_DAB_VALID_DETECT_TIME_MASK 0xFFFF
#define PROP_DAB_VALID_DETECT_TIME_INDEX 0x04
#define PROP_DAB_VALID_DETECT_TIME_GROUP 0xB2
#define PROP_DAB_VALID_DETECT_TIME_value() (sys_prop_ReturnProperty(PROP_DAB_VALID_DETECT_TIME_GROUP, PROP_DAB_VALID_DETECT_TIME_INDEX))
#define PROP_DAB_VALID_DETECT_TIME_MS_LSB 0
#define PROP_DAB_VALID_DETECT_TIME_MS_MSB 10
#define PROP_DAB_VALID_DETECT_TIME_MS_MASK 0x7FF
#define PROP_DAB_VALID_DETECT_TIME_MS_value() (((PROP_DAB_VALID_DETECT_TIME_value()) & 0x7FF)>>0)
#define PROP_DAB_VALID_DETECT_TIME_MS_RANGE_MIN (0)
#define PROP_DAB_VALID_DETECT_TIME_MS_RANGE_MAX (2047)
#define PROP_DAB_VALID_DETECT_TIME_DEFAULT 35

#define PROP_DAB_EVENT_INTERRUPT_SOURCE_MASK 0xFFFF
#define PROP_DAB_EVENT_INTERRUPT_SOURCE_INDEX 0x00
#define PROP_DAB_EVENT_INTERRUPT_SOURCE_GROUP 0xB3
#define PROP_DAB_EVENT_INTERRUPT_SOURCE_value() (sys_prop_ReturnProperty(PROP_DAB_EVENT_INTERRUPT_SOURCE_GROUP, PROP_DAB_EVENT_INTERRUPT_SOURCE_INDEX))
#define PROP_DAB_EVENT_INTERRUPT_SOURCE_RECFG_INTEN_LSB 7
#define PROP_DAB_EVENT_INTERRUPT_SOURCE_RECFG_INTEN_MSB 7
#define PROP_DAB_EVENT_INTERRUPT_SOURCE_RECFG_INTEN_MASK 0x80
#define PROP_DAB_EVENT_INTERRUPT_SOURCE_RECFG_INTEN_BIT 0x80
#define PROP_DAB_EVENT_INTERRUPT_SOURCE_RECFG_INTEN_value() (((PROP_DAB_EVENT_INTERRUPT_SOURCE_value()) & 0x80)>>7)
#define PROP_DAB_EVENT_INTERRUPT_SOURCE_RECFGWRN_INTEN_LSB 6
#define PROP_DAB_EVENT_INTERRUPT_SOURCE_RECFGWRN_INTEN_MSB 6
#define PROP_DAB_EVENT_INTERRUPT_SOURCE_RECFGWRN_INTEN_MASK 0x40
#define PROP_DAB_EVENT_INTERRUPT_SOURCE_RECFGWRN_INTEN_BIT 0x40
#define PROP_DAB_EVENT_INTERRUPT_SOURCE_RECFGWRN_INTEN_value() (((PROP_DAB_EVENT_INTERRUPT_SOURCE_value()) & 0x40)>>6)
#define PROP_DAB_EVENT_INTERRUPT_SOURCE_ANNO_INTEN_LSB 3
#define PROP_DAB_EVENT_INTERRUPT_SOURCE_ANNO_INTEN_MSB 3
#define PROP_DAB_EVENT_INTERRUPT_SOURCE_ANNO_INTEN_MASK 0x8
#define PROP_DAB_EVENT_INTERRUPT_SOURCE_ANNO_INTEN_BIT 0x8
#define PROP_DAB_EVENT_INTERRUPT_SOURCE_ANNO_INTEN_value() (((PROP_DAB_EVENT_INTERRUPT_SOURCE_value()) & 0x8)>>3)
#define PROP_DAB_EVENT_INTERRUPT_SOURCE_SERVLINK_INTEN_LSB 2
#define PROP_DAB_EVENT_INTERRUPT_SOURCE_SERVLINK_INTEN_MSB 2
#define PROP_DAB_EVENT_INTERRUPT_SOURCE_SERVLINK_INTEN_MASK 0x4
#define PROP_DAB_EVENT_INTERRUPT_SOURCE_SERVLINK_INTEN_BIT 0x4
#define PROP_DAB_EVENT_INTERRUPT_SOURCE_SERVLINK_INTEN_value() (((PROP_DAB_EVENT_INTERRUPT_SOURCE_value()) & 0x4)>>2)
#define PROP_DAB_EVENT_INTERRUPT_SOURCE_FREQINFO_INTEN_LSB 1
#define PROP_DAB_EVENT_INTERRUPT_SOURCE_FREQINFO_INTEN_MSB 1
#define PROP_DAB_EVENT_INTERRUPT_SOURCE_FREQINFO_INTEN_MASK 0x2
#define PROP_DAB_EVENT_INTERRUPT_SOURCE_FREQINFO_INTEN_BIT 0x2
#define PROP_DAB_EVENT_INTERRUPT_SOURCE_FREQINFO_INTEN_value() (((PROP_DAB_EVENT_INTERRUPT_SOURCE_value()) & 0x2)>>1)
#define PROP_DAB_EVENT_INTERRUPT_SOURCE_SRVLIST_INTEN_LSB 0
#define PROP_DAB_EVENT_INTERRUPT_SOURCE_SRVLIST_INTEN_MSB 0
#define PROP_DAB_EVENT_INTERRUPT_SOURCE_SRVLIST_INTEN_MASK 0x1
#define PROP_DAB_EVENT_INTERRUPT_SOURCE_SRVLIST_INTEN_BIT 0x1
#define PROP_DAB_EVENT_INTERRUPT_SOURCE_SRVLIST_INTEN_value() (((PROP_DAB_EVENT_INTERRUPT_SOURCE_value()) & 0x1)>>0)
#define PROP_DAB_EVENT_INTERRUPT_SOURCE_DEFAULT 0

#define PROP_DAB_EVENT_MIN_SVRLIST_PERIOD_MASK 0xFFFF
#define PROP_DAB_EVENT_MIN_SVRLIST_PERIOD_INDEX 0x01
#define PROP_DAB_EVENT_MIN_SVRLIST_PERIOD_GROUP 0xB3
#define PROP_DAB_EVENT_MIN_SVRLIST_PERIOD_value() (sys_prop_ReturnProperty(PROP_DAB_EVENT_MIN_SVRLIST_PERIOD_GROUP, PROP_DAB_EVENT_MIN_SVRLIST_PERIOD_INDEX))
#define PROP_DAB_EVENT_MIN_SVRLIST_PERIOD_MIN_SVRLIST_PERIOD_LSB 0
#define PROP_DAB_EVENT_MIN_SVRLIST_PERIOD_MIN_SVRLIST_PERIOD_MSB 15
#define PROP_DAB_EVENT_MIN_SVRLIST_PERIOD_MIN_SVRLIST_PERIOD_MASK 0xFFFF
#define PROP_DAB_EVENT_MIN_SVRLIST_PERIOD_MIN_SVRLIST_PERIOD_value() (((PROP_DAB_EVENT_MIN_SVRLIST_PERIOD_value()) & 0xFFFF)>>0)
#define PROP_DAB_EVENT_MIN_SVRLIST_PERIOD_DEFAULT 10

#define PROP_DAB_EVENT_MIN_SVRLIST_PERIOD_RECONFIG_MASK 0xFFFF
#define PROP_DAB_EVENT_MIN_SVRLIST_PERIOD_RECONFIG_INDEX 0x02
#define PROP_DAB_EVENT_MIN_SVRLIST_PERIOD_RECONFIG_GROUP 0xB3
#define PROP_DAB_EVENT_MIN_SVRLIST_PERIOD_RECONFIG_value() (sys_prop_ReturnProperty(PROP_DAB_EVENT_MIN_SVRLIST_PERIOD_RECONFIG_GROUP, PROP_DAB_EVENT_MIN_SVRLIST_PERIOD_RECONFIG_INDEX))
#define PROP_DAB_EVENT_MIN_SVRLIST_PERIOD_RECONFIG_MIN_SVRLIST_PERIOD_RECONFIG_LSB 0
#define PROP_DAB_EVENT_MIN_SVRLIST_PERIOD_RECONFIG_MIN_SVRLIST_PERIOD_RECONFIG_MSB 15
#define PROP_DAB_EVENT_MIN_SVRLIST_PERIOD_RECONFIG_MIN_SVRLIST_PERIOD_RECONFIG_MASK 0xFFFF
#define PROP_DAB_EVENT_MIN_SVRLIST_PERIOD_RECONFIG_MIN_SVRLIST_PERIOD_RECONFIG_value() (((PROP_DAB_EVENT_MIN_SVRLIST_PERIOD_RECONFIG_value()) & 0xFFFF)>>0)
#define PROP_DAB_EVENT_MIN_SVRLIST_PERIOD_RECONFIG_DEFAULT 10

#define PROP_DAB_EVENT_MIN_FREQINFO_PERIOD_MASK 0xFFFF
#define PROP_DAB_EVENT_MIN_FREQINFO_PERIOD_INDEX 0x03
#define PROP_DAB_EVENT_MIN_FREQINFO_PERIOD_GROUP 0xB3
#define PROP_DAB_EVENT_MIN_FREQINFO_PERIOD_value() (sys_prop_ReturnProperty(PROP_DAB_EVENT_MIN_FREQINFO_PERIOD_GROUP, PROP_DAB_EVENT_MIN_FREQINFO_PERIOD_INDEX))
#define PROP_DAB_EVENT_MIN_FREQINFO_PERIOD_MIN_FREQINFO_PERIOD_LSB 0
#define PROP_DAB_EVENT_MIN_FREQINFO_PERIOD_MIN_FREQINFO_PERIOD_MSB 15
#define PROP_DAB_EVENT_MIN_FREQINFO_PERIOD_MIN_FREQINFO_PERIOD_MASK 0xFFFF
#define PROP_DAB_EVENT_MIN_FREQINFO_PERIOD_MIN_FREQINFO_PERIOD_value() (((PROP_DAB_EVENT_MIN_FREQINFO_PERIOD_value()) & 0xFFFF)>>0)
#define PROP_DAB_EVENT_MIN_FREQINFO_PERIOD_DEFAULT 5

#define PROP_DAB_XPAD_ENABLE_MASK 0xFFFF
#define PROP_DAB_XPAD_ENABLE_INDEX 0x00
#define PROP_DAB_XPAD_ENABLE_GROUP 0xB4
#define PROP_DAB_XPAD_ENABLE_value() (sys_prop_ReturnProperty(PROP_DAB_XPAD_ENABLE_GROUP, PROP_DAB_XPAD_ENABLE_INDEX))
#define PROP_DAB_XPAD_ENABLE_ALL_OTHER_ENABLE_LSB 15
#define PROP_DAB_XPAD_ENABLE_ALL_OTHER_ENABLE_MSB 15
#define PROP_DAB_XPAD_ENABLE_ALL_OTHER_ENABLE_MASK 0x8000
#define PROP_DAB_XPAD_ENABLE_ALL_OTHER_ENABLE_BIT 0x8000
#define PROP_DAB_XPAD_ENABLE_ALL_OTHER_ENABLE_value() (((PROP_DAB_XPAD_ENABLE_value()) & 0x8000)>>15)
#define PROP_DAB_XPAD_ENABLE_JOURNALINE_ENABLE_LSB 13
#define PROP_DAB_XPAD_ENABLE_JOURNALINE_ENABLE_MSB 13
#define PROP_DAB_XPAD_ENABLE_JOURNALINE_ENABLE_MASK 0x2000
#define PROP_DAB_XPAD_ENABLE_JOURNALINE_ENABLE_BIT 0x2000
#define PROP_DAB_XPAD_ENABLE_JOURNALINE_ENABLE_value() (((PROP_DAB_XPAD_ENABLE_value()) & 0x2000)>>13)
#define PROP_DAB_XPAD_ENABLE_MIDDLEWARE_ENABLE_LSB 12
#define PROP_DAB_XPAD_ENABLE_MIDDLEWARE_ENABLE_MSB 12
#define PROP_DAB_XPAD_ENABLE_MIDDLEWARE_ENABLE_MASK 0x1000
#define PROP_DAB_XPAD_ENABLE_MIDDLEWARE_ENABLE_BIT 0x1000
#define PROP_DAB_XPAD_ENABLE_MIDDLEWARE_ENABLE_value() (((PROP_DAB_XPAD_ENABLE_value()) & 0x1000)>>12)
#define PROP_DAB_XPAD_ENABLE_VOICE_ENABLE_LSB 11
#define PROP_DAB_XPAD_ENABLE_VOICE_ENABLE_MSB 11
#define PROP_DAB_XPAD_ENABLE_VOICE_ENABLE_MASK 0x800
#define PROP_DAB_XPAD_ENABLE_VOICE_ENABLE_BIT 0x800
#define PROP_DAB_XPAD_ENABLE_VOICE_ENABLE_value() (((PROP_DAB_XPAD_ENABLE_value()) & 0x800)>>11)
#define PROP_DAB_XPAD_ENABLE_IPDC_ENABLE_LSB 10
#define PROP_DAB_XPAD_ENABLE_IPDC_ENABLE_MSB 10
#define PROP_DAB_XPAD_ENABLE_IPDC_ENABLE_MASK 0x400
#define PROP_DAB_XPAD_ENABLE_IPDC_ENABLE_BIT 0x400
#define PROP_DAB_XPAD_ENABLE_IPDC_ENABLE_value() (((PROP_DAB_XPAD_ENABLE_value()) & 0x400)>>10)
#define PROP_DAB_XPAD_ENABLE_DMB_ENABLE_LSB 9
#define PROP_DAB_XPAD_ENABLE_DMB_ENABLE_MSB 9
#define PROP_DAB_XPAD_ENABLE_DMB_ENABLE_MASK 0x200
#define PROP_DAB_XPAD_ENABLE_DMB_ENABLE_BIT 0x200
#define PROP_DAB_XPAD_ENABLE_DMB_ENABLE_value() (((PROP_DAB_XPAD_ENABLE_value()) & 0x200)>>9)
#define PROP_DAB_XPAD_ENABLE_DABJAVA_ENABLE_LSB 8
#define PROP_DAB_XPAD_ENABLE_DABJAVA_ENABLE_MSB 8
#define PROP_DAB_XPAD_ENABLE_DABJAVA_ENABLE_MASK 0x100
#define PROP_DAB_XPAD_ENABLE_DABJAVA_ENABLE_BIT 0x100
#define PROP_DAB_XPAD_ENABLE_DABJAVA_ENABLE_value() (((PROP_DAB_XPAD_ENABLE_value()) & 0x100)>>8)
#define PROP_DAB_XPAD_ENABLE_EPG_ENABLE_LSB 7
#define PROP_DAB_XPAD_ENABLE_EPG_ENABLE_MSB 7
#define PROP_DAB_XPAD_ENABLE_EPG_ENABLE_MASK 0x80
#define PROP_DAB_XPAD_ENABLE_EPG_ENABLE_BIT 0x80
#define PROP_DAB_XPAD_ENABLE_EPG_ENABLE_value() (((PROP_DAB_XPAD_ENABLE_value()) & 0x80)>>7)
#define PROP_DAB_XPAD_ENABLE_TMC_ENABLE_LSB 6
#define PROP_DAB_XPAD_ENABLE_TMC_ENABLE_MSB 6
#define PROP_DAB_XPAD_ENABLE_TMC_ENABLE_MASK 0x40
#define PROP_DAB_XPAD_ENABLE_TMC_ENABLE_BIT 0x40
#define PROP_DAB_XPAD_ENABLE_TMC_ENABLE_value() (((PROP_DAB_XPAD_ENABLE_value()) & 0x40)>>6)
#define PROP_DAB_XPAD_ENABLE_DGPS_ENABLE_LSB 5
#define PROP_DAB_XPAD_ENABLE_DGPS_ENABLE_MSB 5
#define PROP_DAB_XPAD_ENABLE_DGPS_ENABLE_MASK 0x20
#define PROP_DAB_XPAD_ENABLE_DGPS_ENABLE_BIT 0x20
#define PROP_DAB_XPAD_ENABLE_DGPS_ENABLE_value() (((PROP_DAB_XPAD_ENABLE_value()) & 0x20)>>5)
#define PROP_DAB_XPAD_ENABLE_TPEG_ENABLE_LSB 4
#define PROP_DAB_XPAD_ENABLE_TPEG_ENABLE_MSB 4
#define PROP_DAB_XPAD_ENABLE_TPEG_ENABLE_MASK 0x10
#define PROP_DAB_XPAD_ENABLE_TPEG_ENABLE_BIT 0x10
#define PROP_DAB_XPAD_ENABLE_TPEG_ENABLE_value() (((PROP_DAB_XPAD_ENABLE_value()) & 0x10)>>4)
#define PROP_DAB_XPAD_ENABLE_MOT_BWS_ENABLE_LSB 3
#define PROP_DAB_XPAD_ENABLE_MOT_BWS_ENABLE_MSB 3
#define PROP_DAB_XPAD_ENABLE_MOT_BWS_ENABLE_MASK 0x8
#define PROP_DAB_XPAD_ENABLE_MOT_BWS_ENABLE_BIT 0x8
#define PROP_DAB_XPAD_ENABLE_MOT_BWS_ENABLE_value() (((PROP_DAB_XPAD_ENABLE_value()) & 0x8)>>3)
#define PROP_DAB_XPAD_ENABLE_MOT_SLS_ENABLE_LSB 2
#define PROP_DAB_XPAD_ENABLE_MOT_SLS_ENABLE_MSB 2
#define PROP_DAB_XPAD_ENABLE_MOT_SLS_ENABLE_MASK 0x4
#define PROP_DAB_XPAD_ENABLE_MOT_SLS_ENABLE_BIT 0x4
#define PROP_DAB_XPAD_ENABLE_MOT_SLS_ENABLE_value() (((PROP_DAB_XPAD_ENABLE_value()) & 0x4)>>2)
#define PROP_DAB_XPAD_ENABLE_RFU_LSB 1
#define PROP_DAB_XPAD_ENABLE_RFU_MSB 1
#define PROP_DAB_XPAD_ENABLE_RFU_MASK 0x2
#define PROP_DAB_XPAD_ENABLE_RFU_BIT 0x2
#define PROP_DAB_XPAD_ENABLE_RFU_value() (((PROP_DAB_XPAD_ENABLE_value()) & 0x2)>>1)
#define PROP_DAB_XPAD_ENABLE_DLS_ENABLE_LSB 0
#define PROP_DAB_XPAD_ENABLE_DLS_ENABLE_MSB 0
#define PROP_DAB_XPAD_ENABLE_DLS_ENABLE_MASK 0x1
#define PROP_DAB_XPAD_ENABLE_DLS_ENABLE_BIT 0x1
#define PROP_DAB_XPAD_ENABLE_DLS_ENABLE_value() (((PROP_DAB_XPAD_ENABLE_value()) & 0x1)>>0)
#define PROP_DAB_XPAD_ENABLE_DEFAULT 1

#define PROP_DAB_DRC_OPTION_MASK 0xFFFF
#define PROP_DAB_DRC_OPTION_INDEX 0x01
#define PROP_DAB_DRC_OPTION_GROUP 0xB4
#define PROP_DAB_DRC_OPTION_value() (sys_prop_ReturnProperty(PROP_DAB_DRC_OPTION_GROUP, PROP_DAB_DRC_OPTION_INDEX))
#define PROP_DAB_DRC_OPTION_DRC_OPTION_LSB 0
#define PROP_DAB_DRC_OPTION_DRC_OPTION_MSB 1
#define PROP_DAB_DRC_OPTION_DRC_OPTION_MASK 0x3
#define PROP_DAB_DRC_OPTION_DRC_OPTION_value() (((PROP_DAB_DRC_OPTION_value()) & 0x3)>>0)
#define PROP_DAB_DRC_OPTION_DRC_OPTION_ENUM_DRC_OFF 0
#define PROP_DAB_DRC_OPTION_DRC_OPTION_ENUM_DRC_HALF_COMPRESSION 1
#define PROP_DAB_DRC_OPTION_DRC_OPTION_ENUM_DRC_FULL_COMPRESSION 2
#define PROP_DAB_DRC_OPTION_DRC_OPTION_ENUM_RESERVED 3
#define PROP_DAB_DRC_OPTION_DEFAULT 0

#define PROP_DAB_ACF_ENABLE_MASK 0xFFFF
#define PROP_DAB_ACF_ENABLE_INDEX 0x00
#define PROP_DAB_ACF_ENABLE_GROUP 0xB5
#define PROP_DAB_ACF_ENABLE_value() (sys_prop_ReturnProperty(PROP_DAB_ACF_ENABLE_GROUP, PROP_DAB_ACF_ENABLE_INDEX))
#define PROP_DAB_ACF_ENABLE_COMF_NOISE_ENABLE_LSB 1
#define PROP_DAB_ACF_ENABLE_COMF_NOISE_ENABLE_MSB 1
#define PROP_DAB_ACF_ENABLE_COMF_NOISE_ENABLE_MASK 0x2
#define PROP_DAB_ACF_ENABLE_COMF_NOISE_ENABLE_BIT 0x2
#define PROP_DAB_ACF_ENABLE_COMF_NOISE_ENABLE_value() (((PROP_DAB_ACF_ENABLE_value()) & 0x2)>>1)
#define PROP_DAB_ACF_ENABLE_COMF_NOISE_ENABLE_ENUM_COMF_NOISE_DISABLE 0
#define PROP_DAB_ACF_ENABLE_COMF_NOISE_ENABLE_ENUM_COMF_NOISE_ENABLE 1
#define PROP_DAB_ACF_ENABLE_SOFTMUTE_ENABLE_LSB 0
#define PROP_DAB_ACF_ENABLE_SOFTMUTE_ENABLE_MSB 0
#define PROP_DAB_ACF_ENABLE_SOFTMUTE_ENABLE_MASK 0x1
#define PROP_DAB_ACF_ENABLE_SOFTMUTE_ENABLE_BIT 0x1
#define PROP_DAB_ACF_ENABLE_SOFTMUTE_ENABLE_value() (((PROP_DAB_ACF_ENABLE_value()) & 0x1)>>0)
#define PROP_DAB_ACF_ENABLE_SOFTMUTE_ENABLE_ENUM_MUTE_DISABLE 0
#define PROP_DAB_ACF_ENABLE_SOFTMUTE_ENABLE_ENUM_MUTE_ENABLE 1
#define PROP_DAB_ACF_ENABLE_DEFAULT 3

#define PROP_DAB_ACF_MUTE_SIGLOSS_THRESHOLD_MASK 0xFFFF
#define PROP_DAB_ACF_MUTE_SIGLOSS_THRESHOLD_INDEX 0x01
#define PROP_DAB_ACF_MUTE_SIGLOSS_THRESHOLD_GROUP 0xB5
#define PROP_DAB_ACF_MUTE_SIGLOSS_THRESHOLD_value() (sys_prop_ReturnProperty(PROP_DAB_ACF_MUTE_SIGLOSS_THRESHOLD_GROUP, PROP_DAB_ACF_MUTE_SIGLOSS_THRESHOLD_INDEX))
#define PROP_DAB_ACF_MUTE_SIGLOSS_THRESHOLD_MUTE_SIGLOSS_THRESHOLD_LSB 0
#define PROP_DAB_ACF_MUTE_SIGLOSS_THRESHOLD_MUTE_SIGLOSS_THRESHOLD_MSB 15
#define PROP_DAB_ACF_MUTE_SIGLOSS_THRESHOLD_MUTE_SIGLOSS_THRESHOLD_MASK 0xFFFF
#define PROP_DAB_ACF_MUTE_SIGLOSS_THRESHOLD_MUTE_SIGLOSS_THRESHOLD_value() (((PROP_DAB_ACF_MUTE_SIGLOSS_THRESHOLD_value()) & 0xFFFF)>>0)
#define PROP_DAB_ACF_MUTE_SIGLOSS_THRESHOLD_DEFAULT 6

#define PROP_DAB_ACF_SOFTMUTE_BER_LIMITS_MASK 0xFFFF
#define PROP_DAB_ACF_SOFTMUTE_BER_LIMITS_INDEX 0x03
#define PROP_DAB_ACF_SOFTMUTE_BER_LIMITS_GROUP 0xB5
#define PROP_DAB_ACF_SOFTMUTE_BER_LIMITS_value() (sys_prop_ReturnProperty(PROP_DAB_ACF_SOFTMUTE_BER_LIMITS_GROUP, PROP_DAB_ACF_SOFTMUTE_BER_LIMITS_INDEX))
#define PROP_DAB_ACF_SOFTMUTE_BER_LIMITS_SOFTMUTE_BER_MAX_LSB 8
#define PROP_DAB_ACF_SOFTMUTE_BER_LIMITS_SOFTMUTE_BER_MAX_MSB 15
#define PROP_DAB_ACF_SOFTMUTE_BER_LIMITS_SOFTMUTE_BER_MAX_MASK 0xFF00
#define PROP_DAB_ACF_SOFTMUTE_BER_LIMITS_SOFTMUTE_BER_MAX_value() (int8_t)(((PROP_DAB_ACF_SOFTMUTE_BER_LIMITS_value()) & 0xFF00)>>8)
#define PROP_DAB_ACF_SOFTMUTE_BER_LIMITS_SOFTMUTE_BER_MAX_RANGE_MIN (-127)
#define PROP_DAB_ACF_SOFTMUTE_BER_LIMITS_SOFTMUTE_BER_MAX_RANGE_MAX (0)
#define PROP_DAB_ACF_SOFTMUTE_BER_LIMITS_SOFTMUTE_BER_MIN_LSB 0
#define PROP_DAB_ACF_SOFTMUTE_BER_LIMITS_SOFTMUTE_BER_MIN_MSB 7
#define PROP_DAB_ACF_SOFTMUTE_BER_LIMITS_SOFTMUTE_BER_MIN_MASK 0xFF
#define PROP_DAB_ACF_SOFTMUTE_BER_LIMITS_SOFTMUTE_BER_MIN_value() (int8_t)(((PROP_DAB_ACF_SOFTMUTE_BER_LIMITS_value()) & 0xFF)>>0)
#define PROP_DAB_ACF_SOFTMUTE_BER_LIMITS_SOFTMUTE_BER_MIN_RANGE_MIN (-127)
#define PROP_DAB_ACF_SOFTMUTE_BER_LIMITS_SOFTMUTE_BER_MIN_RANGE_MAX (0)
#define PROP_DAB_ACF_SOFTMUTE_BER_LIMITS_DEFAULT 0xe2a6

#define PROP_DAB_ACF_SOFTMUTE_ATTENUATION_LEVEL_MASK 0xFFFF
#define PROP_DAB_ACF_SOFTMUTE_ATTENUATION_LEVEL_INDEX 0x04
#define PROP_DAB_ACF_SOFTMUTE_ATTENUATION_LEVEL_GROUP 0xB5
#define PROP_DAB_ACF_SOFTMUTE_ATTENUATION_LEVEL_value() (sys_prop_ReturnProperty(PROP_DAB_ACF_SOFTMUTE_ATTENUATION_LEVEL_GROUP, PROP_DAB_ACF_SOFTMUTE_ATTENUATION_LEVEL_INDEX))
#define PROP_DAB_ACF_SOFTMUTE_ATTENUATION_LEVEL_ATTN_LEVEL_LSB 0
#define PROP_DAB_ACF_SOFTMUTE_ATTENUATION_LEVEL_ATTN_LEVEL_MSB 7
#define PROP_DAB_ACF_SOFTMUTE_ATTENUATION_LEVEL_ATTN_LEVEL_MASK 0xFF
#define PROP_DAB_ACF_SOFTMUTE_ATTENUATION_LEVEL_ATTN_LEVEL_value() (uint8_t)(((PROP_DAB_ACF_SOFTMUTE_ATTENUATION_LEVEL_value()) & 0xFF)>>0)
#define PROP_DAB_ACF_SOFTMUTE_ATTENUATION_LEVEL_ATTN_LEVEL_RANGE_MIN (0)
#define PROP_DAB_ACF_SOFTMUTE_ATTENUATION_LEVEL_ATTN_LEVEL_RANGE_MAX (90)
#define PROP_DAB_ACF_SOFTMUTE_ATTENUATION_LEVEL_DEFAULT 80

#define PROP_DAB_ACF_SOFTMUTE_ATTACK_TIME_MASK 0xFFFF
#define PROP_DAB_ACF_SOFTMUTE_ATTACK_TIME_INDEX 0x05
#define PROP_DAB_ACF_SOFTMUTE_ATTACK_TIME_GROUP 0xB5
#define PROP_DAB_ACF_SOFTMUTE_ATTACK_TIME_value() (sys_prop_ReturnProperty(PROP_DAB_ACF_SOFTMUTE_ATTACK_TIME_GROUP, PROP_DAB_ACF_SOFTMUTE_ATTACK_TIME_INDEX))
#define PROP_DAB_ACF_SOFTMUTE_ATTACK_TIME_ATTACK_TIME_LSB 0
#define PROP_DAB_ACF_SOFTMUTE_ATTACK_TIME_ATTACK_TIME_MSB 15
#define PROP_DAB_ACF_SOFTMUTE_ATTACK_TIME_ATTACK_TIME_MASK 0xFFFF
#define PROP_DAB_ACF_SOFTMUTE_ATTACK_TIME_ATTACK_TIME_value() (uint16_t)(((PROP_DAB_ACF_SOFTMUTE_ATTACK_TIME_value()) & 0xFFFF)>>0)
#define PROP_DAB_ACF_SOFTMUTE_ATTACK_TIME_DEFAULT 100

#define PROP_DAB_ACF_SOFTMUTE_RELEASE_TIME_MASK 0xFFFF
#define PROP_DAB_ACF_SOFTMUTE_RELEASE_TIME_INDEX 0x06
#define PROP_DAB_ACF_SOFTMUTE_RELEASE_TIME_GROUP 0xB5
#define PROP_DAB_ACF_SOFTMUTE_RELEASE_TIME_value() (sys_prop_ReturnProperty(PROP_DAB_ACF_SOFTMUTE_RELEASE_TIME_GROUP, PROP_DAB_ACF_SOFTMUTE_RELEASE_TIME_INDEX))
#define PROP_DAB_ACF_SOFTMUTE_RELEASE_TIME_RELEASE_TIME_LSB 0
#define PROP_DAB_ACF_SOFTMUTE_RELEASE_TIME_RELEASE_TIME_MSB 15
#define PROP_DAB_ACF_SOFTMUTE_RELEASE_TIME_RELEASE_TIME_MASK 0xFFFF
#define PROP_DAB_ACF_SOFTMUTE_RELEASE_TIME_RELEASE_TIME_value() (uint16_t)(((PROP_DAB_ACF_SOFTMUTE_RELEASE_TIME_value()) & 0xFFFF)>>0)
#define PROP_DAB_ACF_SOFTMUTE_RELEASE_TIME_DEFAULT 4000

#define PROP_DAB_ACF_CMFTNOISE_BER_LIMITS_MASK 0xFFFF
#define PROP_DAB_ACF_CMFTNOISE_BER_LIMITS_INDEX 0x07
#define PROP_DAB_ACF_CMFTNOISE_BER_LIMITS_GROUP 0xB5
#define PROP_DAB_ACF_CMFTNOISE_BER_LIMITS_value() (sys_prop_ReturnProperty(PROP_DAB_ACF_CMFTNOISE_BER_LIMITS_GROUP, PROP_DAB_ACF_CMFTNOISE_BER_LIMITS_INDEX))
#define PROP_DAB_ACF_CMFTNOISE_BER_LIMITS_CMFTNOISE_BER_MAX_LSB 8
#define PROP_DAB_ACF_CMFTNOISE_BER_LIMITS_CMFTNOISE_BER_MAX_MSB 15
#define PROP_DAB_ACF_CMFTNOISE_BER_LIMITS_CMFTNOISE_BER_MAX_MASK 0xFF00
#define PROP_DAB_ACF_CMFTNOISE_BER_LIMITS_CMFTNOISE_BER_MAX_value() (int8_t)(((PROP_DAB_ACF_CMFTNOISE_BER_LIMITS_value()) & 0xFF00)>>8)
#define PROP_DAB_ACF_CMFTNOISE_BER_LIMITS_CMFTNOISE_BER_MAX_RANGE_MIN (-127)
#define PROP_DAB_ACF_CMFTNOISE_BER_LIMITS_CMFTNOISE_BER_MAX_RANGE_MAX (0)
#define PROP_DAB_ACF_CMFTNOISE_BER_LIMITS_CMFTNOISE_BER_MIN_LSB 0
#define PROP_DAB_ACF_CMFTNOISE_BER_LIMITS_CMFTNOISE_BER_MIN_MSB 7
#define PROP_DAB_ACF_CMFTNOISE_BER_LIMITS_CMFTNOISE_BER_MIN_MASK 0xFF
#define PROP_DAB_ACF_CMFTNOISE_BER_LIMITS_CMFTNOISE_BER_MIN_value() (int8_t)(((PROP_DAB_ACF_CMFTNOISE_BER_LIMITS_value()) & 0xFF)>>0)
#define PROP_DAB_ACF_CMFTNOISE_BER_LIMITS_CMFTNOISE_BER_MIN_RANGE_MIN (-127)
#define PROP_DAB_ACF_CMFTNOISE_BER_LIMITS_CMFTNOISE_BER_MIN_RANGE_MAX (0)
#define PROP_DAB_ACF_CMFTNOISE_BER_LIMITS_DEFAULT 0xe2a6

#define PROP_DAB_ACF_CMFTNOISE_LEVEL_MASK 0xFFFF
#define PROP_DAB_ACF_CMFTNOISE_LEVEL_INDEX 0x08
#define PROP_DAB_ACF_CMFTNOISE_LEVEL_GROUP 0xB5
#define PROP_DAB_ACF_CMFTNOISE_LEVEL_value() (sys_prop_ReturnProperty(PROP_DAB_ACF_CMFTNOISE_LEVEL_GROUP, PROP_DAB_ACF_CMFTNOISE_LEVEL_INDEX))
#define PROP_DAB_ACF_CMFTNOISE_LEVEL_CMFTNOISE_LEVEL_LSB 0
#define PROP_DAB_ACF_CMFTNOISE_LEVEL_CMFTNOISE_LEVEL_MSB 15
#define PROP_DAB_ACF_CMFTNOISE_LEVEL_CMFTNOISE_LEVEL_MASK 0xFFFF
#define PROP_DAB_ACF_CMFTNOISE_LEVEL_CMFTNOISE_LEVEL_value() (uint16_t)(((PROP_DAB_ACF_CMFTNOISE_LEVEL_value()) & 0xFFFF)>>0)
#define PROP_DAB_ACF_CMFTNOISE_LEVEL_CMFTNOISE_LEVEL_RANGE_MIN (0)
#define PROP_DAB_ACF_CMFTNOISE_LEVEL_CMFTNOISE_LEVEL_RANGE_MAX (4000)
#define PROP_DAB_ACF_CMFTNOISE_LEVEL_DEFAULT 0x200

#define PROP_DAB_ACF_CMFTNOISE_ATTACK_TIME_MASK 0xFFFF
#define PROP_DAB_ACF_CMFTNOISE_ATTACK_TIME_INDEX 0x09
#define PROP_DAB_ACF_CMFTNOISE_ATTACK_TIME_GROUP 0xB5
#define PROP_DAB_ACF_CMFTNOISE_ATTACK_TIME_value() (sys_prop_ReturnProperty(PROP_DAB_ACF_CMFTNOISE_ATTACK_TIME_GROUP, PROP_DAB_ACF_CMFTNOISE_ATTACK_TIME_INDEX))
#define PROP_DAB_ACF_CMFTNOISE_ATTACK_TIME_ATTACK_TIME_LSB 0
#define PROP_DAB_ACF_CMFTNOISE_ATTACK_TIME_ATTACK_TIME_MSB 15
#define PROP_DAB_ACF_CMFTNOISE_ATTACK_TIME_ATTACK_TIME_MASK 0xFFFF
#define PROP_DAB_ACF_CMFTNOISE_ATTACK_TIME_ATTACK_TIME_value() (uint16_t)(((PROP_DAB_ACF_CMFTNOISE_ATTACK_TIME_value()) & 0xFFFF)>>0)
#define PROP_DAB_ACF_CMFTNOISE_ATTACK_TIME_DEFAULT 100
#define PROP_DAB_ACF_CMFTNOISE_RELEASE_TIME_MASK 0xFFFF
#define PROP_DAB_ACF_CMFTNOISE_RELEASE_TIME_INDEX 0x0A
#define PROP_DAB_ACF_CMFTNOISE_RELEASE_TIME_GROUP 0xB5
#define PROP_DAB_ACF_CMFTNOISE_RELEASE_TIME_value() (sys_prop_ReturnProperty(PROP_DAB_ACF_CMFTNOISE_RELEASE_TIME_GROUP, PROP_DAB_ACF_CMFTNOISE_RELEASE_TIME_INDEX))
#define PROP_DAB_ACF_CMFTNOISE_RELEASE_TIME_RELEASE_TIME_LSB 0
#define PROP_DAB_ACF_CMFTNOISE_RELEASE_TIME_RELEASE_TIME_MSB 15
#define PROP_DAB_ACF_CMFTNOISE_RELEASE_TIME_RELEASE_TIME_MASK 0xFFFF
#define PROP_DAB_ACF_CMFTNOISE_RELEASE_TIME_RELEASE_TIME_value() (uint16_t)(((PROP_DAB_ACF_CMFTNOISE_RELEASE_TIME_value()) & 0xFFFF)>>0)
#define PROP_DAB_ACF_CMFTNOISE_RELEASE_TIME_DEFAULT 4000

#define PROP_DAB_ANNOUNCEMENT_ENABLE_MASK 0xFFFF
#define PROP_DAB_ANNOUNCEMENT_ENABLE_INDEX 0x00
#define PROP_DAB_ANNOUNCEMENT_ENABLE_GROUP 0xB7
#define PROP_DAB_ANNOUNCEMENT_ENABLE_value() (sys_prop_ReturnProperty(PROP_DAB_ANNOUNCEMENT_ENABLE_GROUP, PROP_DAB_ANNOUNCEMENT_ENABLE_INDEX))
#define PROP_DAB_ANNOUNCEMENT_ENABLE_RESERVED5_LSB 15
#define PROP_DAB_ANNOUNCEMENT_ENABLE_RESERVED5_MSB 15
#define PROP_DAB_ANNOUNCEMENT_ENABLE_RESERVED5_MASK 0x8000
#define PROP_DAB_ANNOUNCEMENT_ENABLE_RESERVED5_BIT 0x8000
#define PROP_DAB_ANNOUNCEMENT_ENABLE_RESERVED5_value() (((PROP_DAB_ANNOUNCEMENT_ENABLE_value()) & 0x8000)>>15)
#define PROP_DAB_ANNOUNCEMENT_ENABLE_RESERVED4_LSB 14
#define PROP_DAB_ANNOUNCEMENT_ENABLE_RESERVED4_MSB 14
#define PROP_DAB_ANNOUNCEMENT_ENABLE_RESERVED4_MASK 0x4000
#define PROP_DAB_ANNOUNCEMENT_ENABLE_RESERVED4_BIT 0x4000
#define PROP_DAB_ANNOUNCEMENT_ENABLE_RESERVED4_value() (((PROP_DAB_ANNOUNCEMENT_ENABLE_value()) & 0x4000)>>14)
#define PROP_DAB_ANNOUNCEMENT_ENABLE_RESERVED3_LSB 13
#define PROP_DAB_ANNOUNCEMENT_ENABLE_RESERVED3_MSB 13
#define PROP_DAB_ANNOUNCEMENT_ENABLE_RESERVED3_MASK 0x2000
#define PROP_DAB_ANNOUNCEMENT_ENABLE_RESERVED3_BIT 0x2000
#define PROP_DAB_ANNOUNCEMENT_ENABLE_RESERVED3_value() (((PROP_DAB_ANNOUNCEMENT_ENABLE_value()) & 0x2000)>>13)
#define PROP_DAB_ANNOUNCEMENT_ENABLE_RESERVED2_LSB 12
#define PROP_DAB_ANNOUNCEMENT_ENABLE_RESERVED2_MSB 12
#define PROP_DAB_ANNOUNCEMENT_ENABLE_RESERVED2_MASK 0x1000
#define PROP_DAB_ANNOUNCEMENT_ENABLE_RESERVED2_BIT 0x1000
#define PROP_DAB_ANNOUNCEMENT_ENABLE_RESERVED2_value() (((PROP_DAB_ANNOUNCEMENT_ENABLE_value()) & 0x1000)>>12)
#define PROP_DAB_ANNOUNCEMENT_ENABLE_RESERVED1_LSB 11
#define PROP_DAB_ANNOUNCEMENT_ENABLE_RESERVED1_MSB 11
#define PROP_DAB_ANNOUNCEMENT_ENABLE_RESERVED1_MASK 0x800
#define PROP_DAB_ANNOUNCEMENT_ENABLE_RESERVED1_BIT 0x800
#define PROP_DAB_ANNOUNCEMENT_ENABLE_RESERVED1_value() (((PROP_DAB_ANNOUNCEMENT_ENABLE_value()) & 0x800)>>11)
#define PROP_DAB_ANNOUNCEMENT_ENABLE_FINANCIAL_LSB 10
#define PROP_DAB_ANNOUNCEMENT_ENABLE_FINANCIAL_MSB 10
#define PROP_DAB_ANNOUNCEMENT_ENABLE_FINANCIAL_MASK 0x400
#define PROP_DAB_ANNOUNCEMENT_ENABLE_FINANCIAL_BIT 0x400
#define PROP_DAB_ANNOUNCEMENT_ENABLE_FINANCIAL_value() (((PROP_DAB_ANNOUNCEMENT_ENABLE_value()) & 0x400)>>10)
#define PROP_DAB_ANNOUNCEMENT_ENABLE_FINANCIAL_ENUM_FINANCIAL_REPORT_DISABLE 0
#define PROP_DAB_ANNOUNCEMENT_ENABLE_FINANCIAL_ENUM_FINANCIAL_REPORT_ENABLE 1
#define PROP_DAB_ANNOUNCEMENT_ENABLE_SPORT_LSB 9
#define PROP_DAB_ANNOUNCEMENT_ENABLE_SPORT_MSB 9
#define PROP_DAB_ANNOUNCEMENT_ENABLE_SPORT_MASK 0x200
#define PROP_DAB_ANNOUNCEMENT_ENABLE_SPORT_BIT 0x200
#define PROP_DAB_ANNOUNCEMENT_ENABLE_SPORT_value() (((PROP_DAB_ANNOUNCEMENT_ENABLE_value()) & 0x200)>>9)
#define PROP_DAB_ANNOUNCEMENT_ENABLE_SPORT_ENUM_SPORT_REPORT_DISABLE 0
#define PROP_DAB_ANNOUNCEMENT_ENABLE_SPORT_ENUM_SPORT_REPORT_ENABLE 1
#define PROP_DAB_ANNOUNCEMENT_ENABLE_PROGRAM_LSB 8
#define PROP_DAB_ANNOUNCEMENT_ENABLE_PROGRAM_MSB 8
#define PROP_DAB_ANNOUNCEMENT_ENABLE_PROGRAM_MASK 0x100
#define PROP_DAB_ANNOUNCEMENT_ENABLE_PROGRAM_BIT 0x100
#define PROP_DAB_ANNOUNCEMENT_ENABLE_PROGRAM_value() (((PROP_DAB_ANNOUNCEMENT_ENABLE_value()) & 0x100)>>8)
#define PROP_DAB_ANNOUNCEMENT_ENABLE_PROGRAM_ENUM_PROGRAM_INFO_DISABLE 0
#define PROP_DAB_ANNOUNCEMENT_ENABLE_PROGRAM_ENUM_PROGRAM_INFO_ENABLE 1
#define PROP_DAB_ANNOUNCEMENT_ENABLE_SPECIAL_LSB 7
#define PROP_DAB_ANNOUNCEMENT_ENABLE_SPECIAL_MSB 7
#define PROP_DAB_ANNOUNCEMENT_ENABLE_SPECIAL_MASK 0x80
#define PROP_DAB_ANNOUNCEMENT_ENABLE_SPECIAL_BIT 0x80
#define PROP_DAB_ANNOUNCEMENT_ENABLE_SPECIAL_value() (((PROP_DAB_ANNOUNCEMENT_ENABLE_value()) & 0x80)>>7)
#define PROP_DAB_ANNOUNCEMENT_ENABLE_SPECIAL_ENUM_SPECIAL_EVENT_DISABLE 0
#define PROP_DAB_ANNOUNCEMENT_ENABLE_SPECIAL_ENUM_SPECIAL_EVENT_ENABLE 1
#define PROP_DAB_ANNOUNCEMENT_ENABLE_EVENT_LSB 6
#define PROP_DAB_ANNOUNCEMENT_ENABLE_EVENT_MSB 6
#define PROP_DAB_ANNOUNCEMENT_ENABLE_EVENT_MASK 0x40
#define PROP_DAB_ANNOUNCEMENT_ENABLE_EVENT_BIT 0x40
#define PROP_DAB_ANNOUNCEMENT_ENABLE_EVENT_value() (((PROP_DAB_ANNOUNCEMENT_ENABLE_value()) & 0x40)>>6)
#define PROP_DAB_ANNOUNCEMENT_ENABLE_EVENT_ENUM_EVENT_ANNOUNCEMENT_DISABLE 0
#define PROP_DAB_ANNOUNCEMENT_ENABLE_EVENT_ENUM_EVENT_ANNOUNCEMENT_ENABLE 1
#define PROP_DAB_ANNOUNCEMENT_ENABLE_WEATHER_LSB 5
#define PROP_DAB_ANNOUNCEMENT_ENABLE_WEATHER_MSB 5
#define PROP_DAB_ANNOUNCEMENT_ENABLE_WEATHER_MASK 0x20
#define PROP_DAB_ANNOUNCEMENT_ENABLE_WEATHER_BIT 0x20
#define PROP_DAB_ANNOUNCEMENT_ENABLE_WEATHER_value() (((PROP_DAB_ANNOUNCEMENT_ENABLE_value()) & 0x20)>>5)
#define PROP_DAB_ANNOUNCEMENT_ENABLE_WEATHER_ENUM_AREA_WEATHER_FLASH_DISABLE 0
#define PROP_DAB_ANNOUNCEMENT_ENABLE_WEATHER_ENUM_AREA_WEATHER_FLASH_ENABLE 1
#define PROP_DAB_ANNOUNCEMENT_ENABLE_NEWS_LSB 4
#define PROP_DAB_ANNOUNCEMENT_ENABLE_NEWS_MSB 4
#define PROP_DAB_ANNOUNCEMENT_ENABLE_NEWS_MASK 0x10
#define PROP_DAB_ANNOUNCEMENT_ENABLE_NEWS_BIT 0x10
#define PROP_DAB_ANNOUNCEMENT_ENABLE_NEWS_value() (((PROP_DAB_ANNOUNCEMENT_ENABLE_value()) & 0x10)>>4)
#define PROP_DAB_ANNOUNCEMENT_ENABLE_NEWS_ENUM_NEWS_FLASH_DISABLE 0
#define PROP_DAB_ANNOUNCEMENT_ENABLE_NEWS_ENUM_NEWS_FLASH_ENABLE 1
#define PROP_DAB_ANNOUNCEMENT_ENABLE_WARNING_LSB 3
#define PROP_DAB_ANNOUNCEMENT_ENABLE_WARNING_MSB 3
#define PROP_DAB_ANNOUNCEMENT_ENABLE_WARNING_MASK 0x8
#define PROP_DAB_ANNOUNCEMENT_ENABLE_WARNING_BIT 0x8
#define PROP_DAB_ANNOUNCEMENT_ENABLE_WARNING_value() (((PROP_DAB_ANNOUNCEMENT_ENABLE_value()) & 0x8)>>3)
#define PROP_DAB_ANNOUNCEMENT_ENABLE_WARNING_ENUM_WARNING_SERVICE_DISABLE 0
#define PROP_DAB_ANNOUNCEMENT_ENABLE_WARNING_ENUM_WARNING_SERVICE_ENABLE 1
#define PROP_DAB_ANNOUNCEMENT_ENABLE_TRANSPORT_LSB 2
#define PROP_DAB_ANNOUNCEMENT_ENABLE_TRANSPORT_MSB 2
#define PROP_DAB_ANNOUNCEMENT_ENABLE_TRANSPORT_MASK 0x4
#define PROP_DAB_ANNOUNCEMENT_ENABLE_TRANSPORT_BIT 0x4
#define PROP_DAB_ANNOUNCEMENT_ENABLE_TRANSPORT_value() (((PROP_DAB_ANNOUNCEMENT_ENABLE_value()) & 0x4)>>2)
#define PROP_DAB_ANNOUNCEMENT_ENABLE_TRANSPORT_ENUM_TRANSPORT_FLASH_DISABLE 0
#define PROP_DAB_ANNOUNCEMENT_ENABLE_TRANSPORT_ENUM_TRANSPORT_FLASH_ENABLE 1
#define PROP_DAB_ANNOUNCEMENT_ENABLE_TRAFFIC_LSB 1
#define PROP_DAB_ANNOUNCEMENT_ENABLE_TRAFFIC_MSB 1
#define PROP_DAB_ANNOUNCEMENT_ENABLE_TRAFFIC_MASK 0x2
#define PROP_DAB_ANNOUNCEMENT_ENABLE_TRAFFIC_BIT 0x2
#define PROP_DAB_ANNOUNCEMENT_ENABLE_TRAFFIC_value() (((PROP_DAB_ANNOUNCEMENT_ENABLE_value()) & 0x2)>>1)
#define PROP_DAB_ANNOUNCEMENT_ENABLE_TRAFFIC_ENUM_ROAD_TRAFFIC_FLASH_DISABLE 0
#define PROP_DAB_ANNOUNCEMENT_ENABLE_TRAFFIC_ENUM_ROAD_TRAFFIC_FLASH_ENABLE 1
#define PROP_DAB_ANNOUNCEMENT_ENABLE_ALARM_LSB 0
#define PROP_DAB_ANNOUNCEMENT_ENABLE_ALARM_MSB 0
#define PROP_DAB_ANNOUNCEMENT_ENABLE_ALARM_MASK 0x1
#define PROP_DAB_ANNOUNCEMENT_ENABLE_ALARM_BIT 0x1
#define PROP_DAB_ANNOUNCEMENT_ENABLE_ALARM_value() (((PROP_DAB_ANNOUNCEMENT_ENABLE_value()) & 0x1)>>0)
#define PROP_DAB_ANNOUNCEMENT_ENABLE_ALARM_ENUM_ALARM_DISABLE 0
#define PROP_DAB_ANNOUNCEMENT_ENABLE_ALARM_ENUM_ALARM_ENABLE 1
#define PROP_DAB_ANNOUNCEMENT_ENABLE_DEFAULT 0x07FF

#define PROP_DAB_TEST_BER_CONFIG_MASK 0xFFFF
#define PROP_DAB_TEST_BER_CONFIG_INDEX 0x00
#define PROP_DAB_TEST_BER_CONFIG_GROUP 0xE8
#define PROP_DAB_TEST_BER_CONFIG_value() (sys_prop_ReturnProperty(PROP_DAB_TEST_BER_CONFIG_GROUP, PROP_DAB_TEST_BER_CONFIG_INDEX))
#define PROP_DAB_TEST_BER_CONFIG_ENABLE_LSB 8
#define PROP_DAB_TEST_BER_CONFIG_ENABLE_MSB 8
#define PROP_DAB_TEST_BER_CONFIG_ENABLE_MASK 0x100
#define PROP_DAB_TEST_BER_CONFIG_ENABLE_BIT 0x100
#define PROP_DAB_TEST_BER_CONFIG_ENABLE_value() (((PROP_DAB_TEST_BER_CONFIG_value()) & 0x100)>>8)
#define PROP_DAB_TEST_BER_CONFIG_PATTERN_LSB 0
#define PROP_DAB_TEST_BER_CONFIG_PATTERN_MSB 7
#define PROP_DAB_TEST_BER_CONFIG_PATTERN_MASK 0xFF
#define PROP_DAB_TEST_BER_CONFIG_PATTERN_value() (((PROP_DAB_TEST_BER_CONFIG_value()) & 0xFF)>>0)
#define PROP_DAB_TEST_BER_CONFIG_DEFAULT 0

#define PROP_HD_TEST_BER_CONFIG_MASK 0xFFFF
#define PROP_HD_TEST_BER_CONFIG_INDEX 0x00
#define PROP_HD_TEST_BER_CONFIG_GROUP 0xE8
#define PROP_HD_TEST_BER_CONFIG_value() (sys_prop_ReturnProperty(PROP_HD_TEST_BER_CONFIG_GROUP, PROP_HD_TEST_BER_CONFIG_INDEX))
#define PROP_HD_TEST_BER_CONFIG_ENABLE_LSB 0
#define PROP_HD_TEST_BER_CONFIG_ENABLE_MSB 0
#define PROP_HD_TEST_BER_CONFIG_ENABLE_MASK 0x1
#define PROP_HD_TEST_BER_CONFIG_ENABLE_BIT 0x1
#define PROP_HD_TEST_BER_CONFIG_ENABLE_value() (((PROP_HD_TEST_BER_CONFIG_value()) & 0x1)>>0)
#define PROP_HD_TEST_BER_CONFIG_DEFAULT 0

#define PROP_HD_TEST_DEBUG_AUDIO_MASK 0xFFFF
#define PROP_HD_TEST_DEBUG_AUDIO_INDEX 0x01
#define PROP_HD_TEST_DEBUG_AUDIO_GROUP 0xE8
#define PROP_HD_TEST_DEBUG_AUDIO_value() (sys_prop_ReturnProperty(PROP_HD_TEST_DEBUG_AUDIO_GROUP, PROP_HD_TEST_DEBUG_AUDIO_INDEX))
#define PROP_HD_TEST_DEBUG_AUDIO_TESTMODE_LSB 0
#define PROP_HD_TEST_DEBUG_AUDIO_TESTMODE_MSB 1
#define PROP_HD_TEST_DEBUG_AUDIO_TESTMODE_MASK 0x3
#define PROP_HD_TEST_DEBUG_AUDIO_TESTMODE_value() (((PROP_HD_TEST_DEBUG_AUDIO_value()) & 0x3)>>0)
#define PROP_HD_TEST_DEBUG_AUDIO_DEFAULT 0

