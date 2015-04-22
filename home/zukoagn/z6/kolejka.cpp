#include<iostream>
#include<string>
using namespace std;

/*
 * Obiekty klas implementuj¹cych interfejs ElementKolejki mo¿na
 * przechowywaæ w ni¿ej okreœlonej strukturze Kolejka.
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
 * Obiekty klasy Kolejka mog¹ przechowywaæ dowolne obiekty implementuj¹ce interfejs
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
        ElementKolejki     *dane;
        Link               *nastepny;
    };

    Link* poczatek_kolejki;
    Link* koniec_kolejki;

    int licznik;

public:
    Kolejka() {
        poczatek_kolejki = NULL;
        koniec_kolejki = NULL;
        licznik=0;
    }

    ~Kolejka() {
        while (poczatek_kolejki != NULL) {
            delete pop();
        }
        licznik=0;
    }

    void push(ElementKolejki* el) {
        Link *nowy = new Link;

        nowy -> nastepny = NULL;
        nowy -> dane = el;

        if(licznik==0)
        {
            poczatek_kolejki=nowy;
        }
        else if (licznik==1)
        {
            poczatek_kolejki -> nastepny = nowy;
            koniec_kolejki = nowy;
        }
        else{
            koniec_kolejki -> nastepny = nowy;
            koniec_kolejki = nowy;
        }

        licznik++;
    }

    ElementKolejki* pop() {
        if (licznik == 0) return NULL;

        ElementKolejki *wynik = poczatek_kolejki -> dane;
        Link* nastepny = poczatek_kolejki -> nastepny;
        delete poczatek_kolejki;
        poczatek_kolejki = nastepny;

        licznik--;

        return wynik;
    }

    bool empty()
    {
        if (poczatek_kolejki == NULL)
            return true;
        else
            return false;
    }

    int size()
    {
        return licznik;
    }

    friend ostream& operator<<(ostream&, Kolejka &);
};

ostream& operator<<(ostream& os, Kolejka &k) {
    os << "[";

    Kolejka::Link *el = k.poczatek_kolejki;
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
    //Test kolejki

    Kolejka k;

    cout<<"***************************************************************************"<<endl;
    cout<<"*                                KOLEJKA                                  *"<<endl;
    cout<<"*                                                                         *"<<endl;
    cout<<"*        W kolejce moga sie znalezc liczby calkowite nieujemne            *"<<endl;
    cout<<"*   Jezeli chcesz zdjac element z kolejki podaj liczbe calkowita ujemna   *"<<endl;
    cout<<"*                                                                         *"<<endl;
    cout<<"***************************************************************************"<<endl;
    cout<<endl;

    while(true){
        cout<<k<<endl;
        cout<<"> ";


        int a;
        cin>>a;

        if ((a<0)&&(k.empty()!= true))
            k.pop();
        else if ((a<0)&&(k.empty()== true))
            cout<<"Kolejka jest pusta. Podaj liczbe, ktora chcesz dodac do kolejki"<<endl;
        else if (a>=0)
            k.push(new Liczba (a));

            cout<<"Liczba elementow w kolejce: "<<k.size()<<endl;
    }


}

