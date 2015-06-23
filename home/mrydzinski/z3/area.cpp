#include<iostream>
#include<math.h>
using namespace std;

#include "point.h"

double area(Point e, Point f, Point g)
{
    double a, b, c, d;
    a = sqrt(pow(f.getX() - g.getX(), 2) + pow(f.getY() - g.getY(), 2) + pow(f.getZ() - g.getZ(), 2));
    b = sqrt(pow(e.getX() - g.getX(), 2) + pow(e.getY() - g.getY(), 2) + pow(e.getZ() - g.getZ(), 2));
    c = sqrt(pow(e.getX() - f.getX(), 2) + pow(e.getY() - f.getY(), 2) + pow(e.getZ() - f.getZ(), 2));
    d = (a+b+c)/2;

    return sqrt(d*(d-a)*(d-b)*(d-c));
}
int main()
{
    Point X;
    Point Y;
    Point Z;

    cout << "Podaj wspolrzedne punktu X: ";
    cin >> X;
    cout << "Podaj wspolrzedne punktu Y: ";
    cin >> Y;
    cout << "Podaj wspolrzedne punktu Z: ";
    cin >> Z;

    cout << endl << "Współrzędne: " << A << " " << B << " " << C << endl;
    cout << "Pole: " << area(X, Y, Z) << endl;

    return 0;
}
