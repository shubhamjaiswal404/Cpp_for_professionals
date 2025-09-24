#include <iostream>
#include"nodebase.h"

using namespace std;

int main()
{
//    cout << "Hello World!" << endl;
/*

    NodeBase myObj("This is Object One ");
    NodeBase myObj2("This is Object Two ");
    myObj.displayNodeBase();
    myObj2.displayNodeBase();
*/

    Node myObj("This is Object One ");
    Node myObj2("This is Object Two ");
    myObj.setLink(&myObj2);
    myObj.displayNode();
    myObj.getLinkNode()->displayNode();


   return 0;
}
