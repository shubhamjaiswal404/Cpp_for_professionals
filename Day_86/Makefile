CC=g++
CFLAGS=-c -Wall -g -I./

all:param_pack

param_pack:param_pack.o
	$(CC) param_pack.o -o param_pack -std=c++11
param_pack.o: param_pack.cpp
	$(CC) $(CFLAGS) param_pack.cpp -std=c++11  

clean:
	rm -f *.o param_pack


