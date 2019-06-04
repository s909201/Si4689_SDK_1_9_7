/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   MMI: slave mode 
   FILE: mode_slave.c
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

#include "mode_slave.h"
#include "usb_main.h"
#include "Firmware_API_Manager.h"
#include "si46xx_firmware_api.h"
#include "DAB_Service_List_Handler.h"
#include "mode_other.h"
#include "main.h"
#include "mode_common.h"
#include "key.h"
#include "LCD.h"
#include "sys.h"
#include "mode_dab.h"
#include "delay.h"
#include "uart.h"
#include "si46xx_firmware_api_constants.h"
#include "mode_fm_am.h"
#include "mode_fmhd_amhd.h"
#include "mode_dab.h"
#include "mode_common.h"
#include "SDK_Callbacks.h"

#ifdef OPTION__OPERATE_AS_SLAVE_NO_MMI
/*************************************************************************************
convert the frequency to DAB freqindex
***************************************************************************************/
extern u32 DAB_FREQ_TABLE[];
/***********************************************************************
check the  length of string ,and return the length ;
***********************************************************************/
u16 check_len_string(u8 *str,u8 max_len_default,u8 end_character)
{
	u16 i;
	for(i=0;i<max_len_default;i++)
	{
		if(str[i]==end_character)
		{
			return i;
		}
	}
	return max_len_default;
}
/***************************************************************************

*****************************************************************************/
u8 get_time_data(u8 *year,u8 *month,u8 *day,u8 *week,u8 *hour,u8 *min)
{
	RETURN_CODE ret = SUCCESS;
#ifdef OPTION__INCLUDE_MODE__FM
    rds_time temp_rds_time;
    u32 mdjConvertTemp; //modifiedJulianDay;
    u16 n;
#endif //OPTION__INCLUDE_MODE__FM
	u16 temp_y;
	u8 temp_m;
	u8 temp_d;
	char convertedHour;

#ifdef OPTION__INCLUDE_MODE__FM
	temp_rds_time = RDSGetCurrentTime();
    if(temp_rds_time.ctDayLow != 0)
    {
        convertedHour = temp_rds_time.ctHour + (temp_rds_time.ctOffset / 2);
        if (convertedHour < 0)
        {
            convertedHour = 24 + convertedHour;
        }
		*hour = convertedHour;
		*min =  temp_rds_time.ctMinute;
		//RDS time MJD convertion to Gregorian
        mdjConvertTemp = (temp_rds_time.ctDayHigh << 16);
        mdjConvertTemp += temp_rds_time.ctDayLow;

        mdjConvertTemp = mdjConvertTemp + 68569 + 2400000;
        n = (4 * mdjConvertTemp / 146097);

        mdjConvertTemp = mdjConvertTemp - ((146097 * n + 3) / 4);
        temp_y = (4000 * (mdjConvertTemp + 1) / 1461001);

        mdjConvertTemp = mdjConvertTemp - (1461 * temp_y / 4) + 31;
        temp_m = (80 * mdjConvertTemp / 2447);

        temp_d = mdjConvertTemp - (2447 * temp_m / 80);

        mdjConvertTemp = (temp_m / 11);

        temp_m = (temp_m + 2 - 12 * mdjConvertTemp);
        temp_y = (100 * (n - 49) + temp_y + mdjConvertTemp);

		*year = temp_y - 1900;
		*month = temp_m;
		*day = temp_d;
		*week = (temp_rds_time.ctDayLow+2)%7+1;
		*hour = convertedHour;
		*min =  temp_rds_time.ctMinute;
		return 0;
	}
	else
	{
		return 1;
	}
#endif //OPTION__INCLUDE_MODE__FM
}
/**********************************************************************
dispatch the command from master 
***********************************************************************/
void slave_receive_cmd(void)
{
	if(uart0_rx_flag)
	{
		if((uart0_rx_buf[uart0_rx_num-1]==check_sum(uart0_rx_buf+3,uart0_rx_num-3-1))
			&&(uart0_rx_buf[0]=='S'
			&&uart0_rx_buf[1]=='L'
			&&uart0_rx_buf[2]=='A'))//1:remove the checksum byte 
		{
		   uart0_rx_flag = 0;
		   slave_command_dispatch(&uart0_rx_buf[4]);
		}
	}
}
/*****************************************************************
response to master
******************************************************************/
void slave_send_cmd(u8 *buf,u8 len)
{
	u8 cmd[32];
	u8 index;
	u8 i;

	index= 0;
	cmd[index++] = 'M';
	cmd[index++] = 'A';
	cmd[index++] = 'S';
	cmd[index++] = len+1;//cm+arg0+arg1...+checksume

	for(i=0;i<len;i++)
	{
		cmd[index++]=buf[i];
	}

	cmd[index++]=check_sum(cmd+3,index-3);

	uart0_send(cmd,index);	
}
/****************************************************************************************

******************************************************************************************/
void slave_command_dispatch(u8 *uart_cmd)
{
	RETURN_CODE ret = SUCCESS;
	u16 temp;
	u16 i;
	u8 CTS;
	u8 ERR;
	u8 STC;
	u8 index;
	u8 count;
#ifdef OPTION__INCLUDE_MODE__DAB
	u32 xdata freq_index;
	u32 xdata freq_temp;
	dab_time xdata TimeDab;
	dab_service_list_element xdata tempListElement;
#endif

#ifdef OPTION__INCLUDE_MODE__FMHD
	u8 HD_bitmask_temp;
	u8 desire_service_num;
#endif
	index = 0;
	switch(uart_cmd[0])
	{
		case SET_PROPERTY_SLA_CMD:
		 		ret = SetProperty(((u16)uart_cmd[1]<<8)|((u16)uart_cmd[2]),
									(uart_cmd[3]|((u16)uart_cmd[4]<<8))
									);
				CTS = 1;
				ERR = !!ret;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);
				index = 1;
				break;
		case GET_PROPERTY_SLA_CMD:
		 		ret = GetProperty(((u16)uart_cmd[1]<<8)|((u16)uart_cmd[2]),&temp);
				CTS = 1;
				ERR = !!ret;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);
				uart0_tx_buf[1] = (u8)(temp>>8);
				uart0_tx_buf[2] = (u8)temp;
				index = 3;
				break;
		case GET_CHIP_INFO_SLA_CMD://534c41010304
				power_flag = 1;//set up this flag for avoid initialize the device system clock again,if not, it will cause F340 work out
				ret =Initialize(fmonly);
				ret |=Get_part(&temp);
				power_flag = 0;
				CTS = 1;
				ERR = !!ret;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);
				uart0_tx_buf[1] = (u8)(temp>>8);
				uart0_tx_buf[2] = (u8)temp;
				index = 3;
				break;
		case VOLUME_SLA_CMD:
				ret = AudioLevel(uart_cmd[1]);
				CTS = 1;
				ERR = !!ret;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);
				index = 1;
				break;
		case AUDIO_MUTE_SLA_CMD:
				if(uart_cmd[1]==0)
				{
					ret = AudioMute(MUTE_LEFT_RIGHT);
				}
				else
				{
					ret = AudioMute(MUTE);
				}
				CTS = 1;
				ERR = !!ret;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);
				index = 1;
				break;
		case POWER_DOWN_SLA_CMD:
				si468x_RST = 0;//push down the RST for saving power by now
				CTS = 1;
				ERR = 0;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);
				index = 1;
				break;
