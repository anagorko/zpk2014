 #include "vect.h"



    Vect::Vect(const Vect &w){
    dim = w.getDimension();
    v = new double[dim];
    for (int i = 0; i < dim; i++) {
        setCoordinate(i, w.getCoordinate(i));
    }
    }


    void Vect::setCoordinate(int n,double a){
    assert(n >= 0 && n < getDimension());
    v[n] = a;
    }


    double Vect::getCoordinate(int n) const{
        assert(n >= 0 && n < getDimension());
        return v[n];
    }


    int Vect::getDimension() const{
    return dim;
    }


    Vect& Vect::operator=(const Vect &w){
    assert (getDimension() == w.getDimension());
    for (int i = 0; i < w.getDimension(); i++)
        {
        setCoordinate(i, w.getCoordinate(i));
        }
    return *this;
    }


    Vect& Vect::operator+=(const Vect& p) {
    assert(getDimension()==p.getDimension());
    for (int i = 0; i < p.getDimension(); i++)
    setCoordinate(i,getCoordinate(i)+p.getCoordinate(i));

    return *this;
    }


    Vect& Vect::operator-=(const Vect& p) {

    assert(getDimension()==p.getDimension());
    for (int i = 0; i < p.getDimension(); i++)
    setCoordinate(i,getCoordinate(i)-p.getCoordinate(i));
    return *this;
    }


    double Vect::norm() const{
    return sqrt( *this * *this );
    }


    void Vect::normalize(){
    assert (norm() != 0);
    double n = 1 / norm();
    for (int i = 0; i < getDimension(); i++)
    setCoordinate(i, getCoordinate(i)*n);

    }



Vect operator+(const Vect &p1, const Vect &p2){
    assert(p1.getDimension()==p2.getDimension());
    Vect p(p1);
    p += p2;
    return p;
}
Vect operator-(const Vect &p1, const Vect &p2){

    assert(p1.getDimension()==p2.getDimension());
    Vect p(p1);
    p -= p2;
    return p;


}


double operator*(const Vect &p1, const Vect &p2)
{   double s=0;
    assert(p1.getDimension()==p2.getDimension());
    for (int i = 0; i < p1.getDimension(); i++)
        s=s+p1.getCoordinate(i)*p2.getCoordinate(i);

    return s;
}


Vect operator*(const Vect &p, double d){
    Vect s(p);
    for (int i = 0; i < p.getDimension(); i++)
        s.setCoordinate(i,d*p.getCoordinate(i));

    return s;
}



Vect operator*(double d, const Vect& p){
    return p*d;
}


ostream& operator<<(ostream &o, const Vect p){
  o<<"(";
        for(int i=0;i<p.getDimension()-1;i++){
            o<<p.getCoordinate(i)<<",";
        }
        o<<p.getCoordinate(p.getDimension()-1)<<")";
        return o;
}
istream& operator>>(istream &i, Vect&p){
    for(int j=0;j<p.getDimension();j++){
            i >>p.v[j];
        }
        return i;
}





