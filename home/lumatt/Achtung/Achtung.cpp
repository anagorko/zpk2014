#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "allegro5/allegro_native_dialog.h"

#include "vect.h"
#include "objects.h"

using namespace std;

const int screen_w = 800; // zdefiniowanie szerokosci ekranu gry (ktory to zostanie rozszerzony o pewna stala szerokosc zwiazana z wyswietlaniem
                          // paska z wynikami
const int screen_h = 600; // zdefiniowanie wysokosci ekranu gry
const float FPS = 60.0;

vector<Snake*> snakes; // utworzenie wektora, w którym beda przechowywani gracze; dzieki trzymaniu w wektorze krocej bedzie mozna sie odwolywac
                       // do graczy w petlach
vector<Bonus*> bonuses; // utworzenie wektora, w którym beda przechowywane bonusy; dzieki trzymaniu w wektorze krocej bedzie mozna sie odwolywac
                       // do bonusow w petlach

// utworzenie klasy przedstawiajacej macierz (a wlasciwie kostke), gdzie beda trzymane i modyfikowane wartosci zwiazane z graczem, ktory odwiedzil
// dany piksel na planszy oraz w jakim czasie - bedzie ona determinowac przegrana graczy po najechaniu na cudza linie

class Table
{

public:

    Table(){
        time_table = new float[screen_w][screen_h];
        player_table = new float[screen_w][screen_h];
    }

    ~Table(){
        delete time_table;
        delete player_table;
    }

    // wyzerowanie tabel
    void zeros(){
        for(int i=0;i<screen_w;++i){
            for(int j=0;j<screen_h;++j){
                time_table[i][j]=0.0;
                player_table[i][j]=0.0;
            }
        }
    }

    // zmiana wartosci pola w tabeli
    void change(float x, float y, float time, float player){
        time_table[int(x)][int(y)]=time;
        player_table[int(x)][int(y)]= player;
    }

    void showtime(int i, int j){ cout<<time_table[i][j]; } // wyswietlenie czasu z danego pola tabeli
    void showplayer(int i, int j){ cout<<player_table[i][j]; } // wyswietlenie numeru gracza z danego pola tabeli

    float returntime(int i, int j){ return time_table[i][j]; } // pobranie czasu z danego pola tabeli
    float returnplayer(int i, int j){ return player_table[i][j]; } // pobranie numeru gracza z danego pola tabeli

private:

