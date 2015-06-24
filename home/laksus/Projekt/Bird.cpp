#include "Bird.h"
#include <iostream>

using namespace std;

Bird::Bird(){
    type = 0;
    pos_y = 150;
}

Bird::~Bird(){};

void Bird::move(double step, double speed){
    pos_y += speed*step;
}

void Bird::reset(){
    pos_y = 150;
}

bool Bird::collision_ground(){ //kolizacja sprawdza tylko czy nie wypadl za ekran, pierwotnie miala byc ziemia, ale nie pasowala do projektu poziomow
    if(pos_y >= 600)
        return true;
    else
        return false;
}

bool Bird::collision_obstacle(double obs_x, double obs_y){ //ptak jest dla mnie kolem, w planach bylo zbieranie monet i wtedy kolizje bylyby tylko suma promieni
    double col_pos_x, col_pos_y;
    col_pos_x = pos_x; col_pos_y = pos_y;
    if(col_pos_x + radius >= obs_x){
        if((col_pos_y + radius > obs_y && col_pos_y + radius < obs_y + 50) || (col_pos_y - radius > obs_y -200 && col_pos_y - radius < obs_y - 150)){
            return true;
        }
        else if (col_pos_x + radius >= obs_x + 15){
            if((col_pos_y + radius < 600 && col_pos_y - radius > obs_y - 50) || (col_pos_y + radius < obs_y - 200 && col_pos_y - radius > 0)){
                return true;
            }
        }
    }
    return false;
}

double Bird::getXb(){
    return pos_x;
}

double Bird::getYb(){
    return pos_y;
}
