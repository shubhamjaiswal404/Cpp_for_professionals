#include<iostream>
#include<string>
#include<vector>
#include<chrono>
using namespace std;

class myData
{
private:
        std::string*    pData;
public:
        
        myData(const std::string& inStr)
        {
                pData = new std::string(inStr);
//              std::cout << "Class myData constructor 1 : create " << pData << " " << *pData << std::endl;
        }

        
        myData(const myData& inObj)
        {
                pData = new std::string(*inObj.pData);
//                std::cout << "Class myData constructor 2 : copy " << pData << " " << *pData << std::endl;
        }

        
        myData(myData&& inObj)
        {
                pData = inObj.pData;
                inObj.pData = nullptr ;
//                std::cout << "Class myData constructor 3 : moving " << pData << " " << *pData << std::endl;
        }

        ~myData()
        {
                delete pData;
        }
};

int main()
{

        std::vector<myData> mVec;   
        typedef std::chrono::high_resolution_clock Clock;
        typedef std::chrono::milliseconds millisecond;

        Clock::time_point tStart = std::chrono::high_resolution_clock::now();
        for( int i = 0; i< 10000 ; i++)
        {
                mVec.push_back(myData("Hello World I am saving to vecctor "));

        }
        Clock::time_point tEnd = std::chrono::high_resolution_clock::now();
        std::chrono::milliseconds execTime = std::chrono::duration_cast<millisecond>(tEnd - tStart);
        cout << " With Move Running time " << execTime.count() << " ms " <<endl;


        return 0;
}


