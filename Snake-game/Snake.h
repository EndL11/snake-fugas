#pragma once
#include <SDL.h>
#include <list>
#include <string>
class Snake {
private:
	int parts = 2;
	std::list<SDL_Point> body;
	char direction = 'r';
	std::string m_tag;
public:
	Snake();
	~Snake();
	std::string tag();
};