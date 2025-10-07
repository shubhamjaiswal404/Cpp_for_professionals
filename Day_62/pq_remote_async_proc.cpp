#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <array>
#include <string>
#include <string.h>
#include <sstream>

#include "postgresql/libpq-fe.h"

#include <libssh/libsshpp.hpp>
#include <libssh/libssh.h>

// std::string strCONN ="host =192.168.29.151 post =5432 user = hyuan  dbname=YHDB password=DBpassword";
//

int main(int argc,char *argv[])
{
    const char  *conninfo;
    PGconn      *conn;
    PGresult    *res;
        
    int totCols = 0;
    int totRows = 0;
    int nLoop = 0;
    int i,j,rc;

    char mPass[20];
    char sCONN[256];
    std::stringstream ss;


    std::array<int,5> wCol ={4,15,18,8,12};
    std::string mySQL = "SELECT id,name,membership,gender,level from players;"; 
	
	memset(mPass,'\0',sizeof(mPass));

//	memset(sCONN,'\0',sizeof(sCONN)+1);
	memset(sCONN,'\0',sizeof(sCONN));
	if(argc != 5)
    	{
		std::cout << "Usage : pq_async_proc <host> <port> <user> <database>"<<std::endl;
		exit(-1);
	}

	ss<<"hostaddr="<<argv[1]<<" ";
	ss<<"port="<<argv[2]<<" ";
	ss<<"user="<<argv[3]<<" ";
	ss<<"dbname="<<argv[4]<<" ";
	ss<<"password=";

	rc=ssh_getpass("password:",mPass,sizeof(mPass),0,0);

	if(rc==0)
    {
		ss<<mPass;
	}

	memcpy(sCONN,ss.str().c_str(),ss.str().length());

	conninfo = sCONN;


    //conninfo ="dbname = YHDB";

    /*Make a connection to the database */

    conn =PQconnectdb(conninfo);
    std::cout << std::endl;
    if(PQstatus(conn) == CONNECTION_BAD)
    {
        printf("Connection to database failed:%s",PQerrorMessage(conn));
        PQfinish(conn);
        exit(1);
    }


/*
 * Step1 :Submits a command to the server without waiting for the result(s)
 * Return 1 Success,0 Failed
 */

    if(PQsendQuery(conn,mySQL.c_str()) == 0)
    {
        printf("Send query Failed:%s",PQerrorMessage(conn));
        PQfinish(conn);
        exit(1);
    }

    PQsetSingleRowMode(conn);

    /*Step2:get result*/
	res=PQgetResult(conn);
    while(res != nullptr)
    {
        totCols =PQnfields(res); //->Total Columns each row
        totRows =PQntuples(res); //->Total Rows retrieved

        if(nLoop == 0)
        {
            std::cout<<"+----+---------------+------------------+--------+------------+"<<std::endl;
            std::cout<<"|";
            for(j=0;j<totCols;j++)
            {
                std::cout<<std::setfill(' ')<<std::setw(wCol[j])<<std::left<<PQfname(res,j)<<"|";
            }
            std::cout<<std::endl;
            std::cout<<"+----+---------------+------------------+--------+------------+"<<std::endl;
        }


        for(i=0;i<totRows;i++)
        {
            std::cout<<"|";
            for(j=0;j<totCols;j++)
            {
               std::cout<<std::setfill(' ')<<std::setw(wCol[j])<<std::left<<PQgetvalue(res,i, j)<<"|";
            }
            std::cout<<std::endl;
        }
        
        PQclear(res);
		nLoop++;
		res =PQgetResult(conn);
        
    }


        std::cout<<"+----+---------------+------------------+--------+------------+"<<std::endl;

        std::cout<<"Total Rows Retrieved :"<<totRows<<" ";
        std::cout<<"Total Column of rows :"<<totCols<<std::endl;
        std::cout<<"Total Loops :"<<nLoop<<std::endl;

        PQclear(res);

        /*close the connection to the database and cleanup */
        PQfinish(conn);

        return 0;

        }


