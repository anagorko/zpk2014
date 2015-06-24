#include<iostream>

#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>

#include "cObject.h"

using namespace std;

//constructor
//cObject::cObject(char* dirToLoad){
//    this->loadBitmap(dirToLoad);
//}

//getters
cPoint cObject::getTopLeft(){
    return this->topLeft;
}
cPoint cObject::getTopRight(){
    return this->topRight;
}
cPoint cObject::getBottomLeft(){
    return this->bottomLeft;
}
cPoint cObject::getBottomRight(){
    return this->bottomRight;
}

//setters
void cObject::setTopLeft(cPoint inputValue){
    this->topLeft.setX(inputValue.getX());
    this->topLeft.setY(inputValue.getY());
}
void cObject::setTopRight(cPoint inputValue){
    this->topRight.setX(inputValue.getX());
    this->topRight.setY(inputValue.getY());
}
void cObject::setBottomLeft(cPoint inputValue){
    this->bottomLeft.setX(inputValue.getX());
    this->bottomLeft.setY(inputValue.getY());
}
void cObject::setBottomRight(cPoint inputValue){
    this->bottomRight.setX(inputValue.getX());
    this->bottomRight.setY(inputValue.getY());
}
void cObject::setFTopLeft(float inputX, float inputY){
    this->topLeft.setX(inputX);
    this->topLeft.setY(inputY);
}
void cObject::setFTopRight(float inputX, float inputY){
    this->topRight.setX(inputX);
    this->topRight.setY(inputY);
}
void cObject::setFBottomLeft(float inputX, float inputY){
    this->bottomLeft.setX(inputX);
    this->bottomLeft.setY(inputY);
}
void cObject::setFBottomRight(float inputX, float inputY){
    this->bottomRight.setX(inputX);
    this->bottomRight.setY(inputY);
}


//methods
void cObject::setObject(float tl_x, float tl_y, float tr_x, float tr_y, float bl_x, float bl_y, float br_x, float br_y){
    this->topLeft.setX(tl_x);
    this->topLeft.setY(tl_y);
    this->topRight.setX(tr_x);
    this->topRight.setY(tr_y);
    this->bottomLeft.setX(bl_x);
    this->bottomLeft.setY(bl_y);
    this->bottomRight.setX(br_x);
    this->bottomRight.setY(br_y);
}

float cObject::frontX(){
    return this->topRight.getX();
}
float cObject::backX(){
    return this->topLeft.getX();
}
float cObject::topY(){
    return this->topLeft.getY();
}
float cObject::bottomY(){
    return this->bottomLeft.getY();
}

void cObject::loadBitmap(string dirToLoad){
    char* bitmapTest = new char[dirToLoad.size() + 1];
    copy(dirToLoad.begin(), dirToLoad.end(), bitmapTest);
    bitmapTest[dirToLoad.size()] = '\0';
    this->bitmapObj = al_load_bitmap(bitmapTest);

}