//////////////////////////////////////////below is FM mode///////////////////////////////////////////////

#ifdef OPTION__INCLUDE_MODE__FM
		case FM_INIT_MODE_SLA_CMD://534c41022022
				ret = Finalize();	
				power_flag =1;
				ret |= fm_am_initialize();
				display_mode = FM_MODE;
				CTS = 1;
				ERR = !!ret;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);
				index = 1;
				break;
		case FM_TUNE_FREQ_SLA_CMD://534c41042152269d tune 98.1Mhz
				ret |= Tune((u16)uart_cmd[1]|((u16)uart_cmd[2]<<8));
				CTS = 1;
				ERR = !!ret;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);
				index = 1;
				break;  
		case FM_TUNE_STATUS_SLA_CMD://534c41022224
			  ret |= UpdateMetrics();
			  	STC = 1;
			  	CTS = 1;
				ERR = !!ret;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);
				uart0_tx_buf[0] |= STC<<0;
				uart0_tx_buf[1] =MetricsGetFMPtr()->VALID;
			    uart0_tx_buf[2] =(u8)(MetricsGetFMPtr()->FREQUENCY_10KHZ);	
				uart0_tx_buf[3] =(u8)(MetricsGetFMPtr()->FREQUENCY_10KHZ>>8);
				uart0_tx_buf[4]	=MetricsGetFMPtr()->RSSI;
				uart0_tx_buf[5]	=MetricsGetFMPtr()->SNR;
				uart0_tx_buf[6]	=MetricsGetFMPtr()->MULTIPATH;
				index = 7;
				break;
		case FM_FREQ_SPACE_SLA_CMD://534c4102236489 set space to 100
				ret = SetStepSize(uart_cmd[1]);
				CTS = 1;
				ERR = !!ret;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);
				index = 1;
				break;
		case FM_START_SEEK_SLA_CMD://534c4102240127  :seek down wrap
				//send the response immediately, as the seek action need a span to deal with
				CTS = 1;
				STC = 0;
				ERR = !!ret;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6|STC<<0);
				index = 1;	
				slave_send_cmd(uart0_tx_buf,index);
				index = 0;

