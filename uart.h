/*------------------------------------------------------------------*-
   UART.H (v1.00)
   Mohammadhossein Behgam
  ------------------------------------------------------------------*/
#ifndef _uart_H
#define _uart_H

#include "main.h"

// ------ Public function prototypes -------------------------------
void UART_Init(uint16_t baud_rate);
uint8_t UART_Transmit(uint8_t send_value);
uint8_t UART_Receive(void);


#endif