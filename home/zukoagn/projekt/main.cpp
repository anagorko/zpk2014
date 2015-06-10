#include<iostream>
#include<vector>// klasa ze standrdowego jezyka c++; podobna do tablicy, ale dzialja jak kolejki i stosy
#include<math.h>
#include <iomanip>
using namespace std;

#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h> //do wyswietlania okna z wiadomoscia

const int screen_w = 800; // szerokosc okna
const int screen_h = 600; // wysokosc okna
const int exit_screen_w = 350;
const int exit_screen_h = 250;
const float FPS = 60.0;

class Vect
{
    float x, y;

public:
    Vect() : Vect(0.0, 0.0) {
    }
    Vect(float _x, float _y) {
        setX(_x);
        setY(_y);
    }

    float distanceTo(Vect p)
    {
        float dx = x - p.x;
        float dy = y - p.y;

        return sqrt(dx*dx + dy*dy); //odleglosc
    }

    float getX() const { return x; } //wez wspolrzedna x
    float getY() const { return y; } //wez wspolrzedna y

    void setX(float _x) { x = _x; } // ustaw wspolrzedna x
    void setY(float _y) { y = _y; }// ustaw wspolrzedna y

    Vect& operator*=(float f) {
        x *= f; y *= f; return *this;
    }

    Vect& operator+=(Vect v) {
        x += v.x; y += v.y; return *this;
    }
};

Vect operator*(Vect v, float f)
{
    v *= f;
    return v;
}
Vect operator+(Vect v1, Vect v2)
{
    v1 += v2;
    return v1;
}


//Klasa odpowiadajaca za poruszanie obiektu
class Moving
{
protected:
    ALLEGRO_BITMAP* bitmap; //bitmapa

    Vect p, v; //p-polozenie, v - predkosc

public:
    Moving()//kontruktor
    {

    }
// seria metod
    Vect getPosition() const { return p; }
    void setPosition(const Vect _p) { p = _p; }

    Vect getVelocity() const { return v; } //wez predkosc
    void setVelocity(Vect _v) { v = _v; } // ustaw predkosc

    virtual void move(float time) {//move - wykonuje te nasza fizyke
        Vect p = getPosition();// wez pozycje punktu p
        p += getVelocity() * time; // p powieksz o iloraz szybkosci i czasu; zwykly ruch jednostajny
        setPosition(p);// ustaw pozycje p
    }

    bool collidesWith(Moving* f) const
    //traktujemy obiekty jako kola o srednicach;
    //kolizja, gdy srednice dwóch obiektów naloza sie na siebie;
    {
        return getPosition().distanceTo(f -> getPosition()) <
                (diameter() + f -> diameter()) / 2; //diameter = srednica
    }
//virtual - dotyczy polimorfizmu
    virtual float diameter() const { return 0; } //const - dzieki temu nie modyfikujemy obiektów
    virtual ALLEGRO_BITMAP* getBitmap() const { return bitmap; }
};


// klasa odpowiedzialna za strzelanie przez czolg
class Shooting
{

};

//klasa odpowiedzialna za kontrolowanie czolgu
class Controlled : public Moving
{
    bool left;
    bool right;

public:
    Controlled()
    {
        left = false; right = false;
    }

    void goLeft(bool l) { left = l; }
    void goRight(bool r) { right = r; }

};

//klasa czolg
class Tank : public Controlled/*, public Shooting*/{

    public:
    Tank()
    {
        bitmap = al_load_bitmap("tank_turret.png");
    }

    virtual float diameter() const { return 64; }// obiekt o srednicy 64
};

//klasa space invader
class SpaceInvader : public Moving
{

    public:
    SpaceInvader()
    {
    }
    virtual float diameter() const { return 40; }// obiekt o srednicy 40
};

class SpaceInvader01 : public SpaceInvader{
    public:
        SpaceInvader01()
        {
            bitmap = al_load_bitmap("SpaceInvader01a.png");
        }
};

class SpaceInvader02 : public SpaceInvader{
    public:
        SpaceInvader02()
        {
            bitmap = al_load_bitmap("SpaceInvader02.png");
        }
};

class SpaceInvader03 : public SpaceInvader{
    public:
        SpaceInvader03()
        {
            bitmap = al_load_bitmap("SpaceInvader03.png");
        }
};


//klasa pocisk
class Missile : public Moving
{
    public:
    Missile()
    {
       bitmap = al_load_bitmap("missile.png");
    }

    virtual float diameter() const { return 4; }// obiekt o srednicy 4
};

//klasa okop
class Shield : public Moving
{
    public:
    Shield()
    {
       bitmap = al_load_bitmap("fortress.png");
    }

    virtual float diameter() const { return 80; }// obiekt o srednicy 80
};

//klasa eksplozja
class Explosion
{
    public:
    Explosion()
    {
        //bitmap = al_load_bitmap("explosion.png");
    }
};

//klasa zycie
class Life : public Moving
{

    public:
        Life()
        {
            bitmap = al_load_bitmap("heart.png");
        }

};

