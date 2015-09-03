#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <time.h>
#include <unistd.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
using namespace std;
/* 
GAME OF LIFE
zakladam, ze jednostka czasu to rok
 */
const int Ekran_X = 600;
const int Ekran_Y = 600;
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
/* dodaje zywa komorke we wskazanym miejscu*/
bool Plansza::dodajZywa(int x,int y)
{
	if(x<0||y<0||x>=szer||y>=wys)
	{
		return false;
	}
	tablica[x][y]=1;
	tablicaBuf[x][y]=1;

}

/* funkcja wykorzystana w konstruktorach do stworzenia tablic o zadanych wymiarach (tablicaBuf ulatwia przejscie do kolejnego roku) */
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
ALLEGRO_BITMAP*  potworek;
/* konstruktor pustej planszy z podanymi wymiarami */
int pixSzer,pixWys;
Plansza::Plansza(int szer,int wys)
	{
		potworek=al_load_bitmap(cell.png);
		this->szer=szer;
		this->wys=wys;
		pixSzer=Ekran_X/szer;
		pixWys=Ekran_Y/wys;
		if(potworek==NULL)
			cout<<"brak bitmapy potworka";
		tworzTablice();
	}
/* konstruktor wczytujacy gotowa plansze poczatkowa, wczytuje plik txt i tworzy 'tablica' oraz 'tablicaBuf' */
Plansza::Plansza(string nazwaPliku)
	{
		potworek=al_load_bitmap(cell.png);
		ifstream plik;
		if(potworek==NULL)
			cout<<"brak bitmapy potworka";
		plik.open(nazwaPliku.c_str());
		plik>>szer>>wys;
		pixSzer=Ekran_X/szer;
		pixWys=Ekran_Y/wys;
		tworzTablice();
			for(int j=0;j<wys;j++)
				for(int i=0;i<szer;i++)
				{
					plik>>tablica[i][j];
					tablicaBuf[i][j]=tablica[i][j];

				}
		plik.close();
	}

/* funkcja zapelniajaca plansze w sposob losowy */
void Plansza::generujLos(int ile)
	{
		for(int i=0;i<ile;i++)
		{
			int x=rand()%szer,y=rand()%wys;
			tablica[x][y]=1;
			tablicaBuf[x][y]=1;
		}
	}
/* funkcja wypisujaca plansze na ekran, gdzie komorki zywe (przyjmujace wartosc 1) sa oznaczone jako #, a komorki martwe (o wartosci 0) oznaczone sa spacja */
void Plansza::wypisz()
	{
		al_clear_to_color(al_map_rgb(250, 250, 250));
		for(int j=0;j<wys;j++)

		{
			for(int i=0;i<szer;i++)
			{
					if(tablica[i][j]!=0)
						al_draw_scaled_bitmap(potworek,0,0,500,500,pixSzer*j, pixWys*i,pixSzer,pixWys,  0);
			}
/*				if(i==0||j==0||i==szer+1||j==wys+1)
					cout<<"*";
				else
				{
					if(tablica[i-1][j-1]==0)
						cout<<" ";
					else
						cout<<"#";
				}
			cout<<endl;*/
		}
	}
/* funkcja zliczajaca i zwracajaca liczbe sasiadow danej komorki. Aby kazda komorka miala 8 sasiadow, trzeba umiescic je na torusie, w tym celu wykorzystalem modulo  */
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
/* funkcja tworzaca nowa plansze, ktora powstaje po roku wedlug regul:
    -Martwa komorka, ktora ma dokladnie 3 zywych sasiadow, staje sie zywa
    -zywa komorka z 2 albo 3 zywymi sasiadami pozostaje nadal zywa; przy innej liczbie sasiadow umiera
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
/* ileLat pozwala uzytkownikowi wybrac ile kolenych lat plansza ma sie zmieniac, natomiast ileLatCicho pozwala wybrac od ktorego roku zmiany maja byc obserwowane na ekranie*/
	int ileLat,ileLatCicho;
	char znak,znak2;
	
		srand(time(NULL));
		 if (!al_init() || !al_init_image_addon())
		{
		cout << "Initialization error!" << endl;
		return 1;
		}
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

					 ALLEGRO_DISPLAY *Show_Display = al_create_display(Ekran_X, Ekran_Y);
						al_set_window_title(Show_Display, "Game of Life");
						al_clear_to_color(al_map_rgb(230, 230, 230));
					for(int i=0;i<ileLat;i++)
					{
						/* dopiero bo wybranej liczbie lat wyswietlane sa plansze */
						if(i>=ileLatCicho)
						{

						/* dla czytelnosci miedzy wyswietleniami kolejnych plansz nastepuje sekundowa przerwa, a poprzednia plansza jest kasowana z ekranu) */
							usleep(1000000);
							p->wypisz();
						}
						p->jedenKrokSymulacji();
						al_flip_display();
					}
					 al_destroy_display(Show_Display);
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



