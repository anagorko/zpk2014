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

const float FPS = 60;


struct wynik {
    int punkty;
    string imie;
};

const int n = 10;

wynik wyniki[n];

void czytaj_wyniki()
{
    for (int i = 0; i < n; i++) {
        wyniki[i].punkty = 1000 - 100 * i;
        wyniki[i].imie = "A";
    }
}

void zapisz_wyniki()
{
}

void wypisz_wyniki()
{
    for (int i = 0; i < n; i++) {
        cout << (i+1) << ". " << wyniki[i].imie << " " << wyniki[i].punkty << endl;
            ALLEGRO_FONT *font = al_load_ttf_font("HappyMonkey-Regular.ttf",24,0 );
            al_draw_textf(font, al_map_rgb( 0, 0, 0 ), 170, 35*i+120, ALLEGRO_ALIGN_CENTRE, "%s" , wyniki[i].imie.c_str());
            al_draw_textf(font, al_map_rgb( 0, 0, 0 ), 300, 35*i+120, ALLEGRO_ALIGN_CENTRE, "%d" , wyniki[i].punkty);
            al_flip_display();
    }
}

void dodaj_wynik(wynik w)
{
    int i;

    for (i = 0; i < n; i++) {
        if (w.punkty > wyniki[i].punkty) {
            break;
        }
    }

    if (i == n) return;

    for (int j = n-1; j > i; j--) {
        wyniki[j] = wyniki[j-1];
    }

    wyniki[i] = w;
}

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

    void wyczysc();

    int zawartoscPola(int w, int k);

    bool koniecGry();

    int podajWynik();

    void zerujWynik();

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
        if (t[0][j] == t[1][j] && t[2][j] != t[3][j]) {
            t[0][j] = t[0][j] + t[1][j];
            t[1][j] = t[2][j];
            t[2][j] = t[3][j];
            t[3][j] = 0;
        }
        else if (t[0][j] == t[1][j] && t[2][j] == t[3][j]) {
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

void Plansza::wyczysc(){
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            t[i][j] = 0;
        }}
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

