#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "entity.h"


class Player: public Entity
{
private:
	SDL_Renderer* renderer;
	SDL_Texture *texture;
	int loop_img;
public:
	Player(SDL_Renderer* renderer, int x, int y);
	void render();
	void control(bool[]);
};


#endif
