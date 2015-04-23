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
    struct Link
    {
        ElementKolejki    *dane;
        Link              *poprzedni;
        Link              *nastepny;
    };

    Link* wierzcholek;
    Link* spodek;

public:
    Kolejka() {
        wierzcholek = NULL;
        spodek = NULL;
    }

    ~Kolejka() {
        while (spodek != NULL) {
            delete pop();
        }
    }

    void push(ElementKolejki* el) {

        Link *nowy = new Link;

        nowy -> poprzedni = wierzcholek;
        nowy -> dane = el;

        if(wierzcholek != NULL) wierzcholek -> nastepny = nowy;
        if(wierzcholek != NULL && wierzcholek -> poprzedni == NULL) spodek = wierzcholek;

        nowy -> nastepny = NULL;
        wierzcholek = nowy;
    }

    ElementKolejki* pop() {
        if (wierzcholek == NULL && spodek == NULL) return NULL;

         if (wierzcholek -> poprzedni == NULL){
            ElementKolejki *wynik = spodek -> dane;
            delete spodek;
            spodek = NULL;
            wierzcholek = NULL;
            return wynik;
         }else{
            spodek -> nastepny -> poprzedni = NULL;
            ElementKolejki *wynik = spodek -> dane;
            Link* nowy_spodek = spodek -> nastepny;
            delete spodek;
            spodek = nowy_spodek;
            return wynik;
         }
    }

    bool empty(){
        if(wierzcholek==NULL) return 1;
        return 0;
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
    Kolejka k;

    while (true) {
        cout << k << endl;
        int num;
        cin >> num;

        if (num == 0){
            k.pop();
        }else{
            k.push(new Liczba(num));
        }
    }
}

