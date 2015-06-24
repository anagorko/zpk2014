#ifndef CLSSKRZYNKA_H
#define CLSSKRZYNKA_H

#include <clsPlansza.h>
class clsPlansza;

class clsSkrzynka //: public clsObiektyRuchome
{
    static const int intWiersze = 7;
    static const int intKolumny = 7;

    int tblSkrzynkiS[intWiersze][intKolumny];

public:

    clsSkrzynka(clsPlansza p); //konstruktor
    //~clsSkrzynka(); //destruktor

    int get_tblSkrzynkiS(int x, int y) { return tblSkrzynkiS[x][y];}
    void set_tblSkrzynkiS(int x, int y, int wartosc) { tblSkrzynkiS[x][y] = wartosc;}



    //bool MozliwyRuch(char pchrKierunek);
    //void Ruch(int pintPozycjaWiersz, int pintPozycjaKolumna, char pchrKierunek);

    int CzyUkonczono(clsPlansza& p); // sprawdza czy ukonczona te plansze

static const string plik_z_grat[1];
ALLEGRO_BITMAP* wskGrat[1];
void WyswietlGrat();
void zwloka(int sekund);
};

#endif // CLSSKRZYNKA_H
