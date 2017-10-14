#include <msp430.h>
#include <libTimer.h>
#include "switches.h"
#include "buzzer.h"
#include "note_interrupt_handler.h"
#include "song_state_machines.h"

/* In order to create the main file, I merged the main files of buzzer and button, so similar methods remained while the ones that were diferent were included */

void main(void) 
{  
  switch_init();
  configureClocks();
  buzzer_init();
  enableWDTInterrupts();

  or_sr(0x18);  // CPU off, GIE on
} 
