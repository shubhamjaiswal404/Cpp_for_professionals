#Make file 
CC=g++ 
CFLAGS = -c -Wall  
LFLAGS = -lm  

all: iteratorContainer

iteratorContainer : iteratorContainer.o
	$(CC) $(LFAGS) iteratorContainer.o -o iteratorContainer

iteratorContainer.o: iteratorContainer.cpp
	$(CC) $(CFLAGS) iteratorContainer.cpp -o iteratorContainer.o
 
clean: 
	rm -f *.o iteratorContainer

