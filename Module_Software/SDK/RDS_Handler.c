/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   SDK RDS decoder
   FILE: RDS_Handler.c
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include "common_types.h"
#include "platform_options.h"
#include "RDS_Handler.h"
#include "SDK_Callbacks.h"
//#include "si46xx_firmware_api.h"

#ifdef OPTION__INCLUDE_MODE__FM
#ifdef OPTION__RDS_BUFFER_V4L2
// TODO: add V4L2 implementation of RDS buffers
#else
//-----------------------------------------------------------------------------
// local defines
//-----------------------------------------------------------------------------
#define RDS_TYPE_0A     ( 0 * 2 + 0)
#define RDS_TYPE_0B     ( 0 * 2 + 1)
#define RDS_TYPE_1A     ( 1 * 2 + 0)
#define RDS_TYPE_1B     ( 1 * 2 + 1)
#define RDS_TYPE_2A     ( 2 * 2 + 0)
#define RDS_TYPE_2B     ( 2 * 2 + 1)
#define RDS_TYPE_3A     ( 3 * 2 + 0)
#define RDS_TYPE_3B     ( 3 * 2 + 1)
#define RDS_TYPE_4A     ( 4 * 2 + 0)
#define RDS_TYPE_4B     ( 4 * 2 + 1)
#define RDS_TYPE_5A     ( 5 * 2 + 0)
#define RDS_TYPE_5B     ( 5 * 2 + 1)
#define RDS_TYPE_6A     ( 6 * 2 + 0)
#define RDS_TYPE_6B     ( 6 * 2 + 1)
#define RDS_TYPE_7A     ( 7 * 2 + 0)
#define RDS_TYPE_7B     ( 7 * 2 + 1)
#define RDS_TYPE_8A     ( 8 * 2 + 0)
#define RDS_TYPE_8B     ( 8 * 2 + 1)
#define RDS_TYPE_9A     ( 9 * 2 + 0)
#define RDS_TYPE_9B     ( 9 * 2 + 1)
#define RDS_TYPE_10A    (10 * 2 + 0)
#define RDS_TYPE_10B    (10 * 2 + 1)
#define RDS_TYPE_11A    (11 * 2 + 0)
#define RDS_TYPE_11B    (11 * 2 + 1)
#define RDS_TYPE_12A    (12 * 2 + 0)
#define RDS_TYPE_12B    (12 * 2 + 1)
#define RDS_TYPE_13A    (13 * 2 + 0)
#define RDS_TYPE_13B    (13 * 2 + 1)
#define RDS_TYPE_14A    (14 * 2 + 0)
#define RDS_TYPE_14B    (14 * 2 + 1)
#define RDS_TYPE_15A    (15 * 2 + 0)
#define RDS_TYPE_15B    (15 * 2 + 1)

#define CORRECTED_NONE          0
#define CORRECTED_ONE_TO_TWO    1
#define CORRECTED_THREE_TO_FIVE 2
#define UNCORRECTABLE           3


//-----------------------------------------------------------------------------
// Globals
//-----------------------------------------------------------------------------

// RDS Program Identifier
uint16_t  piDisplay;              // Displayed Program Identifier

// RDS Program Type
uint8_t   ptyDisplay;             // Displayed Program Type

#ifdef OPTION__RADIODNS
	//ECC, a necessary component of the RADIODNS address
	uint8_t eccDisplay;
#endif

uint8_t  firstInitDone;
uint8_t  rdsBlerMax[4];

// RDS Radio Text
           uint8_t   rtDisplay[RDS_RADIO_TEXT_BUFFER_SIZE];   // Displayed Radio Text
    static uint8_t   rtFlag;          // Radio Text A/B flag
    static uint8_t   rtFlagValid;     // Radio Text A/B flag is valid
