
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

string intToStr(int x)
{
    stringstream ss;
    ss << x;
    return ss.str();
}

class Wisielec
{
private:

    int X, Y; // wspolrzedne poczatkowe szubienicy
    string haslo; // zgadywane haslo
	string odgadniete; // jakie litery sa odgadniete
	string uzyte; // wszystkie uzyte
	string pozostale; // te ktore byly uzyte, ale nie pasuja

	vector<bool> indeksyOdgadnietych; // na ktorych indeksach litera jest odgadnieta, a na ktorych nie
    vector<string> hasla; // hasla wczytane z pliku

    int wybor; // wybor opcji z menu
	bool zainicjowana; // czy gra jest zainicjowana
    int klatka; // ktora klatka (ile elementow wisielca)
    int tura; // ktora tura (dla gry dwuosobowej sa 2 tury)
    int ostatniaKlatka; // numer ostatniej klatki (konczacej gre)
    int faza; // faza rozgrywki (0 - wybor z menu, 1 - rozgrywka)
    int rodzajGry; // rodzaj gry (jednoosobowa lub dwuosobowa)
    int wygrana; // czy nastapila wygrana

    ALLEGRO_FONT* font; // normalna czcionka
    ALLEGRO_FONT* bigFont; // duza czcionka


    int punkty1;
    int punkty2;

public:

    // konstruktor
    Wisielec()
    {
        X = 300;
        Y = 500;
        wybor = 0;
        haslo = "";
        odgadniete = "";
        uzyte = "";
        pozostale = "";
        zainicjowana = false;
        klatka = 0;
        tura = 0;
        ostatniaKlatka = 12;
        faza = 0;
        rodzajGry = 0;
        wygrana = false;

        punkty1 = 0;
        punkty2 = 0;

        // zaladowanie czcionek
        font = al_load_ttf_font("Font.ttf", 20, 0);
        bigFont = al_load_ttf_font("Font.ttf", 60, 0);
    }



    // funkcja rysujaca szubienice, wisielca oraz litery
    void rysuj()
    {
        int ileElementow = klatka;

        ALLEGRO_COLOR kolorCzarny = al_map_rgb(0, 0, 0);
        int odstep = 20; // odstep pomiedzy literami

        // rysowanie hasla
        for (unsigned int i = 0; i < haslo.size(); i++)
        {
            char c = haslo[i];
            // rysowanie litery jesli jest odgadnieta
            if (indeksyOdgadnietych[i])
            {
               al_draw_text(font, kolorCzarny, 50 + i * odstep, Y + 20, ALLEGRO_ALIGN_CENTRE, &c);
            }

            // rysowawanie linii pod litetrami
            al_draw_line(43 + i * odstep, Y + 44, 39 + (i + 1) * odstep, Y + 44, kolorCzarny, 1);
        }

        // wypisanie liter, ktore nie wystepuja w hasle
        for (unsigned int i = 0; i < pozostale.size(); i++)
        {
            string s = pozostale.substr(i, 1) + ",";
            const char* c = s.c_str();
            al_draw_text(font, kolorCzarny, 50 + i * odstep, Y + 50, ALLEGRO_ALIGN_CENTRE, c);
        }

        // rysowanie kolejnych elementow szubienicy/wisielca


        if (ileElementow == 0) return; // w zaleznosci od wartosci ileElementow bedziemy przerywac rysowanie w odpowiednim miejscu

        // szubienica
        al_draw_line(X + 0, Y + 0, X + 50, Y - 20, kolorCzarny, 2);
        if (ileElementow == 1) return;
        al_draw_line(X + 50, Y - 20, X + 100, Y + 0, kolorCzarny, 2);
        if (ileElementow == 2) return;
        al_draw_line(X + 50, Y - 20, X + 50, Y - 320, kolorCzarny, 2);
        if (ileElementow == 3) return;

        al_draw_line(X + 50, Y - 270, X + 100, Y - 320, kolorCzarny, 2);
        al_draw_line(X + 50, Y - 320, X + 150, Y - 320, kolorCzarny, 2);
        if (ileElementow == 4) return;

        al_draw_line(X + 150, Y - 320, X + 150, Y - 270, kolorCzarny, 2);
        if (ileElementow == 5) return;

        // rysowanie glowy
        al_draw_circle(X + 150, Y - 250,  20, kolorCzarny, 2);
        al_draw_circle(X + 140, Y - 250,  2, kolorCzarny, 2);
        al_draw_circle(X + 160, Y - 250,  2, kolorCzarny, 2);

        al_draw_line(X + 142, Y - 240, X + 158, Y - 240, kolorCzarny, 2);

        if (ileElementow == 6) return;

        al_draw_ellipse(X + 150, Y - 180, 30, 50, kolorCzarny, 2); // rysowanie tulowia
        if (ileElementow == 7) return;

        // rece
        al_draw_line(X + 130, Y - 220, X + 110, Y - 280, kolorCzarny, 2);
        if (ileElementow == 8) return;

        al_draw_line(X + 170, Y - 220, X + 190, Y - 280, kolorCzarny, 2);
        if (ileElementow == 9) return;

        // nogi
        al_draw_line(X + 130, Y - 144, X + 110, Y - 70, kolorCzarny, 2);
        if (ileElementow == 10) return;

        al_draw_line(X + 170, Y - 144, X + 190, Y - 70, kolorCzarny, 2);
        if (ileElementow == 11) return;


        if (ileElementow == 12)
        {
            al_draw_text(font, kolorCzarny, X + 50, Y - 360, ALLEGRO_ALIGN_CENTRE, "PRZEGRANA");
        }
    }

