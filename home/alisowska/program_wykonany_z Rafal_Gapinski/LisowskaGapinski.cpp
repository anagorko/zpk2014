// NIEZBEDNE BIBLIOTEKI:

#include <iostream>     // STANDARDOWA BIBLIOTEKA (CIN/COUT itd.)
#include <windows.h>    // BIBLIOTEKA Z KOMENDAMI DO ZMIANY KOLOROW
#include <conio.h>      // BIBLIOTEKA POTRZEBNA DO UZYSKANIA GRAFIKI Z PLIKU
#include <time.h>       // KONTROLNIE - DO OBLICZENIA CZASU DZIALANIA PROGRAMU
#include <fstream>      // BIBLIOTEKA KONIECZNA DO ZAPISYWANIA DANYCH DO PLIKU
#include <string>       // BIBLIOTEKA KONIECZNA DO OBSLUGI ZNAKOW

using namespace std;

// DEFINICJA KLASY PRZECHOWUJACEJ PLANSZE + USTAWIENIA GRY (INTERFEJS):
class Plansza{
	// ZMIENNE UZYTE W KLASIE (DO CHARAKTERYSTYKI PLANSZY):
public:
	char** tabela;	            // DWUWYMIAROWA TABELA ZMIENNYCH TYPU CHAR PELNIACYCH FUNKCJE PLANSZY
    int wysokosc;               // WYSOKOSC PLANSZY
	int szerokosc;              // SZEROKOSC PLANSZY
	int liczbaAgentow;          // OKRESLENIE LICZBY AGENTOW
	float procentCzerwonych;    // PROCENT CZERWONYCH AGENTOW W OGOLNEJ LICZBIE
	short defSasiedztwa;        // SPOSOB ZDEFINIOWANIA SASIEDZTWA (4/8 POL)
	float podCzer;              // MINIMALNY AKCEPTOWALNY PROCENT AGENTOW CZERWONYCH
	float podBia;               // MINIMALNY AKCEPTOWALNY PROCENT AGENTOW BIALYCH
	int maxIteracji;            // MAKSYMALNA LICZBA ITERACJI

	// KONSTRUKTOR DOMYSLNY:
	Plansza();                  // UTWORZENIE DOMYSLNEJ PLANSZY

	// UZYTE KLASY:
	void wyswietl();            // WYSWIETLENIE PLANSZY
	bool sprawdz();             // SPRAWDZENIE SPOJNOSCI ZMIENNYCH
	void aktualizuj();          // AKTUALIZACJA TABELI ZRODLOWYCH DLA PLANSZY
};

// KONSTRUKTOR DOMYSLNY:
Plansza::Plansza(){
    // OKRESLENIE PARAMETROW DOMYSLNYCH GRY:
	wysokosc = 26; // WYSOKOSC PLANSZY
	szerokosc = 26; // SZEROKOSC PLANSZY
	liczbaAgentow = 500; //
	procentCzerwonych = 50;
	podCzer = 30;
	podBia = 30;
	defSasiedztwa = 2;
	maxIteracji = 150;

    // DEFINICJA PLANSZY:
    tabela = new char*[wysokosc];
	for (int i = 0; i < wysokosc; i++){
		tabela[i] = new char[szerokosc];
		for (int j = 0; j < szerokosc; j++){
		    tabela[i][j] = ' ';
		}
	}
}

// DEFINICJA SPOSOBU WYSWIETLANIA:
void Plansza::wyswietl(){
	HANDLE hOut;						    // DO WYSWIETLENIA KOLOROW
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);	// DO WYSWIETLENIA KOLOROW
	for (int i = 0; i < szerokosc; i++){
		cout << "--";	// GORNA KRAWEDZ PLANSZY
	}
	cout << "\n";
	for (int i = 0; i < wysokosc; i++){
		cout << "|"; // BOCZNE KRAWEDZIE PLANSZY
		for (int j = 0; j < szerokosc; j++){
			if (tabela[i][j] == '*'){
				SetConsoleTextAttribute(hOut, 12);	// KOLOR CZERWONY
				cout << tabela[i][j];
				SetConsoleTextAttribute(hOut, 15); // KOLOR BIALY
				cout << "|";
			}
			else
				cout << tabela[i][j] << "|";
		}
		cout << "\n";
		for (int i = 0; i < szerokosc; i++){
			cout << "--"; // DOLNA KRAWEDZ PLANSZY
		}
		cout << "\n";
	}
}

