#include <iostream>
using namespace std;

int main() {
    // tablica 4x4
    int t[4][4];

    // wype³nienie tablicy przyk³adowymi liczbami - same zera
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            t[i][j] = 0;
        }
    }

/*
    // wype³nienie tablicy przyk³adowymi liczbami
    // tutaj podstawia³am sobie ró¿ne opcje, by sprawdzaæ poprawnoœæ funkcji
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            if (i%2 == 0) {
                if (j%2 == 0) t[i][j] = 2;
                else t[i][j] = 0;
            }
            else t[i][j] = 4;
        }
    } */

    // wype³nienie tablicy przyk³adowymi liczbami - inny sposób
    // tutaj podstawia³am sobie ró¿ne opcje, by sprawdzaæ poprawnoœæ funkcji
t[0][0] = 2;
t[0][1] = 0;
t[0][2] = 4;
t[0][3] = 2;
t[1][0] = 4;
t[1][1] = 0;
t[1][2] = 0;
t[1][3] = 0;
t[2][0] = 0;
t[2][1] = 4;
t[2][2] = 2;
t[2][3] = 0;
t[3][0] = 0;
t[3][1] = 2;
t[3][2] = 16;
t[3][3] = 0;

    // wyswietlenie tablicy w konsoli
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                cout << t[i][j] << " ";
            }
        cout << endl;
        }
        cout << endl;

    // przesuniêcie w górê (bez sklejania)
    // kolejno dla ka¿dej kolumny j
    for (int j=0; j<4; j++) {
/* nie robiê pêtli dla ka¿dego wiersza - bo i tak ka¿dy mia³by inne warunki -
- inn¹ liczbê wierszy pod sob¹ */
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

    // przesuniêcie do drugiego wiersza:
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

    // przesuniêcie do drugiego wiersza:
    if (t[2][j] == 0) {
        if (t[3][j] != 0) {
            t[2][j] = t[3][j];
            t[3][j] = 0;
        }
    }

    }


    // wyswietlenie tablicy w konsoli
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                cout << t[i][j] << " ";
            }
        cout << endl;
        }
        cout << endl;
}
