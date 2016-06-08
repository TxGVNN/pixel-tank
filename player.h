#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <vector>
#include "entity.h"
#include "bullet.h"


class Player: public Entity
{
private:
	SDL_Renderer* renderer;
	SDL_Texture *texture;
	int loop_img;
public:
	Player(SDL_Renderer* renderer, int x, int y, int direction);
	std::vector<Bullet> v_bullet;
	void render();
	void update();
	void control(bool[]);
};


#endif
