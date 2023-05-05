#ifndef FACULTYTABLE_H
#define FACULTYTABLE_H
#include "Faculty.h"
#include "BST.h"

class FacultyTable {
    public:
        FacultyTable();
        ~FacultyTable();
        Faculty find(int facultyID);
        void del(int facultyID);
        void update(Faculty oldFaculty, Faculty Faculty);
        void add(Faculty Faculty);
    private:
        BST<Faculty> facultyList;
};

#endif 