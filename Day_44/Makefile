#Make file 
CC=g++
CFLAGS = -c -Wall
LFLAGS = -lm

all: MultiProcessProgram

MultiProcessProgram : MultiProcessProgram.o
	$(CC) $(LFAGS) MultiProcessProgram.o -o MultiProcessProgram

MultiProcessProgram.o: MultiProcessProgram.cpp
	$(CC) $(CFLAGS) MultiProcessProgram.cpp -o MultiProcessProgram.o

clean: 
	rm -f *.o MultiProcessProgram


