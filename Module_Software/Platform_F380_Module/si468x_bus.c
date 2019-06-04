/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   control interface driver for C8051F380 based module
   FILE: si468x_bus.c
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#include "compiler_defs.h"
#include "typedefs.h"
#include <platform_options.h>

#ifdef PLATFORM_F380_MODULE
	#include "C8051F380_defs.h"
#endif
#ifdef PLATFORM_F340_DEMOBOARD
	#include "C8051F340_defs.h"
#endif


#include "sys.h"
#include "delay.h"
#include "si468x_bus.h"
#include "LCD.h"


#define WAIT 2
/************************************************************************

*************************************************************************/
void si468x_reset(void)
{
	si468x_RST = 0;
	wait_ms(100);
	si468x_RST = 1;
	wait_ms(200);
}

void si468x_disable(void)
{
   	si468x_RST = 0;
}

#ifdef PLATFORM_F380_MODULE

/************************************************************************

*************************************************************************/
#ifdef OPTION__MCU_HARDWARE_SPI
#define SPI_CLOCK	0
void spi0_init(void)
{
   SPI0CFG   = 0x40;                   // Enable the SPI as a Master
                                      // CKPHA = '0', CKPOL = '0'
   SPI0CN    = 0x01;                  // 3-wire Single Master, SPI enabled
   // SPI clock frequency equation from the datasheet
   SPI0CKR   = 11;//1MHz
   //SPI0_clk = SYSCLK/(2*(SPI0CKR+1))
 //  ESPI0 = 1;                          // Enable SPI interrupts
}
/************************************************************************
*************************************************************************/
void si468x_write(u8 in_data)
{
	SPIF = 0;
	SPI0DAT = in_data;
	while(!SPIF);
	SPIF = 0;
}
/************************************************************************
*************************************************************************/
u8 si468x_read(void)
{
	u8 wait_time_us = 200;
	SPIF = 0;
	SPI0DAT = 0xFF;
	while((!SPIF)&&(wait_time_us>10))
	{
		wait_us(10);
		wait_time_us-=10;
	}
	SPIF = 0;
	return SPI0DAT;
}
#endif //OPTION__MCU_HARDWARE_SPI
/************************************************************************

*************************************************************************/
#ifndef OPTION__MCU_HARDWARE_SPI
void si468x_write(u8 in_data)
{
	u8 i;
	for(i=0;i<8;i++)
	{
		si468x_SCLK = 0;
		NOP();
		si468x_MOSI = !!(0x80 & in_data);
		NOP();
		si468x_SCLK = 1;
		in_data <<=1;
	}
}
/************************************************************************

*************************************************************************/
u8 si468x_read(void)
{
	u8 i;
	u8 out_data;
	out_data = 0;
	for(i=0;i<8;i++)
	{
		out_data <<=1;
		si468x_SCLK = 0;
		NOP();
		si468x_SCLK = 1;
		NOP();
		out_data |= si468x_MISO;
		NOP();	
	}
	return out_data;
}
#endif //undef OPTION__MCU_HARDWARE_SPI

/************************************************************************

*************************************************************************/
void si468x_writeCommand (u16 len,u8* buffer)
{	
	u16 i;
	i = 0;
	si468x_SSB = 0;
	while(len--)
	{
		si468x_write(buffer[i++]);
	}
	si468x_SSB = 1;	
}
/************************************************************************

*************************************************************************/
void si468x_readReply (u16 len,u8* buffer)
{
	u16 i;
	i = 0;
	si468x_SSB = 1;
	wait_us(20);
	si468x_SSB = 0;
	si468x_write(0x00);
	while(len--)
	{
		buffer[i++]=si468x_read();
	}	
	si468x_SSB = 1;
}
#endif //PLATFORM_F380_MODULE


#ifdef PLATFORM_F340_DEMOBOARD


/************************************************************************

*************************************************************************/
void si468x_start(void)
{

	SCL = 1;
	wait_us(WAIT);

	SDA = 1;
	wait_us(WAIT);

	SDA = 0;
	wait_us(WAIT);

	SCL = 0;
	
	wait_us(WAIT);
}
/************************************************************************

*************************************************************************/
void si468x_write(u8 in_data)
{
	u8 i;

	SCL = 0;
	wait_us(WAIT);
	SDA = 0;

	for(i=0;i<8;i++)
	{
		SDA = !!(in_data&0x80);
		wait_us(WAIT);

		SCL = 1;
		wait_us(WAIT);
		SCL = 0;
		wait_us(WAIT);

		in_data <<= 1;		
	}
	SDA = 0;
	wait_us(WAIT);

	SDA_OUT &= ~(SDA_HEX);  // Configure SDIO as open-drain
	SDA = 1;
	SCL = 0;
	wait_us(WAIT);
	SCL = 1;
	wait_us(WAIT);
	while(SDA)
	{
		wait_us(10);
	}
	SCL = 0;
	SDA_OUT |= (SDA_HEX);  // Configure SDIO as open-drain
	SDA = 0;

	wait_us(WAIT);
}
/************************************************************************

*************************************************************************/
u8 si468x_read(void)
{
	u8 i;
	u8 out_data;
	out_data = 0;

    SDA_OUT &= ~(SDA_HEX);  // Configure SDIO as open-drain
    SDA = 1;                 // Configure SDIO as a digital input????????????????????????????
   
	for(i=0;i<8;i++)
	{
		out_data <<= 1;

		SCL = 0;
		wait_us(WAIT);

		SCL = 1;
		wait_us(WAIT);

		out_data |= SDA&0x01;

		wait_us(WAIT);
		
	}
	SCL = 0;
	wait_us(WAIT);
	SDA_OUT |= (SDA_HEX);  // Configure SDIO as push up
    SDA = 0; 
	return out_data;
}
void si468x_ack(void)
{
	SDA = 0;
	wait_us(WAIT);
	SCL = 1;
	wait_us(WAIT);
	SCL = 0;
}
void si468x_nack(void)
{
	SDA = 1;
	wait_us(WAIT);
	SCL = 1;
	wait_us(WAIT);
	SCL = 0;
	wait_us(WAIT);
	SDA = 0;
}
/************************************************************************

*************************************************************************/
void si468x_stop(void)
{
//	SCL = 0;
	wait_us(WAIT);

	SDA = 0;
	wait_us(WAIT);

	SCL = 1;
	wait_us(WAIT);
	SDA = 1;
}
/************************************************************************

*************************************************************************/
void si468x_writeCommand (u16 len,u8* buffer)
{	
	u16 i;
	si468x_start();
	si468x_write(CHIP_ADDRESS|I2C_WRITE);
	i = 0;
	while(i < len)
	{
		si468x_write(buffer[i++]);
	}
	si468x_stop();
}
/************************************************************************

*************************************************************************/
void si468x_readReply (u16 len,u8* buffer)
{
	u16 i;
    u8 rd_reply_cmd = 0x00;
    si468x_writeCommand(1,&rd_reply_cmd);
	si468x_start();
	si468x_write(CHIP_ADDRESS|I2C_READ);
	i = 0;
	while(i < len)
	{
		buffer[i++] = si468x_read();
		if(i!=len)
		{
			si468x_ack();
		}
	}
	si468x_nack();
	si468x_stop();
}
#endif //PLATFORM_F340_DEMOBOARD
