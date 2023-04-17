#include "Customer.h"



Customer::Customer(int arrivalTime, char office1, int time1, char office2, int time2, char office3, int time3) :
    mArrivalTime(arrivalTime),
    mWaitTime(0),
    mOrderedTasks() {
    mOrderedTasks.insertBack(Task(office1, time1)); 
    mOrderedTasks.insertBack(Task(office2, time2)); 
    mOrderedTasks.insertBack(Task(office3, time3)); 
}

Customer::Customer() :
    mWaitTime(0),
    mArrivalTime(0),
    mOrderedTasks() {
}

Customer::Customer(const Customer& rhs) :
    mArrivalTime(rhs.mArrivalTime),
    mWaitTime(rhs.mWaitTime) {
    for(int i = 0; i < rhs.mOrderedTasks.getSize(); i++) {
        mOrderedTasks.insertBack(rhs.mOrderedTasks.getAt(i));
    }
}

Customer & Customer::operator=(const Customer& rhs ) {
    if(this == &rhs) {
        return *this;
    }
    mWaitTime = rhs.mWaitTime;
    mArrivalTime = rhs.mArrivalTime;
    for(int i = 0; i < rhs.mOrderedTasks.getSize(); i++) {
       mOrderedTasks.insertBack(rhs.mOrderedTasks.getAt(i));
    }
    return *this;
}

Customer::~Customer() {

}

void Customer::incrementWaitTime() {
    mWaitTime++;
}

void Customer::resetWaitTime() {
    mWaitTime = 0;
}
int Customer::getArrivalTime() {
    return mArrivalTime;
}

DblList<Task>& Customer::getOrderedTasks() {
    return mOrderedTasks;
}

int Customer::getWaitTime() {
    return mWaitTime;
}