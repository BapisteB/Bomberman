//
// Created by bapti on 06/04/2021.
//

#ifndef BOMBERMAN_PLAYER_H
#define BOMBERMAN_PLAYER_H

#include "Power_up.h"
#include <string>
#include <vector>

class Player {
public:
    std::string skin;
    std::vector<Power_up> pow_up;
    int bomb_nb;

    explicit Player();
};


#endif //BOMBERMAN_PLAYER_H
