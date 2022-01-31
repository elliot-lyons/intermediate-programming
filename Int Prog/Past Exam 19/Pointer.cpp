#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int x = 1;
    int* p = &x;
    
    cout << "p = " << p << " (address of x)" << endl;
    cout << "&p = " << &p << " (address of p)" << endl;
    cout << "p* = " << *p << " (value in address p points to, in this case x)" << endl;
    cout << "&x = " << &x << " (address of x)" << endl;

    return 0;
}