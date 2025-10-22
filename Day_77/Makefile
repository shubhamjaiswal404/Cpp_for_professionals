CC=g++
CFLAGS=  -c -Wall -g 
LDFLAGS= -lpthread -std=c++11

all: myThreadReadFile

myThreadReadFile: myThreadReadFile.o
	$(CC) $(LDFLAGS) myThreadReadFile.o  -o myThreadReadFile 
myThreadReadFile.o: myThreadReadFile.cpp
	$(CC) $(CFLAGS) myThreadReadFile.cpp -o myThreadReadFile.o

run:
	./myThreadReadFile example.txt >  pippo.txt

clean:
	rm -f *.o myThreadReadFile

# linux command : 
# ....> /myThreadReadFile example.txt >  pippo.txt
# ....>vi example.txt # 20000 lines of Hello World
# ....> vi pippo.txt  



