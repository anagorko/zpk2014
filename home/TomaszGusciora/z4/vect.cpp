#include "vect.h"
using namespace std;

Vect::Vect(const Vect &p)
{
    dim=p.getDimension();
    v=new double[p.getDimension()];
for (int i=0; i < p.getDimension(); i++)
    setCoordinate(i, p.getCoordinate(i));
}

Vect& Vect::operator=(const Vect &p)
{
    assert(getDimension() == p.getDimension());
for (int i = 0; i < p.getDimension(); i++)
    setCoordinate(i, p.getCoordinate(i));
return *this;

}

void Vect::setCoordinate(int N, double K)
{
   assert (N >= 0 && N < getDimension());
    v[N] = K;
}

double Vect::getCoordinate(int N) const
{
    assert (N >= 0 && N < getDimension());
return v[N];
}

int Vect::getDimension() const
{
return dim;
}

Vect& Vect::operator+=(const Vect &p)
{
  assert (getDimension() == p.getDimension());
for (int i = 0; i < getDimension(); i++)
  setCoordinate(i, getCoordinate(i) + p.getCoordinate(i));
return *this;
}
Vect& Vect::operator-=(const Vect &p)
{
  assert (getDimension() == p.getDimension());
for (int i = 0; i < getDimension(); i++)
  setCoordinate(i, getCoordinate(i) - p.getCoordinate(i));
return *this;
}

double Vect::norm() const
{
return sqrt(*this * *this);
}

void Vect::normalize()
{
  assert (norm() != 0);
double K = norm();
for (int i = 0; i < getDimension(); i++)
  setCoordinate(i, getCoordinate(i) / K);
}

Vect operator+(const Vect &p1, const Vect &p2)
{
assert (p1.getDimension() == p2.getDimension());
Vect p(p1.getDimension());
p= p1;
p+= p2;
return p;
}

Vect operator-(const Vect &p1, const Vect &p2)
{
assert (p1.getDimension() == p2.getDimension());
Vect p(p1.getDimension());
p= p1;
p-= p2;
return p;
}

double operator*(const Vect &p1, const Vect &p2)
{
assert (p1.getDimension() == p2.getDimension());
double K = 0;
for (int i = 0; i < p1.getDimension(); i++)
K = K + p1.getCoordinate(i) * p2.getCoordinate(i);
return K;
}

Vect operator*(const Vect &p, double K)
{
Vect d(p.getDimension());
d=p;
for (int i = 0; i < p.getDimension(); i++)
d.setCoordinate(i, K * p.getCoordinate(i));
return d;
}

Vect operator*(double K, const Vect &p)
{
return p*K;
}

ostream& operator<<(ostream &ostrm, const Vect p)
{
ostrm << "("; for (int i = 0; i < p.getDimension() - 1; i++)
ostrm << p.getCoordinate(i) << ",";
ostrm << p.getCoordinate(p.getDimension() - 1) << ")";
return ostrm;
}

istream& operator>>(istream &istrm, Vect &p)
{
for (int i = 0; i < p.getDimension(); i++)
istrm >> p.v[i];
return istrm;
}
