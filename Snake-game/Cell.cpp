#include "Cell.h"
Cell::Cell() : m_texture(), m_free(true), m_dir(' ') {};
Cell::Cell(SDL_Rect t_rect, SDL_Texture* t_texture, int t_row, int t_col) 
	: m_texture(t_rect, t_texture), m_free(true), m_dir(' '), m_row(t_row), m_col(t_col)
{};
Cell::~Cell() {};
char Cell::dir() { return this->m_dir; };
bool Cell::free() { return this->m_free; }
void Cell::changeDirection(char dir) {
	//	changing cell direction for moving player
	m_dir = dir;
}
void Cell::render(SDL_Renderer* t_renderer) {
	//	if texture not null - render
	if(m_texture.texture() != nullptr)
		SDL_RenderCopy(t_renderer, m_texture.texture(), nullptr, &m_texture.rect());
}

CustomTexture Cell::texture() { return this->m_texture; }

int Cell::row() { return this->m_row; }
int Cell::col() { return this->m_col; }

void Cell::changeFree(bool is_free) { this->m_free = is_free; }

