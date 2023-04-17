#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <iostream>
#include "Task.h"
#include "DblList.h"

class Customer {
    public:
        ~Customer();
        Customer();
        Customer(int arrivalTime, char office1, int time1, char office2, int time2, char office3, int time3);
        Customer(const Customer& rhs);
        Customer & operator=(const Customer& rhs );
        int getArrivalTime();
        void resetWaitTime();
        void incrementWaitTime();
        int getWaitTime();
        DblList<Task>& getOrderedTasks();
        
    private:
        int mArrivalTime;
        int mWaitTime;
        DblList<Task> mOrderedTasks;
};

#endif