#pragma once
#include "BodyPart.hpp"
#include "Field.hpp"
#include <list>
#include <string>
class Snake {
private:
	std::list<BodyPart> body;
	char direction = ' ';
public:
	Snake();
	Snake(Cell t_cell, SDL_Rect t_rect, SDL_Texture* t_texture);
	~Snake();
	void render(SDL_Renderer* t_renderer);
	bool move(Field& field);
	void changeDir(char new_dir);
	Cell& nextHeadCell(Field& field);
	char getDirection();
	void createPart(Field& t_field);
};