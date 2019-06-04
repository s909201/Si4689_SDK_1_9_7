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
SST25VF032B 32 Mbit(2M x 8) ����Flash�洢��
Read_Status_Register	��ȡ״̬�Ĵ���
EWSR					ʹ��д״̬�Ĵ���
WRSR					��д״̬�Ĵ���
WREN					дʹ��
WRDI					д��ֹ
EBSY					����ʹ��MISO ��ΪAAIģʽ��RY/BY#�������
DBSY					��ֹ��MISO���RY/BY#
HighSpeed_Read			��ȡһ���ֽ�(���50Mhzʱ��Ƶ��)������byte
HighSpeed_Read_Cont		������ȡ(���50 MHzʱ��Ƶ��)
Byte_Program			дһ���ֽ�����
Auto_Add_IncA			��ʼ��Auto Address Increment(AAI)
Auto_Add_IncB			AAI��ʼ�������Auto_Address_Increment(AAI)
Chip_Erase				��������оƬ
Block_Erase_32K			����һ��32 KByte������
Block_Erase_64K			����һ��64 KByte������
Wait_Busy				�ȴ�����(״̬�Ĵ�����BUSYλΪ0)
Wait_Busy_AAI			AAIģʽ�µȴ�����
WREN_Check				���WEL�Ƿ���λ
WREN_AAI_Check			���WEL��AAIģʽλ����λ
**************************************************************************************/
#include "typedefs.h"
#include "compiler_defs.h"

#include "SST25VF032B.h"

#ifdef PLATFORM_F340_DEMOBOARD

#include "delay.h"
#include "sys.h"
#include "C8051F340_defs.h"

/*************************************************************************
/*�������ƣ�SST_SPIInit()
/*�������ܣ�SST25VF016B SPI���߳�ʼ��
/*�����������
/*�����������
*************************************************************************
void SST_SPIInit(void)
{
    SPI0CFG   = 0x40;
    SPI0CN    = 0x01;//ʹ��SPIΪ����ʽ��ʹ��SPI
	SPI0CKR   = 120;
	ESPI0 	  = 1;  //ʹ��SPI�ж�
}
/************************************************************************/
/* ��������: Send_Byte													*/
/* ������:��ʱ�ӵ���������MOSI����д��һλ����,д��һ���ֽ�  			*/
/* ����:out																*/
/* ���:SI																*/
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
/* ��������: Get_Byte													*/
/* �����ܣ���SCL���½��ش�MISO���϶�ȡ���� 							*/
/* ����:	 SO															*/
/* ���:	 None														*/
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
/* ��������: SPI interrupt process										*/
/* ������: SPI �շ����ݲ������ж�					*/
/* ����:		None													*/
/* ����:		byte													*/
/************************************************************************
void SPI_ISR() interrupt 6
{
	if(WCOL)//д��ͻ
		WCOL =0;  
	if(MODF)//ģʽ����
		MODF =0; 
	if(RXOVRN);//�������
	SPIF=0;
}
/************************************************************************/
/* ��������: Read_Status_Register										*/
/* ������: ������ȡ״̬�Ĵ���,������״̬�Ĵ�����ֵ					*/
/* ����:		None													*/
/* ����:		byte													*/
/************************************************************************/
u8 Read_Status_Register()
{
	u8 byte = 0;
	SST_CE =0;					/* ʹ���豸 */
	Send_Byte(0x05);		/* ���Ͷ�״̬�Ĵ��������� */
	byte = Get_Byte();		/* ��ȡ״̬�Ĵ��� */
	SST_CE =1;					/* ��ֹ�豸 */
	return byte;
}
/************************************************************************/
/* ��������: EWSR														*/
/* ������: ʹ�ܸ�д״̬�Ĵ�������  									*/
/* ����:		None													*/
/* ����:		Nothing													*/
/************************************************************************/
void EWSR()
{
	SST_CE =0;				/* ʹ���豸*/
	Send_Byte(0x50);	/* ����ʹ��д�Ĵ��������� */
	SST_CE =1;				/* ��ֹ�豸*/
}
/************************************************************************/
/* ��������: WRSR														*/
/* ������: ��״̬�Ĵ�����дһ���ֽ�									*/
/* ����:	 byte														*/
/* ����:	 Nothing													*/
/************************************************************************/
void WRSR(u8 byte)
{
	SST_CE =0;			 /* ʹ���豸 */
	Send_Byte(0x01); /* ����д״̬�Ĵ��� */
	Send_Byte(byte); /* �ı�Ĵ�����BPx����BPL (ֻ��2,3,4,5,7λ���Ը�д)*/
	SST_CE =1;			 /* ��ֹ�豸 */
}
/************************************************************************/
/* ��������: WREN														*/
/* ������: дʹ�ܣ�ͬ����������ʹ��д״̬�Ĵ���						*/
/* ����:		None													*/
/* ����:		Nothing													*/
/************************************************************************/
void WREN()
{
	SST_CE =0;			
	Send_Byte(0x06);		/* ����WREN���� */
	SST_CE =1;			
}
/************************************************************************/
/* ����: WRDI															*/
/* ����: д��ֹ															*/
/* ����:		None													*/
/* ����:		Nothing													*/
/************************************************************************/
void WRDI()
{
	SST_CE =0;			
	Send_Byte(0x04);		/* ����WRDI����*/
	SST_CE =1;		
}
/************************************************************************/
/* ����: EBSY															*/
/* ����: ����MISO��AAIģʽ�ڼ����RY/BY# ״̬ 							*/
/* ����:		None													*/
/* ����:		Nothing													*/
/************************************************************************/
void EBSY()
{
	SST_CE =0;			
	Send_Byte(0x70);		/* ����EBSY����*/
	SST_CE =1;		
}
/************************************************************************/
/* ����: DBSY															*/
/* ����: ��ֹMISO��AAIģʽ����Ϊ���RY/BY#״̬���ź�					*/
/* ����:		None													*/
/* ����:		Nothing													*/
/************************************************************************/
void DBSY()
{
	SST_CE =0;		
	Send_Byte(0x80);		/* ����DBSY���� */
	SST_CE =1;		
}
/************************************************************************/
/* ����: Wait_Busy														*/
/* ����: �ȴ�оƬ����(��ִ��Byte-Program, Sector-Erase, Block-Erase		*/
/*		 Chip-Erase������)												*/
/* ����: None															*/
/* ����: Nothing														*/
/************************************************************************/
void Wait_Busy()
{
	while ((Read_Status_Register())&0x01 == 0x01);/* waste time until not busy */
	//	Read_Status_Register();
}

