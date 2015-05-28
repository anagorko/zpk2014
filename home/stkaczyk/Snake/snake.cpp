#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<cstdlib>
#include<fstream>
using namespace std;

#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>

const int screen_w = 800;
const int screen_h = 600;
const float FPS = 60.0;

class ElementKolejki
{
    virtual ostream& output(ostream&) const = 0;

public:
    virtual ~ElementKolejki() = 0;

    friend ostream& operator<<(ostream& os, ElementKolejki& el);
};

ElementKolejki::~ElementKolejki() {}

ostream& operator<<(ostream& os, ElementKolejki& el)
{
    el.output(os);
    return os;
}

class Punkt : public ElementKolejki  //Pole na planszy
{
    int x;
    int y;

    virtual ostream& output(ostream& os) const {
        return os << "(" <<  x << "," << y << ")";
    }

public:

    Punkt() : Punkt(0, 0) {
    }
    Punkt(int _x, int _y) {
        x = _x; y = _y;
    }

    ~Punkt() {}

    int getX() { return x; }
    int getY() { return y; }
};

class Kolejka
{
    struct Link
    {
        ElementKolejki    *dane;
        Link            *nastepny;
    };

    Link* pierwszy;
    Link* ostatni;
    int dlugosc;

public:
    Kolejka() {
        pierwszy = NULL;
        ostatni = NULL;
        dlugosc = 0;
    }

    ~Kolejka() {
        while (pierwszy != NULL) {
            delete pop();
        }
    }

    void push(ElementKolejki* el) {
        Link *nowy = new Link;

        nowy -> nastepny = NULL;
        nowy -> dane = el;

        if(dlugosc == 0) {
            pierwszy = nowy;
            ostatni = nowy;
        }
        else {
            ostatni -> nastepny = nowy;
            ostatni = nowy;
        }
        dlugosc += 1;
    }

    ElementKolejki* pop() {
        if (dlugosc == 0) return NULL;

        ElementKolejki *wynik = pierwszy -> dane;
        Link* nastepny = pierwszy -> nastepny;
        delete pierwszy;
        pierwszy = nastepny;

        if(dlugosc == 1){
            ostatni = NULL;
        }

        dlugosc -= 1;

        return wynik;
    }
    bool empty()
    {
        if(dlugosc == 0)
            return true;
        else
            return false;
    };

    int size()
    {
        return dlugosc;
    };

    friend ostream& operator<<(ostream&, Kolejka &);
};

ostream& operator<<(ostream& os, Kolejka &s) {
    os << "[";

    Kolejka::Link *el = s.pierwszy;
    while (el != NULL) {
        os << *(el->dane);
        el = el -> nastepny;
        if (el != NULL) { cout << ", "; }
    }

    os << "]";
    return os;
}

class Waz
{
    Kolejka pola; //Kolejne pola zajmowane przez weza na planszy
    int kierunek; //Samoczynny ruch weza: 0 - prawo, 1 - lewo, 2 - dół, 3 - góra

public:
    void zmien_kierunek(int kierunek); //Zmienia kierunek weza

    void ruch_glowy(bool tryb_bez_scian); //Przesuniecie glowy weza wg aktualnego kierunku.
                                          //W trybie ze scianami glowa moze sie znalezc poza plansza.
                                          //W trybie bez scian glowa moze sie znalezc po przeciwnej stronie planzzy.

    void skroc(); //usuniecie ostatniego pola weza

    Punkt glowa(); //zwraca pole zajmowane przez glowe weza

    bool czy_nalezy(Punkt p); //sprawdza czy na polu jest waz

    bool czy_zapetlony();
};

class Plansza
{
    const int wymiar_x = 30;
    const int wymiar_y = 20;
    int wynik = 0; //Liczba zjedzonych jablek

    Waz waz;

    Punkt jablko;

    bool tryb_bez_scian;

public:
    void wyswietl(); //Wyswietla aktualny stan planszy na ekranie

    void zmien_kierunek(int kierunek); //Zmienia kierunek weza

    void ruch_weza(); //Przesuwa weza

    bool czy_kolizja(); //Sprawdza czy wystapila kolizja

    void nowe_jablko(); //Generuje nowe jablko
};



int main(int, char**)
{
    if (!al_init() || !al_install_keyboard() || !al_init_image_addon()) {
        cout << "Błąd inicjalizacji." << endl;
        return 1;
    }

    ALLEGRO_DISPLAY *display = al_create_display(screen_w, screen_h);
    ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

    if (display == NULL || timer == NULL || event_queue == NULL) {
        cout << "Błąd inicjalizacji." << endl;
        return 2;
    }

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    ALLEGRO_BITMAP *menu = al_load_bitmap("grafika/snake_menu.png");
    ALLEGRO_BITMAP *wyniki = al_load_bitmap("grafika/highscores.png");
    ALLEGRO_BITMAP *tryb = al_load_bitmap("grafika/tryb_menu.png");

    al_clear_to_color(al_map_rgb(255,255,255));

    al_draw_bitmap(menu,0,0,0);
    al_flip_display();

    al_start_timer(timer);

    int poziom_menu = 1; //1 - menu glowne, 2 - tryb, 3 -  highscores, 4 - gra

    while (true)
    {
        // process events
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }

        else if(ev.keyboard.keycode == ALLEGRO_KEY_Q) {
            break;
        }
        if (poziom_menu == 1){
            if(ev.keyboard.keycode == ALLEGRO_KEY_S) {
                al_draw_bitmap(tryb,0,0,0);
                al_flip_display();
                poziom_menu = 2;
            }
            else if(ev.keyboard.keycode == ALLEGRO_KEY_H) {
                al_clear_to_color(al_map_rgb(255,255,255));
                al_draw_bitmap(wyniki,0,0,0);
                al_flip_display();
                poziom_menu = 3;
            }
        }
        if (poziom_menu == 2){
            if(ev.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
                al_clear_to_color(al_map_rgb(0,255,255));
                al_flip_display();
                poziom_menu = 4;
            }
            else if(ev.keyboard.keycode == ALLEGRO_KEY_LEFT) {
                al_clear_to_color(al_map_rgb(255,255,0));
                al_flip_display();
                poziom_menu = 4;
            }
        }
        if (poziom_menu == 2 || poziom_menu == 3 || poziom_menu == 4){
            if(ev.keyboard.keycode == ALLEGRO_KEY_BACKSPACE) {
                al_draw_bitmap(menu,0,0,0);
                al_flip_display();
                poziom_menu = 1;
            }
        }
    }

    //WRZUC DO GITHUBA !!!

    al_stop_timer(timer); //zatrzymanie zegarka
    float life_time = al_get_timer_count(timer) / FPS;
    cout  << "Czas gry: " << life_time << " seconds!" << endl;

    return 0;
}