#ifdef OPTION__RDS_DECODE_ADVANCED
    static uint8_t   rtTmp0[RDS_RADIO_TEXT_BUFFER_SIZE];      // Temporary Radio Text (high probability)
    static uint8_t   rtTmp1[RDS_RADIO_TEXT_BUFFER_SIZE];      // Temporary radio text (low probability)
    static uint8_t   rtCnt[RDS_RADIO_TEXT_BUFFER_SIZE];       // Hit count of high probabiltiy radio text
#endif


// RDS Program Service
       uint8_t   psDisplay[RDS_PROGRAM_SERVICE_BUFFER_SIZE];    // Displayed Program Service text
#ifdef OPTION__RDS_DECODE_ADVANCED
    static uint8_t   psTmp0[RDS_PROGRAM_SERVICE_BUFFER_SIZE];       // Temporary PS text (high probability)
    static uint8_t   psTmp1[RDS_PROGRAM_SERVICE_BUFFER_SIZE];       // Temporary PS text (low probability)
    static uint8_t   psCnt[RDS_PROGRAM_SERVICE_BUFFER_SIZE];        // Hit count of high probability PS text
#endif

// RDS Clock Time and Date
       rds_time currentTime;

// RDS Alternate Frequency List
static uint8_t   afCount;
static uint16_t  afList[25];

// RDS flags and counters
static uint16_t  RdsGroupCounters[32];  // Number of each kind of group received

uint8_t rdsIgnoreAB = 1; // By default we do not trust the AB flag but a user can turn this off

//-----------------------------------------------------------------------------
// When tracking alternate frequencies, it's important to clear the list
// after tuning to a new station. (unless you are tuning to check an alternate
// frequency.
//-----------------------------------------------------------------------------
static void init_alt_freq(void)
{
    uint8_t i;
    afCount = 0;
    for (i = 0; i < sizeof(afList)/sizeof(afList[0]); i++)
    {
        afList[i] = 0;
    }
}

//-----------------------------------------------------------------------------
// The basic implementation of the Program Service update displays data
// immediately but does no additional error detection.
//-----------------------------------------------------------------------------
#ifdef OPTION__RDS_DECODE_BASIC
static void update_ps_basic(uint8_t current_ps_addr, uint8_t current_ps_byte)
{
    psDisplay[current_ps_addr] = current_ps_byte;
    CALLBACK_Updated_Data(UPDATED_RDS_PST);
}
#endif
//-----------------------------------------------------------------------------
// This implelentation of the Program Service update attempts to display
// only complete messages for stations who rotate text through the PS field
// in violation of the RBDS standard as well as providing enhanced error
// detection.
//-----------------------------------------------------------------------------
#ifdef OPTION__RDS_DECODE_ADVANCED
#define PS_VALIDATE_LIMIT 3
static void update_ps(uint8_t addr, uint8_t byte)
{
    uint8_t i;
    uint8_t textChange = 0; // indicates if the PS text is in transition
    uint8_t psComplete = 1; // indicates that the PS text is ready to be displayed

    if(psTmp0[addr] == byte)
    {
        // The new byte matches the high probability byte
        if(psCnt[addr] < PS_VALIDATE_LIMIT)
        {
            psCnt[addr]++;
        }
        else
        {
            // we have recieved this byte enough to max out our counter
            // and push it into the low probability array as well
            psCnt[addr] = PS_VALIDATE_LIMIT;
            psTmp1[addr] = byte;
        }
    }
    else if(psTmp1[addr] == byte)
    {
        // The new byte is a match with the low probability byte. Swap
        // them, reset the counter and flag the text as in transition.
        // Note that the counter for this character goes higher than
        // the validation limit because it will get knocked down later
        if(psCnt[addr] >= PS_VALIDATE_LIMIT)
        {
            textChange = 1;
            psCnt[addr] = PS_VALIDATE_LIMIT + 1;
        }
        else
        {
            psCnt[addr] = PS_VALIDATE_LIMIT;
        }
        psTmp1[addr] = psTmp0[addr];
        psTmp0[addr] = byte;
    }
    else if(!psCnt[addr])
    {
        // The new byte is replacing an empty byte in the high
        // proability array
        psTmp0[addr] = byte;
        psCnt[addr] = 1;
    }
    else
    {
        // The new byte doesn't match anything, put it in the
        // low probablity array.
        psTmp1[addr] = byte;
    }

    if(textChange)
    {
        // When the text is changing, decrement the count for all
        // characters to prevent displaying part of a message
        // that is in transition.
        for(i=0;i<sizeof(psCnt);i++)
        {
            if(psCnt[i] > 1)
            {
                psCnt[i]--;
            }
        }
    }

    // The PS text is incomplete if any character in the high
    // probability array has been seen fewer times than the
    // validation limit.
    for (i=0;i<sizeof(psCnt);i++)
    {
        if(psCnt[i] < PS_VALIDATE_LIMIT)
        {
            psComplete = 0;
            break;
        }
    }

    // If the PS text in the high probability array is complete
    // copy it to the display array
    if (psComplete)
    {
        for (i=0;i<sizeof(psDisplay); i++)
        {
            psDisplay[i] = psTmp0[i];
        }
        CALLBACK_Updated_Data(UPDATED_RDS_PST);
    }
}
#endif

