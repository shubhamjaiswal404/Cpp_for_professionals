#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include"postgresql/libpq-fe.h"


int main(int argc, char*argv[])
{
	const char *conninfo;
	PGconn     *conn;

	// step 1: setup to setting connect string ,defualt: dbname=postgres
	
	conninfo ="dbname =postgres";
    
//	conninfo = "host=192.168.29.151 port=5432 dbname=postgres user=shubham  password=JAISWAL444";

	//step2: Make a connection to the database 
	
	conn = PQconnectdb(conninfo);

	if(PQstatus(conn)!= CONNECTION_OK)
	{
		printf("connection to database failed:%s",PQerrorMessage(conn));
		PQfinish(conn);
		exit(1);
	}

	std::cout << "HostPost:" << PQport(conn) << std::endl;
	std::cout << "ServPath:" << PQhost(conn) << std::endl;
	std::cout << "Database:" << PQdb(conn) << std::endl;
	std::cout << "LoginiD:"  << PQuser(conn) << std::endl;
    	std::cout << "ProcPID:"  << PQbackendPID(conn) << std::endl;

	int ver =PQserverVersion((const PGconn*)conn);
	int verMajor = int (ver/10000);
	int verMinor =(ver%10000);

	std::cout<<"Version:"<<verMajor<<":"<<verMinor<<std::endl;

	//close the connection to the database and cleanup
	PQfinish(conn);
	return 0;
}

// std::cout<<"Options:"<<PQoptions(conn)<<std::endl;
// std::cout<<"HostAddr:"<<PQhostaddr(conn)<<std::endl;

