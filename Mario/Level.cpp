#include "Level.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

Level::Level() {

}

Level::~Level() {

}

Level::Level(int size, int percentCoins, int percentKoopas, int percentGoombas, int percentNothing, int percentMushrooms) {
    srand(time(NULL));
    mSize = size;
    std::string* level = new std::string[mSize * mSize];
    pLevel = level;
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            int randomlyDispurseEnemies = rand() % 100;
            if (randomlyDispurseEnemies < percentNothing) {
                *(level + i * mSize + j) = 'x';
            } else if (randomlyDispurseEnemies < (percentMushrooms+percentNothing)) {
                *(level + i * mSize + j) = 'm';
            } else if (randomlyDispurseEnemies < (percentCoins+percentMushrooms+percentNothing)) {
                *(level + i * mSize + j) = 'c';
            } else if (randomlyDispurseEnemies < (percentGoombas + percentCoins+percentMushrooms+percentNothing)) {
                *(level + i * mSize + j) = 'g';
            } else if (randomlyDispurseEnemies < (percentKoopas + percentGoombas + percentCoins+percentMushrooms+percentNothing)) {
                *(level + i * mSize + j) = 'k';
            }
        }
    }
    int i = rand() % mSize;
    int j = rand() % mSize;
    *(level + i * mSize + j) = 'w';  
    int bossCoordX = rand() % size;
    int bossCoordY = rand() % size;
    *(level + bossCoordX * size + bossCoordY) = 'b'; 
    marioCoordX = rand() % size;
    marioCoordY = rand() % size;
    std::cout << "Mario is at column: " << marioCoordY << ", row: " << marioCoordX << std::endl;
    pointerX = &marioCoordX;
    pointerY = &marioCoordY;
    previousItem = *(level + marioCoordX * size + marioCoordY);
    *(level + marioCoordX * size + marioCoordY) = 'H';
} 

void Level::up() {
    std::cout << "up\n";
    *(pLevel + *pointerX * mSize + *pointerY) = ' ';
    *pointerX += 1;
    if(*pointerX > mSize-1) {
        *pointerX = 0;
    }
    std::cout << "Mario is at column "<< *pointerY << ", row: " <<*pointerX << std::endl;
    previousItem = *(pLevel + *pointerX * mSize + *pointerY);
    std::cout << previousItem << " is what you landed on\n";
    *(pLevel + *pointerX * mSize + *pointerY) = 'H';
}

void Level::down() {
    std::cout << "down\n";
    *(pLevel + *pointerX * mSize + *pointerY) = ' ';
    *pointerX -= 1;
    if(*pointerX < 0){
        *pointerX = mSize-1;
    }
    std::cout << "Mario is at column "<< *pointerY << ", row: " <<*pointerX << std::endl;
    previousItem = *(pLevel + *pointerX * mSize + *pointerY);
    std::cout << previousItem << " is what you landed on\n";
    *(pLevel + *pointerX * mSize + *pointerY) = 'H';
}

void Level::left() {
    std::cout << "left\n";
    *(pLevel + *pointerX * mSize + *pointerY) = ' ';
    *pointerY += 1;
    if(*pointerY > mSize-1){
        *pointerY = 0;
    }
    std::cout << "Mario is at column "<< *pointerY << ", row: " <<*pointerX << std::endl;
    previousItem = *(pLevel + *pointerX * mSize + *pointerY);
    std::cout << previousItem << " is what you landed on\n";
    *(pLevel + *pointerX * mSize + *pointerY) = 'H';
}

void Level::right() {
    std::cout << "right\n";
    *(pLevel + *pointerX * mSize + *pointerY) = ' ';
    *pointerY -= 1;
    if(*pointerY < 0){
        *pointerY = mSize-1;
    }
    std::cout << "Mario is at column "<< *pointerY << ", row: " <<*pointerX << std::endl;
    previousItem = *(pLevel + *pointerX * mSize + *pointerY);
    std::cout << previousItem << " is what you landed on\n";
    *(pLevel + *pointerX * mSize + *pointerY) = 'H';
}

void Level::move() {
    int randomMovement = rand() % 4;
    if (randomMovement == 0) {
        up();
    } else if (randomMovement == 1) {
        down();
    } else if (randomMovement == 2) {
        left();
    } else if (randomMovement == 3) {
        right();
    }
}

void Level::printLevel() {
    for(int i = 0; i < mSize;  ++i) {
        for(int j = 0; j < mSize; ++j) {
            std::cout << *(pLevel + i * mSize + j) << " ";
        }
    std::cout << std::endl; 
    }
    std::cout << "\n";
}

std::string Level::indexLevel() {
    return *(pLevel + *pointerX * mSize + *pointerY);
}

void Level::clear() {
    *(pLevel + *pointerX * mSize + *pointerY) = ' ';
}

std::string Level::getPreviousItem(){
    return previousItem;
}
