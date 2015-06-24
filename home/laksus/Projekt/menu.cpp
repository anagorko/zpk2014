#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include<iostream>
#include "menu.h"

using namespace std;

MainMenu::MainMenu(){
    ALLEGRO_PATH *path = al_get_standard_path(ALLEGRO_RESOURCES_PATH); //uzywam odwolan wzglednych do obrazkow i czcionek, foldery musza byc obok pliku wykonywalnego
    al_append_path_component(path, "images");

    al_set_path_filename(path, "title_screen.png");
    title = al_load_bitmap(al_path_cstr(path, '/'));

    al_set_path_filename(path, "background1.jpg");
    background = al_load_bitmap(al_path_cstr(path, '/'));

    al_set_path_filename(path, "butt1.png");
    buttons[0] = al_load_bitmap(al_path_cstr(path, '/'));

    al_set_path_filename(path, "butt2.png");
    buttons[1] = al_load_bitmap(al_path_cstr(path, '/'));

    al_set_path_filename(path, "butt3.png");
    buttons[2] = al_load_bitmap(al_path_cstr(path, '/'));

    al_set_path_filename(path, "butt5.png");
    buttons[3] = al_load_bitmap(al_path_cstr(path, '/'));

    al_set_path_filename(path, "butt4.png");
    buttons[4] = al_load_bitmap(al_path_cstr(path, '/'));

    actButton = 0;
    al_destroy_path(path);
}

MainMenu::~MainMenu(){}

void MainMenu::display(){
    al_draw_scaled_bitmap(background,0,0,400,300,0,0,w,h,0);
    al_draw_scaled_bitmap(title,0,0,1500,1000,175,100,700,600,0);

    for(int i = 0; i < ButtonCount; i++){
        if(i/3 < 1)
            show_button(buttons[i],130+200*i,300);
        else
            show_button(buttons[i],30+200*(i-2),400);
    }
    al_flip_display();
}

void MainMenu::show_button(ALLEGRO_BITMAP* but, int pos_x, int pos_y){
    al_draw_scaled_bitmap(but,0,0,325,185,pos_x,pos_y,140,70,0);
}

void MainMenu::select_menu_item(int direction){
    display();
    actButton += direction;
    if(actButton > (ButtonCount-1))
        actButton = 0;
    else if(actButton < 0)
        actButton = ButtonCount - 1;
    if(actButton/3 < 1)
        al_draw_rounded_rectangle(130+200*actButton,300,130+200*actButton+140,370,25,25,al_map_rgb(0,0,0),5);
    else
        al_draw_rounded_rectangle(30+200*(actButton-2),400,30+200*(actButton-2)+140,470,25,25,al_map_rgb(0,0,0),5);
    al_flip_display();
}

int MainMenu::type(){
    return typ;
}

int MainMenu::actual_selection(){
    return actButton;
}




SettingsMenu::SettingsMenu(){
ALLEGRO_PATH *path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
    al_append_path_component(path, "images");

    al_set_path_filename(path, "background1.jpg");
    background = al_load_bitmap(al_path_cstr(path, '/'));

    al_set_path_filename(path, "butt7.png");
    buttons[0] = al_load_bitmap(al_path_cstr(path, '/'));

    al_set_path_filename(path, "butt8.png");
    buttons[1] = al_load_bitmap(al_path_cstr(path, '/'));

    al_set_path_filename(path, "butt9.png");
    buttons[2] = al_load_bitmap(al_path_cstr(path, '/'));

    al_set_path_filename(path, "hero.png");
    buttons[3] = al_load_bitmap(al_path_cstr(path, '/'));

    al_set_path_filename(path, "hero2.png");
    buttons[4] = al_load_bitmap(al_path_cstr(path, '/'));

    al_set_path_filename(path, "hero3.png");
    buttons[5] = al_load_bitmap(al_path_cstr(path, '/'));

    al_set_path_filename(path, "butt6.png");
    buttons[6] = al_load_bitmap(al_path_cstr(path, '/'));

    path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
    al_append_path_component(path, "fonts");
    al_set_path_filename(path, "arial.ttf");
    MenuFont = al_load_ttf_font(al_path_cstr(path, '/'),28,0);

    actButton = 0;
    actHero = 3;
    actDiff = 1;
    al_destroy_path(path);
}

SettingsMenu::~SettingsMenu(){}

void SettingsMenu::display(){
    al_draw_scaled_bitmap(background,0,0,400,300,0,0,w,h,0);

    al_draw_filled_rectangle(130,30,670,80,al_map_rgb(255,255,255));
    al_draw_rectangle(130,30,670,80,al_map_rgb(0,0,0),2);
    al_draw_text(MenuFont,al_map_rgb(0,0,0),400,40,ALLEGRO_ALIGN_CENTER,"Wybierz poziom trudnosci:");

    al_draw_filled_rectangle(130,230,670,280,al_map_rgb(255,255,255));
    al_draw_rectangle(130,230,670,280,al_map_rgb(0,0,0),2);
    al_draw_text(MenuFont,al_map_rgb(0,0,0),400,240,ALLEGRO_ALIGN_CENTER,"Wybierz swojego bohatera:");

    for(int i = 0; i < ButtonCount; i++){
        if(i/3 < 1)
            show_button(buttons[i],130+200*i,100);
        else if(i/3 < 2)
            show_button(buttons[i],170+190*(i-3),300);
        else
            show_button(buttons[i],330+200*(i-6),450);
    }
    selected_item(actHero);
    selected_item(actDiff);
    al_flip_display();
}

void SettingsMenu::show_button(ALLEGRO_BITMAP* but, int pos_x, int pos_y){
    al_draw_scaled_bitmap(but,0,0,325,185,pos_x,pos_y,140,70,0);
}

void SettingsMenu::select_menu_item(int direction){
    display();
    actButton += direction;
    if(actButton > (ButtonCount-1))
        actButton = 0;
    else if(actButton < 0)
        actButton = ButtonCount - 1;
    if(actButton/3 <1)
        al_draw_rounded_rectangle(130+200*actButton,100,130+200*actButton+140,170,25,25,al_map_rgb(0,0,0),5);
    else if(actButton/3 < 2)
        al_draw_rounded_rectangle(140+190*(actButton-3),290,140+190*(actButton-3)+140,350,25,25,al_map_rgb(0,0,0),5);
    else
        al_draw_rounded_rectangle(330+200*(actButton-6),450,330+200*(actButton-6)+140,520,25,25,al_map_rgb(0,0,0),5);
    al_flip_display();
}

void SettingsMenu::selected_item(int _actButton){
    if(_actButton/3 <1)
        al_draw_filled_triangle(130+200*_actButton+25,200,130+200*_actButton+140-25,200,(130+200*_actButton)+70,180,al_map_rgb(0,0,0));
    else if(_actButton/3 < 2)
        al_draw_filled_triangle(140+190*(_actButton-3)+25,390,140+190*(_actButton-3)+140-25,390,(140+190*(_actButton-3))+70,360,al_map_rgb(0,0,0));
}

int SettingsMenu::type(){
    return typ;
}

int SettingsMenu::actual_selection(){
    return actButton;
}



