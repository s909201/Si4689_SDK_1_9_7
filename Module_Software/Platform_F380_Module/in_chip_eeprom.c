/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   persistant storage using internal MCU flash driver for C8051F380 based module
   FILE: in_chip_eeprom.c
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

#include "in_chip_eeprom.h"
#include "delay.h"
#include "main.h"
#include "mode_fm_am.h"
#include "mode_fmhd_amhd.h"
#include "mode_dab.h"
#include "mode_common.h"
#include "utility.h"

#include "Firmware_API_Manager.h" // Needed to store DAB service list
/****************************************************************************
This subroutine write a byte data to scratchpad area of flash 0x0000~0x1FF
****************************************************************************
void eeprom_wbyte(u16 addr,u8 in_data)
{
	u8 xdata * data pWrite;
	EA = 0; //close all the interrupt while write Flash
	pWrite = (u8 xdata *) addr; //pointer to the Flash area to be write

    VDM0CN = 0x80;                      // Enable VDD monitor

    RSTSRC = 0x02;                      // Enable VDD monitor as a reset source

	FLKEY = 0xA5;
	FLKEY = 0xF1; //unlock the Flash write/erase option
	
	PSCTL = 0x01; //Enable the scratchpad area write set SFLE bit of PSCTL.2 and  PSCTL.0

	VDM0CN = 0x80;
	RSTSRC = 0x02;

	*pWrite = in_data;

	PSCTL &=~0x03; //disable all write/erase function to flash
	EA = 1;		//open the interrupt 
}
/******************************************************************************
this function read a byte data from indicated address of flash
*******************************************************************************
u8 eeprom_rbyte(u16 addr)
{
	u16 code * data pRead;
	u8 rdata;
	EA = 0;  //close the interrupt
	pRead = (u16 code *) addr; //point to the flash area to be read
	
	//FLKEY = 0xA5;
	//FLKEY = 0xF1; //unlock the Flash write/erase option
	
	PSCTL = 0x03; //Enable the scratchpad area write set SFLE bit of PSCTL.2
	rdata = *pRead;
	PSCTL &=~0x03; //disable all write/erase function to flash
	EA = 1;		//open the interrupt 
	
	return rdata;	
}
/****************************************************************************
This subroutine Erase a page data to scratchpad area of flash 0x000~0x1FF
****************************************************************************
#define EEPROM_STRORE_START_ADDRESS 0x3700
void eeprom_page_erase(void) 
{
	u8 xdata * data pWrite;
	EA = 0; //close all the interrupt while write Flash
	pWrite = (u8 xdata *) EEPROM_STRORE_START_ADDRESS; //pointer to the beginning address of scratchpad Flash area to be write

	FLKEY = 0xA5;
	FLKEY = 0xF1; //unlock the Flash write/erase option
	
	PSCTL |= 0x03; //Enable the scratchpad area write set SFLE PSEE PSWE

//	VDM0CN = 0x80;
//	RSTSRC = 0x02;
	*pWrite = 0xff;
	PSCTL &=~0x03; //disable all write/erase function to flash

	EA = 1;		//open the interrupt 
}
/************************************************************************************

************************************************************************************/
#define EEPROM_STRORE_START_ADDRESS 0x3620
#define eeprom_wbyte(addr,in_data)  flash_write(addr, in_data)
#define eeprom_rbyte(addr)    		flash_read(addr)
#define eeprom_page_erase() 		flash_page_erase(EEPROM_STRORE_START_ADDRESS);flash_page_erase(EEPROM_STRORE_START_ADDRESS+0x100);

#define FM_START_ADDR	3
#define FMHD_START_ADDR FM_START_ADDR+30
#define DAB_START_ADDR  FMHD_START_ADDR+50
#define AM_START_ADDR 	DAB_START_ADDR+245
#define AMHD_START_ADDR	AM_START_ADDR+30
#define COMMAND_VARIBLE_ADDR AMHD_START_ADDR+50

#ifndef OPTION__DAB_PRESETS_AS_FAVORITES
    #define PARAMETER_VERSION 0x11
#else
    #define PARAMETER_VERSION 0x84 //We need to mark the storage differently in case a user has stored data from the alternate pset mode for dab
#endif

