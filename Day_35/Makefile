#CC=g++
#CFLAGS=-c -Wall -I.
#LDFLAGS= -lm -L.

#OBJ_LIST = myObjTest.o mysquare.o mytriangle.o

#all:myObjTest

#myObjTest:$(OBJ_LIST)
#	$(CC) $(LDFLAGS) $(OBJ_LIST) -o myObjTest

#myObjTest.o:myObjTest.cpp
#	$(CC) $(CFLAGS) myObjTest.cpp -o myObjTest.o

#mysquare.o:mysquare.cpp
#	$(CC) $(CFLAGS) mysquare.cpp -o mysquare.o

#mytriangle.o:mytriangle.cpp
#	$(CC) $(CFLAGS) mytriangle.cpp -o mytriangle.o

#clean:
#	rm -f *.o myObjTest


# building library
#



CC=g++
CFLAGS=-c -Wall -I.
LDFLAGS= -lm -L. -lmyLib      # add after commands -lmyLib

OBJ_LIST = myObjTest.o mysquare.o mytriangle.o

all:myObjTest

myObjTest:myObjTest.o		# add after commands myObjTest.o 
	$(CC)  myObjTest.o $(LDFLAGS)  -o myObjTest

#myObjTest:$(OBJ_LIST)
#	$(CC) $(LDFLAGS) $(OBJ_LIST) -o myObjTest


myObjTest.o:myObjTest.cpp
	$(CC) $(CFLAGS) myObjTest.cpp -o myObjTest.o

mysquare.o:mysquare.cpp
	$(CC) $(CFLAGS) -fPIC mysquare.cpp -o mysquare.o

mytriangle.o:mytriangle.cpp
	$(CC) $(CFLAGS) -fPIC mytriangle.cpp -o mytriangle.o

clean:
	rm -f *.o myObjTest


#follow this series of command on linux 

# 1:: make clean 
# 2:: make mysquare.o
# 3:: make mytriangle.o
# 4:: ls -l *.o   // lib{filename}.so.1   like libmyLib.so.1
# 5:: g++ --share -Wl,-soname,libmyLib.so.1 -o libmyLib.so.1.0 *.o
# 6:: pwd
# 7:: echo $LD_LIBRARY_PATH    //environment variable 
# 8:: ln -sf libmyLib.so.1.0 libmyLib.so.1
# 9:: ln -sf libmyLib.so.1.0 libmyLib.so
# 10:: vi Makefile    // edit Makefile 
# 11:: make clean
# 12:: make myObjTest
# // output is same 
