//-----------------------------------------------------------------------------
// The basic implementation of the Radio Text update displays data
// immediately but does no additional error detection.
//-----------------------------------------------------------------------------
#ifdef OPTION__RDS_DECODE_BASIC
static void update_rt_simple(uint8_t abFlag, uint8_t count, uint8_t addr, uint8_t* chars, uint8_t BleC, uint8_t BleD)
{
    uint8_t errCount;
    uint8_t blerMax;
    uint8_t i,j;

    // If the A/B flag changes, wipe out the rest of the text
    if ((abFlag != rtFlag) && rtFlagValid)
    {
        for (i=addr;i<sizeof(rtDisplay);i++)
        {
            rtDisplay[i] = 0;
        }
    }
    rtFlag = abFlag;    // Save the A/B flag
    rtFlagValid = 1;    // Now the A/B flag is valid

    for (i=0; i<count; i++)
    {
        // Choose the appropriate block. Count > 2 check is necessary for 2B groups
        if ((i < 2) && (count > 2))
        {
            errCount = BleC;
            blerMax = rdsBlerMax[2];
        }
        else
        {
            errCount = BleD;
            blerMax = rdsBlerMax[3];
        }

        if(errCount <= blerMax)
        {
            // Store the data in our temporary array
            rtDisplay[addr+i] = chars[i];
            if(chars[i] == 0x0d)
            {
                // The end of message character has been received.
                // Wipe out the rest of the text.
                for (j=addr+i+1;j<sizeof(rtDisplay);j++)
                {
                    rtDisplay[j] = 0;
                }
                break;
            }
        }
    }

    // Any null character before this should become a space
    for (i=0;i<addr;i++)
    {
        if(!rtDisplay[i])
        {
            rtDisplay[i] = ' ';
        }
    }
    CALLBACK_Updated_Data(UPDATED_RDS_RT);
}
#endif

//-----------------------------------------------------------------------------
// This implelentation of the Radio Text update attempts to display
// only complete messages even if the A/B flag does not toggle as well
// as provide additional error detection. Note that many radio stations
// do not implement the A/B flag properly. In some cases, it is best left
// ignored.
//-----------------------------------------------------------------------------
#ifdef OPTION__RDS_DECODE_ADVANCED
#define RT_VALIDATE_LIMIT 2
static void display_rt(void)
{
    uint8_t rtComplete = 1;
    uint8_t i;

    // The Radio Text is incomplete if any character in the high
    // probability array has been seen fewer times than the
    // validation limit.
    for (i=0; i<sizeof(rtTmp0);i++)
    {
        if(rtCnt[i] < RT_VALIDATE_LIMIT)
        {
            rtComplete = 0;
            break;
        }
        if(rtTmp0[i] == 0x0d)
        {
            // The array is shorter than the maximum allowed
            break;
        }
    }

    // If the Radio Text in the high probability array is complete
    // copy it to the display array
    if (rtComplete)
    {
        for (i=0;i<sizeof(rtDisplay); i++)
        {
            rtDisplay[i] = rtTmp0[i];
            if(rtTmp0[i] == 0x0d)
            {
                break;
            }
        }
        // Wipe out everything after the end-of-message marker
        for (i++;i<sizeof(rtDisplay);i++)
        {
            rtDisplay[i] = 0;
            rtCnt[i]     = 0;
            rtTmp0[i]    = 0;
            rtTmp1[i]    = 0;
        }

        CALLBACK_Updated_Data(UPDATED_RDS_RT);
    }
}
#endif

