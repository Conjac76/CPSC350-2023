
class World {
    public:
        World();
        ~World();
        World(int level);
        int getNumOfLevels();
        void setNumOfLevels(int level);
    private:
        int mLevel;
};
