#include "obs.h"
#include<cstdlib>
#include<ctime>
#include<algorithm>



Pipe::Pipe(){
    srand(time(NULL));
    type = 0;
    pos_x = 790;
    pos_y = std::max(5*(rand()%100),200);
}

Pipe::Pipe(int _type){
    srand(time(NULL));
    type = _type;
    pos_x = 600;
    pos_y = 600;//*rand();
}

Pipe::~Pipe(){
}

double Pipe::getX(){
        return pos_x;
}

double Pipe::getY(){
        return pos_y;
}

void Pipe::move(int _step){
    pos_x -= _step;
}
