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
//int energia = 100;

bool key[ALLEGRO_KEY_MAX];  // wciśnięte klawisze

int PozycjaLudzikaWiersz(clsPlansza);
int PozycjaLudzikaKolumna(clsPlansza);

int czas = 0;

void rysuj_ruchome(clsLudzik, int);

void ruchy(clsPlansza& plansza1, clsLudzik& on)
{
    int x = on.get_X();
    int y = on.get_Y();
    int energia = on.get_energia();
    //int ile_bomb = p.g[0].ile_bomb;
    //bool moze_stawiac = p.g[0].moze_stawiac;

    if (key[ALLEGRO_KEY_LEFT] && energia > energia_ruchu)
    {
        if ((plansza1.tblPodloga[x][y-1] == 0 || 6) && (plansza1.tblSkrzynki[x][y-1] == 0))
        {
            energia = 0; y--;
            cout << "lewo" << endl;
        }
        else if ((plansza1.tblSkrzynki[x][y-1] == 1) && (plansza1.tblSkrzynki[x][y-2] == 0) && (plansza1.tblPodloga[x][y-2] == 0 || 6))
        {
            plansza1.tblSkrzynki[x][y-1] = 0;
            plansza1.tblSkrzynki[x][y-2] = 1;
            energia = 0; y--;
            cout << "lewo - dłuzsza" << endl;
        }
        plansza1.rysuj_statyczne();
    }
    if (key[ALLEGRO_KEY_RIGHT] && energia > energia_ruchu) {
        if ((plansza1.tblPodloga[x][y+1] == 0 || 6) && (plansza1.tblSkrzynki[x][y+1] == 0))
        {
            energia = 0; y++;
            cout << "prawo" << endl;
        }
        else if ((plansza1.tblSkrzynki[x][y+1] == 1) && (plansza1.tblSkrzynki[x][y+2] == 0) && (plansza1.tblPodloga[x][y+2] == 0 || 6))
        {
            plansza1.tblSkrzynki[x][y+1] = 0;
            plansza1.tblSkrzynki[x][y+2] = 1;
            energia = 0; y++;
            cout << "prawo - dłuzsza" << endl;
        }
        plansza1.rysuj_statyczne();
    }
    if (key[ALLEGRO_KEY_DOWN] && energia > energia_ruchu)
    {
        if ((plansza1.tblPodloga[x+1][y] == 0 || 6) && (plansza1.tblSkrzynki[x+1][y] == 0))
        {
            energia = 0; x++;
            cout << "gora" << endl;
        }
        else if ((plansza1.tblSkrzynki[x+1][y] == 1) && (plansza1.tblSkrzynki[x+2][y] == 0) && (plansza1.tblPodloga[x+2][y] == 0 || 6))
        {
            plansza1.tblSkrzynki[x+1][y] = 0;
            plansza1.tblSkrzynki[x+2][y] = 1;
            energia = 0; x++;
            cout << "gora - dłuzsza" << endl;
        }
        plansza1.rysuj_statyczne();
    }
    if (key[ALLEGRO_KEY_UP] && energia > energia_ruchu)
    {
        if ((plansza1.tblPodloga[x-1][y] == 0 || 6) && (plansza1.tblSkrzynki[x-1][y] == 0))
        {
            energia = 0; x--;
            cout << "dol" << endl;
        }
        else if ((plansza1.tblSkrzynki[x-1][y] == 1) && (plansza1.tblSkrzynki[x-2][y] == 0) && (plansza1.tblPodloga[x-2][y] == 0 || 6))
        {
            plansza1.tblSkrzynki[x-1][y] = 0;
            plansza1.tblSkrzynki[x-2][y] = 1;
            energia = 0; x--;
            cout << "dol - dłuzsza" << endl;
        }
        plansza1.rysuj_statyczne();
    }

    on.set_X(x);
    on.set_Y(y);
    on.set_energia(energia);
}
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
// Rysuje siê na okr¹g³o.

/* ******************************************************************************************************************* */
/*  Poruszanie ludzikiem, sprawdzenie czy ma energie, czy ruch mozliwy, czy stoi obok skrzynki -> ruch Skrzynka        */
/* ******************************************************************************************************************* */
        int x = objPlansza.PozycjaLudzikaWiersz();
        int y = objPlansza.PozycjaLudzikaKolumna();
        clsLudzik objLudzik(x, y);

        objPlansza.rysuj_ruchome(objLudzik, 0);

//        cout << endl << "czy mozna ruszyc sie w D: " << objLudzik.MozliwyRuch(objPlansza, 'D') << " G: " << objLudzik.MozliwyRuch(objPlansza, 'G');
 //       cout    << " L: " << objLudzik.MozliwyRuch(objPlansza, 'L') << " P: " << objLudzik.MozliwyRuch(objPlansza, 'P');

/*
while(true)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

int x = 0;
if (static_cast<long int>(time(NULL))%4 == 0)
{  x = 1;  }

cout << x << " " << timer << " " ;
objPlansza.rysuj_ruchome(x);


        if (ev.type == ALLEGRO_EVENT_KEY_UP)
        {
            if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                break;
            }
        }
    }*/

//<> jeœli U¿ytkownik wykona³ ruch Ludzikiem:
    //objLudzik.SprawdzEnergie();
    //objLudzik.MozliwyRuch();
    //objLudzik.ObokSkrzynka();
    //objLudzik.Ruch();

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
}


getTblSkrzynki(i ,j) {return TblSK[i][j]}

        int x = objPlansza.PozycjaSkrzynkiWiersz();
        int y = objPlansza.PozycjaSkrzynkiKolumna();
        clsSkrzynka objSkrzynka(x, y);


        */
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
cout << "ludzika X: " << objLudzik.get_X() << " ludzika Y: " << objLudzik.get_Y();
bool wyjdz = false;

  while(!wyjdz)
    { //cout << "czas" << czas << endl;
    //animacja
    czas++;
    int x = (czas /50) % 4;
    objPlansza.rysuj_ruchome(objLudzik, x);


        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_TIMER) {
            //
            // minęła 1/60 (1/FPS) część sekundy
            //

            objLudzik.set_energia(objLudzik.get_energia() + 1);
            objPlansza.rysuj_ruchome(objLudzik, x);
            ruchy(objPlansza, objLudzik);
}
        else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            key[ev.keyboard.keycode] = true;
        } else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
            key[ev.keyboard.keycode] = false;

            if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                wyjdz = true;
            }
        }

         //  al_flip_display();
         }

    return 0;
}
