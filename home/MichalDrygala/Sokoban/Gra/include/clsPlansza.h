#ifndef CLSPLANSZA_H
#define CLSPLANSZA_H

#include<clsMenu.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "allegro5/allegro_image.h"

//#include "clsObiektyRuchome.h"
#include "clsLudzik.h"

#include <iostream>
using namespace std;

class clsLudzik;
class clsSkrzynka;

class clsPlansza
{
//dane dotyczace okna i wyswietlania na oknie

    static const int k_sz = 32; //szerokosc kafelka
    static const int k_wy = 32;

    static const int intWiersze = 7;    //liczba wierszy planszy
    static const int intKolumny = 7;

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
        liczba_kafelkow
    };

    ALLEGRO_BITMAP* bitmapa[liczba_kafelkow]; //tabela z bitmapami

    static const string plik_z_kafelkiem[liczba_kafelkow]; //sciezka do bitmap

//tabele z danymi potrzebnymi do rysowania planszy

    char tblDane[intWiersze][intKolumny];   //tabela z # $ itp.
    int tblPodloga[intWiersze][intKolumny];//tabela z informacja czy to jest podloga 0, scioana 1 albo cel 6
    int tblSkrzynkiP[intWiersze][intKolumny];// tabela z informacja czy jest skrzynka 1, albo czy jej nie ma 0

//wspolrzedne ludzika
    int xLudzik;
    int yLudzik;


    //int intNumerPlanszy;
    //static bool tblnUkonczonePlansze[];
    //static int intLiczbaPlansz;

public:

    bool przygotuj_bitmapy();
    void rysuj_statyczne();
    void rysuj_ruchome(clsLudzik l, clsSkrzynka s, int wersja);

    void WczytajDane();
    void WypiszDane();
    void KonwertujDane();

    //void WyswietlMenu();
    bool CzySaNieukonczone(int pintNumerPlanszy); //sprawdza czy sa jeszcze jakies nie ukonczone plansze

    int PozycjaLudzikaWiersz()  { return xLudzik;}
    int PozycjaLudzikaKolumna() { return yLudzik;}

    int get_tblPodloga(int x, int y) { return tblPodloga[x][y];}
    int get_tblSkrzynkiP(int x, int y) { return tblSkrzynkiP[x][y];}

    int get_intWiersze() {return intWiersze;}
    int get_intKolumny() {return intKolumny;}

    void ruchy(clsPlansza& plansza1, clsLudzik& on, clsSkrzynka& s);
};
#endif // CLSPLANSZA_H
