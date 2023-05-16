#include "IO.h"
#include "DBLlist.h"
#include "ListNode.h"
#include "Sort.h"
#include <string>

int main(int argc, char *argv[]) {
    std::string inFile;
    inFile = argv[1];
    IO input(inFile);
    input.processFile();
    Sort s(input.getUnsortedDoubles());
    s.mergeSort();
    s.quickSort();

}