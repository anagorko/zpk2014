#include<iostream>
#include<vector>
#include<math.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <cstdio>
#include "bitmap_image.hpp"
using namespace std;

class Display
{
    ALLEGRO_DISPLAY *display = NULL;

    double cXmin = 0.20, cYmin = 0.54;
    double cXmax = 0.22, cYmax = 0.55;
    double w = cXmax - cXmin;
    double h = cYmax - cYmin;
    int n = 0;

public:
    void init();
    void close();
    void show();
    double drawPoint(double, double);
    void clear();

};

void Display::clear()
{
    al_clear_to_color(al_map_rgb(0,0,0));
}

void Display::init()
{
    if(!al_init()) {
        cerr << "Błąd podczas inicjalizacji allegro." << endl;
        assert(false);
    }

    if (!al_init_primitives_addon()) {
        cerr << "Błąd podczas inicjalizacji dodatku 'primitives'." << endl;
        assert(false);
    }

    display = al_create_display(w, h);

    if(!display) {
        cerr << "Błąd podczas inicjalizacji ekranu." << endl;
        assert(false);
    }

    clear(); show();
}

void Display::show()
{
    al_flip_display();
}

double Display::drawPoint(double x, double y)
{
    al_draw_filled_circle(x+w/2,y+h/2,2, al_map_rgb(255,255,255));
}

/*class Plansza
{
    double cXmin, cXmax, cYmin, cYmax;

public:
    Plansza() : Plansza(0.0, 0.0) {
    }
    Plansza(double _cXmin, double _cXmax,double _cYmin, double _cYmax)
    {
        setX_min(_cXmin)
        setX_max(_cXmax);
        setY_min(_cYmin);
        setY_max(_cYmax);
    }

virtual void draw(Display) = 0;

void draw(Graphics g)
{
    int kMax = ClientSize.Width;
    int lMax = ClientSize.Height;
    Bitmap płótno = new Bitmap(kMax, lMax);
    for (int l = 0; l < lMax; l++)
    for (int k = 0; k < kMax; k++)
    {
        double cX, cY;
        cX = cXmin + k * (cXmax – cXmin) / kMax; cY = cYmin + l * (cYmax – cYmin) / lMax;
        płótno.SetPixel(k, l, KolorPunktuFraktala(cX, cY));
        g.DrawImage(płótno, 0, 0);
    }
}

int main;
    cin >> "podaj cXmax " >> cXmax >> endl;
    cin >> "podaj cYmax " >> cYmax >> endl;
    cin >> "podaj cXmin " >> cXmin >> endl;
    cin >> "podaj cYmin " >> cYmin >> endl;
;*/

/*Display Fraktal(double x, double y)
{


    double cXmin = 0.20, cYmin = 0.54;
    double cXmax = 0.22, cYmax = 0.55;
    double w = cXmax - cXmin;
    double h = cYmax - cYmin;
    double wMax = cXmax - cXmin;
    double hMax = cYmax - cYmin;
    double cX = cXmin + w*(cXmax-cXmin)/wMax;
    double cY = cYmin + h*(cYmax-cYmin)/hMax;
    double _x,_y;
    _x = _y = 0;
    int n = 0;
}*/

int main ()
{

    double cXmin = 0.20, cYmin = 0.54;
    double cXmax = 0.22, cYmax = 0.55;
    double w = cXmax - cXmin;
    double h = cYmax - cYmin;
    bitmap_image image(w,h);
    double wMax = cXmax - cXmin;
    double hMax = cYmax - cYmin;

    for (int w = 0; w < wMax; w++)
        for (int h = 0; h < hMax; h++)
            {
            ALLEGRO_DISPLAY *display = NULL;
            // tworzy okno
            display = al_create_display(w, h);
            // sprawdzenie czy okno się utworzylo
            if(!display) {
            return 1;

            double cX = cXmin + w*(cXmax-cXmin)/wMax;
            double cY = cYmin + h*(cYmax-cYmin)/hMax;
            double _x,_y;
            _x = _y = 0;
            int n = 0;
            for (0 < n < 255; n++;)
            {
                double xNastepny= _x*_x - _y*_y +cX;
                double yNastepny= 2*_x*_y +cY;
                if (xNastepny*xNastepny + yNastepny*yNastepny > 4)
                    break;
                else
                {
                    _x= xNastepny;
                    _y= yNastepny;
                }
            }

    if (n<255)
        drawPoint(_x,_y);


    //double drawPoint(double x, double y)
    //al_draw_filled_circle(x+w/2,y+h/2,2, al_map_rgb(255,255,255));
    //drawPoint(_x, _y);
    //else
        //kolor = Color(n/255);
   // return kolor;
}
}
}


