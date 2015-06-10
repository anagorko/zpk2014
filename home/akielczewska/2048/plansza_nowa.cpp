#include <iostream>
#include <cstdlib> // losowanie liczb calkowitych
#include <ctime> // wyciaganie czasu rzeczywistego - zeby losowanie bylo losowe
using namespace std;

class Plansza {

    int t[4][4];


public:
    Plansza() {
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                t[i][j] = 0;
            }
        }
        //wynik = 0;
    }

    void ustawPozycjePoczatkowa();

    void wykonajRuch(s);

    void ustawLosowaLiczbe();

    int zawartoscPola(int w, int k);

    bool koniecGry();

    int wynik();

    void wyswietlWKonsoli(); //// na potrzeby testowania w trakcie pisania programu
};

void Plansza::wykonajRuch(s) {
    x = 0;
    int nr[16]; // do punumerowania pol od 1 do 16 w sposob zalezny od kierunku ruchu
    if (s == 1) { // w gore
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                x++;
                nr[x] =
            }
        }
    }

    // przesuniecie do pierwszego górnego wiersza:
    for (int j=0; j<4; j++) {
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
}

//sklejenie
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
    //cout << los << " " << nr << endl;
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
    //cout << los << " " << nr << endl;
}

void Plansza::wykonajRuchWGore() {
    przesunWGore();
    sklejWGore();
}

void Plansza::wykonajRuchWDol() {
    przesunWDol();
    sklejWDol();
}

void Plansza::wykonajRuchWLewo() {
    przesunWLewo();
    sklejWLewo();
}

void Plansza::wykonajRuchWPrawo() {
    przesunWPrawo();
    sklejWPrawo();
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
            }
            if (nr == l) {
                t[i][j] = 2;
            }
        }
    }
    //cout << los << " " << nr << endl;
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


int main() {
    Plansza gra;
    gra.wyswietlWKonsoli();
    srand( time( NULL ) ); // zeby losowanie bylo losowe
    gra.ustawPozycjePoczatkowa();
    gra.wyswietlWKonsoli();
    gra.wykonajRuchWPrawo();
    gra.wyswietlWKonsoli();
    gra.ustawLosowaLiczbe();
    gra.wyswietlWKonsoli();
    gra.wykonajRuchWLewo();
    gra.wyswietlWKonsoli();
    gra.ustawLosowaLiczbe();
    gra.wyswietlWKonsoli();
    gra.wykonajRuchWGore();
    gra.wyswietlWKonsoli();
    gra.ustawLosowaLiczbe();
    gra.wyswietlWKonsoli();
    gra.wykonajRuchWDol();
    gra.wyswietlWKonsoli();
}

