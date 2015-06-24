#include<iostream>
#include<cstdlib>
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<ctime>
#include<random>

#include "cObstacle.h"

using namespace std;

const int MINIMUM_HOLE_SIZE = 70;
const int MAXIMUM_HOLE_SIZE = 100;
const float MAXIMUM_HOLE_DIFFERENCE_Y = 300.0;
const int MAX_DIFFERENCE_OBSTACLE = 200;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
char* PIPE_DIR_BITMAP = "images/wall.jpg";

//constructor
cObstacle::cObstacle(int previousHole){
    //previousHole jest to górna krawędź dziury
    // doskonale wiem, że zostaną ucięte wartości dziesiętne
    // jednak nie jest potrzebne dokładne wyliczenie wartości dla hole
    // dlatego nie widzę problemów, żeby dokonać niejawnej konwersji


    int upLimitValue = previousHole - MAXIMUM_HOLE_DIFFERENCE_Y > MINIMUM_HOLE_SIZE ? previousHole - MAXIMUM_HOLE_DIFFERENCE_Y : MINIMUM_HOLE_SIZE;
    int downLimitValue = previousHole + MAXIMUM_HOLE_DIFFERENCE_Y + MINIMUM_HOLE_SIZE < SCREEN_HEIGHT ? previousHole + MAXIMUM_HOLE_DIFFERENCE_Y : (float)SCREEN_HEIGHT - MINIMUM_HOLE_SIZE;
    srand(time(0)-rand());
    this->holeY = upLimitValue + (rand() * (int)(downLimitValue - upLimitValue)/RAND_MAX); //rand()%downLimitValue + upLimitValue;
    int aaa = (rand() * (int)(downLimitValue - upLimitValue)/RAND_MAX) + upLimitValue;
    this->holeY = aaa;
    //wylosowanie i ustalenie wielkości dziury
    srand(time(0));


    srand(time(0));
    if(this->holeY > SCREEN_HEIGHT - MINIMUM_HOLE_SIZE - MAXIMUM_HOLE_SIZE){
        this->setHoleSize(rand()%(SCREEN_HEIGHT - MINIMUM_HOLE_SIZE - this->holeY) + MINIMUM_HOLE_SIZE);
    } else{
        this->setHoleSize(rand()%MAXIMUM_HOLE_SIZE + MINIMUM_HOLE_SIZE);
    }


    // na podstawie holeSize oraz holeY, zostaną utworzone
    // nowe instancje dla topPipe i bottomPipe

    this->topPipe = new cPipe(true, (float)holeY, PIPE_DIR_BITMAP);
    this->bottomPipe = new cPipe(false, (float)(SCREEN_HEIGHT - this->holeY - this->getHoleSize()), PIPE_DIR_BITMAP);
}
//destructor
cObstacle::~cObstacle(){
    delete this->topPipe;
    delete this->bottomPipe;
}

//methods
void cObstacle::moveLeft(float moveObstacleValue){
    this->topPipe->moveLeft(moveObstacleValue);
    this->bottomPipe->moveLeft(moveObstacleValue);
    //samobójstwo obiektu gdy wyjdzie poza ekran
//    if(this->topPipe->getTopRight()->getX() < 0){
//        delete this*;
//    }
}

float cObstacle::frontX(){
    return this->topPipe->getTopRight().getX();
}
float cObstacle::backX(){
    return this->topPipe->getTopLeft().getX();
}
float cObstacle::topHoleY(){
    return this->topPipe->getBottomLeft().getY();
}
float cObstacle::bottomHoleY(){
    return this->bottomPipe->getTopLeft().getY();
}

void cObstacle::drawObstacle(){
    al_draw_scaled_bitmap(this->topPipe->bitmapObj
                          , 0
                          , 0
                          , 60
                          , 200
                          , this->topPipe->getTopLeft().getX()
                          , this->topPipe->getTopLeft().getY()
                          , 60
                          , this->topPipe->getHeight()
                          , false);
    al_draw_scaled_bitmap(this->bottomPipe->bitmapObj
                          , 0
                          , 0
                          , 60
                          , 200
                          , this->bottomPipe->getTopLeft().getX()
                          , this->bottomPipe->getTopLeft().getY()
                          , 60
                          , this->bottomPipe->getHeight()
                          , false);
}

//getter
int cObstacle::getHoleSize(){
    return this->holeSize;
}
float cObstacle::getBitmapPointTopX(){
    return this->topPipe->getTopLeft().getX();
}
float cObstacle::getBitmapPointTopY(){
    return this->topPipe->getTopLeft().getY();
}
float cObstacle::getBitmapPointBottomX(){
    return this->bottomPipe->getTopLeft().getX();
}
float cObstacle::getBitmapPointBottomY(){
    return this->bottomPipe->getTopLeft().getY();
}
cPipe cObstacle::getTopPipeByVal(){
    cPipe returnPipe(this->topPipe->getIsTopPipe(), this->topPipe->getHeight(), PIPE_DIR_BITMAP);
    return returnPipe;
}
cPipe cObstacle::getBottomPipeByVal(){
    cPipe returnPipe(this->bottomPipe->getIsTopPipe(), this->bottomPipe->getHeight(), PIPE_DIR_BITMAP);
    return returnPipe;
}
cPipe* cObstacle::getTopPipe(){
    return this->topPipe;
}
cPipe* cObstacle::getBottomPipe(){
    return this->bottomPipe;
}

//setter
void cObstacle::setHoleSize(int inputValue){
    this->holeSize = inputValue;
}
