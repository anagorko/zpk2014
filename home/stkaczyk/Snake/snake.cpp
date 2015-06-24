#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<cstdlib>
#include<fstream>
using namespace std;

#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

const int screen_w = 800;
const int screen_h = 600;
const float FPS = 4;

struct wynik {  //Trzyma highscores
    int punkty;
    string imie;
};

const int n = 10;

wynik wyniki[n]; //tablica najlepszych wynikow

string imie_gracza;  //imie aktualnie grajacego

void czytaj_wyniki() //czyta wyniki z pliku (lub wczytuje domyslne w przypadku braku pliku)
{
    string dane;
    fstream plik;
    plik.open("wyniki.txt", ios::in);

    if(!plik.good()){
        wyniki[0].punkty = 100;
        wyniki[0].imie = "MK";
        wyniki[1].punkty = 90;
        wyniki[1].imie = "EC";
        wyniki[2].punkty = 80;
        wyniki[2].imie = "BS";
        wyniki[3].punkty = 70;
        wyniki[3].imie = "BD";
        wyniki[4].punkty = 60;
        wyniki[4].imie = "RJD";
        wyniki[5].punkty = 50;
        wyniki[5].imie = "JBJ";
        wyniki[6].punkty = 40;
        wyniki[6].imie = "LU";
        wyniki[7].punkty = 3;
        wyniki[7].imie = "JH";
        wyniki[8].punkty = 2;
        wyniki[8].imie = "PT";
        wyniki[9].punkty = 1;
        wyniki[9].imie = "FM";
    }
    else {
        for(int i=0; i<n; i++){
            getline(plik, dane);
            wyniki[i].imie = dane;
            getline(plik, dane);
            wyniki[i].punkty = atoi(dane.c_str());
        }
    }
    plik.close();
}

void czytaj_imie() //czyta imie gracza z pliku (lub wczytuje domyslne w przypadku braku pliku)
{
    string dane;
    fstream plik;
    plik.open("imie.txt", ios::in);

    if(!plik.good()){
        imie_gracza = "PLAYER2";
    }
    else {
        getline(plik, dane);
        imie_gracza = dane;
    }

    plik.close();
}

void zapisz_wyniki() //zapisuje do pliku
{
    fstream plik;
    plik.open("wyniki.txt", ios::out);

    for(int i=0; i<n; i++){
        plik << wyniki[i].imie << endl << wyniki[i].punkty << endl;
    }
    plik.close();
}

void wypisz_wyniki() //wypisuje wyniki na ekranie
{
    const int x = 125;
    const int y = 150;
    const int czcionka = 36;
    ALLEGRO_FONT *font = al_load_ttf_font("pixelart.ttf",czcionka,0 );
    for (int i = 0; i < n; i++) {
        al_draw_textf(font, al_map_rgb(0,0,0), x, (y + czcionka*i),ALLEGRO_ALIGN_CENTRE, "%d", i+1);
        al_draw_text(font, al_map_rgb(0,0,0), x + 60, (y + czcionka*i),ALLEGRO_ALIGN_LEFT, wyniki[i].imie.c_str());
        al_draw_textf(font, al_map_rgb(0,0,0), x + 525, (y + czcionka*i),ALLEGRO_ALIGN_CENTRE, "%d", wyniki[i].punkty);
    }
}

void dodaj_wynik(wynik w) //dodaje wynik i sortuje
{
    int i;

    for (i = 0; i < n; i++) {
        if (w.punkty > wyniki[i].punkty) {
            break;
        }
    }

    if (i == n) return;

    for (int j = n-1; j > i; j--) {
        wyniki[j] = wyniki[j-1];
    }

    wyniki[i] = w;
}

