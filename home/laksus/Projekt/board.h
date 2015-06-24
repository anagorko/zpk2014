#ifndef __BOARD_H__
#define __BOARD_H__

struct lvl{
    ALLEGRO_BITMAP *background;
    int ObstacleLevel;
    double multiplier;
};


class Board{
    private:
    ALLEGRO_BITMAP *obstacle_up, *obstacle_down, *endgame, *lvl_win, *helper, *counter[4];
    ALLEGRO_FONT *MenuFont;
    const int w=800, h=600;

    public:
    ALLEGRO_BITMAP *hero;
    lvl level[5];

    void init(int bird_type);
    void welcome();
    void refresh_hero(double, double, double);
    void refresh_pipe(double, double);
    void refresh_background(int);
    void refresh_counter(int, int, int);
    void counting(int);
    void win_lvl();
    void show();
    void end_game();

};

#endif
