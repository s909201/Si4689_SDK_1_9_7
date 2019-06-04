/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   boot flash driver for C8051F380 based module
   FILE: SST25VF032B.c
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

/**************************************************************************************
SST25VF032B 32 Mbit(2M x 8) 串行Flash存储器
Read_Status_Register	读取状态寄存器
EWSR					使能写状态寄存器
WRSR					改写状态寄存器
WREN					写使能
WRDI					写禁止
EBSY					允许使用MISO 作为AAI模式下RY/BY#的输出脚
DBSY					禁止用MISO输出RY/BY#
HighSpeed_Read			读取一个字节(最大50Mhz时钟频率)并返回byte
HighSpeed_Read_Cont		连续读取(最大50 MHz时钟频率)
Byte_Program			写一个字节数据
Auto_Add_IncA			初始化Auto Address Increment(AAI)
Auto_Add_IncB			AAI初始化后进入Auto_Address_Increment(AAI)
Chip_Erase				擦除整个芯片
Block_Erase_32K			擦除一块32 KByte的区域
Block_Erase_64K			擦除一块64 KByte的区域
Wait_Busy				等待空闲(状态寄存器的BUSY位为0)
Wait_Busy_AAI			AAI模式下等待空闲
WREN_Check				检查WEL是否被置位
WREN_AAI_Check			检查WEL和AAI模式位被置位
**************************************************************************************/
#include "typedefs.h"
#include "compiler_defs.h"

#include "SST25VF032B.h"

#ifdef PLATFORM_F340_DEMOBOARD

#include "delay.h"
#include "sys.h"
#include "C8051F340_defs.h"

