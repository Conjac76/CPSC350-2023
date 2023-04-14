#include "ServiceCenter.h"

ServiceCenter::ServiceCenter() {}

ServiceCenter::ServiceCenter(int windowsRegistrar, int windowsFinancialAid, int windowsCashier) {
    Office registar(windowsRegistrar);
    Office financialAid(windowsFinancialAid);
    Office cashier(windowsCashier);
}

void ServiceCenter::addCustomer(Customer c) {
    std::string orderString = c.getOrder();
    if(orderString[0] == 'R') {
        //registarQueue.enqueue(c);
    } else if(orderString[0] == 'C') {
        //
    } else if(orderString[0] == 'F') {
        //
    }
}

ServiceCenter::~ServiceCenter() {

}

void ServiceCenter::Game() {
    
}