#ifndef __POINT_H__
#define __POINT_H__

#include<iostream>
#include<math.h>
using namespace std;

class Point
{
    double x, y, z;

public:
    Point();
    Point(double, double, double);

    ~Point();

    void setX(double);
    void setY(double);
    void setZ(double);

    double getX() const;
    double getY() const;
    double getZ() const;

    friend istream& operator>>(istream&, Point&);

    Point& operator+=(const Point& p);
    Point& operator-=(const Point& p);
    
    double norm() const;
    
    void normalize();
};

Point operator+(const Point &p1, const Point &p2);
Point operator-(const Point &p1, const Point &p2);
double operator*(const Point &p1, const Point &p2);

Point operator*(const Point &p, double d);
Point operator*(double d, const Point& p);

ostream& operator<<(ostream &, const Point);
istream& operator>>(istream &, Point&);

#endif
