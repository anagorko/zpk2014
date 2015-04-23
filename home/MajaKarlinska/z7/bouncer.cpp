#include <stdio.h>
#include <allegro5/allegro.h>

const float FPS = 60; //stala FPS - frames per second - ile kratek bedzie wyswietlanych na sekunde
const int SCREEN_W = 640; //szerokosc okienka
const int SCREEN_H = 480; //wysokosc okienka
const int BOUNCER_SIZE = 32; //szerokosc tego co sie porusza, wielkosc kwadratu, szerokosc boku 32 px

int main(int argc, char **argv){
   ALLEGRO_DISPLAY *display = NULL; //tutaj przechowywany adres okienka
   ALLEGRO_EVENT_QUEUE *event_queue = NULL; //kolejka zdarzen informuje o tym ze cos sie wydarzylo, zdarzeniem
   //moze byc np klikniecie gdzies, udarzenie w klawisz, ruszenie myszka itp
   ALLEGRO_TIMER *timer = NULL; //wlasne zrodlo zdarzen, sprawia ze nasz bouncer porusza sie pomimo braku
   //zewnetrznych wydarzen
   ALLEGRO_BITMAP *bouncer = NULL;
   float bouncer_x = SCREEN_W / 2.0 - BOUNCER_SIZE / 2.0; //polozenie gornego rogu kwadratu
   float bouncer_y = SCREEN_H / 2.0 - BOUNCER_SIZE / 2.0;
   float bouncer_dx = -4.0, bouncer_dy = 4.0; //predkosc z jaka porusza sie kwadrat, wektor z jakim bedzie sie poruszal
   bool redraw = true;

   if(!al_init()) {
      fprintf(stderr, "failed to initialize allegro!\n");
      return -1;
   }

   timer = al_create_timer(1.0 / FPS); //tworzymy budzik, ktory sprawia ze program zacznie dzialac 1/60, czyli 60
   //razy na sekunde
   if(!timer) {
      fprintf(stderr, "failed to create timer!\n");
      return -1;
   }

   display = al_create_display(SCREEN_W, SCREEN_H);
   if(!display) {
      fprintf(stderr, "failed to create display!\n");
      al_destroy_timer(timer);
      return -1;
   }

   bouncer = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE); //utworzenie bitmapy
   if(!bouncer) {
      fprintf(stderr, "failed to create bouncer bitmap!\n");
      al_destroy_display(display);
      al_destroy_timer(timer);
      return -1;
   }

   al_set_target_bitmap(bouncer); // zmienie bitmapy w bouncera

   al_clear_to_color(al_map_rgb(255, 0, 255)); //kolorujemy bitmape na rozowo - czyli naszego bouncera

   al_set_target_bitmap(al_get_backbuffer(display));

   event_queue = al_create_event_queue();

   if(!event_queue) { //event queue - wskaznik do kolejki zdarzen, sprawdzamy czy wszystko sie outworzylo poprawnie
      fprintf(stderr, "failed to create event_queue!\n");
      al_destroy_bitmap(bouncer);
      al_destroy_display(display);
      al_destroy_timer(timer);
      return -1;
   }

   al_register_event_source(event_queue, al_get_display_event_source(display));
   //rejestrujrmy zdarzenie al_get_display_event_source(display_ - klikniecie w czerwony przycisk

   al_register_event_source(event_queue, al_get_timer_event_source(timer));
 //rejestrujrmy zdarzenie al_get_timer_event_source(timer)) - budzik

   al_clear_to_color(al_map_rgb(0,0,0));

   al_flip_display();

   al_start_timer(timer);

   while(1)
   {
      ALLEGRO_EVENT ev;
      al_wait_for_event(event_queue, &ev); //czekaj na zdaezenie, aby pojawilo sie w kolejce zdarzen
      //&ev - oznacza ze przekazujemy zmienna, a nie jej wartosc

      if(ev.type == ALLEGRO_EVENT_TIMER) { //zdarzenie ktore oznacza ze minela 1/6o sek
         if(bouncer_x < 0 || bouncer_x > SCREEN_W - BOUNCER_SIZE) {
            bouncer_dx = -bouncer_dx; //zanim sie poruszamy sprawdzamy czy doszlismy do sciany i musimy sie odbic
            //sprawdzamy czy doszlismy do punktu 0 (lewej krawedzi) lub do (prawej krawedzi minus rozmiar bouncera),
            //czyli do prawej krawedzi
         }

         if(bouncer_y < 0 || bouncer_y > SCREEN_H - BOUNCER_SIZE) {
            bouncer_dy = -bouncer_dy;
         }

         bouncer_x += bouncer_dx; //przesuwamy x o wartosc wektora dx
         bouncer_y += bouncer_dy; //przesuwamy y o wartosc wektora dy

         redraw = true; //narysuj to jeszcze raz
      }
      else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) { //jesli ktos kliknie w czerwony klawisz na gorze
         break; //to wychodzimy z petli, wszystko jest konczone i wychodzimy z programu
      }

      if(redraw && al_is_event_queue_empty(event_queue)) {
            //jesli masz narysowac scene jeszcze raz i nie ma nic kolejnego w kolejce zdarzen, to wowczas nie rysuj,
            //tylko najpierw przelicz wszystkie wydarzenia
         redraw = false;

         al_clear_to_color(al_map_rgb(0,0,0)); //gdybysmy nie pokolorowali tla na czarno, wowczas za naszym bouncerem
         //zostawal by jego slad

         al_draw_bitmap(bouncer, bouncer_x, bouncer_y, 0);
         // i po przeliczeniu wwszystkich zdarzen ktore zostaly wykonane, rysujemy wszystko od nowa

         al_flip_display();
      }
   }

   al_destroy_bitmap(bouncer);
   al_destroy_timer(timer);
   al_destroy_display(display);
   al_destroy_event_queue(event_queue);

   return 0;
}
