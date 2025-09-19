#include <stdlib.h>
#include <iostream>
#include <jdbc/mysql_connection.h>

#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>

using namespace std;
using namespace sql;

int main( )
{
	std::cout << " Start C++ connect mysql test example  \n";
	try 
	{
	sql::Driver     *myDriver;
        sql::Connection *myConn;
        sql::Statement  *myStmt;
        sql::ResultSet  *myRes;

	myDriver = get_driver_instance();
        myConn = myDriver->connect("tcp://127.0.0.1:3306","root","Database-password");
       
  	myConn->setSchema("Testing_DB");

   	myStmt = myConn->createStatement();
   	myRes =myStmt->executeQuery("SELECT ' Hello World' AS _message" );

        while (myRes->next()) {
            std::cout<< myRes->getString("_message") <<std::endl;
        }

	delete myRes;
        delete myStmt;
        delete myConn;


        std::cout<< " C++ sucessfully connected to mysql database \n";

	}
        catch (sql::SQLException &e) 
	{
  	std::cout<<" Failed Connect to mySql database test "<<std::endl;
        std::cout<<" Error : "<< e.what() << std::endl;
        std::cout<<" Error Code : "<<e.getErrorCode() <<std::endl;
	}



	return 0;


}






