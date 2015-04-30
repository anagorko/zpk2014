#ifndef POINT_H
#define POINT_H

#include<iostream>
#include<math.h>
using namespace std;

class Point
{
    double x, y;

public:
    Point();
    Point(double, double);

    ~Point();

    void setX(double);
    void setY(double);

    double getX();
    double getY();

};

ostream& operator<<(ostream &, Point);

#endif
