#include "BST.h"
#include "Student.h"
#include "Faculty.h"
#include "FacultyTable.h"
#include "StudentTable.h"
#include "Database.h"
#include "Operations.h"
#include <iostream>

int main(int argc, char** argv) {

    
    Operations o;
    Database d;
    Faculty cheezit(0, "Sharon", "professor", "CPSC");
    d.addFaculty(cheezit);
    d.addStudent(Student(1, "Connor", "sophomore", "CPSC", 3.2, 0));
    cheezit.addStudentID(1);
    d.addStudent(Student(0, "Noah", "sophomore", "CSPC", 4.0, 0));
    cheezit.addStudentID(0);
    d.addStudent(Student(2, "John", "sophomore", "Math", 1.0, 0));
    cheezit.addStudentID(2);
    d.addStudent(Student(3, "Ronnor", "sophomore", "CPSC", 5.5, 0));
    cheezit.addStudentID(3); 

    o.printAllStudents(d);


    /*
    Database d;
    Faculty cheezit(0, "Sharon", "professor", "CPSC");
    d.addFaculty(cheezit);
    d.addStudent(Student(1, "Connor", "sophomore", "CPSC", 3.2, 0));
    cheezit.addStudentID(1);
    d.addStudent(Student(0, "Noah", "sophomore", "CSPC", 4.0, 0));
    cheezit.addStudentID(0);
    d.addStudent(Student(2, "John", "sophomore", "Math", 1.0, 0));
    cheezit.addStudentID(2);
    d.addStudent(Student(3, "Ronnor", "sophomore", "CPSC", 5.5, 0));
    cheezit.addStudentID(3); 

    d.getStudentTable().print();
    */

    /*
    StudentTable s;
    FacultyTable f;
    Faculty cheezit(0, "Sharon", "professor", "CPSC");
    f.add(cheezit);
    s.add(Student(1, "Connor", "sophomore", "CPSC", 3.2, 0));
    cheezit.addStudentID(1);
    s.add(Student(0, "Noah", "sophomore", "CSPC", 4.0, 0));
    cheezit.addStudentID(0);
    s.add(Student(2, "John", "sophomore", "Math", 1.0, 0));
    cheezit.addStudentID(2);
    s.add(Student(3, "Ronnor", "sophomore", "CPSC", 5.5, 0));
    cheezit.addStudentID(3); 


    s.find(3).print();
    s.update((s.find(3)), (Student(3, "Ronnoc", "junior", "accounting", 5.0, 0)));
    s.find(3).print();
    

    s.print();


    cheezit.getStudentIDList().printTree();
    */

    /*
   
    Faculty cheezit(0, "Sharon", "professor", "CPSC", studentIDList);
    BST<Student> studentList;
    studentList.insert((0, "Connor", "sophomore", "CPSC", 3.2, 0));
    Student(1, "Noah", "sophomore", "CSPC", 4.0, 0);
    Student(2, "John", "sophomore", "Math", 1.0, 0);
    Student(3, "Ronnor", "sophomore", "CPSC", 5.5, 0);

    cheezit.getStudentIDList().printTree();
    */

    /*
    BST<int> bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    bst.printTree();

    int* min = bst.getMin();
    int* max = bst.getMax();

    cout << endl << "Min: " << *min << endl;
    cout << "Max: " << *max << endl;

    bool found70 = bst.contains(70);
    bool found90 = bst.contains(90);

    cout << "Found 70? " << found70 << endl;
    cout << "Found 90? " << found90 << endl;

    bool deleted = bst.deleteNode(20);
    cout << "Deleted 20? " << deleted << endl;
    bst.printTree();

    deleted = bst.deleteNode(30);
    cout << "Deleted 30? " << deleted << endl;
    bst.printTree();

    deleted = bst.deleteNode(50);
    cout << "Deleted 50? " << deleted << endl;
    bst.printTree();

    return 0;
    */
}