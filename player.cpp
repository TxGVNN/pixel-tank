#include "player.h"

Player::Player(int x, int y):Entity(x,y){
	Player::x = x;
	Player::y = y;
	IMG_Init(IMG_INIT_JPG);
	img = IMG_Load("res/images/player.png");
	IMG_Quit();
	if (img == NULL) {
		std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
	}
}

void Player::render(SDL_Renderer* renderer){
	texture = SDL_CreateTextureFromSurface(renderer, img);
	SDL_Rect *clip = nullptr;

	// std::cout << x << " " << y <<std::endl;
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	SDL_QueryTexture(texture, nullptr, nullptr, &dst.w, &dst.h);
	SDL_RenderCopy(renderer, texture, clip, &dst); // Copy the texture into render
}
