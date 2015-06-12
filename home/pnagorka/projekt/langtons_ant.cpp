#include <iostream>
#include <vector>
#include <math.h>
#include <random>

using namespace std;

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

const double PI = 2 * acos(0.0);
const int Ekran_X = 600;    // tymczasowo wartosc stala
const int Ekran_Y = 600;     // tymczasowo wartosc stala
const int Ruch = 30;         // tymczasowo wartosc stala     MUSI TO BYC DZIELNIK Ekran_X !!!
const float Przeskalowanie = 0.0125 * Ruch;

class Tlo
{
protected:
    unsigned short Wartosc_R, Wartosc_G, Wartosc_B;

public:
    unsigned short podajWartoscR() const { return Wartosc_R; }
    unsigned short podajWartoscG() const { return Wartosc_G; }
    unsigned short podajWartoscB() const { return Wartosc_B; }
};

class Kierunkowzkaz
{
protected:
    unsigned short Kierunek;

public:
    unsigned short podajKierunek() const { return Kierunek; }
};

class Plansza : public Tlo
{
public:

    Plansza()
    {
        Wartosc_R = 205;
        Wartosc_G = 205;
        Wartosc_B = 205;
    }

    unsigned int Tablica_Planszy[Ekran_X / Ruch][Ekran_Y / Ruch] = {};
};

class Kolor : public Tlo, public Kierunkowzkaz
{
public:

    Kolor(unsigned short r, unsigned short g, unsigned short b, unsigned short direction)
    {
        Wartosc_R = r;
        Wartosc_G = g;
        Wartosc_B = b;
        Kierunek = direction;
    }
};

class Mrowka : public Kierunkowzkaz
{
    ALLEGRO_BITMAP* Obraz;
    int Pozycja_X, Pozycja_Y;
    float Kat;

public:

    // Lewy gorny rog czesci ciala mrowki
    Mrowka(): Mrowka((Ekran_X - Ekran_X % (Ruch * 2)) / 2, (Ekran_Y - Ekran_Y % (Ruch * 2)) / 2, 4) {}

    Mrowka(int x, int y, unsigned short direction)
    {
        Obraz = al_load_bitmap("mrowka.png");
        ustawX(x);
        ustawY(y);
        ustawKierunek(direction);
    }

    void ustawX(int x) { Pozycja_X = x; }
    void ustawY(int y) { Pozycja_Y = y; }
    int podajX() const { return Pozycja_X; }
    int podajY() const { return Pozycja_Y; }

    void ustawKierunek(unsigned short direction)
    {
        Kierunek = direction;
        ustawKat(direction * PI / 2);
    }

    float podajKat() const     { return Kat; }
    void ustawKat(float angle) { Kat = angle; }

    virtual void Poruszanie()
    {
        switch(Kierunek)
        {
            case 1:
                if (podajX() + Ruch < Ekran_X)
                    ustawX(podajX() + Ruch);
                else
                    ustawX(0);
                break;
            case 2:
                if (podajY() + Ruch < Ekran_Y)
                    ustawY(podajY() + Ruch);
                else
                    ustawY(0);
                break;
            case 3:
                if (podajX() - Ruch >= 0)
                    ustawX(podajX() - Ruch);
                else
                    ustawX(Ekran_X - Ruch);
                break;
            case 4:
                if (podajY() - Ruch >= 0)
                    ustawY(podajY() - Ruch);
                else
                    ustawY(Ekran_Y - Ruch);
                break;
        }
    }

    virtual ALLEGRO_BITMAP* getBitmap() const { return Obraz; }
};

vector<Kolor*> Paleta_Kolorow;

void Stworz_Regule_Koloru(unsigned short r, unsigned short g, unsigned short b, unsigned short direction)
{
    Kolor *k = new Kolor(r, g, b, direction);
    Paleta_Kolorow.push_back(k);
}


