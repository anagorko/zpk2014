#include<iostream>
using namespace std;

struct wynik {
    int punkty;
    string imie;
};

const int n = 10;

wynik wyniki[n];

void czytaj_wyniki()
{
    for (int i = 0; i < n; i++) {
        wyniki[i].punkty = 1000 - 100 * i;
        wyniki[i].imie = "A";
    }
}

void zapisz_wyniki()
{
}

void wypisz_wyniki()
{
    for (int i = 0; i < n; i++) {
        cout << (i+1) << ". " << wyniki[i].imie << " " << wyniki[i].punkty << endl;
    }    
}

void dodaj_wynik(wynik w)
{
    int i;
    
    for (i = 0; i < n; i++) {
        if (w.punkty > wyniki[i].punkty) {
            break;
        }
    }
    
    if (i == n) return;
    
    for (int j = n-1; j > i; j--) {
        wyniki[j] = wyniki[j-1];    
    }
    
    wyniki[i] = w;
}

int main()
{
    czytaj_wyniki();
    
    wypisz_wyniki();

    wynik test;
    cout << "punkty: "; cin >> test.punkty;
    cout << "imie: "; cin >> test.imie;
     
    dodaj_wynik(test);
     
    wypisz_wyniki();
     
    zapisz_wyniki();
}
