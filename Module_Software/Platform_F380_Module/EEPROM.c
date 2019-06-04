#include "typedefs.h"
#include "compiler_defs.h"

#include "EEPROM.h"

#ifdef PLATFORM_F380_MODULE

#include "delay.h"
#include "sys.h"
#include "C8051F380_defs.h"




#define EEPROM_PORT		P4
#define EEPROM_WC		0x80
#define EEPROM_SCLK		0x40
#define EEPROM_SDIO		0x20

#define EEPROM_WC_L		EEPROM_PORT &=~EEPROM_WC
#define EEPROM_WC_H   	EEPROM_PORT |= EEPROM_WC

#define EEPROM_SCLK_L	EEPROM_PORT &=~EEPROM_SCLK
#define EEPROM_SCLK_H   EEPROM_PORT |= EEPROM_SCLK

#define EEPROM_SDIO_L   EEPROM_PORT &=~EEPROM_SDIO
#define EEPROM_SDIO_H   EEPROM_PORT |= EEPROM_SDIO




#define EEPROM_DELAY		wait_us(10)
#define CHIP_ADDR			0xa0
#define EEPROM_I2C_OUT 		P4MDOUT
#define EEPROM_SDIO_HEX 	EEPROM_SDIO
#define EEPROM_SCLK_HEX 	EEPROM_SCLK
#define EEPROM_WC_HEX 		EEPROM_WC
#define WRITE				0
#define READ				1

/*************************************************************************************
I2C start condition
**************************************************************************************/
void eeprom_start(void)
{
//	EEPROM_SCLK_L;
//	EEPROM_DELAY;
	EEPROM_SDIO_H;
	EEPROM_DELAY;
	EEPROM_SCLK_H;

	EEPROM_DELAY;
	EEPROM_SDIO_L;
	EEPROM_DELAY;
	EEPROM_SCLK_L;
	EEPROM_DELAY;

}
/**************************************************************************************
I2C stop condition
***************************************************************************************/
void eeprom_stop(void)
{
	EEPROM_DELAY;
	EEPROM_SCLK_L;
	EEPROM_DELAY;
	EEPROM_SDIO_L;
	EEPROM_DELAY;
	EEPROM_SCLK_H;
	EEPROM_DELAY;
	EEPROM_SDIO_H;	
}
/*************************************************************************************
I2C ack  signal condition
**************************************************************************************/
void eeprom_ack(void)
{
	EEPROM_DELAY;
	EEPROM_SCLK_L;
	EEPROM_DELAY;
	EEPROM_SDIO_L;
	EEPROM_DELAY;
	EEPROM_SCLK_H;
	EEPROM_DELAY;
	EEPROM_DELAY;
	EEPROM_SCLK_L;

}
/**************************************************************************************
I2C none ack signal condition
***************************************************************************************/
void eeprom_nack(void)
{
	EEPROM_DELAY;
	EEPROM_SCLK_L;
	EEPROM_DELAY;
	EEPROM_SDIO_H;
	EEPROM_DELAY;
	EEPROM_SCLK_H;
	EEPROM_DELAY;
	EEPROM_DELAY;
	EEPROM_SCLK_L;
}
/***************************************************************************************
write the one byte  into eeprom 
***************************************************************************************/
void eeprom_write_byte(u8 in_byte)
{
	u8 i;
	for(i=0;i<8;i++)
	{
		EEPROM_SCLK_L;
		if(0x80&in_byte)
		{
			EEPROM_SDIO_H;
		}
		else
		{
			EEPROM_SDIO_L;
		}			
			
		EEPROM_DELAY;
		EEPROM_SCLK_H;
		EEPROM_DELAY;
		EEPROM_DELAY;
		EEPROM_SCLK_L;
		EEPROM_DELAY;
		in_byte <<=1;

	}
	//EEPROM_SDIO_H;
	EEPROM_I2C_OUT &= ~(EEPROM_SDIO_HEX);  // Configure SDIO as open-drain
	EEPROM_SDIO_H;
	EEPROM_SCLK_L;
	EEPROM_DELAY;
	EEPROM_DELAY;
	EEPROM_SCLK_H;
	EEPROM_DELAY;

	while(i)
	{
		i = EEPROM_SDIO&EEPROM_PORT;
		EEPROM_DELAY;
	}
	EEPROM_SCLK_L;
	EEPROM_I2C_OUT |= (EEPROM_SDIO_HEX);  // Configure SDIO as open-drain
	EEPROM_SDIO_L;

	EEPROM_DELAY;
}
/***************************************************************************************
read the one byte from eeprom
***************************************************************************************/
u8 eeprom_read_byte(void)
{
	u8 i;
	u8 out_data;
	out_data = 0;
	EEPROM_I2C_OUT &= ~(EEPROM_SDIO_HEX);  // Configure SDIO as open-drain
	EEPROM_SDIO_H;
	for(i=0;i<8;i++)
	{
		out_data <<=1;
		EEPROM_SCLK_L;
		if(EEPROM_SDIO&EEPROM_PORT)
		{
			out_data|=0x01;
		}
		EEPROM_DELAY;
		EEPROM_SCLK_H;
		EEPROM_DELAY;
		EEPROM_DELAY;
		EEPROM_SCLK_L;

	}
	EEPROM_I2C_OUT |=EEPROM_SDIO_HEX;
	return out_data;
}

