#ifndef __Gra_H__
#define __Gra_H__

#include<iostream>
#include<cmath>
#include<cstdlib>
#include<time.h>
using namespace std;

#include "klocek.h"
#include "plansza.h"

class Gra{

public:
// Gra (Plansza *p,Klocek *k);
//klocek obecny
    int typ_klocka;
    int rotacja_klocka;
    int pX;
    int pY;

 //klocek kolejny
    int n_typ_klocka;
    int n_rotacja_klocka;
    int n_pX;
    int n_pY;

    Klocek *k;
    Plansza *p;

    void generuj_klocek();
    void rozpocznij_gre();
    void rysuj_klocek();
    void rysuj_plasze();
    int losuj_liczbe(int a, int b);
};




#endif