void Plansza::wyswietlWGrze() {ALLEGRO_FONT *font = al_load_ttf_font("HappyMonkey-Regular.ttf",32,0 );
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {

           if (t[i][j] == 2){
           // ALLEGRO_FONT *font = al_load_ttf_font("HappyMonkey-Regular.ttf",32,0 );
            al_draw_textf(font, al_map_rgb( 0, 0, 0 ), 118*j+218, 118*i+160, ALLEGRO_ALIGN_CENTRE, "%d" , t[i][j]);
            float alpha = 0.99f;
            al_draw_filled_rectangle( 166+118*j, 121+118*i, 278+118*j, 234+118*i, al_map_rgba( 255*alpha, 227*alpha, 10*alpha, alpha ) );
            al_flip_display();
           }

            else if(t[i][j] == 8){
            //ALLEGRO_FONT *font = al_load_ttf_font("HappyMonkey-Regular.ttf",32,0 );
            al_draw_textf(font, al_map_rgb( 0, 0, 0 ), 118*j+218, 118*i+160, ALLEGRO_ALIGN_CENTRE, "%d" , t[i][j]);
            float alpha = 0.99f;
            al_draw_filled_rectangle( 166+118*j, 121+118*i, 278+118*j, 234+118*i, al_map_rgba( 255*alpha, 0*alpha, 0*alpha, alpha ) );
            al_flip_display();

           }

            else if(t[i][j] == 4){
            //ALLEGRO_FONT *font = al_load_ttf_font("HappyMonkey-Regular.ttf",32,0 );
            al_draw_textf(font, al_map_rgb( 0, 0, 0 ), 118*j+218, 118*i+160, ALLEGRO_ALIGN_CENTRE, "%d" , t[i][j]);
            float alpha = 0.99f;
            al_draw_filled_rectangle( 166+118*j, 121+118*i, 278+118*j, 234+118*i, al_map_rgba( 255*alpha, 146*alpha, 0*alpha, alpha ) );
            al_flip_display();

           }

            else if(t[i][j] == 16){
            //ALLEGRO_FONT *font = al_load_ttf_font("HappyMonkey-Regular.ttf",32,0 );
            al_draw_textf(font, al_map_rgb( 0, 0, 0 ), 118*j+218, 118*i+160, ALLEGRO_ALIGN_CENTRE, "%d" , t[i][j]);
            float alpha = 0.99f;
            al_draw_filled_rectangle( 166+118*j, 121+118*i, 278+118*j, 234+118*i, al_map_rgba( 163*alpha, 92*alpha, 0*alpha, alpha ) );
            al_flip_display();

           }

           else if(t[i][j] == 32){
            //ALLEGRO_FONT *font = al_load_ttf_font("HappyMonkey-Regular.ttf",32,0 );
            al_draw_textf(font, al_map_rgb( 0, 0, 0 ), 118*j+218, 118*i+160, ALLEGRO_ALIGN_CENTRE, "%d" , t[i][j]);
            float alpha = 0.99f;
            al_draw_filled_rectangle( 166+118*j, 121+118*i, 278+118*j, 234+118*i, al_map_rgba( 207*alpha, 250*alpha, 0*alpha, alpha ) );
            al_flip_display();

           }

            else if(t[i][j] == 64){
           // ALLEGRO_FONT *font = al_load_ttf_font("HappyMonkey-Regular.ttf",32,0 );
            al_draw_textf(font, al_map_rgb( 0, 0, 0 ), 118*j+218, 118*i+160, ALLEGRO_ALIGN_CENTRE, "%d" , t[i][j]);
            float alpha = 0.99f;
            al_draw_filled_rectangle( 166+118*j, 121+118*i, 278+118*j, 234+118*i, al_map_rgba( 140*alpha, 169*alpha, 0*alpha, alpha ) );
            al_flip_display();

           }

            else if(t[i][j] == 128){
            //ALLEGRO_FONT *font = al_load_ttf_font("HappyMonkey-Regular.ttf",32,0 );
            al_draw_textf(font, al_map_rgb( 0, 0, 0 ), 118*j+218, 118*i+160, ALLEGRO_ALIGN_CENTRE, "%d" , t[i][j]);
            float alpha = 0.99f;
            al_draw_filled_rectangle( 166+118*j, 121+118*i, 278+118*j, 234+118*i, al_map_rgba( 59*alpha, 71*alpha, 0*alpha, alpha ) );
            al_flip_display();


           }
           else if(t[i][j] == 256){
            //ALLEGRO_FONT *font = al_load_ttf_font("HappyMonkey-Regular.ttf",32,0 );
            al_draw_textf(font, al_map_rgb( 0, 0, 0 ), 118*j+218, 118*i+160, ALLEGRO_ALIGN_CENTRE, "%d" , t[i][j]);
            float alpha = 0.99f;
            al_draw_filled_rectangle( 166+118*j, 121+118*i, 278+118*j, 234+118*i, al_map_rgba( 141*alpha, 222*alpha, 202*alpha, alpha ) );
            al_flip_display();

           }
           else if(t[i][j] == 512){
            //ALLEGRO_FONT *font = al_load_ttf_font("HappyMonkey-Regular.ttf",32,0 );
            al_draw_textf(font, al_map_rgb( 0, 0, 0 ), 118*j+218, 118*i+160, ALLEGRO_ALIGN_CENTRE, "%d" , t[i][j]);
            float alpha = 0.99f;
            al_draw_filled_rectangle( 166+118*j, 121+118*i, 278+118*j, 234+118*i, al_map_rgba( 0*alpha, 147*alpha, 110*alpha, alpha ) );
            al_flip_display();

           }
           else if(t[i][j] == 1024){
            //ALLEGRO_FONT *font = al_load_ttf_font("HappyMonkey-Regular.ttf",32,0 );
            al_draw_textf(font, al_map_rgb( 0, 0, 0 ), 118*j+218, 118*i+160, ALLEGRO_ALIGN_CENTRE, "%d" , t[i][j]);
            float alpha = 0.99f;
            al_draw_filled_rectangle( 166+118*j, 121+118*i, 278+118*j, 234+118*i, al_map_rgba( 0*alpha, 91*alpha, 76*alpha, alpha ) );
            al_flip_display();

           }



            else {
            //ALLEGRO_FONT *font = al_load_ttf_font("HappyMonkey-Regular.ttf",32,0 );
            al_draw_textf(font, al_map_rgb( 0, 0, 0 ), 118*j+218, 118*i+160, ALLEGRO_ALIGN_CENTRE, "%d" , t[i][j]);
            al_flip_display();
            }

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
    cout << "koniec gry" <<endl;
}

int Plansza::podajWynik() {
    return wynik;
}

void Plansza::zerujWynik(){
        wynik = 0;
}

/*enum MYKEYS {
   KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};*/


int main(int, char**)
{
    if (!al_init() || !al_install_keyboard() || !al_init_image_addon()) {
        cout << "Blad inicjalizacji." << endl;
        return 1;
    }

    ALLEGRO_DISPLAY *display = al_create_display(screen_w, screen_h);
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();//kolejka zdarzen
    ALLEGRO_TIMER *timer = NULL;

    //bool redraw = true;
    bool doexit = false;

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
    ALLEGRO_BITMAP * wyniki = al_load_bitmap("wyniki.png");

    ALLEGRO_FONT *font = al_load_ttf_font("HappyMonkey-Regular.ttf",32,0 );


    timer = al_create_timer(1.0 / FPS);

    al_clear_to_color(al_map_rgb(0,0,0));

    al_draw_bitmap(ekran_glowny,0,0,0);
    al_flip_display();
    al_start_timer(timer);

    al_init_font_addon();
    al_init_ttf_addon();

    al_init_primitives_addon();

    //srand( time( NULL ) );

            Plansza gra;
            gra.ustawPozycjePoczatkowa();
            gra.wyswietlWGrze();

    while (!doexit)
    {
        // process events
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);


        if( mode == 0 ){


            al_draw_bitmap(ekran_glowny,0,0,0);
            ALLEGRO_FONT *font = al_load_ttf_font("HappyMonkey-Regular.ttf",32,0 );
            al_draw_textf(font, al_map_rgb( 0, 0, 0 ), 181, 39, ALLEGRO_ALIGN_CENTRE, "%d" , gra.podajWynik());
            al_flip_display();


            //Plansza gra;
             srand( time( NULL ) );
            //gra.wyswietlWKonsoli();
              gra.wyswietlWGrze();

            if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch(ev.keyboard.keycode){

                case ALLEGRO_KEY_LEFT:
                    //srand( time( NULL ) );
                    gra.wykonajRuch(4);
                    //gra.wyswietlWGrze();
                    gra.wyswietlWKonsoli();
                    gra.ustawLosowaLiczbe();

                    break;
                 case ALLEGRO_KEY_RIGHT:{
                    //srand( time( NULL ) );
                    gra.wykonajRuch(2);
                    //gra.wyswietlWGrze();
                    gra.wyswietlWKonsoli();
                    gra.ustawLosowaLiczbe();

                    break;}
                case ALLEGRO_KEY_UP:
                    //srand( time( NULL ) );
                    gra.wykonajRuch(1);
                    //gra.wyswietlWGrze();
                    gra.wyswietlWKonsoli();
                    gra.ustawLosowaLiczbe();

                    break;

                case ALLEGRO_KEY_DOWN:
                    //srand( time( NULL ) );
                    gra.wykonajRuch(3);
                    gra.wyswietlWGrze();
                    gra.wyswietlWKonsoli();
                    gra.ustawLosowaLiczbe();
                    break;
            }

            }
            // narazie wstepnie proponuje przejscie pomiedzy ekranami za pomoca wciskania przyciskow na klawiaturze
            // za pomoca klikniecia 'o' przechodzimy z ekranu glownego do menu
            if(ev.keyboard.keycode == ALLEGRO_KEY_O){
                mode = 1;
            }
            else if(ev.keyboard.keycode == ALLEGRO_KEY_Q){//wyjscie z gry moze nastapic w kazdym ekranie za pomoca 'q'
                break;
            }
            else if(ev.keyboard.keycode == ALLEGRO_KEY_E){//wyjscie z gry moze nastapic w kazdym ekranie za pomoca 'q'
                mode = 3;

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
            else if(ev.keyboard.keycode == ALLEGRO_KEY_P){//przejscie do ekranu gry za pomoca przycisku 'g'
                //Plansza gra;
                gra.wyczysc();
                gra.zerujWynik();
                gra.ustawPozycjePoczatkowa();
                gra.wyswietlWGrze();
                mode = 0;
            }
            else if(ev.keyboard.keycode == ALLEGRO_KEY_Q){//wyjscie z gry moze nastapic w kazdym ekranie za pomoca 'q'
                break;
            }
            else if(ev.keyboard.keycode == ALLEGRO_KEY_P){//przejscie do ekranu gry za pomoca przycisku 'g'
                mode = 0;
            }
        }

        else if ( mode == 2 ){
                al_draw_bitmap(tablica_wynikow,0,0,0);
                al_flip_display();
                wypisz_wyniki();

                if(ev.keyboard.keycode == ALLEGRO_KEY_O){//powrot z wynikow do menu za pomoca przycisku 'o'
                mode = 1;
                }
                else if(ev.keyboard.keycode == ALLEGRO_KEY_Q){//wyjscie z gry moze nastapic w kazdym ekranie za pomoca 'q'
                break;
                }



        }
        else if ( mode == 3 ){
                al_draw_bitmap(wyniki,0,0,0);
                al_flip_display();

                ALLEGRO_FONT *font = al_load_ttf_font("HappyMonkey-Regular.ttf",32,0 );
                al_draw_text(font, al_map_rgb( 0, 0, 0 ), 390, 35, ALLEGRO_ALIGN_CENTRE, "Koniec Gry!");

            //    ALLEGRO_FONT *font = al_load_ttf_font("HappyMonkey-Regular.ttf",32,0 );
                al_draw_text(font, al_map_rgb( 0, 0, 0 ), 390, 170, ALLEGRO_ALIGN_CENTRE, "Wpisz swoje imie:");
                al_flip_display();

                if(ev.keyboard.keycode == ALLEGRO_KEY_W){//powrot z wynikow do menu za pomoca przycisku 'o'
                mode = 2;
                }



                czytaj_wyniki();

               // wypisz_wyniki();

                wynik test;
                cout << "punkty: "; cin >> test.punkty;
                cout << "imie: "; cin >> test.imie;

                dodaj_wynik(test);



                wypisz_wyniki();

                zapisz_wyniki();

                mode = 2;




        }


    };

    return 0;
}
