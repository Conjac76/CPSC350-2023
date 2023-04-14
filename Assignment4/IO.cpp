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
                    serviceCenter = ServiceCenter(mWindowsRegistar, mWindowsFincialAid, mWindowsCashier);
                } else if (counter == 3) {
                    mClockTick = mychar - zero;
                    std::cout << mClockTick << std::endl;
                } else if (counter == 4) {
                    mNumStudents = mychar - zero;
                    std::cout << mNumStudents << std::endl;
                    //Outer loop for each Student.
                    for(int i = 0; i < mNumStudents; i++) {
                        int regTime, cashierTime, aidTime;
                        myfile >> regTime >> cashierTime >> aidTime >> order[0] >> order[1] >> order[2];
                        orderString += order[0];
                        orderString += order[1];
                        orderString += order[2];
                        //Inner loop for the information about student.
                        for(int j = 0; j < 3; j++) {
                            std::cout << order[j];
                        }
                        if(order[0] == 'R') {
                            if(order[1] == 'C') {
                                //Order is RCF
                                serviceCenter.addCustomer(Customer(regTime, cashierTime, aidTime, orderString));
                            } else if(order[1] == 'F') {
                                //Order is RFC
                                Customer(regTime, aidTime, cashierTime, orderString);
                            }   
                        } else if(order[0] == 'C') {
                            if(order[1] == 'F') {
                                //Order is CFR
                                Customer(cashierTime, aidTime, regTime, orderString);
                            } else if(order[1] == 'R') {
                                //Order is CRF
                                Customer(cashierTime, regTime, aidTime, orderString);
                            }
                        } else if(order[0] == 'F') {
                            if(order[1] == 'C') {
                                //Order is FCR
                                Customer(aidTime, cashierTime, regTime, orderString);
                            } else if(order[1] == 'R') {
                                //Order is FRC
                                Customer(aidTime, regTime, cashierTime, orderString);
                            }
                        }
                    }
                    std::cout << std::endl;
                    counter = 2;
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
