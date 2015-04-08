#include<iostream>
#include<math.h>
#include "point.h"
using namespace std;

double area(Point i, Point j, Point k)
{
    double a, b, c, p;
    a = sqrt(pow(j.getX() - k.getX(), 2) + pow(j.getY() - k.getY(), 2) + pow(j.getZ() - k.getZ(), 2));
    b = sqrt(pow(i.getX() - k.getX(), 2) + pow(i.getY() - k.getY(), 2) + pow(i.getZ() - k.getZ(), 2));
    c = sqrt(pow(i.getX() - j.getX(), 2) + pow(i.getY() - j.getY(), 2) + pow(i.getZ() - j.getZ(), 2));
    p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main()
{
    Point A, B, C;
    cout << "Podaj wspolrzedne punktu A: ";
    cin >> A;
    cout << "Podaj wspolrzedne punktu B: ";
    cin >> B;
    cout << "Podaj wspolrzedne punktu C: ";
    cin >> C;
    cout << endl << "Podales nastepujace wspolrzedne: " << A << " " << B << " " << C << endl;
    cout << "Pole trojkata wynosi: " << area(A, B, C) << endl;
    return 0;
}
