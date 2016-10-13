/*------------------------------------------------------------------
   MAIN.C (v1.00)
   Mohammadhossein Behgam                                           
  ------------------------------------------------------------------*/
// Include Files
#include <stdio.h>
#include "main.h"
#include "interrupt.h"
#include "uart.h"
#include "led.h"
#include "memory_test.h"
#include "print_bytes.h"
#include "delay.h"
#include "lcd.h"

/*------------------------------------------------------------------*/
// Function prototypes
void PeripheralInit(void);
void BoardInit(void);

/*------------------------------------------------------------------*/
// Global Variables
static uint8_t code LcdTestStr[] = "Test LCD String!";

/*------------------------------------------------------------------*/
void main(void)
{
   // Variable Init
   uint8_t value;
   uint8_t *CodeMemPtr;
   uint8_t *XdataMemPtr;

   // Micro-Controller  peripheral Initilazation
   PeripheralInit();

   // Board Initializtion
   BoardInit();

   // Memory Test
   CodeMemPtr  = code_memory_init();
   XdataMemPtr = xdata_memory_init();

   print_memory(CodeMemPtr , 50);
   print_memory(XdataMemPtr, 50);

   // LCD Test
   LcdPrint(LcdTestStr);
   
   
   while(1)
   {
      // Change the LED state (OFF to ON, or vice versa)
      LED_FLASH_Change_State();

      // Delay for *approx* 500 ms
      DelaySW(500);

      //UART Test
      //putchar('U');
      //value = UART_Receive();
      //UART_Transmit(value);
   };   
}

/*------------------------------------------------------------------*/
void PeripheralInit(void)
{
   DisableInterrupts();
   UART_Init(57600);
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