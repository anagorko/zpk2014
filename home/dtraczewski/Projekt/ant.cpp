#include <iomanip>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

#define M_PI 3.14159265358979323846264338327


const int screen_w = 800;
const int screen_h = 600;

const int north = 1;
const int east = 2;
const int south = 3;
const int west = 4;

class Point
{
    double x, y;

public:
    Point(): Point (0.0, 0.0) {}

    Point(double _x, double _y) {
        setX(_x);
        setY(_y);
    }

    void setX(double _x) {x = _x;}
    void setY(double _y) {y = _y;}

    double getX() const {return x;}
    double getY() const {return y;}

    Point& operator*=(float f) {
        x *= f;
        y *= f;
        return *this;
    }

    Point& operator+=(Point v){
        x += v.x;
        y += v.y;
        return *this;
    }

    bool operator<(const Point &a) const
    {
        return getX() < a.getX() || (getX() == a.getX() && getY() < a.getY());
    }

    bool operator==(const Point &p) const
    {
        return (getX() == p.getX()) && (getY() == p.getY());
    }

};

Point roundMe (const Point &p) {
    Point nowy(floor(p.getX()), floor(p.getY()));
    return nowy;
}

Point operator*(Point v, float f) {
    v *= f;
    return v;
}

Point operator+(Point v1, const Point &v2) {
    v1 += v2;
    return v1;
}

class Ant {

    Point p;
    unsigned short kierunek;
    ALLEGRO_BITMAP* bitmapa;

public:

    Ant(): Ant(0.0, 0.0) {}

    Ant(double _x, double _y) {
        p.setX(_x);
        p.setY(_y);
        kierunek = north;
        bitmapa = al_load_bitmap("mrowka.png");
    }

    Ant(Point _p) {
        p.setX(_p.getX());
        p.setY(_p.getY());
        kierunek = north;
        bitmapa = al_load_bitmap("mrowka.png");
    }

    Point getPosition() const {
        return p;
    }

    ALLEGRO_BITMAP* getBitmap() const { return bitmapa; }

    unsigned short getDirection() const {
        return kierunek;
    }

    void lewo() {
        switch(kierunek) {
            case north:
                p.setX(p.getX() - 1);
                kierunek = west;
                break;
            case east:
                p.setY(p.getY() - 1);
                kierunek = north;
                break;
            case south:
                p.setX(p.getX() + 1);
                kierunek = east;
                break;
            case west:
                p.setY(p.getY() + 1);
                kierunek = south;
                break;
        }
    }

    void prawo() {
        switch(kierunek) {
            case 1:
                p.setX(p.getX() + 1);
                kierunek = east;
                break;
            case 2:
                p.setY(p.getY() + 1);
                kierunek = south;
                break;
            case 3:
                p.setX(p.getX() - 1);
                kierunek = west;
                break;
            case 4:
                p.setY(p.getY() - 1);
                kierunek = north;
                break;
        }
    }

    bool operator==(const Ant &a) const
    {
        return ((p.getX() == a.p.getX()) && (p.getY() == a.p.getY()));
    }
};

set<Point> czarne;
vector<Ant> mrowki;

void ruch(set<Point> &czarne, vector<Ant> &mrowki) {

    bool czyCzarne;
    Point pozycja;

    for (unsigned int i = 0; i < mrowki.size(); ++i) {

        czyCzarne = false;
        pozycja = mrowki[i].getPosition();

        czyCzarne = czarne.find(pozycja) != czarne.end();

        if (czyCzarne) {
            mrowki[i].prawo();
            czarne.erase(pozycja);
        }
        else {
            mrowki[i].lewo();
            czarne.insert(pozycja);
        }

    }
}

void rysujPole (const Point &lg, const Point &p, float rozmiar) {

    al_draw_filled_rectangle(rozmiar * (p.getX() - lg.getX()), rozmiar * (p.getY()  - lg.getY()), rozmiar * (p.getX()  - lg.getX()) + rozmiar, rozmiar * (p.getY() - lg.getY()) + rozmiar ,al_map_rgb(0,0,0));

}

void rysujMrowke (const Point &lg, const Ant &a, float rozmiar) {

    al_draw_scaled_rotated_bitmap(a.getBitmap(),40, 40, rozmiar * (a.getPosition().getX() - lg.getX()) + rozmiar / 2, rozmiar * (a.getPosition().getY()  - lg.getY()) + rozmiar / 2,  rozmiar / 80, rozmiar / 80, (M_PI * (a.getDirection() - 1)) / 2, 0);

}

Point lg(const set<Point> &czarne, const vector<Ant> &mrowki) {

    int x_min = 0;
    int y_min = 0;

    for (Point p: czarne) {
        if (p.getX() < x_min)
            x_min = p.getX();
        if (p.getY() < y_min)
            y_min = p.getY();

    }
    for (Ant a: mrowki) {
        if (a.getPosition().getX() < x_min)
            x_min = a.getPosition().getX();
        if (a.getPosition().getY() < y_min)
            y_min = a.getPosition().getY();
    }

    Point p(x_min, y_min);

    return p;
}

