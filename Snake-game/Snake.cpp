#include "Snake.h"
#include <iostream>
Snake::Snake() {}
Snake::Snake(Cell t_cell, SDL_Rect t_rect, SDL_Texture* t_texture) {
	t_cell.changeDirection(direction);
	BodyPart head(t_cell, t_rect, t_texture);
	body.push_back(head);
}
Snake::~Snake() {}
void Snake::render(SDL_Renderer* t_renderer) {
	for (auto part : body)
		part.render(t_renderer);
}
bool Snake::move(Field& field) {
	int i = 0;
	for (auto &part : body) {
		if (direction != ' ') {
			Cell& prev = field.getCell(part.cell().row(), part.cell().col());
			if (i == 0) {
				Cell& nextCell = field.nextCellByDirection(part.cell(), direction);
				if (nextCell.texture().texture() == nullptr) {
					std::cout << "Game Over" << std::endl;
					return false;
				}
				if (body.size() == 1) {
					prev.changeFree(true);
				}
				else {
					prev.changeDirection(direction);
				}
				part.setCell(nextCell);
				nextCell.changeFree(false);
				nextCell.changeDirection(direction);
			}
			else{
				Cell& nextCell = field.nextCellByDirection(part.cell(), part.cell().dir());
				if (nextCell.dir() == ' ') {
					std::cout << "Game Over" << std::endl;
					return false;
				}
				part.setCell(nextCell);
				nextCell.changeFree(false);
				if (i == body.size() - 1 && body.size() != 1) {
					prev.changeFree(true);
					prev.changeDirection(' ');
				}					
			}			
			i++;
		}
	}
	return true;
}


void Snake::changeDir(char new_dir) {
	direction = new_dir;
}

Cell& Snake::nextHeadCell(Field& field) {
	return field.nextCellByDirection(body.front().cell(), direction);
}

char Snake::getDirection() { return this->direction; }

void Snake::createPart(Field& t_field) {
	Cell& cell = body.front().cell();
	cell.changeFree(false);
	cell.changeDirection(direction);
	BodyPart new_part(cell, cell.texture().rect(), body.front().texture().texture());
	BodyPart head = body.front();
	body.push_front(new_part);
	head.setCell(t_field.nextCellByDirection(head.cell(), direction));
	head.cell().changeDirection(direction);
	body.push_front(head);
}