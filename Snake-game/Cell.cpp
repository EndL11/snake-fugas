#include "Cell.h"
Cell::Cell() : m_texture(), m_free(true), m_changeDir(false), m_dir(' ') {};
Cell::Cell(SDL_Rect t_rect, SDL_Texture* t_texture) : m_texture(t_rect, t_texture), m_free(true), m_changeDir(false), m_dir(' ') {};
Cell::~Cell() {};
char Cell::dir() { return this->m_dir; };
bool Cell::free() { return this->m_free; }
bool Cell::changeDir() { return this->m_changeDir; }
void Cell::changeDirection(char dir) {
	if (dir == ' ')
		m_changeDir = false;
	m_dir = dir;
}
void Cell::render(SDL_Renderer* t_renderer) {
	SDL_RenderCopy(t_renderer, m_texture.texture(), nullptr, &m_texture.rect());
}

CustomTexture Cell::texture() { return this->m_texture; }