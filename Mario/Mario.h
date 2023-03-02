class Mario {
    public:
        Mario();
        ~Mario();
        Mario(int numofLives);
        bool isTwenty();
    private:
        int mNumOfLives;
        int mNumOfCoins; 
        int mPowerLevel; //up if contacts a mushie
                        //dont for enemey
};