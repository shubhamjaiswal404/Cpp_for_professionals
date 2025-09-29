#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<zlib.h>

using namespace std;

int main(int argc , char* argv[])
{
	size_t wIdx = 0;
	struct gzFile_s *myGzFile;

	if( argc != 2)
	{
	     std::cout << " Usage : read_gzip [in gz File] " << std::endl;
	     exit(1);
	}
 
	myGzFile = gzopen(argv[1] , "rb");
	if(!myGzFile)
	{
	     std::cout << " Failed to open gz file : " << argv[1] << std::endl;
	     exit(1);
	}	

	if( gzbuffer(myGzFile, 8192))
	{
	     std::cout << " Failed of buffering false : " << argv[1] << std::endl;
	     exit(1);
	}

	// get length of  file : 
	unsigned char *pInData = new unsigned char[8192];
	memset(pInData,'\0' ,sizeof(*pInData));
	while(!gzeof(myGzFile))
	{
	    wIdx = gzread(myGzFile, voidp(pInData) , 8192);
	    std::cout << pInData << std::endl;
	}
	std::cout << " Total Byte Unzipped : " << wIdx << std::endl;
	gzclose(myGzFile);


	exit(0);
}
