CC=g++
CFLAGS=-c -Wall -g 
LDFLAGS= -L/usr/local -lboost_regex -lboost_iostreams -lpthread -lboost_system

all:rfc_server rfc_client

rfc_server:rfc_server.o
	$(CC) rfc_server.o $(LDFLAGS) -o rfc_server
rfc_server.o: rfc_server.cpp
	$(CC) $(CFLAGS) rfc_server.cpp -o rfc_server.o


rfc_client:rfc_client.o
	$(CC) rfc_client.o $(LDFLAGS) -o rfc_client
rfc_client.o: rfc_client.cpp
	$(CC) $(CFLAGS) rfc_client.cpp -o rfc_client.o

clean:
	rm -f *.o rfc_server rfc_client





# Adding Extra IP in linux :: Temporary
# ....> sudo ip addr 192.168.0.102/24 dev enp3s0
# ....>hostname -I
# 192.168.0.102 192.168.0.101
# ....>sudo ip addr del 192.168.0.102/24 dev enp3s0    // Remove IP
# ....>hostname -I 
# 192.168.0.101
#


