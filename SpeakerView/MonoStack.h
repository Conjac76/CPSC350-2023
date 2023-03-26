#ifndef MONOSTACK_H
#define MONOSTACK_H

#include <iostream>
#include <exception>

template <typename T>
class MonoStack {
public:
    MonoStack(){ // default constructor
        mSize = 64;
        top = -1;
        value = new T[mSize];
        increasing = true;
    }
    // Overloaded constructor to create MonoStack of size maxSize
    MonoStack(int maxSize) {
        mSize = maxSize;
        top = -1;
        value = new T[mSize];
        increasing = true;
    }
    
    MonoStack(int maxSize, char o) {
        mSize = maxSize;
        top = -1;
        value = new T[mSize];
        if (o == 'i' || o == 'I') {
            increasing = true;
        }
        else if (o == 'd' || o == 'D') {
            increasing = false;
        }
        else {
            // put in different char
        }
    }
    ~MonoStack(){ // destructor
        delete[] value;
    }
    // core functions
    void push(const T& data) {
         // check if stack is full
        if (isFull()) {
            throw std::runtime_error("stack is full");
        }
        while (top >= 0 && ((increasing && value[top] > data) || (!increasing && value[top] < data))) {
            top--;
        }
        value[++top] = data;
    }
    T pop() {
        // check if stack is empty
        if (isEmpty()) {
            throw std::runtime_error("stack is empty, nothing to pop");
        }
        return value[top--];
    }
    T peek(){ // aka top()
        // check if stack is empty
        if (isEmpty()) {
            throw std::runtime_error("stack is empty, nothing to peek");
        }
        return value[top];
    }

    // aux functions
    int getSize() {
        return top + 1;
    }
    bool isEmpty() {
        return (top == -1);
    }
    bool isFull() {
        return (top == mSize - 1);
    }

private:
    T* value; // pointer to array of values
    int mSize;
    int top;
    bool increasing;
};

#endif