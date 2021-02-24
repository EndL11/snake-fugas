#include "Field.h"
#include <iostream>
Field::Field():m_rows(0), m_cols(0) {};
Field::Field(int WINDOW_WIDTH, int WINDOW_HEIGHT, int w, int h) {
	this->m_rows = WINDOW_HEIGHT / h;
	this->m_cols = WINDOW_WIDTH / w;
};
Field::~Field() {};

void Field::generateField(SDL_Rect t_rect, SDL_Texture* t_texture) {
	for (int i = 0; i < m_rows; i++) {
		std::vector<Cell> row;
		for (int j = 0; j < m_cols; j++) {
			row.push_back(Cell(t_rect, t_texture, i, j));
			t_rect.x += t_rect.w;
		}
		cells.push_back(row);
		t_rect.y += t_rect.h;
		t_rect.x = 0;
	}
}

Cell& Field::getCell(int row, int col) {
	return cells[row][col];
}
void Field::renderField(SDL_Renderer* t_renderer) {
	for (auto row : cells) {
		for (auto cell : row) {
			cell.render(t_renderer);
		}
	}
}

int Field::rows() { return this->m_rows; }
int Field::cols() { return this->m_cols; }

Cell& Field::nextCellByDirection(Cell current, char dir) {
	int row = current.row();
	int col = current.col();
	if (dir == 'r') {
		if (col + 1 >= m_cols) {
			return empty;
		}
		return cells[row][++col];
	}
	else if (dir == 'l') {
		if (col - 1 <= -1) {
			return empty;
		}
		return cells[row][--col];
	}
	else if (dir == 'u') {
		if (row - 1 <= -1) {
			return empty;
		}
		return cells[--row][col];
	}
	else if (dir == 'd') {
		if (row + 1 >= m_rows) {
			return empty;
		}
		return cells[++row][col];
	}
	else {
		return empty;
	}
}

Cell& Field::prevCellByDirection(Cell current, char dir) {
	int row = current.row();
	int col = current.col();
	if (dir == 'r') {

		return cells[row][--col];
	}
	else if (dir == 'l') {

		return cells[row][++col];
	}
	else if (dir == 'u') {

		return cells[++row][col];
	}
	else if (dir == 'd') {

		return cells[--row][col];
	}
	else {
		std::cout << 11 << std::endl;
		return empty;
	}
}
