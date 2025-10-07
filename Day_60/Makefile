CC=g++
CFLAGS=-c -Wall -g -I/usr/include/postgresql
LDFLAGS=-lm -L/usr/lib/x86_64-linux-gnu -lpq


all:pq_select_ex

pq_select_ex:pq_select_ex.o
	$(CC) pq_select_ex.o $(LDFLAGS) -o pq_select_ex -std=c++11
pq_select_ex.o: pq_select_ex.cpp
	$(CC) $(CFLAGS) pq_select_ex.cpp -o pq_select_ex.o
run:
	./pq_select_ex
clean:
	rm -f *.o pq_select_ex

#Note 1 :: To see log of postgresql 
#....> sudo tail -n 20 /var/log/postgresql/postgresql-*.log

#Note 2 :: edit in pg_hba.conf  which is located /etc/postgresql/16/main/pg_hba.conf
#....> cd etc/postgresql/16/main/
#....> sudo vi pg_hba.conf
#....> sudo systemctl restart postgresql
