#ifndef COBJECT_H_
#define COBJECT_H_


//biblioteki standardowe:
#include<iostream>
#include<string>

//biblioteka graficzna:
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>

#include "cPoint.h"

using namespace std;

class cObject{
protected:
    cPoint topLeft;
    cPoint topRight;
    cPoint bottomLeft;
    cPoint bottomRight;
    void loadBitmap(string dirToLoad);

public:
    cPoint getTopLeft();
    cPoint getTopRight();
    cPoint getBottomLeft();
    cPoint getBottomRight();
    void setTopLeft(cPoint inputValue);
    void setTopRight(cPoint inputValue);
    void setBottomLeft(cPoint inputValue);
    void setBottomRight(cPoint inputValue);
    void setFTopLeft(float x, float y);
    void setFTopRight(float x, float y);
    void setFBottomLeft(float x, float y);
    void setFBottomRight(float x, float y);

    void setObject(float tl_x, float tl_y, float tr_x, float tr_y, float bl_x, float bl_y, float br_x, float br_y);
    float frontX();
    float backX();
    float topY();
    float bottomY();

    ALLEGRO_BITMAP* bitmapObj;
};

#endif // COBJECT_H_