//-----------------------------------------------------------------------------
// This implementation of the Radio Text update attempts to further error
// correct the data by making sure that the data has been identical for
// multiple receptions of each byte.
//-----------------------------------------------------------------------------
#ifdef OPTION__RDS_DECODE_ADVANCED
static void update_rt_advance(uint8_t abFlag, uint8_t count, uint8_t addr, uint8_t* byte, uint8_t BleC, uint8_t BleD)
{
    uint8_t i;
    uint8_t textChange = 0; // indicates if the Radio Text is changing

    if (abFlag != rtFlag && rtFlagValid && !rdsIgnoreAB)
    {
        // If the A/B message flag changes, try to force a display
        // by increasing the validation count of each byte
        // and stuffing a space in place of every NUL char
        for (i=0;i<sizeof(rtCnt);i++)
        {
            if (!rtTmp0[i])
            {
                rtTmp0[i] = ' ';
                rtCnt[i]++;
            }
        }
        for (i=0;i<sizeof(rtCnt);i++)
        {
            rtCnt[i]++;
        }
        display_rt();

        // Wipe out the cached text
        for (i=0;i<sizeof(rtCnt);i++)
        {
            rtCnt[i]  = 0;
            rtTmp0[i] = 0;
            rtTmp1[i] = 0;
        }
    }

    rtFlag = abFlag;    // Save the A/B flag
    rtFlagValid = 1;    // Our copy of the A/B flag is now valid

    for(i=0;i<count;i++)
    {
        uint8_t errCount;
        uint8_t blerMax;
        // Choose the appropriate block. Count > 2 check is necessary for 2B groups
        if ((i < 2) && (count > 2))
        {
            errCount = BleC;
            blerMax = rdsBlerMax[2];
        }
        else
        {
            errCount = BleD;
            blerMax = rdsBlerMax[3];
        }
        if (errCount <= blerMax)
        {
            if(!byte[i])
            {
                byte[i] = ' '; // translate nulls to spaces
            }

            // The new byte matches the high probability byte
            if(rtTmp0[addr+i] == byte[i])
            {
                if(rtCnt[addr+i] < RT_VALIDATE_LIMIT)
                {
                    rtCnt[addr+i]++;
                }
                else
                {
                    // we have recieved this byte enough to max out our counter
                    // and push it into the low probability array as well
                    rtCnt[addr+i] = RT_VALIDATE_LIMIT;
                    rtTmp1[addr+i] = byte[i];
                }
            }
            else if(rtTmp1[addr+i] == byte[i])
            {
                // The new byte is a match with the low probability byte. Swap
                // them, reset the counter and flag the text as in transition.
                // Note that the counter for this character goes higher than
                // the validation limit because it will get knocked down later
                if(rtCnt[addr+i] >= RT_VALIDATE_LIMIT)
                {
                    textChange = 1;
                    rtCnt[addr+i] = RT_VALIDATE_LIMIT + 1;
                }
                else
                {
                    rtCnt[addr+i] = RT_VALIDATE_LIMIT;
                }
                rtTmp1[addr+i] = rtTmp0[addr+i];
                rtTmp0[addr+i] = byte[i];
            }
            else if(!rtCnt[addr+i])
            {
                // The new byte is replacing an empty byte in the high
                // proability array
                rtTmp0[addr+i] = byte[i];
                rtCnt[addr+i] = 1;
            }
            else
            {
                // The new byte doesn't match anything, put it in the
                // low probablity array.
                rtTmp1[addr+i] = byte[i];
            }
        }
    }

    if(textChange)
    {
        // When the text is changing, decrement the count for all
        // characters to prevent displaying part of a message
        // that is in transition.
        for(i=0;i<sizeof(rtCnt);i++)
        {
            if(rtCnt[i] > 1)
            {
                rtCnt[i]--;
            }
        }
    }

    // Display the Radio Text
    display_rt();
}
#endif

