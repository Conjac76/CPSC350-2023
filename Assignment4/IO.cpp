#include <iostream>
#include <fstream>
#include <sstream>

#include "IO.h"
#include "DblList.h"

IO::IO() :
    mServiceCenter(),
    mCustomerList() {
}   

IO::~IO() {
}

void IO::readFile(std::string inputFile) {
    std::ifstream myfile;
    try {
        myfile.open(inputFile);
        if(myfile.is_open()) {
            int windowsRegistrar;
            int windowsCashier;
            int windowsFinancialAid;

            // Process first 3 lines and create service center
            std::string line;
            int lineCounter = 0;
            while(getline(myfile, line)) {
                int value = std::stoi(line);
                // first line number of registrar windows
                if(lineCounter == 0) {
                    windowsRegistrar = value;
                 // second line number of cashier windows
                } else if (lineCounter == 1) {
                    windowsCashier = value;
                // third line number of finanical aid windows 
                // then move on to reading custoemrs.             
                } else if (lineCounter == 2) {
                    windowsFinancialAid = value;
                    break;
                }
                lineCounter++;
            }
            mServiceCenter = ServiceCenter(windowsRegistrar, windowsFinancialAid, windowsFinancialAid);

            // Load all the customers until we run out of lines
            int numStudents = 0;
            int arrivalTime = 0;
            lineCounter = 0;
            while (getline(myfile, line)) {             
                // first line if arrival time
                if (lineCounter == 0) {
                    arrivalTime = std::stoi(line);
                    lineCounter++;
                // second line is number of students
                } else if (lineCounter == 1) {
                    numStudents = std::stoi(line);
                    lineCounter++;
                // third+ line is tasks.
                } else if (lineCounter >= 2) {
                    std::istringstream iss(line);
                    int task1, task2, task3;
                    char office1, office2, office3;
                    iss >> task1 >> task2 >> task3 >> office1 >> office2 >> office3;

                    // Create all the customers
                    mCustomerList.insertBack(Customer(arrivalTime, office1, task1, office2, task2, office3, task3));
                    // reset if we've read each students tasks
                    if (lineCounter == numStudents + 1) {
                        lineCounter = 0;
                    } else {
                        lineCounter ++;
                    }
                } 
            }
        }
    } catch (const std::exception& e) {
        std::cout << "Error\n";
    }
}

void IO::run() {
    int minutes = 1;
    int customerIndex = 0;
    
    // Run until there are no more customers entering the service center or in the service center
    while (customerIndex < mCustomerList.getSize() || mServiceCenter.hasCustomers() == true) {
        // process any customers where arrival time == current clock and 
        // add them to the service center, which will put them to the office,
        // which will put them in a queue.
        while (customerIndex < mCustomerList.getSize() && mCustomerList.getAt(customerIndex).getArrivalTime() == minutes) {
            Customer *pCustomer = &mCustomerList.getAt(customerIndex);
            customerIndex++;
            mServiceCenter.addCustomer(pCustomer);
        }

        mServiceCenter.runOneMinute(minutes);

        minutes++;
    }
    mServiceCenter.printStats();
    std::cout << "All customers processe in [" << minutes << "]\n";
}

