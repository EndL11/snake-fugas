#include "BodyPart.h"
BodyPart::BodyPart() {}
BodyPart::BodyPart(Cell t_cell, SDL_Rect t_rect, SDL_Texture* t_texture): m_cell(t_cell), m_texture(t_rect, t_texture) {}
BodyPart::~BodyPart() {}
CustomTexture BodyPart::texture() { return this->m_texture; }
void BodyPart::render(SDL_Renderer* t_renderer) {
	//	if texture not null - render
	if(m_texture.texture() != nullptr)
		SDL_RenderCopy(t_renderer, m_texture.texture(), nullptr, &m_cell.texture().rect());
}
Cell& BodyPart::cell() { return this->m_cell; }
void BodyPart::setCell(Cell newCell) { 
	//	set cell and change rect position
	this->m_cell = newCell; 
	this->m_texture.setRect(newCell.texture().rect());
}