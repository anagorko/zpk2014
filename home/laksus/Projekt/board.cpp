#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include<iostream>
#include "board.h"

using namespace std;

void Board::init(int bird_type){

    if(!al_init()) {
        cerr << "Blad podczas inicjalizacji allegro." << endl;
        assert(false);
    }
    al_init_image_addon();

    board = al_create_display(w, h);
    al_set_window_title(board,"Flappy Bird v. 1.0alfa");

    if(!board) {
        cerr << "Blad podczas inicjalizacji ekranu." << endl;
        assert(false);
    }
    if(bird_type == 0)
        hero = al_load_bitmap("flappy-bird.png");
    background = al_load_bitmap("background.jpg");
    obstacle_up = al_load_bitmap("mario_pipe_up.png");
    obstacle_down = al_load_bitmap("mario_pipe_down.png");
    endgame = al_load_bitmap("game_over.jpg");
    al_draw_scaled_bitmap(background,0,0,400,300,0,0,w,h,0);
    al_flip_display();
}

void Board::close(){
    al_destroy_display(board);
}

void Board::refresh_hero(double b_x, double b_y){
    al_draw_scaled_bitmap(hero,0,0,161,119,b_x,b_y,60,60,0);
    //al_draw_line(0,b_y+7,800,b_y+7,al_map_rgb(0,0,0),1);
    //al_draw_line(0,b_y+30,800,b_y+30,al_map_rgb(0,0,0),1);
    //al_draw_line(0,b_y+53,800,b_y+53,al_map_rgb(0,0,0),1);
}

void Board::refresh_pipe(double p_x, double p_y){
        al_draw_scaled_bitmap(obstacle_down,0,0,183,213,p_x+15,p_y+45,70,h-p_y-40,0);
        al_draw_scaled_bitmap(obstacle_up,0,0,233,88,p_x,p_y,100,50,0);

        al_draw_scaled_bitmap(obstacle_down,0,0,183,213,p_x+15,0,70,p_y-140,0);
        al_draw_scaled_bitmap(obstacle_up,0,0,233,88,p_x,p_y-150,100,50,0);

        //al_draw_line(p_x,0,p_x,600,al_map_rgb(1,0,0),1);
        //al_draw_line(0,p_y,800,p_y,al_map_rgb(1,0,0),1);

        //al_draw_line(0,p_y-100,800,p_y-100,al_map_rgb(1,0,0),1);
}

void Board::refresh_background(){
    al_draw_scaled_bitmap(background,0,0,400,300,0,0,w,h,0);
    //al_draw_line(110,0,110,600,al_map_rgb(0,0,0),1);
    //al_draw_line(87,0,87,600,al_map_rgb(0,0,0),1);
    //al_draw_line(137,0,137,600,al_map_rgb(0,0,0),1);
}

void Board::show(){
    al_flip_display();
}


void Board::end_game(){
    al_draw_scaled_bitmap(endgame,0,0,480,480,0,0,w,h,0);
    show();
}
