#include "mysquare.h"

mySquare::mySquare() : side(0) {} // one liner for default constructor

mySquare::mySquare(int i) : side(i) {}


void mySquare::setSide(int i)
{
    side = i;
}

int mySquare::getArea()
{
    return side * side;
}
