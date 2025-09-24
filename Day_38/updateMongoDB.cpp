#include<bsoncxx/builder/basic/array.hpp>
#include<bsoncxx/builder/basic/document.hpp>
#include<bsoncxx/builder/basic/kvp.hpp>
#include<mongocxx/client.hpp>
#include<mongocxx/instance.hpp>
#include<mongocxx/uri.hpp>
#include <iostream>

using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_array;
using bsoncxx::builder::basic::make_document;



//using namespace std;

int main()
{
    mongocxx::instance inst{};
    mongocxx::uri    myURI("mongodb://localhost:27017");
    mongocxx::client conn{myURI};
    mongocxx::collection myColl = conn["MongoDB_Enterprise"]["players"];
    {
        myColl.update_one(
            make_document(kvp("gender" , "Female")),
            make_document(kvp("$set" , make_document(kvp("level" , "Intermedia")))
                          ));    
    }
     
    return 0;
}

