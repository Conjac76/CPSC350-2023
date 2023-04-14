#include "Customer.h"


Customer::Customer(int timeRegistar, int timeCashier, int timeFinacialAid, std::string order) {
    mTimeCashier = timeCashier;
    mTimeFinacialAid = timeFinacialAid;
    mTimeRegistrar = timeRegistar;
    mOrder = order;
    mWaitTime = 0;
}

int Customer::getTimeFinancialAid() {
    return mTimeFinacialAid;
}

int Customer::getTimeCashier() {
    return mTimeCashier;
}

int Customer::getTimeRegistar() {
    return mTimeRegistrar;
}

std::string Customer::getOrder() {
    return mOrder;
}

Customer::~Customer() {

}

Customer::Customer() {

}