//-----------------------------------------------------------------------------
// Decode the RDS AF data into an array of AF frequencies.
//-----------------------------------------------------------------------------
#define AF_COUNT_MIN 225
#define AF_COUNT_MAX (AF_COUNT_MIN + 25)
#define AF_FREQ_MIN 0
#define AF_FREQ_MAX 204
#define AF_FREQ_TO_U16F(freq) (8750+((freq-AF_FREQ_MIN)*10))
static void update_alt_freq(uint16_t current_alt_freq)
{
    // Currently this only works well for AF method A, though AF method B
    // data will still be captured.
    uint8_t dat;
    uint8_t i;
    uint16_t freq;

    // the top 8 bits is either the AF Count or AF Data
    dat = (uint8_t)(current_alt_freq >> 8);
    // look for the AF Count indicator
    if ((dat >= AF_COUNT_MIN) && (dat <= AF_COUNT_MAX) && ((dat - AF_COUNT_MIN) != afCount))
    {
        init_alt_freq();  // clear the alternalte frequency list
        afCount = (dat - AF_COUNT_MIN); // set the count
        dat = (uint8_t)current_alt_freq;
        if (dat >= AF_FREQ_MIN && dat <= AF_FREQ_MAX)
        {
            freq = AF_FREQ_TO_U16F(dat);
            afList[0]= freq;
        }
    }
    // look for the AF Data
    else if (afCount && dat >= AF_FREQ_MIN && dat <= AF_FREQ_MAX)
    {
        uint8_t foundSlot = 0;
        static  uint8_t clobber=1;  // index to clobber if no empty slot is found
        freq = AF_FREQ_TO_U16F(dat);
        for (i=1; i < afCount; i+=2)
        {
            // look for either an empty slot or a match
            if ((!afList[i]) || (afList[i] == freq))
            {
                afList[i] = freq;
                dat = (uint8_t)current_alt_freq;
                freq = AF_FREQ_TO_U16F(dat);
                afList[i+1] = freq;
                foundSlot = 1;
                break;
            }
        }
        // If no empty slot or match was found, overwrite a 'random' slot.
        if (!foundSlot)
        {
            clobber += (clobber&1) + 1; // this ensures that an odd slot is always chosen.
            clobber %= (afCount);       // keep from overshooting the array
            afList[clobber] = freq;
            dat = (uint8_t)current_alt_freq;
            freq = AF_FREQ_TO_U16F(dat);
            afList[clobber+1] = freq;
        }
    }

    //CALLBACK_Updated_Data(UPDATED_RDS_ALT_FREQ);
}

//-----------------------------------------------------------------------------
// Decode the RDS time data into its individual parts.
//-----------------------------------------------------------------------------
static void update_clock(fm_rds_status__data rdsData)
{

    if (rdsData.BLEB <= rdsBlerMax[1] &&
        rdsData.BLEC <= rdsBlerMax[2] &&
        rdsData.BLED <= rdsBlerMax[3] &&
        (rdsData.BLEB + rdsData.BLEC + rdsData.BLED) <= rdsBlerMax[1]) {

            currentTime.ctDayHigh = (rdsData.BLOCKB >> 1) & 1;
            currentTime.ctDayLow  = (rdsData.BLOCKB << 15) | (rdsData.BLOCKC >> 1);
            currentTime.ctHour    = ((rdsData.BLOCKC & 1) << 4) | (rdsData.BLOCKD >> 12);
            currentTime.ctMinute  = (rdsData.BLOCKD >> 6) & 0x3F;
            currentTime.ctOffset  = rdsData.BLOCKD & 0x1F;

            if (rdsData.BLOCKD & (1<<5))
            {
                currentTime.ctOffset = -currentTime.ctOffset;
            }
            CALLBACK_Updated_Data(UPDATED_RDS_TIME);
    }
}


