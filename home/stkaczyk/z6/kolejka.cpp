#include<iostream>
#include<string>
using namespace std;

/*
 * Obiekty klas implementuj¹cych interfejs ElementStosu mo¿na
 * przechowywaæ w ni¿ej okreœlonej strukturze Stos.
 */

class ElementKolejki
{
    virtual void output(ostream&) = 0;

public:
    virtual ~ElementKolejki() = 0;

    friend ostream& operator<<(ostream& os, ElementKolejki& el);
};

ElementKolejki::~ElementKolejki() {}

ostream& operator<<(ostream& os, ElementKolejki& el)
{
    el.output(os);
    return os;
}

/*
 * Obiekty klasy Stos mog¹ przechowywaæ dowolne obiekty implementuj¹ce interfejs
 * ElementStosu.
 */

class Liczba : public ElementKolejki
{
    int l;

    virtual void output(ostream& os) {
        os << l;
    }

public:
    Liczba(int l) {
        set(l);
    }

    Liczba() : Liczba(0) {
    }

    ~Liczba() {}

    int get() { return l; }
    void set(int _l) { l = _l; }
};

class Kolejka
{
    struct Link
    {
        ElementKolejki    *dane;
        Link            *nastepny;
    };

    Link* pierwszy;
    Link* ostatni;
    int dlugosc;

public:
    Kolejka() {
        pierwszy = NULL;
        ostatni = NULL;
        dlugosc = 0;
    }

    ~Kolejka() {
        while (pierwszy != NULL) {
            delete pop();
        }
    }

    void push(ElementKolejki* el) {
        Link *nowy = new Link;

        nowy -> nastepny = NULL;
        nowy -> dane = el;

        if(dlugosc == 0) {
            pierwszy = nowy;
            ostatni = nowy;
        }
        else {
            ostatni -> nastepny = nowy;
            ostatni = nowy;
        }
        dlugosc += 1;
    }

    ElementKolejki* pop() {
        if (dlugosc == 0) return NULL;

        ElementKolejki *wynik = pierwszy -> dane;
        Link* nastepny = pierwszy -> nastepny;
        delete pierwszy;
        pierwszy = nastepny;

        if(dlugosc == 1){
            ostatni = NULL;
        }

        dlugosc -= 1;

        return wynik;
    }
    bool empty()
    {
        if(dlugosc == 0)
            return true;
        else
            return false;
    };

    int size()
    {
        return dlugosc;
    };

    friend ostream& operator<<(ostream&, Kolejka &);
};

ostream& operator<<(ostream& os, Kolejka &s) {
    os << "[";

    Kolejka::Link *el = s.pierwszy;
    while (el != NULL) {
        os << *(el->dane);
        el = el -> nastepny;
        if (el != NULL) { cout << ", "; }
    }

    os << "]";
    return os;
}
