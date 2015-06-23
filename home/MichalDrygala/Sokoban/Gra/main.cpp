#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include<allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>

#include <iostream>
using namespace std;

#include<clsMenu.h>
#include<clsPlansza.h>
#include<clsLudzik.h>
#include<clsSkrzynka.h>

const int screen_w = 800;
const int screen_h = 600;
const float FPS = 60.0;
const int energia_ruchu = 7;

bool key[ALLEGRO_KEY_MAX];  // wciśnięte klawisze

int czas = 0;

void rysuj_ruchome(clsLudzik, clsSkrzynka, int);

void ruchy(clsPlansza& plansza1, clsLudzik& on, clsSkrzynka& s)
{
    int x = on.get_X();
    int y = on.get_Y();
    int energia = on.get_energia();

    if (key[ALLEGRO_KEY_LEFT] && energia > energia_ruchu)
    {
        if ((plansza1.get_tblPodloga(x, y - 1)== 0 || plansza1.get_tblPodloga(x, y - 1)== 6) && (s.get_tblSkrzynkiS(x, y - 1) == 0))
        {
            energia = 0; y--;
        }
        else if ((s.get_tblSkrzynkiS(x, y - 1) == 1) && (s.get_tblSkrzynkiS(x, y - 2) == 0) && (plansza1.get_tblPodloga(x, y - 2) == 0 || plansza1.get_tblPodloga(x, y - 2) == 6))
        {
            s.set_tblSkrzynkiS(x, y - 1, 0);
            s.set_tblSkrzynkiS(x, y - 2, 1);
            energia = 0; y--;
        }
        plansza1.rysuj_statyczne();
    }
    if (key[ALLEGRO_KEY_RIGHT] && energia > energia_ruchu)
    {   if ((plansza1.get_tblPodloga(x, y + 1) == 0 || plansza1.get_tblPodloga(x, y + 1) == 6) && (s.get_tblSkrzynkiS(x, y + 1) == 0))
        {
            energia = 0; y++;
        }
        else if ((s.get_tblSkrzynkiS(x, y + 1) == 1) && (s.get_tblSkrzynkiS(x, y + 2) == 0) && (plansza1.get_tblPodloga(x, y + 2) == 0 || plansza1.get_tblPodloga(x, y + 2) == 6))
        {
            s.set_tblSkrzynkiS(x, y + 1, 0);
            s.set_tblSkrzynkiS(x, y + 2, 1);
            energia = 0; y++;
        }
        plansza1.rysuj_statyczne();
    }
    if (key[ALLEGRO_KEY_DOWN] && energia > energia_ruchu)
    {
        if ((plansza1.get_tblPodloga(x + 1, y) == 0 || plansza1.get_tblPodloga(x + 1, y) == 6) && (s.get_tblSkrzynkiS(x + 1, y) == 0))
        {
            energia = 0; x++;
        }
        else if ((s.get_tblSkrzynkiS(x + 1, y) == 1) && (s.get_tblSkrzynkiS(x + 2, y) == 0) && (plansza1.get_tblPodloga(x + 2, y) == 0 || plansza1.get_tblPodloga(x + 2, y) == 6))
        {
            s.set_tblSkrzynkiS(x + 1, y, 0);
            s.set_tblSkrzynkiS(x + 2, y, 1);
            energia = 0; x++;
        }
        plansza1.rysuj_statyczne();
    }
    if (key[ALLEGRO_KEY_UP] && energia > energia_ruchu)
    {
        if ((plansza1.get_tblPodloga(x - 1, y) == 0 || plansza1.get_tblPodloga(x - 1, y) == 6) && (s.get_tblSkrzynkiS(x - 1, y) == 0))
        {
            energia = 0; x--;
        }
        else if ((s.get_tblSkrzynkiS(x - 1, y) == 1) && (s.get_tblSkrzynkiS(x - 2, y) == 0) && (plansza1.get_tblPodloga(x - 2, y) == 0 || plansza1.get_tblPodloga(x - 2, y) ==  6))
        {
            s.set_tblSkrzynkiS(x - 1, y, 0);
            s.set_tblSkrzynkiS(x - 2, y, 1);
            energia = 0; x--;
        }
        plansza1.rysuj_statyczne();
    }

    on.set_X(x);
    on.set_Y(y);
    on.set_energia(energia);
}


