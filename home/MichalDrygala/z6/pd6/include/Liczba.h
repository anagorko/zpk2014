#ifndef LICZBA_H
#define LICZBA_H

#include<iostream>
using namespace std;

#include "ElementStosu.h"

class Liczba : public ElementStosu
{
    int l;

    virtual void output(ostream& os) {  os << l;  }

public:

//konstruktory
    Liczba(int l) {  set(l);  }
    Liczba() : Liczba(0) {}

//destruktor
    ~Liczba() {}

//funkcje
    int get() { return l; }
    void set(int _l) { l = _l; }
};

#endif // LICZBA_H
