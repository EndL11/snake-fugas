#include "Food.h"
Food::Food() {};
Food::Food(SDL_Rect t_rect, SDL_Texture* t_texture): m_texture(t_rect, t_texture) {};
Food::~Food() {};
std::string Food::tag() { return this->m_tag; }
CustomTexture Food::texture() { return this->m_texture; }
void Food::render(SDL_Renderer* t_renderer) {
	SDL_RenderCopy(t_renderer, m_texture.texture(), nullptr, &m_texture.rect());
}