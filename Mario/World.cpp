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