RETURN_CODE eeprom_save_parameter(void)
{
    RETURN_CODE ret = 0;
	u8 i;
    u8 j;
	u16 addr = EEPROM_STRORE_START_ADDRESS;
	eeprom_page_erase();//erase all scratchpad area for save parameter

    //common variable
	eeprom_wbyte(addr++,PARAMETER_VERSION);
    eeprom_wbyte(addr++,work_mode);


#ifdef OPTION__INCLUDE_MODE__FM
//--------------------------FM---------------------

	addr = EEPROM_STRORE_START_ADDRESS + FM_START_ADDR;
	eeprom_wbyte(addr++,(u8)(fm_freq>>8));
	eeprom_wbyte(addr++,(u8)(fm_freq));
	eeprom_wbyte(addr++,(u8)(fm_freq_step_size));
	eeprom_wbyte(addr++,(u8)(mono_stereo_flag));
	for(i=0;i<MAX_PRESET_NUM;i++)//persist in flash of MCU
	{
		eeprom_wbyte(addr++,(u8)(fm_pset_table[i]>>8));
		eeprom_wbyte(addr++,(u8)(fm_pset_table[i]));
	}
#endif
//--------------------------FMHD---------------------
#ifdef OPTION__INCLUDE_MODE__FMHD

	addr = EEPROM_STRORE_START_ADDRESS+FMHD_START_ADDR;
	eeprom_wbyte(addr++,(u8)(fmhd_freq>>8));
	eeprom_wbyte(addr++,(u8)(fmhd_freq));
	eeprom_wbyte(addr++,(u8)(fmhd_freq_step_size));
	for(i=0;i<MAX_PRESET_NUM;i++)//persist in flash of MCU
	{
		eeprom_wbyte(addr++,(u8)(fmhd_pset_table[i].valid));
		eeprom_wbyte(addr++,(u8)(fmhd_pset_table[i].frequency>>8));
		eeprom_wbyte(addr++,(u8)(fmhd_pset_table[i].frequency));
		eeprom_wbyte(addr++,(u8)(fmhd_pset_table[i].component_id));
		for(j=0;j<6;j++)
		{
			eeprom_wbyte(addr++,fmhd_pset_table[i].service_name[j]);
		}
	}
    eeprom_wbyte(addr++,(u8)(fmhd_seekonly));
#endif
//---------------------------DAB---------------------

#ifdef OPTION__INCLUDE_MODE__DAB

		addr = EEPROM_STRORE_START_ADDRESS+DAB_START_ADDR;
		eeprom_wbyte(addr++,(u8)(dab_uk_freq_list_flag));

        #ifndef OPTION__DAB_PRESETS_AS_FAVORITES
    		for(i=0;i<MAX_PRESET_NUM;i++)//persist in flash of MCU
    		{
    			eeprom_wbyte(addr++,dab_pset_table[i].valid);
    			eeprom_wbyte(addr++,dab_pset_table[i].freq_index);

    			eeprom_wbyte(addr++,(u8)(dab_pset_table[i].service_id>>24));
    			eeprom_wbyte(addr++,(u8)(dab_pset_table[i].service_id>>16));
    			eeprom_wbyte(addr++,(u8)(dab_pset_table[i].service_id>>8));
    			eeprom_wbyte(addr++,(u8)(dab_pset_table[i].service_id));
    			eeprom_wbyte(addr++,(u8)(dab_pset_table[i].component_id>>8));
    			eeprom_wbyte(addr++,(u8)(dab_pset_table[i].component_id));

    			for(j=0;j<16;j++)
    			{
    				eeprom_wbyte(addr++,dab_pset_table[i].label_str[j]);
    			}
    		}
        #endif //OPTION__DAB_PRESETS_AS_FAVORITES

        if(current_work_mode == dab)
        {
        #ifdef OPTION__DAB_SERVICE_LIST_PERSISTENCE
            ret = SaveServiceList_DAB();
        #endif
        }
#endif

#ifdef OPTION__INCLUDE_MODE__AM
//--------------------------FM---------------------

	addr = EEPROM_STRORE_START_ADDRESS + AM_START_ADDR;
	eeprom_wbyte(addr++,(u8)(am_freq>>8));
	eeprom_wbyte(addr++,(u8)(am_freq));
	eeprom_wbyte(addr++,(u8)(am_freq_step_size));
//	eeprom_wbyte(addr++,(u8)(mono_stereo_flag));
	for(i=0;i<MAX_PRESET_NUM;i++)//persist in flash of MCU
	{
		eeprom_wbyte(addr++,(u8)(am_pset_table[i]>>8));
		eeprom_wbyte(addr++,(u8)(am_pset_table[i]));
	}
#endif
//--------------------------FMHD---------------------
#ifdef OPTION__INCLUDE_MODE__AMHD

	addr = EEPROM_STRORE_START_ADDRESS+AMHD_START_ADDR;
	eeprom_wbyte(addr++,(u8)(amhd_freq>>8));
	eeprom_wbyte(addr++,(u8)(amhd_freq));
	eeprom_wbyte(addr++,(u8)(amhd_freq_step_size));
	for(i=0;i<MAX_PRESET_NUM;i++)//persist in flash of MCU
	{
		eeprom_wbyte(addr++,(u8)(amhd_pset_table[i].valid));
		eeprom_wbyte(addr++,(u8)(amhd_pset_table[i].frequency>>8));
		eeprom_wbyte(addr++,(u8)(amhd_pset_table[i].frequency));
		eeprom_wbyte(addr++,(u8)(amhd_pset_table[i].component_id));
		for(j=0;j<6;j++)
		{
			eeprom_wbyte(addr++,amhd_pset_table[i].service_name[j]);
		}
	}
    eeprom_wbyte(addr++,(u8)(fmhd_seekonly));
#endif

    //common variable
		addr = EEPROM_STRORE_START_ADDRESS +COMMAND_VARIBLE_ADDR;
		eeprom_wbyte(addr++,(u8)(ship_ats_inter_flag)); 
		eeprom_wbyte(addr++,(u8)auto_time_correct_flag);
        eeprom_wbyte(addr++,(u8)volume);
    return ret;
}

