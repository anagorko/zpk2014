class Board{
    ALLEGRO_BITMAP *hero, *background, *obstacle_up, *obstacle_down, *endgame, *lvl_win;
    ALLEGRO_FONT *MenuFont;

public:
    void init(int bird_type);
    void refresh_hero(double, double, double);
    void refresh_pipe(double, double);
    void refresh_background();
    void refresh_counter(int, int);
    void win_lvl();
    void show();
    void end_game();
    const int w=800, h=600;
};