    // menu startowe programu
    void menuStartowe()
    {
        // wczytanie czcionki
        ALLEGRO_FONT * font = al_load_ttf_font("Font.ttf", 60, 0);

        // kolory
        ALLEGRO_COLOR kolorCzarny = al_map_rgb(0, 0, 0);
        ALLEGRO_COLOR kolorZielony = al_map_rgb(100, 200, 100);

        // ustawienie tla
        al_clear_to_color(al_map_rgb(105, 205, 205));

        // prostokaty dla opcji w menu
        al_draw_filled_rectangle(45, 160, 750, 250, kolorZielony);
        al_draw_filled_rectangle(45, 260, 750, 350, kolorZielony);
        al_draw_filled_rectangle(45, 360, 750, 450, kolorZielony);

        // obramowanie wybranej opcji
        al_draw_rectangle(45, 160 + wybor * 100, 750, 250 + wybor * 100, kolorCzarny, 2);

        // napisy dla opcji w menu
        al_draw_text(font, kolorCzarny, 400, 170, ALLEGRO_ALIGN_CENTRE, "NOWA GRA: 1 GRACZ  ");
        al_draw_text(font, kolorCzarny, 400, 270, ALLEGRO_ALIGN_CENTRE, "NOWA GRA: 2 GRACZY");
        al_draw_text(font, kolorCzarny, 400, 370, ALLEGRO_ALIGN_CENTRE, "WYJSCIE");
    }


    void menuPoTurze()
    {
        // wczytanie czcionki
        ALLEGRO_FONT * font = al_load_ttf_font("Font.ttf", 60, 0);

        // kolory
        ALLEGRO_COLOR kolorCzarny = al_map_rgb(0, 0, 0);
        ALLEGRO_COLOR kolorZielony = al_map_rgb(100, 200, 100);

        // ustawienie tla
        al_clear_to_color(al_map_rgb(105, 205, 205));

        // prostokaty dla opcji w menu
        al_draw_filled_rectangle(45, 160, 750, 250, kolorZielony);
        al_draw_filled_rectangle(45, 260, 750, 350, kolorZielony);
        al_draw_filled_rectangle(45, 360, 750, 450, kolorZielony);

        // obramowanie wybranej opcji
        al_draw_rectangle(45, 160 + wybor * 100, 750, 250 + wybor * 100, kolorCzarny, 2);

        // napisy dla opcji w menu
        al_draw_text(font, kolorCzarny, 400, 170, ALLEGRO_ALIGN_CENTRE, "KONTYNUUJ");
        al_draw_text(font, kolorCzarny, 400, 270, ALLEGRO_ALIGN_CENTRE, "MENU STARTOWE");
        al_draw_text(font, kolorCzarny, 400, 370, ALLEGRO_ALIGN_CENTRE, "WYJSCIE");
    }

    // wczytuje hasla z pliku
    void wczytajHasla()
    {
        string linia;
        ifstream plik("hasla.txt");
        if (plik.is_open())
        {
            while (getline(plik, linia))
            {
                hasla.push_back(linia);
            }
            plik.close();
        }
    }

    void nastepnaOpcjaMenu()
    {
        if (faza == 0 || faza == 2)
        {
            wybor = (wybor + 1) % 3;
        }
    }

    void poprzedniaOpcjaMenu()
    {
        if (faza == 0 || faza == 2)
        {
            wybor = (wybor + 2) % 3;
        }
    }

