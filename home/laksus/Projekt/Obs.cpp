#include "obs.h"
#include<cstdlib>
#include<ctime>
#include<algorithm>

using namespace std;
Pipe::Pipe(){//losowana jest wysokosc rury
    srand(time(NULL));
    type = 0;
    pos_x = 790;
    pos_y = std::max(5*(rand()%100),200);
}

Pipe::Pipe(int _type){//inny sposob generowania rur, losuje odleglosc od sroka a nie wysokosc
    srand(time(NULL));
    type = 0;
    pos_x = 790;
    pos_y = 300+(_type*(rand()%200));
}

Pipe::~Pipe(){
}

double Pipe::getX(){
        return pos_x;
}

double Pipe::getY(){
        return pos_y;
}

void Pipe::move(int _step){ //jest z minusem ze wzzgledu na to, ze ruch w lewo jest zmniejszeniem pozycji x
    pos_x -= _step;
}

void Pipe::randHigh(int _type){
    pos_y = 300+(_type*(rand()%80));
}
