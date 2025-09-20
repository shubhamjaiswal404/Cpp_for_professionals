CC=g++
CFLAGS=-c -Wall
LDFLAGS = -lm -lcgicc

all: CppWebForm MyWebAppGet

CppWebForm: CppWebForm.o
	$(CC) CppWebForm.o -o CppWebForm $(LDFLAGS)
CppWebForm.o: CppWebForm.cpp
	$(CC) $(CFLAGS) CppWebForm.cpp $(LDFLAGS)


MyWebAppGet: MyWebAppGet.o
	$(CC) MyWebAppGet.o -o MyWebAppGet $(LDFLAGS)
MyWebAppGet.o: MyWebAppGet.cpp
	$(CC) $(CFLAGS) MyWebAppGet.cpp $(LDFLAGS)

install:
	sudo cp CppWebForm /usr/lib/cgi-bin/CppWebForm.cgi
	sudo cp MyWebAppGet /usr/lib/cgi-bin/MyWebAppGet.cgi
uninstall:
	  sudo rm -f  /usr/lib/cgi-bin/CppWebForm.cgi
	  sudo rm -f  /usr/lib/cgi-bin/MyWebAppGet.cgi

clean:
	rm -f *.o MyWebAppGet CppWebForm 



