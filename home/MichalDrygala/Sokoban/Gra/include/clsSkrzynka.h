#ifndef CLSSKRZYNKA_H
#define CLSSKRZYNKA_H

#include<clsObiektyRuchome.h>

class clsSkrzynka //: public clsObiektyRuchome
{
    //int intPozycjaWiersz;
    //int intPozycjaKolumna;

    //tblSkrzynki

public:
    bool MozliwyRuch(char pchrKierunek);
    void Ruch(int pintPozycjaWiersz, int pintPozycjaKolumna, char pchrKierunek);

    bool CzyUkonczono();                // sprawdza czy ukonczona te plansze
};

#endif // CLSSKRZYNKA_H
