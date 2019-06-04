/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   SDK->MMI callback implementations for C8051F380 based module
   FILE: SDK_Callbacks.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#include "common_types.h"
#include "platform_options.h"
#include "main.h"
#include "SDK_Callbacks.h"
#include "mode_common.h"
#include "mode_dab.h"
#include "LCD.h"
#include "Firmware_API_Manager.h"
#include "key.h"
#include "delay.h"
#include "mode_slave.h"
#include "in_chip_eeprom.h"


void CALLBACK_Updated_Data(SDK_CALLBACKS_UPDATED_DATA_TYPE updatedType)
{
#ifdef OPTION__INCLUDE_MODE__DAB
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
	u8 i;
	static u16 temp_index =0;
    u8 totalFrequencyIndex;
#endif
#endif

    switch(updatedType)
    {
#ifdef OPTION__INCLUDE_MODE__FM
        case UPDATED_RDS_PI:
			rds_update_ready_item |=UPDATED_RDS_PI_ITEM;
        	break;

        case UPDATED_RDS_PTY:
			rds_update_ready_item |=UPDATED_RDS_PTY_ITEM;
        	break;

        case UPDATED_RDS_RT:
			rds_update_ready_item |=UPDATED_RDS_RT_ITEM;
        	break;

        case UPDATED_RDS_PST:
			rds_update_ready_item |=UPDATED_RDS_PST_ITEM;
        	break;

        case UPDATED_RDS_TIME:
			rds_update_ready_item |=UPDATED_RDS_TIME_ITEM;
        	break;

        case UPDATED_RDS_ALT_FREQ:
			rds_update_ready_item |=UPDATED_RDS_ALT_FREQ_ITEM;
        	break;
#endif //OPTION__INCLUDE_MODE__FM
#ifdef OPTION__INCLUDE_MODE__FMHD
    #ifdef OPTION__DECODE_SIS
        //SIS
        case UPDATED_SIS_SLOGAN:
			sis_update_ready_item |= UPDATED_SIS_SLOGAN_ITEM;
        	break;

        case UPDATED_SIS_UNIVERSAL_SHORT_NAME:
			sis_update_ready_item |= UPDATED_SIS_UNIVERSAL_SHORT_NAME_ITEM;
        	break;

        case UPDATED_SIS_STATION_MESSAGE:
			sis_update_ready_item |= UPDATED_SIS_STATION_MESSAGE_ITEM;
        	break;

        case UPDATED_SIS_STATION_NAME_LONG:
			sis_update_ready_item |= UPDATED_SIS_STATION_NAME_LONG_ITEM;
        	break;

        case UPDATED_SIS_STATION_NAME_SHORT:
			sis_update_ready_item |= UPDATED_SIS_STATION_NAME_SHORT_ITEM;
        	break;

        case UPDATED_SIS_STATION_ID:
			sis_update_ready_item |= UPDATED_SIS_STATION_ID_ITEM;
        	break;

        case UPDATED_SIS_LOC_LAT:
			sis_update_ready_item |= UPDATED_SIS_LOC_LAT_ITEM;
        	break;

        case UPDATED_SIS_LOC_LON:
			sis_update_ready_item |= UPDATED_SIS_LOC_LON_ITEM;
        	break;
    #endif //OPTION__DECODE_SIS
    #ifdef OPTION__DECODE_PSD
        //PSD
        case UPDATED_PSD_TITLE:
			psd_update_ready_item |= UPDATED_PSD_TITLE_ITEM;
        	break;

        case UPDATED_PSD_ARTIST:
			psd_update_ready_item |= UPDATED_PSD_ARTIST_ITEM;
        	break;

        case UPDATED_PSD_ALBUM:
			psd_update_ready_item |= UPDATED_PSD_ALBUM_ITEM;
        	break;

        case UPDATED_PSD_GENRE:
			psd_update_ready_item |= UPDATED_PSD_GENRE_ITEM;
        	break;

    #endif //OPTION__DECODE_PSD
    #ifdef OPTION__DECODE_HD_ALERTS
        case UPDATED_HD_ALERT:
			alert_update_ready_item |= UPDATED_ALERT_ITEM;
        	break;
    #endif //OPTION__DECODE_HD_ALERTS

        case UPDATED_SERVICE_LIST_FAST:	
    	case UPDATED_SERVICE_LIST_AUDIO:
	    case UPDATED_SERVICE_LIST_DATA:

#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
				show_freq(0,0);
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
			break;

#endif //OPTION__INCLUDE_MODE__FMHD
#ifdef OPTION__INCLUDE_MODE__DAB
        case DAB_SERVICE_LIST_REQUIRED_UPDATE:
            if(!dab_scan_flag)//avoid display scroll when tuning not scanning
			{

#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
				LCD_Clear(LCD_CLEAR_LINE1);
                LCD_DisplayStr("List Update\n",0,0);
                display_refresh_flag = 1;
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI

			}
            break;
//#ifdef OPTION__DAB_SERVICE_LIST_PERSISTENCE
//        case UPDATED_SERVICE_LIST_DAB:
//            eeprom_save_parameter();
//            break;
//#endif //OPTION__DAB_SERVICE_LIST_PERSISTENCE
    #ifdef OPTION__DECODE_DLS
        //DLS
        case UPDATED_DLS_STRING:
			dls_update_ready_item |= UPDATED_DLS_STRING_ITEM;
        	break;
    #endif //OPTION__DECODE_DLS
        case SERVICE_LIST_BUFFER_FULL_ERROR:

#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
            LCD_DisplayStr("LIST FULL \n",0,0);
			wait_ms(1000);
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
            break;

		case DAB_TUNE_SCAN_PROCESS_UPDATE:

#ifdef OPTION__OPERATE_AS_SLAVE_NO_MMI
			seek_scan_process_dispatch();
#endif

#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI

			key_scan();
			if(key_flag)
			{
				key_flag = 0;
				switch(key_value)
				{
					case MODE_KEY:
					case ON_OFF_KEY:
					case DAB_RESCAN_KEY:
						ScanBandCancel_DAB();
						LCD_DisplayStr("Stop scan\n",0,0);
						wait_ms(1000);
						break;
					default:break;
				}
			}
			if(!dab_scan_flag)//avoid display scroll when tuning not scanning
			{
				break;
			}
			if(temp_index == MetricsGetDABPtr()->FREQUENCY_INDEX)
			{
				break;
			}
			temp_index = MetricsGetDABPtr()->FREQUENCY_INDEX;

			LCD_DisplayNum(DABServiceListAudioPtr()->SERVICE_COUNT,14,0);

            if(dab_reduced_list_flag)
            {
                totalFrequencyIndex = DAB_NUM_ENSEMBLES_UK_REGION;
            }
            else
            {
                totalFrequencyIndex = DAB_STANDARD__MAX_ENSEMBLES_EUROPE;
            }
			for(i=0;i<16;i++)
			{	
				if((((temp_index+1)*16)/totalFrequencyIndex)>i)
				{
					LCD_DisplayCBD(DEF_SFRECTANGLE,i,1);
				}
				else
				{
					LCD_DisplayCBD(DEF_SERECTANLG,i,1);	
				}			
			}
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
			break;
        case DAB_TUNE_REQUIRED_UPDATE:

#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
            LCD_Clear(LCD_CLEAR_ALL);
    		LCD_DisplayStr("Tuning...\n",0,0);
    		LCD_DisplayStr("Please wait\n",0,1);
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI

            break;
		case DAB_TUNE_SCAN_PROCESS_COMPLETE:
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
				LCD_Clear(LCD_CLEAR_LINE2);
				//LCD_DisplayStr("- Complete -\n",2,1);
				//wait_ms(1000);//comment for speeding up in manual tuning
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
			break;
//		case EVENT_ENSEMBLE_RECONFIGURATION:
//
//            break;
//        case EVENT_ENSEMBLE_RECONFIGURATION_WARNING:
//
//            break;
//        case EVENT_CURRENT_SERVICE_NO_LONGER_AVAILABLE:
//
//            break;
        case EVENT_FINDING_ALTERNATE_SERVICE:

#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
            LCD_Clear(LCD_CLEAR_ALL);
    		LCD_DisplayStr("Searching\n",0,0);
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI

            break;
    #ifdef OPTION__INCLUDE_FRONT_END_TEST_FUNCTIONS
        case DAB_FRONT_END_CAL_PROCESS_UPDATE:

			#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
            LCD_Clear(LCD_CLEAR_LINE1);
            LCD_DisplayNum(_ANTCAP_DAB,0,0);
			#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI

            break;
    #endif
#endif //OPTION__INCLUDE_MODE__DAB

        case EVENT_READY_FOR_FIRMWARE_UPDATE:

			#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
            LCD_DisplayStr("FIRMWARE UPDATE\n",0,0);
			#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI

			//wait_ms(1000);
            break;
#ifdef OPTION__INCLUDE_MODE__FM
        case FM_SEEK_PROCESS_UPDATE:
		case AM_SEEK_PROCESS_UPDATE:
			
    #ifdef 	OPTION__OPERATE_AS_SLAVE_NO_MMI
			seek_scan_process_dispatch();
    #else 
            if(work_mode == fmonly)
			{
                fm_freq = MetricsGetFMPtr()->FREQUENCY_10KHZ;
                rds_update_ready_item = 0;
			}    
		#ifdef OPTION__INCLUDE_MODE__AM
			else if(work_mode == am)
			{
				am_freq = MetricsGetAMPtr()->FREQUENCY_1KHZ;
			}
		#endif
		#ifdef OPTION__INCLUDE_MODE__FMHD 
			else if(work_mode == fmhd)
			{
                fmhd_freq = MetricsGetFMHDPtr()->FREQUENCY_10KHZ;
                rds_update_ready_item = 0;
			    sis_update_ready_item = 0;
                psd_update_ready_item = 0;
                alert_update_ready_item = 0;
			}
    	#endif //OPTION__INCLUDE_MODE__FMHD
		#ifdef OPTION__INCLUDE_MODE__AMHD 
			else if(work_mode == amhd)
			{
                amhd_freq = MetricsGetAMHDPtr()->FREQUENCY_1KHZ;
			    sis_update_ready_item = 0;
                psd_update_ready_item = 0;
                alert_update_ready_item = 0;
			}
    	#endif //OPTION__INCLUDE_MODE__FMHD
		    show_freq(0,0);
    #endif //OPTION__OPERATE_AS_SLAVE_NO_MMI

            break;
        
        case FM_SEEK_PROCESS_COMPLETE:
		case AM_SEEK_PROCESS_COMPLETE:
            if(work_mode == fmonly)
			{
				fm_freq = MetricsGetFMPtr()->FREQUENCY_10KHZ;
			}
    #ifdef OPTION__INCLUDE_MODE__FMHD
			else if(work_mode == fmhd)
			{
    
                fmhd_freq = MetricsGetFMHDPtr()->FREQUENCY_10KHZ;
            }
    #endif //OPTION__INCLUDE_MODE__FMHD
	#ifdef OPTION__INCLUDE_MODE__AM
			else if(work_mode == am)
			{
				am_freq = MetricsGetAMPtr()->FREQUENCY_1KHZ;
			}
	#endif
	#ifdef OPTION__INCLUDE_MODE__AMHD
			else if(work_mode == amhd)
			{
				amhd_freq = MetricsGetAMHDPtr()->FREQUENCY_1KHZ;
			}
	#endif
            seek_state = SEEK_NULL;
            display_refresh_flag = 1;
            break;
#endif // OPTION__INCLUDE_MODE__FM
        default:
        	break;
    }
}