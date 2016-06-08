#ifndef _ENTITY_H_
#define _ENTITY_H_
#include "utils.h"

class Entity
{
private:
	volatile bool updateDirection;
	volatile bool updatePosition;
protected:
	volatile int direction;
	bool active;
	virtual void createSprite();
	virtual void render();
	virtual void update();
	bool changeDirection(int newDirection);
	void move(int distance);
	bool runAvailble();

public:
	static const int SPEED;
	static const int DIRECTION_UP;//UP
	static const int DIRECTION_RIGHT;//RIGHT
	static const int DIRECTION_DOWN;//LEFT
	static const int DIRECTION_LEFT;//DOWN
	int oldX,oldY, x,y;
	int width, height;
	double degrees;
	bool noncollision;
	int tdNong, tdVai, tdMong, tdChan, tdTrai, tdPhai;
	Entity(int x, int y, int direction);
	void refresh();
	bool checkCollision(Entity other);
};

#endif
