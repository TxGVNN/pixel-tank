#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "entity.h"


class Player: public Entity
{
private:
	SDL_Surface* img;
	SDL_Texture *texture;
public:
	Player(int x, int y);
	void render(SDL_Renderer* renderer);
	void control(bool[]);
};


#endif
