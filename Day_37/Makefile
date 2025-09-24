CC=g++ 
CFLAGS = -c -Wall  
LFLAGS = -lm   
  
all: templateLinkList

templateLinkList : templateLinkList.o
	$(CC) $(LFAGS) templateLinkList.o -o templateLinkList

templateLinkList.o: templateLinkList.cpp
	$(CC) $(CFLAGS) templateLinkList.cpp -o templateLinkList.o
 
clean: 
	rm -f *.o templateLinkList


