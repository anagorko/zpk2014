#include "point.h"

Point::Point()
{
    setX(0.0);
    setY(0.0);
    setZ(0.0);
}

Point::Point(double _x, double _y, double _z)
{
    setX(_x);
    setY(_y);
    setZ(_z);
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

void Point::setZ(double _z)
{
    z = _z;
}

double Point::getX()
{
    return x;
}

double Point::getY()
{
    return y;
}

double Point::getZ()
{
    return z;
}

ostream& operator<<(ostream &o, Point p)
{

    o << "(" << p.getX() << "," << p.getY() << "," << p.getZ() << ")";

    return o;
}

istream& operator>>(istream &i, Point &p)
{
    i >> p.x;
    i >> p.y;
    i >> p.z;

    return i;
}
