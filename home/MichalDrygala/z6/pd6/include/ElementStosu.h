#ifndef ELEMENTSTOSU_H
#define ELEMENTSTOSU_H

#include <iostream>
using namespace std;

/*
 * Obiekty klas implementuj¹cych interfejs ElementStosu mo¿na
 * przechowywaæ w ni¿ej okreœlonej strukturze Stos.
 */

class ElementStosu
{
//wypisywanie
    virtual void output(ostream&) = 0;

public:

//destruktor
    virtual ~ElementStosu() = 0;

//operatory
    friend ostream& operator<<(ostream& os, ElementStosu& el);
};

#endif // ELEMENTSTOSU_H
