#ifndef DATABASE_H
#define DATABASE_H
#include "StudentTable.h"
#include "FacultyTable.h"
#include "Student.h"
#include "Faculty.h"

class Database {
    public: 
        Database();
        ~Database();
        StudentTable getStudentTable();
        FacultyTable getFacultyTable();
        void addStudent(Student s);
        void addFaculty(Faculty f);
        void deleteStudent(int studentID);
        void deleteFaculty(int studentID);

    private:
        FacultyTable facultyTable;
        StudentTable studentTable;
};

#endif