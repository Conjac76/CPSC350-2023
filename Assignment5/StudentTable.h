#ifndef STUDENTTABLE_H
#define STUDENTTABLE_H
#include "Student.h"
#include "LazyBST.h"

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
        void changeAdvisor(int studentID, int facultyID);
        bool contains(int studentID);
    private:
        LazyBST<Student> studentList;
};

#endif 