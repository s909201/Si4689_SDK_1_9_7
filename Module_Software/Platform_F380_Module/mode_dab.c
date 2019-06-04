/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   MMI: for dab functions
   FILE: mode_dab.c
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#include "compiler_defs.h"
#include "typedefs.h"
#include <platform_options.h>

#ifdef OPTION__INCLUDE_MODE__DAB

#ifdef PLATFORM_F380_MODULE
	#include "C8051F380_defs.h"
#endif
#ifdef PLATFORM_F340_DEMOBOARD
	#include "C8051F340_defs.h"
	#include "usb_main.h"
#endif
#include "Firmware_API_Manager.h"

#include "si46xx_firmware_api.h"
#include "SDK_Callbacks.h"
#include "mode_dab.h"
#include "main.h"
#include "mode_common.h"
#include "key.h"
#include "LCD.h"
#include "delay.h"
#include "in_chip_eeprom.h"
/********************************************************************************

********************************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
code u8 DAB_ITEM_STR[][15] = {
	"Info auto roll\n",
	"Metric\n",	
	"DLS String\n",
    #ifdef OPTION__RADIODNS
        "RadioDNS Str\n",
    #endif	
};
code u8 DAB_DISPLAY_ITEM[]={
 		ITEM_AUTO_ROLL,		
 		ITEM_METRIC,				
 		ITEM_DLS_STRING,
        #ifdef OPTION__RADIODNS
            ITEM_RADIODNS_STRING,
        #endif	
};
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
/********************************************************************************
function to change the frequency list to only include those found in the UK - option menu should enable
********************************************************************************/
RETURN_CODE ChangeFreqListToLimitedUK(void)
{
    RETURN_CODE ret;
    uint8_t numFreq = DAB_NUM_ENSEMBLES_UK_REGION;
    uint32_t frequencyList[DAB_NUM_ENSEMBLES_UK_REGION] = {211648, 213360, 215072, 216928, 218640, 220352, 222064, 223936, 225648, 227360, 229072};
    
    ret =  SetFrequencyList_DAB(numFreq, frequencyList);
    ret |= GetFrequencyList_DAB(DAB_NUM_ENSEMBLES_UK_REGION*4,&numFreq, &frequencyList);

    if(ret == SUCCESS)
    {
        if(numFreq != DAB_NUM_ENSEMBLES_UK_REGION)
        {
            return COMMAND_ERROR;
        }

        dab_reduced_list_flag = 1;
        dab_manual_freq_index = 0;
    }

    return ret;
}

