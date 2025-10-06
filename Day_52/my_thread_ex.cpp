#include <iostream> //std::cout, std::ios
#include<thread>    // std::thread
#include<future>    // std::async , std::future
#include<exception> // std::exception

int myFunction(int tid)
{
    int totLoop = 0;
    for(int j = 0; j <= 10000 ; j++)
    {
        totLoop++;

        if((j%5000) == 0)
        {
            std::cout << "Thread Num : " << tid << " As Loop Number : " << j << std::endl;
        }
    }
    return totLoop;
}

//using namespace std;

int main()
{

/*

    int ret = 0;
    for( int i=0 ; i<5 ; i++)
    {
        ret = myFunction(i);
    }
    return ret;
*/


/*
    int ret = 0;
    std::thread mTh[5];

    for( int i=0 ; i<5 ; i++)
    {
        mTh[i] = std::thread(myFunction,i);
    }
    for( int i=0 ; i<5 ; i++)
    {
        mTh[i].join();
    }

    return ret;
*/

      
    int ret = 0;

    std::future<int> mTh[5];
    for( int i=0 ; i<5 ; i++)
    {
        mTh[i] = std::async(myFunction,i);
    }
    for( int i=0 ; i<5 ; i++)
    {
        ret = mTh[i].get();
    }

    return ret;

}
