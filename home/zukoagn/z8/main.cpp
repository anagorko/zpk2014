/*zajecia 30.04.2015 - galactic_mail*/
//praca domowa: wyswietlic napis "game over" plus ile minie sekund

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
const float FPS = 60.0; //

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
    void setY(float _y) { y = _y; }// ustwa wspolrzedna y

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
//Klasa odpowiadajaca za latanie obiektu
class Flying
{
protected:
    ALLEGRO_BITMAP* bitmap; //bitmapa

    Vect p, v; //p-polozenie, v - predkosc
    float a, r; //a - kat alfa; r - predkosc obrotowa

public:
    Flying()//kontruktor
    {
        bitmap = al_load_bitmap("asteroid.png"); // laduje asteroide
    }
// seria metod
    Vect getPosition() const { return p; }
    void setPosition(const Vect _p) { p = _p; }

    Vect getVelocity() const { return v; } //wez predkosc
    void setVelocity(Vect _v) { v = _v; } // ustaw predkosc

    float getRotation() const { return r; } //predkosc obrotowa
    void setRotation(float _r) { r = _r; }//

    float getAngle() const { return a; } //kąt
    void setAngle(float _a) { a = _a; }

    virtual void move(float time) {//move - wykonuje te nasza fizyke
        Vect p = getPosition();// wez pozycje pnktu p
        p += getVelocity() * time; // p powieksz o iloraz szybkosci i czasu; zwykly ruch jednostajny
        if (p.getX() > screen_w) { p.setX(p.getX() - screen_w); }// jezeli wspolrzedna x jest wieksza od szerokosci to ustaw x; pojawia sie po drugiej stronie planszy
        if (p.getY() > screen_h) { p.setY(p.getY() - screen_h); }// to samo tylko z wysokoscia okna i y
        if (p.getX() < 0) { p.setX(p.getX() + screen_w); }// jezeli ujemny to
        if (p.getY() < 0) { p.setY(p.getY() + screen_h); }// jezeli ujemny to
        setPosition(p);// ustaw pozycje p

        float a = getAngle();
        a += getRotation() * time; //powieksz kat o iloraz roatcji i czasu
        setAngle(a);
    }

    bool collidesWith(Flying* f) const
    //traktujemy obiektu jako koła o średnicach;
    //kolizja z asteroidą; gdy średnice dwóch obiektów nałożą się na siebie;
    {
        return getPosition().distanceTo(f -> getPosition()) <
                (diameter() + f -> diameter()) / 2; //diameter = srednica
    }
//virtual - dotyczy polimorfizmu
    virtual float diameter() const { return 0; } //const - dzięki temu nie modyfikujemy obiektów
    virtual ALLEGRO_BITMAP* getBitmap() const { return bitmap; }
};

class Controlled : public Flying //klasa odpowiedzialna za kontrolowanie latania statku
{
    bool left;
    bool right;
    bool forw;

public:
    Controlled()
    {
        left = false; right = false; forw = false;
    }

    void turnLeft(bool l) { left = l; }
    void turnRight(bool r) { right = r; }
    void forward(bool f) { forw = f; }

    virtual void move(float time) {
        if (left) {
            setRotation(getRotation() - 0.1);
        }
        if (right) {
            setRotation(getRotation() + 0.1);
        }
        if (forw) {
            setVelocity(getVelocity() + Vect(cos(getAngle()), sin(getAngle())));
        }
        Flying::move(time);
    }
};

class Spaceship : public Controlled //klasa odpowiedzialna za statek; dziedziczy z klasy controlled
{
public:
    Spaceship()
    {
        bitmap = al_load_bitmap("spaceship.png");
    }

    virtual float diameter() const { return 48; }// obiekt o srednicy 48
};

class Asteroid : public Flying
{
public:
    Asteroid()
    {
        bitmap = al_load_bitmap("asteroid.png");
    }

    virtual float diameter() const { return 64; }// obiekt o srednicy 64
};

vector<Flying*> objects; //tablica wszystkich obiektow; ale nie chcemy z gory specyfikowac ile chcemy obiektow
//zawiera wskazniki do obiektow

void create_asteroid()// utworzenie asteroidy
{
    Asteroid *a = new Asteroid();
//petla by nie wylosowac asteroidy na statku
    do {
        a -> setPosition(Vect(rand() % screen_w, rand() % screen_h)); //losujemy pozycje asteroidy
    } while (a -> getPosition().distanceTo(objects[0] -> getPosition()) < 200);//wez pozycje asteroidy; policz dystans od pozycji statku

    a -> setAngle(rand());
    a -> setRotation(((float) (rand() % 200) - 100) / 100.0); //losowanie predkosci obrotowej; [-1; 1]; kat w radianach
    a -> setVelocity(Vect((rand() % 60) - 30, (rand() % 60) - 30));

    objects.push_back(a);// doklada nowy element do naszej tablicy
}

int main(int, char**)
{
    //inicjalizacja biblioteki; obslugoi klawiatury oraz warunku wyświetlania
    if (!al_init() || !al_install_keyboard() || !al_init_image_addon()) {
        cout << "Błąd inicjalizacji." << endl;
        return 1;
    }

    ALLEGRO_DISPLAY *display = al_create_display(screen_w, screen_h);// stworzenie naszej planszy
    ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS); //stworzenie timera do tworzenia ateroidy
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();//stworzenie kolejki zdarzeń


