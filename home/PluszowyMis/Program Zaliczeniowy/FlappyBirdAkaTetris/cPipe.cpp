#include<iostream>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "cPipe.h"
using namespace std;

const int HEIGHT_PIPE = 200;
const int WIDTH_PIPE = 60;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;


//constructor
cPipe::cPipe(bool isTop, float inputHeight, char* bitmapDir){
    this->startHeight = HEIGHT_PIPE;

    this->isTopPipe = isTop;
    this->height = inputHeight;
    this->width = WIDTH_PIPE;
    this->loadBitmap(bitmapDir);

    if(isTop){
        this->setFTopLeft(SCREEN_WIDTH, 0.0);
        this->setFTopRight(SCREEN_WIDTH + WIDTH_PIPE, 0.0);
        this->setFBottomLeft(SCREEN_WIDTH, this->getHeight());
        this->setFBottomRight(SCREEN_WIDTH + WIDTH_PIPE, this->getHeight());
    } else{
        this->setFTopLeft(SCREEN_WIDTH, SCREEN_HEIGHT - this->getHeight());
        this->setFTopRight(SCREEN_WIDTH + WIDTH_PIPE, SCREEN_HEIGHT - this->getHeight());
        this->setFBottomLeft(SCREEN_WIDTH, SCREEN_HEIGHT);
        this->setFBottomRight(SCREEN_WIDTH + WIDTH_PIPE, SCREEN_HEIGHT);
    }

}

//getter:
float cPipe::getHeight(){
    return this->height;
}
bool cPipe::getIsTopPipe(){
    return this->isTopPipe;
}
float cPipe::getWidth(){
    return this->width;
}
float cPipe::getStartHeight(){
    return this->startHeight;
}

//methods:
void cPipe::moveLeft(float moveValue){
    this->topLeft.setX(this->topLeft.getX() - moveValue);
    this->topRight.setX(this->topRight.getX() - moveValue);
    this->bottomRight.setX(this->bottomRight.getX() - moveValue);
    this->bottomLeft.setX(this->bottomLeft.getX() - moveValue);
}
