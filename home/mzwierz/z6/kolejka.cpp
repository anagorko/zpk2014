#include<iostream>
#include<string>
using namespace std;

class ElementKolejki {
    virtual void output(ostream&) = 0;

public:
    virtual ~ElementKolejki() = 0;
    friend ostream& operator<<(ostream& os, ElementKolejki& el);
};

ElementKolejki::~ElementKolejki() {}

ostream& operator<<(ostream& os, ElementKolejki& el) {
    el.output(os);
    return os;
}

class Liczba : public ElementKolejki {
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

class Kolejka {
    int d;
    struct Link
    {
        ElementKolejki    *dane;
        Link            *nastepny;
    };

    Link* pierwszy;
    Link* ostatni;

public:
    Kolejka() {
        pierwszy = NULL;
        ostatni = NULL;
        d = 0;
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
        if(empty()) {
            pierwszy = nowy;
        }
        else if (d == 1) {
            pierwszy -> nastepny = nowy;
            ostatni = nowy;
        }
        else {
            ostatni -> nastepny = nowy;
            ostatni = nowy;
        }
        d++;
    }

    ElementKolejki* pop() {
        if (empty()) return NULL;
        ElementKolejki *wynik = pierwszy -> dane;
        Link* nastepny = pierwszy -> nastepny;
        delete pierwszy;
        pierwszy = nastepny;
        if (d <= 2) {
            ostatni = NULL;
        }
        d--;
        return wynik;
    }

     int size() {
        return d;
    }

    bool empty() {
        if (d == 0)
            return true;
        return false;
    }

    friend ostream& operator<<(ostream&, Kolejka &);
};

ostream& operator<<(ostream& os, Kolejka &k) {

    os << "[";

    Kolejka::Link *el = k.pierwszy;
    while (el != NULL) {
        os << *(el -> dane);
        el = el -> nastepny;
        if (el != NULL) { cout << ", "; }
    }

    os << "]";
    return os;
}

int main() {
    Kolejka k;
}
