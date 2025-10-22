CC=g++
CFLAGS=-c -Wall -g 
LDFLAGS=-lm -lpthread

all:rusage_ex

rusage_ex:rusage_ex.o
	$(CC) $(LDFLAGS) rusage_ex.o   -o rusage_ex 
rusage_ex.o: rusage_ex.cpp
	$(CC) $(CFLAGS) rusage_ex.cpp -o rusage_ex.o
run:
	./rusage_ex example.txt example_out.txt

clean:
	rm -f *.o rusage_ex

# linux command : 
# ....> man getrusage
# ....>vi example.txt # 20000 lines of Hello World  



