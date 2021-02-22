#include "Field.h"

Field::Field():rows(0), cols(0) {};
Field::Field(int WINDOW_WIDTH, int WINDOW_HEIGHT, int w, int h) {
	int rows = WINDOW_HEIGHT / h;
	int cols = WINDOW_WIDTH / w;
	this->rows = rows;
	this->cols = cols;
};
Field::~Field() {};

void Field::generateField(SDL_Rect& t_rect, SDL_Texture* t_texture) {
	for (int i = 0; i < rows; i++) {
		std::vector<Cell> row;
		for (int j = 0; j < cols; j++) {
			row.push_back(Cell(t_rect, t_texture));
		}
		cells.push_back(row);
	}
}

Cell Field::getCell(int row, int col) {
	return cells[row][col];
}