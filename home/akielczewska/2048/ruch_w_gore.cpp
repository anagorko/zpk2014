#include <iostream>
using namespace std;



int main() {
    // tablica 4x4
    int t[4][4];

    // wypelnienie tablicy przykladowymi liczbami
    // tutaj podstawialam sobie ró¿ne opcje, by sprawdzac poprawnosc funkcji
    t[0][0] = 2; t[0][1] = 0; t[0][2] = 4; t[0][3] = 8;
    t[1][0] = 2; t[1][1] = 2; t[1][2] = 4; t[1][3] = 2;
    t[2][0] = 4; t[2][1] = 2; t[2][2] = 2; t[2][3] = 4;
    t[3][0] = 4; t[3][1] = 2; t[3][2] = 16; t[3][3] = 4;

// wyswietlenie tablicy w konsoli
    cout << "Poczatkowa plansza:" << endl;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            cout << t[i][j] << " ";
        }
    cout << endl;
    }
    cout << endl;


    // przesuniecie w góre (bez sklejania)
    // kolejno dla ka¿dej kolumny j
    for (int j=0; j<4; j++) {
/* nie robie petli dla kazdego wiersza - bo i tak kazdy mialby inne warunki -
- inna liczbe wierszy pod soba */
    // przesuniêcie do pierwszego górnego wiersza:
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

    // wyswietlenie tablicy w konsoli
    cout << "Plansza po przesunieciu w gore:" << endl;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            cout << t[i][j] << " ";
        }
    cout << endl;
    }
    cout << endl;


    // sklejanie (i dociaganie tego co ponizej)
    // kolejno dla kazdej kolumny j
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
            t[2][j] = t[3][j] + t[4][j];
            t[3][j] = 0;
        }
    }


    // wyswietlenie tablicy w konsoli
    cout << "Plansza po doklejeniu w gore:" << endl;
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                cout << t[i][j] << " ";
            }
        cout << endl;
        }
        cout << endl;

}
