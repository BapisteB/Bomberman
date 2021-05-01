//
// Created by bapti on 06/04/2021.
//

#ifndef BOMBERMAN_PLAYER_H
#define BOMBERMAN_PLAYER_H

#include <SDL2/SDL.h>
#include <iostream>
#include <memory>

class Player {
public:
	enum class Direction 
	{
		NONE,
		UP,
		DOWN,
		LEFT,
		RIGHT
	};

    Player();
	~Player() = default;

	void handle_events(const SDL_Event &event);
	
	void update(double delta_time);

	void draw(SDL_Surface *window_surface);
private:
	Direction 	 m_direction;

	SDL_Surface *m_image;
	SDL_Rect	 m_position;
	double 		 m_x;
	double 		 m_y;
};


#endif //BOMBERMAN_PLAYER_H
