#include "Faculty.h"

Faculty::Faculty() : 
    mFacultyID(0),
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