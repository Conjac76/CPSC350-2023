#ifndef WINDOW_H
#define WINDOW_H
#include "Customer.h" 

class Window {
    public:
        Window();
        ~Window();
        Window(const Window& rhs );
        Window & operator=(const Window& rhs );

        void setCurrentCustomer(Customer *pCurrrentCustomer);
        Customer* getCurrentCustomer();
        void resetWaitTime();
        void incrementWaitTime();
        int getWaitTime();
    private:
        Customer *mpCurrentCustomer;
        int mWaitTime;
};

#endif