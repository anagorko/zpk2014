#include <iostream>
#include <cstdlib> // losowanie liczb calkowitych
#include <ctime> // wyciaganie czasu rzeczywistego - zeby losowanie bylo losowe
using namespace std;

class Plansza {

    int t[4][4];

    int wynik = 0;

    void obrocO90Stopni();

public:
    Plansza() {
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                t[i][j] = 0;
            }
        }
    }

    void ustawPozycjePoczatkowa();

    void wykonajRuch(int kierunek);

    void ustawLosowaLiczbe();

    int zawartoscPola(int w, int k);

    bool koniecGry();

    int podajWynik();

    void wyswietlWKonsoli(); //// na potrzeby testowania w trakcie pisania programu

};

void Plansza::obrocO90Stopni() {
    int tk[4][4]; // kopia planszy t - obrot
    tk[0][0] = t[0][3];
    tk[1][0] = t[0][2];
    tk[2][0] = t[0][1];
    tk[3][0] = t[0][0];
    tk[0][1] = t[1][3];
    tk[1][1] = t[1][2];
    tk[2][1] = t[1][1];
    tk[3][1] = t[1][0];
    tk[0][2] = t[2][3];
    tk[1][2] = t[2][2];
    tk[2][2] = t[2][1];
    tk[3][2] = t[2][0];
    tk[0][3] = t[3][3];
    tk[1][3] = t[3][2];
    tk[2][3] = t[3][1];
    tk[3][3] = t[3][0];


    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            t[i][j] = tk[i][j];
        }
    }
}

void Plansza::wykonajRuch(int kierunek) {
    if (kierunek == 1) { // ruch w gore
    }
    else if (kierunek == 2) { // ruch w prawo
        obrocO90Stopni();
    }
    else if (kierunek == 3) { // ruch w dol
        obrocO90Stopni();
        obrocO90Stopni();
    }
    else if (kierunek == 4) { // ruch w lewo
        obrocO90Stopni();
        obrocO90Stopni();
        obrocO90Stopni();
    }
    // Ruch w gore
    for (int j=0; j<4; j++) {
        // przesuniecie do pierwszego górnego wiersza:
        if (t[0][j] == 0) {
            if (t[1][j] != 0) {
                t[0][j] = t[1][j];
                t[1][j] = 0;
            }
            else if (t[2][j] != 0) {
                t[0][j] = t[2][j];
                t[2][j] = 0;
            }
            else if (t[3][j] != 0) {
                t[0][j] = t[3][j];
                t[3][j] = 0;
            }
        }
        // przesuniecie do drugiego wiersza:
        if (t[1][j] == 0) {
            if (t[2][j] != 0) {
                t[1][j] = t[2][j];
                t[2][j] = 0;
            }
            else if (t[3][j] != 0) {
                t[1][j] = t[3][j];
                t[3][j] = 0;
            }
        }
        // przesuniecie do trzeciego wiersza:
        if (t[2][j] == 0) {
            if (t[3][j] != 0) {
                t[2][j] = t[3][j];
                t[3][j] = 0;
            }
        }

    }


    // sklejanie w gore
    for (int j=0; j<4; j++) {
        if (t[0][j] == t[1][j] & t[2][j] != t[3][j]) {
            t[0][j] = t[0][j] + t[1][j];
            t[1][j] = t[2][j];
            t[2][j] = t[3][j];
            t[3][j] = 0;
        }
        else if (t[0][j] == t[1][j] & t[2][j] == t[3][j]) {
            t[0][j] = t[0][j] + t[1][j];
            t[1][j] = t[2][j] + t[3][j];
            t[2][j] = 0;
            t[3][j] = 0;
        }
        else if (t[1][j] == t[2][j]) {
            t[1][j] = t[1][j] + t [2][j];
            t[2][j] = t[3][j];
        }
        else if (t[2][j] == t[3][j]) {
            t[2][j] = t[2][j] + t[3][j];
            t[3][j] = 0;
        }
    }
    if (kierunek == 1) { // ruch w gore
    }
    else if (kierunek == 2) { // ruch w prawo
        obrocO90Stopni();
        obrocO90Stopni();
        obrocO90Stopni();
    }
    else if (kierunek == 3) { // ruch w dol
        obrocO90Stopni();
        obrocO90Stopni();
    }
    else if (kierunek == 4) { // ruch w lewo
        obrocO90Stopni();
    }

}


void Plansza::ustawPozycjePoczatkowa() {
    // ustawienie pierwszej liczby
    int los = std::rand();
    int nr = los%16;
    int l = -1;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            l++;
            if (nr == l) {
                t[i][j] = 2;
            }
        }
    }
    // ustawienie drugiej liczby
    los = std::rand();
    nr = los%15;
    l = -1;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            if (t[i][j] == 0) {
                l++;
            }
            if (nr == l) {
                t[i][j] = 2;
            }
        }
    }
    wynik += 4;
}


void Plansza::ustawLosowaLiczbe() {
    int ile = 0; // zwraca liczbe pustych pol
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            if (t[i][j] == 0) {
                ile++;
            }
        }
    }
    int los = std::rand();
    int nr = los%ile;
    int l = -1;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            if (t[i][j] == 0) {
                l++;
                if (nr == l) {
                    t[i][j] = 2;
                }
            }
        }
    }
    wynik += 2;
}

int Plansza::zawartoscPola(int w, int k) {
    // wiersze i kolumny numerujemy od 1 do 4
    return t[w-1][k-1];
}

void Plansza::wyswietlWKonsoli() {
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            cout << t[i][j] << " ";
        }
    cout << endl;
    }
    cout << endl;
}

bool Plansza::koniecGry() {
    bool k = true;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            if (t[i][j] == 0) k = false;
        }
    }
    return k;
}

int Plansza::podajWynik() {
    return wynik;
}

int main() {
    Plansza gra;
    gra.wyswietlWKonsoli();
    srand( time( NULL ) ); // zeby losowanie bylo losowe
    gra.ustawPozycjePoczatkowa();
    gra.wyswietlWKonsoli();
    for (int i = 1; i < 5; i++) {
        gra.wykonajRuch(1);
        gra.wyswietlWKonsoli();
        gra.ustawLosowaLiczbe();
        gra.wyswietlWKonsoli();
        gra.wykonajRuch(2);
        gra.wyswietlWKonsoli();
        gra.ustawLosowaLiczbe();
        gra.wyswietlWKonsoli();
        gra.wykonajRuch(3);
        gra.wyswietlWKonsoli();
        gra.ustawLosowaLiczbe();
        gra.wyswietlWKonsoli();
        gra.wykonajRuch(4);
        gra.wyswietlWKonsoli();
        gra.ustawLosowaLiczbe();
        gra.wyswietlWKonsoli();
    }







}
