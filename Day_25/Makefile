CC=g++
CFLAGS=-c -Wall
LDFLAGS = -lm

all: CppWebPage

CppWebPage: CppWebPage.o
	$(CC) CppWebPage.o -o CppWebPage $(LDFLAGS)
CppWebPage.o: CppWebPage.cpp
	$(CC) $(CFLAGS) CppWebPage.cpp $(LDFLAGS)

install:
	  sudo cp CppWebPage /usr/lib/cgi-bin/CppWebPage.cgi
uninstall:
	  sudo rm -f  /usr/lib/cgi-bin/CppWebPage.cgi
