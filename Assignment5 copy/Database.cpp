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

void Database::addStudentID(int studentID, int facultyID) {
    facultyTable.addStudentID(studentID, facultyID);
}

void Database::deleteStudentID(int studentID, int facultyID) {
    facultyTable.deleteStudentID(studentID, facultyID);
}

void Database::changeAdvisor(int studentID, int facultyID) {
    studentTable.changeAdvisor(studentID, facultyID);
}