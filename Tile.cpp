//
// Created by bapti on 05/04/2021.
//

#include "Tile.h"

Tile::Tile(){
	row = 0;
	col = 0;
	breakable = true;
	texture = Spritesheet("Spritesheet.bmp", 2, 2);
	m_type = Type::FLOOR;
	select_type();
}

Tile::Tile(ifstream & is) {
    is >> breakable >> row >> col >> path;
	texture = Spritesheet((const char*)path, row, col);
	m_type = Type::FLOOR;
	select_type();
}

Tile::Tile(bool br, char* p, int r, int c) {
	row = r;
	col = c;
	path = p;
    breakable = br;
    texture = Spritesheet(path, row, col);
	m_type = Type::FLOOR;
	select_type();
}

void Tile::select_type() {
	switch(m_type) {
		case Type::FLOOR:
			texture.select_sprite(0, 1);
			break;
		case Type::EXPLOSION:
			texture.select_sprite(0, 0);
			break;
		case Type::WALL:
			texture.select_sprite(1, 0);
			break;
		case Type::BREAKABLE_WALL:
			texture.select_sprite(1, 1);
			break;
		default:
			texture.select_sprite(0, 1);
			break;
	}
}

void Tile::update(double delta_time) {
	//TODO
	return;
}

void Tile::draw(SDL_Surface *window_surface, SDL_Rect *position) {
	std::cout << "Drawing Tile...\n";
	texture.draw_selected_sprite(window_surface, position);
}

void Tile::save(string &src) const {
    string tab = " ";
    src += tab + "{\n";
    src += tab + tab + (breakable ? "1" : "0") + " ";
    src += row + ' ' + col + ' ' + path + '\n';
    src += tab + "}\n";
}
