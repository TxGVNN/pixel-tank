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
}
