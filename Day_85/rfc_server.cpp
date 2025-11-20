#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
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
        if(argc != 2 )
        {
            std::cerr << "Usage : " << argv[0] << " <port> " << std::endl;
            return 1;
        }

        boost::asio::io_context io_context;

        tcp::endpoint endpoint(tcp::v4() , std::atoi(argv[1]));
        tcp::acceptor acceptor(io_context, endpoint);
        std::string fileName = "my_test.txt";
        std::string line;

        for(;;)
        {
            tcp::iostream myStream;
            boost::system::error_code ec;
            acceptor.accept(myStream.socket(), ec);

            if(!ec)
            {
                ofstream myFile(fileName);
                if( myFile.is_open())
                {
                    for(;;)
                    {
                        std::getline(myStream,line);
                        if(myStream.basic_iostream::eof())
                        {
                            break;
                        }
                        myFile << line << std::endl;
                    }
                    myFile.flush();
                    myFile.close();
                    std::cout << " Receiving completed and writtem to " << fileName << std::endl;
                }
            }
        }

    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }


    return 0;
}
