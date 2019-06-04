/***************************************************************************************
                  Silicon Laboratories Broadcast Digital Radio SDK

   EVALUATION AND USE OF THIS SOFTWARE IS SUBJECT TO THE TERMS AND CONDITIONS OF
     THE SOFTWARE LICENSE AGREEMENT IN THE DOCUMENTATION FILE CORRESPONDING
     TO THIS SOURCE FILE.
   IF YOU DO NOT AGREE TO THE LIMITED LICENSE AND CONDITIONS OF SUCH AGREEMENT,
     PLEASE RETURN ALL SOURCE FILES TO SILICON LABORATORIES.

   delay driver for C8051F380 based module
   FILE: delay.c
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


#include "delay.h"

void Delay(void)
{
        volatile int x;
        for(x = 0;x < 500;x)
                x++;	
}
//-----------------------------------------------------------------------------
// Delay routine based on hardware timer
//
// Inputs:
//              Delay in microseconds
//
//-----------------------------------------------------------------------------
void wait_us(u16 us)
{
        u16 j;

        j = 65535u -  24*us;
        TL0 = j;                // Load Timer 0 low byte
        TH0 = j >> 8;           // Load Timer 0 high byte
        TR0 = 1;                // Enable Timer 0
        TF0 = 0;                // Clear Timer 0 Overflow flag
        while(TF0 != 1);        // Wait for Timer 0 to overflow
        TR0 = 0;                // Disable Timer 0
        TF0 = 0;                // Clear Timer 0 Overflow Flag
		/*
		j = 24*us;
		while(j--);
		*/
}

//-----------------------------------------------------------------------------
// delay routine for long delays
//
// Inputs:
//              Delay in milliseconds
//
//-----------------------------------------------------------------------------
void wait_ms(u16 ms)
{
        int i;

        for (i=0; i<ms; i++)
        {
                wait_us(1000);
        }
}

//-----------------------------------------------------------------------------
// delay routine for small delays.  Assume each for loop takes
// at least 64nS, and divide parameter by just doing a shift.
// This routine primarily exists for documentation purposes.
// On this 8051, all waits will be much longer than they need to be.
//
// Inputs:
//              Delay in nanoseconds
//
//-----------------------------------------------------------------------------
//void wait_ns(u16 ns)
//{
//        u8 i;
//
//        for(i = 1; i <= ns/32; i++)
//        {
//            // do nothing
//        }
//}