#include "House.cpp"
using namespace std;

void window_clean(House& h);

int main()
{
    House h;

    cout << "Before\n";
    h.show();
    window_clean(h);
    h.flr_clean();
    cout << "After\n";
    h.show();

    return 1;
}

void window_clean(House& h)
{
    h.win_state = true;
}
