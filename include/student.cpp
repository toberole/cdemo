#include "student.h"

#include <iostream>

Student::Student() {
    std::cout << "Student 1 ......" << std::endl;
}

void Student::sysHello() {
    std::cout << "Student sysHello ......" << std::endl;
}

Student::~Student() {
    std::cout << "~Student ......" << std::endl;
}