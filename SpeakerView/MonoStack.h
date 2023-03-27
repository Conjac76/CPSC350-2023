#ifndef MONOSTACK_H
#define MONOSTACK_H

#include <iostream>
#include <exception>

template <typename T>
class MonoStack {
public:
    MonoStack(){ // default constructor
        mSize = 64;
        mTop = -1;
        pValue = new T[mSize];
        mIncreasing = true;
    }
    // Overloaded constructor to create MonoStack of size maxSize
    MonoStack(int maxSize) {
        mSize = maxSize;
        mTop = -1;
        pValue = new T[mSize];
        mIncreasing = true;
    }
    
    MonoStack(int maxSize, char o) {
        mSize = maxSize;
        mTop = -1;
        pValue = new T[mSize];
        if (o == 'i' || o == 'I') {
            mIncreasing = true;
        }
        else if (o == 'd' || o == 'D') {
            mIncreasing = false;
        }
        else {
             throw std::invalid_argument("MonoStack must be increasing or decreasing");
        }
    }
    ~MonoStack(){ // destructor
        delete[] pValue;
    }
    // core functions
    void push(const T& data) {
         // check if stack is full
        if (isFull()) {
            throw std::runtime_error("stack is full");
        }
        while (mTop >= 0 && ((mIncreasing && pValue[mTop] > data) || (!mIncreasing && pValue[mTop] < data))) {
            mTop--;
        }
        pValue[++mTop] = data;
    }
    T pop() {
        // check if stack is empty
        if (isEmpty()) {
            throw std::runtime_error("stack is empty, nothing to pop");
        }
        return pValue[mTop--];
    }
    T peek(){ // aka mTop()
        // check if stack is empty
        if (isEmpty()) {
            throw std::runtime_error("stack is empty, nothing to peek");
        }
        return pValue[mTop];
    }

    // aux functions
    int getSize() {
        return mTop + 1;
    }
    bool isEmpty() {
        return (mTop == -1);
    }
    bool isFull() {
        return (mTop == mSize - 1);
    }

    void printStack() {
        for (int i = mTop; i >=0; i--) {
            std::cout << pValue[i] << ", ";
        }
        std::cout << std::endl;
    }

private:
    MonoStack(const MonoStack &rhs);
    MonoStack &operator=(const MonoStack &rhs);

    T* pValue; // pointer to array of values
    int mSize;
    int mTop;
    bool mIncreasing;
};

#endif