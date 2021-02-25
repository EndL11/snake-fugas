#pragma once
#include <SDL.h>
#include "CustomTexture.hpp"
class Cell {
private:
	CustomTexture m_texture;
	bool m_free;
	char m_dir = ' ';
	int m_row;
	int m_col;
public:
	Cell();
	Cell(SDL_Rect t_rect, SDL_Texture* t_texture, int r, int c);
	~Cell();
	bool free();
	char dir();
	void changeDirection(char dir);
	void render(SDL_Renderer* t_renderer);
	CustomTexture texture();
	int col();
	int row();
	void changeFree(bool is_free);
	friend bool operator==(Cell lcell, Cell rcell) { return lcell.m_row == rcell.m_row && lcell.m_col == rcell.m_col; }
	friend bool operator!=(Cell lcell, Cell rcell) { return lcell.m_row != rcell.m_row && lcell.m_col != rcell.m_col; }
};