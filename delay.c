/*------------------------------------------------------------------*-
   DELAY.C (v1.00)
   Mohammadhossein Behgam
  ------------------------------------------------------------------*/
#include "delay.h"

#define maxCount 0xFFFF

/*------------------------------------------------------------------*-
  DelaySW()
  Delay duration varies with parameter.  
  Parameter is, *ROUGHLY*, the delay, in milliseconds,
  You need to adjust the timing for your application!
-*------------------------------------------------------------------*/
void DelaySW(const unsigned int DELAY)
{
   uint32_t timeOut = DELAY*255;
   while(timeOut--);
}

/*------------------------------------------------------------------*-
  DelayHW()
-*------------------------------------------------------------------*/
void DelayHW(uint16_t timeMSec)
{
	uint16_t preLoad  = (maxCount + 1 - (uint16_t)(timeMSec*OSC_FREQ/(OSC_PER_INST*1020UL)));
	uint8_t  preLoadH = (uint8_t)(preLoad >> 8);
	uint8_t  preLoadL = (uint8_t)(preLoad & 0xFF);	

	// Start Timer0
	TMOD &= 0xF0; 
	TMOD |= 0x01;
	ET0 = 0;
	TR0 = 0;
	TH0 = preLoadH;
	TL0 = preLoadL;
	TR0 = 1;

	// Wait
	//if(TR0 == 1)
	   while(TF0 == 0);

}

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/