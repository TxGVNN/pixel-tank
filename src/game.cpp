#include "game.h"
#include "event.h"


const int Game::SCREEN_WIDTH = 690;
const int Game::SCREEN_HEIGHT = 480;
const int Game::SCREEN_LINE = 560;
const int Game::CELL_SIZE = 15;

Game::Game(){
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_ShowCursor(0);

    window = SDL_CreateWindow("Pixel Tank",
                              SDL_WINDOWPOS_UNDEFINED,  // Centered window.
                              SDL_WINDOWPOS_UNDEFINED,  // Centered window.
                              SCREEN_WIDTH,
                              SCREEN_HEIGHT,
                              SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    xCell = SCREEN_WIDTH / CELL_SIZE;
    yCell = SCREEN_HEIGHT / CELL_SIZE;

    init();
}
Game::~Game(){

    // Destroy renderer and window.
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    // Shuts down SDL.
    SDL_Quit();
}
void Game::start()
{
  
    int i = 100;
    init();
    while(i>0){
        input();
        update();
        render();
        i--;
    }
}
void Game::init(){
    IMG_Init(IMG_INIT_JPG);
    SDL_Surface* img = IMG_Load("res/images/cell_empty.png");
    IMG_Quit();
    if (img == NULL) {
        std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
    }

    background = SDL_CreateTextureFromSurface(renderer, img);
    SDL_FreeSurface( img );

    player = new Player(renderer, 15,15,0);
}

void Game::update(){
    // Entity *entity;
    player -> update();

}

void Game::render(){

    SDL_SetRenderDrawColor(renderer, 128, 130, 114, 0);
    SDL_RenderClear(renderer);

    //Draw the Cell by calculating their positions
    for (int i = 0; i < xCell * yCell; ++i){
        int x = i % xCell;
        int y = i / xCell;

        SDL_Rect dst;
        dst.x = x * CELL_SIZE;
        dst.y = y * CELL_SIZE;
        dst.w = CELL_SIZE;
        dst.h = CELL_SIZE;
        SDL_RenderCopy(renderer, background, NULL, &dst);

    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(renderer, 600, 0, 600, 480);

    player -> render();
    SDL_RenderPresent(renderer);
    SDL_Delay(100);
}

void Game::input(){
    player -> control(Event::control);
}