Point pg (const set<Point> &czarne, const vector<Ant> &mrowki) {

    int x_max = 0;
    int y_max = 0;

    for (Point p: czarne) {

        if (p.getX() > x_max)
            x_max = p.getX();
        if (p.getY() > y_max)
            y_max = p.getY();
    }
    for (Ant a: mrowki) {

        if (a.getPosition().getX() > x_max)
            x_max = a.getPosition().getX();
        if (a.getPosition().getY() > y_max)
            y_max = a.getPosition().getY();
    }

    Point p(x_max, y_max);

    return p;

}

float rozmiar (const set<Point> &czarne, const vector<Ant> &mrowki) {

    Point lewyGorny = lg(czarne, mrowki);
    Point prawyGorny = pg(czarne, mrowki);

    int x_min = lewyGorny.getX();
    int y_min = lewyGorny.getY();
    int x_max = prawyGorny.getX();
    int y_max = prawyGorny.getY();

    float roz = 30.0;

    if ((screen_w - 170) / (x_max - x_min + 1) < roz) {
        roz = (float) (screen_w - 170) / (x_max - x_min + 1);
    }
    if ((screen_h - 20)/ (y_max - y_min + 1) < roz) {
        roz = (float) (screen_h - 20) / (y_max - y_min + 1);
    }

    return roz;

}

void rysuj (set<Point> &czarne, const vector<Ant> &mrowki) {

    Point lewyGorny = lg(czarne, mrowki);

    float roz = rozmiar(czarne, mrowki);

    for(Point p: czarne) {
        rysujPole(lewyGorny, p, roz);
    }

    for(Ant a: mrowki) {
        rysujMrowke(lewyGorny, a, roz);
    }
}

