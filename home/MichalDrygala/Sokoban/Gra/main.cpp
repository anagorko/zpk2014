#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include<allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <ctime>

#include <iostream>
using namespace std;

#include<clsMenu.h>
#include<clsPlansza.h>
#include<clsLudzik.h>
#include<clsSkrzynka.h>

const int screen_w = 1240;
const int screen_h = 600;
const float FPS = 60.0;
const int energia_ruchu = 7;
int czas = 0;
bool key[ALLEGRO_KEY_MAX];  // wciśnięte klawisze

int ruchy(clsPlansza& plansza1, clsLudzik& on, clsSkrzynka& s);
int WybierzLevel(ALLEGRO_EVENT_QUEUE *event_queue);

int main(){

/* ******************************************************************************************************************* */
/*Inicjalizacja allegro                                                                                                */
/* ******************************************************************************************************************* */

    al_init_font_addon();  //inicjalizacja czcionek

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
    ALLEGRO_FONT *font = al_load_ttf_font("arial.ttf", 34, 0 );
    ALLEGRO_FONT *font2 = al_load_ttf_font("arial.ttf", 24, 0 );

    al_set_window_title( display,"SOKOBAN VERSION 3.0 Drygala & Lemberski");//nazwa okna

//sprawdzenie poprawnosci wskaznikow
//
    if (display == NULL || timer == NULL || event_queue == NULL || font == NULL)
    {
        cout << "Blad inicjalizacji 2." << endl;
        return -1;
    }

//muzyka

    //inicjalizacja muzyki + kodeki
     if (!al_install_audio() || !al_init_acodec_addon() )
    {
        cout << "Blad inicjalizacji audio." << endl;
        return 1;
    }

    ALLEGRO_SAMPLE *songE = al_load_sample("music/0788.ogg");
    al_reserve_samples(1);
    ALLEGRO_SAMPLE_INSTANCE *songInstance = al_create_sample_instance(songE);
    al_set_sample_instance_playmode(songInstance, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(songInstance, al_get_default_mixer());
    al_play_sample_instance(songInstance);

    if (songE == NULL || songInstance == NULL)
    {
        cout << "Blad inicjalizacji 2." << endl;
        return -1;
    }

//kolejka zdarzen
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_start_timer(timer);

/* ********************************************************************************************************************************************** */
/* Petla MENU.                                                                                                                                 */
/* ********************************************************************************************************************************************** */
bool menu = false;
while(!menu)
{
    clsMenu objMenu;
    objMenu.WyswietlMenu();

    clsPlansza objPlansza(WybierzLevel(event_queue));

/* ********************************************************************************************************************************************** */
/* Petla tworzaca plansze.                                                                                                                                 */
/* ********************************************************************************************************************************************** */
    bool plansza = false;
    while(!plansza)
    {
    objPlansza.KonwertujDane();
    objPlansza.przygotuj_bitmapy();
    objPlansza.rysuj_statyczne();
    objPlansza.WyswietlKomunikat(font, font2);
    clsLudzik objLudzik(objPlansza.PozycjaLudzikaWiersz(), objPlansza.PozycjaLudzikaKolumna()); //tworzy obiekt ze wspolrzedntmi
    clsSkrzynka objSkrzynka(objPlansza);

/* ********************************************************************************************************************************************** */
/* Glowna petla                                                                                                                                   */
/* ********************************************************************************************************************************************** */
bool wyjdz = false;
while(!wyjdz)
{

//animacja
    czas++;
    int x = (czas / 40) % 4;
    objPlansza.rysuj_statyczne();
    objPlansza.WyswietlKomunikat(font, font2);
    objPlansza.rysuj_ruchome(objLudzik, objSkrzynka, x);


        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_TIMER)  // minęła 1/60 (1/FPS) część sekundy
        {
            objLudzik.set_energia(objLudzik.get_energia() + 1);
            int a = ruchy(objPlansza, objLudzik, objSkrzynka);
            if (a == 1) {wyjdz = true;}
            if (a == 2) {wyjdz = true; plansza = true;}
        }
        else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {   key[ev.keyboard.keycode] = true;
        }
        else if (ev.type == ALLEGRO_EVENT_KEY_UP)
        {   key[ev.keyboard.keycode] = false;

            if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
            {
                wyjdz = true;
                plansza = true;
                menu = true;
            }
            if (ev.keyboard.keycode == ALLEGRO_KEY_R)
            {   wyjdz = true;
            }
            if (ev.keyboard.keycode == ALLEGRO_KEY_M)
            {
                wyjdz = true;
                plansza = true;
            }
        }

        al_flip_display();

        }//koniet petli while(!wyjdz)
    }//koniet petli while(!plansze)
}//koniec petli while(!menu)

    return 0;
}

/* ******************************************************************************************************************************************* */
/* FUNKCJE                                                                                                                                     */
/* ******************************************************************************************************************************************* */