/*************************************************************************
/*函数名称：SST_SPIInit()
/*函数功能：SST25VF016B SPI总线初始化
/*输入参数：无
/*输出参数：无
*************************************************************************
void SST_SPIInit(void)
{
    SPI0CFG   = 0x40;
    SPI0CN    = 0x01;//使能SPI为主方式并使能SPI
	SPI0CKR   = 120;
	ESPI0 	  = 1;  //使能SPI中断
}
/************************************************************************/
/* 程序名称: Send_Byte													*/
/* 程序功能:在时钟的上升沿在MOSI线上写入一位数据,写满一个字节  			*/
/* 输入:out																*/
/* 输出:SI																*/
/************************************************************************/
void Send_Byte(u8 out)
{	
    u8 i;
 	for(i=0;i<8;i++)
	{
		SST_CLK	 = 0;
		_nop_();
		_nop_();
		SST_OUT = !!(out&0x80);
		out <<=1;
		_nop_();
		_nop_();
		SST_CLK  = 1;
	}
	
}
/************************************************************************/
/* 程序名称: Get_Byte													*/
/* 程序功能：在SCL的下降沿从MISO线上读取数据 							*/
/* 输入:	 SO															*/
/* 输出:	 None														*/
/**     **********************************************************************/
u8 Get_Byte(void)
{
	u8 i;
	u8 in;
	in = 0;
	for(i =0;i<8;i++)
	{
		in <<= 1;
		SST_CLK  = 0;
		_nop_();
		SST_CLK  = 1;
		_nop_();
		_nop_();
		in =in|(SST_IN&0x01);

	}
	return in;
}		
/************************************************************************/
/* 程序名称: SPI interrupt process										*/
/* 程序功能: SPI 收发数据产生的中断					*/
/* 输入:		None													*/
/* 返回:		byte													*/
/************************************************************************
void SPI_ISR() interrupt 6
{
	if(WCOL)//写冲突
		WCOL =0;  
	if(MODF)//模式错误
		MODF =0; 
	if(RXOVRN);//接收溢出
	SPIF=0;
}
/************************************************************************/
/* 程序名称: Read_Status_Register										*/
/* 程序功能: 用来读取状态寄存器,并返回状态寄存器的值					*/
/* 输入:		None													*/
/* 返回:		byte													*/
/************************************************************************/
u8 Read_Status_Register()
{
	u8 byte = 0;
	SST_CE =0;					/* 使能设备 */
	Send_Byte(0x05);		/* 发送读状态寄存器的命令 */
	byte = Get_Byte();		/* 读取状态寄存器 */
	SST_CE =1;					/* 禁止设备 */
	return byte;
}
/************************************************************************/
/* 程序名称: EWSR														*/
/* 程序功能: 使能改写状态寄存器操作  									*/
/* 输入:		None													*/
/* 返回:		Nothing													*/
/************************************************************************/
void EWSR()
{
	SST_CE =0;				/* 使能设备*/
	Send_Byte(0x50);	/* 发送使能写寄存器的命令 */
	SST_CE =1;				/* 禁止设备*/
}
/************************************************************************/
/* 程序名称: WRSR														*/
/* 程序功能: 往状态寄存器里写一个字节									*/
/* 输入:	 byte														*/
/* 返回:	 Nothing													*/
/************************************************************************/
void WRSR(u8 byte)
{
	SST_CE =0;			 /* 使能设备 */
	Send_Byte(0x01); /* 发送写状态寄存器 */
	Send_Byte(byte); /* 改变寄存器里BPx或者BPL (只有2,3,4,5,7位可以改写)*/
	SST_CE =1;			 /* 禁止设备 */
}
/************************************************************************/
/* 程序名称: WREN														*/
/* 程序功能: 写使能，同样可以用于使能写状态寄存器						*/
/* 输入:		None													*/
/* 返回:		Nothing													*/
/************************************************************************/
void WREN()
{
	SST_CE =0;			
	Send_Byte(0x06);		/* 发送WREN命令 */
	SST_CE =1;			
}
/************************************************************************/
/* 名称: WRDI															*/
/* 功能: 写禁止															*/
/* 输入:		None													*/
/* 返回:		Nothing													*/
/************************************************************************/
void WRDI()
{
	SST_CE =0;			
	Send_Byte(0x04);		/* 发送WRDI命令*/
	SST_CE =1;		
}
/************************************************************************/
/* 名称: EBSY															*/
/* 功能: 允许MISO在AAI模式期间输出RY/BY# 状态 							*/
/* 输入:		None													*/
/* 返回:		Nothing													*/
/************************************************************************/
void EBSY()
{
	SST_CE =0;			
	Send_Byte(0x70);		/* 发送EBSY命令*/
	SST_CE =1;		
}
/************************************************************************/
/* 名称: DBSY															*/
/* 功能: 禁止MISO在AAI模式下作为输出RY/BY#状态的信号					*/
/* 输入:		None													*/
/* 返回:		Nothing													*/
/************************************************************************/
void DBSY()
{
	SST_CE =0;		
	Send_Byte(0x80);		/* 发送DBSY命令 */
	SST_CE =1;		
}
/************************************************************************/
/* 名称: Wait_Busy														*/
/* 功能: 等待芯片空闲(在执行Byte-Program, Sector-Erase, Block-Erase		*/
/*		 Chip-Erase操作后)												*/
/* 输入: None															*/
/* 返回: Nothing														*/
/************************************************************************/
void Wait_Busy()
{
	while ((Read_Status_Register())&0x01 == 0x01);/* waste time until not busy */
	//	Read_Status_Register();
}

/************************************************************************/
/* 名称: Wait_Busy_AAI													*/
/* 功能:  在AAI模式下等待芯片空闲										*/
/* 输入:		None													*/
/* 返回:		Nothing													*/
/************************************************************************/
void Wait_Busy_AAI()
{
	while (Read_Status_Register()&0xC3 != 0x43);	/* 等待空闲 */
		//Read_Status_Register();
}

