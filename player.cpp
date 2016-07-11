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
	Player::v_bullet.reserve(10);
}

void Player::render(){
	SDL_Rect clip;
	clip.x = 0;
	clip.y = loop_img*72;
	clip.w = 72;
	clip.h = 72;
	// std::cout << x << " " << y <<std::endl;
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = 45;
	dst.h = 45;

	SDL_RenderCopyEx(renderer, texture, &clip, &dst, degrees, NULL, SDL_FLIP_NONE ); // Copy the texture into render
	for (int i =0 ; i < (int)v_bullet.size(); i++){
		v_bullet.at(i).render();
	}
}

void Player::update(){
	// Bullet bullet;
	for (int i = (int)v_bullet.size() -1; i>=0; i--){
		// bullet =
		// bullet.update();
		v_bullet.at(i).update();
		if (!v_bullet.at(i).isActive()){
			v_bullet.erase(v_bullet.begin()+ i);

		}
	}
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
	if (control[4]){
		Bullet bullet(renderer, x+15,y+15,direction);
		v_bullet.push_back(bullet);
	}
}
