//
// Created by bapti on 05/04/2021.
//

#include "Map.h"

Map::Map(size_t s) {
	std::cout << "Creating map...\n";
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

void Map::changeTile(int x, int y, Tile tile) {
    board[x][y] = tile;
}

void Map::update(double delta_time) {
	return;
}

void Map::draw(SDL_Surface *window_surface) {
	SDL_Rect m_rect;
	m_rect.x = 0.0;
	m_rect.y = 0.0;
	m_rect.w = board[0][0].texture.clip.w;
	m_rect.h = board[0][0].texture.clip.h;

	for (size_t i = 0; i < board.size(); i++) {
		for (size_t j = 0; j < board[i].size(); j++) {
			m_rect.x += m_rect.w;
			board[i][j].draw(window_surface, NULL);
		}
		m_rect.y += m_rect.h;
		m_rect.x = 0.0;
	}
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
