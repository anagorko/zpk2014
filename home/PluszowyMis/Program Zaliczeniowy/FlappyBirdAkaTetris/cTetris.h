#ifndef CTETRIS_H_
#define CTETRIS_H_

#include<string>
#include<iostream>
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include "cObject.h"
#include "cObstacle.h"

using namespace std;

class cTetris:public cObject{
private:
    string bitmapName = "";
    int flyCounter = 0;
    bool isFlying = false;
    int obstacleCounter = 0;
public:
    cTetris(string dirToBitmap);
    ~cTetris();
    void fly(float flyValue);
    void startFly();
    bool stillFlying();
    bool collidesWithObstacle(cObstacle& dangerObject);
    bool collidesWithBoard();
    int getObstacleCounter();
    int GotPoints = 0;
    void incrementGotPoints();
    void incrementFly();
    void stopFly();
    void drawTetris();
};

#endif // CTETRIS_H_