vector<Moving*> objects; //tablica wszystkich obiektow gry; ale nie chcemy z gory specyfikowac ile chcemy obiektow; zawiera wskazniki do obiektow

vector<Moving*> objects2; //tablica pozostalych obiektow planszy, np. zycie

// utworzenie poczatkowego ukladu najezdzcow
void create_space_invader()
{
    int odleglosc, wysokosc;

   wysokosc = 0;

   for(int i=1; i<=5; i++)
    {
        odleglosc = 0;
        for(int j=1; j<=11; j++)
        {
            if (i==1)
            {SpaceInvader02 *s = new SpaceInvader02();
            s -> setPosition(Vect(odleglosc + screen_w / 5, wysokosc + (screen_h / 5)));
            s -> setVelocity(Vect(0, 0));
            objects.push_back(s);// doklada nowy element do naszej tablicy
            }
            else if (i==2 || i== 3){
            SpaceInvader01 *s = new SpaceInvader01();
            s -> setPosition(Vect(odleglosc + screen_w / 5, wysokosc + (screen_h / 5)));
            s -> setVelocity(Vect(0, 0));
            objects.push_back(s);}// doklada nowy element do naszej tablicy}
            else if (i==4 || i== 5){
            SpaceInvader03 *s = new SpaceInvader03();
            s -> setPosition(Vect(odleglosc + screen_w / 5, wysokosc + (screen_h / 5)));
            s -> setVelocity(Vect(0, 0));
            objects.push_back(s);}// doklada nowy element do naszej tablicy}


            odleglosc = odleglosc + 50;
        }
        wysokosc = wysokosc + 50;
    }

   }

void create_shield()// utworzenie okopow
{
    int odleglosc_s;
    odleglosc_s = 0;
    for(int i=1; i < 5; i++)
    {

        Shield *sh = new Shield();

        sh -> setPosition(Vect(odleglosc_s + (screen_w / 5), 3 * screen_h / 4));
        sh -> setVelocity(Vect(0, 0));

        objects.push_back(sh);// doklada nowy element do naszej tablicy
       odleglosc_s = odleglosc_s + 160;
    }

}

void create_life() // utworzenie zycia
{
    int odl=0;
    for(int i=1; i<4; i++)
    {
        Life *l = new Life();
        l -> setPosition(Vect(700+odl, 20));
        l -> setVelocity(Vect(0, 0));
        objects2.push_back(l);
        odl=odl+30;
    }

}


int main(int, char**)
{

    //inicjalizacja biblioteki; obslugi klawiatury oraz warunku wyswietlania
    if (!al_init() || !al_install_keyboard() || !al_init_image_addon()) {
        cout << "Blad inicjalizacji." << endl;
        return 1;
    }

    ALLEGRO_DISPLAY *display = al_create_display(screen_w, screen_h);// stworzenie naszej planszy
    ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS); //stworzenie timera
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();//stworzenie kolejki zdarzen

    //gdy nie stworzy któregos z powyzszych
    if (display == NULL || timer == NULL || event_queue == NULL) {
        cout << "Blad inicjalizacji." << endl;
        return 2;
    }

    al_register_event_source(event_queue, al_get_display_event_source(display));//ladujemy do naszej kolejki zdarzen poszczegolne zrodla zdarzenia
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_clear_to_color(al_map_rgb(0,0,0));
    al_flip_display();

    al_start_timer(timer);

    //pokazywanie zycia
    create_life();

    //tworzenie oslon

    create_shield();

     //tworzenie statku

    Tank *t = new Tank();
    t -> setPosition(Vect(screen_w / 5, 9 * screen_h / 10));
    t -> setVelocity(Vect(0, 0));

    objects.push_back(t);

    //tworzenie ukladu poczatkowego

    create_space_invader();

    //Rysowanie obiektow

    al_clear_to_color(al_map_rgb(0,0,0));

        for (Moving* o: objects2) {
            al_draw_rotated_bitmap(o -> getBitmap(),
                                   al_get_bitmap_width(o -> getBitmap()) / 2,
                                   al_get_bitmap_height(o -> getBitmap()) / 2,
                                   o -> getPosition().getX(),
                                   o -> getPosition().getY(),
                                   0,
                                   0);

        }
        for (Moving* f: objects) {
            al_draw_rotated_bitmap(f -> getBitmap(),
                                   al_get_bitmap_width(f -> getBitmap()) / 2,
                                   al_get_bitmap_height(f -> getBitmap()) / 2,
                                   f -> getPosition().getX(),
                                   f -> getPosition().getY(),
                                   0,
                                   0);

        }
        al_flip_display();



/*
ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_BITMAP *bitmap=NULL;
if (!al_init()||!al_init_image_addon()) {
        cout << "B³¹d inicjalizacji." << endl;
        return 1;
    }

display = al_create_display(800, 600);

bitmap=al_load_bitmap("poczatek.bmp");

al_draw_bitmap(bitmap, 0, 0, 0);
*/

al_rest(10.0);

/*
al_destroy_bitmap(bitmap);
al_destroy_display(display);*/

return 0;
}

