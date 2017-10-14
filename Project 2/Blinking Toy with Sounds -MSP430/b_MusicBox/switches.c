#include <msp430.h>
#include "switches.h"
#include "buzzer.h"
#include "song_state_machines.h"

char song, sw1_state, sw2_state, sw3_state, sw4_state; //which song to play in the state machines

/*
In order to make the green board buttons work, all the 1s needed to be changed to 2s, so that way the upper buttons were the one to work 

The rest of the methods followed the same approach, other than that, it was the same as the demo.
*/

static char switch_sense(){
    char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
    P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
    P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
    return p2val;

}

void switch_init(){
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_sense();
  switch_interrupt_handler();	/* to initially read the switches */
}

void switch_interrupt_handler(){
  char p2val = switch_sense();

  //Defining each button state, whether it was pressed (1) or not (0)
  sw1_state=(p2val & SW1) ? 0 : 1;
  sw2_state=(p2val & SW2) ? 0 : 1;
  sw3_state=(p2val & SW3) ? 0 : 1;
  sw4_state=(p2val & SW4) ? 0 : 1;

  //Checking wich song to play depending on which button  was pressed

  if(sw1_state && song == 0){ //if button 1 is pressed and there is no song playing
    song = 1; //set song1 to be played
    }

  //The same approach was followed for the remaining songs
  
  else if(sw2_state && song == 0){
    song = 2;
  }
  
  else if(sw3_state && song == 0){
    song = 3;
  }
  
  else if(sw4_state && song == 0){
    song = 4;
  }
}
