#include <cmath>
#include <string>
#include <sstream>

#include <allegro5/allegro.h>

#include "vect.h"
#include "objects.h"

/* Definicje funkcje z klasy Flying */

Flying::Flying(){
    bitmap = al_load_bitmap("snake0.png"); //domyslne pobranie grafiki z czarnym kwadratem
}

Flying::~Flying(){
    delete bitmap;
}

Vect Flying::getPosition() const { return p; } // pobranie polozenia
void Flying::setPosition(const Vect _p) { p = _p; } // ustawienie polozenia

Vect Flying::getVelocity() const { return v; } // pobranie predkosci
void Flying::setVelocity(Vect _v) { v = _v; } //ustawienie predkosci

void Flying::move(float time) { //ruch
    Vect p = getPosition(); //pobranie polozenia
    p += getVelocity(); //przesuniecie punktu zgodnie z wektorem predkosci
    //if (p.getX() > screen_w) { p.setX(p.getX() - screen_w); }
    //if (p.getY() > screen_h) { p.setY(p.getY() - screen_h); }
    //if (p.getX() < 0) { p.setX(p.getX() + screen_w); }
    //if (p.getY() < 0) { p.setY(p.getY() + screen_h); }
    setPosition(p); //ustawienie polozenia
}

bool Flying::collidesWith(Flying* f) const{ //sprawdzenie kolizji
    return getPosition().distanceTo(f -> getPosition()) < (diameter() + f -> diameter()) / 2; //porownanie odleglosci obu wektorow
    //do srednic dwoch grafik
}

float Flying::diameter() const { return 0; } // pobranie srednicy bitmapy
ALLEGRO_BITMAP* Flying::getBitmap() const { return bitmap; } //pobranie bitmapy

/* Definicje funkcje z podklasy Snake */

Snake::Snake(float num){

    // najpierw przypisanie do zmiennych bedacych elementami struktury przetrzymujacych dane dla wezy, ktore sa w trakcie
    // robienia przerwy
    // zmienna boolowska inv definiuje czy waz jest w stanie "przerwy", zas time oznacza wielkosc bezwzgledna, w ktorej to
    // waz ponownie przejdzie w stan "rysowania"
    rand_break.inv = false;
    rand_break.time = 0.0;

    // ustawienie pozostalych zmiennych prywatnych
    left = false; // zmienna determinujaca czy obiekt porusza sie w lewo
    right = false; // zmienna determinujaca czy obiekt porusza sie w prawo
    stop = false; // zmienna determinujaca czy obiekt stoi

    angle_left = -0.05; // zmienna okreslajaca kat przy skrecie w lewo
    angle_right = 0.05; // zmienna okreslajaca kat przy skrecie w prawo
    bonus2 = false; // zmienna okreslajaca czy waz jest pod wplywem 2go bonusa (zmiana kata obrotu)
    bonus3 = false; // zmienna okreslajaca czy waz jest pod wplywem 3go bonusa (zamiana klawiszy)

    number = num; // numer weza

    // ustawienie ostatniej zmiennej "filename" przechowujacej wskaznika na char bedacy nazwa pliku, z ktorego pochodzi podpieta
    // bitmapa

    // tworzenie lancucha, a potem stringa z nazwa
    std::stringstream sstm;
    sstm << "snake" << num <<".png";
    std::string name = sstm.str();
    // ustawianie wartosci wskaznika
    filename = new char[10];
    strcpy(filename,name.c_str());
    bitmap = al_load_bitmap(filename);

}

Snake::~Snake(){ delete filename;} // destruktor zwalniajacy pamiec podpieta do nazwy pliku, z ktorego pochodzi bitmapa

void Snake::turnLeft(bool l) { left = l; } // zmiana stanu weza w przypadku skrecania w lewo
void Snake::turnRight(bool r) { right = r; } // zmiana stanu weza w przypadku skrecania w lewo
void Snake::set_stop(){ stop = true; } // zmiana stanu weza w przypadku zatrzymania sie
void Snake::set_go(){ stop = false; } // zmiana stanu weza w przypadku ponownego poruszania sie

bool Snake::get_stop(){ return stop; } // funkcja zwracajaca czy obiekt stoi czy nie

