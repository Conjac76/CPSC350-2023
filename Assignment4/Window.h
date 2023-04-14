#ifndef WINDOW_H
#define WINDOW_H
#include "Customer.h" 

class Window {
    public:
        Window();
        ~Window();
        int getIdleTime();
        bool getIdle();
        void setIdleTime(int idleTime);
        void setIdle(bool idle);
        void start(const Customer& customer, int waitTime);
    private:
        bool idle;
        int idleTime;
        Customer currentCustomer;
        int remainingTime = 0;
};

#endif