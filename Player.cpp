//
// Created by bapti on 06/04/2021.
//

#include "Player.h"

Player::Player() {
	m_image = SDL_LoadBMP("image.bmp");

	m_position.x = 0;
	m_position.y = 0;
	m_position.w = 22;
	m_position.h = 43;

	m_x = 0.0;
	m_y = 0.0;

	m_direction = Direction::NONE;
}

void Player::handle_events(const SDL_Event &event) {
	switch(event.type) {
		case SDL_KEYDOWN:
		Uint8 const *keys = SDL_GetKeyboardState(nullptr);
	
		if(keys[SDL_SCANCODE_Z] == 1)
			m_direction = Direction::UP;
		else if (keys[SDL_SCANCODE_S] == 1)
			m_direction = Direction::DOWN;
		else if (keys[SDL_SCANCODE_Q] == 1)
			m_direction = Direction::LEFT;
		else if (keys[SDL_SCANCODE_D] == 1)
			m_direction = Direction::RIGHT;
		break;
	}
}

void Player::update(double delta_time) { 
	switch(m_direction) {
		case Direction::NONE:
			m_x += 0.0;
			m_y += 0.0;
			std::cout << "Direction: NONE\n";
			break;
		case Direction::UP:
			m_y = m_y - (5.0 * delta_time);
			std::cout << "Direction: UP\n";
			break;
		case Direction::DOWN:
			m_y = m_y + (5.0 * delta_time);
			std::cout << "Direction: DOWN\n";
			break;
		case Direction::LEFT:
			m_x = m_x - (5.0 * delta_time);
			std::cout << "Direction: LEFT\n";
			break;
		case Direction::RIGHT:
			m_x = m_x + (5.0 * delta_time);
			std::cout << "Direction: RIGHT\n";
			break;
	}

	m_position.x = m_x;
	m_position.y = m_y;
}

void Player::draw(SDL_Surface *window_surface) {
	SDL_BlitSurface(m_image, NULL, window_surface, &m_position);
}


