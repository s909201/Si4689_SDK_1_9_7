/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   lcd driver for C8051F380 based module
   FILE: lcd.c
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

#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI

#include <string.h>

#include "sys.h"
#include "delay.h"
#include "LCD.h"
#include "main.h"
#include "si46xx_firmware_api.h"
#include <character.h>
//extern code u8 EBU_UP_128_BITMAPS[];
/*********************************************************************/
//ucs2 is contain of two bytes
//In order to compatiable with ASCII.
//the high 8bit of UCS2 code is alway a zero and the low 8bit is same as ascii 
//but it seem there are some code is not equal to low 8bit 
//.so it must use a table for conversion,
/**********************************************************************/
#ifdef OPTION__INCLUDE_MODE__ANY
u8 UCS2_To_EBU(u8 len,u8* usc2_str,u8* ascii_str)
{
	u8 i,j;
	u16 temp;
	u8 ascii_str_len;
	ascii_str_len = 0;
	for(j=0;j<len;j+=2)
	{
		temp =((u16)usc2_str[j]<<8|usc2_str[j+1]);
		for(i=0;i<sizeof(EBU_TO_UCS2)/sizeof(EBU_TO_UCS2[0]);i++)
		{
			if(temp == EBU_TO_UCS2[i]) 
			{
				ascii_str[ascii_str_len++] = i+0x20;//put the ascii to group,0x20 = start index of EBU_TO_UCS2 table
				break;
			}
		}
	}
	return ascii_str_len;
}
#endif
#ifdef OPTION__INCLUDE_MODE__DAB
/*********************************************************************
the UTF8 code which under 0x80 is same as ascii
 bin 			HEX    UTF8
0000 0000-0000 007F | 0xxxxxxx
0000 0080-0000 07FF | 110xxxxx 10xxxxxx
0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
**********************************************************************/
u8 UTF8_To_EBU(u8 len,u8* utf8_str,u8* ascii_str)
{
	u8 i,j,k;
	u8 temp[4];
	u8 ucs2_temp[2];
	u8 ascii_str_len;
	ascii_str_len =0;
	for(i=0,j=0;i<len;i++,j++)
	{
		if(utf8_str[i]<0x80)//1byte
		{
			ascii_str[j] = utf8_str[i];
			ascii_str_len++;

            if(ascii_str[j] == 0x24)
            {
                //Special case for the '$' character being different in UTF8 vs UCS2 and EBU
                ascii_str[j] = 0xAB;
            }
		}
		else
		{
			if((utf8_str[i]&0xF0) == 0xF0)//4bytes
			{
				for(k=0;k<4;k++)
				{
					temp[k] = utf8_str[i+k];
				}
				i+=3;
				ucs2_temp[1] = 0;
				ucs2_temp[1] = (temp[3]&0x3F)|(temp[2]&0x03)<<6;

				ucs2_temp[0] = 0;
				ucs2_temp[0] = ((temp[2]&0x3c)>>2)|((temp[1]&0x0F)<<4);
				ucs2_temp[0] = ((temp[1]&0x30)>>4)|((temp[0]&0x07)<<2);

			}
			else if((utf8_str[i]&0xE0) == 0xE0)//3 bytes
			{
				for(k=0;k<3;k++)
				{
					temp[k] = utf8_str[i+k];
				}
				i+=2;
				ucs2_temp[1] = 0;
				ucs2_temp[1] = (temp[2]&0x3F)|(temp[1]&0x03)<<6;

				ucs2_temp[0] = 0;
				ucs2_temp[0] = ((temp[1]&0x3c)>>2)|((temp[0]&0x0F)<<4);
			}
			else if((utf8_str[i]&0xC0) == 0xC0)//2bytes
			{
				for(k=0;k<2;k++)
				{
					temp[k] = utf8_str[i+k];
				}
				i+=1;
				ucs2_temp[1] = 0;
				ucs2_temp[1] = (temp[1]&0x3F)|(temp[0]&0x03)<<6;

				ucs2_temp[0] = 0;
				ucs2_temp[0] = ((temp[0]&0x1c)>>2);
			}
			else
			{	
				;
			}
			//ucs2 to ascii
			ascii_str_len+=UCS2_To_EBU(1,ucs2_temp,&ascii_str[j]);
		}
	}
	return ascii_str_len;
}
#endif //OPTION__INCLUDE_MODE__DAB
/******************************************************************
load the define character array data into 1602
*******************************************************************/
code u8 DefineData[]={
						0x00,0x01,0x03,0x1D,0x15,0x1D,0x03,0x01,//"DEF_HORN",0
						0x00,0x00,0x11,0x0A,0x04,0x0A,0x11,0x00,//"DEF_DELETE",1
						0x00,0x0E,0x15,0x15,0x1D,0x11,0x11,0x0E,//"DEF_ALARM",2
						0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,//"DEF_FRECTANGLE",3
						0x00,0x00,0x1F,0x11,0x11,0x11,0x1F,0x00,//"DEF_SERECTANLG",4  small empty rec
						0x00,0x00,0x1F,0x1F,0x1F,0x1F,0x1F,0x00,//"DEF_SFRECTANGLE",5 small full rec
						0x1F,0x11,0x1F,0x1F,0x1F,0x1F,0x11,0x1F,//"DEF_SSFRECTANGLE",6
						0x1F,0x11,0x1F,0x11,0x11,0x1F,0x11,0x1F,//"DEF_SSERECTANGLE",7
					 };	
