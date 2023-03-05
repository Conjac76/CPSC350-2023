#include "World.h"
#include "Mario.h"
#include "Level.h"
#include "Interaction.h"
#include <iostream>

int main() {
    World world(2);
    Mario mario(3);
    int marioStatus = 0;
    int looseFlag = 0;
    int levelsCompleted = 0;
    while(looseFlag != 1 && world.getNumOfLevels() >= 0 && mario.getNumOfLives() >= 0){
        levelsCompleted += 1;
        std::cout << "Level# " << levelsCompleted << std::endl;
        std::cout << "loose flag is: " << looseFlag << std::endl;
        Level level(5, 20, 20, 20, 20, 20);
        std::cout << level.getPreviousItem() << " is what you landed on\n";
        while(marioStatus != 3) {
            Interaction interaction;
            std::cout << "Level# " << levelsCompleted << std::endl;
            marioStatus = interaction.interact(level, mario);
            level.printLevel();
            std::cout << "Marios power Level: " << mario.getPowerLevel() << "\n";
            if(marioStatus == 1) {
                int helloworld;
                std::cin >> helloworld;
            } else if(marioStatus == 2) {
                looseFlag = 1;
                break;
            } else if(marioStatus == 3) {
                std::cout << "next level";
                world.setNumOfLevels(-1);
                break;
            }
        }
    }
}