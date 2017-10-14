all: lab1

CFLAGS=-g -O3

# Symbols helpful for understanding the productions
#   $@ is the production's target
#   $^ are the production's prerequisites

lab1:	PMS2.o
	cc -o $@ $^

lab1.o:	PMS2.c add_name.h delete_name.h read_file.h 
	cc -c $(CFLAGS) PMS2.c

clean:
	rm -f *.o lab1
