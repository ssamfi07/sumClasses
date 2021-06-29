#include <iostream>
#include "../student.hpp"
#include "studentFunctions.hpp"

void displayStudents(Student *students[])
{
    for(int i = 0; i < 3; ++i)
    {
        students[i] -> display();
        std::cout << "\nStudent average: " << students[i] -> calculateAverage() << "\n";
    }
}