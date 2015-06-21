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
        //intLiczbaRuchów++;

    bool ObokSkrzynka(int pintPozycjaWiersz, int pintPozycjaKolumna, char pchrKierunek);
        //clsSkrzynka::Ruch();
    bool SprawdzEnergie(int pintEnergia);
};

#endif // CLSLUDZIK_H
