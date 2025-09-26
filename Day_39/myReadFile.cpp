#include <iostream>
#include <chrono>
#include <fstream>
#include <pthread.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(int argc, char *argv[])
{
    std::string line;
    int i;
    
    if(argc !=2 )
    {
        std::cout << " Usage : myReadFile <file-name> " << std::endl;
        return 1;
        
    }
    
    ifstream myFile(argv[1]);
    
    if(myFile.is_open())
    {
        i=0;
        while(getline(myFile,line))
        {
            i++;
            if(i == 1 || i== 20000)
            {
                std::cout << line <<std::endl;
            }
        }
        std::cout << line <<std::endl;
        myFile.close();
    }
    else{
        std::cout << " can not open file example.txt for reading  " << std::endl;
    }
    
    return 0;
}

