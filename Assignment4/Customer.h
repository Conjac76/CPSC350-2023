#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>

class Customer{
    public:
        Customer(int timeRegistar, int timeCashier, int timeFinacialAid, std::string order);
        ~Customer();
        int getTimeRegistar();
        int getTimeCashier();
        int getTimeFinancialAid();
        std::string getOrder();
        Customer();
    private:
        int mTimeRegistrar;
        int mTimeCashier;
        int mTimeFinacialAid;
        int mWaitTime;
        std::string mOrder;
};

#endif