/************************************************************************************
This function get all AM/FM parameter from Flash
************************************************************************************/
RETURN_CODE eeprom_get_work_mode(void)
{
    u16 addr;
    u8 temp;
    u8 unknown_mode = 0;
    
    addr = EEPROM_STRORE_START_ADDRESS;
	temp = eeprom_rbyte(addr++);

	if(temp == PARAMETER_VERSION)
	{
        work_mode = eeprom_rbyte(addr++);

        //Because we boot based upon the build loaded we need to confirm if the last image was a build which is not currently loaded
        #ifndef OPTION__INCLUDE_MODE__FM
            if(work_mode == fmonly)
            {
                unknown_mode = 1;
            }
        #endif
        #ifndef OPTION__INCLUDE_MODE__FMHD
            if(work_mode == fmhd)
            {
                unknown_mode = 1;
            }
        #endif
        #ifndef OPTION__INCLUDE_MODE__DAB
            if(work_mode == dab)
            {
                unknown_mode = 1;
            }
        #endif

		#ifndef OPTION__INCLUDE_MODE__AM
			if(work_mode == am)
			{
				unknown_mode = 1;
			}
		#endif

		#ifndef OPTION__INCLUDE_MODE__AMHD
			if(work_mode == amhd)
			{
				unknown_mode = 1;
			}
		#endif

        //Either the EEPROM version was not recognized or we were last in a work_mode which is not supported in this image
        //ignore the EEPROM
        if(unknown_mode == 1)
        {
        #ifdef OPTION__INCLUDE_MODE__FM
      		fm_am_set_parameter_default();
            work_mode = fmonly;
        #endif //OPTION__INCLUDE_MODE__FM
        #ifdef OPTION__INCLUDE_MODE__FMHD
     		fmhd_amhd_set_parameter_default();
            work_mode = fmhd;
        #endif //OPTION__INCLUDE_MODE__FMHD
        #ifdef OPTION__INCLUDE_MODE__DAB
      		dab_set_parameter_default();
            work_mode = dab;
        #endif //OPTION__INCLUDE_MODE__DAB
        }

        //common variable stored
		addr = EEPROM_STRORE_START_ADDRESS+COMMAND_VARIBLE_ADDR;
		ship_ats_inter_flag = eeprom_rbyte(addr++);
		auto_time_correct_flag = eeprom_rbyte(addr++);
        volume = eeprom_rbyte(addr++);

        return SUCCESS; // successful load
    }

    addr = EEPROM_STRORE_START_ADDRESS;
	eeprom_page_erase();//erase all scratchpad area for save parameter

	ship_ats_inter_flag = 0;
	auto_time_correct_flag = AUTO_TIME_CORRECT_ENABLE;
    volume = MAX_VOLUME;

    return INVALID_INPUT;
}


