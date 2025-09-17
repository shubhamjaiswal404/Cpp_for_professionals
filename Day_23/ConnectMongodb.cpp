#include <cstdint>
#include <vector>
#include <iostream>
#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/exception/exception.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>


using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_document;


int main() {
    try {
        mongocxx::instance instance;

        mongocxx::uri uri("mongodb://localhost:27017");
        mongocxx::client client(uri);

        auto database = client["MongoDB_Enterprise"];
        auto collection = database["players"];
	auto cursor = collection.find({});

	for(auto&& doc : cursor) 
	{
		std::cout << bsoncxx::to_json(doc) << std::endl<<std::endl;
	}

    } catch (const mongocxx::exception& e) {
        std::cout << "An exception occurred: " << e.what() << "\n";
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}