// SPRAWDZENIE POPRAWNOSCI ROZLOZENIA AGENTOW:
bool Plansza::sprawdz(){
	if (liczbaAgentow >= wysokosc*szerokosc){
		system("cls");
		cout << "Liczba agentow wieksza lub rowna liczbe pol na planszy!\nZmien parametry i sprobuj jeszcze raz.\n";
		return false;
	}
	return true;
}

// AKTUALIZACJA WIELKOSCI PLANSZY:
void Plansza::aktualizuj(){

    tabela = new char*[wysokosc];
	for (int i = 0; i < wysokosc; i++){
		tabela[i] = new char[szerokosc];
		for (int j = 0; j < szerokosc; j++)
		{
		    tabela[i][j] = ' ';
		}
	}

    // AKTUALIZACJA ZAWARTOSCI
	float los;
	srand(time(NULL));             // CZYNNIK LOSOWY
	int liczbaAgentowDoWpisania = liczbaAgentow;
    // ITERACJA
	do{
        for (int i = 0; (i < wysokosc) && (liczbaAgentowDoWpisania > 0); i++){
            for (int j = 0; (j < szerokosc) && (liczbaAgentowDoWpisania > 0); j++){
                los = rand() % (wysokosc * szerokosc + 1);  // LOSOWANIE POZYCJI POCZATKOWEJ W ITERACJI
                if (los < (liczbaAgentow * procentCzerwonych / 100)){
                    tabela[i][j] = '*';
                    liczbaAgentowDoWpisania--; }
                else{
                    if (los < liczbaAgentow){
                        tabela[i][j] = '#';
                        liczbaAgentowDoWpisania--;
                    }
                    else
                        tabela[i][j] = ' ';
                }
            }
        }
    } while (liczbaAgentowDoWpisania > 0);
}

// WZORZEC ZMIENNEJ - DO WCZYTYWANIA ZMIENNYCH ROZNEGO TYPU:
template <typename T>
T wczytajZmienna (){
	T a;
	cin >> a;
	if (cin.fail()){
		do{
			cin.clear();
			cin.sync();
			cout << "Niepoprawna komenda! Podaj wlasciwa liczbe." << endl;
			cin >> a;
		}                                                                                                                                                                                                                                                                                                                                                               while (cin.fail());
    }
    return a;
}

