area.cpp

#include<iostream>
#include<math.h>
using namespace std;

#include "point.h"

double area_under(Point a, Point b, Point c)

{
    double e, f, g, p, S;

        e = sqrt(pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY(), 2) + pow(a.getZ() - b.getZ(), 2));
        f = sqrt(pow(b.getX() - c.getX(), 2) + pow(b.getY() - c.getY(), 2) + pow(b.getZ() - c.getZ(), 2));
        g = sqrt(pow(a.getX() - c.getX(), 2) + pow(a.getY() - c.getY(), 2) + pow(a.getZ() - c.getZ(), 2));


    p = (e + f + g)/2.0;
    S = sqrt(p*(p-e)*(p-f)*(p-g));

    return S;
}


int main()
{
    Point A;
    Point B;
    Point C;

    cout << "Podaj wspolrzedne punktu : ";

    cin >> A;
    cout << endl;

    cin >> B;
    cout << endl;

    cin >> C;
    cout << endl;

    cout << "Punkty: " << A << " " << B << " " << C << endl;
    cout << "Pole: " << area_under(A, B, C) << endl;

    return 0;
}

