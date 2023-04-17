#include "ServiceCenter.h"
#include <iostream>

ServiceCenter::ServiceCenter() {

}

ServiceCenter::ServiceCenter(int windowsRegistrar, int windowsFinancialAid, int windowsCashier) :
    mRegistrar(windowsRegistrar), 
    mFinancialAid(windowsFinancialAid),
    mCashier(windowsCashier) {
}
ServiceCenter::ServiceCenter(const ServiceCenter& rhs) : 
    mRegistrar(rhs.mRegistrar), 
    mFinancialAid(rhs.mFinancialAid),
    mCashier(rhs.mCashier)
{}

ServiceCenter& ServiceCenter::operator = (const ServiceCenter& rhs) {
    if(this == &rhs) {
        return *this;
    }

    mCashier = rhs.mCashier;
    mFinancialAid = rhs.mFinancialAid;
    mRegistrar = rhs.mRegistrar;

    return *this;
    
}

ServiceCenter::~ServiceCenter() {
}

void ServiceCenter::addCustomer(Customer *pCustomer) {
    if(pCustomer->getOrderedTasks().getSize() > 0) {
        if(pCustomer->getOrderedTasks().getAt(0).getOffice() == 'R') {
            mRegistrar.addCustomer(pCustomer);
        } else if(pCustomer->getOrderedTasks().getAt(0).getOffice() == 'C') {
            mCashier.addCustomer(pCustomer);
        } else if(pCustomer->getOrderedTasks().getAt(0).getOffice() == 'F') {
            mFinancialAid.addCustomer(pCustomer);
        }
    } 
}

void ServiceCenter::runOneMinute(int minutes) {
    // run each office in alphabetical order, then re-add the customers to the next office.
    DblList<Customer *> cashierFinishedList = mCashier.runOneMinute(minutes);
    DblList<Customer *> financialFinishedList = mFinancialAid.runOneMinute(minutes);
    DblList<Customer *> registrarFinishedList = mRegistrar.runOneMinute(minutes);

    for (int i = 0; i < cashierFinishedList.getSize(); i++) {
        addCustomer(cashierFinishedList.getAt(i));
    }
    for (int i = 0; i < financialFinishedList.getSize(); i++) {
        addCustomer(financialFinishedList.getAt(i));
    }
    for (int i = 0; i < registrarFinishedList.getSize(); i++) {
        addCustomer(registrarFinishedList.getAt(i));
    }
}

bool ServiceCenter::hasCustomers() {
    bool hasCustomers =  mCashier.hasCustomers()|| mFinancialAid.hasCustomers()|| mRegistrar.hasCustomers();
    return hasCustomers;
}

void ServiceCenter::printStats() {
    std::cout << "\nREGISTRAR\n";
    std::cout << "\tMean Wait Time: " << mRegistrar.getMeanWaitTime() << std::endl;
    std::cout << "\tLongest Student Wait Time: " << mRegistrar.getMaxWaitTime() << std::endl;
    std::cout << "\tAverage Window Idle Time: " << mRegistrar.getMeanIdleTime() << std::endl;
    std::cout << "\nCASHIER\n";
    std::cout << "\tMean Wait Time: " << mCashier.getMeanWaitTime() << std::endl;
    std::cout << "\tLongest Student Wait Time: " << mCashier.getMaxWaitTime() << std::endl;
    std::cout << "\tAverage Window Idle Time: " << mCashier.getMeanIdleTime() << std::endl;
    std::cout << "\nFINANCIAL AID\n";
    std::cout << "\tMean Wait Time: " << mFinancialAid.getMeanWaitTime() << std::endl;
    std::cout << "\tLongest Student Wait Time: " << mFinancialAid.getMaxWaitTime() << std::endl;
    std::cout << "\tAverage Window Idle Time: " << mFinancialAid.getMeanIdleTime() << std::endl;
    std::cout << "Accross all offices: " << std::endl;
    std::cout << "\tStudents waiting longer than 10 minutes: " << mFinancialAid.getLongerThanTen()+mCashier.getLongerThanTen()+mRegistrar.getLongerThanTen() << std::endl;

}

