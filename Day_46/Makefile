#Make file 
CC=g++
CFLAGS = -c -Wall
LFLAGS = -lm

all: pdf_dump

pdf_dump : pdf_dump.o
	$(CC) $(LFAGS) pdf_dump.o -o pdf_dump

pdf_dump.o: pdf_dump.cpp
	$(CC) $(CFLAGS) pdf_dump.cpp -o pdf_dump.o

run:
	./pdf_dump gcc.pdf gcc_dump.txt

clean: 
	rm -f *.o pdf_dump gcc_dump.txt


	


