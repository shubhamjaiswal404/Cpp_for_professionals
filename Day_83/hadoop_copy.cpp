#include <iostream>
#include <stdio.h>
#include <string.h>

#include <hdfs.h>

/**
 * hdfsCopy - Copy file from one filesystem to another.
 * @param srcFS The handle to source filesystem
 * @param src The path of source file
 * @param dstFS The handle to destination filesystem.
 * @param dst The path of destination file
 * @return Return 0 on success, -1 on error
 * LIBHDFS_EXTERNAL
 * int hdfsCopy(hdfsFS srcFS, const char* src, hdfsFS dstFS, const char* dst);
 */

int main(int argc , char **argv)
{
    int rc = 0;
    if(argc != 3)
    {
        std::cout << " Usage : " << argv[0] << " <local file> <HDFS path> " << std::endl;
        return 1;
    }

    hdfsFS fs = hdfsConnect("localhost",9000);
    if(!fs)
    {
        fprintf(stderr, "Failed to connect %s \n", "localhost:9000");
        exit(-1);
    }

    hdfsFS lfs = hdfsConnect(NULL,0);
    if(!lfs)
    {
        fprintf(stderr,"Failed to open %s for reading! \n", argv[1]);
        exit(-1);
    }

    rc = hdfsCopy(lfs,argv[1],fs,argv[2]);
    if(rc != 0)
    {
        fprintf(stderr,"Failed to copy file %s to %s \n" , argv[1] , argv[2]);
        exit(-1);
    }

    hdfsDisconnect(lfs);
    hdfsDisconnect(fs);

    return 0;

}