/*********************************************************************/
#ifdef PLATFORM_F380_MODULE

#define LCD_NOP	wait_us(2)
/*********************************************************************/

/**********************************************************************/
void LCD_WriteCommand(u8 cmd)
{
//	 LCD_CS = 1;
	 LCD_NOP;

	 LCD_RS = 0;
	 LCD_NOP;
	 LCD_RW = 0;
	 LCD_NOP;
	 LCD_EN = 1;
	 LCD_NOP;
	 P2 = cmd;
	 LCD_NOP;
	 LCD_NOP;
	 LCD_EN = 0;
	 LCD_NOP;
	 LCD_RW = 1;

	 LCD_NOP;
//	 LCD_CS = 0;
}
/*****************************************************/

/*****************************************************/
void LCD_WriteData(u8 Data)
{
//	 LCD_CS = 1;
	 LCD_NOP;

	 LCD_RS = 1;
	 LCD_NOP;
	 LCD_RW = 0;
	 LCD_NOP;
	 LCD_EN = 1;
	 LCD_NOP;
	 P2 = Data;
	 LCD_NOP;
	 LCD_NOP;
	 LCD_EN = 0;
	 LCD_NOP;
	 LCD_RW = 1;

	 LCD_NOP;
//	 LCD_CS = 0;
	 LCD_NOP;
}
/*****************************************************/

/*****************************************************/
void LCD_init(void)
{
	 LCD_WriteCommand(0x38); 
	 wait_ms(10);
	 LCD_WriteCommand(0x08); 
	 wait_ms(10);
	 LCD_WriteCommand(0x06); 
	 wait_ms(10);
	 LCD_WriteCommand(0x01); 
	 wait_ms(10);
	 LCD_WriteCommand(0x0c);

 	 DISP_BKLIGHT = LCD_BL_ON;
	 LCD_BL_flag = 1;

}
/*****************************************************/

/*****************************************************/
void LCD_Clear(u8 mode)
{
	if(mode == LCD_CLEAR_ALL)
	{
		LCD_WriteCommand(0x01);
		wait_ms(2);
	}
	else if(mode ==LCD_CLEAR_LINE1)
	{
		LCD_DisplayStr("                \n",0,0);
	}
	else //if(mode ==LCD_CLEAR_LINE2)
	{
		LCD_DisplayStr("                \n",0,1);
	}		
}
/**********************************************************

**********************************************************/
void set_address(u8 x,u8 y)
{
	y &= 0x1;
	x &= 0xf; 
	if (y)
	{ 
		x |= 0x40; 
	}
	LCD_WriteCommand(0x80|x);
}
/**********************************************************

**********************************************************/
void load_define_character_bitmap(u8 lcd_buf_index,  u8 code * array,u8 define_num)
{
	u8 i;
	u8 ram_addr;
	u16 temp;
	temp = define_num*8;
	ram_addr = 0x40+lcd_buf_index*8;//get the lcd buffer index
	LCD_WriteCommand(ram_addr);
	for(i=0;i<8;i++)
	{
		LCD_WriteData(array[temp+i]);
	}
}
/*****************************************************
position = 0 -31
*****************************************************/
void LCD_DisplayNum(u16 num,u8 x,u8 y)
{	
	u8 display_buffer[7]; 
 	char i; 

	set_address(x,y);

	for(i=6;i>=0;i--) 
	{ 
		display_buffer[i]='0'+num%10; 
		num/=10; 
	} 
	for(i=0;i<6;i++) 
	{ 
		if(display_buffer[i]!='0')break; 
	}
	for(;i<7;i++)
	{
		LCD_WriteData(display_buffer[i]);
	}

}

