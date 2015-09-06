// Program na zaliczenie Zaawansowanego Programowania Komputerowego WNE UW  sem. letni 2015
// Autor: Przemysław Kaczmarek



#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Podstawowe zmienne opisujace okno
const int screen_w = 800;
const int screen_h = 600;
const float FPS = 60.0;
const float _PI = 3.141593;

ALLEGRO_DISPLAY *display = NULL; // generowanie okna
ALLEGRO_EVENT_QUEUE *event_queue = NULL; // generowanie kolejki zdarzen
ALLEGRO_TIMER *timer = NULL; // generowanie timera (m.in. sterowanie FPS)

// generowanie kolejnych bitmap uzywanych w programie

ALLEGRO_BITMAP *icon = NULL;
ALLEGRO_BITMAP *explosion_bitmap = NULL;
ALLEGRO_BITMAP *alien1_bitmap = NULL;
ALLEGRO_BITMAP *missle1_bitmap = NULL;
ALLEGRO_BITMAP *player1_bitmap = NULL;
ALLEGRO_BITMAP *player_lvlup = NULL;
ALLEGRO_BITMAP *lose_b = NULL;
ALLEGRO_BITMAP *win_b = NULL;
ALLEGRO_BITMAP *wellcome_b = NULL;
ALLEGRO_BITMAP *start_b = NULL;
ALLEGRO_BITMAP *exit_b = NULL;
ALLEGRO_BITMAP *lose_word_b = NULL;

ALLEGRO_BITMAP *bonus1_b = NULL;
ALLEGRO_BITMAP *bonus2_b = NULL;
ALLEGRO_BITMAP *bonus3_b = NULL;
ALLEGRO_BITMAP *shield_b = NULL;
ALLEGRO_BITMAP *life_b = NULL;
ALLEGRO_FONT *font30 = NULL;

ALLEGRO_COLOR black = al_map_rgb(0,0,0), white = al_map_rgb(255,255,255);

// Reprezentacja punktów w przestrzeni oraz metody m.in. do pomiaru odległości
class Vect {
    float x, y;

public:
    Vect() : Vect(0.0, 0.0) {}
    Vect(float _x, float _y) {
        setX(_x);
        setY(_y);
    }

    ~Vect () {}

    float distanceTo(Vect p) {
        float dx = x - p.getX();
        float dy = y - p.getY();
        return sqrt(dx*dx + dy*dy);
    }
    float distanceTo(float _x, float _y){
        float dx = x - _x;
        float dy = y - _y;
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
    void print(){cout << x << "; " << y << endl;}
};

Vect operator*(Vect v, float f) {
    v *= f;
    return v;
}

Vect operator+(Vect v1, Vect v2) {
    v1 += v2;
    return v1;
}

ostream& operator<<(ostream &o, const Vect w) {
    o << "(" << w.getX();
    o << "," << w.getY();
    o << ")";
    return o;
}


// Podstawowa klasa reprezentujaca kazdy obiekt w grze (poprzez dziedziczenie)
class object {
   ALLEGRO_BITMAP *bitmap;
    Vect p;
    float rotation;
    float tinted;
    int bitmap_w;
    int bitmap_h;
public:
    object() {
        bitmap = NULL;
        p = Vect();
        rotation = 0.0;
        tinted = 0.0;
        bitmap_w = 0;
        bitmap_h = 0;
    }

    // konstruuje obiekt o bitmapie i wsp. srodka bitmapy (wsp obiektu)
    object(ALLEGRO_BITMAP *_bitmap, float _x, float _y) {
        bitmap = _bitmap;
        p = Vect(_x, _y);
        rotation = 0.0;
        tinted = 0.0;
        bitmap_w = al_get_bitmap_width(bitmap);
        bitmap_h = al_get_bitmap_height(bitmap);
    }

    ~object(){
        al_destroy_bitmap(bitmap);
        p.~Vect();
    }

    Vect getPosition() const { return p; }
    void setPosition(const Vect _p) { p = _p; }
    void setPosition(const float _x, const float _y) { p.setX(_x); p.setY(_y); }

    float distanceTo(const float _x, const float _y) { return p.distanceTo(_x,_y); }
    float distanceTo(const Vect r) { return p.distanceTo(r); }
    float distanceTo(const object *r) { return p.distanceTo(r -> getPosition()); }

    float getRotation() const { return rotation; }
    void setRotation(float _r) { rotation = _r; }
    void setTinted(float _tinted) {tinted = _tinted;}
    int getBitmap_w() {return bitmap_w; }
    int getBitmap_h() {return bitmap_h; }

