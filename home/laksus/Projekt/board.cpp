#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include<iostream>
#include "board.h"

using namespace std;

void Board::init(int bird_type){
    ALLEGRO_PATH *path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
    al_append_path_component(path, "images");

    if(bird_type == 0){
        al_set_path_filename(path, "hero.png");
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
    if(MenuFont == NULL)
        cout << "problem font" << endl;

    for(int i = 0; i < 5; i++){
        level[i].ObstacleLevel=10/(i+1);
    }
}

void Board::refresh_hero(double b_x, double b_y, double angle){
    //al_draw_scaled_bitmap(hero,0,0,161,119,b_x,b_y,60,60,0);
    al_draw_scaled_rotated_bitmap(hero,80,60,b_x,b_y,0.373,0.504,angle,0);
}

void Board::refresh_pipe(double p_x, double p_y){
    al_draw_scaled_bitmap(obstacle_down,0,0,183,213,p_x+15,p_y+45,70,h-p_y-40,0);
    al_draw_scaled_bitmap(obstacle_up,0,0,233,88,p_x,p_y,100,50,0);

    al_draw_scaled_bitmap(obstacle_down,0,0,183,213,p_x+15,0,70,p_y-140,0);
    al_draw_scaled_bitmap(obstacle_up,0,0,233,88,p_x,p_y-150,100,50,0);
}

void Board::refresh_background(int _lvl){
    al_draw_scaled_bitmap(level[_lvl].background,0,0,400,300,0,0,w,h,0);
}

void Board::show(){
    al_flip_display();
}

void Board::end_game(){
    al_draw_scaled_bitmap(endgame,0,0,480,480,w/2,h/2,w/2,h/2,0);
    show();
}

void Board::refresh_counter(int _cnt, int lvl_req, int _lvl){
    al_draw_filled_rectangle(30,30,270,70,al_map_rgb(255,255,255));
    al_draw_rectangle(30,30,270,70,al_map_rgb(0,0,0),3);
    al_draw_textf(MenuFont,al_map_rgb(0,0,0),145,40,ALLEGRO_ALIGN_CENTER,"Lvl: %d  Przeszkody: %d / %d",_lvl, _cnt,lvl_req);
}

void Board::win_lvl(){
    double scale, angl;
    while(313*scale <= 600){
        al_draw_scaled_rotated_bitmap(lvl_win,156,116,w/2,h/2,scale,scale,0,0);
        show();
        scale += 0.01;
        Sleep(25);
    }
}

void Board::welcome(){
    refresh_background(0);
    refresh_hero(80,150,0);
    //al_draw_filled_rectangle(180,100,700,500,al_map_rgb(255,255,255));
    al_draw_scaled_bitmap(helper,0,0,400,300,180,100,520,400,0);
    show();
    Sleep(4000);
}


void Board::pause(){
    al_draw_filled_rectangle(100,100,700,500,al_map_rgb(255,255,255));
    al_draw_text(MenuFont,al_map_rgb(0,0,0),400,300,ALLEGRO_ALIGN_CENTER,"PAUSE: enter lub c");
    show();
}
