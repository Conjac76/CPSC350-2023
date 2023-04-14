#include "Office.h"


Office::Office(int numWindows) {
    for(int i = 0; i < numWindows; ++i) {
        Window d;
        windows.insertFront(d);
    }
}

Office::Office() {
    
}

Office::~Office() {

}