#include <iostream>
#include<list>
#include"templateLinkList.h"

using namespace std;

int main()
{

// Without Template 

/*

    std::list<std::string> myList;
    myList.push_back("This is Std::list Object 1");
    myList.push_back("This is Std::list Object 2");
    myList.push_back("This is Std::list Object 3");
    myList.push_back("This is Std::list Object 4");
    myList.push_back("This is Std::list Object 5");

    for( auto it=myList.rbegin(); it!= myList.rend() ; it++)
    {
        std::cout<< *it << std::endl;
    }

    std::cout << "------------------------------------" << std::endl;
    std::cout << "myList size is : " << myList.size() << std::endl;
    std::cout << "------------------------------------" << std::endl;

    myList.pop_back();
    myList.pop_back();

    for(auto it=myList.rbegin() ; it!= myList.rend() ; it++)
    {
        std::cout << *it << std::endl;
    }
    std::cout << "------------------------------" << std::endl;
    std::cout << "myList size is : " << myList.size() <<std::endl;
    std::cout << "------------------------------------" << std::endl;
*/

// With Template 

    myList<std::string> myList;
    myList.push_back("This is my List Object 1 ");
    myList.push_back("This is my List Object 2 ");
    myList.push_back("This is my List Object 3 ");
    myList.push_back("This is my List Object 4 ");
    myList.push_back("This is my List Object 5 ");
    myList.displayList();

    std::cout << "------------------------------" << std::endl;
    std::cout << "myList size is : " << myList.size() <<std::endl;
    std::cout << "------------------------------" << std::endl;

    myList.pop_back();
    myList.pop_back();
    myList.displayList();

    std::cout << "------------------------------" << std::endl;
    std::cout << "myList size is : " << myList.size() <<std::endl;
    std::cout << "------------------------------" << std::endl;




    return 0;
}

