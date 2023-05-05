#ifndef STUDENT_H
#define STUDENT_H
#include <string>

class Student {
    public:
        Student();
        ~Student();
        Student(const Student& other);
        Student(int studentID, std::string name, std::string level, std::string major, double GPA, int facultyID);

        int getID();
        void setFacultyID(int facultyID);



        void print();        
        // Overloading operators
        bool operator==(const Student& other) const {
            return mStudentID == other.mStudentID;
        }

        bool operator<(const Student& other) const {
            return mStudentID < other.mStudentID;
        }

        bool operator>(const Student& other) const {
            return mStudentID > other.mStudentID;
        }

        bool operator!=(const Student& other) const {
            return mStudentID != other.mStudentID;
        }

    private:
        int mStudentID;
        std::string mName;
        std::string mLevel;
        std::string mMajor;
        double mGPA;
        int mFacultyID;
};

#endif