#ifdef OPTION__INCLUDE_MODE__FMHD
#ifdef OPTION__INCLUDE_FRONT_END_TEST_FUNCTIONS
void LCD_DisplayNum32(u32 num,u8 x,u8 y)
{	
	u8 display_buffer[12]; 
 	char i; 

	set_address(x,y);

	for(i=11;i>=0;i--) 
	{ 
		display_buffer[i]='0'+num%10; 
		num/=10; 
	} 
	for(i=0;i<11;i++) 
	{ 
		if(display_buffer[i]!='0')break; 
	}
	for(;i<12;i++)
	{
		LCD_WriteData(display_buffer[i]);
	}

}
#endif //OPTION__INCLUDE_FRONT_END_TEST_FUNCTIONS
#endif //OPTION__INCLUDE_MODE__FMHD
/******************************************************************
display user define character
*******************************************************************/
void LCD_DisplayCBD(u8 define_num,u8 x,u8 y)
{
	load_define_character_bitmap(define_num,DefineData,define_num);
	set_address(x,y);
	LCD_WriteData(define_num);	
}
#endif



#ifdef PLATFORM_F340_DEMOBOARD
/*****************************************************/
#define Slave       	0x7C
#define Comsend     	0x00
#define Datasend     	0x40
#define Wake        	0x30
#define Function     	0x31
#define Internalosc  	0x14
#define Powercontrol    0x56
#define Followercontrol 0x6D
#define Contrast        0x29
#define Displayon       0x0C
#define Entrymode       0x06
#define Clear       	0x01
#define Line2       	0xC0

/********************************************************
LCD show address DDRAM
0x80	0x81 ..0x8F;
0xC0	0xC1...0XCF
********************************************************/
void I2C_out(u8 j) //I2C Output
{
	u16 xdata n;
	u8 xdata d;
	d=j;
	for(n=0;n<8;n++){
		if((d&0x80)==0x80)
			SDA=1;
		else
			SDA=0;
		d=(d<<1);
		SCL = 0;
		SCL = 1;
		wait_us(20);
		SCL = 0;
	}
	SCL = 1;
    SDA = 1; 
	wait_us(10);
	SCL=0;
	SDA=0;
}

/************************************************************************/

/************************************************************************/
void I2C_Start(void)
{
	SCL=1;
	SDA=1;
	SDA=0;
	SCL=0;
}
/************************************************************************/

/************************************************************************/
void I2C_Stop(void)
{
	SDA=0;
	SCL=0;
	SCL=1;
	SDA=1;
}
/************************************************************************/

/************************************************************************/
void set_address(u8 x,u8 y)
{
	u8 address;

	address = x ;
	if( y>0 ){
		address+=0xC0;
	}else{
		address+=0x80;
	}
		
	I2C_Start();
	I2C_out(Slave);
	I2C_out(Comsend);
	I2C_out(address);
	I2C_Stop();
}
/************************************************************************/
//write one character to lcd 
/************************************************************************/
void LCD_WriteData(u8 str)
{
	I2C_Start();
	I2C_out(Slave);
	I2C_out(Datasend);
	I2C_out(str);
	I2C_Stop();
}	
/*************************************************************

***************************************************************/
void load_define_character_bitmap(u8 lcd_buf_index,u8* array,u8 define_num)
{
	u8 i;
	u8 ram_addr;
	u16 temp;

	ram_addr = 0x40;
	temp = define_num *8;

	I2C_Start();
	I2C_out(Slave);
	I2C_out(Comsend);
	I2C_out(0x38);////go to instructino table 0
	I2C_out(ram_addr+lcd_buf_index*8);
	I2C_Stop();

	wait_ms(1);

	I2C_Start();
	I2C_out(Slave);
	I2C_out(Datasend);

	for(i=0;i<8;i++)
	{	
		I2C_out(array[temp+i]);
	}
	I2C_Stop();
}		
/************************************************************************/

