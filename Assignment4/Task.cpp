#include "Task.h" 
#include <iostream>

Task::Task() {
    mOffice = ' ';
    mTaskTime = 0;
    mRemainingTime = 0;
    mWaitTime = 0;
}

Task::Task(char office, int taskTime) {
    mOffice = office;
    mTaskTime = taskTime;
    mRemainingTime = taskTime;
    mWaitTime = 0;
}

Task::Task(const Task& rhs) {
    mOffice = rhs.mOffice;
    mTaskTime = rhs.mTaskTime;
    mRemainingTime = rhs.mRemainingTime;
    mWaitTime = rhs.mWaitTime;
}
Task & Task::operator=(const Task& rhs ) {
    if(this == &rhs) {
        return *this;
    }
    mOffice = rhs.mOffice;
    mTaskTime = rhs.mTaskTime;
    mRemainingTime = rhs.mRemainingTime;
    mWaitTime = rhs.mWaitTime;
    return *this;
}
Task::~Task(){

}
int Task::getRemainingTime() {
    return mRemainingTime;
}

void Task::decrementRemainingTime() {
    mRemainingTime--;
}

char Task::getOffice() {
    return mOffice;
}