void rysuj_menu() //rysuje menu glowne
{
    ALLEGRO_FONT *font24 = al_load_ttf_font("pixelart.ttf",24,0 );
    ALLEGRO_BITMAP *menu = al_load_bitmap("grafika/snake_menu.png");

    al_clear_to_color(al_map_rgb(255,255,255));
    al_draw_bitmap(menu,0,0,0);
    al_draw_text(font24, al_map_rgb(0,0,0), 400, 482,ALLEGRO_ALIGN_CENTRE, "YOUR CURRENT NAME IS");
    al_draw_text(font24, al_map_rgb(0,0,0), 400, 510,ALLEGRO_ALIGN_CENTRE, imie_gracza.c_str());
    al_draw_text(font24, al_map_rgb(0,0,0), 400, 536,ALLEGRO_ALIGN_CENTRE, "MODIFY FILE IMIE.TXT IN GAME DIRECTORY AND PRESS R");
    al_draw_text(font24, al_map_rgb(0,0,0), 400, 562,ALLEGRO_ALIGN_CENTRE, "IN ORDER TO CHANGE YOUR NAME");
    al_flip_display();
}

void rysuj_highscores() //rysuje menu highscores
{
    ALLEGRO_FONT *font24 = al_load_ttf_font("pixelart.ttf",24,0 );
    ALLEGRO_BITMAP *menu_wyniki = al_load_bitmap("grafika/highscores.png");
    al_clear_to_color(al_map_rgb(255,255,255));
    al_draw_bitmap(menu_wyniki,0,0,0);
    wypisz_wyniki();
    al_draw_text(font24, al_map_rgb(0,0,0), 320, 570,ALLEGRO_ALIGN_LEFT, "PRESS BACKSPACE FOR MAIN MENU");
    al_flip_display();
}

void rysuj_game_over() //rysuje ekran game over
{
    ALLEGRO_FONT *font48 = al_load_ttf_font("pixelart.ttf",48,0 );
    ALLEGRO_FONT *font24 = al_load_ttf_font("pixelart.ttf",24,0 );
    al_clear_to_color(al_map_rgb(255,255,255));
    al_draw_text(font48, al_map_rgb(0,0,0), 400, 100,ALLEGRO_ALIGN_CENTRE, "GAME OVER");
    al_draw_text(font48, al_map_rgb(0,0,0), 400, 200,ALLEGRO_ALIGN_CENTRE, "YOUR SCORE");
    al_draw_text(font24, al_map_rgb(0,0,0), 400, 500,ALLEGRO_ALIGN_CENTRE, "PRESS ENTER FOR HIGHSCORES OR");
    al_draw_text(font24, al_map_rgb(0,0,0), 400, 530,ALLEGRO_ALIGN_CENTRE, "BACKSPACE FOR MAIN MENU");
    al_flip_display();
}

void rysuj_tryb() //rysuje ekran wyboru trybu gry
{
    ALLEGRO_FONT *font72 = al_load_ttf_font("pixelart.ttf",72,0 );
    ALLEGRO_FONT *font24 = al_load_ttf_font("pixelart.ttf",24,0 );
    ALLEGRO_BITMAP *tryb = al_load_bitmap("grafika/tryb_menu.png");
    al_draw_bitmap(tryb,0,0,0);
    al_draw_text(font24, al_map_rgb(0,0,0), 320, 570,ALLEGRO_ALIGN_LEFT, "PRESS BACKSPACE FOR MAIN MENU");
    al_draw_text(font72, al_map_rgb(0,0,0), 400, 0,ALLEGRO_ALIGN_CENTRE, "CHOOSE GAME MODE");
    al_flip_display();
}


class ElementKolejki
{
    virtual ostream& output(ostream&) const = 0;

public:
    virtual ~ElementKolejki() = 0;

    friend ostream& operator<<(ostream& os, ElementKolejki& el);
    virtual bool czy_rowne(ElementKolejki& inny_punkt) = 0;
};

ElementKolejki::~ElementKolejki() {}

ostream& operator<<(ostream& os, ElementKolejki& el)
{
    el.output(os);
    return os;
}

class Punkt : public ElementKolejki  //Pole na planszy
{
    int x;
    int y;

    virtual ostream& output(ostream& os) const {
        return os << "(" <<  x << "," << y << ")";
    }

public:

    Punkt() : Punkt(0, 0) {
    }
    Punkt(int _x, int _y) {
        x = _x; y = _y;
    }

    ~Punkt() {}

    int getX() { return x; }
    int getY() { return y; }

    bool czy_rowne(ElementKolejki& inny_punkt){
        Punkt* inny = (Punkt*)&inny_punkt;
        return x==inny->x && y==inny->y;
    }
};

