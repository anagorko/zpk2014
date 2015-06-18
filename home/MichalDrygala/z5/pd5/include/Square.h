#ifndef SQUARE_H
#define SQUARE_H

#include "Figure.h"
#include "Point.h"

using namespace std;
#include <iostream>
#include <math.h>
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Square : public Figure
{
    Point a, b, c, d;

    virtual ostream& output(ostream& os) const
    {  return os << "[" << a << ";" << b << ";" << c << ";" << d << "]";  }

public:

// konstruktor
    Square(Point p, double x);

 //tutejsze wersje funkcji virtual z klasy Figure
    virtual double area();
    virtual Figure* scale(double k);
    virtual Figure* translate(double dx, double dy);
    virtual Figure* rotate(double alpha);
};

#endif // SQUARE_H
