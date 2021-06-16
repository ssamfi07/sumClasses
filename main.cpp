#include <iostream>
#include <fstream>
#include <vector>
#include <sstream> //for the string stream
#include <string.h>

#include "student.hpp"

void readFromFile(Student *students[])
{

    std::fstream in;
    in.open("in.txt", std::ios::in);
    if(!in)
    {
        std::cout << "\nError at opening the file!";
    }
    else
    {
        std::string name, department, sumString;
        char allSubjects[101];
        int age, i = 0;
        float grade;
        std::vector <float> grades;
        std::vector <std::string> subjects;
        while(!in.eof())
        {
            in >> name >> age >> allSubjects >> department;
            
            char *first = nullptr, *last = nullptr;
            char subject[101];

            //separate subjects if uppercase letter is met and add them to the subjects vector
            for(auto i = 0; i < strlen(allSubjects); ++i)
            {   
                if(allSubjects[i] > 'A' && allSubjects[i] < 'Z')
                {
                    if(!first)
                    {
                        first = allSubjects;
                    }
                    last = allSubjects + i;

                    //create/update the subject string
                    memset(subject, 0, sizeof(subject));
                    strncpy(subject, first, last - first);
                    subject[last - first + 1] = '\0'; //adding the null character manually

                    //insert the string to the vector if subject is not null
                    if(subject != NULL)
                    {
                         subjects.push_back(subject);
                    }
                    //update found position of uppercase char
                    first = last;
                }
            }
            //the last pointer remembers the last subject
            subjects.push_back(last);

            //read the remaining grades in the line as a string and then separate them into floats
            getline(in, sumString);
            std::istringstream iss(sumString);
            while(iss >> grade)
            {
                grades.push_back(grade);
            }

            //create new Student object and assign it's address to the students addresses array
            students[i++] = new Student(name, age, subjects, department, grades);

            //clear grades and subjects vector
            grades.clear();
            subjects.clear();
        }
    }

    in.close();
}

int main()
{
    const int n = 10;
    Student *students[n];;
    readFromFile(students);

    for(int i = 0; i < 3; ++i)
    {
        students[i] -> display();
        std::cout << "\nStudent average: " << students[i] -> calculateAverage() << "\n";
    }
    return 0;
}