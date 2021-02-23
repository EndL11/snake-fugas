#include "Field.h"
#include <iostream>
Field::Field():rows(0), cols(0) {};
Field::Field(int WINDOW_WIDTH, int WINDOW_HEIGHT, int w, int h) {
	int rows = WINDOW_HEIGHT / h;
	int cols = WINDOW_WIDTH / w;
	this->rows = rows;
	this->cols = cols;
};
Field::~Field() {};

void Field::generateField(SDL_Rect t_rect, SDL_Texture* t_texture) {
	for (int i = 0; i < rows; i++) {
		std::vector<Cell> row;
		for (int j = 0; j < cols; j++) {
			row.push_back(Cell(t_rect, t_texture));
			t_rect.x += t_rect.w;
		}
		cells.push_back(row);
		t_rect.y += t_rect.h;
		t_rect.x = 0;
	}
}

Cell Field::getCell(int row, int col) {
	return cells[row][col];
}
void Field::renderField(SDL_Renderer* t_renderer) {
	for (auto row : cells) {
		for (auto cell : row) {
			cell.render(t_renderer);
		}
	}
}

Food Field::generateFood(SDL_Texture* t_texture) {
	int randRow = rand() % rows;
	int randCol = rand() % cols;
	Cell cell = getCell(randRow, randCol);
	while (!cell.free())
	{
		randRow = rand() % rows;
		randCol = rand() % cols;
		cell = getCell(randRow, randCol);
	}
	
	return Food(cell.texture().rect(), t_texture);
}