//RETURN_CODE SeekStart(uint8_t seekup, uint8_t wrap, uint8_t hdseekonly)
				ret = SeekStart(uart_cmd[1]&0x10>>4,uart_cmd[1]&0x01,0);	
						
				break;
		case FM_RDS_STATUS_SLA_CMD://534c41012526
				CTS = 1;
				ERR = 0;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);
				uart0_tx_buf[1] = rds_update_ready_item;
				index = 2;	
				break;
		case FM_RDS_PI_SLA_CMD://534c41012627
				CTS = 1;
				ERR = 0;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);	
				if(rds_update_ready_item&UPDATED_RDS_PI_ITEM)
				{
					temp = RDSGetProgramIdentifier();
					uart0_tx_buf[0] |=0x01;
				}
				else
				{
					temp = 0x0000;
					uart0_tx_buf[0] &=~0x01;
				}
				uart0_tx_buf[1]	=(u8)temp;
				uart0_tx_buf[2] =(u8)(temp>>8);
				index = 3;	
				break;
		case FM_RDS_PTY_SLA_CMD://534c41012728
				CTS = 1;
				ERR = 0;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);	
				if(rds_update_ready_item&UPDATED_RDS_PTY_ITEM)
				{
					temp = RDSGetProgramType();
					uart0_tx_buf[0] |=0x01;
				}
				else
				{
					temp = 0x0000;
					uart0_tx_buf[0] &=~0x01;
				}
				uart0_tx_buf[1]	=(u8)temp;
				index = 2;	
				break;
		case FM_RDS_PS_SLA_CMD://534c41012829
				CTS = 1;
				ERR = 0;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);	
				if(rds_update_ready_item&UPDATED_RDS_PST_ITEM)
				{
					uart0_tx_buf[0] |=0x01;
					uart0_tx_buf[1]	= *(RDSGetProgramServiceTextPtr());
					uart0_tx_buf[2]	= *(RDSGetProgramServiceTextPtr()+1);
					uart0_tx_buf[3]	= *(RDSGetProgramServiceTextPtr()+2);
					uart0_tx_buf[4]	= *(RDSGetProgramServiceTextPtr()+3);
					uart0_tx_buf[5]	= *(RDSGetProgramServiceTextPtr()+4);
					uart0_tx_buf[6]	= *(RDSGetProgramServiceTextPtr()+5);
					uart0_tx_buf[7]	= *(RDSGetProgramServiceTextPtr()+6);
					uart0_tx_buf[8]	= *(RDSGetProgramServiceTextPtr()+7);
					index = 9;
				}
				else
				{
					uart0_tx_buf[0] &=~0x01;
					index = 1;
				}
				break;
		case FM_RDS_RT_SLA_CMD://534c4101292a
				CTS = 1;
				ERR = 0;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);	
				if(rds_update_ready_item&UPDATED_RDS_RT_ITEM)
				{
					uart0_tx_buf[0] |=0x01;
				
					temp = check_len_string(RDSGetRadioTextPtr(),RDS_RADIO_TEXT_BUFFER_SIZE,0x0d);//0x0d is end character
					uart0_tx_buf[1]= temp;
					count= 0;
					for(i=uart_cmd[1];i<((uart_cmd[1]+8)>temp?temp:(uart_cmd[1]+8));i++)
					{
						uart0_tx_buf[2+count] =*(RDSGetRadioTextPtr()+i);
						count++;
					}
					index = count+2;	
				}
				else
				{
					uart0_tx_buf[0] &=~0x01;
					uart0_tx_buf[1] = 0;
					index = 2;
				}
				break;
		case FM_RDS_CT_SLA_CMD://534c41012a2b
				if(rds_update_ready_item&UPDATED_RDS_TIME_ITEM)
				{
					CTS = 1;
					ERR = get_time_data(&uart0_tx_buf[1],&uart0_tx_buf[3],&uart0_tx_buf[4],&uart0_tx_buf[5],&uart0_tx_buf[6],&uart0_tx_buf[7]);
					uart0_tx_buf[0] = (CTS<<7|ERR<<6);	
					uart0_tx_buf[0] |=0x01;//set CT flag bit
					temp = uart0_tx_buf[1] +1900;
					uart0_tx_buf[1] = (u8)temp;
					uart0_tx_buf[2] = (u8)(temp>>8);
					index = 8;
				}
				else
				{
					CTS = 1;
					ERR = 0;
					uart0_tx_buf[0] = (CTS<<7|ERR<<6);
					uart0_tx_buf[0] &=~0x01;//clear CT flag bit;
					index = 1;
				}
				break;
		case FM_RDS_AF_SLA_CMD://this command is not supported by SDK by now
				CTS = 1;
				ERR = 0;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);
				if(rds_update_ready_item&UPDATED_RDS_ALT_FREQ_ITEM)
				{
					uart0_tx_buf[0] |=0x01;//set CT flag bit
				}
				else
				{
					uart0_tx_buf[0] &=~0x01;//clear CT flag bit
				}
				index =1;
				break;
#endif//OPTION__INCLUDE_MODE__FM

