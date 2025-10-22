#include "singletonfile.h"

SingletonFile::SingletonFile() {
}

SingletonFile* SingletonFile::getInstance()
{
    if( instance == nullptr)
    {
        instance = new SingletonFile();
    }
    return instance;
}

bool SingletonFile::Ready()
{
    if(pFile && pFile->is_open())
    {
        return true;
    }
    return false;
}

void SingletonFile::OpenFile(std::string fileName)
{
    if(pFile == nullptr)
    {
        pFile = new std::ifstream(fileName);
    }
    if(!pFile->is_open())
    {
        pFile->open(fileName,std::ios::in);
    }
}

std::string SingletonFile::ReadLine()
{
    std::string rtn;
    getline(*pFile, rtn);
    return rtn;
}

SingletonFile::~SingletonFile()
{
    if( pFile != nullptr)
    {
        if(pFile != nullptr)
        {
            pFile->close();
        }
        delete pFile;
    }
}



























