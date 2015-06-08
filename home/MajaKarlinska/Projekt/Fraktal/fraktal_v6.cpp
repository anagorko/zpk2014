#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>

const int screen_w = 800;
const int screen_h = 600;
const float FPS = 60.0;

int main(int, char**)
{
    if (!al_init() || !al_install_keyboard() || !al_init_image_addon()) {
        cout << "B³¹d inicjalizacji." << endl;
        return 1;
    }

    ALLEGRO_DISPLAY *display = al_create_display(screen_w, screen_h);

    if (display == NULL) {
        cout << "B³¹d inicjalizacji." << endl;
        return 2;
}
}
