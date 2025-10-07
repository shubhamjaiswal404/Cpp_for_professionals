#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<array>
#include<stdlib.h>

#include"postgresql/libpq-fe.h"


int main(int argc, char*argv[])
{
        const char  *conninfo;
        PGconn      *conn;
        PGresult    *res;
        
        int i,j;

        std::array<int,5>wCol={4,15,18,8,12};

        // step 1: setup to setting connect string ,defualt: dbname=postgres

        //conninfo ="dbname =YHDB";
	//conninfo = "host=192.168.29.151 port=5432 dbname=postgres user=shubham password=JAISWAL444";
	
	conninfo = "dbname=yhdb user=postgres password=JAISWAL444";

        //step2: Make a connection to the database 

        conn =PQconnectdb(conninfo);

        if(PQstatus(conn) == CONNECTION_BAD)
        {
            printf("connection to database failed:%s",PQerrorMessage(conn));
            PQfinish(conn);
            exit(1);
        }
        //step1::Start a transaction block
	 
        res =PQexec(conn,"BEGIN");

        if(PQresultStatus(res) != PGRES_COMMAND_OK)
        {
            printf("BEGIN command failed:%s",PQerrorMessage(conn));
            PQclear(res);
            PQfinish(conn);
            exit(1);
        }

        /* Do PQclear PGresult whenever it is no longer needed to avoid memory leaks*/

        PQclear(res);

        /*Step2: Declare quary CURSOR of database*/
        res=PQexec(conn,"DECLARE myCURSOR CURSOR FOR \
                    select id ,name ,membership,gender,level from players;");

        if(PQresultStatus(res) != PGRES_COMMAND_OK)
        {
            printf("DECLARE CURSOR failed :%s",PQerrorMessage(conn));
            PQclear(res);
            PQfinish(conn);
            exit(1);
        }
        PQclear(res);
        
	/*  Step3:: Fetch quaring of CURSOR*/
	res=PQexec(conn,"FETCH ALL in myCURSOR");

	if(PQresultStatus(res) != PGRES_TUPLES_OK)
	{
		printf("FETCH ALL failed :%s",PQerrorMessage(conn));
		PQclear(res);
		PQfinish(conn);
		exit(1);
	}

	/*first get total rows and total column each row */

	int totCols = PQnfields(res);   //--> Total columns each row 
	int totRows = PQntuples(res);   //--> Total Rows retrieved

	/*First , print out the column header names*/

	std::cout<<"+----+---------------+------------------+--------+------------+"<<std::endl;
	std::cout<<"|";


	for(j=0;j<totCols;j++)
	{
	    //int nSize = PQfsize(res,i);
	    std::cout << std::setfill(' ') << std::setw(wCol[j]) << std::left << PQfname(res,j) << "|";
	}

	std::cout << std::endl;

	std::cout << "+----+---------------+------------------+--------+------------+" << std::endl;

	/*next ,print out the retrived value of rows */
	for(i=0;i<totRows;i++)
    	{

          std::cout << "|";
          for(j=0;j< totCols; j++)
          { 
            //int nSize =PQfsize(res,j);   
            std::cout<<std::setfill(' ')<<std::setw(wCol[j])<<std::left<<PQgetvalue(res,i,j)<<"|";   
          }
		std::cout<<std::endl;
	}
	
	
	std::cout<<"+----+---------------+------------------+--------+------------+"<<std::endl;
	std::cout<<"Total Rows Retrieved :"<<totRows<<" ";
	std::cout<<"Total Column of rows :"<<totCols<<std::endl;

	PQclear(res);

	/*Close the portal  ... we don't bother to check for error ...*/

	res =PQexec(conn,"CLOSE myCURSOR");
	PQclear(res);

	/*end the transaction */
	res =PQexec(conn,"END");
	PQclear(res);

	/*close the connection to the database and cleanup */
	PQfinish(conn);

	return 0;

}
