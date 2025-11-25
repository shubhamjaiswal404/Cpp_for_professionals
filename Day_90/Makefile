CC=g++
CFLAGS=-c -Wall -g -I/usr/local/include/xercesc
LDFLAGS = -L/usr/local/lib  -lxerces-c-3.3  -std=c++11

all: MySAXParser MySAXHandler

MySAXParser: MySAXParser.o MySAXHandler.o
	$(CC) MySAXParser.o MySAXHandler.o -o MySAXParser $(LDFLAGS)

MySAXParser.o: MySAXParser.cpp
	$(CC) $(CFLAGS) MySAXParser.cpp -o MySAXParser.o

MySAXHandler.o: MySAXHandler.cpp
	$(CC) $(CFLAGS) MySAXHandler.cpp -o MySAXHandler.o

clean:
	rm -f *.o MySAXParser MySAXHandler
