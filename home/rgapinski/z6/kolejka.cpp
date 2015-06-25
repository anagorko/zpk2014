#include<iostream>
using namespace std;

class ElementKolejki{
    virtual void output(ostream&) = 0;
    public:
    virtual ~ElementKolejki() = 0;
    friend ostream& operator<<(ostream& os, ElementKolejki& k);
};

ElementKolejki :: ~ElementKolejki(){}
ostream& operator<<(ostream& os, ElementKolejki& el){
        el.output(os);
        return os;
    }

class Liczba_k : public ElementKolejki{
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
    int get() { return k; }
    void set(int _k) { k = _k; }
};

class wl_Kolejka{
    struct Link{
        ElementKolejki *dane;
        Link *poprzedni;
        Link *nastepny;
    };
    Link* wierzcholek;
    Link* dol;
    public:
    wl_Kolejka(){
        wierzcholek = NULL;
        dol = NULL;
    }
    ~wl_Kolejka(){
        while (dol != NULL){
            delete poprz();
        }
    }
    void push(ElementKolejki* k){
        Link *nowy = new Link;
        nowy -> poprzedni = wierzcholek;
        nowy -> dane = k;
        if(wierzcholek != NULL) wierzcholek -> nastepny = nowy;
        if(wierzcholek != NULL && wierzcholek -> poprzedni == NULL) dol = wierzcholek;
        nowy -> nastepny = NULL;
        wierzcholek = nowy;
    }
    ElementKolejki* poprz(){
        if (wierzcholek == NULL && dol == NULL) return NULL;
        if (wierzcholek -> poprzedni == NULL){
            ElementKolejki *wynik = dol -> dane;
            delete dol;
            dol = NULL;
            wierzcholek = NULL;
            return wynik;
        }
        else{
            dol -> nastepny -> poprzedni = NULL;
            ElementKolejki *wynik = dol -> dane;
            Link* dol2 = dol -> nastepny;
            delete dol;
            dol = dol2;
            return wynik;
        }
    }
    bool empty(){
        if(wierzcholek == NULL) return 1;
        return 0;
    }
    friend ostream& operator<<(ostream&, wl_Kolejka &);
};

ostream& operator<<(ostream& os, wl_Kolejka &s){
    os << "[";
    wl_Kolejka::Link *el = s.wierzcholek;
    while (el != NULL){
        os << *(el -> dane);
        el = el -> poprzedni;
        if (el != NULL) { cout << " , "; }
    }
    os << " ]";
    return os;
}

//PROGRAM GLOWNY:
int main(){
    wl_Kolejka k;
    while (true){
        cout << k << endl;
        int n;
        cin >> n;
        if (n == 0){
            k.poprz();
        }
        else{
            k.push(new Liczba_k(n));
        }
    }
}
