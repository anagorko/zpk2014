#ifndef __Plansza_H__
#define __Plansza_H__

#include<iostream>
#include<math.h>
using namespace std;

#include "klocek.h"

class Plansza{

    public:
    int wysokosc; //=20;
    int szerokosc; //=10;
    double** tablica;
    int punkty; //liczba punktów

    //wymiary planszy
    Plansza(int w=20,int s=10,int p=0){
        wysokosc=w;
        szerokosc=s;
    //tablica=new double[w][s];
        punkty=p;
    }

    Klocek*k;

    bool czy_kolizja(int pX, int pY, int typ_klocka, int rotacja_klocka); //czy kolizja z innym klockiem lub sciana
    void usun_linie(int wiersz); //usuwa jedna linie i przesuwa klocki w dol
    void usun_mozliwe_linie();
    bool czy_cala_linia(int wiersz); //sprawdza czy linia jest wypelniona
    bool czy_koniec_poziomu(int poziom); // sprawdza czy zgromadzono wystarczajaca liczbe punktow
    void pusta_plansza();
    void zapelnij_plansze(int level);
    bool czy_przegrana();
    void umiesc_klocek(int pX, int pY, int typ_klocka,int rotacja_klocka);
    int losuj_liczbee(int a, int b);
};

#endif
