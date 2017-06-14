#ifndef _EVENT_H_
#define _EVENT_H_
#include "utils.h"

class Event
{

 public:
    static SDL_Event event;
    static bool control[5];
    static int checkEvent(void *data);
};
#endif
