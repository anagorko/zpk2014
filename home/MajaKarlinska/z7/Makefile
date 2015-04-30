all: bouncer load keyboard mouse fullscreen font primitives
	# Done
bouncer: bouncer.cpp
	g++ bouncer.cpp -o bouncer -I/usr/local/include/ -L/usr/local/lib -lallegro -lallegro_main
load: load.cpp
	g++ load.cpp -o load -I/usr/local/include/ -L/usr/local/lib -lallegro -lallegro_main -lallegro_image -lallegro_dialog
keyboard: keyboard.cpp
	g++ keyboard.cpp -o keyboard -I/usr/local/include/ -L/usr/local/lib -lallegro -lallegro_main -lallegro_image -lallegro_dialog
mouse: mouse.cpp
	g++ mouse.cpp -o mouse -I/usr/local/include/ -L/usr/local/lib -lallegro -lallegro_main -lallegro_image -lallegro_dialog
fullscreen: fullscreen.cpp
	g++ fullscreen.cpp -o fullscreen -I/usr/local/include/ -L/usr/local/lib -lallegro -lallegro_main -lallegro_image -lallegro_dialog -lallegro_primitives
font: font.cpp
	g++ font.cpp -o font -I/usr/local/include/ -L/usr/local/lib -lallegro -lallegro_main -lallegro_image -lallegro_dialog -lallegro_primitives -lallegro_font -lallegro_ttf
primitives: primitives.cpp
	g++ primitives.cpp -o primitives -I/usr/local/include/ -L/usr/local/lib -lallegro -lallegro_main -lallegro_primitives -lallegro_font -lallegro_ttf
