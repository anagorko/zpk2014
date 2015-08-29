#include <iostream>
#include <string>
using namespace std;

/*
 * Obiekty klas implementuj�cych interfejs ElementStosu mo�na
 * przechowywa� w ni�ej okre�lonej strukturze Stos.
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
 * Obiekty klasy Stos mog� przechowywa� dowolne obiekty implementuj�ce interfejs
 * ElementStosu.
 */

class Stos
{
    struct Link
    {
        ElementStosu    *dane;
        Link            *poprzedni;
    };

    Link* wierzcholek;

    int nr;

public:
    Stos() ;
    ~Stos();
    void push(ElementStosu* el);
    ElementStosu* pop();
    bool empty ();
    int size();
    friend ostream& operator<<(ostream&, Stos &);
};

class Liczba: public ElementStosu{
    int l;
    virtual void output(ostream& os){
        os<<l;}

    public:

        Liczba(int l){
        set(l);}
        Liczba():Liczba(0){}
        ~Liczba(){}
        int get(){
            return l;}
        void set (int _l){
        l=_l;}
};

Stos::Stos(){
    wierzcholek = NULL;
    nr = 0;
}

Stos::~Stos(){
    while(wierzcholek != NULL)
        delete pop();
    nr = 0;
}

void Stos::push(ElementStosu* el){
    Link* nowy = new Link;
    nowy->poprzedni = wierzcholek;
    nowy-> dane =el;
    wierzcholek = nowy;
    nr++;
}

ElementStosu* Stos::pop(){
    if(wierzcholek==NULL)
        return NULL;
    ElementStosu* wynik = wierzcholek -> dane;
    Link* poprzedni = wierzcholek -> poprzedni;
    delete wierzcholek;
    wierzcholek = poprzedni;
    nr--;
    return wynik;
}

bool Stos:: empty(){
    if (wierzcholek==NULL)
        return true;
    else
        return false;
}

int Stos::size()
{
    return nr;
}

ostream& operator<<(ostream& os, Stos& s){
    os << "[";
    Stos::Link *el = s.wierzcholek;
    while(el != NULL){
        os<<*(el -> dane);
        el = el->poprzedni;
        if (el!=NULL)
            cout <<",";
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

        if (komenda == "+" || komenda == "*" || komenda == "-" || komenda == "/" || komenda == "%" ) {
            Liczba *l2 = static_cast<Liczba*>(s.pop());
            Liczba *l1 = static_cast<Liczba*>(s.pop());

            if (l1 == NULL || l2 == NULL) {
                cout << "Brak element�w na stosie." << endl; continue;
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
                    cout << "Nie umiem dzieli� przez zero." << endl;

                    wynik = new Liczba();
                } else {
                    wynik = new Liczba(l1 -> get() / l2 -> get());
                }
            } else if (komenda == "%") {
                if (l2 -> get() == 0) {
                    cout << "Nie umiem dzieli� przez zero." << endl;

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

