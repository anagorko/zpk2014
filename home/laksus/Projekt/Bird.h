#ifndef __BIRD_H__
#define __BIRD_H__


class Bird{
    private:
        const double radius = 22;
        double pos_y;
        int type;
        double pos_x = 80;

    public:

        Bird();
        ~Bird();

        void move(double step, double speed);
        void reset();
        bool collision_ground();
        bool collision_obstacle(double obs_x, double obs_y);
        double getXb();
        double getYb();
};


#endif
