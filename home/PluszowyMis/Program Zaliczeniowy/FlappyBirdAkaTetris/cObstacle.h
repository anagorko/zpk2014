#ifndef COBSTACLE_H_
#define COBSTACLE_H_

#include<iostream>
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>

#include "cPipe.h"
using namespace std;


class cObstacle{
private:
    cPipe* topPipe;
    cPipe* bottomPipe;
    int holeY;
    int holeSize;
    int orderNumber = 0;
public:
    bool Counted = false;
    void moveLeft(float value);
    cObstacle(int previousHole);
    ~cObstacle();
    float frontX();
    float backX();
    float topHoleY();
    float bottomHoleY();
    int getHoleSize();
    void setHoleSize(int inputValue);
    float getBitmapPointTopX();
    float getBitmapPointTopY();
    float getBitmapPointBottomX();
    float getBitmapPointBottomY();
    cPipe getTopPipeByVal();
    cPipe getBottomPipeByVal();
    cPipe* getTopPipe();
    cPipe* getBottomPipe();
    void drawObstacle();
};

#endif // COBSTACLE_H_
