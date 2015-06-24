#ifndef CLSPLANSZA_H
#define CLSPLANSZA_H

#include<clsMenu.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "allegro5/allegro_image.h"

#include <iostream>
using namespace std;

class clsLudzik;
class clsSkrzynka;

class clsPlansza
{
//dane dotyczace okna i wyswietlania na oknie

    static const int k_sz = 32; //szerokosc kafelka
    static const int k_wy = 32;

    static const int intWiersze = 12;    //liczba wierszy planszy
    static const int intKolumny = 12;

    static const int intXStart = (((600 / k_wy) - intWiersze) / 2) * k_wy;  //wspolrzedna X gdzie ma zaczac wyswietlac plansze tak by byla na srodku
    static const int intYStart = (((1240 / k_sz) - intKolumny) / 2) * k_sz;

    enum typ_kafelka    //typ kafelkow
    {   podloga,
        sciana,
        ludzik,
        ludzikNaCelu,
        skrzynka,
        skrzynkaNaCelu,
        cel,
        puste,
        liczba_kafelkow
    };

    ALLEGRO_BITMAP* bitmapa[liczba_kafelkow]; //tabela z bitmapami

    static const string plik_z_kafelkiem[liczba_kafelkow]; //sciezka do bitmap

//tabele z danymi potrzebnymi do rysowania planszy
    int tblPodloga[intWiersze][intKolumny];//tabela z informacja czy to jest podloga 0, scioana 1 albo cel 6
    int tblSkrzynkiP[intWiersze][intKolumny];// tabela z informacja czy jest skrzynka 1, albo czy jej nie ma 0

//wspolrzedne ludzika
    int xLudzik;
    int yLudzik;

//ukonczone plansze
    int level;

    static const int intLiczbaPlansz = 5;
    bool *wskTblUkonczone = new bool[intLiczbaPlansz];

public:

//konstruktor
    clsPlansza(int x){ level = x; wskTblUkonczone += level - 1;}

    bool przygotuj_bitmapy();
    void rysuj_statyczne();
    void rysuj_ruchome(clsLudzik l, clsSkrzynka s, int wersja);

    void KonwertujDane();

    bool CzySaNieukonczone(int pintNumerPlanszy); //sprawdza czy sa jeszcze jakies nie ukonczone plansze

    int PozycjaLudzikaWiersz()  { return xLudzik;}
    int PozycjaLudzikaKolumna() { return yLudzik;}

    int get_tblPodloga(int x, int y) { return tblPodloga[x][y];}
    int get_tblSkrzynkiP(int x, int y) { return tblSkrzynkiP[x][y];}

    int get_intWiersze() {return intWiersze;}
    int get_intKolumny() {return intKolumny;}

    void ruchy(clsPlansza& plansza1, clsLudzik& on, clsSkrzynka& s);

    void set_tblUkonczone(bool wynik);
    bool get_tblUkonczone(int i) { return *wskTblUkonczone + i - 1;}
    int get_level() { return level;}
    void set_level(int _level) {level = _level;}

    int get_LiczbaPlansz() { return intLiczbaPlansz; }

    void WyswietlKomunikat(ALLEGRO_FONT* font, ALLEGRO_FONT* font2);
};
#endif // CLSPLANSZA_H