    bool wyborOpcji()
    {
        if (faza == 0)
        {
            if (wybor == 2)
            {
                return false;
            }
            rodzajGry = wybor;
            faza = 1;
        }

        if (faza == 2)
        {
            if (wybor == 0)
            {
                faza = 1;
            }
            else if (wybor == 1)
            {
                faza = 0;
                punkty1 = 0;
                punkty2 = 0;
                wybor = 0;
                al_rest(0.1);

            }
            else if (wybor == 2)
            {
                return false;
            }
        }

        return true;
    }

    bool czyMenu()
    {
        return faza == 0;
    }

    bool czyRozgrywka()
    {
        return faza == 1;
    }


    void inicjujDlaJednegoGracza()
    {
        // losuje haslo
        haslo = hasla[rand() % hasla.size()];

        // inicjalizuje odgadniete indeksy zerami
        indeksyOdgadnietych.clear();
        for (unsigned int i = 0; i < haslo.size(); i++)
        {
            indeksyOdgadnietych.push_back(0);
        }

        zainicjowana = true;
    }

    void inicjujDlaDwochGraczy(ALLEGRO_KEYBOARD_STATE* klawiatura)
    {
        // sprawdza wpisane litery
        for (int klawisz = ALLEGRO_KEY_A; klawisz <= ALLEGRO_KEY_Z; klawisz++)
        {
            if ( al_key_down(klawiatura, klawisz))
            {
                char litera = (char)(klawisz - 1 + 'a');
                string s(1, litera);
                haslo += litera;
            }
        }


        string s = "";
        string str = s + "Gracz " + (tura % 2 == 0 ? "1" : "2") + " - wpisz haslo i zatwierdz enterem: " + haslo;
        const char* cc = str.c_str();

        // wyswietla aktualny stan wpisanego hasla
        al_draw_text(font, al_map_rgb(0, 0, 0), 50, 50, ALLEGRO_ALIGN_LEFT, cc);

        // kasowanie ostatniej litery
        if (al_key_down(klawiatura, ALLEGRO_KEY_BACKSPACE) && haslo.size() > 0)
        {
            haslo = haslo.substr(0, haslo.size() - 1);
        }

        // zatwierdzanie hasla i przejscie do rozgrywki
        if (al_key_down(klawiatura, ALLEGRO_KEY_ENTER) && haslo.size() > 0)
        {
            indeksyOdgadnietych.clear();
            for (unsigned int i = 0; i < haslo.size(); i++)
            {
                indeksyOdgadnietych.push_back(0);
            }
            zainicjowana = true;
        }
    }

    // resetowanie opcji
    void reset()
    {
        wybor = 0;
        klatka = 0;
        odgadniete = "";
        uzyte = "";
        pozostale = "";
        haslo = "";
        zainicjowana = false;
    }

    // wyswietla wynik zakonczonej rozgrywki
    void wyswietlResultat()
    {
        if (wygrana)
        {
            al_draw_text(bigFont, al_map_rgb(0, 0, 0), 220, 250, ALLEGRO_ALIGN_LEFT, "WYGRANA");
        }
        else
        {
            al_draw_text(bigFont, al_map_rgb(0, 0, 0), 220, 250, ALLEGRO_ALIGN_LEFT, "PRZEGRANA");
        }
    }

    void koniecTury()
    {
        reset();
        wyswietlResultat();

        wygrana = false;

        al_flip_display();
        al_rest(1.5);

        faza = 2;
        tura++;
    }

    // sprawdza wpisana litery podczas gry
    bool sprawdzWyborLitery(ALLEGRO_KEYBOARD_STATE* klawiatura)
    {
        for (int klawisz = ALLEGRO_KEY_A; klawisz <= ALLEGRO_KEY_Z; klawisz++)
        {
            // jesli jakis klawisz jest wcisniety
            if ( al_key_down(klawiatura, klawisz ))
            {
                // wyznacza litere z kodu klawisza
                char litera = (char)(klawisz - 1 + 'a');
                string s(1, litera);

                // o ile nie byla jeszcze uzyta
                if (uzyte.find(s) == string::npos)
                {
                    uzyte += s;

                    // jesli jest w hasle
                    if (haslo.find(s) != string::npos)
                    {
                        odgadniete += s;

                            for (unsigned int i = 0; i < haslo.size(); i++)
                            {
                                indeksyOdgadnietych[i] = (odgadniete.find(haslo[i]) != string::npos);
                            }
                    }
                    // jesli nie ma jej w hasle
                    else
                    {
                        pozostale += s;
                        klatka++;
                    }
                }

            }

            // sprawdza czy sa jeszcze jakies puste
            bool puste = false;
            for (unsigned int i = 0; i < indeksyOdgadnietych.size(); i++)
            {
                if (!indeksyOdgadnietych[i])
                {
                    puste = true;
                    break;
                }
            }

            // jesli nie ma to jest go wygrana
            if (!puste && zainicjowana)
            {
                wygrana = true;

                if (rodzajGry == 0)
                {
                    punkty1++;
                }
                else
                {
                    if (tura % 2 == 0) punkty2++;
                    else punkty1++;
                }


            }

            // sprawdza koniec gry
            if (zainicjowana && (wygrana || klatka == ostatniaKlatka))
            {
                koniecTury();
            }
        }
        return 0;
    }


