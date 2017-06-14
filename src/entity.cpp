#include "entity.h"
#include "game.h"

const int Entity::SPEED = 15;
const int Entity::DIRECTION_UP = 0;//UP
const int Entity::DIRECTION_RIGHT = 1;//RIGHT
const int Entity::DIRECTION_DOWN = 2;//DOWN
const int Entity::DIRECTION_LEFT = 3;//LEFT

Entity::Entity(int x, int y, int direction){
    direction = direction;
    tdNong = y - 16;
    tdVai = y - 5;
    tdMong = y + 5;
    tdChan = y + 16;
    tdTrai = x - 16;
    tdPhai = x + 16;
    degrees = 0;

}
void Entity::createSprite(){};
void Entity::render(){};
void Entity::update(){};

void Entity::refresh(){
    switch (direction) {
    case DIRECTION_UP:
        tdNong= y - 16;
        tdVai = y - 5;
        tdMong = y + 5;
        tdChan = y + 16;
        tdTrai = x - 16;
        tdPhai = x + 16;
        break;
    case DIRECTION_DOWN:
        tdNong= y + 16;
        tdVai = y + 5;
        tdMong = y - 5;
        tdChan = y - 16;
        tdTrai = x + 16;
        tdPhai = x - 15;
        break;
    case DIRECTION_LEFT:
        tdNong= x - 16;
        tdVai = x - 5;
        tdMong = x + 5;
        tdChan = x + 16;
        tdTrai = y + 15;
        tdPhai = y - 15;
        break;
    case DIRECTION_RIGHT:
        tdNong= x + 16;
        tdVai = x + 5;
        tdMong = x - 5;
        tdChan = x - 16;
        tdTrai = y - 15;
        tdPhai = y + 15;
        break;
    }
    if (updatePosition) {
        if (runAvailble()&& noncollision) {
            move(SPEED);
        }
    }

    if (updateDirection) {
        noncollision = true;
        updateDirection = false;
        updatePosition = true;

        switch (direction) {
        case DIRECTION_UP:
            degrees = 0;
            break;
        case DIRECTION_DOWN:
            degrees = 180;
            break;
        case DIRECTION_LEFT:
            degrees = -90;
            break;
        case DIRECTION_RIGHT:
            degrees = +90;
            break;
        }
    }
}

bool Entity::changeDirection(int newDirection) {
    bool changed = direction != newDirection;
    direction = newDirection;
    if (changed) {
        updateDirection = true;
        updatePosition = false;
    }
    return changed;
}
void Entity::move(int distance) {

    switch (direction) {
    case DIRECTION_UP:
        y -= distance;
        break;
    case DIRECTION_DOWN:
        y += distance;
        break;
    case DIRECTION_LEFT:
        x -= distance;
        break;
    case DIRECTION_RIGHT:
        x += distance;
        break;
    }
    // set pixel center?
}
bool Entity::runAvailble(){
    bool avail = true;
    if (((x <= 0) && (direction == DIRECTION_LEFT)) || ((x >= Game::SCREEN_LINE - 33) && (direction == DIRECTION_RIGHT)) || ((y <= 0) && (direction == DIRECTION_UP)) || ((y >= Game::SCREEN_HEIGHT -33) && (direction == DIRECTION_DOWN))) {
        avail = false;
    }
    return avail;
}

bool Entity::checkCollision(Entity other){
    return 0;//checkCollision
}
