#ifndef MENU_H
#define MENU_H
#include "Operations.h"
#include "Database.h"
#include "StudentTable.h"
#include "FacultyTable.h"
#include "Student.h"
#include "Faculty.h"
#include "iostream"

class Menu {
    public:
        Menu();
        ~Menu();

        void play();

    private:
        Database d;
        Operations o;
};

#endif