/************************************************************************/
/* ����: Wait_Busy_AAI													*/
/* ����:  ��AAIģʽ�µȴ�оƬ����										*/
/* ����:		None													*/
/* ����:		Nothing													*/
/************************************************************************/
void Wait_Busy_AAI()
{
	while (Read_Status_Register()&0xC3 != 0x43);	/* �ȴ����� */
		//Read_Status_Register();
}

/************************************************************************/
/* ����: WREN_Check														*/
/* ����: ����д����ǰWELλ�Ƿ�Ϊ1										*/
/* ����:		None													*/
/* ����:		Nothing													*/
/************************************************************************/
void WREN_Check()
{
	u8 byte;
	byte = Read_Status_Register();	/* ��ȡ״̬register */
	if ((byte&0x02) != 0x02)		/* ���WELλ��λ */
	{
		WREN();
			//���δ��1������Ӧ����,��������дʹ�ò���
	}
}

/*************************************************************************
/*�������ƣ�SST_Init()
/*�������ܣ�SST25VF016B ������ʼ��
/*�����������
/*�����������
*************************************************************************/
void SST_Init(void)
{
SPI_IO_OUT;	
//	SST_SPIInit();//���߳�ʼ��
	WREN();//дʹ��
	EWSR();//ʹ�ܸ�д״̬�Ĵ������� 
	WRSR(0x02);//ȡ�����п鱣��
	DBSY();//��ֹMISO��AAIģʽ����Ϊ���RY/BY#״̬���ź�
SPI_IO_IN;
}

/************************************************************************/
/* ����: WREN_AAI_Check													*/
/* ����: ��AAIģʽ�¼��AAI��WELλ										*/
/************************************************************************/
void WREN_AAI_Check()
{
	u8 byte;
	byte = Read_Status_Register();	/*��ȡ״̬�Ĵ���*/
	if (byte != 0x42)		/* ��ʵAAI �� WELλ����1 */
	{
		//while(1);		
		SST_Init();/*����������������Ӧ����*/
	}
}


