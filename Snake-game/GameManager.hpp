#pragma once
#include "Field.hpp"
#include "Snake.hpp"
#include "Food.hpp"

class GameManager {
private:
	Field m_field;
	Snake player;
	int m_score;
	SDL_Renderer* renderer;
	SDL_Texture* food_texture;
	Food m_food;
	bool game_over = false;
public:
	GameManager();
	GameManager(SDL_Renderer* t_renderer, SDL_Texture* food_texture);
	~GameManager();
	void PerformGameSession(SDL_Rect t_rect, SDL_Texture* cell_texture, SDL_Texture* player_texture, int w_w, int w_h);
	void Render();
	int score();
	bool gameOver();
};