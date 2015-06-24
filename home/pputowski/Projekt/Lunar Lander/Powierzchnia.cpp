#include "Powierzchnia.h"

Powierzchnia::Powierzchnia()
{
/* Funkcja losuje plansze:
1. Losowane sa punkty w ktorych nastapi zmiana trendu.
2. Trend zawsze wystepuje w kolejnosci: plasko, gorka, plasko, dolek, plasko itd.
3. Wielkosc bonusu jest zalezna od odleglosci od lewej krawedzi ekranu
4. Bonusy wystepuja tylko na plaskich powierzchniach dluzszych niz 8 pikseli
*/
    int punktyZwrotne [screen_w][2]; //0 - miesca zmian; 1 - dlugosc trendu
    int zmiana = 1;
    bool gorka, dolek;
    int bonus = 0;
    punktyZwrotne[0][0] = 1;
    // Ustawienie losowosci
    srand( time( NULL ) );
    powierzchnia[0][0] = 600;
    while( punktyZwrotne[zmiana - 1][0] < screen_w ){
        punktyZwrotne[zmiana][0] = punktyZwrotne[zmiana - 1][0] + rand() % 200; // pkt zwrotny trendu,
        //  trend trwa maksymalnie 200 pikseli
        punktyZwrotne[zmiana][1] = punktyZwrotne[zmiana][0] - punktyZwrotne[zmiana - 1][0]; // obliczenie dlugosci trendu
        // Jezeli zmiana nieparzysta -> plaski teren
        // podzielna przez 2 ale nie przez 4 -> dolek
        // podzielna przez 4 -> gorka
        if( zmiana % 2 == 0 )
            if( zmiana % 4 == 0 )
                gorka = false;
            else
                dolek = false;
        else{
            dolek = true;
            gorka = true;
        }
        for( int i = punktyZwrotne[zmiana - 1][0]; i < min( punktyZwrotne[zmiana][0], screen_w ); i++ ){
             powierzchnia[i][0] = min( powierzchnia[i-1][0] + dolek * ( rand() % 3 ) - gorka * ( rand() % 3 ), screen_h - 10.0 );
             if( dolek && gorka && punktyZwrotne[zmiana - 1][1] > 8 ) // warunek na przydzielenie bonusu
                powierzchnia[i][2] = 10 * ( i == punktyZwrotne[zmiana - 1][0] + punktyZwrotne[zmiana - 1][1] / 2 ) + bonus;
                // W przypadku gdy jest srodek danego bonusu wartosc bonusu jest +10 na potrzeby pozniej rysowania planszy
            else
                powierzchnia[i][2] = 1;
            bonus = ( i + 300 ) / 300;
        }
        zmiana ++;

    }
}
void Powierzchnia::RysujPowierzchnie( int czas, bool zoom )
{
/* Plansza jest rysowana wraz z bonusami w przypadku gdy wartosc bonusu > 10 to jest znak, ¿e nale¿y wypisaæ na ekran wartosc bonusu
*/
    char strBonusy [3];
    ALLEGRO_FONT *czBonusy = al_load_ttf_font("OpenSans-Light.ttf", zoom * 15 + 15, NULL);
    al_clear_to_color( al_map_rgb( 0, 0, 30 ) );
    for( int i = 1; i < screen_w; i++ ){
        al_draw_line( i - 1, powierzchnia[i - 1][0 + 3 * zoom], i, powierzchnia[i][0 + 3 * zoom], al_map_rgb(254,254,254),1);
        if( powierzchnia[i][2 + 3 * zoom] > 11 ){
            sprintf( strBonusy, "%0.0f x", powierzchnia[i][2 + 3 * zoom] - 10 );
            // Bonusy rysowane sa pod plansza chyba ze wyjda po za ekran wtedy nad plansza
            al_draw_text( czBonusy, al_map_rgb( 255, 255, 255 ), i
                         , powierzchnia[i][0 + 3 * zoom] + ( ( powierzchnia[i][0 + 3 * zoom] + 35 ) < screen_h ) * 20
                            - ( powierzchnia[i][0 + 3 * zoom] + 35 >= screen_h ) * 20, ALLEGRO_ALIGN_CENTRE, strBonusy );
        }
        // Efekt wizualny pozwala pokazac jak powstaje plansza piksel po pikselu
        if( czas != 0 ){
            Sleep( czas );
            al_flip_display();
        }
    }
    al_destroy_font( czBonusy );
}
void Powierzchnia::obliczOdleglosci( Statek* s, bool zoom )
{
    double najnizszeX = 0;
    double najnizszeY = 0;
    for( int i = 0; i < 9; i++ ){ // Znalezienie najnizszego punktu statku
        najnizszeY = max( s -> WspolStatku( i, 1 ), najnizszeY );
        if( najnizszeY == s -> WspolStatku( i, 1 ) )
            najnizszeX = s -> WspolStatku( i, 0 );
    }
    int najnizszeXint = static_cast<int>( najnizszeX );
    // Obliczenie odleglosci najnizszego pkt statku od kazdego miejsca na powierzchni
    for( int i = 0; i < screen_w; i++ ){
        powierzchnia[i][1 + 3 * zoom] = sqrt( ( najnizszeX - i ) * ( najnizszeX - i )
                                             + ( najnizszeY - powierzchnia[i][0 + 3 * zoom]
                                            ) * ( najnizszeY - powierzchnia[i][0 + 3 * zoom] ) );
        if( i == najnizszeXint && powierzchnia[i][0 + 3 * zoom] < najnizszeY ){
            powierzchnia[i][1 + 3 * zoom] = - 1000; // Zabezpieczenie gdyby np. po przyblizeniu statek znalazl sie pod powierzchnia
        }
    }
}
double Powierzchnia::Zblizenie( int skala, int x )
{
    x = x - ( screen_w / skala ) / 2; // obliczenie gdzie wypadnie lewa krawedz ekranu po przyblizeniu wzgledem calej planszy
    if( x < 0 ){ // Zabezpieczenie gdyby wypadlo po za ekranem
        x = 0;
    }
    if( x + ( screen_w / skala ) > screen_w ){
        x = screen_w - ( screen_w / skala ) - 1;
    }
    double minimumY = screen_h - powierzchnia[x][0];
    double maximumY = screen_h - powierzchnia[x][0];
    for( int i = x + 1; i < x + screen_w / skala; i++ ){ // odnalezeienie minimum i maksimum planszy potrzebnego do przeskalowania
        minimumY = min( minimumY, screen_h - powierzchnia[i][0] );
        maximumY = max( maximumY, screen_h - powierzchnia[i][0] );
    }
    double stosunek = maximumY / minimumY;

    int iteracja;
    // Rozpisanie przeskalowanych wspolrzednych przyblizonej planszy
    // punkty zmiana wartosci Y nastepuje co wartosc skali
    for( int i = 0; i < ( screen_w / skala ); i++ ){
        iteracja = skala;
        while( iteracja > 0 ){
            powierzchnia[skala * i - iteracja + skala][3] = screen_h -
                                                                stosunek * ( screen_h - powierzchnia[i + x][0] )
                                                                + stosunek * minimumY;
                if( iteracja != skala && powierzchnia[i + x][2] > 10 )
                    powierzchnia[skala * i - iteracja + skala][5] = powierzchnia[i + x][2] - 10;
                else
                    powierzchnia[skala * i - iteracja + skala][5] = powierzchnia[i + x][2];
            iteracja --;
            }
    }
    return x;
}
double Powierzchnia::sprawdzOdleglosci( bool zoom )
{
// Wybranie sposrod wszystkich obliczonych odleglosci wartosci najmniejszej
    double minimum = screen_h;
    for( int i = 0; i < screen_w; i++ ){
        minimum = min( powierzchnia[i][1 + 3 * zoom], minimum );
    }
    return minimum;
}
double Powierzchnia::bonus( double _x, bool zoom )
{
// Wyciagniecie wartosci bonusu pod statkiem
    int _xx = static_cast<int>( _x );
    return powierzchnia[_xx][2 + 3 * zoom];
}
double Powierzchnia::wysokosc( double _x, bool zoom )
{
// Zwrocenie wysokosci statku nad powierzchnia
    int _xx = static_cast<int>( _x );
    return powierzchnia[_xx][0 + 3 * zoom];
}
int Powierzchnia::sprawdzWygrana( Statek* s )
{
// Sprawdzenie ktory punkt statku dotyka powierzchni
    int wynik = -1;
    int _x = -1;
    for( int i = 0; i < 9; i++ ){
        _x = static_cast<int>( s -> WspolStatku( i, 0 ) );
        if( _x > 0 && _x < screen_w ){
            if( s -> WspolStatku( i, 1 ) > powierzchnia[_x][3] - 1 ){
                wynik = i;
                break;
            }
        }
    }
    return wynik;
}
Powierzchnia::~Powierzchnia()
{
    delete powierzchnia;
}
