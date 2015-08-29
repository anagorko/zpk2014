#include <iostream>
#include <string>
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


class Kolejka
{
    struct Link
    {
        ElementKolejki    *dane;
        Link            *nastepny;
    };

    Link* pierwszy;
    Link* ostatni;
    int nr;

public:
    Kolejka() ;
    ~Kolejka();
    void push(ElementKolejki* el);
    ElementKolejki* pop();
    bool empty ();
    int size();
    friend ostream& operator<<(ostream&, Kolejka &);
};

class Liczba: public ElementKolejki{
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

Kolejka:Kolejka(){
    pierwszy = NULL;
    ostatni = NULL;
    nr = 0;
}

Kolejka::~Kolejka(){
    while(pierwszt != NULL)
        delete pop();
    nr = 0;
}

void Kolejka::push(ElementKolejki* el){
    Link* nowy = new Link;
    nowy->nastepny = NULL;
    nowy-> dane =el;

   if(nr==0)
        pierwszy = nowy;
    else if (nr==1){
        pierwszy->nastepny = nowy;
        ostatni = nowy;}
    else{
        ostatni->nastepny = nowy;
        ostatni = nowy;}
    nr++;
}

ElementKolejki* Kolejka::pop(){
    if(nr==0)
        return NULL;
    ElementKolejki* wynik = pierwszy -> dane;
    Link* nastepny = pierwszy -> nastepny;
    delete pierwszy;
    pierwszy = nastepny;
    if(nr<=2)
        ostatni=NULL;
    nr--;
    return wynik;
}

bool Kolejka:: empty(){
    if (nr==0)
        return true;
    else
        return false;
}

int Kolejka::size()
{
    return nr;
}

ostream& operator<<(ostream& os, Kolejka& s){
    os << "[";
    Kolejka::Link *el = s.pierwszy;
    while(el != NULL){
        os<<*(el -> dane);
        el = el->nastepny;
        if (el!=NULL)
            cout <<",";
        }
        os << "]";
        return os;
}

