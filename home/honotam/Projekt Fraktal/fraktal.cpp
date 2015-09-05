#include "fraktal.h"
#include <math.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>

Fraktal::Fraktal()
{
}

double Fraktal::transX(const double& _x)
{
	return (( _x + 350 )/700 * ( maximumX - minimumX )) + minimumX;
}

double Fraktal::transY(const double& _y)
{
	return (( _y + 300 )/600 * ( maximumY - minimumY )) + minimumY;
}

// RYSOWANIE FRAKTALA
// Oś X oznacza wartości reczywiste, natomiast os Y wartości urojone
// Przedstawiając kolejne przybliżenia na płaszczyźnie (lewy górny róg ma współrzędne -2.0 + -1.25i,
// dolny prawy róg ma współrzędne 0.5 + 1.25i) i oznaczając je różnymi kolorami otrzymujemy wynik - zbiór Mandelbrota
double Fraktal::oblicz (const double& _x, const double& _y)
	{
	int n = 0;
	int iter_max = 200;
	double rmax = 4 * sqrt((_x * _x) + (_y * _y)); //Moduł z liczby zespolonej definiujemy następująco
	double real = 0;
	double imaginary = 0;
	double xx = 0;
	double r;
	for (n = 0; n < iter_max; ++n)
		{
		xx = ( real * real ) - ( imaginary * imaginary ) + _x;
		imaginary = 2 * (real * imaginary ) + _y;
		real = xx;
		r = sqrt( ( real * real ) + ( imaginary * imaginary ) );
		if ( r > rmax )
        break;
		}
    return iter_max - n;
	}

double Fraktal::kolor (const double &_x, const double& _y)
{
	return oblicz(transX(_x),transY(_y));
}

void Fraktal::setScale (const double& _x, const double& _y)
{
            double pixelWidth = (maximumX - minimumX) / 700;
            double pixelHeight = (maximumY - minimumY) / 600.0;

            double newWidth = (maximumX - minimumX) / 4.0;
            double newHeight = (maximumY - minimumY) / 4.0;

            minimumX = (minimumX + _x * pixelWidth) - newWidth / 2;
            minimumY = (minimumY + _y * pixelHeight) - newHeight / 2;

            maximumX = minimumX + newWidth;
            maximumY = minimumY + newHeight;
}

double Fraktal::getXmin()
{
    return minimumX;
}

double Fraktal::getXmax()
{
    return maximumX;
}

double Fraktal::getYmin()
{
    return minimumY;
}
double Fraktal::getYmax()
{
    return maximumY;
}

void Fraktal::setZoom(double _z)
{
    z = _z;
}

void Fraktal::setPointX(double _px)
{
    px = _px;
}

void Fraktal::setPointY(double _py)
{
    py = _py;
}

