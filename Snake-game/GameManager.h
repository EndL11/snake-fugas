#pragma once
#include "Field.h"
#include "Snake.h"
#include "Food.h"

class GameManager {
private:
	Field m_field;
	Snake player;
	int score;
	SDL_Renderer* renderer;
	SDL_Texture* food_texture;
	Food m_food;
public:
	GameManager();
	GameManager(SDL_Renderer* t_renderer, SDL_Texture* food_texture);
	~GameManager();
	void PerformGameSession(SDL_Rect t_rect, SDL_Texture* cell_texture, SDL_Texture* player_texture, int w_w, int w_h);
	void UpdateScore(int plusScore);
	void Render(SDL_Event *e);
};