/*------------------------------------------------------------------
   INTERRUPT.c (v1.00)
   Mohammadhossein Behgam
  ------------------------------------------------------------------*/
// Include Files
#include "interrupt.h"

/*------------------------------------------------------------------*/
void DisableInterrupts(void)
{
   // Disabling Interrupts
   EA = 0;
}