/************************************************************************/
/* ����:  HighSpeed_Read_Cont											*/
/* ����:  ���ٶ�ȡоƬ������ַ������,���ɶ�ȡ128�ֽ�					*/
/* ����:  Dst:(Ŀ���ַ 000000H - 1FFFFFH)								*/
/*        no_bytes:	��ȡ�ֽ���	(���128�ֽ�)							*/
/*        upper_128[]: ��ȡ���ݴ�ŵ�ַָ��                             */
/* ����:  Nothing														*/
/************************************************************************/
void Group_Read_Flash(u32 Dst, u8 xdata * Rbuffer,u8 Len)
{
	u8 i = 0;
SPI_IO_OUT;	
	Wait_Busy();
	SST_CE =0; /* оƬʹ�� */
	//Send_Byte(0x03); /* ���Ͷ�ȡָ�� */
	Send_Byte(0x0B);
	Send_Byte((u8)(((Dst) & 0xFFFFFF) >> 16)); 
	Send_Byte((u8)(((Dst) & 0xFFFF) >> 8));
	Send_Byte((u8)(Dst) & 0xFF);

	Send_Byte(0xFF); /*�����ֽ�*/
	for (i = 0; i < Len; i++) /* ��ȡLen�ֽ�*/
	{
		Rbuffer[i] = Get_Byte();	/*�������ݴ��� SPI_Rbuffer */
	}
	SST_CE =1; /* ��ֹоƬ*/
SPI_IO_IN;
}

/************************************************************************/
/* ����: Byte_Program													*/
/* ����: дһ���ֽ�����,��д�ĵ�ַ���뱻������δ������					*/				
/* ����:																*/
/*		Dst:		(Ŀ���ַ 000000H - 3FFFFFH)						*/
/*		byte:		����												*/
/* ����:																*/
/*		Nothing															*/
/************************************************************************/
void Byte_Write_Flash(u32  Dst, u8 Byte)
{
SPI_IO_OUT;	
	WREN();
	SST_CE =0;			/* оƬʹ�� */
	Send_Byte(0x02); 	/* ����д����ָ�� */

	Send_Byte((u8)(((Dst) & 0xFFFFFF) >> 16)); 
	Send_Byte((u8)(((Dst) & 0xFFFF) >> 8));
	Send_Byte((u8)(Dst) & 0xFF);

	Send_Byte(Byte);	/*����Ҫд������*/
	//Send_Byte(0xcc);
	SST_CE =1;
	Wait_Busy();	
SPI_IO_IN;			
}

void Word_Write_Flash(u32 Dst,u8 Byte1,u8 Byte2)
{
SPI_IO_OUT;	
	WREN();//дʹ��
	SST_CE =0;				
	Send_Byte(0xAD);			/* ����AAI����*/

	Send_Byte((u8)(((Dst) & 0xFFFFFF) >> 16)); 
	Send_Byte((u8)(((Dst) & 0xFFFF) >> 8));
	Send_Byte((u8)(Dst) & 0xFF);

	Send_Byte(Byte1);	
	Send_Byte(Byte2);
	SST_CE = 1;
	Wait_Busy_AAI();
	WRDI();//�˳�дʹ��	
SPI_IO_IN;						
}
/************************************************************************/
/* ����: Auto_Write_chip															*/
/* ����: there are two mode in write action .one byte mode and word auto increment address mode 															*/
/* ����:		data need to be write into flash,address,and leng													*/
/* ����:		Nothing													*/
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
	WREN();//дʹ��
	SST_CE =0;				
	Send_Byte(0xAD);			/* ����AAI����*/

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
			WRDI();//�˳�дʹ��
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
	WRDI();//�˳�дʹ��

	Wait_Busy();
SPI_IO_IN;	
}
/************************************************************************/
/* ����: Chip_Erase														*/
/* ����: ��������оƬ													*/
/* ����: None													        */
/* ����: Nothing													    */
/************************************************************************/
void Chip_Erase()
{	
SPI_IO_OUT;						
	WREN_Check();
	SST_CE =0;			
	Send_Byte(0x60);			/* ���� Chip Erase���� (60h or C7h) */
	SST_CE =1;
	Wait_Busy();
SPI_IO_IN;	
}
/************************************************************************/
/* ����: Chip_Erase														*/
/* ����: ����BLOCK													*/
/* ����: None													        */
/* ����: Nothing													    */
/************************************************************************/
void Block_Erase_4K(u32 Dst)
{	
SPI_IO_OUT;				
	WREN_Check();
	SST_CE =0;			
	Send_Byte(0x20);			/* ���� Chip Erase���� */

	Send_Byte((u8)(((Dst) & 0xFFFFFF) >> 16)); 
	Send_Byte((u8)(((Dst) & 0xFFFF) >> 8));
	Send_Byte((u8)(Dst) & 0xFF);


	SST_CE =1;
	Wait_Busy();
SPI_IO_IN;	
}

#endif