class Kolejka
{
    struct Link
    {
        ElementKolejki    *dane;
        Link            *nastepny;
    };

    Link* pierwszy;
    Link* ostatni;
    int dlugosc;

public:
    Kolejka() {
        pierwszy = NULL;
        ostatni = NULL;
        dlugosc = 0;
    }

    ~Kolejka() {
        while (pierwszy != NULL) {
            delete pop();
        }
    }

    void push(ElementKolejki* el) {
        Link *nowy = new Link;

        nowy -> nastepny = NULL;
        nowy -> dane = el;

        if(dlugosc == 0) {
            pierwszy = nowy;
            ostatni = nowy;
        }
        else {
            ostatni -> nastepny = nowy;
            ostatni = nowy;
        }
        dlugosc += 1;
    }

    ElementKolejki* pop() {
        if (dlugosc == 0) return NULL;

        ElementKolejki *wynik = pierwszy -> dane;
        Link* nastepny = pierwszy -> nastepny;
        delete pierwszy;
        pierwszy = nastepny;

        if(dlugosc == 1){
            ostatni = NULL;
        }

        dlugosc -= 1;

        return wynik;
    }
    bool empty()
    {
        if(dlugosc == 0)
            return true;
        else
            return false;
    };

    int size()  //zwraca dlugosc kolejki
    {
        return dlugosc;
    }

    Link* get_ostatni(){  //zwraca ostatni element kolejki
        return ostatni;
    }

    bool czy_zawiera(ElementKolejki *p){  //sprawdza, czy dany punkt nalezy do kolejki
        Link *aktualny = pierwszy;
        while(aktualny != NULL){
            if((aktualny -> dane)->czy_rowne(*p)){
                return true;
            }
            aktualny = aktualny -> nastepny;
        }
        return false;
    }

    int ile_zawiera(ElementKolejki *p){  //sprawdza, ile razy dany punkt wystepuje w kolejce (potrzebne do sprawdzania zapetlenia weza)
        int licznik = 0;
        Link *aktualny = pierwszy;
        while(aktualny != NULL){
            if((aktualny -> dane)->czy_rowne(*p)){
                licznik++;
            }
            aktualny = aktualny -> nastepny;
        }
        return licznik;
    }

    friend ostream& operator<<(ostream&, Kolejka &);
};

ostream& operator<<(ostream& os, Kolejka &s) {
    os << "[";

    Kolejka::Link *el = s.pierwszy;
    while (el != NULL) {
        os << *(el->dane);
        el = el -> nastepny;
        if (el != NULL) { cout << ", "; }
    }

    os << "]";
    return os;
}

class Waz
{
    Kolejka pola; //Kolejne pola zajmowane przez weza na planszy
    int kierunek; //Samoczynny ruch weza: 1 - prawo, -1 - lewo, -2 - dół, 2 - góra

public:
    Waz() {
        kierunek = 1;
        for(int i=0; i<6; i++){
            pola.push(new Punkt(i+10,10));
        }
    }

    void zmien_kierunek(int _kierunek){ //Zmienia kierunek weza
        if(kierunek + _kierunek != 0 && kierunek != _kierunek){
            kierunek = _kierunek;
        }
    };

    void ruch_glowy(bool tryb_bez_scian, int wymiar_x, int wymiar_y){     //Przesuniecie glowy weza wg aktualnego kierunku.
        Punkt p = glowa();                                                //W trybie ze scianami glowa moze sie znalezc poza plansza.
        if(tryb_bez_scian){                                               //W trybie bez scian glowa moze sie znalezc po przeciwnej stronie planszy.
            if(kierunek == 1){
                pola.push(new Punkt((p.getX() + 1) % wymiar_x, p.getY()));
            }
            else if(kierunek == -1){
                pola.push(new Punkt((p.getX() - 1 + wymiar_x) % wymiar_x, p.getY()));
            }
            else if(kierunek == 2) {
                pola.push(new Punkt(p.getX(), (p.getY() - 1 + wymiar_y) % wymiar_y));
            }
            else if(kierunek == -2) {
                pola.push(new Punkt(p.getX(), (p.getY() + 1) % wymiar_y));
            }
        }
        else {
            if(kierunek == 1){
                pola.push(new Punkt(p.getX() + 1, p.getY()));
            }
            else if(kierunek == -1){
                pola.push(new Punkt(p.getX() - 1, p.getY()));
            }
            else if(kierunek == 2) {
                pola.push(new Punkt(p.getX(), p.getY() - 1));
            }
            else if(kierunek == -2) {
                pola.push(new Punkt(p.getX(), p.getY() + 1));
            }
        }
    }

