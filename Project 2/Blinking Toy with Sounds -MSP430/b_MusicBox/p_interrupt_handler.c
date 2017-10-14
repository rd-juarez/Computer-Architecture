#include <msp430.h>
#include "switches.h"

/* In order to make the buttons work from the secondary board, the 1s referencing the main board needed to be changed to 2s, so that now the secondary board could enable sounds and buttons as wells */

void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  
  if (P2IFG & SWITCHES) {	      /* did a button cause this interrupt? */
    P2IFG &= ~SWITCHES;		      /* clear pending sw interrupts */
    switch_interrupt_handler();	/* single handler for all switches */
  }
}

