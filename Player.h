//
// Created by bapti on 06/04/2021.
//

#ifndef BOMBERMAN_PLAYER_H
#define BOMBERMAN_PLAYER_H

#include "Tools.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <memory>

class Player {
public:
	/**
	* An enum to choose the direction of the player
	*/
	enum class Direction 
	{
		NONE,
		UP,
		DOWN,
		LEFT,
		RIGHT
	};
	/**
  	* @brief Creates a new Player from scratch
    */
    Player();
	~Player() = default;

	/**
	* @brief Handle the different events for a 
	* player, meaning moving and/or placing
	* bombs.
	*
	* @param event a SDL_event that the method 
	* will handle
	*/
	void handle_events(cinst SDL_Event &event);

	/**
	* @brief Updates the player position
	*
	* @param delta_time time for the frames per 
	* seconds
	*/
	void update(double delta_time);

	/**
	* @brief Draws the player on the SDL_Surface
 	*
   	* @param window_surface the SDL_Surface
	*/
	void draw(SDL_Surface *window_surface);
private:
	Direction 	 m_direction;

	SDL_Surface *m_image;
	SDL_Rect	 m_position;
	double 		 m_x;
	double 		 m_y;
};


#endif //BOMBERMAN_PLAYER_H