    void skroc(){  //usuniecie ostatniego pola weza
        pola.pop();
    }

    Punkt glowa(){   //zwraca pole zajmowane przez glowe weza
        return *static_cast<Punkt*>(pola.get_ostatni()->dane);
    }
    bool czy_nalezy(Punkt p){  //sprawdza czy na polu jest waz
        return pola.czy_zawiera(&p);
    }

    bool czy_zapetlony(){ // 1 jesli waz wszedl sam w siebie
        Punkt p = glowa();
        return (pola.ile_zawiera(&p) > 1);
    }

    int dlugosc(){  //zwraca dlugosc weza
        return pola.size();
    };
};

class Plansza
{
    const int wymiar_x = 39;
    const int wymiar_y = 29;
    int wynik = 0; //Liczba zjedzonych jablek

    Waz waz;

    Punkt jablko;

    bool tryb_bez_scian;

public:

    Plansza(bool tryb){
        tryb_bez_scian = tryb;
        nowe_jablko();
    }

    void wyswietl(){  //Wyswietla aktualny stan planszy na ekranie
        const int przesuniecie = 10;
        const int mnoznik = 20;
        al_init_primitives_addon();
        al_draw_filled_rectangle(10, 10, 790, 590,al_map_rgba(54,107,54, 255));
        for(int i=0; i<wymiar_x; i++){
            for(int j=0; j< wymiar_y; j++){
                Punkt p(i,j);
                if(waz.czy_nalezy(p)){
                    al_draw_filled_rectangle(i*mnoznik + przesuniecie, j*mnoznik + przesuniecie, (i+1)*mnoznik + przesuniecie, (j+1)*mnoznik + przesuniecie,al_map_rgba(0,0,0, 255));
                    al_draw_rectangle(i*mnoznik + przesuniecie, j*mnoznik + przesuniecie, (i+1)*mnoznik + przesuniecie, (j+1)*mnoznik + przesuniecie,al_map_rgba(255,255,0, 255), 1);
                }
                if(p.czy_rowne(jablko)){
                    al_draw_filled_rectangle(i*mnoznik + przesuniecie, j*mnoznik + przesuniecie, (i+1)*mnoznik + przesuniecie, (j+1)*mnoznik + przesuniecie,al_map_rgba(255,0,0, 255));
                }
            }
        }
        if(!tryb_bez_scian){
            al_draw_rectangle(5, 5, 795, 595,al_map_rgba(0,0,0, 255), 7);
        }


    }
    void zmien_kierunek(int _kierunek){  //Zmienia kierunek weza
        waz.zmien_kierunek(_kierunek);
    }

    void ruch_weza(){ //Przesuwa weza
        waz.ruch_glowy(tryb_bez_scian, wymiar_x, wymiar_y);
//        cout << "(" << waz.glowa().getX() << ", " << waz.glowa().getY() << ")" << endl;
        if(waz.glowa().czy_rowne(jablko)){
            nowe_jablko();
            wynik++;
        }
        else {
            waz.skroc();
        }
    }

    bool czy_kolizja(){  //Sprawdza czy wystapila kolizja
        if(waz.czy_zapetlony()){
            return true;
        }
        else{
            if(tryb_bez_scian){
                return false;
            }
            else{
                if(waz.glowa().getX() >= wymiar_x || waz.glowa().getY() >= wymiar_y || waz.glowa().getX() < 0 || waz.glowa().getY() < 0){
                    return true;
                }
            }
        }
    }

    void nowe_jablko(){ //Generuje nowe jablko
        srand(time(NULL));
        int pozycja = (rand() * 99) % (wymiar_x*wymiar_y - waz.dlugosc());
        for(int i=0; i<wymiar_x; i++){
            for(int j=0; j< wymiar_y; j++){
                Punkt p(i,j);
                if(!waz.czy_nalezy(p)){
                    if(pozycja == 0){
                        jablko = p;
                    }
                    pozycja--;
                }
            }
        }
    }

