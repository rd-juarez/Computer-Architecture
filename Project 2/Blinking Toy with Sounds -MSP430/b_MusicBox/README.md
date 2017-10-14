Lab 2 -Blinky-Buzzy Toys
Due Date: April 7 @10 pm

How to use the program:

1) First, type

   :$ make

In the in the directory before the project, in order to make the TimerLib, which is necessary for the program to work

2) Inside the project folder, there is b_MusicBox,(../project/b_MusicBox) once inside type

   :$ make load

to load the program into the MSP430, when the intallation was succesfully, a beep sound will be heard, and the musick box could be start to be used

3) To clean the binaries:
   :$ make clean

Description: The program creates a "toy" with both msp430 boards. The toy itself consist of 4 buttons and a speaker with a lcd screen (not to be used in this lab). On my configuration, each of my buttons plays a little theme song:

- Power Rangers: Zordon calling & Opening them song
- Adams Family theme song
- A mexican clasic "la cucaracha"

So when the user press the button, a song is played and cannot be interrupted by any other song, until its finished then the user can decided if he/she want to play the same song or to play another one.
My program was started from 0 using the files from the demos and Daniel's (TA) help. He helped to uunderstand the requirements of the work and how to implement a better approach for the state machines that played the songs. I used to have switch statements, similar to the button and led demo, tha did work only for the first song, but when I tried to implement different songs, there was a problem and the songs where overlapping each other, like a song was playing a piece of another song afterthe first song has ended. So I changed, with Daniel's advice, from a switch statement to a song's arrays and traverse through it, and for each note, the buzzer will be used according to each note's frequency and lenth. For the butons, after each button state was created, it was just a matter of using if statements, if (button 1 is pressed) play song1, and the same approach was copied for the other 3 buttons/songs.

Collaborations and References:

- Bobsomers on GitHub for the note's frequency definition which were specific for the msp430
  github.com/bobsomers/msp430-launchpad-music/blob/music.h

-During the process of the development of the lab, I helped Eulalio Garcia and Marco Munoz to understand the concepts of merging files and how to create the relations between the buttons and the buzzer so they could make their buttons work and make noises. Eventhough we all started using the same approach, at the end Daniel point me out a better way to play the notes, so I changed but the logic was the same, only the way to access each note was the difference. I want to give credit to the arch 1 team for using his code to implement my music box, because at the end, were them code that helped me to complete the lab, was just a matter of changing/merging a little code, even both make file where very similar to those on the demos, so it was easier to reuse that structre since it was a pretty neat implementation of a makefile.