// PLANSZA CD: USTALENIE WYMIAROW:
void ustalWysokoscPlanszy(Plansza &a){
    system("cls");
    cout << "Podaj wysokosc planszy.\n"
         << "Pamietaj, ze duze plansze moga sie zle wyswietlac!\n\n";
    a.wysokosc = wczytajZmienna<int>();
    while (a.wysokosc < 1){
        cout << "Wysokosc musi byc wartoscia dodatnia!\n"
             << "Wpisz poprawna wartosc.\n";
        a.wysokosc = wczytajZmienna<int>();
    }
    cout << "\nNacisnij dowolny klawisz, aby wrocic do poprzedniego menu.\n";
    _getch();
}
// USTALENIE SZEROKOSCI PLANSZY:
void ustalSzerokoscPlanszy(Plansza &a){
    system("cls");
    cout << "Podaj szerokosc planszy.\n"
         << "Pamietaj, ze duze plansze moga sie zle wyswietlac!\n\n";
    a.szerokosc = wczytajZmienna<int>();
    while (a.szerokosc < 1){
        cout << "Szerokosc musi byc wartoscia dodatnia!\n"
             << "Wpisz poprawna wartosc.\n";
        a.szerokosc = wczytajZmienna<int>();
    }
    cout << "\nNacisnij dowolny klawisz, aby wrocic do poprzedniego menu.\n";
    _getch();
}
// USTALENIE LICZBY AGENTOW:
void ustalLiczbeAgentow(Plansza& a){
    system("cls");
    cout << "Podaj liczbe agentow.\n"
         << "Pamietaj, ze liczba agentow musi byc mniejsza od liczby pol na planszy!\n\n";
    a.liczbaAgentow = wczytajZmienna<int>();

    while (a.liczbaAgentow < 1){
        cout << "Liczba agentow musi byc wartoscia dodatnia!\n"
             << "Wpisz poprawna wartosc.\n";
        a.liczbaAgentow = wczytajZmienna<int>();
    }
    cout << "\nNacisnij dowolny klawisz, aby wrocic do poprzedniego menu.\n";
    _getch();
}
// USTALENIE PROCENTA CZERWONYCH GRACZY:
void ustalProcentCzerwonych(Plansza& a){
    system("cls");
    cout << "Podaj procent agentow, jaki maja stanowic agenci koloru czerownego.\n"
         << "Wpisz liczbe z przedzialu (0,100).\n\n";
    a.procentCzerwonych = wczytajZmienna<float>();
    while (a.procentCzerwonych < 0 || a.procentCzerwonych > 100){
        cout << "Procent czerwonych musi byc wartoscia z przedzialu (0,100)!\n"
             << "Wpisz poprawna wartosc.\n";
        a.procentCzerwonych = wczytajZmienna<float>();
    }

    cout << "\nNacisnij dowolny klawisz, aby wrocic do poprzedniego menu.\n";
    _getch();
}
// WYBOR SASIEDZTWA:
void ustalDefinicjeSasiedztwa(Plansza& a){
    system("cls");
    cout << "Wybierz definicje sasiedztwa.\n";
    cout << "(1) - cztery najblizsze pola (gora, dol, lewo, prawo)\n\n";
    cout << "(2) - osiem najblizszych pol (wszystkie pola stykajace sie)\n\n";
    a.defSasiedztwa = wczytajZmienna<short>();
    while (a.defSasiedztwa != 1 && a.defSasiedztwa != 2){
        cout << "Wpisz liczbe 1 lub 2!\n";
        a.defSasiedztwa = wczytajZmienna<short>();
    }
    cout << "\nNacisnij dowolny klawisz, aby wrocic do poprzedniego menu.\n";
    _getch();
}
// MINIMALNY PROCENT CZERWONYCH:
void ustalPodCzer(Plansza& a)
{
    system("cls");
    cout << "Podaj minimalny procent, dla ktorego czerwony agent sie nie wyprowadzi.\n";
    cout << "Wpisz liczbe z przedzialu (0,100).\n\n";
    a.podCzer = wczytajZmienna<float>();

    while (a.podCzer < 0 || a.podCzer > 100)
    {
        cout << "Minimalny procent czerwonych musi byc wartoscia z przedzialu (0,100)!\n"
             << "Wpisz poprawna wartosc.\n";
        a.podCzer = wczytajZmienna<float>();
    }
    cout << "\nNacisnij dowolny klawisz, aby wrocic do poprzedniego menu.\n";
    _getch();
}
// MINIMALNY PROCENT BIALYCH:
void ustalPodBia(Plansza& a){
    system("cls");
    cout << "Podaj minimalny procent, dla ktorego bialy agent sie nie wyprowadzi.\n";
    cout << "Wpisz liczbe z przedzialu (0,100).\n\n";
    a.podBia = wczytajZmienna<float>();
    while (a.podBia < 0 || a.podBia > 100)
    {
        cout << "Minimalny procent czerwonych musi byc wartoscia z przedzialu (0,100)!\n"
             << "Wpisz poprawna wartosc.\n";
        a.podBia = wczytajZmienna<float>();
    }
    cout << "\nNacisnij dowolny klawisz, aby wrocic do poprzedniego menu.\n";
    _getch();
}
// MAKSYMALNA LICZBA ITERACJI:
void ustalMaxIteracji(Plansza& a){
    system("cls");
    cout << "Podaj maksymalna liczbe iteracji, po ktorej program ma zakonczyc symulacje.\n";
    a.maxIteracji = wczytajZmienna<int>();

    while (a.maxIteracji < 1)
    {
        cout << "Liczba iteracji musi byc wieksza od zera!\n"
             << "Wpisz poprawna wartosc.\n";
        a.maxIteracji = wczytajZmienna<int>();
    }

    cout << "\nNacisnij dowolny klawisz, aby wrocic do poprzedniego menu.\n";
    _getch();
}
// SPRAWDZANIE LICZBY POL:
void sprawdzPole (int x, int y, char agent, Plansza a, float &iloscPodobnych, float &iloscSasiadow){
    if (a.tabela[x][y] == agent)
        iloscPodobnych += 1.0;
    if (a.tabela[x][y] != ' ')
        iloscSasiadow += 1.0;
}
// OBLICZANIE LICZBY PODOBNYCH POL:
float odsetekPodobnych(Plansza a, int i, int j){
	char agent = a.tabela[i][j];
	float iloscSasiadow = 0.0;
	float iloscPodobnych = 0.0;
	if (i - 1 >= 0)
    {
		sprawdzPole (i - 1, j, agent, a, iloscPodobnych, iloscSasiadow);

        if (a.defSasiedztwa == 2)
        {
            if (j - 1 >= 0)
                sprawdzPole (i - 1, j - 1, agent, a, iloscPodobnych, iloscSasiadow);

            if (j + 1 < a.szerokosc)
                sprawdzPole (i - 1, j + 1, agent, a, iloscPodobnych, iloscSasiadow);
        }
    }

	if (i + 1 < a.wysokosc)
    {
        sprawdzPole (i + 1, j, agent, a, iloscPodobnych, iloscSasiadow);

        if (a.defSasiedztwa == 2)
        {
            if (j - 1 >= 0)
                sprawdzPole(i + 1, j - 1, agent, a, iloscPodobnych, iloscSasiadow);

            if (j + 1 < a.szerokosc)
                sprawdzPole (i + 1, j + 1, agent, a, iloscPodobnych, iloscSasiadow);
        }
    }

	if (j - 1 >= 0)
        sprawdzPole (i, j - 1, agent, a, iloscPodobnych, iloscSasiadow);

	if (j + 1 < a.szerokosc)
        sprawdzPole (i, j + 1, agent, a, iloscPodobnych, iloscSasiadow);

	if (iloscSasiadow == 0)
        return 1;
	return iloscPodobnych/iloscSasiadow;
}
// PRZENIESIENIE AGENTA DO KOLEJNEJ POZYCJI:
void przeprowadzka(Plansza a, int i, int j){
	char agent = a.tabela[i][j];
	int numerMiejsca = (rand() % ((a.wysokosc*a.szerokosc) - a.liczbaAgentow)) +1;
	int licznikMiejsc = 0;
	for (int idx = 0; idx < a.wysokosc; idx++){
		bool przeprowadzka = false;
		for (int jdx = 0; jdx < a.szerokosc; jdx++)
		{
			if (a.tabela[idx][jdx] == ' ') {
				licznikMiejsc = licznikMiejsc + 1;
				if (licznikMiejsc == numerMiejsca) {
					a.tabela[idx][jdx] = agent;
					a.tabela[i][j] = ' ';
					przeprowadzka = true;
					break;
				}
			}
		}
		if (przeprowadzka) {
			przeprowadzka = false;
			break;
		}

	}
}
// WYSWIETLENIE STATYSTYK:
void wyswietlPodsumowanie(int iteracja, Plansza a, float liczbaNiezadowolonych, float poczatkowaLiczbaNiezadowolonych, float sumaOdsetkowPodobnych, float poczatkowaSumaPodobnych)
{
    cout    << "Liczba wykonanych iteracji =\t" << iteracja - 1 << "\n\n"
            << "Poczatkowy odsetek niezadowolonych =\t" << poczatkowaLiczbaNiezadowolonych / a.liczbaAgentow << "\n"
            << "Koncowy odsetek niezadowolonych = \t" << liczbaNiezadowolonych / a.liczbaAgentow << "\n"
            << "Poczatkowy sredni odsetek podobnych = \t" << poczatkowaSumaPodobnych / a.liczbaAgentow << "\n"
            << "Koncowy sredni odsetek podobnych = \t" << sumaOdsetkowPodobnych / a.liczbaAgentow << "\n";
}


