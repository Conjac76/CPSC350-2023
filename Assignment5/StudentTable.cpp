#include "StudentTable.h"
#include "BST.h"

StudentTable::StudentTable() {

}

StudentTable::~StudentTable() {

}

Student StudentTable::find(int studentID) {
    if(studentList.searchByID(studentID) == NULL) {
        return Student();
    }
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

void StudentTable::changeAdvisor(int studentID, int facultyID) {
    Student s = find(studentID);
    s.setFacultyID(facultyID);
    update(s, s);
}

bool StudentTable::contains(int studentID) {
    Student s = find(studentID);
    return studentList.contains(s);
}