/************************************************************************/
/* 名称: WREN_Check														*/
/* 功能: 检查擦写操作前WEL位是否为1										*/
/* 输入:		None													*/
/* 返回:		Nothing													*/
/************************************************************************/
void WREN_Check()
{
	u8 byte;
	byte = Read_Status_Register();	/* 读取状态register */
	if ((byte&0x02) != 0x02)		/* 检查WEL位置位 */
	{
		WREN();
			//如果未置1进行相应处理,如对其进行写使得操作
	}
}

/*************************************************************************
/*函数名称：SST_Init()
/*函数功能：SST25VF016B 器件初始化
/*输入参数：无
/*输出参数：无
*************************************************************************/
void SST_Init(void)
{
SPI_IO_OUT;	
//	SST_SPIInit();//总线初始化
	WREN();//写使能
	EWSR();//使能改写状态寄存器操作 
	WRSR(0x02);//取消所有块保护
	DBSY();//禁止MISO在AAI模式下作为输出RY/BY#状态的信号
SPI_IO_IN;
}

/************************************************************************/
/* 名称: WREN_AAI_Check													*/
/* 功能: 在AAI模式下检查AAI和WEL位										*/
/************************************************************************/
void WREN_AAI_Check()
{
	u8 byte;
	byte = Read_Status_Register();	/*读取状态寄存器*/
	if (byte != 0x42)		/* 核实AAI 和 WEL位被置1 */
	{
		//while(1);		
		SST_Init();/*如果发生错误进行相应处理*/
	}
}


/************************************************************************/
/* 名称:  HighSpeed_Read_Cont											*/
/* 功能:  高速读取芯片连续地址的内容,最大可读取128字节					*/
/* 输入:  Dst:(目标地址 000000H - 1FFFFFH)								*/
/*        no_bytes:	读取字节数	(最大128字节)							*/
/*        upper_128[]: 读取数据存放地址指针                             */
/* 返回:  Nothing														*/
/************************************************************************/
void Group_Read_Flash(u32 Dst, u8 xdata * Rbuffer,u8 Len)
{
	u8 i = 0;
SPI_IO_OUT;	
	Wait_Busy();
	SST_CE =0; /* 芯片使能 */
	//Send_Byte(0x03); /* 发送读取指令 */
	Send_Byte(0x0B);
	Send_Byte((u8)(((Dst) & 0xFFFFFF) >> 16)); 
	Send_Byte((u8)(((Dst) & 0xFFFF) >> 8));
	Send_Byte((u8)(Dst) & 0xFF);

	Send_Byte(0xFF); /*虚拟字节*/
	for (i = 0; i < Len; i++) /* 读取Len字节*/
	{
		Rbuffer[i] = Get_Byte();	/*接收数据存入 SPI_Rbuffer */
	}
	SST_CE =1; /* 禁止芯片*/
SPI_IO_IN;
}

/************************************************************************/
/* 名称: Byte_Program													*/
/* 功能: 写一个字节数据,被写的地址必须被擦除及未被保护					*/				
/* 输入:																*/
/*		Dst:		(目标地址 000000H - 3FFFFFH)						*/
/*		byte:		数据												*/
/* 返回:																*/
/*		Nothing															*/
/************************************************************************/
void Byte_Write_Flash(u32  Dst, u8 Byte)
{
SPI_IO_OUT;	
	WREN();
	SST_CE =0;			/* 芯片使能 */
	Send_Byte(0x02); 	/* 发送写操作指令 */

	Send_Byte((u8)(((Dst) & 0xFFFFFF) >> 16)); 
	Send_Byte((u8)(((Dst) & 0xFFFF) >> 8));
	Send_Byte((u8)(Dst) & 0xFF);

	Send_Byte(Byte);	/*发送要写的数据*/
	//Send_Byte(0xcc);
	SST_CE =1;
	Wait_Busy();	
SPI_IO_IN;			
}

