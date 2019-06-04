/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   SDK HD radio PSD decoder
   FILE: FMHD_PSD_Handler.c
   Supported IC : Si468x
   Date: June 20 2014
  (C) Copyright 2014, Silicon Laboratories, Inc. All rights reserved.
****************************************************************************************/

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include "common_types.h"
#include "platform_options.h"
#include "FMHD_PSD_Handler.h"
#include "SDK_Callbacks.h"
//#include "si46xx_firmware_api.h"

#ifdef OPTION__INCLUDE_MODE__FMHD
#ifdef OPTION__DECODE_PSD

//-----------------------------------------------------------------------------
// local defines
//-----------------------------------------------------------------------------
#ifdef OPTION__PSD_FORMAT_ID3
MEMORY_SPACE__CODE const uint8_t TAG_STRING__ID3_START_LOC[4] = "ID3";
MEMORY_SPACE__CODE const uint8_t TAG_STRING__TITLE[5] = "TIT2";
MEMORY_SPACE__CODE const uint8_t TAG_STRING__ARTIST[5] = "TPE1";
MEMORY_SPACE__CODE const uint8_t TAG_STRING__ALBUM[5] = "TALB";
MEMORY_SPACE__CODE const uint8_t TAG_STRING__GENRE[5] = "TCON";
MEMORY_SPACE__CODE const uint8_t TAG_STRING__COMMENT[5] = "COMM";
MEMORY_SPACE__CODE const uint8_t TAG_STRING__COMMERCIAL[5] = "COMR";
MEMORY_SPACE__CODE const uint8_t TAG_STRING__UFID[5] = "UFID";
#endif

//-----------------------------------------------------------------------------
// Globals
//-----------------------------------------------------------------------------

// PSD Data
fmhd_psd_generic_string titleDisplay;   // Displayed PSD Title for current program
fmhd_psd_generic_string artistDisplay;  // Displayed PSD Artist for current program
fmhd_psd_generic_string albumDisplay;   // Displayed PSD Album for current program
fmhd_psd_generic_string genreDisplay;   // Displayed PSD Genre for current program

//TODO: add support for COMMENT if desired
//TODO: add support for UFID if desired
//TODO: add support for COMMERCIAL if desired
//NOTE: this will need to be another compile option as we don't want to force all C-SDK devices to require this memory


void _update_generic_psd(fmhd_psd_generic_string* dest, uint8_t* src, uint8_t enc, uint8_t len)
{
    dest->ENCODING = (FMHD_SIS_PSD_ENCODING_TYPE)enc;
    dest->LENGTH = len;
    if(len > FMHD_PSD_TEXT_TYPE_BUFFER_SIZE)
    {
        dest->LENGTH = FMHD_PSD_TEXT_TYPE_BUFFER_SIZE;
    }
    else
    {
        dest->LENGTH = len;
    }
    CpyMemory(dest->DATA, src, dest->LENGTH);
}

//-----------------------------------------------------------------------------
// After changing services, the PSD tracking variables need to be
// initialized.
//-----------------------------------------------------------------------------
void initPSD(void)
{
    titleDisplay.FIELD = TITLE;
    titleDisplay.ENCODING = ENCODING_RESERVED;
    titleDisplay.LENGTH = 0;
    ClearMemory(titleDisplay.DATA,sizeof(titleDisplay.DATA));

    artistDisplay.FIELD = ARTIST;
    artistDisplay.ENCODING = ENCODING_RESERVED;
    artistDisplay.LENGTH = 0;
    ClearMemory(artistDisplay.DATA,sizeof(artistDisplay.DATA));

    albumDisplay.FIELD = ALBUM;
    albumDisplay.ENCODING = ENCODING_RESERVED;
    albumDisplay.LENGTH = 0;
    ClearMemory(albumDisplay.DATA,sizeof(albumDisplay.DATA));

    genreDisplay.FIELD = GENRE;
    genreDisplay.ENCODING = ENCODING_RESERVED;
    genreDisplay.LENGTH = 0;
    ClearMemory(genreDisplay.DATA,sizeof(genreDisplay.DATA));
}


