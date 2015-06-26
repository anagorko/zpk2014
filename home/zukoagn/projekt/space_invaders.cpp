/* ***************************************************************************** */
/*     Projekt na zaliczenie przedmiotu Zaawansowane programowanie komputerowe   */
/*                                                                               */
/*                             "Space Invaders"                                  */
/*                                                                               */
/*                            Agnieszka Żukowska                                 */
/* ***************************************************************************** */

#include<iostream>
#include<vector>
#include<math.h>
#include <iomanip>
#include <random>
#include<ctime>

using namespace std;

#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

const int screen_w = 800; // szerokosc okna
const int screen_h = 600; // wysokosc okna
const float FPS = 60.0;
const int level_end=3; //liczba poziomow


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
    int object, life, explosion, where;

public:
    Moving(){}

    virtual ~Moving(){}
// seria metod
    Vect getPosition() const { return p; }
    void setPosition(const Vect _p) { p = _p; }

    Vect getVelocity() const { return v; } //wez predkosc
    void setVelocity(Vect _v) { v = _v; } // ustaw predkosc

    int getObject()const { return object; }
    void setObject(const int _object) { object= _object; }


    int getLife() const { return life; }
    void setLife(const int _life) { life = _life; }

    int getShow()const { return where; } //metoda potrzebna do pokazania statku matki
    void setShow(const int _where) { where= _where; } //metoda potrzebna do pokazania statku matki

    int getExplosion() const {return explosion;}
    void setExplosion(const int _explosion){explosion = _explosion;}

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
                (diameter() + f -> diameter()) / 2;
    }

    virtual float diameter() const { return 0; }
    virtual ALLEGRO_BITMAP* getBitmap() const { return bitmap; }
    virtual void draw() {
        al_draw_rotated_bitmap(bitmap,
                               al_get_bitmap_width(bitmap) / 2,
                               al_get_bitmap_height(bitmap) / 2,
                               getPosition().getX(),
                               getPosition().getY(),
                               0,
                               0);
    }
};

//klasa odpowiedzialna za kontrolowanie czolgu
class Controlled : public Moving
{
    bool left;
    bool right;
    float speed;

public:
    Controlled()
    {
        left = false; right = false;
        speed = 0;
    }

    ~Controlled(){}

    void goLeft(bool l) { left = l; }
    void goRight(bool r) { right = r; }
    void setSpeed(float s) { speed = s; }

    virtual void move(float time) {
        int direction = 0;
        if (left) {
            direction--;
        }
        if (right) {
            direction++;
        }
        setVelocity(Vect(direction * speed, 0));
        Moving::move(time);
    }

};

//klasa czolg
class Tank : public Controlled{

    protected:
    int score;

    public:
    Tank()
    {
        bitmap = al_load_bitmap("tank_turret.png");
        life=3;
    }

    ~Tank(){}

    int getScore()const { return score; }
    void setScore(const int _score) { score= _score; }

    virtual float diameter() const { return 64; }// obiekt o srednicy 64
};

//klasa space invader
class SpaceInvader : public Moving
{
    int direction;
    float base_line;
    float speed;

    int points;

    public:
    SpaceInvader()
    {
        direction = 1; speed = 20.0;
        base_line = -1;
        life=1;
    }

    ~SpaceInvader(){}

    int getPoints()const { return points; }
    void setPoints(const int _points) { points= _points; }

    void setSpeed(float s) { speed = s; }

    void changeDirection() {
        direction *= -1;
        base_line += diameter()/2;
    }


    virtual float diameter() const { return 40; }// obiekt o srednicy 40


    //logika poruszania sie najezdzcow
    virtual void move(float time) {
        int down = 0;
        if (base_line < 0) {
            base_line = getPosition().getY();
        };
        if (base_line > getPosition().getY()) {
            down=1;
        }
        setVelocity(Vect(direction * speed, down*speed*5.0));
        Moving::move(time);
    }
};

class SpaceInvader01 : public SpaceInvader{
    public:
        SpaceInvader01()
        {
            bitmap = al_load_bitmap("SpaceInvader01a.png");
        }

        ~SpaceInvader01(){}

};

class SpaceInvader02 : public SpaceInvader{
    public:
        SpaceInvader02()
        {
            bitmap = al_load_bitmap("SpaceInvader02.png");
        }

