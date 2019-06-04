/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   header for control interface driver for C8051F380 based module
   FILE: si468x_bus.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#ifndef _si468x_bus_h_
#define _si468x_bus_h_



#ifdef PLATFORM_F340_DEMOBOARD
	#define WAIT_US  		20
	#define SDA_HEX  		0x08
	//#define SDA_OUT  		P2MOUT
	#define CHIP_ADDRESS 	0xC8

	#define I2C_WRITE 		0
	#define I2C_READ  		1
#endif

/************************************************************************

*************************************************************************/
void si468x_reset(void);
void si468x_disable(void);
void si468x_start(void);
void si468x_stop(void);
void spi0_init(void);
/************************************************************************

*************************************************************************/
void si468x_write(u8 in_data);
/************************************************************************

*************************************************************************/
u8 si468x_read(void);

/************************************************************************

*************************************************************************/
void si468x_writeCommand (u16 len,u8* buffer);
/************************************************************************

*************************************************************************/
void si468x_readReply (u16 len,u8* buffer);
#endif