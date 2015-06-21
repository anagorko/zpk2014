#include <cmath>
#include "vect.h"

Vect::Vect() : Vect(0.0, 0.0){}

Vect::Vect(float _x, float _y) {
    setX(_x);
    setY(_y);
}

float Vect::distanceTo(Vect p) {
    float dx = x - p.x;
    float dy = y - p.y;

    return sqrt(dx*dx + dy*dy);
}

float Vect::getX() const { return x; }
float Vect::getY() const { return y; }

void Vect::setX(float _x) { x = _x; }
void Vect::setY(float _y) { y = _y; }

Vect& Vect::operator*=(float f) {
    x *= f;
    y *= f;
    return *this;
}

Vect& Vect::operator+=(Vect v) {
    x += v.x;
    y += v.y;
    return *this;
}

bool Vect::compare(Vect v){
    if(getX()==v.getX() && getY()==v.getY()) return true;
    else return false;
}

Vect operator*(Vect v, float f){
    v *= f;
    return v;
}

Vect operator+(Vect v1, Vect v2){
    v1 += v2;
    return v1;
}