        ~SpaceInvader02(){}

};

class SpaceInvader03 : public SpaceInvader{
    public:
        SpaceInvader03()
        {
            bitmap = al_load_bitmap("SpaceInvader03.png");
        }

        ~SpaceInvader03(){}

};

class SpaceInvader_Mother : public SpaceInvader{

    float speed;

    public:
        SpaceInvader_Mother()
        {
            bitmap = al_load_bitmap("SpaceInvader_Matka.png");
            speed = 150;
        }

        ~SpaceInvader_Mother(){}

        virtual void move(float time) {

        setVelocity(Vect((-1)*speed, 0));
        Moving::move(time);
        }

};


//klasa pocisk
class Missile : public Moving
{
    int position;
    float speed;
    int object_m;

    public:
    Missile()
    {
       bitmap = al_load_bitmap("missile.png");
       position = 0; speed = 200.0;
       object_m=1;
       life=1;
    }

    ~Missile(){}

    virtual float diameter() const { return 4; }// obiekt o srednicy 4


    virtual void move(float time) {
        int direction=1;
        object_m=getObject();
        position=getPosition().getX();

        if(object==1)
        {
                        direction=-1;
        }


        setVelocity(Vect(0, direction*speed));
        Moving::move(time);
    }


};

//klasa okop
class Shield : public Moving
{

    public:
    Shield()
    {
       bitmap = al_load_bitmap("fortress.png");
       life=3;
    }

    ~Shield(){}

    void change_color(int i)
    {
        if(i == 3)
        {
        bitmap = al_load_bitmap("fortress_orange.png");
        setLife(2);
        }

        if(i == 2)
        {
            bitmap = al_load_bitmap("fortress_red.png");
            setLife(1);
        }


    }

    virtual float diameter() const { return 80; }// obiekt o srednicy 80
};

//klasa eksplozja
class Explosion : public Moving
{
    public:
    Explosion()
    {
        bitmap = al_load_bitmap("explosion.png");
    }

    ~Explosion(){}

};

//klasa zycie
class Life : public Moving
{

    public:
        Life()
        {
            bitmap = al_load_bitmap("heart.png");
        }

        ~Life(){}

};

//tablicze poszczegolnych obiektow
vector<Tank*> tanks;
vector<SpaceInvader*> invaders;
vector<SpaceInvader_Mother*> mother;
vector<Shield*> shields;
vector<Missile*> missiles;
vector<Missile*> missiles_space;

vector<Moving*> layout; //tablica pozostalych obiektow planszy, np. zycie

int RandomElement(int i, int j)
{

    int random_element;
    random_element=rand()%i+j;
    return random_element;
}


// utworzenie poczatkowego ukladu najezdzcow
void create_space_invader(int level)
{

    int odleglosc, wysokosc;
    float speed;

    if(level==1)
    speed=20;
    else
    speed=15*level;

    if(level==1)
        speed=20;
    else if(level==2)
        speed=40;

   wysokosc = 0;

   for(int i=1; i<=5; i++)
    {
        odleglosc = 0;
        for(int j=1; j<=11; j++)
        {
            if (i==1) {
                SpaceInvader02 *s = new SpaceInvader02();
                s -> setPosition(Vect(odleglosc + screen_w / 5, wysokosc + ((screen_h+400) / 10)));
                s -> setVelocity(Vect(0, 0));
                s -> setPoints(50);
                s -> setSpeed(speed);
                invaders.push_back(s); // doklada nowy element do naszej tablicy
            } else if (i==2 || i== 3) {
                SpaceInvader01 *s = new SpaceInvader01();
                s -> setPosition(Vect(odleglosc + screen_w / 5, wysokosc + ((screen_h+400) / 10)));
                s -> setVelocity(Vect(0, 0));
                s -> setPoints(30);
                s -> setSpeed(speed);
                invaders.push_back(s);
            } else if (i==4 || i== 5) {
                SpaceInvader03 *s = new SpaceInvader03();
                s -> setPosition(Vect(odleglosc + screen_w / 5, wysokosc + ((screen_h+400) / 10)));
                s -> setVelocity(Vect(0, 0));
                s -> setPoints(10);
                s -> setSpeed(speed);
                invaders.push_back(s);
            }
            odleglosc = odleglosc + 50;
        }
        wysokosc = wysokosc + 50;
    }

}

