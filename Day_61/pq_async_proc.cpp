#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
#include<array>
#include<string>

#include"postgresql/libpq-fe.h"

int main(int argc,char *argv[])
{
	const char   *conninfo;
	PGconn       *conn;
	PGresult     *res;
    
	int totCols = 0;
	int totRows = 0;
	int nLoop = 0;
	int i,j;

	std::array<int,5> wCol ={4,15,18,8,12};
	std::string mySQL = "SELECT id,name,membership,gender,level from players;";

    	//conninfo ="dbname =yhdb";
	conninfo = "dbname=yhdb user=postgres password=DBpassword";

	/*Make a connection to the database */

	conn =PQconnectdb(conninfo);
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

	 //PQsetSingleRowMode(conn); //Important

	/*Step2:get result*/

	while((res = PQgetResult(conn)) != nullptr)
	{
	   totCols =PQnfields(res); //->Total Columns each row
	   totRows =PQntuples(res); //->Total Rows retrieved
				    //
	   if(nLoop == 0)
	   {
		
               std::cout<< "+----+---------------+------------------+--------+------------+" << std::endl;
               std::cout<<"|";
	       for(j=0;j<totCols;j++)
	       {
	           std::cout<<std::setfill(' ')<<std::setw(wCol[j])<<std::left<<PQfname(res,j)<<"|";
	       }
	       std::cout<<std::endl;
               std::cout<<"+----+---------------+------------------+--------+------------+"<<std::endl;
	  }

	  nLoop++;
	  for(i=0;i<totRows;i++)
	  {
	      std::cout<<"|";
	      for(j=0;j<totCols;j++)
	      {
		  std::cout<<std::setfill(' ')<<std::setw(wCol[j])<<std::left<<PQgetvalue(res,i,j)<<"|";
	      }
	      std::cout<<std::endl;
	  }
	  PQclear(res);

	}


	std::cout<<"+----+---------------+------------------+--------+------------+"<<std::endl;

        std::cout<<"Total Rows Retrieved :"<<totRows<<" ";
        std::cout<<"Total Column of rows :"<<totCols<<" ";
        std::cout<<"Total Loop : " << nLoop << std::endl;
        
        PQclear(res);
        
        /*close the connection to the database and cleanup */
        PQfinish(conn);

        return 0;

}