/*

void ruchy(clsPlansza& plansza1, clsLudzik& on)
{
    int x = on.get_X();
    int y = on.get_Y();
    int energia = on.get_energia();

    if (key[ALLEGRO_KEY_LEFT] && energia > energia_ruchu)
    {
        if ((plansza1.get_tblPodloga(x, y - 1)== 0 || plansza1.get_tblPodloga(x, y - 1)== 6) && (plansza1.tblSkrzynki[x][y-1] == 0))
        {
            energia = 0; y--;
        }
        else if ((plansza1.tblSkrzynki[x][y-1] == 1) && (plansza1.tblSkrzynki[x][y-2] == 0) && (plansza1.get_tblPodloga(x, y - 2) == 0 || plansza1.get_tblPodloga(x, y - 2) == 6))
        {
            plansza1.tblSkrzynki[x][y-1] = 0;
            plansza1.tblSkrzynki[x][y-2] = 1;
            energia = 0; y--;
        }
        plansza1.rysuj_statyczne();
    }
    if (key[ALLEGRO_KEY_RIGHT] && energia > energia_ruchu)
    {   if ((plansza1.get_tblPodloga(x, y + 1) == 0 || plansza1.get_tblPodloga(x, y + 1) == 6) && (plansza1.tblSkrzynki[x][y+1] == 0))
        {
            energia = 0; y++;
        }
        else if ((plansza1.tblSkrzynki[x][y+1] == 1) && (plansza1.tblSkrzynki[x][y+2] == 0) && (plansza1.get_tblPodloga(x, y + 2) == 0 || plansza1.get_tblPodloga(x, y + 2) == 6))
        {
            plansza1.tblSkrzynki[x][y+1] = 0;
            plansza1.tblSkrzynki[x][y+2] = 1;
            energia = 0; y++;
        }
        plansza1.rysuj_statyczne();
    }
    if (key[ALLEGRO_KEY_DOWN] && energia > energia_ruchu)
    {
        if ((plansza1.get_tblPodloga(x + 1, y) == 0 || plansza1.get_tblPodloga(x + 1, y) == 6) && (plansza1.tblSkrzynki[x+1][y] == 0))
        {
            energia = 0; x++;
        }
        else if ((plansza1.tblSkrzynki[x+1][y] == 1) && (plansza1.tblSkrzynki[x+2][y] == 0) && (plansza1.get_tblPodloga(x + 2, y) == 0 || plansza1.get_tblPodloga(x + 2, y) == 6))
        {
            plansza1.tblSkrzynki[x+1][y] = 0;
            plansza1.tblSkrzynki[x+2][y] = 1;
            energia = 0; x++;
        }
        plansza1.rysuj_statyczne();
    }
    if (key[ALLEGRO_KEY_UP] && energia > energia_ruchu)
    {
        if ((plansza1.get_tblPodloga(x - 1, y) == 0 || plansza1.get_tblPodloga(x - 1, y) == 6) && (plansza1.tblSkrzynki[x-1][y] == 0))
        {
            energia = 0; x--;
        }
        else if ((plansza1.tblSkrzynki[x-1][y] == 1) && (plansza1.tblSkrzynki[x-2][y] == 0) && (plansza1.get_tblPodloga(x - 2, y) == 0 || plansza1.get_tblPodloga(x - 2, y) ==  6))
        {
            plansza1.tblSkrzynki[x-1][y] = 0;
            plansza1.tblSkrzynki[x-2][y] = 1;
            energia = 0; x--;
        }
        plansza1.rysuj_statyczne();
    }

    on.set_X(x);
    on.set_Y(y);
    on.set_energia(energia);
}
*/



