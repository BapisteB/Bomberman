//
// Created by bapti on 06/04/2021.
//

#ifndef BOMBERMAN_MY_WINDOW_H
#define BOMBERMAN_MY_WINDOW_H

#include <SDL2/SDL.h>
#include <iostream>
#include <memory>
#include "Player.h"

class My_window {
public:
    My_window();

    ~My_window();

    void loop();

    void update(double delta_time);

    void draw();

private:
	Player		m_player;
    
    SDL_Window  *m_window;
    SDL_Surface *m_window_surface;
    SDL_Event    m_window_event;
    
};


#endif //BOMBERMAN_MY_WINDOW_H
