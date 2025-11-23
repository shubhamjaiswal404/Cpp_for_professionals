CC=g++
CFLAGS=-c -Wall -g -I/usr/local/include/xercesc
LDFLAGS = -L/usr/local/lib  -lxerces-c-3.3  -std=c++11

all: MyDOMCreat myDOMView

MyDOMCreat: MyDOMCreat.o
	$(CC) MyDOMCreat.o -o MyDOMCreat $(LDFLAGS)
#	$(CC) MyDOMParser.o $(LDFLAGS) -o MyDOMParser

MyDOMCreat.o: MyDOMCreat.cpp
	$(CC) $(CFLAGS) MyDOMCreat.cpp -o MyDOMCreat.o


myDOMView: myDOMView.o
	$(CC) myDOMView.o -o myDOMView $(LDFLAGS)


myDOMView.o: myDOMView.cpp
	$(CC) $(CFLAGS) myDOMView.cpp -o myDOMView.o


clean:
	rm -f *.o MyDOMCreat myDOMView

