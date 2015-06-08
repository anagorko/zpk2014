#include<iostream>
#include<string>
using namespace std;

/*
 * Obiekty klas implementujacych interfejs ElementStosu mozna
 * przechowywac w nizej okreslonej strukturze Stos.
 */

class ElementStosu
{
    virtual void output(ostream&) = 0;

public:

    virtual ~ElementStosu() = 0;
    friend ostream& operator<<(ostream& os, ElementStosu& el);
};

ElementStosu::~ElementStosu()
{
}

ostream& operator<<(ostream& os, ElementStosu& el)
{
    el.output(os);
    return os;
}

class Liczba : public ElementStosu
{
    int l;

    virtual void output(ostream& os)
    {
        os << l;
    }

public:

    Liczba(int l)
    {
        set(l);
    }

    Liczba() : Liczba(0)
    {
    }

    ~Liczba()
    {
    }

    int get()
    {
        return l;
    }

    void set(int _l)
    {
        l = _l;
    }
};


/*
 * Obiekty klasy Stos moga przechowywac dowolne obiekty
 * implementujace interfejs ElementStosu.
 */

class Stos
{
    int dlugosc;
    struct Link
    {
        ElementStosu    *dane;
        Link            *poprzedni;
    };

    Link* wierzcholek;

public:

    Stos()
    {
        wierzcholek = NULL;
        dlugosc = 0;
    }

    ~Stos()
    {
        while (wierzcholek != NULL)
        {
            delete pop();
        }
        dlugosc = 0;
    }

    void push(ElementStosu* el)
    {
        Link *nowy = new Link;

        nowy -> poprzedni = wierzcholek;
        nowy -> dane = el;

        wierzcholek = nowy;
        dlugosc++;
    }

    ElementStosu* pop()
    {
        if (wierzcholek == NULL) return NULL;

        ElementStosu *wynik = wierzcholek -> dane;
        Link* poprzedni = wierzcholek -> poprzedni;
        delete wierzcholek;
        wierzcholek = poprzedni;
        dlugosc--;

        return wynik;
    }

    bool empty()
    {
        if (wierzcholek == NULL)
	    return true;
        else
	    return false;
    }

    int size()
    {
        return dlugosc;
    }

    friend ostream& operator<<(ostream&, Stos &);
};

ostream& operator<<(ostream& os, Stos &s)
{
    os << "[";

    Stos::Link *el = s.wierzcholek;
    while (el != NULL)
    {
        os << *(el -> dane);
        el = el -> poprzedni;
        if (el != NULL)
            cout << ", ";
    }

    os << "]";
    return os;
}

int main()
{
    Stos s;

    while (true)
    {
        cout << s << endl;
        cout << "> ";

        string komenda;
        cin >> komenda;

        if (komenda == "q" || komenda == "quit")
        {
            cout << "Bye" << endl;
            return 0;
        }

        if (komenda == "+" || komenda == "*" || komenda == "-" || komenda == "/" || komenda == "%")
        {
            Liczba *l2 = static_cast<Liczba*>(s.pop());
            Liczba *l1 = static_cast<Liczba*>(s.pop());

            if (l1 == NULL || l2 == NULL)
            {
                cout << "Brak elementów na stosie." << endl;
                continue;
            }

            Liczba *wynik;

            if (komenda == "+")
                wynik = new Liczba(l1 -> get() + l2 -> get());
            else if (komenda == "*")
                wynik = new Liczba(l1 -> get() * l2 -> get());
            else if (komenda == "-")
                wynik = new Liczba(l1 -> get() - l2 -> get());
            else if (komenda == "/")
            {
                if (l2 -> get() == 0)
                {
                    cout << "Nie umiem dzielić przez zero." << endl;
                    wynik = new Liczba();
                }
                else
                    wynik = new Liczba(l1 -> get() / l2 -> get());
            }
            else if (komenda == "%")
	    {
                if (l2 -> get() == 0)
                {
                    cout << "Nie umiem dzielić przez zero." << endl;
                    wynik = new Liczba();
                }
                else
		wynik = new Liczba(l1 -> get() % l2 -> get());
	    }

            s.push(wynik);

            delete l1;
            delete l2;

            continue;
        }

        try
        {
            int l = stoi(komenda);
            s.push(new Liczba(l));
        }
        catch (string ex)
        {
            cout << "Nieznana komenda: " << komenda << endl;
        }
    }
}
