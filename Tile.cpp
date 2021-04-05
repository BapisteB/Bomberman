//
// Created by bapti on 05/04/2021.
//

#include "Tile.h"

#include <utility>

Tile::Tile() {
    texture = "0";
    breakable = true;
    transparent = true;
}

Tile::Tile(ifstream & is) {
    is >> breakable >> transparent >> texture;
}

Tile::Tile(bool br, bool tr, string te) {
    breakable = br;
    transparent = tr;
    texture = std::move(te);
}

void Tile::save(string &src) const {
    string tab = "  ";
    src += tab + "{\n";
    src += tab + tab + (breakable ? "1" : "0") + " ";
    src += (transparent ? "1" : "0");
    src += " " + texture + "\n";
    src += tab + "}\n";
}


