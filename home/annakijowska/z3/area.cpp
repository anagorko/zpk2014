#include<iostream>
#include<math.h>
using namespace std;

#include "point.h"

double odcinek(Point a, Point b)
{
    return sqrt((a.getX() - b.getX()) * (a.getX() - b.getX()) + (a.getY() - b.getY()) * (a.getY() - b.getY()) + (a.getZ() - b.getZ()) * (a.getZ() - b.getZ()));
}

double area(Point a, Point b, Point c)
{
    double p;
    p=(odcinek(a,b)+odcinek(a,c)+odcinek(b,c))/2;

    return sqrt(p*(p-odcinek(a,b))*(p-odcinek(a,c))*(p-odcinek(b,c)));
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
