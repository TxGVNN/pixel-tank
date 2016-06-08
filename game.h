#ifndef _GAME_H_
#define _GAME_H_
#include "utils.h"
#include "player.h"

class Game
{
private:
	SDL_Window* window;  // Holds window properties.
	SDL_Renderer* renderer;  // Holds rendering surface properties.
	Player* player;

public:
	static const int SCREEN_WIDTH;
	static const int SCREEN_HEIGHT;
	static const int SCREEN_LINE;
	Game();
	~Game();
	void start();
	void init();
	void input();
	void update();
	void render();

};

#endif
