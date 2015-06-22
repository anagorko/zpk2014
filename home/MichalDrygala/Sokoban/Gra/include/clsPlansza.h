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
    static const int k_sz = 31;
    static const int k_wy = 31;

    static const int intWiersze = 7;
    static const int intKolumny = 7;

    char tblDane[intWiersze][intKolumny];
    int  tblPodloga[intWiersze][intKolumny];

    int xLudzik;
    int yLudzik;

    int tblSkrzynki[intWiersze][intKolumny];

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
    ALLEGRO_BITMAP* bitmapa[2 * liczba_kafelkow];

    static const string plik_z_kafelkiem[2 * liczba_kafelkow];

    int intNumerPlanszy;

    static bool tblnUkonczonePlansze[];
    static int intLiczbaPlansz;

public:

    bool przygotuj_bitmapy();
    void rysuj_statyczne();
    void rysuj_ruchome(int);

    void WczytajDane();
    void WypiszDane();
    void KonwertujDane();

    void WyswietlMenu();
    void Ukonczono(int pintNumerPlanszy);
    bool CzySaNieukonczone(int pintNumerPlanszy); //sprawdza czy sa jeszcze jakies nie ukonczone plansze

    int PozycjaLudzikaWiersz()  { return xLudzik;}
    int PozycjaLudzikaKolumna() { return yLudzik;}
};

#endif // CLSPLANSZA_H
