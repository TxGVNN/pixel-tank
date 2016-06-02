all: *.o
	g++ -o tanks -lSDL2 *.o
*.o: clean
	g++ -c *.cpp
clean:
	rm -f *.o 