RETURN_CODE eeprom_get_parameter(void)
{
	u16 addr,i,j;
    u8 temp;

    addr = EEPROM_STRORE_START_ADDRESS;
	temp = eeprom_rbyte(addr++);

	if(temp == PARAMETER_VERSION)
    {
    //-----------------------FM -----------------------------------------
    #ifdef OPTION__INCLUDE_MODE__FM
    	if(work_mode == fmonly)
    	{
    		addr = EEPROM_STRORE_START_ADDRESS+FM_START_ADDR;
    		fm_freq = ((u16)eeprom_rbyte(addr++)<<8)|(u16)eeprom_rbyte(addr++);
    		fm_freq_step_size = eeprom_rbyte(addr++);
    		mono_stereo_flag = eeprom_rbyte(addr++);
    		for(i=0;i<MAX_PRESET_NUM;i++)//persist in flash of MCU
    		{
    			fm_pset_table[i] = ((u16)eeprom_rbyte(addr++)<<8)|(u16)eeprom_rbyte(addr++);
    		}
            return SUCCESS;
    	}
    #endif
    //-----------------------FMHD ------------------------------------------
    #ifdef OPTION__INCLUDE_MODE__FMHD
    	if(work_mode == fmhd)
    	{
    		addr = EEPROM_STRORE_START_ADDRESS+FMHD_START_ADDR;
    		fmhd_freq = ((u16)eeprom_rbyte(addr++)<<8)|(u16)eeprom_rbyte(addr++);
    		fmhd_freq_step_size = eeprom_rbyte(addr++);
    		for(i=0;i<MAX_PRESET_NUM;i++)//persist in flash of MCU
    		{
    			fmhd_pset_table[i].valid = eeprom_rbyte(addr++);
    			fmhd_pset_table[i].frequency=((u16)eeprom_rbyte(addr++)<<8)|(u16)eeprom_rbyte(addr++);
    			fmhd_pset_table[i].component_id = eeprom_rbyte(addr++);
    			for(j=0;j<6;j++)
    			{
    				fmhd_pset_table[i].service_name[j] = eeprom_rbyte(addr++);
    			}
    		}
            fmhd_seekonly = eeprom_rbyte(addr++)&0x01;

            return SUCCESS;
    	}
    #endif


    //------------------------DAB---------------------------------------------
    #ifdef OPTION__INCLUDE_MODE__DAB
		if(work_mode == dab)
		{
			addr = EEPROM_STRORE_START_ADDRESS+DAB_START_ADDR;
			dab_uk_freq_list_flag = (bit)eeprom_rbyte(addr++);

            #ifndef OPTION__DAB_PRESETS_AS_FAVORITES
    			for(i=0;i<MAX_PRESET_NUM;i++)//persist in flash of MCU
    			{
    				dab_pset_table[i].valid =eeprom_rbyte(addr++);
    				dab_pset_table[i].freq_index =eeprom_rbyte(addr++);
    				dab_pset_table[i].service_id =((u32)(eeprom_rbyte(addr++))<<24)
    												|((u32)(eeprom_rbyte(addr++))<<16)
    												|((u32)(eeprom_rbyte(addr++))<<8)
    												|((u32)(eeprom_rbyte(addr++)));	
    				dab_pset_table[i].component_id = ((u16)eeprom_rbyte(addr++)<<8)|(u16)eeprom_rbyte(addr++);
    				for(j=0;j<16;j++)
    				{
    					dab_pset_table[i].label_str[j] = eeprom_rbyte(addr++);
    				}
    			}
            #endif //#OPTION__DAB_PRESETS_AS_FAVORITES
	        #ifdef OPTION__DAB_SERVICE_LIST_PERSISTENCE
	            return LoadServiceList_DAB(&dab_last_played_service_list_index);
            
	        #endif
		}
    #endif

    #ifdef OPTION__INCLUDE_MODE__AM
    	if(work_mode == am)
    	{
    		addr = EEPROM_STRORE_START_ADDRESS+AM_START_ADDR;
    		am_freq = ((u16)eeprom_rbyte(addr++)<<8)|(u16)eeprom_rbyte(addr++);
    		am_freq_step_size = eeprom_rbyte(addr++);
    		//mono_stereo_flag = eeprom_rbyte(addr++);
    		for(i=0;i<MAX_PRESET_NUM;i++)//persist in flash of MCU
    		{
    			am_pset_table[i] = ((u16)eeprom_rbyte(addr++)<<8)|(u16)eeprom_rbyte(addr++);
    		}
            return SUCCESS;
    	}
    #endif
	#ifdef OPTION__INCLUDE_MODE__AMHD
		if(work_mode == amhd)
		{
			addr = EEPROM_STRORE_START_ADDRESS+AMHD_START_ADDR;
    		amhd_freq = ((u16)eeprom_rbyte(addr++)<<8)|(u16)eeprom_rbyte(addr++);
    		amhd_freq_step_size = eeprom_rbyte(addr++);
    		for(i=0;i<MAX_PRESET_NUM;i++)//persist in flash of MCU
    		{
    			amhd_pset_table[i].valid = eeprom_rbyte(addr++);
    			amhd_pset_table[i].frequency=((u16)eeprom_rbyte(addr++)<<8)|(u16)eeprom_rbyte(addr++);
    			amhd_pset_table[i].component_id = eeprom_rbyte(addr++);
    			for(j=0;j<6;j++)
    			{
    				amhd_pset_table[i].service_name[j] = eeprom_rbyte(addr++);
    			}
    		}
            fmhd_seekonly = eeprom_rbyte(addr++)&0x01;

            return SUCCESS;
    	}
	#endif //option__include_mode__amhd
	}

    return INVALID_INPUT;
}