    bool gra(ALLEGRO_KEYBOARD_STATE* klawiatura)
    {
        // inicjalizacja dla gry jednoosobowej
        if (rodzajGry == 0 && !zainicjowana)
        {
            inicjujDlaJednegoGracza();
        }

        // inicjalizacja dla gry dwuosobowej
        if (rodzajGry == 1 && !zainicjowana)
        {
            inicjujDlaDwochGraczy(klawiatura);
        }

        // uspienie na pewien czas (zeby np nie dublowalo liter podczas ustawiania hasla)
        if (!zainicjowana)
        {
            al_rest(0.08);
        }
        // sprawdzenie liter podczas rozgrywki
        else
        {

            string punkty1Str = string("Gracz1: ") + intToStr(punkty1) + " pkt";
            al_draw_text(font, al_map_rgb(0, 0, 0), 20, 20, ALLEGRO_ALIGN_LEFT, punkty1Str.c_str());

            if (rodzajGry == 1)
            {
                string punkty2Str = string("Gracz2: ") + intToStr(punkty2) + " pkt";
                al_draw_text(font, al_map_rgb(0, 0, 0), 20, 50, ALLEGRO_ALIGN_LEFT, punkty2Str.c_str());
            }


            int koniec = sprawdzWyborLitery(klawiatura);
            if (koniec)
            {
                return 1;
            }
            rysuj();
        }

        return 0;
    }
};

int main()
{
    // rozmiary okna
    const int W = 800;
    const int H = 600;

    // ustawienie ziarna generatora pseudolosowego
    srand(time(NULL));

    // inicjalizacja srodowiska allegro
	al_init();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();

	ALLEGRO_KEYBOARD_STATE klawiatura;
	al_set_new_display_flags(ALLEGRO_WINDOWED);
	ALLEGRO_DISPLAY *okno = al_create_display(W, H);
	ALLEGRO_EVENT_QUEUE *kolejka = al_create_event_queue();
	al_register_event_source(kolejka, al_get_display_event_source(okno));
	ALLEGRO_EVENT zdarzenie;

    Wisielec wisielec;
	wisielec.wczytajHasla();

    // dopoki nie zostanie wcisniety ESC
	while (!al_key_down(&klawiatura, ALLEGRO_KEY_ESCAPE))
	{
	    // sprawdza kolejne zdarzenie
	    al_get_next_event(kolejka, &zdarzenie);

        // jesli zdarzeniem jest zamkniecie okna to wychodzi z gry
		if(zdarzenie.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			return 0;
		}

        // czysci ekran
        al_clear_to_color(al_map_rgb(200, 255, 200));


        // sprawdza stan klawiatury
		al_get_keyboard_state(&klawiatura);

        // strzalka w gore - poprzednia opcja w menu
        if ( al_key_down(&klawiatura, ALLEGRO_KEY_UP))
        {
            wisielec.poprzedniaOpcjaMenu();
        }
        // strzalka w dol - kolejna opcja w menu
        if ( al_key_down(&klawiatura, ALLEGRO_KEY_DOWN))
        {
            wisielec.nastepnaOpcjaMenu();
        }
        // enter - zatwierdzenie opcji w menu
        if ( al_key_down(&klawiatura, ALLEGRO_KEY_ENTER))
        {
            bool czyWyjscie = !wisielec.wyborOpcji();
            if (czyWyjscie)
            {
                break;
            }
        }
	    if (wisielec.czyMenu())
        {
            wisielec.menuStartowe(); // wyswietlenie menu
        }
	    else if (wisielec.czyRozgrywka()) // rozgrywka
        {
            bool czyKoniec = wisielec.gra(&klawiatura);
            if (czyKoniec)
            {
                break;
            }
        }
        else
        {
            wisielec.menuPoTurze();
        }
		al_flip_display(); // naniesienie zmian graficznych na ekran
		al_rest(0.05); // uspienie

	}
	al_destroy_display(okno); // zamkniecie okna graficznego
	return 0;
}
