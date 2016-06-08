#ifndef _BULLET_H_
#define _BULLET_H_
#include "entity.h"

class Bullet: public Entity
{
private:
	SDL_Renderer* renderer;
	SDL_Texture *texture;
public:
	Bullet(SDL_Renderer* renderer, int x, int y, int direction);
	void render();
	void update();
	bool isActive();
};


#endif
