#ifndef __Plansza_H__
#define __Plansza_H__

#include<iostream>
#include<math.h>
#include<cstdlib>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
using namespace std;

#include "klocek.h"

class Plansza{

    public:
    int wysokosc; //=20;
    int szerokosc; //=10;
    double tablica[17][13];
    int punkty; //liczba punktów

    //wymiary planszy
    Plansza(int w=17,int s=13,int p=0){
        wysokosc=w;
        szerokosc=s;
    //tablica=new double[w][s];
        punkty=p;
    }

    Klocek *k;

    bool czy_kolizja(int pX, int pY, int typ_klocka, int rotacja_klocka); //czy kolizja z innym klockiem lub sciana
    void usun_linie(int wiersz); //usuwa jedna linie i przesuwa klocki w dol
    void usun_mozliwe_linie();
    bool czy_cala_linia(int wiersz); //sprawdza czy linia jest wypelniona
    bool czy_koniec_poziomu(int poziom); // sprawdza czy zgromadzono wystarczajaca liczbe punktow
    void pusta_plansza();
    void zapelnij_plansze(int level);
    bool czy_przegrana();
    void umiesc_klocek(int pX, int pY, int typ_klocka, int rotacja_klocka);
    int losuj_liczbee(int a, int b);
    void rysuj_plansze();
    //all_init_primitives_addon();
};

#endif
