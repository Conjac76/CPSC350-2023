#ifndef OFFICE_H
#define OFFICE_H
#include "Window.h"
#include "ListQueue.h"
#include "DblList.h"

class Office {
    public:
        Office(int numWindows);
        ~Office();
    private:
        int totalWaitTime = 0;
        int totalIdleTime = 0;
        int numCustomersServed = 0;
        Office();
        int mNumWindow;
        ListQueue<Customer> customerQueue;
        DblList<Window> windows;

};

#endif