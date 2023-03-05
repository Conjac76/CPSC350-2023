#ifndef MARIO_H
#define MARIO_H
class Mario {
    public:
        Mario();
        ~Mario();
        Mario(int numofLives);
        void isTwenty();
        void setCoins(int coins);
        void setPowerLevel(int powerLevel);
        void setLives(int lives);
        int getPowerLevel();
        int getNumOfLives();
    private:
        int mNumOfLives;
        int mNumOfCoins; 
        int mPowerLevel;                  
};

#endif

