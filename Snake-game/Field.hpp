#pragma once
#include "Cell.hpp"
#include <vector>
class Field {
private:
	std::vector<std::vector<Cell>> cells;
	int m_rows;
	int m_cols;
	Cell empty = Cell();
public:
	Field();
	Field(int WINDOW_WIDTH, int WINDOW_HEIGHT, int w, int h);
	~Field();
	Cell& getCell(int row, int col);
	void generateField(SDL_Rect t_rect, SDL_Texture* t_texture);
	void renderField(SDL_Renderer* t_renderer);
	int rows();
	int cols();
	Cell& nextCellByDirection(Cell current, char dir);
	Cell& prevCellByDirection(Cell current, char dir);
};