#include "MonoStack.h"
#include "SpeakerView.h"
#include <iostream>
#include <fstream>
#include <string>

int main() {
    /*
    MonoStack<double> monostack(8, 'i');
    monostack.push(9.9);
    monostack.push(1.1);
    monostack.push(11.1);

    std::cout << monostack.pop() << std::endl;
    std::cout << monostack.pop() << std::endl;
    */
    SpeakerView<double> speakerview("seatting.txt");
    speakerview.views();
}