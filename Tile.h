//
// Created by bapti on 05/04/2021.
//

#ifndef BOMBERMAN_TILE_H
#define BOMBERMAN_TILE_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Tile {
public:
    string texture;
    bool breakable;
    bool transparent;

    explicit Tile();

    explicit Tile(ifstream & is);

    Tile(bool br, bool tr, string te);

    void save(string &src) const;
};


#endif //BOMBERMAN_TILE_H
