#include "Cell.h"
Cell::Cell() : texture(), m_free(true), m_changeDir(false), m_dir(' ') {};
Cell::Cell(SDL_Rect t_rect, SDL_Texture* t_texture) : texture(t_rect, t_texture), m_free(true), m_changeDir(false), m_dir(' ') {};
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
	SDL_RenderCopy(t_renderer, texture.texture(), nullptr, &texture.rect());
}