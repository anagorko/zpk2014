#include<iostream>
#include<math.h>
using namespace std;
#include "point.h"
double area_under(Point a, Point b)
{
return (b.getX() - a.getX()) * (a.getY() + b.getY()) / 2.0;
}
double area(Point a, Point b, Point c)
{
return fabs(area_under(a,b) + area_under(b,c) + area_under(c,a));
}
double pole(Point a, Point b, Point c){
    double AB, BC, AC, p;
AB=sqrt(pow(sqrt(pow(b.getX()- a.getX(),2)+pow(b.getZ()-a.getZ(),2)),2)+pow(b.getY()- a.getY(),2));
BC=sqrt(pow(sqrt(pow(b.getX()- c.getX(),2)+pow(b.getZ()-c.getZ(),2)),2)+pow(b.getY()- c.getY(),2));
AC=sqrt(pow(sqrt(pow(a.getX()- c.getX(),2)+pow(a.getZ()-c.getZ(),2)),2)+pow(a.getY()- c.getY(),2));
p=(AB+BC+AC)/2;
return sqrt(p * (p - AB) * (p - BC) * (p - AC));
}
int main()
{
Point p(0.0, 0.0, 0.0);
Point q(2.0, 0.0, 0.0);
Point r(0.0, 10.0, 10.0);


cout << "Punkty: " << p << " " << q << " " << r << endl;
cout << "Pole: " << pole(p,q,r) << endl;
return 0;
}
