/* The program works with the stable version of Allegro 5.0.10. */

/* LIBRARIES */

#include <iostream>
#include <vector>
#include <math.h>
#include <random>

using namespace std;

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

/* GLOBAL VARIABLES & CONSTANTS */

const double PI = 2 * acos(0.0);    // PI value
const int Ekran_X = 600;            // x-dimension size of display screen(s)
const int Ekran_Y = 600;            // y-dimension size of display screen(s)
int Rozmiar_Mrowki = 3;            // size of the Ant
float Przeskalowanie = 0.0125 * Rozmiar_Mrowki;     // relative size of the Ant (compared to the original .png file)
unsigned short Rozmiar_Planszy = 2; // default / previously set relative size of the board

/* CLASSES AND SUBCLASSES */

class Kierunkowzkaz
{
protected:
    unsigned short Kierunek;

public:
    unsigned short podajKierunek() const { return Kierunek; }
};

class Kolor : public Kierunkowzkaz
{
    unsigned short Wartosc_R, Wartosc_G, Wartosc_B;

public:

    Kolor(unsigned short r, unsigned short g, unsigned short b, unsigned short direction)
    {
        Wartosc_R = r;
        Wartosc_G = g;
        Wartosc_B = b;
        Kierunek = direction;
    }

    unsigned short podajWartoscR() const { return Wartosc_R; }
    unsigned short podajWartoscG() const { return Wartosc_G; }
    unsigned short podajWartoscB() const { return Wartosc_B; }
};

vector<Kolor*> Paleta_Kolorow;      // dynamically-allocated vector of sets of rules of colors and moving directions

class Mrowka : public Kierunkowzkaz
{
    ALLEGRO_BITMAP* Obraz;
    int Pozycja_X, Pozycja_Y;
    float Kat;

public:

    // Upper left corner of Ant's image
    Mrowka(): Mrowka((Ekran_X - Ekran_X % (Rozmiar_Mrowki * 2)) / 2, (Ekran_Y - Ekran_Y % (Rozmiar_Mrowki * 2)) / 2, 4) {}

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

    /* 1 - East / turn left
       2 - South / turn back
       3 - West / turn right
       4 - North / go straight ahead */
    void ustawKierunek(unsigned short direction)
    {
        Kierunek = direction;
        ustawKat(direction * PI / 2);
    }

    float podajKat() const     { return Kat; }
    void ustawKat(float angle) { Kat = angle; }

    /* Map-wrapping cases included */
    virtual void Poruszanie()
    {
        switch(Kierunek)
        {
            case 1:
                if (podajX() + Rozmiar_Mrowki < Ekran_X)
                    ustawX(podajX() + Rozmiar_Mrowki);
                else
                    ustawX(0);
                break;
            case 2:
                if (podajY() + Rozmiar_Mrowki < Ekran_Y)
                    ustawY(podajY() + Rozmiar_Mrowki);
                else
                    ustawY(0);
                break;
            case 3:
                if (podajX() - Rozmiar_Mrowki >= 0)
                    ustawX(podajX() - Rozmiar_Mrowki);
                else
                    ustawX(Ekran_X - Rozmiar_Mrowki);
                break;
            case 4:
                if (podajY() - Rozmiar_Mrowki >= 0)
                    ustawY(podajY() - Rozmiar_Mrowki);
                else
                    ustawY(Ekran_Y - Rozmiar_Mrowki);
                break;
        }
    }

    virtual ALLEGRO_BITMAP* getBitmap() const { return Obraz; }
};

/* MAIN AND GLOBAL FUNCTIONS */

/* Refreshing chosen option of relative size of board and drawing Ant's image in a proper box */
void Renderuj_Wybor_Rozmiaru(unsigned short option)
{
    al_set_clipping_rectangle(41, 328, 25, 25);
    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_set_clipping_rectangle(236, 328, 25, 25);
    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_set_clipping_rectangle(432, 328, 25, 25);
    al_clear_to_color(al_map_rgb(255, 255, 255));

    al_set_clipping_rectangle(0, 0, Ekran_X, Ekran_Y);

    switch(option)
    {
        case 1:
            al_draw_scaled_rotated_bitmap(al_load_bitmap("mrowka.png"),
                                          40, 40, 40 + 13, 327 + 13, 0.3125, 0.3125, PI * 7 / 4, 0);
            Rozmiar_Mrowki = 10;
            break;
        case 2:
            al_draw_scaled_rotated_bitmap(al_load_bitmap("mrowka.png"),
                                          40, 40, 235 + 13, 327 + 13, 0.3125, 0.3125, PI * 7 / 4, 0);
            Rozmiar_Mrowki = 3;
            break;
        case 3:
            al_draw_scaled_rotated_bitmap(al_load_bitmap("mrowka.png"),
                                          40, 40, 431 + 13, 327 + 13, 0.3125, 0.3125, PI * 7 / 4, 0);
            Rozmiar_Mrowki = 1;
            break;
    }

    al_flip_display();
}

