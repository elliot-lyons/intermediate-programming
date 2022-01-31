#include "House.h"
#include <iostream>


House::House()
{
    win_state = false;
    flr_state = false;
}

void House::show()
{
    cout << "windows: " << win_state << " ";
    cout << "floors: " << flr_state << endl;
}

void House::flr_clean()
{
    flr_state = true;
}