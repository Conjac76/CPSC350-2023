#include "Interaction.h"
#include <iostream>
#include "Mario.h"
#include "Level.h"
#include "World.h"
#include <cstdlib>


Interaction::Interaction() {

}

Interaction::~Interaction() {

}

int Interaction::interact(Level level, Mario mario) {
    numOfMoves = 0;
    numOfEnemiesDefeated = 0;
    std::string item;
    item = level.getPreviousItem();
    if(item == "x") {
        level.move();
        numOfMoves += 1;
        return 1;
    } else if (item == "c") {
        mario.isTwenty();
        level.move();
        numOfMoves += 1;
        std::cout << "Mario collected a coin\n";
        return 1;
    } else if (item == "m") {
        mario.setPowerLevel(1);
        level.move();
        numOfMoves += 1;
        std::cout << "Mario ate a mushroom\n";
        return 1;
    } else if (item == "g") {
        int random = rand() % 5;
        if(random < 3) {
            level.clear();
            numOfEnemiesDefeated += 1;
            checkNumOfEnemiesDefeated(mario);
            level.move();
            numOfMoves += 1;
            std::cout << "Mario fought a Goomba and won\n";
            return 1;
        } else {
            mario.setPowerLevel(-1);
            if(mario.getPowerLevel() <= 0) {
                std::cout << "Mario fought a Goomba and lost the whole game\n because powerlevel = 0\n";
                numOfMoves += 1;
                return 2;
            } else {
                level.move();
                numOfMoves += 1;
                std::cout << "Mario fought a Goomba and lost\n";
                return 1;
            }
        }
    } else if (item == "k") {
        int random  = rand() % 20;
        if(random < 13) {
            level.clear();
            checkNumOfEnemiesDefeated(mario);
            level.move();
            numOfMoves += 1;
            std::cout << "Mario fought a Koopa and won\n";
            return 1;
        } else {
            mario.setPowerLevel(-1);
            if(mario.getPowerLevel() <= 0) {
                std::cout << "Mario fought a Koopa and lost the whole game\n because power level = 0\n";
                numOfMoves += 1;
                return 2;
            } else {
                level.move();
                numOfMoves += 1;
                std::cout << "Mario fought a Koopa and lost\n";
                return 1;
            }
        }
    } else if (item == "b") {
        int random = rand() % 1;
        if(random > 0){
            numOfMoves += 1;
            level.clear();
            std::cout << "Mario fought the level boss and won\n";
            return 3;
        } else if (mario.getPowerLevel() == 2) {
            mario.setPowerLevel(-2);
            if(mario.getPowerLevel() >= 0) {
                int random2 = rand() % 1;
                if(random2 > 0){
                    level.clear();
                    numOfMoves += 1;
                    std::cout << "Mario fought the level boss and won\n";
                    return 3;
                }
                else {
                    std::cout << "Mario fought the level boss and lost\n";
                    numOfMoves += 1;
                    return 2;
                }
            }
        } else {
            std::cout << "Mario fought the level boss and lost\n";
            numOfMoves += 1;
            return 2;
        }
    } else if (item == "w") {
        numOfMoves += 1;
        std::cout << "Mario warped.\n";
        return 3;
    } else {
        level.printLevel();
        std::cout << "The position is empty\n";
        return 0;
    }
}
void Interaction::checkNumOfEnemiesDefeated(Mario mario) {
    if(numOfEnemiesDefeated % 7 == 0) {
        mario.setLives(1);
    }
}