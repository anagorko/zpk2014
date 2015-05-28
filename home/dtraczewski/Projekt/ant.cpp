#include <iomanip>
#include <iostream>
#include <vector>
#include <set>
#include <math.h>

using namespace std;

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

const int screen_w = 800;
const int screen_h = 600;

const float FPS = 60.0;

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
};

Point operator*(Point v, float f) {
    v *= f;
    return v;
}

Point operator+(Point v1, Point v2) {
    v1 += v2;
    return v1;
}

class Ant: public Point {

    /*ALLEGRO_BITMAP* bitmap; */

    Point p;
    float a;

public:

    Ant(): Ant(0.0, 0.0) {}

    Ant(double _x, double _y) {
        p.setX(_x);
        p.setY(_y);
    }

    Ant(Point _p) {
        setPosition(_p);
    }

    Point getPosition() const {
        return p;
    }
    void setPosition (Point _p) {
        p.setX(_p.getX());
        p.setY(_p.getY());
    }

    float getAngle() const;
    void setAngle(float _a);

    void move(double dx, double dy);

    bool collidesWith(Ant _ant) const;
};

vector<Point> czarne;
vector<Ant> mrowki;

void rysuj_pole (Point p, float rozmiar) {
    al_draw_filled_rectangle(p.getX(), p.getY(), p.getX() + rozmiar , p.getY() + rozmiar ,al_map_rgb(0,0,0));
};
void rysuj_ant (Ant a, float rozmiar) {
    al_draw_ellipse(a.getPosition().getX(), a.getPosition().getY() , rozmiar / 4, rozmiar / 5, al_map_rgb(0,0,0), 5);
    al_draw_ellipse(a.getPosition().getX() + rozmiar / 2, a.getPosition().getY() , rozmiar / 4, rozmiar / 5, al_map_rgb(0,0,0), 5);
};

void rysuj (vector<Point> czarne, vector<Ant> mrowki, float rozmiar) {

    int x_min = czarne.front().getX();
    int y_min = czarne.front().getY();

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

    ALLEGRO_DISPLAY *display = al_create_display(screen_w, screen_h);
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

    al_register_event_source(event_queue, al_get_display_event_source(display));

    ALLEGRO_EVENT ev;

    al_clear_to_color(al_map_rgb(255,255,255));

    for(Point p: czarne) {
        rysuj_pole(p, rozmiar);
    }
    for(Ant a: mrowki) {
        rysuj_ant(a, rozmiar);
    }

    al_flip_display();

    al_wait_for_event(event_queue, &ev);
    al_destroy_display(display);
};

int main() {
    al_init();
    al_init_primitives_addon();

    Ant mrowka = Ant(200, 200);
    mrowki.push_back(mrowka);

    Point czarny = Point (200, 200);
    czarne.push_back(czarny);

    rysuj(czarne, mrowki, 20);

}

