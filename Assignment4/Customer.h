#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>

class Customer{
    public:
        Customer(int timeRegistar, int timeCashier, int timeFinacialAid);
        ~Customer();
    private:
        int mTimeRegistrar;
        int mTimeCashier;
        int mTimeFinacialAid;
        int mWaitTime;
        Customer();
};

#endif