class Level {
    public:
        Level();
        ~Level();
        Level(int size);
        void up();
        void down();
        void left();
        void right();
    private:
        int mSize;
        int marioCoordX;
        int marioCoordY;
};