//-----------------------------------------------------------------------------
// After tuning to a new station, the RDS tracking variables need to be
// initialized.
//-----------------------------------------------------------------------------
void initRDS(void)
{
    // Set the maximum allowable errors in a block considered acceptable
    // It's critical that block B be correct since it determines what's
    // contained in the latter blocks. For this reason, a stricter tolerance
    // is placed on block B
    if (!firstInitDone)
    {
        rdsBlerMax[0] = CORRECTED_THREE_TO_FIVE; // Block A
        rdsBlerMax[1] = CORRECTED_ONE_TO_TWO;    // Block B
        rdsBlerMax[2] = CORRECTED_THREE_TO_FIVE; // Block C
        rdsBlerMax[3] = CORRECTED_THREE_TO_FIVE; // Block D
        firstInitDone = 1;
    }

    // Clear Radio Text
    rtFlag          = 0;
    rtFlagValid     = 0;

    ClearMemory(rtDisplay,sizeof(rtDisplay));

	#ifdef OPTION__RDS_DECODE_ADVANCED
        ClearMemory(rtTmp0,sizeof(rtTmp0));
        ClearMemory(rtTmp1,sizeof(rtTmp1));
        ClearMemory(rtCnt,sizeof(rtCnt));
	#endif

    // Clear Program Service
    ClearMemory(psDisplay,sizeof(psDisplay));

    #ifdef OPTION__RDS_DECODE_ADVANCED
        ClearMemory(psTmp0,sizeof(psTmp0));
        ClearMemory(psTmp1,sizeof(psTmp1));
        ClearMemory(psCnt,sizeof(psCnt));
    #endif

    // Reset Debug Group counters
    ClearMemory((uint8_t*)RdsGroupCounters,sizeof(RdsGroupCounters));

    // Reset alternate frequency tables
    init_alt_freq();

    ptyDisplay     = 0;
    piDisplay      = 0;

	#ifdef OPTION__RADIODNS
		eccDisplay = 0;
	#endif

    currentTime.ctDayHigh      = 0;
    currentTime.ctDayLow       = 0;
    currentTime.ctHour         = 0;
    currentTime.ctMinute       = 0;
    currentTime.ctOffset       = 0;
}

#ifndef OPTION__REMOVE_SDK_FUNCTIONS_NOT_USED_BY_MMI
    void ignoreAB(uint8_t ignore)
    {
        rdsIgnoreAB = ignore;
    }
#endif //OPTION__REMOVE_SDK_FUNCTIONS_NOT_USED_BY_MMI

