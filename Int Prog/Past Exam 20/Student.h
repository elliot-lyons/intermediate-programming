#include <string>
#include <vector>
using namespace std;

class Student 
{
    public:
    Student();
    Student(string name);
    string initials;
    string surname;
    
    void show_me();
    void show_friends();
    void add_friends(Student* a_student);

    private:
    vector<Student *> friends;
};