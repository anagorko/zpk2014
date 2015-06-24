#ifndef CPOINT_H_
#define CPOINT_H_

#include<iostream>

using namespace std;

class cPoint{
private:
    float x;
    float y;
public:
    cPoint(float inputX, float inputY);
    cPoint();
    float getX();
    float getY();
    void setX(float inputX);
    void setY(float inputY);
};

#endif // CPOINT_H_
