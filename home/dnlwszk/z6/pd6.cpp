#include<iostream>
using namespace std;

/*
 * Obiekty klas implementujących interfejs ElementStosu można
 * przechowywać w niżej określonej strukturze Stos.
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
 * Obiekty klasy Stos mogą przechowywać dowolne obiekty implementujące interfejs
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
    int   rozmiar;
    Link* wierzcholek;

public:
    Stos() {
        wierzcholek = NULL;
        rozmiar = 0;
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
        rozmiar++;
        wierzcholek = nowy;
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

    bool empty() {
        if (wierzcholek == NULL) return true;

        return false;
    }

    int size() {

        return rozmiar;
    }

    friend ostream& operator<<(ostream&, Stos &);
};

class Kolejka
{
    struct Link
    {
        ElementStosu    *dane;
        Link            *poprzedni;

    };

    int   rozmiar;
    Link* pierwszy;
    Link* ostatni;

public:
    Kolejka() {
        pierwszy = NULL;
        ostatni = NULL;
        rozmiar = 0;

    }

    ~Kolejka() {
        while (pierwszy != NULL) {
            delete pop();
        }
    }

    void push(ElementStosu* el) {


        Link *nowy = new Link;

        nowy -> poprzedni = ostatni;
        nowy -> dane = el;
        rozmiar++;
        ostatni = nowy;
        if(pierwszy == NULL) pierwszy = nowy;


    }

    ElementStosu* pop() {
        if ( pierwszy == NULL) return NULL;

        ElementStosu *wynik = pierwszy -> dane;
        Link* poprzedni = pierwszy -> poprzedni;
        delete poprzedni;
        pierwszy = poprzedni;
        rozmiar--;

        return wynik;
    }

    bool empty() {
        if (wierzcholek == NULL) return true;

        return false;
    }

    int size() {

        return rozmiar;
    }

    friend ostream& operator<<(ostream&, Kolejka &);
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
    Stos s;

    while (true) {
        cout << s << endl;
        cout << "> ";

        string komenda;
        cin >> komenda;

        if (komenda == "q" || komenda == "quit") {
            cout << "Bye" << endl;
            return 0;
        }

        if (komenda == "+" || komenda == "*" || komenda == "-" || komenda == "/" || komenda == "%") {
            Liczba *l2 = static_cast<Liczba*>(s.pop());
            Liczba *l1 = static_cast<Liczba*>(s.pop());

            if (l1 == NULL || l2 == NULL) {
                cout << "Brak elementów na stosie." << endl; continue;
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
            } else if (komenda == "%"){
                if (l2 -> get() == 0) {
                    cout << "Nie umiem dzielić przez zero." << endl;

                    wynik = new Liczba();
                } else {
                    wynik = new Liczba(l1 -> get() % l2 -> get());
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
