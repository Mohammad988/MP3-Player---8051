/*------------------------------------------------------------------*-
   LCD.C (v1.00)
   Mohammadhossein Behgam
  ------------------------------------------------------------------*/
// Include Files
#include <stdio.h>
#include "lcd.h"
#include "delay.h"

/*------------------------------------------------------------------*/
// LCD Definitions
#define COMMAND   0
#define DISPLAY   1
#define FuncSet   0x3C
#define DispOnOff 0x0F
#define DispClr   0x01
#define EntryMode 0x06
#define setAddr	0x80
#define line1	   0x00
#define line2	   0x40

/*------------------------------------------------------------------*/
void LcdInit(void)
{
   // Delay for *approx* 30 ms
   DelaySW(30);
   LcdWrite(COMMAND,FuncSet);

   // Delay for *approx* 5 ms
   DelaySW(5);
   LcdWrite(COMMAND,FuncSet);

   // Delay for *approx* 1 ms
   DelaySW(1);
   LcdWrite(COMMAND,FuncSet);

   // Delay for *approx* 1 ms
   DelaySW(1);
   LcdWrite(COMMAND,FuncSet);

   // Delay for *approx* 1 ms
   DelaySW(1);
   LcdWrite(COMMAND,DispOnOff);

   // Delay for *approx* 1 ms
   DelaySW(1);
   LcdWrite(COMMAND,DispClr);

   // Delay for *approx* 2 ms
   DelaySW(2);
   LcdWrite(COMMAND,EntryMode);

   // Delay for *approx* 1 ms
   DelaySW(1);
}

/*------------------------------------------------------------------*/
void LcdWrite(bit RSval, uint8_t Data)
{
	RS = RSval; 
	E = 1;
	LcdPort = Data;
	E = 0;
	LcdPort = 0xFF; // Passive pull up
}

/*------------------------------------------------------------------*/
void LcdPrint(uint8_t *str)
{
   while(*str != NULL)
   {
      LcdWrite(DISPLAY,*str);
      str++;
      DelaySW(1);
   }
}

/*------------------------------------------------------------------
  ----------------------- END OF FILE ------------------------------
  ------------------------------------------------------------------*/