    // zasieg bitmapy - poniewaz ruch odbywa sie glownie pionowo oraz wiekszosc bitmap jest kwadratowa, to ustawiono go na polowe wysokosci
    virtual float radius() const {
        if(bitmap)
            return bitmap_h / 2;
        else
            return 0;
    }

    virtual ALLEGRO_BITMAP* getBitmap() const { return bitmap; }
    virtual void setBitmap( ALLEGRO_BITMAP * _bitmap) { bitmap = _bitmap; }

    // podstawowa metoda odpowiedzialna za rysowanie obiektow - pozwala na rysowanie z obrotem i przezroczystoscia
    // przezroczystosc wykorzystana w celu zwiekszenia plynnosci wyswietlania i unikniecia zjawiska zaslaniania
    virtual void draw() {
        al_draw_tinted_rotated_bitmap(bitmap, al_map_rgba_f( 1.0, 1.0, 1.0, tinted),bitmap_w / 2, bitmap_h / 2,
                             getPosition().getX(), getPosition().getY(),0,0);
    }
};

// Klasa obiektow, ktore w czasie gry zmieniaja swoja pozycje
class moving_object: public object{
    Vect v = Vect();
    Vect starting_point;
    float angle = 3.0 * _PI / 2.0;
    Vect target;
    float speed;
    float destr_start_time;
    int destroyed;
    ALLEGRO_BITMAP *explosion_b;
public:
    moving_object():object(){
        starting_point = getPosition();
        destr_start_time = -1;
        destroyed = 0;
        explosion_b = explosion_bitmap;
    }

    moving_object(ALLEGRO_BITMAP *bitmap, float _x, float _y):object(bitmap, _x, _y){
        starting_point = getPosition();
        destr_start_time = -1;
        destroyed = 0;
        explosion_b = explosion_bitmap;
    }

    ~moving_object(){this -> ~object();}

    Vect getVelocity() { return v; };
    void setVelocity(const Vect _v) { v = _v; }
    void setVelocity(const float v_x, const float v_y) { v.setX(v_x); v.setY(v_y); }

    float getAngle() { return angle; }
    void setAngle(float _a) { angle = _a; }

    void setSpeed(float _s) { speed = _s; }
    float getSpeed() { return speed; }

