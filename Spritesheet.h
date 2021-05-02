#include <SDL2/SDL.h>
#include "Tools.h"

class Spritesheet {
public:
	SDL_Rect	 clip;

	Spritesheet();

	Spritesheet(const char *path, int row, int col);

	~Spritesheet();

	void select_sprite(int x, int y);

	void draw_selected_sprite(SDL_Surface *window_surface, SDL_Rect *position);

private:
	SDL_Surface	*spritesheet_image;

	int 		 start_y;
	int 		 start_x;
};
