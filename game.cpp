#include "game.h"

const int Game::SCREEN_WIDTH = 640;
const int Game::SCREEN_HEIGHT = 480;

Game::Game(){
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_ShowCursor(0);

	window = SDL_CreateWindow("Tank tank",
		SDL_WINDOWPOS_UNDEFINED,  // Centered window.
		SDL_WINDOWPOS_UNDEFINED,  // Centered window.
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
			SDL_RENDERER_PRESENTVSYNC);

	init();

	int i = 100;
	while(i>0){
		init();
		i--;
	}
}
void Game::init(){
	SDL_SetRenderDrawColor(renderer, 128, 130, 114, 0);
	SDL_RenderClear(renderer);
	// Paddle color.
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawLine(renderer, 560, 0, 560, 480);

	// Swap buffers.
	SDL_RenderPresent(renderer);
}

void Game::render(){
	SDL_SetRenderDrawColor(renderer, 128, 130, 114, 0);
	SDL_RenderClear(renderer);
	// Paddle color.
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawLine(renderer, 560, 0, 560, 480);
	// Swap buffers.
	SDL_RenderPresent(renderer);
}