void create_mother()
{

    SpaceInvader_Mother *s= new SpaceInvader_Mother();
    s -> setPosition(Vect(screen_w, screen_h/10));
    s -> setVelocity(Vect(0,0));
    s -> setShow(0);
    mother.push_back(s);

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
        sh -> setLife(3);

        shields.push_back(sh);// doklada nowy element do naszej tablicy
        odleglosc_s = odleglosc_s + 160;
    }

}

void create_missile(float x, float y, int object) // tworzenie pociskow
{
    Missile *m= new Missile();
    m -> setPosition(Vect(x,y));
    m -> setVelocity(Vect(0,0));
    m -> setObject(object);
    m -> setLife(1);

    if(object==1)
    missiles.push_back(m);
    if(object==0)
    missiles_space.push_back(m);
}

void create_life() // utworzenie zycia
{
    int odl=60;
    for(int i=1; i<= 3; i++)
    {
        Life *l = new Life();
        l -> setPosition(Vect(700+odl, 20));
        l -> setVelocity(Vect(0, 0));
        layout.push_back(l);
        odl=odl-30;
    }

}

//eksplozja

void create_explosion()
{
    Explosion *e = new Explosion();
    e -> setPosition(Vect(0,0));
    e -> setLife(10);
    layout.push_back(e);
}

void explosion(float x, float y)
{
    layout[3] -> setPosition(Vect(x,y));
    int life_e = layout[3] -> getLife();
    layout[3] -> setLife(life_e-1);

}


//kolizje pociskow

void missile_collision_tank() {
    vector<Missile*> missile_death;
    vector<Missile*> missiles_fly;

    int score, points;

    for (unsigned int j=0; j< missiles.size(); j++) {

        if(missiles[j] -> getLife() == 1 ) {
                if(mother[0] -> getShow()== 1){
                    if (missiles[j] -> collidesWith(mother[0])) {
                        missiles[j] -> setLife(0);
                        missile_death.push_back(missiles[j]);
                        mother[0] -> setLife(0);
                        score=tanks[0] -> getScore();
                        points=RandomElement(500, 100);
                        tanks[0] -> setScore(score+points);}
                }
        }

        for(unsigned int i=0; i< invaders.size(); i++) {
           if(missiles[j] -> getLife() == 1 ) {
                if(invaders[i] -> getLife() == 1) {
                    if (missiles[j] -> collidesWith(invaders[i])) {
                        missiles[j] -> setLife(0);
                        missile_death.push_back(missiles[j]);
                        invaders[i] -> setLife(0);
                        score=tanks[0] -> getScore();
                        points=invaders[i] -> getPoints();
                        tanks[0] -> setScore(score+points);}
                    }
                }
            }

        for(unsigned int k=0; k < shields.size(); k++) {
            if(missiles[j] -> getLife() == 1) {
                if(shields[k] -> getLife() != 0) {
                    if (missiles[j]->collidesWith(shields[k])) {
                        missiles[j] -> setLife(0);
                        missile_death.push_back(missiles[j]);
                        int l;
                        if(shields[k] -> getLife() !=1) {
                            l= shields[k] -> getLife();
                            shields[k] -> change_color(shields[k] -> getLife());
                            shields[k] -> setLife(l-1);
                        } else {
                            shields[k] -> setLife(0);
                        }

                    }
                }
            }
        }

        if(missiles[j] -> getLife() == 1)
        {
            if(missiles[j]-> getPosition().getY() < 0)
            {
                missiles[j] -> setLife(0);
                missile_death.push_back(missiles[j]);
            }
        }

        if(missiles[j] -> getLife() != 0) {
            missiles_fly.push_back(missiles[j]);
        }
    }

    missiles.clear();
    for (Missile* md: missiles_fly) {
        missiles.push_back(md);
    }
    missiles_fly.clear();

    for (Missile* md: missile_death){delete md;}
    missile_death.clear();

}

