#include "StudentTable.h"
#include "BST.h"

StudentTable::StudentTable() {

}

StudentTable::~StudentTable() {

}

Student StudentTable::find(int studentID) {
    return studentList.searchByID(studentID)->getValue();
}

void StudentTable::add(Student student) {
    studentList.insert(student);
}

void StudentTable::del(int studentID) {
    studentList.deleteNode(studentList.searchByID(studentID)->getValue());
}

void StudentTable::update(Student oldStudent, Student student) {
    studentList.replace(oldStudent, student);
}

void StudentTable::print() {
    studentList.studentPrinter();
}


