/*------------------------------------------------------------------
   EXPERIMENT 2
   MAIN.C (v1.00)
   Mohammadhossein Behgam                                           
  ------------------------------------------------------------------*/
// Include Files
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "interrupt.h"
#include "uart.h"
#include "led.h"
#include "print_bytes.h"
#include "delay.h"
#include "lcd.h"
#include "spi.h"
#include "sd_card.h"

/*------------------------------------------------------------------*/
// Function prototypes
void PeripheralInit(void);
void BoardInit(void);

/*------------------------------------------------------------------*/
// Global Variables

/*------------------------------------------------------------------*/
void main(void)
{
   // Local Variable Init

   // Micro-Controller  peripheral Initilazation
   PeripheralInit();

   // Board Initializtion
   BoardInit();    

   // Idle State   
   while(1)
   {
      // Change the LED state (OFF to ON, or vice versa)
      LED_FLASH_Change_State();
      // Delay for *approx* 500 ms
      DelaySW(100);
   };   
}

/*------------------------------------------------------------------*/
void PeripheralInit(void)
{
   DisableInterrupts();
   UART_Init(57600);
   SPI_Master_Init(400000);
}

/*------------------------------------------------------------------*/
 void BoardInit(void)
{
   LED_FLASH_Init();
   LcdInit();
}

/*------------------------------------------------------------------
  ----------------------- END OF FILE ------------------------------
  ------------------------------------------------------------------*/