/*
void ruchy(clsPlansza& plansza1, clsLudzik& on)
{
    int x = on.get_X();
    int y = on.get_Y();
    int energia = on.get_energia();

    if (key[ALLEGRO_KEY_LEFT] && energia > energia_ruchu)
    {
        if ((plansza1.tblPodloga[x][y-1] == 0 || 6) && (plansza1.tblSkrzynki[x][y-1] == 0))
        {
            energia = 0; y--;
        }
        else if ((plansza1.tblSkrzynki[x][y-1] == 1) && (plansza1.tblSkrzynki[x][y-2] == 0) && (plansza1.tblPodloga[x][y-2] == 0 || 6))
        {
            plansza1.tblSkrzynki[x][y-1] = 0;
            plansza1.tblSkrzynki[x][y-2] = 1;
            energia = 0; y--;
        }
        plansza1.rysuj_statyczne();
    }
    if (key[ALLEGRO_KEY_RIGHT] && energia > energia_ruchu) {
        if ((plansza1.tblPodloga[x][y+1] == 0 || 6) && (plansza1.tblSkrzynki[x][y+1] == 0))
        {
            energia = 0; y++;
        }
        else if ((plansza1.tblSkrzynki[x][y+1] == 1) && (plansza1.tblSkrzynki[x][y+2] == 0) && (plansza1.tblPodloga[x][y+2] == 0 || 6))
        {
            plansza1.tblSkrzynki[x][y+1] = 0;
            plansza1.tblSkrzynki[x][y+2] = 1;
            energia = 0; y++;
        }
        plansza1.rysuj_statyczne();
    }
    if (key[ALLEGRO_KEY_DOWN] && energia > energia_ruchu)
    {
        if ((plansza1.tblPodloga[x+1][y] == 0 || 6) && (plansza1.tblSkrzynki[x+1][y] == 0))
        {
            energia = 0; x++;
        }
        else if ((plansza1.tblSkrzynki[x+1][y] == 1) && (plansza1.tblSkrzynki[x+2][y] == 0) && (plansza1.tblPodloga[x+2][y] == 0 || 6))
        {
            plansza1.tblSkrzynki[x+1][y] = 0;
            plansza1.tblSkrzynki[x+2][y] = 1;
            energia = 0; x++;
        }
        plansza1.rysuj_statyczne();
    }
    if (key[ALLEGRO_KEY_UP] && energia > energia_ruchu)
    {
        if ((plansza1.tblPodloga[x-1][y] == 0 || 6) && (plansza1.tblSkrzynki[x-1][y] == 0))
        {
            energia = 0; x--;
        }
        else if ((plansza1.tblSkrzynki[x-1][y] == 1) && (plansza1.tblSkrzynki[x-2][y] == 0) && (plansza1.tblPodloga[x-2][y] == 0 || 6))
        {
            plansza1.tblSkrzynki[x-1][y] = 0;
            plansza1.tblSkrzynki[x-2][y] = 1;
            energia = 0; x--;
        }
        plansza1.rysuj_statyczne();
    }

    on.set_X(x);
    on.set_Y(y);
    on.set_energia(energia);
}
*/


