#include "game.h"
#include "event.h"

const int Game::SCREEN_WIDTH = 640;
const int Game::SCREEN_HEIGHT = 480;
const int Game::SCREEN_LINE = 560;

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
}

void Game::start()
{
	int i = 100;
	while(i>0){
		update();
		render();
		i--;
	}
}
void Game::init(){
	SDL_SetRenderDrawColor(renderer, 128, 130, 114, 0);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawLine(renderer, SCREEN_LINE, 0, SCREEN_LINE, SCREEN_HEIGHT);

	SDL_RenderPresent(renderer);
	player = new Player(renderer, 100,100);
}

void Game::update(){
	// Entity *entity;
	player -> control(Event::control);

}

void Game::render(){

	SDL_SetRenderDrawColor(renderer, 128, 130, 114, 0);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawLine(renderer, 560, 0, 560, 480);

	player -> render();
	SDL_RenderPresent(renderer);
	SDL_Delay(50);
}
/*
void Game::input(){
	for (int i =0; i < 5; i++){
		std::cout << Event::control[i];
	}
	std::cout<<std::endl;
}
*/
