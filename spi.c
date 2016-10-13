/*------------------------------------------------------------------
   spi.c (v1.00)                                                   
   Mohammadhossein Behgam
  ------------------------------------------------------------------*/
// Include Files
#include "spi.h"

/*------------------------------------------------------------------*/
// Function prototypes
uint8_t SPI_Baudrate(uint32_t clock_rate);

/*------------------------------------------------------------------*/
// SPI Definitions
//SPCON
#define SPR2   (1<<7)
#define SPEN   (1<<6)
#define SSDIS  (1<<5)
#define MSTR   (1<<4)
#define CPOL   (1<<3)
#define CPHA   (1<<2)
#define SPR1   (1<<1)
#define SPR0   (1<<0)

//SPSTA
#define SPIF   (1<<7)
#define WCOL   (1<<6)
#define SSERR  (1<<5)
#define MODF   (1<<4)
#define SPI_ERR_MASK    (SPIF | WCOL | SSERR | MODF)

// SPI clock
enum spiBaudrate
{
   Fclk_0 = 0,
   Fclk_2,
   Fclk_4,
   Fclk_8,
   Fclk_16,
   Fclk_32,
   Fclk_64,
   Fclk_128,
   NO_BRG
};

SPI_PACKET_t spi_packet;

/*------------------------------------------------------------------*/
void SPI_EnableSS()
{
   SS = 0; // enable SS
}

/*------------------------------------------------------------------*/
void SPI_DisableSS()
{
   SS = 1; // disable SS
}

/*------------------------------------------------------------------*/
uint8_t SPI_Baudrate(uint32_t clock_rate)
{
   uint8_t i;
   for(i = 0; i < 8; i++)
      if((clock_rate << i) >= OSC_FREQ)
         return i;
         
   return i;                
} 

/*------------------------------------------------------------------*/
uint8_t SPI_Master_Init(uint32_t clock_rate)
{
   uint8_t Baud;
   uint8_t flag;

   SPCON = 0;
   SPCON |= MSTR; /* Master mode */

   Baud = SPI_Baudrate(clock_rate);
   switch(Baud)
   {
      case Fclk_0:
      case Fclk_2:
         ClrBit(SPCON, (SPR2 | SPR1 | SPR0));
         break;

      case Fclk_4:
         ClrBit(SPCON, (SPR2 | SPR1));
         SetBit(SPCON, SPR0);
         break;

      case Fclk_8:
         ClrBit(SPCON, (SPR2 | SPR0));
         SetBit(SPCON, SPR1);
         break;

      case Fclk_16:
         ClrBit(SPCON, SPR2);
         SetBit(SPCON, (SPR1 |SPR0));
         break;

      case Fclk_32:
         ClrBit(SPCON, (SPR1 | SPR0));
         SetBit(SPCON, SPR2);
         break;

      case Fclk_64:
         ClrBit(SPCON, SPR1);
         SetBit(SPCON, (SPR2 | SPR0));
         break;

      case Fclk_128:
      default:
         ClrBit(SPCON, SPR0);
         SetBit(SPCON, (SPR2 | SPR1));
         break;
   }

   SPCON |= SSDIS;   /* P1.1 is available as standard I/O pin */
   SPCON &= ~CPOL;   /* CPOL = 0 */
   SPCON &= ~CPHA;   /* CPHA = 1 */
   SPCON |= SPEN;    /* run spi */

   return flag;
}

/*------------------------------------------------------------------*/
uint8_t SPI_Transfer(uint8_t send_value, uint8_t *received_value)
{
   uint8_t spiStat;
   uint8_t timeOut = 0;
   
   SPI_EnableSS();            /* start a transmission */
   SPDAT = send_value;        /* send the data */
   do
   {
      spiStat = SPSTA;
   }
   while(((spiStat & SPI_ERR_MASK) == 0) && (++timeOut != 0));    /* wait for end of transmission */

   if(timeOut)
      return TimeOut;

   switch(spiStat)         /* read and clear spi status register */
   {
      case 0x80:
         if(received_value != NULL)
            *received_value = SPDAT;   /* read receive data */
         break;
      
      case 0x10:
         /* mode fault */
         return ModeFault;
         break;

      case 0x40:
         /* overrun */
         return OverRun;
         break;
   }

   SPI_DisableSS();
   
   return NoErrors;    
}

/*------------------------------------------------------------------*/
uint8_t SPI_Packet_Transfer(SPI_PACKET_t *packet)
{
   if(packet == NULL)
      return NullPtr;


   
   return NoErrors;    
}
/*------------------------------------------------------------------
  ----------------------- END OF FILE ------------------------------
  ------------------------------------------------------------------*/