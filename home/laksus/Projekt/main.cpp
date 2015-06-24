#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

#include "bird.h"
#include "board.h"
#include "obs.h"
#include "menu.h"

ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_EVENT ev;
ALLEGRO_TIMER *timer;
ALLEGRO_DISPLAY *displ;


//uzywam kolejki aby w przyszlosci moc zmienic ja na priority queue i dorzucaæ przeszkody z dowolnego miejsca kodu
queue<Pipe>OBS;


int obsCount=1, pom, ObstacleCompleted, actLvl=0, hero=3, diff=1,pipeType=1;
bool failed, decision_made, quit_game, new_lvl;

double angle;

int main(){
    al_init();
    al_install_keyboard();
    al_install_mouse(); //sterowanie jest klawiatura, ale uzywam ukrywania myszki i mozliwosci zamkniecia krzyzykiem
    al_init_image_addon();
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    displ = al_create_display(800, 600);
    al_set_window_title(displ,"Flappy Bird v. 3.0beta");

    Board plansza;
    Bird flap;
    MainMenu men;
    Menu *act_menu;
    SettingsMenu set_menu;
    act_menu = &men;

    plansza.init(0);
    al_set_display_icon(displ,plansza.hero);
    al_hide_mouse_cursor(displ);

    event_queue = al_create_event_queue();
    timer = al_create_timer(4.5*plansza.level[actLvl].multiplier/60);


    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_display_event_source(displ));


    while(!quit_game){

        act_menu->select_menu_item(0);

        while(!decision_made){ //Petla obslugujaca menu glowne i menu ustawien

            if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                quit_game = true;
                decision_made = true;
                actLvl = 5;
                break;
            }

            if(ev.type == ALLEGRO_EVENT_KEY_DOWN){

                if(ev.keyboard.keycode == ALLEGRO_KEY_UP || ev.keyboard.keycode == ALLEGRO_KEY_RIGHT){
                    act_menu->select_menu_item(1);
                }

                else if(ev.keyboard.keycode == ALLEGRO_KEY_DOWN || ev.keyboard.keycode == ALLEGRO_KEY_LEFT){
                    act_menu->select_menu_item(-1);
                }

                else if(ev.keyboard.keycode == ALLEGRO_KEY_ENTER){

                    if(act_menu->type() == 0){ //menu glowne
                            switch(act_menu->actual_selection()){

                            case 0:{
                                decision_made = true;
                                break;
                            }
                            case 1:{
                                decision_made = true;
                                break;
                            }
                            case 2:{
                                    act_menu = &set_menu;
                                    set_menu.actButton=0;
                                    act_menu->select_menu_item(0);
                                    break;
                            }
                            case 3:{
                                plansza.welcome();
                                Sleep(4000);
                                act_menu->select_menu_item(0);
                                break;
                            }
                            case 4:{
                                quit_game = true;
                                decision_made = true;
                                actLvl = 5;
                                break;
                            }
                            }
                    }

                    else if(act_menu->type() == 1){ //menu ustawien

                        switch(act_menu->actual_selection()){
                            case 0:{
                                diff = act_menu->actual_selection();
                                set_menu.actDiff = diff;
                                act_menu->select_menu_item(0);
                                break;
                            }
                            case 1:{
                                diff = act_menu->actual_selection();
                                set_menu.actDiff = diff;
                                act_menu->select_menu_item(0);
                                break;
                            }
                            case 2:{
                                diff = act_menu->actual_selection();
                                set_menu.actDiff = diff;
                                act_menu->select_menu_item(0);
                                break;
                            }
                            case 3:{
                                hero = act_menu->actual_selection();
                                set_menu.actHero = hero;
                                act_menu->select_menu_item(0);
                                break;
                            }
                            case 4:{
                                hero = act_menu->actual_selection();
                                set_menu.actHero = hero;
                                act_menu->select_menu_item(0);
                                break;
                            }
                            case 5:{
                                hero = act_menu->actual_selection();
                                set_menu.actHero = hero;
                                act_menu->select_menu_item(0);
                                break;
                            }
                            case 6:{
                                act_menu = &men;
                                act_menu->select_menu_item(0);
                                break;
                            }
                            }
                    }
                }
            }
            al_wait_for_event(event_queue, &ev);
        }

        decision_made = false;
        failed = false;
        new_lvl = true;
        ObstacleCompleted = 0;
        obsCount = 1;
        while(!OBS.empty())
            OBS.pop();
        Pipe p(pipeType);
        OBS.push(p);
        flap.reset();
        angle = 0;
        plansza.init(hero-3);
        if(diff == 2)
            diff = 10;
        else if(diff == 1)
            diff = 15;
        else
            diff = 20;
        //przekodowuje zmienna trudnosci bo latwiej jej potem uzyc w zmienionej formie

        while(!flap.collision_ground() && !failed && actLvl<5){ //petla obslugujac glowna gre

            if(new_lvl){
                plansza.counting(actLvl);
                new_lvl = false;
            }

            al_start_timer(timer);
            al_wait_for_event(event_queue, &ev);
            plansza.refresh_background(actLvl);

            if(ev.type == ALLEGRO_EVENT_KEY_DOWN){
                if(ev.keyboard.keycode == ALLEGRO_KEY_UP){
                    flap.move(-1*(diff/10),15*plansza.level[actLvl].multiplier);
                    angle = 0;
                }
            }

            if(ev.type == ALLEGRO_EVENT_TIMER){
                flap.move(1,5*(plansza.level[actLvl].multiplier-0.05));
                angle += 0.05;
                angle = min(angle,90.0);
            }

            pom = obsCount;
                while(pom--){ // odswiezam wszystkie przeszkody od pierwszej do ostatniej, tutaj kolejka bardzo sie przydaje
                    if(OBS.front().getX() == 400){
                            if(pipeType==1){
                                p.randHigh(-1);
                                pipeType = -1;
                            }
                            else{
                                p.randHigh(1);
                                pipeType = 1;
                            }
                            OBS.push(p);
                            obsCount++;
                    }
                    OBS.front().move(5);

                    if(flap.collision_obstacle(OBS.front().getX(),OBS.front().getY()))
                        failed = true;
                    plansza.refresh_pipe(OBS.front().getX(),OBS.front().getY());

                    if(OBS.front().getX()<0){
                        obsCount--;
                        ObstacleCompleted++;
                    }

                    if(OBS.front().getX()>=0)
                        OBS.push(OBS.front());
                        OBS.pop();
                }

            plansza.refresh_hero(flap.getXb(), flap.getYb(), angle);
            plansza.refresh_counter(ObstacleCompleted,plansza.level[actLvl].ObstacleLevel,actLvl+1);
            plansza.show();

            if(ObstacleCompleted >= plansza.level[actLvl].ObstacleLevel){ //sprawdzenie czy ukonczono poziom
                al_stop_timer(timer);
                plansza.win_lvl();
                actLvl ++;
                ObstacleCompleted = 0;
                obsCount = 1;
                while(!OBS.empty())
                    OBS.pop();
                Pipe p;
                OBS.push(p);
                flap.reset();
                angle = 0;
                new_lvl = true;
                timer = al_create_timer(4.5*plansza.level[actLvl].multiplier/60); //z kazdym poziomem plansza przyspiesza
                al_register_event_source(event_queue, al_get_timer_event_source(timer));
            }
        }
        if(failed || flap.collision_ground()){
            al_stop_timer(timer);
            plansza.end_game();
            actLvl = 0;
            Sleep(1000);
        }
    }
    al_destroy_display(displ);
    return 0;
}
