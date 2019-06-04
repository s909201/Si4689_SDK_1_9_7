/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   MMI: slave mode header
   FILE: mode_slave.h
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

#ifndef _mode_slave_h_
#define _mode_slave_h_

#include "typedefs.h"
#include <platform_options.h>
void slave_command_dispatch(u8 *cmd);
void slave_receive_cmd(void);

//commmon command list
/*
0x01	Set property
0x02	Get property
0x03	Get chip information
0x04	Work mode switch
0x05	volume
0x06	Audio mute
0x07	Power down
0x08	reserve
*/

#define SET_PROPERTY_SLA_CMD		0x01
#define GET_PROPERTY_SLA_CMD		0x02
#define GET_CHIP_INFO_SLA_CMD		0x03
#define VOLUME_SLA_CMD				0x04
#define AUDIO_MUTE_SLA_CMD			0x05
#define POWER_DOWN_SLA_CMD 			0x06

//FM command list
/*
0x20	FM Initialize mode
0x21	FM Tune frequency 
0x22	FM tune status
0x23	FM frequency space
0x24	FM Start Seek 
0x25	FM RDS status(PI,PTY,RT,PST,CT,AF)
0x26	FM RDS PI 
0x27	FM RDS PTY 
0x28	FM RDS PS 
0x29	FM RDS RT
0x2a	FM RDS CT
0x2b	FM RDS AF
*/
#define FM_INIT_MODE_SLA_CMD			0x20
#define FM_TUNE_FREQ_SLA_CMD			0x21   
#define FM_TUNE_STATUS_SLA_CMD			0x22
#define FM_FREQ_SPACE_SLA_CMD			0x23
#define FM_START_SEEK_SLA_CMD			0x24
#define FM_RDS_STATUS_SLA_CMD			0x25
#define FM_RDS_PI_SLA_CMD				0x26
#define FM_RDS_PTY_SLA_CMD				0x27
#define FM_RDS_PS_SLA_CMD				0x28
#define FM_RDS_RT_SLA_CMD				0x29
#define FM_RDS_CT_SLA_CMD				0x2A
#define FM_RDS_AF_SLA_CMD				0x2B


//FMHD command list
/*
0x40	Initialize FMHD mode
0x41	Tune frequency
0x42	Get FMHD current tune status
0x43	Set frequency space
0x44	Seek station
0x45	Get HD service name
0x46	Get service count
0x47	Start HD service by count id
0x48	FMHD information status
0x49	Get RDS RT
0x4A	Get RDS PS
0x4B	Get SIS slogan
0x4C	Get SIS universal short name
0x4D	Get SIS station message
0x4E	Get SIS station name long
0x4F	Get SIS station name short
0x50	Get SIS station id
0x51	Get SIS station location
0x52	Get PSD title
0x53	Get PSD artist
0x54	Get PSD album
0x55	Get PSD genre
0x56	Get alert HD
0x57	reserve
*/
#define FMHD_INIT_MODE_SLA_CMD					0x40
#define FMHD_TUNE_FREQ_SLA_CMD					0x41
#define FMHD_TUNE_STATUS_SLA_CMD				0x42
#define FMHD_FREQ_SPACE_SLA_CMD					0x43
#define FMHD_START_SEEK_SLA_CMD					0x44
#define FMHD_SERVICE_NAME_SLA_CMD				0x45
#define FMHD_SERVICE_COUNT_SLA_CMD				0x46
#define FMHD_START_SERVICE_ID_SLA_CMD			0x47
#define FMHD_INFO_SLA_CMD						0x48
#define FMHD_RDS_RT_SLA_CMD						0x49
#define FMHD_RDS_PS_SLA_CMD						0x4A
#define FMHD_SIS_SLOGAN_SLA_CMD					0x4B
#define FMHD_SIS_USN_SLA_CMD					0x4C
#define FMHD_SIS_SM_SLA_CMD						0x4D
#define FMHD_SIS_SNL_SLA_CMD					0x4E
#define FMHD_SIS_SNS_SLA_CMD					0x4F
#define FMHD_SIS_STI_SLA_CMD					0x50
#define FMHD_SIS_SL_SLA_CMD						0x51
#define FMHD_PSD_TITLE_SLA_CMD					0x52
#define FMHD_PSD_ARTIST_SLA_CMD					0x53
#define FMHD_PSD_ALBUM_SLA_CMD					0x54
#define FMHD_PSD_GENRE_SLA_CMD					0x55
#define FMHD_PSD_ALERT_SLA_CMD					0x56


//DAB command list
/*
0x60	Initialize DAB mode
0x61	DAB scan 
0x62	Service count
0x63	Start DAB service by count id
0x64	Get metrics
0x65	Tune by frequency index
0x66	Tune frequency
0x67	Get service name
0x68	Change frequency list to limit UK 
0x69	Get DLS string
0x6A	Get DAB Time
0x6b	Reserves
*/
#define DAB_INIT_MODE_SLA_CMD					0x60
#define DAB_SCAN_SLA_CMD						0x61
#define DAB_SERVICE_COUNT_SLA_CMD				0x62
#define DAB_START_SERVICE_ID_SLA_CMD			0x63
#define DAB_TUNE_STATUS_SLA_CMD					0x64
#define DAB_TUNE_FREQ_INDEX_SLA_CMD				0x65
#define DAB_TUNE_FREQ_SLA_CMD					0x66
#define DAB_SERVICE_NAME_SLA_CMD				0x67
#define DAB_UK_FREQ_LIST_SLA_CMD				0x68
#define DAB_DLS_STR_SLA_CMD						0x69
#define DAB_TIME_SLA_CMD						0x6A

void seek_scan_process_dispatch(void);

#endif