#pragma once
#include <iostream>
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
	void render(SDL_Renderer* t_renderer);
};