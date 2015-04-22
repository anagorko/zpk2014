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
}};

class Kolejka
{
struct Link
{
ElementKolejki *dane;
Link *nastepny;

};
Link* pierwszy;
Link* ostatni;

int zmienna;
public:

Kolejka()
{
    pierwszy = NULL;
    ostatni = NULL;
    zmienna = 0;
}
~Kolejka()
{
while (pierwszy != NULL)
{
delete pop();
}
zmienna = 0;
}
void push(ElementKolejki* el)
{
Link *nowy = new Link;
nowy -> dane = el;
nowy -> nastepny = NULL;
if(zmienna == 0)
{
pierwszy = nowy;
}
else if (dlugosc == 1)
{
pierwszy -> nastepny = nowy;
ostatni = nowy;
}
else
{
ostatni -> nastepny = nowy;
ostatni = nowy;
}
zmienna++;
}
ElementKolejki* pop()
{
if (zmienna == 0) return NULL;

ElementKolejki *wynik = pierwszy -> dane;
Link* nastepny = pierwszy -> nastepny;

delete pierwszy;
pierwszy = nastepny;
if (zmienna <= 2)
    ostatni = NULL;
zmienna--;

return wynik;
}

bool empty()
{
if (zmienna == 0)
    return true;
else
    return false;
}
int size()
{
return zmienna;
}
friend ostream& operator<<(ostream&, Stos &);
};

ostream& operator<<(ostream& os, Stos &s)
{
os << "[";
Stos::Link *el = s.wierzcholek;
while (el != NULL)
{
os << *(el -> dane);
el = el -> poprzedni;
if (el != NULL)
cout << ", ";
}
os << "]";
return os;
}
