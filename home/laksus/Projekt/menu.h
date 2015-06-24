#ifndef __MENU_H__
#define __MENU_H__


class Menu{
    public:
    virtual void display() = 0;
    virtual void select_menu_item(int) = 0;
    virtual void show_button(ALLEGRO_BITMAP*, int, int) = 0;
    virtual int type() = 0;
    virtual int actual_selection() = 0;
};

class MainMenu: public Menu{ //kazde menu jest dla mnie oddzielna klasa, ktora dziedziczy po interfejsie Menu. Zrobilem to w ten sposob poniewaz latwiej jest przechodzic pomiedzy nimi
    private:                  //i dodatkowo jest wiêksza swoboda w ich modyfikacji
    const int ButtonCount = 5;
    const int w = 800;
    const int h = 600;
    int actButton, typ=0;
    ALLEGRO_BITMAP *title, *background;
    ALLEGRO_BITMAP *buttons[5];

    void display();
    void show_button(ALLEGRO_BITMAP*, int, int);

    public:

    MainMenu();
    ~MainMenu();

    void select_menu_item(int);
    int type();
    int actual_selection();
};

class SettingsMenu: public Menu{
    private:
    const int w = 800;
    const int h = 600;
    const int ButtonCount = 7;

    ALLEGRO_BITMAP *background;
    ALLEGRO_BITMAP *buttons[7];
    ALLEGRO_FONT *MenuFont;

    void display();
    void show_button(ALLEGRO_BITMAP*, int, int);

    public:

    int actButton, typ=1, actHero, actDiff;

    SettingsMenu();
    ~SettingsMenu();

    void select_menu_item(int);
    void selected_item(int);
    int type();
    int actual_selection();

};


#endif
