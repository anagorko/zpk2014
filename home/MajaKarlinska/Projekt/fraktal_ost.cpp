#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include <iostream>
#include <math.h>
using namespace std;
#include "stdio.h"

double cXmin = -2, cYmin = -1.5;
double cXmax = 2, cYmax = 1.5;
double w = cXmax - cXmin;
double h = cYmax - cYmin;
double _x,_y;

double translateX(double _x)
	{
	return ((_x+400)/800*(cXmax-cXmin))+cXmin;
	}

double translateY(double _y)
	{
	return ((_y+300)/600*(cYmax-cYmin))+cYmin;
	}

const int max_iters = 255;

int calculate (double _x, double _y)
	{
	int n=0;
	int imax=max_iters;
	double rmax = 3*sqrt(_x*_x + _y*_y);
	double x=0;
	double y=0;
	double xx=0;
	double r;
	for (n=0; n < imax; ++n)
		{
		xx = x*x-y*y+_x;
		y=2*x*y+_y;
		x=xx;
		r=sqrt(x*x+y*y);
		if (r > rmax)
			break;
		}
        return imax - n;
	}

double color (double _x, double _y)
	{
	return calculate(translateX(_x),translateY(_y));
	}

int main (int, char**)
{
	ALLEGRO_DISPLAY *display = NULL;

	if(!al_init()) {
        	cerr << "Błąd podczas inicjalizacji allegro." << endl;
        	assert(false);
    	}

    	if (!al_init_primitives_addon()) {
        	cerr << "Błąd podczas inicjalizacji dodatku 'primitives'." << endl;
        	assert(false);
    	}

    	display = al_create_display(800, 600);

    	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
        if(!al_install_mouse()) {
                cout <<  "failed to initialize the mouse!" << endl;
                return -1;
        }
        event_queue = al_create_event_queue();
        if (!event_queue) {
                cout << "fail" << endl;
                return -1;
        }
        al_register_event_source(event_queue, al_get_mouse_event_source());
        
    	while (true)
    	{
                ALLEGRO_EVENT ev;
                al_wait_for_event(event_queue, &ev);

                if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
                        cout << "wcisniety klawisz " << ev.mouse.x << " " << ev.mouse.y << endl;

                        double x = ev.mouse.x;
                        double y = ev.mouse.y;
                        
                        double pixelWidth = (cXmax - cXmin) / 800.0;
                        double pixelHeight = (cYmax - cYmin) / 600.0;
                        
                        double newWidth = (cXmax - cXmin) / 4.0;
                        double newHeight = (cYmax - cYmin) / 4.0;
                        
                        
                        cXmin = (cXmin + x * pixelWidth) - newWidth / 2;
                        cYmin = (cYmin + y * pixelHeight) - newHeight / 2;
                        
                        cXmax = cXmin + newWidth;
                        cYmax = cYmin + newHeight;
                }
                
                if (al_is_event_queue_empty(event_queue)) {
                    	// rysowanie fraktala
                    	int c = 0;
                    	al_clear_to_color(al_map_rgb(0,0,0));
                    	for (_y=-300; _y<300 ; _y++)
		        {
		                for (_x=-400; _x<400; _x++)
			        {
				        c = color(_x, _y);
				        if (c>0) {
				                al_draw_pixel(_x+800/2,_y+600/2, al_map_rgb(c * 255 / max_iters,c * 255 / max_iters, c * 255 / max_iters));
				                }
                                }
                        }
        		al_flip_display();

        		cout << "Rozmiary: " << cXmin << " " << cYmin << " " << cXmax << " " << cYmax << endl;
		}
		
        }
        
	return 0;
}
