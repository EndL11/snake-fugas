#include "Snake.h"
#include <iostream>
Snake::Snake() {}
Snake::Snake(Cell t_cell, SDL_Rect t_rect, SDL_Texture* t_texture) {
	BodyPart head(t_cell, t_rect, t_texture);
	body.push_back(head);
}
Snake::~Snake() {}
void Snake::render(SDL_Renderer* t_renderer) {
	for (auto part : body)
		part.render(t_renderer);
}
bool Snake::move(Field field) {
	for (auto &part : body) {
		Cell nextCell = field.nextCellByDirection(part.cell(), direction);
		if (nextCell.texture().texture() == nullptr) {
			std::cout << "Game Over" << std::endl;
			return false;
		}
		part.cell().changeFree(true);
		part.setCell(nextCell);
		nextCell.changeFree(false);
		return true;
	}
}

void Snake::changeDir(char new_dir) {
	direction = new_dir;
}