void Fraktal::Statystyki()
{
    ALLEGRO_FONT *fonty = al_load_font("fonts\\Ubuntu-B.ttf", 20, 0);
    al_draw_text(fonty, al_map_rgb(212, 172, 247), 848.5, 275, ALLEGRO_ALIGN_CENTER, "Coordinates of Mandelbrot’s");
    al_draw_text(fonty, al_map_rgb(212, 172, 247), 848.5, 295, ALLEGRO_ALIGN_CENTER, "Fractal");

    ALLEGRO_FONT *fonty2 = al_load_font("fonts\\Ubuntu-B.ttf", 13, 0);
    al_draw_text(fonty2, al_map_rgb(191, 149, 228), 710, 340, ALLEGRO_ALIGN_LEFT, "Original");
    al_draw_text(fonty2, al_map_rgb(191, 149, 228), 710, 360, ALLEGRO_ALIGN_LEFT, "Top left corner:");
    al_draw_text(fonty2, al_map_rgb(191, 149, 228), 860, 360, ALLEGRO_ALIGN_LEFT, "(  0.5000  ,  1.2500 )");
    al_draw_text(fonty2, al_map_rgb(191, 149, 228), 710, 380, ALLEGRO_ALIGN_LEFT, "Bottom right corner:");
    al_draw_text(fonty2, al_map_rgb(191, 149, 228), 860, 380, ALLEGRO_ALIGN_LEFT, "( -2.0000 ,-1.2500 )");


    al_draw_text(fonty2, al_map_rgb(191, 149, 228), 710, 405, ALLEGRO_ALIGN_LEFT, "After Zoom");
    al_draw_text(fonty2, al_map_rgb(191, 149, 228), 710, 425, ALLEGRO_ALIGN_LEFT, "Top left corner:");
    al_draw_text(fonty2, al_map_rgb(191, 149, 228), 860, 425, ALLEGRO_ALIGN_LEFT, "(");
    al_draw_textf(fonty2, al_map_rgb(191, 149, 228), 892, 425, ALLEGRO_ALIGN_CENTER, "%.4f", getXmax());
    al_draw_text(fonty2, al_map_rgb(191, 149, 228), 920, 425, ALLEGRO_ALIGN_LEFT, ", ");
    al_draw_textf(fonty2, al_map_rgb(191, 149, 228), 950, 425, ALLEGRO_ALIGN_CENTER, "%.4f", getYmax());
    al_draw_text(fonty2, al_map_rgb(191, 149, 228), 978, 425, ALLEGRO_ALIGN_LEFT, ") ");
    al_draw_text(fonty2, al_map_rgb(191, 149, 228), 710, 445, ALLEGRO_ALIGN_LEFT, "Bottom right corner:");
    al_draw_text(fonty2, al_map_rgb(191, 149, 228), 860, 445, ALLEGRO_ALIGN_LEFT, "(");
    al_draw_textf(fonty2, al_map_rgb(191, 149, 228), 892, 445, ALLEGRO_ALIGN_CENTER, "%.4f", getXmin());
    al_draw_text(fonty2, al_map_rgb(191, 149, 228), 920, 445, ALLEGRO_ALIGN_LEFT, ", ");
    al_draw_textf(fonty2, al_map_rgb(191, 149, 228), 950, 445, ALLEGRO_ALIGN_CENTER, "%.4f", getYmin());
    al_draw_text(fonty2, al_map_rgb(191, 149, 228), 978, 445, ALLEGRO_ALIGN_LEFT, ")");

    al_draw_text(fonty2, al_map_rgb(191, 149, 228), 710, 480, ALLEGRO_ALIGN_LEFT, "Zoom");
    al_draw_text(fonty2, al_map_rgb(191, 149, 228), 775, 480, ALLEGRO_ALIGN_LEFT, "x"); // x3 razy
    al_draw_textf(fonty2, al_map_rgb(191, 149, 228), 783, 480, ALLEGRO_ALIGN_LEFT, "%.0f", z);
    al_draw_text(fonty2, al_map_rgb(191, 149, 228), 710, 498, ALLEGRO_ALIGN_LEFT, "At point:");
    al_draw_text(fonty2, al_map_rgb(191, 149, 228), 775, 498, ALLEGRO_ALIGN_LEFT, "(");
    al_draw_textf(fonty2, al_map_rgb(191, 149, 228), 782, 498, ALLEGRO_ALIGN_LEFT, "%.0f", px);
    al_draw_text(fonty2, al_map_rgb(191, 149, 228), 810, 498, ALLEGRO_ALIGN_LEFT, ", ");
    al_draw_textf(fonty2, al_map_rgb(191, 149, 228), 820, 498, ALLEGRO_ALIGN_LEFT, "%.0f", py);
    al_draw_text(fonty2, al_map_rgb(191, 149, 228), 845, 498, ALLEGRO_ALIGN_LEFT, ")");

    ALLEGRO_FONT *fonty3 = al_load_font("fonts\\Ubuntu-R.ttf", 11, 0);
    al_draw_text(fonty3, al_map_rgb(191, 149, 228), 710, 520, ALLEGRO_ALIGN_LEFT, "Range for x is from 0 to 700");
    al_draw_text(fonty3, al_map_rgb(191, 149, 228), 710, 532, ALLEGRO_ALIGN_LEFT, "Range for y is from 0 to 600");
}
