# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h 
LDFLAGS = ../lib/libTimer.a -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: b_musicbox.elf 

#additional rules for files
b_musicbox.elf: ${COMMON_OBJECTS} main.o song_state_machines.o buzzer.o note_interrupt_handler.o p_interrupt_handler.o switches.o ../lib/libTimer.a
	${CC} $(CFLAGS) $^ $(LDFLAGS) -o $@ 

load: b_musicbox.elf
	mspdebug rf2500 "prog $^"

clean:
	rm -f *.o *.elf


main.o: buzzer.h
buzzer.c: buzzer.h
song_state_machines.o: song_state_machines.h buzzer.h
note_interrupt_handler.o: song_state_machines.h
p_interrupt_handler.c: switches.h
switches.c: switches.h buzzer.h song_state_machines.h
