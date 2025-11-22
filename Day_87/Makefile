CC=g++
CFLAGS=-c -Wall -g -I/usr/local/include/xercesc
LDFLAGS = -L/usr/local/lib -lxerces-c-3.3 

all: MyDOMParser

MyDOMParser: MyDOMParser.o
	$(CC) MyDOMParser.o $(LDFLAGS) -o MyDOMParser

MyDOMParser.o: MyDOMParser.cpp
	$(CC) $(CFLAGS) MyDOMParser.cpp -o MyDOMParser.o

clean:
	rm -f *.o MyDOMParser

#....>export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH
#....> ./MyDOMParser my_test.xml

