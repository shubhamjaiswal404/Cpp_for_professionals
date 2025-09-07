#ifndef MYSQUARE_H
#define MYSQUARE_H

class mySquare
{
public:
    mySquare();
    mySquare(int);
    mySquare(float) = delete;
    void setSide(int i);
    int getArea();
private:
    int side ;

};

#endif // MYSQUARE_H
