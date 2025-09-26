#include <iostream>
#include<list>
#include"iteratorContainer.h"


using namespace std;

int main()
{
    myList<std::string>::iterator   it;
    myList<std::string> myList;

    myList.push_back("This is my List Object 1 ");
    myList.push_back("This is my List Object 2 ");
    myList.push_back("This is my List Object 3 ");
    myList.push_back("This is my List Object 4 ");
    myList.push_back("This is my List Object 5 ");
    myList.displayList();

    std::cout << "------------------------------" << std::endl;
    std::cout << "myList size is : " << myList.size() <<std::endl;
    std::cout << "myList last  Node is : " << myList.lastNode().getValue() <<std::endl;
    std::cout << "myList first Node is : " << myList.firstNode().getValue() <<std::endl;
    std::cout << "------------------------------" << std::endl;


/*
    it = myList.begin();
    std::cout << "Dereference is begin() : " << *it << std::endl;
    it++;
    std::cout << "Dereference is it++ :  " << *it << std::endl;
*/


    std::cout << "------------------------------" << std::endl;
    for(it = myList.begin(); it!= myList.end() ; it++)
    {
        std::cout << *it << std::endl;
    }

    return 0;
}


