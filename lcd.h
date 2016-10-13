/*------------------------------------------------------------------*-
   LCD.H (v1.00)
   Mohammadhossein Behgam
  ------------------------------------------------------------------*/
#ifndef _lcd_H
#define _lcd_H

#include "main.h"

// LCD Pins
sfr  LcdPort = 0x80;
sbit RS = P3^6;
sbit E  = P3^7;

// Function prototypes
void LcdInit(void);
void LcdWrite(bit RSval, uint8_t Data);
void LcdPrint(uint8_t *str);

#endif