#include "Window.h"

Window::Window() {
    idle = true;
    idleTime = 0;
}

int Window::getIdleTime() {
    return idleTime;
}

bool Window::getIdle() {
    return idle;
}

void Window::setIdle(bool idlee) {
    idle = idlee;
}

void Window::setIdleTime(int idletime) {
    idleTime = idletime;
}

void Window::start(const Customer& customer, int time) {
    idle = false;
    currentCustomer = customer;
}

Window::~Window() {

}