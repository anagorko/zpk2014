#ifndef CLSLUDZIK_H
#define CLSLUDZIK_H

#include "clsPlansza.h"
class clsPlansza;

class clsLudzik
{
    int intPozycjaWiersz;
    int intPozycjaKolumna;
    int intEnergia = -5;

public:
//konstruktor
    clsLudzik(int x, int y);

    void set_X(int x){ intPozycjaWiersz = x; }
    void set_Y(int y){ intPozycjaKolumna = y; }
    void set_energia(int energia){ intEnergia = energia; }

    int get_X(){ return intPozycjaWiersz;}
    int get_Y(){ return intPozycjaKolumna; }
    int get_energia(){ return intEnergia; }

};

#endif // CLSLUDZIK_H
