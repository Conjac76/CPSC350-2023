#include "FacultyTable.h"
#include "BST.h"

FacultyTable::FacultyTable() {

}

FacultyTable::~FacultyTable() {

}

Faculty FacultyTable::find(int facultyID) {
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