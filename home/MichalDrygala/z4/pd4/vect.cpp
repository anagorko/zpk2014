//Uwaga: używamy instrukcji ze standardu C++11 języka C++ - kompilacja może wymagać dodatkowej opcji kompilatora (np. -std=c++11).
 #include "vect.h"

 // Konstruktor domyœlnie przyjmuje wymiar = 3
    Vect::Vect(int _dim = 3)
    {
        dim = _dim;
        v = new double[_dim];
    }

    // Konstruktor inicjalizujacy wspólrzedne wektora
    Vect::Vect(int _dim, initializer_list<double> _v) : Vect(_dim)
    {
        int i = 0;
        for (const double & d: _v)
        {
            assert(i + 1 < dim);
            v[i++] = d;
        }
    }

    // Destruktor
    Vect::~Vect()
    {
        delete[] v;
    }

    // konstruktor kopiujacy
    Vect::Vect(const Vect &w)
    {

    }

     // Operator podstawienia
    Vect::Vect& operator=(const Vect &w)
    {

    }


    //Wskazówka - przykładowa implementacja metody setCoordinate
    void Vect::setCoordinate(int n, double c)
    {
        assert(n >= 0 && n < getDimension());
        v[n] = c;
    }


    // Metoda pobierajaca wartosc wspólrzednej
    double Vect::getCoordinate(int) const
    {
        assert(n >= 0 && n < getDimension());
        cin >> a;
        return a;
    }

    // Metoda zwracajaca wymiar przestrzeni
    int Vect::getDimension() const
    {
        return dim;
    }

    istream& operator >> (istream &m, Vect &v)
{
    for (int i = 1; i <= dim; i++)
    {m >> v[_dim];
    }

    return m;
}

    // Operatory dodawania i odejmowania od danego wektora
    Vect& operator+=(const Vect& p)
    {

    }

    Vect& operator-=(const Vect& p)
    {

    }

    // Metoda obliczajaca norme tego wektora
    double norm() const
    {

    }

    // Metoda normalizujaca wektor
    void normalize()
    {

    }

    // Dodawanie i odejmowanie wektorów
    Vect operator+(const Vect &p1, const Vect &p2)
    {

    }

    Vect operator-(const Vect &p1, const Vect &p2)
    {

    }

    // Iloczyn skalarny
    double operator*(const Vect &p1, const Vect &p2)
    {

    }

    // Mno¿enie wektora przez skalar
    Vect operator*(const Vect &p, double d)
    {

    }
    Vect operator*(double d, const Vect& p)
    {

    }

    // Wypisywanie i odczytywanie wektora ze strumieni
    ostream& operator<<(ostream &, const Vect)
    {

    }

    istream& operator>>(istream &, Vect&)
    {

    }
//Kilka uwag.

//Klasa niewiele różni się od klasy Point. Trzeba jednak użyć pętli (bo wymiar nie jest z góry znany),
//uwzględnić problemy związane z dynamiczną alokacją tablicy v i używać więcej asercji, bo nie możemy
//np. dodać do siebie wektora z R^3 i wektora z R^4.

//Należy zaimplementować konstruktor kopiujący i operator= tak, by tworzyły kopię tablicy zawierającej współrzędne.
//Domyślnie generowany kod nie będzie działał prawidłowo. Dlaczego?


//Używaj funkcji assert() by sprawdzać kompatybilość typów (wymiar wektora) i zakresy.

//Operator + zaimplementuj za pomocą operatora +=, podobnie z -.

//Operacje w * d i d * w (w - wektor, d - skalar) to te same operacje. Nie duplikuj kodu.

//Użyj iloczynu skalarnego, by obliczyć normę wektora. Nie duplikuj kodu!

//Normalizując wektor upewnij się, że nie dzielisz przez 0
