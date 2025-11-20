#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/asio.hpp>

using namespace std;
using boost::asio::ip::tcp;

std::string func_daytime_string()
{
    time_t now = time(0);
    return ctime(&now);
}

int main(int argc , char* argv[])
{
    try
    {
        if(argc != 3)
        {
            std::cerr << "Usage : " << argv[0] << " <host:port> <File Name> " <<std::endl;
            return 1;
        }

        std::vector<std::string> sVec;
        split(sVec, argv[1],boost::is_any_of(":"));

        std::string line;
        tcp::iostream mStream(sVec[0] , sVec[1]);
        if(!mStream)
        {
            std::cout << "Unable to connect: " << mStream.error().message() << std::endl;
            return 1;
        }

        ifstream myFile(argv[2]);
        if(myFile.is_open())
        {
            while( std::getline(myFile, line))
            {
                mStream << line << std::endl;
            }
            myFile.close();
            mStream.close();
        }
    }
    catch(std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

