// DATA I CZAS - ZACZERPNIETE Z http://stackoverflow.com/questions/16357999/current-date-and-time-as-string
string getDateAndTime(){
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer,80,"%d-%m-%Y %H:%M:%S",timeinfo);
    std::string str(buffer);

    return (str);
}

// GENEROWANIE RAPORTU O ROZGRYWCE
void stworzRaport(){
    fstream raport;
    raport.open("Raport.txt", ios::out | ios::trunc);
    if (raport.good()){
        raport  << getDateAndTime() << "\n"
                << "Ponizszy raport przedstawia:\n"
                << "- odsetek niezadowolonych agentow w kolejnych iteracjach\n"
                << "- sredni odsetek podobnych w kolejnych iteracjach\n\n"
                << "Iteracja\t| Odsetek niezadowolonych\t| Sredni odsetek podobnych\n";
        raport.close();
    }
}
void aktualizujRaport(int iteracja, float liczbaNiezadowolonych, float sumaOdsetkowPodobnych, Plansza a)
{
    fstream raport;
    raport.open("Raport.txt", ios::out | ios::app);
    if (raport.good())
    {
        raport  << iteracja << "\t\t| " << std::fixed << liczbaNiezadowolonych / a.liczbaAgentow << "\t\t\t| "
                << sumaOdsetkowPodobnych / a.liczbaAgentow << "\n";
        raport.close();
    }
}

