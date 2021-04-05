//
// Created by bapti on 05/04/2021.
//

#include "Map.h"

Map::Map(size_t s) {
    size = s;
    board.resize(size);
    for (std::vector<Tile> &p : board)
        p.resize(size);
}

Map::Map(const char *src) {
    ifstream is(src);
    is >> size;
    std::string line;
    board.resize(size);
    for (std::vector<Tile> &p : board) {
        p.resize(size);
        is >> line;
        for (size_t i = 0; i < size; i++) {
            is >> line;
            p[i] = Tile(is);
            is >> line;
        }
        is >> line;
    }
}

void Map::display() {
    for (std::vector<Tile> p : board) {
        for (Tile tile : p)
            cout << tile.texture << " ";
        cout << endl;
    }
}

void Map::changeTile(int x, int y, Tile tile) {
    board[x][y] = tile;
}

void Map::saveMap(const char *src) {
    string tmp = "";
    tmp += to_string(board.size()) + "\n";
    for (vector<Tile> p : board) {
        tmp += "{\n";
        for (Tile tile : p) {
            tile.save(tmp);
        }
        tmp += "}\n";
    }
    ofstream os(src, ios::out);
    os << tmp;
}
