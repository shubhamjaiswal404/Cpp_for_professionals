#include <iostream>
#include<stdlib.h>
#include<iomanip>
#include<mysql/jdbc.h>

/*
 * // Older version need all and New version only need one header file which contains conbination of all
 * #include<mysql_connect.h>
 * #include<driver.h>
 * #include<exception.h>
 * #include<resultset.h>
 * #include<statement.h>
 */

using namespace sql;

int main()
{
    std::cout<< " C++ connect mysql test example \n ";

    std::cout << "Start C++ connect mysql test example \n";
    try{
        // Do Something connect to mysql
        sql::Driver     *myDriver;
        sql::Connection *myConn;
        sql::Statement  *myStmt;
        sql::ResultSet  *myRes;

        myDriver = get_driver_instance();
        myConn = myDriver->connect("tcp://127.0.0.1:3306","cppuser","cpp_pass");
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
    catch(sql::SQLException &e)
    {
        std::cout<<" Failed Connect to mySql database test "<<std::endl;
        std::cout<<" Error : "<< e.what() << std::endl;
        std::cout<<" Error Code : "<<e.getErrorCode() <<std::endl;

    }
    return 0;
}

