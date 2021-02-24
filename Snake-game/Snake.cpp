#include "Snake.h"
#include <iostream>
Snake::Snake() {}
Snake::Snake(Cell t_cell, SDL_Rect t_rect, SDL_Texture* t_texture) {
	//	on creating snake, set for cell moving direction
	t_cell.changeDirection(direction);
	//	create head with direction
	BodyPart head(t_cell, t_rect, t_texture);
	//	push head to list of parts
	body.push_back(head);
}
Snake::~Snake() {}
void Snake::render(SDL_Renderer* t_renderer) {
	//	rendering each part
	for (auto part : body)
		part.render(t_renderer);
}
bool Snake::move(Field& field) {
	int i = 0;
	for (auto &part : body) {
		if (direction != ' ') {
			Cell& prev = field.getCell(part.cell().row(), part.cell().col());
			//	if part is head
			if (i == 0) {
				//	get next cell for head by direction
				Cell& nextCell = field.nextCellByDirection(part.cell(), direction);
				//	if cell texture is null (returned empty cell)
				if (nextCell.texture().texture() == nullptr) {
					//	player try to move beyond the borders
					std::cout << "Game Over" << std::endl;
					//	return false if try to move to empty cell
					return false;
				}
				//	if there are any parts except head
				if (body.size() == 1) {
					//	set prev cell to free
					prev.changeFree(true);
				}
				else {
					//	otherwise set to prev cell how to move for head
					prev.changeDirection(direction);
				}
				//	move head
				part.setCell(nextCell);
				//	set to next (current) cell not free
				nextCell.changeFree(false);
				//	set to next cell direction
				nextCell.changeDirection(direction);
			}
			//	if it's not head
			else{
				//	get next cell for part
				Cell& nextCell = field.nextCellByDirection(part.cell(), part.cell().dir());
				//	if cell dir is null (returned empty cell)
				if (nextCell.dir() == ' ') {
					std::cout << "Game Over" << std::endl;
					return false;
				}
				//	move part
				part.setCell(nextCell);
				//	set current cell to not free
				nextCell.changeFree(false);
				//	if it's last part of body 
				if (i == body.size() - 1) {
					//	set previous cell to free
					prev.changeFree(true);
				}					
			}			
			i++;
		}
	}
	//	return true if movement is correct
	return true;
}


void Snake::changeDir(char new_dir) {
	//	set head direction
	direction = new_dir;
}

Cell& Snake::nextHeadCell(Field& field) {
	//	get next head direction cell to move
	return field.nextCellByDirection(body.front().cell(), direction);
}

char Snake::getDirection() { return this->direction; }

void Snake::createPart(Field& t_field) {
	//	get head cell
	Cell& cell = body.front().cell();
	//	set this cell to not free
	cell.changeFree(false);
	//	set cell direction (set head direction)
	cell.changeDirection(direction);
	//	create new part
	BodyPart new_part(cell, cell.texture().rect(), body.front().texture().texture());
	//	get head
	BodyPart head = body.front();
	//	remove head from body list
	body.remove(head);
	//	push new part to start of body list
	body.push_front(new_part);
	//	set head cell to next cell by direction 
	head.setCell(t_field.nextCellByDirection(head.cell(), direction));
	//	set direction to this new cell for head
	head.cell().changeDirection(direction);
	//	push head to start
	body.push_front(head);
}