    // utworzenie dwoch dynamicznych tablic o wymiarach korespondujacych z wymiarami planszy przechowujacych numer gracza oraz czas kiedy najechal
    // na konkretne pole - utworzone tablice sa duze, co wymuszalo zaalokowaniu pamieci na stercie
    float (*time_table)[screen_h];
    float (*player_table)[screen_h];

};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                   MAIN
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int, char**)
{

    srand(time(NULL)); // ustawienie generatora

    // inicjalizacje zwiazane z allegro

    if (!al_init() || !al_install_keyboard() || !al_init_image_addon()) {
        cout << "Blad inicjalizacji." << endl;
        return 1;
    }

    // inicjalizacje czcionki

    al_init_font_addon();
    al_init_ttf_addon();

    ALLEGRO_FONT *font = al_load_ttf_font("FreeMono.ttf",50,0 );
    if (!font){
        fprintf(stderr, "Could not load 'FreeMono.ttf'.\n");
        return 3;
    }

    // inicjalizacja ekranu, stopera i kolejki zdarzen

    ALLEGRO_DISPLAY *display = al_create_display(screen_w + 200, screen_h);
    ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

    if (display == NULL || timer == NULL || event_queue == NULL) {
        cout << "Blad inicjalizacji." << endl;
        return 2;
    }

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    // rysowanie ekranu intra
    ALLEGRO_BITMAP  *intro  = NULL;
    ALLEGRO_BITMAP  *intro2  = NULL;
    intro = al_load_bitmap("intro.png");
    intro2 = al_load_bitmap("intro2.png");
    al_draw_bitmap(intro,0,0,0);

    // wyswietlenie ekranu

    al_flip_display();

    // czekanie na klikniecie przycisku 2,3,4 lub krzyzyka w lewym gornym rogu i zapisanie odpowiedzi do zmiennej liczba graczy

    int liczba_graczy;
    bool iter = true;
    while(iter){
        ALLEGRO_EVENT ev1;
        al_wait_for_event(event_queue, &ev1);
        if(ev1.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            return 0;
        }else if(ev1.type == ALLEGRO_EVENT_KEY_DOWN){
            if(ev1.keyboard.keycode==ALLEGRO_KEY_2){
                    liczba_graczy = 2;
                    iter = false;
            }else if(ev1.keyboard.keycode==ALLEGRO_KEY_3){
                    liczba_graczy = 3;
                    iter = false;
            }else if(ev1.keyboard.keycode==ALLEGRO_KEY_4){
                    liczba_graczy = 4;
                    iter = false;
            }
        }
    }

    // wyswietlenie ekranu ze sterowaniem oraz czekanie na klikniecie spacji przez uzytkownika

    al_clear_to_color(al_map_rgb(0,0,0));
    al_draw_bitmap(intro2,0,0,0);
    al_flip_display();

    iter = true;
    while(iter){
        ALLEGRO_EVENT ev2;
        al_wait_for_event(event_queue, &ev2);
        if(ev2.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            return 0;
        }else if(ev2.type == ALLEGRO_EVENT_KEY_DOWN){
            if(ev2.keyboard.keycode==ALLEGRO_KEY_SPACE){ iter = false;}
        }
    }

    // utworzenie wskaznikow na typ Snake oraz zapisanie ich do globalnego wektora snakes

    Snake* gracze[5]; // utworzenie wiekszej tablicy nawet niz maksymalna liczba graczy tak aby numerowac od jedynki

    float vec_x, vec_y; //zmmienne przechowywujace tymczasowo wspolrzedne wektora predkosci

    for(int i = 1; i <= liczba_graczy; ++i){
        gracze[i] = new Snake(i);
        gracze[i] -> setPosition(Vect(rand() % screen_w, rand() % screen_h)); // losowanie pozycji na planszy
        vec_x = float(rand()) / float(RAND_MAX); // losowanie wspolrzednej iksowej wektora predkosci
        vec_y = float(rand()) / float(RAND_MAX); // losowanie wspolrzednej igrekowej wektora predkosci
        //normalizacja wspolrzednych, tak aby wektor mial dlugosc 1
        vec_x = vec_x / pow(pow(vec_x,2)+pow(vec_y,2),0.5);
        vec_y = vec_y / pow(pow(vec_x,2)+pow(vec_y,2),0.5);
        gracze[i] -> setVelocity(Vect(vec_x,vec_y)); // ustawienie predkosci
        snakes.push_back(gracze[i]); // zapisanie w globalnym wektorze
    }

    // sprawdzenie stan zaladowania bitmap

    for (Snake* f: snakes) {
        if (f -> getBitmap() == NULL) {
            cout << "Nie udalo sie zaladowac bitmapy." << endl;
            return 4;
        }
    }

    // utworzenie kostki, gdzie beda zapisywaly sie odwiedzone przez weze pola
    Table tab;
    tab.zeros(); //zerowanie tablicy

    // utworzenie zmiennych wykorzystywanych w glownej petli

    float time = 0.0; // czas
    char* result = new char; // zmienna potrzebna do aktualizacji wyniku na panelu bocznym
    string str; // zmienna potrzebna do aktualizacji wyniku na panelu bocznym
    int number_of_deaths=0; // tymczasowa zmienna przechowujaca liczbe wezy, które do danej chwili przegraly
    float time_bonus2 = 0; // zmienna przechowujaca czas do kiedy aktywowany jest bonus2 (zmiana katow obrotu)
    float time_bonus3 = 0; // zmienna przechowujaca czas do kiedy aktywowany jest bonus3 (zamiana klawiszy)
    float angle_left; // zmienna przechowujaca kat obrotu w lewo
    float angle_right; // zmienna przechowujaca kat obrotu w prawo
    bool answer; // pomocnicza zmienna boolowska

    // utorzenie dwoch tabel reprezentujacych tymczasowe wyniki graczy, ktore aktualizuja sie przez caly czas trwania rundy oraz wyniki globalne
    // aktualizowanie po zakonczeniu kazdej z nich

    int* global_results = new int[liczba_graczy];
    for (int i = 0; i < liczba_graczy; ++i) global_results[i] = 0;
    int* temp_results = new int[liczba_graczy];
    for (int i = 0; i < liczba_graczy; ++i) temp_results[i] = 0;

    // zaladowanie odpowiedniego paska z wynikami (zalezy od liczby graczy wybranej wczesniej) oraz informacji o przejsciu do nastepnej rundy

    ALLEGRO_BITMAP  *image_results  = NULL;
    ALLEGRO_BITMAP  *image_info  = NULL;

    // utworzenie zmiennej filename, ktora bedzie wskaznikiem na typ char z nazwa ladowanego pliku
    stringstream sstm;
    sstm << "panel" << liczba_graczy <<".png";
    string nazwa = sstm.str();
    char* filename = new char[10];
    strcpy(filename,nazwa.c_str());

    // ladowanie plikow i sprawdzenie czy sie powiodlo
    image_results = al_load_bitmap(filename);
    if(!image_results) {
      al_show_native_message_box(display, "Error", "Error", "Failed to load image!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
      return 5;
    }

    image_info = al_load_bitmap("info.png");
    if(!image_info) {
      al_show_native_message_box(display, "Error", "Error", "Failed to load image!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
      return 6;
    }

    // usuniecie z pamieci tymczasowej zmiennej filename
    delete filename;

    // ruszenie timera, zakolorowanie wszystkiego na czarno i wyswietlenie ekranu

    al_clear_to_color(al_map_rgb(0,0,0));
    al_flip_display();
    al_start_timer(timer);

     ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     /////////                                               GLOWNA PETLA PROGRAMU                                                  /////////
     ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    while (true)
    {
        // instrukcje warunkowe dla glownych eventow
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        // event na timerze
        if(ev.type == ALLEGRO_EVENT_TIMER) {

            // sprawdzenie czy jakis waz nie najechal na aktywny bonus
            for (Snake* f: snakes){
                for(Bonus* b: bonuses){
                    if(b->collidesWith(f) && !b->get_used()){
                        if(b->get_type()==1.0){ // niewidzialnosc
                            f->rand_break.inv = true;
                            f->rand_break.time = time + 3;
                            b->set_used(true); // flaga - bonus zuzyty
                            b->change_bitmap(); // zmiana bitmapy bonusa na czarna kule
                        }else if(b->get_type()==2.0){ // inni gracze skrecaja dluzej
                            for (Snake* s: snakes){ // przywrocenie poierwotnych wartosci (oraz ewentualnie dezaktywacja bonusa nr 3)
                                s->set_angle_left(-0.05);
                                s->set_angle_right(0.05);
                            }
                            f->set_bonus2(true); // oflagowanie gracza, ktory jest pod wplywem bonusa
                            time_bonus2 = time + 6.0; // ustawienie czasu do ktorego bonus jest aktywny
                            angle_left = f->get_angle_left();
                            angle_right = f->get_angle_right();
                            for (Snake* s: snakes){ // zmniejszenie kata dla wszystkich pozostalych graczy
                                if(!s->get_bonus2()){
                                    s->set_angle_left(angle_left/4);
                                    s->set_angle_right(angle_right/4);
                                }
                            }
                            b->set_used(true); // flaga - bonus zuzyty
                            b->change_bitmap(); // zmiana bitmapy bonusa na czarna kule
                        }else if(b->get_type()==3.0){ //klawisze skretu innych graczy zamieniaja sie
                            for (Snake* s: snakes){ // przywrocenie poierwotnych wartosci (oraz ewentualnie dezaktywacja bonusa nr 2)
                                s->set_angle_left(-0.05);
                                s->set_angle_right(0.05);
                            }
                            f->set_bonus3(true); // oflagowanie gracza, ktory jest pod wplywem bonusa
                            time_bonus3 = time + 8.0; // ustawienie czasu do ktorego bonus jest aktywny
                            for (Snake* s: snakes){ // zamiana klawiszy dla wszystkich pozostalych graczy
                                if(!s->get_bonus3()){
                                    angle_left = s->get_angle_left();
                                    s->set_angle_left(s->get_angle_right());
                                    s->set_angle_right(angle_left);
                                }
                            }
                            b->set_used(true); // flaga - bonus zuzyty
                            b->change_bitmap(); // zmiana bitmapy bonusa na czarna kule
                        }
                    }
                }
            }

            // Sprawdzenie czy nie trzeba zdezaktywowac ktoregos z bonusow

            // popatrzenie czy ktorykolwiek z wezy jest pod wplywem bonusa nr 2
            answer = false;
            for (Snake* f: snakes){
                if(f->get_bonus2()) answer = true;
            }

            // jesli tak i jest spelniony warunek zwiazany z czasem bonus jest stopowany
            if(answer && time > time_bonus2){
                for (Snake* f: snakes){
                    if(f->get_bonus2()) f->set_bonus2(false);
                    if(!f->get_bonus2()){
                            f->set_angle_left(-0.05);
                            f->set_angle_right(0.05);
                    }
                }
            }

            // popatrzenie czy ktorykolwiek z wezy jest pod wplywem bonusa nr 3
            answer = false;
            for (Snake* f: snakes){
                if(f->get_bonus3()) answer = true;
            }

            // jesli tak i jest spelniony warunek zwiazany z czasem bonus jest stopowany
            if(answer && time > time_bonus3){
                for (Snake* f: snakes){
                    if(f->get_bonus3()) f->set_bonus3(false);
                    if(!f->get_bonus3()){
                            angle_left = f->get_angle_left();
                            f->set_angle_left(f->get_angle_right());
                            f->set_angle_right(angle_left);
                    }
                }
            }

            for (Snake* f: snakes){ f -> move(1.0 / FPS); } // przesuniecie wezy
            time = time + 1.0 / FPS; // aktualizacja czasu

            for (Snake* f: snakes) f->randomize_break(0.005, time, 10.0 / FPS); // losowanie czy waz ma przejsc w stan "przerwy" oraz sprawdzenie
                                                                                 // czy nie powinien z powrotem rysowac

            // sprawdzenie czy waz nie najechal na krawedzie planszy, innego weza albo samego siebie
            // jesli najechal: zatrzymuje sie on i zmienna boolowska stop charakteryzujaca weza zmieniana jest na true
            // jesli nie najechal: nic sie nie dzieje poza zmiana odpowiednich wartosci w kostce tab (zwiazanej z tym ze dany
            // waz wjechal na wolne pole)

            for (Snake* f: snakes){

                // sprawdzenie czy waz najechal na krawedz planszy
                // poniewaz pozycja weza na planszy moze byc opisywane wektorem skladajacym sie z liczb po przecinku, zas krawedzie planszy
                // sa okreslone przez typ int, uzywane sa zmienne ceil (sufit) i floor (podloga)

                if(ceil(f->getPosition().getX()) == 0 || ceil(f->getPosition().getX()) == screen_w || ceil(f->getPosition().getY()) == 0 ||
                ceil(f->getPosition().getY()) == screen_h || floor(f->getPosition().getX()) == 0 ||
                floor(f->getPosition().getX()) == screen_w || floor(f->getPosition().getY()) == 0 ||
                floor(f->getPosition().getY()) == screen_h){
                    f->setVelocity(Vect(0.0,0.0));
                    f->set_stop();
                }

                // sprawdzenie czy waz najechal na siebie lub na innego weza; jelsi nie dokonywana jest zmiana kostki tab
                // punktem wyjscia jest sprawdzenie czy waz nie jest w stanie "przerwy" - jesli tak nic sie nie dzieje

                if(!f->rand_break.inv){

                    if(tab.returntime(f->getPosition().getX(),f->getPosition().getY())!=0){

                        if(tab.returnplayer(f->getPosition().getX(),f->getPosition().getY()) != f->getNumber() ||
                           time-1>tab.returntime(f->getPosition().getX(),f->getPosition().getY())){
                            f->setVelocity(Vect(0.0,0.0));
                            f->set_stop();
                        }

                    }

                    tab.change(f->getPosition().getX(),f->getPosition().getY(),time,f->getNumber());

                }
            }

        // event na przycisku "zamknij"

        } else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            return 0;

        // event na klawiaturze 1
        // zmiana wektora predkosci pod wplywem nacisniecia przycisku lewo/prawo

        } else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
             switch(ev.keyboard.keycode) {
                 case ALLEGRO_KEY_LEFT:
                    snakes[0] -> turnLeft(true);
                    break;
                 case ALLEGRO_KEY_RIGHT:
                    snakes[0] -> turnRight(true);
                    break;
                 case ALLEGRO_KEY_A:
                    snakes[1] -> turnLeft(true);
                    break;
                 case ALLEGRO_KEY_D:
                    snakes[1] -> turnRight(true);
                    break;
                 case ALLEGRO_KEY_B:
                    snakes[2] -> turnLeft(true);
                    break;
                 case ALLEGRO_KEY_M:
                    snakes[2] -> turnRight(true);
                    break;
                 case ALLEGRO_KEY_PAD_4:
                    snakes[3] -> turnLeft(true);
                    break;
                 case ALLEGRO_KEY_PAD_6:
                    snakes[3] -> turnRight(true);
                    break;
            }

        // event na klawiaturze 2
        // zastopowanie zmiany wektora predkosci pod wplywem zwolnienia przycisku lewo/prawo

        } else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
             switch(ev.keyboard.keycode) {
                 case ALLEGRO_KEY_LEFT:
                    snakes[0] -> turnLeft(false);
                    break;
                 case ALLEGRO_KEY_RIGHT:
                    snakes[0] -> turnRight(false);
                    break;
                 case ALLEGRO_KEY_A:
                    snakes[1] -> turnLeft(false);
                    break;
                 case ALLEGRO_KEY_D:
                    snakes[1] -> turnRight(false);
                    break;
                 case ALLEGRO_KEY_B:
                    snakes[2] -> turnLeft(false);
                    break;
                 case ALLEGRO_KEY_M:
                    snakes[2] -> turnRight(false);
                    break;
                 case ALLEGRO_KEY_PAD_4:
                    snakes[3] -> turnLeft(false);
                    break;
                 case ALLEGRO_KEY_PAD_6:
                    snakes[3] -> turnRight(false);
                    break;
            }
        }

        for (Snake* f: snakes) if(f ->getVelocity().compare(Vect(0.0,0.0))) number_of_deaths++; // zliczenie liczby wezy przegrywajacych w danej
                                                                                                 // rundzie

        // zmiana odpowiednich elementow tablicy z tymczasowymi wynikami w obecnej rundzie

        for (Snake* f: snakes) if(temp_results[int(f->getNumber()-1)]==0 && (f->get_stop())) temp_results[int(f->getNumber()-1)] = number_of_deaths;

        // instrukcje determinujace stan gry gdy wszyscy przegrali (nie ruszaja sie) albo rusza sie tylko jeden waz

        if(number_of_deaths>=liczba_graczy-1){

            // uzupelnienie tabeli tem_results w odpowiednim miejscu o wynik weza ktory pozostal w rozgrywce (jeszcze sie rusza)

            if(number_of_deaths==liczba_graczy-1){
                for (Snake* f: snakes) {
                    if(!(f->get_stop())) temp_results[int(f->getNumber()-1)] = liczba_graczy;
                }
            }

            // event po nacisnieciu spacji

            if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {

                if(ev.keyboard.keycode==ALLEGRO_KEY_SPACE){

                    // aktualizacja wynikow w tablicy global_results
                    for(int i = 0; i < liczba_graczy; ++i){
                        global_results[i] += temp_results[i];
                        temp_results[i] = 0;
                    }

                    // wyczyszczenie planszy i wyzerowanie kostki tab
                    al_clear_to_color(al_map_rgb(0,0,0));
                    tab.zeros();

                    // wyloswanie nowych miejsc i predkosci dla graczy
                    // wyczyszczenie informacji o aktualnych bonusach
                    for(int i = 1; i <= liczba_graczy; ++i){
                        gracze[i] -> setPosition(Vect(rand() % screen_w, rand() % screen_h));
                        gracze[i] -> set_go();
                        vec_x = float(rand()) / float(RAND_MAX);
                        vec_y = float(rand()) / float(RAND_MAX);
                        vec_x = vec_x / pow(pow(vec_x,2)+pow(vec_y,2),0.5)*1.0;
                        vec_y = vec_y / pow(pow(vec_x,2)+pow(vec_y,2),0.5)*1.0;
                        gracze[i] -> setVelocity(Vect(vec_x,vec_y));
                        gracze[i] -> set_angle_left(-0.05);
                        gracze[i] -> set_angle_right(0.05);
                        gracze[i] -> set_bonus2(false);
                        gracze[i] -> set_bonus3(false);
                        gracze[i] -> rand_break.inv = false;
                        gracze[i] -> rand_break.time = 0.0;
                    }

                    // wyczyszczenie bonusow
                    bonuses.clear();

                }

            }

        }

        // narysowanie panelu bocznego z wynikami oraz informacji o przejsciu do nastepnej rundy o ile zostal co najwyzej jeden gracz
        al_draw_bitmap(image_results,screen_w,0,0);
        if(number_of_deaths>=liczba_graczy-1) al_draw_bitmap(image_info, screen_w + 3, 450, 0);

        // wyzerowanie zmiennej zliczajacej przegrane weze
        number_of_deaths=0;

        // losowanie pojawienia sie nowego bonusa
        if(float(rand())/float(RAND_MAX) < 0.002){
            Bonus *b = new Bonus(float(rand()%3 + 1));
            b -> setPosition(Vect(rand() % screen_w, rand() % screen_h)); // losowanie pozycji na planszy
            b -> setVelocity(Vect(0,0)); // wyzerowanie predkosci, tak aby sie nie ruszal
            bonuses.push_back(b);
        }

        // dorysowanie przesunietych pozycji wezy (lub poczatkowych pozycji wezy w przypadku rozpoczecia nowej tury) pod warunkiem, ze nie sa one
        // w stanie przerwy
        for (Snake* f: snakes) {
            if(!f->rand_break.inv) al_draw_rotated_bitmap(f -> getBitmap(),
                                   al_get_bitmap_width(f -> getBitmap()) / 2,
                                   al_get_bitmap_height(f -> getBitmap()) / 2,
                                   f -> getPosition().getX(),
                                   f -> getPosition().getY(),
                                   0,
                                   0);
        }

        // narysowanie bonusow
        for (Bonus* b: bonuses) {
            if(!b->get_used()){ // tu rysowane sa bonusy jesli sa aktywne
                al_draw_rotated_bitmap(b -> getBitmap(),
                                       al_get_bitmap_width(b -> getBitmap()) / 2,
                                       al_get_bitmap_height(b -> getBitmap()) / 2,
                                       b -> getPosition().getX(),
                                       b -> getPosition().getY(),
                                       0,
                                       0);
            }
            if(b->get_used() && !b->get_black()){ //tu rysowane sa bonusy, ktore przed momentem sie aktywowaly zas zmienna black w klasie bonus
                                                  // uniemozliwia ponowne narysowanie czarnej kuli dzieki czemu otrzymujemy fajny efekt wizualny
                al_draw_rotated_bitmap(b -> getBitmap(),
                                       al_get_bitmap_width(b -> getBitmap()) / 2,
                                       al_get_bitmap_height(b -> getBitmap()) / 2,
                                       b -> getPosition().getX(),
                                       b -> getPosition().getY(),
                                       0,
                                       0);
                b->set_black();
            }
        }

        // wyswietlenie aktualnych wynikow
        for(int i = 1; i<=liczba_graczy; ++i){
                str = to_string(global_results[i-1]);
                strcpy(result,str.c_str());
                al_draw_text(font, al_map_rgb(0,0,0), screen_w + 120, 50 + (i-1) * 58, ALLEGRO_ALIGN_LEFT, result);
        }

        // wyswietlenie ekranu
        al_flip_display();

    }

    //usuniecie wczesniej utworzonych na stercie zmiennych

    delete gracze[5];
    delete result;
    delete global_results;
    delete temp_results;

    return 0;

}
