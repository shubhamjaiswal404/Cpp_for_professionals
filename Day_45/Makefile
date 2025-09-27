#Make file 
CC=g++
CFLAGS = -c -Wall
LFLAGS = -lm

all: main_process sub_process

main_process : main_process.o
	$(CC) $(LFAGS) main_process.o -o main_process

main_process.o: main_process.cpp
	$(CC) $(CFLAGS) main_process.cpp -o main_process.o

sub_process : sub_process.o
	$(CC) $(LFAGS) sub_process.o -o sub_process

sub_process.o: sub_process.cpp
	$(CC) $(CFLAGS) sub_process.cpp -o sub_process.o

clean: 
	rm -f *.o sub_process main_process


