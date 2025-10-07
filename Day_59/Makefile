CC=g++
CFLAGS=-c -Wall -g  -I/usr/include/postgresql
LDFLAGS=-lm -L/usr/lib/x86_64-linux-gnu -lpq

# Targets and rules
all:pq_connect_ex

pq_connect_ex:pq_connect_ex.o
	$(CC) pq_connect_ex.o $(LDFLAGS) -o pq_connect_ex -std=c++11
pq_connect_ex.o: pq_connect_ex.cpp
	$(CC) $(CFLAGS) pq_connect_ex.cpp -o pq_connect_ex.o 
run:
	./pq_connect_ex

clean:
	rm -f *.o pq_connect_ex

# Linux Command 
# ....> g++ pq_coonect_ex.cpp -o pq_coonect_ex -lpq
# ....> ./pq_coonect_ex
