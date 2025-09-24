#include "mytriangle.h"

myTriangle::myTriangle()
{
    base = 0;
    height = 0;
}

void myTriangle::setBaseHeight(int i , int j)
{
    base = i;
    height = j;
}

int myTriangle::getArea()
{
    return (0.5)*base * height;
}