//gdy nie stworzy któregoś z powyższych
    if (display == NULL || timer == NULL || event_queue == NULL) {
        cout << "Błąd inicjalizacji." << endl;
        return 2;
    }

    al_register_event_source(event_queue, al_get_display_event_source(display));//ładujemy do naszej kolejki zdarzen poszczegolne zrodla zdarzenia
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_clear_to_color(al_map_rgb(0,0,0));
    al_flip_display();

    al_start_timer(timer);

    //tworzenie statku

    Spaceship *s = new Spaceship();
    s -> setPosition(Vect(screen_w / 2, screen_h / 2));
    s -> setAngle(0);
    s -> setRotation(0);
    s -> setVelocity(Vect(0, 0));

    objects.push_back(s);

    for (int i = 0; i < 5; i++) {
        create_asteroid();
    }

    for (Flying* f: objects) { //nowy sposob petli; do klasy vector
        if (f -> getBitmap() == NULL) {
            cout << "Nie udało się załadować bitmapy." << endl;
            return 3;
        }
    }
    /* Można to też w ten sposób zapisać
    for (int i=0; i<objects.size(); i++)
        Flying *f = objects[i];*/

    float time = 0.0;
    float czas_gry = 0.0;


    while (true)
    {
        // process events
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);


        if(ev.type == ALLEGRO_EVENT_TIMER) {
            // move objects
            for (Flying* f: objects) {
                f -> move(1.0 / FPS);
            }
            time = time + 1.0 / FPS;
            czas_gry = czas_gry + 1.0 / FPS;

            if (time > 15.0) {
                create_asteroid(); time = 0.0;
            }
        } else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        } else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
             switch(ev.keyboard.keycode) {
                 case ALLEGRO_KEY_UP:
                    static_cast<Controlled*>(objects[0]) -> forward(true);
                    break;
                 case ALLEGRO_KEY_LEFT:
                    static_cast<Controlled*>(objects[0]) -> turnLeft(true);
                    break;
                 case ALLEGRO_KEY_RIGHT:
                    static_cast<Controlled*>(objects[0]) -> turnRight(true);
                    break;
            }
        } else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
             switch(ev.keyboard.keycode) {
                 case ALLEGRO_KEY_UP:
                    static_cast<Controlled*>(objects[0]) -> forward(false);
                    break;
                 case ALLEGRO_KEY_LEFT:
                    static_cast<Controlled*>(objects[0]) -> turnLeft(false);
                    break;
                 case ALLEGRO_KEY_RIGHT:
                    static_cast<Controlled*>(objects[0]) -> turnRight(false);
                    break;
                }
        }

        // detect collsion

        int coll = 0;
        for (Flying *f: objects)
        {
            if (f -> collidesWith(objects[0])) {
                coll++;
            }
        }
        if (coll > 1) { break;}

        // draw objects
        al_clear_to_color(al_map_rgb(0,0,0));
        for (Flying* f: objects) {
            al_draw_rotated_bitmap(f -> getBitmap(),
                                   al_get_bitmap_width(f -> getBitmap()) / 2,
                                   al_get_bitmap_height(f -> getBitmap()) / 2,
                                   f -> getPosition().getX(),
                                   f -> getPosition().getY(),
                                   f -> getAngle(),
                                   0);

            al_draw_rotated_bitmap(f -> getBitmap(),
                                   al_get_bitmap_width(f -> getBitmap()) / 2,
                                   al_get_bitmap_height(f -> getBitmap()) / 2,
                                   f -> getPosition().getX() + screen_w,
                                   f -> getPosition().getY(),
                                   f -> getAngle(),
                                   0);

            al_draw_rotated_bitmap(f -> getBitmap(),
                                   al_get_bitmap_width(f -> getBitmap()) / 2,
                                   al_get_bitmap_height(f -> getBitmap()) / 2,
                                   f -> getPosition().getX() - screen_w,
                                   f -> getPosition().getY(),
                                   f -> getAngle(),
                                   0);

            al_draw_rotated_bitmap(f -> getBitmap(),
                                   al_get_bitmap_width(f -> getBitmap()) / 2,
                                   al_get_bitmap_height(f -> getBitmap()) / 2,
                                   f -> getPosition().getX(),
                                   f -> getPosition().getY() + screen_h,
                                   f -> getAngle(),
                                   0);

            al_draw_rotated_bitmap(f -> getBitmap(),
                                   al_get_bitmap_width(f -> getBitmap()) / 2,
                                   al_get_bitmap_height(f -> getBitmap()) / 2,
                                   f -> getPosition().getX(),
                                   f -> getPosition().getY() - screen_h,
                                   f -> getAngle(),
                                   0);

        }
        al_flip_display();
    };

/*tworze okno z wiadomoscia "GAME OVER" */
al_show_native_message_box(
                display,
                NULL,
                "GAME OVER",
                NULL,
                NULL,
                NULL
    );

/*po wcisnieciu OK, w oknie dialogowym wyswietla sie komunikat o liczbie sekund spedzonych w przestrzeni kosmicznej*/
cout<<endl;
cout<<"Przetrwales w przestrzeni kosmicznej "<<setprecision(3)<< czas_gry <<" sekund(y)."<<endl;
cout<<endl;

    return 0;
}
