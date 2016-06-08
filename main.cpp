#include "utils.h"
#include "game.h"
#include "event.h"

int main(int argc, char *argv[])
{
	SDL_CreateThread(Event::checkEvent,"checkEvent", (void *)NULL);
	Game game;


}
