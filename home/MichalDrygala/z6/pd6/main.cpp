#include "Liczba.h"
#include "Stos.h"

#include <iostream>
using namespace std;

#include<cstdlib>

int main()
{
    Stos s;

    while (true) {
        cout << s << endl;
        cout << "> ";

        string komenda;
        cin >> komenda;

//czekamy na komende
//jesli uzytkownik wpisze 'q'

        if (komenda == "q" || komenda == "quit")
        {
            cout << "Bye" << endl;
            return 0;
        }

        if (komenda == "+" || komenda == "*" || komenda == "-" || komenda == "/" || komenda == "%")
        {
            Liczba* l2 = static_cast<Liczba*>(s.pop());
            Liczba* l1 = static_cast<Liczba*>(s.pop());

            // jesli nie ma liczby 1 albo liczby 2
            if (l1 == NULL || l2 == NULL)
            {
                cout << "Brak elementow na stosie." << endl; continue; // continue nie wykonuje dalszych instrukcji w tej petli
            }                                                         // ale jej nie przerywa, nastapi kolejny bieg petli

            Liczba* wynik;

            if (komenda == "+")
            { wynik = new Liczba(l1 -> get() + l2 -> get());
            }
            else if (komenda == "*")
            { wynik = new Liczba(l1 -> get() * l2 -> get());
            }
            else if (komenda == "-")
            { wynik = new Liczba(l1 -> get() - l2 -> get());
            }
            else if (komenda == "/")
            {
                if (l2 -> get() == 0)
                {   cout << "Nie umiem dzielic przez zero." << endl;
                    wynik = new Liczba();
                }
                else
                {  wynik = new Liczba(l1 -> get() / l2 -> get());
                }
            }
            else if (komenda == "%")
            {
                if (l2 -> get() == 0)
                {   cout << "Nie umiem dzielic przez zero." << endl;
                    wynik = new Liczba();
                }
                else
                {  wynik = new Liczba(l1 -> get() % l2 -> get());
                }
            }

            s.push(wynik);

            delete l1;
            delete l2;

            continue;
        }

        try
        {
            int l = atoi(komenda.c_str());
            s.push(new Liczba(l));
        }

        catch (string ex)
        {
            cout <<  "Nieznana komenda: " << komenda << endl;
        }

// sprawdzmy czy nasze funkcje size() i empty() sa poprawne
        cout << endl << "Liczba elementow na stosie: " << s.size() << endl;
        if (s.empty() == 0) { cout << "Stos nie jest pusty: "; };
    }
}


