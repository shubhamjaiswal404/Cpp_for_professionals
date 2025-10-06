#Makefile 

CC=g++
CFLAGS = -c -Wall -I/usr/include
LDFLAGS = -lm -L/usr/lib/x86_64-linux-gnu -lboost_regex -lboost_iostreams -lpthread -lboost_system 

all: boostUDPServer

boostUDPServer : boostUDPServer.o
	$(CC)  boostUDPServer.o  $(LDFLAGS)  -o boostUDPServer

boostUDPServer.o: boostUDPServer.cpp
	$(CC) $(CFLAGS) boostUDPServer.cpp -o boostUDPServer.o

run:
	./boostUDPServer 1234

clean: 
	rm -f *.o boostUDPServer


