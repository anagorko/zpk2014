#ifndef STOS_H
#define STOS_H

#include<iostream>
using namespace std;

#include "ElementStosu.h"

/* Obiekty klasy Stos mog¹ przechowywaæ dowolne obiekty implementuj¹ce interfejs ElementStosu. */

class Stos
{
    struct Link
    {
        ElementStosu    *dane;
        Link            *poprzedni;
    };

    Link* wierzcholek;

public:

// konstruktor
    Stos() {  wierzcholek = NULL;  }

//destruktor
    ~Stos();

// funkcje
    void push(ElementStosu* el);
    ElementStosu* pop();
    bool empty();
    int size();

//operator
    friend ostream& operator << (ostream&, Stos &);
};

#endif // STOS_H
