#include <iostream>
#include <stdio.h>
#include <string.h>

#include <hdfs.h>

#define MAX_BUFFER_SIZE 1024

using namespace std;

int main(int argc, char **argv)
{
    if(argc != 3)
    {
        std::cout << "Usage : " << argv[0] <<" <local file> <HDFS path> " << std::endl;
        return 1;
    }

    tSize readByte = 0;
    char buffer[MAX_BUFFER_SIZE];
    memset(buffer,'\0',MAX_BUFFER_SIZE);

    hdfsFS fs = hdfsConnect("localhost", 9000);
    if(!fs)
    {
        fprintf(stderr,"Failed to connect %s \n" , "localhost:9000");
        exit(-1);
    }

    hdfsFile writeFile = hdfsOpenFile(fs,argv[2],O_WRONLY|O_CREAT,0,0,0);
    if(!writeFile)
    {
        fprintf(stderr,"Failed to open %s for writing!\n", argv[2]);
        exit(-1);
    }

    hdfsFS lfs = hdfsConnect(NULL,0);
    hdfsFile readFile = hdfsOpenFile(lfs,argv[1],O_RDONLY,0,0,0);
    if(!readFile)
    {
        fprintf(stderr,"Failed to open %s for reading !\n", argv[1]);
        exit(-1);
    }

    readByte =hdfsRead(lfs,readFile,(void*)buffer, MAX_BUFFER_SIZE);
    while( readByte > 0 )
    {
        hdfsWrite(fs, writeFile, (void*)buffer, readByte );
        if(hdfsFlush(fs,writeFile))
        {
            fprintf(stderr,"Failed to 'flush' %s\n ", argv[2]);
            hdfsCloseFile(lfs,readFile);
            hdfsCloseFile(fs,writeFile);
            hdfsDisconnect(lfs);
            hdfsDisconnect(fs);
            exit(-1);
        }
        memset(buffer,'\0', MAX_BUFFER_SIZE);
        readByte = hdfsRead(lfs, readFile, (void*)buffer , MAX_BUFFER_SIZE);
    }

    hdfsCloseFile(lfs, readFile);
    hdfsFlush(fs, writeFile);
    hdfsCloseFile(fs,writeFile);
    hdfsDisconnect(lfs);
    hdfsDisconnect(fs);

    return 0;
}


















