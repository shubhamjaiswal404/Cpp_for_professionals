CC= g++
CFLAGS=-c -Wall 
LDFLAGS = -lprotobuf -pthread

all: MyArena

MyArena:MyArena.o
	$(CC) MyArena.o $(LDFLAGS) -o MyArena

MyArena.o: MyArena.cpp
	$(CC) $(CFLAGS) MyArena.cpp -o MyArena.o

clean:
	rm -f *.o MyArena
	
#Direct linux command
#....>g++ MyArena.cpp -lprotobuf -pthread -o MyArena