void missile_collision_space() {
    vector<Missile*> missile_space_death; //wektor pociskow, ktore sie zderzyly
    vector<Missile*> missiles_space_fly; //wektor pociskow, ktore nadal leca
    int life_tank;

    for (unsigned int j=0; j< missiles_space.size(); j++)
    {

        if(missiles_space[j] -> getLife() == 1) {
            if(tanks[0] -> getLife() != 0) {
                if (missiles_space[j] -> collidesWith(tanks[0])) {
                    missiles_space[j] -> setLife(0);
                    missile_space_death.push_back(missiles_space[j]);

                    if (tanks[0] -> getLife() !=0 ) {
                        life_tank=tanks[0] -> getLife();
                        life_tank--;
                        tanks[0] -> setLife(life_tank);
                        tanks[0] -> setExplosion(1);
                        tanks[0] -> setPosition(Vect(screen_w / 5, 9 * screen_h / 10));
                    } else {
                        tanks[0] -> setLife(0);
                    }
                }
            }
        }

        for(unsigned int k=0; k < shields.size(); k++) {
            if (missiles_space[j] -> getLife() == 1) {
                if(shields[k] -> getLife() != 0) {
                    if (missiles_space[j]->collidesWith(shields[k])) {
                        missiles_space[j] -> setLife(0);
                        missile_space_death.push_back(missiles_space[j]);
                        int l;
                        if(shields[k] -> getLife() !=1) {
                            l = shields[k] -> getLife();
                            shields[k] -> change_color(shields[k] -> getLife());
                            shields[k] -> setLife(l-1);
                        } else {
                            shields[k] -> setLife(0);
                        }
                    }
                }
            }
        }

        if(missiles_space[j] -> getLife() == 1)
        {
            if(missiles_space[j]-> getPosition().getY() > screen_h)
            {
                missiles_space[j] -> setLife(0);
                missile_space_death.push_back(missiles_space[j]);
            }
        }

        if(missiles_space[j] -> getLife() != 0) {
            missiles_space_fly.push_back(missiles_space[j]);
        }
    }

    missiles_space.clear();
    for (Missile* md: missiles_space_fly) {
        missiles_space.push_back(md);
    }
    missiles_space_fly.clear();

    for (Missile* md: missile_space_death){delete md;}
    missile_space_death.clear();
}

void missile_collision()
{
    missile_collision_tank();
    missile_collision_space();
}

void tank_vs_invaders_collision()
{
    for(unsigned int i=0; i<invaders.size(); i++)
    {
        if(invaders[i] -> getLife() == 1)
        {
            if(tanks[0] -> getLife() != 0)
            {
                 if ((invaders[i] -> collidesWith(tanks[0]))||(invaders[i] -> getPosition().getY() > screen_h))
                 {
                     tanks[0] -> setLife(0);
                     break;
                 }
            }

        }
    }
}


void game_start(int level)
{

    srand (time(NULL));
    //tworzenie oslon

    create_shield();

     //tworzenie czolgu

    Tank *tank = new Tank();
    tank -> setPosition(Vect(screen_w / 5, 9 * screen_h / 10));
    tank -> setSpeed(300.0);
    tank -> setLife(4);
    tank -> setExplosion(0);
    tank -> setScore(0);

    tanks.push_back(tank);

    create_life();
    create_explosion();
    //rysowanie najezdzcow
    create_space_invader(level);
    create_mother();



}

void change_level(int &level, float &time_l)
{
    level++;
    time_l=0;
    game_start(level);

}