void Word_Write_Flash(u32 Dst,u8 Byte1,u8 Byte2)
{
SPI_IO_OUT;	
	WREN();//写使能
	SST_CE =0;				
	Send_Byte(0xAD);			/* 发送AAI命令*/

	Send_Byte((u8)(((Dst) & 0xFFFFFF) >> 16)); 
	Send_Byte((u8)(((Dst) & 0xFFFF) >> 8));
	Send_Byte((u8)(Dst) & 0xFF);

	Send_Byte(Byte1);	
	Send_Byte(Byte2);
	SST_CE = 1;
	Wait_Busy_AAI();
	WRDI();//退出写使能	
SPI_IO_IN;						
}
/************************************************************************/
/* 名称: Auto_Write_chip															*/
/* 功能: there are two mode in write action .one byte mode and word auto increment address mode 															*/
/* 输入:		data need to be write into flash,address,and leng													*/
/* 返回:		Nothing													*/
/************************************************************************/
void Group_Write_Flash(u32 Dst,u8 xdata * Wbuffer,u8 Len)
{
	u8 i;
SPI_IO_OUT;	
	if(Len == 1)
	{
		Byte_Write_Flash(Dst,Wbuffer[0]);
		return;
	}		
	WREN();//写使能
	SST_CE =0;				
	Send_Byte(0xAD);			/* 发送AAI命令*/

	Send_Byte((u8)(((Dst) & 0xFFFFFF) >> 16)); 
	Send_Byte((u8)(((Dst) & 0xFFFF) >> 8));
	Send_Byte((u8)(Dst) & 0xFF);

	for(i=0;i<Len;i+=2)
	{
		SST_CE = 0;
		if(i>0) Send_Byte(0xAD);
		Send_Byte(Wbuffer[i]);
		Send_Byte(Wbuffer[i+1]);
		//Send_Byte(0x01);
		//Send_Byte(0x10);
		SST_CE = 1;
		Wait_Busy_AAI();
		if(Len==i+2+1)//len ==i+2 that means only one byte leave need to write into flash
		{
			WRDI();//退出写使能
		//	Byte_Write_Flash(Dst+Len-1,Wbuffer[i+2]);
			Byte_Write_Flash(Dst+Len-1,Wbuffer[i+2]);


/*

	//WREN();
	SST_CE =0;		
	Send_Byte(0x02); 
	Send_Byte((u8)(((Dst+Len-1) & 0xFFFFFF) >> 16)); 
	Send_Byte((u8)(((Dst+Len-1) & 0xFFFF) >> 8));
	Send_Byte((u8)(Dst+Len-1) & 0xFF);
	//Send_Byte(Byte);	
	Send_Byte(Wbuffer[i+1]);
	SST_CE =1;
	Wait_Busy();	

*/
		}
	}
	SST_CE = 1;
	WRDI();//退出写使能

	Wait_Busy();
SPI_IO_IN;	
}
/************************************************************************/
/* 名称: Chip_Erase														*/
/* 功能: 擦除整个芯片													*/
/* 输入: None													        */
/* 返回: Nothing													    */
/************************************************************************/
void Chip_Erase()
{	
SPI_IO_OUT;						
	WREN_Check();
	SST_CE =0;			
	Send_Byte(0x60);			/* 发送 Chip Erase命令 (60h or C7h) */
	SST_CE =1;
	Wait_Busy();
SPI_IO_IN;	
}
/************************************************************************/
/* 名称: Chip_Erase														*/
/* 功能: 擦除BLOCK													*/
/* 输入: None													        */
/* 返回: Nothing													    */
/************************************************************************/
void Block_Erase_4K(u32 Dst)
{	
SPI_IO_OUT;				
	WREN_Check();
	SST_CE =0;			
	Send_Byte(0x20);			/* 发送 Chip Erase命令 */

	Send_Byte((u8)(((Dst) & 0xFFFFFF) >> 16)); 
	Send_Byte((u8)(((Dst) & 0xFFFF) >> 8));
	Send_Byte((u8)(Dst) & 0xFF);


	SST_CE =1;
	Wait_Busy();
SPI_IO_IN;	
}

#endif