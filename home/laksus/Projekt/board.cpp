#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include<iostream>
#include "board.h"

using namespace std;

void Board::init(int bird_type){
    ALLEGRO_PATH *path = al_get_standard_path(ALLEGRO_RESOURCES_PATH); //uzywam odwolan wzglednych do obrazkow i czcionek, foldery musza byc obok pliku wykonywalnego
    al_append_path_component(path, "images");

    if(bird_type == 0){
        al_set_path_filename(path, "hero.png");
        hero = al_load_bitmap(al_path_cstr(path, '/'));
    }
    else if(bird_type == 1){
        al_set_path_filename(path, "hero2.png");
        hero = al_load_bitmap(al_path_cstr(path, '/'));
    }
    else if(bird_type == 2){
        al_set_path_filename(path, "hero3.png");
        hero = al_load_bitmap(al_path_cstr(path, '/'));
    }

    al_set_path_filename(path, "background1.jpg");
    level[0].background = al_load_bitmap(al_path_cstr(path, '/'));

    al_set_path_filename(path, "background2.png");
    level[1].background = al_load_bitmap(al_path_cstr(path, '/'));

    al_set_path_filename(path, "background3.jpeg");
    level[2].background = al_load_bitmap(al_path_cstr(path, '/'));

    al_set_path_filename(path, "background4.jpeg");
    level[3].background = al_load_bitmap(al_path_cstr(path, '/'));

    al_set_path_filename(path, "background5.jpeg");
    level[4].background = al_load_bitmap(al_path_cstr(path, '/'));

    al_set_path_filename(path, "1.png");
    counter[0] = al_load_bitmap(al_path_cstr(path, '/'));

    al_set_path_filename(path, "2.png");
    counter[1] = al_load_bitmap(al_path_cstr(path, '/'));

    al_set_path_filename(path, "3.png");
    counter[2] = al_load_bitmap(al_path_cstr(path, '/'));

    al_set_path_filename(path, "4.png");
    counter[3] = al_load_bitmap(al_path_cstr(path, '/'));

    al_set_path_filename(path, "Mario_pipe_up.png");
    obstacle_up = al_load_bitmap(al_path_cstr(path, '/'));

    al_set_path_filename(path, "Mario_pipe_down.png");
    obstacle_down = al_load_bitmap(al_path_cstr(path, '/'));

    al_set_path_filename(path, "helper.png");
    helper = al_load_bitmap(al_path_cstr(path, '/'));

    al_set_path_filename(path, "win.png");
    lvl_win = al_load_bitmap(al_path_cstr(path, '/'));

    al_set_path_filename(path, "game_over.jpg");
    endgame = al_load_bitmap(al_path_cstr(path, '/'));


    path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
    al_append_path_component(path, "fonts");
    al_set_path_filename(path, "arial.ttf");
    MenuFont = al_load_ttf_font(al_path_cstr(path, '/'),20,0);

    for(int i = 0; i < 5; i++){  //kazda plansza ma wiekszy poziom trudnosci dlatego maleje ilosc koniecznych do ukonczenia
        level[i].ObstacleLevel = 10/(i+1);
        level[i].multiplier = 1-(0.1*i);
    }
}

void Board::welcome(){ //tutorial w formie krotkiej instrukcji, znajduje sie w klasie board bo pierwotnie mial byc wyswietlany przy rozpoczeciu nowej rozgrywki
    refresh_background(0);
    al_draw_bitmap(helper,100,100,0);
    al_draw_rectangle(100,100,w-100,h-100,al_map_rgb(0,0,0),2);
    show();
}

void Board::refresh_hero(double b_x, double b_y, double angle){
    al_draw_scaled_rotated_bitmap(hero,80,60,b_x,b_y,0.373,0.504,angle,0);
}

void Board::refresh_pipe(double p_x, double p_y){ //oddzielnie traktuje koniec rury i rure aby nie byla rozciagnieta i dobrze wygladala przy kazdej dlugosci
    al_draw_scaled_bitmap(obstacle_down,0,0,183,213,p_x+15,p_y+45,70,h-p_y-40,0);
    al_draw_scaled_bitmap(obstacle_up,0,0,233,88,p_x,p_y,100,50,0);

    al_draw_scaled_bitmap(obstacle_down,0,0,183,213,p_x+15,0,70,p_y-190,0);
    al_draw_scaled_bitmap(obstacle_up,0,0,233,88,p_x,p_y-200,100,50,0);
}

void Board::refresh_background(int _lvl){
    al_draw_scaled_bitmap(level[_lvl].background,0,0,400,300,0,0,w,h,0);
}

void Board::refresh_counter(int _cnt, int lvl_req, int _lvl){
    al_draw_filled_rectangle(30,30,270,70,al_map_rgb(255,255,255));
    al_draw_rectangle(30,30,270,70,al_map_rgb(0,0,0),3);
    al_draw_textf(MenuFont,al_map_rgb(0,0,0),145,40,ALLEGRO_ALIGN_CENTER,"Lvl: %d  Przeszkody: %d / %d",_lvl, _cnt,lvl_req);
}

void Board::counting(int _lvl){
    for(int i = 3; i>=0; i--){
        refresh_background(_lvl);
        al_draw_bitmap(counter[i],272,172,0);
        show();
        Sleep(500);
    }
}

void Board::win_lvl(){
    double scale;
    while(313*scale <= 600){
        al_draw_scaled_rotated_bitmap(lvl_win,156,116,w/2,h/2,scale,scale,0,0);
        show();
        scale += 0.01;
        Sleep(25);
    }
}

void Board::show(){
    al_flip_display();
}

void Board::end_game(){
    al_draw_scaled_bitmap(endgame,0,0,480,480,w/2,h/2,w/2,h/2,0);
    show();
}






