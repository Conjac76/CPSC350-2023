#ifndef INTERACTION_H
#define INTERACTION_H
#include "Level.h"
#include "Mario.h"

class Interaction {
    public:
        Interaction();
        ~Interaction();
        int interact(Level level, Mario mario);
        int numOfMoves;
        int numOfEnemiesDefeated;
        void checkNumOfEnemiesDefeated(Mario mario);
};

#endif
