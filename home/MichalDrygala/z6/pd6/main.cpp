#include "ElementStosu.h"
#include "Stos.h"

#include <iostream>
#include <math.h>
using namespace std;

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
                    cout << "Nie umiem dzieliæ przez zero." << endl;

                    wynik = new Liczba();
                } else {
                    wynik = new Liczba(l1 -> get() / l2 -> get());
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
