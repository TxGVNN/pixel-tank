#include "bullet.h"

Bullet::Bullet(SDL_Renderer* renderer, int x, int y, int direction): Entity(x,y,direction){
    Bullet::renderer = renderer;
    Bullet::direction = direction;
    Bullet::x = x;
    Bullet::y = y;

    if (direction == Bullet::DIRECTION_UP){
        Bullet::y = y - 15;
    }
    if (direction == Bullet::DIRECTION_DOWN){
        Bullet::y = y + 15;
    }
    if (direction == Bullet::DIRECTION_LEFT){
        Bullet::x = x + 15;
    }
    if (direction == Bullet::DIRECTION_RIGHT){
        Bullet::x = x + 15;
    }

    noncollision = true;
    active = true;

    IMG_Init(IMG_INIT_JPG);
    SDL_Surface* img = IMG_Load("res/images/bullet.png");
    IMG_Quit();
    if (img == NULL) {
        std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
    }
    texture = SDL_CreateTextureFromSurface(renderer, img);
    SDL_FreeSurface( img );

}
void Bullet::render(){
    SDL_Rect clip;
    clip.x = 0;
    clip.y = 0;
    clip.w = 24;
    clip.h = 24;
    // std::cout << x << " " << y <<std::endl;
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    dst.w = 15;
    dst.h = 15;

    SDL_RenderCopy(renderer, texture, &clip, &dst); // Copy the texture into render
}

void Bullet::update(){
    if (!runAvailble()) {
        active = false;
    } else {
        move(15);
    }
}

bool Bullet::isActive(){
    return active;
}
