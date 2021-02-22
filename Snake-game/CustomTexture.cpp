#include "CustomTexture.h"

CustomTexture::CustomTexture(SDL_Rect& t_rect, SDL_Texture* t_texture): rect{ t_rect }, texture(t_texture){};
CustomTexture::CustomTexture()
	: rect{ 0, 0, 50, 50 }, texture(nullptr)
{}
CustomTexture::~CustomTexture() {
	SDL_DestroyTexture(this->texture);
}