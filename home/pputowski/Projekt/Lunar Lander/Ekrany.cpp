#include "Ekrany.h"

const int screen_w = 1200;
const int screen_h = 700;

Ekrany::Ekrany()
{
    Paliwo = 50000;
    czas = 0.0;
    T = false;
    S = false;
}
void Ekrany::MenuStart()
{
    Paliwo = 50000;
    al_clear_to_color( al_map_rgb( 0, 0, 30 ) ); // Wyczyszczenie ekranu

    // Wypisanie Tytulu gry
    ALLEGRO_FONT *czTytul = al_load_ttf_font("OpenSans-ExtraBold.ttf", 60, NULL);
    al_draw_text( czTytul, al_map_rgb( 255, 255, 255 ), screen_w / 2, 10, ALLEGRO_ALIGN_CENTRE, "[Lunar Lander]" );
    al_destroy_font(czTytul);

    // Wypisanie Tytulu okna
    ALLEGRO_FONT *czNapisy = al_load_ttf_font("OpenSans-Light.ttf", 40, NULL);
    al_draw_text( czNapisy, al_map_rgb( 255, 255, 255 ), screen_w / 2, 110, ALLEGRO_ALIGN_CENTRE, "Menu gry" );
    al_destroy_font(czNapisy);

    // Wypisanie instrukcji klawiszy
    ALLEGRO_FONT *czPodpisy = al_load_ttf_font("OpenSans-Light.ttf", 15, NULL);
    al_draw_text( czPodpisy, al_map_rgb( 255, 255, 255 ), screen_w - 180, screen_h - 100, ALLEGRO_ALIGN_LEFT, "Zwiekszanie paliwa" );
    al_draw_filled_triangle( screen_w - 229, screen_h - 90, screen_w - 213, screen_h - 90, screen_w - 221, screen_h - 97, al_map_rgb( 255, 255, 255 ));
    al_draw_line( screen_w - 221, screen_h - 90, screen_w - 221, screen_h - 83, al_map_rgb( 255,255,255 ), 6 );

    al_draw_text( czPodpisy, al_map_rgb( 255, 255, 255 ), screen_w - 180, screen_h - 75, ALLEGRO_ALIGN_LEFT, "Zmniejszanie paliwa" );
    al_draw_filled_triangle( screen_w - 229, screen_h - 65, screen_w - 213, screen_h - 65, screen_w - 221, screen_h - 58, al_map_rgb( 255, 255, 255 ));
    al_draw_line( screen_w - 221, screen_h - 65, screen_w - 221, screen_h - 72, al_map_rgb( 255,255,255 ), 6 );

    ALLEGRO_FONT *czEnter = al_load_ttf_font("OpenSans-ExtraBold.ttf", 15, NULL);
    al_draw_text( czPodpisy, al_map_rgb( 255, 255, 255 ), screen_w - 180, screen_h - 50, ALLEGRO_ALIGN_LEFT, "Start gry" );
    al_draw_text( czEnter, al_map_rgb( 255, 255, 255 ), screen_w - 250, screen_h - 50, ALLEGRO_ALIGN_LEFT, "[ENTER]" );
    al_destroy_font(czEnter);
    al_destroy_font(czPodpisy);

    // Odswiezenie ekranu
    al_flip_display();
}
void Ekrany::Tankuj( bool t )
{
    T = t;
}
void Ekrany::Spuszczaj( bool s )
{
    S = s;
}
void Ekrany::Stacja( int l )
{
    // Ograniczenie mozliwej ilosci paliwa do wziecia
    Paliwo = min( max( Paliwo + T * l - S * l, 10000 ), 99999 );

    char strPaliwo [15];
    sprintf( strPaliwo, "Paliwo: %d", Paliwo);
    ALLEGRO_FONT *czPaliwo = al_load_ttf_font("OpenSans-Light.ttf", 30, NULL);
    // Zamazanie poprzednich wartosci paliwa
    al_draw_filled_rectangle( screen_w / 2 - 500, 200, screen_w / 2 + 500, 500, al_map_rgb( 0, 0, 30 ));
    // Wypisanie nowej wartosci paliwa
    al_draw_text( czPaliwo, al_map_rgb( 255, 255, 255 ), screen_w / 2, 250, ALLEGRO_ALIGN_CENTRE, strPaliwo );
    // Skasowanie czcionki
    al_destroy_font(czPaliwo);
}
int Ekrany::ilePaliwa()
{
    return Paliwo;
}
void Ekrany::Wygrana( double bonus, int _paliwo  )
{
    char strPunkty [30];
    char strPaliwo [30];
    char strCzas [30];
    // Rozbicie czasu gry na minuty i sekundy
    float minuty = floor( czas / 60 );
    float sekundy = floor( czas ) - minuty * 60;
    float Punkty = (
                    200000 - 500 * czas // Kara za dlugi lot
                    - static_cast<float>( Paliwo - _paliwo ) // Kara za zle oszacowana ilosc potrzebnego paliwa
                    - 0.5 * ( Paliwo > 35000 ) * static_cast<float>( Paliwo - _paliwo ) // kara za wziecie wiecej niz 35 000 paliwa
                    - 0.5 * static_cast<float>( _paliwo ) ) // Kara za zuzyte paliwo
                    * ( bonus - ( bonus > 10 ) * 10 ); // przemnozenie przez bonus
    sprintf( strPunkty, "Zdobyles: %.0f punktow", Punkty );
    sprintf( strPaliwo, "Zostalo: %d paliwa", _paliwo );
    sprintf( strCzas, "Czas gry: %02.0f:%02.0f", minuty, sekundy );

    al_clear_to_color( al_map_rgb( 0, 0, 30 ) );
    ALLEGRO_FONT *czTytul = al_load_ttf_font("OpenSans-ExtraBold.ttf", 60, NULL);
    al_draw_text( czTytul, al_map_rgb( 255, 255, 255 ), screen_w / 2, 10, ALLEGRO_ALIGN_CENTRE, "Wygrana!" );
    al_destroy_font( czTytul );

    ALLEGRO_FONT *czNapis = al_load_ttf_font("OpenSans-Light.ttf", 40, NULL);
    al_draw_text( czNapis, al_map_rgb( 255, 255, 255 ), screen_w / 2, 110, ALLEGRO_ALIGN_CENTRE, "Gratulacje" );
    al_destroy_font( czNapis );

    ALLEGRO_FONT *czOpis = al_load_ttf_font("OpenSans-Light.ttf", 30, NULL);
    al_draw_text( czOpis, al_map_rgb( 255, 255, 255 ), screen_w / 2, 250, ALLEGRO_ALIGN_CENTRE, strPunkty );
    al_draw_text( czOpis, al_map_rgb( 255, 255, 255 ), screen_w / 2, 300, ALLEGRO_ALIGN_CENTRE, strPaliwo );
    al_draw_text( czOpis, al_map_rgb( 255, 255, 255 ), screen_w / 2, 350, ALLEGRO_ALIGN_CENTRE, strCzas );
    al_destroy_font( czOpis );

    ALLEGRO_FONT *czPodpisy = al_load_ttf_font("OpenSans-Light.ttf", 15, NULL);
    ALLEGRO_FONT *czEnter = al_load_ttf_font("OpenSans-ExtraBold.ttf", 15, NULL);
    // Z menu Wygrana mozna tylko przejsc do menu gry
    al_draw_text( czPodpisy, al_map_rgb( 255, 255, 255 ), screen_w - 180, screen_h - 50, ALLEGRO_ALIGN_LEFT, "Menu gry" );
    al_draw_text( czEnter, al_map_rgb( 255, 255, 255 ), screen_w - 250, screen_h - 50, ALLEGRO_ALIGN_LEFT, "[ESC]" );
    al_destroy_font( czEnter );
    al_destroy_font( czPodpisy );

    al_flip_display();
}
void Ekrany::Przegrana( int _paliwo, bool predkosc )
{
    // Monza przegrac rozbijajac statek lub za szybko podchodzac do ladowania
    char strPowod [100];
    if( predkosc ){
        sprintf( strPowod, "Ups... Troszke za szybko." );
    }else if( _paliwo < 0 ){ // Zabezpieczenie przed wyswietlaniem ujemnych wartosci paliwa
        _paliwo = 0;
    }else
        sprintf( strPowod, "Ups... Rozbiles sie." );
    char strPaliwo [30];
    char strCzas [30];
    float minuty = floor( czas / 60 );
    float sekundy = floor( czas ) - minuty * 60;
    sprintf( strPaliwo, "Zostalo: %d paliwa", _paliwo );
    sprintf( strCzas, "Czas gry: %02.0f:%02.0f", minuty, sekundy );

    al_clear_to_color( al_map_rgb( 0, 0, 30 ) );
    ALLEGRO_FONT *czTytul = al_load_ttf_font("OpenSans-ExtraBold.ttf", 60, NULL);
    al_draw_text( czTytul, al_map_rgb( 255, 255, 255 ), screen_w / 2, 10, ALLEGRO_ALIGN_CENTRE, "Przegrana!" );
    al_destroy_font( czTytul );

    ALLEGRO_FONT *czNapis = al_load_ttf_font("OpenSans-Light.ttf", 40, NULL);
    al_draw_text( czNapis, al_map_rgb( 255, 255, 255 ), screen_w / 2, 110, ALLEGRO_ALIGN_CENTRE, strPowod );
    al_destroy_font( czNapis );

    ALLEGRO_FONT *czPunkty = al_load_ttf_font("OpenSans-Light.ttf", 30, NULL);
    al_draw_text( czPunkty, al_map_rgb( 255, 255, 255 ), screen_w / 2, 250, ALLEGRO_ALIGN_CENTRE, strPaliwo );
    al_draw_text( czPunkty, al_map_rgb( 255, 255, 255 ), screen_w / 2, 300, ALLEGRO_ALIGN_CENTRE, strCzas );
    al_destroy_font( czPunkty );

    ALLEGRO_FONT *czPodpisy = al_load_ttf_font("OpenSans-Light.ttf", 15, NULL);
    ALLEGRO_FONT *czEnter = al_load_ttf_font("OpenSans-ExtraBold.ttf", 15, NULL);
    // Po przegranej mozna zagrac na tej samej planszy z tymi samymi ustawieniami lub przejsc do menu gry
    al_draw_text( czPodpisy, al_map_rgb( 255, 255, 255 ), screen_w - 180, screen_h - 75, ALLEGRO_ALIGN_LEFT, "Jeszcze raz" );
    al_draw_text( czEnter, al_map_rgb( 255, 255, 255 ), screen_w - 200, screen_h - 75, ALLEGRO_ALIGN_RIGHT, "[ENTER]" );
    al_draw_text( czPodpisy, al_map_rgb( 255, 255, 255 ), screen_w - 180, screen_h - 50, ALLEGRO_ALIGN_LEFT, "Menu gry" );
    al_draw_text( czEnter, al_map_rgb( 255, 255, 255 ), screen_w - 200, screen_h - 50, ALLEGRO_ALIGN_RIGHT, "[ESC]" );
    al_destroy_font( czEnter );
    al_destroy_font( czPodpisy );

    al_flip_display();
}
void Ekrany::Gra( ALLEGRO_FONT* _czStatystyki, int _paliwo, float _czas )
{
    czas = _czas;
    char strPaliwo [30];
    char strCzas [50];
    char strPunkty [50];
    float minuty = floor( czas / 60 );
    float sekundy = floor( czas ) - minuty * 60;
    float Punkty = (
                    200000
                    - 500 * czas // Kara za dlugi lot
                    - static_cast<float>( Paliwo - _paliwo ) // Kara za zle oszacowana ilosc potrzebnego paliwa
                    - 0.5 * ( Paliwo > 35000 ) * static_cast<float>( Paliwo - _paliwo ) // kara za wziecie wiecej niz 35 000 paliwa
                    - 0.5 * static_cast<float>( _paliwo ) ); // Kara za zuzyte paliwo
    sprintf( strPaliwo, "Paliwo: %d", _paliwo );
    sprintf( strCzas, "Czas gry: %02.0f:%02.0f", minuty, sekundy );
    sprintf( strPunkty, "Punkty: %.0f", Punkty );
    al_draw_filled_rectangle( screen_w - 190, 0, screen_w, 110, al_map_rgb( 0, 0, 30 ));

    al_draw_text( _czStatystyki, al_map_rgb( 255, 255, 255 ), screen_w - 180, 10, ALLEGRO_ALIGN_LEFT, strCzas );
    al_draw_text( _czStatystyki, al_map_rgb( 255, 255, 255 ), screen_w - 180, 45, ALLEGRO_ALIGN_LEFT, strPaliwo );
    al_draw_text( _czStatystyki, al_map_rgb( 255, 255, 255 ), screen_w - 180, 80, ALLEGRO_ALIGN_LEFT, strPunkty );
}