    int get_wynik(){  //zwraca wynik (liczbe zjedzonych jablek)
        return wynik;
    }
};

int main(int, char**)
{
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

    al_init_font_addon();
    al_init_ttf_addon();
    ALLEGRO_FONT *font48 = al_load_ttf_font("pixelart.ttf",48,0 );

    czytaj_wyniki();
    czytaj_imie();
    Plansza *gra;

    rysuj_menu();

    int poziom_menu = 1; //1 - menu glowne, 2 - tryb, 3 -  highscores, 4 - gra, 5 - game over
    bool lista; //czy zakfalifikowany do highscores?

    while (true)
    {
        // process events
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }

        else if(ev.keyboard.keycode == ALLEGRO_KEY_Q) {
            break;
        }
        //obsluga menu
        if (poziom_menu == 1){

            if(ev.keyboard.keycode == ALLEGRO_KEY_R) {
                czytaj_imie();
                rysuj_menu();
            }
            else if(ev.keyboard.keycode == ALLEGRO_KEY_S) {
                rysuj_tryb();
                poziom_menu = 2;
            }
            else if(ev.keyboard.keycode == ALLEGRO_KEY_H) {
                rysuj_highscores();
                poziom_menu = 3;
            }
        }
        if (poziom_menu == 2){
            if(ev.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
                al_clear_to_color(al_map_rgb(255,255,255));
                gra = new Plansza(1);
                al_flip_display();
                poziom_menu = 4;
            }
            else if(ev.keyboard.keycode == ALLEGRO_KEY_LEFT) {
                al_clear_to_color(al_map_rgb(255,255,255));
                gra = new Plansza(0);
                al_flip_display();
                poziom_menu = 4;
            }
        }
        if (poziom_menu == 2 || poziom_menu == 3 || poziom_menu == 4 || poziom_menu == 5){
            if(ev.keyboard.keycode == ALLEGRO_KEY_BACKSPACE) {
                rysuj_menu();
                poziom_menu = 1;
                gra = new Plansza(1);
            }
        }
        if(poziom_menu == 4){
            al_start_timer(timer);
            al_clear_to_color(al_map_rgb(255,255,255));
            gra->wyswietl();
            al_flip_display();

            if(ev.type == ALLEGRO_EVENT_TIMER){
                gra->ruch_weza();
                gra->wyswietl();
                al_flip_display();
            }

            switch(ev.keyboard.keycode){

                case ALLEGRO_KEY_LEFT:
                    gra->zmien_kierunek(-1);
                    break;
                case ALLEGRO_KEY_RIGHT:
                    gra->zmien_kierunek(1);
                    break;
                case ALLEGRO_KEY_UP:
                    gra->zmien_kierunek(2);
                    break;
                case ALLEGRO_KEY_DOWN:
                    gra->zmien_kierunek(-2);
                    break;
            }

            if(gra->czy_kolizja()){
                rysuj_game_over();
                al_draw_textf(font48, al_map_rgb(0,0,0), 400, 250,ALLEGRO_ALIGN_CENTRE, "%d", gra->get_wynik());
                if(gra->get_wynik() > wyniki[9].punkty){
                    al_draw_text(font48, al_map_rgb(0,0,0), 400, 400,ALLEGRO_ALIGN_CENTRE, "HIGHSCORE! CONGRATS!");
                    lista = 1;
                }
                al_flip_display();
                poziom_menu = 5;
                al_stop_timer(timer);
            }
        }
        if(poziom_menu == 5){
            delete gra;
            if(lista){
                czytaj_wyniki();
                wynik nowy;
                nowy.imie = imie_gracza;
                nowy.punkty = gra->get_wynik();
                dodaj_wynik(nowy);
                zapisz_wyniki();
                lista = 0;
            }
            if(ev.keyboard.keycode == ALLEGRO_KEY_ENTER) {
                rysuj_highscores();
                poziom_menu = 3;
            }
        }
    }
    return 0;
}