/* Adding a new single rule of colors and moving directions and stacking it at the last position */
void Stworz_Regule_Koloru(unsigned short r, unsigned short g, unsigned short b, unsigned short direction)
{
    Kolor *K = new Kolor(r, g, b, direction);
    Paleta_Kolorow.push_back(K);

    cout << "Colour set " << Paleta_Kolorow.size() << ": ";
    cout << "R: " << r << ", ";
    cout << "G: " << g << ", ";
    cout << "B: " << b << ", ";
    cout << "Direction: " << direction << endl;

    delete &K;
}

/* Creating full set of rules of colors and moving directions based on chosen option */
void Stworz_Reguly_Symulacji(unsigned short option)
{
    Paleta_Kolorow.clear();
    switch (option)
    {
        case 1:
            Stworz_Regule_Koloru(255, 255, 255, 1);
            Stworz_Regule_Koloru(255, 0, 0, 3);
            break;
        case 2:
            Stworz_Regule_Koloru(206, 103, 112, 4);
            Stworz_Regule_Koloru(1, 65, 98, 3);
            Stworz_Regule_Koloru(0, 138, 23, 2);
            Stworz_Regule_Koloru(146, 103, 96, 4);
            Stworz_Regule_Koloru(144, 217, 64, 3);
            break;
        case 3:
            Stworz_Regule_Koloru(207, 239, 211, 1);
            Stworz_Regule_Koloru(51, 198, 34, 2);
            Stworz_Regule_Koloru(162, 79, 56, 1);
            Stworz_Regule_Koloru(167, 158, 108, 1);
            break;
        case 4:
            Stworz_Regule_Koloru(212, 162, 10, 1);
            Stworz_Regule_Koloru(81, 80, 241, 3);
            Stworz_Regule_Koloru(148, 209, 209, 1);
            Stworz_Regule_Koloru(153, 237, 162, 1);
            Stworz_Regule_Koloru(153, 70, 164, 1);
            Stworz_Regule_Koloru(156, 11, 171, 1);
            Stworz_Regule_Koloru(144, 144, 148, 1);
            Stworz_Regule_Koloru(52, 210, 3, 3);
            Stworz_Regule_Koloru(235, 27, 41, 3);
            break;
        case 5:
            Stworz_Regule_Koloru(212, 36, 66, 1);
            Stworz_Regule_Koloru(154, 228, 75, 3);
            Stworz_Regule_Koloru(60, 65, 12, 3);
            Stworz_Regule_Koloru(16, 116, 32, 1);
            Stworz_Regule_Koloru(200, 8, 147, 3);
            Stworz_Regule_Koloru(100, 19, 0, 3);
            Stworz_Regule_Koloru(76, 63, 42, 3);
            Stworz_Regule_Koloru(153, 70, 164, 1);
            Stworz_Regule_Koloru(57, 18, 87, 1);
            Stworz_Regule_Koloru(200, 47, 98, 1);
            Stworz_Regule_Koloru(100, 147, 198, 1);
            break;
        case 6:
            srand(time(0));
            for (int i = 0; i < floor(rand() % 9 + 2); i++)
                Stworz_Regule_Koloru(floor(rand() % 256), floor(rand() % 256), floor(rand() % 256), floor(rand() % 4 + 1));
            break;
    }
}

/* Creating and refreshing upper-left in-game table displaying no. iteration and speed (measured in iterations per second) */
void Renderuj_Ramke_Tekstowa(ALLEGRO_FONT *fonty, unsigned long iteration, float ips)
{
    al_set_clipping_rectangle(10, 10, 170, 54);
    al_clear_to_color(al_map_rgb(0, 0, 0));

    al_set_clipping_rectangle(13, 13, 164, 48);
    al_clear_to_color(al_map_rgb(250, 250, 250));

    al_draw_text(fonty, al_map_rgb(0, 0, 80), 18, 18, ALLEGRO_ALIGN_LEFT, "Iteration:");
    al_draw_textf(fonty, al_map_rgb(0, 0, 80), 103, 18, ALLEGRO_ALIGN_LEFT, "%.0lu", iteration);
    al_draw_text(fonty, al_map_rgb(0, 0, 80), 18, 38, ALLEGRO_ALIGN_LEFT, "Speed (IPS):");
    al_draw_textf(fonty, al_map_rgb(0, 0, 80), 103, 38, ALLEGRO_ALIGN_LEFT, "%.2f", ips);

    al_set_clipping_rectangle(0, 0, Ekran_X, Ekran_Y);

    al_flip_display();
}


