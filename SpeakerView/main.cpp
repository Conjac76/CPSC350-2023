#include "MonoStack.h"
#include "SpeakerView.h"
#include <iostream>
#include <fstream>
#include <string>

int main (int argc, char** argv) {

    /*
    MonoStack<double> monostack(8, 'd');
    monostack.push(9.7);
    monostack.printStack();
    monostack.push(1.1);
    monostack.printStack();
    monostack.push(5.5);
    monostack.printStack();
    monostack.push(3.3);
    monostack.printStack();
    */

    //std::cout << monostack.pop() << std::endl;
    //std::cout << monostack.pop() << std::endl;
    
    SpeakerView<double> speakerview;
    std::string charInputFileName(argv[1]);
    speakerview.processFile(charInputFileName);
    speakerview.views();
}