#include "World.h"
#include "Mario.h"
#include <iostream>
#include <cstdlib>

World::~World() {
    delete[] mpWorldMap;
}

World::World(int numberOfLevels, int gridSize, int percentCoins, int percentNothing, int percentGoombas, int percentKoopas, int percentMushrooms) {
    mGrideSize = gridSize;
    mNumOfLevels = numberOfLevels;
    //Defines a 3D world as a single char array.
    mpWorldMap = new char[numberOfLevels * gridSize * gridSize];
    for(int h = 0; h < numberOfLevels; ++h) {
        for(int i = 0; i < gridSize; ++i) {
            for(int j = 0; j < gridSize; ++j) {
                int randomlyDispurseEnemies = rand() % 100;
                if (randomlyDispurseEnemies < percentNothing) {
                    setAt(h, i , j, 'x');
                } else if (randomlyDispurseEnemies < (percentMushrooms+percentNothing)) {
                    setAt(h, i, j, 'm');
                } else if (randomlyDispurseEnemies < (percentCoins+percentMushrooms+percentNothing)) {
                    setAt(h, i, j, 'c');
                } else if (randomlyDispurseEnemies < (percentGoombas + percentCoins+percentMushrooms+percentNothing)) {
                    setAt(h, i, j, 'g');
                } else if (randomlyDispurseEnemies < (percentKoopas + percentGoombas + percentCoins+percentMushrooms+percentNothing)) {
                    setAt(h, i, j, 'k');
                }
            }
        }
        if(h < numberOfLevels-1) {
            int warpCoordX = rand() % gridSize;
            int warpCoordY = rand() % gridSize;
            setAt(h, warpCoordX, warpCoordY, 'w');
        }
        int bossCoordX = rand() % gridSize;
        int bossCoordY = rand() % gridSize;
        setAt(h, bossCoordX, bossCoordY, 'b');
    }
    
}

int World::getNumOfLevels() {
    return mNumOfLevels;
}


char World::getAt(int level, int row, int col) {
    //Translates position from 3D world position to world map array.
    int position = level * (mGrideSize * mGrideSize) + row * mGrideSize + col;
    return mpWorldMap[position];  
}

void World::setAt(int level, int row, int col, char c) {
    //Translates position from 3D world position to world map array.
    int position = level * (mGrideSize * mGrideSize) + row * mGrideSize + col;
    mpWorldMap[position] = c;  
}

void World::printLevel(int level) {
    std::cout << "Level: " << level << std:: endl;
    for(int i = 0; i < mGrideSize; ++i) {
        for(int j = 0; j < mGrideSize; ++j){
            std::cout << getAt(level, i, j) << " ";
        }
        std:: cout << "\n";
    }
    std::cout << std::endl;
}

void World::printWorld() {
    for(int level = 0; level < mNumOfLevels; ++level) {
        printLevel(level);         
    }
}

int World::getGridSize() {
    return mGrideSize;
}