/********************************************************************************

********************************************************************************/
RETURN_CODE DAB_scan(void)
{
	RETURN_CODE ret = SUCCESS;

	dab_scan_flag = 1;

#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
	LCD_Clear(LCD_CLEAR_LINE1);
	LCD_DisplayStr("Scanning...\n",0,0);
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI

	ScanBand_DAB();
	dab_scan_flag = 0;

	if(DABServiceListAudioPtr()->SERVICE_COUNT>0)
	{
		CALLBACK_Updated_Data(DAB_TUNE_REQUIRED_UPDATE);
		ret |= BrowseServicesStartCurrentSelection_DAB();
	}
	return ret;
}
/***********************************************************************************
set the parameter to default value
************************************************************************************/
RETURN_CODE dab_set_parameter_default()
{
	RETURN_CODE ret = SUCCESS;
	dab_uk_freq_list_flag = 0;//using internal freq list
    dab_reduced_list_flag = 0;
    dab_favorites_only_flag = 0;
    dab_last_played_service_list_index = 0xFF;

	return ret;
}		
/***********************************************************************************

************************************************************************************/
RETURN_CODE dab_initialize(void)
{
	RETURN_CODE ret = SUCCESS;
	work_mode = dab;

    dab_set_parameter_default();
	pset_table_index =0;

    ret |= Initialize(work_mode);
	ret |= eeprom_get_parameter(); //Note: eeprom_get_parameter must always come after Initialize for dab mode - need to load the service list
    ret |= AudioLevel(volume);

    if(ret == SUCCESS)
    {
    #ifdef  ATS_EMBED_CODE
        if(dab_uk_freq_list_flag || ATS_test_uk_freq_flag)
    	{
    #else
        if(dab_uk_freq_list_flag)
    	{
    #endif
    		ChangeFreqListToLimitedUK();
	    }
        ret = StartLastServiceByIndex(dab_last_played_service_list_index);
    }

    //if(ret != SUCCESS)
    //{
	//	DAB_scan();//then execute dab scan process
	//}

		
	rds_update_ready_item =0;
	sis_update_ready_item =0;
	dls_update_ready_item =0;

	item_loop = ITEM_AUTO_ROLL;
	display_item_str_4ms = 200;
	dab_browse_flag = 0;
	dab_scan_flag = 0;

	return ret;
}
/****************************************************************************************

******************************************************************************************/
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI

extern code u8 RDS_Pty_List[32][9];

void dab_browse_window_refresh(uint8_t* svcStringBrowse, uint8_t* ptyBrowse)
{
    svcStringBrowse[DAB_SERVICE_LIST_SERVICE_LABEL__SIZE] = '\n';
	LCD_Clear(LCD_CLEAR_LINE1);
	LCD_DisplayStr("< Ch >\n",0,0);
	LCD_DisplayStr(RDS_Pty_List[*ptyBrowse],7,0);
    #ifdef OPTION__DAB_PRESETS_AS_FAVORITES
        if(FavoritesIsCurrentServiceAFavorite_DAB())
        {
            LCD_DisplayStr(" *\n",14,0);
        }
    #endif
	LCD_DisplayStr(svcStringBrowse,0,1);
}


RETURN_CODE dab_key_process(void)
{
	RETURN_CODE ret = SUCCESS;
	u8 xdata svcStringBrowse[DAB_SERVICE_LIST_SERVICE_LABEL__SIZE+1];
	u8 ptyBrowse;
	u8 encodingBrowse;

#ifdef OPTION__INCLUDE_FRONT_END_TEST_FUNCTIONS
	uint32_t err;
    uint32_t tot;
	uint8_t berPass;

    uint16_t antcap;
#endif

	if(key_flag==1)
	{
		key_flag = 0;
		display_refresh_flag = 1;
		switch(key_value)
		{
            case SELECT_KEY:
			case TUNE_PRESS_KNOBS:
				if(dab_browse_flag==0)
				{
					item_loop ++;
					if(item_loop>(sizeof(DAB_ITEM_STR)/sizeof(DAB_ITEM_STR[0]))-1)
					{
						item_loop = 0;
					}
					LCD_Clear(LCD_CLEAR_LINE2);
					LCD_DisplayStr(DAB_ITEM_STR[item_loop],0,1);	
					display_item_str_4ms = 500;
	                loop_display_times = 0;
				}
				else
				{
					ret |= BrowseServicesStartCurrentSelection_DAB();
                   	BrowseServicesReset_DAB();
                    eeprom_save_parameter();  //The user has made a change to the current state - we need to save it.
					if(dls_update_ready_item&UPDATED_DLS_STRING_ITEM)
					{
						dls_update_ready_item =0;
						ClearMemory(DLSGetPtr()->DATA,DLSGetPtr()->LENGTH+1);
						DLSGetPtr()->LENGTH = 0;
					}					
					display_item_str_4ms = 0;
				}
				break;
			case DOWN_KEY:
			case TUNE_DEC_KNOBS:
				dab_browse_flag = 1;
				ret = BrowseServicesChangeSelection_DAB(1,svcStringBrowse,&encodingBrowse,&ptyBrowse);
				//LCD_DisplayNum(encodingBrowse,0,14);
				display_item_str_4ms =2500;
				if(ret == SUCCESS)
				{
					dab_browse_window_refresh(svcStringBrowse,&ptyBrowse);
				}
				else
				{
					LCD_DisplayStr("< No Stat list >",0,0);	
				}									
				break;
			case UP_KEY:
			case TUNE_INC_KNOBS:
				dab_browse_flag = 1;
				ret = BrowseServicesChangeSelection_DAB(0,svcStringBrowse,&encodingBrowse,&ptyBrowse);
				//LCD_DisplayNum(encodingBrowse,0,14);
				display_item_str_4ms =2500;
				if(ret == SUCCESS)
				{
					dab_browse_window_refresh(svcStringBrowse,&ptyBrowse);
				}
				else
				{
					LCD_DisplayStr("< No Stat list >",0,0);	
				}		
				break;
			case DAB_RESCAN_KEY:
				DAB_scan();								
				break;
            #ifdef OPTION__DAB_PRESETS_AS_FAVORITES
                case PRESET_INC_KEY:
                case PRESET_DEC_KEY:
				    if(FavoritesIsCurrentServiceAFavorite_DAB() == 0)
                    {
                        FavoritesSetCurrentService_DAB();
                    }             
                    else
                    {
                        FavoritesRemoveCurrentService_DAB();
                    }

                    ret = GetCurrentBrowseServiceString_DAB(svcStringBrowse, &encodingBrowse, &ptyBrowse);
                    if((ret == SUCCESS) && (dab_browse_flag == 1))
                    {
                        dab_browse_window_refresh(svcStringBrowse,&ptyBrowse);
                    }

                    eeprom_save_parameter();

                    break;
            #else
    			case PRESET_INC_KEY:
                case PRESET_DEC_KEY:
                    ret |=pset_operate(key_value);
				    display_item_str_4ms = 1500;
                    break;
            #endif //OPTION__DAB_PRESETS_AS_FAVORITES
            #ifdef OPTION__DAB_PRESETS_AS_FAVORITES
			    case PRESET_INC_HOLD_KEY:
                case PRESET_DEC_HOLD_KEY:
                    LCD_Clear(LCD_CLEAR_ALL);
                    if(dab_favorites_only_flag == 0)
                    {
                        FavoritesBrowseOnly_DAB(1);
                        LCD_DisplayStr("Favorites\n",0,0);
                        dab_favorites_only_flag = 1;
                    }
                    else
                    {
                        FavoritesBrowseOnly_DAB(0);
                        LCD_DisplayStr("All\n",0,0);
                        dab_favorites_only_flag = 0;
                    }
                    
                    display_item_str_4ms = 1000;
                    break;
            #else
                case PRESET_INC_HOLD_KEY:
                case PRESET_DEC_HOLD_KEY:
                    ret |=pset_operate(key_value);
				    display_item_str_4ms = 1000;
                break;
            #endif //OPTION__DAB_PRESETS_AS_FAVORITES
				
#ifdef OPTION__INCLUDE_FRONT_END_TEST_FUNCTIONS
			case HDSEEK_KEY:
			     LCD_Clear(LCD_CLEAR_ALL);
				 LCD_DisplayStr("BER Test\n",0,0);
				// BER Measurement and check for pass
                //***************************
                Test_GetBER_DAB(0xFF, &err,&tot, &berPass); // We expect ABER_NullPattern_test1.eti which uses 0xFF for the pattern
                LCD_Clear(LCD_CLEAR_ALL);
				
				LCD_DisplayNum(err,0,0);
                if(berPass == 0)
				{
					LCD_DisplayStr("BER FAIL\n",0,1);
				}
				else
				{
					LCD_DisplayStr("BER PASS\n",0,1);
				}
				display_item_str_4ms = 3000;
                //***************************
				break;
			case HDSEEK_HOLD_KEY:
				// test the ANTCAP for front end cal
                //***************************
                Test_DeterminePeakANTCAP_DAB(MetricsGetDABPtr()->FREQUENCY_INDEX, &antcap);
                LCD_Clear(LCD_CLEAR_ALL);
                LCD_DisplayStr("ANTCAP Peak\n",0,0);
                LCD_DisplayNum(antcap,8,1);
				display_item_str_4ms = 3000;
                //***************************
				break;
#endif
			default:
                key_flag = 1;//display_refresh_flag = 0;
                break;
		}
	}
	return ret;
}
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI
/****************************************************************************************

******************************************************************************************/
RETURN_CODE dab_work_mode(void)
{
	RETURN_CODE ret = SUCCESS;
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI
	u8 xdata svcStringCurrent[DAB_SERVICE_LIST_SERVICE_LABEL__SIZE+2];
	u8 xdata service_name[DAB_SERVICE_LIST_SERVICE_LABEL__SIZE+2];
	u8 xdata service_name_len;
	u8 ptyCurrent;
	u8 encodeingCurrent;
	dab_metrics* dabMet;
	static u8 display_item_state = 0;
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI

	if( power_flag ==0)
	{
		power_flag =1;
		dab_initialize();
	}
#ifndef OPTION__OPERATE_AS_SLAVE_NO_MMI

	ret |=dab_key_process();

	if(display_item_str_4ms >0)
	{
		//display_refresh_flag = 1;
		return 0;// wait for time up
	}

	if(display_refresh_flag)
	{
		display_refresh_flag = 0;
		ret = UpdateMetrics();
		dabMet = MetricsGetDABPtr();
        LCD_Clear(LCD_CLEAR_LINE1);
    	ret = GetCurrentServiceString_DAB(svcStringCurrent,&encodeingCurrent,&ptyCurrent);
		if((dabMet->VALID >0) && (dabMet->ACQ >0) && (ret == SUCCESS))//if there are a valid station, display the current service name
		{
		    decode_str(service_name,&service_name_len,svcStringCurrent,16,encodeingCurrent);
			service_name[service_name_len+1] = '\n';
    		LCD_DisplayStr(service_name,0,0);
		}
		else
		{
			LCD_DisplayStr("[No DAB station]\n",0,0);//prompt no service station
            ReacquireCurrentService_DAB();
		}			
		if(mute_flag)
		{
			LCD_DisplayCBD(DEF_HORN,14,0);	
			LCD_DisplayCBD(DEF_DELETE,15,0);		
		}
	}
	if(display_item_str_4ms ==0)
	{
		dab_browse_flag= 0;
        BrowseServicesReset_DAB();
        #ifdef OPTION__DAB_PRESETS_AS_FAVORITES
            if((FavoritesIsCurrentServiceAFavorite_DAB() == 1) && (mute_flag == 0))
            {
                LCD_DisplayStr("*\n",15,0);
            }
        #endif
		display_item_str_4ms = STATUS_UPDATE_INTERVAL;
		if(item_loop == ITEM_AUTO_ROLL) // display will auto change next next 
		{
			if(display_item_state > sizeof(DAB_DISPLAY_ITEM)/sizeof(DAB_DISPLAY_ITEM[0])-1)
			{
				display_item_state = 1;
			}
		}
		else
		{
			display_item_state = item_loop;// fix display special item switched by hold tune knobs
		}
		if(display_data_item(DAB_DISPLAY_ITEM[display_item_state]) == ITEM_NEXT)
		{
			display_item_state ++;
		}
	}

#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI

#ifdef OPTION__OPERATE_AS_SLAVE_NO_MMI
	ret |= UpdateMetrics();
	ret |= UpdateDataServiceData();
#endif //OPTION__OPERATE_AS_SLAVE_NO_MMI

    ret |= UpdateServiceList(); // Need to periodically check for updates to the service list - reconfiguration
	return ret;
}
#endif //OPTION__INCLUDE_MODE__DAB