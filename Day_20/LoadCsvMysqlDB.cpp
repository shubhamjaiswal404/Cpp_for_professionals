#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>

#include <jdbc/mysql_connection.h>
#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>

using namespace std;
using namespace sql;

sql::SQLString csvSplit(std::string inStr)
{
    std::stringstream myStream(inStr);
    sql::SQLString mySQL;
    std::string myStr;

    mySQL = " ";
    mySQL.append("INSERT INTO players(name,membership,gender,level,create_date) VALUES(");
    int i =0 ;
    while(i<4)
    {
       i++;
       myStr.clear();
       getline(myStream,myStr,',');
       mySQL.append("'" + myStr + " ' ," );
    }
    mySQL.append("now());");

    std::cout<< mySQL << std::endl;

    return mySQL;
}


int main(int argc , char* argv[] )
{
     std::string  line;

     std::vector<sql::SQLString> myVec;

     std::ifstream myFile(argv[1]);

     if(myFile.is_open())
     {
	while(getline(myFile,line ))
	{
	    // split line read from file and build insert statement 
	    // save to myVector
	    myVec.push_back(csvSplit(line));

	}
	myFile.close();

     }	
     else
     {
	std::cout << " can not open file for readong " << std::endl;
	return -1;
     }
   
     try
     {
	std::cout << " C++ Load CSV connect to  mysql  \n";
        sql::Driver     *myDriver;
        sql::Connection *myConn;
        sql::Statement  *myStmt;
  

        myDriver = get_driver_instance();
        myConn = myDriver->connect("tcp://127.0.0.1:3306","root","Database-password");

        myConn->setSchema("Testing_DB");

        myStmt = myConn->createStatement();

	for( auto it = myVec.begin(); it!=myVec.end() ;it++)
	{
	     myStmt->execute(*it);

	}
    
        delete myStmt;
        delete myConn;

     }
     catch (sql::SQLException &e)
     {
        std::cout<<" Failed Connect to mySql database test "<<std::endl;
        std::cout<<" Error : "<< e.what() << std::endl;
        std::cout<<" Error Code : "<<e.getErrorCode() <<std::endl;
     }
	
	std::cout<< " End Load CSV file to mysql example  \n";

        return 0;

}


