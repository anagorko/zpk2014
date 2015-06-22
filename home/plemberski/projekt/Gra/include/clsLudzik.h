#ifndef CLSLUDZIK_H
#define CLSLUDZIK_H

#include<clsObiektyRuchome.h>

class clsLudzik : public clsObiektyRuchome
{
    int intPozycjaWiersz;
    int intPozycjaKolumna;
    int intLiczbaRuchow;
    int intEnergia;

public:
    bool MozliwyRuch(int pintPozycjaWiersz, int pintPozycjaKolumna, char pchrKierunek);
    void Ruch(int pintPozycjaWiersz, int pintPozycjaKolumna, char pchrKierunek);
        //intLiczbaRuch�w++;

    bool ObokSkrzynka(int pintPozycjaWiersz, int pintPozycjaKolumna, char pchrKierunek);
        //clsSkrzynka::Ruch();
    bool SprawdzEnergie(int pintEnergia);
  clsLudzik(int x = 5, int y = 5, int ruchy = 0, int energia = 10);
};

#endif // CLSLUDZIK_H
