
  #
  #  Makefile on Linux
  #
  #java -Djava.library.path=. MyTestJNI  // to use this set environment variable 
 
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

# Integrating Java with C++
# Linux - Terminal
# ....> g++ --version   	    // we get C++ compiler
# ....> java --version  	    // we get java compiler and jvm thats Openjdk 21 
# 
# Compilation of normal java program 
# write java program note file name and class name should same 
# ....> javac filename.java         // we generate filename.class
# ....> java filename        	    // execute the bytecode to jvm , consider like binary in C++
#
# Generate header for integrating java and C++
# ....> javac -h . filename.java    // filename of java program and C++ program should same 
# filename.h  			    // system generated code only copy function name use in C++ program with header of #include <jni.h>
# filename.class  	            // bytecode 
#
# Using Makefile to linking library of java and generating libmytest.so
# ....>make libmytest.so
# ....>ldd libmytest.so 	    // checking library 
# ....> make run 
#
#// Note:: we can modify .cpp file follow Makefile commands ,modify .java file then only compile and follow Makefile commands 
#
#