//-----------------------------------------------------------------------------
// After a PSD interrupt, process the data.
//-----------------------------------------------------------------------------
#ifdef OPTION__PSD_FORMAT_ID3
#define ID3_HEADER_FLAGS__OFFSET 5
#define ID3_HEADER_FLAGS__UNSYNCH 0x80
#define ID3_HEADER_FLAGS__EXTENDED 0x40
#define ID3_HEADER_FLAGS__EXPERIMENTAL 0x20
#define ID3_HEADER_LENGTH__OFFSET 6

#define ID3_HEADER_LENGTH 10

#define ID3_EXTENDED_HEADER_SIZE__OFFSET 0
#define ID3_EXTENDED_HEADER_FLAGS__OFFSET 4
#define ID3_EXTENDED_HEADER_PAD_SIZE__OFFSET 6

#define ID3_FRAME_LENGTH__OFFSET 4
#define ID3_FRAME_FLAGS__OFFSET 8
#define ID3_FRAME_TEXTTYPE_ENCODING__OFFSET 10
#define ID3_FRAME_TEXTTYPE_DATA__OFFSET 11

#define ID3_FRAME_HEADER_LENGTH 10

#define ID3_FRAME_UFIDTYPE_OWNERID__OFFSET 10

FMHD_PSD_FIELD_DATA_TYPE _determine_ID3_frame_type(uint8_t* buffer)
{
    if(CompareMemory(buffer,TAG_STRING__TITLE,4) == 0)
    {
        return TITLE;
    }
    else if(CompareMemory(buffer,TAG_STRING__ARTIST,4) == 0)
    {
        return ARTIST;
    }
    else if(CompareMemory(buffer,TAG_STRING__ALBUM,4) == 0)
    {
        return ALBUM;
    }
    else if(CompareMemory(buffer,TAG_STRING__GENRE,4) == 0)
    {
        return GENRE;
    }
    else if(CompareMemory(buffer,TAG_STRING__COMMENT,4) == 0)
    {
        return COMMENT;
    }
    else if(CompareMemory(buffer,TAG_STRING__UFID,4) == 0)
    {
        return UFID;
    }
    else if(CompareMemory(buffer,TAG_STRING__COMMERCIAL,4) == 0)
    {
        return COMMERCIAL;
    }
    else
    {
        return PSD_UNKNOWN;
    }
}