int game_logic(float time, int level) {
    for (Moving* entity: tanks) { entity -> move(time); }
    for (Moving* entity: invaders) { entity -> move(time); }
    for (Moving* entity: missiles) { entity -> move(time); }
    for (Moving* entity: missiles_space) { entity -> move(time); }
    for (Moving* entity: mother) { entity -> move(time); }

    //ruch najezdzcow
    float max = 0;
    float min = screen_w;
    for (SpaceInvader* invader: invaders) {
        if (invader -> getLife() > 0) {
            float x = invader -> getPosition().getX();
            if (x > max) {
                max = x;
            };
            if (x < min) {
                min = x;
            }
        }
    }

    if (max > screen_w - 80 || min < 80) {
        for (SpaceInvader* invader: invaders) {
            invader -> changeDirection();
        }
    }


    //sprawdzenie, czy czolg dojechal do krawedzi ekranu
    int maxt = 20;
    int mint = screen_w-20;
    int xt=tanks[0] -> getPosition().getX();

    if(xt < maxt)
    {   xt=maxt;
        tanks[0] -> setPosition(Vect(xt, 9 * screen_h / 10));}
    if(xt > mint)
    {   xt=mint;
        tanks[0] -> setPosition(Vect(xt, 9 * screen_h / 10));}

    //losowe pociski najezdzcow

    int liczba_prob;
    int all_invaders=0;
    int life_invaders=0;

    for(SpaceInvader* i: invaders) {
        all_invaders++;
        if (i -> getLife() > 0) life_invaders++;
    }

    float fraction_life = float(life_invaders)/float(all_invaders);
    float one_per_time = 5.0/(float)level; // srednio jeden wrog na okreslony czas (w zaleznosci od poziomu; im wyzej tym czesciej)

    if (fraction_life > 0.5) {
        one_per_time = 1; // jak duzo wrogow to czesciej strzelaja
    } else if (fraction_life > 0.1) {
        one_per_time = 4.0/(float)level; // rzadziej strzelaja, ale czesciej niz domyslnie
    }
    liczba_prob=int((1/time)*life_invaders*one_per_time)+1;

    int random_element;

    for(SpaceInvader* i: invaders) {
        if (i -> getLife() > 0) {
            random_element=RandomElement(liczba_prob, 1);
            if (random_element==20) {
                create_missile(i -> getPosition().getX(), i -> getPosition().getY(), 0);
            }
        }
    }

    //Losowe pojawianie sie Statku Matki
    int random_mother;

    if(mother[0] -> getPosition().getX() == screen_w)
    {
        random_mother=RandomElement(5, 1);
        mother[0] -> setLife(1);
        if((random_mother==2)||(random_mother==4))
        {
            mother[0] -> setShow(1);
        }
        else {mother[0] -> setShow(0);}

    }

    if(mother[0] -> getPosition().getX() < 0)
    {mother[0] -> setPosition(Vect(screen_w+50, screen_h/10));}

    return life_invaders;

}


void clean_game()
{
                for (Missile* m: missiles){delete m;}
                missiles.clear();

                for (Missile* m: missiles_space){delete m;}
                missiles_space.clear();

                for(SpaceInvader* i: invaders){delete i;}
                invaders.clear();

                for(SpaceInvader* i: mother){delete i;}
                mother.clear();

                for(Shield* s: shields){delete s;}
                shields.clear();

                for (Tank* t: tanks){delete t;}
                tanks.clear();

                for (Moving* l: layout){delete l;}
                layout.clear();

}

//renderowanie gry
void render_game()
{
    for (Moving* entity: tanks) {
            if(entity -> getLife()!=0)
            {
                if((entity -> getExplosion() == 1)&&(layout[3] -> getLife()>0))
                {
                    explosion(entity -> getPosition().getX(), entity -> getPosition(). getY());
                    layout[3] -> draw();
                    if(layout[3] -> getLife() == 0)
                    entity -> setExplosion(0);
                }else{
                    layout[3] -> setLife(10);
                    entity -> draw();}
            }

    }

    for (Moving* entity: invaders) { if(entity -> getLife()!=0) entity -> draw(); }
    for (Moving* entity: shields) { if(entity -> getLife()!=0) entity -> draw(); }
    for (Moving* entity: missiles) { if(entity -> getLife()!=0) entity -> draw(); }
    for (Moving* entity: missiles_space) { if(entity -> getLife()!=0) entity -> draw(); }

    if(tanks[0] -> getLife()>0){
        for (int i=0; i<((tanks[0] -> getLife())-1); i++) {
            layout[i] -> draw();}
    }

    for (Moving* entity: mother) {if((entity -> getLife()!=0)&&(entity -> getShow() == 1)) entity -> draw(); }
}


