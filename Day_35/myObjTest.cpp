#include <iostream>
#include"mysquare.h"
#include"mytriangle.h"

using namespace std;

int main()
{
    mySquare mySqre;

    mySqre.setSide(2.0);

    myTriangle myTri;
    myTri.setBaseHeight(2.0,3.0);

    std::cout << "My Square area of (2.0) is  : " << mySqre.getArea() << std::endl;
    std::cout << "My Triangle area of (2.0 ,3.0) is  : " << myTri.getArea() << std::endl;

    return 0;
}
