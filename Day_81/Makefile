
  #
  # Makefile on Linux
  #
  #java -Djava.library,path=. MyTestJNI
 
JAVA_HOME=/usr/lib/jvm/java-21-openjdk-amd64
CC=g++
CFLAGS=-c -Wall -fPIC -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux -I./
LDFLAGS = -shared -L${JAVA_HOME}/lib
 
all:libmytest.so
 
libmytest.so:MyTestJNI.o
	$(CC) $(LDFLAGS) MyTestJNI.o -o libmytest.so
MyTestJNI.o:MyTestJNI.cpp
	$(CC) $(CFLAGS) MyTestJNI.cpp -o MyTestJNI.o
 
clean:
	rm -f *.o libmytest.so
 
run:
	java -cp . -Djava.library.path=. MyTestJNI
#	java -Djava.library.path=. MyTestJNI


