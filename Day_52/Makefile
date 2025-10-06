#Makefile 

CC=g++
CFLAGS = -c -Wall -I/usr/include
LDFLAGS = -lm -L/usr/lib/x86_64-linux-gnu -lpthread

all: my_thread_ex

my_thread_ex : my_thread_ex.o
	$(CC)  my_thread_ex.o  $(LDFLAGS)  -o my_thread_ex

my_thread_ex.o: my_thread_ex.cpp
	$(CC) $(CFLAGS) my_thread_ex.cpp -o my_thread_ex.o

clean: 
	rm -f *.o my_thread_ex


