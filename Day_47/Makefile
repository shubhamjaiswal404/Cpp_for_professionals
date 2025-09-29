#Make file 
CC=g++
CFLAGS = -c -Wall
LFLAGS = -lm

all: pdf_count_page

pdf_count_page : pdf_count_page.o
	$(CC) $(LFAGS) pdf_count_page.o -o pdf_count_page

pdf_count_page.o: pdf_count_page.cpp
	$(CC) $(CFLAGS) pdf_count_page.cpp -o pdf_count_page.o

run:
	./pdf_count_page gcc.pdf 

clean: 
	rm -f *.o pdf_count_page 


	


