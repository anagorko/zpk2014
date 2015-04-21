#include<iostream>
#include<math.h>
using namespace std;

#include "point.h"

double area(Point a, Point b, Point c)
{
    double ab_length, ac_length, bc_length, p;

    ab_length = sqrt((a.getX()-b.getX())*(a.getX()-b.getX())+(a.getY()-b.getY())*(a.getY()-b.getY())
                     +(a.getZ()-b.getZ())*(a.getZ()-b.getZ()));
    ac_length = sqrt((a.getX()-c.getX())*(a.getX()-c.getX())+(a.getY()-c.getY())*(a.getY()-c.getY())
                     +(a.getZ()-c.getZ())*(a.getZ()-c.getZ()));
    bc_length = sqrt((b.getX()-c.getX())*(b.getX()-c.getX())+(b.getY()-c.getY())*(b.getY()-c.getY())
                     +(b.getZ()-c.getZ())*(b.getZ()-c.getZ()));
    p = (ab_length + ac_length + bc_length) * 0.5;
    return sqrt(p*(p-ab_length)*(p-ac_length)*(p-bc_length));
}

int main()
{
    Point p;
    Point q;
    Point r;

    cout << "Podaj wspolrzedne punktu p: ";
    cin >> p;
    cout << "Podaj wspolrzedne punktu q: ";
    cin >> q;
    cout << "Podaj wspolrzedne punktu r: ";
    cin >> r;
    cout << "Punkty: " << p << " " << q << " " << r << endl;
    cout << "Pole: " << area(p,q,r) << endl;

    return 0;
}
