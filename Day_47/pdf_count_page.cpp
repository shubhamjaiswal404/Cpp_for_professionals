#include <iostream>
#include<fstream>
#include<string.h>
#include<cstring>


#define BUFFER_SIZE 1024

using namespace std;

int main(int argc, char* argv[])
{
    int pgCount = 0;
    // int totPage = 0;
    // bool pTree = false;
    int i, j;

    char inBuf[BUFFER_SIZE];     // Read bytes from file to memory
    char workBuf[BUFFER_SIZE];   // Parse kine to working buffer for process
    char tmpBuf[20];

 //   PageTreeNode pTreeNode;

    if( argc !=2)
    {
        std::cout<< " Usage : pdf_count_page [in PDF File] " << std::endl;
        exit(1);
    }

    ifstream inFile(argv[1] , ios::in | ios::binary);

    if(!inFile.is_open())
    {
        std::cout << "Failed to open file : " << argv[1] << std::endl;
        exit(1);
    }

    j = 0;
    pgCount = 0;
    //memset(workBuf,'\0' ,BUFFER_SIZE+1);

    memset(workBuf,'\0',BUFFER_SIZE);

    while(!inFile.eof())
    {
       // memset(inBuf, '\0' ,BUFFER_SIZE+1);

        memset(inBuf, '\0' ,BUFFER_SIZE);
        inFile.read(reinterpret_cast<char*>(inBuf),BUFFER_SIZE);

        for( i=0 ; i<(int)sizeof(inBuf) ; i++)
        {
            // loop byte by byte to workBuff till 0x0A
            char mChar = inBuf[i];
            int mInt = int(mChar);

            if(mChar == 0x0A || j== (BUFFER_SIZE - 1))
            {
                /*
                 * 1) process worfBuf
                 * 2) counting how many Page Objects (/Type./Page)
                 */
                if(j >=11)
                {
                 //   memset(tmpBuf,'\0',sizeof(tmpBuf) + 1);
			
		    memset(tmpBuf,'\0',sizeof(tmpBuf)) ;

                    memcpy(tmpBuf,&workBuf[j-11],11);
                    if(memcmp(tmpBuf,"/Type./Page",11) == 0 )
                    {
                        // page leafe count + 1
                        pgCount++;
                    }
                }

                j = 0;
                memset(workBuf,'\0',BUFFER_SIZE);
            }
            else{
                if(mInt> 32 && mInt<=127)
                {
                    workBuf[j] = mChar;

                }
                else{
                    workBuf[j] = '.';
                }
                j++;
	    }
        }
    }

    inFile.close();
    std::cout << std::endl << " ********************************** " << std::endl;
    std::cout << "	Total pages : " << pgCount << std::endl;
    std::cout <<" ********************************** " << std::endl;
    exit(0);

}

