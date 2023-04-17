#ifndef IO_H
#define IO_H
#include <string>

#include "ServiceCenter.h"
#include "Customer.h"
#include "Office.h"
#include "DblList.h"

class IO {
    public:
        IO();
        ~IO();
        void readFile(std::string inputFile);
        void run();
    private:
        IO(const IO &rhs);
        IO& operator=(const IO &rhs);
        ServiceCenter mServiceCenter;
        DblList<Customer> mCustomerList;
};

#endif