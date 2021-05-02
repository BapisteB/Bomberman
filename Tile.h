//
// Created by bapti on 05/04/2021.
//

#ifndef BOMBERMAN_TILE_H
#define BOMBERMAN_TILE_H

#include <string>
#include <fstream>
#include <iostream>
#include "Spritesheet.h"

using namespace std;

class Tile {
public:
	Spritesheet	 texture;

	enum class Type {
		FLOOR,
		EXPLOSION,
		WALL,
		BREAKABLE_WALL
	};

	explicit Tile();
	
	Tile(ifstream & is);

    Tile(bool br, char *path, int row, int col);

	void select_type();

	void update(double delta_time);

	void draw(SDL_Surface *window_surface, SDL_Rect *position);

    void save(string &src) const;

private:
	Type		 m_type;
	bool		 breakable;
	int 		 row;
	int			 col;
	char	 	*path;
};


#endif //BOMBERMAN_TILE_H
