#include "game.h"
#include "event.h"

const int Game::SCREEN_WIDTH = 640;
const int Game::SCREEN_HEIGHT = 480;

Game::Game(){
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_ShowCursor(0);

	window = SDL_CreateWindow("Pixel Tank",
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
		input();
		render();
		i--;
	}
}
void Game::init(){
	SDL_SetRenderDrawColor(renderer, 128, 130, 114, 0);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawLine(renderer, 560, 0, 560, 480);

	SDL_RenderPresent(renderer);
	player = new Player(100,100);
}

void Game::render(){

	SDL_SetRenderDrawColor(renderer, 128, 130, 114, 0);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawLine(renderer, 560, 0, 560, 480);

	player -> render(renderer);
	SDL_RenderPresent(renderer);
	SDL_Delay(10);

}

void Game::input(){
	for (int i =0; i < 5; i++){
		std::cout << Event::control[i];
	}
	std::cout<<std::endl;

}
void Game::update(){
	// Entity *entity;

}
