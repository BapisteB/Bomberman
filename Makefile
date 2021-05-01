all : main

main: Map.o Map.h Tile.h Player.h Power_up.h
	g++ -Wall -o Bomberman -c main.cpp

SDL_prgm: My_window.o
	g++ -o SDL_prgm main.cpp `sdl2-config --cflags --libs` 

My_window.o: Player.o
	g++ -c -o My_window.o My_window.cpp `sdl2-config --cflags --libs`

Player.o:
	g++ -c -o Player.o Player.cpp `sdl2-config --cflags --libs`

Map.o: Tile.o Map.cpp Map.h
	g++ -Wall -o Map.o -c Map.cpp

Power_up.o: Power_up.cpp Power_up.h
	g++ -Wall -o Power_up.o -c Power_up.cpp

Tile.o: Tile.cpp Tile.h
	g++ -Wall -o Tile.o -c Tile.cpp

clean:
	rm -rf *.o
