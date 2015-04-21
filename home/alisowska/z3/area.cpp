#include<iostream>
#include<math.h>
using namespace std;

#include "point.h"


double area(Point a, Point b, Point c)
{
    double AB, AC, BC, p;
    AB=sqrt((b.getX()-a.getX())*(b.getX()-a.getX())+(b.getY()-a.getY())*(b.getY()-a.getY())+(b.getZ()-a.getZ())*(b.getZ()-a.getZ()));
    AC=sqrt((c.getX()-a.getX())*(c.getX()-a.getX())+(c.getY()-a.getY())*(c.getY()-a.getY())+(c.getZ()-a.getZ())*(c.getZ()-a.getZ()));
    BC=sqrt((c.getX()-b.getX())*(c.getX()-b.getX())+(c.getY()-b.getY())*(c.getY()-b.getY())+(c.getZ()-b.getZ())*(c.getZ()-b.getZ()));
    p=(AB+AC+BC)/2;
    return sqrt(p*(p-AB)*(p-AC)*(p-BC));
}

int main()
{
    Point A;
    Point B;
    Point C;

    cout << "Podaj wspolrzedne punktow A, B, C: " << endl;
    cin >> A;
    cout << endl;
    cin >> B;
    cout << endl;
    cin >> C;
    cout << endl;
    cout << "Punkty: " << A << " " << B << " " << C << endl;
    cout << "Pole: " << area(A,B,C) << endl;
    return 0;
}
