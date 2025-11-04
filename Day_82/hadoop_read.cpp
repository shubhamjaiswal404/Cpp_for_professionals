#include <iostream>
#include <stdio.h>
#include <string.h>

#include <hdfs.h>

/*
 *overview
 *libhdfs is a JNI based C API for Hadoop's Distributed File System (HDFS).
 *It provides C APIs to a subset of the HDFS APIs to manipulate HDFS file and the filesystem.
 *libhdfs is part of the Hadoop distribution and comes pre-compiled in
 *${HADOOP_HOME}/libhdfs/libhdfs.so .
 *
 *https://hadoop.apache.org/doc/r1.2.1/libhdfs.html#How+To+Link+With+The+Library
 *
 *gcc above_sample.c -I${HADOOP_HOME}/src/c++/libhdfs -L${HADOOP_HOME}/libhdfs -o above_sample
 *hdfsFS fs = hdfsConnect("default",0);
 */

#define MAX_BUFFER_SIZE 1024

int main(int argc , char* argv[] )
{
    if( argc != 2)
    {
        std::cout << "Usage : " << argv[0] << "<HDFS path (file name)>" <<std::endl;
        return 1;
    }

    tSize readByte = 0;
    char buffer[MAX_BUFFER_SIZE];
    memset(buffer,'\0',MAX_BUFFER_SIZE);

    hdfsFS fs = hdfsConnect("localhost", 9000);
    if(!fs)
    {
        std::cout << " failed of connection to HDFS " << std::endl;
        exit(1);
    }

    hdfsFile readFile = hdfsOpenFile(fs, argv[1], O_RDONLY,0,0,0);
    if(!readFile)
    {
        std::cout << "failed of opening HDFS file : " << argv[1] << std::endl;
        exit(1);
    }

    readByte = hdfsRead(fs, readFile, (void*)buffer, MAX_BUFFER_SIZE);
    while( readByte > 0)
    {
        std::cout << buffer;
        memset(buffer,'\0',MAX_BUFFER_SIZE);
        readByte = hdfsRead(fs, readFile,(void*)buffer,MAX_BUFFER_SIZE);
    }
    std::cout << std::endl;

    hdfsCloseFile(fs, readFile);
    hdfsDisconnect(fs);

    return 0;
}


























