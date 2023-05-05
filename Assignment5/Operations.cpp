#include "Operations.h"

Operations::Operations() {

}

Operations::~Operations() {

}

void Operations::printAllStudents(Database d) {
    d.getStudentTable().print();
}
