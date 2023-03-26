#ifndef SPEAKERVIEW_H
#define SPEAKERVIEW_H
#include "MonoStack.h"
#include <fstream>
#include <sstream>

template<typename T>
class SpeakerView {
public:
    SpeakerView(std::string inputFileName) {
        std::ifstream inputFile(inputFileName);
        if(!(inputFile)) {
            throw std::runtime_error("error opening input file");
        }
        //dimensions
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
        n = numRows;
        p = numCols;
        std::cout << "rows: " << numRows << " and cols: " << numCols << std::endl;

        inputFile.clear();
        inputFile.seekg(0);

        height = new T*[n];
        for(int i = 0; i < n; ++i) {
            height[i] = new T[p];
            for (int j = 0; j < p; j++) {
                inputFile >> height[i][j];
                std::cout << height[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    ~SpeakerView() {
        for (int i = 0; i < n; ++i) {
            delete[] height[i];
        }
        delete[] height;
    }
    void views() {
        for (int j = 0; j < p; ++j) {
            MonoStack<T> stack (n, 'i');
            int count = 0;
            for (int i = 0; i < n; ++i) {
                T heights = height[i][j];
                stack.push(heights);
            }
            std::cout << "in column: " << j << " the number of people with a clear view is: " << stack.getSize() << std::endl;
        }
    }
private:
    T** height;
    int n;
    int p;
    

};


#endif