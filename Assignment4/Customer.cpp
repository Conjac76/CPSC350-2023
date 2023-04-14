#include "Customer.h"


Customer::Customer(int timeRegistar, int timeCashier, int timeFinacialAid) {
    mTimeCashier = timeCashier;
    mTimeFinacialAid = timeFinacialAid;
    mTimeRegistrar = timeRegistar;
    mWaitTime = 0;
}

Customer::~Customer() {

}

Customer::Customer() {

}