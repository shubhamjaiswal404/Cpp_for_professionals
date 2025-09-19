#CC=g++ 
#CFLAGS = -c -Wall -I/usr/include/mysql-cppconn    
#LDFLAGS = -lm -L/usr/lib -lmysqlcppconn
#all: mysqlconnector
#mysqlconnector: mysqlconnector.o
#	$(CC) $(LDFLAGS) mysqlconnector.o -o mysqlconnector
#mysqlconnector.o: mysqlconnector.cpp
#	$(CC) $(CFLAGS) mysqlconnector.cpp -o mysqlconnector.o
#clean: 
#	rm -f *.o mysqlconnector

CC=g++
CFLAGS = -c -Wall -I/usr/include/mysql-cppconn
LDFLAGS = -lm -L/usr/lib -lmysqlcppconn

all: mysqlconnector

mysqlconnector: mysqlconnector.o
	$(CC) mysqlconnector.o $(LDFLAGS) -o mysqlconnector

mysqlconnector.o: mysqlconnector.cpp
	$(CC) $(CFLAGS) mysqlconnector.cpp -o mysqlconnector.o

clean:
	rm -f *.o mysqlconnector






