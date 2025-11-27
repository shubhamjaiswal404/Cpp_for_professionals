#protoc --cpp_out=./ Order.proto

CC=g++
CFLAGS=-c -Wall 
LDFLAGS = -lprotobuf -pthread

all:writePO readPO

writePO:writePO.o Order.pb.o
	$(CC) writePO.o Order.pb.o $(LDFLAGS) -o writePO

write.o:writePO.cpp
	$(CC) $(CFLAGS) writePO.cpp -o writePO.o
    
readPO:readPO.o Order.pb.o
	$(CC) readPO.o Order.pb.o $(LDFLAGS) -o readPO

readPO.o:readPO.cpp
	$(CC) $(CFLAGS) readPO.cpp -o readPO.o
    
Order.pd.o:Order.pb.cc
	$(CC) $(CFLAGS) Order.pb.cc -o Order.pb.o
    
clean:
	rm -f *.o writePO readPO
    

