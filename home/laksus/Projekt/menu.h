class Menu{
    public:
    virtual void display() = 0;
    virtual void create() = 0;
    virtual void select_menu_item(int) = 0;
    virtual void show_button(ALLEGRO_BITMAP*, int, int) = 0;
    virtual int actual_selection() = 0;
};

class MainMenu: public Menu{
    public:
    const int ButtonCount = 3;
    int actButton;
    ALLEGRO_BITMAP *title, *background;
    ALLEGRO_BITMAP *buttons[3];

    MainMenu();
    ~MainMenu();

    void display();
    void create();
    void show_button(ALLEGRO_BITMAP*, int, int);
    void select_menu_item(int);
    int actual_selection();
    private:
    const int w = 800;
    const int h = 600;
};

class SettingsMenu: public Menu{
    public:
    const int ButtonCount = 3;
    int actButton;
    ALLEGRO_BITMAP *title, *background;
    ALLEGRO_BITMAP *buttons[3];

    SettingsMenu();
    ~SettingsMenu();

    void display();
    void create();
    void show_button(ALLEGRO_BITMAP*, int, int);
    void select_menu_item(int);
    int actual_selection();
    private:
    const int w = 800;
    const int h = 600;
};
