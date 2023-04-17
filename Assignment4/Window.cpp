#include "Window.h"

Window::Window() : 
   mpCurrentCustomer(NULL),
   mWaitTime(0)
{
}

Window::Window(const Window& rhs ) :
    mpCurrentCustomer(rhs.mpCurrentCustomer),
    mWaitTime(rhs.mWaitTime)
{
}

Window & Window::operator=(const Window& rhs ) {
    if(this == &rhs) {
        return *this;
    } 
    mpCurrentCustomer = rhs.mpCurrentCustomer;
    mWaitTime = rhs.mWaitTime;
    return *this;
}

Window::~Window() {
}

Customer* Window::getCurrentCustomer()  {
    return mpCurrentCustomer;
}

void Window::setCurrentCustomer(Customer *pCurrentCustomer)  {
    mpCurrentCustomer = pCurrentCustomer;
}

void Window::incrementWaitTime() {
    mWaitTime++;
}

void Window::resetWaitTime() {
    mWaitTime = 0;
}

int Window::getWaitTime() {
    return mWaitTime;
}