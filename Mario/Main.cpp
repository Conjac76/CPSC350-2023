#include "World.h"
#include "Mario.h"
#include "Game.h"
#include <iostream>


int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "Usage: main <inputfile> <outputfile>\n";
        exit(-1);
    }
    std::string charInputFileName(argv[1]);
    std::string charOutputFileName(argv[2]);
    Game game(charInputFileName, charOutputFileName);
    
}