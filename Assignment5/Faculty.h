#ifndef FACULTY_H
#define FACULTY_H
#include <string>
#include "LazyBST.h"

class Faculty {
    public:
        Faculty();
        ~Faculty();
        Faculty(const Faculty& other);
        Faculty(int facultyID, std::string name, std::string level, std::string department);
        void addStudentID(int studentID);
        void deleteStudentID(int studentID);
        void print();



        int getID();
        LazyBST<int> getStudentIDList();

        // Overloading operators
        bool operator==(const Faculty& other) const {
            return mFacultyID == other.mFacultyID;
        }

        bool operator<(const Faculty& other) const {
            return mFacultyID < other.mFacultyID;
        }

        bool operator>(const Faculty& other) const {
            return mFacultyID > other.mFacultyID;
        }

        bool operator!=(const Faculty& other) const {
            return mFacultyID != other.mFacultyID;
        }


    private:
        int mFacultyID;
        std::string mName;
        std::string mLevel;
        std::string mDepartment;
        LazyBST<int> mStudentIDList;
};

#endif