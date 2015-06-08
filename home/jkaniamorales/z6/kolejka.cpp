#include<iostream>
#include <string>
using namespace std;

/*
 * Obiekty klas implementujących interfejs ElementKolejki można
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
        ElementKolejki  *dane;
        Link            *poprzedni;
        Link            *nastepny;
    };

    Link* wierzcholek;
    Link* ogonek;

public:
    Kolejka() {
        wierzcholek = NULL;
        ogonek = NULL;
    }

    ~Kolejka() {
        while (wierzcholek != NULL) {
            delete pop();
        }
    }

    void push(ElementKolejki* el) {
        Link *nowy = new Link;
        if(wierzcholek==NULL){
            ogonek = nowy;
        }

        nowy -> poprzedni = wierzcholek;
        nowy -> dane = el;
        nowy -> nastepny = NULL;

        if(wierzcholek != NULL){
                wierzcholek -> nastepny = nowy;
        }

        wierzcholek = nowy;
    }

    ElementKolejki* pop() {
        if (ogonek == NULL)return NULL;

        ElementKolejki *wynik = ogonek -> dane;
        Link* nastepny = ogonek -> nastepny;
        delete ogonek;
        ogonek = nastepny;
        if(ogonek!=NULL){
            ogonek -> poprzedni = NULL;
        }

        if(ogonek==NULL){
            wierzcholek = NULL;
        }

        return wynik;
    }

    friend ostream& operator<<(ostream&, Kolejka &);
};

ostream& operator<<(ostream& os, Kolejka &s) {
    os << "[";

    Kolejka::Link *el = s.wierzcholek;
    while (el != NULL) {
        os << *(el->dane);
        el = el -> poprzedni;
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
        cout << "> ";

        string komenda;
        cin >> komenda;

        if (komenda == "q" || komenda == "quit") {
            cout << "Bye" << endl;
            return 0;
        }

        if (komenda == "+" || komenda == "*" || komenda == "-" || komenda == "/") {
            Liczba *l2 = static_cast<Liczba*>(s.pop());
            Liczba *l1 = static_cast<Liczba*>(s.pop());

            if (l1 == NULL || l2 == NULL) {
                cout << "Brak elementów w kolejce." << endl; continue;
            }

            Liczba *wynik;

            if (komenda == "+") {
                wynik = new Liczba(l1 -> get() + l2 -> get());
            } else if (komenda == "*") {
                wynik = new Liczba(l1 -> get() * l2 -> get());
            } else if (komenda == "-") {
                wynik = new Liczba(l1 -> get() - l2 -> get());
            } else if (komenda == "/") {
                if (l2 -> get() == 0) {
                    cout << "Nie umiem dzielić przez zero." << endl;

                    wynik = new Liczba();
                } else {
                    wynik = new Liczba(l1 -> get() / l2 -> get());
                }
            }

            s.push(wynik);

            delete l1;
            delete l2;

            continue;
        }

        try {
            int l = stoi(komenda);

            s.push(new Liczba(l));
        } catch (string ex) {
            cout << "Nieznana komenda: " << komenda << endl;
        }
    }
}

