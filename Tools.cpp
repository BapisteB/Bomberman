#include "Tools.h"

SDL_Surface *load_bmp(const char *path) {
	SDL_Surface *image_surface = SDL_LoadBMP(path);
	if(image_surface)
		return image_surface;
	
	return 0;
}
