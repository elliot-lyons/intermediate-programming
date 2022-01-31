#include <string>
#include <iostream>

using namespace std;

int div_with_rem(int num, int& rem);

int main()
{
    int x = 22;
    int d = 4;
    int m, r;

    r = d;
    m = div_with_rem(x, r);

    cout << x << " / " << d << endl;
    cout << "m = " << m << "r = " << r << endl;
    return 0;
}

int div_with_rem(int num, int& div)
{
    int result = num / div;
    div = num % div;

    return result;
}