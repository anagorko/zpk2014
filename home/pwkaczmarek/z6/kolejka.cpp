#include<iostream>
#include<string>
using namespace std;

class ElementKolejki
{
    virtual void output(ostream&) = 0;

public:
    virtual ~ElementKolejki() = 0;
    friend ostream& operator<<(ostream& os, ElementKolejki& el);
};

ElementKolejki::~ElementKolejki()
{
}

ostream& operator<<(ostream& os, ElementKolejki& el)
{
    el.output(os);
    return os;
}

class Liczba : public ElementKolejki
{
    int l;
    virtual void output(ostream& os)
    {
        os << l;
    }

public:
    Liczba(int l)
    {
        set(l);
    }

    Liczba() : Liczba(0)
    {
    }

    ~Liczba()
    {
    }

    int get()
    {
        return l;
    }

    void set(int _l)
    {
        l = _l;
    }
};

class Kolejka
{
    struct Link
    {
        ElementKolejki *dane;
        Link *nastepny;
    };

    Link* pierwszy;
    Link* ostatni;
    int numer;

public:
    Kolejka();
    ~Kolejka();

    void push(ElementKolejki* el);
    ElementKolejki* pop();
    bool empty();
    int size();

    friend ostream& operator<<(ostream&, Kolejka &);
};


Kolejka::Kolejka()
{
    pierwszy = NULL;
    ostatni = NULL;
    numer = 0;
}

Kolejka::~Kolejka()
{
    while(pierwszy != NULL)
    {
        delete pop();
    }
    numer = 0;
}

void Kolejka::push(ElementKolejki* el)
{
    Link *nowy = new Link;
    nowy -> dane = el;
    nowy -> nastepny = NULL;

    if(numer == 0) {
        pierwszy = nowy;
    } else if(numer == 1) {
        pierwszy -> nastepny = nowy;
        ostatni = nowy;
    } else {
        ostatni -> nastepny = nowy;
        ostatni = nowy;
    }

    numer++;
}

ElementKolejki* Kolejka::pop()
{
    if(numer == 0)
        return NULL;

    ElementKolejki *wynik = pierwszy -> dane;
    Link* nastepny = pierwszy -> nastepny;
    delete pierwszy;
    pierwszy = nastepny;
    if(numer <= 2)
        ostatni = NULL;

    numer--;
    return wynik;
}

bool Kolejka::empty()
{
    if(numer == 0)
        return true;
    else
        return false;
}

int Kolejka::size()
{
    return numer;
}


ostream& operator<<(ostream& os, Kolejka &s)
{
    os << "[";

    Kolejka::Link *el = s.pierwszy;
    while(el != NULL)
    {
        os << *(el -> dane);
        el = el -> nastepny;
        if (el != NULL)
            cout << ", ";
    }

    os << "]";
    return os;
}

