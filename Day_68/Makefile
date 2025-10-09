CC=g++
CFLAGS=-c -Wall -g 
LDFLAGS= -lpthread -lrt

all:mq_send mq_recv

mq_send:mq_send.o
	$(CC) mq_send.o $(LDFLAGS) -o mq_send 
mq_send.o: mq_send.cpp
	$(CC) $(CFLAGS) mq_send.cpp -o mq_send.o

mq_recv:mq_recv.o
	$(CC) mq_recv.o $(LDFLAGS) -o mq_recv 
mq_recv.o: mq_recv.cpp
	$(CC) $(CFLAGS) mq_recv.cpp -o mq_recv.o

clean:
	rm -f *.o mq_send mq_recv

