#pragma once
#include <iostream>
#include "Field.h"
#include "CustomTexture.h"
class Food {
private:
	std::string m_tag = "food";
	int points = 20;
	CustomTexture m_texture;
public:
	Food();
	Food(SDL_Rect t_rect, SDL_Texture* t_texture);
	~Food();
	std::string tag();
	CustomTexture texture();
	void replaceFood(Field t_field);
	void render(SDL_Renderer* t_renderer);
	Food generateFood(SDL_Texture* t_texture, Field t_field);
};