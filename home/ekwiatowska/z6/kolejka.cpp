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

ElementKolejki::~ElementKolejki() {}

ostream& operator<<(ostream& os, ElementKolejki& el)
{
    el.output(os);
    return os;
}


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

    Link* poczatek;
    Link* koniec;

public:
    Kolejka() {
        poczatek = NULL;
        koniec = NULL;
    }

    ~Kolejka() {
        while (poczatek != NULL) {
            delete pop();
        }
    }

    void push(ElementKolejki* el) {
        Link *nowy = new Link;

        nowy -> nastepny = NULL;
        nowy -> dane = el;

        if (koniec == NULL){
            poczatek = nowy;
            koniec = nowy;
        }
        else {
            koniec -> nastepny = nowy;
            koniec = nowy;
        }

    }

    ElementKolejki* pop() {
        if (poczatek == NULL) return NULL;

        ElementKolejki *wynik = poczatek -> dane;
        Link* nastepny = poczatek -> nastepny;
        if (nastepny == NULL) koniec=NULL;
        delete poczatek;
        poczatek = nastepny;

        return wynik;
    }

    bool empty() {
        if (poczatek == NULL) return true;
        else return false;
    }

    int size() {
        int roz=1;
        Link* p = poczatek;
        Link* k = NULL;
        while (p != koniec){
            roz=roz+1;
            k = p -> nastepny;
            p = k;
        }
        return roz;
   }

    friend ostream& operator<<(ostream&, Kolejka &);
};

ostream& operator<<(ostream& os, Kolejka &k) {
    os << "[";

    Kolejka::Link *el = k.poczatek;
    while (el != NULL) {
        os << *(el->dane);
        el = el -> nastepny;
        if (el != NULL) { cout << ", "; }
    }

    os << "]";
    return os;
}

int main()
{
    Kolejka k;
}

