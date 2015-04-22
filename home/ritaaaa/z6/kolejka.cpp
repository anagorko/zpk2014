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

    Link* pierwszy;
    Link* ostatni;

public:
    Kolejka() {
        pierwszy = NULL;
        ostatni = NULL;
        dlugosc=0;
    }

    ~Kolejka() {
        while (pierwszy != NULL) {
            delete pop();
        }
    }
    bool empty() {
        if (dlugosc = 0) return true;
        else return false;
    }
      int size() {
        return dlugosc;
    }

    void push(ElementKolejki* el) {
        Link *nowy = new Link;

        nowy -> nastepny = pierwszy;
        nowy -> dane = el;

        pierwszy = nowy;
    }

    ElementKolejki* pop() {
        if (pierwszy == NULL) return NULL;

        ElementKolejki *wynik = pierwszy -> dane;
        Link* nastepny = pierwszy -> nastepny;
        delete pierwszy;
       pierwszy = nastepny;

        return wynik;
    }


    friend ostream& operator<<(ostream&, Kolejka &);
};

ostream& operator<<(ostream& os, Kolejka &s) {
    os << "[";

    Kolejka::Link *el = s.pierwszy;
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
        cout << "> ";

        string komenda;
        cin >> komenda;

        if (komenda == "q" || komenda == "quit") {
            cout << "Bye" << endl;
            return 0;
        }

        if (komenda == "+" || komenda == "*" || komenda == "-" || komenda == "/"|| komenda == "%") {
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
            }

                else if (komenda == "%") {
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

