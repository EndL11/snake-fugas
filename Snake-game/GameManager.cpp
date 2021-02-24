#include "GameManager.h"
GameManager::GameManager(): m_score(0), renderer(nullptr), food_texture(nullptr), m_food() {};
GameManager::GameManager(SDL_Renderer* t_renderer, SDL_Texture* t_food_texture)
	: renderer(t_renderer), m_score(0), m_food(), food_texture(t_food_texture)
{};
GameManager::~GameManager() {};
void GameManager::PerformGameSession(SDL_Rect t_rect, SDL_Texture* cell_texture, SDL_Texture* player_texture, int w_w, int w_h) {
	//	perform game 

	//	creating field with cell window width and height and width and height 
	Field field(w_w, w_h, t_rect.w, t_rect.h );
	//	generate cells
	field.generateField(t_rect, cell_texture);
	//	setting field 
	this->m_field = field;
	//	get center cell for player spawn
	Cell& cell = m_field.getCell(m_field.rows() / 2, m_field.cols() / 2);
	//	set cell to not free
	cell.changeFree(false);
	//	create player
	Snake snake(cell, t_rect, player_texture);
	//	set created snake to player
	player = snake;
	//	generate on random position food and set it
	m_food = this->m_food.generateFood(food_texture, m_field);
};

void GameManager::Render() {
	//	flag for must create new part for player after moving
	bool need_spawn = false;
	//	render field
	this->m_field.renderField(this->renderer);
	//	render food
	m_food.render(this->renderer);
	//	render player
	player.render(this->renderer);

	//	if not game over
	if (!game_over) {
		//	get keys state
		const Uint8* state = SDL_GetKeyboardState(NULL);
		//	change moving direction for player
		// d - down, u - up, r - right, l - left 
		if (state[SDL_SCANCODE_W] && player.getDirection() != 'd') 		player.changeDir('u');
		else if (state[SDL_SCANCODE_S] && player.getDirection() != 'u') player.changeDir('d');
		else if (state[SDL_SCANCODE_A] && player.getDirection() != 'r') player.changeDir('l');
		else if (state[SDL_SCANCODE_D] && player.getDirection() != 'l') player.changeDir('r');

		//	if next head cell if food
		if (player.nextHeadCell(m_field) == m_food.cell()) {
			//	increase score
			m_score += 1;
			//	replace food to another free cell
			m_food.replaceFood(m_field);
			//	set must create new part to true
			need_spawn = true;
		}
		//	otherwise if newx head cell to move is not food but it's not free
		else if (player.nextHeadCell(m_field) != m_food.cell() && !player.nextHeadCell(m_field).free()) {
			//	player try to move to it's part
			//	game over
			std::cout << "Cell is not free" << std::endl;
			game_over = true;
		}
		//	if movement not correct
		if (!(player.move(this->m_field))) {
			//	player try to move out of window borders
			std::cout << "Zone over" << std::endl;
			//	game over
			game_over = true;
		}
		//	if need to create new part
		if (need_spawn) {
			//	create part for player
			player.createPart(m_field);
		}
	}
};

int GameManager::score() { return this->m_score; }

bool GameManager::gameOver() {
	return this->game_over;
}
