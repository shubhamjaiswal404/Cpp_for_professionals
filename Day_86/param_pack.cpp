// Parameter pack after c++11
#include <iostream>
#include <string>
#include <tuple>


template<typename... Targs>
void param_pack_func(Targs... Fargs)
{
/*
    const int length = sizeof...(Targs);
    std::cout << "Tot. args: " << length << std::endl;
    int res[length] = {Fargs...};

    float myAvg = 0.0;
    for( int i = 0; i < length; i++)
    {
        myAvg += res[i];
        std::cout << res[i] << ", ";
    }
    std::cout << std::endl;
    myAvg = myAvg / length;
    std::cout << "Average is : " << myAvg << std::endl;
*/

    const int length = sizeof...(Targs);
    std::cout << "Tot. args: " << length << std::endl; 
    std::string res[length] = {Fargs...};

    for( int i = 0; i < length; i++)
    {
        std::cout << res[i] << ", ";
    }
    std::cout << std::endl;


}



void avg_func(int n1,int n2 ,int n3)
{
    float myAvg = (n1 + n2)/2;
    std::cout << "Average is : "<< myAvg << std::endl;
}

using namespace std;

int main()
{
/*    
    std::cout << "param_pack_func(10,20,40)" << std::endl;
    param_pack_func(10,20,40);

    std::cout << "param_pack_func(10,20,40,50)" << std::endl;
    param_pack_func(10,20,40,50);
*/  

    
    std::cout << "param_pack_func(\"hello\", \"World\", \"I am\", \"here\")" << std::endl;
    param_pack_func("hello","World","I am","here");

    std::cout << "param_pack_func(\"hello\",\"World\")" << std::endl;
    param_pack_func("hello","World");
    

    return 0;
}













