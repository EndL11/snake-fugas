#include "GameManager.h"
GameManager::GameManager(): score(0), renderer(nullptr), food_texture(nullptr), m_food() {};
GameManager::GameManager(SDL_Renderer* t_renderer, SDL_Texture* t_food_texture)
	: renderer(t_renderer), score(0), m_food(), food_texture(t_food_texture) 
{};
GameManager::~GameManager() {};
void GameManager::PerformGameSession(SDL_Rect t_rect, SDL_Texture* cell_texture, SDL_Texture* player_texture, int w_w, int w_h) {

	Field field(w_w, w_h, t_rect.w, t_rect.h );
	field.generateField(t_rect, cell_texture);
	this->m_field = field;
	Cell cell = m_field.getCell(0, 0);
	cell.changeFree(false);
	Snake snake(cell, t_rect, player_texture);
	player = snake;
	m_food = this->m_food.generateFood(food_texture, m_field);
};
void GameManager::UpdateScore(int t_score) {
	this->score += t_score;
};
void GameManager::Render(SDL_Event *e) {
	const Uint8* state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_W]) {
		player.changeDir('u');
	}
	if (state[SDL_SCANCODE_S]) {
		player.changeDir('d');
	}
	if (state[SDL_SCANCODE_A]) {
		player.changeDir('l');
	}
	if (state[SDL_SCANCODE_D]) {
		player.changeDir('r');
	}

	this->m_field.renderField(this->renderer);
	m_food.render(this->renderer);
	if (!(player.move(this->m_field))) {
		std::cout << "Game manager game over" << std::endl;
		return;
	}
	player.render(this->renderer);
};
