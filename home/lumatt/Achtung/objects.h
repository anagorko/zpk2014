#ifndef OBJECTS_H
#define OBJECTS_H

class Flying{

public:

    Flying();
    virtual ~Flying();

    Vect getPosition() const;
    void setPosition(const Vect _p);

    Vect getVelocity() const;
    void setVelocity(Vect _v);

    virtual void move(float time);
    bool collidesWith(Flying* f) const;

    virtual float diameter() const;

    virtual ALLEGRO_BITMAP* getBitmap() const;

protected:

    ALLEGRO_BITMAP* bitmap;
    Vect p, v;
    float a, r;

};

class Snake : public Flying{

public:

    struct random_break{
        bool inv;
        float time;
    } rand_break;

    Snake(float num);
    virtual ~Snake();

    void turnLeft(bool l);
    void turnRight(bool r);
    void set_stop();
    void set_go();

    bool get_stop();

    virtual void move(float time);
    void set_angle_left(float _left);
    void set_angle_right(float _right);
    float get_angle_left();
    float get_angle_right();

    void set_bonus2(bool bonus);
    void set_bonus3(bool bonus);
    bool get_bonus2();
    bool get_bonus3();

    virtual float diameter() const;

    float getNumber();

    void randomize_break(float threshold, float time, float dur);

private:

    bool left;
    bool right;
    bool stop;

    float angle_left;
    float angle_right;
    bool bonus2;
    bool bonus3;

    float number;
    char *filename;

};

class Bonus : public Flying{

public:

    Bonus(float _type);
    virtual ~Bonus();

    virtual float diameter() const;

    float get_type();
    bool get_used();
    void set_used(bool _used);

    void change_bitmap();
    bool get_black();
    void set_black();

private:

    float type;
    bool used;
    bool black;
    char *filename;

};

#endif
