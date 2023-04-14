#ifndef SERVICECENTER_H
#define SERVICECENTER_H
#include "Office.h"
#include "Window.h"
#include "Customer.h"
#include "ListQueue.h"

class ServiceCenter {
    public:
        ServiceCenter(int windowsRegistrar, int windowsFinancialAid, int windowsCashier);
        ServiceCenter();
        ~ServiceCenter();
        void Game();

    private:
        int mClockTick;

};

#endif