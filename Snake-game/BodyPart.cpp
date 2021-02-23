#include "BodyPart.h"
BodyPart::BodyPart() {}
BodyPart::BodyPart(Cell t_cell, SDL_Rect t_rect, SDL_Texture* t_texture): m_cell(t_cell), m_texture(t_rect, t_texture) {}
BodyPart::~BodyPart() {}
std::string BodyPart::tag() { return this->m_tag; }
CustomTexture BodyPart::texture() { return this->m_texture; }
void BodyPart::render(SDL_Renderer* t_renderer) {
	SDL_RenderCopy(t_renderer, m_texture.texture(), nullptr, &m_texture.rect());
}
Cell BodyPart::cell() { return this->m_cell; }
void BodyPart::setCell(Cell newCell) { 
	this->m_cell = newCell; 
	this->m_texture.setRect(newCell.texture().rect());
}