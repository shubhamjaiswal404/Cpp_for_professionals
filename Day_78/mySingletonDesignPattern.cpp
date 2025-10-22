#include <iostream>
#include <fstream>
#include <chrono>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <future>
#include <mutex>
#include "singletonfile.h"


using namespace std;
#define MAX_THREADS   8
std::mutex mtx;

SingletonFile* SingletonFile::instance = nullptr;
ifstream* SingletonFile::pFile = nullptr;

int SigletonReadFile(int t_id)
{
    std::string line;
    SingletonFile *tsf = SingletonFile::getInstance();

    for(int i= 0; i< 2500 ; i++)
    {
        mtx.lock();
        line = tsf->ReadLine();
        std::cout << line << "-> Thread : " << t_id <<" loop : "<< i << std::endl;
        mtx.unlock();

    }
    return 0;
}


int main(int argc , char* argv[])
{
    int j , ret = 0;
    std::future<int> rc[MAX_THREADS];

    if( argc != 2)
    {
        std::cout << " Usage : myThreadReadFile <file-name> " << std::endl;
        return 1;
    }

    SingletonFile *sf = SingletonFile::getInstance();
    sf->OpenFile(argv[1]);
    if( !sf->Ready())
    {
        std::cout << "Failed Open File " << argv[1] << std::endl;
        exit(1);
    }

    try{
        for(j=0 ; j< MAX_THREADS;  j++) {
          
            rc[j] = std::async(SigletonReadFile,j);
        }

        for( j= 0 ; j < MAX_THREADS;j++)
        {
            ret = rc[j].get();
        }
    }
    catch(std::exception &ec)
    {
        std::cout << "[Exception] " << ec.what() << std::endl;
    }
    return ret;

}













