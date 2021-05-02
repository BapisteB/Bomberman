CC = g++
CFLAGS = -c -pedantic -Wall 
SDLFAGS = `sdl2-config --cflags --libs`

all : main

main: My_window.o
	$(CC) -pedantic -Wall -o Bomberman.exe My_window.cpp Player.cpp main.cpp Map.cpp Tile.cpp Spritesheet.cpp Tools.cpp `sdl2-config --cflags --libs`
#	rm -rf *.o

My_window.o: Map.o
	$(CC) $(CFLAGS) My_window.cpp Player.cpp Map.cpp Tile.cpp Spritesheet.cpp Tools.cpp `sdl2-config --cflags --libs`

Player.o: Tools.o
	$(CC) $(CFLAGS) Player.cpp Tools.cpp `sdl2-config --cflags --libs` 

Map.o: Tile.o Player.o
	$(CC) $(CFLAGS) Map.cpp Tile.cpp Spritesheet.cpp Tools.cpp Player.cpp `sdl2-config --cflags --libs`

Tile.o: Spritesheet.o
	$(CC) $(CFLAGS) Tile.cpp Spritesheet.cpp Tools.cpp `sdl2-config --cflags --libs`

Spritesheet.o: Tools.o
	$(CC) $(CFLAGS) Spritesheet.cpp Tools.cpp `sdl2-config --cflags --libs`

Tools.o:
	$(CC) $(CFLAGS) Tools.cpp `sdl2-config --cflags --libs`

clean:
	rm -rf *.o
