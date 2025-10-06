#Make file 
CC=g++
CFLAGS = -c -Wall -I/usr/include
LDFLAGS = -lm  -lssh
all: ssh_client

ssh_client : ssh_client.o
	$(CC)  ssh_client.o  $(LDFLAGS)  -o ssh_client

ssh_client.o: ssh_client.cpp
	$(CC) $(CFLAGS) ssh_client.cpp -o ssh_client.o

run:
	./ssh_client 127.0.0.1 22 shubham

clean: 
	rm -f *.o ssh_client

#linux command 
# ....> ./ssh_client 127.0.0.1 22 shubham 
# // this will show text file in shubham folder 
