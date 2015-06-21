#ifndef VECT_H
#define VECT_H

class Vect{

public:

    Vect(float _x, float _y);
    Vect();

    float distanceTo(Vect p);

    float getX() const;
    float getY() const;

    void setX(float _x);
    void setY(float _y);

    Vect& operator*=(float f);
    Vect& operator+=(Vect v);

    bool compare(Vect v);

private:

    float x, y;

};

#endif // VECT_H
