#include<iostream>
using namespace std;

#include "vect.h"

int main()
{    
    Vect u(4, { 0, 1, 1, 1 }), v(4, { 1, 0, 1, 1 }), w(4, { 1, 1, 0, 1 } ), z(4, { 1, 1, 1, 0 });
    Vect a(4), b(4), c(4), d(4);
        
    a = u; 
    a.normalize();
    
    b = v - (v * a) * a;
    b.normalize();
    
    c = w - (w * a) * a - (w * b) * b;
    c.normalize();

    d = z - (z * a) * a - (z * b) * b - (z * c) * c;
    d.normalize();
    
    cout << endl << "Układ po ortogonalizacji." << endl << endl;
    
    cout << "a = " << a << endl;    
    cout << "b = " << b << endl;    
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
    
    return 0;
}
