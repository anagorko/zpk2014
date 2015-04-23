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

class Kolejka {
    struct Link
    {
        ElementKolejki *dane;
        Link           *nastepny;
    };

    Link* start;
    Link* koniec;

    int rozmiar;

public:

    Kolejka() {
        start = NULL;
        koniec = NULL;
        rozmiar = 0;
    }

    ~Kolejka() {
        while (start != NULL)
        {
            delete pop();
        }
        rozmiar = 0;
    }

    void push(ElementKolejki* el) {
        Link *nowy = new Link;

        nowy -> dane = el;
        nowy -> nastepny = NULL;

        if (koniec == NULL){
            start = nowy;
            koniec = nowy;
        }
        else {
            koniec -> nastepny = nowy;
            koniec = nowy;
        }

        rozmiar++;
    }

    ElementKolejki* pop() {
        if (rozmiar == 0) return NULL;

        ElementKolejki *wynik = start -> dane;
        Link* nastepny = start -> nastepny;

        if (nastepny == NULL) koniec=NULL;
        delete start;
        start = nastepny;

        rozmiar--;

        return wynik;
    }

    bool empty() {
        if (start == 0)
            return true;
        else
            return false;
    }

    int size() {
        return rozmiar;
    }

 friend ostream& operator<<(ostream&, Kolejka &);
};

ostream& operator<<(ostream& os, Kolejka &k) {
    os << "[";

    Kolejka::Link *el = k.start;
    while (el != NULL) {
        os << *(el->dane);
        el = el -> nastepny;
        if (el != NULL) { cout << ", "; }
    }

    os << "]";
    return os;
}

int main(){

    Kolejka k;

}


