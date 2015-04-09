#include<iostream>
#include<math.h>
using namespace std;

#include "point.h"

double odcinek(Point a, Point b)
{
    return ((a.getX()-b.getX)^2 + a.getY()-b.getY)^2 + a.getZ()-b.getZ)^2)^(0.5);
}

double pole(Point a, Point b, Point c)
{
    p = (odcinek(a,b) + odcinek(b,c) + odcinek(a,c))/2;

    return (p * (p - odcinek(a,b)) * (p - odcinek(b,c)) * (p - odcinek(a,c)))^(0.5);
}

istream& operator>>(istream& 1, Point &p) // sluzy do wpisania wsp punktu
{
    double t;
    i >> t; p.setX(t);
    i >> t; p.setY(t);
    i >> t; p.setZ(t);
}

int main()
{
    Point p;
    Point q(2.0, 2.0, 2.0);
    Point r(0.0, 3.0, 1.0);

    cout << "Podaj wspolrzedne punktu p: ";
    cin >> p;

    cout << "Punkty: " << p << " " << q << " " << r << endl;
    cout << "Pole: " << pole(p,q,r) << endl;
    return 0;
}
