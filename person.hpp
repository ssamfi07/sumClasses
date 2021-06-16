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
        Person(std::string name, int age);
        ~Person(){};
        virtual void display();
};

Person::Person(std::string name, int age)
{
    this->name = name;
    this->age = age;
}

void Person::display()
{
    std::cout << "\nName: " << this->name << "\nAge: " << this->age;
}