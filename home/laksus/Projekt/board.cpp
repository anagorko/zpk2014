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
        hero = al_load_bitmap("images/flappy-bird.png");
    background = al_load_bitmap("images/background.jpg");
    obstacle_up = al_load_bitmap("images/mario_pipe_up.png");
    obstacle_down = al_load_bitmap("images/mario_pipe_down.png");
    endgame = al_load_bitmap("images/game_over.jpg");
    al_draw_scaled_bitmap(background,0,0,400,300,0,0,w,h,0);
    al_flip_display();
}

void Board::close(){
    al_destroy_display(board);
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

void Board::refresh_background(){
    al_draw_scaled_bitmap(background,0,0,400,300,0,0,w,h,0);
}

void Board::show(){
    al_flip_display();
}

void Board::end_game(){
    al_draw_scaled_bitmap(endgame,0,0,480,480,0,0,w,h,0);
    show();
}
