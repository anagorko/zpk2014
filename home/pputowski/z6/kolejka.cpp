#include<iostream>
#include<string>
using namespace std;

class ElementKolejki
{
    virtual void output( ostream& ) = 0;

public:
    virtual ~ElementKolejki() = 0;

    friend ostream& operator << ( ostream& os, ElementKolejki& el );
};

ElementKolejki::~ElementKolejki() {}

ostream& operator<<( ostream& os, ElementKolejki& el )
{
    el.output( os );
    return os;
}

class Liczba : public ElementKolejki
{
    int l;

    virtual void output( ostream& os ) {
        os << l;
    }

public:

	Liczba( int l )
	{
        set( l );
    }

    Liczba() : Liczba( 0 ) {}

    ~Liczba() {}

    int get()
	{
		return l;
	}

	void set( int _l )
	{
		l = _l;
	}

};

class Kolejka
{
    struct Link
    {
        ElementKolejki    *dane;
        Link            *kolejny;
    };
    int i;
    Link* pierwszy;
	Link* ostatni;

public:
    Kolejka()
	{
        pierwszy = NULL;
		ostatni = NULL;
        i = 0;
    }

    ~Kolejka() {
        while ( pierwszy != NULL) {
            delete pop();
        }
        i = 0;
    }

	int size()
	{
		return i;
	}

	bool empty()
	{
		if( i == 0 )
			return true;
		else
			return false;
	}

    void push( ElementKolejki* el )
	{
		Link *nowy = new Link;

        nowy -> kolejny = NULL;
        nowy -> dane = el;

		if( i == 0 )
			pierwszy = nowy;
		else
			ostatni -> kolejny = nowy;

		ostatni = nowy;
        i++;
    }

    ElementKolejki* pop()
	{
        if ( i == 0 )
			return NULL;

        ElementKolejki *wynik = pierwszy -> dane;
        Link* kolejny = pierwszy -> kolejny;
        delete pierwszy;
        pierwszy = kolejny;
		i--;
        return wynik;
    }

    friend ostream& operator<<( ostream&, Kolejka & );
};

ostream& operator<<( ostream& os, Kolejka &k )
{
    os << "[";

    Kolejka::Link *el = k.pierwszy;
    while ( el != NULL ) {
        os << *( el -> dane );
        el = el -> kolejny;
        if ( el != NULL )
			cout << ", ";
    }

    os << "]";
    return os;
}

int main()
{
	Kolejka k;

    while ( true ) {
        cout << k << endl;
        cout << "> ";

        int komenda;
        cin >> komenda;

        if ( komenda == 0 ){
        	cout << "pop" << endl;
        	k.pop();
        }
        else {
	            cout << "Czy kolejka jest pusta: " << k.empty() << endl;
	            k.push( new Liczba( komenda ) );
	            cout << "Nowa wielkosc kolejki: " << k.size() << endl;
	        }
    }
}