int main(){

/* ******************************************************************************************************************* */
/*Inicjalizacja allegro                                                                                                */
/* ******************************************************************************************************************* */

//inicjalizacja czcionek
    al_init_font_addon();

//inicjalizacja allegro + klawiatury + obrazow + czcionek ttf
    if (!al_init() || !al_install_keyboard()  || !al_init_image_addon() || !al_init_ttf_addon())
    {
        cout << "Blad inicjalizacji 1." << endl;
        return 1;
    }

// wskazniki na ekran, czas, kolejke zdarzen, czcionke
    ALLEGRO_DISPLAY *display = al_create_display(screen_w, screen_h);
    ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    ALLEGRO_FONT *font = al_load_ttf_font("arial.ttf", 12, 0 );

 al_set_window_title( display,"SOKOBAN VERSION 3.0 Drygala & Lemberski");//nazwa okna

//sprawdzenie poprawnosci wskaznikow
    if (display == NULL || timer == NULL || event_queue == NULL || font == NULL)
    {
        cout << "Blad inicjalizacji 2." << endl;
        return 2;
    }
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_start_timer(timer);

//   al_clear_to_color(al_map_rgb(0,0,0));
/*    al_flip_display();

*/

/* ******************************************************************************************************************* */
/*Wyswietlenie MENU wraz z komunikatem powitalnym. Mozliwosc wybrania odpowiedniej planszy oraz wyjscia z programu.    */
/* ******************************************************************************************************************* */

    clsMenu objMenu;
    objMenu.WyswietlKomunikat(font);

    int a;
    cin >> a;


//<> wybiera odpowiedni¹ planszê (decyduje u¿ytkownik)
//<> wy³¹cza program (decyduje u¿ytkownik)



/* ******************************************************************************************************************* */
/*  Wyswietlenie Planszy, wczytanie danych, rysowanie Planszy wraz z mozliwoscia wyswietlenie MENU.                    */
/* ******************************************************************************************************************* */

    clsPlansza objPlansza;
    objPlansza.WczytajDane();
    objPlansza.WypiszDane();
    objPlansza.KonwertujDane();
    objPlansza.przygotuj_bitmapy();
    objPlansza.rysuj_statyczne();
    //objPlansza.WyswietlMenu();

/* ******************************************************************************************************************* */
/*  Poruszanie ludzikiem, sprawdzenie czy ma energie, czy ruch mozliwy, czy stoi obok skrzynki -> ruch Skrzynka        */
/* ******************************************************************************************************************* */

        clsLudzik objLudzik(objPlansza.PozycjaLudzikaWiersz(), objPlansza.PozycjaLudzikaKolumna()); //tworzy obiekt ze wspolrzedntmi

/* ******************************************************************************************************************* */
/*  Poruszanie Skrzynka, sprawdzenie czy ruch mozliwy, czy ukonczono Plansze ->                                        */
/*  -> zapisanie ze ukonczono plansze, sprawdzenie czy sa jakies nieukonczone plansze -> narysowanie / koniec gry      */
/* ******************************************************************************************************************* */
/*
friend void SkopiujTabele (clsPlansza p, clsSkrzynka s)

for{
    {
        s.setTblSkrzynki(i,j, p.tblSkrzynka[i][j])
    }

getTblSkrzynki(i ,j) {return TblSK[i][j]}

        int x = objPlansza.PozycjaSkrzynkiWiersz();
        int y = objPlansza.PozycjaSkrzynkiKolumna();
        clsSkrzynka objSkrzynka(x, y);

        */
    //objSkrzynka.MozliwyRuch();
    //objSkrzynka.Ruch();


    clsSkrzynka objSkrzynka(objPlansza);


    objPlansza.rysuj_ruchome(objLudzik, objSkrzynka, 0);


    bool wyjdz = false;

    while(!wyjdz)
    {

    //animacja
    czas++;
    int x = (czas / 40) % 4;
    objPlansza.rysuj_ruchome(objLudzik, objSkrzynka, x);


        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_TIMER) {
            //
            // minęła 1/60 (1/FPS) część sekundy
            //

            objLudzik.set_energia(objLudzik.get_energia() + 1);
            objPlansza.rysuj_ruchome(objLudzik, objSkrzynka, x);
            ruchy(objPlansza, objLudzik, objSkrzynka);
}
        else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            key[ev.keyboard.keycode] = true;
        }
        else if (ev.type == ALLEGRO_EVENT_KEY_UP)
        {
            key[ev.keyboard.keycode] = false;

            if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
            {
                wyjdz = true;
            }
        }
           al_flip_display();
    }

    return 0;
}