    Vect getStarting_point() { return starting_point; }
    int getDestroyed() {return destroyed;}

// poruszanie sie po prostej
    virtual void move(float _time) {
        Vect p = getPosition();
        p += getVelocity() * _time;
        setPosition(p);
    }

// kolizja z wskazanym obiektem - poniewaz na planszy sa tylko ruchome obiekty, wksazany obiekt to klasy dziedziczace z moving_object
    virtual bool collision(moving_object *p) {
        return distanceTo(p -> object::getPosition()) < (radius() + p -> radius());
    }

// ustawienie celu - punktu, w kierunku ktorego odbywa sie ruch
    virtual void setTarget(float t_x, float t_y) { target.setX(t_x); target.setY(t_y); }

// ruch po okregu - niestety nie wykorzystany w module generujacym rozgrywke, nie mniej jednak metoda wpelni dzialajaca
    virtual void circle_move(float _time, bool clockwise) {
        if(clockwise) { angle += ((_PI / 10) * _time); }
        else { angle -= ((_PI / 10) * _time); }

        setPosition(100.0 * cos(angle) + starting_point.getX(), 100.0 * sin(angle) + starting_point.getY() + 100.0);
    }

// ruch po "luku" - docelowo statki oraz pociski (po aktywacji bonusu lub pociski bossa) mialy miec mozliwosc poruszania sie po torach innych niz prosta
// niestety nie wykorzystane w mechanice gry. Metoda wpelni dzialajaca
    virtual void elipse_move(float _time, bool left_side) {
        if(left_side) {
            if(angle == (3.0 * _PI / 2.0)) { setVelocity((target.getX() - (100.0 * cos(3.0 * _PI / 4.0) + starting_point.getX()))/10 , (target.getY() - (100.0 * sin(3.0 * _PI / 4.0) + starting_point.getY() + 100.0)) / 10); }

            if(starting_point.getX() < target.getX()) {
                if(angle > 3.0 * _PI / 4.0 || angle == 3.0 * _PI / 2.0) { circle_move(_time, false); }
                else { moving_object::move(_time); }
            } else {
                if(angle > _PI || angle == 3.0 * _PI / 2.0) { circle_move(_time, false); }
                else{ moving_object::move(_time); }
            }
        } else {
            if(angle == (3.0 * _PI / 2.0)) { setVelocity((target.getX() - (100.0 * cos(_PI / 4.0) + starting_point.getX()))/10 , (target.getY() - (100.0 * sin(_PI / 4.0) + starting_point.getY() + 100.0)) / 10); }

            if(starting_point.getX() > target.getX()) {
                if(angle < 2.0 * _PI || angle == 3.0 * _PI / 2.0) { circle_move(_time, true); }
                else { moving_object::move(_time); }
            }else {
                if(angle <  7.0 * _PI / 4.0 || angle == 3.0 * _PI / 2.0) { circle_move(_time, true); }
                else{ moving_object::move(_time); }
            }
        }
    }

// niszczenie obiektow, tj. ich wybuch i odpowiednie ustawienie parametrow
    virtual void destroy( float _time) {
        if(destroyed == 0){
            destr_start_time = _time;
            explode(_time);
            destroyed = 1;
        } else if(destroyed == 1){
            explode(_time);
        }
    }

// animacja wybuchu - wybuch to tak naprawde 16 obrazkow wyswietlonych z duza predkoscia
// kolejne klatki to fragmenty jednej duzej bitmapy
    virtual void explode(float _time) {
        int iteracja = (_time - destr_start_time) * 30;
        float wsp_x = 0.0;
        float wsp_y = 0.0;

        if(iteracja < 16) {
            switch(iteracja) {
                case 0: {wsp_x = 0.0; wsp_y = 0.0; break; }
                case 1: {wsp_x = 64.0; wsp_y = 0.0; break; }
                case 2: {wsp_x = 128.0; wsp_y = 0.0; break; }
                case 3: {wsp_x = 196.0; wsp_y = 0.0; break; }
                case 4: {wsp_x = 0.0; wsp_y = 64.0; break; }
                case 5: {wsp_x = 64.0; wsp_y = 64.0; break; }
                case 6: {wsp_x = 128.0; wsp_y = 64.0; break; }
                case 7: {wsp_x = 196.0; wsp_y = 64.0; break; }
                case 8: {wsp_x = 0.0; wsp_y = 128.0; break; }
                case 9: {wsp_x = 64.0; wsp_y = 128.0; break; }
                case 10: {wsp_x = 128.0; wsp_y = 128.0; break; }
                case 11: {wsp_x = 196.0; wsp_y = 128.0; break; }
                case 12: {wsp_x = 0.0; wsp_y = 196.0; break; }
                case 13: {wsp_x = 64.0; wsp_y = 196.0; break; }
                case 14: {wsp_x = 128.0; wsp_y = 196.0; break; }
                case 15: {wsp_x = 196.0; wsp_y = 196.0; break; }
            }
            al_draw_bitmap_region(explosion_b,wsp_x,wsp_y,64, 64, getPosition().getX() - 32, getPosition().getY() - 32, 0);
        } else {destroyed = -1;}
    }
};

// Klasa reprezentujaca gracza
class spaceship: public moving_object {
    bool left;
    bool right;
    float start_time;
    int life;

public:
    spaceship():moving_object() {
        left = false;
        right = false;
        setSpeed(150.0);
        start_time = 0.0;
        life = 3;
    }
    spaceship(ALLEGRO_BITMAP *bitmap, float _x, float _y):moving_object(bitmap, _x, _y) {
        left = false;
        right = false;
        setSpeed(150.0);
        start_time = 0.0;
        life = 3;}
    ~spaceship() {this -> ~moving_object(); }

    void moveLeft(bool l) { left = l; }
    void moveRight(bool r) { right = r; }

    //setVelocity nie powoduje zmiany ruchu gracza - zablokowana zmiana

    // zmiana interfejsu w celu umozliwienia ruchu jedynie lewa-prawa
    virtual void move(float _time) {
        if (left && !right && getPosition().getX() >= getBitmap_w() / 2) {
            setVelocity(-getSpeed() , 0.0);
            moving_object::move(_time);
        } else if (right && !left && getPosition().getX() <= (screen_w - getBitmap_h() / 2)) {
            setVelocity(getSpeed() , 0.0);
            moving_object::move(_time);
        } else {
            setVelocity(0.0,0.0);
        }
    }

    int getLife() {
        return life;
    }

    void takeLife(int hit){
        life -= hit;
    }
};

// reprezentacja statkow kosmitow
class alien: public moving_object {
    int direction;

public:
    alien():moving_object() {
        direction = 1;
        setSpeed(60.0);
        setTinted(0.0);
    }
    alien(ALLEGRO_BITMAP *bitmap, float _x, float _y):moving_object(bitmap, _x, _y) {
        direction = 1;
        setSpeed(60.0);
        setTinted(0.0);
    }
    ~alien() {this -> ~moving_object(); }

