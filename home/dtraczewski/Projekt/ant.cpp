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

    bool operator<(const Point &a) const
    {
        return getX() < a.getX() || (getX() == a.getX() && getY() < a.getY());
    }

    bool operator==(const Point &a) const
    {
        return (getX() == a.getX()) && (getY() == a.getY());
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
    unsigned short kierunek;

public:

    Ant(): Ant(0.0, 0.0) {}

    Ant(double _x, double _y) {
        p.setX(_x);
        p.setY(_y);
        kierunek = 1;
    }

    Ant(Point _p) {
        p.setX(_p.getX());
        p.setY(_p.getY());
        kierunek = 1;
    }

    Point getPosition() {
        return p;
    }

    unsigned short getDirection() const {return kierunek;}

    float getAngle() const;
    void setAngle(float _a);

    void lewo() {
        switch(kierunek) {
            case 1:
                p.setX(p.getX() - 1);
                kierunek = 4;
                break;
            case 2:
                p.setY(p.getY() + 1);
                kierunek = 1;
                break;
            case 3:
                p.setX(p.getX() + 1);
                kierunek = 2;
                break;
            case 4:
                p.setY(p.getY() - 1);
                kierunek = 3;
                break;
        }
    }

    void prawo() {
        switch(kierunek) {
            case 1:
                p.setX(p.getX() + 1);
                kierunek = 2;
                break;
            case 2:
                p.setY(p.getY() - 1);
                kierunek = 3;
                break;
            case 3:
                p.setX(p.getX() - 1);
                kierunek = 4;
                break;
            case 4:
                p.setY(p.getY() + 1);
                kierunek = 1;
                break;
        }
    }
};

set<Point> czarne;
vector<Ant> mrowki;

void ruch(set<Point> &czarne, vector<Ant> &mrowki) {

    set<Point>::iterator it;
    bool czyCzarne;
    Point pozycja;

    for (int i = 0; i < mrowki.size(); ++i) {

        czyCzarne = false;
        pozycja = mrowki[i].getPosition();

        for (it = czarne.begin(); it != czarne.end(); ++it) {
            if(*it == pozycja) {
                czyCzarne = true;
                break;
            }
        }

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

void rysujPole (Point lg, Point p, float rozmiar) {
    al_draw_filled_rectangle(rozmiar * (p.getX() - lg.getX()), rozmiar * (p.getY()  - lg.getY()), rozmiar * (p.getX()  - lg.getX()) + rozmiar, rozmiar * (p.getY() - lg.getY()) + rozmiar ,al_map_rgb(0,0,0));
}
void rysujMrowke (Point lg, Ant a, float rozmiar) {
    switch (a.getDirection()){
        case 1:
            al_draw_ellipse(rozmiar * (a.getPosition().getX() - lg.getX()) + rozmiar / 2, rozmiar * (a.getPosition().getY()  - lg.getY()) + rozmiar / 2, rozmiar / 4, rozmiar / 2 - ((5 * rozmiar) / (40 * 2)), al_map_rgb(0,0,255), ((5 * rozmiar) / 40));
            break;
        case 2:
            al_draw_ellipse(rozmiar * (a.getPosition().getX() - lg.getX()) + rozmiar / 2, rozmiar * (a.getPosition().getY()  - lg.getY()) + rozmiar / 2, rozmiar / 2 - ((5 * rozmiar) / (40 * 2)), rozmiar / 4 , al_map_rgb(0,0,255), ((5 * rozmiar) / 40));
            break;
        case 3:
            al_draw_ellipse(rozmiar * (a.getPosition().getX() - lg.getX()) + rozmiar / 2, rozmiar * (a.getPosition().getY()  - lg.getY()) + rozmiar / 2, rozmiar / 4, rozmiar / 2 - ((5 * rozmiar) / (40 * 2)), al_map_rgb(0,0,255), ((5 * rozmiar) / 40));
            break;
        case 4:
            al_draw_ellipse(rozmiar * (a.getPosition().getX() - lg.getX()) + rozmiar / 2, rozmiar * (a.getPosition().getY()  - lg.getY()) + rozmiar / 2, rozmiar / 2 - ((5 * rozmiar) / (40 * 2)), rozmiar / 4 , al_map_rgb(0,0,255), ((5 * rozmiar) / 40));
            break;
    }
}

void rysuj (set<Point> czarne, vector<Ant> mrowki) {

    int x_min = 1000000000; //czarne.front().getX();
    int y_min = 1000000000; // czarne.front().getY();
    int x_max = -1000000000; //czarne.front().getX();
    int y_max = -1000000000; // czarne.front().getY();

    for (Point p: czarne) {
        if (p.getX() < x_min)
            x_min = p.getX();
        if (p.getY() < y_min)
            y_min = p.getY();
        if (p.getX() > x_max)
            x_max = p.getX();
        if (p.getY() > y_max)
            y_max = p.getY();
    }
    for (Ant a: mrowki) {
        if (a.getPosition().getX() < x_min)
            x_min = a.getPosition().getX();
        if (a.getPosition().getY() < y_min)
            y_min = a.getPosition().getY();
        if (a.getPosition().getX() > x_max)
            x_max = a.getPosition().getX();
        if (a.getPosition().getY() > y_max)
            y_max = a.getPosition().getY();
    }

    float rozmiar = 40.0;

    if (screen_w / (x_max - x_min + 1) < rozmiar) {
        rozmiar = (float) screen_w / (x_max - x_min + 1);
    }
    if (screen_h / (y_max - y_min + 1) < rozmiar) {
        rozmiar = (float) screen_h / (y_max - y_min + 1);
    }

    /*Point lg (0.0, 0.0);

    if (x_min < lg.getX())
        lg.setX(x_min);

    if (y_min < lg.getY())
        lg.setY(y_min);
    */

    for(Point p: czarne) {
        rysujPole(Point(x_min, y_min), p, rozmiar);
    }
    for(Ant a: mrowki) {
        rysujMrowke(Point(x_min, y_min), a, rozmiar);
    }
}

int main(int, char**) {
    al_init();
    al_init_primitives_addon();

    ALLEGRO_DISPLAY *display = al_create_display(screen_w, screen_h);
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

    al_register_event_source(event_queue, al_get_display_event_source(display));

    ALLEGRO_EVENT ev;
    ALLEGRO_TIMEOUT timeout;
    al_init_timeout(&timeout, 0.005f);

    al_clear_to_color(al_map_rgb(255,255,255));

    mrowki.push_back(Point(8,9));
    mrowki.push_back(Point(12,7));
    mrowki.push_back(Point(3,20));
    mrowki.push_back(Point(15,18));

    czarne.insert(Point(3,4));
    czarne.insert(Point(4,6));
    czarne.insert(Point(2,5));
    czarne.insert(Point(8,8));

    for (int i = 0 ; i < 10000; ++i) {

        al_clear_to_color(al_map_rgb(255,255,255));
        rysuj(czarne, mrowki);
        ruch(czarne, mrowki);

        al_flip_display();

        ALLEGRO_EVENT ev;
        ALLEGRO_TIMEOUT timeout;
        al_init_timeout(&timeout, 0.05f);
        bool get_event = al_wait_for_event_until(event_queue, &ev, &timeout);

        if(get_event && ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            break;

    }

    al_destroy_display(display);
}

