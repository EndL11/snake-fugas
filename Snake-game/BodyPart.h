#pragma once
#include "Cell.h"
#include <string>
class BodyPart {
private:
	Cell m_cell;
	std::string m_tag = "player";
	SDL_Texture* texture;
public:
	BodyPart();
	BodyPart(Cell t_cell);
	~BodyPart();
	std::string tag();
};