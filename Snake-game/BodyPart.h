#pragma once
#include "Cell.h"
#include <string>
class BodyPart {
private:
	Cell m_cell;
	std::string m_tag = "player";
	CustomTexture m_texture;
public:
	BodyPart();
	BodyPart(Cell t_cell, SDL_Rect t_rect, SDL_Texture* t_texture);
	~BodyPart();
	std::string tag();
	CustomTexture texture();
	void render(SDL_Renderer* t_renderer);
	Cell cell();
	void setCell(Cell newCell);
};