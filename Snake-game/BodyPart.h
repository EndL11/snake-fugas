#pragma once
#include "Cell.h"
#include <string>
class BodyPart {
private:
	Cell m_cell;
	CustomTexture m_texture;
public:
	BodyPart();
	BodyPart(Cell t_cell, SDL_Rect t_rect, SDL_Texture* t_texture);
	~BodyPart();
	CustomTexture texture();
	void render(SDL_Renderer* t_renderer);
	Cell& cell();
	void setCell(Cell newCell);
	friend bool operator==(BodyPart& lcell, BodyPart& rcell) { return lcell.m_cell == rcell.m_cell; }
	friend bool operator==(BodyPart lcell, BodyPart rcell) { return lcell.m_cell == rcell.m_cell; }
	friend bool operator!=(BodyPart& lcell, BodyPart& rcell) { return lcell.m_cell != rcell.m_cell; }
	friend bool operator!=(BodyPart lcell, BodyPart rcell) { return lcell.m_cell != rcell.m_cell; }
};