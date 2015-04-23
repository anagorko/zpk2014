#include<iostream>
#include<string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/*
 * Obiekty klas implementujących interfejs ElementKolejka można
 * przechowywać w niżej określonej strukturze Kolejka.
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
 * Obiekty klasy Kolejka mogą przechowywać dowolne obiekty implementujące interfejs
 * ElementKolejki.
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

    Link* koniec;
    Link* poczatek;
    int n;


public:
    Kolejka() {
        koniec = NULL;
        poczatek = NULL;
        n=0;
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

        if(empty()){
            poczatek = nowy;
        }

        else if (n==1){
            poczatek -> nastepny=nowy;
            koniec = nowy;
        }
        else{
            koniec -> nastepny=nowy;
            koniec=nowy;
        }
        n++;
    }

    ElementKolejki* pop() {
        if (empty()) return NULL;

        ElementKolejki *wynik = poczatek -> dane;
        Link* kolejny = poczatek -> nastepny;
        delete poczatek;
        poczatek = kolejny;

        n--;

        return wynik;
    }

    bool empty(){
        if (poczatek == NULL) return true;
        else return false;
    }

    int size(){
        return n;
    }

    friend ostream& operator<<(ostream&, Kolejka &);
};

ostream& operator<<(ostream& os, Kolejka &s) {
    os << "[";

    Kolejka::Link *el = s.poczatek;
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
    Kolejka s;

    while (true) {
        cout << s << endl;

        int liczba;
        cin>>liczba;

        if(liczba!=0){
            s.push(new Liczba(liczba));
        }
        else s.pop();
    }
}


