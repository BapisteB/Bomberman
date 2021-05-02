//
// Created by bapti on 05/04/2021.
//

#include "Tile.h"

Tile::Tile(){
	row = 2;
	col = 2;
	breakable = true;
	texture = Spritesheet("Spritesheet.bmp", row, col);
	m_type = Type::FLOOR;
	select_texture_from_type();
}

Tile::Tile(ifstream & is) {
    is >> breakable >> row >> col >> path;
	texture = Spritesheet((const char*)path, row, col);
	m_type = Type::FLOOR;
	select_texture_from_type();
}

void Tile::select_texture_from_type() {
	switch(m_type) {
		case Type::FLOOR:
			texture.select_sprite(1, 0);
			break;
		case Type::EXPLOSION:
			texture.select_sprite(0, 0);
			break;
		case Type::WALL:
			texture.select_sprite(0, 1);
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
	texture.draw_selected_sprite(window_surface, position);
}

void Tile::save(string &src) const {
    string tab = " ";
    src += tab + "{\n";
    src += tab + tab + (breakable ? "1" : "0") + " ";
    src += row + ' ' + col + ' ' + path + '\n';
    src += tab + "}\n";
}
