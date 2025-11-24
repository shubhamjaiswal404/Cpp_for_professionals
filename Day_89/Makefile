CC=g++
CFLAGS=-c -Wall -g -I/usr/local/include/xercesc
LDFLAGS = -L/usr/local/lib  -lxerces-c-3.3  -std=c++11

all: MyDOMLSParser DOMPrintFilter

MyDOMLSParser: MyDOMLSParser.o DOMPrintFilter.o
	$(CC) MyDOMLSParser.o DOMPrintFilter.o -o MyDOMLSParser $(LDFLAGS)

MyDOMLSParser.o: MyDOMLSParser.cpp
	$(CC) $(CFLAGS) MyDOMLSParser.cpp -o MyDOMLSParser.o

DOMPrintFilter.o: DOMPrintFilter.cpp
	$(CC) $(CFLAGS) DOMPrintFilter.cpp -o DOMPrintFilter.o

clean:
	rm -f *.o MyDOMLSParser DOMPrintFilter

