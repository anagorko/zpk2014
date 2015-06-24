#ifndef EKRANY_H_INCLUDED
#define EKRANY_H_INCLUDED

class Ekrany
{
    int Paliwo; // Pamieta ilosc paliwa ustawiona przy uruchomieniu gry
    float czas; // zapamietuje czas gry
    bool T, S; // Zmienne uzywane do dodawania/odejmowania paliwa
public:
    Ekrany();
    void MenuStart(); // Wyswietla menu glowne gry
    void Tankuj( bool t ); // Dodaje paliwa
    void Spuszczaj( bool s ); // Odejmuje paliwa
    void Stacja( int l ); // Wyswietla wybrana ilosc paliwa na ekranie
    void Przegrana( int _paliwo, bool predkosc ); // Sprawdza jaki jest powod przegranej i wyswietla stosowny ekran
    void Wygrana( double bonus, int _paliwo  ); // Oblicza ostateczna punktacje i wyswietla ekran
    int ilePaliwa(); // Zwraca ustawiona liczbe paliwa
    void Gra( ALLEGRO_FONT* czStatystyki, int _paliwo, float _czas ); // Aktualizuje statystyki podczas gry
};

#endif // EKRANY_H_INCLUDED
