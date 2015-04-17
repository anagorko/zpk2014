#include<iostream>
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
    int dlugosc;

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
        dlugosc = 0;
    }

    ~Kolejka() {
        while (poczatek != NULL) {
            delete pop();
        }
    }

    int size() {
        return dlugosc;
    }

    bool empty() {
        if (dlugosc == 0)
            return true;
        return false;
    }

    void push(ElementKolejki* el) {

        Link *nowy = new Link;
        nowy -> nastepny = NULL;
        nowy -> dane = el;

        if(empty()) {

            poczatek = nowy;
            poczatek -> nastepny = koniec;

        }
        else if (dlugosc == 1) {

            poczatek -> nastepny = nowy;
            koniec = nowy;

        }
        else {

            koniec -> nastepny = nowy;
            koniec = nowy;

        }

        ++dlugosc;

    }

    ElementKolejki* pop() {

        if (empty()) return NULL;

        ElementKolejki *wynik = poczatek -> dane;
        Link* nastepny = poczatek -> nastepny;

        if (dlugosc <= 2) {

            delete poczatek;
            poczatek = nastepny;
            koniec = NULL;

        }
        else {

            delete poczatek;
            poczatek = nastepny;

        }

        --dlugosc;

        return wynik;
    }

    friend ostream& operator<<(ostream&, Kolejka &);
};

ostream& operator<<(ostream& os, Kolejka &s) {

    os << "[";

    Kolejka::Link *el = s.poczatek;
    while (el != NULL) {
        os << *(el -> dane);
        el = el -> nastepny;
        if (el != NULL) { cout << ", "; }
    }

    os << "]";
    return os;
}

int main()
{
    Kolejka s;

    // Prosty mechanizm testowy
    while (true) {
        cout << s << endl;
        int l;
        cin >> l;

        if (l == 0)
            s.pop();
        else
        s.push(new Liczba(l));

    }
}
