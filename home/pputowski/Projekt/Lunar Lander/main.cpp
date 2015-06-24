using namespace std;
#include <stdio.h>
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <ctime>
#include <math.h>
#include "Ekrany.cpp"
#include "Statek.cpp"
#include "Powierzchnia.cpp"

const float FPS = 60.0;

Ekrany *e = new Ekrany();
Statek *s = new Statek();
Powierzchnia *p = new Powierzchnia();

int main()
{
    if ( !al_init() || !al_install_keyboard() || !al_init_primitives_addon() ) {
        cout << "Blad" << endl;
        return 1;
    }
    ALLEGRO_DISPLAY *display = al_create_display(screen_w, screen_h);
    al_set_window_title( display,"Lunar Lander");
    ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    if (display == NULL || timer == NULL || event_queue == NULL) {
        cout << "Blad" << endl;
        return 2;
    }

    al_init_font_addon();
    al_init_ttf_addon();
    al_init_font_addon();

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_start_timer( timer );

    e -> MenuStart();

    float czas; // Zegar do odmierzania czasu gry
    int status = 0; // 0 - Menu start, 1 - Gra, 10 - Wygrana, 9 - Przegrana
    bool zoom = false; // zmienna do okreslenia czy gra znajduje sie w przyblizeniu
    double miejsceZoom = 0; // Zapamietane miejsce zoomowania
    ALLEGRO_FONT *czStatystyki = al_load_ttf_font("OpenSans-Light.ttf", 25, NULL);
    // Za³adowanie czcionki, ¿eby przy ka¿dej aktualizacji nie trzebaby³o ³adowaæ

    al_flip_display();

    while(true){
        ALLEGRO_EVENT ev;
        al_wait_for_event( event_queue, &ev );
        if( ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE )
            break;
        else if( ev.type == ALLEGRO_EVENT_KEY_DOWN ){
            switch( ev.keyboard.keycode ){
                case ALLEGRO_KEY_UP:
                    s -> Lec( true ); // Gdy gramy to statek leci
                    e -> Tankuj( true );// gdy Menu Start to tankujemy statek
                    break;
                case ALLEGRO_KEY_LEFT:
                    s -> Lewo( true );
                    break;
                case ALLEGRO_KEY_RIGHT:
                    s -> Prawo( true );
                    break;
                case ALLEGRO_KEY_DOWN:
                    e -> Spuszczaj( true ); // Gdy Menu start spuszcza benzyne
                    break;
                case ALLEGRO_KEY_ENTER:
                    if( status == 0 || status == 9 ){ // Przy przejsciu z menu start lub ekranu przegranej laduje t¹ sam¹ planszê
                        p -> RysujPowierzchnie( 1, false );
                        s -> Restart( e -> ilePaliwa() ); // Restart samolotu z uwzglêdnieniem opóŸnienia odpalenia
                        s -> WyswietlStatek();
                        status = 1;
                        czas = -2.5; // Uwzglêdnienie opóŸnienia pomiedzy przejsciem z menu do gry
                    }else if( status == 10 ){
                        p -> ~Powierzchnia(); // Po wygranej zawsze kasowana jest plansza
                        Powierzchnia *p = new Powierzchnia();
                        e -> MenuStart(); // i przechodzimy do menu start
                        status = 0;
                    }
                    break;
                case ALLEGRO_KEY_ESCAPE:
                    if( status == 9 || status == 10 || status == 1 )
                        p -> ~Powierzchnia(); // Nacisniecie ESCAPE powoduje usuniecie aktualnej planszy
                        Powierzchnia *p = new Powierzchnia(); // oraz stworzenie nowej
                        e -> MenuStart();
                        status = 0;
            }
        } else if( ev.type == ALLEGRO_EVENT_KEY_UP ) {
             switch( ev.keyboard.keycode ) {
                 case ALLEGRO_KEY_UP:
                    s -> Lec( false );
                    e -> Tankuj( false );
                    break;
                 case ALLEGRO_KEY_LEFT:
                    s -> Lewo( false );
                    break;
                 case ALLEGRO_KEY_RIGHT:
                    s -> Prawo( false );
                    break;
                case ALLEGRO_KEY_DOWN:
                    e -> Spuszczaj( false );
                    break;
            }
        }
        switch( status ){
            case 0: // Menu Start
                s -> WyczyscStatek(); // Usuwa staek
                e -> Stacja( 70 ); // Podnosi lub opuszcza poziom paliwa w zadanym tempie
                break;
            case 1: // Gra
                s -> WyczyscStatek();
                if( zoom ){
                    p -> RysujPowierzchnie( 0, true ); // Rysuje powierzchnie w przyblizeniu
                    int wygrana = p -> sprawdzWygrana( s ); // Zwraca ktory rog statku dotyka planszy
                    if( wygrana != -1 ){ // Czy jakikolwiek dotyka
                        s -> WyczyscStatek();
                        zoom = false;
                        if( ( wygrana == 0 || wygrana == 1 || wygrana == 4 || wygrana == 5 ) ){
                        // Sprawdzenie czy dotyka rog ze spodu statku
                            if( s -> predkoscY() < 0.25 ){
                            // Sprawdzenie predkosci podejsca do ladowania
                                status = 10;
                                e -> Wygrana( p -> bonus( s -> WspolStatku( 9, 0 ), true ), s -> ilePaliwa() );
                                // Odpalenie ekranu Wygrana wraz z obliczeniem statysyk gry
                            }else{
                                e -> Przegrana( s -> ilePaliwa(), true );
                                status = 9;
                                // Odpalenie ekranu przegrana
                            }
                        }else{
                            status = 9;
                            e -> Przegrana( s -> ilePaliwa(), false );
                            // Wyswietlenie ekranu przegrana wraz z powodem przegranej
                        }
                    }else if( s -> WspolStatku( 9, 1 ) < 0 || s -> WspolStatku( 9, 0 ) < 0 || s -> WspolStatku( 9, 0 ) > screen_w ){
                    // Sprawdzenie czy statek nie wylecial poza obszar zoomowania
                        s -> Zblizenie( miejsceZoom + ( s -> WspolStatku( 9, 0 ) ) / 4
                                       , p -> wysokosc( miejsceZoom + ( s -> WspolStatku( 9, 0 ) ) / 4, false ) - screen_h / 4 + 90
                                       , 1 );
                        //oddalenie zoomu z uwzglednieniem gdzie odbylo sie zoomowanie, gdzie dolecial statek w zoomie oraz skala
                        p -> RysujPowierzchnie( 0, false );
                        zoom = false;
                    }
                }else{ // Jezeli plansza nie byla w zoomowana
                    p -> obliczOdleglosci( s, false );
                    // obliczenie polozenia najnizszego pkt statku wzgledem wszystkich pkt planszy
                    if( p -> sprawdzOdleglosci( false ) < 50 ){
                    // jezeli ta odleglosc jest < 50
                        miejsceZoom = p -> Zblizenie( 4, s -> WspolStatku( 9, 0 ) );
                        // 4 krotne przyblizenie i zapamietanie miejsca zoomowania
                        s -> Zblizenie( screen_w / 2, 10, 4 );
                        // powiekszenie statku
                        p -> RysujPowierzchnie( 0, true );
                        zoom = true;
                    }
                }
                if( status == 1 ){ // Sprawdzenie czy nie zmienil sie status gry
                    e -> Gra( czStatystyki, s -> ilePaliwa(), czas );
                    // odswiezenie statystyk gry
                    s -> Ruch( czas );
                    // przemieszczenie statku
                    s -> WyswietlStatek();
                    // wyswietlenie statku
                }
        }
        czas = czas + 1.0 / FPS;
        // odswierzenie czasu gry
        al_flip_display();
        // odswierzenie ekranu
    }
}
