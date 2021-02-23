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
};
void GameManager::UpdateScore(int t_score) {
	this->score += t_score;
};
void GameManager::Render() {
	this->m_field.renderField(this->renderer);
	if (m_food.texture().texture() == nullptr) {
		Food food = this->m_field.generateFood(food_texture);
		m_food = food;
	}
	m_food.render(this->renderer);
};
