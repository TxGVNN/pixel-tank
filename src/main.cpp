#include "utils.h"
#include "game.h"
#include "event.h"
#include <iostream>

int main(int argc, char *argv[])
{
    Game game;
    SDL_CreateThread(Event::checkEvent,"checkEvent", (void *)NULL);
    SDL_Delay(50);
    game.start();
    std::cout<<SDL_GetError();
    

}
