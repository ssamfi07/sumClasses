#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>

#include "person.hpp"

//a student is registered as a person that has subjects, department and grades

class Student:public Person
{
    std::string name, department;
    int age;
    std::vector <float> grades; 
    std::vector <std::string> subjects;

    public:
        inline Student(std::string name, int age, std::vector<std::string> subjects, std::string department, std::vector <float> grades):Person(name, age)
        {
            this->name = name;
            this->age = age;
            this->subjects = subjects;
            this->department = department;
            this->grades = grades;
        };
        ~Student(){};
        void inline display();
        float inline calculateAverage();
};

void inline Student::display()
{
    //call method from parent class
    Person::display();
    std::cout << "\nSubjects: ";
    for(auto i = this -> subjects.begin(); i != this->subjects.end(); ++i)
    {
        std::cout << *i << " ";
    }
    std::cout << "\nDepartment: " << this -> department << "\nGrades: ";
    for(auto i = this -> grades.begin(); i != this->grades.end(); ++i)
    {
        std::cout << *i << " ";
    }
}

float inline Student::calculateAverage()
{
    return accumulate(this->grades.begin(), this->grades.end(), 0.0) / this -> grades.size();
}