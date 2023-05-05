#ifndef OPERATIONS_H
#define OPERATIONS_H
#include "Database.h"
#include "FacultyTable.h"
#include "Student.h"
#include "StudentTable.h"
#include "Faculty.h"

class Operations {
    public:
        Operations();
        ~Operations();
        void printAllStudents(Database d); 
    private:

};

#endif