#include "Student.h"
#include <iostream>

Student::Student() {
    mStudentID = -1;
    mName = "";
    mMajor = "";
    mLevel = "";
    mGPA = 0.0;
    mFacultyID = 0;
}

Student::Student(int studentID, std::string name, std::string level, std::string major, double GPA, int facultyID) {
    mStudentID = studentID;
    mName = name;
    mMajor = major;
    mLevel = level;
    mGPA = GPA;
    mFacultyID = facultyID;
}

Student::Student(const Student& other) {
    mStudentID = other.mStudentID;
    mName = other.mName;
    mMajor = other.mMajor;
    mLevel = other.mLevel;
    mGPA = other.mGPA;
    mFacultyID = other.mFacultyID;
}

Student::~Student() {

}

int Student::getID() {
    return mStudentID;
}

void Student::print() {
    std::cout << "Student ID: " << mStudentID << std::endl;
    std::cout << "Name: " << mName << std::endl;
    std::cout << "Level: " << mLevel << std::endl;
    std::cout << "Major: " << mMajor << std::endl;
    std::cout << "GPA: " << mGPA << std::endl;
    std::cout << "Faculty ID: " << mFacultyID << std::endl;
    std::cout << std::endl;
}

void Student::setFacultyID(int facultyID) {
    mFacultyID = facultyID;
}

int Student::getFacultyID() {
    return mFacultyID;
}
