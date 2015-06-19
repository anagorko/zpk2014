#include "Bird.h"

Bird::Bird(){
    type = 0;
    pos_y = 150;
}

Bird::Bird(int _type){
    type = _type;
    pos_y = 150;
}
Bird::~Bird(){};

void Bird::move(int step, double speed){
    pos_y += speed*step;
}

void Bird::show_position(){
    cout << "Pozycja x: " << pos_x+30 << ", pozycja y: " << pos_y+30 << endl;
}

double Bird::getX(){
    return pos_x;
}

double Bird::getY(){
    return pos_y;
}

bool Bird::collision_ground(){
    if(pos_y >= 460)
        return true;
    else
        return false;
}

bool Bird::collision_obstacle(double obs_x, double obs_y){ //ptak jest dla mnie ko³em
    double col_pos_x, col_pos_y;
    col_pos_x = pos_x + 30; col_pos_y = pos_y+30;
    if(col_pos_x + radius >= obs_x){
        if((col_pos_y + radius > obs_y && col_pos_y + radius < obs_y + 50) || (col_pos_y - radius > obs_y -150 && col_pos_y - radius < obs_y - 100)){
            return true;
        }
        else if (col_pos_x + radius >= obs_x + 15){
            if((col_pos_y + radius < 600 && col_pos_y - radius > obs_y - 50) || (col_pos_y + radius < obs_y - 150 && col_pos_y - radius > 0)){
                return true;
            }
        }
    }
    return false;
}
