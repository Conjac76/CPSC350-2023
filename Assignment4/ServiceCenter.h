#ifndef SERVICECENTER_H
#define SERVICECENTER_H
#include "Office.h"
#include "Window.h"
#include "Customer.h"
#include "ListQueue.h"

class ServiceCenter {
    public:
        ServiceCenter(int windowsRegistrar, int windowsFinancialAid, int windowsCashier);
        ~ServiceCenter();
        ServiceCenter();
        ServiceCenter(const ServiceCenter& rhs );
        ServiceCenter & operator=(const ServiceCenter& rhs );
        void addCustomer(Customer *pCustomer);
        void runOneMinute(int minutes);
        bool hasCustomers();
        void printStats();

    private:
        Office mRegistrar;
        Office mFinancialAid;
        Office mCashier;

};

#endif