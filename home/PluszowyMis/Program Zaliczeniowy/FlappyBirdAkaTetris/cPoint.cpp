#include<iostream>

#include "cPoint.h"

using namespace std;

//constructors
cPoint::cPoint(float inputX, float inputY){
    this->x = inputX;
    this->y = inputY;
}
cPoint::cPoint(){
    cPoint(0.0,0.0);
}

//getters
float cPoint::getX(){
    return this->x;
}
float cPoint::getY(){
    return this->y;
}
//setters
void cPoint::setX(float inputX){
    this->x = inputX;
}
void cPoint::setY(float inputY){
    this->y = inputY;
}





