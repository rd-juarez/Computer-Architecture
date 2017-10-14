#include <msp430.h>
#include "song_state_machines.h"
#include "buzzer.h"
#include "switches.h"

/* Songs to be Played */

//Power Rangers: Zordon Calling
static int song1[] = {E,E,D,E,G,E};

//Power Rangers: Song Intro
static int song2[] = {A,A,A,A,D,E,A,D,E,G,D,D,E};

//Adam's Family
static int song3[] = {C,D,E,F,R,R,R,R,R,R,D,E,F,G,R,R,R,R,D,E,F,G,R,R,R,D,E,F,G,R,R,D,C,D,E,F,R,R,E,R,E};

//La Cucaracha
static int song4[] = {C,C,C,F,A,C,C,C,F,A,F,F,E,E,D,D,C};

void change_note(){
  static int current_note =0;

  //To get rid of the annoying beep sound before actually touching a button
  buzzer_set_period(0);

  /* Here the differents song's arrays will be played using buzzer_set_period() while the method traverse through the each song's arrays */
  
  if(song == 1){
    if(current_note < 6){
      buzzer_set_period(song1[current_note++]);
    }
    //After the song is played
    else{
      song = 0;
      current_note = 0;
    }
  }
  
  else if(song == 2){
    if(current_note < 13){
      buzzer_set_period(song2[current_note++]);
    }
    //After the song is played
    else{
      song = 0;
      current_note = 0;
    }
  }
   else if(song == 3){
     if(current_note < 41){
      buzzer_set_period(song3[current_note++]);
    }
    //After the song is played
    else{
      song = 0;
      current_note = 0;
    }
  }
   else if(song == 4){
     if(current_note < 18){
      buzzer_set_period(song4[current_note++]);
    }
    //After the song is played
    else{
      song = 0;
      current_note = 0;
    }
  }
  
}
