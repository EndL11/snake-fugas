#include <iostream>
#include <SDL.h>
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

int main(int argc, char** args) {
	srand(time(NULL));
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	const int WINDOW_WIDTH = 900;
	const int WINDOW_HEIGHT = 900;

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

	SDL_Texture* cell_texture = loadImage("1.bmp", renderer);
	SDL_Texture* player_texture = loadImage("2.bmp", renderer);
	SDL_Texture* food_texture = loadImage("4.bmp", renderer);
	SDL_Rect rect = { 0,0,30,30};

	GameManager gm(renderer, food_texture);
	gm.PerformGameSession(rect, cell_texture, player_texture, WINDOW_WIDTH, WINDOW_HEIGHT);

	bool quit = false;
	while (!quit) {
		SDL_Event e;
		SDL_PollEvent(&e);
		if (e.type == SDL_QUIT) {
			quit = true;
			break;
		}
		SDL_SetRenderDrawColor(renderer, 105, 105, 105, 255);
		SDL_RenderClear(renderer);
		gm.Render();
		SDL_RenderPresent(renderer);
		SDL_Delay(100);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}