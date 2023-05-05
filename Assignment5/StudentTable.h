#ifndef STUDENTTABLE_H
#define STUDENTTABLE_H
#include "Student.h"
#include "BST.h"

class StudentTable {
    public:
        StudentTable();
        ~StudentTable();
        Student find(int studentID);
        void del(int studentID);
        void update(Student oldStudent, Student student);
        void add(Student student);
        void print();
        void studentPrint(Student student);
    private:
        BST<Student> studentList;
};

#endif 