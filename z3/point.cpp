#include "point.h"

Point::Point()
{
    setX(0.0);
    setY(0.0);
}

Point::Point(double _x, double _y)
{
    setX(_x);
    setY(_y);
}

Point::~Point()
{
}

void Point::setX(double _x)
{
    x = _x;
}

void Point::setY(double _y)
{
    y = _y;
}

double Point::getX()
{
    return x;
}

double Point::getY()
{
    return y;
}


ostream& operator<<(ostream &o, Point p)
{
    o << "(" << p.getX() << "," << p.getY() << ")";
    
    return o;
}

