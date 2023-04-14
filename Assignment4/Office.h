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
        Office();
        int mNumWindow;
        ListQueue<Customer> queue;
        DblList<Window> windows;

};

#endif