
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Mario.h"
#include "World.h"


Mario::Mario() {

}

Mario::~Mario() {
}

Mario::Mario(int numOfLives){
    mNumOfLives = numOfLives;
    mNumOfCoins = 0;
    mPowerLevel = 0;
    mCurrentLevel = 0;
    mCurrentRow = 0;
    mCurrentCol = 0;
    mNumOfMoves = 0;
    mNumOfEnemiesDefeated = 0;

}



void Mario::isTwenty() {
    if(mNumOfCoins == 19) {
        mNumOfLives += 1;
        mNumOfCoins = 0;
    } else {
        mNumOfCoins +=1;
    }
}

void Mario::printLevel(std::ostream &outputStream,World &world){
    for(int i = 0; i < world.getGridSize(); ++i) {
        for(int j = 0; j < world.getGridSize(); ++j) {
            if(i == mCurrentRow && j == mCurrentCol) {
                outputStream << "H ";
            } else { 
                outputStream << world.getAt(mCurrentLevel, i, j) << ' ';
            }
        }
        outputStream << std::endl;
    }
    outputStream << "\n";
}


void Mario::setLives(int lives) {
    mNumOfLives += lives;
}

int Mario::getNumOfLives() {
    return mNumOfLives;
}

int Mario::getNumOfMoves() {
    return mNumOfMoves;
}

void Mario::setPowerLevel(int powerLevel) {
    mPowerLevel = powerLevel; 
}
int Mario::getPowerLevel() {
    return mPowerLevel;
}

int Mario::getNumOfCoins() {
    return mNumOfCoins;
}

bool Mario::isAlive() {
    if(mNumOfLives <= 0) {
        return false;
    } else {
        return true;
    }
}

void Mario::printCoords(std::ostream &outputStream) {
    outputStream << "Hero Location row:" << mCurrentRow << ", col:" << mCurrentCol << std::endl;
}


bool Mario::hasPrincess(World & world) {
    // The only way to get past the last level is to save the princess.
    if(mCurrentLevel >= world.getNumOfLevels()){
        return true;
    } else {
        return false;
    }
}

void Mario::incrementNumOfEnemiesDefeated() {
    mNumOfEnemiesDefeated += 1;
    if(mNumOfEnemiesDefeated % 7 == 0) {
        mNumOfLives += 1;
    }
}

void Mario::start(World &world) {
    mCurrentCol = rand() % world.getGridSize();
    mCurrentRow = rand() % world.getGridSize();

    //takeAction(world);
}

void Mario::move(World &world, MarioDirection direction) {
    if(direction == UP) {
        mCurrentRow -= 1;
        if(mCurrentRow < 0) {
            mCurrentRow = world.getGridSize()-1;
        }
    } else if(direction == DOWN) {
        mCurrentRow += 1;
        if(mCurrentRow > world.getGridSize()-1) {
            mCurrentRow = 0;
        }
    } else if(direction == LEFT) {
        mCurrentCol -= 1;
        if(mCurrentCol < 0) {
            mCurrentCol = world.getGridSize()-1;
        }
    } else if(direction == RIGHT) {
        mCurrentCol += 1;
        if(mCurrentCol > world.getGridSize()-1) {
            mCurrentCol = 0;
        }
    }
}
MarioDirection Mario::getRandomDirection() {
    //srand(time(NULL));
    int random = rand() % 4;
    MarioDirection d = STAY_PUT;
    switch (random) {
        case 0: 
            d =  UP;
            break;
        case 1:
            d = DOWN;
            break;
        case 2:
            d = LEFT;
            break;
        case 3: 
            d = RIGHT;
            break;
        case 4:
            d =  STAY_PUT;
            break;
    }
    return d;
}

MarioDirection Mario::takeAction(std::ostream &outputStream, World &world) {
    char item = world.getAt(mCurrentLevel, mCurrentRow, mCurrentCol);
    // 'x' is nothing
    mNumOfMoves += 1;
    if(item == 'x') {
        outputStream << "The position is empty\n";
        return getRandomDirection();
    // 'c' is a coin
    } else if (item == 'c') {
        isTwenty();
        outputStream << "Mario collected a coin\n";
        world.setAt(mCurrentLevel, mCurrentRow, mCurrentCol,'x');
        return getRandomDirection();
    // 'm' is a mushroom
    } else if (item == 'm') {
        incrementPowerLevel();
        outputStream << "Mario ate a mushroom\n";
        world.setAt(mCurrentLevel, mCurrentRow, mCurrentCol,'x');
       return getRandomDirection();
    // 'g' is a goomba
    } else if (item == 'g') {
        int random = rand() % 100 + 1 ;
        if(random <= 80) {
            incrementNumOfEnemiesDefeated();
            outputStream << "Mario fought a Goomba and won\n";
            world.setAt(mCurrentLevel, mCurrentRow, mCurrentCol,'x');
            return getRandomDirection();
        } else {
            if(mPowerLevel == 0) {
                outputStream << "Mario fought a Goomba and lost a life \n";
                decrementPowerLevel(); // this will take away a life.
                return STAY_PUT;
            }
            outputStream << "Mario fought a Goomba and lost\n";
            decrementPowerLevel();
            return getRandomDirection();
        }
        return getRandomDirection();
    } else if (item == 'k') {
        int random = rand() % 100 + 1 ;
        if(random <= 65) {
            incrementNumOfEnemiesDefeated();
            outputStream << "Mario fought a Koopa and won\n";
            world.setAt(mCurrentLevel, mCurrentRow, mCurrentCol,'x');
            return getRandomDirection();
        } else {
            if(mPowerLevel == 0) {
                outputStream << "Mario fought a Koopa and lost a life \n";
                decrementPowerLevel(); // this will take away a life.
                return STAY_PUT;
            }
            outputStream << "Mario fought a Koopa and lost\n";
            decrementPowerLevel();
            return getRandomDirection();
        }
    } else if (item == 'b') {
        int random = rand() % 100+1;
        // Winning 50% of the time.
        if(random <= 50){
            world.setAt(mCurrentLevel, mCurrentRow, mCurrentCol, 'x');
            outputStream << "Mario fought the level boss and won\n";
            // Note: Princess is recsued (see hasPrincess()) if current level is >= than world.getNumOfLevels()
            incrementCurrentLevel();
            start(world);
            return STAY_PUT;
        // Losing 50% of the time.
        } else {
            decrementBossPowerLevel();
            // Note, game will exit if Mario has no more lives.
            return STAY_PUT;
        }
    } else if (item == 'w') {
        outputStream << "Mario warped.\n";
        incrementCurrentLevel();
        start(world);
        return STAY_PUT;
    // Should never happen, but if it does just keep going.
    } else {
        return getRandomDirection();
    }
}

void Mario::incrementPowerLevel() {
    if (mPowerLevel < 2) {
     mPowerLevel ++;
    }
}

void Mario::decrementPowerLevel() {
    if (mPowerLevel == 0) {
        mNumOfLives--;
    } else {
        mPowerLevel--;
    }
}

void Mario::decrementBossPowerLevel() {
    if (mPowerLevel <= 1) {
        mNumOfLives--;
        mPowerLevel = 0;
    } else {
        mPowerLevel -= 2;
    }
}

void Mario::incrementCurrentLevel() {
    mCurrentLevel +=1;
}

int Mario::getCurrentLevel() {
    return mCurrentLevel;
}

