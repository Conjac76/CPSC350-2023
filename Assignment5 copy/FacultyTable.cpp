#include "FacultyTable.h"
#include "BST.h"

FacultyTable::FacultyTable() {

}

FacultyTable::~FacultyTable() {

}

Faculty FacultyTable::find(int facultyID) {
    if(facultyList.searchByID(facultyID) == NULL) {
        return Faculty();
    }
    return facultyList.searchByID(facultyID)->getValue();
}

void FacultyTable::add(Faculty faculty) {
    facultyList.insert(faculty);
}

void FacultyTable::del(int facultyID) {
    facultyList.deleteNode(facultyList.searchByID(facultyID)->getValue());
}

void FacultyTable::update(Faculty oldFaculty, Faculty faculty) {
    facultyList.replace(oldFaculty, faculty);
}

void FacultyTable::addStudentID(int studentID, int facultyID) {
    Faculty faculty = find(facultyID);
    faculty.addStudentID(studentID);
    update(faculty, faculty);
}

void FacultyTable::print() {
    facultyList.studentPrinter();
}

void FacultyTable::deleteStudentID(int studentID, int facultyID) {
    Faculty faculty = find(facultyID);
    faculty.deleteStudentID(studentID);
    update(faculty, faculty);
}

bool FacultyTable::contains(int ID) {
    Faculty f = find(ID);
    return facultyList.contains(f);
}