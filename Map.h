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

	/**
	* @brief Creates new map object from a size (only for tests)
	*
	* @param s the size of the map
	*/
	Map(size_t s);

	/**
	* @brief Creates new map object from a savefile
	*
	* @param src the path to the save file
	*/
    Map(const char *src);

	/**
	* @brief Changes a tile to another, mostly for an after 
	* explosion
	*
	* @param x, y coordinates of the tile to change
	* @param tile new tile 
	*/
    void changeTile(int x, int y, Tile tile);

	/**
	* @brief Updates the game by calling other update methods 
	* for other objects
	*
	* @param delta_time used to change the frame per seconds
	* of the game
	*/
	void update(double delta_time);

	/**
	* @brief Redraws the game by calling draw method for 
	* other objects
	*
	* @param window_surface The surface that we will redraw on
	*/
	void draw(SDL_Surface *window_surface);

	/**
	* @brief Saves the map object to a savefile
	*
	* @param src the path to the savefile
	*/
    void saveMap(const char *src);

private:
	std::vector<std::vector<Tile>> board;

	Player		 m_player;
	int			 player_x;
	int			 player_y;
	std::size_t  size;

};


#endif //BOMBERMAN_MAP_H
