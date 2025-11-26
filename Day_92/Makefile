CC=g++
CFLAGS=-c -Wall -g 
LDFLAGS= -lboost_json -lboost_system -std=c++11

all:json_parse MyParserHandler

json_parse:json_parse.o MyParserHandler.o
	$(CC)  json_parse.o MyParserHandler.o $(LDFLAGS) -o json_parse
 
json_parse.o: json_parse.cpp
	$(CC) $(CFLAGS) json_parse.cpp -o json_parse.o
	
MyParserHandler.o: MyParserHandler.cpp
	$(CC) $(CFLAGS) MyParserHandler.cpp -o MyParserHandler.o
	
clean:
	rm -f *.o json_parse MyParserHandler
