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

bool Mario::isTwenty() {
    if(mNumOfCoins == 19) {
        mNumOfLives += 1;
        mNumOfCoins = 0;
        return true;
    } else {
        return false;
    }
}