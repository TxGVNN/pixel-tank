#include "player.h"

Player::Player(SDL_Renderer* renderer, int x, int y, int direction):Entity(x,y,direction){
	Player::renderer = renderer;
	Player::x = x;
	Player::y = y;
	Player::direction = direction;
	noncollision = true;
	loop_img =0;

	IMG_Init(IMG_INIT_JPG);
	SDL_Surface* img = IMG_Load("res/images/player.png");
	IMG_Quit();
	if (img == NULL) {
		std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
	}
	texture = SDL_CreateTextureFromSurface(renderer, img);
	SDL_FreeSurface( img );
}

void Player::render(){
	SDL_Rect clip;
	clip.x = 0;
	clip.y = loop_img*33;
	clip.w = 33;
	clip.h = 33;
	// std::cout << x << " " << y <<std::endl;
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = 33;
	dst.h = 33;

	SDL_RenderCopyEx(renderer, texture, &clip, &dst, degrees, NULL, SDL_FLIP_NONE ); // Copy the texture into render
}

void Player::control(bool control[]){
	for (int i = 0; i < 4; i++) {
		// std::cout << i;
		if (control[i]) {
			changeDirection(i);
			refresh();
		}
	}
	loop_img = (loop_img +1) % 2 ;
}
