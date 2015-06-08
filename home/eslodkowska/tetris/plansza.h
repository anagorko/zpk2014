#ifndef __Plansza_H__
#define __Plansza_H__

#include<iostream>
#include<math.h>
using namespace std;

#include klocek.h

class Plansza
{
    public
    //wymiary planszy
    int wysokosc=20;
    int szerokosc=10;
    int punkty; //liczna punktów
    bool czy_kolizja(); //czy kolizja z innym klockiem lub sciana
    void usun_linie(); //usuwa linie i przesuwa klocki w dol
    void czy_cala_linia(); //sprawdza czy linia jest wypelniona
    bool czy_koniec_poziomu(); // sprawdza czy zgromadzono wystarczajaca liczbe punktow
    void pusta_plansza();
    void zapelnij_plansze();
    bool czy_przegrana();

    private
    int tablica [wysokosc][szerokosc];



};

#endif
