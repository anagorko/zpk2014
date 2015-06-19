#include<iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include<queue>

#define PB push_back

using namespace std;

#include "bird.h"
#include "board.h"
#include "obs.h"

int obsCount=1, pom;
bool done;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_EVENT ev;
ALLEGRO_TIMER *timer;
queue<Pipe>OBS;

int main(){
    al_init();
    al_install_keyboard();

    Board plansza;
    Bird flap;
    Pipe pip;
    OBS.push(pip);

    plansza.init(flap.type);
    event_queue = al_create_event_queue();
    timer = al_create_timer(8.0/60);

    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_start_timer(timer);
    while(!done){
        al_wait_for_event(event_queue, &ev);
        plansza.refresh_background();
        if(ev.type == ALLEGRO_EVENT_KEY_DOWN){
            if(ev.keyboard.keycode == ALLEGRO_KEY_UP){
                flap.move(-1,10);
            }
            if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                done = true;
        }
        else if(ev.type == ALLEGRO_EVENT_TIMER){
            flap.move(1,5);
        }
        pom = obsCount;
            while(pom--){
                if(OBS.front().getX()==500){
                        Pipe p;
                        OBS.push(p);
                        obsCount++;
                }
                OBS.front().move(5);
                if(flap.collision_obstacle(OBS.front().getX(),OBS.front().getY()))
                    done = true;
                plansza.refresh_pipe(OBS.front().getX(),OBS.front().getY());
                if(OBS.front().getX()<0)
                    obsCount--;
                if(OBS.front().getX()>=0)
                    OBS.push(OBS.front());
                    OBS.pop();
            }
        //flap.show_position();
        plansza.refresh_hero(flap.getX(), flap.getY());
        plansza.show();
        if(flap.collision_ground())
            done = true;
    }
    plansza.end_game();
    while(ev.keyboard.keycode != ALLEGRO_KEY_ESCAPE)
            al_wait_for_event(event_queue, &ev);
    plansza.close();
    return 0;
}
