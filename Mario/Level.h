#ifndef LEVEL_H
#define LEVEL_H
#include <string>
class Level {
    public:
        Level();
        ~Level();
        Level(int size, int percentCoins, int percentKoopas, int percentGoombas, int percentNothing, int percentMushrooms);
        void up();
        void down();
        void left();
        void right();
        void move();
        void clear();
        std::string indexLevel();
        std::string getPreviousItem();
        void printLevel();
    private:
        int mSize;
        int marioCoordX;
        int marioCoordY;
        std::string previousItem;
        void clearSpace();
        std::string *pLevel;
        int mPercentCoins;
        int mPercentNothing;
        int mPercentGoombas;
        int mPercentKoopas;
        int* pointerX;
        int* pointerY;


};
#endif