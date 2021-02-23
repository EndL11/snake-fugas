#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <time.h>
#include "GameManager.h"


SDL_Texture* loadImage(std::string file_name, SDL_Renderer* t_renderer) {
	SDL_Texture* texture = nullptr;
	SDL_Surface* surf = nullptr;
	surf = SDL_LoadBMP(file_name.c_str());

	if (surf != nullptr) {
		texture = SDL_CreateTextureFromSurface(t_renderer, surf);
		SDL_FreeSurface(surf);
	}
	return texture;
}

SDL_Texture* getTextTexture(TTF_Font* font, std::string t_text, SDL_Renderer* t_render) {
	SDL_Color color = { 24,255,24 };
	SDL_Texture* texture = nullptr;
	SDL_Surface* surf = TTF_RenderText_Solid(font, t_text.c_str(), color);
	if (surf != nullptr) {
		texture = SDL_CreateTextureFromSurface(t_render, surf);
		SDL_FreeSurface(surf);
	}
	return texture;
}

int main(int argc, char** args) {
	srand(time(NULL));
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	TTF_Font* font = nullptr;
	//	TODO: load best score
	const int WINDOW_WIDTH = 900;
	const int WINDOW_HEIGHT = 900;

	TTF_Init();

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
		system("pause");
		return 1;
	}

	window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

	if (!window) {
		std::cout << "Error creating window: " << SDL_GetError() << std::endl;
		system("pause");
		return 1;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	font = TTF_OpenFont("oi.ttf", 50);

	SDL_Texture* cell_texture = loadImage("1.bmp", renderer);
	SDL_Texture* player_texture = loadImage("2.bmp", renderer);
	SDL_Texture* food_texture = loadImage("4.bmp", renderer);
	SDL_Rect rect = { 0,0,30,30};
	//	TODO: change window width and height with map rect
	SDL_Rect map = {25, 25, WINDOW_WIDTH - 50, WINDOW_HEIGHT - 50};

	GameManager gm(renderer, food_texture);
	gm.PerformGameSession(rect, cell_texture, player_texture, WINDOW_WIDTH, WINDOW_HEIGHT);

	bool quit = false;
	bool game_over = false;
	while (!quit) {
		SDL_Event e;
		SDL_PollEvent(&e);
		if (e.type == SDL_QUIT) {
			//	TODO: save best score to file
			quit = true;
			break;
		}
		SDL_SetRenderDrawColor(renderer, 105, 105, 105, 255);
		SDL_RenderClear(renderer);


		if (!(gm.Render())) {				
			game_over = true;
		}
		
		if (game_over) {
			SDL_Texture* text_texture = getTextTexture(font, "GAME OVER", renderer);
			SDL_Rect rect_game_over = { WINDOW_WIDTH / 3, WINDOW_HEIGHT / 3, 200, 100 };
			SDL_RenderCopy(renderer, text_texture, nullptr, &rect_game_over);
			SDL_DestroyTexture(text_texture);
		}
		//	TODO: show best score
		//	TODO: make user interface

		SDL_Rect rect_score = { WINDOW_WIDTH / 2 - 150, 0, 150, 80 };
		SDL_Texture* score_texture = getTextTexture(font, ("Score: " + std::to_string(gm.score())), renderer);
		SDL_RenderCopy(renderer, score_texture, nullptr, &rect_score);

		SDL_RenderPresent(renderer);
		SDL_Delay(50);
		SDL_DestroyTexture(score_texture);
	}

	SDL_DestroyTexture(food_texture);
	SDL_DestroyTexture(player_texture);
	SDL_DestroyTexture(cell_texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}