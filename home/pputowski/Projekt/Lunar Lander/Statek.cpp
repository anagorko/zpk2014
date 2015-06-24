#include "Statek.h"

Statek::Statek()
{
    Restart( 500000 );
}
void Statek::obliczWspol( double x, double y, double skala )
{
    punkty[9][0] = x;
    punkty[9][1] = y;

    punkty[0][0] = punkty[9][0] - skala * 10;
    punkty[0][1] = punkty[9][1] + skala * 12.5;

    punkty[1][0] = punkty[9][0] - skala * 3;
    punkty[1][1] = punkty[9][1] + skala * 12.5;

    punkty[2][0] = punkty[9][0] - skala * 3;
    punkty[2][1] = punkty[9][1] + skala * 7.5;

    punkty[3][0] = punkty[9][0] + skala * 3;
    punkty[3][1] = punkty[9][1] + skala * 7.5;

    punkty[4][0] = punkty[9][0] + skala * 3;
    punkty[4][1] = punkty[9][1] + skala * 12.5;

    punkty[5][0] = punkty[9][0] + skala * 10;
    punkty[5][1] = punkty[9][1] + skala * 12.5;

    punkty[6][0] = punkty[9][0] + skala * 10;
    punkty[6][1] = punkty[9][1] - skala * 2.5;

    punkty[7][0] = punkty[9][0];
    punkty[7][1] = punkty[9][1] - skala * 12.5;

    punkty[8][0] = punkty[9][0] - skala * 10;
    punkty[8][1] = punkty[9][1] - skala * 2.5;

    plomien[0][0] = punkty[0][0];
    plomien[0][1] = punkty[0][1] + skala * 3;

    plomien[1][0] = punkty[1][0];
    plomien[1][1] = punkty[1][1] + skala * 3;

    plomien[2][0] = punkty[1][0];
    plomien[2][1] = punkty[1][1] + skala * 10;

    plomien[3][0] = punkty[4][0];
    plomien[3][1] = punkty[4][1] + skala * 3;

    plomien[4][0] = punkty[5][0];
    plomien[4][1] = punkty[5][1] + skala * 3;

    plomien[5][0] = punkty[4][0];
    plomien[5][1] = punkty[4][1] + skala * 10;
}
void Statek::WyczyscStatek()
{
    for( int i = 1; i < 10; i++ ){
        if( i == 9 )
            al_draw_line( punkty[i-1][0], punkty[i-1][1], punkty[0][0], punkty[0][1], al_map_rgb( 0, 0, 30 ), 1 );
        else
            al_draw_line( punkty[i-1][0], punkty[i-1][1], punkty[i][0], punkty[i][1], al_map_rgb( 0, 0, 30 ), 1 );
    }
}
void Statek::WyswietlStatek()
{
    for( int i = 1; i < 10; i++ ){
        if( i == 9 )
            al_draw_line( punkty[i-1][0], punkty[i-1][1], punkty[0][0], punkty[0][1], al_map_rgb( 254, 254, 254 ), 1 );
        else
            al_draw_line( punkty[i-1][0], punkty[i-1][1], punkty[i][0], punkty[i][1], al_map_rgb( 254, 254, 254 ), 1 );
    }
}
void Statek::ObrocStatek( double x )
{
    // Statek obraca sie tylko jezeli ma jeszcze paliwo
    if( paliwo > 0 ){
        for( int i = 0; i < 9; i++ ){
            // Obrot wzgledem srodka ( przesuniecie statku do poczatku ukladu wspol., obrot i oddalenie
            punkty[i][0] = ( punkty[i][0] - punkty[9][0] ) * cos( x ) - ( punkty[i][1] - punkty[9][1] ) * sin( x ) + punkty[9][0];
            punkty[i][1] = ( punkty[i][0] - punkty[9][0] ) * sin( x ) + ( punkty[i][1] - punkty[9][1] ) * cos( x ) + punkty[9][1];
            if( i < 6 ) {
                plomien[i][0] = ( plomien[i][0] - punkty[9][0] ) * cos( x ) - ( plomien[i][1] - punkty[9][1] ) * sin( x ) + punkty[9][0];
                plomien[i][1] = ( plomien[i][0] - punkty[9][0] ) * sin( x ) + ( plomien[i][1] - punkty[9][1] ) * cos( x ) + punkty[9][1];
            }
        }
        // dodanie wartosci obrotu do zmiennej kat, oraz zwiekszenie liczby obrotow
        kat = kat + x;
        if( x > 0 )
            sumaObrotowPlus++;
        if( x < 0 )
            sumaObrotowMinus++;
        // Spalanie paliwa
        paliwo = paliwo - 5 * prawo - 5 * lewo;
    }
}
void Statek::PchnijStatek()
{
    // przemieszczenie sie statku pod warunkiem ze jest jeszcze paliwo
    if( paliwo > 0 ){
        if( bezwladnoscX < skala * 0.6 && bezwladnoscX > skala * -0.6 )
            bezwladnoscX = bezwladnoscX + skala * cos( kat ) * 0.002;
        if( ( bezwladnoscY > skala * -0.3 && skala * sin( kat ) < 0 ) || ( bezwladnoscY < skala * 0.6 && skala * sin( kat ) > 0 ) )
            bezwladnoscY = bezwladnoscY + skala * sin( kat ) * 0.004;
        paliwo = paliwo - 39 * go;
    }
}
double Statek::WspolStatku( int x, int y )
{
    return punkty[x][y];
}
void Statek::Grawitacja( const float &_czas )
{
    /* Najpierw sprawdzane jest czy srodek statku nie wyleci za ekran ale tylko i wylacznie gdy nie jest obraz w zblizeniu
    jezeli ma wyleciec to ustawiana jest predkosc na zero
    w przeciwnym przypadku statek traci na pedzie
    nastepnie oszacowana wartosc pedu dodawana jest do wspolrzednych statku i plomieni */
    if( punkty[9][1] + bezwladnoscY < screen_h && punkty[9][1] + bezwladnoscY > 0 || zoomS ){
        if( bezwladnoscY < skala * 0.35 )
            bezwladnoscY = bezwladnoscY + skala * 0.0004;
    }else
        bezwladnoscY = 0;
    if( punkty[9][0] + bezwladnoscX < screen_w && punkty[9][0] + bezwladnoscX > 0 || zoomS ){
        if( bezwladnoscX > 0 )
            bezwladnoscX = bezwladnoscX - skala * 0.0004;
        if( bezwladnoscX < 0 )
            bezwladnoscX = bezwladnoscX + skala * 0.0004;
    }else
        bezwladnoscX = 0;
    for( int i = 0; i < 10; i++ ){
        punkty[i][1] = punkty[i][1] + bezwladnoscY;
        punkty[i][0] = punkty[i][0] + bezwladnoscX;
        if( i < 6 ){
            plomien[i][1] = plomien[i][1] + bezwladnoscY;
            plomien[i][0] = plomien[i][0] + bezwladnoscX;
        }
    }
    // co 0.05 sekundy odswierzana jest wartosc paliwa
    if( _czas > czas + 0.05 ){
        czas = _czas;
        if( paliwo > 0 )
            paliwo = paliwo - 1;
        else
            paliwo = 0;
    }
}
void Statek::Lec( bool przod ){ go = przod; }
void Statek::Lewo( bool L ){ lewo = L; }
void Statek::Prawo( bool P ){ prawo = P; }
void Statek::Ruch( const float &_czas )
{
    // Najpierw kasowany jest plomien statku pozniej statek jest przemieszczany i znow jest plomien rysowany pod warunkiem
    // ze statek jest napedzany dalej odpalane sa wszystkie funkcje zwiazane z przemieszczaniem
    al_draw_triangle( plomien[0][0], plomien[0][1], plomien[1][0], plomien[1][1], plomien[2][0], plomien[2][1]
                     , al_map_rgb( 0, 0, 30 ), 3 );
    al_draw_triangle( plomien[3][0], plomien[3][1], plomien[4][0], plomien[4][1], plomien[5][0], plomien[5][1]
                     , al_map_rgb( 0, 0, 30 ), 3 );
    if( go ){
        PchnijStatek();
        if( paliwo > 0 ){
            al_draw_triangle( plomien[0][0], plomien[0][1], plomien[1][0], plomien[1][1], plomien[2][0], plomien[2][1]
                             , al_map_rgb( 254, 0, 0 ), 1 );
            al_draw_triangle( plomien[3][0], plomien[3][1], plomien[4][0], plomien[4][1], plomien[5][0], plomien[5][1]
                             , al_map_rgb( 254, 0, 0 ), 1 );
        }
    }
    ObrocStatek( prawo * 0.006 - lewo * 0.006 );
    Grawitacja( _czas );
}
void Statek::Restart( int _paliwo )
{
    // Ustawienie wszysztkich zmiennych
    obliczWspol( 20.0, 20.0, 1 );
    kat = M_PI * 3 / 2;
    bezwladnoscX = 0;
    bezwladnoscY = 0;
    lewo = false;
    prawo = false;
    go = false;
    paliwo = _paliwo;
    sumaObrotowMinus = 0;
    sumaObrotowPlus = 0;
    zoomS = false;
    skala = 1;
    czas = 0;
}

