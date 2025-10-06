#Make file 
CC=g++
CFLAGS = -c -Wall -I/usr/include
LDFLAGS = -lm -L/usr/lib/x86_64-linux-gnu -lboost_regex -lboost_iostreams -lpthread -lboost_system 

all: udp_client

udp_client : udp_client.o
	$(CC)  udp_client.o  $(LDFLAGS)  -o udp_client

udp_client.o: udp_client.cpp
	$(CC) $(CFLAGS) udp_client.cpp -o udp_client.o

run:
	./udp_client 1234 "I write message send by client and receive by server"

clean: 
	rm -f *.o udp_client


