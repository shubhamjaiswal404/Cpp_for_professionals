#include <iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<string>
#define BUFFER_SIZE 1024

using namespace std;

int main(int argc , char* argv[])
{
    int i,j;

    char inBuf[BUFFER_SIZE];
    char workBuf[BUFFER_SIZE];

    if( argc != 3 )
    {
        std::cout << " Usage : pdf_dump [in PDF File] [out Text File] " << std::endl;
        exit(1);
    }

    ifstream inFile(argv[1] , ios::in | ios::binary );
    if (!inFile.is_open())
    {
        std::cout << " Failed to open reading file : " << argv[1] <<std::endl;
        exit(1);
    }

    ofstream outFile(argv[2] , ios::out);
    if(!outFile.is_open())
    {
        std::cout << " Failed to open writing file : " << argv[2] << std::endl;
        exit(1);
    }

    j = 0;

    memset(workBuf,'\0',sizeof(workBuf) );

  //  memset(workBuf,'\0',sizeof(workBuf)+1 );   // Doubt  

    while(!inFile.eof())
    {
        memset(inBuf, '\0' ,sizeof(inBuf));

//	memset(inBuf, '\0' ,sizeof(inBuf)+1);   // Doubt  
        inFile.read(reinterpret_cast<char*>(inBuf), sizeof(inBuf));

        // 1) loop inBuf byte by byte
        // 2) if printable byte , move byte to workBuf
        // 3) if not printable byte, convert '.' to workBuf
        // 4) if 0x0A byte or workBuf full , write workBuf to outFile
        for( i= 0 ; i<(int) sizeof(inBuf) ; i++)
        {
            char mChar = inBuf[i];
            int mInt =int(mChar);
            if(mChar == 0x0A || j== BUFFER_SIZE)
            {
                outFile.write(workBuf,j);
                outFile.write("\n",1);

                j=0;
                memset(workBuf,'\0',BUFFER_SIZE);
            }
            else{
                if(mInt > 32 && mInt <= 127)
                {
                    workBuf[j] = mChar;
                }
                else{
                    workBuf[j]='.';
                }

                j++;
            }
        }


    } // last while loop line
    inFile.close();
    outFile.close();
    exit(0);

 
}