//-----------------------------------------------------------------------------
// After an RDS interrupt, read back the RDS registers and process the data.
//-----------------------------------------------------------------------------
void updateRDS(fm_rds_status__data rdsData)
{
	uint8_t rtblocks[4];
    uint8_t group_type;      // bits 4:1 = type,  bit 0 = version
    uint8_t addr;
    uint8_t abflag;

	// Update pi code.
    if (rdsData.PIVALID)
	{
        piDisplay = rdsData.PI;
        CALLBACK_Updated_Data(UPDATED_RDS_PI);
	}

    if (rdsData.BLEB <= rdsBlerMax[1])
	{
        group_type = rdsData.BLOCKB >> 11;  // upper five bits are the group type and version
	    // Check for group counter overflow and divide all by 2
	    if((RdsGroupCounters[group_type] + 1) == 0)
	    {
	        uint8_t i;
	        for (i=0;i<32;i++)
	        {
	            RdsGroupCounters[i] >>= 1;
	        }
	    }
	    RdsGroupCounters[group_type] += 1;
	}
	else
	{
	    // Drop the data if more than two errors were corrected in block B
	    return;
	}


	// update pty code.
    if(rdsData.TPPTYVALID)
    {
        ptyDisplay = rdsData.PTY;
        CALLBACK_Updated_Data(UPDATED_RDS_PTY);
    }

	switch (group_type) {
	    case RDS_TYPE_0A:
            if (rdsData.BLEC <= rdsBlerMax[2])
	        {
                update_alt_freq(rdsData.BLOCKC);
	        }
	        // fallthrough
	    case RDS_TYPE_0B:
            addr = (rdsData.BLOCKB & 0x3) * 2;
            if (rdsData.BLED <= rdsBlerMax[3])
	        {
	            #ifdef OPTION__RDS_DECODE_BASIC
                    update_ps_basic(addr+0, rdsData.BLOCKD >> 8  );
                    update_ps_basic(addr+1, rdsData.BLOCKD & 0xff);
                #endif
	            #ifdef OPTION__RDS_DECODE_ADVANCED
                    update_ps(addr+0, rdsData.BLOCKD >> 8  );
                    update_ps(addr+1, rdsData.BLOCKD & 0xff);
                #endif
            }
            break;
        
        #ifdef OPTION__RADIODNS
            case RDS_TYPE_1A:
                {
                if (rdsData.BLEC <= rdsBlerMax[2])
                {
                    eccDisplay = (uint8_t)(rdsData.BLOCKC & 0xFF);
                }
            }
            break;
        #endif

        case RDS_TYPE_2A:
	    {
            rtblocks[0] = (uint8_t)(rdsData.BLOCKC >> 8);
            rtblocks[1] = (uint8_t)(rdsData.BLOCKC & 0xFF);
            rtblocks[2] = (uint8_t)(rdsData.BLOCKD >> 8);
            rtblocks[3] = (uint8_t)(rdsData.BLOCKD & 0xFF);
            addr = (rdsData.BLOCKB & 0xf) * 4;
            abflag = (rdsData.BLOCKB & 0x0010) >> 4;
            #ifdef OPTION__RDS_DECODE_BASIC
	            update_rt_simple(abflag, 4, addr, rtblocks, rdsData.BLEC, rdsData.BLED);
            #endif
            #ifdef OPTION__RDS_DECODE_ADVANCED
	            update_rt_advance(abflag, 4, addr, rtblocks, rdsData.BLEC, rdsData.BLED);
            #endif
	        break;
	    }

	    case RDS_TYPE_2B:
	    {
            rtblocks[0] = (uint8_t)(rdsData.BLOCKD >> 8);
            rtblocks[1] = (uint8_t)(rdsData.BLOCKD & 0xFF);
			rtblocks[2] = 0;
			rtblocks[3] = 0;
            addr = (rdsData.BLOCKB & 0xf) * 2;
            abflag = (rdsData.BLOCKB & 0x0010) >> 4;
	        // The last 32 bytes are unused in this format
            #ifdef OPTION__RDS_DECODE_BASIC
	            rtDisplay[32]  = 0x0d;
                update_rt_simple (abflag, 2, addr, rtblocks, rdsData.BLEC, rdsData.BLED);
            #endif
            #ifdef OPTION__RDS_DECODE_ADVANCED
	            rtTmp0[32]    = 0x0d;
	            rtTmp1[32]    = 0x0d;
	            rtCnt[32]     = RT_VALIDATE_LIMIT;
                update_rt_advance(abflag, 2, addr, rtblocks, rdsData.BLEC, rdsData.BLED);
            #endif
	        break;
	    }
	    case RDS_TYPE_4A:
	        // Clock Time and Date
            update_clock(rdsData);
	        break;
	    default:
	        break;
    }
}
#endif
#endif //OPTION__INCLUDE_MODE__FM
