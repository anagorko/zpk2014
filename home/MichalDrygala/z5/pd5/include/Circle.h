#ifndef CIRCLE_H
#define CIRCLE_H

#include "Figure.h"
#include "Point.h"

using namespace std;
#include <iostream>
#include <math.h>
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Circle : public Figure
{
    Point a;
    double r;

    virtual ostream& output(ostream& os) const
    {  return os << "S" << a << ", r = " << r ;  }

public:

// konstruktor
    Circle(Point p, double x);

 //tutejsze wersje funkcji virtual z klasy Figure
    virtual double area();
    virtual Figure* scale(double k);
    virtual Figure* translate(double dx, double dy);
    virtual Figure* rotate(double alpha);
};

#endif // CIRCLE_H
