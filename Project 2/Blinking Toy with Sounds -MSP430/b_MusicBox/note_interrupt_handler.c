#include <msp430.h>
#include "song_state_machines.h"

/* Since there are 250 interrupts per second, the song consist of 6 notes, so when counts reach 42(250/6), a new note will start to sound, meaning change_note() */

void
__interrupt_vec(WDT_VECTOR) WDT(){
  static char count = 0;
  if(++count ==42){
    change_note();
    count = 0;
  }
}
