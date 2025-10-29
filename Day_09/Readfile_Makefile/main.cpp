#include <iostream>
#include <fstream>
#include<pthread.h>
#include<stdio.h>
#include<string.h>

using namespace std;

int main(int argc, char* argv[])
{
    std::string line;
    int i;
    if( argc !=2 )
    {
        std::cout << "Usage: myReadFile <fileName>"<<std::endl;
        return 1;
    }
    ifstream mFile(argv[1]);
    if(mFile.is_open())
    {
        i=0;
        while(getline(mFile,line))
        {
            i++;
            if(i==1 || i== 20)
                std::cout<<line <<std::endl;
        }
        mFile.close();
    }
    return 0;
}
