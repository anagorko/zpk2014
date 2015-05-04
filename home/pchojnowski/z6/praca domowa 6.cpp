#include<iostream>
using namespace std;

/*
 * Obiekty klas implementuj¹cych interfejs ElementStosu mo¿na
 * przechowywaæ w ni¿ej okreœlonej strukturze Stos.
 */

class ElementStosu
{
    virtual void output(ostream&) = 0;

public:
    virtual ~ElementStosu() = 0;

    friend ostream& operator<<(ostream& os, ElementStosu& el);
};

ElementStosu::~ElementStosu() {}

ostream& operator<<(ostream& os, ElementStosu& el)
{
    el.output(os);
    return os;
}

/*
 * Obiekty klasy Stos mog¹ przechowywaæ dowolne obiekty implementuj¹ce interfejs
 * ElementStosu.
 */

class Liczba : public ElementStosu
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

class Stos
{
    struct Link
    {
        ElementStosu    *dane;
        Link            *poprzedni;
    };

    Link* wierzcholek;



public:
    int rozmiar = 0;
    Stos() {
        wierzcholek = NULL;
    }

    ~Stos() {
        while (wierzcholek != NULL) {
            delete pop();
        }
    }

    void push(ElementStosu* el) {
        Link *nowy = new Link;

        nowy -> poprzedni = wierzcholek;
        nowy -> dane = el;

        wierzcholek = nowy;

        rozmiar++;
    }

    ElementStosu* pop() {
        if (wierzcholek == NULL) return NULL;

        ElementStosu *wynik = wierzcholek -> dane;
        Link* poprzedni = wierzcholek -> poprzedni;
        delete wierzcholek;
        wierzcholek = poprzedni;

        rozmiar--;

        return wynik;
    }
    int size(){
         return rozmiar;
        }

    bool empty(){
        if(rozmiar) return true;
        else return false;
        }

    friend ostream& operator<<(ostream&, Stos &);
};

ostream& operator<<(ostream& os, Stos &s) {
    os << "[";

    Stos::Link *el = s.wierzcholek;
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

    Stos s;

    cout << "Rozmiar stosu wpisz r lub rozmiar." << endl << "Sprawdz czy zawiera elementy, wpisz p lub pusty.";


    while (true) {
        cout << s << endl;
        cout << "> ";

        string komenda;
        cin >> komenda;

        if (komenda == "q" || komenda == "quit") {
            cout << "Bye" << endl;
            return 0;
        }


        if (komenda == "r" || komenda == "rozmiar") {
            cout << "Rozmiar wynosi: " << endl;
            cout << s.size() << endl;
            continue;
        }
            if (komenda == "p" || komenda == "pusty") {
            cout << "Zawartosc: " << endl;
            if(s.empty()) cout << " elementy wystepuja"  << endl;
                else cout << "brak" << endl;

            continue;
        }


        if (komenda == "+" || komenda == "*" || komenda == "-" || komenda == "/" || komenda == "%") {
            Liczba *l2 = static_cast<Liczba*>(s.pop());
            Liczba *l1 = static_cast<Liczba*>(s.pop());

            if (l1 == NULL || l2 == NULL) {
                cout << "Brak elementów na stosie." << endl; continue;
            }

            Liczba *wynik;

            if (komenda == "%") {
                    if (l2 -> get() == 0) {
                    cout << "Nie umiem dzielic przez zero." << endl;
                    wynik = new Liczba();
                    }else wynik = new Liczba(l1 -> get() % l2 -> get());

            } else if (komenda == "+") {
                wynik = new Liczba(l1 -> get() + l2 -> get());
            } else if (komenda == "*") {
                wynik = new Liczba(l1 -> get() * l2 -> get());
            } else if (komenda == "-") {
                wynik = new Liczba(l1 -> get() - l2 -> get());
            } else if (komenda == "/") {
                if (l2 -> get() == 0) {
                    cout << "Nie umiem dzieliæ przez zero." << endl;

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

