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

void set_X(int x){
    intPozycjaWiersz = x;
}

void set_Y(int y){
    intPozycjaKolumna = y;
}

int get_X(){
    return intPozycjaWiersz;
}

int get_Y(){
    return intPozycjaKolumna;
}

void set_energia(int energia){
    intEnergia = energia;
}

int get_energia(){
    return intEnergia;
}

void ruchy();

    bool MozliwyRuch(char pchrKierunek); //tblPodloga

    void Ruch(char chrKierunek);
        //intLiczbaRuchów++;

    bool ObokSkrzynka(int pintPozycjaWiersz, int pintPozycjaKolumna, char pchrKierunek); //tblSkrzynka



};

#endif // CLSLUDZIK_H
