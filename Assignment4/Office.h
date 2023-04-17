#ifndef OFFICE_H
#define OFFICE_H
#include "Window.h"
#include "ListQueue.h"
#include "DblList.h"

class Office {
    public:
        Office();
        Office(int numWindows);
        Office(const Office& rhs);
        Office & operator=(const Office& rhs);
        ~Office();
    
        void addCustomer(Customer *pCustomer);
        DblList<Customer *> runOneMinute(int minutes); 
        int lengthCustomerQueue();
        int hasCustomers();
        double getMeanWaitTime();
        int getMaxWaitTime();
        int getLongerThanTen();
        double getMeanIdleTime();
        int getMaxIdleTIme();
    
        

    private:
        mutable DblList<Window> mWindows;
        ListQueue<Customer*> mCustomerQueue;
        int mTotalWaitTime;
        int mTotalOfficeVisits;
        int mMaxWaitTime;
        int mNumStudentsLongerThanTen;
        int mTotalIdleTime;
        int mNumWindows;
        int mMaxIdleTime;
};

#endif