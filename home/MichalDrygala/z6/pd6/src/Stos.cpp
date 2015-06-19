#include "Stos.h"

//destruktor
Stos::~Stos()
 {
    while (wierzcholek != NULL)
    {
        delete pop();
    }
}

//funkcje
void Stos::push(ElementStosu* el)
    {
        Link *nowy = new Link;

        nowy -> poprzedni = wierzcholek;
        nowy -> dane = el;

        wierzcholek = nowy;
    }

ElementStosu* Stos::pop()
     {
        if (wierzcholek == NULL) return NULL;

        ElementStosu* wynik = wierzcholek -> dane; //'wynik' zaczyna byc wskaznikiem na ElemntStosu i wskazuje na to samo na co wskazuje 'dane'
                                                   //ten wskaznik 'dane' przypisany do obiektu na ktory wskazuje wierzcholek
        Link* poprzedni = wierzcholek -> poprzedni; // 'poprzedni' zaczyna byc wskaznikiem na Link i wskazuje na to samo na co wskazuje 'poprzedni'
                                                    // ten 'poprzedni' przypisany do obiektu na ktory wskazywal wierzcholek
        delete wierzcholek;
        wierzcholek = poprzedni;

        return wynik; //zwracamy wskaznik na ElemntStostu (dane), kasujemy stary wierzcholek i przypisujemy mu wskaznik na Link(poprzedni)
    }

bool Stos::empty()
    {
    if( size() == 0)
        {return true;}
    else
        {return false;};
    }

int Stos::size()
{
    int suma = 0;
    Link* el = wierzcholek;

    while (el != NULL)
    {
        if ( el -> dane != NULL)
            { suma += 1;};
        el = el -> poprzedni;
    }
    return suma;
}


//operatory
ostream& operator << (ostream& os, Stos &s)
{
    os << "[";

    Stos::Link* el = s.wierzcholek;
    while (el != NULL)
    {
        os << *(el -> dane);
        el = el -> poprzedni;
        if (el != NULL) { cout << ", "; }
    }

    os << "]";
    return os;
}