void updatePSD(get_digital_service_data__data psdData)
{
    uint16_t psdAddr = 0; // we need a 16 bit addr because psd max size is 1k
    uint32_t psdFrameLength;
    uint32_t psdExtendedHeaderSize = 0;
    uint32_t psdSizeOfPadding = 0;
    

    //Need to find the start of the ID3 tags in the stream - ignore the main header
    if(CompareMemory(&psdData.PAYLOAD[0],TAG_STRING__ID3_START_LOC,3) == 0)
    {
        //Found ID3 at position 0 (new iBiquity library is in use)
        psdAddr = 0; // The starting address in the buffer for ID3 tags
    }
    else
    {
        //Found ID3 at position 10 (old iBiquity library is in use)
        psdAddr = 10; // The starting address in the buffer for ID3 tags
    }

    psdAddr += ID3_HEADER_LENGTH;

    //Check if the extended header is present and needs to be ignored
    if((psdData.PAYLOAD[psdAddr + ID3_HEADER_FLAGS__OFFSET] & ID3_HEADER_FLAGS__EXTENDED))
    {
        //The extended header is present we need to read it to move to the start of the first FIELD
        psdExtendedHeaderSize = _recover_32bit_from_big_endian_buffer(&psdData.PAYLOAD[psdAddr]);
        psdSizeOfPadding = _recover_32bit_from_big_endian_buffer(&psdData.PAYLOAD[psdAddr + ID3_EXTENDED_HEADER_PAD_SIZE__OFFSET]);
    }
    psdAddr += psdExtendedHeaderSize;

    while(psdAddr < (psdData.BYTE_COUNT - psdSizeOfPadding))
    {
        psdFrameLength = _recover_32bit_from_big_endian_buffer(&psdData.PAYLOAD[psdAddr + ID3_FRAME_LENGTH__OFFSET]);

        switch(_determine_ID3_frame_type(&psdData.PAYLOAD[psdAddr]))
        {
            case TITLE:
                _update_generic_psd(&titleDisplay,&psdData.PAYLOAD[psdAddr + ID3_FRAME_TEXTTYPE_DATA__OFFSET], psdData.PAYLOAD[psdAddr + ID3_FRAME_TEXTTYPE_ENCODING__OFFSET], (uint8_t)(psdFrameLength - 1));
                CALLBACK_Updated_Data(UPDATED_PSD_TITLE);
                break;
            case ARTIST:
                _update_generic_psd(&artistDisplay,&psdData.PAYLOAD[psdAddr + ID3_FRAME_TEXTTYPE_DATA__OFFSET], psdData.PAYLOAD[psdAddr + ID3_FRAME_TEXTTYPE_ENCODING__OFFSET], (uint8_t)(psdFrameLength - 1));
                CALLBACK_Updated_Data(UPDATED_PSD_ARTIST);
                break;
            case ALBUM:
                _update_generic_psd(&albumDisplay,&psdData.PAYLOAD[psdAddr + ID3_FRAME_TEXTTYPE_DATA__OFFSET], psdData.PAYLOAD[psdAddr + ID3_FRAME_TEXTTYPE_ENCODING__OFFSET], (uint8_t)(psdFrameLength - 1));
                CALLBACK_Updated_Data(UPDATED_PSD_ALBUM);
                break;
            case GENRE:
                _update_generic_psd(&genreDisplay,&psdData.PAYLOAD[psdAddr + ID3_FRAME_TEXTTYPE_DATA__OFFSET], psdData.PAYLOAD[psdAddr + ID3_FRAME_TEXTTYPE_ENCODING__OFFSET], (uint8_t)(psdFrameLength - 1));
                CALLBACK_Updated_Data(UPDATED_PSD_GENRE);
                break;
            case COMMENT:
            case UFID:
            case COMMERCIAL:
                //TODO: add support for COMMENT, UFID, COMMERICAL - if desired
                //Do not return, just ignore the text and move on
                break;
            default:
                //Unknown text found in the tag - discarding remainder
                return;
                break;
        }

        psdAddr += (ID3_FRAME_HEADER_LENGTH + psdFrameLength); //move the packet address to next packet
    }
}
#else

void updatePSD(FMHD_PSD_FIELD_DATA_TYPE field, fmhd_get_psd_decode__data psdData)
{
    switch(field)
    {
        case TITLE:
            ClearMemory(titleDisplay.DATA,sizeof(titleDisplay.DATA));
            _update_generic_psd(&titleDisplay,psdData.PAYLOAD,psdData.DATATYPE,psdData.LENGTH);
            CALLBACK_Updated_Data(UPDATED_PSD_TITLE);
            break;
        case ARTIST:
            ClearMemory(artistDisplay.DATA,sizeof(artistDisplay.DATA));
            _update_generic_psd(&artistDisplay,psdData.PAYLOAD,psdData.DATATYPE,psdData.LENGTH);
            CALLBACK_Updated_Data(UPDATED_PSD_ARTIST);
            break;
        case ALBUM:
            ClearMemory(albumDisplay.DATA,sizeof(albumDisplay.DATA));
            _update_generic_psd(&albumDisplay,psdData.PAYLOAD,psdData.DATATYPE,psdData.LENGTH);
            CALLBACK_Updated_Data(UPDATED_PSD_ALBUM);
            break;
        case GENRE:
            ClearMemory(genreDisplay.DATA,sizeof(genreDisplay.DATA));
            _update_generic_psd(&genreDisplay,psdData.PAYLOAD,psdData.DATATYPE,psdData.LENGTH);
            CALLBACK_Updated_Data(UPDATED_PSD_GENRE);
            break;
        default:
            break;
    }
}
#endif

#endif //OPTION__DECODE_PSD
#endif //OPTION__INCLUDE_MODE__FMHD