void Statek::Zblizenie( double x, double y, double _skala )
{
    // Najpierw skalowany jest ped jaki posiada statek
    if( _skala == 1 ){
        bezwladnoscX = bezwladnoscX / skala;
        bezwladnoscY = bezwladnoscY / skala;
        zoomS = false;
    }else{
        bezwladnoscX = bezwladnoscX * _skala;
        bezwladnoscY = bezwladnoscY * _skala;
        zoomS = true;
    }
    skala = _skala;

    obliczWspol( x, y, skala ); // Obliczane sa nowe wspolrzedne statku
    double k = 0.006; // Wartosc wspolczynnika obrotu musi byc taki sam jak w funkcji Obrot()
    // Obracanie statatku az do otrzymania pozycji sprzed obrotow najpierw w prawo pozniej w lewo
    for( int o = 0; o < sumaObrotowPlus; o++ )
        for( int i = 0; i < 9; i++ ){
            punkty[i][0] = ( punkty[i][0] - punkty[9][0] ) * cos( k ) - ( punkty[i][1] - punkty[9][1] ) * sin( k ) + punkty[9][0];
            punkty[i][1] = ( punkty[i][0] - punkty[9][0] ) * sin( k ) + ( punkty[i][1] - punkty[9][1] ) * cos( k ) + punkty[9][1];
            if( i < 6 ) {
                plomien[i][0] = ( plomien[i][0] - punkty[9][0] ) * cos( k ) - ( plomien[i][1] - punkty[9][1] ) * sin( k ) + punkty[9][0];
                plomien[i][1] = ( plomien[i][0] - punkty[9][0] ) * sin( k ) + ( plomien[i][1] - punkty[9][1] ) * cos( k ) + punkty[9][1];
            }
        }
    k = k * ( -1 );
    for( int o = 0; o < sumaObrotowMinus; o++ )
        for( int i = 0; i < 9; i++ ){
            punkty[i][0] = ( punkty[i][0] - punkty[9][0] ) * cos( k ) - ( punkty[i][1] - punkty[9][1] ) * sin( k ) + punkty[9][0];
            punkty[i][1] = ( punkty[i][0] - punkty[9][0] ) * sin( k ) + ( punkty[i][1] - punkty[9][1] ) * cos( k ) + punkty[9][1];
            if( i < 6 ) {
                plomien[i][0] = ( plomien[i][0] - punkty[9][0] ) * cos( k ) - ( plomien[i][1] - punkty[9][1] ) * sin( k ) + punkty[9][0];
                plomien[i][1] = ( plomien[i][0] - punkty[9][0] ) * sin( k ) + ( plomien[i][1] - punkty[9][1] ) * cos( k ) + punkty[9][1];
            }
        }
}
int Statek::ilePaliwa()
{
    return paliwo;
}
float Statek::predkoscX()
{
    return bezwladnoscX;
}
float Statek::predkoscY()
{
    return bezwladnoscY;
}
Statek::~Statek()
{
    delete punkty;
    delete plomien;
}
