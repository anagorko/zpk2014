class napisy
{
public:
	void rysuj( char[] tekst );
};

class vect
{
	float x, y;
	
public:
	void Vect();
	float getX();
	float getY();
	void setX();
	void setY();
};

class powierzchnia
{
	float punkty [screen_w];
	float odleglosc [screen_w];
	
public:
	void setOdleglosci();
	float getOdleglosc( int piksel, czubekX, czubekY, float kat );
	void losujPlansze( lBonus2, lBonus4, lBonus5 );
	void rysujPlansze();
	float getPunkty( int piksel );
};

class statek
{
	vect predkosc, czubek;
	float kat;
	
public:
	void lec( bool lewo, bool prawo, bool przod );
	void rysujStatek();
	float getCzubekX();
	float getCzubekY();
	bool zblizaSie();
	bool wypadek();	
};

class gra
{
	int paliwo, punkty, czas;
	float zblizenie [screen_w];

public:
	void zrobZblizenie( czubekX, czubekY, float kat, float punkty[] );
	void wygrana();
	void przegrana();
	
};