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
