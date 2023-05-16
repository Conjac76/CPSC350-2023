#include "IO.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>

IO::IO(std::string inputString) {
    mInputString = inputString;
}

void IO::processFile() {
    std::ifstream infile;
    try {
        infile.open(mInputString);
        if (!infile) {
            std::cout << "Error: failed to open file" << std::endl;
        } 

        std::string line;
        while (getline(infile, line)) {
            std::istringstream iss(line);
            double value;
            while (iss >> value) {
                unsortedDoubles.insertFront(value);
            }
        }
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

IO::~IO() {
    
}

DblList<double> IO::getUnsortedDoubles() {
    return unsortedDoubles;
}
