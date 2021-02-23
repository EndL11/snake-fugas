#pragma once
#include <SDL.h>
#include "CustomTexture.h"
class Cell {
private:
	CustomTexture m_texture;
	bool m_free;
	bool m_changeDir;
	char m_dir;
	int m_row;
	int m_col;
public:
	Cell();
	Cell(SDL_Rect t_rect, SDL_Texture* t_texture, int r, int c);
	~Cell();
	bool free();
	bool changeDir();
	char dir();
	void changeDirection(char dir);
	void render(SDL_Renderer* t_renderer);
	CustomTexture texture();
	int col();
	int row();
	void changeFree(bool is_free);
};