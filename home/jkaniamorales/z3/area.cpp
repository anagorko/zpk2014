#include<iostream>
#include<math.h>
using namespace std;

#include "point.cpp"

double area(Point a, Point b, Point c)
{
    double bokab, bokbc, bokca;
    bokab=sqrt((a.getX()-b.getX())*(a.getX()-b.getX())+(a.getY()-b.getY())*(a.getY()-b.getY())+(a.getZ()-b.getZ())*(a.getZ()-b.getZ()));
    bokbc=sqrt((b.getX()-c.getX())*(b.getX()-c.getX())+(b.getY()-c.getY())*(b.getY()-c.getY())+(b.getZ()-c.getZ())*(b.getZ()-c.getZ()));
    bokca=sqrt((c.getX()-a.getX())*(c.getX()-a.getX())+(c.getY()-a.getY())*(c.getY()-a.getY())+(c.getZ()-a.getZ())*(c.getZ()-a.getZ()));
    double p=(bokab+bokbc+bokca)*0.5;
    return sqrt(p*(p-bokab)*(p-bokbc)*(p-bokca));
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
