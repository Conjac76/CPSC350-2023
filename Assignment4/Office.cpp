#include "Office.h"


Office::Office(int numWindows) {
    for(int i = 0; i < numWindows; ++i) {
        windows.insertFront(Window());
    }
}

Office::Office() {
    
}

Office::~Office() {

}