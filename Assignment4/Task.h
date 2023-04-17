class Task {
    public: 
        Task(char office, int mTaskTime);
        Task(const Task& rhs );
        Task();
        Task & operator=(const Task& rhs );
        ~Task();
        char getOffice();
        int getTotalTime();
        int getRemainingTime();
        int getWaitTime();
        void decrementRemainingTime();
    private:
        char mOffice;
        int mTaskTime;
        int mRemainingTime;
        int mWaitTime;
};


