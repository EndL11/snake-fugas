#include "CustomTexture.hpp"

CustomTexture::CustomTexture(SDL_Rect t_rect, SDL_Texture* t_texture): m_rect{ t_rect }, m_texture(t_texture){};
CustomTexture::CustomTexture()
	: m_rect{ 0, 0, 50, 50 }, m_texture(nullptr)
{}
CustomTexture::~CustomTexture() {}

SDL_Rect CustomTexture::rect() {
	return this->m_rect;
}

SDL_Texture* CustomTexture::texture() {
	return this->m_texture;
}

void CustomTexture::setRect(SDL_Rect t_rect) {
	m_rect = { t_rect };
}