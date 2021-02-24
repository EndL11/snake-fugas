#include "Food.h"
Food::Food() {};
Food::Food(SDL_Rect t_rect, SDL_Texture* t_texture, Cell t_cell) : m_texture(t_rect, t_texture), m_cell(t_cell) {};
Food::~Food() {};
CustomTexture Food::texture() { return this->m_texture; }
void Food::render(SDL_Renderer* t_renderer) {
	//	render if texture not null
	if(m_texture.texture() != nullptr)
		SDL_RenderCopy(t_renderer, m_texture.texture(), nullptr, &m_texture.rect());
}
void Food::replaceFood(Field t_field) {
	//	changing food position to random cell
	int randRow = rand() % t_field.rows();
	int randCol = rand() % t_field.cols();
	Cell cell = t_field.getCell(randRow, randCol);
	//	if cell not free - try again
	while (!cell.free())
	{
		randRow = rand() % t_field.rows();
		randCol = rand() % t_field.cols();
		cell = t_field.getCell(randRow, randCol);
	}
	//	setting cell to not free
	cell.changeFree(false);
	//	changing rect position for correct place to render food
	m_texture.setRect({ cell.texture().rect().x, cell.texture().rect().y, m_texture.rect().w, m_texture.rect().h });
	//	changing cell
	m_cell = cell;
}

Food Food::generateFood(SDL_Texture* t_texture, Field t_field) {
	//	generating and returing food on free cell
	int randRow = rand() % t_field.rows();
	int randCol = rand() % t_field.cols();
	Cell& cell = t_field.getCell(randRow, randCol);
	while (!cell.free())
	{
		randRow = rand() % t_field.rows();
		randCol = rand() % t_field.cols();
		cell = t_field.getCell(randRow, randCol);
	}
	cell.changeFree(false);
	return Food(cell.texture().rect(), t_texture, cell);
}

Cell Food::cell() { return this->m_cell; }