int main(int, char**) {

    bool czyRuch = false;
    float FPS = 10.0;
    int it = 0;

    al_init();
    al_init_primitives_addon();
    al_install_mouse();
    al_install_keyboard();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();

    ALLEGRO_FONT *title = al_load_font("arial.ttf", 20, 0);
    ALLEGRO_FONT *body = al_load_font("arial.ttf", 12, 0);
    ALLEGRO_FONT *counter = al_load_font("arial.ttf", 20, 0);
    ALLEGRO_FONT *element = al_load_font("arial.ttf", 10, 0);
    ALLEGRO_FONT *title2 = al_load_font("arial.ttf", 48, 0);

    ALLEGRO_DISPLAY *display = al_create_display(screen_w, screen_h);
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    ALLEGRO_EVENT ev;
    ALLEGRO_TIMER *timer = al_create_timer(1 / FPS);
    ALLEGRO_BITMAP* bitmap;

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_mouse_event_source());
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    al_start_timer(timer);

    Start:

    while (true) {

        al_clear_to_color(al_map_rgb(44, 34, 85));
        bitmap = al_load_bitmap("ant.png");
        al_draw_bitmap(bitmap, screen_w / 2 - 150, 10, 0);

        al_draw_rectangle(screen_w / 2 - 200, 270, screen_w / 2 + 200, 400, al_map_rgb(255, 255, 255), 5);
        al_draw_text(title2, al_map_rgb(255, 255, 255), screen_w / 2 , 310, ALLEGRO_ALIGN_CENTRE, "Mrówka Langtona");

        al_draw_filled_rounded_rectangle(screen_w / 2 - 75, 420, screen_w / 2 + 75, 490, 20, 20, al_map_rgb(0, 0, 0));
        al_draw_text(counter, al_map_rgb(255, 255, 255), screen_w / 2 , 445, ALLEGRO_ALIGN_CENTRE, "SYMULACJA");

        al_draw_filled_rounded_rectangle(screen_w / 2 - 75, 510, screen_w / 2 + 75, 580, 20, 20, al_map_rgb(0, 0, 0));
        al_draw_text(counter, al_map_rgb(255, 255, 255), screen_w / 2 , 535, ALLEGRO_ALIGN_CENTRE, "WYJŚCIE");

        al_flip_display();

        al_wait_for_event(event_queue, &ev);

        if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            if ((ev.mouse.x > screen_w / 2 - 75) && (ev.mouse.x < screen_w / 2 + 75) && (ev.mouse.y > 420) && (ev.mouse.y < 490))
                break;
            else if ((ev.mouse.x > screen_w / 2 - 75) && (ev.mouse.x < screen_w / 2 + 75) && (ev.mouse.y > 510) && (ev.mouse.y < 580)) {
                goto Koniec;
            }
        }
        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            goto Koniec;
    }

    while (true) {

        al_clear_to_color(al_map_rgb(255,255,255));
        al_draw_filled_rectangle(screen_w - 150, 0, screen_w, screen_h, al_map_rgb(44, 34, 85));

        al_draw_text(body, al_map_rgb(255, 255, 255), screen_w - 75, 30, ALLEGRO_ALIGN_CENTRE, "LICZBA ITERACJI:");
        al_draw_textf(counter, al_map_rgb(255, 255, 255), screen_w - 75, 45, ALLEGRO_ALIGN_CENTRE, "%.0f iteracji", (float)it);

        al_draw_text(body, al_map_rgb(255, 255, 255), screen_w - 75, 95, ALLEGRO_ALIGN_CENTRE, "LICZBA FPS:");
        al_draw_textf(counter, al_map_rgb(255, 255, 255), screen_w - 75, 110, ALLEGRO_ALIGN_CENTRE, "%.0f klatek/sek", FPS);

        al_draw_text(title, al_map_rgb(255, 255, 255), screen_w - 75, screen_h / 2, ALLEGRO_ALIGN_CENTRE, "STEROWANIE:");

        al_draw_text(element, al_map_rgb(255, 255, 255), screen_w - 75, screen_h / 2 + 40, ALLEGRO_ALIGN_CENTRE, "Spacja = zatrzymaj symulację");
        al_draw_text(element, al_map_rgb(255, 255, 255), screen_w - 75, screen_h / 2 + 55, ALLEGRO_ALIGN_CENTRE, "Lewo = FPS - 1");
        al_draw_text(element, al_map_rgb(255, 255, 255), screen_w - 75, screen_h / 2 + 70, ALLEGRO_ALIGN_CENTRE, "Prawo = FPS + 1");
        al_draw_text(element, al_map_rgb(255, 255, 255), screen_w - 75, screen_h / 2 + 85, ALLEGRO_ALIGN_CENTRE, "Góra = FPS + 5");
        al_draw_text(element, al_map_rgb(255, 255, 255), screen_w - 75, screen_h / 2 + 100, ALLEGRO_ALIGN_CENTRE, "Dół = FPS - 5");

        al_draw_text(element, al_map_rgb(255, 255, 255), screen_w - 75, screen_h / 2 + 140, ALLEGRO_ALIGN_CENTRE, "PPM = Dodaj/usuń mrówkę");
        al_draw_text(element, al_map_rgb(255, 255, 255), screen_w - 75, screen_h / 2 + 155, ALLEGRO_ALIGN_CENTRE, "LPM = Dodaj/usuń pole");

        al_draw_text(element, al_map_rgb(255, 255, 255), screen_w - 75, screen_h / 2 + 180, ALLEGRO_ALIGN_CENTRE, "ENTER = Wyczyść planszę");
        al_draw_text(element, al_map_rgb(255, 255, 255), screen_w - 75, screen_h / 2 + 210, ALLEGRO_ALIGN_CENTRE, "ESC = Powrót do menu");

        rysuj(czarne, mrowki);

        Point lewyGorny = lg(czarne, mrowki);
        float roz = rozmiar(czarne, mrowki);

        al_flip_display();

        al_wait_for_event(event_queue, &ev);

        if (ev.type == ALLEGRO_EVENT_TIMER && czyRuch){
            ruch(czarne, mrowki);
            it++;
        }

        else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && ev.mouse.x < screen_w - 150) {

            Point klik(ev.mouse.x, ev.mouse.y);
            Point zaokr = roundMe((klik * (1/roz) + lewyGorny));

            ALLEGRO_MOUSE_STATE state;
            al_get_mouse_state(&state);

            if (state.buttons & 1) {
                if(czarne.find(zaokr) != czarne.end())
                    czarne.erase(zaokr);
                else
                    czarne.insert(zaokr);

            }
            if (state.buttons & 2) {
                bool czyJest = false;
                for (unsigned int i = 0; i < mrowki.size(); ++i){
                    if (zaokr == mrowki[i].getPosition()){
                        czyJest = true;
                        mrowki.erase(mrowki.begin() + i);
                        break;
                    }
                }
                if (!czyJest)
                    mrowki.push_back(zaokr);
            }
        }

        else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {

            switch (ev.keyboard.keycode) {
                case ALLEGRO_KEY_SPACE:
                    czyRuch = !czyRuch;
                    break;
                case ALLEGRO_KEY_LEFT:
                    if(FPS > 1.0){
                        FPS -= 1.0;
                        al_set_timer_speed(timer, 1 / FPS);
                    }
                    else
                        FPS = 1.0;
                    break;
                case ALLEGRO_KEY_RIGHT:
                    if(FPS < 60.0){
                        FPS += 1.0;
                        al_set_timer_speed(timer, 1 / FPS);
                    }
                    else
                        FPS = 60.0;
                    break;
                case ALLEGRO_KEY_DOWN:
                    if(FPS > 5.0){
                        FPS -= 5.0;
                        al_set_timer_speed(timer, 1 / FPS);
                    }
                    else
                        FPS = 1.0;
                    break;
                case ALLEGRO_KEY_UP:
                    if(FPS < 55.0){
                        FPS += 5.0;
                        al_set_timer_speed(timer, 1 / FPS);
                    }
                    else
                        FPS = 60;
                    break;
                case ALLEGRO_KEY_ESCAPE:
                    goto Start;
                    break;
                case ALLEGRO_KEY_ENTER:
                    czyRuch = false;
                    czarne.clear();
                    mrowki.clear();
                    it = 0;

            }
        }
        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            break;

    }

    Koniec:

    al_destroy_timer(timer);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

}
