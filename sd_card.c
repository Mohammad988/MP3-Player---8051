/*------------------------------------------------------------------
   sd_card.c (v1.00)                                                   
   Mohammadhossein Behgam
  ------------------------------------------------------------------*/
// Include Files
#include "sd_card.h"

/*------------------------------------------------------------------*/
// Global Variables
SD_CMD_PACKET_t sd_cmd_packet;
extern SPI_PACKET_t spi_packet;

/*------------------------------------------------------------------*/
uint8_t send_command(uint8_t cmd, uint32_t arg)
{
   uint8_t flag, i;

   if(cmd >= 64)
      return Illegal_Cmd;
   
   sd_cmd_packet.packet.Cmd = 0x40 | cmd;
   sd_cmd_packet.packet.Arg = arg;

   switch(cmd)
   {
      case CMD_00:
         sd_cmd_packet.packet.Chksum = 0x95;
         break;

      case CMD_08:
         sd_cmd_packet.packet.Chksum = 0x87;
         break;

      default:
         sd_cmd_packet.packet.Chksum = 0x01;
         break;
   }

   for(i = 0; i < SD_CMD_PACET_SIZE; i++)   
   	flag = SPI_Transfer(sd_cmd_packet.allData[i],NULL);

   return NoError;
}

/*------------------------------------------------------------------*/
uint8_t reeceive_response(uint8_t nBytes, uint8_t *buff)
{
	
	
	return NoError;
}

/*------------------------------------------------------------------
  ----------------------- END OF FILE ------------------------------
  ------------------------------------------------------------------*/