int ruchy(clsPlansza& plansza1, clsLudzik& on, clsSkrzynka& s)
{
    int x = on.get_X();
    int y = on.get_Y();
    int energia = on.get_energia();

    if (key[ALLEGRO_KEY_LEFT] && energia > energia_ruchu)
    {
        if ((plansza1.get_tblPodloga(x, y - 1)== 0 || plansza1.get_tblPodloga(x, y - 1)== 6) && (s.get_tblSkrzynkiS(x, y - 1) == 0))
        {   energia = 0; y--;
        }
        else if ((s.get_tblSkrzynkiS(x, y - 1) == 1) && (s.get_tblSkrzynkiS(x, y - 2) == 0) && (plansza1.get_tblPodloga(x, y - 2) == 0 || plansza1.get_tblPodloga(x, y - 2) == 6))
        {
            s.set_tblSkrzynkiS(x, y - 1, 0);
            s.set_tblSkrzynkiS(x, y - 2, 1);
            energia = 0; y--;
        }
    }
    if (key[ALLEGRO_KEY_RIGHT] && energia > energia_ruchu)
    {   if ((plansza1.get_tblPodloga(x, y + 1) == 0 || plansza1.get_tblPodloga(x, y + 1) == 6) && (s.get_tblSkrzynkiS(x, y + 1) == 0))
        {   energia = 0; y++;
        }
        else if ((s.get_tblSkrzynkiS(x, y + 1) == 1) && (s.get_tblSkrzynkiS(x, y + 2) == 0) && (plansza1.get_tblPodloga(x, y + 2) == 0 || plansza1.get_tblPodloga(x, y + 2) == 6))
        {
            s.set_tblSkrzynkiS(x, y + 1, 0);
            s.set_tblSkrzynkiS(x, y + 2, 1);
            energia = 0; y++;
        }
    }
    if (key[ALLEGRO_KEY_DOWN] && energia > energia_ruchu)
    {
        if ((plansza1.get_tblPodloga(x + 1, y) == 0 || plansza1.get_tblPodloga(x + 1, y) == 6) && (s.get_tblSkrzynkiS(x + 1, y) == 0))
        {   energia = 0; x++;
        }
        else if ((s.get_tblSkrzynkiS(x + 1, y) == 1) && (s.get_tblSkrzynkiS(x + 2, y) == 0) && (plansza1.get_tblPodloga(x + 2, y) == 0 || plansza1.get_tblPodloga(x + 2, y) == 6))
        {
            s.set_tblSkrzynkiS(x + 1, y, 0);
            s.set_tblSkrzynkiS(x + 2, y, 1);
            energia = 0; x++;
        }
    }
    if (key[ALLEGRO_KEY_UP] && energia > energia_ruchu)
    {
        if ((plansza1.get_tblPodloga(x - 1, y) == 0 || plansza1.get_tblPodloga(x - 1, y) == 6) && (s.get_tblSkrzynkiS(x - 1, y) == 0))
        {   energia = 0; x--;
        }
        else if ((s.get_tblSkrzynkiS(x - 1, y) == 1) && (s.get_tblSkrzynkiS(x - 2, y) == 0) && (plansza1.get_tblPodloga(x - 2, y) == 0 || plansza1.get_tblPodloga(x - 2, y) ==  6))
        {
            s.set_tblSkrzynkiS(x - 1, y, 0);
            s.set_tblSkrzynkiS(x - 2, y, 1);
            energia = 0; x--;
        }
    }

    on.set_X(x);
    on.set_Y(y);
    on.set_energia(energia);
//    plansza1.rysuj_statyczne();

    return s.CzyUkonczono(plansza1);
}

/* *************************************************************************************************************************************************/

int WybierzLevel(ALLEGRO_EVENT_QUEUE *event_queue)
{
    bool wyjdz = false;
    while(!wyjdz)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_TIMER)  // minęła 1/60 (1/FPS) część sekundy
        {
            if (key[ALLEGRO_KEY_1] || key[ALLEGRO_KEY_PAD_1])
            {   return 1;  }

            if (key[ALLEGRO_KEY_2] || key[ALLEGRO_KEY_PAD_2])
            {   return 2; }

            if (key[ALLEGRO_KEY_3] || key[ALLEGRO_KEY_PAD_3])
            {   return 3; }

            if (key[ALLEGRO_KEY_4] || key[ALLEGRO_KEY_PAD_4])
            {   return 4; }

            if (key[ALLEGRO_KEY_5] || key[ALLEGRO_KEY_PAD_5])
            {   return 5; }
        }
        else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {   key[ev.keyboard.keycode] = true;
        }
        else if (ev.type == ALLEGRO_EVENT_KEY_UP)
        {   key[ev.keyboard.keycode] = false;
            if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
            {   exit(0);
            }
        }
    }
    return -1;
}
