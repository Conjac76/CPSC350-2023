#ifndef IO_H
#define IO_H
#include <string>

#include "ServiceCenter.h"
#include "Customer.h"
#include "Office.h"

class IO {
    public:
        IO(std::string inputFile);
        ~IO();
        int getWindowsRegistar();
        int getWindowsCashier();
        int getWindowsFincialAid();
        int getClockTick();
        int getNumStudents();
        std::string getStudentOrder();
    private:
        ServiceCenter serviceCenter;
        IO();
        int mWindowsRegistar;
        int mWindowsCashier;
        int mWindowsFincialAid;
        int mClockTick;
        int mNumStudents;
        char order[3];
        std::string orderString;
};

#endif