int main(int, char**)
{
    if (!al_init() || !al_install_keyboard() || !al_init_image_addon())
    {
        cout << "Initialization error!" << endl;
        return 1;
    }

    float IteracjiNaSekunde = 1.0;
    unsigned long Iteracja = 1;
    bool CzyPauza = false;
    int WymiarX, WymiarY;

    ALLEGRO_DISPLAY *Wyswietl_Ekran = al_create_display(Ekran_X, Ekran_Y);
    ALLEGRO_TIMER *Czas = al_create_timer(1 / IteracjiNaSekunde);
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

    if (Wyswietl_Ekran == NULL || Czas == NULL || event_queue == NULL)
    {
        cout << "Initialization error!" << endl;
        return 2;
    }

    al_register_event_source(event_queue, al_get_display_event_source(Wyswietl_Ekran));
    al_register_event_source(event_queue, al_get_timer_event_source(Czas));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_init_font_addon();
    al_init_ttf_addon();
    //ALLEGRO_FONT *Czcionka = al_load_font("arial.ttf", 12, 0);

    al_start_timer(Czas);

    Plansza *P = new Plansza();
    Mrowka *M = new Mrowka();

    // Wersja podstawowa:
    /*Stworz_Regule_Koloru(255, 255, 255, 1);
    Stworz_Regule_Koloru(255, 0, 0, 3);*/

    // Wersja calkiem ciekawa (odkryta przypadkowo):
    /*Stworz_Regule_Koloru(53, 233, 138, 2);
    Stworz_Regule_Koloru(208, 32, 182, 2);
    Stworz_Regule_Koloru(239, 202, 171, 3);
    Stworz_Regule_Koloru(19, 212, 243, 3);
    Stworz_Regule_Koloru(67, 5, 40, 3);*/

    // Wersja calkiem abstrakcyjna:
    /*Stworz_Regule_Koloru(255, 255, 255, 1);
    Stworz_Regule_Koloru(255, 0, 0, 2);
    Stworz_Regule_Koloru(0, 255, 0, 3);
    Stworz_Regule_Koloru(0, 0, 255, 4);*/

    // Wersja stabilna:
    /*Stworz_Regule_Koloru(0, 0, 0, 1);
    Stworz_Regule_Koloru(150, 0, 0, 3);
    Stworz_Regule_Koloru(0, 150, 0, 2);
    Stworz_Regule_Koloru(0, 0, 150, 2);*/

    // Wersja bardzo abstrakcyjna:
    srand(time(0));
    for (int i = 0; i < floor(rand() % 5 + 2); i++)
    {
        Stworz_Regule_Koloru(floor(rand() % 256), floor(rand() % 256), floor(rand() % 256), floor(rand() % 4 + 1));
        cout << "Colour set " << i << ": ";
        cout << "R: " << Paleta_Kolorow[i] -> podajWartoscR() << ", ";
        cout << "G: " << Paleta_Kolorow[i] -> podajWartoscG() << ", ";
        cout << "B: " << Paleta_Kolorow[i] -> podajWartoscB() << ", ";
        cout << "Direction: " << Paleta_Kolorow[i] -> podajKierunek() << endl;
    }


    if (M -> getBitmap() == NULL)
    {
        cout << "Could not load a bitmap for the Ant!" << endl;
        return 3;
    }

    al_clear_to_color(al_map_rgb(P -> podajWartoscR(), P -> podajWartoscG(), P -> podajWartoscB()));
    al_draw_scaled_rotated_bitmap(M -> getBitmap(),
                                  al_get_bitmap_width(M -> getBitmap()) / 2, al_get_bitmap_height(M -> getBitmap()) / 2,
                                  M -> podajX() + Ruch / 2, M -> podajY() + Ruch / 2,
                                  Przeskalowanie, Przeskalowanie, M -> podajKat(), 0);
/*
    al_draw_text(Czcionka, al_map_rgb(0, 0, 100), 10, 10, ALLEGRO_ALIGN_LEFT, "Iteration:");
    al_draw_textf(Czcionka, al_map_rgb(0, 0, 100), 85, 10, ALLEGRO_ALIGN_LEFT, "%.0lu", Iteracja);
    al_draw_text(Czcionka, al_map_rgb(0, 0, 100), 10, 30, ALLEGRO_ALIGN_LEFT, "Speed (IPS):");
    al_draw_textf(Czcionka, al_map_rgb(0, 0, 100), 85, 30, ALLEGRO_ALIGN_LEFT, "%.0f", IteracjiNaSekunde);
*/

    al_flip_display();

    while(true)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_TIMER && CzyPauza == false)
        {
            WymiarX = (M -> podajX()) / Ruch;
            WymiarY = (M -> podajY()) / Ruch;

            if (P -> Tablica_Planszy[WymiarX][WymiarY] + 1 >= Paleta_Kolorow.size())
                P -> Tablica_Planszy[WymiarX][WymiarY] = 0;
            else
                P -> Tablica_Planszy[WymiarX][WymiarY]++;

            al_set_clipping_rectangle(M -> podajX(), M -> podajY(), Ruch, Ruch);
            al_clear_to_color(al_map_rgb(Paleta_Kolorow[P -> Tablica_Planszy[WymiarX][WymiarY]] -> podajWartoscR(),
                                         Paleta_Kolorow[P -> Tablica_Planszy[WymiarX][WymiarY]] -> podajWartoscG(),
                                         Paleta_Kolorow[P -> Tablica_Planszy[WymiarX][WymiarY]] -> podajWartoscB()));
            al_set_clipping_rectangle(0, 0, Ekran_X, Ekran_Y);

            M -> ustawKierunek((M -> podajKierunek()) + (Paleta_Kolorow[P -> Tablica_Planszy[WymiarX][WymiarY]] -> podajKierunek()));
            if (M -> podajKierunek() > 4)
                M -> ustawKierunek((M -> podajKierunek()) - 4);

            M -> Poruszanie();

            al_draw_scaled_rotated_bitmap(M -> getBitmap(),
                                          al_get_bitmap_width(M -> getBitmap()) / 2, al_get_bitmap_height(M -> getBitmap()) / 2,
                                          M -> podajX() + Ruch / 2, M -> podajY() + Ruch / 2,
                                          Przeskalowanie, Przeskalowanie, M -> podajKat(), 0);
            Iteracja++;
/*
            al_draw_text(Czcionka, al_map_rgb(0, 0, 100), 10, 10, ALLEGRO_ALIGN_LEFT, "Iteration:");
            al_draw_textf(Czcionka, al_map_rgb(0, 0, 100), 85, 10, ALLEGRO_ALIGN_LEFT, "%.0lu", Iteracja);
            al_draw_text(Czcionka, al_map_rgb(0, 0, 100), 10, 30, ALLEGRO_ALIGN_LEFT, "Speed (IPS):");
            al_draw_textf(Czcionka, al_map_rgb(0, 0, 100), 85, 30, ALLEGRO_ALIGN_LEFT, "%.0f", IteracjiNaSekunde);
*/
            al_flip_display();

        }
        else if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            switch(ev.keyboard.keycode)
            {
                case ALLEGRO_KEY_LEFT:
                    if (IteracjiNaSekunde > 1)
                    {
                        IteracjiNaSekunde--;
                        al_set_timer_speed(Czas, 1 / IteracjiNaSekunde);
                    }
                    break;
                case ALLEGRO_KEY_RIGHT:
                    if (IteracjiNaSekunde < 3000)
                    {
                        IteracjiNaSekunde++;
                        al_set_timer_speed(Czas, 1 / IteracjiNaSekunde);
                    }
                    break;
                case ALLEGRO_KEY_DOWN:
                    if (IteracjiNaSekunde > 10)
                    {
                        IteracjiNaSekunde = IteracjiNaSekunde / 10;
                        al_set_timer_speed(Czas, 1 / IteracjiNaSekunde);
                    }
                    else if (IteracjiNaSekunde > 1)
                    {
                        IteracjiNaSekunde = 1;
                        al_set_timer_speed(Czas, 1 / IteracjiNaSekunde);
                    }
                    break;
                case ALLEGRO_KEY_UP:
                    if (IteracjiNaSekunde <= 300)
                    {
                        IteracjiNaSekunde = IteracjiNaSekunde * 10;
                        al_set_timer_speed(Czas, 1 / IteracjiNaSekunde);
                    }
                    else if (IteracjiNaSekunde < 3000)
                    {
                        IteracjiNaSekunde = 3000;
                        al_set_timer_speed(Czas, 1 / IteracjiNaSekunde);
                    }
                    break;
                case ALLEGRO_KEY_SPACE:
                    CzyPauza = CzyPauza * (-1) + 1;
                    break;
                case ALLEGRO_KEY_ESCAPE:
                    goto exit_program;
                    break;
            }
        }
        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            break;
    }

    exit_program:

    // usuwanie zmiennych ze sterty

    cout << endl << "End of Simulation after " << Iteracja << " iterations." << endl;
    //cout << "Przetrwales w przestrzeni kosmicznej " << setprecision(2) << game_time << " sekund(y)." << endl;
    return 0;
}
