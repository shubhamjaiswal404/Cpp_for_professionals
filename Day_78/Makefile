CC=g++
CFLAGS=  -c -Wall -g -I./ 
LDFLAGS= -lpthread -std=c++11

all: mySingletonDesignPattern 

mySingletonDesignPattern :  singletonfile.o   mySingletonDesignPattern.o
	$(CC) $(LDFLAGS) singletonfile.o  mySingletonDesignPattern.o   -o mySingletonDesignPattern 

singletonfile.o: singletonfile.cpp singletonfile.h
	$(CC) $(CFLAGS) singletonfile.cpp -o singletonfile.o

mySingletonDesignPattern.o: mySingletonDesignPattern.cpp singletonfile.h
	$(CC) $(CFLAGS) mySingletonDesignPattern.cpp -o mySingletonDesignPattern.o


run:
	./mySingletonDesignPattern example.txt > pippo.txt

clean:
	rm -f *.o mySingletonDesignPattern

# linux command : 
# ....> ./mySingletonDesignPattern example.txt > pippo.txt
# ....>vi example.txt # 20000 lines of Hello World  
#
#
# Same Makefile for source and header file with classes 
#
### Compiler and flags
#CC = g++
#CFLAGS = -c -Wall -g -I./ 
#LDFLAGS = -lpthread -std=c++11

### Target names
#TARGET = mySingletonDesignPattern
#OBJS = singletonfile.o mySingletonDesignPattern.o

### Default target
#all: $(TARGET)

### Linking stage
#$(TARGET): $(OBJS)
#	$(CC) $(OBJS) $(LDFLAGS) -o $(TARGET)

### Compile object files
#singletonfile.o: singletonfile.cpp singletonfile.h
#	$(CC) $(CFLAGS) singletonfile.cpp -o singletonfile.o

#mySingletonDesignPattern.o: mySingletonDesignPattern.cpp singletonfile.h
#	$(CC) $(CFLAGS) mySingletonDesignPattern.cpp -o mySingletonDesignPattern.o

### Run the program (optional)
#run: $(TARGET)
#	./$(TARGET) example.txt > pippo.txt

### Clean up build artifacts
#clean:
#	rm -f *.o $(TARGET)