#ifdef OPTION__INCLUDE_MODE__FMHD
		case FMHD_INIT_MODE_SLA_CMD://534c41014041
				ret = Finalize();	
				power_flag =1;
				ret |= fmhd_amhd_initialize();
				display_mode = FMHD_MODE;
				CTS = 1;
				ERR = !!ret;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);
				index = 1;
				break;
		case FMHD_TUNE_FREQ_SLA_CMD://534c4104415226bd
				ret = Tune((u16)uart_cmd[1]|(((u16)uart_cmd[2])<<8));
				CTS = 1;
				ERR = !!ret;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);
				index = 1;
				break;
		case FMHD_TUNE_STATUS_SLA_CMD://534c4103420045
			  	ret |= UpdateMetrics();
			  	CTS = 1;
				ERR = !!ret;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);
				uart0_tx_buf[1] = MetricsGetFMHDPtr()->VALID;
				uart0_tx_buf[1] |= MetricsGetFMHDPtr()->AUDIO_SOURCE<<1;
				uart0_tx_buf[1] |= MetricsGetFMHDPtr()->HDLOGO<<2;

			    uart0_tx_buf[2] =(u8)( MetricsGetFMHDPtr()->FREQUENCY_10KHZ);	
				uart0_tx_buf[3] =(u8)( MetricsGetFMHDPtr()->FREQUENCY_10KHZ>>8);
				uart0_tx_buf[4]	= MetricsGetFMHDPtr()->RSSI;
				uart0_tx_buf[5]	= MetricsGetFMHDPtr()->SNR;
				uart0_tx_buf[6]	= MetricsGetFMHDPtr()->MULTIPATH;
				uart0_tx_buf[7]	= MetricsGetFMHDPtr()->HDLEVEL;
				uart0_tx_buf[8]	= MetricsGetFMHDPtr()->ACQ;
				uart0_tx_buf[9]	= MetricsGetFMHDPtr()->DAAI;
				uart0_tx_buf[10]= MetricsGetFMHDPtr()->CDNR;
				uart0_tx_buf[11]= MetricsGetFMHDPtr()->HDLOGO;
				uart0_tx_buf[12]= MetricsGetFMHDPtr()->CURRENT_AUDIO_SERVICE;
				uart0_tx_buf[13]= MetricsGetFMHDPtr()->CURRENT_AUDIO_SERVICE__LIST_INDEX;
				index = 14;
				break;
		case FMHD_FREQ_SPACE_SLA_CMD:
				ret = SetStepSize(uart_cmd[1]);
				CTS = 1;
				ERR = !!ret;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);
				index = 1;
				break;
		case FMHD_START_SEEK_SLA_CMD://FM and FMHD seek process need to divide to two parts?? 
				//send the response immediately, as the seek action need a span to deal with
				CTS = 1;
				STC = 0;
				ERR = !!ret;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6|STC<<0);
				index = 1;	
				slave_send_cmd(uart0_tx_buf,index);
				index = 0;
				if(uart_cmd[1])
				{
					ret=SeekStart(1,1,fmhd_seekonly);
				}
				else
				{
					ret=SeekStart(1,1,fmhd_seekonly);
				}
				break;
		case FMHD_SERVICE_NAME_SLA_CMD://534c41014546
				index = get_HD_service_name(&uart0_tx_buf[0])+1;
				CTS = 1;
				ERR = 0;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);
				break;
		case FMHD_SERVICE_COUNT_SLA_CMD://534C41014647			
				CTS = 1;
				ERR = 0;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);
				uart0_tx_buf[1] = get_HD_service_count();
				index = 2;
				break;
		case FMHD_START_SERVICE_ID_SLA_CMD://534c410247024b
				if(uart_cmd[1]>get_HD_service_count())
				{
					CTS = 1;
					ERR = 1;
					uart0_tx_buf[0] = (CTS<<7|ERR<<6);
					index = 1;
				}
				else
				{
					desire_service_num = uart_cmd[1];
					//TODO:We need to make sure the MPS service comp is zero in everyone HD station?
					temp =0;// MetricsGetFMHDPtr()->CURRENT_AUDIO_SERVICE;
					HD_bitmask_temp = 0x01;
					for(i=0;i<8;i++)
					{						
						if(HD_bitmask_temp&FMHDServiceListFastPtr()->AUDIO_SERVICE_PRESENT_BITMASK)
						{
							desire_service_num--;
							if(desire_service_num==0)
							{
								ret =StartProcessingChannel(SERVICE_TYPE_HD_AUDIO,
								 					0,
													temp, 0);	
								break;							
							}
						}
						HD_bitmask_temp <<=1;
						temp++;
					}
					if(ret == SUCCESS)
					{
						MetricsGetFMHDPtr()->CURRENT_AUDIO_SERVICE = temp;
					}
					CTS = 1;
					ERR = !!ret;
					uart0_tx_buf[0] = (CTS<<7|ERR<<6);
					index = 1;
				}										
				break;
		case FMHD_INFO_SLA_CMD://534c410248004a
				if(uart_cmd[1]&0x01)
				{
					CTS = 1;
					ERR = !!ret;
					uart0_tx_buf[0] = (CTS<<7|ERR<<6);
					index = 1;
					//clear the flag 
					rds_update_ready_item = 0;
					sis_update_ready_item = 0;
					alert_update_ready_item = 0;
					psd_update_ready_item = 0;
				}
				else
				{
					CTS = 1;
					ERR = !!ret;
					uart0_tx_buf[0] = (CTS<<7|ERR<<6);
					uart0_tx_buf[1] = rds_update_ready_item&0x0c;//only exist RT& PST
					uart0_tx_buf[2] = sis_update_ready_item;
					uart0_tx_buf[3] = psd_update_ready_item;
					uart0_tx_buf[4] = alert_update_ready_item;
					index = 5;					
				}											
				break;
		case FMHD_RDS_RT_SLA_CMD://534c410249004B
				CTS = 1;
				ERR = 0;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);	
				if(rds_update_ready_item&UPDATED_RDS_RT_ITEM)
				{
					uart0_tx_buf[0] |=0x01;
					temp = check_len_string(RDSGetRadioTextPtr(),RDS_RADIO_TEXT_BUFFER_SIZE,0x0d);//0x0d is end character
					uart0_tx_buf[1]= temp;
					count = 0;
					for(i=uart_cmd[1];i<((uart_cmd[1]+8)>temp?temp:(uart_cmd[1]+8));i++)
					{
						uart0_tx_buf[2+count] =*(RDSGetRadioTextPtr()+i);
						count++;
					}
					index = count+2;
				}
				else
				{
					uart0_tx_buf[0] &=~0x01;
					uart0_tx_buf[1] = 0;
					index = 2;
				}
				break;
		case FMHD_RDS_PS_SLA_CMD://534c41024a004c
				CTS = 1;
				ERR = 0;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);	
				if(rds_update_ready_item&UPDATED_RDS_PST_ITEM)
				{
					uart0_tx_buf[0] |=0x01;
					uart0_tx_buf[1]	=*(RDSGetProgramServiceTextPtr());
					uart0_tx_buf[2]	=*(RDSGetProgramServiceTextPtr()+1);
					uart0_tx_buf[3]	=*(RDSGetProgramServiceTextPtr()+2);
					uart0_tx_buf[4]	=*(RDSGetProgramServiceTextPtr()+3);
					uart0_tx_buf[5]	=*(RDSGetProgramServiceTextPtr()+4);
					uart0_tx_buf[6]	=*(RDSGetProgramServiceTextPtr()+5);
					uart0_tx_buf[7]	=*(RDSGetProgramServiceTextPtr()+6);
					uart0_tx_buf[8]	=*(RDSGetProgramServiceTextPtr()+7);
					index = 9;	
				}
				else
				{
					uart0_tx_buf[0] &=~0x01;
					index = 1;
				}
				break;
		case FMHD_SIS_SLOGAN_SLA_CMD://534c41024B004D
				CTS = 1;
				ERR = 0;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);
				if(sis_update_ready_item&UPDATED_SIS_SLOGAN_ITEM)
				{
					uart0_tx_buf[0] |=0x01;
					temp = check_len_string(SISGetSloganPtr()->SLGN_TEXT,FMHD_SIS_SLOGAN_BUFFER_SIZE,0);//0x0d is end character
					uart0_tx_buf[1]=(u8)temp;
					uart0_tx_buf[2] = SISGetSloganPtr()->SLGN_ENCODING;
					count = 0;
					for(i=uart_cmd[1];i<((uart_cmd[1]+8)>temp?temp:(uart_cmd[1]+8));i++)
					{
						uart0_tx_buf[3+count] =SISGetSloganPtr()->SLGN_TEXT[i];
						count++;
					}
					index = count+3;
				}
				else
				{
					uart0_tx_buf[0] &=~0x01;
					uart0_tx_buf[1] = 0;
					index = 2;
				}
				break;
		case FMHD_SIS_USN_SLA_CMD://534c41024C004E
				CTS = 1;
				ERR = 0;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);
				if(sis_update_ready_item&UPDATED_SIS_UNIVERSAL_SHORT_NAME_ITEM)
				{
					uart0_tx_buf[0] |=0x01;
					
					temp = (u8)check_len_string(SISGetUSNPtr()->USN_TEXT,FMHD_SIS_UNIVERSAL_SHORT_NAME_BUFFER_SIZE,0);//0x0d is end character
					uart0_tx_buf[1]= temp;
					uart0_tx_buf[2] = SISGetUSNPtr()->USN_ENCODING;
					uart0_tx_buf[3] = SISGetUSNPtr()->USN_APPEND;
					count = 0;
					for(i=uart_cmd[1];i<((uart_cmd[1]+8)>temp?temp:(uart_cmd[1]+8));i++)
					{
						uart0_tx_buf[4+count] =SISGetUSNPtr()->USN_TEXT[i];
						count++;
					}
					index = count+4;
				}
				else
				{
					uart0_tx_buf[0] &=~0x01;
					uart0_tx_buf[1] = 0;
					index = 2;
				}
				break;
		case FMHD_SIS_SM_SLA_CMD://534c41024D004F
				CTS = 1;
				ERR = 0;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);
				if(sis_update_ready_item&UPDATED_SIS_STATION_MESSAGE_ITEM)
				{
					uart0_tx_buf[0] |=0x01;
					
					temp = check_len_string(SISGetSMPtr()->SM_TEXT,FMHD_SIS_STATION_MESSAGE_BUFFER_SIZE,0);//0x0d is end character
					uart0_tx_buf[1]=(u8)temp;
					uart0_tx_buf[2] =SISGetSMPtr()->SM_ENCODING;
					uart0_tx_buf[3] = SISGetSMPtr()->SM_PRIORITY;
					count = 0;
					for(i=uart_cmd[1];i<((uart_cmd[1]+8)>temp?temp:(uart_cmd[1]+8));i++)
					{
						uart0_tx_buf[4+count] =SISGetSMPtr()->SM_TEXT[i];
						count++;
					}
					index = count+4;
				}
				else
				{
					uart0_tx_buf[0] &=~0x01;
					uart0_tx_buf[1] = 0;
					index = 2;
				}
				break;
		case FMHD_SIS_SNL_SLA_CMD://534c41024E0050
				CTS = 1;
				ERR = 0;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);
				if(sis_update_ready_item&UPDATED_SIS_STATION_NAME_LONG_ITEM)
				{
					uart0_tx_buf[0] |=0x01;
					
					temp = (u8)check_len_string(SISGetSNLPtr(),FMHD_SIS_STATION_NAME_LONG_BUFFER_SIZE,0);//0x0d is end character
					uart0_tx_buf[1]= temp;
					count=0;
					for(i=uart_cmd[1];i<((uart_cmd[1]+8)>temp?temp:(uart_cmd[1]+8));i++)
					{
						uart0_tx_buf[2+count] =*(SISGetSNLPtr()+i);
						count++;
					}
					index = count+2;
				}
				else
				{
					uart0_tx_buf[0] &=~0x01;
					uart0_tx_buf[1] = 0;
					index = 2;
				}
				break;
		case FMHD_SIS_SNS_SLA_CMD://534c41014f50
				CTS = 1;
				ERR = 0;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);	
				if(sis_update_ready_item&UPDATED_SIS_STATION_NAME_SHORT_ITEM)
				{
					uart0_tx_buf[0] |=0x01;
					uart0_tx_buf[1]	=*(SISGetSNSPtr());
					uart0_tx_buf[2]	=*(SISGetSNSPtr()+1);
					uart0_tx_buf[3]	=*(SISGetSNSPtr()+2);
					uart0_tx_buf[4]	=*(SISGetSNSPtr()+3);
					uart0_tx_buf[5]	=*(SISGetSNSPtr()+4);
					uart0_tx_buf[6]	=*(SISGetSNSPtr()+5);
					uart0_tx_buf[7]	=*(SISGetSNSPtr()+6);
					index = 8;
				}
				else
				{
					uart0_tx_buf[0] &=~0x01;
					index = 1;
				}
				break;
		case FMHD_SIS_STI_SLA_CMD://534c41015051	
				CTS = 1;
				ERR = 0;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);	
				if(sis_update_ready_item&UPDATED_SIS_STATION_ID_ITEM)
				{
					uart0_tx_buf[0] |=0x01;
					uart0_tx_buf[1]	=*(SISGetStationIDPtr());
					uart0_tx_buf[2]	=*(SISGetStationIDPtr()+1);
					uart0_tx_buf[3]	=*(SISGetStationIDPtr()+2);
					uart0_tx_buf[4]	=*(SISGetStationIDPtr()+3);
					index = 5;
				}
				else
				{
					uart0_tx_buf[0] &=~0x01;
					index = 1;
				}
				break;
		case FMHD_SIS_SL_SLA_CMD://534c41015152
				CTS = 1;
				ERR = 0;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);	
				if(sis_update_ready_item&UPDATED_SIS_LOC_LAT_ITEM)
				{
					uart0_tx_buf[0] |=0x01;
					uart0_tx_buf[1]	=*(SISGetStationLocLatPtr());
					uart0_tx_buf[2]	=*(SISGetStationLocLatPtr()+1);
					uart0_tx_buf[3]	=*(SISGetStationLocLatPtr()+2);
					uart0_tx_buf[4]	=*(SISGetStationLocLatPtr()+3);
					index = 5;
				}
				else
				{
					uart0_tx_buf[0] &=~0x01;
					index = 1;
				}
				break;
		case FMHD_PSD_TITLE_SLA_CMD://534c4102520054
				CTS = 1;
				ERR = 0;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);
				if(psd_update_ready_item&UPDATED_PSD_TITLE_ITEM)
				{
					uart0_tx_buf[0] |=0x01;
					
					temp = (u8)check_len_string(PSDGetTitlePtr()->DATA,PSDGetTitlePtr()->LENGTH,0);//0x0d is end character
					uart0_tx_buf[1]= temp;
					uart0_tx_buf[2]= PSDGetTitlePtr()->ENCODING;
					count = 0;
					for(i=uart_cmd[1];i<((uart_cmd[1]+8)>temp?temp:(uart_cmd[1]+8));i++)
					{
						uart0_tx_buf[3+count] =PSDGetTitlePtr()->DATA[i];
						count++;
					}
					index = count+3;
				}
				else
				{
					uart0_tx_buf[0] &=~0x01;
					uart0_tx_buf[1] = 0;
					index = 2;
				}
				break;
		case FMHD_PSD_ARTIST_SLA_CMD://534c4102530055
				CTS = 1;
				ERR = 0;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);
				if(psd_update_ready_item&UPDATED_PSD_ARTIST_ITEM)
				{
					uart0_tx_buf[0] |=0x01;
					
					temp =(u8)check_len_string(PSDGetArtistPtr()->DATA,PSDGetArtistPtr()->LENGTH,0);//0x0d is end character
					uart0_tx_buf[1] = temp;
					uart0_tx_buf[2] = PSDGetArtistPtr()->ENCODING;
					count = 0;
					for(i=uart_cmd[1];i<((uart_cmd[1]+8)>temp?temp:(uart_cmd[1]+8));i++)
					{
						uart0_tx_buf[3+count] =PSDGetTitlePtr()->DATA[i];
						count++;
					}
					index = count+3;
				}
				else
				{
					uart0_tx_buf[0] &=~0x01;
					uart0_tx_buf[1] = 0;
					index = 2;
				}
				break;
		case FMHD_PSD_ALBUM_SLA_CMD://534c4102540056
				CTS = 1;
				ERR = 0;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);
				if(psd_update_ready_item&UPDATED_PSD_ALBUM_ITEM)
				{
					uart0_tx_buf[0] |=0x01;
					
					temp =(u8)check_len_string(PSDGetAlbumPtr()->DATA,PSDGetAlbumPtr()->LENGTH,0);//0x0d is end character
					uart0_tx_buf[1] = temp;
					uart0_tx_buf[2] = PSDGetAlbumPtr()->ENCODING;
					count = 0;
					for(i=uart_cmd[1];i<((uart_cmd[1]+8)>temp?temp:(uart_cmd[1]+8));i++)
					{
						uart0_tx_buf[3+count] =PSDGetAlbumPtr()->DATA[i];
						count++;
					}
					index = count+3;
				}
				else
				{
					uart0_tx_buf[0] &=~0x01;
					uart0_tx_buf[1] = 0;
					index = 2;
				}
				break;
		case FMHD_PSD_GENRE_SLA_CMD:
				CTS = 1;
				ERR = 0;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);
				if(psd_update_ready_item&UPDATED_PSD_GENRE_ITEM)
				{
					uart0_tx_buf[0] |=0x01;
					
					temp = (u8)check_len_string(PSDGetGenrePtr()->DATA,PSDGetGenrePtr()->LENGTH,0);//0x0d is end character
					uart0_tx_buf[1]= temp;
					uart0_tx_buf[2] = PSDGetGenrePtr()->ENCODING;
					count = 0;
					for(i=uart_cmd[1];i<((uart_cmd[1]+8)>temp?temp:(uart_cmd[1]+8));i++)
					{
						uart0_tx_buf[3+count] =PSDGetGenrePtr()->DATA[i];
						count++;
					}
					index = count+3;
				}
				else
				{
					uart0_tx_buf[0] &=~0x01;
					uart0_tx_buf[1] = 0;
					index = 2;
				}
				break;
		case FMHD_PSD_ALERT_SLA_CMD:
				CTS = 1;
				ERR = 0;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);
				if(alert_update_ready_item&UPDATED_ALERT_ITEM)
				{
					uart0_tx_buf[0] |=0x01;
					
					temp = (u8)check_len_string(HDAlertGetPtr()->DATA,HDAlertGetPtr()->LENGTH,0);//0x0d is end character
					uart0_tx_buf[1]= temp;
					uart0_tx_buf[2]= HDAlertGetPtr()->ENCODING;

					count = 0;
					for(i=uart_cmd[1];i<((uart_cmd[1]+8)>temp?temp:(uart_cmd[1]+8));i++)
					{
						uart0_tx_buf[3+count] =HDAlertGetPtr()->DATA[i];
						count++;
					}
					index = count+3;
				}
				else
				{
					uart0_tx_buf[0] &=~0x01;
					uart0_tx_buf[1] = 0;
					index = 2;
				}
				break;
