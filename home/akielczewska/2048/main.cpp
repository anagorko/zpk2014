#include<iostream>
#include<vector>
#include<math.h>
#include <cstdlib>
#include <allegro5/allegro_font.h>
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>

using namespace std;


const int screen_w = 800;
const int screen_h = 600;

class Plansza {

    int t[4][4];

    int wynik = 0;

    void obrocO90Stopni();

public:
    Plansza() {
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                t[i][j] = 0;
            }
        }
    }

    void ustawPozycjePoczatkowa();

    void wykonajRuch(int kierunek);

    void ustawLosowaLiczbe();

    int zawartoscPola(int w, int k);

    bool koniecGry();

    int podajWynik();

    void wyswietlWKonsoli(); //// na potrzeby testowania w trakcie pisania programu

    void wyswietlWGrze();

};

void Plansza::obrocO90Stopni() {
    int tk[4][4]; // kopia planszy t - obrot
    tk[0][0] = t[0][3];
    tk[1][0] = t[0][2];
    tk[2][0] = t[0][1];
    tk[3][0] = t[0][0];
    tk[0][1] = t[1][3];
    tk[1][1] = t[1][2];
    tk[2][1] = t[1][1];
    tk[3][1] = t[1][0];
    tk[0][2] = t[2][3];
    tk[1][2] = t[2][2];
    tk[2][2] = t[2][1];
    tk[3][2] = t[2][0];
    tk[0][3] = t[3][3];
    tk[1][3] = t[3][2];
    tk[2][3] = t[3][1];
    tk[3][3] = t[3][0];


    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            t[i][j] = tk[i][j];
        }
    }
}

void Plansza::wykonajRuch(int kierunek) {
    if (kierunek == 1) { // ruch w gore
    }
    else if (kierunek == 2) { // ruch w prawo
        obrocO90Stopni();
    }
    else if (kierunek == 3) { // ruch w dol
        obrocO90Stopni();
        obrocO90Stopni();
    }
    else if (kierunek == 4) { // ruch w lewo
        obrocO90Stopni();
        obrocO90Stopni();
        obrocO90Stopni();
    }
    // Ruch w gore
    for (int j=0; j<4; j++) {
        // przesuniecie do pierwszego górnego wiersza:
        if (t[0][j] == 0) {
            if (t[1][j] != 0) {
                t[0][j] = t[1][j];
                t[1][j] = 0;
            }
            else if (t[2][j] != 0) {
                t[0][j] = t[2][j];
                t[2][j] = 0;
            }
            else if (t[3][j] != 0) {
                t[0][j] = t[3][j];
                t[3][j] = 0;
            }
        }
        // przesuniecie do drugiego wiersza:
        if (t[1][j] == 0) {
            if (t[2][j] != 0) {
                t[1][j] = t[2][j];
                t[2][j] = 0;
            }
            else if (t[3][j] != 0) {
                t[1][j] = t[3][j];
                t[3][j] = 0;
            }
        }
        // przesuniecie do trzeciego wiersza:
        if (t[2][j] == 0) {
            if (t[3][j] != 0) {
                t[2][j] = t[3][j];
                t[3][j] = 0;
            }
        }

    }


    // sklejanie w gore
    for (int j=0; j<4; j++) {
        if (t[0][j] == t[1][j] & t[2][j] != t[3][j]) {
            t[0][j] = t[0][j] + t[1][j];
            t[1][j] = t[2][j];
            t[2][j] = t[3][j];
            t[3][j] = 0;
        }
        else if (t[0][j] == t[1][j] & t[2][j] == t[3][j]) {
            t[0][j] = t[0][j] + t[1][j];
            t[1][j] = t[2][j] + t[3][j];
            t[2][j] = 0;
            t[3][j] = 0;
        }
        else if (t[1][j] == t[2][j]) {
            t[1][j] = t[1][j] + t [2][j];
            t[2][j] = t[3][j];
        }
        else if (t[2][j] == t[3][j]) {
            t[2][j] = t[2][j] + t[3][j];
            t[3][j] = 0;
        }
    }
    if (kierunek == 1) { // ruch w gore
    }
    else if (kierunek == 2) { // ruch w prawo
        obrocO90Stopni();
        obrocO90Stopni();
        obrocO90Stopni();
    }
    else if (kierunek == 3) { // ruch w dol
        obrocO90Stopni();
        obrocO90Stopni();
    }
    else if (kierunek == 4) { // ruch w lewo
        obrocO90Stopni();
    }

}

void Plansza::ustawPozycjePoczatkowa() {
    // ustawienie pierwszej liczby
    int los = std::rand();
    int nr = los%16;
    int l = -1;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            l++;
            if (nr == l) {
                t[i][j] = 2;
            }
        }
    }
    // ustawienie drugiej liczby
    los = std::rand();
    nr = los%15;
    l = -1;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            if (t[i][j] == 0) {
                l++;
            }
            if (nr == l) {
                t[i][j] = 2;
            }
        }
    }
    wynik += 4;
}

