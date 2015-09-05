#ifndef FRAKTAL_H_INCLUDED
#define FRAKTAL_H_INCLUDED

class Fraktal
{
public:
    Fraktal();

    double kolor (const double &_x, const double& _y);

    // skaluje wartoœci - pomnnijeszanie
    void setScale(const double& _x, const double& _y);

    // Rysuje ramki statystyki i wypisuje ich wartosci
    void Statystyki();

    // pobiera przeksztaLcone wartoœci
    double getXmin();
    double getXmax();
    double getYmin();
    double getYmax();

    // ustawia liczbe klikniec myszka
    void setZoom(double z);

    // ustawia wspolrzedne
    void setPointX(double px);
    void setPointY(double py);

private:
    double transX(const double& _x);
    double transY(const double& _y);
    double oblicz (const double& _x, const double& _y);
    double minimumX = -2.0;
    double minimumY = -1.25;
    double maximumX = 0.5;
    double maximumY = 1.25;
    double z;
    double px;
    double py;
};

#endif // FRAKTAL_H_INCLUDED
