#include "Office.h"

Office::Office() : 
    mWindows(),
    mCustomerQueue(),
    mTotalOfficeVisits(0),
    mTotalWaitTime(0),
    mMaxWaitTime(0),
    mNumStudentsLongerThanTen(0),
    mTotalIdleTime(0),
    mMaxIdleTime(0),
    mNumIdleOverFive(0) {
}
    

Office::Office(int numWindows) : 
    mWindows(),
    mCustomerQueue(),
    mTotalOfficeVisits(0),
    mTotalWaitTime(0),
    mMaxWaitTime(0),
    mNumStudentsLongerThanTen(0),
    mTotalIdleTime(0),
    mMaxIdleTime(0),
    mNumIdleOverFive(0) {
      for(int i = 0; i < numWindows; ++i) {
        //Windows is a DoublyLinkedList.
        mWindows.insertBack(Window());
    }
}

Office::Office (const Office& rhs) :
    mWindows(rhs.mWindows),
    mCustomerQueue(rhs.mCustomerQueue),
    mTotalOfficeVisits(rhs.mTotalOfficeVisits),
    mTotalWaitTime(rhs.mTotalWaitTime),
    mMaxWaitTime(rhs.mMaxWaitTime),
    mNumStudentsLongerThanTen(rhs.mNumStudentsLongerThanTen),
    mTotalIdleTime(rhs.mTotalIdleTime),
    mMaxIdleTime(rhs.mMaxIdleTime),
    mNumIdleOverFive(rhs.mNumIdleOverFive) {
}

Office & Office::operator=(const Office& rhs)  { 
    if(this == &rhs) {
        return *this;
    } 
    mTotalOfficeVisits = rhs.mTotalOfficeVisits;
    mTotalWaitTime = rhs.mTotalWaitTime;
    mWindows = rhs.mWindows;
    mCustomerQueue = rhs.mCustomerQueue;
    mMaxWaitTime = rhs.mMaxWaitTime;
    mNumStudentsLongerThanTen = rhs.mNumStudentsLongerThanTen;
    mTotalIdleTime = rhs.mTotalIdleTime;
    mNumIdleOverFive = rhs.mNumIdleOverFive;
  
    return *this;
}

Office::~Office() {
}

void Office::addCustomer(Customer *pCustomer) {
    mCustomerQueue.enqueue(pCustomer);
}

int Office::lengthCustomerQueue() {
    return mCustomerQueue.getSize();
}

int Office::hasCustomers() {
    for(int i = 0; i < mWindows.getSize(); i++) {
        if (mWindows[i].getCurrentCustomer() != NULL) {
            return true;
        }
    }
    return mCustomerQueue.getSize() > 0;
}

DblList<Customer *> Office::runOneMinute(int minutes) {
    // Add customer from queue to empty windows.
    for (int i = 0; i<mWindows.getSize(); i++) {
        if (mWindows.getAt(i).getCurrentCustomer() == NULL) {
            if (mCustomerQueue.isEmpty() == false) {
                Customer *pCustomer = mCustomerQueue.dequeue();
                mWindows.getAt(i).setCurrentCustomer(pCustomer);
                mTotalIdleTime += mWindows.getAt(i).getWaitTime();
                mTotalWaitTime += pCustomer->getWaitTime();
                if(mMaxWaitTime < pCustomer->getWaitTime()) {
                    mMaxWaitTime = pCustomer->getWaitTime();
                }
                if(pCustomer->getWaitTime() >= 10) {
                    mNumStudentsLongerThanTen++;
                }
                if(mMaxIdleTime < mTotalIdleTime) {
                    mMaxIdleTime = mTotalIdleTime;
                }
                if(mTotalIdleTime >= 5) {
                    mNumIdleOverFive++;
                }
                mTotalOfficeVisits++;
                mWindows.getAt(i).resetWaitTime();
                pCustomer->resetWaitTime();
                //mWindows.getAt(i).resetWaitTime();
            } else {
                mWindows.getAt(i).incrementWaitTime();
            }
        } 
    }
    //Increment wait times of customers stuck in queue.
    for (int i = 0; i < mCustomerQueue.getSize(); i++) {
        mCustomerQueue.getAt(i)->incrementWaitTime();
    }

    // Process customer at window, if there is one.
    DblList<Customer *> finishedCustomers;
    for (int i = 0; i<mWindows.getSize(); i++) {
         if (mWindows.getAt(i).getCurrentCustomer() != NULL) {
            Customer *pCustomer = mWindows.getAt(i).getCurrentCustomer();
            // Please don't blow up.
            pCustomer->getOrderedTasks().getAt(0).decrementRemainingTime();
            // if customer is done
            if (pCustomer->getOrderedTasks().getAt(0).getRemainingTime() == 0) {
                // remove from current window
                mWindows.getAt(i).setCurrentCustomer(NULL);
                // The task is done.
                pCustomer->getOrderedTasks().removeFront();
                finishedCustomers.insertBack(pCustomer);
            }
        }
    }
    return finishedCustomers;
}

double Office::getMeanWaitTime() {
    return (mTotalWaitTime/mTotalOfficeVisits);
}    

int Office::getMaxWaitTime() {
    return mMaxWaitTime;
}

int Office::getLongerThanTen() {
    return mNumStudentsLongerThanTen;
}

double Office::getMeanIdleTime() {
    return (mTotalIdleTime/mWindows.getSize());
}

int Office::getMaxIdleTIme() {
    return mMaxIdleTime;
}

int Office::getNumIdleOverFive() {
    return mNumIdleOverFive;
}

