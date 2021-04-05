//
// Created by bapti on 05/04/2021.
//

#ifndef BOMBERMAN_MAP_H
#define BOMBERMAN_MAP_H

#include "Tile.h"
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class Map {
    std::vector<std::vector<Tile>> board;
    std::size_t size;
public:
    explicit Map(size_t s);

    explicit Map(const char *src);

    void display();

    void changeTile(int x, int y, Tile tile);

    void saveMap(const char *src);

};


#endif //BOMBERMAN_MAP_H
