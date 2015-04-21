#include<iostream>
#include<math.h>
using namespace std;

#include "point.h"

double area(Point i, Point j, Point k)
{
    double a, b, c, s;

    a = sqrt(pow(j.getX() - k.getX(), 2) + pow(j.getY() - k.getY(), 2) + pow(j.getZ() - k.getZ(), 2));
    b = sqrt(pow(i.getX() - k.getX(), 2) + pow(i.getY() - k.getY(), 2) + pow(i.getZ() - k.getZ(), 2));
    c = sqrt(pow(i.getX() - j.getX(), 2) + pow(i.getY() - j.getY(), 2) + pow(i.getZ() - j.getZ(), 2));

    s = (a + b + c) / 2;

    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main()
{
    Point A;
    Point B;
    Point C;

    cout << "Podaj wspolrzedne punktu A: ";
    cin >> A;

    cout << "Podaj wspolrzedne punktu B: ";
    cin >> B;

    cout << "Podaj wspolrzedne punktu C: ";
    cin >> C;

    cout << endl << "Punkty: " << A << " " << B << " " << C << endl;
    cout << "Pole: " << area(A, B, C) << endl;

    return 0;
}