/************************************************************************/
void LCD_DisplayNum(u16 num,u8 x,u8 y)
{
 	char i; 
	u8 xdata display_buffer[8]; 
 	set_address(x,y);
	wait_ms(2);
	I2C_Start();
	I2C_out(Slave);
	I2C_out(Datasend);

	for(i=6;i>=0;i--) 
	{ 
		display_buffer[i]='0'+num%10; 
		num/=10; 
	} 
	for(i=0;i<6;i++) 
	{ 
		if(display_buffer[i]!='0')break; 
	}
	for(;i<7;i++)
	{
		I2C_out(display_buffer[i]);
	}
	I2C_Stop();
}
/************************************************************************/

/************************************************************************/
void LCD_init()
{

	DISP_RST  = 0;
	wait_ms(10);
	DISP_RST  = 1;
	DISP_BKLIGHT = LCD_BL_ON;

	LCD_BL_flag = 1;

	I2C_Start();
	I2C_out(Slave);
	I2C_out(Comsend);
	I2C_out(0x31);
	I2C_out(Internalosc);
	I2C_out(Contrast);
	I2C_out(Powercontrol);
	I2C_out(Followercontrol);
	I2C_out(Displayon);
	I2C_out(Entrymode);
	I2C_out(0x02);
	I2C_out(Clear);
	I2C_Stop();

}

