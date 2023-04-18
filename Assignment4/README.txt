Connor Jacobs
2395380
Rene German 
CPSC-350-2023
Assignment 4 - ServiceCenter

g++ *.cpp
./a.out inputFile.txt

Task 
    represents a task to be completed. It has four members Office, tasktime1, tasktime2, tasktime3
    and wait time. 

Customer
    represents a cutomers in the ServiceCenter, this includes the customers arrival time,
    orded taks and wait time. 

Window 
    represnts a serivce window. This includes a pointer to the current customer to be serivced
    as well as the window idle time. 

Office
    represnets an office. It holds a doubly linked list of windows, a queue of customers and other 
    counters which help to calculate the statistics. 

    the statistics are calculated from this class 
ServiceCenter
    represents a service center class. It holds three offices (registrar, cashier, and financialAid).
    this is repsonsible for managing the flow as well as recycling of students. 

IO
    represents the simulation of the service. It reads the input file and finds the amount of customers
    there tasks, and their neccessary times at the windows. 

    runs untl all are proccessed 





