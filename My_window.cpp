//
// Created by bapti on 06/04/2021.
//

#include "My_window.h"

My_window::My_window() {

	m_window = SDL_CreateWindow("SDL2_window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 680, 480, 0);

	if (!m_window) {
		std::cout << "Failed to created window\n";
		std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
		return;
	}

	m_window_surface = SDL_GetWindowSurface(m_window);

	if (!m_window_surface) {
		std::cout << "Failed to created window\n";
		std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
		return;
	}
	m_map = Map(8);
}

My_window::~My_window() {
	SDL_FreeSurface(m_window_surface);
	SDL_DestroyWindow(m_window);
}

void My_window::loop() {
	bool keep_window_open = true;
	while (keep_window_open) {

		while (SDL_PollEvent(&m_window_event) > 0) {

			m_player.handle_events(m_window_event);
			switch(m_window_event.type) {

				case SDL_QUIT:
					keep_window_open = false;
					break;
			}

		}

		update(1.0/60.0);
		draw();
	}

}

void My_window::update(double delta_time) {
	m_player.update(delta_time);
	m_map.update(delta_time);
}

void My_window::draw() {
	SDL_FillRect(m_window_surface, NULL, SDL_MapRGB(m_window_surface->format, 0, 0, 0));

	m_map.draw(m_window_surface);
	m_player.draw(m_window_surface);

	SDL_UpdateWindowSurface(m_window);

}
