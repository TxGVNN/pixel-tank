BINARY		:= tanks
SRCS		:= $(wildcard *.cpp)
OBJS		:= $(SRCS:.cpp=.o)
SDL_INCLUDE	:= `sdl2-config --cflags` -I.
SDL_LIB		:= `sdl2-config --libs` -lSDL2_ttf -lSDL2_mixer

CPPFLAGS	+= $(SDL_INCLUDE)
CXXFLAGS	+= -g -Wall -std=c++11
LDFLAGS		+= $(SDL_LIB)

.PHONY: all clean

all: $(BINARY)

$(BINARY): $(OBJS)
	$(LINK.cc) -o $(BINARY) $(LDFLAGS) $(OBJS)
clean:
	rm -f *.o $(BINARY)
