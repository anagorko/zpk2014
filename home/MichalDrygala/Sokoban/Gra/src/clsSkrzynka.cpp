#include "clsSkrzynka.h"

//konstruktor
    clsSkrzynka::clsSkrzynka(clsPlansza p)
    {   for(int i = 0; i < intWiersze; i++)
        {   for(int j = 0; j < intKolumny; j++)
            {   tblSkrzynkiS[i][j] = p.get_tblSkrzynkiP(i, j);
            }
        }
    }

//destruktor
    clsSkrzynka:: ~clsSkrzynka()
    {
        delete []tblSkrzynkiS;
    }

