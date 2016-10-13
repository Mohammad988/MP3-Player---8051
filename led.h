/*------------------------------------------------------------------*-
   LED.H (v1.00)
   Mohammadhossein Behgam
  ------------------------------------------------------------------*/
#ifndef _led_H
#define _led_H

#include "main.h"

// LED is to be connected to this pin
sbit GreenLED  = P2^7;
sbit AmberLED  = P2^6;
sbit YellowLED = P2^5;
sbit RedLED    = P2^4;

// Function prototypes
void LED_FLASH_Init(void);
void LED_FLASH_Change_State(void);
void DELAY_LOOP_Wait(const unsigned int);


#endif