#include <string>
#include <vector>
#include "Student.h"
#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <fstream>
using namespace std;

class Scholar : public Student {

    public:
    Scholar(void) : Student(){};
    Scholar(string fullname) : Student(fullname){};

    private:
    vector<Student*> friends;
};
