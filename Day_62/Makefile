CC=g++
CFLAGS=-c -Wall -g -I/usr/include/postgresql
LDFLAGS=-lm -L/usr/lib/x86_64-linux-gnu -lpq -lssh

all:pq_remote_async_proc

pq_remote_async_proc:pq_remote_async_proc.o
	$(CC) pq_remote_async_proc.o $(LDFLAGS) -o pq_remote_async_proc -std=c++11
pq_remote_async_proc.o: pq_remote_async_proc.cpp
	$(CC) $(CFLAGS) pq_remote_async_proc.cpp -o pq_remote_async_proc.o

run:
	./pq_remote_async_proc 192.168.0.103 5432 postgres yhdb

clean:
	rm -f *.o pq_remote_async_proc
#linux command
#....> hostname -I 
#....> ./pq_remote_async_proc 192.168.0.103 5432 postgres yhdb
#password::

