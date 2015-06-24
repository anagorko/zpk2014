#include<iostream>
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>

#include "cTetris.h"

using namespace std;

const int MAXIMUM_FLYING_TIME = 15;
const int HEIGHT_TETRIS = 40;
const int WIDTH_TETRIS = 40;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;


//constructor
cTetris::cTetris(string dirToBitmap){
    this->bitmapName = dirToBitmap;
    this->loadBitmap(this->bitmapName);

    //utworzenie punktów gdzie znajduje się tetris
    cPoint startPlace(15.0f, (SCREEN_HEIGHT - 15.0f) / 2);
    this->setTopLeft(startPlace);
    this->setFTopRight(startPlace.getX() + WIDTH_TETRIS, startPlace.getY());
    this->setFBottomLeft(startPlace.getX(), startPlace.getY() + HEIGHT_TETRIS);
    this->setFBottomRight(this->getTopRight().getX(), this->getBottomLeft().getY());

}
//destructor
cTetris::~cTetris(){
//    delete this->bitmapObj;
}

//methods
void cTetris::fly(float flyValue){
    if(this->stillFlying()){
        //Y -> w górę maleje
        flyValue *= (-1);
    }

    this->topLeft.setY(this->topLeft.getY() + flyValue);
    this->topRight.setY(this->topRight.getY() + flyValue);
    this->bottomLeft.setY(this->bottomLeft.getY() + flyValue);
    this->bottomRight.setY(this->bottomRight.getY() + flyValue);

    //zmienić umiejscowienie bitmapy
}
void cTetris::startFly(){
    this->isFlying = true;
    this->flyCounter = 0;
}
bool cTetris::stillFlying(){
    return (this->isFlying && this->flyCounter < MAXIMUM_FLYING_TIME);
}
bool cTetris::collidesWithObstacle(cObstacle& dangerObject){
    bool resultOfCollides = false;

    if((this->frontX() >= dangerObject.backX() && this->frontX() <= dangerObject.frontX())
       || (this->backX() >= dangerObject.backX() && this->backX() <= dangerObject.frontX())){
        if(this->topY() <= dangerObject.topHoleY() || this->bottomY() >= dangerObject.bottomHoleY()){
            resultOfCollides = true;
        }
    }
    return resultOfCollides;
}
bool cTetris::collidesWithBoard(){
    bool returnValue = false;
    //cout << this->topY() << " " << this->bottomY() << endl;
    if(this->topY() < 0 || this->bottomY() > SCREEN_HEIGHT){
        returnValue = true;
    }

    return returnValue;
}

void cTetris::incrementFly(){
    this->flyCounter++;
}
void cTetris::stopFly(){
    this->isFlying = false;
    this->flyCounter = 0;
}
void cTetris::incrementGotPoints(){
    this->obstacleCounter++;
}

void cTetris::drawTetris(){
    al_draw_bitmap(this->bitmapObj
                       , this->getTopLeft().getX()
                       , this->getTopLeft().getY()
                       , 0);
}

//getters
int cTetris::getObstacleCounter(){
    return obstacleCounter;
}


