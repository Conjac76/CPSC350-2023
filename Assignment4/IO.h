#ifndef IO_H
#define IO_H
#include <string>

class IO {
    public:
        IO(std::string inputFile);
        ~IO();
        int getWindowsRegistar();
        int getWindowsCashier();
        int getWindowsFincialAid();
        int getClockTick();
        int getNumStudents();
    private:
        IO();
        int mWindowsRegistar;
        int mWindowsCashier;
        int mWindowsFincialAid;
        int mClockTick;
        int mNumStudents;
};

#endif