#pragma once
#include <SDL.h>
#include "CustomTexture.h"
class Cell {
private:
	CustomTexture texture;
	bool m_free;
	bool m_changeDir;
	char m_dir;
public:
	Cell();
	Cell(SDL_Rect& t_rect, SDL_Texture* t_texture);
	~Cell();
	bool free();
	bool changeDir();
	char dir();
	void changeDirection(char dir);
};