void Snake::move(float time) {

    if (left) {
        // ustawienie predkosci w razie skrecania w lewo
        // ponizszy wzor precyzuje wspolrzedne wektora predkosci po przeksztalceniu przez obrot
        setVelocity(Vect(getVelocity().getX() * cos(angle_left) - getVelocity().getY() * sin(angle_left),
                         getVelocity().getX() * sin(angle_left) + getVelocity().getY() * cos(angle_left)));
    }

    if (right) {
        // ustawienie predkosci w razie skrecania w prawo
        // ponizszy wzor precyzuje wspolrzedne wektora predkosci po przeksztalceniu przez obrot
        setVelocity(Vect(getVelocity().getX() * cos(angle_right) - getVelocity().getY() * sin(angle_right),
                         getVelocity().getX() * sin(angle_right) + getVelocity().getY() * cos(angle_right)));
    }

    Flying::move(time); // wywolanie poruszania sie wyspecyfikowanego w nadklasie

}

void Snake::set_angle_left(float _left){ angle_left = _left; } // funkcja zmieniajaca kat obrotu w lewo
void Snake::set_angle_right(float _right){ angle_right = _right; } // funkcja zmieniajaca kat obrotu w prawo
float Snake::get_angle_left(){ return angle_left; } // funkcja wyrzucajaca kat obrotu w lewo
float Snake::get_angle_right(){ return angle_right; } // funkcja wyrzucajaca kat obrotu w prawo

void Snake::set_bonus2(bool bonus){ bonus2 = bonus; } // funkcja flagujaca weza ktory jest pdo wplywem bonusa nr 2
void Snake::set_bonus3(bool bonus){ bonus3 = bonus; } // funkcja flagujaca weza ktory jest pdo wplywem bonusa nr 3
bool Snake::get_bonus2(){ return bonus2; } // funkcja zwracajaca czy waz jest pod wplywem bonusa nr 2
bool Snake::get_bonus3(){ return bonus3; }; // funkcja zwracajaca czy waz jest pod wplywem bonusa nr 3


float Snake::diameter() const { return 3; } // funkcja zwracajaca srednice

float Snake::getNumber(){ return number; } // funkcja zwracajaca numer weza

void Snake::randomize_break(float threshold, float time, float dur){ //funkcja determinujaca czy waz a przejsc w stan "przerwy"

    float if_break; // tymczasowa zmienna determinujaca czy waz ma przejsc w stan "przerwy

    if(!rand_break.inv){
        // wylosowanie wartosci i porownanie go z wartoscia graniczna - odpowiednio mala wartoscc pociaga za soba zmiane
        // zmiennej inv oraz time (momentu do ktorego waz bedzie w stanie "przerwy")
        if_break = float(rand()) / float(RAND_MAX);
        if(if_break < threshold){
            rand_break.inv = true;
            rand_break.time = time + dur;
        }
    }

    if(rand_break.time < time) rand_break.inv = false; // zmiana wartosci rand_break.inv jesli aktualny czas jest wiekszy niz
                                                       // ten zapisany w zmiennej rand_break.time
}

/* Definicje funkcje z podklasy Snake */

Bonus::Bonus(float _type){

    // ustawienie wartosci zmiennych wewnatrz klasy
    type = _type;
    used = false;
    black = false;

    // tworzenie lancucha, a potem stringa z nazwa
    std::stringstream sstm;
    sstm << "bonus" << type <<".png";
    std::string name = sstm.str();
    // ustawianie wartosci wskaznika
    filename = new char[10];
    strcpy(filename,name.c_str());
    bitmap = al_load_bitmap(filename);

}

Bonus::~Bonus(){ delete filename; } // destruktor zwalniajacy pamiec podpieta do nazwy pliku, z ktorego pochodzi bitmapa

float Bonus::diameter() const { return 30; } // funkcja zwracajaca srednice

float Bonus::get_type(){ return type; } // funkcja zwracajaca typ bonusa
bool Bonus::get_used(){ return used; } // funkcja zwracajaca czy bonus zostal zuzyty
void Bonus::set_used(bool _used){ used = _used; } // funkcja zmieniajaca wartosc used (uzywana gdy ktos wejdzie na bonus

void Bonus::change_bitmap(){ // funkcja zmieniajaca bitmape na czarna kule
    // zmiana wskaznika filename
    std::string name = "bonusx.png";
    strcpy(filename,name.c_str());
    bitmap = al_load_bitmap("bonusx.png"); //zaladowanie nowej bitmapy
}

bool Bonus::get_black(){ return black; } // funkcja zwracajaca zmienna black determinujaca dalsze nierysowanie bonusa ktoremu
                                         // zmieniono bitmape
void Bonus::set_black(){ black = true; } // funkcja ustawiajaca zmienna black aby nierysowano dalej bonusa ktoremu zmieniono
                                         // wlasnie bitmape
