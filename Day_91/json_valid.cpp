#include <iostream>
#include <iomanip>
#include <fstream>

#include "json_valid.h"

#include <boost/json.hpp>
#include <boost/json/basic_parser_impl.hpp>


using namespace std;
using namespace boost::json;

/*
 * Streaming Parser
 *
 * A DOM parser for JSON contained in multiple buffer. The stream_parser implements a
 * streaming algorithm; it allows incremental processing of large JSON inputs
 *
 * To use the stream_parser , declare an instance Then call write zero or more times with
 * successive buffers representing the input JSON. When there are no more buffers , call finish.
 * The function done returns true after a successful call to write or finish if parsing is complete
 */

int main(int argc, char* argv[])
{

    if(argc != 2)
    {
        std::cerr << "Usage : json_vaild <filename> "<< std::endl;
        return EXIT_FAILURE;
    }


    bool result;

    {
        result = json_stream_parse(argv[1]);
        if(result)
        {
            std::cerr << " JSON File : " << argv[1] << " <- Validation Success \n";
        }
        else
        {
            std::cerr << "JSON File : " << argv[1] << " <- Validation Not Success\n";
        }
    }

    return EXIT_SUCCESS;
}
