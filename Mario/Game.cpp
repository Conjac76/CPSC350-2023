#include <cstdlib>
#include <ostream>
#include "Game.h"
#include <fstream>

Game::~Game() {
    
}

Game::Game(std::string file, std::string outputFile) {
    std::string fileString;
    std::ifstream MyReadFile(file);
    int numberOfLevels = 2;
    int gridSize = 5;
    int numberOfLives = 3;
    int percentCoins = 20;
    int percentNothing = 20;
    int percentGoomba = 20;
    int percentKoopa = 20;
    int percentMushroom = 20;
    int counter = 0;
    int keepLevel = 0;

    // Open passed in file if not empty.
    std::ofstream passedInOutputFile;
    if (outputFile.empty() == false) {
        passedInOutputFile.open(outputFile);
    }
    // print to output file if there is one, otherwise print std::cout for lack of a 
    // better alternative.
    // Use a reference to avoid any craziness with assignment operator and avoiding pointers.
    std::ostream &outputStream = passedInOutputFile.is_open()? passedInOutputFile : std::cout;

    while ( getline(MyReadFile, fileString)) {
        if(counter == 0) {
            numberOfLevels = stoi(fileString);
            counter++;
        } else if(counter == 1) {
            gridSize = stoi(fileString);
            counter++;
        } else if(counter == 2) {
            numberOfLives = stoi(fileString);
            counter++;
        } else if(counter == 3) {
            percentCoins = stoi(fileString);
            counter++;
        } else if(counter == 4) {
            counter++;
            percentNothing = stoi(fileString);
        } else if(counter == 5) {
            counter++;
            percentGoomba = stoi(fileString);
        } else if(counter == 6) {
            counter++;
            percentKoopa = stoi(fileString);
        } else if(counter == 7) {
            counter++;
            percentMushroom = stoi(fileString);
        }
        
    }
    
    //replace with numbers from input file
    srand(time(NULL));
    World world(numberOfLevels, gridSize, percentCoins, percentNothing, percentGoomba, percentKoopa, percentMushroom);
    Mario mario(numberOfLives);
    std::string pause;
    // Start Mario on level 0 and random location.
    mario.start(world);

    // The game goes while Mario dies or rescues the princess.
    while(mario.isAlive() == true && mario.hasPrincess(world) == false) {   
        outputStream << "Level: " << mario.getCurrentLevel() << std::endl;
        mario.printCoords(outputStream);
        outputStream << "Power Level: " << mario.getPowerLevel() << std::endl;
        MarioDirection direction = mario.takeAction(outputStream, world);
        outputStream << "Number of lives: " << mario.getNumOfLives() << std::endl;
        outputStream << "Number of Coins: " << mario.getNumOfCoins() << std::endl;
        if(direction == 0) {
            outputStream<< "up\n";
        } else if (direction == 1) {
            outputStream << "down\n";
        } else if (direction == 2) {
            outputStream << "left\n";
        } else if (direction == 3) {
            outputStream << "right\n";
        } else if (direction == 4) {
            outputStream << "stay put\n";
        } 
        if(mario.getCurrentLevel() != numberOfLevels)
        mario.printLevel(outputStream, world);
        mario.move(world, direction);
    }
    
    if(mario.isAlive() == false) {
        outputStream << "it took " << mario.getNumOfMoves() << " turns to lose\n";
    } else {
        outputStream << "it took " << mario.getNumOfMoves() << " turns to win\n";
    }
}