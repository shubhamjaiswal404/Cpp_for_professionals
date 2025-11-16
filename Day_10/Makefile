#  Makefile 
CC=g++
CFLAGS=-c -Wall 
LFLAGS=-lm -lpthread -std=c++11

all: myThreadReadFile
myThreadReadFile: myThreadReadFile.o
	$(CC) $(LFLAGS) myThreadReadFile.o -o myThreadReadFile
myThreadReadFile.o: myThreadReadFile.cpp
	$(CC) $(CFLAGS) myThreadReadFile.cpp -o myThreadReadFile.o

clean:
	rm -f *.o myThreadReadFile
