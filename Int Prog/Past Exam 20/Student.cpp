#include <string>
#include <vector>
#include "Student.h"
#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <fstream>
using namespace std;

Student::Student()
{
    surname = "Unknown";
    initials = "N/a"; 
}

Student::Student(string name)
{
    initials = name[0];
    initials += '.'; 
    surname = "";
    int last_space = 0;

    for (int i = 0; i < name.length(); i++)
    {
        char current = name[i];

        if (isspace(current))
        {
            last_space = i;
        }
    }

    if (last_space == 0 || last_space == name.length() - 1)
    {
        cout << "Incorrect name format." << endl;
        surname = "Unknown";
        initials = "N/a";
    }

    else
    {
        initials = initials + name[last_space + 1] + '.';

        for (int i = last_space + 1; i < name.length(); i++)
        {
            surname += name[i];
        }
    }
}

void Student::show_me()
{
    cout << surname << ", " << initials << endl;
}

void Student::show_friends()
{
    for (int i = 0; i < friends.size(); i++)
    {
        Student* current = friends.at(i);
        current->show_me();
    }
}

void Student::add_friends(Student* a_student)
{
    friends.push_back(a_student);
}