all : main

main: Map.o Map.h Tile.h Player.h Power_up.h
	g++ -Wall -o main.o -c main.cpp

Map.o: Tile.o Map.cpp Map.h
	g++ -Wall -o Map.o -c Map.cpp

Player.o: Power_up.o Player.cpp Player.h
	g++ -Wall -o Player.o -c Player.cpp

Power_up.o: Power_up.cpp Power_up.h
	g++ -Wall -o Power_up.o -c Power_up.cpp

Tile.o: Tile.cpp Tile.h
	g++ -Wall -o Tile.o -c Tile.cpp

clean:
	rm -rf *.o