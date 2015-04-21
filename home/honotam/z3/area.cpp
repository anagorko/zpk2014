#include<iostream>
#include<math.h>
using namespace std;

#include "point.h"

double pole(Point d, Point e, Point f)
{
    //definiujemy zmienne (jak we wzorze Herona)
    double p, a, b, c;

    // kolejno obliczamy d�ugo�ci odcink�w |AB|, |BC| i |CA|

    // w 2D
    // Je�li mamy dane dwa punkty A(xa , ya ) i B(xb , yb ) to d�ugo�� odcinka |AB| jest dana wzorem
    // d = sqrt[ (xb-xa)^2 + (yb-ya)^2 ]

    // w 3D obliczone poni�ej

    // funckcja pow, z math.h - podnoszenie liczby do dowolnej pot�gi
    // double pow( double podstawa, double potega )
    a = sqrt(pow(e.getX() - f.getX(), 2) + pow(e.getY() - f.getY(), 2) + pow(e.getZ() - f.getZ(), 2));
    b = sqrt(pow(d.getX() - f.getX(), 2) + pow(d.getY() - f.getY(), 2) + pow(d.getZ() - f.getZ(), 2));
    c = sqrt(pow(d.getX() - e.getX(), 2) + pow(d.getY() - e.getY(), 2) + pow(d.getZ() - e.getZ(), 2));

    //wz�r na p ze wzoru Herona (p jest po�ow� obwodu tr�jk�ta)
    p = (a + b + c)/2;

    //zwracamy pole obliczone stosuj�c wz�r Herona
    return sqrt(p * (p - a) * (p - b) * (p - c));
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
    cout << "Pole: " << pole(A, B, C) << endl;

    return 0;
}
