#pragma once
#include <SDL.h>
class CustomTexture {
private:
	SDL_Rect m_rect;
	SDL_Texture* m_texture;
public:
	CustomTexture();
	CustomTexture(SDL_Rect t_rect, SDL_Texture* t_texture);
	~CustomTexture();
	SDL_Rect rect();
	SDL_Texture* texture();
};