#endif //OPTION__INCLUDE_MODE__FMHD

#ifdef OPTION__INCLUDE_MODE__DAB

		case DAB_INIT_MODE_SLA_CMD://534c41016061
				ret = Finalize();	
				power_flag =1;
				ret |= dab_initialize();
				display_mode = DAB_MODE;
				CTS = 1;
				ERR = !!ret;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);
				index = 1;
				break;
		case DAB_SCAN_SLA_CMD://534c4102610063
				//send the response immediately, as the scan action need a span to deal with
				CTS = 1;
				STC = 0;
				ERR = !!ret;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6|STC<<0);
				index = 1;	
				slave_send_cmd(uart0_tx_buf,index);
				index = 0;

				ret=DAB_scan();
				break;
		case DAB_SERVICE_COUNT_SLA_CMD://534c41016263
				CTS = 1;
				ERR = 0;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);
				uart0_tx_buf[1] = DABServiceListAudioPtr()->SERVICE_COUNT;
				index = 2;
				break;
		case DAB_START_SERVICE_ID_SLA_CMD://534c4102630166
				if(uart_cmd[1]>=DABServiceListAudioPtr()->SERVICE_COUNT)
				{
					CTS = 1;
					ERR = 1;
					uart0_tx_buf[0] = (CTS<<7|ERR<<6);
					index = 1;
				}
				else
				{
					ret = getServiceListElement(DABServiceListAudioPtr()->SERVICE_OFFSETS[uart_cmd[1]], 
												&tempListElement);
					ret |= ManualTune_DAB(tempListElement.FREQUENCY_INDEX); // izt on 2
                	ret |= StartProcessingChannel(SERVICE_TYPE_DAB_AUDIO,
					 						tempListElement.SERVICE_ID,
											tempListElement.COMPONENT_ID, 0);
					CTS = 1;
					ERR = !!ret;
					uart0_tx_buf[0] = (CTS<<7|ERR<<6);
					index = 1;
				}
				break;
		case DAB_TUNE_STATUS_SLA_CMD://534c4102640066
				ret = UpdateMetrics();
			  	CTS = 1;
				ERR = !!ret;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);
			    uart0_tx_buf[1] = MetricsGetDABPtr()->FREQUENCY_INDEX;	
				uart0_tx_buf[2]	=MetricsGetDABPtr()->RSSI;
				uart0_tx_buf[3]	=MetricsGetDABPtr()->SNR;
				uart0_tx_buf[4]	=MetricsGetDABPtr()->VALID;
				uart0_tx_buf[5]	=MetricsGetDABPtr()->ACQ;
				uart0_tx_buf[6]	=MetricsGetDABPtr()->FIC_QUALITY;
				uart0_tx_buf[7] =MetricsGetDABPtr()->CNR;
				uart0_tx_buf[8]=(u8)MetricsGetDABPtr()->EID;
				uart0_tx_buf[9]=(u8)(MetricsGetDABPtr()->EID>>8);
				uart0_tx_buf[10]=MetricsGetDABPtr()->CURRENT_AUDIO_SERVICE_LIST__SERVICE_INDEX;
				uart0_tx_buf[11]=(u8)MetricsGetDABPtr()->CURRENT_AUDIO_INFO__BIT_RATE;
				uart0_tx_buf[12]=(u8)(MetricsGetDABPtr()->CURRENT_AUDIO_INFO__BIT_RATE>>8);
				uart0_tx_buf[13]=(u8)MetricsGetDABPtr()->CURRENT_AUDIO_INFO__MODE;
				index = 14;
				break;
		case DAB_TUNE_FREQ_INDEX_SLA_CMD://534c4102651279
				if(uart_cmd[1]>41)
				{
					ERR = 1;
				}
				else
				{
					//initDAB_ServiceList(); // Clear the service list
    				ret =ManualTune_DAB(uart_cmd[1]); // izt on 2
    				//ret |=BrowseServicesStartCurrentSelection_DAB();
						
					CTS = 1;
					STC = 1;
					ERR =!!ret;
				}					
				uart0_tx_buf[0] = (CTS<<7|ERR<<6|STC<<0);
				index = 1;				
				break;
		case DAB_TUNE_FREQ_SLA_CMD://534c41056610260300a4
				freq_temp = (u32)uart_cmd[4]<<24
								|(u32)uart_cmd[3]<<16
								|(u32)uart_cmd[2]<<8
								|(u32)uart_cmd[1];
				freq_index = freq_to_dab_index(freq_temp);
				if(freq_index == 0xff)
				{
					ERR = 1;						
				}
				else
				{
					//initDAB_ServiceList(); // Clear the service list
    				ret = ManualTune_DAB(freq_index); // izt on 2
    				//ret |=BrowseServicesStartCurrentSelection_DAB();	
				}	
				CTS = 1;
				STC = 1;
				ERR = !!ret;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6|STC<<0);
				index = 1;
				break;
		case DAB_SERVICE_NAME_SLA_CMD://534c41016768
				ret = GetCurrentServiceString_DAB(&uart0_tx_buf[3],&uart0_tx_buf[2],&uart0_tx_buf[1]);	
				CTS = 1;
				ERR = !!ret;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);
				index = 19;		
				break;
		case DAB_UK_FREQ_LIST_SLA_CMD://534c41016869
				ret = ChangeFreqListToLimitedUK();
				CTS = 1;
				STC = 1;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);
				index = 1;
				break;
		case DAB_DLS_STR_SLA_CMD://534c410269006b
				CTS = 1;
				ERR = 0;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);
				if(dls_update_ready_item&UPDATED_DLS_STRING_ITEM)
				{
					uart0_tx_buf[0] |=0x01;
					
					temp = (u8)check_len_string(DLSGetPtr()->DATA,DLSGetPtr()->LENGTH,0);//0x0d is end character
					uart0_tx_buf[1] = temp;
					uart0_tx_buf[2] = DLSGetPtr()->ENCODING;
					count = 0;
					for(i=uart_cmd[1];i<((uart_cmd[1]+8)>temp?temp:(uart_cmd[1]+8));i++)
					{
						uart0_tx_buf[3+count] = DLSGetPtr()->DATA[i];
						count++;
					}
					index = count+3;
				}
				else
				{
					uart0_tx_buf[0] &=~0x01;
					uart0_tx_buf[1] = 0;
					index = 2;
				}
				break;
		case DAB_TIME_SLA_CMD://534c41016a6b
                ret = GetCurrentTime_DAB(LOCAL,&TimeDab);	
				CTS = 1;
				ERR = !!ret;
				uart0_tx_buf[0] = (CTS<<7|ERR<<6);	
				uart0_tx_buf[1] =(u8)TimeDab.YEAR;
				uart0_tx_buf[2] =(u8)(TimeDab.YEAR>>8);
				uart0_tx_buf[3] =TimeDab.MONTH;
				uart0_tx_buf[4] =TimeDab.DAYS;
				uart0_tx_buf[5] =TimeDab.HOURS;
				uart0_tx_buf[6] =TimeDab.MINUTES;
				uart0_tx_buf[7] =TimeDab.SECONDS;	
				index = 8;																																			
				break;
