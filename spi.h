/*------------------------------------------------------------------*-
   SPI.H (v1.00)
   Mohammadhossein Behgam
  ------------------------------------------------------------------*/
#ifndef _spi_H
#define _spi_H

#include "main.h"

//------------------------------------------------------------------
// SPI Errors
enum spiErrors
{
   NoErrors = 0,
   TimeOut,
   ModeFault,
   OverRun,
   NullPtr
};

// ------ Public Variables -----------------------------------------
typedef struct SPI_Packet
{
   uint8_t *txBuff;           /* The buffer of data being sent.*/
   uint8_t  txSize;           /* The remaining number of bytes to be transmitted. */
   uint8_t *rxBuff;           /* The buffer of received data. */
   uint8_t  rxSize;           /* The remaining number of bytes to be received. */
} SPI_PACKET_t;

// ------ Public function prototypes -------------------------------
void SPI_EnableSS(void);
void SPI_DisableSS(void);
uint8_t SPI_Master_Init(uint32_t clock_rate);
uint8_t SPI_Transfer(uint8_t send_value, uint8_t *received_value);
uint8_t SPI_Packet_Transfer(SPI_PACKET_t *packet);

#endif