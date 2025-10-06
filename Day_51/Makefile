#Makefile 

CC=g++
CFLAGS = -c -Wall -I/usr/include
LDFLAGS = -lm -L/usr/lib/x86_64-linux-gnu -lboost_regex 

all: regularExperssion

regularExperssion : regularExperssion.o
	$(CC)  regularExperssion.o  $(LDFLAGS)  -o regularExperssion

regularExperssion.o: regularExperssion.cpp
	$(CC) $(CFLAGS) regularExperssion.cpp -o regularExperssion.o

run1:
	echo "1234-5678-9012-36" | ./regularExperssion
run2:
	cat ex_testing.txt | ./regularExperssion

clean: 
	rm -f *.o regularExperssion

# linux command :
#....> echo "1234-5678-9012-36" | ./regularExperssion
#....> cat ex_testing.txt | ./regularExperssion
#....> cat ex_testing.txt | grep "^Subject:"