#endif //OPTION__INCLUDE_MODE__DAB
		default:break;
	}
	if(index>0)
	{
		slave_send_cmd(uart0_tx_buf,index);
		index = 0;
	}
}
/****************************************************************************************
dispatch the command in SEEK or scan process
*****************************************************************************************/
void seek_scan_process_dispatch(void)
{
	u8 index;
	u8 CTS;
	u8 ERR;
	u8 STC;
	index = 0;
	if(uart0_rx_flag)
	{
		if((uart0_rx_buf[uart0_rx_num-1]==check_sum(uart0_rx_buf+3,uart0_rx_num-3-1))
			&&(uart0_rx_buf[0]=='S'
			&&uart0_rx_buf[1]=='L'
			&&uart0_rx_buf[2]=='A'))//1:remove the checksum byte 
		{
		    uart0_rx_flag = 0;
		    if(work_mode == dab)
		    {
#ifdef OPTION__INCLUDE_MODE__DAB
		   		if(uart0_rx_buf[4] == DAB_TUNE_STATUS_SLA_CMD)
				{
					if(dab_scan_flag)
					{
						STC =0;//TUNE or scan have not been trigger, do not send the TUNE/SEEK/SCAN command
					}
					if(uart0_rx_buf[5]&0x01)
					{
						ScanBandCancel_DAB();
						STC = 1;//TUNE or SCAN have been complete						
					}
					CTS = 1;
					ERR = 0;
					uart0_tx_buf[0] = (CTS<<7|ERR<<6|STC<<0);
					uart0_tx_buf[1] = MetricsGetDABPtr()->FREQUENCY_INDEX;
					index = 2;
				}
#endif//OPTION__INCLUDE_MODE__DAB
			}
			else if(work_mode == fmhd)
			{
#ifdef OPTION__INCLUDE_MODE__FMHD				
				if(uart0_rx_buf[4] == FMHD_TUNE_STATUS_SLA_CMD)
				{
					if(uart0_rx_buf[5]&0x01)
					{
						//cancel the seek action
					}
					STC = 0;
					CTS = 1;
					ERR = 0;
					uart0_tx_buf[0] = (CTS<<7|ERR<<6|STC<<0);
					uart0_tx_buf[1] = 0;
					uart0_tx_buf[2] = (u8)(MetricsGetFMHDPtr()->FREQUENCY_10KHZ);
					uart0_tx_buf[3] = (u8)(MetricsGetFMHDPtr()->FREQUENCY_10KHZ>>8);
					index = 4;
				}
#endif//OPTION__INCLUDE_MODE__FMHD
			}
			else if(work_mode == fmonly)
			{
#ifdef OPTION__INCLUDE_MODE__FM
				if(uart0_rx_buf[4] == FM_TUNE_STATUS_SLA_CMD)
				{
					if(uart0_rx_buf[5]&0x01)
					{
						//stop_seek();//cancel the seek action
					}
					STC = 0;
					CTS = 1;
					ERR = 0;
					uart0_tx_buf[0] = (CTS<<7|ERR<<6|STC<<0);
					uart0_tx_buf[1] = 0;
					uart0_tx_buf[2] = (u8)(MetricsGetFMPtr()->FREQUENCY_10KHZ);
					uart0_tx_buf[3] = (u8)(MetricsGetFMPtr()->FREQUENCY_10KHZ>>8);
					index = 4;
				}	
#endif//OPTION__INCLUDE_MODE__FM
			}
			else
			{
					CTS = 1;
					ERR = 1;
					uart0_tx_buf[0] = (CTS<<7|ERR<<6);
					index  = 1;
			}						
		}
	}
	if(index>0)
	{
		slave_send_cmd(uart0_tx_buf,index);
		index =0;
	}
}	
#endif