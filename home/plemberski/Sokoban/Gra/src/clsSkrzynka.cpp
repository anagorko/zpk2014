#include "clsSkrzynka.h"
/* *********************************************************************************************************************************************** */
    const string clsSkrzynka::plik_z_grat[1] =
    {
        "kafelki/gratulacje.png"
    };

//konstruktor
    clsSkrzynka::clsSkrzynka(clsPlansza p)
    {   for(int i = 0; i < intWiersze; i++)
        {   for(int j = 0; j < intKolumny; j++)
            {   tblSkrzynkiS[i][j] = p.get_tblSkrzynkiP(i, j);
            }
        }
    }

//funkcje
    int clsSkrzynka::CzyUkonczono(clsPlansza& p)
    {   bool ukonczono = 1;

        for(int i = 0; i < intWiersze; i++) //sprawdza czy skrzynki stoja na Celach
        {   for(int j = 0; j < intKolumny; j++)
            {   if(tblSkrzynkiS[i][j] == 1 && p.get_tblPodloga(i, j) != 6)
                {   ukonczono = 0;
                }
            }
        }

        if (ukonczono)  //jesli ukonczono plansze zapisuje te informacje w tabeli oraz przestawaia level o jeden dalej
        {   p.set_tblUkonczone(ukonczono);

            int a = p.get_level() + 1;
            p.set_level(a);
       }

       if(p.get_level() > p.get_LiczbaPlansz()) // sprawdza czy to ostania plansza
       {
           WyswietlGrat();
           zwloka(3);
           return 2;

       }
        return ukonczono;
    }

    void clsSkrzynka::WyswietlGrat()
    {
        ALLEGRO_BITMAP* wskGrat[1];
        wskGrat[0] = al_load_bitmap(plik_z_grat[0].c_str());

        al_clear_to_color(al_map_rgb(0,0,0));
        al_draw_bitmap_region(wskGrat[0], 0, 0, 1240, 600, 0, 0, 0);
        al_flip_display();
    }

    void clsSkrzynka::zwloka(int sekund)
    {   time_t poczatkowy_czas = time(NULL);
        while(time(NULL) - poczatkowy_czas < sekund);
    }
