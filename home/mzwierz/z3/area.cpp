#include<iostream>
#include<math.h>
using namespace std;

#include "point.h"

double bok(Point a, Point b)
{
    return sqrt(pow(a.getX()-b.getX(),2) + pow(a.getY()-b.getY(),2) + pow(a.getZ()-b.getZ(),2));
}

double area(Point a, Point b, Point c)
{
   double _a = bok(a, b);
    double _b = bok(a, c);
    double _c = bok(c, b);
    double p = (_a + _b + _c) / 2;
    return sqrt(p*(p-_a))*(p-_b)*(p-_c));
}

int main()
{
    Point p, q, r;

    cout << "Podaj wspolrzedne pkt. p (wg wzoru: p.x p.y p.z): ";
    cin >> p;

    cout << "Podaj wspolrzedne pkt. q (wg wzoru: q.x q.y q.z): ";
    cin >> q;

    cout << "Podaj wspolrzedne pkt. r (wg wzoru: r.x r.y r.z): ";
    cin >> r;



    cout << "Punkty: " << p << " " << q << " " << r << endl;
    cout << "Pole: " << area(p,q,r) << endl;

    return 0;
}
