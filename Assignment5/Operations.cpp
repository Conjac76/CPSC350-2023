#include "Operations.h"

Operations::Operations() {

}

Operations::~Operations() {

}

void Operations::printAllStudents() {
    database.getStudentTable().print();
}

FacultyTable Operations::getFacultyTable() {
    return database.getFacultyTable();
}

StudentTable Operations::getStudentTable() {
    return database.getStudentTable();
}