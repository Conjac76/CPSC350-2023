#include "IO.h"
#include <iostream>
#include <fstream>

IO::IO(std::string inputFile) {
    std::ifstream myfile;
    myfile.open(inputFile);
    char mychar;
    int counter = 0;
    char zero = '0';
    if(myfile.is_open()) {
        while(myfile) {
            mychar = myfile.get();
            if(mychar >= '0' && mychar <= '9') {
                if(mychar == '\n') {
                    continue;
                }
                if(counter == 0) {
                    mWindowsRegistar = mychar - zero;
                    std::cout << mWindowsRegistar << std::endl;
                } else if (counter == 1) {
                    mWindowsCashier = mychar - zero;
                    std::cout << mWindowsCashier << std::endl;                   
                } else if (counter == 2) {
                    mWindowsFincialAid = mychar - zero;
                    std::cout << mWindowsFincialAid << std::endl;
                } else if (counter == 3) {
                    mClockTick = mychar - zero;
                    std::cout << mClockTick << std::endl;
                } else if (counter == 4) {
                    mNumStudents = mychar - zero;
                    std::cout << mNumStudents << std::endl;
                } else if (counter == 5) {
                    if(mychar == '\n') {
                        std::cout << "End of student info" << std::endl;
                    } else {
                        std::cout << mychar << std::endl;
                    }
                    for(int i = 0; i < mNumStudents; i++) {
                        int regTime, cashierTime, aidTime;
                        char regChar, cashierChar, aidChar;
                        myfile >> regTime >> cashierTime >> aidTime;
                        std::cout << "Student " << i+1 << " info: " << regTime << cashierTime << aidTime << std::endl;
                    }
                }
                counter++;
            }
        }
    }
}

IO::~IO() {

}

int IO::getWindowsRegistar() {
    return mWindowsRegistar;
}

int IO::getWindowsCashier() {
    return mWindowsCashier;
}

int IO::getWindowsFincialAid() {
    return mWindowsFincialAid;
}

int IO::getNumStudents() {
    return mNumStudents;
}

int IO::getClockTick() {
    return mClockTick;
}
