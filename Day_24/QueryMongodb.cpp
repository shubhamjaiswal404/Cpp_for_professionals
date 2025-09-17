#include <cstdint>
#include <vector>
#include<string>
#include <iostream>
#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/exception/exception.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>


using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_document;


int main( int argc , char* argv[] )
{
    try {
        mongocxx::instance instance;

        mongocxx::uri uri("mongodb://localhost:27017");
        mongocxx::client client(uri);

        auto database = client["MongoDB_Enterprise"];
        auto collection = database["players"];
       
	bsoncxx::document::value course = make_document( kvp("gender",argv[1]));
        auto cursor = collection.find(course.view());


        for(auto&& doc : cursor)
        {	
		 bsoncxx::document::element    myName = doc["name"];
                 bsoncxx::document::element    myGender = doc["gender"]; 
  
//                std::cout << bsoncxx::to_json(doc) << std::endl<<std::endl ;    // 1 output 
	     
		std::string	strName = std::string(myName.get_string().value);    // 2 output
		std::string	strGender = std::string(myGender.get_string().value); // 2 output

		std::cout << "Player :: name : " << strName << "     gender : " << strGender << std::endl;

        }

    } catch (const mongocxx::exception& e) {
        std::cout << "An exception occurred: " << e.what() << "\n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
























