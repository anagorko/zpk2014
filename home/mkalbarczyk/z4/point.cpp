#include "point.h"
#include <cassert>

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

double Point::getX() const
{
    return x;
}

double Point::getY() const
{
    return y;
}

double Point::getZ() const
{
    return z;
}

ostream& operator<<(ostream &o, const Point p)
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

Point& Point::operator+=(const Point& p)
{
    setX(getX() + p.getX());
    setY(getY() + p.getY());
    setZ(getZ() + p.getZ());

    return *this;
}

Point& Point::operator-=(const Point& p)
{
    setX(getX() - p.getX());
    setY(getY() - p.getY());
    setZ(getZ() - p.getZ());

    return *this;
}

    
double Point::norm() const
{
    return sqrt(getX() * getX() + getY() * getY() + getZ() * getZ());
}

    
void Point::normalize()
{
    assert (norm() != 0);
    
    double n = 1 / norm();
    
    setX(n * getX());
    setY(n * getY());
    setZ(n * getZ());
}

Point operator+(const Point &p1, const Point &p2)
{
    Point p(p1);    
    p += p2;
    return p;
}

Point operator-(const Point &p1, const Point &p2)
{
    Point p(p1);
    p -= p2;
    return p;
}

double operator*(const Point &p1, const Point &p2)
{
    return p1.getX() * p2.getX() + p1.getY() * p2.getY() + p1.getZ() * p2.getZ();
}

Point operator*(const Point &p, double d)
{
    Point r(p);
    r.setX(d * r.getX());
    r.setY(d * r.getY());
    r.setZ(d * r.getZ());
    
    return r;
}

Point operator*(double d, const Point& p)
{
    return p * d;
}

