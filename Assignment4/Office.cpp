#include "Office.h"


Office::Office(int numWindows) {
    for(int i = 0; i < numWindows; ++i) {
        windows.insertBack(Window(i+1));
    }
}



Office::Office() {
    
}

Office::~Office() {

}