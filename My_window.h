//
// Created by bapti on 06/04/2021.
//

#ifndef BOMBERMAN_MY_WINDOW_H
#define BOMBERMAN_MY_WINDOW_H

#include <SDL2/SDL.h>
#include <iostream>
#include <memory>
#include "Map.h"

class My_window {
public:
	/**
	* @brief Creates a new window from scratch 
	*/
    My_window();

	/**
	* @brief Destroys the window object
	*/
    ~My_window();

	/**
	* @brief Main function to keep the game running 
	*/
    void loop();

	/**
	* @brief updates the game by updating the map 
	* and the player
	*
	* @param delta_time frames per seconds
	*/
    void update(double delta_time);

	/**
	* @brief redraws the game by redrawing the map 
	* and the player
	*/
    void draw();

private:
	Player		 m_player;
	Map			 m_map;

    SDL_Window  *m_window;
    SDL_Surface *m_window_surface;
    SDL_Event    m_window_event;
    
};


#endif //BOMBERMAN_MY_WINDOW_H