    void changeDirection() { direction *= -1; }

// statki moga ruszac sie jedynie lewa-prawa i to na odleglosc 100 od punktu startowego
// zostala zaimplementowana rowniez metoda do ruchu po elipsie, jednak nie wykorzystano jej w mechanice rozgrywki
    virtual void move(float _time) {
        if (getPosition().distanceTo(getStarting_point()) > 100.0) {
                changeDirection();
        }

        setVelocity(Vect(direction * getSpeed(), 0.0));
        moving_object::move(_time);
    }
};

// klasa reprezentujaca pociski
class missle:public moving_object {
    bool by_player;

public:
    missle():moving_object() {
        setVelocity(20.0, 0);
        by_player = true;
        }

    missle(ALLEGRO_BITMAP *bitmap, float _x, float _y, bool _by_player):moving_object(bitmap, _x, _y) {
        if(!_by_player){
                setVelocity(0, 7.0);
        }else{
                setVelocity(0, -10.0);
        }
        by_player = _by_player;
    }

    missle(ALLEGRO_BITMAP *bitmap, float _x, float _y):moving_object(bitmap, _x, _y) {
        setVelocity(0, -10.0);
        by_player = true;
    }

    ~missle() {this -> ~moving_object(); }

// metoda odpowiedzialna za przemieszanie stworzonego juz pocisku
    virtual void fire(float _time){
        if(by_player){
            setTarget(getPosition().getX(), 0);
            move(_time);
        } else {
            setTarget(getPosition().getX(), screen_h);
            move(_time);
        }
    }
};

// klasa zawierajaca infromacje o aktualnym stanie rozgrywki
// poniewaz koncepcja zakladala wykorzystanie bonusow oraz pojawienie sie bossa, zawiera ona rowniez ikony bonusow oraz mozliwosc
// wyswietlania animowanego paska zycia dla bossa

class game_status {
    int points;
    int lvl;
    bool boss_status;
    int player_hp;
    float boss_hp;
    bool bonus1;
    bool bonus2;
    bool bonus3;
    bool shield;

public:
    game_status(){
        bonus1 = true;
         bonus2 = true;
         bonus3 = true;
         shield = true;
         player_hp = 3;
         boss_status = false;
         boss_hp = 100.0;
         points = 0;
         lvl = 1;
    };

    int getPoints() {return points;}
    bool getBossStatus() { return boss_status;}
    float getBossLife() { return boss_hp;}

    void setPlayerLife(spaceship * _gracz) {player_hp = _gracz -> getLife();}
    void setPoints(int _points) {points = _points;}
    void addPoints(int _points) {points += _points;}
    void setBossStatus(bool _status) {boss_status = _status;}
    void setBossLife(float _boss_hp) {boss_hp = _boss_hp;}

    bool getBonus1() {return bonus1;}
    bool getBonus2() {return bonus2;}
    bool getBonus3() {return bonus3;}
    bool getShield() {return shield;}
    int getPlayerLife() {return player_hp;}

