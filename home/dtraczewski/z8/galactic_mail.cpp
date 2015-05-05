#include <iomanip>
#include <iostream>
#include <vector>
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

const int exit_w = 400;
const int exit_h = 300;

class Vect
{
    float x, y;

public:

    Vect() : Vect(0.0, 0.0) {}

    Vect(float _x, float _y) {
        setX(_x);
        setY(_y);
    }

    float distanceTo(Vect p) {
        float dx = x - p.x;
        float dy = y - p.y;
        return sqrt(dx*dx + dy*dy);
    }

    float getX() const { return x; }
    float getY() const { return y; }

    void setX(float _x) { x = _x; }
    void setY(float _y) { y = _y; }

    Vect& operator*=(float f) {
        x *= f;
        y *= f;
        return *this;
    }

    Vect& operator+=(Vect v){
        x += v.x;
        y += v.y;
        return *this;
    }
};

Vect operator*(Vect v, float f) {
    v *= f;
    return v;
}

Vect operator+(Vect v1, Vect v2) {
    v1 += v2;
    return v1;
}

class Flying {
protected:

    ALLEGRO_BITMAP* bitmap;

    Vect p, v;
    float a, r;

public:

    Flying() {
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

    virtual void move(float time) {
        Vect p = getPosition();
        p += getVelocity() * time;
        if (p.getX() > screen_w)
            p.setX(p.getX() - screen_w);
        if (p.getY() > screen_h)
            p.setY(p.getY() - screen_h);
        if (p.getX() < 0)
            p.setX(p.getX() + screen_w);
        if (p.getY() < 0)
            p.setY(p.getY() + screen_h);
        setPosition(p);

        float a = getAngle();
        a += getRotation() * time;
        setAngle(a);
    }

    bool collidesWith(Flying* f) const {
        return getPosition().distanceTo(f -> getPosition()) < (diameter() + f -> diameter()) / 2;
    }

    virtual float diameter() const { return 0; }
    virtual ALLEGRO_BITMAP* getBitmap() const { return bitmap; }
};

class Controlled : public Flying {
    bool left;
    bool right;
    bool forw;

public:

    Controlled() {
        left = false;
        right = false;
        forw = false;
    }

    void turnLeft(bool l) { left = l; }
    void turnRight(bool r) { right = r; }
    void forward(bool f) { forw = f; }

    virtual void move(float time) {
        if (left)
            setRotation(getRotation() - 0.1);
        if (right)
            setRotation(getRotation() + 0.1);
        if (forw)
            setVelocity(getVelocity() + Vect(cos(getAngle()), sin(getAngle())));
        Flying::move(time);
    }
};

class Spaceship : public Controlled {
public:

    Spaceship()
    {
        bitmap = al_load_bitmap("spaceship.png");
    }

    virtual float diameter() const { return 48; }
};

class Asteroid : public Flying {
public:

    Asteroid() {
        bitmap = al_load_bitmap("asteroid.png");
    }

    virtual float diameter() const { return 64; }
};

vector<Flying*> objects;

void create_asteroid() {
    Asteroid *a = new Asteroid();

    do {
        a -> setPosition(Vect(rand() % screen_w, rand() % screen_h));
    } while (a -> getPosition().distanceTo(objects[0] -> getPosition()) < 200);

    a -> setAngle(rand());
    a -> setRotation(((float) (rand() % 200) - 100) / 100.0);
    a -> setVelocity(Vect((rand() % 60) - 30, (rand() % 60) - 30));

    objects.push_back(a);
}

int main(int, char**) {
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

    al_clear_to_color(al_map_rgb(0,0,0));
    al_flip_display();

    al_start_timer(timer);

    Spaceship *s = new Spaceship();
    s -> setPosition(Vect(screen_w / 2, screen_h / 2));
    s -> setAngle(0);
    s -> setRotation(0);
    s -> setVelocity(Vect(0, 0));

    objects.push_back(s);

    for (int i = 0; i < 5; i++)
        create_asteroid();

    for (Flying* f: objects) {
        if (f -> getBitmap() == NULL) {
            cout << "Nie udało się załadować bitmapy." << endl;
            return 3;
        }
    }

    float time = 0.0;
    float game = 0.0;

    while (true) {
        // process events
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_TIMER) {
            // move objects
            for (Flying* f: objects)
                f -> move(1.0 / FPS);

            time +=  1.0 / FPS;
            game +=  1.0 / FPS;

            if (time > 15.0)
                create_asteroid(); time = 0.0;
        }
        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            break;
        else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
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
        }
        else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
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
                 case ALLEGRO_KEY_ESCAPE:
                    goto koniec;
                    break;
            }
        }

        // detect collsion

        int coll = 0;
        for (Flying *f: objects) {
            if (f -> collidesWith(objects[0]))
                coll++;
        }

        if (coll > 1) {
            ALLEGRO_DISPLAY *exit_screen = al_create_display(exit_w, exit_h);
            al_register_event_source(event_queue, al_get_display_event_source(exit_screen));

            al_init_font_addon();
            al_init_ttf_addon();

            ALLEGRO_FONT *title = al_load_font("pirulen.ttf", 50, 0);
            ALLEGRO_FONT *body = al_load_font("pirulen.ttf", 30, 0);
            ALLEGRO_FONT *game_time = al_load_font("pirulen.ttf", 32, 0);

            al_clear_to_color(al_map_rgb(255, 255, 255));

            al_draw_text(title, al_map_rgb(0, 0, 100), exit_w / 2, exit_h / 10, ALLEGRO_ALIGN_CENTRE, "GAME OVER!");
            al_draw_text(body, al_map_rgb(0, 0, 100), exit_w / 2, exit_h / 2 , ALLEGRO_ALIGN_CENTRE, "Twoja gra trwala: ");
            al_draw_textf(game_time, al_map_rgb(0, 0, 100), exit_w / 2, exit_h / 2 + 50, ALLEGRO_ALIGN_CENTRE, "%.2f sekund(y)", game);

            al_flip_display();

            while(true) {
                ALLEGRO_EVENT ev;
                al_wait_for_event(event_queue, &ev);
                if((ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) | (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE))
                    break;
            }

            al_destroy_display(exit_screen);

            goto koniec;
        }

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

    koniec:

    cout << "GAME OVER!" << endl;
    cout << "Twoja gra trwala: " << setprecision(2) << game << " sekund(y)." << endl;
    return 0;
}
