all: tetris
	# Done
tetris: gra.o klocek.o new_main.o plansza.o plansza.h
	g++ --std=c++11 -o tetris gra.o klocek.o new_main.o plansza.o -I/usr/local/include/ -L/usr/local/lib -lallegro -lallegro_main -lallegro_image 
new_main.o: new_main.cpp
	g++ --std=c++11 -c new_main.cpp -g
klocek.o: klocek.cpp
	g++ --std=c++11 -c klocek.cpp -g
plansza.o: plansza.cpp
	g++ --std=c++11 -c plansza.cpp -g
gra.o: gra.cpp
	g++ --std=c++11 -c gra.cpp -g
