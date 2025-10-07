CC=g++
CFLAGS=-c -Wall -g -I/usr/include/postgresql
LDFLAGS=-lpq -lpqxx -lssh -L/usr/lib/x86_64-linux-gnu

all:pqxx_select_ex

pqxx_select_ex:pqxx_select_ex.o
	$(CC) pqxx_select_ex.o $(LDFLAGS) -o pqxx_select_ex -std=c++11
pqxx_select_ex.o: pqxx_select_ex.cpp
	$(CC) $(CFLAGS) pqxx_select_ex.cpp -o pqxx_select_ex.o

run:
	./pqxx_select_ex 192.168.0.103 5432 postgres yhdb

clean:
	rm -f *.o pqxx_select_ex


#linux command 
#....> ./pqxx_select_ex 192.168.0.103 5432 postgres yhdb