    int getLVL() {return lvl;}
    void levelUp() {lvl++;}

// Metoda odpowiedzialna za wysiwtlanie gornego paska stanu
    void draw(){
        if(bonus1){
            al_draw_rotated_bitmap(bonus1_b, 20.0, 20.0, 500.0, 25.0, 0 ,0);
        }
        if(bonus2){
            al_draw_rotated_bitmap(bonus2_b, 20.0, 20.0, 550.0, 25.0, 0 ,0);
        }
        if(bonus3){
            al_draw_rotated_bitmap(bonus3_b, 16.0, 16.0, 600.0, 25.0, 0 ,0);
        }
        if(shield){
            al_draw_rotated_bitmap(shield_b, 16.0, 16.0, 450.0, 25.0, 0 ,0);
        }
        for(int i = 1; i <= player_hp; i++){
            al_draw_rotated_bitmap(life_b, 20.0, 20.0, 600.0 + i * 50.0, 25.0, 0 ,0);
        }

        if(boss_status){
            float bar_width = boss_hp * 2.0;
            al_draw_filled_rectangle(300,50,500,60,al_map_rgba(100,100,100,255));
            al_draw_filled_rectangle(300,50,300 + bar_width,60,al_map_rgba(150,0,0,255));
            al_draw_rectangle(300,50,500,60,al_map_rgba(200,200,200,255),0);
        }

        al_draw_textf(font30, al_map_rgb(140,140,140), 40, 3, ALLEGRO_ALIGN_LEFT, "LVL:%d", lvl);
        al_draw_textf(font30, al_map_rgb(140,140,140), 200, 3, ALLEGRO_ALIGN_LEFT, "POINTS:%d", points);
    }
};

// wektory przechowujace wksazniki na obiekty z gry
vector<alien*> aliens_vect;
vector<missle*> missles_vect;
vector<missle*> aliens_missles_vect;
vector<alien**> shooting_aliens; // wektor przechowujacy wskaznik na wskaznik obiektu z vectora aliens_vect - wykorzystane do tworzenia list obiektow, ktore moga strzelac i losowani sposrod nich
vector<alien**> left_moving_aliens;
vector<alien**> right_moving_aliens;

// zmienne do sprawdzania ile statkow moze strzelac oraz rozpoczac ruch po elipsie w lewo/prawo (czyli ktore obiekty sa skrajne)
int how_many_forward = 0;
int how_many_left = 0;
int how_many_right = 0;



// funkcja generujaca wektor zawierajacy kosmitow
void create_aliens(){
    for(int j = 0; j < 5; j++){
        for(int i = 0; i < 10; i++){
            alien *a = new alien(alien1_bitmap, 200 + i * 50 , 100 + j * 50);
            aliens_vect.push_back(a);
        }
    }
}

// tworzenie pociskow przez gracza
void create_missle(spaceship *gracz){
    missle *m = new missle(missle1_bitmap, gracz -> getPosition().getX(), gracz -> getPosition().getY());
    missles_vect.push_back(m);
    missles_vect.back() -> fire(1);
}

// tworzenie pociskow przez kosmitow - obiekty przypisywane do roznych wektorow
void create_missle_alien (alien *alien_ship){
    missle *m = new missle(missle1_bitmap, alien_ship -> getPosition().getX(), alien_ship -> getPosition().getY(), false);
    aliens_missles_vect.push_back(m);
    aliens_missles_vect.back() -> fire(1);
}

// sprawdzenie, czy przed statkiem kosmity nie ma innego kosmity - zalozeniem gry jest to, ze strzelac moga jedynie statki,
// ktore nie sa zasloniete przez inny statek
bool isAlienForward(alien *current){
    for(alien* a:aliens_vect){
       if(a -> getPosition().getX() == current -> getPosition().getX()){
            if(a -> getPosition().getY() > current -> getPosition().getY())
                return true;
       }
    }
    return false;
}

// sprawdzenie czy nie jest zasloniety przez inny statek od swojej lewej - potrzebne do uruchomienia ruchu po elipsie
bool isAlienLeft(alien *current){
    for(alien* a:aliens_vect){
       if(a -> getPosition().getY() == current -> getPosition().getY()){
            if(a -> getPosition().getX() < current -> getPosition().getX())
                return true;
       }
    }
    return false;
}

// analog dla prawej strony
bool isAlienRight(alien *current){
    for(alien* a:aliens_vect){
       if(a -> getPosition().getY() == current -> getPosition().getY()){
            if(a -> getPosition().getX() > current -> getPosition().getX())
                return true;
       }
    }
    return false;
}

// zliczanie, ile jest statkow spelniajacych powyzsze warunku
// potrzebne jest to do ograniczania generatorow losowych
// wykorzystano tutaj przekazywanie wskaznikow na element wektora do innego wektora - tworzona jest "lista" obiektow spelniajacych dany warunek
void howMany(){
    how_many_forward = 0;
    how_many_left = 0;
    how_many_right = 0;
    alien** alien_pointer = aliens_vect.data(); // istotne
    shooting_aliens.clear();
    left_moving_aliens.clear();
    right_moving_aliens.clear();

    for(alien* a:aliens_vect){
        if(!isAlienForward(a)){
            how_many_forward++;
            shooting_aliens.push_back(alien_pointer);
        }
        if(!isAlienLeft(a)){
            how_many_left++;
            left_moving_aliens.push_back(alien_pointer);
        }
        if(!isAlienRight(a)){
            how_many_right++;
            right_moving_aliens.push_back(alien_pointer);
        }
    alien_pointer++;
    }
}

// rysowanie calego wektora kosmitow
void draw_aliens(float _time) {
    for(alien* a:aliens_vect ){
        a -> move(1/FPS);
        a -> draw();
    }
}

// poniewaz wybor statkow, ktore strzelaja w danej chwili, odbywa sie losowo, funkcja ta jest odpowiedzialna za tworzenie pociskow
// dla wybranych statkow
// plan projektu zakladal zmiane liczby statkow strzelajacych w zaleznosci od poziomu gry

void random_aliens_shooting(int how_many){
    int choosed_alien1, choosed_alien2, choosed_alien3;

    if(how_many > how_many_forward)
        how_many = how_many_forward;

    if(how_many == 1){
        choosed_alien1 = rand() % how_many_forward;
        create_missle_alien(*shooting_aliens[choosed_alien1]);
    }else if(how_many == 2){
        choosed_alien1 = rand() % how_many_forward;
        choosed_alien2 = rand() % how_many_forward;
        while(choosed_alien1==choosed_alien2){
            choosed_alien2 = rand() % how_many_forward;
        }
        create_missle_alien(*shooting_aliens[choosed_alien1]);
        create_missle_alien(*shooting_aliens[choosed_alien2]);
    }else if(how_many == 3){
        choosed_alien1 = rand() % how_many_forward;
        choosed_alien2 = rand() % how_many_forward;
        choosed_alien3 = rand() % how_many_forward;
        while(choosed_alien1==choosed_alien2){
            choosed_alien2 = rand() % how_many_forward;
        }
        while(choosed_alien1==choosed_alien3){
            choosed_alien3 = rand() % how_many_forward;
        }
        while(choosed_alien2==choosed_alien3 || choosed_alien1 ==choosed_alien3){
            choosed_alien3 = rand() % how_many_forward;
        }
        create_missle_alien(*shooting_aliens[choosed_alien1]);
        create_missle_alien(*shooting_aliens[choosed_alien2]);
        create_missle_alien(*shooting_aliens[choosed_alien3]);
    }

    shooting_aliens.clear(); // isotne - losowania odbywaja sie kazdym takcie, wiec wektor musi byc czyszczony, bo statek mogl zostac zniszczony
}

// mechanika dzialania pociskow gracza
// aby nie zapelnic pamieci, pociski, ktore trafily lub wyleciay poza obszar gry sa usuwane (usuwane sa obiekty z wektora)
// analogicznie dzieje sie z zestrzelonymi statkami - stad potrzebne byly metody do sprawdzania czy statki sa na skraju rzedu
void player_missles_control(game_status * _game_status){
            std::vector<missle*>::iterator it_mis = missles_vect.begin(); // iterator wektora - potrzebny z uwagi na usuwanie elementow wewnatrz wektora
            for(missle *m: missles_vect ){
                m -> fire(1);
                m -> draw();
                std::vector<alien*>::iterator it_al = aliens_vect.begin();
                for(alien *a: aliens_vect){
                    if(m -> collision(a)){
                        a -> destroy(1/FPS);
                        _game_status -> addPoints(5);
                        if(!aliens_vect.empty()){ // zabezpieczenie przed usuwanie elemntu wektora, gdy jest on pusty
                            aliens_vect.erase(it_al); // usuniecie elementu wektora i przesuniecie kolejnych elementow o jeden w kierunku poczatku
                        }
                        if(!missles_vect.empty()){
                            missles_vect.erase(it_mis);
                        }
                        it_al++;
                        break;
                    }
                    it_al++;
                }
                if(m -> getPosition().getY() < 70){
                    if(!missles_vect.empty())
                        missles_vect.erase(it_mis);
                }
                it_mis++;
            }
}

// analog do pociskow gracza
void alien_missles_control(spaceship * _gracz){
            if(!aliens_missles_vect.empty()){
                std::vector<missle*>::iterator it_misa = aliens_missles_vect.begin();
                for(missle *m: aliens_missles_vect){
                   // m -> fire(1);
                    m -> draw();

                    if(m -> collision(_gracz)){
                        _gracz -> destroy(1/FPS);
                        _gracz -> takeLife(1);
                        if(!aliens_missles_vect.empty())
                                    aliens_missles_vect.erase(it_misa);
                    }
                    it_misa++;
                }
                std::vector<missle*>::iterator it_mis = aliens_missles_vect.begin();
                    for(missle *m: aliens_missles_vect){
                        if(m -> getPosition().getY() >650){
                                if(!aliens_missles_vect.empty())
                                    aliens_missles_vect.erase(it_mis);
                        } else{
                        it_mis++;
                        }
                    }
            }
}



// w koncu  main :)
int main()
{
// sprawdzenie inicjalizacji
    if(!al_init()){
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize allegro!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return 0;
    }
    if(!al_init_image_addon()){
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_image_addon!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return 0;
    }
    icon = al_load_bitmap("graphics/icon.png");
    if(!icon){
        al_show_native_message_box(display, "Error", "Error", "Failed to load icon!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        al_destroy_display(display); // nie udalo sie zainicjowac okna, wiec je usuwamy, chociaz jeszcze nie zostalo nawet wygenerowane
        return 0;
    }

    // Tworzenie struktury okna
    al_set_new_display_flags(ALLEGRO_WINDOWED);
    display = al_create_display(screen_w, screen_h);
    al_set_window_title(display,"Space Invaders by P.Kaczmarek");
    al_set_display_icon(display,icon);

    if(!display){
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return 0;
    }

    if(!al_install_keyboard()){
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize keyboard!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return 0;
    }

    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();

    timer = al_create_timer(1.0 / FPS); // timer
    event_queue = al_create_event_queue(); // kolejka

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_clear_to_color(al_map_rgb(0,0,0));
    al_flip_display();

    al_set_new_bitmap_flags ( ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR); // uplynnienie wysiwetlania bitmap poprzez rozmycie
    al_start_timer(timer);

    // zaladowanie bitmap
    explosion_bitmap = al_load_bitmap("graphics/explosion.png");
    alien1_bitmap = al_load_bitmap("graphics/alien1.png");
    missle1_bitmap = al_load_bitmap("graphics/missle2.png");
    player1_bitmap = al_load_bitmap("graphics/player1.png");
    player_lvlup = al_load_bitmap("graphics/lvlup.png");
    lose_b = al_load_bitmap("graphics/alf.png");
    win_b = al_load_bitmap("graphics/win.jpg");
    wellcome_b = al_load_bitmap("graphics/wellcome.jpg");
    start_b = al_load_bitmap("graphics/start_game.png");
    exit_b = al_load_bitmap("graphics/exit_game.png");
    lose_word_b = al_load_bitmap("graphics/you_lose4.png");

    bonus1_b = al_load_bitmap("graphics/bonus1.png");
    bonus2_b = al_load_bitmap("graphics/bonus2.png");
    bonus3_b = al_load_bitmap("graphics/bonus3.png");
    shield_b = al_load_bitmap("graphics/shield.png");
    life_b = al_load_bitmap("graphics/life.png");

    font30 = al_load_ttf_font("OpenSans-Semibold.ttf",30,0 ); //czcionka

// Tworzenie kolejnych obiektow
    spaceship *gracz = new spaceship(player1_bitmap, 400, 550); // tworzymy naszego gracza
    float _time = 0.0; // zerujemy czas
    game_status *status_gry = new game_status(); // tworzymy status gry
    create_aliens(); // tworzymy kosmitow

//    missle *pocisk2 = new missle(missle1_bitmap, 300, 400, false);
//    aliens_missles_vect.push_back(pocisk2);

    float fire_interval = 2.0; // jak czesto strzelaja kosmici
    //float move_interval = 3.0;
    //float elipse_move_interval = 5.0;
    float fire_base_time = 0.0; // zerujemy timer dla strzalow kosmitow
    //float move_base_time = 0.0;
    //float elipse_move_base_time = 0.0;
    float wait_for = 0; // opoznienie dzialania gry
    bool main_menu = true; // czy jestesmy w glownym menu
    bool main_menu_start_button = true; // ktora opcje wybrano
    bool main_menu_exit_button = false;
    bool main_menu_choose = false;

    srand( time( NULL ) ); // wymagane do pseudolosowosci f rand (ustawienie seed na zegar systemowy)

// glowna nieskonczona petla while
    while(true){
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        // sterowanie glownym menu - przejscie z menu do gry
        if(main_menu_choose && main_menu_start_button){
            main_menu = false; // wybor startu gry
        }else if(main_menu_choose && main_menu_exit_button){
            break; // wybor wyjscia z gry
        }

        if(ev.type == ALLEGRO_EVENT_TIMER) {
            if(wait_for <= 0 && !main_menu){ // czyli jestesmy na planszy i nie czekamy
                gracz -> move(1.0 / FPS); // uruchomienie mozliwosci poruszania sie gracza
                _time = _time + 1.0 / FPS; // a zegar tyka...
                al_clear_to_color(black);

                // alien obcy = new alien(alien1_bitmap, 300, 400);
                //obcy -> circle_move(0.05, true); // przyklad wykorzystania metody circle_move
               // obcy -> draw();

                gracz -> draw(); // wysietlamy gracza
                howMany(); // zliczamy obiekty, ktore moga strzelac itp.

                //random_aliens_elipse_left();

                draw_aliens(_time); // wyswietlenie obcych

                status_gry ->setPlayerLife(gracz); // zaczytanie do ststusu gry HP gracza
                status_gry -> draw(); // wyswietlenie statusu gry

                player_missles_control(status_gry); // kontrola pociskow gracza
                alien_missles_control(gracz); // kontrola pociskow kosmitow

                // kosmici strzelaja z zadanym interwalem
                if(_time - fire_base_time >= fire_interval){
                    random_aliens_shooting(2);
                    fire_base_time = _time;
                }

                // wyswietlamy wszystkie pociski kosmitow i wprawiamy je w ruch
                for(missle *m:aliens_missles_vect ){
                    m -> fire(1);
                    m -> draw();
                }

                al_flip_display(); // wyswietlamy na ekanie obecny stan planszy

                // sprawdzenie czy skonczylismy poziom, tj. usunelismy wszystkie statki kosmitow z wektora przechowujacego te obiekty
                if(aliens_vect.empty()){
                    status_gry -> levelUp();
                    create_aliens(); // ponownie zapelniamy wektor
                    wait_for = 2; // czekamy 2 sekundy zanim pojawi sie nowy ekran z kolejnym poziomem

                    if(!aliens_missles_vect.empty()){
                        aliens_missles_vect.clear(); // czyscimy wektory z pociskami gracza ...
                    }
                    if(!missles_vect.empty()){
                        missles_vect.clear(); //... oraz z pociskami kosmitow
                    }
                }
            }

            // kolejny z mozliwych stanow gry - przejscie miedzy kolejnymi poziomami
            if(wait_for > 0 && !main_menu){
                wait_for -=(1.0 / FPS);
                al_clear_to_color(black);
                status_gry -> draw();
                gracz -> draw();
                al_draw_rotated_bitmap(player_lvlup, 25, 25,400 ,300,0,0);
                al_flip_display();
            }

            // stan odpwiedzialny za wysiwtlenie porazki
            if(gracz -> getLife() <= 0){
                al_clear_to_color(black);
                al_draw_rotated_bitmap(lose_b, 320, 240,400 ,300,0,0);

                al_draw_tinted_rotated_bitmap(lose_word_b, al_map_rgba_f( 1.0, 1.0, 1.0, 1.0),150, 110, 250, 150,0,0);
                al_flip_display();
                al_rest(5.0);
                break;
            }

            // Tutaj natomiast wysiwtlana jest wygrana -> zdobycie 10 lvl
            if(status_gry -> getLVL() == 10){
                al_clear_to_color(black);
                al_draw_rotated_bitmap(win_b, 400, 300,400 ,300,0,0);
                al_flip_display();
                al_rest(3.0);
                break;
            }

            // Od tego powinno zaczac sie... glowne menu
            if(main_menu){
                al_clear_to_color(black);
                al_draw_rotated_bitmap(wellcome_b, 400, 300,400 ,300,0,0);
                al_draw_tinted_rotated_bitmap(start_b, al_map_rgba_f( 1.0, 1.0, 1.0, 1.0),230, 50,400, 200,0,0);
                al_draw_tinted_rotated_bitmap(exit_b, al_map_rgba_f( 1.0, 1.0, 1.0, 1.0),215, 40,400, 300,0,0);

                // animacja wyboru opcji
                if(main_menu_start_button && !main_menu_exit_button){
                    al_draw_rectangle(170,150,630,250,al_map_rgba(200,200,200,255),4);
                }else if(!main_menu_start_button && main_menu_exit_button){
                    al_draw_rectangle(170,250,630,350,al_map_rgba(200,200,200,255),4);
                }
                al_flip_display();
                //break;
                }

            // wylaczenie gry
            } else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                break;
            // sterowanie strzalkami - rozroznienie pomiedzy menu glownym a plansza
            } else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
                 switch(ev.keyboard.keycode) {
                     case ALLEGRO_KEY_UP:
                       if(!main_menu){
                            create_missle(gracz);
                            break;
                       }else{
                            if(main_menu_exit_button){
                                main_menu_start_button = true;
                                main_menu_exit_button = false;
                            }
                            break;
                       }
                     case ALLEGRO_KEY_DOWN:
                        if(main_menu){
                            if(main_menu_start_button){
                                main_menu_start_button = false;
                                main_menu_exit_button = true;
                            }
                            break;
                        }
                     case ALLEGRO_KEY_LEFT:
                        if(!main_menu){
                            gracz -> moveLeft(true);
                            break;
                        }
                     case ALLEGRO_KEY_RIGHT:
                        if(!main_menu){
                            gracz -> moveRight(true);
                            break;
                        }
                     case ALLEGRO_KEY_ENTER:
                        if(main_menu){
                            main_menu_choose = true;
                            break;
                        }
                    // sterowanie zamknieciem okna
                    case ALLEGRO_KEY_ESCAPE:
                        cout << "Koniec gry!" << endl;
                        return 0;
                        break;
                }
              }else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
                 switch(ev.keyboard.keycode) {
                     case ALLEGRO_KEY_LEFT:
                        gracz -> moveLeft(false);
                        break;
                     case ALLEGRO_KEY_RIGHT:
                        gracz -> moveRight(false);
                        break;
                 }
               }
    };

// Czas na koniec programu
    al_flip_display();
    al_destroy_display(display); //usuwamy okno z pamiêci i zwalniamy pamiêæ
    return 0;
};