/***************************************************************************************
write the seria data into eeprom 
there are 31 bytes at most writed into eeprom at once,
if the number of data exceed 31, then it must waits about 3ms for eeprom  to write and
send start signal again at next writing 
***************************************************************************************/

#define EEPROM_PAGE_BYTES	64
void eeprom_write(u16 address,u8* w_buffer,u16 len)
{
	u16 i,j;

	TR1 = 0;	// as the TGN module share the knobs pin with the EEPROM pin 
				// and the scaning action is triggered by Timer1 overflow
	EEPROM_I2C_OUT |=EEPROM_SCLK_HEX;
	EEPROM_I2C_OUT |=EEPROM_SDIO_HEX;
	EEPROM_I2C_OUT |=EEPROM_WC_HEX;

	EEPROM_WC_L;
	EEPROM_DELAY;
	if(len<EEPROM_PAGE_BYTES)
	{
		eeprom_start();
		eeprom_write_byte(CHIP_ADDR+WRITE);
		eeprom_write_byte((u8)(address>>8));
		eeprom_write_byte((u8)(address));
		for(i=0;i<len;i++)
		{
			eeprom_write_byte(w_buffer[i]);
		}
		eeprom_stop();
	}
	else
	{
		for(j=0;j<len;j+=EEPROM_PAGE_BYTES)
		{
			eeprom_start();
			eeprom_write_byte(CHIP_ADDR+WRITE);
			eeprom_write_byte((u8)(address>>8));
			eeprom_write_byte((u8)(address));
			for(i=j;i<(len<(EEPROM_PAGE_BYTES+j)?len:(EEPROM_PAGE_BYTES+j));i++)
			{
				eeprom_write_byte(w_buffer[i]);
			}
			eeprom_stop();
			wait_ms(20);//waitting for eeprom to write data into inside
		}
	}
	EEPROM_DELAY;
	EEPROM_WC_H;

	EEPROM_I2C_OUT &=~EEPROM_WC_HEX;
	EEPROM_WC_H;
	EEPROM_I2C_OUT &=~EEPROM_SCLK_HEX;
	EEPROM_SCLK_H;
	EEPROM_I2C_OUT &=~EEPROM_SDIO_HEX;
	EEPROM_SDIO_H;
	
				
	TR1 = 1;
}
/***************************************************************************************
read the seria data from eeprom
***************************************************************************************/
void eeprom_read(u16 address,u8* r_buffer,u16 len)
{
	u16 i;

	TR1 = 0;

	EEPROM_I2C_OUT |=EEPROM_SCLK_HEX;
	EEPROM_I2C_OUT |=EEPROM_SDIO_HEX;
	EEPROM_I2C_OUT |=EEPROM_WC_HEX;


	EEPROM_WC_L;
	EEPROM_DELAY;
	eeprom_start();
	eeprom_write_byte(CHIP_ADDR|WRITE);
	eeprom_write_byte((u8)(address>>8));
	eeprom_write_byte((u8)(address));
	eeprom_start();
	eeprom_write_byte(CHIP_ADDR|READ);
	for(i=0;i<len;i++)
	{
		r_buffer[i] = eeprom_read_byte();
		if(i==len-1)
		{
			eeprom_nack();
		}
		else
		{
			eeprom_ack();
		}
	}
	eeprom_stop();
	EEPROM_DELAY;
	EEPROM_WC_H;

	EEPROM_I2C_OUT &=~EEPROM_WC_HEX;
	EEPROM_WC_H;
	EEPROM_I2C_OUT &=~EEPROM_SCLK_HEX;
	EEPROM_SCLK_H;
	EEPROM_I2C_OUT &=~EEPROM_SDIO_HEX;
	EEPROM_SDIO_H;

	TR1 = 1;	// as the TGN module share the knobs pin with the EEPROM pin 
				// and the scaning action is triggered by Timer1 overflow
}


#endif