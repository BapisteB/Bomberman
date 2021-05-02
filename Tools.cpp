#include "Tools.h"

SDL_Surface *load_bmp(const char *path) {
	SDL_Surface *image_surface = SDL_LoadBMP(path);

	return image_surface ? image_surface : 0;
}
