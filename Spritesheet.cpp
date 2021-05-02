#include "Spritesheet.h"

Spritesheet::Spritesheet(){
	spritesheet_image = nullptr;
}

Spritesheet::Spritesheet(const char *path, int row, int col) {
	spritesheet_image = load_bmp(path);

	clip.w = spritesheet_image->w / col;
	clip.h = spritesheet_image->h / row;
}

void Spritesheet::select_sprite(int x, int y) {
	clip.x = x * clip.w;
	clip.y = y * clip.h;
}

void Spritesheet::draw_selected_sprite(SDL_Surface *window_surface, SDL_Rect *position) {
	SDL_BlitSurface(spritesheet_image, &clip, window_surface, position);
}
