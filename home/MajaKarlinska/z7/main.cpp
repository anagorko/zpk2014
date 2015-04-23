#include <allegro5/allegro.h> //Main Allegro header
#include <allegro5/allegro_primitives.h> //aby moc np rysowac odcinki
//zainstowalismy zewnetrzna biblioteke allegro, sluzy ona do obslugi ekranu, rysowania na ekranie
//powyzej jest zalaczenie tejze biblioteki.
int main()
{
//This is the display on which you draw everyting
ALLEGRO_DISPLAY *display; //*display jest wskaznikiem do obiektu ALLEGRO DISPLAY, czyli do okienka na ktorym rysujemy
//If Allegro fails to initialize show a message box
    if(!al_init()) //al_init - inicjalizuje wszystko/ allegro, okienko, jesli nie zostaje zainicjowana biblioteka
    //wychodzimy z progmamu z liczba 1
    return 1;
//Define the display
    if(!al_init_primitives_addon())
    return 4; //aby skorzystac z biblioteki primitvies
    display = al_create_display(800, 600); // tutaj tworzymy okienko o rozmiarze 800x600

//If Allegro fails to create a display show a message box
    if(display == NULL)
    return 2; //je¿eli okienko by siê nie otworzy³o, program siê koñczy z liczb¹ 2 (pojawia siê ona na dole)

al_clear_to_color(al_map_rgb(0,0,255)); //t³o - dzialamy na czerwonym, zielonym, niebieskim, (rgb), zmieniamy kolor
//tla, kolory zmieniaja sie od 0 do 255.
al_draw_line( 10, 15, 80, 90, al_map_rgba( 0, 255, 0, 128), 4); //rysujemy odcinek, podajemy wspolrzedne poczatku (x1,y1)
//i konca odcinka, pozniej kolor, a na koncu grubosc odcinka - 4 px
        al_draw_triangle(100, 15, 150, 25, 125, 80, al_map_rgb(255, 0, 0), 8); //rysuj trojkat
        al_draw_filled_triangle(190, 15, 250, 76, 175, 80, al_map_rgb(0,0,255)); //rysuj wypelniony trojkat
        al_draw_rectangle(250,10,300, 60,al_map_rgba(255,255,0,128),2);
        al_draw_filled_rectangle(280, 20,350, 80,al_map_rgba(0,0,0,100)); //kolor tworzony inaczej niz zwykle
        //do rgb dodane jest a - przezroczystosc - tworzymy cos np polprzezroczystego
        al_draw_rounded_rectangle( 50,100,100,150,12,12,al_map_rgb(0,255,255),5);
        al_draw_filled_rounded_rectangle(110, 90,150,154, 12, 20,al_map_rgb(128,0,255));
        al_draw_circle(200,120, 30, al_map_rgb( 0,128, 0), 20); //rysuj kolo o grubosci 20
        al_draw_filled_circle(250,120, 34, al_map_rgba(200,28, 0,60)); //rysuj uzupelnione kolo (z srodkiem)

al_flip_display(); //aby uruchomilo sie - ze zmienionym tlem - trzeba koniecznie dolozyc te linijke

//Show the application window for 5 seconds
//(if you don't, the application will shut down immediately after you launch it)
al_rest(5.0f); //uœnij/ odpocznij na 5 sekund - pozwala na wyœwietlanie okienka przez 5 s.

//Deallocate the memory used for the display creation
al_destroy_display(display); //skasowanie okienka
return 0;
}
