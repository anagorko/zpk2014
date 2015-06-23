#ifndef __BIRD_H__
#define __BIRD_H__


class Bird{
    public:
        double pos_y;
        int type;
        const int pos_x = 80;
        const double radius = 22;

        Bird();
        Bird(int);
        ~Bird();

        void move(int step, double speed);
        void show_position();
        void reset();
        bool collision_ground();
        bool collision_obstacle(double obs_x, double obs_y);
        double getX();
        double getY();
};


#endif
