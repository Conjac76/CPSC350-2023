#ifndef MARIO_H
#define MARIO_H

#include <ostream>
#include "World.h"

 enum MarioDirection {
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3,
    STAY_PUT = 4
};
class Mario {
    public:
       

        Mario();
        ~Mario();
        Mario(int numofLives);
        void isTwenty();
        void setCoins(int coins);
        void setPowerLevel(int powerLevel);
        void setLives(int lives);
        int getPowerLevel();
        int getNumOfLives();
        int getNumOfMoves();
        bool isAlive();
        bool hasPrincess(World &World);
        void move(World &world, MarioDirection direction);
        MarioDirection takeAction(std::ostream &outputStream, World &world);
        MarioDirection getRandomDirection();
        void start(World &world);
        void printCoords(std::ostream &outputStream);
        int getNumOfCoins();
        int getCurrentLevel();
        void getCurrentCol();
        void getCurrentRow();
        void printLevel(std::ostream &outputStream, World &world);
    private:
        void incrementNumOfEnemiesDefeated();
        void incrementPowerLevel();
        void decrementPowerLevel();  
        void decrementBossPowerLevel();
        void incrementCurrentLevel();
        int mNumOfLives;
        int mNumOfCoins; 
        int mPowerLevel;
        int mCurrentLevel;
        int mCurrentRow;
        int mCurrentCol;
        int mNumOfMoves;
        int mNumOfEnemiesDefeated;      
};

#endif

