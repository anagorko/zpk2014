#include <iostream>
#include <math.h>
using namespace std;
#include "display.h"
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

int calculate (double _x, double _y)
	{
	int n=0;
	int imax=30;
	double rmax = 0.3;
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
		if (r < rmax)
			break;
		}
	if (n==imax) return 0;
	return 1;
	}

double color (double _x, double _y)
	{
	return calculate(translateX(_x),translateY(_y));
	}

int main ()
	{
	Display *d = new Display();
	int c = 0;
	d->init();
	d->clear();
	for (_y=-300; _y<300 ; _y++)
		{
		for (_x=-400; _x<400; _x++)
			{
			c = color(_x, _y);
			if (c>0) d->drawPoint ( _x, _y);
			}
		}
	d->show();
	system("pause");
	return 0;
	}
