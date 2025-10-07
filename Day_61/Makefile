CC=g++
CFLAGS=-c -Wall -g -I/usr/include/postgresql
LDFLAGS=-lm -L/usr/lib/x86_64-linux-gnu -lpq

all:pq_async_proc

pq_async_proc:pq_async_proc.o
	$(CC) pq_async_proc.o $(LDFLAGS) -o pq_async_proc -std=c++11
pq_async_proc.o: pq_async_proc.cpp
	$(CC) $(CFLAGS) pq_async_proc.cpp -o pq_async_proc.o
run:
	./pq_async_proc

clean:
	rm -f *.o pq_async_proc