/* MAIN FUNCTION, 1/2 */
/* Displays menu window with introduction, instruction and game option to be chosen */

int Wyswietl_Okno_Menu()
{
    unsigned short Wybrana_Symulacja = 0;

    ALLEGRO_DISPLAY *Wyswietl_Menu = al_create_display(Ekran_X, Ekran_Y);
    al_set_window_title(Wyswietl_Menu, "Langton's Ant - Main Menu");
    al_set_display_icon(Wyswietl_Menu, al_load_bitmap("mrowka.png"));

    ALLEGRO_EVENT_QUEUE *Kolejka_Wydarzen = al_create_event_queue();

    al_register_event_source(Kolejka_Wydarzen, al_get_keyboard_event_source());
    al_register_event_source(Kolejka_Wydarzen, al_get_mouse_event_source());
    al_register_event_source(Kolejka_Wydarzen, al_get_display_event_source(Wyswietl_Menu));

    al_draw_bitmap(al_load_bitmap("glowne_menu.png"), 0, 0, 0);
    Renderuj_Wybor_Rozmiaru(Rozmiar_Planszy);

    while(true)
    {
        ALLEGRO_EVENT KW;
        al_wait_for_event(Kolejka_Wydarzen, &KW);

        // Mouse left button pressing-down management
        if (KW.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && KW.mouse.button == 1)
        {
            if (KW.mouse.x >= 40 && KW.mouse.x <= 67 && KW.mouse.y >= 327 && KW.mouse.y <= 354)
                Renderuj_Wybor_Rozmiaru(Rozmiar_Planszy = 1);
            else if (KW.mouse.x >= 235 && KW.mouse.x <= 262 && KW.mouse.y >= 327 && KW.mouse.y <= 354)
                Renderuj_Wybor_Rozmiaru(Rozmiar_Planszy = 2);
            else if (KW.mouse.x >= 431 && KW.mouse.x <= 458 && KW.mouse.y >= 327 && KW.mouse.y <= 354)
                Renderuj_Wybor_Rozmiaru(Rozmiar_Planszy = 3);
            else if (KW.mouse.x >= 30 && KW.mouse.x <= 179 && KW.mouse.y >= 381 && KW.mouse.y <= 458)
                Wybrana_Symulacja = 1;
            else if (KW.mouse.x >= 226 && KW.mouse.x <= 375 && KW.mouse.y >= 381 && KW.mouse.y <= 458)
                Wybrana_Symulacja = 2;
            else if (KW.mouse.x >= 421 && KW.mouse.x <= 570 && KW.mouse.y >= 381 && KW.mouse.y <= 458)
                Wybrana_Symulacja = 3;
            else if (KW.mouse.x >= 30 && KW.mouse.x <= 179 && KW.mouse.y >= 486 && KW.mouse.y <= 563)
                Wybrana_Symulacja = 4;
            else if (KW.mouse.x >= 226 && KW.mouse.x <= 375 && KW.mouse.y >= 486 && KW.mouse.y <= 563)
                Wybrana_Symulacja = 5;
            else if (KW.mouse.x >= 421 && KW.mouse.x <= 570 && KW.mouse.y >= 486 && KW.mouse.y <= 563)
                Wybrana_Symulacja = 6;
        }
        // Mouse left button releasing management
        else if (KW.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && KW.mouse.button == 1 && Wybrana_Symulacja > 0)
        {
            if (!(KW.mouse.x >= 30 && KW.mouse.x <= 179 && KW.mouse.y >= 381 && KW.mouse.y <= 458 && Wybrana_Symulacja == 1) &&
                !(KW.mouse.x >= 226 && KW.mouse.x <= 375 && KW.mouse.y >= 381 && KW.mouse.y <= 458 && Wybrana_Symulacja == 2) &&
                !(KW.mouse.x >= 421 && KW.mouse.x <= 570 && KW.mouse.y >= 381 && KW.mouse.y <= 458 && Wybrana_Symulacja == 3) &&
                !(KW.mouse.x >= 30 && KW.mouse.x <= 179 && KW.mouse.y >= 486 && KW.mouse.y <= 563 && Wybrana_Symulacja == 4) &&
                !(KW.mouse.x >= 226 && KW.mouse.x <= 375 && KW.mouse.y >= 486 && KW.mouse.y <= 563 && Wybrana_Symulacja == 5) &&
                !(KW.mouse.x >= 421 && KW.mouse.x <= 570 && KW.mouse.y >= 486 && KW.mouse.y <= 563 && Wybrana_Symulacja == 6))
                    continue;
            break;
        }
        else if((KW.type == ALLEGRO_EVENT_KEY_DOWN && KW.keyboard.keycode == ALLEGRO_KEY_ESCAPE) || KW.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            al_destroy_event_queue(Kolejka_Wydarzen);
            al_destroy_display(Wyswietl_Menu);
            cout << endl << "Program has been ended!" << endl;
            return 0;
        }
    }

    cout << endl << "Simulation starts:" << endl;
    Stworz_Reguly_Symulacji(Wybrana_Symulacja);
    al_destroy_event_queue(Kolejka_Wydarzen);
    al_destroy_display(Wyswietl_Menu);

    return 1;
}

