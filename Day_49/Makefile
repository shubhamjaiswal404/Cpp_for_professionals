#Make file 
CC=g++
CFLAGS = -c -Wall -I/usr/include
LDFLAGS = -lm -L/usr/lib/x86_64-linux-gnu -lz

all: read_gzip

read_gzip : read_gzip.o
	$(CC)  read_gzip.o  $(LDFLAGS)  -o read_gzip

read_gzip.o: read_gzip.cpp
	$(CC) $(CFLAGS) read_gzip.cpp -o read_gzip.o

run:
	./read_gzip example.txt.gz

clean: 
	rm -f *.o read_gzip

# linux commands to follow 
# ....> gzip --help > example.txt
# ....> vi example.txt
# ....> gzip example.txt
# ....> ls -l
# ....> ./read_gzip example.txt.gz
# ....> ./read_gzip example.txt.gz > pippo.txt
# ....>  diff example.txt.gz pippo.txt

