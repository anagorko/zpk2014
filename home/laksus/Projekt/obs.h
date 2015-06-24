#ifndef __OBS_H__
#define __OBS_H__

class Pipe{
private:
    int type;
    double pos_x,pos_y;

public:
    Pipe();
    Pipe(int);
    ~Pipe();

    double getX();
    double getY();
    void move(int);
    void randHigh(int);
};

#endif
