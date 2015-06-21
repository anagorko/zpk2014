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

//sprawdzenie poprawnosci wskaznikow
    if (display == NULL || timer == NULL || event_queue == NULL || font == NULL)
    {
        cout << "Blad inicjalizacji 2." << endl;
        return 2;
    }


 /*   al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

*/    al_clear_to_color(al_map_rgb(0,0,0));
/*    al_flip_display();

  al_start_timer(timer);
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
   // objPlansza.przygotuj_plansze();
    objPlansza.rysuj_plansze();


    cin >> a;
    //objPlansza.WyswietlMenu();
// Rysuje siê na okr¹g³o.



/* ******************************************************************************************************************* */
/*  Poruszanie ludzikiem, sprawdzenie czy ma energie, czy ruch mozliwy, czy stoi obok skrzynki -> ruch Skrzynka        */
/* ******************************************************************************************************************* */

    //clsLudzik objLudzik;
//<> jeœli U¿ytkownik wykona³ ruch Ludzikiem:
    //objLudzik.SprawdzEnergie();
    //objLudzik.MozliwyRuch();
    //objLudzik.ObokSkrzynka();
    //objLudzik.Ruch();


/* ******************************************************************************************************************* */
/*  Poruszanie Skrzynka, sprawdzenie czy ruch mozliwy, czy ukonczono Plansze ->                                        */
/*  -> zapisanie ze ukonczono plansze, sprawdzenie czy sa jakies nieukonczone plansze -> narysowanie / koniec gry      */
/* ******************************************************************************************************************* */

    //clsSkrzynka objSkrzynka;
    //objSkrzynka.MozliwyRuch();
    //objSkrzynka.Ruch();

/*    if (objSkrzynka.CzyUkonczono()) // sprawdza czy ukonczono plansze
    {
       objPlansza.Ukonczono();    // zapisanie ze plansze ukonczono

        if (objPlansza.CzySaNieukonczone()) // sprawdcza czy sa jescze jakies nieukonczone plansze
        {
            // Rysuje nasteppna planszê
        }
        else
            // Koñczy program (jeœli to ostatnia ukoñczona plansza).
    }
*/
    return 0;
}
