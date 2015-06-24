#ifndef CLSSKRZYNKA_H
#define CLSSKRZYNKA_H

#include <clsPlansza.h>
class clsPlansza;

class clsSkrzynka
{
    static const int intWiersze = 12;
    static const int intKolumny = 12;

    int tblSkrzynkiS[intWiersze][intKolumny];

    static const string plik_z_grat[1];
    ALLEGRO_BITMAP* wskGrat[1];

public:

    clsSkrzynka(clsPlansza p); //konstruktor

    int get_tblSkrzynkiS(int x, int y) { return tblSkrzynkiS[x][y];}
    void set_tblSkrzynkiS(int x, int y, int wartosc) { tblSkrzynkiS[x][y] = wartosc;}

    int CzyUkonczono(clsPlansza& p); // sprawdza czy ukonczona te plansze

    void WyswietlGrat();
    void zwloka(int sekund);
};

#endif // CLSSKRZYNKA_H
