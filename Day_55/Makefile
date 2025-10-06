#Make file 
CC=g++
CFLAGS = -c -Wall -I/usr/include
LDFLAGS = -lm  -lssh -lpthread
all: ssh_cmd

ssh_cmd : ssh_cmd.o
	$(CC)  ssh_cmd.o  $(LDFLAGS)  -o ssh_cmd

ssh_cmd.o: ssh_cmd.cpp
	$(CC) $(CFLAGS) ssh_cmd.cpp -o ssh_cmd.o

run:
	./ssh_cmd 127.0.0.1 22 shubham "ls -l *.txt" "who" "ls -l *.json"

clean: 
	rm -f *.o ssh_cmd

#linux command 
# ....> ./ssh_cmd 127.0.0.1 22 shubham "ls -l *.txt" "who" "ls -l *.json"
# // this will show txt,json file in shubham folder 
