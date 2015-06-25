#include<iostream>
#include<string>
using namespace std;

/*
 * Obiekty klas implementuj¹cych interfejs ElementStosu mo¿na
 * przechowywaæ w ni¿ej okreœlonej strukturze Stos.
 */

class ElementStosu{
    virtual void output(ostream&) = 0;
    public:
        virtual ~ElementStosu() = 0;
    friend ostream& operator<<(ostream& os, ElementStosu& el);
};

ElementStosu::~ElementStosu() {}
    ostream& operator<<(ostream& os, ElementStosu& el){
        el.output(os);
        return os;
}

class Liczba_k : public ElementStosu{
    int k;
    virtual void output(ostream& os){
        os << k;
    }
    public:
    Liczba_k(int k){
        set(k);
    }
    Liczba_k() : Liczba_k(0){
    }
    ~Liczba_k() {}
    int get() { return k;}
    void set(int _k) { k = _k;}
};

/*
 * Obiekty klasy Stos mog¹ przechowywaæ dowolne obiekty implementuj¹ce interfejs
 * ElementStosu.
 */
class Stos{
    struct Link{
        ElementStosu    *dane;
        Link            *poprzedni;
    };
    Link* wierzcholek;
    long number;
    public:
        Stos() {
            wierzcholek = NULL;
            number  = 0;
        }
        ~Stos() {
            while (wierzcholek != NULL){
                delete pop();
            }
        }
        void push(ElementStosu* el){
            number = ++number;
            Link * nowy_w = new Link;
            nowy_w -> poprzedni = wierzcholek;
            nowy_w -> dane = el;
            wierzcholek = nowy_w;
        }
        ElementStosu* pop() {
            if (wierzcholek == NULL) return NULL;
            number = --number;
            ElementStosu * wynik = wierzcholek -> dane;
            Link * poprzedni = wierzcholek -> poprzedni;
            delete wierzcholek;
            wierzcholek = poprzedni;
            return wynik;
        }
// IMPPLEMENTACJA BOOL
    bool empty(){
        if(wierzcholek == NULL) return 1;
        return 0;
    }
// IMPLEMENTACJA SIZE
    long size(){
        return number;
    }
    friend ostream& operator<<(ostream&, Stos &);
};
    ostream& operator<<(ostream& os, Stos &s){
        os << "[";
        Stos::Link *el = s.wierzcholek;
        while (el != NULL) {
            os << *(el -> dane);
            el = el -> poprzedni;
            if (el != NULL) { cout << " , ";}
        }
        os << " ]";
    return os;
}




// WLASCIWY PROGRAM - STOS:
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

        if (komenda == "+" || komenda == "*" || komenda == "-" || komenda == "/") {
            Liczba_k *l2 = static_cast<Liczba_k*>(s.pop());
            Liczba_k *l1 = static_cast<Liczba_k*>(s.pop());

            if (l1 == NULL || l2 == NULL) {
                cout << "Brak elementów na stosie." << endl; continue;
            }

            Liczba_k *wynik;

            if (komenda == "+") {
                wynik = new Liczba_k(l1 -> get() + l2 -> get());
            } else if (komenda == "*") {
                wynik = new Liczba_k(l1 -> get() * l2 -> get());
            } else if (komenda == "-") {
                wynik = new Liczba_k(l1 -> get() - l2 -> get());
            } else if (komenda == "/") {
                if (l2 -> get() == 0) {
                    cout << "Nie umiem dzieliæ przez zero." << endl;

                    wynik = new Liczba_k();
                } else {
                    wynik = new Liczba_k(l1 -> get() / l2 -> get());
                }
            }

            s.push(wynik);

            delete l1;
            delete l2;

            continue;
        }

        try{
            int k = stoi(komenda);

            s.push(new Liczba_k(k));
        } catch (string ex) {
            cout << "Nieznana komenda: " << komenda << endl;
        }
    }
}