void START(Plansza a)
{
    if (a.sprawdz())
    {
        a.aktualizuj();     // Aktualizuje plansze (na wypadek, gdyby uzytkownik zmienil w menu glownym jakies ustawienia)
        stworzRaport(); // Tworze plik oraz jego naglowek

        bool ZaszlaZmiana  = true;
        int iteracja = 1;
        float liczbaNiezadowolonych = 0;
        float poczatkowaLiczbaNiezadowolonych = 0;
        float poczatkowaSumaPodobnych = 0;
        float sumaOdsetkowPodobnych = 0;        // tworze zmienna potrzebna do utworzenia raportu
        for (iteracja = 1; (iteracja <= a.maxIteracji) && ZaszlaZmiana; iteracja++)   // Powtorz ponizsza petle tyle razy, ile wynosi ustalona maksymalna liczba iteracji lub do osiagniecia rownowagi
        {
            system("cls");          // Czyszcze ekran
            cout << "Iteracja: " << iteracja << "\n\n";
            a.wyswietl();
            ZaszlaZmiana = false;
            liczbaNiezadowolonych = 0;
            sumaOdsetkowPodobnych = 0;

            for (int i = 0; i < a.wysokosc; i++)
            {
                for (int j = 0; j < a.szerokosc; j++)
                {
                    if (GetAsyncKeyState(VK_ESCAPE)) {goto koniec;} // jezeli uzytkownik wcisnie Escape, program natychmiast wraca do glownego menu
                    if (a.tabela[i][j] == '*')       // jezeli w analizowanym polu znajduje sie "czerwony"
                    {
                        sumaOdsetkowPodobnych += odsetekPodobnych(a, i, j);
                        if (odsetekPodobnych(a, i, j) < a.podCzer/100) // jezeli analizowanemu agentowi jest "zle"...
                        {
							przeprowadzka(a, i, j);                 // ... to sie wyprowadza
                            ZaszlaZmiana = true;                    // i zapamietuje, ze zaszla zmiana, wiec nie osiagnieto jeszcze rownowagi
                            liczbaNiezadowolonych++;                // zapamietuje, ze w tej iteracji pojawil sie jeszcze jeden niezadowolony
                        }
                    }
                    if (a.tabela[i][j] == '#')                      // jezeli w analizowanym polu znajduje sie "bialy"
                    {
                        sumaOdsetkowPodobnych += odsetekPodobnych(a, i, j);
                        if (odsetekPodobnych(a, i, j) < a.podBia/100)  // jezeli analizowanemu agentowi jest "zle"
                        {
                            przeprowadzka(a, i, j);                    // ... to sie wyprowadza
                            ZaszlaZmiana = true;                    // i zapamietuje, ze zaszla zmiana, wiec nie osiagnieto jeszcze rownowagi
                            liczbaNiezadowolonych++;                // zapamietuje, ze w tej iteracji pojawil sie jeszcze jeden niezadowolony
                        }
                    }
                }
            }
            aktualizujRaport(iteracja, liczbaNiezadowolonych, sumaOdsetkowPodobnych, a);
            if (iteracja == 1)
            {
                poczatkowaLiczbaNiezadowolonych = liczbaNiezadowolonych;
                poczatkowaSumaPodobnych = sumaOdsetkowPodobnych;
            }
        }
        wyswietlPodsumowanie(iteracja, a, liczbaNiezadowolonych, poczatkowaLiczbaNiezadowolonych, sumaOdsetkowPodobnych, poczatkowaSumaPodobnych);
    }
    koniec:
    cout << "\nNacisnij dowolny klawisz, aby wrocic do poprzedniego menu.\n";
    _getch();
}

