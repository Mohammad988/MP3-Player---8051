/*------------------------------------------------------------------*-
   SD_CARD.H (v1.00)
   Mohammadhossein Behgam
  ------------------------------------------------------------------*/
#ifndef _sd_card_H
#define _sd_card_H

#include "main.h"
#include "spi.h"

//------- Types ----------------------------------------------------
typedef struct
{
   uint8_t  Cmd;
   uint32_t Arg;
   uint8_t  Chksum;
}SD_CMD_t;

typedef union
{
   SD_CMD_t packet;   
   uint8_t allData[sizeof(uint8_t) + sizeof(uint32_t) + sizeof(uint8_t)];
}SD_CMD_PACKET_t;

//------- Definitions ----------------------------------------------
#define CMD_00    0
#define CMD_08    8

#define SD_CMD_PACET_SIZE  (sizeof(SD_CMD_t))

// ------ Public Variables -----------------------------------------
enum SD_Errors
{
   NoError = 0,
   Illegal_Cmd
};

// ------ Public function prototypes -------------------------------
uint8_t send_command(uint8_t cmd, uint32_t arg);
uint8_t reeceive_response(uint8_t nBytes, uint8_t *buff);
uint8_t SD_Init();

#endif