/************************************************************************************
save/read the service list information into MCU flash
input:
	start_addr: store start address like: 0xF000
	len: data length
	buffer: data point
ouput:
	None
note:
	before writing the data into flash, it need to erase the flash
	call function flash_page_erase()
************************************************************************************/
#ifdef OPTION__INCLUDE_MODE__DAB
    #ifdef OPTION__DAB_SERVICE_LIST_PERSISTENCE

    //The F380 cannot in-system erase beyond 0xFA00 because it cannot erase the page which contains the lock byte (0xFA00) and 0xFC00 is reserved
    #define MCU_RESERVED_FLASH_ADDR 0xFA00
    #define MCU_PAGE_SIZE 512
    #define MCU_SDK_STORAGE_START_ADDRESS 0x2800
    #define MCU_SDK_STORAGE_END_ADDRESS 0x3600
    #define MCU_SDK_STORAGE_SIZE (MCU_SDK_STORAGE_END_ADDRESS - MCU_SDK_STORAGE_START_ADDRESS)

    const u8 code DABServiceListStorage[MCU_SDK_STORAGE_SIZE] _at_ MCU_SDK_STORAGE_START_ADDRESS;

    RETURN_CODE write_storage(u16 start_addr,u16 len,u8* buffer)
    {
    	u16 i = 0;
        u16 addr = start_addr + MCU_SDK_STORAGE_START_ADDRESS;
    
        if((addr + len) >= MCU_SDK_STORAGE_END_ADDRESS)
        {
            return INVALID_INPUT;
        }

    	while(len--)
    	{
    		if(addr&0x00FF == 0x0000)
    		{
    			flash_page_erase(addr);//one page contain 256 bytes, and will erase one page one times
    		}
    		eeprom_wbyte(addr++,buffer[i++]);
    	}

        return SUCCESS;
    }
    RETURN_CODE read_storage(u16 start_addr,u16 len,u8* buffer)
    {
    	u16 i = 0;
        u16 addr = start_addr + MCU_SDK_STORAGE_START_ADDRESS;

        if((addr + len) >= MCU_SDK_STORAGE_END_ADDRESS)
        {
            return INVALID_INPUT;
        }

    	while(len--)
    	{
    		buffer[i++] = eeprom_rbyte(addr++);
    	}

        return SUCCESS;
    }

    void erase_storage()
    {
        u16 addr;

        for(addr = MCU_SDK_STORAGE_START_ADDRESS; addr < MCU_SDK_STORAGE_END_ADDRESS; addr += MCU_PAGE_SIZE)
        {
            flash_page_erase(addr);
        }
    }
    #endif // OPTION__DAB_SERVICE_LIST_PERSISTENCE
#endif // OPTION__INCLUDE_MODE__DAB