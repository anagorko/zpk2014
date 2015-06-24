#ifndef __OBS_H__
#define __OBS_H__

class Pipe{

public:
    int type;
    double pos_x,pos_y;

    Pipe();
    Pipe(int);
    ~Pipe();

    double getX();
    double getY();
    void move(int);
};

#endif
