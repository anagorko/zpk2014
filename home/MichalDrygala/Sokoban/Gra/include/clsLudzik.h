#ifndef CLSLUDZIK_H
#define CLSLUDZIK_H

//#include <clsObiektyRuchome.h>
#include "clsPlansza.h"
class clsPlansza;

class clsLudzik //: public clsObiektyRuchome
{

    int intPozycjaWiersz;
    int intPozycjaKolumna;
    int intLiczbaRuchow = 0;
    int intEnergia = 100;

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
