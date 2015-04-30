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

Point& Point::operator+=(const Point& p)
{
    setX(getX() + p.getX());
    setY(getY() + p.getY());
    setZ(getZ() + p.getZ());
    return *this;
}

Point& Point::operator-=(const Point& p){
    setX(getX() - p.getX());
    setY(getY() - p.getY());
    setZ(getZ() - p.getZ());
    return *this;
}


double Point::norm() const{
    return sqrt( pow(getX(), 2) + pow(getY(), 2) + pow(getZ(), 2) );
}

void Point::normalize(){
    double length=norm();
    setX(getX()/length);
    setY(getY()/length);
    setZ(getZ()/length);
}

/*koniec czêœci pierwszej*/

Point operator+(const Point &p1, const Point &p2){
    Point result;
    result.setX(p1.getX()+p2.getX());
    result.setY(p1.getY()+p2.getY());
    result.setZ(p1.getZ()+p2.getZ());
    return result;
}

Point operator-(const Point &p1, const Point &p2){
    Point result;
    result.setX(p1.getX()-p2.getX());
    result.setY(p1.getY()-p2.getY());
    result.setZ(p1.getZ()-p2.getZ());
    return result;
}

double operator*(const Point &p1, const Point &p2){
    double result;
    result = p1.getX()*p2.getX() + p1.getY()*p2.getY() + p1.getZ()*p2.getZ();
    return result;
}

Point operator*(const Point &p, double d){
    Point result;
    result.setX(p.getX()*d);
    result.setY(p.getY()*d);
    result.setZ(p.getZ()*d);
    return result;
}

Point operator*(double d, const Point& p){
    Point result;
    result = p*d;
    return result;
}












