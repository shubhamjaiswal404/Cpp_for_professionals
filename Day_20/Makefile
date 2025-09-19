CC=g++
CFLAGS = -c -Wall -I/usr/include/mysql-cppconn
LDFLAGS = -lm -L/usr/lib -lmysqlcppconn

all: LoadCsvMysqlDB

LoadCsvMysqlDB: LoadCsvMysqlDB.o
	$(CC) LoadCsvMysqlDB.o $(LDFLAGS) -o LoadCsvMysqlDB

LoadCsvMysqlDB.o: LoadCsvMysqlDB.cpp
	$(CC) $(CFLAGS) LoadCsvMysqlDB.cpp -o LoadCsvMysqlDB.o

clean:
	rm -f *.o LoadCsvMysqlDB






