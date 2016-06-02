#ifndef _GAME_H_
#define _GAME_H_

#include <SDL2/SDL.h>                       // SDL library.
#include <SDL2/SDL_ttf.h>                   // SDL font library.
#include <SDL2/SDL_mixer.h>

class Game
{
private:
	SDL_Window* window;  // Holds window properties.
	SDL_Renderer* renderer;  // Holds rendering surface properties.

public:
	static const int SCREEN_WIDTH;
	static const int SCREEN_HEIGHT;
	
	Game();
};

#endif
