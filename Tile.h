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

	/**
	* An enum to choose different Tile types => might
	* be changed into Map.h/cpp for changing the Type 
	* easily.
	*/
	enum class Type {
		FLOOR,
		EXPLOSION,
		WALL,
		BREAKABLE_WALL
	};

	Tile();
	
	Tile(ifstream & is);

	
	/**
	* Select the texture of the Spritesheet depending
	* on the selected type.
	*/
	void select_texture_from_type();

	/**
	* Not fully implemented and might not be used or
	* maybe made virtual to implement the explosive 
	* tiles.
	*
	* @param delta_time
	*/
	void update(double delta_time);

	/**
	* Draws a tile
	*
	* @param window_surface the window we are drawing on
	* @param position the position where we draw
	*/
	void draw(SDL_Surface *window_surface, SDL_Rect *position);

	/**
	* Saves a tile 
	*
	* @param src the string that will be written
	*/
    void save(string &src) const;

private:
	Type		 m_type;
	bool		 breakable;
	int 		 row;
	int			 col;
	char	 	*path;
};


#endif //BOMBERMAN_TILE_H
