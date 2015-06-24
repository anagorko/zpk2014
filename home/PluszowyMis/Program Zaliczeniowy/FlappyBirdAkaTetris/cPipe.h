#ifndef CPIPE_H_
#define CPIPE_H_

#include<iostream>

#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>

#include "cObject.h"
#include "cPoint.h"

using namespace std;

class cPipe:public cObject{
private:
    bool isTopPipe = true;
    float height;
    float width;
    float startHeight;
    void resizeBitmap();
public:
    cPipe(bool isTop, float inputHeight, char* bitmapDir);
    float getHeight();
    float getStartHeight();
    bool getIsTopPipe();
    void moveLeft(float moveValue);
    float getWidth();

};

#endif // CPIPE_H_
