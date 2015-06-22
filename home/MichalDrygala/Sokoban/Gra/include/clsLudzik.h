#ifndef CLSLUDZIK_H
#define CLSLUDZIK_H

#include <clsObiektyRuchome.h>
#include "clsPlansza.h"

class clsLudzik //: public clsObiektyRuchome
{
    int intPozycjaWiersz;
    int intPozycjaKolumna;
    int intLiczbaRuchow = 0;
    int intEnergia = 100;

public:

//konstruktor
    clsLudzik(int x, int y)
    {
        intPozycjaWiersz = x;
        intPozycjaKolumna = y;
    }

    bool MozliwyRuch(char pchrKierunek);

    void Ruch(char chrKierunek);
        //intLiczbaRuchów++;

    bool ObokSkrzynka(int pintPozycjaWiersz, int pintPozycjaKolumna, char pchrKierunek);
        //clsSkrzynka::Ruch();
    bool SprawdzEnergie(int pintEnergia);
};

#endif // CLSLUDZIK_H
