#include "mysquare.h"

mySquare::mySquare()
{
    side = 0;
}

void mySquare::setSide(int i)
{
    side = i;
}

int mySquare::getArea()
{
    return side * side;
}