void wyswietlInstrukcje()
{
    system("cls");

	cout << "***INSTRUKCJA OBSLUGI PROGRAMU***\n\n"
		 << "Ponizej przedstawiona zostala instrukcja programu. Po jej przeczytaniu, wcisnij dowolny klawisz w celu powrotu do menu glownego i postepuj zgodnie z zawartymi w niej wytycznymi.\n\n"
		 << "Najwazniejszym etapem symulacji jest wskazanie odpowiednich parametrow. Na poczatku, nalezy wyznaczyc wymiary planszy. W tym celu, nalezy wybrac w menu glownym (2) poprzez wcisniecie klawisza <2> a nastepnie <enter>; uzytkownik zostanie poproszony o wskazanie wysokosci planszy. Po powrocie do menu glownego, nalezy wybrac w analogiczny sposob (3) i wpisac szerokosc planszy.\n\n"
		 << "Po okresleniu wielkosci planszy, w menu glownym wyswietli sie dostepna na niej liczba pol. W tym momencie, uzytkownik powinien wybrac (4) i wskazac liczbe agentow, jednak musi ona byc nizsza od dostepnej liczby pol.\n\n"
		 << "Nastepnym krokiem, po wybraniu (5), jest podanie przez uzytkownika odsetku (w procentach) agentow 'czerwonych'; automatycznie, pozostali agenci beda 'biali'. Oprocz kolorow, agenci wyrozniaja sie reprezentujacym ich symbolem (czerwoni - '*', biali - '#').\n\n"
		 << "W kolejnym kroku, w punkcie (6), uzytkownik powinien przyjac definicje sasiedztwa. W mysl pierwszej definicji, sasiadami sa jedynie Ci, ktorzy granicza bezposrednio z danym agentem z gory, dolu, badz z lewej lub prawej strony. Zgodnie z te definicja, maksymalna liczba sasiadow wynosi 4. Zgodnie z druga definicja, sasiadami sa rowniez Ci, ktorzy znajduja sie po przekatnej od danego agenta; maksymalna liczba sasiadow wynosi zatem 8.\n\n"
		 << "Nastepnie, w (7) oraz (8) kroku, uzytkownik dokonuje wyboru minimalnego procentu podobnych sasiadow, ktory sprawia, ze dany agent (odpowiednio czerwony i bialy) jest zadowolony. W przypadku, gdy udzial podobnych sasiadow jest nizszy, dany agent bedzie chcial sie przeprowadzic.\n\n"
		 << "W ostatnim, to jest (9) kroku, uzytkownik proszony jest o podanie maksymalnej liczby iteracji, po dotarciu do ktorej - jesli nie zostanie osiagnieta rownowaga - algorytm sie zatrzyma.\n\n"
		 << "Gdy wprowadzone juz zostana wszystkie parametry symulacji, nalezy wcisnac (10), to jest START, w celu uruchomienia symulacji. Po zakoczeniu pracy algorytmu - w wyniku osiagniecia rownowagi lub maksymalnej liczby iteracji - wyswietlona zostanie plansza powstala po przeprowadzeniu ostatniej iteracji, liczba wykonanych iteracji, poczatkowy oraz koncowy odsetek niezadowolonych, a takze poczatkowy i koncowy sredni odsetek podobnych sasiadow.\n\n"
		 << "W wyniku pracy algorytmu, w folderze mieszczacym projekt, wygenerowany zostanie raport zawierajacy odsetek niezawodolnych oraz sredni odsetek podobnych agentow dla kazdej z przeprowadzonych iteracji.\n\n"
		 << "W celu wyjscia z programu, mozna wybrac w menu glownym (11).\n\n"
		 << "Aby wrocic do menu glownego, nacisnij dowolny klawisz...";


	_getch();

}

