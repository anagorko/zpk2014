#ifndef __BOARD_H__
#define __BOARD_H__

struct lvl{
    ALLEGRO_BITMAP *background;
    int ObstacleLevel;
    double multiplier;
};


class Board{
    ALLEGRO_BITMAP *hero, *obstacle_up, *obstacle_down, *endgame, *lvl_win, *helper;
    ALLEGRO_FONT *MenuFont;

public:
    void init(int bird_type);
    void welcome();
    void refresh_hero(double, double, double);
    void refresh_pipe(double, double);
    void refresh_background(int);
    void refresh_counter(int, int, int);
    void pause();
    void win_lvl();
    void show();
    void end_game();
    const int w=800, h=600;
    lvl level[5];
};

#endif
