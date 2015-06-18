#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <time.h>
#include <unistd.h>
using namespace std;
/* GAME OF LIFE

zak³adam, ¿e jednostka czasu to rok
 */
class Plansza
{
	private:
	int **tablica;
	int **tablicaBuf;
	int szer,wys;
	void tworzTablice();
	int ileSasiadow(int x,int y);
	public:
	Plansza(int szer,int wys);
	Plansza(string nazwaPliku);
	void generujLos(int ile);
	void wypisz();
	void jedenKrokSymulacji();
	bool dodajZywa(int x,int y);

};
/* dodaje ¿ywa komorke we wskazanym miejscu*/
bool Plansza::dodajZywa(int x,int y)
{
	if(x<0||y<0||x>=szer||y>=wys)
	{
		return false;
	}
	tablica[x][y]=1;
	tablicaBuf[x][y]=1;

}

/* funkcja wykorzystana w konstruktorach do stworzenia tablic o zadanych wymiarach (tablicaBuf u³atwia przejscie do kolejnego roku) */
void Plansza::tworzTablice()
	{
		tablica=new int*[szer];
		tablicaBuf=new int*[szer];
		for(int i=0;i<szer;i++)
		{
			tablica[i]=new int[wys];
			tablicaBuf[i]=new int[wys];
			for(int j=0;j<wys;j++)
			{
				tablica[i][j]=0;
				tablicaBuf[i][j]=0;
			}
		}

	}
/* konstruktor pustej planszy z podanymi wymiarami */
Plansza::Plansza(int szer,int wys)
	{
		this->szer=szer;
		this->wys=wys;
		tworzTablice();
	}
/* konstruktor wczytujacy gotowa plansze poczatkowa, wczytuje plik txt i tworzy 'tablica' oraz 'tablicaBuf' */
Plansza::Plansza(string nazwaPliku)
	{
		ifstream plik;
		plik.open(nazwaPliku.c_str());
		plik>>szer>>wys;
		tworzTablice();
			for(int j=0;j<wys;j++)
				for(int i=0;i<szer;i++)
				{
					plik>>tablica[i][j];
					tablicaBuf[i][j]=tablica[i][j];

				}
		plik.close();
	}

/* funkcja zape³niajaca plansze w sposob losowy */
void Plansza::generujLos(int ile)
	{
		for(int i=0;i<ile;i++)
		{
			int x=rand()%szer,y=rand()%wys;
			tablica[x][y]=1;
			tablicaBuf[x][y]=1;
		}
	}
/* funkcja wypisujaca plansze na ekran, gdzie komorki ¿ywe (przyjmujace wartosc 1) sa oznaczone jako #, a komorki martwe (o wartosci 0) oznaczone sa spacja */
void Plansza::wypisz()
	{
		for(int j=0;j<wys+2;j++)

		{
			for(int i=0;i<szer+2;i++)
				if(i==0||j==0||i==szer+1||j==wys+1)
					cout<<"*";
				else
				{
					if(tablica[i-1][j-1]==0)
						cout<<" ";
					else
						cout<<"#";
				}
			cout<<endl;
		}
	}
/* funkcja zliczajaca i zwracajaca liczbe sasiadow danej komorki. Aby ka¿da komorka mia³a 8 sasiadow, trzeba umiescic je na torusie, w tym celu wykorzysta³em modulo  */
int Plansza::ileSasiadow(int x,int y)
	{
		int licznik=0;
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(tablica[(x+i-1+szer)%szer][(y+j-1+wys)%wys]==1)
				{
					licznik++;
				}
			}
		}
		if(tablica[x][y]==1)
			licznik--;

		return licznik;
	}
/* funkcja tworzaca nowa plansze, ktora powstaje po roku wed³ug regu³:
    -Martwa komorka, ktora ma dok³adnie 3 ¿ywych sasiadow, staje sie ¿ywa
    -¿ywa komorka z 2 albo 3 ¿ywymi sasiadami pozostaje nadal ¿ywa; przy innej liczbie sasiadow umiera
*/

void Plansza::jedenKrokSymulacji()
	{

		for(int i=0;i<szer;i++)
			for(int j=0;j<wys;j++)
			{

				if(tablica[i][j]==0&&ileSasiadow(i,j)==3)
				{
					tablicaBuf[i][j]=1;
				}

				if(tablica[i][j]==1&&ileSasiadow(i,j)!=3&&ileSasiadow(i,j)!=2)
				{
					tablicaBuf[i][j]=0;
				}

			}

		for(int i=0;i<szer;i++)
			for(int j=0;j<wys;j++)
			{
				tablica[i][j]=tablicaBuf[i][j];

			}

	}


