#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//a person has name and age

class Person
{
    std::string name;
    int age;

    public:
        inline Person(std::string name, int age);
        ~Person(){};
        virtual void inline display();
};

inline Person::Person(std::string name, int age)
{
    this->name = name;
    this->age = age;
}

void inline Person::display()
{
    std::cout << "\nName: " << this->name << "\nAge: " << this->age;
}