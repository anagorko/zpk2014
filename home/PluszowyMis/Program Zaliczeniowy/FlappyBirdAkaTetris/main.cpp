#include<iostream>
#include<math.h>
#include<vector>
#include<string>
//allegro:
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>

//klasy i funkcje dodatkowe
#include "cPoint.h"
#include "cObject.h"
#include "cPipe.h"
#include "cTetris.h"
#include "cObstacle.h"


using namespace std;

////podstawowe własności okna i biblioteki:
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const float START_GAME_X = 20;
const float FPS = 60.0;
const float GAME_TEMPO = 100.0;

////komunikaty podstawowe:
string info_kontakt = "Proszę o skontaktowanie sie z twórcą oprogramowania:\n\tk.s.m.jaskiewicz@gmail.com";
string ERROR_INIT_LIB_OR_OBJECT = "BŁĄD INICJALIZACJI!\n\n" + info_kontakt + "\n\n(bilioteka Allegro)";
string ERROR_DISPLAY_BITMAP = "BŁĄD PRZETWARZANIA OBRAZU!\n\n" + info_kontakt + "\n\n(loading bitmap)";
//
////cObstacle
//const int MINIMUM_HOLE_SIZE = 60;
//const int MAXIMUM_HOLE_SIZE = 200;
//const float MAXIMUM_HOLE_DIFFERENCE_Y = 200.0;
//const int MAX_DIFFERENCE_OBSTACLE = 200;
//
////cTetris:
//const int MAXIMUM_FLYING_TIME = 15;
//const int HEIGHT_TETRIS = 40;
//const int WIDTH_TETRIS = 40;
//
////cPipe
//const int HEIGHT_PIPE = 200;
//const int WIDTH_PIPE = 60;
//

////ścieżki do grafiki:
string TETRIS_DIR_BITMAP = "images/tetris_cube.png";
//string PIPE_DIR_BITMAP = "";
string BACKGROUD_DIR_BITMAP = "";

int main(){
    float lastValueObstacle = SCREEN_HEIGHT/2;

    //inicjalizacja biblioteki allegro(potrzebnych modu³ów)
    if (!al_init() || !al_install_keyboard() || !al_init_image_addon()) {
        cout << ERROR_INIT_LIB_OR_OBJECT << endl;
        return 1;
    }
    al_init_font_addon();
    al_init_ttf_addon();
    //utworzenie wskaŸników do obiektów typu display, timer i kolejki
    ALLEGRO_DISPLAY *display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
    ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();


    //weryfikacja poprawnie utworzonych obiektów
    if (display == NULL || timer == NULL || event_queue == NULL) {
        cout << ERROR_DISPLAY_BITMAP << endl;
        return 2;
    }

    //zarejestrowanie eventów
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_clear_to_color(al_map_rgb(0,0,0));
    al_flip_display();

    al_start_timer(timer);

    //background
    ALLEGRO_BITMAP *backgroundImage = al_load_bitmap("images/background.png");
    ALLEGRO_FONT *fontScoreboard = al_load_ttf_font("images/Pacifico.ttf", 30, 0);

    cTetris newMainPlayer(TETRIS_DIR_BITMAP);

    vector<cObstacle*> vObstacles;
    vObstacles.push_back(new cObstacle(lastValueObstacle));

    al_start_timer(timer);
    float time = 0.0;
    bool gameOver = false;

    //gra:
    while(true){

        al_clear_to_color(al_map_rgb(0,0,0));
        al_draw_bitmap(backgroundImage, 0, 0, 0);
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        //poruszanie się w górę albo w dół:
        newMainPlayer.fly(GAME_TEMPO/FPS);
        newMainPlayer.drawTetris();

        //sprawdzenie czy gracz nadal frunie czy może juz spada w dół
        if(newMainPlayer.stillFlying()){
            newMainPlayer.incrementFly();
        }

        for(cObstacle* obs: vObstacles){
            obs->moveLeft(GAME_TEMPO/FPS);
            obs->drawObstacle();
            // czy doszło do kolizji z obiektem klasy cObstacle
            if(newMainPlayer.collidesWithObstacle(*obs)){
                gameOver = true;
            }
            // sprawdzenie czy któryś z cObstacle przekroczył już cTetris:
            if(obs->frontX() < newMainPlayer.backX() && !obs->Counted){
                newMainPlayer.GotPoints++;
                obs->Counted = true;
            }
        }

        //sprawdzenie czy któryś już jest poza ekranem -> jeżeli tak to go usunąć z vObstacles
        if(vObstacles.front()->frontX() < 0){
            vObstacles.erase(vObstacles.begin());
        }

        //czy gracz wyszedł poza obszar gry
        if(newMainPlayer.collidesWithBoard()){
            gameOver = true;
        }

        //obługa klawisza w górę
        if(ev.type == ALLEGRO_EVENT_KEY_DOWN){
            if(ev.keyboard.keycode == ALLEGRO_KEY_UP){
                newMainPlayer.startFly();
            }
        }

        //tworzenie nowego obiektu:
        if(ev.type == ALLEGRO_EVENT_TIMER){
            time = time + 1.0/FPS;
            if(time > 3.5){
                lastValueObstacle = vObstacles.back()->topHoleY();
                vObstacles.push_back(new cObstacle(lastValueObstacle));
                time = 0.0;
                //weryfikacja wyniku:

            }
        }
        //wyświetlenie wyniku:
        al_draw_textf(fontScoreboard , al_map_rgb(255, 255, 255) , 600 , 20 , 0, "WYNIK: %d", newMainPlayer.GotPoints);
        al_flip_display();

        if(gameOver){
            break;
        }
    }

    al_show_native_message_box(display, "FlappyTetris", "GAME OVER!", "KONIEC GRY...", 0, 0);

    //czyszczenie:
    vObstacles.clear();
    al_destroy_bitmap(backgroundImage);
    al_destroy_font(fontScoreboard);
    al_shutdown_ttf_addon();
    al_shutdown_font_addon();
    al_uninstall_keyboard();

}

