/*------------------------------------------------------------------*-
   LED.C (v1.00)
   Mohammadhossein Behgam
  ------------------------------------------------------------------*/
#include "led.h"

// Stores the LED state
bit LED_state_G;

/*------------------------------------------------------------------*-
  LED_FLASH_Init()
  Prepare for LED_Change_State() function - see below.
-*------------------------------------------------------------------*/
void LED_FLASH_Init(void)
{
   LED_state_G = 0;
}

 /*------------------------------------------------------------------*-
  LED_FLASH_Change_State()
  Changes the state of an LED (or pulses a buzzer, etc) on a 
  specified port pin.
  Must call at twice the required flash rate: thus, for 1 Hz
  flash (on for 0.5 seconds, off for 0.5 seconds),
  this function must be called twice a second.
-*------------------------------------------------------------------*/
void LED_FLASH_Change_State(void)
{
   // Change the LED from OFF to ON (or vice versa)
   if (LED_state_G == 1)
   {
      LED_state_G = 0;
      GreenLED = 0;
   }
   else
   {
      LED_state_G = 1;
      GreenLED = 1;
   }
}

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
