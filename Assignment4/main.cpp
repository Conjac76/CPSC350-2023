#include "DblList.h"
#include "ListNode.h"
#include "ListQueue.h"
#include "IO.h"

int main() {
    /*
    DblList<double> mylist;
    mylist.insertFront(1.1);
    mylist.insertFront(2.2);
    mylist.insertFront(3.3);
    mylist.insertFront(4.4);
    mylist.insertFront(5.5);
    mylist.insertFront(6.6);
    for(int i = 0; i < mylist.getSize(); i++) {
        std::cout << mylist[i] << std::endl;
    }
    */
    /*
    ListQueue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    int temp = q.getSize();
    for(int i = 0; i < temp; i++) {
        std::cout << q.dequeue() << std::endl;
    }
    */

    IO input;
    input.readFile("inputFile.txt");
    input.run();

    /*
    Office registrar(1);
    Office aid(1);
    Office cashier(1);
    
    Customer c1(1, 2, 3, "RCF", 1);
    Customer c2(1, 3, 4, "CFR", 1);
    Customer c3(2, 4, 6, "FRC", 3);

    registrar.addCustomer(c1);
    cashier.addCustomer(c2);
    aid.addCustomer(c3);

    registrar.printStats();
    */

}