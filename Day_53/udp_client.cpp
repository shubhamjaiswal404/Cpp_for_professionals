#include <iostream>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

// step 1 : Create the socket
// step 2 : Identify the socket (name it)
// step 3 : On the client , send a message
// step 4 : On the client , receive a message back from server
// step 5 : Close the socket


int main(int argc , char* argv[])
{
    int sockfd;
    if( argc != 3)
    {
        std::cout << "Usage : udp_client [server port ] [Message] " << std::endl;
        exit(-1);
    }

    char bufferSend[256];
    char bufferRecv[256];
    memset(bufferSend,'\0',sizeof(bufferSend)); // sizeof(bufferSend)+1
    memset(bufferRecv,'\0',sizeof(bufferRecv)); // sizeof(bufferSend)+1
    memcpy(bufferSend,argv[2],strlen(argv[2]));

    // step 1 : Create the socket
    // int sockfd = socket(AF_INET, SOCK_DGRAM,0);
    if((sockfd = socket(AF_INET,SOCK_DGRAM,0)) < 0)
    {
        std::cout << " cannot create socket " <<std::endl;
        exit(-1);
    }

    // step 2 : Identify the socket (name it)
    struct sockaddr_in servAddr,cliAddr;
    socklen_t cLen = sizeof(cliAddr);
    socklen_t sLen = sizeof(servAddr);

    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(std::stoi(argv[1]));
    servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // step 3 : On the client , send a message
    ssize_t sByte = sendto(sockfd,bufferSend,sizeof(bufferSend),0,(struct sockaddr *)&servAddr, sLen);
    std::cout << "[" << sByte << "] Bytes Sent : " << std::endl;

    // step 4 : On the client , receive a message back from server
    ssize_t rByte = recvfrom(sockfd, bufferRecv, sizeof(bufferRecv) ,0 ,(struct sockaddr*)&cliAddr , &cLen );
    std::cout << "[" <<rByte <<"] Bytes Rcvd : " << bufferRecv << std::endl;

    // step 5 : Close the socket
    close(sockfd);

    exit(0);


}
