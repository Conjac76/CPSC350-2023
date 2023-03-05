#include "World.h"
#include "Mario.h"
#include <iostream>

World::World() {
    mLevel = 1;
}
World::~World() {

}

World::World(int level) {
    mLevel = level;
}

int World::getNumOfLevels() {
    return mLevel;
}

void World::setNumOfLevels(int level) {
    mLevel += level;
}