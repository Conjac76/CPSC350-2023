#include "Mario.h"
#include "World.h"
#include <iostream>

Mario::Mario() {

}

Mario::~Mario() {
}

Mario::Mario(int numOfLives){
    mNumOfLives = numOfLives;
    mNumOfCoins = 0;
    mPowerLevel = 0;
}

void Mario::isTwenty() {
    if(mNumOfCoins == 19) {
        mNumOfLives += 1;
        mNumOfCoins = 0;
    } else {
        mNumOfCoins +=1;
    }
}


void Mario::setLives(int lives) {
    mNumOfLives += lives;
}

int Mario::getNumOfLives() {
    return mNumOfLives;
}

void Mario::setPowerLevel(int powerLevel) {
    if(mPowerLevel <= 2) {
        mPowerLevel += powerLevel; 
    }
}
int Mario::getPowerLevel() {
    return mPowerLevel;
}