/*************************************************************

***************************************************************/
void LCD_Clear(u8 mode)
{

	if(mode == LCD_CLEAR_ALL)
	{
			I2C_Start();
			I2C_out(Slave);
			I2C_out(Comsend);
			I2C_out(0x01);
			I2C_Stop();
			wait_ms(2);
	}
	else if(mode ==LCD_CLEAR_LINE1)
	{
		LCD_DisplayStr("                \n",0,0);
	}
	else //(mode ==LCD_CLEAR_LINE1)
	{
		LCD_DisplayStr("                \n",0,1);
	}


}
/******************************************************************
display user define character
*******************************************************************/
void LCD_DisplayCBD(u8 define_num,u8 x,u8 y)
{

	static u8 define_num_temp = 0;

	if(define_num_temp !=define_num)
	{
		define_num_temp = define_num;
		load_define_character_bitmap(define_num,DefineData,define_num);
	}

 	set_address(x,y);

	wait_ms(1);

	I2C_Start();
	I2C_out(Slave);
	I2C_out(Datasend);
	I2C_out(define_num);
	I2C_Stop();	
}
#endif
/************************************************************************
check if there are same bitmap stored in lcd buffer
*************************************************************************/
#define NO_SAME_BITMAP_AT_LCD_BUF 0xff
u8 check_lcd_buffer(u8* LCD_buf,u8* str)
{
	u8 i;
	for(i=0;i<8;i++)//the lcd only support displaying 8 self-define character at most at one time
	{
		if(LCD_buf[i] == *str )
		{
			return i;//return bitmap index of lcd buffer
		}
	}
	return NO_SAME_BITMAP_AT_LCD_BUF;//there are no same bitmap stored in lcd buffer
}
/************************************************************************
there are some character is difference between EBU and LCD BUFFER
so there 
*************************************************************************/
u8 LCD_to_EBU(u8* str,u8* index)
{
	u8 ret;
	ret = 1;
#ifdef OPTION__INCLUDE_MODE__DAB
	if(work_mode == dab)
	{
		switch(*str)
		{
			case 0x24:*index = 0;//return the table index							
				 break;
			case 0x5c:*index = 1;//return the table index
				 break;
			case 0x5e:*index = 2;//return the table index
				 break;
			case 0x60:*index = 3;//return the table index
				 break;
			case 0x7e:*index = 4;//return the table index
				 break;
			case 0x7f:*index = 5;//return the table index
				 break;
			default:ret =0;break;
		}
	}
#endif//OPTION__INCLUDE_MODE__DAB

#if defined(OPTION__INCLUDE_MODE__FM)||defined(OPTION__INCLUDE_MODE__AM)
	if(work_mode == fmonly ||work_mode == fmhd || work_mode == am || work_mode == amhd)
	{
		switch(*str)
		{
			case 0x5c:*index = 0;//return the table index
				 break;
			case 0x7e:*index = 1;//return the table index
				 break;
			case 0x7f:*index = 2;//return the table index
				 break;
			default:ret =0;break;
		}
	}	
#endif//OPTION__INCLUDE_MODE__FM
	return ret;
}	
/*******************************************************************************
position = 0 ~79 
*********************************************************************************/
void LCD_DisplayStr(u8 *str,u8 x,u8 y)
{
	u8 char_num = (16 - x);//one string can't overflow the screen from start point to the end point
	static u8 LCD_buf_id=0;
	u8 temp_id;
	u8 index;
	while(*str!='\n'&&char_num --)
	{
		if(*str<0x20)
		{
			set_address(x,y);
			*str = ' ';//can't support the low 0x32 character
			LCD_WriteData(*str);
		}
		else if(*str<0x80)//the bitmap of 126 127 index of 1602 is differece with EBU character 
		{
			if(LCD_to_EBU(str,&index))//check the character which's bitmap is differece with internal of LCD
			{
				temp_id = check_lcd_buffer(LCD_buf,str);//check if the bitmap have been stored in LCD buffer
				if(temp_id == NO_SAME_BITMAP_AT_LCD_BUF)
				{
					if(work_mode == dab)
					{
						load_define_character_bitmap(LCD_buf_id,LCD_to_EBU_BITMAPS,index);
					}
					else
					{
						load_define_character_bitmap(LCD_buf_id,LCD_to_IEC88591_BITMAP,index);
					}
					set_address(x,y);
					LCD_WriteData(LCD_buf_id);
					LCD_buf[LCD_buf_id]=*str;//store in LCD buffer
					LCD_buf_id++;
					LCD_buf_id&=0x07;
				}
				else
				{
					set_address(x,y);
					LCD_WriteData(temp_id);
				}						

			}
			else//the bitmap is same as internal of LCD
			{
				set_address(x,y);
				LCD_WriteData(*str);
			}
		}
		else
		{
#ifdef OPTION__INCLUDE_MODE__DAB
				if(work_mode == dab)//Those support EBU Characters
				{
					temp_id= check_lcd_buffer(LCD_buf,str);
					if(temp_id== NO_SAME_BITMAP_AT_LCD_BUF)//the self-define character is not in LCD buffer,need load the bitmap into buffer first
					{
					//high character index of the EBU  is from 0x80 to 0xff
					 	load_define_character_bitmap(LCD_buf_id,
													 EBU_UP_128_BITMAPS,
													 *str-0x80//return the table index
													 );
						set_address(x,y);

						LCD_WriteData(LCD_buf_id);
						LCD_buf[LCD_buf_id]=*str;//store in LCD buffer
						LCD_buf_id++;
						LCD_buf_id&=0x07;
					}
					else
					{
						set_address(x,y);
					// if the bitmap have been stored in lcd,
						LCD_WriteData(temp_id);//display pervious stored bitmap
					}
				}
#endif //OPTION__INCLUDE_MODE__DAB
#ifdef OPTION__INCLUDE_MODE__FM
				if(work_mode == fmonly || work_mode == fmhd || work_mode ==am||work_mode == amhd)//those mode support ISO/IEC-88591
				{
					//the lcd only support displaying 8 self-define character at most at one time
					temp_id= check_lcd_buffer(LCD_buf,str);
					//high character index of the ISO/IEC 88591  is from 0xa0 to0xff
					
					if(*str>=0xa0)
					{
						if(temp_id == NO_SAME_BITMAP_AT_LCD_BUF)
						{
							if(ISO_IEC_88591_TO_EBU_index[*str-0xa0]>=0x80)
							{
								load_define_character_bitmap(LCD_buf_id,//load the self-define into lcd buffer
															EBU_UP_128_BITMAPS,//lookup at EBU bitmap
															ISO_IEC_88591_TO_EBU_index[*str-0xa0]-0x80//return the table index
															);
							}
							else
							{
								load_define_character_bitmap(LCD_buf_id,//load the self-define into lcd buffer
															BitMap_88951_NO_IN_EBU,//lookup at NO EBU bitmap
															ISO_IEC_88591_TO_EBU_index[*str-0xa0]//return the table index
															);						
							}
							set_address(x,y);
							LCD_WriteData(LCD_buf_id);
							LCD_buf[LCD_buf_id]=*str;//store in LCD buffer
							LCD_buf_id++;
							LCD_buf_id&=0x07;

						}//end if(*str>=0xa0)
						else
						{
							set_address(x,y);
							LCD_WriteData(temp_id);
						}
					}//end if(*str>=0xa0)
				}
#endif //OPTION__INCLUDE_MODE__FM
		}//else	
		x++;
		*(str++);//move next character
	}//end while
}	
#else //not OPTION__OPERATE_AS_SLAVE_NO_MMI
//Driver stubs for when in slave mode
void LCD_DisplayStr(u8 *str,u8 x,u8 y)
{
    return;
}

void LCD_DisplayNum(u16 num,u8 x,u8 y)
{
    return;
}

#endif
	
			
