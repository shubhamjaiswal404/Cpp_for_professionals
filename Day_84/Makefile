CC=g++
CFLAGS=-c -Wall -g 
LDFLAGS= -L/usr/local -lboost_regex -lboost_iostreams -lpthread -lboost_system

all:iostream_server iostream_client

iostream_server:iostream_server.o
	$(CC) iostream_server.o $(LDFLAGS) -o iostream_server
iostream_server.o: iostream_server.cpp
	$(CC) $(CFLAGS) iostream_server.cpp -o iostream_server.o


iostream_client:iostream_client.o
	$(CC) iostream_client.o $(LDFLAGS) -o iostream_client
iostream_client.o: iostream_client.cpp
	$(CC) $(CFLAGS) iostream_client.cpp -o iostream_client.o

clean:
	rm -f *.o iostream_server iostream_client

# Note for network :: We required two different linux machine , means two different IPs 

# Linux machine - 1 : linux command
#
# ....> hostname -I 
# 192.168.0.105
# ....> sudo lsof -i -P -n | grep LISTEN

# ....>./iostream_server 1234 
# ....> sudo lsof -i -P -n | grep LISTEN
# iostream_7752   .....     TCP *:1234

# ....>./iostream_server 1234
# Message recevied : Hello from Client 


# Linux machine - 2 : linux command 
#
# ....> hostname -I
# 192.168.0.106

# ....>./iostream_client 192.168.0.105:1234 "Hello from Client" 
# Remote Confirm Time: ....


# Note for Local PCs : Open two terminals 
# Terminal 1: linux command
#
# ....>./iostream_server 1234 
# ....> sudo lsof -i -P -n | grep LISTEN
# iostream_7752   .....     TCP *:1234

# ....>./iostream_server 1234
# Message recevied : Hello from Client

#Terminal 2 : linux command
# 
# ....>./iostream_client 127.0.0.1:1234 "Hello from Client" 
# Remote Confirm Time: ....