void Plansza::ustawLosowaLiczbe() {
    int ile = 0; // zwraca liczbe pustych pol
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            if (t[i][j] == 0) {
                ile++;
            }
        }
    }
    int los = std::rand();
    int nr = los%ile;
    int l = -1;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            if (t[i][j] == 0) {
                l++;
                if (nr == l) {
                    t[i][j] = 2;
                }
            }
        }
    }
    wynik += 2;
}

int Plansza::zawartoscPola(int w, int k) {
    // wiersze i kolumny numerujemy od 1 do 4
    return t[w-1][k-1];
}

void Plansza::wyswietlWKonsoli() {
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            cout << t[i][j] << " ";
        }
    cout << endl;
    }
    cout << endl;
}

void Plansza::wyswietlWGrze() {
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            ALLEGRO_FONT *font = al_load_ttf_font("Telex-Regular.ttf",32,0 );
            al_draw_textf(font, al_map_rgb( 0, 0, 0 ), 118*i+218, 118*j+160, ALLEGRO_ALIGN_CENTRE, "%d" , t[i][j]);
            al_flip_display();

        }

    }
}

bool Plansza::koniecGry() {
    bool k = true;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            if (t[i][j] == 0) k = false;
        }
    }
    return k;
}

int Plansza::podajWynik() {
    return wynik;
}


int main(int, char**)
{
    if (!al_init() || !al_install_keyboard() || !al_init_image_addon()) {
        cout << "Blad inicjalizacji." << endl;
        return 1;
    }

    ALLEGRO_DISPLAY *display = al_create_display(screen_w, screen_h);
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();//kolejka zdarzen

    if (display == NULL || event_queue == NULL) {
        cout << "Blad inicjalizacji." << endl;
        return 2;
    }

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());


    int mode = 0; //0 - wyswietlam ekran gry 1 - wyswietlam menu 2 - wyswietlam wyniki

    ALLEGRO_BITMAP * ekran_glowny = al_load_bitmap("ekran_glowny.png");
    ALLEGRO_BITMAP * menu = al_load_bitmap("menu.png");
    ALLEGRO_BITMAP * tablica_wynikow = al_load_bitmap("tablica_wynikow.png");

    al_clear_to_color(al_map_rgb(0,0,0));

    al_draw_bitmap(ekran_glowny,0,0,0);
    al_flip_display();

    al_init_font_addon();
    al_init_ttf_addon();

            Plansza gra;
            gra.ustawPozycjePoczatkowa();
            gra.wyswietlWKonsoli();
            gra.wyswietlWGrze();




    while (true)
    {
        // process events
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);


        if( mode == 0 ){


            al_draw_bitmap(ekran_glowny,0,0,0);

            Plansza gra;
            gra.wyswietlWKonsoli();
            gra.wyswietlWGrze();



            if(ev.keyboard.keycode == ALLEGRO_KEY_DOWN) {
                     Plansza gra;
                    gra.wykonajRuch(3);
                    gra.wyswietlWGrze();
            }
            else if(ev.keyboard.keycode == ALLEGRO_KEY_UP) {
                 //  gra.wykonajRuch(1);
            }
            else if(ev.keyboard.keycode == ALLEGRO_KEY_RIGHT){
                   // gra.wykonajRuch(2);
            }
            else if(ev.keyboard.keycode == ALLEGRO_KEY_LEFT){
                   // gra.wykonajRuch(4);
            }

            // narazie wstepnie proponuje przejscie pomiedzy ekranami za pomoca wciskania przyciskow na klawiaturze
            // za pomoca klikniecia 'o' przechodzimy z ekranu glownego do menu
            else if(ev.keyboard.keycode == ALLEGRO_KEY_O){
                mode = 1;
            }
            else if(ev.keyboard.keycode == ALLEGRO_KEY_Q){//wyjscie z gry moze nastapic w kazdym ekranie za pomoca 'q'
                break;
            }


        }

        else if ( mode == 1 ){
            al_draw_bitmap(menu,0,0,0);
            al_flip_display();


            if(ev.keyboard.keycode == ALLEGRO_KEY_W){//przejscie z menu do ekranu wynikow za pomoca wcisniecia przycisku 'w'
                mode = 2;
            }
            else if(ev.keyboard.keycode == ALLEGRO_KEY_G){//przejscie do ekranu gry za pomoca przycisku 'g'
                mode = 0;
            }
            else if(ev.keyboard.keycode == ALLEGRO_KEY_Q){//wyjscie z gry moze nastapic w kazdym ekranie za pomoca 'q'
                break;
            }
        }

        else if ( mode == 2 ){
                al_draw_bitmap(tablica_wynikow,0,0,0);
                al_flip_display();

                if(ev.keyboard.keycode == ALLEGRO_KEY_O){//powrot z wynikow do menu za pomoca przycisku 'o'
                mode = 1;
                }
                else if(ev.keyboard.keycode == ALLEGRO_KEY_Q){//wyjscie z gry moze nastapic w kazdym ekranie za pomoca 'q'
                break;
                }



        }



    };

    return 0;
}
