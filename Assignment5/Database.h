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
        void addStudentID(int studentID, int facultyID);
        void deleteStudentID(int studentID, int facultyID);
        void changeAdvisor(int studentID, int facultyID);

    private:
        FacultyTable facultyTable;
        StudentTable studentTable;
};

#endif