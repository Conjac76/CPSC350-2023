#include "Database.h"

Database::Database() {

}

Database::~Database() {

}

StudentTable Database::getStudentTable() {
    return studentTable;
}

FacultyTable Database::getFacultyTable() {
    return facultyTable;
}

void Database::addStudent(Student s) {
    studentTable.add(s);
}

void Database::addFaculty(Faculty f) {
    facultyTable.add(f);
}

void Database::deleteFaculty(int facultyID) {
    facultyTable.del(facultyID);
}

void Database::deleteStudent(int studentID) {
    studentTable.del(studentID);
}