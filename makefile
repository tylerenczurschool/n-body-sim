testmake: main.c graphics.c
	gcc -o main main.c graphics.c physics.c import.c `sdl2-config --cflags --libs` -lm -I. -O2