int main(){
    short wyborMenu = 0;            // INICJALIZACJA OBSLUGI MENU
    Plansza a;                       // UTWORZENIE MENU
    while (wyborMenu != 11){          // 11 - WYJSCIE Z PROGRAMU
        system("cls");              // CZYSZCZENIE EKRANU
        cout << "\t*** Model Schellinga ***\n"
             << "\t Anna Lisowska, Rafal Gapinski\n\n\n"
             << "\t Menu Glowne:\n\n"
             << "(1) Instrukcja obslugi\n"
             << "(2) Wysokosc planszy:\t\t" << a.wysokosc << "\n"
             << "(3) Szerokosc planszy:\t\t" << a.szerokosc << "\n"
             << "    Liczba pol na planszy:\t" << a.wysokosc*a.szerokosc << "\n"
             << "(4) Liczba agentow:\t\t" << a.liczbaAgentow << "\n"
             << "(5) Procent \"czerwonych\":\t" << a.procentCzerwonych << "\n"
             << "(6) Definicja sasiedztwa:\t" << a.defSasiedztwa << "\n"
             << "(7) Minimalny procent podobnych (dla \"czerwonych\"):\t" << a.podCzer << "\n"
             << "(8) Minimalny procent podobnych (dla \"bialych\"):\t" << a.podBia << "\n"
             << "(9) Maksymalna liczba iteracji:\t" << a.maxIteracji << "\n\n"
             << "(10) START" << "\n\n"
             << "(11) Wyjdz\n\n";
        // PO KOLEI: WARUNKI WYBORU:
        wyborMenu = wczytajZmienna<short>();
        switch(wyborMenu){
        case 1:
            wyswietlInstrukcje();
            break;
        case 2:
            ustalWysokoscPlanszy(a);
            break;
        case 3:
            ustalSzerokoscPlanszy(a);
            break;
        case 4:
            ustalLiczbeAgentow(a);
            break;
        case 5:
            ustalProcentCzerwonych(a);
            break;
        case 6:
            ustalDefinicjeSasiedztwa(a);
            break;
        case 7:
            ustalPodCzer(a);
            break;
        case 8:
            ustalPodBia(a);
            break;
        case 9:
            ustalMaxIteracji(a);
            break;
        case 10:
            START(a);
            break;
        case 11:
            system ("cls");
			cout << "Do widzenia!\n\n";
			break;
        default:
            cout << "Podaj liczbe od 1 do 11.\n";
            break;
        }
    }
}
