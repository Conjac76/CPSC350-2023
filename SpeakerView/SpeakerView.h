#ifndef SPEAKERVIEW_H
#define SPEAKERVIEW_H
#include "MonoStack.h"
#include <fstream>
#include <sstream>

template<typename T>
class SpeakerView {
public:
    SpeakerView() {
        //Initialize and set 2D array to components of text file accordingly. 
        height = new T*[mN];
    }

    void processFile(std::string inputFileName) {
        std::ifstream inputFile(inputFileName);
        if(!(inputFile)) {
            throw std::runtime_error("error opening input file");
        }
        //Iterate through text file in order to find width and height.
        std::string line;
        std::getline(inputFile, line);
        std::stringstream ss(line);
        int numRows = 1;
        int numCols = 0;
        T val;
        while(ss >> val) {
            numCols++;
        }
        while (std::getline(inputFile, line)) {
            numRows++;
        }
        mN = numRows;
        mP = numCols;
        std::cout << "rows: " << numRows << " and cols: " << numCols << std::endl;
        inputFile.clear();
        inputFile.seekg(0);
        for(int i = 0; i < mN; ++i) {
            height[i] = new T[mP];
            for (int j = 0; j < mP; j++) {
                inputFile >> height[i][j];
                std::cout << height[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    ~SpeakerView() {
        for (int i = 0; i < mN; ++i) {
            delete[] height[i];
        }
        delete[] height;
    }



    void views() {
        for (int j = 0; j < mP; ++j) {
            MonoStack<T> stack (mN, 'd');
            int count = 0;
            for (int i = mN-1; i >= 0; i--) {
                T heights = height[i][j];
                stack.push(heights);
            }
            std::cout << "in column: " << j << " the number of people with a clear view is: " << stack.getSize() << std::endl;
        }
    }

private:
    T** height;
    int mN;
    int mP;
};

#endif