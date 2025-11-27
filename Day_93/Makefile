CC=g++
CFLAGS=-c -Wall -fPIC -I/usr/include/python3.12 -I/home/shubham/workspace/Cpp_for_professionals/Day_93/boost_1_75_0/boost
LDFLAGS = -shared -Wl,--export-dynamic -L/usr/lib/x86_64-linux-gnu/ -lboost_python312 -L/usr/lib/python3.12/config-3.12-x86_64-linux-gnu -lpython3.12

all: MyPyLib.so

MyPyLib.so:MyFunc.o
	$(CC) MyFunc.o $(LDFLAGS) -o MyPyLib.so

MyFunc.o: MyFunc.cpp
	$(CC) $(CFLAGS) MyFunc.cpp -o MyFunc.o

clean:
	rm -f *.o MyPyLib.so
