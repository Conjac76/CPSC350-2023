#ifndef LEVEL_H
#define LEVEL_H


class World {
    public:
        ~World();
    
        World(int numberOfLevels, int gridSize, int percentCoins, int percentNothing, int percentGoombas, int percentKoopas, int percentMushrooms);
        int getNumOfLevels();
        char getAt(int level, int row, int col);
        void setAt(int level, int row, int col, char c);
        void printLevel(int level);
        void printWorld();
        int getGridSize();

    private:
        // Private default constructor we don't use it.
        World();
        // Private copy constructor so that the pointer doesn't get copied by accident to a new World.
        World(const World & world);
        // Private assignment operator so that the pointer doesn't get copied by accident to a new World.
        World & operator=(const World & world);
        

    private:
        char *mpWorldMap;
        int mNumOfLevels;
        int mGrideSize;
};

#endif