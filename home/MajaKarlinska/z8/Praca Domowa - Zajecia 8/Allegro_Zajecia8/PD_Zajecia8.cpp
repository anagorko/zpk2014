#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>

const int screen_w = 800;
const int screen_h = 600;
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

        return sqrt(dx*dx + dy*dy);
    }

    float getX() const { return x; }
    float getY() const { return y; }

    void setX(float _x) { x = _x; }
    void setY(float _y) { y = _y; }

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

class Flying
{
protected: //do tych zmiennych moga siê odwolywac klasy dziedziczace z niej
    ALLEGRO_BITMAP* bitmap; //rysunek, tutaj jest to asteroid, statek

    Vect p, v; //p - pozycja w jakiej jestesmy - wspolrzedne srodka obiektu, v - predkosc (w pikselach na sek)
    float a, r; //a - to pod jakim k¹tem jest coœ ustawione  , r - prêdkoœæ k¹towa, z jak¹ obiekt siê obraca

public:
    Flying()
    {
        bitmap = al_load_bitmap("asteroid.png");
    }

    Vect getPosition() const { return p; }
    void setPosition(const Vect _p) { p = _p; }

    Vect getVelocity() const { return v; }
    void setVelocity(Vect _v) { v = _v; }

    float getRotation() const { return r; }
    void setRotation(float _r) { r = _r; }

    float getAngle() const { return a; }
    void setAngle(float _a) { a = _a; }

    virtual void move(float time) { //metoda ktora jako parametr podaje czas
        Vect p = getPosition(); //przypisujemy p miejsce w ktorym cos jest obecnie, tworzymy kopiê
        p += getVelocity() * time; // do p dodajemy czas*prêdkosc = drogê, przesuwamy sie w czasie t, o v*t
        if (p.getX() > screen_w) { p.setX(p.getX() - screen_w); } //jesli dojdziemy do brzegu, to pojawiamy sie na
        //przecilweglym brzegu, jesli dojdziemy do prawej strony, to pojawiamy sie po lewej stronie
        if (p.getY() > screen_h) { p.setY(p.getY() - screen_h); } //jesli pojawiamy sie na dole, to pozniej przechodzimy
        //do gory
        if (p.getX() < 0) { p.setX(p.getX() + screen_w); }
        if (p.getY() < 0) { p.setY(p.getY() + screen_h); }
        setPosition(p);

        float a = getAngle();
        a += getRotation() * time; //dodajemy to ile obrocil siê nasz obiekt
        setAngle(a);
    }

    bool collidesWith(Flying* f) const
    {
        return getPosition().distanceTo(f -> getPosition()) < (diameter() + f -> diameter()) / 2;
                //zwraca prawde jesli sie obiekty zderza, falsz jesli nie
                //mamy srodki obiektow i ich srednice (diamater)
                //jesli odleglosc miedzy srodkami jest mniejsza niz suma promieni
                //tzn ze sie ze soba zderzaja
    }

    virtual float diameter() const { return 0; }
    virtual ALLEGRO_BITMAP* getBitmap() const { return bitmap; } //metoda zwracajaca bitmape
};

class Controlled : public Flying
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

class Spaceship : public Controlled
{
public:
    Spaceship()
    {
        bitmap = al_load_bitmap("spaceship.png");
    }

    virtual float diameter() const { return 48; }//srednica spaaceship to 48
};

class Asteroid : public Flying
{
public:
    Asteroid()
    {
        bitmap = al_load_bitmap("asteroid.png");
    }

    virtual float diameter() const { return 64; }
};

vector<Flying*> objects;

void create_asteroid()
{
    Asteroid *a = new Asteroid();

    do {
        a -> setPosition(Vect(rand() % screen_w, rand() % screen_h));
    } while (a -> getPosition().distanceTo(objects[0] -> getPosition()) < 200);
    //losuj pozycje tak dlugo jak odleglsc miedzy obiektem 0 - statkiem, a asteroida, bedzie wieksza niz 200

    //zmniejszamy liczbe, aby wylosowac pozycje poczatkowa
    //naszego asteroidy, ale musi byc mniejsza niz 800, bo taki rozmiar ekranu
    a -> setAngle(rand()); //rand - zwraca liczbe losowa
    a -> setRotation(((float) (rand() % 200) - 100) / 100.0);
    //predkosc, zmniejszamy ja, aby asteroidy krêci³y sie z mniejsza predkoscia
    a -> setVelocity(Vect((rand() % 60) - 30, (rand() % 60) - 30));
    //predkosc, zmniejszamy ja, aby asteroidy poruszaly sie z mniejsza predkoscia

    objects.push_back(a); //dodaje nowy element na koncu tablicy, dodajemy tam nasz statek kosmiczny

}

int main(int, char**)
{
    if (!al_init() || !al_install_keyboard() || !al_init_image_addon()) {
            //sprawdzamy czy zainstalowane sa biblioteki allegro, klawiatury, obslugujaca obrazy
        cout << "B³¹d inicjalizacji." << endl;
        return 1;
    }

    ALLEGRO_DISPLAY *display = al_create_display(screen_w, screen_h); //ustawienia okienka
    ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS); //ustawienie szybkosci zmiany, jest timer szybko ustawiony
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue(); //kolejka zdarzen, ktora podaje kolejne wydarzenia

    if (display == NULL || timer == NULL || event_queue == NULL) {
            //sprawdzanie czy nie zostal utoworzne okienko, timer, kolejka
        cout << "B³¹d inicjalizacji." << endl;
        return 2;
    }

    al_register_event_source(event_queue, al_get_display_event_source(display));
    //tworzymy zdarzenia
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_clear_to_color(al_map_rgb(0,0,0)); //ustalamy okienko na czarno
    al_flip_display(); //wyswietlenie

    al_start_timer(timer); //wystartkowanie timera

    Spaceship *s = new Spaceship(); //tworzymy obiekt z klasy speceship, tworzy zmienna s, wskaznik do obiektu spaceship
    s -> setPosition(Vect(screen_w / 2, screen_h / 2)); //ustawiamy polozenie na srodku ekranu
    s -> setAngle(0); //kat na zero
    s -> setRotation(0);
    s -> setVelocity(Vect(0, 0)); //wszystko ustawiamy na zero

    objects.push_back(s);

    for (int i = 0; i < 5; i++) {
        create_asteroid();
        //tworzymy 5 astereoidow
    }

    for (Flying* f: objects) {
        if (f -> getBitmap() == NULL) {
            cout << "Nie uda³o siê za³adowaæ bitmapy." << endl;
            return 3;
            //sprawdzamy czy udalo sie zaladowac wszystkie obrazki, dla wszystkich obiektow (st¹d for)
        }
    }

    float time = 0.0;

    while (true) //czekamy na zdarzenie
    {
        // process events
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);


        if(ev.type == ALLEGRO_EVENT_TIMER) { //jesli zdarzenie to to wynikajace z budzika
            // move objects
            for (Flying* f: objects) {
                f -> move(1.0 / FPS);
            }
            time = time + 1.0 / FPS;
            //to wszystko porusza sie o tyle ile powinni w jednym sek
            //do czasu dodajemy 1 sek

            if (time > 15.0) {
                create_asteroid(); time = 0.0;
                //po 15 s tworzymy kolejna asteroide
            }
        } else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break; //jesli ktos klika zakonczenie, to konczymy
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
        if (coll > 1) { break; }

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
//rysujemy 5 razy aby nie bylo przenoszenia takiego przeywanego tylko plynne,
        }
        al_flip_display();
    };

    cout << "Liczba przezytych sekund:" << time << endl;
    return 0;
}
