#include "Operations.h"

Operations::Operations() {

}

Operations::~Operations() {

}

void Operations::printAllStudents(Database d) {
    d.getStudentTable().print();
}

void Operations::printAllFaculty(Database d) {
    d.getFacultyTable().print();
}

void Operations::printStudent(Database d, int studentID) {
    d.getStudentTable().find(studentID).print();
}

void Operations::printFaculty(Database d, int facultyID) {
    d.getFacultyTable().find(facultyID).print();
}

void Operations::addNewStudent(Database& d, Student s) {
    d.addStudent(s);
}

void Operations::addNewFaculty(Database& d, Faculty f) {
    d.addFaculty(f);
}

void Operations::deleteStudent(Database& d, int studentID) {
    d.deleteStudent(studentID);
}

void Operations::deleteFaculty(Database& d, int facultyID) {
    d.deleteFaculty(facultyID);
}

void Operations::changeAdvisor(Database& d, int studentID, int facultyID) {
    d.changeAdvisor(studentID, facultyID);
}

void Operations::deleteStudentID(Database& d, int studentID, int facultyID) {
    d.deleteStudentID(studentID, facultyID);
}
