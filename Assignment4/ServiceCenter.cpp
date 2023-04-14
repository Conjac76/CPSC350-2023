#include "ServiceCenter.h"

ServiceCenter::ServiceCenter(int windowsRegistrar, int windowsFinancialAid, int windowsCashier) {
    Office registar(windowsRegistrar);
    Office financialAid(windowsFinancialAid);
    Office cashier(windowsCashier);
    ListQueue<Customer> registarQueue;
    ListQueue<Customer> financialQueue;
    ListQueue<Customer> cashierQueue;

}

ServiceCenter::~ServiceCenter() {

}

void ServiceCenter::Game() {
    
}