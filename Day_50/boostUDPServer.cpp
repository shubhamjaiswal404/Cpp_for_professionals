#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<string.h>

#include<boost/asio.hpp>
#include"boostUDPServer.h"


using boost::asio::ip::udp;

using namespace std;

int main(int argc, char* argv[])
{
    if(argc != 2 )
    {
        std::cerr << " Usage : udp_server <port>\n ";
        return 1;
    }
    try
    {
        // 1) instantiate io_service
        // 2) make a customerized server
        // 3) start io_service
        
        
        boost::asio::io_service io_service;
        myUdpServer mySer(io_service, std::atoi(argv[1]));
        io_service.run();
        
        
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception  : " << e.what() << "\n";
    }
    
    return 0;
}
