/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   initial definitions for V4L2 implementation fof RDS (android)
   FILE: RDS_V4L2_Headers.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#ifndef __VIDEO_4_LINUX_RDS_BUFFER__
#define __VIDEO_4_LINUX_RDS_BUFFER__

// RDS type descriptors for the V4L2 implementation of the "RAW" RDS buffer
//*****************************************************************************
#ifdef OPTION__RDS_BUFFER_V4L2
struct v4l2_rds_data
{
	uint8_t lsb; //Least Significant Byte of RDS Block
	uint8_t msb; //Most Significant Byte of RDS Block
	uint8_t block; //The description for the included block.
};


#define V4L2_RDS_BLOCK_MSK 7 //Mask for bits 0-2 to get the block ID.
#define V4L2_RDS_BLOCK_A 0 //Block A.
#define V4L2_RDS_BLOCK_B 1 //Block B.
#define V4L2_RDS_BLOCK_C 2 //Block C.
#define V4L2_RDS_BLOCK_D 3 //Block D.
#define V4L2_RDS_BLOCK_C_ALT 4 //Block C'.
#define V4L2_RDS_BLOCK_INVALID 7 //An invalid block.
#define V4L2_RDS_BLOCK_CORRECTED 0x40 //A bit error was detected but corrected.
#define V4L2_RDS_BLOCK_ERROR 0x80 //An uncorrectable error occurred.

#endif //OPTION__RDS_BUFFER_V4L2

#endif