#include "vect.h"
using namespace std;

    // konstruktor kopiuj¹cy
    Vect::Vect(const Vect &w){
    dim = w.getDimension();
    v = new double[dim];
    for (int i = 0; i<dim; i++){
        setCoordinate(i, w.getCoordinate(i));
    }}

    // Operator podstawienia
    Vect& Vect::operator = (const Vect &w){
    assert (getDimension() == w.getDimension());
    for (int i = 0; i<w.getDimension(); i++){
        setCoordinate(i, w.getCoordinate(i));}
    return *this;}

    // Metoda ustawiaj¹ca wartoœæ wspó³rzêdnej
    void Vect::setCoordinate(int n, double c){
        assert(n >= 0 && n < getDimension());
        v[n] = c;}

    // Metoda pobieraj¹ca wartoœæ wspó³rzêdnej
    double Vect::getCoordinate(int n) const{
    assert(n >= 0 && n < getDimension());
    return v[n];}

    // Metoda zwracaj¹ca wymiar przestrzeni
    int Vect::getDimension() const{
    return dim;}

    // Operatory dodawania i odejmowania od danego wektora
    Vect& Vect::operator+=(const Vect& p){
    assert (getDimension()==p.getDimension());
    for (int i=0; i<p.getDimension();i++}{
        setCoordinate(i, getCoordinate(i)+p.getCoordinate(i))}
    return *this;}

    Vect& Vect::operator-=(const Vect& p){
    assert (getDimension()==p.getDimension());
    for (int i=0; i<p.getDimension();i++}{
        setCoordinate(i, getCoordinate(i)-p.getCoordinate(i))}
    return *this;}

    // Metoda obliczaj¹ca normê tego wektora
    double Vect::norm() const{
    return sqrt(*this * *this);}

    // Metoda normalizuj¹ca wektor
    void Vect::normalize(){
    assert (norm()!=0);
    double n=norm();
    for (int i=0; i<getDimension(); i++){
        setCoordinate(i, getCoordinate(i)/n);)}}


    // Dodawanie i odejmowanie wektorów
    Vect operator+(const Vect &p1, const Vect &p2){
    assert (p1.getDimension() == p2.getDimension());
    Vect w(p1.getDimension());
    w=p1;
    w+=p2;
    return w;}

    Vect operator-(const Vect &p1, const Vect &p2){
    assert (p1.getDimension() == p2.getDimension());
    Vect w(p1.getDimension());
    w=p1;
    w-=p2;
    return w;}

    // Iloczyn skalarny
    double operator*(const Vect &p1, const Vect &p2){
    assert (p1.getDimension() == p2.getDimension();
    double skalar=0;
    for (int i=0; i<p1.getDimension();i++){
        skalar=skalar+p1.getCoordinate(i)*p2.getCoordinate(i);}
        return skalar;}

    // Mno¿enie wektora przez skalar
    Vect operator*(const Vect &p, double d){
    Vect x(p.getDimension());
    x=p;
    for(int i =0; i<p.getDimension(); i++){
        p.setCoordinate(i, d*p.getCoordinate(i));}
    return x;}

    Vect operator*(double d, const Vect& p){
        return p*d;}

    // Wypisywanie i odczytywanie wektora ze strumieni
    ostream& operator<<(ostream &ost, const Vect w){
    osr<<"(";
    for(int i=0; i<w.getDimension(); i++)
        ost<<<","<<w.getCoordinate(i);
        ost<<")";
    return ost;}

    istream& operator>>(istream &ist, Vect&w){
    for (int i=0; i<w.getDimension(); i++){
    ist>>w.v[i];}
    return ist;}

