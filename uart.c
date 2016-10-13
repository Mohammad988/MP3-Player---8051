/*------------------------------------------------------------------
   uart.c (v1.00)                                                   
   Mohammadhossein Behgam
  ------------------------------------------------------------------*/
// Include Files
#include "uart.h"

/*------------------------------------------------------------------*/
// UART Definitions
//PCON
#define SMOD0  0
#define SMOD1  1

//BDRCON
#define BRR_stop  0
#define BRR_start 1
#define TBCK 1
#define RBCK 0
#define SPD  1

/*------------------------------------------------------------------*/
void UART_Init(uint16_t baud_rate)
{
   // PCON Init
   PCON &= (~((~SMOD0)<<6));
   PCON &= (~((~SMOD1)<<7));
   PCON |= (SMOD1<<7);

   // SCON Init
   SM0 = 0;
   SM1 = 1;
   SM2 = 0;
   REN = 1;

   // BDRCON Init
   BDRCON = 0x0E;

   // BRL Init
   BRL = (uint8_t) (256-(((1+(5*SPD))*(1+(1*SMOD1))*OSC_FREQ)/(32*OSC_PER_INST*(uint32_t)baud_rate)));

   // Start the internal Baudrate Generator
   BDRCON |= 0x10;

   // Set the Transmit Interrupt Flag
   TI = 1;
}

/*------------------------------------------------------------------*/
uint8_t UART_Transmit(uint8_t send_value)
{
   // wait until the TI bit is set
   while(TI != 1);

   SBUF = send_value;
   TI = 0;

   return send_value;
}

/*------------------------------------------------------------------*/
uint8_t UART_Receive(void)
{
   uint8_t received_value;
   // wait until the RI bit is set
   while(RI != 1);

   received_value = SBUF;
   RI = 0;

   return received_value;
}

/*------------------------------------------------------------------
  ----------------------- END OF FILE ------------------------------
  ------------------------------------------------------------------*/