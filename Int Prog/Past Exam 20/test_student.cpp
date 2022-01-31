#include <string>
#include <vector>
#include "Scholar.cpp"
#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    Student s1("Pat Smith");
    s1.show_me();    
    
    Student s2("Samuel Barclay Beckett");
    //s2.show_me();

    s1.add_friends(&s2);
    s1.show_friends();

    Scholar sc1("Ted Wall");
    sc1.show_me();

    Scholar sc2("Diana King");
    sc1.add_friends(&sc2);
    sc1.add_friends(&s1);

    sc1.show_friends();
    // Student s3(" Jwhwh");
    // s3.show_me();

    // Student s4("Pat ");
    // s4.show_me();

    return 1;
}