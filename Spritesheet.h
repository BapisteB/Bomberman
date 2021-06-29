#include <SDL2/SDL.h>
#include "Tools.h"

class Spritesheet {
public:
	SDL_Rect clip;

	/**
	* @brief Creates a new spritesheet object
	*/
	Spritesheet();

	/**
	* @brief Creates a new spritesheet object from variables
	*
	* @param path path to the spritesheet file
	* @param row number of rows in the spritesheet
	* @param col number of columns in the spritesheet
	*/
	Spritesheet(const char *path, int row, int col);

	~Spritesheet() = default;

	/**
	* @brief Select a sprite from the spritesheet 
	* and saves it in a SDL_Surface
	*
	* @param x, y position of the sprite in the spritesheet
	*/
	void select_sprite(int x, int y);

	/**
	* @brief draws the selected sprite on a windows
	*
	* @param window_surface the window we draw on
	* @param position the position of the sprite on
	* the window surface
	*/
	void draw_selected_sprite(SDL_Surface *window_surface, SDL_Rect *position);

private:
	SDL_Surface	*spritesheet_image;
};
