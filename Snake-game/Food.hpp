#pragma once
#include <iostream>
#include "Field.hpp"
#include "CustomTexture.hpp"
class Food {
private:
	CustomTexture m_texture;
	Cell m_cell;
public:
	Food();
	Food(SDL_Rect t_rect, SDL_Texture* t_texture, Cell t_cell);
	~Food();
	CustomTexture texture();
	void replaceFood(Field t_field);
	void render(SDL_Renderer* t_renderer);
	Food generateFood(SDL_Texture* t_texture, Field t_field);
	Cell cell();
};