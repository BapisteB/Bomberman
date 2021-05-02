//
// Created by bapti on 05/04/2021.
//

#ifndef BOMBERMAN_MAP_H
#define BOMBERMAN_MAP_H

#include "Tile.h"
#include "Player.h"
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class Map {
public:
	Map() = default;

	Map(size_t s);

    Map(const char *src);

    void changeTile(int x, int y, Tile tile);

	void update(double delta_time);

	void draw(SDL_Surface *window_surface);

    void saveMap(const char *src);

private:
	std::vector<std::vector<Tile>> board;

	Player		 m_player;
	int			 player_x;
	int			 player_y;
	std::size_t  size;

};


#endif //BOMBERMAN_MAP_H