/* MAIN FUNCTION, 2/2 */
/* Displays simulation window with board and Langton's Ant; Starts simulation */

int Wyswietl_Okno_Gry()
{
    float IteracjiNaSekunde = 1.0;
    unsigned long Iteracja = 1;
    bool CzyPauza = false;
    int WymiarX, WymiarY;
    Przeskalowanie = 0.0125 * Rozmiar_Mrowki;

    ALLEGRO_DISPLAY *Wyswietl_Ekran = al_create_display(Ekran_X, Ekran_Y);
    al_set_window_title(Wyswietl_Ekran, "Langton's Ant - Simulation");
    al_set_display_icon(Wyswietl_Ekran, al_load_bitmap("mrowka.png"));

    ALLEGRO_EVENT_QUEUE *Kolejka_Wydarzen = al_create_event_queue();
    ALLEGRO_FONT *Czcionka = al_load_font("arial.ttf", 14, 0);
    ALLEGRO_TIMER *Czas = al_create_timer(1);

    al_register_event_source(Kolejka_Wydarzen, al_get_keyboard_event_source());
    al_register_event_source(Kolejka_Wydarzen, al_get_mouse_event_source());
    al_register_event_source(Kolejka_Wydarzen, al_get_display_event_source(Wyswietl_Ekran));
    al_register_event_source(Kolejka_Wydarzen, al_get_timer_event_source(Czas));

    // 2-dimension dynamically-allocated table, declared as vector-x-dimension and vector-y-dimension within another vector
    vector<vector<double>> Tablica_Planszy(Ekran_X / Rozmiar_Mrowki, vector<double>(Ekran_Y / Rozmiar_Mrowki));
    Mrowka *M = new Mrowka();

    al_clear_to_color(al_map_rgb(230, 230, 230));
    al_draw_scaled_rotated_bitmap(M -> getBitmap(),
                                  al_get_bitmap_width(M -> getBitmap()) / 2, al_get_bitmap_height(M -> getBitmap()) / 2,
                                  M -> podajX() + Rozmiar_Mrowki / 2, M -> podajY() + Rozmiar_Mrowki / 2,
                                  Przeskalowanie, Przeskalowanie, M -> podajKat(), 0);
    Renderuj_Ramke_Tekstowa(Czcionka, Iteracja, IteracjiNaSekunde);

    al_start_timer(Czas);

    // Main while-loop running each simulation, based on set and delivered parameters or pressed keys
    while(true)
    {
        ALLEGRO_EVENT KW;
        al_wait_for_event(Kolejka_Wydarzen, &KW);

        // Run a single-iteration simulation (provided the simulation is not paused)
        if(KW.type == ALLEGRO_EVENT_TIMER && CzyPauza == false)
        {
            WymiarX = (M -> podajX()) / Rozmiar_Mrowki;
            WymiarY = (M -> podajY()) / Rozmiar_Mrowki;

            // Choose next in order set of rules of colors and moving directions
            if (Tablica_Planszy[WymiarX][WymiarY] + 1 >= Paleta_Kolorow.size())
                Tablica_Planszy[WymiarX][WymiarY] = 0;
            else
                Tablica_Planszy[WymiarX][WymiarY]++;

            // Repaint a particular tile
            al_set_clipping_rectangle(M -> podajX(), M -> podajY(), Rozmiar_Mrowki, Rozmiar_Mrowki);
            al_clear_to_color(al_map_rgb(Paleta_Kolorow[Tablica_Planszy[WymiarX][WymiarY]] -> podajWartoscR(),
                                         Paleta_Kolorow[Tablica_Planszy[WymiarX][WymiarY]] -> podajWartoscG(),
                                         Paleta_Kolorow[Tablica_Planszy[WymiarX][WymiarY]] -> podajWartoscB()));
            al_set_clipping_rectangle(0, 0, Ekran_X, Ekran_Y);

            // Turn the Ant
            M -> ustawKierunek((M -> podajKierunek()) + (Paleta_Kolorow[Tablica_Planszy[WymiarX][WymiarY]] -> podajKierunek()));
            if (M -> podajKierunek() > 4)
                M -> ustawKierunek((M -> podajKierunek()) - 4);

            // Move the Ant
            M -> Poruszanie();

            // Draw the Ant
            al_draw_scaled_rotated_bitmap(M -> getBitmap(),
                                          al_get_bitmap_width(M -> getBitmap()) / 2, al_get_bitmap_height(M -> getBitmap()) / 2,
                                          M -> podajX() + Rozmiar_Mrowki / 2, M -> podajY() + Rozmiar_Mrowki / 2,
                                          Przeskalowanie, Przeskalowanie, M -> podajKat(), 0);

            // Refresh the in-game table containing no. iteration and speed
            Renderuj_Ramke_Tekstowa(Czcionka, ++Iteracja, IteracjiNaSekunde);

        }
        // Keyboard management
        else if(KW.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            switch(KW.keyboard.keycode)
            {
                case ALLEGRO_KEY_LEFT:
                    if (IteracjiNaSekunde > 1)
                    {
                        Renderuj_Ramke_Tekstowa(Czcionka, Iteracja, --IteracjiNaSekunde);
                        al_set_timer_speed(Czas, 1 / IteracjiNaSekunde);
                    }
                    break;
                case ALLEGRO_KEY_RIGHT:
                    if (IteracjiNaSekunde < 600)
                    {
                        Renderuj_Ramke_Tekstowa(Czcionka, Iteracja, ++IteracjiNaSekunde);
                        al_set_timer_speed(Czas, 1 / IteracjiNaSekunde);
                    }
                    break;
                case ALLEGRO_KEY_DOWN:
                    if (IteracjiNaSekunde > 2)
                    {
                        Renderuj_Ramke_Tekstowa(Czcionka, Iteracja, IteracjiNaSekunde = IteracjiNaSekunde / 2);
                        al_set_timer_speed(Czas, 1 / IteracjiNaSekunde);
                    }
                    else if (IteracjiNaSekunde > 1)
                    {
                        Renderuj_Ramke_Tekstowa(Czcionka, Iteracja, IteracjiNaSekunde = 1);
                        al_set_timer_speed(Czas, 1 / IteracjiNaSekunde);
                    }
                    break;
                case ALLEGRO_KEY_UP:
                    if (IteracjiNaSekunde <= 300)
                    {
                        Renderuj_Ramke_Tekstowa(Czcionka, Iteracja, IteracjiNaSekunde = IteracjiNaSekunde * 2);
                        al_set_timer_speed(Czas, 1 / IteracjiNaSekunde);
                    }
                    else if (IteracjiNaSekunde < 600)
                    {
                        Renderuj_Ramke_Tekstowa(Czcionka, Iteracja, IteracjiNaSekunde = 600);
                        al_set_timer_speed(Czas, 1 / IteracjiNaSekunde);
                    }
                    break;
                case ALLEGRO_KEY_SPACE:
                    CzyPauza = CzyPauza * (-1) + 1;
                    break;
                case ALLEGRO_KEY_ESCAPE:
                    goto Zakonczenie_Symulacji;
                    break;
            }
        }
        else if(KW.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            goto Zakonczenie_Symulacji;
    }

Zakonczenie_Symulacji:

    al_destroy_timer(Czas);
    al_destroy_font(Czcionka);
    al_destroy_event_queue(Kolejka_Wydarzen);
    al_destroy_display(Wyswietl_Ekran);
    delete &M;

    cout << "Simulation ends after " << Iteracja << " iterations." << endl;

    return 1;
}


/* INT MAIN - Main int loop initializing the simulation and displaying both main windows in while-loop */

int main(int, char**)
{
    unsigned short Stan_Gry = 1;

    if (!al_init() || !al_install_keyboard() || !al_install_mouse() || !al_init_image_addon())
    {
        cout << "Initialization error!" << endl;
        return 1;
    }
    al_init_font_addon();
    al_init_ttf_addon();

    while(true)
    {
        Stan_Gry = Wyswietl_Okno_Menu();
        if (Stan_Gry == 0)
            break;

        Stan_Gry = Wyswietl_Okno_Gry();
        if (Stan_Gry == 0)
            break;
    }

    return 0;
}
