BINARY		:= tanks
OBJS		:= *.o
SDL_INCLUDE	:= `sdl2-config --cflags` -I.
SDL_LIB		:= `sdl2-config --libs` -lSDL2_ttf -lSDL2_mixer

CPPFLAGS	+= $(SDL_INCLUDE)
CXXFLAGS	+= -g -Wall -std=c++11
LDFLAGS		+= $(SDL_LIB)

all: $(BINARY)

$(BINARY): $(OBJS)
	$(LINK.cc) -o $(BINARY) $(LDFLAGS) *.o
$(OBJS): clean
	$(LINK.cc) $(DEBUG) -c *.cpp
clean:
	rm -f *.o 
