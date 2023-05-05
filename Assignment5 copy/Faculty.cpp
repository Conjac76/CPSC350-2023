#include "Faculty.h"

Faculty::Faculty() : 
    mFacultyID(-1),
    mName(""),
    mLevel(""),
    mDepartment("")
{

}

Faculty::~Faculty() {

}

Faculty::Faculty(int facultyID, std::string name, std::string level, std::string department) :
    mFacultyID(facultyID),
    mName(name),
    mLevel(level),
    mDepartment(department)
{

}

Faculty::Faculty(const Faculty& other) : 
    mFacultyID(other.mFacultyID),
    mName(other.mName),
    mLevel(other.mLevel),
    mDepartment(other.mDepartment),
    mStudentIDList(other.mStudentIDList)
{

}

BST<int> Faculty::getStudentIDList() {
    return mStudentIDList;
}

int Faculty::getID() {
    return mFacultyID;
}

void Faculty::addStudentID(int studentID) {
    mStudentIDList.insert(studentID);
}

void Faculty::deleteStudentID(int studentID) {
    mStudentIDList.deleteNode(studentID);
}

void Faculty::print() {
    std::cout << "Faculty ID: " << mFacultyID << std::endl;
    std::cout << "Name: " << mName << std::endl;
    std::cout << "Level: " << mLevel << std::endl;
    std::cout << "Department: " << mDepartment << std::endl;
    std::cout << "Student ID List: ";
    mStudentIDList.printTree();
    std::cout << std::endl;
    std::cout << std::endl;
}
