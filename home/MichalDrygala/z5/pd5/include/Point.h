#ifndef POINT_H
#define POINT_H

#include "Figure.h"

using namespace std;
#include <iostream>
#include <math.h>
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Point : public Figure
{
    double x, y;

    virtual ostream& output(ostream& os) const
    {
        return os << "(" <<  x << "," << y << ")";
    }

public:
//konstruktory
    Point() : Point(0.0, 0.0) {}

    Point(double _x, double _y);

//dostêp do skladnikow prywatnych
    double getX() const     { return x; }
    double getY() const     { return y; }

 //tutejsze wersje funkcji virtual z klasy Figure
    virtual double area()   {  return 0;  }

    virtual Figure* scale(double k);
    virtual Figure* translate(double dx, double dy);
    virtual Figure* rotate(double alpha);

// funkcje wlasne klasy Point
    double distanceTo(Point p);
};

#endif // POINT_H
