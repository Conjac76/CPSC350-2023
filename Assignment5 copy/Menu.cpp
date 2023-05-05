#include "Menu.h"
#include <string>
#include <iostream>
#include <fstream>

Menu::Menu() {

}

Menu::~Menu() {

}

void Menu::play() {
   

    //for testing purposes
    Faculty cheezit(0, "Sharon", "professor", "CPSC");
    Faculty peperoni(1, "Carol", "professor", "math");
    d.addFaculty(cheezit);
    d.addFaculty(peperoni);
    d.addStudent(Student(1, "Connor", "sophomore", "CPSC", 3.2, 0));
    d.addStudentID(1, 0);
    d.addStudent(Student(0, "Noah", "sophomore", "CSPC", 4.0, 0));
    d.addStudentID(0, 0);
    d.addStudent(Student(2, "John", "sophomore", "Math", 1.0, 0));
    d.addStudentID(2, 0);
    d.addStudent(Student(3, "Ronnor", "sophomore", "CPSC", 5.5, 0));
    d.addStudentID(3, 0); 

    std::cout << "1. Print all students and their information (sorted by ascending id #)" << std::endl;
    std::cout << "2. Print all faculty and their information (sorted by ascending id #)" << std::endl;
    std::cout << "3. Find and display student information given the student id" << std::endl;
    std::cout << "4. Find and display faculty information given the faculty id" << std::endl;
    std::cout << "5. Add a new student" << std::endl;
    std::cout << "6. Delete a student given the id" << std::endl;
    std::cout << "7. Add a new faculty member" << std::endl;
    std::cout << "8. Delete a faculty member given the id."  << std::endl;
    std::cout << "9. Change a student’s advisor given the student id and the new faculty id." << std::endl;
    std::cout << "10. Remove an advisee from a faculty member given the ids" << std::endl;
    std::cout << "11. Exit" << std::endl;


    int number = 12;
    while(number != 11) {
        std::cout << "Enter number 1-11\n";
        std::cin >> number;
        if(number == 1) {
            o.printAllStudents(d);
        } else if(number == 2) {
            o.printAllFaculty(d);
        } else if(number == 3) {
            std::cout << "Enter a student ID number\n";
            int n;
            std::cin >> n;
            if(!(d.getStudentTable().find(n).getID() == -1)) {
                o.printStudent(d, n);
            } else {
                std::cout << "Student doesn't exist\n";
            }
        } else if(number == 4) {
            std::cout << "Enter a faculty ID number\n";
            int n;
            std::cin >> n;
            if(!(d.getFacultyTable().find(n).getID() == -1)) {
                o.printFaculty(d, n);
            } else {
                std::cout << "This Faculty Member does not exist\n";
            }
        } else if(number == 5) {
            int newStudentID;
            std::string name;
            std::string grade;
            std::string major;
            double gpa;
            int facultyID;
            std::cout << "Enter new student ID\n";
            std::cin >> newStudentID;
            if(d.getStudentTable().contains(newStudentID) || newStudentID < 0) {
                std::cout << "There is already a student with this id\n";
                continue;
            }
            std::cout << "Enter new student name\n";
            std::cin >> name;
            std::cout << "Enter new student grade\n";
            std::cin >> grade;
            std::cout << "Enter new student major\n";
            std::cin >> major;
            std::cout << "Enter new student gpa\n";
            std::cin >> gpa;
            std::cout << "Enter new student faculty ID\n";
            std::cin >> facultyID;
            o.addNewStudent(d, Student(newStudentID, name, grade, major, gpa, facultyID));
            d.addStudentID(newStudentID, facultyID);
        } else if (number == 6) {
            int studentID;
            std::cout << "Enter student ID to delete\n";
            std::cin >> studentID;
            if(!(d.getStudentTable().contains(studentID)) || studentID < 0) {
                std::cout << "The student is not in the list\n";
                continue;
            }
            int facultyOfStudent = d.getStudentTable().find(studentID).getFacultyID();
            d.deleteStudentID(studentID, facultyOfStudent);
            o.deleteStudent(d, studentID);
        } else if (number == 7) {
            int facultyID;
            std::string name;
            std::string level;
            std::string department;
            std::cout << "Enter new faculty ID\n";
            std::cin >> facultyID;
            if (d.getFacultyTable().contains(facultyID) || facultyID < 0) {
                std::cout << "There is already a faculty member with this ID\n";
                continue;
            }
            std::cout << "Enter new faculty name\n";
            std::cin >> name;
            std::cout << "Enter new faculty level\n";
            std::cin >> level;
            std::cout << "Enter new faculty department\n";
            std::cin >> department;
            o.addNewFaculty(d, Faculty(facultyID, name, level, department));
        } else if (number == 8 ) {
            int facultyID;
            std::cout << "Enter faculty ID to be deleted\n";
            std::cin >> facultyID;
            if(!(d.getFacultyTable().contains(facultyID))) {
                std::cout << "You cannot delete a non-existant faculty member\n";
                continue;
            }
            if(d.getFacultyTable().find(facultyID).getStudentIDList().isEmpty()) {
                o.deleteFaculty(d, facultyID);
                std::cout << "deleted faculty ID#:" << facultyID << std::endl;
            } else {
                std::cout << "Cannot delete faculty who still has advisees\n";
                continue;
            }
        } else if (number == 9) {
            int studentID;
            int facultyID;
            std::cout << "Enter Student ID to be switched\n";
            std::cin >> studentID;
            if(!(d.getStudentTable().contains(studentID))) {
                std::cout << "You cannot delete a student that does not exist\n";
                continue;
            }
            std::cout << "Enter Faculty ID to gain a student\n";
            std::cin >> facultyID;
            if(!(d.getFacultyTable().contains(facultyID))) {
                std::cout << "You cannot add a student to a non-existant faculty member\n";
                continue;
            }
            int oldFacultyID = d.getStudentTable().find(studentID).getFacultyID();
            d.deleteStudentID(studentID, oldFacultyID);
            d.addStudentID(studentID, facultyID);
            o.changeAdvisor(d, studentID, facultyID);
        } else if (number == 10) {
            int studentID;
            int facultyID;
            std::cout << "Enter Student ID to be removed from advisee's list\n";
            std::cin >> studentID;
            if(!(d.getStudentTable().contains(studentID))) {
                std::cout << "You cannot switch a student that does not exist\n";
                continue;
            }
            std::cout << "Enter Faculty ID\n";
            std::cin >> facultyID;
            if(!(d.getFacultyTable().contains(facultyID))) {
                std::cout << "Advisor does not exist\n";
                continue;
            }
            int currentFaculty = d.getStudentTable().find(studentID).getFacultyID();
            if(currentFaculty != facultyID) {
                o.deleteStudentID(d, studentID, facultyID);
            } else {
                std::cout << "You cannot delete an advisee's current faculty member\n";
                continue;
            }
        } else if (number == 11) {
            std::ofstream outputFile("runLog.txt");
            std::streambuf* coutbuf = std::cout.rdbuf();
            std::cout.rdbuf(outputFile.rdbuf());
            o.printAllFaculty(d);
            o.printAllStudents(d);
            std::cout.rdbuf(coutbuf);
            outputFile.close();
            break;
        } else {
            std::cout << "You enter the wrong number try again\n";
            continue;

        }
    }
}
