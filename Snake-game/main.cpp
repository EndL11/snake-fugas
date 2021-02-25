#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <time.h>
#include "GameManager.hpp"


int loadScore() {
	//	return score value from file or 0
	int score = 0;
	SDL_RWops* file = SDL_RWFromFile("score.bin", "rb");
	if (file != nullptr) {
		//	if file exist - read and close
		SDL_RWread(file, &score, sizeof(score), 1);
		SDL_RWclose(file);
	}
	return score;
}

void saveScore(int score) {
	// save score value	
	SDL_RWops* file = SDL_RWFromFile("score.bin", "wb");
	SDL_RWwrite(file, &score, sizeof(score), 1);
	SDL_RWclose(file);
}


SDL_Texture* loadImage(std::string file_name, SDL_Renderer* t_renderer) {
	//	return texture of image
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
	//	return text texture 
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
	//	loading best score
	int best_score = loadScore();
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

	font = TTF_OpenFont("oi.ttf", 30);
	//	creating textures from images for cell, player and food
	SDL_Texture* cell_texture = loadImage("1.bmp", renderer);
	SDL_Texture* player_texture = loadImage("2.bmp", renderer);
	SDL_Texture* food_texture = loadImage("4.bmp", renderer);
	//	rect for rendering all textures
	SDL_Rect rect = { 0,0,30,30};
	//	creating game manager
	GameManager gm(renderer, food_texture);
	//	starting game, creating field, generating cells, creating food
	gm.PerformGameSession(rect, cell_texture, player_texture, WINDOW_WIDTH, WINDOW_HEIGHT);

	bool quit = false;
	while (!quit) {
		SDL_Event e;
		SDL_PollEvent(&e);
		if (e.type == SDL_QUIT) {
			//	if score > best score save new best score
			if(gm.score() > best_score)
				saveScore(gm.score());
			//	quit
			quit = true;
			break;
		}
		//	set background
		SDL_SetRenderDrawColor(renderer, 105, 105, 105, 255);
		//	clear render
		SDL_RenderClear(renderer);
		//	render field, player and food
		gm.Render();
		//	if game over - show game over text
		if (gm.gameOver()) {
			SDL_Texture* text_texture = getTextTexture(font, "GAME OVER", renderer);
			SDL_Rect rect_game_over = { WINDOW_WIDTH / 3 - 80, WINDOW_HEIGHT / 3, 400, 200 };
			//	render text
			SDL_RenderCopy(renderer, text_texture, nullptr, &rect_game_over);
			//	clear texture
			SDL_DestroyTexture(text_texture);
		}
		//	show best score 
		SDL_Rect rect_best_score = { WINDOW_WIDTH - 200, 0, 200, 60 };
		SDL_Texture* best_score_texture = getTextTexture(font, ("Best Score: " + std::to_string(best_score)), renderer);
		SDL_RenderCopy(renderer, best_score_texture, nullptr, &rect_best_score);

		//	show current score
		SDL_Rect rect_score = { WINDOW_WIDTH / 2 - 30, 0, 40, 70 };
		SDL_Texture* score_texture = getTextTexture(font, std::to_string(gm.score()), renderer);
		SDL_RenderCopy(renderer, score_texture, nullptr, &rect_score);
		//	show
		SDL_RenderPresent(renderer);
		//	clear textures for score and best score
		SDL_DestroyTexture(score_texture);
		SDL_DestroyTexture(best_score_texture);

		SDL_Delay(75);
	}
	//	clear memory
	SDL_DestroyTexture(food_texture);
	SDL_DestroyTexture(player_texture);
	SDL_DestroyTexture(cell_texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}