#include<iostream>
#include<math.h>
using namespace std;
#include "point.h"

double Pole(Point x, Point y, Point z){
    double a, b, c, p, Pol;
    a = sqrt(pow(x.getX() - y.getX(), 2) + pow(x.getY() - y.getY(), 2) + pow(x.getZ() - y.getZ(), 2));
    b = sqrt(pow(x.getX() - z.getX(), 2) + pow(x.getY() - z.getY(), 2) + pow(x.getZ() - z.getZ(), 2));
    c = sqrt(pow(y.getX() - z.getX(), 2) + pow(y.getY() - z.getY(), 2) + pow(y.getZ() - z.getZ(), 2));
    p = (a + b + c) / 2;
    Pol = sqrt(p * (p - a) * (p - b) * (p - c));
    return Pol;
}

int main(){
    Point x1;
    Point x2;
    Point x3;
    cout << "Prosze podac wspolrzedne punktu x1" << endl;
    cin >> x1;
    cout << "Prosze podac wspolrzedne punktu x2" << endl;
    cin >> x2;
    cout << "Prosze podac wspolrzedne punktu x3" << endl;
    cin >> x3;
    cout << " " << endl;
    cout << "Wybrane punkty to: " << endl;
    cout << " " << endl;
    cout <<  x1 << endl;
    cout <<  x2 << endl;
    cout <<  x3 << endl;
    cout << " " << endl;
    cout << "A pole wynosi : " << Pole(x1,x2,x3) << endl;
    return 0;
}
