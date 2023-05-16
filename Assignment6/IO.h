#ifndef IO_H
#define IO_H

#include <string>
#include "DBLlist.h"

class IO {
    public:
        IO(std::string inputString);
        ~IO();
        void processFile();
        DblList<double> getUnsortedDoubles();

        
    private:
        std::string mInputString;
        DblList<double> unsortedDoubles;
};

#endif