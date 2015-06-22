#ifndef CLSPLANSZA_H
#define CLSPLANSZA_H

#include<clsMenu.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "allegro5/allegro_image.h"

#include "clsObiektyRuchome.h"
#include "clsLudzik.h"

#include <iostream>
using namespace std;

class clsPlansza
{
    static const int sz = 12; //szrokosc kafelka
    static const int wy = 12;  //wysokosc kafelka

    static const int k_sz = 32;
    static const int k_wy = 32;

    static const int intWiersze = 7;
    static const int intKolumny = 7;

enum typ_kafelka
{
    podloga,
    sciana,
    ludzik,
    ludzikNaCelu,
    skrzynka,
    skrzynkaNaCelu,
    cel,
    liczba_kafelkow
};

/*
struct kafelek
{
    enum typ_kafelka typ;
    //int wariant;
};
*/

    ALLEGRO_BITMAP* bitmapa[liczba_kafelkow];

    static const string plik_z_kafelkiem[liczba_kafelkow];

/*
struct plansza
{
    struct kafelek podloga[sz][wy];
    struct kafelek sciana[sz][wy];
    struct kafelek ludzik[sz][wy];
    struct kafelek ludzikNaCelu[sz][wy];
    struct kafelek skrzynka[sz][wy];
    struct kafelek skrzynkaNaCelu[sz][wy];
    struct kafelek cel[sz][wy];
};
*/

    int intNumerPlanszy;

    static bool tblnUkonczonePlansze[];
    static int intLiczbaPlansz;

    char tblDane[7][7];
    int  tblDaneLiczby[7][7];

public:

    bool przygotuj_bitmapy();
    void przygotuj_plansze();
    void rysuj_plansze();

    void WczytajDane();
    void WypiszDane();
    void KonwertujDane();

    void WyswietlMenu();
    void Ukonczono(int pintNumerPlanszy);
    bool CzySaNieukonczone(int pintNumerPlanszy); //sprawdza czy sa jeszcze jakies nie ukonczone plansze

    int PozycjaLudzikaWiersz();
    int PozycjaLudzikaKolumna();
};

#endif // CLSPLANSZA_H