int main(int, char**)
{

       //inicjalizacja biblioteki; obslugi klawiatury oraz warunku wyswietlania
    if (!al_init() || !al_install_keyboard() || !al_init_image_addon()) {
        cout << "Blad inicjalizacji." << endl;
        return 1;
    }

    al_init_font_addon();
    al_init_ttf_addon();

    ALLEGRO_DISPLAY *display = al_create_display(screen_w, screen_h);// stworzenie naszej planszy
    ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS); //stworzenie timera
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();//stworzenie kolejki zdarzen

    //gdy nie stworzy któregos z powyzszych
    if (display == NULL || timer == NULL || event_queue == NULL) {
        cout << "Blad inicjalizacji." << endl;
        return 2;
    }

    // zainicjowanie czcionki

    ALLEGRO_FONT *font = al_load_ttf_font("DejaVuSans-Bold.ttf",25,0);
    ALLEGRO_FONT *font2 = al_load_ttf_font("DejaVuSans-Bold.ttf",50,0);

    if (!font){
      fprintf(stderr, "Could not load 'DejaVuSans-Bold.ttf'.\n");
      return -1;
    }

    al_register_event_source(event_queue, al_get_display_event_source(display));//ladujemy do naszej kolejki zdarzen poszczegolne zrodla zdarzenia
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_start_timer(timer);

    const int MENU = 1;
    const int GAME = 2;
    const int RULES = 3;
    const int THEYARECOMING = 4;
    const int GAMEOVER = 5;
    const int WIN=6;
    int screen = 0;// 1- menu glowne, 2 - gra, 3 - rules, 4 - they are coming, 5 - gameover, 6 - win
    int switch_to_screen = 1;
    int level=1;

    int redraw_count = 0;
    bool redraw = true;

    ALLEGRO_BITMAP *menu_bitmap=NULL;
    menu_bitmap=al_load_bitmap("start2.png");

    ALLEGRO_BITMAP *rules_bitmap=NULL;
    rules_bitmap=al_load_bitmap("rules_screen02.png");

    ALLEGRO_BITMAP *theyrecoming_bitmap=NULL;
    theyrecoming_bitmap=al_load_bitmap("theyrecoming03.png");

    ALLEGRO_BITMAP *gameover_bitmap=NULL;
    gameover_bitmap=al_load_bitmap("gameover.png");

    ALLEGRO_BITMAP *win_bitmap=NULL;
    win_bitmap=al_load_bitmap("win.png");

    int score=0;//wynik ogolny
    int score_level=0; //wynik po poziomie
    float time_m=0;
    float time_sm=0; // space mother
    float time_level=0; //czas wyswietlenia informującego o poziomie

    int life_invaders=55;

    while (true)
    {
        // process events
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if (ev.type == ALLEGRO_EVENT_TIMER) {
            redraw = true;
            time_m = time_m + 1.0/FPS;
            time_sm = time_sm + 1.0/FPS;
        }
        else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }

        // jezeli przelaczamy sie miedzy widokami, nie obslugujemy eventow
        if (!switch_to_screen) {
            if (screen == MENU) {
                if (ev.type == ALLEGRO_EVENT_KEY_UP) {
                    switch (ev.keyboard.keycode) {
                            case ALLEGRO_KEY_S:
                                switch_to_screen = THEYARECOMING;
                                break;
                            case ALLEGRO_KEY_R:
                                switch_to_screen = RULES;
                                break;
                    }
                }
            } else if (screen == GAME) {

                time_sm = time_sm + 1.0/FPS;

                if (ev.type == ALLEGRO_EVENT_TIMER) {
                    time_level++;
                }
                if (time_level < FPS*3) {
                al_draw_textf( font2, al_map_rgb( 255, 255, 255 ), screen_w/2, (screen_h+100)/2, ALLEGRO_ALIGN_CENTRE, "LEVEL %i", level);
                }


                if(tanks[0] -> getLife() == 0)
                {
                    score_level=tanks[0]->getScore();
                    clean_game();
                    switch_to_screen = GAMEOVER;

                }else if(life_invaders==0){
                    score_level=tanks[0]->getScore();
                    clean_game();
                    life_invaders=55;
                    if(level==level_end)
                    {
                        switch_to_screen = WIN;
                    }else{
                        score+=score_level;
                        change_level(level, time_level);
                    }
;
                }
                else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
                    switch (ev.keyboard.keycode) {
                        case ALLEGRO_KEY_LEFT:
                            tanks[0]-> goLeft(true);
                            break;
                        case ALLEGRO_KEY_RIGHT:
                            tanks[0] -> goRight(true);
                            break;
                        case ALLEGRO_KEY_SPACE:
                            if(time_m>0.5)// czolg moze strzelac raz na 0.5sek.
                            {
                            create_missile(tanks[0] -> getPosition().getX(),tanks[0] -> getPosition().getY()-40, 1);
                            time_m=0;
                            }
                            break;
                        case ALLEGRO_KEY_ESCAPE:
                            clean_game();
                            score_level=0;
                            life_invaders=55;
                            switch_to_screen = MENU;
                            break;
                    }
                } else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
                    switch (ev.keyboard.keycode) {
                        case ALLEGRO_KEY_LEFT:
                            tanks[0] -> goLeft(false);
                            break;
                        case ALLEGRO_KEY_RIGHT:
                            tanks[0] -> goRight(false);
                            break;
                    }
                }
            } else if (screen == RULES) {
                if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
                        switch (ev.keyboard.keycode) {
                            case ALLEGRO_KEY_ESCAPE:
                                switch_to_screen = MENU;
                                break;
                }

                }
            } else if (screen == THEYARECOMING) {
                level=1;
                score=0;
                time_level=0;
                if (ev.type == ALLEGRO_EVENT_TIMER) {
                    redraw_count++;
                }
                if (redraw_count > FPS*3) {
                    switch_to_screen = GAME;
                    game_start(level);
                }
            } else if (screen == GAMEOVER){
                if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
                        switch (ev.keyboard.keycode) {
                            case ALLEGRO_KEY_ESCAPE:
                                switch_to_screen = MENU;
                                break;
                }

                }

            }else if(screen == WIN){
                if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
                        switch (ev.keyboard.keycode) {
                            case ALLEGRO_KEY_ESCAPE:
                                switch_to_screen = MENU;
                                break;
                }

                }
            }
        }


      if (redraw && al_is_event_queue_empty(event_queue)) {
        redraw = false;
        if (switch_to_screen) {
            screen = switch_to_screen;
            switch_to_screen = 0;
            redraw_count = 0;
        }
        // malowanie odbywa sie na ukrytym widoku
        switch (screen) {
            case MENU:
                al_draw_bitmap(menu_bitmap, 0, 0, 0);
                break;
            case GAME:

                score_level=tanks[0] -> getScore();

                al_draw_text( font, al_map_rgb( 255, 255, 255 ), 20, 5, ALLEGRO_ALIGN_LEFT, "SCORE: ");
                al_draw_textf( font, al_map_rgb( 255, 255, 255 ), 250, 5, ALLEGRO_ALIGN_RIGHT, "%i", score_level+score );

                // wykonujemy wszystkie operacje na obiektach:
                // ruchy, wykrywamy kolizje itp.

                life_invaders=game_logic(1.0/FPS, level);

                missile_collision();
                tank_vs_invaders_collision();

                 // renderujemy wszystkie obiekty
                render_game();
                break;
            case RULES:
                al_draw_bitmap(rules_bitmap, 0, 0, 0);
                break;
            case THEYARECOMING:
                al_draw_bitmap(theyrecoming_bitmap, 0, 0, 0);
                break;
            case GAMEOVER:
                al_draw_bitmap(gameover_bitmap, 0, 0, 0);
                al_draw_text( font2, al_map_rgb( 255, 0, 0), screen_w/2, (screen_h+200)/2, ALLEGRO_ALIGN_CENTRE, "YOUR SCORE: ");
                al_draw_textf( font2, al_map_rgb( 255, 0, 0 ), screen_w/2 , (screen_h+300)/2, ALLEGRO_ALIGN_CENTRE, "%i", score_level + score);
                break;
            case WIN:
                al_draw_bitmap(win_bitmap, 175, 0, 0);
                al_draw_text( font2, al_map_rgb( 255, 0, 0), screen_w/2, (screen_h+100)/2, ALLEGRO_ALIGN_CENTRE, "YOUR SCORE: ");
                al_draw_textf( font2, al_map_rgb( 255, 0, 0 ), screen_w/2 , (screen_h+200)/2, ALLEGRO_ALIGN_CENTRE, "%i", score_level + score);
                break;
        }
        // wyswietlamy to co namalowalismy na ukrytym widoku
        // a ukrywamy obecnie wyswietlany widok
        al_flip_display();
        // czyscimy to co bylo namalowane na wczesniej wyswietlanym
        // wyswietlanym widoku (teraz ukrytym)
        al_clear_to_color(al_map_rgb(0,0,0));
      }

    };


return 0;
}

