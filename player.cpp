#include "player.h"

Player::Player(int x, int y):Entity(x,y){
	Player::x = x;
	Player::y = y;
	noncollision = true;
	IMG_Init(IMG_INIT_JPG);
	img = IMG_Load("res/images/player.png");
	IMG_Quit();
	if (img == NULL) {
		std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
	}
	// HERE shoudL SDL_CreateTextureFromSurface
	// HERE SDL_FreeSurface( img );
}

void Player::render(SDL_Renderer* renderer){
	texture = SDL_CreateTextureFromSurface(renderer, img);
	SDL_Rect clip;
	clip.x = 0;
	clip.y = 0;
	clip.w = 33;
	clip.h = 33;
	// std::cout << x << " " << y <<std::endl;
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = 33;
	dst.h = 33;

	SDL_RenderCopy(renderer, texture, &clip, &dst); // Copy the texture into render
}

void Player::control(bool control[]){
	for (int i = 0; i < 4; i++) {
		// std::cout << i;
		if (control[i]) {
			changeDirection(i);
			refresh();
		}
	}
}
