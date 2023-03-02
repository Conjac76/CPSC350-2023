#include "Level.h"
#include <iostream>
#include <cstdlib>

Level::Level() {

}

Level::~Level() {

}

Level::Level(int size) {
    std::string level[size][size];
    srand(17);
    std::cout << "working..." << std::endl;
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            int randomlyDispurseEnemies = rand() % 5;
            if (randomlyDispurseEnemies == 0) {
                level[i][j] = 'x';
            } else if (randomlyDispurseEnemies == 1) {
                level[i][j] = 'm';
            } else if (randomlyDispurseEnemies == 2) {
                level[i][j] = 'c';
            } else if (randomlyDispurseEnemies == 3) {
                level[i][j] = 'g';
            } else if (randomlyDispurseEnemies == 4) {
                level[i][j] = 'k';
            }
        }
    }   
    marioCoordX = rand() % size;
    marioCoordY = rand() % size;
    level[marioCoordX][marioCoordY] = 'H';
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            std::cout << level[j][i] << std::endl;
        }
    }
} 

void Level::up() {
    marioCoordY += 1;
    if(marioCoordY == mSize) {
        marioCoordY = 0;
    } 
}

void Level::down() {
    marioCoordY -= 1;
    if(marioCoordY == 0){
        marioCoordY = mSize;
    }
}

void Level::left() {
    marioCoordX += 1;
    if(marioCoordX == 0){
        marioCoordY = mSize;
    }
}

void Level::right() {
    marioCoordY += 1;
    if(marioCoordY == mSize){
        marioCoordY = 0;
    }
}