int main(int, char**)
{
/* ileLat pozwala u¿ytkownikowi wybrac ile kolenych lat plansza ma sie zmieniac, natomiast ileLatCicho pozwala wybrac od ktorego roku zmiany maja byc obserwowane na ekranie*/
	int ileLat,ileLatCicho;
	char znak,znak2;
		srand(time(NULL));
	do
	{
		cout<<endl<<"Witaj!"<<endl;
		cout<<"n) Nowa gra"<<endl;
		cout<<"i) Opis gry"<<endl;
		cout<<"w) Wyjdz"<<endl;
		cin>>znak;
		if(znak=='n')
		{
			do
			{
				cout<<endl<<"Jak rozpoczac nowa gre?"<<endl;
				cout<<"w) wczytaj z pliku"<<endl;
				cout<<"l) losowo"<<endl;
				cout<<"n) Narysuj"<<endl;
				cout<<"c) Cofnij"<<endl;
				cin>>znak2;
				Plansza *p=NULL;
				if(znak2=='l')
				{
					int szer,wys,ile;
					cout<<"podaj szerokosc i wysokosc planszy, oraz ilosc komorek do wygenerowania"<<endl;
					cin>>szer>>wys>>ile;
					p=new Plansza(szer,wys);
					p->generujLos(ile);
				}
				if(znak2=='w')
				{
					string nazwa;
					cout<<"wybierz plik"<<endl;
					system("dir *.txt");
					cin>>nazwa;
					p=new Plansza(nazwa);
				}
				if(znak2=='n')
				{
					int szer,wys;
					cout<<"podaj szerokosc i wysokosc planszy"<<endl;
					cin>>szer>>wys;
					p=new Plansza(szer,wys);
					int x,y;
					cout<<"podaj wspolrzedne zywych komorek; podaj wartosc ujemna aby zakonczyc dodawanie"<<endl;
					do
					{

						cin>>x>>y;
						if(x<0||y<0)
							break;
						p->dodajZywa(x,y);
						p->wypisz();
					}while(true);
				}



				if(p!=NULL)
				{


					cout << "Ile okresow (lat) ma trwac symulacja? ";
					cin>>ileLat;
					cout << "Po ilu okresach (latach) chcesz rozpoczac obserwacje symulacji? ";
					cin>>ileLatCicho;



					for(int i=0;i<ileLat;i++)
					{
						/* dopiero bo wybranej liczbie lat wyswietlane sa plansze */
						if(i>ileLatCicho)
						{
						/* dla czytelnosci miedzy wyswietleniami kolejnych plansz nastepuje sekundowa przerwa, a poprzednia plansza jest kasowana z ekranu) */
							usleep(1000);
							p->wypisz();
						}
						p->jedenKrokSymulacji();
					}
					break;
				}
			}while(znak2!='c');
		}
		if(znak=='i')
		{
			cout<<"Zasady tej gry sa bardzo proste, nieskonczona plaszczyzna podzielona jest"<<endl<<"na komorki, z ktorych czesc jest zywa, a pozostale sa martwe."<<endl;
			cout<<"Kazda komorka ma osmiu sasiadow i od ich stanu zalezy co stanie sie w nastepnej jednostce czasu.";
			cout<<"Martwa komorka, z dokladnie trzema zywymi sasiadami,"<<endl<<"staje sie zywa w kolejnej jednostce czasu."<<endl;
			cout<<"Komorka, ktora ma dwoch albo trzech zywych sasiadow nie zmienia stanu,"<<endl<<"a przy innej liczbie sasiadow umiera z samotnosci lub zatloczenia."<<endl;
			cout<<"Rola gracza sprowadza sie do wybrania ustawienia poczatkowego oraz dobrania"<<endl<<"obserwowanych okresow symulacji."<<endl;
			cout<<"Gracz ma do wyboru 3 opcje:"<<endl<<"1) narysowanie planszy poprzez wpisanie wspolrzednych dla zywej komorki."<<endl<<"2) wybranie planszy z pliku."<<endl<<"3) wygenerowanie losowej planszy."<<endl;
		}
	}while(znak!='w');
	return 0;
}

