#include "event.h"

bool Event::control[5] = {false, false, false, false, false}; //{UP,RIGHT, LEFT, DOWN, ATTACK}

SDL_Event Event::event;

int Event::checkEvent(void *data){

	while (1){
		while( SDL_PollEvent( &Event::event ) != 0 )
		{
			//User requests quit
			if( Event::event.type == SDL_QUIT )
			{
				// quit = true;
				std::cout<<"quit"<<std::endl;
			}
			//User presses a key
			if( Event::event.type == SDL_KEYDOWN )
			{
				//Select surfaces based on key press
				switch( Event::event.key.keysym.sym )
				{
					case SDLK_UP:
					std::cout<<"UP"<<std::endl;
					Event::control[0] = true;
					break;

					case SDLK_RIGHT:
					std::cout<<"RIGHT"<<std::endl;
					Event::control[1] = true;
					break;

					case SDLK_DOWN:
					std::cout<<"DOWN"<<std::endl;
					Event::control[2] = true;
					break;

					case SDLK_LEFT:
					std::cout<<"LEFT"<<std::endl;
					Event::control[3] = true;
					break;

					case SDLK_SPACE:
					std::cout<<"SPACE"<<std::endl;
					Event::control[4] = true;
					break;

				}
			}
			if( Event::event.type == SDL_KEYUP )
			{
				//Select surfaces based on key press
				switch( Event::event.key.keysym.sym )
				{
					case SDLK_UP:
					std::cout<<"U_UP"<<std::endl;
					Event::control[0] = false;
					break;

					case SDLK_RIGHT:
					std::cout<<"U_RIGHT"<<std::endl;
					Event::control[1] = false;
					break;

					case SDLK_DOWN:
					std::cout<<"U_DOWN"<<std::endl;
					Event::control[2] = false;
					break;

					case SDLK_LEFT:
					std::cout<<"U_LEFT"<<std::endl;
					Event::control[3] = false;
					break;

					case SDLK_SPACE:
					std::cout<<"SPACE"<<std::endl;
					Event::control[4] = false;
					break;

				}
			}
		}
	}

	return 0;
}
